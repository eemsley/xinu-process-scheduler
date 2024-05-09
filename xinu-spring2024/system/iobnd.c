#include <xinu.h>


void iobnd(void) {

	intmask	mask;			/* Saved interrupt mask		*/
  uint32 i;
  uint32 j;
  int x = 10;
  while (clkcounterms <= STOPPINGTIME) {
    //kprintf("before: %d\n", clkcounterms);
    for (i = 0; i < 300; i++) {
      for (j = 0; j < 300; j++) {
        x = x + 1;
        x = x * 1;
        x = x * 2;
        x = x / 2;
      }
    }
    //kprintf("after: %d\n", clkcounterms);
    sleepms(100);
  }
  mask = disable();
  kprintf("PID: %d, IO-BOUND, CLKCOUNTERMS: %d, CPU USAGE: %d, RESPONSE TIME: %d\n", getpid(), clkcounterms, proctab[getpid()].prcpu, responsetime(getpid()));
  restore(mask);
}
