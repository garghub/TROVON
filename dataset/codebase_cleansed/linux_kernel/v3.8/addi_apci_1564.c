static int apci1564_pci_probe(struct pci_dev *dev,
const struct pci_device_id *ent)
{
return comedi_pci_auto_config(dev, &apci1564_driver);
}
static void apci1564_pci_remove(struct pci_dev *dev)
{
comedi_pci_auto_unconfig(dev);
}
