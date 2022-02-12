phys_addr_t v_block_mapped(unsigned long va)
{
unsigned long p = PHYS_IMMR_BASE;
if (__map_without_ltlbs)
return 0;
if (va >= VIRT_IMMR_BASE && va < VIRT_IMMR_BASE + IMMR_SIZE)
return p + va - VIRT_IMMR_BASE;
if (va >= PAGE_OFFSET && va < PAGE_OFFSET + block_mapped_ram)
return __pa(va);
return 0;
}
unsigned long p_block_mapped(phys_addr_t pa)
{
unsigned long p = PHYS_IMMR_BASE;
if (__map_without_ltlbs)
return 0;
if (pa >= p && pa < p + IMMR_SIZE)
return VIRT_IMMR_BASE + pa - p;
if (pa < block_mapped_ram)
return (unsigned long)__va(pa);
return 0;
}
void __init MMU_init_hw(void)
{
#ifdef CONFIG_PIN_TLB_DATA
unsigned long ctr = mfspr(SPRN_MD_CTR) & 0xfe000000;
unsigned long flags = 0xf0 | MD_SPS16K | _PAGE_SHARED | _PAGE_DIRTY;
#ifdef CONFIG_PIN_TLB_IMMR
int i = 29;
#else
int i = 28;
#endif
unsigned long addr = 0;
unsigned long mem = total_lowmem;
for (; i < 32 && mem >= LARGE_PAGE_SIZE_8M; i++) {
mtspr(SPRN_MD_CTR, ctr | (i << 8));
mtspr(SPRN_MD_EPN, (unsigned long)__va(addr) | MD_EVALID);
mtspr(SPRN_MD_TWC, MD_PS8MEG | MD_SVALID);
mtspr(SPRN_MD_RPN, addr | flags | _PAGE_PRESENT);
addr += LARGE_PAGE_SIZE_8M;
mem -= LARGE_PAGE_SIZE_8M;
}
#endif
}
static void __init mmu_mapin_immr(void)
{
unsigned long p = PHYS_IMMR_BASE;
unsigned long v = VIRT_IMMR_BASE;
unsigned long f = pgprot_val(PAGE_KERNEL_NCG);
int offset;
for (offset = 0; offset < IMMR_SIZE; offset += PAGE_SIZE)
map_kernel_page(v + offset, p + offset, f);
}
static void __init mmu_patch_cmp_limit(unsigned int *addr, unsigned long mapped)
{
unsigned int instr = *addr;
instr &= 0xffff0000;
instr |= (unsigned long)__va(mapped) >> 16;
patch_instruction(addr, instr);
}
unsigned long __init mmu_mapin_ram(unsigned long top)
{
unsigned long mapped;
if (__map_without_ltlbs) {
mapped = 0;
mmu_mapin_immr();
#ifndef CONFIG_PIN_TLB_IMMR
patch_instruction(&DTLBMiss_jmp, PPC_INST_NOP);
#endif
#ifndef CONFIG_PIN_TLB_TEXT
mmu_patch_cmp_limit(&ITLBMiss_cmp, 0);
#endif
} else {
mapped = top & ~(LARGE_PAGE_SIZE_8M - 1);
}
mmu_patch_cmp_limit(&DTLBMiss_cmp, mapped);
mmu_patch_cmp_limit(&FixupDAR_cmp, mapped);
if (mapped)
memblock_set_current_limit(mapped);
block_mapped_ram = mapped;
return mapped;
}
void __init setup_initial_memory_limit(phys_addr_t first_memblock_base,
phys_addr_t first_memblock_size)
{
BUG_ON(first_memblock_base != 0);
memblock_set_current_limit(min_t(u64, first_memblock_size, 0x01800000));
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
