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
asmlinkage int sys_execve(const char __user *filenamei,
const char __user *const __user *argv,
const char __user *const __user *envp, struct pt_regs *regs)
{
int error;
char * filename;
filename = getname(filenamei);
error = PTR_ERR(filename);
if (IS_ERR(filename))
goto out;
error = do_execve(filename, argv, envp, regs);
putname(filename);
out:
return error;
}
int kernel_execve(const char *filename,
const char *const argv[],
const char *const envp[])
{
struct pt_regs regs;
int ret;
memset(&regs, 0, sizeof(struct pt_regs));
ret = do_execve(filename,
(const char __user *const __user *)argv,
(const char __user *const __user *)envp, &regs);
if (ret < 0)
goto out;
regs.ARM_r0 = ret;
asm( "add r0, %0, %1\n\t"
"mov r1, %2\n\t"
"mov r2, %3\n\t"
"bl memmove\n\t"
"mov r8, #0\n\t"
"mov r9, %0\n\t"
"mov sp, r0\n\t"
"b ret_to_user"
:
: "r" (current_thread_info()),
"Ir" (THREAD_START_SP - sizeof(regs)),
"r" (&regs),
"Ir" (sizeof(regs))
: "r0", "r1", "r2", "r3", "ip", "lr", "memory");
out:
return ret;
}
asmlinkage long sys_arm_fadvise64_64(int fd, int advice,
loff_t offset, loff_t len)
{
return sys_fadvise64_64(fd, offset, len, advice);
}
