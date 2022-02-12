static int ni_670x_ao_winsn(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct ni_670x_private *devpriv = dev->private;
int i;
int chan = CR_CHAN(insn->chanspec);
for (i = 0; i < insn->n; i++) {
writel(((chan & 15) << 1) | ((chan & 16) >> 4),
devpriv->mite->daq_io_addr + AO_CHAN_OFFSET);
writel(data[i], devpriv->mite->daq_io_addr + AO_VALUE_OFFSET);
devpriv->ao_readback[chan] = data[i];
}
return i;
}
static int ni_670x_ao_rinsn(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct ni_670x_private *devpriv = dev->private;
int i;
int chan = CR_CHAN(insn->chanspec);
for (i = 0; i < insn->n; i++)
data[i] = devpriv->ao_readback[chan];
return i;
}
static int ni_670x_dio_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct ni_670x_private *devpriv = dev->private;
void __iomem *io_addr = devpriv->mite->daq_io_addr +
DIO_PORT0_DATA_OFFSET;
unsigned int mask = data[0];
unsigned int bits = data[1];
if (mask) {
s->state &= ~mask;
s->state |= (bits & mask);
writel(s->state, io_addr);
}
data[1] = readl(io_addr);
return insn->n;
}
static int ni_670x_dio_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct ni_670x_private *devpriv = dev->private;
int chan = CR_CHAN(insn->chanspec);
switch (data[0]) {
case INSN_CONFIG_DIO_OUTPUT:
s->io_bits |= 1 << chan;
break;
case INSN_CONFIG_DIO_INPUT:
s->io_bits &= ~(1 << chan);
break;
case INSN_CONFIG_DIO_QUERY:
data[1] =
(s->io_bits & (1 << chan)) ? COMEDI_OUTPUT : COMEDI_INPUT;
return insn->n;
break;
default:
return -EINVAL;
break;
}
writel(s->io_bits, devpriv->mite->daq_io_addr + DIO_PORT0_DIR_OFFSET);
return insn->n;
}
static const struct ni_670x_board *
ni_670x_find_boardinfo(struct pci_dev *pcidev)
{
unsigned int dev_id = pcidev->device;
unsigned int n;
for (n = 0; n < ARRAY_SIZE(ni_670x_boards); n++) {
const struct ni_670x_board *board = &ni_670x_boards[n];
if (board->dev_id == dev_id)
return board;
}
return NULL;
}
static int __devinit ni_670x_attach_pci(struct comedi_device *dev,
struct pci_dev *pcidev)
{
const struct ni_670x_board *thisboard;
struct ni_670x_private *devpriv;
struct comedi_subdevice *s;
int ret;
int i;
ret = alloc_private(dev, sizeof(*devpriv));
if (ret < 0)
return ret;
devpriv = dev->private;
dev->board_ptr = ni_670x_find_boardinfo(pcidev);
if (!dev->board_ptr)
return -ENODEV;
devpriv->mite = mite_alloc(pcidev);
if (!devpriv->mite)
return -ENOMEM;
thisboard = comedi_board(dev);
ret = mite_setup(devpriv->mite);
if (ret < 0) {
dev_warn(dev->class_dev, "error setting up mite\n");
return ret;
}
dev->board_name = thisboard->name;
ret = comedi_alloc_subdevices(dev, 2);
if (ret)
return ret;
s = &dev->subdevices[0];
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = thisboard->ao_chans;
s->maxdata = 0xffff;
if (s->n_chan == 32) {
const struct comedi_lrange **range_table_list;
range_table_list = kmalloc(sizeof(struct comedi_lrange *) * 32,
GFP_KERNEL);
if (!range_table_list)
return -ENOMEM;
s->range_table_list = range_table_list;
for (i = 0; i < 16; i++) {
range_table_list[i] = &range_bipolar10;
range_table_list[16 + i] = &range_0_20mA;
}
} else {
s->range_table = &range_bipolar10;
}
s->insn_write = &ni_670x_ao_winsn;
s->insn_read = &ni_670x_ao_rinsn;
s = &dev->subdevices[1];
s->type = COMEDI_SUBD_DIO;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE;
s->n_chan = 8;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = ni_670x_dio_insn_bits;
s->insn_config = ni_670x_dio_insn_config;
writel(0x10, devpriv->mite->daq_io_addr + MISC_CONTROL_OFFSET);
writel(0x00, devpriv->mite->daq_io_addr + AO_CONTROL_OFFSET);
dev_info(dev->class_dev, "%s: %s attached\n",
dev->driver->driver_name, dev->board_name);
return 0;
}
static void ni_670x_detach(struct comedi_device *dev)
{
struct ni_670x_private *devpriv = dev->private;
struct comedi_subdevice *s;
if (dev->n_subdevices) {
s = &dev->subdevices[0];
if (s)
kfree(s->range_table_list);
}
if (devpriv && devpriv->mite) {
mite_unsetup(devpriv->mite);
mite_free(devpriv->mite);
}
}
static int __devinit ni_670x_pci_probe(struct pci_dev *dev,
const struct pci_device_id *ent)
{
return comedi_pci_auto_config(dev, &ni_670x_driver);
}
static void __devexit ni_670x_pci_remove(struct pci_dev *dev)
{
comedi_pci_auto_unconfig(dev);
}
