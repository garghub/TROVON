static int pci1723_ao_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned int chan = CR_CHAN(insn->chanspec);
int i;
for (i = 0; i < insn->n; i++) {
unsigned int val = data[i];
outw(val, dev->iobase + PCI1723_AO_REG(chan));
s->readback[chan] = val;
}
return insn->n;
}
static int pci1723_dio_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned int mask = (chan < 8) ? 0x00ff : 0xff00;
unsigned short mode = 0x0000;
int ret;
ret = comedi_dio_insn_config(dev, s, insn, data, mask);
if (ret)
return ret;
if (!(s->io_bits & 0x00ff))
mode |= PCI1723_DIO_CTRL_LDIO;
if (!(s->io_bits & 0xff00))
mode |= PCI1723_DIO_CTRL_HDIO;
outw(mode, dev->iobase + PCI1723_DIO_CTRL_REG);
return insn->n;
}
static int pci1723_dio_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
if (comedi_dio_update_state(s, data))
outw(s->state, dev->iobase + PCI1723_DIO_DATA_REG);
data[1] = inw(dev->iobase + PCI1723_DIO_DATA_REG);
return insn->n;
}
static int pci1723_auto_attach(struct comedi_device *dev,
unsigned long context_unused)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
struct comedi_subdevice *s;
unsigned int val;
int ret;
int i;
ret = comedi_pci_enable(dev);
if (ret)
return ret;
dev->iobase = pci_resource_start(pcidev, 2);
ret = comedi_alloc_subdevices(dev, 2);
if (ret)
return ret;
s = &dev->subdevices[0];
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITABLE | SDF_GROUND | SDF_COMMON;
s->n_chan = 8;
s->maxdata = 0xffff;
s->range_table = &range_bipolar10;
s->insn_write = pci1723_ao_insn_write;
ret = comedi_alloc_subdev_readback(s);
if (ret)
return ret;
outw(PCI1723_SYNC_CTRL_SYNC, dev->iobase + PCI1723_SYNC_CTRL_REG);
for (i = 0; i < s->n_chan; i++) {
outw(PCI1723_CTRL_RANGE(0) | PCI1723_CTRL_CHAN(i),
PCI1723_CTRL_REG);
outw(0, dev->iobase + PCI1723_RANGE_STROBE_REG);
outw(0x8000, dev->iobase + PCI1723_AO_REG(i));
s->readback[i] = 0x8000;
}
outw(0, dev->iobase + PCI1723_SYNC_STROBE_REG);
outw(PCI1723_SYNC_CTRL_ASYNC, dev->iobase + PCI1723_SYNC_CTRL_REG);
s = &dev->subdevices[1];
s->type = COMEDI_SUBD_DIO;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE;
s->n_chan = 16;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_config = pci1723_dio_insn_config;
s->insn_bits = pci1723_dio_insn_bits;
val = inw(dev->iobase + PCI1723_DIO_CTRL_REG);
if (!(val & PCI1723_DIO_CTRL_LDIO))
s->io_bits |= 0x00ff;
if (!(val & PCI1723_DIO_CTRL_HDIO))
s->io_bits |= 0xff00;
s->state = inw(dev->iobase + PCI1723_DIO_DATA_REG);
return 0;
}
static int adv_pci1723_pci_probe(struct pci_dev *dev,
const struct pci_device_id *id)
{
return comedi_pci_auto_config(dev, &adv_pci1723_driver,
id->driver_data);
}
