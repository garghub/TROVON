int __init pcibios_map_irq(const struct pci_dev *dev, u8 slot, u8 pin)
{
return 0;
}
int pcibios_plat_dev_init(struct pci_dev *dev)
{
int res;
u8 slot, pin;
res = ssb_pcibios_plat_dev_init(dev);
if (res < 0) {
printk(KERN_ALERT "PCI: Failed to init device %s\n",
pci_name(dev));
return res;
}
pci_read_config_byte(dev, PCI_INTERRUPT_PIN, &pin);
slot = PCI_SLOT(dev->devfn);
res = ssb_pcibios_map_irq(dev, slot, pin);
if (res < 2) {
printk(KERN_ALERT "PCI: Failed to map IRQ of device %s\n",
pci_name(dev));
return res;
}
dev->irq = res;
return 0;
}
