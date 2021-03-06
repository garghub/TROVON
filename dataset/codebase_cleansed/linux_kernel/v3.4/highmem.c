void *kmap(struct page *page)
{
void *addr;
might_sleep();
if (!PageHighMem(page))
return page_address(page);
addr = kmap_high(page);
flush_tlb_one((unsigned long)addr);
return addr;
}
void kunmap(struct page *page)
{
BUG_ON(in_interrupt());
if (!PageHighMem(page))
return;
kunmap_high(page);
}
void *kmap_atomic(struct page *page)
{
unsigned long vaddr;
int idx, type;
pagefault_disable();
if (!PageHighMem(page))
return page_address(page);
type = kmap_atomic_idx_push();
idx = type + KM_TYPE_NR*smp_processor_id();
vaddr = __fix_to_virt(FIX_KMAP_BEGIN + idx);
#ifdef CONFIG_DEBUG_HIGHMEM
BUG_ON(!pte_none(*(kmap_pte - idx)));
#endif
set_pte(kmap_pte-idx, mk_pte(page, PAGE_KERNEL));
local_flush_tlb_one((unsigned long)vaddr);
return (void*) vaddr;
}
void __kunmap_atomic(void *kvaddr)
{
unsigned long vaddr = (unsigned long) kvaddr & PAGE_MASK;
int type;
if (vaddr < FIXADDR_START) {
pagefault_enable();
return;
}
type = kmap_atomic_idx();
#ifdef CONFIG_DEBUG_HIGHMEM
{
int idx = type + KM_TYPE_NR * smp_processor_id();
BUG_ON(vaddr != __fix_to_virt(FIX_KMAP_BEGIN + idx));
pte_clear(&init_mm, vaddr, kmap_pte-idx);
local_flush_tlb_one(vaddr);
}
#endif
kmap_atomic_idx_pop();
pagefault_enable();
}
void *kmap_atomic_pfn(unsigned long pfn)
{
unsigned long vaddr;
int idx, type;
pagefault_disable();
type = kmap_atomic_idx_push();
idx = type + KM_TYPE_NR*smp_processor_id();
vaddr = __fix_to_virt(FIX_KMAP_BEGIN + idx);
set_pte(kmap_pte-idx, pfn_pte(pfn, PAGE_KERNEL));
flush_tlb_one(vaddr);
return (void*) vaddr;
}
struct page *kmap_atomic_to_page(void *ptr)
{
unsigned long idx, vaddr = (unsigned long)ptr;
pte_t *pte;
if (vaddr < FIXADDR_START)
return virt_to_page(ptr);
idx = virt_to_fix(vaddr);
pte = kmap_pte - (idx - FIX_KMAP_BEGIN);
return pte_page(*pte);
}
void __init kmap_init(void)
{
unsigned long kmap_vstart;
kmap_vstart = __fix_to_virt(FIX_KMAP_BEGIN);
kmap_pte = kmap_get_fixmap_pte(kmap_vstart);
}
