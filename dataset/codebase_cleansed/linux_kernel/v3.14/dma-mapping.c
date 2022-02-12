static void *arm64_swiotlb_alloc_coherent(struct device *dev, size_t size,
dma_addr_t *dma_handle, gfp_t flags,
struct dma_attrs *attrs)
{
if (dev == NULL) {
WARN_ONCE(1, "Use an actual device structure for DMA allocation\n");
return NULL;
}
if (IS_ENABLED(CONFIG_ZONE_DMA32) &&
dev->coherent_dma_mask <= DMA_BIT_MASK(32))
flags |= GFP_DMA32;
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
static void arm64_swiotlb_free_coherent(struct device *dev, size_t size,
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
void __init arm64_swiotlb_init(void)
{
dma_ops = &arm64_swiotlb_dma_ops;
swiotlb_init(1);
}
static int __init dma_debug_do_init(void)
{
dma_debug_init(PREALLOC_DMA_DEBUG_ENTRIES);
return 0;
}
