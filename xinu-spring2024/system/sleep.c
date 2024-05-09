/* sleep.c - sleep sleepms */

#include <xinu.h>

#define	MAXSECONDS	2147483		/* Max seconds per 32-bit msec	*/

/*------------------------------------------------------------------------
 *  sleep  -  Delay the calling process n seconds
 *------------------------------------------------------------------------
 */
syscall	sleep(
	  int32	delay		/* Time to delay in seconds	*/
	)
{
	if ( (delay < 0) || (delay > MAXSECONDS) ) {
		return SYSERR;
	}
	sleepms(1000*delay);
	return OK;
}

/*------------------------------------------------------------------------
 *  sleepms  -  Delay the calling process n milliseconds
 *------------------------------------------------------------------------
 */
syscall	sleepms(
	  int32	delay			/* Time to delay in msec.	*/
	)
{
	intmask	mask;			/* Saved interrupt mask		*/

	if (delay < 0) {
		return SYSERR;
	}

  /* CASE 2: IO BOUND, PROMOTE IT */
  if (proctab[currpid].prprio != 12) {
    chprio(currpid, dynprio[proctab[currpid].prprio].ts_slpret); // promote priority of the sleeping process
  }
  proctab[currpid].remainpreempt = 0; //set remaining time slice to 0, it gets a full time slice next run
  /* CASE 2: IO BOUND */


	if (delay == 0) {
		yield();
		return OK;
	}

	/* Delay calling process */

	mask = disable();
	if (insertd(currpid, sleepq, delay) == SYSERR) {
		restore(mask);
		return SYSERR;
	}
  
  
	proctab[currpid].prstate = PR_SLEEP;
	resched();
	restore(mask);
	return OK;
}
