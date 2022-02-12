static inline int fsr_fs(unsigned int fsr)
{
return (fsr & FSR_FS3_0) | (fsr & FSR_FS4) >> 6;
}
static inline int notify_page_fault(struct pt_regs *regs, unsigned int fsr)
{
int ret = 0;
if (!user_mode(regs)) {
preempt_disable();
if (kprobe_running() && kprobe_fault_handler(regs, fsr))
ret = 1;
preempt_enable();
}
return ret;
}
static inline int notify_page_fault(struct pt_regs *regs, unsigned int fsr)
{
return 0;
}
void show_pte(struct mm_struct *mm, unsigned long addr)
{
pgd_t *pgd;
if (!mm)
mm = &init_mm;
printk(KERN_ALERT "pgd = %p\n", mm->pgd);
pgd = pgd_offset(mm, addr);
printk(KERN_ALERT "[%08lx] *pgd=%08llx",
addr, (long long)pgd_val(*pgd));
do {
pud_t *pud;
pmd_t *pmd;
pte_t *pte;
if (pgd_none(*pgd))
break;
if (pgd_bad(*pgd)) {
printk("(bad)");
break;
}
pud = pud_offset(pgd, addr);
if (PTRS_PER_PUD != 1)
printk(", *pud=%08llx", (long long)pud_val(*pud));
if (pud_none(*pud))
break;
if (pud_bad(*pud)) {
printk("(bad)");
break;
}
pmd = pmd_offset(pud, addr);
if (PTRS_PER_PMD != 1)
printk(", *pmd=%08llx", (long long)pmd_val(*pmd));
if (pmd_none(*pmd))
break;
if (pmd_bad(*pmd)) {
printk("(bad)");
break;
}
if (PageHighMem(pfn_to_page(pmd_val(*pmd) >> PAGE_SHIFT)))
break;
pte = pte_offset_map(pmd, addr);
printk(", *pte=%08llx", (long long)pte_val(*pte));
printk(", *ppte=%08llx",
(long long)pte_val(pte[PTE_HWTABLE_PTRS]));
pte_unmap(pte);
} while(0);
printk("\n");
}
void show_pte(struct mm_struct *mm, unsigned long addr)
{ }
static void
__do_kernel_fault(struct mm_struct *mm, unsigned long addr, unsigned int fsr,
struct pt_regs *regs)
{
if (fixup_exception(regs))
return;
bust_spinlocks(1);
printk(KERN_ALERT
"Unable to handle kernel %s at virtual address %08lx\n",
(addr < PAGE_SIZE) ? "NULL pointer dereference" :
"paging request", addr);
show_pte(mm, addr);
die("Oops", regs, fsr);
bust_spinlocks(0);
do_exit(SIGKILL);
}
static void
__do_user_fault(struct task_struct *tsk, unsigned long addr,
unsigned int fsr, unsigned int sig, int code,
struct pt_regs *regs)
{
struct siginfo si;
#ifdef CONFIG_DEBUG_USER
if (user_debug & UDBG_SEGV) {
printk(KERN_DEBUG "%s: unhandled page fault (%d) at 0x%08lx, code 0x%03x\n",
tsk->comm, sig, addr, fsr);
show_pte(tsk->mm, addr);
show_regs(regs);
}
#endif
tsk->thread.address = addr;
tsk->thread.error_code = fsr;
tsk->thread.trap_no = 14;
si.si_signo = sig;
si.si_errno = 0;
si.si_code = code;
si.si_addr = (void __user *)addr;
force_sig_info(sig, &si, tsk);
}
void do_bad_area(unsigned long addr, unsigned int fsr, struct pt_regs *regs)
{
struct task_struct *tsk = current;
struct mm_struct *mm = tsk->active_mm;
if (user_mode(regs))
__do_user_fault(tsk, addr, fsr, SIGSEGV, SEGV_MAPERR, regs);
else
__do_kernel_fault(mm, addr, fsr, regs);
}
static inline bool access_error(unsigned int fsr, struct vm_area_struct *vma)
{
unsigned int mask = VM_READ | VM_WRITE | VM_EXEC;
if (fsr & FSR_WRITE)
mask = VM_WRITE;
if (fsr & FSR_LNX_PF)
mask = VM_EXEC;
return vma->vm_flags & mask ? false : true;
}
static int __kprobes
__do_page_fault(struct mm_struct *mm, unsigned long addr, unsigned int fsr,
struct task_struct *tsk)
{
struct vm_area_struct *vma;
int fault;
vma = find_vma(mm, addr);
fault = VM_FAULT_BADMAP;
if (unlikely(!vma))
goto out;
if (unlikely(vma->vm_start > addr))
goto check_stack;
good_area:
if (access_error(fsr, vma)) {
fault = VM_FAULT_BADACCESS;
goto out;
}
fault = handle_mm_fault(mm, vma, addr & PAGE_MASK, (fsr & FSR_WRITE) ? FAULT_FLAG_WRITE : 0);
if (unlikely(fault & VM_FAULT_ERROR))
return fault;
if (fault & VM_FAULT_MAJOR)
tsk->maj_flt++;
else
tsk->min_flt++;
return fault;
check_stack:
if (vma->vm_flags & VM_GROWSDOWN && !expand_stack(vma, addr))
goto good_area;
out:
return fault;
}
static int __kprobes
do_page_fault(unsigned long addr, unsigned int fsr, struct pt_regs *regs)
{
struct task_struct *tsk;
struct mm_struct *mm;
int fault, sig, code;
if (notify_page_fault(regs, fsr))
return 0;
tsk = current;
mm = tsk->mm;
if (interrupts_enabled(regs))
local_irq_enable();
if (in_atomic() || !mm)
goto no_context;
if (!down_read_trylock(&mm->mmap_sem)) {
if (!user_mode(regs) && !search_exception_tables(regs->ARM_pc))
goto no_context;
down_read(&mm->mmap_sem);
} else {
might_sleep();
#ifdef CONFIG_DEBUG_VM
if (!user_mode(regs) &&
!search_exception_tables(regs->ARM_pc))
goto no_context;
#endif
}
fault = __do_page_fault(mm, addr, fsr, tsk);
up_read(&mm->mmap_sem);
perf_sw_event(PERF_COUNT_SW_PAGE_FAULTS, 1, regs, addr);
if (fault & VM_FAULT_MAJOR)
perf_sw_event(PERF_COUNT_SW_PAGE_FAULTS_MAJ, 1, regs, addr);
else if (fault & VM_FAULT_MINOR)
perf_sw_event(PERF_COUNT_SW_PAGE_FAULTS_MIN, 1, regs, addr);
if (likely(!(fault & (VM_FAULT_ERROR | VM_FAULT_BADMAP | VM_FAULT_BADACCESS))))
return 0;
if (fault & VM_FAULT_OOM) {
pagefault_out_of_memory();
return 0;
}
if (!user_mode(regs))
goto no_context;
if (fault & VM_FAULT_SIGBUS) {
sig = SIGBUS;
code = BUS_ADRERR;
} else {
sig = SIGSEGV;
code = fault == VM_FAULT_BADACCESS ?
SEGV_ACCERR : SEGV_MAPERR;
}
__do_user_fault(tsk, addr, fsr, sig, code, regs);
return 0;
no_context:
__do_kernel_fault(mm, addr, fsr, regs);
return 0;
}
static int
do_page_fault(unsigned long addr, unsigned int fsr, struct pt_regs *regs)
{
return 0;
}
static int __kprobes
do_translation_fault(unsigned long addr, unsigned int fsr,
struct pt_regs *regs)
{
unsigned int index;
pgd_t *pgd, *pgd_k;
pud_t *pud, *pud_k;
pmd_t *pmd, *pmd_k;
if (addr < TASK_SIZE)
return do_page_fault(addr, fsr, regs);
if (user_mode(regs))
goto bad_area;
index = pgd_index(addr);
pgd = cpu_get_pgd() + index;
pgd_k = init_mm.pgd + index;
if (pgd_none(*pgd_k))
goto bad_area;
if (!pgd_present(*pgd))
set_pgd(pgd, *pgd_k);
pud = pud_offset(pgd, addr);
pud_k = pud_offset(pgd_k, addr);
if (pud_none(*pud_k))
goto bad_area;
if (!pud_present(*pud))
set_pud(pud, *pud_k);
pmd = pmd_offset(pud, addr);
pmd_k = pmd_offset(pud_k, addr);
index = (addr >> SECTION_SHIFT) & 1;
if (pmd_none(pmd_k[index]))
goto bad_area;
copy_pmd(pmd, pmd_k);
return 0;
bad_area:
do_bad_area(addr, fsr, regs);
return 0;
}
static int
do_translation_fault(unsigned long addr, unsigned int fsr,
struct pt_regs *regs)
{
return 0;
}
static int
do_sect_fault(unsigned long addr, unsigned int fsr, struct pt_regs *regs)
{
do_bad_area(addr, fsr, regs);
return 0;
}
static int
do_bad(unsigned long addr, unsigned int fsr, struct pt_regs *regs)
{
return 1;
}
void __init
hook_fault_code(int nr, int (*fn)(unsigned long, unsigned int, struct pt_regs *),
int sig, int code, const char *name)
{
if (nr < 0 || nr >= ARRAY_SIZE(fsr_info))
BUG();
fsr_info[nr].fn = fn;
fsr_info[nr].sig = sig;
fsr_info[nr].code = code;
fsr_info[nr].name = name;
}
asmlinkage void __exception
do_DataAbort(unsigned long addr, unsigned int fsr, struct pt_regs *regs)
{
const struct fsr_info *inf = fsr_info + fsr_fs(fsr);
struct siginfo info;
if (!inf->fn(addr, fsr & ~FSR_LNX_PF, regs))
return;
printk(KERN_ALERT "Unhandled fault: %s (0x%03x) at 0x%08lx\n",
inf->name, fsr, addr);
info.si_signo = inf->sig;
info.si_errno = 0;
info.si_code = inf->code;
info.si_addr = (void __user *)addr;
arm_notify_die("", regs, &info, fsr, 0);
}
void __init
hook_ifault_code(int nr, int (*fn)(unsigned long, unsigned int, struct pt_regs *),
int sig, int code, const char *name)
{
if (nr < 0 || nr >= ARRAY_SIZE(ifsr_info))
BUG();
ifsr_info[nr].fn = fn;
ifsr_info[nr].sig = sig;
ifsr_info[nr].code = code;
ifsr_info[nr].name = name;
}
asmlinkage void __exception
do_PrefetchAbort(unsigned long addr, unsigned int ifsr, struct pt_regs *regs)
{
const struct fsr_info *inf = ifsr_info + fsr_fs(ifsr);
struct siginfo info;
if (!inf->fn(addr, ifsr | FSR_LNX_PF, regs))
return;
printk(KERN_ALERT "Unhandled prefetch abort: %s (0x%03x) at 0x%08lx\n",
inf->name, ifsr, addr);
info.si_signo = inf->sig;
info.si_errno = 0;
info.si_code = inf->code;
info.si_addr = (void __user *)addr;
arm_notify_die("", regs, &info, ifsr, 0);
}
static int __init exceptions_init(void)
{
if (cpu_architecture() >= CPU_ARCH_ARMv6) {
hook_fault_code(4, do_translation_fault, SIGSEGV, SEGV_MAPERR,
"I-cache maintenance fault");
}
if (cpu_architecture() >= CPU_ARCH_ARMv7) {
hook_fault_code(3, do_bad, SIGSEGV, SEGV_MAPERR,
"section access flag fault");
hook_fault_code(6, do_bad, SIGSEGV, SEGV_MAPERR,
"section access flag fault");
}
return 0;
}
