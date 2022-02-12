static inline void xgmac_mac_disable(void __iomem *ioaddr)
{
u32 value = readl(ioaddr + XGMAC_DMA_CONTROL);
value &= ~(DMA_CONTROL_ST | DMA_CONTROL_SR);
writel(value, ioaddr + XGMAC_DMA_CONTROL);
value = readl(ioaddr + XGMAC_CONTROL);
value &= ~(MAC_ENABLE_TX | MAC_ENABLE_RX);
writel(value, ioaddr + XGMAC_CONTROL);
}
static int vfio_platform_calxedaxgmac_reset(struct vfio_platform_device *vdev)
{
struct vfio_platform_region *reg = &vdev->regions[0];
if (!reg->ioaddr) {
reg->ioaddr =
ioremap_nocache(reg->addr, reg->size);
if (!reg->ioaddr)
return -ENOMEM;
}
writel(0, reg->ioaddr + XGMAC_DMA_INTR_ENA);
xgmac_mac_disable(reg->ioaddr);
return 0;
}
