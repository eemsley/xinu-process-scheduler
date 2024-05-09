/* resched.c - resched, resched_cntl */

#include <xinu.h>

struct	defer	Defer;

/*------------------------------------------------------------------------
 *  resched  -  Reschedule processor to highest priority eligible process
 *------------------------------------------------------------------------
 */
void	resched(void)		/* Assumes interrupts are disabled	*/
{
	struct procent *ptold;	/* Ptr to table entry for old process	*/
	struct procent *ptnew;	/* Ptr to table entry for new process	*/

	/* If rescheduling is deferred, record attempt and return */

	if (Defer.ndefers > 0) {
		Defer.attempt = TRUE;
		return;
	}

	/* Point to process table entry for the current (old) process */

	ptold = &proctab[currpid];

	if (ptold->prstate == PR_CURR) {  /* Process remains eligible, it has either been interrupted before the quantum expired, or it is cpu_bound */
    if (ptold->prprio == 12) return;
    if (ptold->prprio > firstkey(readylist)) {
      preempt = dynprio[ptold->prprio].ts_quantum; //old process keeps running even with demoted priority (done in clkhandler), change the quantum to match new prio
      return;
		}

		/* Old process will no longer remain current... even if prio is the same as the next ready process, we switch it out */
    if (preempt > 0) { //check if the time slice has expired... if not we must store the remaining time
      ptold->remainpreempt = preempt; 
    }

		ptold->prstate = PR_READY;
		insert(currpid, readylist, ptold->prprio); //old process is not top priority, insert in readylist with new priority
  }

	/* Force context switch to highest priority ready process */

	currpid = dequeue(readylist);
	ptnew = &proctab[currpid];
	ptnew->prstate = PR_CURR;

  ptold->prcpu = currcpu + ptold->prcpu;
  currcpu = 0;
  int prresp = clkcounterms - ptnew->prbeginready;
  if (prresp == 0) {
    prresp = 1;
  }
  ptnew->prresptime = ptnew->prresptime + prresp;
  ptnew->prctxswcount = ptnew->prctxswcount + 1;


   if (ptnew->remainpreempt > 0) {
    preempt = ptnew->remainpreempt;
  } else {
    if (ptnew->prprio == 12) {
      preempt = QUANTUM;
    } else {
	    preempt = dynprio[ptnew->prprio].ts_quantum; //update quantum corresponding to the new process's priority
    }
  }
  //preempt = QUANTUM;		/* Reset time slice for process	*/

	ctxsw(&ptold->prstkptr, &ptnew->prstkptr);

	/* Old process returns here when resumed */

	return;
}

/*------------------------------------------------------------------------
 *  resched_cntl  -  Control whether rescheduling is deferred or allowed
 *------------------------------------------------------------------------
 */
status	resched_cntl(		/* Assumes interrupts are disabled	*/
	  int32	defer		/* Either DEFER_START or DEFER_STOP	*/
	)
{
	switch (defer) {

	    case DEFER_START:	/* Handle a deferral request */

		if (Defer.ndefers++ == 0) {
			Defer.attempt = FALSE;
		}
		return OK;

	    case DEFER_STOP:	/* Handle end of deferral */
		if (Defer.ndefers <= 0) {
			return SYSERR;
		}
		if ( (--Defer.ndefers == 0) && Defer.attempt ) {
			resched();
		}
		return OK;

	    default:
		return SYSERR;
	}
}
