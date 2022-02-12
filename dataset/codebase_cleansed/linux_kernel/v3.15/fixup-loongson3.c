static void print_fixup_info(const struct pci_dev *pdev)
{
dev_info(&pdev->dev, "Device %x:%x, irq %d\n",
pdev->vendor, pdev->device, pdev->irq);
}
int __init pcibios_map_irq(const struct pci_dev *dev, u8 slot, u8 pin)
{
print_fixup_info(dev);
return dev->irq;
}
static void pci_fixup_radeon(struct pci_dev *pdev)
{
if (pdev->resource[PCI_ROM_RESOURCE].start)
return;
if (!loongson_sysconf.vgabios_addr)
return;
pdev->resource[PCI_ROM_RESOURCE].start =
loongson_sysconf.vgabios_addr;
pdev->resource[PCI_ROM_RESOURCE].end =
loongson_sysconf.vgabios_addr + 256*1024 - 1;
pdev->resource[PCI_ROM_RESOURCE].flags |= IORESOURCE_ROM_COPY;
dev_info(&pdev->dev, "BAR %d: assigned %pR for Radeon ROM\n",
PCI_ROM_RESOURCE, &pdev->resource[PCI_ROM_RESOURCE]);
}
int pcibios_plat_dev_init(struct pci_dev *dev)
{
return 0;
}
