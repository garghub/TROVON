int __init pcibios_map_irq(const struct pci_dev *dev, u8 slot, u8 pin)
{
return asic_pcie_map_irq(dev, slot, pin);
}
int pcibios_plat_dev_init(struct pci_dev *dev)
{
return 0;
}
int asic_pcie_map_irq(const struct pci_dev *dev, u8 slot, u8 pin)
{
return irq_pciexp;
}
