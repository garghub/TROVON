static void __devinit quirk_sb1250_pci(struct pci_dev *dev)
{
pci_write_config_byte(dev, 0x40, 0xff);
}
static void __devinit quirk_sb1250_ht(struct pci_dev *dev)
{
dev->class = PCI_CLASS_BRIDGE_PCI << 8;
}
static void __devinit quirk_sp1011(struct pci_dev *dev)
{
pci_write_config_byte(dev, 0x64, 0xff);
}
