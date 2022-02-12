void local_flush_tlb_all(void)
{
unsigned long flags;
unsigned long old_ASID;
int entry;
local_irq_save(flags);
old_ASID = pevn_get() & ASID_MASK;
pectx_set(0);
entry = tlblock_get();
for (; entry < TLBSIZE; entry++) {
tlbpt_set(entry);
pevn_set(KSEG1);
barrier();
tlb_write_indexed();
}
pevn_set(old_ASID);
local_irq_restore(flags);
}
static inline void
drop_mmu_context(struct mm_struct *mm)
{
unsigned long flags;
local_irq_save(flags);
get_new_mmu_context(mm);
pevn_set(mm->context & ASID_MASK);
local_irq_restore(flags);
}
void local_flush_tlb_mm(struct mm_struct *mm)
{
if (mm->context != 0)
drop_mmu_context(mm);
}
void local_flush_tlb_range(struct vm_area_struct *vma, unsigned long start,
unsigned long end)
{
struct mm_struct *mm = vma->vm_mm;
unsigned long vma_mm_context = mm->context;
if (mm->context != 0) {
unsigned long flags;
int size;
local_irq_save(flags);
size = (end - start + (PAGE_SIZE - 1)) >> PAGE_SHIFT;
if (size <= TLBSIZE) {
int oldpid = pevn_get() & ASID_MASK;
int newpid = vma_mm_context & ASID_MASK;
start &= PAGE_MASK;
end += (PAGE_SIZE - 1);
end &= PAGE_MASK;
while (start < end) {
int idx;
pevn_set(start | newpid);
start += PAGE_SIZE;
barrier();
tlb_probe();
idx = tlbpt_get();
pectx_set(0);
pevn_set(KSEG1);
if (idx < 0)
continue;
tlb_write_indexed();
}
pevn_set(oldpid);
} else {
get_new_mmu_context(mm);
if (mm == current->active_mm)
pevn_set(vma_mm_context & ASID_MASK);
}
local_irq_restore(flags);
}
}
void local_flush_tlb_kernel_range(unsigned long start, unsigned long end)
{
unsigned long flags;
int size;
local_irq_save(flags);
size = (end - start + (PAGE_SIZE - 1)) >> PAGE_SHIFT;
if (size <= TLBSIZE) {
int pid = pevn_get();
start &= PAGE_MASK;
end += PAGE_SIZE - 1;
end &= PAGE_MASK;
while (start < end) {
long idx;
pevn_set(start);
start += PAGE_SIZE;
tlb_probe();
idx = tlbpt_get();
if (idx < 0)
continue;
pectx_set(0);
pevn_set(KSEG1);
barrier();
tlb_write_indexed();
}
pevn_set(pid);
} else {
local_flush_tlb_all();
}
local_irq_restore(flags);
}
void local_flush_tlb_page(struct vm_area_struct *vma, unsigned long page)
{
if (vma && vma->vm_mm->context != 0) {
unsigned long flags;
int oldpid, newpid, idx;
unsigned long vma_ASID = vma->vm_mm->context;
newpid = vma_ASID & ASID_MASK;
page &= PAGE_MASK;
local_irq_save(flags);
oldpid = pevn_get() & ASID_MASK;
pevn_set(page | newpid);
barrier();
tlb_probe();
idx = tlbpt_get();
pectx_set(0);
pevn_set(KSEG1);
if (idx < 0)
goto finish;
barrier();
tlb_write_indexed();
finish:
pevn_set(oldpid);
local_irq_restore(flags);
}
}
void local_flush_tlb_one(unsigned long page)
{
unsigned long flags;
int oldpid, idx;
local_irq_save(flags);
oldpid = pevn_get();
page &= (PAGE_MASK << 1);
pevn_set(page);
barrier();
tlb_probe();
idx = tlbpt_get();
pectx_set(0);
if (idx >= 0) {
pevn_set(KSEG1);
barrier();
tlb_write_indexed();
}
pevn_set(oldpid);
local_irq_restore(flags);
}
void __update_tlb(struct vm_area_struct *vma, unsigned long address, pte_t pte)
{
unsigned long flags;
int idx, pid;
if (current->active_mm != vma->vm_mm)
return;
pid = pevn_get() & ASID_MASK;
local_irq_save(flags);
address &= PAGE_MASK;
pevn_set(address | pid);
barrier();
tlb_probe();
idx = tlbpt_get();
pectx_set(pte_val(pte));
pevn_set(address | pid);
if (idx < 0)
tlb_write_random();
else
tlb_write_indexed();
pevn_set(pid);
local_irq_restore(flags);
}
void tlb_init(void)
{
tlblock_set(0);
local_flush_tlb_all();
memcpy((void *)(EXCEPTION_VECTOR_BASE_ADDR + 0x100),
&score7_FTLB_refill_Handler, 0xFC);
flush_icache_range(EXCEPTION_VECTOR_BASE_ADDR + 0x100,
EXCEPTION_VECTOR_BASE_ADDR + 0x1FC);
}
