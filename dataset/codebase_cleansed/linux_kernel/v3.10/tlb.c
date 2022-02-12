void flush_tlb_all(void)
{
int i;
unsigned long num_tlb_sets;
num_tlb_sets = NUM_ITLB_SETS;
for (i = 0; i < num_tlb_sets; i++) {
mtspr_off(SPR_DTLBMR_BASE(0), i, 0);
mtspr_off(SPR_ITLBMR_BASE(0), i, 0);
}
}
void flush_tlb_page(struct vm_area_struct *vma, unsigned long addr)
{
if (have_dtlbeir)
flush_dtlb_page_eir(addr);
else
flush_dtlb_page_no_eir(addr);
if (have_itlbeir)
flush_itlb_page_eir(addr);
else
flush_itlb_page_no_eir(addr);
}
void flush_tlb_range(struct vm_area_struct *vma,
unsigned long start, unsigned long end)
{
int addr;
bool dtlbeir;
bool itlbeir;
dtlbeir = have_dtlbeir;
itlbeir = have_itlbeir;
for (addr = start; addr < end; addr += PAGE_SIZE) {
if (dtlbeir)
flush_dtlb_page_eir(addr);
else
flush_dtlb_page_no_eir(addr);
if (itlbeir)
flush_itlb_page_eir(addr);
else
flush_itlb_page_no_eir(addr);
}
}
void flush_tlb_mm(struct mm_struct *mm)
{
flush_tlb_all();
}
void switch_mm(struct mm_struct *prev, struct mm_struct *next,
struct task_struct *next_tsk)
{
current_pgd = next->pgd;
if (prev != next)
flush_tlb_mm(prev);
}
int init_new_context(struct task_struct *tsk, struct mm_struct *mm)
{
mm->context = NO_CONTEXT;
return 0;
}
void destroy_context(struct mm_struct *mm)
{
flush_tlb_mm(mm);
}
void __init tlb_init(void)
{
}
