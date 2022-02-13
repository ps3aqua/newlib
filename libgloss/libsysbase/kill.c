#include "config.h"
#include <_ansi.h>
#include <_syslist.h>
#include <errno.h>

#ifdef REENTRANT_SYSCALLS_PROVIDED
int _kill_r(struct _reent *r, int pid, int sig) {
#else
int _kill(int pid, int sig) {
	struct _reent *r = _REENT;
#endif
	r->_errno = ENOSYS;
	return -1;
}
