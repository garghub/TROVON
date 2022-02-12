static pgprot_t __get_dma_pgprot(struct dma_attrs *attrs, pgprot_t prot,
bool coherent)
{
if (!coherent || dma_get_attr(DMA_ATTR_WRITE_COMBINE, attrs))
return pgprot_writecombine(prot);
return prot;
}
static void *__dma_alloc_coherent(struct device *dev, size_t size,
dma_addr_t *dma_handle, gfp_t flags,
struct dma_attrs *attrs)
{
if (dev == NULL) {
WARN_ONCE(1, "Use an actual device structure for DMA allocation\n");
return NULL;
}
if (IS_ENABLED(CONFIG_ZONE_DMA) &&
dev->coherent_dma_mask <= DMA_BIT_MASK(32))
flags |= GFP_DMA;
if (IS_ENABLED(CONFIG_DMA_CMA)) {
struct page *page;
size = PAGE_ALIGN(size);
page = dma_alloc_from_contiguous(dev, size >> PAGE_SHIFT,
get_order(size));
if (!page)
return NULL;
*dma_handle = phys_to_dma(dev, page_to_phys(page));
return page_address(page);
} else {
return swiotlb_alloc_coherent(dev, size, dma_handle, flags);
}
}
static void __dma_free_coherent(struct device *dev, size_t size,
void *vaddr, dma_addr_t dma_handle,
struct dma_attrs *attrs)
{
if (dev == NULL) {
WARN_ONCE(1, "Use an actual device structure for DMA allocation\n");
return;
}
if (IS_ENABLED(CONFIG_DMA_CMA)) {
phys_addr_t paddr = dma_to_phys(dev, dma_handle);
dma_release_from_contiguous(dev,
phys_to_page(paddr),
size >> PAGE_SHIFT);
} else {
swiotlb_free_coherent(dev, size, vaddr, dma_handle);
}
}
static void *__dma_alloc_noncoherent(struct device *dev, size_t size,
dma_addr_t *dma_handle, gfp_t flags,
struct dma_attrs *attrs)
{
struct page *page, **map;
void *ptr, *coherent_ptr;
int order, i;
size = PAGE_ALIGN(size);
order = get_order(size);
ptr = __dma_alloc_coherent(dev, size, dma_handle, flags, attrs);
if (!ptr)
goto no_mem;
map = kmalloc(sizeof(struct page *) << order, flags & ~GFP_DMA);
if (!map)
goto no_map;
__dma_flush_range(ptr, ptr + size);
page = virt_to_page(ptr);
for (i = 0; i < (size >> PAGE_SHIFT); i++)
map[i] = page + i;
coherent_ptr = vmap(map, size >> PAGE_SHIFT, VM_MAP,
__get_dma_pgprot(attrs, __pgprot(PROT_NORMAL_NC), false));
kfree(map);
if (!coherent_ptr)
goto no_map;
return coherent_ptr;
no_map:
__dma_free_coherent(dev, size, ptr, *dma_handle, attrs);
no_mem:
*dma_handle = ~0;
return NULL;
}
static void __dma_free_noncoherent(struct device *dev, size_t size,
void *vaddr, dma_addr_t dma_handle,
struct dma_attrs *attrs)
{
void *swiotlb_addr = phys_to_virt(dma_to_phys(dev, dma_handle));
vunmap(vaddr);
__dma_free_coherent(dev, size, swiotlb_addr, dma_handle, attrs);
}
static dma_addr_t __swiotlb_map_page(struct device *dev, struct page *page,
unsigned long offset, size_t size,
enum dma_data_direction dir,
struct dma_attrs *attrs)
{
dma_addr_t dev_addr;
dev_addr = swiotlb_map_page(dev, page, offset, size, dir, attrs);
__dma_map_area(phys_to_virt(dma_to_phys(dev, dev_addr)), size, dir);
return dev_addr;
}
static void __swiotlb_unmap_page(struct device *dev, dma_addr_t dev_addr,
size_t size, enum dma_data_direction dir,
struct dma_attrs *attrs)
{
__dma_unmap_area(phys_to_virt(dma_to_phys(dev, dev_addr)), size, dir);
swiotlb_unmap_page(dev, dev_addr, size, dir, attrs);
}
static int __swiotlb_map_sg_attrs(struct device *dev, struct scatterlist *sgl,
int nelems, enum dma_data_direction dir,
struct dma_attrs *attrs)
{
struct scatterlist *sg;
int i, ret;
ret = swiotlb_map_sg_attrs(dev, sgl, nelems, dir, attrs);
for_each_sg(sgl, sg, ret, i)
__dma_map_area(phys_to_virt(dma_to_phys(dev, sg->dma_address)),
sg->length, dir);
return ret;
}
static void __swiotlb_unmap_sg_attrs(struct device *dev,
struct scatterlist *sgl, int nelems,
enum dma_data_direction dir,
struct dma_attrs *attrs)
{
struct scatterlist *sg;
int i;
for_each_sg(sgl, sg, nelems, i)
__dma_unmap_area(phys_to_virt(dma_to_phys(dev, sg->dma_address)),
sg->length, dir);
swiotlb_unmap_sg_attrs(dev, sgl, nelems, dir, attrs);
}
static void __swiotlb_sync_single_for_cpu(struct device *dev,
dma_addr_t dev_addr, size_t size,
enum dma_data_direction dir)
{
__dma_unmap_area(phys_to_virt(dma_to_phys(dev, dev_addr)), size, dir);
swiotlb_sync_single_for_cpu(dev, dev_addr, size, dir);
}
static void __swiotlb_sync_single_for_device(struct device *dev,
dma_addr_t dev_addr, size_t size,
enum dma_data_direction dir)
{
swiotlb_sync_single_for_device(dev, dev_addr, size, dir);
__dma_map_area(phys_to_virt(dma_to_phys(dev, dev_addr)), size, dir);
}
static void __swiotlb_sync_sg_for_cpu(struct device *dev,
struct scatterlist *sgl, int nelems,
enum dma_data_direction dir)
{
struct scatterlist *sg;
int i;
for_each_sg(sgl, sg, nelems, i)
__dma_unmap_area(phys_to_virt(dma_to_phys(dev, sg->dma_address)),
sg->length, dir);
swiotlb_sync_sg_for_cpu(dev, sgl, nelems, dir);
}
static void __swiotlb_sync_sg_for_device(struct device *dev,
struct scatterlist *sgl, int nelems,
enum dma_data_direction dir)
{
struct scatterlist *sg;
int i;
swiotlb_sync_sg_for_device(dev, sgl, nelems, dir);
for_each_sg(sgl, sg, nelems, i)
__dma_map_area(phys_to_virt(dma_to_phys(dev, sg->dma_address)),
sg->length, dir);
}
static int __dma_common_mmap(struct device *dev, struct vm_area_struct *vma,
void *cpu_addr, dma_addr_t dma_addr, size_t size)
{
int ret = -ENXIO;
unsigned long nr_vma_pages = (vma->vm_end - vma->vm_start) >>
PAGE_SHIFT;
unsigned long nr_pages = PAGE_ALIGN(size) >> PAGE_SHIFT;
unsigned long pfn = dma_to_phys(dev, dma_addr) >> PAGE_SHIFT;
unsigned long off = vma->vm_pgoff;
if (dma_mmap_from_coherent(dev, vma, cpu_addr, size, &ret))
return ret;
if (off < nr_pages && nr_vma_pages <= (nr_pages - off)) {
ret = remap_pfn_range(vma, vma->vm_start,
pfn + off,
vma->vm_end - vma->vm_start,
vma->vm_page_prot);
}
return ret;
}
static int __swiotlb_mmap_noncoherent(struct device *dev,
struct vm_area_struct *vma,
void *cpu_addr, dma_addr_t dma_addr, size_t size,
struct dma_attrs *attrs)
{
vma->vm_page_prot = __get_dma_pgprot(attrs, vma->vm_page_prot, false);
return __dma_common_mmap(dev, vma, cpu_addr, dma_addr, size);
}
static int __swiotlb_mmap_coherent(struct device *dev,
struct vm_area_struct *vma,
void *cpu_addr, dma_addr_t dma_addr, size_t size,
struct dma_attrs *attrs)
{
return __dma_common_mmap(dev, vma, cpu_addr, dma_addr, size);
}
static int dma_bus_notifier(struct notifier_block *nb,
unsigned long event, void *_dev)
{
struct device *dev = _dev;
if (event != BUS_NOTIFY_ADD_DEVICE)
return NOTIFY_DONE;
if (of_property_read_bool(dev->of_node, "dma-coherent"))
set_dma_ops(dev, &coherent_swiotlb_dma_ops);
return NOTIFY_OK;
}
static int __init swiotlb_late_init(void)
{
size_t swiotlb_size = min(SZ_64M, MAX_ORDER_NR_PAGES << PAGE_SHIFT);
bus_register_notifier(&platform_bus_type, &platform_bus_nb);
bus_register_notifier(&amba_bustype, &amba_bus_nb);
dma_ops = &noncoherent_swiotlb_dma_ops;
return swiotlb_late_init_with_default_size(swiotlb_size);
}
static int __init dma_debug_do_init(void)
{
dma_debug_init(PREALLOC_DMA_DEBUG_ENTRIES);
return 0;
}
