static void __init gapspci_fixup_resources(struct pci_dev *dev)
{
struct pci_channel *p = dev->sysdata;
printk(KERN_NOTICE "PCI: Fixing up device %s\n", pci_name(dev));
switch (dev->device) {
case PCI_DEVICE_ID_SEGA_BBA:
dev->resource[1].start = p->resources[0].start + 0x100;
dev->resource[1].end = dev->resource[1].start + 0x200 - 1;
dev->resource[1].flags |= IORESOURCE_PCI_FIXED;
BUG_ON(!dma_declare_coherent_memory(&dev->dev,
GAPSPCI_DMA_BASE,
GAPSPCI_DMA_BASE,
GAPSPCI_DMA_SIZE,
DMA_MEMORY_MAP |
DMA_MEMORY_EXCLUSIVE));
break;
default:
printk("PCI: Failed resource fixup\n");
}
}
int __init pcibios_map_platform_irq(struct pci_dev *dev, u8 slot, u8 pin)
{
return GAPSPCI_IRQ;
}
