void __init pcibios_fixup_resources(struct pci_dev *dev)
{
}
void __init pcibios_fixup(void)
{
}
int __init pcibios_map_irq(const struct pci_dev *dev, u8 slot, u8 pin)
{
return pnx8550_irq_tab[slot][pin];
}
int pcibios_plat_dev_init(struct pci_dev *dev)
{
return 0;
}
