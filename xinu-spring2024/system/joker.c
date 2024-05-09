#include <xinu.h>


void joker(void) {

	intmask	mask;			/* Saved interrupt mask		*/
  while (clkcounterms <= STOPPINGTIME) {
      while (preempt > 1) {
        continue;
      }
    sleepms(1);
  }
  mask = disable();
  kprintf("PID: %d, JOKER!!, CLKCOUNTERMS: %d, CPU USAGE: %d, RESPONSE TIME: %d\n", getpid(), clkcounterms, proctab[getpid()].prcpu, responsetime(getpid()));
  restore(mask);
}
