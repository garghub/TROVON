static int __devinit driver_ni_670x_pci_probe(struct pci_dev *dev,
const struct pci_device_id *ent)
{
return comedi_pci_auto_config(dev, &driver_ni_670x);
}
static void __devexit driver_ni_670x_pci_remove(struct pci_dev *dev)
{
comedi_pci_auto_unconfig(dev);
}
static int __init driver_ni_670x_init_module(void)
{
int retval;
retval = comedi_driver_register(&driver_ni_670x);
if (retval < 0)
return retval;
driver_ni_670x_pci_driver.name = (char *)driver_ni_670x.driver_name;
return pci_register_driver(&driver_ni_670x_pci_driver);
}
static void __exit driver_ni_670x_cleanup_module(void)
{
pci_unregister_driver(&driver_ni_670x_pci_driver);
comedi_driver_unregister(&driver_ni_670x);
}
static int ni_670x_attach(struct comedi_device *dev,
struct comedi_devconfig *it)
{
struct comedi_subdevice *s;
int ret;
int i;
printk(KERN_INFO "comedi%d: ni_670x: ", dev->minor);
ret = alloc_private(dev, sizeof(struct ni_670x_private));
if (ret < 0)
return ret;
ret = ni_670x_find_device(dev, it->options[0], it->options[1]);
if (ret < 0)
return ret;
ret = mite_setup(devpriv->mite);
if (ret < 0) {
printk(KERN_WARNING "error setting up mite\n");
return ret;
}
dev->board_name = thisboard->name;
dev->irq = mite_irq(devpriv->mite);
printk(KERN_INFO " %s", dev->board_name);
if (alloc_subdevices(dev, 2) < 0)
return -ENOMEM;
s = dev->subdevices + 0;
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
s = dev->subdevices + 1;
s->type = COMEDI_SUBD_DIO;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE;
s->n_chan = 8;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = ni_670x_dio_insn_bits;
s->insn_config = ni_670x_dio_insn_config;
writel(0x10, devpriv->mite->daq_io_addr + MISC_CONTROL_OFFSET);
writel(0x00, devpriv->mite->daq_io_addr + AO_CONTROL_OFFSET);
printk(KERN_INFO "attached\n");
return 1;
}
static void ni_670x_detach(struct comedi_device *dev)
{
kfree(dev->subdevices[0].range_table_list);
if (dev->private && devpriv->mite)
mite_unsetup(devpriv->mite);
if (dev->irq)
free_irq(dev->irq, dev);
}
static int ni_670x_ao_winsn(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
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
if (insn->n != 2)
return -EINVAL;
if (data[0]) {
s->state &= ~data[0];
s->state |= data[0] & data[1];
writel(s->state,
devpriv->mite->daq_io_addr + DIO_PORT0_DATA_OFFSET);
}
data[1] = readl(devpriv->mite->daq_io_addr + DIO_PORT0_DATA_OFFSET);
return 2;
}
static int ni_670x_dio_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
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
static int ni_670x_find_device(struct comedi_device *dev, int bus, int slot)
{
struct mite_struct *mite;
int i;
for (mite = mite_devices; mite; mite = mite->next) {
if (mite->used)
continue;
if (bus || slot) {
if (bus != mite->pcidev->bus->number
|| slot != PCI_SLOT(mite->pcidev->devfn))
continue;
}
for (i = 0; i < n_ni_670x_boards; i++) {
if (mite_device_id(mite) == ni_670x_boards[i].dev_id) {
dev->board_ptr = ni_670x_boards + i;
devpriv->mite = mite;
return 0;
}
}
}
printk(KERN_INFO "no device found\n");
mite_list_devices();
return -EIO;
}
