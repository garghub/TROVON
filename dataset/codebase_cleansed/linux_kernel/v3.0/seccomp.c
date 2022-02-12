void __secure_computing(int this_syscall)
{
int mode = current->seccomp.mode;
int * syscall;
switch (mode) {
case 1:
syscall = mode1_syscalls;
#ifdef CONFIG_COMPAT
if (is_compat_task())
syscall = mode1_syscalls_32;
#endif
do {
if (*syscall == this_syscall)
return;
} while (*++syscall);
break;
default:
BUG();
}
#ifdef SECCOMP_DEBUG
dump_stack();
#endif
do_exit(SIGKILL);
}
long prctl_get_seccomp(void)
{
return current->seccomp.mode;
}
long prctl_set_seccomp(unsigned long seccomp_mode)
{
long ret;
ret = -EPERM;
if (unlikely(current->seccomp.mode))
goto out;
ret = -EINVAL;
if (seccomp_mode && seccomp_mode <= NR_SECCOMP_MODES) {
current->seccomp.mode = seccomp_mode;
set_thread_flag(TIF_SECCOMP);
#ifdef TIF_NOTSC
disable_TSC();
#endif
ret = 0;
}
out:
return ret;
}
