static int apci1500_auto_attach(struct comedi_device *dev,
unsigned long context)
{
dev->board_ptr = &apci1500_boardtypes[0];
return addi_auto_attach(dev, context);
}
static int apci1500_pci_probe(struct pci_dev *dev,
const struct pci_device_id *id)
{
return comedi_pci_auto_config(dev, &apci1500_driver, id->driver_data);
}
