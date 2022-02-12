int pcibios_map_irq(const struct pci_dev *dev, u8 slot, u8 pin)
{
return bcm63xx_get_irq_number(IRQ_PCI);
}
int pcibios_plat_dev_init(struct pci_dev *dev)
{
return 0;
}
