#include <limits.h>
#include "config.h"
#include <_ansi.h>
#include <_syslist.h>
#include <sys/syscalls.h>

void _exit(int rc)
{
	if(__syscalls.exit)
		__syscalls.exit(rc);

	while(1);
}
