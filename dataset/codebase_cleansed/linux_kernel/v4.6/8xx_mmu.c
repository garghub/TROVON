void __init MMU_init_hw(void)
{
}
unsigned long __init mmu_mapin_ram(unsigned long top)
{
unsigned long v, s, mapped;
phys_addr_t p;
v = KERNELBASE;
p = 0;
s = top;
if (__map_without_ltlbs)
return 0;
#ifdef CONFIG_PPC_4K_PAGES
while (s >= LARGE_PAGE_SIZE_8M) {
pmd_t *pmdp;
unsigned long val = p | MD_PS8MEG;
pmdp = pmd_offset(pud_offset(pgd_offset_k(v), v), v);
*pmdp++ = __pmd(val);
*pmdp++ = __pmd(val + LARGE_PAGE_SIZE_4M);
v += LARGE_PAGE_SIZE_8M;
p += LARGE_PAGE_SIZE_8M;
s -= LARGE_PAGE_SIZE_8M;
}
#else
while (s >= LARGE_PAGE_SIZE_64M) {
pmd_t *pmdp;
unsigned long val = p | MD_PS8MEG;
pmdp = pmd_offset(pud_offset(pgd_offset_k(v), v), v);
*pmdp++ = __pmd(val);
v += LARGE_PAGE_SIZE_64M;
p += LARGE_PAGE_SIZE_64M;
s -= LARGE_PAGE_SIZE_64M;
}
#endif
mapped = top - s;
memblock_set_current_limit(mapped);
return mapped;
}
void setup_initial_memory_limit(phys_addr_t first_memblock_base,
phys_addr_t first_memblock_size)
{
BUG_ON(first_memblock_base != 0);
#ifdef CONFIG_PIN_TLB
memblock_set_current_limit(min_t(u64, first_memblock_size, 0x01800000));
#else
memblock_set_current_limit(min_t(u64, first_memblock_size, 0x00800000));
#endif
}
void set_context(unsigned long id, pgd_t *pgd)
{
s16 offset = (s16)(__pa(swapper_pg_dir));
#ifdef CONFIG_BDI_SWITCH
pgd_t **ptr = *(pgd_t ***)(KERNELBASE + 0xf0);
*(ptr + 1) = pgd;
#endif
mtspr(SPRN_M_TW, __pa(pgd) - offset);
mtspr(SPRN_M_CASID, id);
mb();
}
void flush_instruction_cache(void)
{
isync();
mtspr(SPRN_IC_CST, IDC_INVALL);
isync();
}
