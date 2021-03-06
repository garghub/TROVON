static __init void *early_alloc(size_t size, int node)
{
return memblock_virt_alloc_try_nid(size, size, __pa(MAX_DMA_ADDRESS),
BOOTMEM_ALLOC_ACCESSIBLE, node);
}
static void __init zero_pte_populate(pmd_t *pmd, unsigned long addr,
unsigned long end)
{
pte_t *pte = pte_offset_kernel(pmd, addr);
pte_t zero_pte;
zero_pte = pfn_pte(PFN_DOWN(__pa(kasan_zero_page)), PAGE_KERNEL);
zero_pte = pte_wrprotect(zero_pte);
while (addr + PAGE_SIZE <= end) {
set_pte_at(&init_mm, addr, pte, zero_pte);
addr += PAGE_SIZE;
pte = pte_offset_kernel(pmd, addr);
}
}
static void __init zero_pmd_populate(pud_t *pud, unsigned long addr,
unsigned long end)
{
pmd_t *pmd = pmd_offset(pud, addr);
unsigned long next;
do {
next = pmd_addr_end(addr, end);
if (IS_ALIGNED(addr, PMD_SIZE) && end - addr >= PMD_SIZE) {
pmd_populate_kernel(&init_mm, pmd, kasan_zero_pte);
continue;
}
if (pmd_none(*pmd)) {
pmd_populate_kernel(&init_mm, pmd,
early_alloc(PAGE_SIZE, NUMA_NO_NODE));
}
zero_pte_populate(pmd, addr, next);
} while (pmd++, addr = next, addr != end);
}
static void __init zero_pud_populate(pgd_t *pgd, unsigned long addr,
unsigned long end)
{
pud_t *pud = pud_offset(pgd, addr);
unsigned long next;
do {
next = pud_addr_end(addr, end);
if (IS_ALIGNED(addr, PUD_SIZE) && end - addr >= PUD_SIZE) {
pmd_t *pmd;
pud_populate(&init_mm, pud, kasan_zero_pmd);
pmd = pmd_offset(pud, addr);
pmd_populate_kernel(&init_mm, pmd, kasan_zero_pte);
continue;
}
if (pud_none(*pud)) {
pud_populate(&init_mm, pud,
early_alloc(PAGE_SIZE, NUMA_NO_NODE));
}
zero_pmd_populate(pud, addr, next);
} while (pud++, addr = next, addr != end);
}
void __init kasan_populate_zero_shadow(const void *shadow_start,
const void *shadow_end)
{
unsigned long addr = (unsigned long)shadow_start;
unsigned long end = (unsigned long)shadow_end;
pgd_t *pgd = pgd_offset_k(addr);
unsigned long next;
do {
next = pgd_addr_end(addr, end);
if (IS_ALIGNED(addr, PGDIR_SIZE) && end - addr >= PGDIR_SIZE) {
pud_t *pud;
pmd_t *pmd;
pgd_populate(&init_mm, pgd, kasan_zero_pud);
pud = pud_offset(pgd, addr);
pud_populate(&init_mm, pud, kasan_zero_pmd);
pmd = pmd_offset(pud, addr);
pmd_populate_kernel(&init_mm, pmd, kasan_zero_pte);
continue;
}
if (pgd_none(*pgd)) {
pgd_populate(&init_mm, pgd,
early_alloc(PAGE_SIZE, NUMA_NO_NODE));
}
zero_pud_populate(pgd, addr, next);
} while (pgd++, addr = next, addr != end);
}
