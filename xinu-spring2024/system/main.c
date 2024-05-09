/* main.c  - main */

#include <xinu.h>

void greetings(void);
void cpubnd(void);

process	main(void)
{
  //BENCHMARK A
  /*
  chprio(getpid(), 10);
  resume( ( create(cpubnd, 0, 6, "cpu1", 0) ) );
  resume( ( create(cpubnd, 0, 6, "cpu2", 0) ) );
  resume( ( create(cpubnd, 0, 6, "cpu3", 0) ) );
  resume( ( create(cpubnd, 0, 6, "cpu4", 0) ) );
  resume( ( create(cpubnd, 0, 6, "cpu5", 0) ) );
  resume( ( create(cpubnd, 0, 6, "cpu6", 0) ) );
*/
  //BENCHMARK B
 /* 
  chprio(getpid(), 10);
  resume( ( create(iobnd, 0, 6, "cpu1", 0) ) );
  resume( ( create(iobnd, 0, 6, "cpu2", 0) ) );
  resume( ( create(iobnd, 0, 6, "cpu3", 0) ) );
  resume( ( create(iobnd, 0, 6, "cpu4", 0) ) );
  resume( ( create(iobnd, 0, 6, "cpu5", 0) ) );
  resume( ( create(iobnd, 0, 6, "cpu6", 0) ) );
  */

  
  //BENCHMARK C
  /*
  chprio(getpid(), 10);
  resume( ( create(cpubnd, 0, 6, "cpu1", 0) ) );
  resume( ( create(cpubnd, 0, 6, "cpu2", 0) ) );
  resume( ( create(cpubnd, 0, 6, "cpu3", 0) ) );
  resume( ( create(iobnd, 0, 6, "cpu4", 0) ) );
  resume( ( create(iobnd, 0, 6, "cpu5", 0) ) );
  resume( ( create(iobnd, 0, 6, "cpu6", 0) ) );
  */

  //BENCHMARK D
  /*
  chprio(getpid(), 10);
  resume( ( create(cpubnd, 0, 6, "cpu1", 0) ) );
  resume( ( create(cpubnd, 0, 6, "cpu2", 0) ) );
  sleep(3);
  resume( ( create(cpubnd, 0, 6, "cpu5", 0) ) );
  resume( ( create(cpubnd, 0, 6, "cpu6", 0) ) );
 */ 

  //JOKER 
  
  chprio(getpid(), 10);
  resume( ( create(cpubnd, 0, 6, "cpu1", 0) ) );
  resume( ( create(cpubnd, 0, 6, "cpu2", 0) ) );
  resume( ( create(iobnd, 0, 6, "cpu3", 0) ) );
  resume( ( create(iobnd, 0, 6, "cpu4", 0) ) );
  resume( ( create(joker, 0, 6, "cpu5", 0) ) );
 

return OK;

}
