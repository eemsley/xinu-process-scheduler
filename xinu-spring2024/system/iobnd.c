#include <xinu.h>


void iobnd(void) {

	intmask	mask;			/* Saved interrupt mask		*/
  uint32 i;
  int x = 10;
  while (clkcounterms <= STOPPINGTIME) {
    for (i = 0; i < 3; i++) {
      x = x + 10;
      x = x * 10;
    }
    sleepms(100);
  }
  mask = disable();
  kprintf("PID: %d, IO-BOUND, CLKCOUNTERMS: %d, CPU USAGE: %d, RESPONSE TIME: %d\n", getpid(), clkcounterms, proctab[getpid()].prcpu, responsetime(getpid()));
  restore(mask);
}
