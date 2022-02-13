#include "config.h"
#include <_ansi.h>
#include <_syslist.h>
#include <reent.h>
#include <errno.h>
#include <sys/syscalls.h>

#ifdef REENTRANT_SYSCALLS_PROVIDED
int _link_r(struct _reent *r, const char *old, const char *new) {
#else
int _link(const char *old, const char *new) {
	struct _reent *r = _REENT;
#endif
	if(__syscalls.link_r)
		return __syscalls.link_r(r,old,new);

	r->_errno = ENOSYS;
	return -1;
}
