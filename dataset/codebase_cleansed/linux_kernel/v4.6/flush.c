void flush_cache_range(struct vm_area_struct *vma, unsigned long start,
unsigned long end)
{
if (vma->vm_flags & VM_EXEC)
__flush_icache_all();
}
static void sync_icache_aliases(void *kaddr, unsigned long len)
{
unsigned long addr = (unsigned long)kaddr;
if (icache_is_aliasing()) {
__clean_dcache_area_pou(kaddr, len);
__flush_icache_all();
} else {
flush_icache_range(addr, addr + len);
}
}
static void flush_ptrace_access(struct vm_area_struct *vma, struct page *page,
unsigned long uaddr, void *kaddr,
unsigned long len)
{
if (vma->vm_flags & VM_EXEC)
sync_icache_aliases(kaddr, len);
}
void copy_to_user_page(struct vm_area_struct *vma, struct page *page,
unsigned long uaddr, void *dst, const void *src,
unsigned long len)
{
memcpy(dst, src, len);
flush_ptrace_access(vma, page, uaddr, dst, len);
}
void __sync_icache_dcache(pte_t pte, unsigned long addr)
{
struct page *page = pte_page(pte);
if (!page_mapping(page))
return;
if (!test_and_set_bit(PG_dcache_clean, &page->flags))
sync_icache_aliases(page_address(page),
PAGE_SIZE << compound_order(page));
else if (icache_is_aivivt())
__flush_icache_all();
}
void flush_dcache_page(struct page *page)
{
if (test_bit(PG_dcache_clean, &page->flags))
clear_bit(PG_dcache_clean, &page->flags);
}
