int handle_page_fault(unsigned long address, unsigned long ip,
int is_write, int is_user, int *code_out)
{
struct mm_struct *mm = current->mm;
struct vm_area_struct *vma;
pgd_t *pgd;
pud_t *pud;
pmd_t *pmd;
pte_t *pte;
int err = -EFAULT;
unsigned int flags = FAULT_FLAG_ALLOW_RETRY | FAULT_FLAG_KILLABLE;
*code_out = SEGV_MAPERR;
if (faulthandler_disabled())
goto out_nosemaphore;
if (is_user)
flags |= FAULT_FLAG_USER;
retry:
down_read(&mm->mmap_sem);
vma = find_vma(mm, address);
if (!vma)
goto out;
else if (vma->vm_start <= address)
goto good_area;
else if (!(vma->vm_flags & VM_GROWSDOWN))
goto out;
else if (is_user && !ARCH_IS_STACKGROW(address))
goto out;
else if (expand_stack(vma, address))
goto out;
good_area:
*code_out = SEGV_ACCERR;
if (is_write) {
if (!(vma->vm_flags & VM_WRITE))
goto out;
flags |= FAULT_FLAG_WRITE;
} else {
if (!(vma->vm_flags & (VM_READ | VM_EXEC)))
goto out;
}
do {
int fault;
fault = handle_mm_fault(vma, address, flags);
if ((fault & VM_FAULT_RETRY) && fatal_signal_pending(current))
goto out_nosemaphore;
if (unlikely(fault & VM_FAULT_ERROR)) {
if (fault & VM_FAULT_OOM) {
goto out_of_memory;
} else if (fault & VM_FAULT_SIGSEGV) {
goto out;
} else if (fault & VM_FAULT_SIGBUS) {
err = -EACCES;
goto out;
}
BUG();
}
if (flags & FAULT_FLAG_ALLOW_RETRY) {
if (fault & VM_FAULT_MAJOR)
current->maj_flt++;
else
current->min_flt++;
if (fault & VM_FAULT_RETRY) {
flags &= ~FAULT_FLAG_ALLOW_RETRY;
flags |= FAULT_FLAG_TRIED;
goto retry;
}
}
pgd = pgd_offset(mm, address);
pud = pud_offset(pgd, address);
pmd = pmd_offset(pud, address);
pte = pte_offset_kernel(pmd, address);
} while (!pte_present(*pte));
err = 0;
#if 0
WARN_ON(!pte_young(*pte) || (is_write && !pte_dirty(*pte)));
#endif
flush_tlb_page(vma, address);
out:
up_read(&mm->mmap_sem);
out_nosemaphore:
return err;
out_of_memory:
up_read(&mm->mmap_sem);
if (!is_user)
goto out_nosemaphore;
pagefault_out_of_memory();
return 0;
}
static void show_segv_info(struct uml_pt_regs *regs)
{
struct task_struct *tsk = current;
struct faultinfo *fi = UPT_FAULTINFO(regs);
if (!unhandled_signal(tsk, SIGSEGV))
return;
if (!printk_ratelimit())
return;
printk("%s%s[%d]: segfault at %lx ip %p sp %p error %x",
task_pid_nr(tsk) > 1 ? KERN_INFO : KERN_EMERG,
tsk->comm, task_pid_nr(tsk), FAULT_ADDRESS(*fi),
(void *)UPT_IP(regs), (void *)UPT_SP(regs),
fi->error_code);
print_vma_addr(KERN_CONT " in ", UPT_IP(regs));
printk(KERN_CONT "\n");
}
static void bad_segv(struct faultinfo fi, unsigned long ip)
{
struct siginfo si;
si.si_signo = SIGSEGV;
si.si_code = SEGV_ACCERR;
si.si_addr = (void __user *) FAULT_ADDRESS(fi);
current->thread.arch.faultinfo = fi;
force_sig_info(SIGSEGV, &si, current);
}
void fatal_sigsegv(void)
{
force_sigsegv(SIGSEGV, current);
do_signal(&current->thread.regs);
os_dump_core();
}
void segv_handler(int sig, struct siginfo *unused_si, struct uml_pt_regs *regs)
{
struct faultinfo * fi = UPT_FAULTINFO(regs);
if (UPT_IS_USER(regs) && !SEGV_IS_FIXABLE(fi)) {
show_segv_info(regs);
bad_segv(*fi, UPT_IP(regs));
return;
}
segv(*fi, UPT_IP(regs), UPT_IS_USER(regs), regs);
}
unsigned long segv(struct faultinfo fi, unsigned long ip, int is_user,
struct uml_pt_regs *regs)
{
struct siginfo si;
jmp_buf *catcher;
int err;
int is_write = FAULT_WRITE(fi);
unsigned long address = FAULT_ADDRESS(fi);
if (!is_user && regs)
current->thread.segv_regs = container_of(regs, struct pt_regs, regs);
if (!is_user && (address >= start_vm) && (address < end_vm)) {
flush_tlb_kernel_vm();
goto out;
}
else if (current->mm == NULL) {
show_regs(container_of(regs, struct pt_regs, regs));
panic("Segfault with no mm");
}
else if (!is_user && address > PAGE_SIZE && address < TASK_SIZE) {
show_regs(container_of(regs, struct pt_regs, regs));
panic("Kernel tried to access user memory at addr 0x%lx, ip 0x%lx",
address, ip);
}
if (SEGV_IS_FIXABLE(&fi))
err = handle_page_fault(address, ip, is_write, is_user,
&si.si_code);
else {
err = -EFAULT;
address = 0;
}
catcher = current->thread.fault_catcher;
if (!err)
goto out;
else if (catcher != NULL) {
current->thread.fault_addr = (void *) address;
UML_LONGJMP(catcher, 1);
}
else if (current->thread.fault_addr != NULL)
panic("fault_addr set but no fault catcher");
else if (!is_user && arch_fixup(ip, regs))
goto out;
if (!is_user) {
show_regs(container_of(regs, struct pt_regs, regs));
panic("Kernel mode fault at addr 0x%lx, ip 0x%lx",
address, ip);
}
show_segv_info(regs);
if (err == -EACCES) {
si.si_signo = SIGBUS;
si.si_errno = 0;
si.si_code = BUS_ADRERR;
si.si_addr = (void __user *)address;
current->thread.arch.faultinfo = fi;
force_sig_info(SIGBUS, &si, current);
} else {
BUG_ON(err != -EFAULT);
si.si_signo = SIGSEGV;
si.si_addr = (void __user *) address;
current->thread.arch.faultinfo = fi;
force_sig_info(SIGSEGV, &si, current);
}
out:
if (regs)
current->thread.segv_regs = NULL;
return 0;
}
void relay_signal(int sig, struct siginfo *si, struct uml_pt_regs *regs)
{
struct faultinfo *fi;
struct siginfo clean_si;
if (!UPT_IS_USER(regs)) {
if (sig == SIGBUS)
printk(KERN_ERR "Bus error - the host /dev/shm or /tmp "
"mount likely just ran out of space\n");
panic("Kernel mode signal %d", sig);
}
arch_examine_signal(sig, regs);
memset(&clean_si, 0, sizeof(clean_si));
clean_si.si_signo = si->si_signo;
clean_si.si_errno = si->si_errno;
clean_si.si_code = si->si_code;
switch (sig) {
case SIGILL:
case SIGFPE:
case SIGSEGV:
case SIGBUS:
case SIGTRAP:
fi = UPT_FAULTINFO(regs);
clean_si.si_addr = (void __user *) FAULT_ADDRESS(*fi);
current->thread.arch.faultinfo = *fi;
#ifdef __ARCH_SI_TRAPNO
clean_si.si_trapno = si->si_trapno;
#endif
break;
default:
printk(KERN_ERR "Attempted to relay unknown signal %d (si_code = %d)\n",
sig, si->si_code);
}
force_sig_info(sig, &clean_si, current);
}
void bus_handler(int sig, struct siginfo *si, struct uml_pt_regs *regs)
{
if (current->thread.fault_catcher != NULL)
UML_LONGJMP(current->thread.fault_catcher, 1);
else
relay_signal(sig, si, regs);
}
void winch(int sig, struct siginfo *unused_si, struct uml_pt_regs *regs)
{
do_IRQ(WINCH_IRQ, regs);
}
void trap_init(void)
{
}
