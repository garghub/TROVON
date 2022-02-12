static int __init lasat_pci_setup(void)
{
printk(KERN_DEBUG "PCI: starting\n");
if (IS_LASAT_200())
lasat_pci_controller.pci_ops = &nile4_pci_ops;
else
lasat_pci_controller.pci_ops = &gt64xxx_pci0_ops;
register_pci_controller(&lasat_pci_controller);
return 0;
}
int __init pcibios_map_irq(const struct pci_dev *dev, u8 slot, u8 pin)
{
switch (slot) {
case 1:
case 2:
case 3:
return LASAT_IRQ_PCIA + (((slot-1) + (pin-1)) % 4);
case 4:
return LASAT_IRQ_ETH1;
case 5:
return LASAT_IRQ_ETH0;
case 6:
return LASAT_IRQ_HDC;
default:
return 0xff;
}
return -1;
}
int pcibios_plat_dev_init(struct pci_dev *dev)
{
return 0;
}
