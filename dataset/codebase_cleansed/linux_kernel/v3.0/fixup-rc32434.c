int __devinit pcibios_map_irq(const struct pci_dev *dev, u8 slot, u8 pin)
{
int irq = 0;
if (dev->bus->number < 2 && PCI_SLOT(dev->devfn) < 12)
irq = irq_map[dev->bus->number][PCI_SLOT(dev->devfn)];
return irq + GROUP4_IRQ_BASE + 4;
}
static void rc32434_pci_early_fixup(struct pci_dev *dev)
{
if (PCI_SLOT(dev->devfn) == 6 && dev->bus->number == 0) {
pci_write_config_word(dev, PCI_PREF_MEMORY_LIMIT, 0);
pci_write_config_word(dev, PCI_PREF_MEMORY_BASE, 0x10);
pci_write_config_byte(dev, PCI_CACHE_LINE_SIZE, 4);
}
}
int pcibios_plat_dev_init(struct pci_dev *dev)
{
return 0;
}
