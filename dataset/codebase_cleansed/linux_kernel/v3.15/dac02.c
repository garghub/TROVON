static int dac02_ao_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct dac02_private *devpriv = dev->private;
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned int range = CR_RANGE(insn->chanspec);
unsigned int val;
int i;
for (i = 0; i < insn->n; i++) {
val = data[i];
devpriv->ao_readback[chan] = val;
if (comedi_range_is_bipolar(s, range))
val = s->maxdata - val;
outb((val << 4) & 0xf0, dev->iobase + DAC02_AO_LSB(chan));
outb((val >> 4) & 0xff, dev->iobase + DAC02_AO_MSB(chan));
}
return insn->n;
}
static int dac02_ao_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct dac02_private *devpriv = dev->private;
unsigned int chan = CR_CHAN(insn->chanspec);
int i;
for (i = 0; i < insn->n; i++)
data[i] = devpriv->ao_readback[chan];
return insn->n;
}
static int dac02_attach(struct comedi_device *dev, struct comedi_devconfig *it)
{
struct dac02_private *devpriv;
struct comedi_subdevice *s;
int ret;
devpriv = comedi_alloc_devpriv(dev, sizeof(*devpriv));
if (!devpriv)
return -ENOMEM;
ret = comedi_request_region(dev, it->options[0], 0x08);
if (ret)
return ret;
ret = comedi_alloc_subdevices(dev, 1);
if (ret)
return ret;
s = &dev->subdevices[0];
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = 2;
s->maxdata = 0x0fff;
s->range_table = &das02_ao_ranges;
s->insn_write = dac02_ao_insn_write;
s->insn_read = dac02_ao_insn_read;
return 0;
}
