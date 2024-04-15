case "${target}" in
  powerpc64-ps3-elf) AC_DEFINE(REENTRANT_SYSCALLS_PROVIDED, 1, [Reentrant syscalls]) ;;
  *) ;;
esac
