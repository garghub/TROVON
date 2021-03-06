int copy_siginfo_to_user32(compat_siginfo_t __user *to, const siginfo_t *from)
{
int err = 0;
bool ia32 = test_thread_flag(TIF_IA32);
if (!access_ok(VERIFY_WRITE, to, sizeof(compat_siginfo_t)))
return -EFAULT;
put_user_try {
put_user_ex(from->si_signo, &to->si_signo);
put_user_ex(from->si_errno, &to->si_errno);
put_user_ex((short)from->si_code, &to->si_code);
if (from->si_code < 0) {
put_user_ex(from->si_pid, &to->si_pid);
put_user_ex(from->si_uid, &to->si_uid);
put_user_ex(ptr_to_compat(from->si_ptr), &to->si_ptr);
} else {
put_user_ex(from->_sifields._pad[0],
&to->_sifields._pad[0]);
switch (from->si_code >> 16) {
case __SI_FAULT >> 16:
break;
case __SI_SYS >> 16:
put_user_ex(from->si_syscall, &to->si_syscall);
put_user_ex(from->si_arch, &to->si_arch);
break;
case __SI_CHLD >> 16:
if (ia32) {
put_user_ex(from->si_utime, &to->si_utime);
put_user_ex(from->si_stime, &to->si_stime);
} else {
put_user_ex(from->si_utime, &to->_sifields._sigchld_x32._utime);
put_user_ex(from->si_stime, &to->_sifields._sigchld_x32._stime);
}
put_user_ex(from->si_status, &to->si_status);
default:
case __SI_KILL >> 16:
put_user_ex(from->si_uid, &to->si_uid);
break;
case __SI_POLL >> 16:
put_user_ex(from->si_fd, &to->si_fd);
break;
case __SI_TIMER >> 16:
put_user_ex(from->si_overrun, &to->si_overrun);
put_user_ex(ptr_to_compat(from->si_ptr),
&to->si_ptr);
break;
case __SI_RT >> 16:
case __SI_MESGQ >> 16:
put_user_ex(from->si_uid, &to->si_uid);
put_user_ex(from->si_int, &to->si_int);
break;
}
}
} put_user_catch(err);
return err;
}
int copy_siginfo_from_user32(siginfo_t *to, compat_siginfo_t __user *from)
{
int err = 0;
u32 ptr32;
if (!access_ok(VERIFY_READ, from, sizeof(compat_siginfo_t)))
return -EFAULT;
get_user_try {
get_user_ex(to->si_signo, &from->si_signo);
get_user_ex(to->si_errno, &from->si_errno);
get_user_ex(to->si_code, &from->si_code);
get_user_ex(to->si_pid, &from->si_pid);
get_user_ex(to->si_uid, &from->si_uid);
get_user_ex(ptr32, &from->si_ptr);
to->si_ptr = compat_ptr(ptr32);
} get_user_catch(err);
return err;
}
