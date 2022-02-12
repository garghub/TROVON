static int __init pci_iommu_init(void)
{
if (iommu_detected)
intel_iommu_init();
return 0;
}
void pci_iommu_shutdown(void)
{
return;
}
void __init
iommu_dma_init(void)
{
return;
}
int iommu_dma_supported(struct device *dev, u64 mask)
{
if (mask < DMA_BIT_MASK(24))
return 0;
if (iommu_sac_force && (mask >= DMA_BIT_MASK(40))) {
dev_info(dev, "Force SAC with mask %llx\n", mask);
return 0;
}
return 1;
}
void __init pci_iommu_alloc(void)
{
dma_ops = &intel_dma_ops;
intel_dma_ops.sync_single_for_cpu = machvec_dma_sync_single;
intel_dma_ops.sync_sg_for_cpu = machvec_dma_sync_sg;
intel_dma_ops.sync_single_for_device = machvec_dma_sync_single;
intel_dma_ops.sync_sg_for_device = machvec_dma_sync_sg;
intel_dma_ops.dma_supported = iommu_dma_supported;
detect_intel_iommu();
#ifdef CONFIG_SWIOTLB
pci_swiotlb_init();
#endif
}
