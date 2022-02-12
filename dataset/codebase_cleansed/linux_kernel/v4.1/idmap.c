static void idmap_add_pmd(pud_t *pud, unsigned long addr, unsigned long end,
unsigned long prot)
{
pmd_t *pmd;
unsigned long next;
if (pud_none_or_clear_bad(pud) || (pud_val(*pud) & L_PGD_SWAPPER)) {
pmd = pmd_alloc_one(&init_mm, addr);
if (!pmd) {
pr_warn("Failed to allocate identity pmd.\n");
return;
}
if (!pud_none(*pud))
memcpy(pmd, pmd_offset(pud, 0),
PTRS_PER_PMD * sizeof(pmd_t));
pud_populate(&init_mm, pud, pmd);
pmd += pmd_index(addr);
} else
pmd = pmd_offset(pud, addr);
do {
next = pmd_addr_end(addr, end);
*pmd = __pmd((addr & PMD_MASK) | prot);
flush_pmd_entry(pmd);
} while (pmd++, addr = next, addr != end);
}
static void idmap_add_pmd(pud_t *pud, unsigned long addr, unsigned long end,
unsigned long prot)
{
pmd_t *pmd = pmd_offset(pud, addr);
addr = (addr & PMD_MASK) | prot;
pmd[0] = __pmd(addr);
addr += SECTION_SIZE;
pmd[1] = __pmd(addr);
flush_pmd_entry(pmd);
}
static void idmap_add_pud(pgd_t *pgd, unsigned long addr, unsigned long end,
unsigned long prot)
{
pud_t *pud = pud_offset(pgd, addr);
unsigned long next;
do {
next = pud_addr_end(addr, end);
idmap_add_pmd(pud, addr, next, prot);
} while (pud++, addr = next, addr != end);
}
static void identity_mapping_add(pgd_t *pgd, const char *text_start,
const char *text_end, unsigned long prot)
{
unsigned long addr, end;
unsigned long next;
addr = virt_to_idmap(text_start);
end = virt_to_idmap(text_end);
pr_info("Setting up static identity map for 0x%lx - 0x%lx\n", addr, end);
prot |= PMD_TYPE_SECT | PMD_SECT_AP_WRITE | PMD_SECT_AF;
if (cpu_architecture() <= CPU_ARCH_ARMv5TEJ && !cpu_is_xscale())
prot |= PMD_BIT4;
pgd += pgd_index(addr);
do {
next = pgd_addr_end(addr, end);
idmap_add_pud(pgd, addr, next, prot);
} while (pgd++, addr = next, addr != end);
}
static int __init init_static_idmap(void)
{
idmap_pgd = pgd_alloc(&init_mm);
if (!idmap_pgd)
return -ENOMEM;
identity_mapping_add(idmap_pgd, __idmap_text_start,
__idmap_text_end, 0);
flush_cache_louis();
return 0;
}
void setup_mm_for_reboot(void)
{
cpu_switch_mm(idmap_pgd, &init_mm);
local_flush_bp_all();
#ifdef CONFIG_CPU_HAS_ASID
local_flush_tlb_all();
#endif
}
