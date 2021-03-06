static void __init kasan_early_pte_populate(pmd_t *pmd, unsigned long addr,
unsigned long end)
{
pte_t *pte;
unsigned long next;
if (pmd_none(*pmd))
pmd_populate_kernel(&init_mm, pmd, kasan_zero_pte);
pte = pte_offset_kernel(pmd, addr);
do {
next = addr + PAGE_SIZE;
set_pte(pte, pfn_pte(virt_to_pfn(kasan_zero_page),
PAGE_KERNEL));
} while (pte++, addr = next, addr != end && pte_none(*pte));
}
static void __init kasan_early_pmd_populate(pud_t *pud,
unsigned long addr,
unsigned long end)
{
pmd_t *pmd;
unsigned long next;
if (pud_none(*pud))
pud_populate(&init_mm, pud, kasan_zero_pmd);
pmd = pmd_offset(pud, addr);
do {
next = pmd_addr_end(addr, end);
kasan_early_pte_populate(pmd, addr, next);
} while (pmd++, addr = next, addr != end && pmd_none(*pmd));
}
static void __init kasan_early_pud_populate(pgd_t *pgd,
unsigned long addr,
unsigned long end)
{
pud_t *pud;
unsigned long next;
if (pgd_none(*pgd))
pgd_populate(&init_mm, pgd, kasan_zero_pud);
pud = pud_offset(pgd, addr);
do {
next = pud_addr_end(addr, end);
kasan_early_pmd_populate(pud, addr, next);
} while (pud++, addr = next, addr != end && pud_none(*pud));
}
static void __init kasan_map_early_shadow(void)
{
unsigned long addr = KASAN_SHADOW_START;
unsigned long end = KASAN_SHADOW_END;
unsigned long next;
pgd_t *pgd;
pgd = pgd_offset_k(addr);
do {
next = pgd_addr_end(addr, end);
kasan_early_pud_populate(pgd, addr, next);
} while (pgd++, addr = next, addr != end);
}
asmlinkage void __init kasan_early_init(void)
{
BUILD_BUG_ON(KASAN_SHADOW_OFFSET != KASAN_SHADOW_END - (1UL << 61));
BUILD_BUG_ON(!IS_ALIGNED(KASAN_SHADOW_START, PGDIR_SIZE));
BUILD_BUG_ON(!IS_ALIGNED(KASAN_SHADOW_END, PGDIR_SIZE));
kasan_map_early_shadow();
}
static void __init clear_pgds(unsigned long start,
unsigned long end)
{
for (; start < end; start += PGDIR_SIZE)
set_pgd(pgd_offset_k(start), __pgd(0));
}
static void __init cpu_set_ttbr1(unsigned long ttbr1)
{
asm(
" msr ttbr1_el1, %0\n"
" isb"
:
: "r" (ttbr1));
}
void __init kasan_init(void)
{
struct memblock_region *reg;
memcpy(tmp_pg_dir, swapper_pg_dir, sizeof(tmp_pg_dir));
cpu_set_ttbr1(__pa(tmp_pg_dir));
flush_tlb_all();
clear_pgds(KASAN_SHADOW_START, KASAN_SHADOW_END);
kasan_populate_zero_shadow((void *)KASAN_SHADOW_START,
kasan_mem_to_shadow((void *)MODULES_VADDR));
for_each_memblock(memory, reg) {
void *start = (void *)__phys_to_virt(reg->base);
void *end = (void *)__phys_to_virt(reg->base + reg->size);
if (start >= end)
break;
vmemmap_populate((unsigned long)kasan_mem_to_shadow(start),
(unsigned long)kasan_mem_to_shadow(end) + 1,
pfn_to_nid(virt_to_pfn(start)));
}
memset(kasan_zero_page, 0, PAGE_SIZE);
cpu_set_ttbr1(__pa(swapper_pg_dir));
flush_tlb_all();
init_task.kasan_depth = 0;
pr_info("KernelAddressSanitizer initialized\n");
}
