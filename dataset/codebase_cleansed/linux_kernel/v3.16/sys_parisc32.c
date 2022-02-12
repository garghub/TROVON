asmlinkage long sys32_unimplemented(int r26, int r25, int r24, int r23,
int r22, int r21, int r20)
{
printk(KERN_ERR "%s(%d): Unimplemented 32 on 64 syscall #%d!\n",
current->comm, current->pid, r20);
return -ENOSYS;
}
asmlinkage long sys32_fanotify_mark(compat_int_t fanotify_fd, compat_uint_t flags,
compat_uint_t mask0, compat_uint_t mask1, compat_int_t dfd,
const char __user * pathname)
{
return sys_fanotify_mark(fanotify_fd, flags,
((__u64)mask1 << 32) | mask0,
dfd, pathname);
}
