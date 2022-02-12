static int apci1564_auto_attach(struct comedi_device *dev,
unsigned long context)
{
dev->board_ptr = &apci1564_boardtypes[0];
return addi_auto_attach(dev, context);
}
static int apci1564_pci_probe(struct pci_dev *dev,
const struct pci_device_id *id)
{
return comedi_pci_auto_config(dev, &apci1564_driver, id->driver_data);
}
