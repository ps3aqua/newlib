#include "config.h"
#include <_ansi.h>
#include <_syslist.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/syscalls.h>

#ifdef REENTRANT_SYSCALLS_PROVIDED
int _stat_r(struct _reent *r, const char *path, struct stat *st) {
#else
int _stat(const char *path, struct stat *st) {
	struct _reent *r = _REENT;
#endif
	if(__syscalls.stat_r)
		return __syscalls.stat_r(r,path,st);

	r->_errno = ENOSYS;
	return -1;
}
