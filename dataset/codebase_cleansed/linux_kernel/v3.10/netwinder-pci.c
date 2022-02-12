static int __init netwinder_map_irq(const struct pci_dev *dev, u8 slot, u8 pin)
{
switch (slot) {
case 0:
return 0;
case 9:
return IRQ_NETWINDER_VGA;
case 10:
return IRQ_NETWINDER_ETHER100;
case 12:
return IRQ_ISA_HARDDISK1;
case 13:
return IRQ_NETWINDER_ETHER10;
default:
printk(KERN_ERR "PCI: unknown device in slot %s\n",
pci_name(dev));
return 0;
}
}
static int __init netwinder_pci_init(void)
{
if (machine_is_netwinder())
pci_common_init(&netwinder_pci);
return 0;
}
