#include <xinu.h>

void greetings(void) {
  kprintf("\nHello Evan Emsley \n");
  kprintf("eemsley\n");
  kprintf("2024\n");
  kprintf("Spring\n\n");
  int x = 0;
  while (x < 100) {
    x++;
    kprintf("%d", x);
  }
  kprintf("\n");
}
