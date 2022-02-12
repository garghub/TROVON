static void das800_ind_write(struct comedi_device *dev,
unsigned val, unsigned reg)
{
outb(reg, dev->iobase + DAS800_GAIN);
outb(val, dev->iobase + 2);
}
static unsigned das800_ind_read(struct comedi_device *dev, unsigned reg)
{
outb(reg, dev->iobase + DAS800_GAIN);
return inb(dev->iobase + 7);
}
static void das800_enable(struct comedi_device *dev)
{
const struct das800_board *thisboard = dev->board_ptr;
struct das800_private *devpriv = dev->private;
unsigned long irq_flags;
spin_lock_irqsave(&dev->spinlock, irq_flags);
if (thisboard->resolution == 16)
outb(CIO_ENHF, dev->iobase + DAS800_GAIN);
das800_ind_write(dev, CONV_HCEN, CONV_CONTROL);
das800_ind_write(dev, CONTROL1_INTE | devpriv->do_bits, CONTROL1);
spin_unlock_irqrestore(&dev->spinlock, irq_flags);
}
static void das800_disable(struct comedi_device *dev)
{
unsigned long irq_flags;
spin_lock_irqsave(&dev->spinlock, irq_flags);
das800_ind_write(dev, 0x0, CONV_CONTROL);
spin_unlock_irqrestore(&dev->spinlock, irq_flags);
}
static void das800_set_frequency(struct comedi_device *dev)
{
struct das800_private *devpriv = dev->private;
unsigned long timer_base = dev->iobase + DAS800_8254;
i8254_set_mode(timer_base, 0, 1, I8254_MODE2 | I8254_BINARY);
i8254_set_mode(timer_base, 0, 2, I8254_MODE2 | I8254_BINARY);
i8254_write(timer_base, 0, 1, devpriv->divisor1);
i8254_write(timer_base, 0, 2, devpriv->divisor2);
}
static int das800_cancel(struct comedi_device *dev, struct comedi_subdevice *s)
{
das800_disable(dev);
return 0;
}
static int das800_ai_check_chanlist(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_cmd *cmd)
{
unsigned int chan0 = CR_CHAN(cmd->chanlist[0]);
unsigned int range0 = CR_RANGE(cmd->chanlist[0]);
int i;
for (i = 1; i < cmd->chanlist_len; i++) {
unsigned int chan = CR_CHAN(cmd->chanlist[i]);
unsigned int range = CR_RANGE(cmd->chanlist[i]);
if (chan != (chan0 + i) % s->n_chan) {
dev_dbg(dev->class_dev,
"chanlist must be consecutive, counting upwards\n");
return -EINVAL;
}
if (range != range0) {
dev_dbg(dev->class_dev,
"chanlist must all have the same gain\n");
return -EINVAL;
}
}
return 0;
}
static int das800_ai_do_cmdtest(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_cmd *cmd)
{
const struct das800_board *thisboard = dev->board_ptr;
struct das800_private *devpriv = dev->private;
int err = 0;
unsigned int arg;
err |= cfc_check_trigger_src(&cmd->start_src, TRIG_NOW | TRIG_EXT);
err |= cfc_check_trigger_src(&cmd->scan_begin_src, TRIG_FOLLOW);
err |= cfc_check_trigger_src(&cmd->convert_src, TRIG_TIMER | TRIG_EXT);
err |= cfc_check_trigger_src(&cmd->scan_end_src, TRIG_COUNT);
err |= cfc_check_trigger_src(&cmd->stop_src, TRIG_COUNT | TRIG_NONE);
if (err)
return 1;
err |= cfc_check_trigger_is_unique(cmd->start_src);
err |= cfc_check_trigger_is_unique(cmd->convert_src);
err |= cfc_check_trigger_is_unique(cmd->stop_src);
if (err)
return 2;
err |= cfc_check_trigger_arg_is(&cmd->start_arg, 0);
if (cmd->convert_src == TRIG_TIMER)
err |= cfc_check_trigger_arg_min(&cmd->convert_arg,
thisboard->ai_speed);
err |= cfc_check_trigger_arg_min(&cmd->chanlist_len, 1);
err |= cfc_check_trigger_arg_is(&cmd->scan_end_arg, cmd->chanlist_len);
if (cmd->stop_src == TRIG_COUNT)
err |= cfc_check_trigger_arg_min(&cmd->stop_arg, 1);
else
err |= cfc_check_trigger_arg_is(&cmd->stop_arg, 0);
if (err)
return 3;
if (cmd->convert_src == TRIG_TIMER) {
arg = cmd->convert_arg;
i8253_cascade_ns_to_timer(I8254_OSC_BASE_1MHZ,
&devpriv->divisor1,
&devpriv->divisor2,
&arg, cmd->flags);
err |= cfc_check_trigger_arg_is(&cmd->convert_arg, arg);
}
if (err)
return 4;
if (cmd->chanlist && cmd->chanlist_len > 0)
err |= das800_ai_check_chanlist(dev, s, cmd);
if (err)
return 5;
return 0;
}
static int das800_ai_do_cmd(struct comedi_device *dev,
struct comedi_subdevice *s)
{
const struct das800_board *thisboard = dev->board_ptr;
struct comedi_async *async = s->async;
struct comedi_cmd *cmd = &async->cmd;
unsigned int gain = CR_RANGE(cmd->chanlist[0]);
unsigned int start_chan = CR_CHAN(cmd->chanlist[0]);
unsigned int end_chan = (start_chan + cmd->chanlist_len - 1) % 8;
unsigned int scan_chans = (end_chan << 3) | start_chan;
int conv_bits;
unsigned long irq_flags;
das800_disable(dev);
spin_lock_irqsave(&dev->spinlock, irq_flags);
das800_ind_write(dev, scan_chans, SCAN_LIMITS);
spin_unlock_irqrestore(&dev->spinlock, irq_flags);
if (thisboard->resolution == 12 && gain > 0)
gain += 0x7;
gain &= 0xf;
outb(gain, dev->iobase + DAS800_GAIN);
conv_bits = 0;
conv_bits |= EACS | IEOC;
if (cmd->start_src == TRIG_EXT)
conv_bits |= DTEN;
if (cmd->convert_src == TRIG_TIMER) {
conv_bits |= CASC | ITE;
das800_set_frequency(dev);
}
spin_lock_irqsave(&dev->spinlock, irq_flags);
das800_ind_write(dev, conv_bits, CONV_CONTROL);
spin_unlock_irqrestore(&dev->spinlock, irq_flags);
das800_enable(dev);
return 0;
}
static unsigned int das800_ai_get_sample(struct comedi_device *dev)
{
unsigned int lsb = inb(dev->iobase + DAS800_LSB);
unsigned int msb = inb(dev->iobase + DAS800_MSB);
return (msb << 8) | lsb;
}
static irqreturn_t das800_interrupt(int irq, void *d)
{
struct comedi_device *dev = d;
struct das800_private *devpriv = dev->private;
struct comedi_subdevice *s = dev->read_subdev;
struct comedi_async *async;
struct comedi_cmd *cmd;
unsigned long irq_flags;
unsigned int status;
unsigned int val;
bool fifo_empty;
bool fifo_overflow;
int i;
status = inb(dev->iobase + DAS800_STATUS);
if (!(status & IRQ))
return IRQ_NONE;
if (!dev->attached)
return IRQ_HANDLED;
async = s->async;
cmd = &async->cmd;
spin_lock_irqsave(&dev->spinlock, irq_flags);
status = das800_ind_read(dev, CONTROL1) & STATUS2_HCEN;
if (status == 0) {
spin_unlock_irqrestore(&dev->spinlock, irq_flags);
return IRQ_HANDLED;
}
for (i = 0; i < DAS802_16_HALF_FIFO_SZ; i++) {
val = das800_ai_get_sample(dev);
if (s->maxdata == 0x0fff) {
fifo_empty = !!(val & FIFO_EMPTY);
fifo_overflow = !!(val & FIFO_OVF);
} else {
fifo_empty = false;
fifo_overflow = !!(inb(dev->iobase + DAS800_GAIN) &
CIO_FFOV);
}
if (fifo_empty || fifo_overflow)
break;
if (s->maxdata == 0x0fff)
val >>= 4;
val &= s->maxdata;
comedi_buf_write_samples(s, &val, 1);
if (cmd->stop_src == TRIG_COUNT &&
async->scans_done >= cmd->stop_arg) {
async->events |= COMEDI_CB_EOA;
break;
}
}
if (fifo_overflow) {
spin_unlock_irqrestore(&dev->spinlock, irq_flags);
async->events |= COMEDI_CB_ERROR | COMEDI_CB_EOA;
comedi_handle_events(dev, s);
return IRQ_HANDLED;
}
if (!(async->events & COMEDI_CB_CANCEL_MASK)) {
das800_ind_write(dev, CONTROL1_INTE | devpriv->do_bits,
CONTROL1);
spin_unlock_irqrestore(&dev->spinlock, irq_flags);
} else {
spin_unlock_irqrestore(&dev->spinlock, irq_flags);
das800_disable(dev);
}
comedi_handle_events(dev, s);
return IRQ_HANDLED;
}
static int das800_ai_eoc(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned long context)
{
unsigned int status;
status = inb(dev->iobase + DAS800_STATUS);
if ((status & BUSY) == 0)
return 0;
return -EBUSY;
}
static int das800_ai_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct das800_private *devpriv = dev->private;
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned int range = CR_RANGE(insn->chanspec);
unsigned long irq_flags;
unsigned int val;
int ret;
int i;
das800_disable(dev);
spin_lock_irqsave(&dev->spinlock, irq_flags);
das800_ind_write(dev, chan | devpriv->do_bits, CONTROL1);
spin_unlock_irqrestore(&dev->spinlock, irq_flags);
if (s->maxdata == 0x0fff && range)
range += 0x7;
range &= 0xf;
outb(range, dev->iobase + DAS800_GAIN);
udelay(5);
for (i = 0; i < insn->n; i++) {
outb_p(0, dev->iobase + DAS800_MSB);
ret = comedi_timeout(dev, s, insn, das800_ai_eoc, 0);
if (ret)
return ret;
val = das800_ai_get_sample(dev);
if (s->maxdata == 0x0fff)
val >>= 4;
data[i] = val & s->maxdata;
}
return insn->n;
}
static int das800_di_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
data[1] = (inb(dev->iobase + DAS800_STATUS) >> 4) & 0x7;
return insn->n;
}
static int das800_do_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct das800_private *devpriv = dev->private;
unsigned long irq_flags;
if (comedi_dio_update_state(s, data)) {
devpriv->do_bits = s->state << 4;
spin_lock_irqsave(&dev->spinlock, irq_flags);
das800_ind_write(dev, CONTROL1_INTE | devpriv->do_bits,
CONTROL1);
spin_unlock_irqrestore(&dev->spinlock, irq_flags);
}
data[1] = s->state;
return insn->n;
}
static int das800_probe(struct comedi_device *dev)
{
const struct das800_board *thisboard = dev->board_ptr;
int board = thisboard ? thisboard - das800_boards : -EINVAL;
int id_bits;
unsigned long irq_flags;
spin_lock_irqsave(&dev->spinlock, irq_flags);
id_bits = das800_ind_read(dev, ID) & 0x3;
spin_unlock_irqrestore(&dev->spinlock, irq_flags);
switch (id_bits) {
case 0x0:
if (board == BOARD_DAS800 || board == BOARD_CIODAS800)
break;
dev_dbg(dev->class_dev, "Board model (probed): DAS-800\n");
board = BOARD_DAS800;
break;
case 0x2:
if (board == BOARD_DAS801 || board == BOARD_CIODAS801)
break;
dev_dbg(dev->class_dev, "Board model (probed): DAS-801\n");
board = BOARD_DAS801;
break;
case 0x3:
if (board == BOARD_DAS802 || board == BOARD_CIODAS802 ||
board == BOARD_CIODAS80216)
break;
dev_dbg(dev->class_dev, "Board model (probed): DAS-802\n");
board = BOARD_DAS802;
break;
default:
dev_dbg(dev->class_dev, "Board model: 0x%x (unknown)\n",
id_bits);
board = -EINVAL;
break;
}
return board;
}
static int das800_attach(struct comedi_device *dev, struct comedi_devconfig *it)
{
const struct das800_board *thisboard;
struct das800_private *devpriv;
struct comedi_subdevice *s;
unsigned int irq = it->options[1];
unsigned long irq_flags;
int board;
int ret;
devpriv = comedi_alloc_devpriv(dev, sizeof(*devpriv));
if (!devpriv)
return -ENOMEM;
ret = comedi_request_region(dev, it->options[0], 0x8);
if (ret)
return ret;
board = das800_probe(dev);
if (board < 0) {
dev_dbg(dev->class_dev, "unable to determine board type\n");
return -ENODEV;
}
dev->board_ptr = das800_boards + board;
thisboard = dev->board_ptr;
dev->board_name = thisboard->name;
if (irq > 1 && irq <= 7) {
ret = request_irq(irq, das800_interrupt, 0, dev->board_name,
dev);
if (ret == 0)
dev->irq = irq;
}
ret = comedi_alloc_subdevices(dev, 3);
if (ret)
return ret;
s = &dev->subdevices[0];
dev->read_subdev = s;
s->type = COMEDI_SUBD_AI;
s->subdev_flags = SDF_READABLE | SDF_GROUND;
s->n_chan = 8;
s->maxdata = (1 << thisboard->resolution) - 1;
s->range_table = thisboard->ai_range;
s->insn_read = das800_ai_insn_read;
if (dev->irq) {
s->subdev_flags |= SDF_CMD_READ;
s->len_chanlist = 8;
s->do_cmdtest = das800_ai_do_cmdtest;
s->do_cmd = das800_ai_do_cmd;
s->cancel = das800_cancel;
}
s = &dev->subdevices[1];
s->type = COMEDI_SUBD_DI;
s->subdev_flags = SDF_READABLE;
s->n_chan = 3;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = das800_di_insn_bits;
s = &dev->subdevices[2];
s->type = COMEDI_SUBD_DO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = 4;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = das800_do_insn_bits;
das800_disable(dev);
spin_lock_irqsave(&dev->spinlock, irq_flags);
das800_ind_write(dev, CONTROL1_INTE | devpriv->do_bits, CONTROL1);
spin_unlock_irqrestore(&dev->spinlock, irq_flags);
return 0;
}
