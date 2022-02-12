void dma_cache_sync(struct device *dev, void *vaddr, size_t size, int direction)
{
if (PXSEG(vaddr) == P2SEG)
return;
switch (direction) {
case DMA_FROM_DEVICE:
invalidate_dcache_region(vaddr, size);
break;
case DMA_TO_DEVICE:
clean_dcache_region(vaddr, size);
break;
case DMA_BIDIRECTIONAL:
flush_dcache_region(vaddr, size);
break;
default:
BUG();
}
}
static struct page *__dma_alloc(struct device *dev, size_t size,
dma_addr_t *handle, gfp_t gfp)
{
struct page *page, *free, *end;
int order;
gfp &= ~(__GFP_COMP);
size = PAGE_ALIGN(size);
order = get_order(size);
page = alloc_pages(gfp, order);
if (!page)
return NULL;
split_page(page, order);
invalidate_dcache_region(phys_to_virt(page_to_phys(page)), size);
*handle = page_to_bus(page);
free = page + (size >> PAGE_SHIFT);
end = page + (1 << order);
while (free < end) {
__free_page(free);
free++;
}
return page;
}
static void __dma_free(struct device *dev, size_t size,
struct page *page, dma_addr_t handle)
{
struct page *end = page + (PAGE_ALIGN(size) >> PAGE_SHIFT);
while (page < end)
__free_page(page++);
}
static void *avr32_dma_alloc(struct device *dev, size_t size,
dma_addr_t *handle, gfp_t gfp, unsigned long attrs)
{
struct page *page;
dma_addr_t phys;
page = __dma_alloc(dev, size, handle, gfp);
if (!page)
return NULL;
phys = page_to_phys(page);
if (attrs & DMA_ATTR_WRITE_COMBINE) {
*handle = phys;
return __ioremap(phys, size, _PAGE_BUFFER);
} else {
return phys_to_uncached(phys);
}
}
static void avr32_dma_free(struct device *dev, size_t size,
void *cpu_addr, dma_addr_t handle, unsigned long attrs)
{
struct page *page;
if (attrs & DMA_ATTR_WRITE_COMBINE) {
iounmap(cpu_addr);
page = phys_to_page(handle);
} else {
void *addr = phys_to_cached(uncached_to_phys(cpu_addr));
pr_debug("avr32_dma_free addr %p (phys %08lx) size %u\n",
cpu_addr, (unsigned long)handle, (unsigned)size);
BUG_ON(!virt_addr_valid(addr));
page = virt_to_page(addr);
}
__dma_free(dev, size, page, handle);
}
static dma_addr_t avr32_dma_map_page(struct device *dev, struct page *page,
unsigned long offset, size_t size,
enum dma_data_direction direction, unsigned long attrs)
{
void *cpu_addr = page_address(page) + offset;
if (!(attrs & DMA_ATTR_SKIP_CPU_SYNC))
dma_cache_sync(dev, cpu_addr, size, direction);
return virt_to_bus(cpu_addr);
}
static int avr32_dma_map_sg(struct device *dev, struct scatterlist *sglist,
int nents, enum dma_data_direction direction,
unsigned long attrs)
{
int i;
struct scatterlist *sg;
for_each_sg(sglist, sg, nents, i) {
char *virt;
sg->dma_address = page_to_bus(sg_page(sg)) + sg->offset;
virt = sg_virt(sg);
if (attrs & DMA_ATTR_SKIP_CPU_SYNC)
continue;
dma_cache_sync(dev, virt, sg->length, direction);
}
return nents;
}
static void avr32_dma_sync_single_for_device(struct device *dev,
dma_addr_t dma_handle, size_t size,
enum dma_data_direction direction)
{
dma_cache_sync(dev, bus_to_virt(dma_handle), size, direction);
}
static void avr32_dma_sync_sg_for_device(struct device *dev,
struct scatterlist *sglist, int nents,
enum dma_data_direction direction)
{
int i;
struct scatterlist *sg;
for_each_sg(sglist, sg, nents, i)
dma_cache_sync(dev, sg_virt(sg), sg->length, direction);
}
