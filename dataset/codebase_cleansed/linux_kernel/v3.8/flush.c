void flush_cache_range(struct vm_area_struct *vma, unsigned long start,
unsigned long end)
{
if (vma->vm_flags & VM_EXEC)
__flush_icache_all();
}
static void flush_ptrace_access(struct vm_area_struct *vma, struct page *page,
unsigned long uaddr, void *kaddr,
unsigned long len)
{
if (vma->vm_flags & VM_EXEC) {
unsigned long addr = (unsigned long)kaddr;
if (icache_is_aliasing()) {
__flush_dcache_area(kaddr, len);
__flush_icache_all();
} else {
flush_icache_range(addr, addr + len);
}
}
}
void copy_to_user_page(struct vm_area_struct *vma, struct page *page,
unsigned long uaddr, void *dst, const void *src,
unsigned long len)
{
#ifdef CONFIG_SMP
preempt_disable();
#endif
memcpy(dst, src, len);
flush_ptrace_access(vma, page, uaddr, dst, len);
#ifdef CONFIG_SMP
preempt_enable();
#endif
}
void __flush_dcache_page(struct page *page)
{
__flush_dcache_area(page_address(page), PAGE_SIZE);
}
void __sync_icache_dcache(pte_t pte, unsigned long addr)
{
unsigned long pfn;
struct page *page;
pfn = pte_pfn(pte);
if (!pfn_valid(pfn))
return;
page = pfn_to_page(pfn);
if (!test_and_set_bit(PG_dcache_clean, &page->flags)) {
__flush_dcache_page(page);
__flush_icache_all();
} else if (icache_is_aivivt()) {
__flush_icache_all();
}
}
void flush_dcache_page(struct page *page)
{
struct address_space *mapping;
if (page == ZERO_PAGE(0))
return;
mapping = page_mapping(page);
if (mapping && mapping_mapped(mapping)) {
__flush_dcache_page(page);
__flush_icache_all();
set_bit(PG_dcache_clean, &page->flags);
} else {
clear_bit(PG_dcache_clean, &page->flags);
}
}
