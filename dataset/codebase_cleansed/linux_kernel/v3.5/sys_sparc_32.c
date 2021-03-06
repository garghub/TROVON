asmlinkage unsigned long sys_getpagesize(void)
{
return PAGE_SIZE;
}
unsigned long arch_get_unmapped_area(struct file *filp, unsigned long addr, unsigned long len, unsigned long pgoff, unsigned long flags)
{
struct vm_area_struct * vmm;
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
if (flags & MAP_SHARED)
addr = COLOUR_ALIGN(addr);
else
addr = PAGE_ALIGN(addr);
for (vmm = find_vma(current->mm, addr); ; vmm = vmm->vm_next) {
if (TASK_SIZE - PAGE_SIZE - len < addr)
return -ENOMEM;
if (!vmm || addr + len <= vmm->vm_start)
return addr;
addr = vmm->vm_end;
if (flags & MAP_SHARED)
addr = COLOUR_ALIGN(addr);
}
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
asmlinkage int
sparc_sigaction (int sig, const struct old_sigaction __user *act,
struct old_sigaction __user *oact)
{
struct k_sigaction new_ka, old_ka;
int ret;
WARN_ON_ONCE(sig >= 0);
sig = -sig;
if (act) {
unsigned long mask;
if (!access_ok(VERIFY_READ, act, sizeof(*act)) ||
__get_user(new_ka.sa.sa_handler, &act->sa_handler) ||
__get_user(new_ka.sa.sa_restorer, &act->sa_restorer) ||
__get_user(new_ka.sa.sa_flags, &act->sa_flags) ||
__get_user(mask, &act->sa_mask))
return -EFAULT;
siginitset(&new_ka.sa.sa_mask, mask);
new_ka.ka_restorer = NULL;
}
ret = do_sigaction(sig, act ? &new_ka : NULL, oact ? &old_ka : NULL);
if (!ret && oact) {
if (!access_ok(VERIFY_WRITE, oact, sizeof(*oact)) ||
__put_user(old_ka.sa.sa_handler, &oact->sa_handler) ||
__put_user(old_ka.sa.sa_restorer, &oact->sa_restorer) ||
__put_user(old_ka.sa.sa_flags, &oact->sa_flags) ||
__put_user(old_ka.sa.sa_mask.sig[0], &oact->sa_mask))
return -EFAULT;
}
return ret;
}
asmlinkage long
sys_rt_sigaction(int sig,
const struct sigaction __user *act,
struct sigaction __user *oact,
void __user *restorer,
size_t sigsetsize)
{
struct k_sigaction new_ka, old_ka;
int ret;
if (sigsetsize != sizeof(sigset_t))
return -EINVAL;
if (act) {
new_ka.ka_restorer = restorer;
if (copy_from_user(&new_ka.sa, act, sizeof(*act)))
return -EFAULT;
}
ret = do_sigaction(sig, act ? &new_ka : NULL, oact ? &old_ka : NULL);
if (!ret && oact) {
if (copy_to_user(oact, &old_ka.sa, sizeof(*oact)))
return -EFAULT;
}
return ret;
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
int kernel_execve(const char *filename,
const char *const argv[],
const char *const envp[])
{
long __res;
register long __g1 __asm__ ("g1") = __NR_execve;
register long __o0 __asm__ ("o0") = (long)(filename);
register long __o1 __asm__ ("o1") = (long)(argv);
register long __o2 __asm__ ("o2") = (long)(envp);
asm volatile ("t 0x10\n\t"
"bcc 1f\n\t"
"mov %%o0, %0\n\t"
"sub %%g0, %%o0, %0\n\t"
"1:\n\t"
: "=r" (__res), "=&r" (__o0)
: "1" (__o0), "r" (__o1), "r" (__o2), "r" (__g1)
: "cc");
return __res;
}
