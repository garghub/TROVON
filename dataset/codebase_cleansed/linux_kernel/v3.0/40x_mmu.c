void __init MMU_init_hw(void)
{
mtspr(SPRN_ZPR, 0x10000000);
flush_instruction_cache();
mtspr(SPRN_DCWR, 0x00000000);
mtspr(SPRN_DCCR, 0xFFFF0000);
mtspr(SPRN_ICCR, 0xFFFF0000);
}
unsigned long __init mmu_mapin_ram(unsigned long top)
{
unsigned long v, s, mapped;
phys_addr_t p;
v = KERNELBASE;
p = 0;
s = total_lowmem;
if (__map_without_ltlbs)
return 0;
while (s >= LARGE_PAGE_SIZE_16M) {
pmd_t *pmdp;
unsigned long val = p | _PMD_SIZE_16M | _PAGE_EXEC | _PAGE_HWWRITE;
pmdp = pmd_offset(pud_offset(pgd_offset_k(v), v), v);
pmd_val(*pmdp++) = val;
pmd_val(*pmdp++) = val;
pmd_val(*pmdp++) = val;
pmd_val(*pmdp++) = val;
v += LARGE_PAGE_SIZE_16M;
p += LARGE_PAGE_SIZE_16M;
s -= LARGE_PAGE_SIZE_16M;
}
while (s >= LARGE_PAGE_SIZE_4M) {
pmd_t *pmdp;
unsigned long val = p | _PMD_SIZE_4M | _PAGE_EXEC | _PAGE_HWWRITE;
pmdp = pmd_offset(pud_offset(pgd_offset_k(v), v), v);
pmd_val(*pmdp) = val;
v += LARGE_PAGE_SIZE_4M;
p += LARGE_PAGE_SIZE_4M;
s -= LARGE_PAGE_SIZE_4M;
}
mapped = total_lowmem - s;
memblock_set_current_limit(mapped);
return mapped;
}
void setup_initial_memory_limit(phys_addr_t first_memblock_base,
phys_addr_t first_memblock_size)
{
BUG_ON(first_memblock_base != 0);
memblock_set_current_limit(min_t(u64, first_memblock_size, 0x00800000));
}
