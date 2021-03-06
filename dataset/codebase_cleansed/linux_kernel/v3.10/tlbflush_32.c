void local_flush_tlb_page(struct vm_area_struct *vma, unsigned long page)
{
unsigned int cpu = smp_processor_id();
if (vma->vm_mm && cpu_context(cpu, vma->vm_mm) != NO_CONTEXT) {
unsigned long flags;
unsigned long asid;
unsigned long saved_asid = MMU_NO_ASID;
asid = cpu_asid(cpu, vma->vm_mm);
page &= PAGE_MASK;
local_irq_save(flags);
if (vma->vm_mm != current->mm) {
saved_asid = get_asid();
set_asid(asid);
}
local_flush_tlb_one(asid, page);
if (saved_asid != MMU_NO_ASID)
set_asid(saved_asid);
local_irq_restore(flags);
}
}
void local_flush_tlb_range(struct vm_area_struct *vma, unsigned long start,
unsigned long end)
{
struct mm_struct *mm = vma->vm_mm;
unsigned int cpu = smp_processor_id();
if (cpu_context(cpu, mm) != NO_CONTEXT) {
unsigned long flags;
int size;
local_irq_save(flags);
size = (end - start + (PAGE_SIZE - 1)) >> PAGE_SHIFT;
if (size > (MMU_NTLB_ENTRIES/4)) {
cpu_context(cpu, mm) = NO_CONTEXT;
if (mm == current->mm)
activate_context(mm, cpu);
} else {
unsigned long asid;
unsigned long saved_asid = MMU_NO_ASID;
asid = cpu_asid(cpu, mm);
start &= PAGE_MASK;
end += (PAGE_SIZE - 1);
end &= PAGE_MASK;
if (mm != current->mm) {
saved_asid = get_asid();
set_asid(asid);
}
while (start < end) {
local_flush_tlb_one(asid, start);
start += PAGE_SIZE;
}
if (saved_asid != MMU_NO_ASID)
set_asid(saved_asid);
}
local_irq_restore(flags);
}
}
void local_flush_tlb_kernel_range(unsigned long start, unsigned long end)
{
unsigned int cpu = smp_processor_id();
unsigned long flags;
int size;
local_irq_save(flags);
size = (end - start + (PAGE_SIZE - 1)) >> PAGE_SHIFT;
if (size > (MMU_NTLB_ENTRIES/4)) {
local_flush_tlb_all();
} else {
unsigned long asid;
unsigned long saved_asid = get_asid();
asid = cpu_asid(cpu, &init_mm);
start &= PAGE_MASK;
end += (PAGE_SIZE - 1);
end &= PAGE_MASK;
set_asid(asid);
while (start < end) {
local_flush_tlb_one(asid, start);
start += PAGE_SIZE;
}
set_asid(saved_asid);
}
local_irq_restore(flags);
}
void local_flush_tlb_mm(struct mm_struct *mm)
{
unsigned int cpu = smp_processor_id();
if (cpu_context(cpu, mm) != NO_CONTEXT) {
unsigned long flags;
local_irq_save(flags);
cpu_context(cpu, mm) = NO_CONTEXT;
if (mm == current->mm)
activate_context(mm, cpu);
local_irq_restore(flags);
}
}
void __flush_tlb_global(void)
{
unsigned long flags;
local_irq_save(flags);
__raw_writel(__raw_readl(MMUCR) | MMUCR_TI, MMUCR);
local_irq_restore(flags);
}
