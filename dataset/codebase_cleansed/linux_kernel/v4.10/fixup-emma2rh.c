static void nec_usb_controller_fixup(struct pci_dev *dev)
{
if (PCI_SLOT(dev->devfn) == EMMA2RH_USB_SLOT)
pci_write_config_dword(dev, 0xe4, 1 << 5);
}
static void emma2rh_pci_host_fixup(struct pci_dev *dev)
{
int i;
if (PCI_SLOT(dev->devfn) == EMMA2RH_PCI_HOST_SLOT) {
dev->class &= 0xff;
dev->class |= PCI_CLASS_BRIDGE_HOST << 8;
for (i = 0; i < PCI_NUM_RESOURCES; i++) {
dev->resource[i].start = 0;
dev->resource[i].end = 0;
dev->resource[i].flags = 0;
}
}
}
int __init pcibios_map_irq(const struct pci_dev *dev, u8 slot, u8 pin)
{
return irq_map[slot][pin];
}
int pcibios_plat_dev_init(struct pci_dev *dev)
{
return 0;
}
