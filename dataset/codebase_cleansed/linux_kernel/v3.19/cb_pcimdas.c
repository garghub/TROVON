static int cb_pcimdas_ai_eoc(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned long context)
{
struct cb_pcimdas_private *devpriv = dev->private;
unsigned int status;
status = inb(devpriv->BADR3 + 2);
if ((status & 0x80) == 0)
return 0;
return -EBUSY;
}
static int cb_pcimdas_ai_rinsn(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct cb_pcimdas_private *devpriv = dev->private;
int n;
unsigned int d;
int chan = CR_CHAN(insn->chanspec);
unsigned short chanlims;
int maxchans;
int ret;
if ((inb(devpriv->BADR3 + 2) & 0x20) == 0)
maxchans = s->n_chan / 2;
else
maxchans = s->n_chan;
if (chan > (maxchans - 1))
return -ETIMEDOUT;
d = inb(devpriv->BADR3 + 5);
if ((d & 0x03) > 0) {
d = d & 0xfd;
outb(d, devpriv->BADR3 + 5);
}
outb(0x01, devpriv->BADR3 + 6);
outb(0x00, devpriv->BADR3 + 7);
chanlims = chan | (chan << 4);
outb(chanlims, devpriv->BADR3 + 0);
for (n = 0; n < insn->n; n++) {
outw(0, devpriv->daqio + 0);
ret = comedi_timeout(dev, s, insn, cb_pcimdas_ai_eoc, 0);
if (ret)
return ret;
data[n] = inw(devpriv->daqio + 0);
}
return n;
}
static int cb_pcimdas_ao_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct cb_pcimdas_private *devpriv = dev->private;
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned int val = s->readback[chan];
unsigned int reg = (chan) ? DAC1_OFFSET : DAC0_OFFSET;
int i;
for (i = 0; i < insn->n; i++) {
val = data[i];
outw(val, devpriv->daqio + reg);
}
s->readback[chan] = val;
return insn->n;
}
static int cb_pcimdas_auto_attach(struct comedi_device *dev,
unsigned long context_unused)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
struct cb_pcimdas_private *devpriv;
struct comedi_subdevice *s;
int ret;
devpriv = comedi_alloc_devpriv(dev, sizeof(*devpriv));
if (!devpriv)
return -ENOMEM;
ret = comedi_pci_enable(dev);
if (ret)
return ret;
devpriv->daqio = pci_resource_start(pcidev, 2);
devpriv->BADR3 = pci_resource_start(pcidev, 3);
dev->iobase = pci_resource_start(pcidev, 4);
ret = comedi_alloc_subdevices(dev, 3);
if (ret)
return ret;
s = &dev->subdevices[0];
s->type = COMEDI_SUBD_AI;
s->subdev_flags = SDF_READABLE | SDF_GROUND;
s->n_chan = 16;
s->maxdata = 0xffff;
s->range_table = &range_unknown;
s->len_chanlist = 1;
s->insn_read = cb_pcimdas_ai_rinsn;
s = &dev->subdevices[1];
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = 2;
s->maxdata = 0xfff;
s->range_table = &range_unknown;
s->insn_write = cb_pcimdas_ao_insn_write;
ret = comedi_alloc_subdev_readback(s);
if (ret)
return ret;
s = &dev->subdevices[2];
ret = subdev_8255_init(dev, s, NULL, 0x00);
if (ret)
return ret;
return 0;
}
static int cb_pcimdas_pci_probe(struct pci_dev *dev,
const struct pci_device_id *id)
{
return comedi_pci_auto_config(dev, &cb_pcimdas_driver,
id->driver_data);
}
