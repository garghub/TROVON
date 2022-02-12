asmlinkage long _sys_clone(unsigned long clone_flags, unsigned long newsp,
int __user *parent_tid, int __user *child_tid,
struct pt_regs *regs)
{
long ret;
if (!newsp)
newsp = regs->sp;
ret = do_fork(clone_flags, newsp, regs, 0, parent_tid, child_tid);
return ret;
}
asmlinkage int _sys_fork(struct pt_regs *regs)
{
#ifdef CONFIG_MMU
return do_fork(SIGCHLD, regs->sp, regs, 0, NULL, NULL);
#else
return -EINVAL;
#endif
}
