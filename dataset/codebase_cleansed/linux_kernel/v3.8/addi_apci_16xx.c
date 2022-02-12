static int apci16xx_pci_probe(struct pci_dev *dev,
const struct pci_device_id *ent)
{
return comedi_pci_auto_config(dev, &apci16xx_driver);
}
static void apci16xx_pci_remove(struct pci_dev *dev)
{
comedi_pci_auto_unconfig(dev);
}
