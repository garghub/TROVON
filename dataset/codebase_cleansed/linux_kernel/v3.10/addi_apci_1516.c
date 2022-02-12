static int apci1516_di_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
data[1] = inw(dev->iobase + APCI1516_DI_REG);
return insn->n;
}
static int apci1516_do_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned int mask = data[0];
unsigned int bits = data[1];
s->state = inw(dev->iobase + APCI1516_DO_REG);
if (mask) {
s->state &= ~mask;
s->state |= (bits & mask);
outw(s->state, dev->iobase + APCI1516_DO_REG);
}
data[1] = s->state;
return insn->n;
}
static int apci1516_reset(struct comedi_device *dev)
{
const struct apci1516_boardinfo *this_board = comedi_board(dev);
struct apci1516_private *devpriv = dev->private;
if (!this_board->has_wdog)
return 0;
outw(0x0, dev->iobase + APCI1516_DO_REG);
addi_watchdog_reset(devpriv->wdog_iobase);
return 0;
}
static int apci1516_auto_attach(struct comedi_device *dev,
unsigned long context)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
const struct apci1516_boardinfo *this_board = NULL;
struct apci1516_private *devpriv;
struct comedi_subdevice *s;
int ret;
if (context < ARRAY_SIZE(apci1516_boardtypes))
this_board = &apci1516_boardtypes[context];
if (!this_board)
return -ENODEV;
dev->board_ptr = this_board;
dev->board_name = this_board->name;
devpriv = kzalloc(sizeof(*devpriv), GFP_KERNEL);
if (!devpriv)
return -ENOMEM;
dev->private = devpriv;
ret = comedi_pci_enable(dev);
if (ret)
return ret;
dev->iobase = pci_resource_start(pcidev, 1);
devpriv->wdog_iobase = pci_resource_start(pcidev, 2);
ret = comedi_alloc_subdevices(dev, 3);
if (ret)
return ret;
s = &dev->subdevices[0];
if (this_board->di_nchan) {
s->type = COMEDI_SUBD_DI;
s->subdev_flags = SDF_READABLE;
s->n_chan = this_board->di_nchan;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = apci1516_di_insn_bits;
} else {
s->type = COMEDI_SUBD_UNUSED;
}
s = &dev->subdevices[1];
if (this_board->do_nchan) {
s->type = COMEDI_SUBD_DO;
s->subdev_flags = SDF_WRITEABLE;
s->n_chan = this_board->do_nchan;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = apci1516_do_insn_bits;
} else {
s->type = COMEDI_SUBD_UNUSED;
}
s = &dev->subdevices[2];
if (this_board->has_wdog) {
ret = addi_watchdog_init(s, devpriv->wdog_iobase);
if (ret)
return ret;
} else {
s->type = COMEDI_SUBD_UNUSED;
}
apci1516_reset(dev);
return 0;
}
static void apci1516_detach(struct comedi_device *dev)
{
if (dev->iobase)
apci1516_reset(dev);
comedi_spriv_free(dev, 2);
comedi_pci_disable(dev);
}
static int apci1516_pci_probe(struct pci_dev *dev,
const struct pci_device_id *id)
{
return comedi_pci_auto_config(dev, &apci1516_driver, id->driver_data);
}
