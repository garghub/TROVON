static int adq12b_ai_eoc(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned long context)
{
unsigned char status;
status = inb(dev->iobase + ADQ12B_STINR);
if (status & ADQ12B_STINR_EOC)
return 0;
return -EBUSY;
}
static int adq12b_ai_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct adq12b_private *devpriv = dev->private;
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned int range = CR_RANGE(insn->chanspec);
unsigned int val;
int ret;
int i;
val = ADQ12B_CTREG_RANGE(range) | ADQ12B_CTREG_CHAN(chan);
if (val != devpriv->last_ctreg) {
outb(val, dev->iobase + ADQ12B_CTREG);
devpriv->last_ctreg = val;
udelay(50);
}
val = inb(dev->iobase + ADQ12B_ADLOW);
for (i = 0; i < insn->n; i++) {
ret = comedi_timeout(dev, s, insn, adq12b_ai_eoc, 0);
if (ret)
return ret;
val = inb(dev->iobase + ADQ12B_ADHIG) << 8;
val |= inb(dev->iobase + ADQ12B_ADLOW);
data[i] = val;
}
return insn->n;
}
static int adq12b_di_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
data[1] = (inb(dev->iobase + ADQ12B_STINR) & ADQ12B_STINR_IN_MASK);
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
ret = comedi_request_region(dev, it->options[0], 0x10);
if (ret)
return ret;
devpriv = comedi_alloc_devpriv(dev, sizeof(*devpriv));
if (!devpriv)
return -ENOMEM;
devpriv->last_ctreg = -1;
ret = comedi_alloc_subdevices(dev, 3);
if (ret)
return ret;
s = &dev->subdevices[0];
s->type = COMEDI_SUBD_AI;
if (it->options[2]) {
s->subdev_flags = SDF_READABLE | SDF_DIFF;
s->n_chan = 8;
} else {
s->subdev_flags = SDF_READABLE | SDF_GROUND;
s->n_chan = 16;
}
s->maxdata = 0xfff;
s->range_table = it->options[1] ? &range_adq12b_ai_unipolar
: &range_adq12b_ai_bipolar;
s->insn_read = adq12b_ai_insn_read;
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
