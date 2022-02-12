static void *arm64_swiotlb_alloc_coherent(struct device *dev, size_t size,
dma_addr_t *dma_handle, gfp_t flags,
struct dma_attrs *attrs)
{
if (IS_ENABLED(CONFIG_ZONE_DMA32) &&
dev->coherent_dma_mask <= DMA_BIT_MASK(32))
flags |= GFP_DMA32;
return swiotlb_alloc_coherent(dev, size, dma_handle, flags);
}
static void arm64_swiotlb_free_coherent(struct device *dev, size_t size,
void *vaddr, dma_addr_t dma_handle,
struct dma_attrs *attrs)
{
swiotlb_free_coherent(dev, size, vaddr, dma_handle);
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
