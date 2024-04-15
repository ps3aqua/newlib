#include "config.h"
#include <_ansi.h>
#include <_syslist.h>
#include <errno.h>
#include <sys/syscalls.h>

#ifdef REENTRANT_SYSCALLS_PROVIDED
int _rename_r(struct _reent *r, const char *old, const char *new) {
#else
int _rename(const char *old, const char *new) {
	struct _reent *r = _REENT;
#endif
	if(__syscalls.rename_r)
		return __syscalls.rename_r(r,old,new);

	r->_errno = ENOSYS;
	return -1;
}
