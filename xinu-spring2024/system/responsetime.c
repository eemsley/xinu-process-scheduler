#include <xinu.h>


int responsetime(pid32 pid) {
  if (proctab[pid].ctxswcount == 0) {
    return clkcounterms - proctab[pid].prbeginready;
  }
  if (proctab[pid].prstate = PR_READY) {
    return (proctab[pid].prresptime + clkcounterms - proctab[pid].prbeginready) / (proctab[pid].prctxswcount + 1);
  }
  return (proctab[pid].clkcounterms - proctab[pid].prbeginready) / (proctab[pid]/ctxswcount);
}
