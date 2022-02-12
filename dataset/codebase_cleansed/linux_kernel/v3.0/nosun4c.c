static void __init should_not_happen(void)
{
prom_printf(shouldnothappen);
prom_halt();
}
unsigned long __init sun4c_paging_init(unsigned long start_mem, unsigned long end_mem)
{
should_not_happen();
return 0;
}
void __init ld_mmu_sun4c(void)
{
should_not_happen();
}
void sun4c_mapioaddr(unsigned long physaddr, unsigned long virt_addr, int bus_type, int rdonly)
{
}
void sun4c_unmapioaddr(unsigned long virt_addr)
{
}
void sun4c_complete_all_stores(void)
{
}
pte_t *sun4c_pte_offset(pmd_t * dir, unsigned long address)
{
return NULL;
}
pte_t *sun4c_pte_offset_kernel(pmd_t *dir, unsigned long address)
{
return NULL;
}
void sun4c_update_mmu_cache(struct vm_area_struct *vma, unsigned long address, pte_t *ptep)
{
}
void __init sun4c_probe_vac(void)
{
should_not_happen();
}
void __init sun4c_probe_memerr_reg(void)
{
should_not_happen();
}
