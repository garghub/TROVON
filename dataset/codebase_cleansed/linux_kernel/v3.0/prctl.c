int os_arch_prctl(int pid, int code, unsigned long *addr)
{
return ptrace(PTRACE_ARCH_PRCTL, pid, (unsigned long) addr, code);
}
