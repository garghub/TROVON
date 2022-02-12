static int apci3xxx_auto_attach(struct comedi_device *dev,
unsigned long context)
{
const struct addi_board *board = NULL;
if (context < ARRAY_SIZE(apci3xxx_boardtypes))
board = &apci3xxx_boardtypes[context];
if (!board)
return -ENODEV;
dev->board_ptr = board;
return addi_auto_attach(dev, context);
}
static int apci3xxx_pci_probe(struct pci_dev *dev,
const struct pci_device_id *id)
{
return comedi_pci_auto_config(dev, &apci3xxx_driver, id->driver_data);
}
