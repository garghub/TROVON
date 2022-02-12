void do_BUG(const char *file, int line)
{
bust_spinlocks(1);
printk("kernel BUG at %s:%d!\n", file, line);
}
asmlinkage void do_page_fault(struct pt_regs *regs, unsigned long error_code,
unsigned long address)
{
bust_spinlocks(1);
if (address < PAGE_SIZE)
printk(KERN_ALERT "Unable to handle kernel NULL pointer dereference");
else
printk(KERN_ALERT "Unable to handle kernel paging request");
printk(" at virtual address %08lx\n",address);
printk(" printing bpc:\n");
printk(KERN_ALERT "bpc = %08lx\n", regs->bpc);
die("Oops", regs, error_code);
bust_spinlocks(0);
do_exit(SIGKILL);
}
void update_mmu_cache(struct vm_area_struct *vma, unsigned long addr,
pte_t *ptep)
{
BUG();
}
void local_flush_tlb_page(struct vm_area_struct *vma, unsigned long page)
{
BUG();
}
void local_flush_tlb_range(struct vm_area_struct *vma, unsigned long start,
unsigned long end)
{
BUG();
}
void local_flush_tlb_mm(struct mm_struct *mm)
{
BUG();
}
void local_flush_tlb_all(void)
{
BUG();
}
