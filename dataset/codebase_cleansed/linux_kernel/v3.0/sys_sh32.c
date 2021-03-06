asmlinkage int sys_sh_pipe(unsigned long r4, unsigned long r5,
unsigned long r6, unsigned long r7,
struct pt_regs __regs)
{
struct pt_regs *regs = RELOC_HIDE(&__regs, 0);
int fd[2];
int error;
error = do_pipe_flags(fd, 0);
if (!error) {
regs->regs[1] = fd[1];
return fd[0];
}
return error;
}
asmlinkage ssize_t sys_pread_wrapper(unsigned int fd, char __user *buf,
size_t count, long dummy, loff_t pos)
{
return sys_pread64(fd, buf, count, pos);
}
asmlinkage ssize_t sys_pwrite_wrapper(unsigned int fd, const char __user *buf,
size_t count, long dummy, loff_t pos)
{
return sys_pwrite64(fd, buf, count, pos);
}
asmlinkage int sys_fadvise64_64_wrapper(int fd, u32 offset0, u32 offset1,
u32 len0, u32 len1, int advice)
{
#ifdef __LITTLE_ENDIAN__
return sys_fadvise64_64(fd, (u64)offset1 << 32 | offset0,
(u64)len1 << 32 | len0, advice);
#else
return sys_fadvise64_64(fd, (u64)offset0 << 32 | offset1,
(u64)len0 << 32 | len1, advice);
#endif
}
int kernel_execve(const char *filename,
const char *const argv[],
const char *const envp[])
{
register long __sc0 __asm__ ("r3") = __NR_execve;
register long __sc4 __asm__ ("r4") = (long) filename;
register long __sc5 __asm__ ("r5") = (long) argv;
register long __sc6 __asm__ ("r6") = (long) envp;
__asm__ __volatile__ (SYSCALL_ARG3 : "=z" (__sc0)
: "0" (__sc0), "r" (__sc4), "r" (__sc5), "r" (__sc6)
: "memory");
return __sc0;
}
