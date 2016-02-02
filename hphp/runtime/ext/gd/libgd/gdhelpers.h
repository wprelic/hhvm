#ifndef GDHELPERS_H
#define GDHELPERS_H 1

#include <sys/types.h>
#include "php.h"

#include "hphp/runtime/base/memory-manager.h"

/* TBB: strtok_r is not universal; provide an implementation of it. */

extern char *gd_strtok_r(char *s, char *sep, char **state);

/* Check for request OOM.  Call before allocating a lot of memory. */
inline bool precheckOOM(size_t allocsz) {
  return allocsz > HPHP::kMaxSmallSize && HPHP::MM().preAllocOOM(allocsz);
}

/* These functions wrap memory management. gdFree is
  in gd.h, where callers can utilize it to correctly
  free memory allocated by these functions with the
  right version of free(). */
#define gdCalloc(nmemb, size) ecalloc(nmemb, size)
#define gdMalloc(size)        emalloc(size)
#define gdRealloc(ptr, size)  erealloc(ptr, size)
#define gdEstrdup(ptr)        estrdup(ptr)
#define gdFree(ptr)           efree(ptr)
#define gdPMalloc(ptr)        pemalloc(ptr, 1)
#define gdPFree(ptr)          pefree(ptr, 1)
#define gdPEstrdup(ptr)       pestrdup(ptr, 1)

/* Returns nonzero if multiplying the two quantities will
  result in integer overflow. Also returns nonzero if
  either quantity is negative. By Phil Knirsch based on
  netpbm fixes by Alan Cox. */

int overflow2(int a, int b);

#ifdef ZTS
#define gdMutexDeclare(x) MUTEX_T x
#define gdMutexSetup(x) x = tsrm_mutex_alloc()
#define gdMutexShutdown(x) tsrm_mutex_free(x)
#define gdMutexLock(x) tsrm_mutex_lock(x)
#define gdMutexUnlock(x) tsrm_mutex_unlock(x)
#else
#define gdMutexDeclare(x)
#define gdMutexSetup(x)
#define gdMutexShutdown(x)
#define gdMutexLock(x)
#define gdMutexUnlock(x)
#endif

#endif /* GDHELPERS_H */
