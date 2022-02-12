int __meminit vmemmap_create_mapping(unsigned long start,
unsigned long page_size,
unsigned long phys)
{
unsigned long i, flags = _PAGE_PRESENT | _PAGE_ACCESSED |
_PAGE_KERNEL_RW;
BUG_ON(mmu_psize_defs[mmu_vmemmap_psize].enc > 0xf);
flags |= mmu_psize_defs[mmu_vmemmap_psize].enc << 8;
for (i = 0; i < page_size; i += PAGE_SIZE)
BUG_ON(map_kernel_page(start + i, phys, flags));
return 0;
}
void vmemmap_remove_mapping(unsigned long start,
unsigned long page_size)
{
}
static __ref void *early_alloc_pgtable(unsigned long size)
{
void *pt;
pt = __va(memblock_alloc_base(size, size, __pa(MAX_DMA_ADDRESS)));
memset(pt, 0, size);
return pt;
}
int map_kernel_page(unsigned long ea, unsigned long pa, unsigned long flags)
{
pgd_t *pgdp;
pud_t *pudp;
pmd_t *pmdp;
pte_t *ptep;
BUILD_BUG_ON(TASK_SIZE_USER64 > PGTABLE_RANGE);
if (slab_is_available()) {
pgdp = pgd_offset_k(ea);
pudp = pud_alloc(&init_mm, pgdp, ea);
if (!pudp)
return -ENOMEM;
pmdp = pmd_alloc(&init_mm, pudp, ea);
if (!pmdp)
return -ENOMEM;
ptep = pte_alloc_kernel(pmdp, ea);
if (!ptep)
return -ENOMEM;
set_pte_at(&init_mm, ea, ptep, pfn_pte(pa >> PAGE_SHIFT,
__pgprot(flags)));
} else {
pgdp = pgd_offset_k(ea);
#ifndef __PAGETABLE_PUD_FOLDED
if (pgd_none(*pgdp)) {
pudp = early_alloc_pgtable(PUD_TABLE_SIZE);
BUG_ON(pudp == NULL);
pgd_populate(&init_mm, pgdp, pudp);
}
#endif
pudp = pud_offset(pgdp, ea);
if (pud_none(*pudp)) {
pmdp = early_alloc_pgtable(PMD_TABLE_SIZE);
BUG_ON(pmdp == NULL);
pud_populate(&init_mm, pudp, pmdp);
}
pmdp = pmd_offset(pudp, ea);
if (!pmd_present(*pmdp)) {
ptep = early_alloc_pgtable(PAGE_SIZE);
BUG_ON(ptep == NULL);
pmd_populate_kernel(&init_mm, pmdp, ptep);
}
ptep = pte_offset_kernel(pmdp, ea);
set_pte_at(&init_mm, ea, ptep, pfn_pte(pa >> PAGE_SHIFT,
__pgprot(flags)));
}
smp_wmb();
return 0;
}
