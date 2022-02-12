static int adl_pci7x3x_do_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned long reg = (unsigned long)s->private;
if (comedi_dio_update_state(s, data))
outl(s->state, dev->iobase + reg);
data[1] = s->state;
return insn->n;
}
static int adl_pci7x3x_di_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned long reg = (unsigned long)s->private;
data[1] = inl(dev->iobase + reg);
return insn->n;
}
static int adl_pci7x3x_auto_attach(struct comedi_device *dev,
unsigned long context)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
const struct adl_pci7x3x_boardinfo *board = NULL;
struct comedi_subdevice *s;
int subdev;
int nchan;
int ret;
if (context < ARRAY_SIZE(adl_pci7x3x_boards))
board = &adl_pci7x3x_boards[context];
if (!board)
return -ENODEV;
dev->board_ptr = board;
dev->board_name = board->name;
ret = comedi_pci_enable(dev);
if (ret)
return ret;
dev->iobase = pci_resource_start(pcidev, 2);
ret = comedi_alloc_subdevices(dev, board->nsubdevs);
if (ret)
return ret;
subdev = 0;
if (board->di_nchan) {
nchan = min(board->di_nchan, 32);
s = &dev->subdevices[subdev];
s->type = COMEDI_SUBD_DI;
s->subdev_flags = SDF_READABLE;
s->n_chan = nchan;
s->maxdata = 1;
s->insn_bits = adl_pci7x3x_di_insn_bits;
s->range_table = &range_digital;
s->private = (void *)PCI7X3X_DIO_REG;
subdev++;
nchan = board->di_nchan - nchan;
if (nchan) {
s = &dev->subdevices[subdev];
s->type = COMEDI_SUBD_DI;
s->subdev_flags = SDF_READABLE;
s->n_chan = nchan;
s->maxdata = 1;
s->insn_bits = adl_pci7x3x_di_insn_bits;
s->range_table = &range_digital;
s->private = (void *)PCI743X_DIO_REG;
subdev++;
}
}
if (board->do_nchan) {
nchan = min(board->do_nchan, 32);
s = &dev->subdevices[subdev];
s->type = COMEDI_SUBD_DO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = nchan;
s->maxdata = 1;
s->insn_bits = adl_pci7x3x_do_insn_bits;
s->range_table = &range_digital;
s->private = (void *)PCI7X3X_DIO_REG;
subdev++;
nchan = board->do_nchan - nchan;
if (nchan) {
s = &dev->subdevices[subdev];
s->type = COMEDI_SUBD_DO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = nchan;
s->maxdata = 1;
s->insn_bits = adl_pci7x3x_do_insn_bits;
s->range_table = &range_digital;
s->private = (void *)PCI743X_DIO_REG;
subdev++;
}
}
return 0;
}
static int adl_pci7x3x_pci_probe(struct pci_dev *dev,
const struct pci_device_id *id)
{
return comedi_pci_auto_config(dev, &adl_pci7x3x_driver,
id->driver_data);
}
