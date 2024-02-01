#include <xinu.h>


int responsetime(pid32 pid) {
  if (proctab[pid].prctxswcount == 0) {
    return clkcounterms - proctab[pid].prbeginready;
  }
  if (proctab[pid].prstate == PR_READY) {
    return (proctab[pid].prresptime + clkcounterms - proctab[pid].prbeginready) / (proctab[pid].prctxswcount + 1);
  }
  return (proctab[pid].prresptime) / (proctab[pid].prctxswcount);
}
