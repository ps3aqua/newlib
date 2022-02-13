#include "config.h"
#include <_ansi.h>
#include <_syslist.h>
#include <reent.h>
#include <errno.h>
#include <sys/syscalls.h>

#ifdef REENTRANT_SYSCALLS_PROVIDED
int _unlink_r(struct _reent *r, const char *name) {
#else
int _unlink(const char *name) {
	struct _reent *r = REENT;
#endif
	if(__syscalls.unlink_r)
		return __syscalls.unlink_r(r,name);

	r->_errno = ENOSYS;
	return -1;
}
