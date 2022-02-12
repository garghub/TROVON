int audit_classify_compat_syscall(int abi, unsigned syscall)
{
switch (syscall) {
#ifdef __NR_open
case __NR_open:
return 2;
#endif
#ifdef __NR_openat
case __NR_openat:
return 3;
#endif
#ifdef __NR_socketcall
case __NR_socketcall:
return 4;
#endif
case __NR_execve:
return 5;
default:
return 1;
}
}
