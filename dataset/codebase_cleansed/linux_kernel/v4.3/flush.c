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
preempt_disable();
memcpy(dst, src, len);
flush_ptrace_access(vma, page, uaddr, dst, len);
preempt_enable();
}
void __sync_icache_dcache(pte_t pte, unsigned long addr)
{
struct page *page = pte_page(pte);
if (!page_mapping(page))
return;
if (!test_and_set_bit(PG_dcache_clean, &page->flags)) {
__flush_dcache_area(page_address(page),
PAGE_SIZE << compound_order(page));
__flush_icache_all();
} else if (icache_is_aivivt()) {
__flush_icache_all();
}
}
void flush_dcache_page(struct page *page)
{
if (test_bit(PG_dcache_clean, &page->flags))
clear_bit(PG_dcache_clean, &page->flags);
}
void pmdp_splitting_flush(struct vm_area_struct *vma, unsigned long address,
pmd_t *pmdp)
{
pmd_t pmd = pmd_mksplitting(*pmdp);
VM_BUG_ON(address & ~PMD_MASK);
set_pmd_at(vma->vm_mm, address, pmdp, pmd);
kick_all_cpus_sync();
}
