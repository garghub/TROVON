static int __init setcoherentio(char *str)
{
coherentio = 1;
pr_info("Hardware DMA cache coherency (command line)\n");
return 0;
}
static int __init setnocoherentio(char *str)
{
coherentio = 0;
pr_info("Software DMA cache coherency (command line)\n");
return 0;
}
static inline struct page *dma_addr_to_page(struct device *dev,
dma_addr_t dma_addr)
{
return pfn_to_page(
plat_dma_addr_to_phys(dev, dma_addr) >> PAGE_SHIFT);
}
static inline int cpu_needs_post_dma_flush(struct device *dev)
{
return !plat_device_is_coherent(dev) &&
(boot_cpu_type() == CPU_R10000 ||
boot_cpu_type() == CPU_R12000 ||
boot_cpu_type() == CPU_BMIPS5000);
}
static gfp_t massage_gfp_flags(const struct device *dev, gfp_t gfp)
{
gfp_t dma_flag;
gfp &= ~(__GFP_DMA | __GFP_DMA32 | __GFP_HIGHMEM);
#ifdef CONFIG_ISA
if (dev == NULL)
dma_flag = __GFP_DMA;
else
#endif
#if defined(CONFIG_ZONE_DMA32) && defined(CONFIG_ZONE_DMA)
if (dev->coherent_dma_mask < DMA_BIT_MASK(32))
dma_flag = __GFP_DMA;
else if (dev->coherent_dma_mask < DMA_BIT_MASK(64))
dma_flag = __GFP_DMA32;
else
#endif
#if defined(CONFIG_ZONE_DMA32) && !defined(CONFIG_ZONE_DMA)
if (dev->coherent_dma_mask < DMA_BIT_MASK(64))
dma_flag = __GFP_DMA32;
else
#endif
#if defined(CONFIG_ZONE_DMA) && !defined(CONFIG_ZONE_DMA32)
if (dev->coherent_dma_mask < DMA_BIT_MASK(64))
dma_flag = __GFP_DMA;
else
#endif
dma_flag = 0;
gfp |= __GFP_NORETRY;
return gfp | dma_flag;
}
void *dma_alloc_noncoherent(struct device *dev, size_t size,
dma_addr_t * dma_handle, gfp_t gfp)
{
void *ret;
gfp = massage_gfp_flags(dev, gfp);
ret = (void *) __get_free_pages(gfp, get_order(size));
if (ret != NULL) {
memset(ret, 0, size);
*dma_handle = plat_map_dma_mem(dev, ret, size);
}
return ret;
}
static void *mips_dma_alloc_coherent(struct device *dev, size_t size,
dma_addr_t * dma_handle, gfp_t gfp, struct dma_attrs *attrs)
{
void *ret;
if (dma_alloc_from_coherent(dev, size, dma_handle, &ret))
return ret;
gfp = massage_gfp_flags(dev, gfp);
ret = (void *) __get_free_pages(gfp, get_order(size));
if (ret) {
memset(ret, 0, size);
*dma_handle = plat_map_dma_mem(dev, ret, size);
if (!plat_device_is_coherent(dev)) {
dma_cache_wback_inv((unsigned long) ret, size);
if (!hw_coherentio)
ret = UNCAC_ADDR(ret);
}
}
return ret;
}
void dma_free_noncoherent(struct device *dev, size_t size, void *vaddr,
dma_addr_t dma_handle)
{
plat_unmap_dma_mem(dev, dma_handle, size, DMA_BIDIRECTIONAL);
free_pages((unsigned long) vaddr, get_order(size));
}
static void mips_dma_free_coherent(struct device *dev, size_t size, void *vaddr,
dma_addr_t dma_handle, struct dma_attrs *attrs)
{
unsigned long addr = (unsigned long) vaddr;
int order = get_order(size);
if (dma_release_from_coherent(dev, order, vaddr))
return;
plat_unmap_dma_mem(dev, dma_handle, size, DMA_BIDIRECTIONAL);
if (!plat_device_is_coherent(dev) && !hw_coherentio)
addr = CAC_ADDR(addr);
free_pages(addr, get_order(size));
}
static inline void __dma_sync_virtual(void *addr, size_t size,
enum dma_data_direction direction)
{
switch (direction) {
case DMA_TO_DEVICE:
dma_cache_wback((unsigned long)addr, size);
break;
case DMA_FROM_DEVICE:
dma_cache_inv((unsigned long)addr, size);
break;
case DMA_BIDIRECTIONAL:
dma_cache_wback_inv((unsigned long)addr, size);
break;
default:
BUG();
}
}
static inline void __dma_sync(struct page *page,
unsigned long offset, size_t size, enum dma_data_direction direction)
{
size_t left = size;
do {
size_t len = left;
if (PageHighMem(page)) {
void *addr;
if (offset + len > PAGE_SIZE) {
if (offset >= PAGE_SIZE) {
page += offset >> PAGE_SHIFT;
offset &= ~PAGE_MASK;
}
len = PAGE_SIZE - offset;
}
addr = kmap_atomic(page);
__dma_sync_virtual(addr + offset, len, direction);
kunmap_atomic(addr);
} else
__dma_sync_virtual(page_address(page) + offset,
size, direction);
offset = 0;
page++;
left -= len;
} while (left);
}
static void mips_dma_unmap_page(struct device *dev, dma_addr_t dma_addr,
size_t size, enum dma_data_direction direction, struct dma_attrs *attrs)
{
if (cpu_needs_post_dma_flush(dev))
__dma_sync(dma_addr_to_page(dev, dma_addr),
dma_addr & ~PAGE_MASK, size, direction);
plat_unmap_dma_mem(dev, dma_addr, size, direction);
}
static int mips_dma_map_sg(struct device *dev, struct scatterlist *sg,
int nents, enum dma_data_direction direction, struct dma_attrs *attrs)
{
int i;
for (i = 0; i < nents; i++, sg++) {
if (!plat_device_is_coherent(dev))
__dma_sync(sg_page(sg), sg->offset, sg->length,
direction);
#ifdef CONFIG_NEED_SG_DMA_LENGTH
sg->dma_length = sg->length;
#endif
sg->dma_address = plat_map_dma_mem_page(dev, sg_page(sg)) +
sg->offset;
}
return nents;
}
static dma_addr_t mips_dma_map_page(struct device *dev, struct page *page,
unsigned long offset, size_t size, enum dma_data_direction direction,
struct dma_attrs *attrs)
{
if (!plat_device_is_coherent(dev))
__dma_sync(page, offset, size, direction);
return plat_map_dma_mem_page(dev, page) + offset;
}
static void mips_dma_unmap_sg(struct device *dev, struct scatterlist *sg,
int nhwentries, enum dma_data_direction direction,
struct dma_attrs *attrs)
{
int i;
for (i = 0; i < nhwentries; i++, sg++) {
if (!plat_device_is_coherent(dev) &&
direction != DMA_TO_DEVICE)
__dma_sync(sg_page(sg), sg->offset, sg->length,
direction);
plat_unmap_dma_mem(dev, sg->dma_address, sg->length, direction);
}
}
static void mips_dma_sync_single_for_cpu(struct device *dev,
dma_addr_t dma_handle, size_t size, enum dma_data_direction direction)
{
if (cpu_needs_post_dma_flush(dev))
__dma_sync(dma_addr_to_page(dev, dma_handle),
dma_handle & ~PAGE_MASK, size, direction);
}
static void mips_dma_sync_single_for_device(struct device *dev,
dma_addr_t dma_handle, size_t size, enum dma_data_direction direction)
{
plat_extra_sync_for_device(dev);
if (!plat_device_is_coherent(dev))
__dma_sync(dma_addr_to_page(dev, dma_handle),
dma_handle & ~PAGE_MASK, size, direction);
}
static void mips_dma_sync_sg_for_cpu(struct device *dev,
struct scatterlist *sg, int nelems, enum dma_data_direction direction)
{
int i;
if (cpu_needs_post_dma_flush(dev))
for (i = 0; i < nelems; i++, sg++)
__dma_sync(sg_page(sg), sg->offset, sg->length,
direction);
}
static void mips_dma_sync_sg_for_device(struct device *dev,
struct scatterlist *sg, int nelems, enum dma_data_direction direction)
{
int i;
if (!plat_device_is_coherent(dev))
for (i = 0; i < nelems; i++, sg++)
__dma_sync(sg_page(sg), sg->offset, sg->length,
direction);
}
int mips_dma_mapping_error(struct device *dev, dma_addr_t dma_addr)
{
return plat_dma_mapping_error(dev, dma_addr);
}
int mips_dma_supported(struct device *dev, u64 mask)
{
return plat_dma_supported(dev, mask);
}
void dma_cache_sync(struct device *dev, void *vaddr, size_t size,
enum dma_data_direction direction)
{
BUG_ON(direction == DMA_NONE);
plat_extra_sync_for_device(dev);
if (!plat_device_is_coherent(dev))
__dma_sync_virtual(vaddr, size, direction);
}
static int __init mips_dma_init(void)
{
dma_debug_init(PREALLOC_DMA_DEBUG_ENTRIES);
return 0;
}
