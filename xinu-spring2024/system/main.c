/* main.c  - main */

#include <xinu.h>

void greetings(void);

process	main(void)
{

  #ifdef XINUTEST
    kprintf("XINU TEST...\n\n");
    kprintf("clktime: %d\nclkcounterms: %d\n", clktime, clkcounterms);
    kprintf("sleeping 1 then calling greetings()...\n\n");
  #endif
  sleep(1);
  int x = 0;
  while (x < 100) {
    x++;
    kprintf("mycputime: %d\n", proctab[(pid32)getpid()].prcpu);
  }
  #ifdef XINUTEST
    kprintf("\n\nclktime: %d\nclkcounterms: %d\n", clktime, clkcounterms);
    kprintf("mycputime: %d\n", proctab[(pid32)getpid()].prcpu);
  #endif

  sleep(1);

  #ifdef XINUTEST
    kprintf("\n\nclktime: %d\nclkcounterms: %d\n", clktime, clkcounterms);
    kprintf("mycputime: %d\n", proctab[(pid32) getpid()].prcpu); 
  #endif
  return OK;
}
