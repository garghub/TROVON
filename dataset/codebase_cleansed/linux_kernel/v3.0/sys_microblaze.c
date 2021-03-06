asmlinkage long microblaze_vfork(struct pt_regs *regs)
{
return do_fork(CLONE_VFORK | CLONE_VM | SIGCHLD, regs->r1,
regs, 0, NULL, NULL);
}
asmlinkage long microblaze_clone(int flags, unsigned long stack,
struct pt_regs *regs)
{
if (!stack)
stack = regs->r1;
return do_fork(flags, stack, regs, 0, NULL, NULL);
}
asmlinkage long microblaze_execve(const char __user *filenamei,
const char __user *const __user *argv,
const char __user *const __user *envp,
struct pt_regs *regs)
{
int error;
char *filename;
filename = getname(filenamei);
error = PTR_ERR(filename);
if (IS_ERR(filename))
goto out;
error = do_execve(filename, argv, envp, regs);
putname(filename);
out:
return error;
}
asmlinkage long sys_mmap(unsigned long addr, unsigned long len,
unsigned long prot, unsigned long flags,
unsigned long fd, off_t pgoff)
{
if (pgoff & ~PAGE_MASK)
return -EINVAL;
return sys_mmap_pgoff(addr, len, prot, flags, fd, pgoff >> PAGE_SHIFT);
}
int kernel_execve(const char *filename,
const char *const argv[],
const char *const envp[])
{
register const char *__a __asm__("r5") = filename;
register const void *__b __asm__("r6") = argv;
register const void *__c __asm__("r7") = envp;
register unsigned long __syscall __asm__("r12") = __NR_execve;
register unsigned long __ret __asm__("r3");
__asm__ __volatile__ ("brki r14, 0x8"
: "=r" (__ret), "=r" (__syscall)
: "1" (__syscall), "r" (__a), "r" (__b), "r" (__c)
: "r4", "r8", "r9",
"r10", "r11", "r14", "cc", "memory");
return __ret;
}
