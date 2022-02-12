static inline int use_swiotlb(struct device *dev)
{
return dev && dev->dma_mask &&
!sba_dma_ops.dma_supported(dev, *dev->dma_mask);
}
struct dma_map_ops *hwsw_dma_get_ops(struct device *dev)
{
if (use_swiotlb(dev))
return &swiotlb_dma_ops;
return &sba_dma_ops;
}
void __init
hwsw_init (void)
{
if (swiotlb_late_init_with_default_size (2 * (1<<20)) != 0) {
#ifdef CONFIG_IA64_GENERIC
printk(KERN_WARNING "%s: Failed to initialize software I/O TLB,"
" reverting to hpzx1 platform vector\n", __func__);
machvec_init("hpzx1");
#else
panic("Unable to initialize software I/O TLB services");
#endif
}
}
