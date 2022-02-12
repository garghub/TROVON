static int multiq3_ai_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
int i, n;
int chan;
unsigned int hi, lo;
chan = CR_CHAN(insn->chanspec);
outw(MULTIQ3_CONTROL_MUST | MULTIQ3_AD_MUX_EN | (chan << 3),
dev->iobase + MULTIQ3_CONTROL);
for (i = 0; i < MULTIQ3_TIMEOUT; i++) {
if (inw(dev->iobase + MULTIQ3_STATUS) & MULTIQ3_STATUS_EOC)
break;
}
if (i == MULTIQ3_TIMEOUT)
return -ETIMEDOUT;
for (n = 0; n < insn->n; n++) {
outw(0, dev->iobase + MULTIQ3_AD_CS);
for (i = 0; i < MULTIQ3_TIMEOUT; i++) {
if (inw(dev->iobase +
MULTIQ3_STATUS) & MULTIQ3_STATUS_EOC_I)
break;
}
if (i == MULTIQ3_TIMEOUT)
return -ETIMEDOUT;
hi = inb(dev->iobase + MULTIQ3_AD_CS);
lo = inb(dev->iobase + MULTIQ3_AD_CS);
data[n] = (((hi << 8) | lo) + 0x1000) & 0x1fff;
}
return n;
}
static int multiq3_ao_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct multiq3_private *devpriv = dev->private;
int i;
int chan = CR_CHAN(insn->chanspec);
for (i = 0; i < insn->n; i++)
data[i] = devpriv->ao_readback[chan];
return i;
}
static int multiq3_ao_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct multiq3_private *devpriv = dev->private;
int i;
int chan = CR_CHAN(insn->chanspec);
for (i = 0; i < insn->n; i++) {
outw(MULTIQ3_CONTROL_MUST | MULTIQ3_DA_LOAD | chan,
dev->iobase + MULTIQ3_CONTROL);
outw(data[i], dev->iobase + MULTIQ3_DAC_DATA);
outw(MULTIQ3_CONTROL_MUST, dev->iobase + MULTIQ3_CONTROL);
devpriv->ao_readback[chan] = data[i];
}
return i;
}
static int multiq3_di_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
data[1] = inw(dev->iobase + MULTIQ3_DIGIN_PORT);
return insn->n;
}
static int multiq3_do_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
s->state &= ~data[0];
s->state |= (data[0] & data[1]);
outw(s->state, dev->iobase + MULTIQ3_DIGOUT_PORT);
data[1] = s->state;
return insn->n;
}
static int multiq3_encoder_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
int n;
int chan = CR_CHAN(insn->chanspec);
int control = MULTIQ3_CONTROL_MUST | MULTIQ3_AD_MUX_EN | (chan << 3);
for (n = 0; n < insn->n; n++) {
int value;
outw(control, dev->iobase + MULTIQ3_CONTROL);
outb(MULTIQ3_BP_RESET, dev->iobase + MULTIQ3_ENC_CONTROL);
outb(MULTIQ3_TRSFRCNTR_OL, dev->iobase + MULTIQ3_ENC_CONTROL);
value = inb(dev->iobase + MULTIQ3_ENC_DATA);
value |= (inb(dev->iobase + MULTIQ3_ENC_DATA) << 8);
value |= (inb(dev->iobase + MULTIQ3_ENC_DATA) << 16);
data[n] = (value + 0x800000) & 0xffffff;
}
return n;
}
static void encoder_reset(struct comedi_device *dev)
{
struct comedi_subdevice *s = &dev->subdevices[4];
int chan;
for (chan = 0; chan < s->n_chan; chan++) {
int control =
MULTIQ3_CONTROL_MUST | MULTIQ3_AD_MUX_EN | (chan << 3);
outw(control, dev->iobase + MULTIQ3_CONTROL);
outb(MULTIQ3_EFLAG_RESET, dev->iobase + MULTIQ3_ENC_CONTROL);
outb(MULTIQ3_BP_RESET, dev->iobase + MULTIQ3_ENC_CONTROL);
outb(MULTIQ3_CLOCK_DATA, dev->iobase + MULTIQ3_ENC_DATA);
outb(MULTIQ3_CLOCK_SETUP, dev->iobase + MULTIQ3_ENC_CONTROL);
outb(MULTIQ3_INPUT_SETUP, dev->iobase + MULTIQ3_ENC_CONTROL);
outb(MULTIQ3_QUAD_X4, dev->iobase + MULTIQ3_ENC_CONTROL);
outb(MULTIQ3_CNTR_RESET, dev->iobase + MULTIQ3_ENC_CONTROL);
}
}
static int multiq3_attach(struct comedi_device *dev,
struct comedi_devconfig *it)
{
struct multiq3_private *devpriv;
struct comedi_subdevice *s;
int ret;
ret = comedi_request_region(dev, it->options[0], MULTIQ3_SIZE);
if (ret)
return ret;
ret = comedi_alloc_subdevices(dev, 5);
if (ret)
return ret;
devpriv = kzalloc(sizeof(*devpriv), GFP_KERNEL);
if (!devpriv)
return -ENOMEM;
dev->private = devpriv;
s = &dev->subdevices[0];
s->type = COMEDI_SUBD_AI;
s->subdev_flags = SDF_READABLE | SDF_GROUND;
s->n_chan = 8;
s->insn_read = multiq3_ai_insn_read;
s->maxdata = 0x1fff;
s->range_table = &range_bipolar5;
s = &dev->subdevices[1];
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = 8;
s->insn_read = multiq3_ao_insn_read;
s->insn_write = multiq3_ao_insn_write;
s->maxdata = 0xfff;
s->range_table = &range_bipolar5;
s = &dev->subdevices[2];
s->type = COMEDI_SUBD_DI;
s->subdev_flags = SDF_READABLE;
s->n_chan = 16;
s->insn_bits = multiq3_di_insn_bits;
s->maxdata = 1;
s->range_table = &range_digital;
s = &dev->subdevices[3];
s->type = COMEDI_SUBD_DO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = 16;
s->insn_bits = multiq3_do_insn_bits;
s->maxdata = 1;
s->range_table = &range_digital;
s->state = 0;
s = &dev->subdevices[4];
s->type = COMEDI_SUBD_COUNTER;
s->subdev_flags = SDF_READABLE | SDF_LSAMPL;
s->n_chan = it->options[2] * 2;
s->insn_read = multiq3_encoder_insn_read;
s->maxdata = 0xffffff;
s->range_table = &range_unknown;
encoder_reset(dev);
return 0;
}
