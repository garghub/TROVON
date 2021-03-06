static inline int notify_page_fault(struct pt_regs *regs, int trap)
{
int ret = 0;
if (kprobes_built_in() && !user_mode(regs)) {
preempt_disable();
if (kprobe_running() && kprobe_fault_handler(regs, trap))
ret = 1;
preempt_enable();
}
return ret;
}
static inline pmd_t *vmalloc_sync_one(pgd_t *pgd, unsigned long address)
{
unsigned index = pgd_index(address);
pgd_t *pgd_k;
pud_t *pud, *pud_k;
pmd_t *pmd, *pmd_k;
pgd += index;
pgd_k = init_mm.pgd + index;
if (!pgd_present(*pgd_k))
return NULL;
pud = pud_offset(pgd, address);
pud_k = pud_offset(pgd_k, address);
if (!pud_present(*pud_k))
return NULL;
if (!pud_present(*pud))
set_pud(pud, *pud_k);
pmd = pmd_offset(pud, address);
pmd_k = pmd_offset(pud_k, address);
if (!pmd_present(*pmd_k))
return NULL;
if (!pmd_present(*pmd))
set_pmd(pmd, *pmd_k);
else {
BUG_ON(pmd_page(*pmd) != pmd_page(*pmd_k));
return NULL;
}
return pmd_k;
}
static noinline int vmalloc_fault(unsigned long address)
{
pgd_t *pgd_k;
pmd_t *pmd_k;
pte_t *pte_k;
if (!(address >= P3SEG && address < P3_ADDR_MAX))
return -1;
pgd_k = get_TTB();
pmd_k = vmalloc_sync_one(pgd_k, address);
if (!pmd_k)
return -1;
pte_k = pte_offset_kernel(pmd_k, address);
if (!pte_present(*pte_k))
return -1;
return 0;
}
static int fault_in_kernel_space(unsigned long address)
{
return address >= TASK_SIZE;
}
asmlinkage void __kprobes do_page_fault(struct pt_regs *regs,
unsigned long writeaccess,
unsigned long address)
{
unsigned long vec;
struct task_struct *tsk;
struct mm_struct *mm;
struct vm_area_struct * vma;
int si_code;
int fault;
siginfo_t info;
tsk = current;
mm = tsk->mm;
si_code = SEGV_MAPERR;
vec = lookup_exception_vector();
if (unlikely(fault_in_kernel_space(address))) {
if (vmalloc_fault(address) >= 0)
return;
if (notify_page_fault(regs, vec))
return;
goto bad_area_nosemaphore;
}
if (unlikely(notify_page_fault(regs, vec)))
return;
if ((regs->sr & SR_IMASK) != SR_IMASK)
local_irq_enable();
perf_sw_event(PERF_COUNT_SW_PAGE_FAULTS, 1, regs, address);
if (in_atomic() || !mm)
goto no_context;
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
if (writeaccess) {
if (!(vma->vm_flags & VM_WRITE))
goto bad_area;
} else {
if (!(vma->vm_flags & (VM_READ | VM_EXEC | VM_WRITE)))
goto bad_area;
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
up_read(&mm->mmap_sem);
return;
bad_area:
up_read(&mm->mmap_sem);
bad_area_nosemaphore:
if (user_mode(regs)) {
info.si_signo = SIGSEGV;
info.si_errno = 0;
info.si_code = si_code;
info.si_addr = (void *) address;
force_sig_info(SIGSEGV, &info, tsk);
return;
}
no_context:
if (fixup_exception(regs))
return;
if (handle_trapped_io(regs, address))
return;
bust_spinlocks(1);
if (oops_may_print()) {
unsigned long page;
if (address < PAGE_SIZE)
printk(KERN_ALERT "Unable to handle kernel NULL "
"pointer dereference");
else
printk(KERN_ALERT "Unable to handle kernel paging "
"request");
printk(" at virtual address %08lx\n", address);
printk(KERN_ALERT "pc = %08lx\n", regs->pc);
page = (unsigned long)get_TTB();
if (page) {
page = ((__typeof__(page) *)page)[address >> PGDIR_SHIFT];
printk(KERN_ALERT "*pde = %08lx\n", page);
if (page & _PAGE_PRESENT) {
page &= PAGE_MASK;
address &= 0x003ff000;
page = ((__typeof__(page) *)
__va(page))[address >>
PAGE_SHIFT];
printk(KERN_ALERT "*pte = %08lx\n", page);
}
}
}
die("Oops", regs, writeaccess);
bust_spinlocks(0);
do_exit(SIGKILL);
out_of_memory:
up_read(&mm->mmap_sem);
if (!user_mode(regs))
goto no_context;
pagefault_out_of_memory();
return;
do_sigbus:
up_read(&mm->mmap_sem);
info.si_signo = SIGBUS;
info.si_errno = 0;
info.si_code = BUS_ADRERR;
info.si_addr = (void *)address;
force_sig_info(SIGBUS, &info, tsk);
if (!user_mode(regs))
goto no_context;
}
asmlinkage int __kprobes
handle_tlbmiss(struct pt_regs *regs, unsigned long writeaccess,
unsigned long address)
{
pgd_t *pgd;
pud_t *pud;
pmd_t *pmd;
pte_t *pte;
pte_t entry;
if (address >= P3SEG && address < P3_ADDR_MAX) {
pgd = pgd_offset_k(address);
} else {
if (unlikely(address >= TASK_SIZE || !current->mm))
return 1;
pgd = pgd_offset(current->mm, address);
}
pud = pud_offset(pgd, address);
if (pud_none_or_clear_bad(pud))
return 1;
pmd = pmd_offset(pud, address);
if (pmd_none_or_clear_bad(pmd))
return 1;
pte = pte_offset_kernel(pmd, address);
entry = *pte;
if (unlikely(pte_none(entry) || pte_not_present(entry)))
return 1;
if (unlikely(writeaccess && !pte_write(entry)))
return 1;
if (writeaccess)
entry = pte_mkdirty(entry);
entry = pte_mkyoung(entry);
set_pte(pte, entry);
#if defined(CONFIG_CPU_SH4) && !defined(CONFIG_SMP)
if (writeaccess == 2)
local_flush_tlb_one(get_asid(), address & PAGE_MASK);
#endif
update_mmu_cache(NULL, address, pte);
return 0;
}
