#include "config.h"
#include <_ansi.h>
#include <_syslist.h>
#include <errno.h>
#include <reent.h>
#include <sys/resource.h>
#include <sys/syscalls.h>

int getrusage(int who, struct rusage *r_usage)
{
	struct _reent *r = _REENT;

	if(__syscalls.getrusage_r)
		return __syscalls.getrusage_r(r,who,r_usage);

	r->_errno = ENOSYS;
	return -1;
}
