static inline void print_prots(pgprot_t prot)
{
printk("prot is 0x%016llx\n",pgprot_val(prot));
printk("%s %s %s %s %s\n",PPROT(_PAGE_SHARED),PPROT(_PAGE_READ),
PPROT(_PAGE_EXECUTE),PPROT(_PAGE_WRITE),PPROT(_PAGE_USER));
}
static inline void print_vma(struct vm_area_struct *vma)
{
printk("vma start 0x%08lx\n", vma->vm_start);
printk("vma end 0x%08lx\n", vma->vm_end);
print_prots(vma->vm_page_prot);
printk("vm_flags 0x%08lx\n", vma->vm_flags);
}
static inline void print_task(struct task_struct *tsk)
{
printk("Task pid %d\n", task_pid_nr(tsk));
}
static pte_t *lookup_pte(struct mm_struct *mm, unsigned long address)
{
pgd_t *dir;
pud_t *pud;
pmd_t *pmd;
pte_t *pte;
pte_t entry;
dir = pgd_offset(mm, address);
if (pgd_none(*dir))
return NULL;
pud = pud_offset(dir, address);
if (pud_none(*pud))
return NULL;
pmd = pmd_offset(pud, address);
if (pmd_none(*pmd))
return NULL;
pte = pte_offset_kernel(pmd, address);
entry = *pte;
if (pte_none(entry) || !pte_present(entry))
return NULL;
return pte;
}
asmlinkage void do_page_fault(struct pt_regs *regs, unsigned long writeaccess,
unsigned long textaccess, unsigned long address)
{
struct task_struct *tsk;
struct mm_struct *mm;
struct vm_area_struct * vma;
const struct exception_table_entry *fixup;
pte_t *pte;
int fault;
tsk = current;
mm = tsk->mm;
local_irq_enable();
perf_sw_event(PERF_COUNT_SW_PAGE_FAULTS, 1, regs, address);
if (in_atomic() || !mm)
goto no_context;
down_read(&mm->mmap_sem);
vma = find_vma(mm, address);
if (!vma) {
#ifdef DEBUG_FAULT
print_task(tsk);
printk("%s:%d fault, address is 0x%08x PC %016Lx textaccess %d writeaccess %d\n",
__func__, __LINE__,
address,regs->pc,textaccess,writeaccess);
show_regs(regs);
#endif
goto bad_area;
}
if (vma->vm_start <= address) {
goto good_area;
}
if (!(vma->vm_flags & VM_GROWSDOWN)) {
#ifdef DEBUG_FAULT
print_task(tsk);
printk("%s:%d fault, address is 0x%08x PC %016Lx textaccess %d writeaccess %d\n",
__func__, __LINE__,
address,regs->pc,textaccess,writeaccess);
show_regs(regs);
print_vma(vma);
#endif
goto bad_area;
}
if (expand_stack(vma, address)) {
#ifdef DEBUG_FAULT
print_task(tsk);
printk("%s:%d fault, address is 0x%08x PC %016Lx textaccess %d writeaccess %d\n",
__func__, __LINE__,
address,regs->pc,textaccess,writeaccess);
show_regs(regs);
#endif
goto bad_area;
}
good_area:
if (textaccess) {
if (!(vma->vm_flags & VM_EXEC))
goto bad_area;
} else {
if (writeaccess) {
if (!(vma->vm_flags & VM_WRITE))
goto bad_area;
} else {
if (!(vma->vm_flags & VM_READ))
goto bad_area;
}
}
fault = handle_mm_fault(mm, vma, address, writeaccess ? FAULT_FLAG_WRITE : 0);
if (unlikely(fault & VM_FAULT_ERROR)) {
if (fault & VM_FAULT_OOM)
goto out_of_memory;
else if (fault & VM_FAULT_SIGBUS)
goto do_sigbus;
BUG();
}
if (fault & VM_FAULT_MAJOR) {
tsk->maj_flt++;
perf_sw_event(PERF_COUNT_SW_PAGE_FAULTS_MAJ, 1,
regs, address);
} else {
tsk->min_flt++;
perf_sw_event(PERF_COUNT_SW_PAGE_FAULTS_MIN, 1,
regs, address);
}
pte = lookup_pte (mm, address);
if (!pte) {
goto no_pte;
}
__do_tlb_refill(address, textaccess, pte);
no_pte:
up_read(&mm->mmap_sem);
return;
bad_area:
#ifdef DEBUG_FAULT
printk("fault:bad area\n");
#endif
up_read(&mm->mmap_sem);
if (user_mode(regs)) {
static int count=0;
siginfo_t info;
if (count < 4) {
count++;
printk("user mode bad_area address=%08lx pid=%d (%s) pc=%08lx\n",
address, task_pid_nr(current), current->comm,
(unsigned long) regs->pc);
#if 0
show_regs(regs);
#endif
}
if (is_global_init(tsk)) {
panic("INIT had user mode bad_area\n");
}
tsk->thread.address = address;
tsk->thread.error_code = writeaccess;
info.si_signo = SIGSEGV;
info.si_errno = 0;
info.si_addr = (void *) address;
force_sig_info(SIGSEGV, &info, tsk);
return;
}
no_context:
#ifdef DEBUG_FAULT
printk("fault:No context\n");
#endif
fixup = search_exception_tables(regs->pc);
if (fixup) {
regs->pc = fixup->fixup;
return;
}
if (address < PAGE_SIZE)
printk(KERN_ALERT "Unable to handle kernel NULL pointer dereference");
else
printk(KERN_ALERT "Unable to handle kernel paging request");
printk(" at virtual address %08lx\n", address);
printk(KERN_ALERT "pc = %08Lx%08Lx\n", regs->pc >> 32, regs->pc & 0xffffffff);
die("Oops", regs, writeaccess);
do_exit(SIGKILL);
out_of_memory:
up_read(&mm->mmap_sem);
if (!user_mode(regs))
goto no_context;
pagefault_out_of_memory();
return;
do_sigbus:
printk("fault:Do sigbus\n");
up_read(&mm->mmap_sem);
tsk->thread.address = address;
tsk->thread.error_code = writeaccess;
tsk->thread.trap_no = 14;
force_sig(SIGBUS, tsk);
if (!user_mode(regs))
goto no_context;
}
void local_flush_tlb_one(unsigned long asid, unsigned long page)
{
unsigned long long match, pteh=0, lpage;
unsigned long tlb;
lpage = neff_sign_extend(page);
match = (asid << PTEH_ASID_SHIFT) | PTEH_VALID;
match |= lpage;
for_each_itlb_entry(tlb) {
asm volatile ("getcfg %1, 0, %0"
: "=r" (pteh)
: "r" (tlb) );
if (pteh == match) {
__flush_tlb_slot(tlb);
break;
}
}
for_each_dtlb_entry(tlb) {
asm volatile ("getcfg %1, 0, %0"
: "=r" (pteh)
: "r" (tlb) );
if (pteh == match) {
__flush_tlb_slot(tlb);
break;
}
}
}
void local_flush_tlb_page(struct vm_area_struct *vma, unsigned long page)
{
unsigned long flags;
if (vma->vm_mm) {
page &= PAGE_MASK;
local_irq_save(flags);
local_flush_tlb_one(get_asid(), page);
local_irq_restore(flags);
}
}
void local_flush_tlb_range(struct vm_area_struct *vma, unsigned long start,
unsigned long end)
{
unsigned long flags;
unsigned long long match, pteh=0, pteh_epn, pteh_low;
unsigned long tlb;
unsigned int cpu = smp_processor_id();
struct mm_struct *mm;
mm = vma->vm_mm;
if (cpu_context(cpu, mm) == NO_CONTEXT)
return;
local_irq_save(flags);
start &= PAGE_MASK;
end &= PAGE_MASK;
match = (cpu_asid(cpu, mm) << PTEH_ASID_SHIFT) | PTEH_VALID;
for_each_itlb_entry(tlb) {
asm volatile ("getcfg %1, 0, %0"
: "=r" (pteh)
: "r" (tlb) );
pteh_epn = pteh & PAGE_MASK;
pteh_low = pteh & ~PAGE_MASK;
if (pteh_low == match && pteh_epn >= start && pteh_epn <= end)
__flush_tlb_slot(tlb);
}
for_each_dtlb_entry(tlb) {
asm volatile ("getcfg %1, 0, %0"
: "=r" (pteh)
: "r" (tlb) );
pteh_epn = pteh & PAGE_MASK;
pteh_low = pteh & ~PAGE_MASK;
if (pteh_low == match && pteh_epn >= start && pteh_epn <= end)
__flush_tlb_slot(tlb);
}
local_irq_restore(flags);
}
void local_flush_tlb_mm(struct mm_struct *mm)
{
unsigned long flags;
unsigned int cpu = smp_processor_id();
if (cpu_context(cpu, mm) == NO_CONTEXT)
return;
local_irq_save(flags);
cpu_context(cpu, mm) = NO_CONTEXT;
if (mm == current->mm)
activate_context(mm, cpu);
local_irq_restore(flags);
}
void local_flush_tlb_all(void)
{
unsigned long flags, tlb;
local_irq_save(flags);
for_each_itlb_entry(tlb)
__flush_tlb_slot(tlb);
for_each_dtlb_entry(tlb)
__flush_tlb_slot(tlb);
local_irq_restore(flags);
}
void local_flush_tlb_kernel_range(unsigned long start, unsigned long end)
{
flush_tlb_all();
}
void __flush_tlb_global(void)
{
flush_tlb_all();
}
void __update_tlb(struct vm_area_struct *vma, unsigned long address, pte_t pte)
{
}
