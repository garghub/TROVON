void flush_tlb_range(struct vm_area_struct *vma, unsigned long start,
unsigned long end)
{
struct mm_struct *mm = vma->vm_mm;
if (mm->context.ptbase == current->active_mm->context.ptbase)
__vmclrmap((void *)start, end - start);
}
void flush_tlb_one(unsigned long vaddr)
{
__vmclrmap((void *)vaddr, PAGE_SIZE);
}
void tlb_flush_all(void)
{
__vmclrmap(0, 0xffff0000);
}
void flush_tlb_mm(struct mm_struct *mm)
{
if (current->active_mm->context.ptbase == mm->context.ptbase)
tlb_flush_all();
}
void flush_tlb_page(struct vm_area_struct *vma, unsigned long vaddr)
{
struct mm_struct *mm = vma->vm_mm;
if (mm->context.ptbase == current->active_mm->context.ptbase)
__vmclrmap((void *)vaddr, PAGE_SIZE);
}
void flush_tlb_kernel_range(unsigned long start, unsigned long end)
{
__vmclrmap((void *)start, end - start);
}
