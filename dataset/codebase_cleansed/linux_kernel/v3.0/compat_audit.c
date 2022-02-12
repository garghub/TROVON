int ppc32_classify_syscall(unsigned syscall)
{
switch(syscall) {
case __NR_open:
return 2;
case __NR_openat:
return 3;
case __NR_socketcall:
return 4;
case __NR_execve:
return 5;
default:
return 1;
}
}
