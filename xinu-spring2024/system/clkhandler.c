/* clkhandler.c - clkhandler */

#include <xinu.h>

/*------------------------------------------------------------------------
 * clkhandler - high level clock interrupt handler
 *------------------------------------------------------------------------
 */


void	clkhandler()
{
  clkcounterms++;
  currcpu++;
	static	uint32	count1000 = 1000;	/* Count to 1000 ms	*/

	/* Decrement the ms counter, and see if a second has passed */

	if((--count1000) <= 0) {

		/* One second has passed, so increment seconds count */

		clktime++;

		/* Reset the local ms counter for the next second */

		count1000 = 1000;
	}

	/* Handle sleeping processes if any exist */

	if(!isempty(sleepq)) {

		/* Decrement the delay for the first process on the	*/
		/*   sleep queue, and awaken if the count reaches zero	*/

		if((--queuetab[firstid(sleepq)].qkey) <= 0) {
			wakeup();
		}
	}

	/* Decrement the preemption counter, and reschedule when the */
	/*   remaining time reaches zero			     */

	if((--preempt) <= 0) {
    
    /* CASE 1: CPU BOUND, quantum has expired, need to demote */
    if (proctab[getpid()].prprio != 12) {
      chprio(getpid(), dynprio[proctab[getpid()].prprio].ts_tqexp); //demote process for next time
    }
    proctab[getpid()].remainpreempt = 0; //remaining preempt is 0, it gets full time slice next time
   /* CASE 1: CPU BOUND*/

		resched();
	}
}
