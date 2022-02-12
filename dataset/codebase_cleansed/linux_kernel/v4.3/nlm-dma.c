static void *nlm_dma_alloc_coherent(struct device *dev, size_t size,
dma_addr_t *dma_handle, gfp_t gfp, struct dma_attrs *attrs)
{
gfp &= ~(__GFP_DMA | __GFP_DMA32 | __GFP_HIGHMEM);
#ifdef CONFIG_ZONE_DMA32
if (dev->coherent_dma_mask <= DMA_BIT_MASK(32))
gfp |= __GFP_DMA32;
#endif
gfp |= __GFP_NORETRY;
return swiotlb_alloc_coherent(dev, size, dma_handle, gfp);
}
static void nlm_dma_free_coherent(struct device *dev, size_t size,
void *vaddr, dma_addr_t dma_handle, struct dma_attrs *attrs)
{
swiotlb_free_coherent(dev, size, vaddr, dma_handle);
}
void __init plat_swiotlb_setup(void)
{
size_t swiotlbsize;
unsigned long swiotlb_nslabs;
swiotlbsize = 1 << 20;
swiotlb_nslabs = swiotlbsize >> IO_TLB_SHIFT;
swiotlb_nslabs = ALIGN(swiotlb_nslabs, IO_TLB_SEGSIZE);
swiotlbsize = swiotlb_nslabs << IO_TLB_SHIFT;
nlm_swiotlb = alloc_bootmem_low_pages(swiotlbsize);
swiotlb_init_with_tbl(nlm_swiotlb, swiotlb_nslabs, 1);
}
