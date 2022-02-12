static unsigned int sh_phys_to_pte(struct isp_mmu *mmu,
phys_addr_t phys)
{
return phys >> ISP_PAGE_OFFSET;
}
static phys_addr_t sh_pte_to_phys(struct isp_mmu *mmu,
unsigned int pte)
{
unsigned int mask = mmu->driver->pte_valid_mask;
return (phys_addr_t)((pte & ~mask) << ISP_PAGE_OFFSET);
}
static int sh_set_pd_base(struct isp_mmu *mmu,
phys_addr_t phys)
{
unsigned int pte = sh_phys_to_pte(mmu, phys);
atomisp_css_mmu_set_page_table_base_index(HOST_ADDRESS(pte));
return 0;
}
static unsigned int sh_get_pd_base(struct isp_mmu *mmu,
phys_addr_t phys)
{
unsigned int pte = sh_phys_to_pte(mmu, phys);
return HOST_ADDRESS(pte);
}
static void sh_tlb_flush(struct isp_mmu *mmu)
{
atomisp_css_mmu_invalidate_cache();
}
