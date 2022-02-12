static int rti800_ai_eoc(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned long context)
{
unsigned char status;
status = inb(dev->iobase + RTI800_CSR);
if (status & RTI800_CSR_OVERRUN) {
outb(0, dev->iobase + RTI800_CLRFLAGS);
return -EOVERFLOW;
}
if (status & RTI800_CSR_DONE)
return 0;
return -EBUSY;
}
static int rti800_ai_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct rti800_private *devpriv = dev->private;
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned int gain = CR_RANGE(insn->chanspec);
unsigned char muxgain_bits;
int ret;
int i;
inb(dev->iobase + RTI800_ADCHI);
outb(0, dev->iobase + RTI800_CLRFLAGS);
muxgain_bits = chan | (gain << 5);
if (muxgain_bits != devpriv->muxgain_bits) {
devpriv->muxgain_bits = muxgain_bits;
outb(devpriv->muxgain_bits, dev->iobase + RTI800_MUXGAIN);
if (insn->n > 0) {
int delay = (gain == 0) ? 10 :
(gain == 1) ? 20 :
(gain == 2) ? 40 : 80;
udelay(delay);
}
}
for (i = 0; i < insn->n; i++) {
outb(0, dev->iobase + RTI800_CONVERT);
ret = comedi_timeout(dev, s, insn, rti800_ai_eoc, 0);
if (ret)
return ret;
data[i] = inb(dev->iobase + RTI800_ADCLO);
data[i] |= (inb(dev->iobase + RTI800_ADCHI) & 0xf) << 8;
if (devpriv->adc_2comp)
data[i] ^= 0x800;
}
return insn->n;
}
static int rti800_ao_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct rti800_private *devpriv = dev->private;
unsigned int chan = CR_CHAN(insn->chanspec);
int reg_lo = chan ? RTI800_DAC1LO : RTI800_DAC0LO;
int reg_hi = chan ? RTI800_DAC1HI : RTI800_DAC0HI;
int i;
for (i = 0; i < insn->n; i++) {
unsigned int val = data[i];
s->readback[chan] = val;
if (devpriv->dac_2comp[chan])
val ^= 0x800;
outb(val & 0xff, dev->iobase + reg_lo);
outb((val >> 8) & 0xff, dev->iobase + reg_hi);
}
return insn->n;
}
static int rti800_di_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
data[1] = inb(dev->iobase + RTI800_DI);
return insn->n;
}
static int rti800_do_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
if (comedi_dio_update_state(s, data)) {
outb(s->state ^ 0xff, dev->iobase + RTI800_DO);
}
data[1] = s->state;
return insn->n;
}
static int rti800_attach(struct comedi_device *dev, struct comedi_devconfig *it)
{
const struct rti800_board *board = dev->board_ptr;
struct rti800_private *devpriv;
struct comedi_subdevice *s;
int ret;
ret = comedi_request_region(dev, it->options[0], 0x10);
if (ret)
return ret;
outb(0, dev->iobase + RTI800_CSR);
inb(dev->iobase + RTI800_ADCHI);
outb(0, dev->iobase + RTI800_CLRFLAGS);
devpriv = comedi_alloc_devpriv(dev, sizeof(*devpriv));
if (!devpriv)
return -ENOMEM;
devpriv->adc_2comp = (it->options[4] == 0);
devpriv->dac_2comp[0] = (it->options[6] == 0);
devpriv->dac_2comp[1] = (it->options[8] == 0);
devpriv->muxgain_bits = 0xff;
ret = comedi_alloc_subdevices(dev, 4);
if (ret)
return ret;
s = &dev->subdevices[0];
s->type = COMEDI_SUBD_AI;
s->subdev_flags = SDF_READABLE | SDF_GROUND;
s->n_chan = (it->options[2] ? 16 : 8);
s->insn_read = rti800_ai_insn_read;
s->maxdata = 0x0fff;
s->range_table = (it->options[3] < ARRAY_SIZE(rti800_ai_ranges))
? rti800_ai_ranges[it->options[3]]
: &range_unknown;
s = &dev->subdevices[1];
if (board->has_ao) {
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = 2;
s->maxdata = 0x0fff;
s->range_table_list = devpriv->ao_range_type_list;
devpriv->ao_range_type_list[0] =
(it->options[5] < ARRAY_SIZE(rti800_ao_ranges))
? rti800_ao_ranges[it->options[5]]
: &range_unknown;
devpriv->ao_range_type_list[1] =
(it->options[7] < ARRAY_SIZE(rti800_ao_ranges))
? rti800_ao_ranges[it->options[7]]
: &range_unknown;
s->insn_write = rti800_ao_insn_write;
s->insn_read = comedi_readback_insn_read;
ret = comedi_alloc_subdev_readback(s);
if (ret)
return ret;
} else {
s->type = COMEDI_SUBD_UNUSED;
}
s = &dev->subdevices[2];
s->type = COMEDI_SUBD_DI;
s->subdev_flags = SDF_READABLE;
s->n_chan = 8;
s->insn_bits = rti800_di_insn_bits;
s->maxdata = 1;
s->range_table = &range_digital;
s = &dev->subdevices[3];
s->type = COMEDI_SUBD_DO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = 8;
s->insn_bits = rti800_do_insn_bits;
s->maxdata = 1;
s->range_table = &range_digital;
return 0;
}
