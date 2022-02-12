static void tegra114_flush_dcache(struct page *page, unsigned long offset,
size_t size)
{
phys_addr_t phys = page_to_phys(page) + offset;
void *virt = page_address(page) + offset;
__cpuc_flush_dcache_area(virt, size);
outer_flush_range(phys, phys + size);
}
