static void print_fixup_info(const struct pci_dev *pdev)
{
dev_info(&pdev->dev, "Device %x:%x, irq %d\n",
pdev->vendor, pdev->device, pdev->irq);
}
int pcibios_map_irq(const struct pci_dev *dev, u8 slot, u8 pin)
{
print_fixup_info(dev);
return dev->irq;
}
static void pci_fixup_radeon(struct pci_dev *pdev)
{
struct resource *res = &pdev->resource[PCI_ROM_RESOURCE];
if (res->start)
return;
if (!loongson_sysconf.vgabios_addr)
return;
pci_disable_rom(pdev);
if (res->parent)
release_resource(res);
res->start = virt_to_phys((void *) loongson_sysconf.vgabios_addr);
res->end = res->start + 256*1024 - 1;
res->flags = IORESOURCE_MEM | IORESOURCE_ROM_SHADOW |
IORESOURCE_PCI_FIXED;
dev_info(&pdev->dev, "BAR %d: assigned %pR for Radeon ROM\n",
PCI_ROM_RESOURCE, res);
}
int pcibios_plat_dev_init(struct pci_dev *dev)
{
return 0;
}
