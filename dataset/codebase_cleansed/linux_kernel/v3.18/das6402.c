static void das6402_set_mode(struct comedi_device *dev,
unsigned int mode)
{
outb(DAS6402_MODE_ENHANCED | mode, dev->iobase + DAS6402_MODE_REG);
}
static void das6402_set_extended(struct comedi_device *dev,
unsigned int val)
{
outb(DAS6402_STATUS_W_EXTEND, dev->iobase + DAS6402_STATUS_REG);
outb(DAS6402_STATUS_W_EXTEND | val, dev->iobase + DAS6402_STATUS_REG);
outb(val, dev->iobase + DAS6402_STATUS_REG);
}
static void das6402_clear_all_interrupts(struct comedi_device *dev)
{
outb(DAS6402_STATUS_W_CLRINT |
DAS6402_STATUS_W_CLRXTR |
DAS6402_STATUS_W_CLRXIN, dev->iobase + DAS6402_STATUS_REG);
}
static void das6402_ai_clear_eoc(struct comedi_device *dev)
{
outb(DAS6402_STATUS_W_CLRINT, dev->iobase + DAS6402_STATUS_REG);
}
static void das6402_enable_counter(struct comedi_device *dev, bool load)
{
struct das6402_private *devpriv = dev->private;
unsigned long timer_iobase = dev->iobase + DAS6402_TIMER_BASE;
if (load) {
i8254_set_mode(timer_iobase, 0, 0, I8254_MODE0 | I8254_BINARY);
i8254_set_mode(timer_iobase, 0, 1, I8254_MODE2 | I8254_BINARY);
i8254_set_mode(timer_iobase, 0, 2, I8254_MODE2 | I8254_BINARY);
i8254_write(timer_iobase, 0, 0, devpriv->count);
i8254_write(timer_iobase, 0, 1, devpriv->divider1);
i8254_write(timer_iobase, 0, 2, devpriv->divider2);
} else {
i8254_set_mode(timer_iobase, 0, 0, I8254_MODE0 | I8254_BINARY);
i8254_set_mode(timer_iobase, 0, 1, I8254_MODE0 | I8254_BINARY);
i8254_set_mode(timer_iobase, 0, 2, I8254_MODE0 | I8254_BINARY);
}
}
static irqreturn_t das6402_interrupt(int irq, void *d)
{
struct comedi_device *dev = d;
das6402_clear_all_interrupts(dev);
return IRQ_HANDLED;
}
static int das6402_ai_cmd(struct comedi_device *dev,
struct comedi_subdevice *s)
{
return -EINVAL;
}
static int das6402_ai_cmdtest(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_cmd *cmd)
{
return -EINVAL;
}
static int das6402_ai_cancel(struct comedi_device *dev,
struct comedi_subdevice *s)
{
outb(DAS6402_CTRL_SOFT_TRIG, dev->iobase + DAS6402_CTRL_REG);
return 0;
}
static void das6402_ai_soft_trig(struct comedi_device *dev)
{
outw(0, dev->iobase + DAS6402_AI_DATA_REG);
}
static int das6402_ai_eoc(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned long context)
{
unsigned int status;
status = inb(dev->iobase + DAS6402_STATUS_REG);
if (status & DAS6402_STATUS_FFNE)
return 0;
return -EBUSY;
}
static int das6402_ai_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned int range = CR_RANGE(insn->chanspec);
unsigned int aref = CR_AREF(insn->chanspec);
unsigned int val;
int ret;
int i;
val = DAS6402_MODE_RANGE(range) | DAS6402_MODE_POLLED;
if (aref == AREF_DIFF) {
if (chan > s->n_chan / 2)
return -EINVAL;
} else {
val |= DAS6402_MODE_SE;
}
if (comedi_range_is_unipolar(s, range))
val |= DAS6402_MODE_UNI;
outb(DAS6402_CTRL_SOFT_TRIG, dev->iobase + DAS6402_CTRL_REG);
das6402_set_mode(dev, val);
outw(DAS6402_AI_MUX_HI(chan) | DAS6402_AI_MUX_LO(chan),
dev->iobase + DAS6402_AI_MUX_REG);
for (i = 0; i < insn->n; i++) {
das6402_ai_clear_eoc(dev);
das6402_ai_soft_trig(dev);
ret = comedi_timeout(dev, s, insn, das6402_ai_eoc, 0);
if (ret)
break;
val = inw(dev->iobase + DAS6402_AI_DATA_REG);
if (s->maxdata == 0x0fff)
val >>= 4;
data[i] = val;
}
das6402_ai_clear_eoc(dev);
return insn->n;
}
static int das6402_ao_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct das6402_private *devpriv = dev->private;
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned int range = CR_RANGE(insn->chanspec);
unsigned int val;
int i;
val = devpriv->ao_range;
val &= ~DAS6402_AO_RANGE_MASK(chan);
val |= DAS6402_AO_RANGE(chan, range);
if (val != devpriv->ao_range) {
devpriv->ao_range = val;
outb(val, dev->iobase + DAS6402_TRIG_REG);
}
for (i = 0; i < insn->n; i++) {
val = data[i];
s->readback[chan] = val;
if (s->maxdata == 0x0fff) {
val <<= 4;
outw(val, dev->iobase + DAS6402_AO_DATA_REG(chan));
} else {
outb(val & 0xff,
dev->iobase + DAS6402_AO_LSB_REG(chan));
outb((val >> 8) & 0xff,
dev->iobase + DAS6402_AO_LSB_REG(chan));
}
}
return insn->n;
}
static int das6402_ao_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned int chan = CR_CHAN(insn->chanspec);
inw(dev->iobase + DAS6402_AO_LSB_REG(chan));
return comedi_readback_insn_read(dev, s, insn, data);
}
static int das6402_di_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
data[1] = inb(dev->iobase + DAS6402_DI_DO_REG);
return insn->n;
}
static int das6402_do_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
if (comedi_dio_update_state(s, data))
outb(s->state, dev->iobase + DAS6402_DI_DO_REG);
data[1] = s->state;
return insn->n;
}
static void das6402_reset(struct comedi_device *dev)
{
struct das6402_private *devpriv = dev->private;
outb(DAS6402_MODE_ENHANCED, dev->iobase + DAS6402_MODE_REG);
das6402_set_extended(dev, DAS6402_STATUS_W_10MHZ);
outb(DAS6402_CTRL_SOFT_TRIG, dev->iobase + DAS6402_CTRL_REG);
das6402_set_mode(dev, DAS6402_MODE_RANGE(0) |
DAS6402_MODE_POLLED |
DAS6402_MODE_SE |
DAS6402_MODE_UNI);
outw(DAS6402_AI_MUX_HI(0) | DAS6402_AI_MUX_LO(0),
dev->iobase + DAS6402_AI_MUX_REG);
devpriv->ao_range = DAS6402_AO_RANGE(0, 2) | DAS6402_AO_RANGE(1, 2);
outb(devpriv->ao_range, dev->iobase + DAS6402_TRIG_REG);
outw(0, dev->iobase + DAS6402_AO_DATA_REG(0));
outw(0, dev->iobase + DAS6402_AO_DATA_REG(0));
inw(dev->iobase + DAS6402_AO_LSB_REG(0));
das6402_enable_counter(dev, false);
outb(0, dev->iobase + DAS6402_DI_DO_REG);
das6402_clear_all_interrupts(dev);
}
static int das6402_attach(struct comedi_device *dev,
struct comedi_devconfig *it)
{
const struct das6402_boardinfo *board = dev->board_ptr;
struct das6402_private *devpriv;
struct comedi_subdevice *s;
int ret;
devpriv = comedi_alloc_devpriv(dev, sizeof(*devpriv));
if (!devpriv)
return -ENOMEM;
ret = comedi_request_region(dev, it->options[0], 0x10);
if (ret)
return ret;
das6402_reset(dev);
if ((1 << it->options[1]) & 0x8cec) {
ret = request_irq(it->options[1], das6402_interrupt, 0,
dev->board_name, dev);
if (ret == 0) {
dev->irq = it->options[1];
switch (dev->irq) {
case 10:
devpriv->irq = 4;
break;
case 11:
devpriv->irq = 1;
break;
case 15:
devpriv->irq = 6;
break;
default:
devpriv->irq = dev->irq;
break;
}
}
}
ret = comedi_alloc_subdevices(dev, 4);
if (ret)
return ret;
s = &dev->subdevices[0];
s->type = COMEDI_SUBD_AI;
s->subdev_flags = SDF_READABLE | SDF_GROUND | SDF_DIFF;
s->n_chan = 64;
s->maxdata = board->maxdata;
s->range_table = &das6402_ai_ranges;
s->insn_read = das6402_ai_insn_read;
if (dev->irq) {
dev->read_subdev = s;
s->subdev_flags |= SDF_CMD_READ;
s->len_chanlist = s->n_chan;
s->do_cmdtest = das6402_ai_cmdtest;
s->do_cmd = das6402_ai_cmd;
s->cancel = das6402_ai_cancel;
}
s = &dev->subdevices[1];
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITEABLE;
s->n_chan = 2;
s->maxdata = board->maxdata;
s->range_table = &das6402_ao_ranges;
s->insn_write = das6402_ao_insn_write;
s->insn_read = das6402_ao_insn_read;
ret = comedi_alloc_subdev_readback(s);
if (ret)
return ret;
s = &dev->subdevices[2];
s->type = COMEDI_SUBD_DI;
s->subdev_flags = SDF_READABLE;
s->n_chan = 8;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = das6402_di_insn_bits;
s = &dev->subdevices[3];
s->type = COMEDI_SUBD_DO;
s->subdev_flags = SDF_WRITEABLE;
s->n_chan = 8;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = das6402_do_insn_bits;
return 0;
}
