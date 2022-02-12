int pcibios_map_irq(const struct pci_dev *dev, u8 slot, u8 pin)
{
return irq_tab_mace[slot][pin];
}
int pcibios_plat_dev_init(struct pci_dev *dev)
{
return 0;
}
