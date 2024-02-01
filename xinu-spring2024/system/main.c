/* main.c  - main */

#include <xinu.h>

void greetings(void);

process	main(void)
{
  #ifdef XINUTEST
    kprintf("Testing prresptime, prctxswcount, prbeginready, responsetime(pid)\n\n");
    kprintf("main prresptime: %d\n", proctab[getpid()].prresptime);
    kprintf("main ctxsw count: %d\n", proctab[getpid()].prctxswcount);
    kprintf("main prbeginready: %d\n", proctab[getpid()].prbeginready);
    kprintf("main responsetime: %d\n", responsetime(getpid()));
    kprintf("null process resptime: %d, prcpu: %d\n", proctab[0].prresptime, proctab[0].prcpu);
    kprintf("null process prbeginready: %d\n", proctab[0].prbeginready);
    kprintf("clkcounterms: %d\n", clkcounterms);
    kprintf("null process responsetime: %d\n", responsetime(0));
    kprintf("clkcounterms: %d\n", clkcounterms);
    pid32 lowgreet = create(greetings, 9086, 2, "greet", 0);
    resume(lowgreet);
    resume( ( create(greetings, 9086, 22, "greet2", 0) ) );
    kprintf("clkcounterms: %d\n", clkcounterms);
    kprintf("main prresptime: %d\n", proctab[getpid()].prresptime);
    kprintf("main ctxsw count: %d\n", proctab[getpid()].prctxswcount);
    kprintf("main prbeginready: %d\n", proctab[getpid()].prbeginready);
    kprintf("main responsetime: %d\n\n", responsetime(getpid()));
    kprintf("lowgreet prresptime: %d\n", proctab[lowgreet].prresptime);
    kprintf("lowgreet ctxsw count: %d\n", proctab[lowgreet].prctxswcount);
    kprintf("lowgreet prbeginready: %d\n", proctab[lowgreet].prbeginready);
    kprintf("clkcounterms: %d\n", clkcounterms);
    kprintf("lowgreet responsetime: %d\n", responsetime(lowgreet));

  #endif
}
