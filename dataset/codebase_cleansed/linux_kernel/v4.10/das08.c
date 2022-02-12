static int das08_ai_eoc(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned long context)
{
unsigned int status;
status = inb(dev->iobase + DAS08_STATUS_REG);
if ((status & DAS08_STATUS_AI_BUSY) == 0)
return 0;
return -EBUSY;
}
static int das08_ai_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
const struct das08_board_struct *board = dev->board_ptr;
struct das08_private_struct *devpriv = dev->private;
int n;
int chan;
int range;
int lsb, msb;
int ret;
chan = CR_CHAN(insn->chanspec);
range = CR_RANGE(insn->chanspec);
inb(dev->iobase + DAS08_AI_LSB_REG);
inb(dev->iobase + DAS08_AI_MSB_REG);
spin_lock(&dev->spinlock);
devpriv->do_mux_bits &= ~DAS08_CONTROL_MUX_MASK;
devpriv->do_mux_bits |= DAS08_CONTROL_MUX(chan);
outb(devpriv->do_mux_bits, dev->iobase + DAS08_CONTROL_REG);
spin_unlock(&dev->spinlock);
if (devpriv->pg_gainlist) {
range = CR_RANGE(insn->chanspec);
outb(devpriv->pg_gainlist[range],
dev->iobase + DAS08_GAIN_REG);
}
for (n = 0; n < insn->n; n++) {
if (board->ai_nbits == 16)
if (inb(dev->iobase + DAS08_AI_MSB_REG) & 0x80)
dev_info(dev->class_dev, "over-range\n");
outb_p(0, dev->iobase + DAS08_AI_TRIG_REG);
ret = comedi_timeout(dev, s, insn, das08_ai_eoc, 0);
if (ret)
return ret;
msb = inb(dev->iobase + DAS08_AI_MSB_REG);
lsb = inb(dev->iobase + DAS08_AI_LSB_REG);
if (board->ai_encoding == das08_encode12) {
data[n] = (lsb >> 4) | (msb << 4);
} else if (board->ai_encoding == das08_pcm_encode12) {
data[n] = (msb << 8) + lsb;
} else if (board->ai_encoding == das08_encode16) {
unsigned int magnitude = lsb | ((msb & 0x7f) << 8);
if (msb & 0x80)
data[n] = (1 << 15) + magnitude;
else
data[n] = (1 << 15) - magnitude;
} else {
dev_err(dev->class_dev, "bug! unknown ai encoding\n");
return -1;
}
}
return n;
}
static int das08_di_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
data[0] = 0;
data[1] = DAS08_STATUS_DI(inb(dev->iobase + DAS08_STATUS_REG));
return insn->n;
}
static int das08_do_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct das08_private_struct *devpriv = dev->private;
if (comedi_dio_update_state(s, data)) {
spin_lock(&dev->spinlock);
devpriv->do_mux_bits &= ~DAS08_CONTROL_DO_MASK;
devpriv->do_mux_bits |= DAS08_CONTROL_DO(s->state);
outb(devpriv->do_mux_bits, dev->iobase + DAS08_CONTROL_REG);
spin_unlock(&dev->spinlock);
}
data[1] = s->state;
return insn->n;
}
static int das08jr_di_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
data[0] = 0;
data[1] = inb(dev->iobase + DAS08JR_DI_REG);
return insn->n;
}
static int das08jr_do_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
if (comedi_dio_update_state(s, data))
outb(s->state, dev->iobase + DAS08JR_DO_REG);
data[1] = s->state;
return insn->n;
}
static void das08_ao_set_data(struct comedi_device *dev,
unsigned int chan, unsigned int data)
{
const struct das08_board_struct *board = dev->board_ptr;
unsigned char lsb;
unsigned char msb;
lsb = data & 0xff;
msb = (data >> 8) & 0xff;
if (board->is_jr) {
outb(lsb, dev->iobase + DAS08JR_AO_LSB_REG(chan));
outb(msb, dev->iobase + DAS08JR_AO_MSB_REG(chan));
inb(dev->iobase + DAS08JR_AO_UPDATE_REG);
} else {
outb(lsb, dev->iobase + DAS08AOX_AO_LSB_REG(chan));
outb(msb, dev->iobase + DAS08AOX_AO_MSB_REG(chan));
inb(dev->iobase + DAS08AOX_AO_UPDATE_REG);
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
const struct das08_board_struct *board = dev->board_ptr;
struct das08_private_struct *devpriv = dev->private;
struct comedi_subdevice *s;
int ret;
int i;
dev->iobase = iobase;
dev->board_name = board->name;
ret = comedi_alloc_subdevices(dev, 6);
if (ret)
return ret;
s = &dev->subdevices[0];
if (board->ai_nbits) {
s->type = COMEDI_SUBD_AI;
s->subdev_flags = SDF_READABLE | SDF_GROUND;
s->n_chan = 8;
s->maxdata = (1 << board->ai_nbits) - 1;
s->range_table = das08_ai_lranges[board->ai_pg];
s->insn_read = das08_ai_insn_read;
devpriv->pg_gainlist = das08_ai_gainlists[board->ai_pg];
} else {
s->type = COMEDI_SUBD_UNUSED;
}
s = &dev->subdevices[1];
if (board->ao_nbits) {
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = 2;
s->maxdata = (1 << board->ao_nbits) - 1;
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
if (board->di_nchan) {
s->type = COMEDI_SUBD_DI;
s->subdev_flags = SDF_READABLE;
s->n_chan = board->di_nchan;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = board->is_jr ? das08jr_di_insn_bits :
das08_di_insn_bits;
} else {
s->type = COMEDI_SUBD_UNUSED;
}
s = &dev->subdevices[3];
if (board->do_nchan) {
s->type = COMEDI_SUBD_DO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = board->do_nchan;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = board->is_jr ? das08jr_do_insn_bits :
das08_do_insn_bits;
} else {
s->type = COMEDI_SUBD_UNUSED;
}
s = &dev->subdevices[4];
if (board->i8255_offset != 0) {
ret = subdev_8255_init(dev, s, NULL, board->i8255_offset);
if (ret)
return ret;
} else {
s->type = COMEDI_SUBD_UNUSED;
}
s = &dev->subdevices[5];
if (board->i8254_offset) {
dev->pacer = comedi_8254_init(dev->iobase + board->i8254_offset,
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
