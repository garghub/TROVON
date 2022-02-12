static int apci1500_pci_probe(struct pci_dev *dev,
const struct pci_device_id *ent)
{
return comedi_pci_auto_config(dev, &apci1500_driver);
}
static void apci1500_pci_remove(struct pci_dev *dev)
{
comedi_pci_auto_unconfig(dev);
}
