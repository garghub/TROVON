static int __init early_cma(char *p)
{
pr_debug("%s(%s)\n", __func__, p);
size_cmdline = memparse(p, &p);
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
pr_debug("%s(limit %08lx)\n", __func__, (unsigned long)limit);
if (size_cmdline != -1) {
selected_size = size_cmdline;
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
dma_contiguous_reserve_area(selected_size, 0, limit,
&dma_contiguous_default_area);
}
}
static int __init cma_activate_area(struct cma *cma)
{
int bitmap_size = BITS_TO_LONGS(cma->count) * sizeof(long);
unsigned long base_pfn = cma->base_pfn, pfn = base_pfn;
unsigned i = cma->count >> pageblock_order;
struct zone *zone;
cma->bitmap = kzalloc(bitmap_size, GFP_KERNEL);
if (!cma->bitmap)
return -ENOMEM;
WARN_ON_ONCE(!pfn_valid(pfn));
zone = page_zone(pfn_to_page(pfn));
do {
unsigned j;
base_pfn = pfn;
for (j = pageblock_nr_pages; j; --j, pfn++) {
WARN_ON_ONCE(!pfn_valid(pfn));
if (page_zone(pfn_to_page(pfn)) != zone)
return -EINVAL;
}
init_cma_reserved_pageblock(pfn_to_page(base_pfn));
} while (--i);
return 0;
}
static int __init cma_init_reserved_areas(void)
{
int i;
for (i = 0; i < cma_area_count; i++) {
int ret = cma_activate_area(&cma_areas[i]);
if (ret)
return ret;
}
return 0;
}
int __init dma_contiguous_reserve_area(phys_addr_t size, phys_addr_t base,
phys_addr_t limit, struct cma **res_cma)
{
struct cma *cma = &cma_areas[cma_area_count];
phys_addr_t alignment;
int ret = 0;
pr_debug("%s(size %lx, base %08lx, limit %08lx)\n", __func__,
(unsigned long)size, (unsigned long)base,
(unsigned long)limit);
if (cma_area_count == ARRAY_SIZE(cma_areas)) {
pr_err("Not enough slots for CMA reserved regions!\n");
return -ENOSPC;
}
if (!size)
return -EINVAL;
alignment = PAGE_SIZE << max(MAX_ORDER - 1, pageblock_order);
base = ALIGN(base, alignment);
size = ALIGN(size, alignment);
limit &= ~(alignment - 1);
if (base) {
if (memblock_is_region_reserved(base, size) ||
memblock_reserve(base, size) < 0) {
ret = -EBUSY;
goto err;
}
} else {
phys_addr_t addr = __memblock_alloc_base(size, alignment, limit);
if (!addr) {
ret = -ENOMEM;
goto err;
} else {
base = addr;
}
}
cma->base_pfn = PFN_DOWN(base);
cma->count = size >> PAGE_SHIFT;
*res_cma = cma;
cma_area_count++;
pr_info("CMA: reserved %ld MiB at %08lx\n", (unsigned long)size / SZ_1M,
(unsigned long)base);
dma_contiguous_early_fixup(base, size);
return 0;
err:
pr_err("CMA: failed to reserve %ld MiB\n", (unsigned long)size / SZ_1M);
return ret;
}
struct page *dma_alloc_from_contiguous(struct device *dev, int count,
unsigned int align)
{
unsigned long mask, pfn, pageno, start = 0;
struct cma *cma = dev_get_cma_area(dev);
struct page *page = NULL;
int ret;
if (!cma || !cma->count)
return NULL;
if (align > CONFIG_CMA_ALIGNMENT)
align = CONFIG_CMA_ALIGNMENT;
pr_debug("%s(cma %p, count %d, align %d)\n", __func__, (void *)cma,
count, align);
if (!count)
return NULL;
mask = (1 << align) - 1;
mutex_lock(&cma_mutex);
for (;;) {
pageno = bitmap_find_next_zero_area(cma->bitmap, cma->count,
start, count, mask);
if (pageno >= cma->count)
break;
pfn = cma->base_pfn + pageno;
ret = alloc_contig_range(pfn, pfn + count, MIGRATE_CMA);
if (ret == 0) {
bitmap_set(cma->bitmap, pageno, count);
page = pfn_to_page(pfn);
break;
} else if (ret != -EBUSY) {
break;
}
pr_debug("%s(): memory range at %p is busy, retrying\n",
__func__, pfn_to_page(pfn));
start = pageno + mask + 1;
}
mutex_unlock(&cma_mutex);
pr_debug("%s(): returned %p\n", __func__, page);
return page;
}
bool dma_release_from_contiguous(struct device *dev, struct page *pages,
int count)
{
struct cma *cma = dev_get_cma_area(dev);
unsigned long pfn;
if (!cma || !pages)
return false;
pr_debug("%s(page %p)\n", __func__, (void *)pages);
pfn = page_to_pfn(pages);
if (pfn < cma->base_pfn || pfn >= cma->base_pfn + cma->count)
return false;
VM_BUG_ON(pfn + count > cma->base_pfn + cma->count);
mutex_lock(&cma_mutex);
bitmap_clear(cma->bitmap, pfn - cma->base_pfn, count);
free_contig_range(pfn, count);
mutex_unlock(&cma_mutex);
return true;
}
