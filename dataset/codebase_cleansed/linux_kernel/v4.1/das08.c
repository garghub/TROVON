static int das08_ai_eoc(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned long context)
{
unsigned int status;
status = inb(dev->iobase + DAS08_STATUS);
if ((status & DAS08_EOC) == 0)
return 0;
return -EBUSY;
}
static int das08_ai_rinsn(struct comedi_device *dev, struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
const struct das08_board_struct *thisboard = dev->board_ptr;
struct das08_private_struct *devpriv = dev->private;
int n;
int chan;
int range;
int lsb, msb;
int ret;
chan = CR_CHAN(insn->chanspec);
range = CR_RANGE(insn->chanspec);
inb(dev->iobase + DAS08_LSB);
inb(dev->iobase + DAS08_MSB);
spin_lock(&dev->spinlock);
devpriv->do_mux_bits &= ~DAS08_MUX_MASK;
devpriv->do_mux_bits |= DAS08_MUX(chan);
outb(devpriv->do_mux_bits, dev->iobase + DAS08_CONTROL);
spin_unlock(&dev->spinlock);
if (s->range_table->length > 1) {
range = CR_RANGE(insn->chanspec);
outb(devpriv->pg_gainlist[range],
dev->iobase + DAS08AO_GAIN_CONTROL);
}
for (n = 0; n < insn->n; n++) {
if (thisboard->ai_nbits == 16)
if (inb(dev->iobase + DAS08_MSB) & 0x80)
dev_info(dev->class_dev, "over-range\n");
outb_p(0, dev->iobase + DAS08_TRIG_12BIT);
ret = comedi_timeout(dev, s, insn, das08_ai_eoc, 0);
if (ret)
return ret;
msb = inb(dev->iobase + DAS08_MSB);
lsb = inb(dev->iobase + DAS08_LSB);
if (thisboard->ai_encoding == das08_encode12) {
data[n] = (lsb >> 4) | (msb << 4);
} else if (thisboard->ai_encoding == das08_pcm_encode12) {
data[n] = (msb << 8) + lsb;
} else if (thisboard->ai_encoding == das08_encode16) {
if (msb & 0x80)
data[n] = (1 << 15) | lsb | ((msb & 0x7f) << 8);
else
data[n] = (1 << 15) - (lsb | (msb & 0x7f) << 8);
} else {
dev_err(dev->class_dev, "bug! unknown ai encoding\n");
return -1;
}
}
return n;
}
static int das08_di_rbits(struct comedi_device *dev, struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
data[0] = 0;
data[1] = DAS08_IP(inb(dev->iobase + DAS08_STATUS));
return insn->n;
}
static int das08_do_wbits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct das08_private_struct *devpriv = dev->private;
if (comedi_dio_update_state(s, data)) {
spin_lock(&dev->spinlock);
devpriv->do_mux_bits &= ~DAS08_DO_MASK;
devpriv->do_mux_bits |= DAS08_OP(s->state);
outb(devpriv->do_mux_bits, dev->iobase + DAS08_CONTROL);
spin_unlock(&dev->spinlock);
}
data[1] = s->state;
return insn->n;
}
static int das08jr_di_rbits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
data[0] = 0;
data[1] = inb(dev->iobase + DAS08JR_DIO);
return insn->n;
}
static int das08jr_do_wbits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
if (comedi_dio_update_state(s, data))
outb(s->state, dev->iobase + DAS08JR_DIO);
data[1] = s->state;
return insn->n;
}
static void das08_ao_set_data(struct comedi_device *dev,
unsigned int chan, unsigned int data)
{
const struct das08_board_struct *thisboard = dev->board_ptr;
unsigned char lsb;
unsigned char msb;
lsb = data & 0xff;
msb = (data >> 8) & 0xff;
if (thisboard->is_jr) {
outb(lsb, dev->iobase + DAS08JR_AO_LSB(chan));
outb(msb, dev->iobase + DAS08JR_AO_MSB(chan));
inb(dev->iobase + DAS08JR_DIO);
} else {
outb(lsb, dev->iobase + DAS08AO_AO_LSB(chan));
outb(msb, dev->iobase + DAS08AO_AO_MSB(chan));
inb(dev->iobase + DAS08AO_AO_UPDATE);
}
}
static int das08_ao_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned int val = s->readback[chan];
int i;
for (i = 0; i < insn->n; i++) {
val = data[i];
das08_ao_set_data(dev, chan, val);
}
s->readback[chan] = val;
return insn->n;
}
int das08_common_attach(struct comedi_device *dev, unsigned long iobase)
{
const struct das08_board_struct *thisboard = dev->board_ptr;
struct das08_private_struct *devpriv = dev->private;
struct comedi_subdevice *s;
int ret;
int i;
dev->iobase = iobase;
dev->board_name = thisboard->name;
ret = comedi_alloc_subdevices(dev, 6);
if (ret)
return ret;
s = &dev->subdevices[0];
if (thisboard->ai_nbits) {
s->type = COMEDI_SUBD_AI;
s->subdev_flags = SDF_READABLE | SDF_GROUND;
s->n_chan = 8;
s->maxdata = (1 << thisboard->ai_nbits) - 1;
s->range_table = das08_ai_lranges[thisboard->ai_pg];
s->insn_read = das08_ai_rinsn;
devpriv->pg_gainlist = das08_gainlists[thisboard->ai_pg];
} else {
s->type = COMEDI_SUBD_UNUSED;
}
s = &dev->subdevices[1];
if (thisboard->ao_nbits) {
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = 2;
s->maxdata = (1 << thisboard->ao_nbits) - 1;
s->range_table = &range_bipolar5;
s->insn_write = das08_ao_insn_write;
ret = comedi_alloc_subdev_readback(s);
if (ret)
return ret;
for (i = 0; i < s->n_chan; i++) {
s->readback[i] = s->maxdata / 2;
das08_ao_set_data(dev, i, s->readback[i]);
}
} else {
s->type = COMEDI_SUBD_UNUSED;
}
s = &dev->subdevices[2];
if (thisboard->di_nchan) {
s->type = COMEDI_SUBD_DI;
s->subdev_flags = SDF_READABLE;
s->n_chan = thisboard->di_nchan;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits =
thisboard->is_jr ? das08jr_di_rbits : das08_di_rbits;
} else {
s->type = COMEDI_SUBD_UNUSED;
}
s = &dev->subdevices[3];
if (thisboard->do_nchan) {
s->type = COMEDI_SUBD_DO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = thisboard->do_nchan;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits =
thisboard->is_jr ? das08jr_do_wbits : das08_do_wbits;
} else {
s->type = COMEDI_SUBD_UNUSED;
}
s = &dev->subdevices[4];
if (thisboard->i8255_offset != 0) {
ret = subdev_8255_init(dev, s, NULL, thisboard->i8255_offset);
if (ret)
return ret;
} else {
s->type = COMEDI_SUBD_UNUSED;
}
s = &dev->subdevices[5];
if (thisboard->i8254_offset) {
dev->pacer = comedi_8254_init(dev->iobase +
thisboard->i8254_offset,
0, I8254_IO8, 0);
if (!dev->pacer)
return -ENOMEM;
comedi_8254_subdevice_init(s, dev->pacer);
} else {
s->type = COMEDI_SUBD_UNUSED;
}
return 0;
}
static int __init das08_init(void)
{
return 0;
}
static void __exit das08_exit(void)
{
}
