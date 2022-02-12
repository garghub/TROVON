int __init pcibios_map_irq(const struct pci_dev *dev, u8 slot, u8 pin)
{
int irq = -1;
switch (slot) {
case 12:
irq = TB0219_PCI_SLOT1_IRQ;
break;
case 13:
irq = TB0219_PCI_SLOT2_IRQ;
break;
case 14:
irq = TB0219_PCI_SLOT3_IRQ;
break;
default:
break;
}
return irq;
}
int pcibios_plat_dev_init(struct pci_dev *dev)
{
return 0;
}
