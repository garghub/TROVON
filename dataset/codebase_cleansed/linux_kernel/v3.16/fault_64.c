static inline __kprobes int notify_page_fault(struct pt_regs *regs)
{
int ret = 0;
if (kprobes_built_in() && !user_mode(regs)) {
preempt_disable();
if (kprobe_running() && kprobe_fault_handler(regs, 0))
ret = 1;
preempt_enable();
}
return ret;
}
static void __kprobes unhandled_fault(unsigned long address,
struct task_struct *tsk,
struct pt_regs *regs)
{
if ((unsigned long) address < PAGE_SIZE) {
printk(KERN_ALERT "Unable to handle kernel NULL "
"pointer dereference\n");
} else {
printk(KERN_ALERT "Unable to handle kernel paging request "
"at virtual address %016lx\n", (unsigned long)address);
}
printk(KERN_ALERT "tsk->{mm,active_mm}->context = %016lx\n",
(tsk->mm ?
CTX_HWBITS(tsk->mm->context) :
CTX_HWBITS(tsk->active_mm->context)));
printk(KERN_ALERT "tsk->{mm,active_mm}->pgd = %016lx\n",
(tsk->mm ? (unsigned long) tsk->mm->pgd :
(unsigned long) tsk->active_mm->pgd));
die_if_kernel("Oops", regs);
}
static void __kprobes bad_kernel_pc(struct pt_regs *regs, unsigned long vaddr)
{
printk(KERN_CRIT "OOPS: Bogus kernel PC [%016lx] in fault handler\n",
regs->tpc);
printk(KERN_CRIT "OOPS: RPC [%016lx]\n", regs->u_regs[15]);
printk("OOPS: RPC <%pS>\n", (void *) regs->u_regs[15]);
printk(KERN_CRIT "OOPS: Fault was to vaddr[%lx]\n", vaddr);
dump_stack();
unhandled_fault(regs->tpc, current, regs);
}
static unsigned int get_user_insn(unsigned long tpc)
{
pgd_t *pgdp = pgd_offset(current->mm, tpc);
pud_t *pudp;
pmd_t *pmdp;
pte_t *ptep, pte;
unsigned long pa;
u32 insn = 0;
if (pgd_none(*pgdp) || unlikely(pgd_bad(*pgdp)))
goto out;
pudp = pud_offset(pgdp, tpc);
if (pud_none(*pudp) || unlikely(pud_bad(*pudp)))
goto out;
local_irq_disable();
pmdp = pmd_offset(pudp, tpc);
if (pmd_none(*pmdp) || unlikely(pmd_bad(*pmdp)))
goto out_irq_enable;
#ifdef CONFIG_TRANSPARENT_HUGEPAGE
if (pmd_trans_huge(*pmdp)) {
if (pmd_trans_splitting(*pmdp))
goto out_irq_enable;
pa = pmd_pfn(*pmdp) << PAGE_SHIFT;
pa += tpc & ~HPAGE_MASK;
__asm__ __volatile__("lduwa [%1] %2, %0"
: "=r" (insn)
: "r" (pa), "i" (ASI_PHYS_USE_EC));
} else
#endif
{
ptep = pte_offset_map(pmdp, tpc);
pte = *ptep;
if (pte_present(pte)) {
pa = (pte_pfn(pte) << PAGE_SHIFT);
pa += (tpc & ~PAGE_MASK);
__asm__ __volatile__("lduwa [%1] %2, %0"
: "=r" (insn)
: "r" (pa), "i" (ASI_PHYS_USE_EC));
}
pte_unmap(ptep);
}
out_irq_enable:
local_irq_enable();
out:
return insn;
}
static inline void
show_signal_msg(struct pt_regs *regs, int sig, int code,
unsigned long address, struct task_struct *tsk)
{
if (!unhandled_signal(tsk, sig))
return;
if (!printk_ratelimit())
return;
printk("%s%s[%d]: segfault at %lx ip %p (rpc %p) sp %p error %x",
task_pid_nr(tsk) > 1 ? KERN_INFO : KERN_EMERG,
tsk->comm, task_pid_nr(tsk), address,
(void *)regs->tpc, (void *)regs->u_regs[UREG_I7],
(void *)regs->u_regs[UREG_FP], code);
print_vma_addr(KERN_CONT " in ", regs->tpc);
printk(KERN_CONT "\n");
}
static void do_fault_siginfo(int code, int sig, struct pt_regs *regs,
unsigned long fault_addr, unsigned int insn,
int fault_code)
{
unsigned long addr;
siginfo_t info;
info.si_code = code;
info.si_signo = sig;
info.si_errno = 0;
if (fault_code & FAULT_CODE_ITLB) {
addr = regs->tpc;
} else {
if (insn)
addr = compute_effective_address(regs, insn, 0);
else
addr = fault_addr;
}
info.si_addr = (void __user *) addr;
info.si_trapno = 0;
if (unlikely(show_unhandled_signals))
show_signal_msg(regs, sig, code, addr, current);
force_sig_info(sig, &info, current);
}
static unsigned int get_fault_insn(struct pt_regs *regs, unsigned int insn)
{
if (!insn) {
if (!regs->tpc || (regs->tpc & 0x3))
return 0;
if (regs->tstate & TSTATE_PRIV) {
insn = *(unsigned int *) regs->tpc;
} else {
insn = get_user_insn(regs->tpc);
}
}
return insn;
}
static void __kprobes do_kernel_fault(struct pt_regs *regs, int si_code,
int fault_code, unsigned int insn,
unsigned long address)
{
unsigned char asi = ASI_P;
if ((!insn) && (regs->tstate & TSTATE_PRIV))
goto cannot_handle;
if (!(fault_code & (FAULT_CODE_WRITE|FAULT_CODE_ITLB)) &&
(insn & 0xc0800000) == 0xc0800000) {
if (insn & 0x2000)
asi = (regs->tstate >> 24);
else
asi = (insn >> 5);
if ((asi & 0xf2) == 0x82) {
if (insn & 0x1000000) {
handle_ldf_stq(insn, regs);
} else {
handle_ld_nf(insn, regs);
}
return;
}
}
if (regs->tstate & TSTATE_PRIV) {
const struct exception_table_entry *entry;
entry = search_exception_tables(regs->tpc);
if (entry) {
regs->tpc = entry->fixup;
regs->tnpc = regs->tpc + 4;
return;
}
} else {
do_fault_siginfo(si_code, SIGSEGV, regs, address, insn, fault_code);
return;
}
cannot_handle:
unhandled_fault (address, current, regs);
}
static void noinline __kprobes bogus_32bit_fault_tpc(struct pt_regs *regs)
{
static int times;
if (times++ < 10)
printk(KERN_ERR "FAULT[%s:%d]: 32-bit process reports "
"64-bit TPC [%lx]\n",
current->comm, current->pid,
regs->tpc);
show_regs(regs);
}
asmlinkage void __kprobes do_sparc64_fault(struct pt_regs *regs)
{
enum ctx_state prev_state = exception_enter();
struct mm_struct *mm = current->mm;
struct vm_area_struct *vma;
unsigned int insn = 0;
int si_code, fault_code, fault;
unsigned long address, mm_rss;
unsigned int flags = FAULT_FLAG_ALLOW_RETRY | FAULT_FLAG_KILLABLE;
fault_code = get_thread_fault_code();
if (notify_page_fault(regs))
goto exit_exception;
si_code = SEGV_MAPERR;
address = current_thread_info()->fault_address;
if ((fault_code & FAULT_CODE_ITLB) &&
(fault_code & FAULT_CODE_DTLB))
BUG();
if (test_thread_flag(TIF_32BIT)) {
if (!(regs->tstate & TSTATE_PRIV)) {
if (unlikely((regs->tpc >> 32) != 0)) {
bogus_32bit_fault_tpc(regs);
goto intr_or_no_mm;
}
}
if (unlikely((address >> 32) != 0))
goto intr_or_no_mm;
}
if (regs->tstate & TSTATE_PRIV) {
unsigned long tpc = regs->tpc;
if ((tpc >= KERNBASE && tpc < (unsigned long) __init_end) ||
(tpc >= MODULES_VADDR && tpc < MODULES_END)) {
} else {
bad_kernel_pc(regs, address);
goto exit_exception;
}
} else
flags |= FAULT_FLAG_USER;
if (in_atomic() || !mm)
goto intr_or_no_mm;
perf_sw_event(PERF_COUNT_SW_PAGE_FAULTS, 1, regs, address);
if (!down_read_trylock(&mm->mmap_sem)) {
if ((regs->tstate & TSTATE_PRIV) &&
!search_exception_tables(regs->tpc)) {
insn = get_fault_insn(regs, insn);
goto handle_kernel_fault;
}
retry:
down_read(&mm->mmap_sem);
}
vma = find_vma(mm, address);
if (!vma)
goto bad_area;
if (((fault_code &
(FAULT_CODE_DTLB | FAULT_CODE_WRITE | FAULT_CODE_WINFIXUP)) == FAULT_CODE_DTLB) &&
(vma->vm_flags & VM_WRITE) != 0) {
insn = get_fault_insn(regs, 0);
if (!insn)
goto continue_fault;
if ((insn & 0xc0200000) == 0xc0200000 &&
(insn & 0x01780000) != 0x01680000) {
fault_code |= FAULT_CODE_WRITE;
}
}
continue_fault:
if (vma->vm_start <= address)
goto good_area;
if (!(vma->vm_flags & VM_GROWSDOWN))
goto bad_area;
if (!(fault_code & FAULT_CODE_WRITE)) {
insn = get_fault_insn(regs, insn);
if ((insn & 0xc0800000) == 0xc0800000) {
unsigned char asi;
if (insn & 0x2000)
asi = (regs->tstate >> 24);
else
asi = (insn >> 5);
if ((asi & 0xf2) == 0x82)
goto bad_area;
}
}
if (expand_stack(vma, address))
goto bad_area;
good_area:
si_code = SEGV_ACCERR;
if ((fault_code & FAULT_CODE_ITLB) && !(vma->vm_flags & VM_EXEC)) {
BUG_ON(address != regs->tpc);
BUG_ON(regs->tstate & TSTATE_PRIV);
goto bad_area;
}
if (fault_code & FAULT_CODE_WRITE) {
if (!(vma->vm_flags & VM_WRITE))
goto bad_area;
if (tlb_type == spitfire &&
(vma->vm_flags & VM_EXEC) != 0 &&
vma->vm_file != NULL)
set_thread_fault_code(fault_code |
FAULT_CODE_BLKCOMMIT);
flags |= FAULT_FLAG_WRITE;
} else {
if (!(vma->vm_flags & (VM_READ | VM_EXEC)))
goto bad_area;
}
fault = handle_mm_fault(mm, vma, address, flags);
if ((fault & VM_FAULT_RETRY) && fatal_signal_pending(current))
goto exit_exception;
if (unlikely(fault & VM_FAULT_ERROR)) {
if (fault & VM_FAULT_OOM)
goto out_of_memory;
else if (fault & VM_FAULT_SIGBUS)
goto do_sigbus;
BUG();
}
if (flags & FAULT_FLAG_ALLOW_RETRY) {
if (fault & VM_FAULT_MAJOR) {
current->maj_flt++;
perf_sw_event(PERF_COUNT_SW_PAGE_FAULTS_MAJ,
1, regs, address);
} else {
current->min_flt++;
perf_sw_event(PERF_COUNT_SW_PAGE_FAULTS_MIN,
1, regs, address);
}
if (fault & VM_FAULT_RETRY) {
flags &= ~FAULT_FLAG_ALLOW_RETRY;
flags |= FAULT_FLAG_TRIED;
goto retry;
}
}
up_read(&mm->mmap_sem);
mm_rss = get_mm_rss(mm);
#if defined(CONFIG_HUGETLB_PAGE) || defined(CONFIG_TRANSPARENT_HUGEPAGE)
mm_rss -= (mm->context.huge_pte_count * (HPAGE_SIZE / PAGE_SIZE));
#endif
if (unlikely(mm_rss >
mm->context.tsb_block[MM_TSB_BASE].tsb_rss_limit))
tsb_grow(mm, MM_TSB_BASE, mm_rss);
#if defined(CONFIG_HUGETLB_PAGE) || defined(CONFIG_TRANSPARENT_HUGEPAGE)
mm_rss = mm->context.huge_pte_count;
if (unlikely(mm_rss >
mm->context.tsb_block[MM_TSB_HUGE].tsb_rss_limit)) {
if (mm->context.tsb_block[MM_TSB_HUGE].tsb)
tsb_grow(mm, MM_TSB_HUGE, mm_rss);
else
hugetlb_setup(regs);
}
#endif
exit_exception:
exception_exit(prev_state);
return;
bad_area:
insn = get_fault_insn(regs, insn);
up_read(&mm->mmap_sem);
handle_kernel_fault:
do_kernel_fault(regs, si_code, fault_code, insn, address);
goto exit_exception;
out_of_memory:
insn = get_fault_insn(regs, insn);
up_read(&mm->mmap_sem);
if (!(regs->tstate & TSTATE_PRIV)) {
pagefault_out_of_memory();
goto exit_exception;
}
goto handle_kernel_fault;
intr_or_no_mm:
insn = get_fault_insn(regs, 0);
goto handle_kernel_fault;
do_sigbus:
insn = get_fault_insn(regs, insn);
up_read(&mm->mmap_sem);
do_fault_siginfo(BUS_ADRERR, SIGBUS, regs, address, insn, fault_code);
if (regs->tstate & TSTATE_PRIV)
goto handle_kernel_fault;
}
