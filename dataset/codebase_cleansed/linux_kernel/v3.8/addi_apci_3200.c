static void fpu_begin(void)
{
kernel_fpu_begin();
}
static void fpu_end(void)
{
kernel_fpu_end();
}
static int apci3200_pci_probe(struct pci_dev *dev,
const struct pci_device_id *ent)
{
return comedi_pci_auto_config(dev, &apci3200_driver);
}
static void apci3200_pci_remove(struct pci_dev *dev)
{
comedi_pci_auto_unconfig(dev);
}
