#include "config.h"
#include <_ansi.h>
#include <_syslist.h>
#include <errno.h>
#include <sys/syscalls.h>

#ifdef REENTRANT_SYSCALLS_PROVIDED
int _execve_r(struct _reent *r, char *name, char **argv, char **env) {
#else
int _execve(char *name, char **argv, char **env) {
	struct _reent *r = _REENT;
#endif
	if(__syscalls.execve_r)
		return __syscalls.execve_r(r,name,argv,env);

	r->_errno = ENOSYS;
	return -1;
}
