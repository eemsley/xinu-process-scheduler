#include <xinu.h>


void iobnd(void) {
  uint32 i;
  while (clkcounterms <= STOPPINGTIME) {
    for (i = 0; i < 5; i++) {
      sleepms(100);
    }
  }
  kprintf("PID: %d, IO-BOUND, CLKCOUNTERMS: %d, CPU USAGE: %d, RESPONSE TIME: %d\n", getpid(), clkcounterms, proctab[getpid()].prcpu, responsetime(getpid()));
}
