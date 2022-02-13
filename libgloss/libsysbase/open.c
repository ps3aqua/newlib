#include "config.h"
#include <_ansi.h>
#include <_syslist.h>
#include <stdio.h>
#include <errno.h>
#include <ctype.h>
#include <string.h>
#include <sys/syscalls.h>

#ifdef REENTRANT_SYSCALLS_PROVIDED
int _open_r(struct _reent *r, const char *file, int flags, int mode) {
#else
int _open(const char *file, int flags, int mode) {
	struct _reent *r = _REENT;
#endif
	if(__syscalls.open_r)
		return __syscalls.open_r(r,file,flags,mode);

	r->_errno = ENOSYS;
	return -1;
}
