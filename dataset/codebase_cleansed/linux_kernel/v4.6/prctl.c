int os_arch_prctl(int pid, int code, unsigned long *addr)\r\n{\r\nreturn ptrace(PTRACE_ARCH_PRCTL, pid, (unsigned long) addr, code);\r\n}
