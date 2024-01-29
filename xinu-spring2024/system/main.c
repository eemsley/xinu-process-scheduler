/* main.c  - main */

#include <xinu.h>

void greetings(void);

process	main(void)
{

  #ifdef XINUTEST
    kprintf("XINU TEST 3.1...\n\n");
    kprintf("clktime: %d\nclkcounterms: %d\n", clktime, clkcounterms);
    kprintf("sleeping 5 then calling greetings()...\n\n");
  #endif
  sleep(5);
  greetings();
  #ifdef XINUTEST
    kprintf("\n\nclktime: %d\nclkcounterms: %d\n", clktime, clkcounterms);
  #endif
  return OK;
}
