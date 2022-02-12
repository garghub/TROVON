static int adq12b_ai_rinsn(struct comedi_device *dev,
struct comedi_subdevice *s, struct comedi_insn *insn,
unsigned int *data)
{
struct adq12b_private *devpriv = dev->private;
int n, i;
int range, channel;
unsigned char hi, lo, status;
range = CR_RANGE(insn->chanspec);
channel = CR_CHAN(insn->chanspec);
if (channel != devpriv->last_channel || range != devpriv->last_range) {
outb((range << 4) | channel, dev->iobase + ADQ12B_CTREG);
udelay(50);
}
status = inb(dev->iobase + ADQ12B_ADLOW);
for (n = 0; n < insn->n; n++) {
i = 0;
do {
status = inb(dev->iobase + ADQ12B_STINR);
status = status & ADQ12B_EOC;
} while (status == 0 && ++i < TIMEOUT);
hi = inb(dev->iobase + ADQ12B_ADHIG);
lo = inb(dev->iobase + ADQ12B_ADLOW);
data[n] = (hi << 8) | lo;
}
return n;
}
static int adq12b_di_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
data[1] = (inb(dev->iobase + ADQ12B_STINR) & (0x1f));
return insn->n;
}
static int adq12b_do_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned int mask;
unsigned int chan;
unsigned int val;
mask = comedi_dio_update_state(s, data);
if (mask) {
for (chan = 0; chan < 8; chan++) {
if ((mask >> chan) & 0x01) {
val = (s->state >> chan) & 0x01;
outb((val << 3) | chan,
dev->iobase + ADQ12B_OUTBR);
}
}
}
data[1] = s->state;
return insn->n;
}
static int adq12b_attach(struct comedi_device *dev, struct comedi_devconfig *it)
{
struct adq12b_private *devpriv;
struct comedi_subdevice *s;
int ret;
ret = comedi_request_region(dev, it->options[0], ADQ12B_SIZE);
if (ret)
return ret;
devpriv = comedi_alloc_devpriv(dev, sizeof(*devpriv));
if (!devpriv)
return -ENOMEM;
devpriv->unipolar = it->options[1];
devpriv->differential = it->options[2];
devpriv->last_channel = -1;
devpriv->last_range = -1;
ret = comedi_alloc_subdevices(dev, 3);
if (ret)
return ret;
s = &dev->subdevices[0];
s->type = COMEDI_SUBD_AI;
if (devpriv->differential) {
s->subdev_flags = SDF_READABLE | SDF_GROUND | SDF_DIFF;
s->n_chan = 8;
} else {
s->subdev_flags = SDF_READABLE | SDF_GROUND;
s->n_chan = 16;
}
if (devpriv->unipolar)
s->range_table = &range_adq12b_ai_unipolar;
else
s->range_table = &range_adq12b_ai_bipolar;
s->maxdata = 0xfff;
s->len_chanlist = 4;
s->insn_read = adq12b_ai_rinsn;
s = &dev->subdevices[1];
s->type = COMEDI_SUBD_DI;
s->subdev_flags = SDF_READABLE;
s->n_chan = 5;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = adq12b_di_insn_bits;
s = &dev->subdevices[2];
s->type = COMEDI_SUBD_DO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = 8;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = adq12b_do_insn_bits;
return 0;
}
