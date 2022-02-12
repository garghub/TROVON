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
struct comedi_insn *insn,
unsigned int *data)
{
struct ni_670x_private *devpriv = dev->private;
void __iomem *io_addr = devpriv->mite->daq_io_addr +
DIO_PORT0_DATA_OFFSET;
if (comedi_dio_update_state(s, data))
writel(s->state, io_addr);
data[1] = readl(io_addr);
return insn->n;
}
static int ni_670x_dio_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct ni_670x_private *devpriv = dev->private;
int ret;
ret = comedi_dio_insn_config(dev, s, insn, data, 0);
if (ret)
return ret;
writel(s->io_bits, devpriv->mite->daq_io_addr + DIO_PORT0_DIR_OFFSET);
return insn->n;
}
static int ni_670x_auto_attach(struct comedi_device *dev,
unsigned long context)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
const struct ni_670x_board *thisboard = NULL;
struct ni_670x_private *devpriv;
struct comedi_subdevice *s;
int ret;
int i;
if (context < ARRAY_SIZE(ni_670x_boards))
thisboard = &ni_670x_boards[context];
if (!thisboard)
return -ENODEV;
dev->board_ptr = thisboard;
dev->board_name = thisboard->name;
ret = comedi_pci_enable(dev);
if (ret)
return ret;
devpriv = comedi_alloc_devpriv(dev, sizeof(*devpriv));
if (!devpriv)
return -ENOMEM;
devpriv->mite = mite_alloc(pcidev);
if (!devpriv->mite)
return -ENOMEM;
ret = mite_setup(devpriv->mite);
if (ret < 0) {
dev_warn(dev->class_dev, "error setting up mite\n");
return ret;
}
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
comedi_pci_disable(dev);
}
static int ni_670x_pci_probe(struct pci_dev *dev,
const struct pci_device_id *id)
{
return comedi_pci_auto_config(dev, &ni_670x_driver, id->driver_data);
}
