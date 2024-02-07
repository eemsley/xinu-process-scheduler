#include <xinu.h>


void cpubnd(void) {
	intmask	mask;			/* Saved interrupt mask		*/

  while (clkcounterms <= STOPPINGTIME) {
    continue;
  }

  mask = disable();
  kprintf("PID: %d, CPU-BOUND, CLKCOUNTERMS: %d, CPU USAGE: %d, RESPONSE TIME: %d\n", getpid(), clkcounterms, proctab[getpid()].prcpu, responsetime(getpid()));
  restore(mask);
}
