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
