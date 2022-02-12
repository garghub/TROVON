void flush_icache_page(struct vm_area_struct *vma, struct page *page)
{
unsigned long start = page_to_phys(page);
unsigned long flags;
flags = smp_lock_cache();
mn10300_local_dcache_flush_page(start);
mn10300_local_icache_inv_page(start);
smp_cache_call(SMP_IDCACHE_INV_FLUSH_RANGE, start, start + PAGE_SIZE);
smp_unlock_cache(flags);
}
static void flush_icache_page_range(unsigned long start, unsigned long end)
{
unsigned long addr, size, off;
struct page *page;
pgd_t *pgd;
pud_t *pud;
pmd_t *pmd;
pte_t *ppte, pte;
off = start & ~PAGE_MASK;
size = end - start;
pgd = pgd_offset(current->mm, start);
if (!pgd || !pgd_val(*pgd))
return;
pud = pud_offset(pgd, start);
if (!pud || !pud_val(*pud))
return;
pmd = pmd_offset(pud, start);
if (!pmd || !pmd_val(*pmd))
return;
ppte = pte_offset_map(pmd, start);
if (!ppte)
return;
pte = *ppte;
pte_unmap(ppte);
if (pte_none(pte))
return;
page = pte_page(pte);
if (!page)
return;
addr = page_to_phys(page);
mn10300_local_dcache_flush_range2(addr + off, size);
mn10300_local_icache_inv_range2(addr + off, size);
smp_cache_call(SMP_IDCACHE_INV_FLUSH_RANGE, start, end);
}
void flush_icache_range(unsigned long start, unsigned long end)
{
unsigned long start_page, end_page;
unsigned long flags;
flags = smp_lock_cache();
if (end > 0x80000000UL) {
if (end > 0xa0000000UL) {
end = 0xa0000000UL;
if (start >= end)
goto done;
}
start_page = (start >= 0x80000000UL) ? start : 0x80000000UL;
mn10300_local_dcache_flush_range(start_page, end);
mn10300_local_icache_inv_range(start_page, end);
smp_cache_call(SMP_IDCACHE_INV_FLUSH_RANGE, start_page, end);
if (start_page == start)
goto done;
end = start_page;
}
start_page = start & PAGE_MASK;
end_page = (end - 1) & PAGE_MASK;
if (start_page == end_page) {
flush_icache_page_range(start, end);
} else if (start_page + 1 == end_page) {
flush_icache_page_range(start, end_page);
flush_icache_page_range(end_page, end);
} else {
mn10300_dcache_flush();
mn10300_icache_inv();
smp_cache_call(SMP_IDCACHE_INV_FLUSH, 0, 0);
}
done:
smp_unlock_cache(flags);
}
