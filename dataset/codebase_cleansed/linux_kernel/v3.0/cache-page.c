void flush_dcache_page(struct page *page)
{
unsigned long dampr2;
void *vaddr;
dampr2 = __get_DAMPR(2);
vaddr = kmap_atomic_primary(page, __KM_CACHE);
frv_dcache_writeback((unsigned long) vaddr, (unsigned long) vaddr + PAGE_SIZE);
kunmap_atomic_primary(vaddr, __KM_CACHE);
if (dampr2) {
__set_DAMPR(2, dampr2);
__set_IAMPR(2, dampr2);
}
}
void flush_icache_user_range(struct vm_area_struct *vma, struct page *page,
unsigned long start, unsigned long len)
{
unsigned long dampr2;
void *vaddr;
dampr2 = __get_DAMPR(2);
vaddr = kmap_atomic_primary(page, __KM_CACHE);
start = (start & ~PAGE_MASK) | (unsigned long) vaddr;
frv_cache_wback_inv(start, start + len);
kunmap_atomic_primary(vaddr, __KM_CACHE);
if (dampr2) {
__set_DAMPR(2, dampr2);
__set_IAMPR(2, dampr2);
}
}
