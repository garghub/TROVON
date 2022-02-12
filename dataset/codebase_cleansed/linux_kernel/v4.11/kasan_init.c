static void __init kasan_early_pte_populate(pmd_t *pmd, unsigned long addr,
unsigned long end)
{
pte_t *pte;
unsigned long next;
if (pmd_none(*pmd))
__pmd_populate(pmd, __pa_symbol(kasan_zero_pte), PMD_TYPE_TABLE);
pte = pte_offset_kimg(pmd, addr);
do {
next = addr + PAGE_SIZE;
set_pte(pte, pfn_pte(sym_to_pfn(kasan_zero_page),
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
__pud_populate(pud, __pa_symbol(kasan_zero_pmd), PMD_TYPE_TABLE);
pmd = pmd_offset_kimg(pud, addr);
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
__pgd_populate(pgd, __pa_symbol(kasan_zero_pud), PUD_TYPE_TABLE);
pud = pud_offset_kimg(pgd, addr);
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
void __init kasan_copy_shadow(pgd_t *pgdir)
{
pgd_t *pgd, *pgd_new, *pgd_end;
pgd = pgd_offset_k(KASAN_SHADOW_START);
pgd_end = pgd_offset_k(KASAN_SHADOW_END);
pgd_new = pgd_offset_raw(pgdir, KASAN_SHADOW_START);
do {
set_pgd(pgd_new, *pgd);
} while (pgd++, pgd_new++, pgd != pgd_end);
}
static void __init clear_pgds(unsigned long start,
unsigned long end)
{
for (; start < end; start += PGDIR_SIZE)
set_pgd(pgd_offset_k(start), __pgd(0));
}
void __init kasan_init(void)
{
u64 kimg_shadow_start, kimg_shadow_end;
u64 mod_shadow_start, mod_shadow_end;
struct memblock_region *reg;
int i;
kimg_shadow_start = (u64)kasan_mem_to_shadow(_text);
kimg_shadow_end = (u64)kasan_mem_to_shadow(_end);
mod_shadow_start = (u64)kasan_mem_to_shadow((void *)MODULES_VADDR);
mod_shadow_end = (u64)kasan_mem_to_shadow((void *)MODULES_END);
memcpy(tmp_pg_dir, swapper_pg_dir, sizeof(tmp_pg_dir));
dsb(ishst);
cpu_replace_ttbr1(lm_alias(tmp_pg_dir));
clear_pgds(KASAN_SHADOW_START, KASAN_SHADOW_END);
vmemmap_populate(kimg_shadow_start, kimg_shadow_end,
pfn_to_nid(virt_to_pfn(lm_alias(_text))));
kimg_shadow_start = round_down(kimg_shadow_start, SWAPPER_BLOCK_SIZE);
kimg_shadow_end = round_up(kimg_shadow_end, SWAPPER_BLOCK_SIZE);
kasan_populate_zero_shadow((void *)KASAN_SHADOW_START,
(void *)mod_shadow_start);
kasan_populate_zero_shadow((void *)kimg_shadow_end,
kasan_mem_to_shadow((void *)PAGE_OFFSET));
if (kimg_shadow_start > mod_shadow_end)
kasan_populate_zero_shadow((void *)mod_shadow_end,
(void *)kimg_shadow_start);
for_each_memblock(memory, reg) {
void *start = (void *)__phys_to_virt(reg->base);
void *end = (void *)__phys_to_virt(reg->base + reg->size);
if (start >= end)
break;
vmemmap_populate((unsigned long)kasan_mem_to_shadow(start),
(unsigned long)kasan_mem_to_shadow(end) + 1,
pfn_to_nid(virt_to_pfn(start)));
}
for (i = 0; i < PTRS_PER_PTE; i++)
set_pte(&kasan_zero_pte[i],
pfn_pte(sym_to_pfn(kasan_zero_page), PAGE_KERNEL_RO));
memset(kasan_zero_page, 0, PAGE_SIZE);
cpu_replace_ttbr1(lm_alias(swapper_pg_dir));
init_task.kasan_depth = 0;
pr_info("KernelAddressSanitizer initialized\n");
}
