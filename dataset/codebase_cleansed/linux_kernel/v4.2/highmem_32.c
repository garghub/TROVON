void *kmap(struct page *page)
{
might_sleep();
if (!PageHighMem(page))
return page_address(page);
return kmap_high(page);
}
void kunmap(struct page *page)
{
if (in_interrupt())
BUG();
if (!PageHighMem(page))
return;
kunmap_high(page);
}
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
BUG_ON(!pte_none(*(kmap_pte-idx)));
set_pte(kmap_pte-idx, mk_pte(page, prot));
arch_flush_lazy_mmu_mode();
return (void *)vaddr;
}
void *kmap_atomic(struct page *page)
{
return kmap_atomic_prot(page, kmap_prot);
}
void *kmap_atomic_pfn(unsigned long pfn)
{
return kmap_atomic_prot_pfn(pfn, kmap_prot);
}
void __kunmap_atomic(void *kvaddr)
{
unsigned long vaddr = (unsigned long) kvaddr & PAGE_MASK;
if (vaddr >= __fix_to_virt(FIX_KMAP_END) &&
vaddr <= __fix_to_virt(FIX_KMAP_BEGIN)) {
int idx, type;
type = kmap_atomic_idx();
idx = type + KM_TYPE_NR * smp_processor_id();
#ifdef CONFIG_DEBUG_HIGHMEM
WARN_ON_ONCE(vaddr != __fix_to_virt(FIX_KMAP_BEGIN + idx));
#endif
kpte_clear_flush(kmap_pte-idx, vaddr);
kmap_atomic_idx_pop();
arch_flush_lazy_mmu_mode();
}
#ifdef CONFIG_DEBUG_HIGHMEM
else {
BUG_ON(vaddr < PAGE_OFFSET);
BUG_ON(vaddr >= (unsigned long)high_memory);
}
#endif
pagefault_enable();
preempt_enable();
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
void __init set_highmem_pages_init(void)
{
struct zone *zone;
int nid;
reset_all_zones_managed_pages();
for_each_zone(zone) {
unsigned long zone_start_pfn, zone_end_pfn;
if (!is_highmem(zone))
continue;
zone_start_pfn = zone->zone_start_pfn;
zone_end_pfn = zone_start_pfn + zone->spanned_pages;
nid = zone_to_nid(zone);
printk(KERN_INFO "Initializing %s for node %d (%08lx:%08lx)\n",
zone->name, nid, zone_start_pfn, zone_end_pfn);
add_highpages_with_active_regions(nid, zone_start_pfn,
zone_end_pfn);
}
}
