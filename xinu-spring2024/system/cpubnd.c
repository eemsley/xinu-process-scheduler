#include <xinu.h>


void cpubnd(void) {
  while (clkcounterms <= STOPPINGTIME) {
    continue;
  }
  kprintf("PID: %d, CPU-BOUND, CLKCOUNTERMS: %d, CPU USAGE: %d, RESPONSE TIME: %d\n", getpid(), clkcounterms, proctab[getpid()].prcpu, responsetime(getpid()));
}
