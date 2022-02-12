static int pci1723_reset(struct comedi_device *dev)
{
struct pci1723_private *devpriv = dev->private;
int i;
outw(0x01, dev->iobase + PCI1723_SYN_SET);
for (i = 0; i < 8; i++) {
devpriv->ao_data[i] = 0x8000;
outw(devpriv->ao_data[i], dev->iobase + PCI1723_DA(i));
devpriv->da_range[i] = 0;
outw(((devpriv->da_range[i] << 4) | i),
PCI1723_RANGE_CALIBRATION_MODE);
}
outw(0, dev->iobase + PCI1723_CHANGE_CHA_OUTPUT_TYPE_STROBE);
outw(0, dev->iobase + PCI1723_SYN_STROBE);
outw(0, dev->iobase + PCI1723_SYN_SET);
return 0;
}
static int pci1723_insn_read_ao(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct pci1723_private *devpriv = dev->private;
int n, chan;
chan = CR_CHAN(insn->chanspec);
for (n = 0; n < insn->n; n++)
data[n] = devpriv->ao_data[chan];
return n;
}
static int pci1723_ao_write_winsn(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct pci1723_private *devpriv = dev->private;
int n, chan;
chan = CR_CHAN(insn->chanspec);
for (n = 0; n < insn->n; n++) {
devpriv->ao_data[chan] = data[n];
outw(data[n], dev->iobase + PCI1723_DA(chan));
}
return n;
}
static int pci1723_dio_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
unsigned int mask;
unsigned int bits;
unsigned short dio_mode;
mask = 1 << CR_CHAN(insn->chanspec);
if (mask & 0x00FF)
bits = 0x00FF;
else
bits = 0xFF00;
switch (data[0]) {
case INSN_CONFIG_DIO_INPUT:
s->io_bits &= ~bits;
break;
case INSN_CONFIG_DIO_OUTPUT:
s->io_bits |= bits;
break;
case INSN_CONFIG_DIO_QUERY:
data[1] = (s->io_bits & bits) ? COMEDI_OUTPUT : COMEDI_INPUT;
return insn->n;
default:
return -EINVAL;
}
dio_mode = 0x0000;
if ((s->io_bits & 0x00FF) == 0)
dio_mode |= 0x0001;
if ((s->io_bits & 0xFF00) == 0)
dio_mode |= 0x0002;
outw(dio_mode, dev->iobase + PCI1723_DIGITAL_IO_PORT_SET);
return 1;
}
static int pci1723_dio_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
if (data[0]) {
s->state &= ~data[0];
s->state |= (data[0] & data[1]);
outw(s->state, dev->iobase + PCI1723_WRITE_DIGITAL_OUTPUT_CMD);
}
data[1] = inw(dev->iobase + PCI1723_READ_DIGITAL_INPUT_DATA);
return insn->n;
}
static int pci1723_auto_attach(struct comedi_device *dev,
unsigned long context_unused)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
struct pci1723_private *devpriv;
struct comedi_subdevice *s;
int ret;
dev->board_name = dev->driver->driver_name;
devpriv = kzalloc(sizeof(*devpriv), GFP_KERNEL);
if (!devpriv)
return -ENOMEM;
dev->private = devpriv;
ret = comedi_pci_enable(pcidev, dev->board_name);
if (ret)
return ret;
dev->iobase = pci_resource_start(pcidev, 2);
ret = comedi_alloc_subdevices(dev, 2);
if (ret)
return ret;
s = &dev->subdevices[0];
dev->write_subdev = s;
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITEABLE | SDF_GROUND | SDF_COMMON;
s->n_chan = 8;
s->maxdata = 0xffff;
s->len_chanlist = 8;
s->range_table = &range_bipolar10;
s->insn_write = pci1723_ao_write_winsn;
s->insn_read = pci1723_insn_read_ao;
s = &dev->subdevices[1];
s->type = COMEDI_SUBD_DIO;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE;
s->n_chan = 16;
s->maxdata = 1;
s->len_chanlist = 16;
s->range_table = &range_digital;
s->insn_config = pci1723_dio_insn_config;
s->insn_bits = pci1723_dio_insn_bits;
switch (inw(dev->iobase + PCI1723_DIGITAL_IO_PORT_MODE) & 0x03) {
case 0x00:
s->io_bits = 0xFFFF;
break;
case 0x01:
s->io_bits = 0xFF00;
break;
case 0x02:
s->io_bits = 0x00FF;
break;
case 0x03:
s->io_bits = 0x0000;
break;
}
s->state = inw(dev->iobase + PCI1723_READ_DIGITAL_INPUT_DATA);
pci1723_reset(dev);
dev_info(dev->class_dev, "%s attached\n", dev->board_name);
return 0;
}
static void pci1723_detach(struct comedi_device *dev)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
if (pcidev) {
if (dev->iobase) {
pci1723_reset(dev);
comedi_pci_disable(pcidev);
}
}
}
static int adv_pci1723_pci_probe(struct pci_dev *dev,
const struct pci_device_id *ent)
{
return comedi_pci_auto_config(dev, &adv_pci1723_driver);
}
static void adv_pci1723_pci_remove(struct pci_dev *dev)
{
comedi_pci_auto_unconfig(dev);
}
