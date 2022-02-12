asmlinkage unsigned long sys_getpagesize(void)
{
return PAGE_SIZE;
}
unsigned long arch_get_unmapped_area(struct file *filp, unsigned long addr, unsigned long len, unsigned long pgoff, unsigned long flags)
{
struct vm_unmapped_area_info info;
if (flags & MAP_FIXED) {
if ((flags & MAP_SHARED) &&
((addr - (pgoff << PAGE_SHIFT)) & (SHMLBA - 1)))
return -EINVAL;
return addr;
}
if (len > TASK_SIZE - PAGE_SIZE)
return -ENOMEM;
if (!addr)
addr = TASK_UNMAPPED_BASE;
info.flags = 0;
info.length = len;
info.low_limit = addr;
info.high_limit = TASK_SIZE;
info.align_mask = (flags & MAP_SHARED) ?
(PAGE_MASK & (SHMLBA - 1)) : 0;
info.align_offset = pgoff << PAGE_SHIFT;
return vm_unmapped_area(&info);
}
asmlinkage int sparc_pipe(struct pt_regs *regs)
{
int fd[2];
int error;
error = do_pipe_flags(fd, 0);
if (error)
goto out;
regs->u_regs[UREG_I1] = fd[1];
error = fd[0];
out:
return error;
}
int sparc_mmap_check(unsigned long addr, unsigned long len)
{
if (len > TASK_SIZE - PAGE_SIZE || addr + len > TASK_SIZE - PAGE_SIZE)
return -EINVAL;
return 0;
}
asmlinkage unsigned long sys_mmap2(unsigned long addr, unsigned long len,
unsigned long prot, unsigned long flags, unsigned long fd,
unsigned long pgoff)
{
return sys_mmap_pgoff(addr, len, prot, flags, fd,
pgoff >> (PAGE_SHIFT - 12));
}
asmlinkage unsigned long sys_mmap(unsigned long addr, unsigned long len,
unsigned long prot, unsigned long flags, unsigned long fd,
unsigned long off)
{
return sys_mmap_pgoff(addr, len, prot, flags, fd, off >> PAGE_SHIFT);
}
long sparc_remap_file_pages(unsigned long start, unsigned long size,
unsigned long prot, unsigned long pgoff,
unsigned long flags)
{
return sys_remap_file_pages(start, size, prot,
(pgoff >> (PAGE_SHIFT - 12)), flags);
}
asmlinkage unsigned long
c_sys_nis_syscall (struct pt_regs *regs)
{
static int count = 0;
if (count++ > 5)
return -ENOSYS;
printk ("%s[%d]: Unimplemented SPARC system call %d\n",
current->comm, task_pid_nr(current), (int)regs->u_regs[1]);
#ifdef DEBUG_UNIMP_SYSCALL
show_regs (regs);
#endif
return -ENOSYS;
}
asmlinkage void
sparc_breakpoint (struct pt_regs *regs)
{
siginfo_t info;
#ifdef DEBUG_SPARC_BREAKPOINT
printk ("TRAP: Entering kernel PC=%x, nPC=%x\n", regs->pc, regs->npc);
#endif
info.si_signo = SIGTRAP;
info.si_errno = 0;
info.si_code = TRAP_BRKPT;
info.si_addr = (void __user *)regs->pc;
info.si_trapno = 0;
force_sig_info(SIGTRAP, &info, current);
#ifdef DEBUG_SPARC_BREAKPOINT
printk ("TRAP: Returning to space: PC=%x nPC=%x\n", regs->pc, regs->npc);
#endif
}
asmlinkage int sys_getdomainname(char __user *name, int len)
{
int nlen, err;
if (len < 0)
return -EINVAL;
down_read(&uts_sem);
nlen = strlen(utsname()->domainname) + 1;
err = -EINVAL;
if (nlen > len)
goto out;
err = -EFAULT;
if (!copy_to_user(name, utsname()->domainname, nlen))
err = 0;
out:
up_read(&uts_sem);
return err;
}
