static int __init setcoherentio(char *str)
{
coherentio = IO_COHERENCE_ENABLED;
pr_info("Hardware DMA cache coherency (command line)\n");
return 0;
}
static int __init setnocoherentio(char *str)
{
coherentio = IO_COHERENCE_DISABLED;
pr_info("Software DMA cache coherency (command line)\n");
return 0;
}
static inline struct page *dma_addr_to_page(struct device *dev,
dma_addr_t dma_addr)
{
return pfn_to_page(
plat_dma_addr_to_phys(dev, dma_addr) >> PAGE_SHIFT);
}
static inline bool cpu_needs_post_dma_flush(struct device *dev)
{
if (plat_device_is_coherent(dev))
return false;
switch (boot_cpu_type()) {
case CPU_R10000:
case CPU_R12000:
case CPU_BMIPS5000:
return true;
default:
return cpu_has_maar;
}
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
if (dev == NULL || dev->coherent_dma_mask < DMA_BIT_MASK(32))
dma_flag = __GFP_DMA;
else if (dev->coherent_dma_mask < DMA_BIT_MASK(64))
dma_flag = __GFP_DMA32;
else
#endif
#if defined(CONFIG_ZONE_DMA32) && !defined(CONFIG_ZONE_DMA)
if (dev == NULL || dev->coherent_dma_mask < DMA_BIT_MASK(64))
dma_flag = __GFP_DMA32;
else
#endif
#if defined(CONFIG_ZONE_DMA) && !defined(CONFIG_ZONE_DMA32)
if (dev == NULL ||
dev->coherent_dma_mask < DMA_BIT_MASK(sizeof(phys_addr_t) * 8))
dma_flag = __GFP_DMA;
else
#endif
dma_flag = 0;
gfp |= __GFP_NORETRY;
return gfp | dma_flag;
}
static void *mips_dma_alloc_coherent(struct device *dev, size_t size,
dma_addr_t *dma_handle, gfp_t gfp, unsigned long attrs)
{
void *ret;
struct page *page = NULL;
unsigned int count = PAGE_ALIGN(size) >> PAGE_SHIFT;
gfp = massage_gfp_flags(dev, gfp);
if (IS_ENABLED(CONFIG_DMA_CMA) && gfpflags_allow_blocking(gfp))
page = dma_alloc_from_contiguous(dev, count, get_order(size),
gfp);
if (!page)
page = alloc_pages(gfp, get_order(size));
if (!page)
return NULL;
ret = page_address(page);
memset(ret, 0, size);
*dma_handle = plat_map_dma_mem(dev, ret, size);
if (!(attrs & DMA_ATTR_NON_CONSISTENT) &&
!plat_device_is_coherent(dev)) {
dma_cache_wback_inv((unsigned long) ret, size);
ret = UNCAC_ADDR(ret);
}
return ret;
}
static void mips_dma_free_coherent(struct device *dev, size_t size, void *vaddr,
dma_addr_t dma_handle, unsigned long attrs)
{
unsigned long addr = (unsigned long) vaddr;
unsigned int count = PAGE_ALIGN(size) >> PAGE_SHIFT;
struct page *page = NULL;
plat_unmap_dma_mem(dev, dma_handle, size, DMA_BIDIRECTIONAL);
if (!(attrs & DMA_ATTR_NON_CONSISTENT) && !plat_device_is_coherent(dev))
addr = CAC_ADDR(addr);
page = virt_to_page((void *) addr);
if (!dma_release_from_contiguous(dev, page, count))
__free_pages(page, get_order(size));
}
static int mips_dma_mmap(struct device *dev, struct vm_area_struct *vma,
void *cpu_addr, dma_addr_t dma_addr, size_t size,
unsigned long attrs)
{
unsigned long user_count = (vma->vm_end - vma->vm_start) >> PAGE_SHIFT;
unsigned long count = PAGE_ALIGN(size) >> PAGE_SHIFT;
unsigned long addr = (unsigned long)cpu_addr;
unsigned long off = vma->vm_pgoff;
unsigned long pfn;
int ret = -ENXIO;
if (!plat_device_is_coherent(dev))
addr = CAC_ADDR(addr);
pfn = page_to_pfn(virt_to_page((void *)addr));
if (attrs & DMA_ATTR_WRITE_COMBINE)
vma->vm_page_prot = pgprot_writecombine(vma->vm_page_prot);
else
vma->vm_page_prot = pgprot_noncached(vma->vm_page_prot);
if (dma_mmap_from_dev_coherent(dev, vma, cpu_addr, size, &ret))
return ret;
if (off < count && user_count <= (count - off)) {
ret = remap_pfn_range(vma, vma->vm_start,
pfn + off,
user_count << PAGE_SHIFT,
vma->vm_page_prot);
}
return ret;
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
size_t size, enum dma_data_direction direction, unsigned long attrs)
{
if (cpu_needs_post_dma_flush(dev) && !(attrs & DMA_ATTR_SKIP_CPU_SYNC))
__dma_sync(dma_addr_to_page(dev, dma_addr),
dma_addr & ~PAGE_MASK, size, direction);
plat_post_dma_flush(dev);
plat_unmap_dma_mem(dev, dma_addr, size, direction);
}
static int mips_dma_map_sg(struct device *dev, struct scatterlist *sglist,
int nents, enum dma_data_direction direction, unsigned long attrs)
{
int i;
struct scatterlist *sg;
for_each_sg(sglist, sg, nents, i) {
if (!plat_device_is_coherent(dev) &&
!(attrs & DMA_ATTR_SKIP_CPU_SYNC))
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
unsigned long attrs)
{
if (!plat_device_is_coherent(dev) && !(attrs & DMA_ATTR_SKIP_CPU_SYNC))
__dma_sync(page, offset, size, direction);
return plat_map_dma_mem_page(dev, page) + offset;
}
static void mips_dma_unmap_sg(struct device *dev, struct scatterlist *sglist,
int nhwentries, enum dma_data_direction direction,
unsigned long attrs)
{
int i;
struct scatterlist *sg;
for_each_sg(sglist, sg, nhwentries, i) {
if (!plat_device_is_coherent(dev) &&
!(attrs & DMA_ATTR_SKIP_CPU_SYNC) &&
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
plat_post_dma_flush(dev);
}
static void mips_dma_sync_single_for_device(struct device *dev,
dma_addr_t dma_handle, size_t size, enum dma_data_direction direction)
{
if (!plat_device_is_coherent(dev))
__dma_sync(dma_addr_to_page(dev, dma_handle),
dma_handle & ~PAGE_MASK, size, direction);
}
static void mips_dma_sync_sg_for_cpu(struct device *dev,
struct scatterlist *sglist, int nelems,
enum dma_data_direction direction)
{
int i;
struct scatterlist *sg;
if (cpu_needs_post_dma_flush(dev)) {
for_each_sg(sglist, sg, nelems, i) {
__dma_sync(sg_page(sg), sg->offset, sg->length,
direction);
}
}
plat_post_dma_flush(dev);
}
static void mips_dma_sync_sg_for_device(struct device *dev,
struct scatterlist *sglist, int nelems,
enum dma_data_direction direction)
{
int i;
struct scatterlist *sg;
if (!plat_device_is_coherent(dev)) {
for_each_sg(sglist, sg, nelems, i) {
__dma_sync(sg_page(sg), sg->offset, sg->length,
direction);
}
}
}
static int mips_dma_mapping_error(struct device *dev, dma_addr_t dma_addr)
{
return 0;
}
static int mips_dma_supported(struct device *dev, u64 mask)
{
return plat_dma_supported(dev, mask);
}
void dma_cache_sync(struct device *dev, void *vaddr, size_t size,
enum dma_data_direction direction)
{
BUG_ON(direction == DMA_NONE);
if (!plat_device_is_coherent(dev))
__dma_sync_virtual(vaddr, size, direction);
}
static int __init mips_dma_init(void)
{
dma_debug_init(PREALLOC_DMA_DEBUG_ENTRIES);
return 0;
}
