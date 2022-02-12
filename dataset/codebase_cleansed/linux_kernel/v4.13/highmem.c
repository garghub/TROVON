void *kmap_atomic_prot(struct page *page, pgprot_t prot)
{
unsigned long vaddr;
int idx, type;
preempt_disable();
pagefault_disable();
if (!PageHighMem(page))
return page_address(page);
type = kmap_atomic_idx_push();
idx = type + KM_TYPE_NR*smp_processor_id();
vaddr = __fix_to_virt(FIX_KMAP_BEGIN + idx);
#ifdef CONFIG_DEBUG_HIGHMEM
BUG_ON(!pte_none(*(kmap_pte-idx)));
#endif
set_pte_at(&init_mm, vaddr, kmap_pte-idx, mk_pte(page, prot));
local_flush_tlb_page(NULL, vaddr);
return (void *) vaddr;
}
void __kunmap_atomic(void *kvaddr)
{
unsigned long vaddr = (unsigned long) kvaddr & PAGE_MASK;
int type;
unsigned int idx;
if (vaddr < __fix_to_virt(FIX_KMAP_END)) {
pagefault_enable();
preempt_enable();
return;
}
type = kmap_atomic_idx();
idx = type + KM_TYPE_NR * smp_processor_id();
#ifdef CONFIG_DEBUG_HIGHMEM
BUG_ON(vaddr != __fix_to_virt(FIX_KMAP_BEGIN + idx));
#endif
pte_clear(&init_mm, vaddr, kmap_pte-idx);
local_flush_tlb_page(NULL, vaddr);
kmap_atomic_idx_pop();
pagefault_enable();
preempt_enable();
}
