asmlinkage int sys_fork(struct pt_regs *regs)
{
#ifdef CONFIG_MMU
return do_fork(SIGCHLD, regs->ARM_sp, regs, 0, NULL, NULL);
#else
return(-EINVAL);
#endif
}
asmlinkage int sys_clone(unsigned long clone_flags, unsigned long newsp,
int __user *parent_tidptr, int tls_val,
int __user *child_tidptr, struct pt_regs *regs)
{
if (!newsp)
newsp = regs->ARM_sp;
return do_fork(clone_flags, newsp, regs, 0, parent_tidptr, child_tidptr);
}
asmlinkage int sys_vfork(struct pt_regs *regs)
{
return do_fork(CLONE_VFORK | CLONE_VM | SIGCHLD, regs->ARM_sp, regs, 0, NULL, NULL);
}
asmlinkage long sys_arm_fadvise64_64(int fd, int advice,
loff_t offset, loff_t len)
{
return sys_fadvise64_64(fd, offset, len, advice);
}
