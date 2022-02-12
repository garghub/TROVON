int os_arch_prctl(int pid, int option, unsigned long *arg2)\r\n{\r\nreturn ptrace(PTRACE_ARCH_PRCTL, pid, (unsigned long) arg2, option);\r\n}
