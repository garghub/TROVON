int __init pcibios_map_platform_irq(const struct pci_dev *pdev, u8 slot, u8 pin)
{
int irq = -1;
switch (slot) {
case 8: break;
case 11: irq = 8; break;
case 12: irq = 11; break;
case 13: irq = 5; break;
case 14: irq = 8; break;
case 15: irq = 11; break;
}
printk("PCI: Mapping SnapGear IRQ for slot %d, pin %c to irq %d\n",
slot, pin - 1 + 'A', irq);
return irq;
}
