static int __init ebsa285_map_irq(struct pci_dev *dev, u8 slot, u8 pin)
{
if (dev->vendor == PCI_VENDOR_ID_CONTAQ &&
dev->device == PCI_DEVICE_ID_CONTAQ_82C693)
switch (PCI_FUNC(dev->devfn)) {
case 1: return 14;
case 2: return 15;
case 3: return 12;
}
return irqmap_ebsa285[(slot + pin) & 3];
}
static int __init ebsa285_init_pci(void)
{
if (machine_is_ebsa285())
pci_common_init(&ebsa285_pci);
return 0;
}
