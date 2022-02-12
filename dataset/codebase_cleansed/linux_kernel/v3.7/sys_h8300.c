asmlinkage int
sys_cacheflush (unsigned long addr, int scope, int cache, unsigned long len)
{
return -EINVAL;
}
asmlinkage int sys_getpagesize(void)
{
return PAGE_SIZE;
}
asmlinkage void syscall_print(void *dummy,...)
{
struct pt_regs *regs = (struct pt_regs *) ((unsigned char *)&dummy-4);
printk("call %06lx:%ld 1:%08lx,2:%08lx,3:%08lx,ret:%08lx\n",
((regs->pc)&0xffffff)-2,regs->orig_er0,regs->er1,regs->er2,regs->er3,regs->er0);
}
asmlinkage
int kernel_execve(const char *filename,
const char *const argv[],
const char *const envp[])
{
register long res __asm__("er0");
register const char *const *_c __asm__("er3") = envp;
register const char *const *_b __asm__("er2") = argv;
register const char * _a __asm__("er1") = filename;
__asm__ __volatile__ ("mov.l %1,er0\n\t"
"trapa #0\n\t"
: "=r" (res)
: "g" (__NR_execve),
"g" (_a),
"g" (_b),
"g" (_c)
: "cc", "memory");
return res;
}
