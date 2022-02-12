int __init pcibios_map_irq(const struct pci_dev *dev, u8 slot, u8 pin)
{
int virq;
virq = irq_tab[slot][pin];
return pci_irq[virq];
}
int pcibios_plat_dev_init(struct pci_dev *dev)
{
return 0;
}
static void __devinit malta_piix_func0_fixup(struct pci_dev *pdev)
{
unsigned char reg_val;
static int piixirqmap[16] __devinitdata = {
0, 0, 0, 3,
4, 5, 6, 7,
0, 9, 10, 11,
12, 0, 14, 15
};
int i;
for (i = 0; i <= 3; i++) {
pci_read_config_byte(pdev, 0x60+i, &reg_val);
if (reg_val & 0x80)
pci_irq[PCIA+i] = 0;
else
pci_irq[PCIA+i] = piixirqmap[reg_val & 15];
}
if (PCI_SLOT(pdev->devfn) == 10) {
pci_read_config_byte(pdev, 0x69, &reg_val);
pci_write_config_byte(pdev, 0x69, reg_val | 0xf0);
}
}
static void __devinit malta_piix_func1_fixup(struct pci_dev *pdev)
{
unsigned char reg_val;
if (PCI_SLOT(pdev->devfn) == 10) {
pci_read_config_byte(pdev, 0x41, &reg_val);
pci_write_config_byte(pdev, 0x41, reg_val|0x80);
pci_read_config_byte(pdev, 0x43, &reg_val);
pci_write_config_byte(pdev, 0x43, reg_val|0x80);
}
}
