static int __init early_cma(char *p)
{
pr_debug("%s(%s)\n", __func__, p);
size_cmdline = memparse(p, &p);
if (*p != '@')
return 0;
base_cmdline = memparse(p + 1, &p);
if (*p != '-') {
limit_cmdline = base_cmdline + size_cmdline;
return 0;
}
limit_cmdline = memparse(p + 1, &p);
return 0;
}
static phys_addr_t __init __maybe_unused cma_early_percent_memory(void)
{
struct memblock_region *reg;
unsigned long total_pages = 0;
for_each_memblock(memory, reg)
total_pages += memblock_region_memory_end_pfn(reg) -
memblock_region_memory_base_pfn(reg);
return (total_pages * CONFIG_CMA_SIZE_PERCENTAGE / 100) << PAGE_SHIFT;
}
static inline __maybe_unused phys_addr_t cma_early_percent_memory(void)
{
return 0;
}
void __init dma_contiguous_reserve(phys_addr_t limit)
{
phys_addr_t selected_size = 0;
phys_addr_t selected_base = 0;
phys_addr_t selected_limit = limit;
bool fixed = false;
pr_debug("%s(limit %08lx)\n", __func__, (unsigned long)limit);
if (size_cmdline != -1) {
selected_size = size_cmdline;
selected_base = base_cmdline;
selected_limit = min_not_zero(limit_cmdline, limit);
if (base_cmdline + size_cmdline == limit_cmdline)
fixed = true;
} else {
#ifdef CONFIG_CMA_SIZE_SEL_MBYTES
selected_size = size_bytes;
#elif defined(CONFIG_CMA_SIZE_SEL_PERCENTAGE)
selected_size = cma_early_percent_memory();
#elif defined(CONFIG_CMA_SIZE_SEL_MIN)
selected_size = min(size_bytes, cma_early_percent_memory());
#elif defined(CONFIG_CMA_SIZE_SEL_MAX)
selected_size = max(size_bytes, cma_early_percent_memory());
#endif
}
if (selected_size && !dma_contiguous_default_area) {
pr_debug("%s: reserving %ld MiB for global area\n", __func__,
(unsigned long)selected_size / SZ_1M);
dma_contiguous_reserve_area(selected_size, selected_base,
selected_limit,
&dma_contiguous_default_area,
fixed);
}
}
int __init dma_contiguous_reserve_area(phys_addr_t size, phys_addr_t base,
phys_addr_t limit, struct cma **res_cma,
bool fixed)
{
int ret;
ret = cma_declare_contiguous(base, size, limit, 0, 0, fixed, res_cma);
if (ret)
return ret;
dma_contiguous_early_fixup(cma_get_base(*res_cma),
cma_get_size(*res_cma));
return 0;
}
struct page *dma_alloc_from_contiguous(struct device *dev, int count,
unsigned int align)
{
if (align > CONFIG_CMA_ALIGNMENT)
align = CONFIG_CMA_ALIGNMENT;
return cma_alloc(dev_get_cma_area(dev), count, align);
}
bool dma_release_from_contiguous(struct device *dev, struct page *pages,
int count)
{
return cma_release(dev_get_cma_area(dev), pages, count);
}
