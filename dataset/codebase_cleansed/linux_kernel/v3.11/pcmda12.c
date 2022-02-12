static int pcmda12_ao_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct pcmda12_private *devpriv = dev->private;
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned int val = devpriv->ao_readback[chan];
unsigned long ioreg = dev->iobase + (chan * 2);
int i;
for (i = 0; i < insn->n; ++i) {
val = data[i];
outb(val & 0xff, ioreg);
outb((val >> 8) & 0xff, ioreg + 1);
if (!devpriv->simultaneous_xfer_mode)
inb(ioreg);
}
devpriv->ao_readback[chan] = val;
return insn->n;
}
static int pcmda12_ao_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct pcmda12_private *devpriv = dev->private;
unsigned int chan = CR_CHAN(insn->chanspec);
int i;
if (devpriv->simultaneous_xfer_mode)
inb(dev->iobase);
for (i = 0; i < insn->n; i++)
data[i] = devpriv->ao_readback[chan];
return insn->n;
}
static void pcmda12_ao_reset(struct comedi_device *dev,
struct comedi_subdevice *s)
{
int i;
for (i = 0; i < s->n_chan; ++i) {
outb(0, dev->iobase + (i * 2));
outb(0, dev->iobase + (i * 2) + 1);
}
inb(dev->iobase);
}
static int pcmda12_attach(struct comedi_device *dev,
struct comedi_devconfig *it)
{
struct pcmda12_private *devpriv;
struct comedi_subdevice *s;
int ret;
ret = comedi_request_region(dev, it->options[0], 0x10);
if (ret)
return ret;
devpriv = kzalloc(sizeof(*devpriv), GFP_KERNEL);
if (!devpriv)
return -ENOMEM;
dev->private = devpriv;
devpriv->simultaneous_xfer_mode = it->options[1];
ret = comedi_alloc_subdevices(dev, 1);
if (ret)
return ret;
s = &dev->subdevices[0];
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE;
s->n_chan = 8;
s->maxdata = 0x0fff;
s->range_table = &pcmda12_ranges;
s->insn_write = pcmda12_ao_insn_write;
s->insn_read = pcmda12_ao_insn_read;
pcmda12_ao_reset(dev, s);
return 0;
}
