int __init pcibios_map_irq(const struct pci_dev *dev, u8 slot, u8 pin)
{
if (pin == 0)
return -1;
return 3;
}
int pcibios_plat_dev_init(struct pci_dev *dev)
{
return 0;
}
