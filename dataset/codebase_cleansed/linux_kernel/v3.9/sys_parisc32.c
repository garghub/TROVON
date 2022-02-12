asmlinkage long sys32_unimplemented(int r26, int r25, int r24, int r23,
int r22, int r21, int r20)
{
printk(KERN_ERR "%s(%d): Unimplemented 32 on 64 syscall #%d!\n",
current->comm, current->pid, r20);
return -ENOSYS;
}
asmlinkage long sys32_sendfile(u32 out_fd, u32 in_fd,
compat_off_t __user *offset, compat_size_t count)
{
return compat_sys_sendfile((int)out_fd, (int)in_fd, offset, count);
}
asmlinkage long sys32_sendfile64(u32 out_fd, u32 in_fd,
compat_loff_t __user *offset, compat_size_t count)
{
return sys_sendfile64((int)out_fd, (int)in_fd,
(loff_t __user *)offset, count);
}
asmlinkage long sys32_semctl(int semid, int semnum, int cmd, union semun arg)
{
union semun u;
if (cmd == SETVAL) {
u.val = *((int *)&arg + 1);
return sys_semctl (semid, semnum, cmd, u);
}
return sys_semctl (semid, semnum, cmd, arg);
}
long sys32_lookup_dcookie(u32 cookie_high, u32 cookie_low, char __user *buf,
size_t len)
{
return sys_lookup_dcookie((u64)cookie_high << 32 | cookie_low,
buf, len);
}
asmlinkage long compat_sys_fanotify_mark(int fan_fd, int flags, u32 mask_hi,
u32 mask_lo, int fd,
const char __user *pathname)
{
return sys_fanotify_mark(fan_fd, flags, ((u64)mask_hi << 32) | mask_lo,
fd, pathname);
}
