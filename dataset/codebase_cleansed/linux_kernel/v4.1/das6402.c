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
static unsigned int das6402_ai_read_sample(struct comedi_device *dev,
struct comedi_subdevice *s)
{
unsigned int val;
val = inw(dev->iobase + DAS6402_AI_DATA_REG);
if (s->maxdata == 0x0fff)
val >>= 4;
return val;
}
static irqreturn_t das6402_interrupt(int irq, void *d)
{
struct comedi_device *dev = d;
struct comedi_subdevice *s = dev->read_subdev;
struct comedi_async *async = s->async;
struct comedi_cmd *cmd = &async->cmd;
unsigned int status;
status = inb(dev->iobase + DAS6402_STATUS_REG);
if ((status & DAS6402_STATUS_INT) == 0)
return IRQ_NONE;
if (status & DAS6402_STATUS_FFULL) {
async->events |= COMEDI_CB_OVERFLOW;
} else if (status & DAS6402_STATUS_FFNE) {
unsigned int val;
val = das6402_ai_read_sample(dev, s);
comedi_buf_write_samples(s, &val, 1);
if (cmd->stop_src == TRIG_COUNT &&
async->scans_done >= cmd->stop_arg)
async->events |= COMEDI_CB_EOA;
}
das6402_clear_all_interrupts(dev);
comedi_handle_events(dev, s);
return IRQ_HANDLED;
}
static void das6402_ai_set_mode(struct comedi_device *dev,
struct comedi_subdevice *s,
unsigned int chanspec,
unsigned int mode)
{
unsigned int range = CR_RANGE(chanspec);
unsigned int aref = CR_AREF(chanspec);
mode |= DAS6402_MODE_RANGE(range);
if (aref == AREF_GROUND)
mode |= DAS6402_MODE_SE;
if (comedi_range_is_unipolar(s, range))
mode |= DAS6402_MODE_UNI;
das6402_set_mode(dev, mode);
}
static int das6402_ai_cmd(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct das6402_private *devpriv = dev->private;
struct comedi_cmd *cmd = &s->async->cmd;
unsigned int chan_lo = CR_CHAN(cmd->chanlist[0]);
unsigned int chan_hi = CR_CHAN(cmd->chanlist[cmd->chanlist_len - 1]);
das6402_ai_set_mode(dev, s, cmd->chanlist[0], DAS6402_MODE_FIFONEPTY);
outw(DAS6402_AI_MUX_HI(chan_hi) | DAS6402_AI_MUX_LO(chan_lo),
dev->iobase + DAS6402_AI_MUX_REG);
comedi_8254_update_divisors(dev->pacer);
comedi_8254_pacer_enable(dev->pacer, 1, 2, true);
outb(DAS6402_CTRL_INTE |
DAS6402_CTRL_IRQ(devpriv->irq) |
DAS6402_CTRL_PACER_TRIG, dev->iobase + DAS6402_CTRL_REG);
return 0;
}
static int das6402_ai_check_chanlist(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_cmd *cmd)
{
unsigned int chan0 = CR_CHAN(cmd->chanlist[0]);
unsigned int range0 = CR_RANGE(cmd->chanlist[0]);
unsigned int aref0 = CR_AREF(cmd->chanlist[0]);
int i;
for (i = 1; i < cmd->chanlist_len; i++) {
unsigned int chan = CR_CHAN(cmd->chanlist[i]);
unsigned int range = CR_RANGE(cmd->chanlist[i]);
unsigned int aref = CR_AREF(cmd->chanlist[i]);
if (chan != chan0 + i) {
dev_dbg(dev->class_dev,
"chanlist must be consecutive\n");
return -EINVAL;
}
if (range != range0) {
dev_dbg(dev->class_dev,
"chanlist must have the same range\n");
return -EINVAL;
}
if (aref != aref0) {
dev_dbg(dev->class_dev,
"chanlist must have the same reference\n");
return -EINVAL;
}
if (aref0 == AREF_DIFF && chan > (s->n_chan / 2)) {
dev_dbg(dev->class_dev,
"chanlist differential channel to large\n");
return -EINVAL;
}
}
return 0;
}
static int das6402_ai_cmdtest(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_cmd *cmd)
{
int err = 0;
unsigned int arg;
err |= comedi_check_trigger_src(&cmd->start_src, TRIG_NOW);
err |= comedi_check_trigger_src(&cmd->scan_begin_src, TRIG_FOLLOW);
err |= comedi_check_trigger_src(&cmd->convert_src, TRIG_TIMER);
err |= comedi_check_trigger_src(&cmd->scan_end_src, TRIG_COUNT);
err |= comedi_check_trigger_src(&cmd->stop_src, TRIG_COUNT | TRIG_NONE);
if (err)
return 1;
err |= comedi_check_trigger_is_unique(cmd->stop_src);
if (err)
return 2;
err |= comedi_check_trigger_arg_is(&cmd->start_arg, 0);
err |= comedi_check_trigger_arg_is(&cmd->scan_begin_arg, 0);
err |= comedi_check_trigger_arg_min(&cmd->convert_arg, 10000);
err |= comedi_check_trigger_arg_min(&cmd->chanlist_len, 1);
err |= comedi_check_trigger_arg_is(&cmd->scan_end_arg,
cmd->chanlist_len);
if (cmd->stop_src == TRIG_COUNT)
err |= comedi_check_trigger_arg_min(&cmd->stop_arg, 1);
else
err |= comedi_check_trigger_arg_is(&cmd->stop_arg, 0);
if (err)
return 3;
arg = cmd->convert_arg;
comedi_8254_cascade_ns_to_timer(dev->pacer, &arg, cmd->flags);
err |= comedi_check_trigger_arg_is(&cmd->convert_arg, arg);
if (err)
return 4;
if (cmd->chanlist && cmd->chanlist_len > 0)
err |= das6402_ai_check_chanlist(dev, s, cmd);
if (err)
return 5;
return 0;
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
unsigned int aref = CR_AREF(insn->chanspec);
int ret;
int i;
if (aref == AREF_DIFF && chan > (s->n_chan / 2))
return -EINVAL;
outb(DAS6402_CTRL_SOFT_TRIG, dev->iobase + DAS6402_CTRL_REG);
das6402_ai_set_mode(dev, s, insn->chanspec, DAS6402_MODE_POLLED);
outw(DAS6402_AI_MUX_HI(chan) | DAS6402_AI_MUX_LO(chan),
dev->iobase + DAS6402_AI_MUX_REG);
for (i = 0; i < insn->n; i++) {
das6402_ai_clear_eoc(dev);
das6402_ai_soft_trig(dev);
ret = comedi_timeout(dev, s, insn, das6402_ai_eoc, 0);
if (ret)
break;
data[i] = das6402_ai_read_sample(dev, s);
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
dev->pacer = comedi_8254_init(dev->iobase + DAS6402_TIMER_BASE,
I8254_OSC_BASE_10MHZ, I8254_IO8, 0);
if (!dev->pacer)
return -ENOMEM;
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
s->subdev_flags = SDF_WRITABLE;
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
s->subdev_flags = SDF_WRITABLE;
s->n_chan = 8;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = das6402_do_insn_bits;
return 0;
}
