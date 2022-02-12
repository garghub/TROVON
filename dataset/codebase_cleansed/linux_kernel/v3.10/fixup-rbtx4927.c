int __init rbtx4927_pci_map_irq(const struct pci_dev *dev, u8 slot, u8 pin)
{
unsigned char irq = pin;
irq--;
if (slot == TX4927_PCIC_IDSEL_AD_TO_SLOT(23)) {
irq = (irq + 0 + slot) % 4;
} else {
if (txx9_pci_option & TXX9_PCI_OPT_PICMG)
irq = (irq + 33 - slot) % 4;
else
irq = (irq + 3 + slot) % 4;
}
irq++;
switch (irq) {
case 1:
irq = RBTX4927_IRQ_IOC_PCIA;
break;
case 2:
irq = RBTX4927_IRQ_IOC_PCIB;
break;
case 3:
irq = RBTX4927_IRQ_IOC_PCIC;
break;
case 4:
irq = RBTX4927_IRQ_IOC_PCID;
break;
}
return irq;
}
