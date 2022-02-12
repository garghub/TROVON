static int ahci_octeon_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct device_node *node = dev->of_node;
struct resource *res;
void __iomem *base;
u64 cfg;
int ret;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(base))
return PTR_ERR(base);
cfg = cvmx_readq_csr(base + CVMX_SATA_UCTL_SHIM_CFG);
cfg &= ~(SATA_UCTL_ENDIAN_MODE_MASK << SATA_UCTL_DMA_ENDIAN_MODE_SHIFT);
cfg &= ~(SATA_UCTL_ENDIAN_MODE_MASK << SATA_UCTL_CSR_ENDIAN_MODE_SHIFT);
#ifdef __BIG_ENDIAN
cfg |= SATA_UCTL_ENDIAN_MODE_BIG << SATA_UCTL_DMA_ENDIAN_MODE_SHIFT;
cfg |= SATA_UCTL_ENDIAN_MODE_BIG << SATA_UCTL_CSR_ENDIAN_MODE_SHIFT;
#else
cfg |= SATA_UCTL_ENDIAN_MODE_LITTLE << SATA_UCTL_DMA_ENDIAN_MODE_SHIFT;
cfg |= SATA_UCTL_ENDIAN_MODE_LITTLE << SATA_UCTL_CSR_ENDIAN_MODE_SHIFT;
#endif
cfg |= 1 << SATA_UCTL_DMA_READ_CMD_SHIFT;
cvmx_writeq_csr(base + CVMX_SATA_UCTL_SHIM_CFG, cfg);
if (!node) {
dev_err(dev, "no device node, failed to add octeon sata\n");
return -ENODEV;
}
ret = of_platform_populate(node, NULL, NULL, dev);
if (ret) {
dev_err(dev, "failed to add ahci-platform core\n");
return ret;
}
return 0;
}
static int ahci_octeon_remove(struct platform_device *pdev)
{
return 0;
}
