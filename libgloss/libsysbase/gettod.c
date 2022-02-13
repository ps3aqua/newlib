#include "config.h"
#include <_ansi.h>
#include <_syslist.h>
#include <sys/time.h>
#include <sys/times.h>
#include <sys/syscalls.h>
#include <errno.h>

#ifdef REENTRANT_SYSCALLS_PROVIDED
int _gettimeofday_r(struct _reent *r, struct timeval *ptimeval, void *ptimezone) {
#else
int _gettimeofday(struct timeval *ptimeval, void *ptimezone) {
	struct _reent *r = _REENT;
#endif
	if(__syscalls.gettod_r)
		return __syscalls.gettod_r(r,ptimeval,ptimezone);

	r->_errno = ENOSYS;
	return -1;
}
