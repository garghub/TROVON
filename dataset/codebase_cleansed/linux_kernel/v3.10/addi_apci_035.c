static int apci035_auto_attach(struct comedi_device *dev,
unsigned long context)
{
dev->board_ptr = &apci035_boardtypes[0];
return addi_auto_attach(dev, context);
}
static int apci035_pci_probe(struct pci_dev *dev,
const struct pci_device_id *id)
{
return comedi_pci_auto_config(dev, &apci035_driver, id->driver_data);
}
