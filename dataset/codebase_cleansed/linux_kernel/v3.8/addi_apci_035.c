static int apci035_pci_probe(struct pci_dev *dev,
const struct pci_device_id *ent)
{
return comedi_pci_auto_config(dev, &apci035_driver);
}
static void apci035_pci_remove(struct pci_dev *dev)
{
comedi_pci_auto_unconfig(dev);
}
