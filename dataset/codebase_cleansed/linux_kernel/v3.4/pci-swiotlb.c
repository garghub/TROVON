static void *ia64_swiotlb_alloc_coherent(struct device *dev, size_t size,
dma_addr_t *dma_handle, gfp_t gfp,
struct dma_attrs *attrs)
{
if (dev->coherent_dma_mask != DMA_BIT_MASK(64))
gfp |= GFP_DMA;
return swiotlb_alloc_coherent(dev, size, dma_handle, gfp);
}
static void ia64_swiotlb_free_coherent(struct device *dev, size_t size,
void *vaddr, dma_addr_t dma_addr,
struct dma_attrs *attrs)
{
swiotlb_free_coherent(dev, size, vaddr, dma_addr);
}
void __init swiotlb_dma_init(void)
{
dma_ops = &swiotlb_dma_ops;
swiotlb_init(1);
}
void __init pci_swiotlb_init(void)
{
if (!iommu_detected) {
#ifdef CONFIG_IA64_GENERIC
swiotlb = 1;
printk(KERN_INFO "PCI-DMA: Re-initialize machine vector.\n");
machvec_init("dig");
swiotlb_init(1);
dma_ops = &swiotlb_dma_ops;
#else
panic("Unable to find Intel IOMMU");
#endif
}
}
