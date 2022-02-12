void do_page_fault(unsigned long address, long cause, struct pt_regs *regs)
{
struct vm_area_struct *vma;
struct mm_struct *mm = current->mm;
siginfo_t info;
int si_code = SEGV_MAPERR;
int fault;
const struct exception_table_entry *fixup;
unsigned int flags = FAULT_FLAG_ALLOW_RETRY | FAULT_FLAG_KILLABLE |
(cause > 0 ? FAULT_FLAG_WRITE : 0);
if (unlikely(in_interrupt() || !mm))
goto no_context;
local_irq_enable();
retry:
down_read(&mm->mmap_sem);
vma = find_vma(mm, address);
if (!vma)
goto bad_area;
if (vma->vm_start <= address)
goto good_area;
if (!(vma->vm_flags & VM_GROWSDOWN))
goto bad_area;
if (expand_stack(vma, address))
goto bad_area;
good_area:
si_code = SEGV_ACCERR;
switch (cause) {
case FLT_IFETCH:
if (!(vma->vm_flags & VM_EXEC))
goto bad_area;
break;
case FLT_LOAD:
if (!(vma->vm_flags & VM_READ))
goto bad_area;
break;
case FLT_STORE:
if (!(vma->vm_flags & VM_WRITE))
goto bad_area;
break;
}
fault = handle_mm_fault(mm, vma, address, flags);
if ((fault & VM_FAULT_RETRY) && fatal_signal_pending(current))
return;
if (likely(!(fault & VM_FAULT_ERROR))) {
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
up_read(&mm->mmap_sem);
return;
}
up_read(&mm->mmap_sem);
if (!user_mode(regs))
goto no_context;
if (fault & VM_FAULT_OOM) {
pagefault_out_of_memory();
return;
}
if (fault & VM_FAULT_SIGBUS) {
info.si_signo = SIGBUS;
info.si_code = BUS_ADRERR;
}
else {
info.si_signo = SIGSEGV;
info.si_code = SEGV_ACCERR;
}
info.si_errno = 0;
info.si_addr = (void __user *)address;
force_sig_info(info.si_code, &info, current);
return;
bad_area:
up_read(&mm->mmap_sem);
if (user_mode(regs)) {
info.si_signo = SIGSEGV;
info.si_errno = 0;
info.si_code = si_code;
info.si_addr = (void *)address;
force_sig_info(SIGSEGV, &info, current);
return;
}
no_context:
fixup = search_exception_tables(pt_elr(regs));
if (fixup) {
pt_set_elr(regs, fixup->fixup);
return;
}
bust_spinlocks(1);
printk(KERN_EMERG "Unable to handle kernel paging request at "
"virtual address 0x%08lx, regs %p\n", address, regs);
die("Bad Kernel VA", regs, SIGKILL);
}
void read_protection_fault(struct pt_regs *regs)
{
unsigned long badvadr = pt_badva(regs);
do_page_fault(badvadr, FLT_LOAD, regs);
}
void write_protection_fault(struct pt_regs *regs)
{
unsigned long badvadr = pt_badva(regs);
do_page_fault(badvadr, FLT_STORE, regs);
}
void execute_protection_fault(struct pt_regs *regs)
{
unsigned long badvadr = pt_badva(regs);
do_page_fault(badvadr, FLT_IFETCH, regs);
}
