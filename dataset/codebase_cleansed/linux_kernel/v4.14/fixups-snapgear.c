int pcibios_map_platform_irq(const struct pci_dev *pdev, u8 slot, u8 pin)
{
int irq = -1;
switch (slot) {
case 8: break;
case 11: irq = evt2irq(0x300); break;
case 12: irq = evt2irq(0x360); break;
case 13: irq = evt2irq(0x2a0); break;
case 14: irq = evt2irq(0x300); break;
case 15: irq = evt2irq(0x360); break;
}
printk("PCI: Mapping SnapGear IRQ for slot %d, pin %c to irq %d\n",
slot, pin - 1 + 'A', irq);
return irq;
}
