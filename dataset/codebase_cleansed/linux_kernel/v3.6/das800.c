static int das800_probe(struct comedi_device *dev)
{
int id_bits;
unsigned long irq_flags;
int board;
spin_lock_irqsave(&dev->spinlock, irq_flags);
outb(ID, dev->iobase + DAS800_GAIN);
id_bits = inb(dev->iobase + DAS800_ID) & 0x3;
spin_unlock_irqrestore(&dev->spinlock, irq_flags);
board = thisboard - das800_boards;
switch (id_bits) {
case 0x0:
if (board == das800) {
dev_dbg(dev->class_dev, "Board model: DAS-800\n");
return board;
}
if (board == ciodas800) {
dev_dbg(dev->class_dev, "Board model: CIO-DAS800\n");
return board;
}
dev_dbg(dev->class_dev, "Board model (probed): DAS-800\n");
return das800;
break;
case 0x2:
if (board == das801) {
dev_dbg(dev->class_dev, "Board model: DAS-801\n");
return board;
}
if (board == ciodas801) {
dev_dbg(dev->class_dev, "Board model: CIO-DAS801\n");
return board;
}
dev_dbg(dev->class_dev, "Board model (probed): DAS-801\n");
return das801;
break;
case 0x3:
if (board == das802) {
dev_dbg(dev->class_dev, "Board model: DAS-802\n");
return board;
}
if (board == ciodas802) {
dev_dbg(dev->class_dev, "Board model: CIO-DAS802\n");
return board;
}
if (board == ciodas80216) {
dev_dbg(dev->class_dev, "Board model: CIO-DAS802/16\n");
return board;
}
dev_dbg(dev->class_dev, "Board model (probed): DAS-802\n");
return das802;
break;
default:
dev_dbg(dev->class_dev,
"Board model: probe returned 0x%x (unknown)\n",
id_bits);
return board;
break;
}
return -1;
}
static int __init driver_das800_init_module(void)
{
return comedi_driver_register(&driver_das800);
}
static void __exit driver_das800_cleanup_module(void)
{
comedi_driver_unregister(&driver_das800);
}
static irqreturn_t das800_interrupt(int irq, void *d)
{
short i;
short dataPoint = 0;
struct comedi_device *dev = d;
struct comedi_subdevice *s = dev->read_subdev;
struct comedi_async *async;
int status;
unsigned long irq_flags;
static const int max_loops = 128;
int fifo_empty = 0;
int fifo_overflow = 0;
status = inb(dev->iobase + DAS800_STATUS);
if (!(status & IRQ))
return IRQ_NONE;
if (!(dev->attached))
return IRQ_HANDLED;
async = s->async;
spin_lock_irqsave(&dev->spinlock, irq_flags);
outb(CONTROL1, dev->iobase + DAS800_GAIN);
status = inb(dev->iobase + DAS800_STATUS2) & STATUS2_HCEN;
if (status == 0) {
spin_unlock_irqrestore(&dev->spinlock, irq_flags);
return IRQ_HANDLED;
}
for (i = 0; i < max_loops; i++) {
dataPoint = inb(dev->iobase + DAS800_LSB);
dataPoint += inb(dev->iobase + DAS800_MSB) << 8;
if (thisboard->resolution == 12) {
fifo_empty = dataPoint & FIFO_EMPTY;
fifo_overflow = dataPoint & FIFO_OVF;
if (fifo_overflow)
break;
} else {
fifo_empty = 0;
}
if (fifo_empty)
break;
if (thisboard->resolution == 12)
dataPoint = (dataPoint >> 4) & 0xfff;
if (devpriv->count > 0 || devpriv->forever == 1) {
cfc_write_to_buffer(s, dataPoint);
if (devpriv->count > 0)
devpriv->count--;
}
}
async->events |= COMEDI_CB_BLOCK;
if (thisboard->resolution == 12) {
fifo_overflow = dataPoint & FIFO_OVF;
} else {
fifo_overflow = inb(dev->iobase + DAS800_GAIN) & CIO_FFOV;
}
if (fifo_overflow) {
spin_unlock_irqrestore(&dev->spinlock, irq_flags);
comedi_error(dev, "DAS800 FIFO overflow");
das800_cancel(dev, dev->subdevices + 0);
async->events |= COMEDI_CB_ERROR | COMEDI_CB_EOA;
comedi_event(dev, s);
async->events = 0;
return IRQ_HANDLED;
}
if (devpriv->count > 0 || devpriv->forever == 1) {
outb(CONTROL1, dev->iobase + DAS800_GAIN);
outb(CONTROL1_INTE | devpriv->do_bits,
dev->iobase + DAS800_CONTROL1);
spin_unlock_irqrestore(&dev->spinlock, irq_flags);
} else {
spin_unlock_irqrestore(&dev->spinlock, irq_flags);
disable_das800(dev);
async->events |= COMEDI_CB_EOA;
}
comedi_event(dev, s);
async->events = 0;
return IRQ_HANDLED;
}
static int das800_attach(struct comedi_device *dev, struct comedi_devconfig *it)
{
struct comedi_subdevice *s;
unsigned long iobase = it->options[0];
unsigned int irq = it->options[1];
unsigned long irq_flags;
int board;
int ret;
dev_info(dev->class_dev, "das800: io 0x%lx\n", iobase);
if (irq)
dev_dbg(dev->class_dev, "irq %u\n", irq);
if (alloc_private(dev, sizeof(struct das800_private)) < 0)
return -ENOMEM;
if (iobase == 0) {
dev_err(dev->class_dev,
"io base address required for das800\n");
return -EINVAL;
}
if (!request_region(iobase, DAS800_SIZE, "das800")) {
dev_err(dev->class_dev, "I/O port conflict\n");
return -EIO;
}
dev->iobase = iobase;
board = das800_probe(dev);
if (board < 0) {
dev_dbg(dev->class_dev, "unable to determine board type\n");
return -ENODEV;
}
dev->board_ptr = das800_boards + board;
if (irq == 1 || irq > 7) {
dev_err(dev->class_dev, "irq out of range\n");
return -EINVAL;
}
if (irq) {
if (request_irq(irq, das800_interrupt, 0, "das800", dev)) {
dev_err(dev->class_dev, "unable to allocate irq %u\n",
irq);
return -EINVAL;
}
}
dev->irq = irq;
dev->board_name = thisboard->name;
ret = comedi_alloc_subdevices(dev, 3);
if (ret)
return ret;
s = dev->subdevices + 0;
dev->read_subdev = s;
s->type = COMEDI_SUBD_AI;
s->subdev_flags = SDF_READABLE | SDF_GROUND | SDF_CMD_READ;
s->n_chan = 8;
s->len_chanlist = 8;
s->maxdata = (1 << thisboard->resolution) - 1;
s->range_table = thisboard->ai_range;
s->do_cmd = das800_ai_do_cmd;
s->do_cmdtest = das800_ai_do_cmdtest;
s->insn_read = das800_ai_rinsn;
s->cancel = das800_cancel;
s = dev->subdevices + 1;
s->type = COMEDI_SUBD_DI;
s->subdev_flags = SDF_READABLE;
s->n_chan = 3;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = das800_di_rbits;
s = dev->subdevices + 2;
s->type = COMEDI_SUBD_DO;
s->subdev_flags = SDF_WRITABLE | SDF_READABLE;
s->n_chan = 4;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = das800_do_wbits;
disable_das800(dev);
spin_lock_irqsave(&dev->spinlock, irq_flags);
outb(CONTROL1, dev->iobase + DAS800_GAIN);
outb(CONTROL1_INTE | devpriv->do_bits, dev->iobase + DAS800_CONTROL1);
spin_unlock_irqrestore(&dev->spinlock, irq_flags);
return 0;
}
static void das800_detach(struct comedi_device *dev)
{
if (dev->iobase)
release_region(dev->iobase, DAS800_SIZE);
if (dev->irq)
free_irq(dev->irq, dev);
}
static int das800_cancel(struct comedi_device *dev, struct comedi_subdevice *s)
{
devpriv->forever = 0;
devpriv->count = 0;
disable_das800(dev);
return 0;
}
static void enable_das800(struct comedi_device *dev)
{
unsigned long irq_flags;
spin_lock_irqsave(&dev->spinlock, irq_flags);
if (thisboard->resolution == 16)
outb(CIO_ENHF, dev->iobase + DAS800_GAIN);
outb(CONV_CONTROL, dev->iobase + DAS800_GAIN);
outb(CONV_HCEN, dev->iobase + DAS800_CONV_CONTROL);
outb(CONTROL1, dev->iobase + DAS800_GAIN);
outb(CONTROL1_INTE | devpriv->do_bits, dev->iobase + DAS800_CONTROL1);
spin_unlock_irqrestore(&dev->spinlock, irq_flags);
}
static void disable_das800(struct comedi_device *dev)
{
unsigned long irq_flags;
spin_lock_irqsave(&dev->spinlock, irq_flags);
outb(CONV_CONTROL, dev->iobase + DAS800_GAIN);
outb(0x0, dev->iobase + DAS800_CONV_CONTROL);
spin_unlock_irqrestore(&dev->spinlock, irq_flags);
}
static int das800_ai_do_cmdtest(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_cmd *cmd)
{
int err = 0;
int tmp;
int gain, startChan;
int i;
tmp = cmd->start_src;
cmd->start_src &= TRIG_NOW | TRIG_EXT;
if (!cmd->start_src || tmp != cmd->start_src)
err++;
tmp = cmd->scan_begin_src;
cmd->scan_begin_src &= TRIG_FOLLOW;
if (!cmd->scan_begin_src || tmp != cmd->scan_begin_src)
err++;
tmp = cmd->convert_src;
cmd->convert_src &= TRIG_TIMER | TRIG_EXT;
if (!cmd->convert_src || tmp != cmd->convert_src)
err++;
tmp = cmd->scan_end_src;
cmd->scan_end_src &= TRIG_COUNT;
if (!cmd->scan_end_src || tmp != cmd->scan_end_src)
err++;
tmp = cmd->stop_src;
cmd->stop_src &= TRIG_COUNT | TRIG_NONE;
if (!cmd->stop_src || tmp != cmd->stop_src)
err++;
if (err)
return 1;
if (cmd->start_src != TRIG_NOW && cmd->start_src != TRIG_EXT)
err++;
if (cmd->convert_src != TRIG_TIMER && cmd->convert_src != TRIG_EXT)
err++;
if (cmd->stop_src != TRIG_COUNT && cmd->stop_src != TRIG_NONE)
err++;
if (err)
return 2;
if (cmd->start_arg != 0) {
cmd->start_arg = 0;
err++;
}
if (cmd->convert_src == TRIG_TIMER) {
if (cmd->convert_arg < thisboard->ai_speed) {
cmd->convert_arg = thisboard->ai_speed;
err++;
}
}
if (!cmd->chanlist_len) {
cmd->chanlist_len = 1;
err++;
}
if (cmd->scan_end_arg != cmd->chanlist_len) {
cmd->scan_end_arg = cmd->chanlist_len;
err++;
}
if (cmd->stop_src == TRIG_COUNT) {
if (!cmd->stop_arg) {
cmd->stop_arg = 1;
err++;
}
} else {
if (cmd->stop_arg != 0) {
cmd->stop_arg = 0;
err++;
}
}
if (err)
return 3;
if (cmd->convert_src == TRIG_TIMER) {
tmp = cmd->convert_arg;
i8253_cascade_ns_to_timer_2div(TIMER_BASE, &(devpriv->divisor1),
&(devpriv->divisor2),
&(cmd->convert_arg),
cmd->flags & TRIG_ROUND_MASK);
if (tmp != cmd->convert_arg)
err++;
}
if (err)
return 4;
if (cmd->chanlist) {
gain = CR_RANGE(cmd->chanlist[0]);
startChan = CR_CHAN(cmd->chanlist[0]);
for (i = 1; i < cmd->chanlist_len; i++) {
if (CR_CHAN(cmd->chanlist[i]) !=
(startChan + i) % N_CHAN_AI) {
comedi_error(dev,
"entries in chanlist must be consecutive channels, counting upwards\n");
err++;
}
if (CR_RANGE(cmd->chanlist[i]) != gain) {
comedi_error(dev,
"entries in chanlist must all have the same gain\n");
err++;
}
}
}
if (err)
return 5;
return 0;
}
static int das800_ai_do_cmd(struct comedi_device *dev,
struct comedi_subdevice *s)
{
int startChan, endChan, scan, gain;
int conv_bits;
unsigned long irq_flags;
struct comedi_async *async = s->async;
if (!dev->irq) {
comedi_error(dev,
"no irq assigned for das-800, cannot do hardware conversions");
return -1;
}
disable_das800(dev);
startChan = CR_CHAN(async->cmd.chanlist[0]);
endChan = (startChan + async->cmd.chanlist_len - 1) % 8;
scan = (endChan << 3) | startChan;
spin_lock_irqsave(&dev->spinlock, irq_flags);
outb(SCAN_LIMITS, dev->iobase + DAS800_GAIN);
outb(scan, dev->iobase + DAS800_SCAN_LIMITS);
spin_unlock_irqrestore(&dev->spinlock, irq_flags);
gain = CR_RANGE(async->cmd.chanlist[0]);
if (thisboard->resolution == 12 && gain > 0)
gain += 0x7;
gain &= 0xf;
outb(gain, dev->iobase + DAS800_GAIN);
switch (async->cmd.stop_src) {
case TRIG_COUNT:
devpriv->count = async->cmd.stop_arg * async->cmd.chanlist_len;
devpriv->forever = 0;
break;
case TRIG_NONE:
devpriv->forever = 1;
devpriv->count = 0;
break;
default:
break;
}
conv_bits = 0;
conv_bits |= EACS | IEOC;
if (async->cmd.start_src == TRIG_EXT)
conv_bits |= DTEN;
switch (async->cmd.convert_src) {
case TRIG_TIMER:
conv_bits |= CASC | ITE;
i8253_cascade_ns_to_timer_2div(TIMER_BASE, &(devpriv->divisor1),
&(devpriv->divisor2),
&(async->cmd.convert_arg),
async->cmd.
flags & TRIG_ROUND_MASK);
if (das800_set_frequency(dev) < 0) {
comedi_error(dev, "Error setting up counters");
return -1;
}
break;
case TRIG_EXT:
break;
default:
break;
}
spin_lock_irqsave(&dev->spinlock, irq_flags);
outb(CONV_CONTROL, dev->iobase + DAS800_GAIN);
outb(conv_bits, dev->iobase + DAS800_CONV_CONTROL);
spin_unlock_irqrestore(&dev->spinlock, irq_flags);
async->events = 0;
enable_das800(dev);
return 0;
}
static int das800_ai_rinsn(struct comedi_device *dev,
struct comedi_subdevice *s, struct comedi_insn *insn,
unsigned int *data)
{
int i, n;
int chan;
int range;
int lsb, msb;
int timeout = 1000;
unsigned long irq_flags;
disable_das800(dev);
chan = CR_CHAN(insn->chanspec);
spin_lock_irqsave(&dev->spinlock, irq_flags);
outb(CONTROL1, dev->iobase + DAS800_GAIN);
outb(chan | devpriv->do_bits, dev->iobase + DAS800_CONTROL1);
spin_unlock_irqrestore(&dev->spinlock, irq_flags);
range = CR_RANGE(insn->chanspec);
if (thisboard->resolution == 12 && range)
range += 0x7;
range &= 0xf;
outb(range, dev->iobase + DAS800_GAIN);
udelay(5);
for (n = 0; n < insn->n; n++) {
outb_p(0, dev->iobase + DAS800_MSB);
for (i = 0; i < timeout; i++) {
if (!(inb(dev->iobase + DAS800_STATUS) & BUSY))
break;
}
if (i == timeout) {
comedi_error(dev, "timeout");
return -ETIME;
}
lsb = inb(dev->iobase + DAS800_LSB);
msb = inb(dev->iobase + DAS800_MSB);
if (thisboard->resolution == 12) {
data[n] = (lsb >> 4) & 0xff;
data[n] |= (msb << 4);
} else {
data[n] = (msb << 8) | lsb;
}
}
return n;
}
static int das800_di_rbits(struct comedi_device *dev,
struct comedi_subdevice *s, struct comedi_insn *insn,
unsigned int *data)
{
unsigned int bits;
bits = inb(dev->iobase + DAS800_STATUS) >> 4;
bits &= 0x7;
data[1] = bits;
data[0] = 0;
return insn->n;
}
static int das800_do_wbits(struct comedi_device *dev,
struct comedi_subdevice *s, struct comedi_insn *insn,
unsigned int *data)
{
int wbits;
unsigned long irq_flags;
data[0] &= 0xf;
wbits = devpriv->do_bits >> 4;
wbits &= ~data[0];
wbits |= data[0] & data[1];
devpriv->do_bits = wbits << 4;
spin_lock_irqsave(&dev->spinlock, irq_flags);
outb(CONTROL1, dev->iobase + DAS800_GAIN);
outb(devpriv->do_bits | CONTROL1_INTE, dev->iobase + DAS800_CONTROL1);
spin_unlock_irqrestore(&dev->spinlock, irq_flags);
data[1] = wbits;
return insn->n;
}
static int das800_set_frequency(struct comedi_device *dev)
{
int err = 0;
if (i8254_load(dev->iobase + DAS800_8254, 0, 1, devpriv->divisor1, 2))
err++;
if (i8254_load(dev->iobase + DAS800_8254, 0, 2, devpriv->divisor2, 2))
err++;
if (err)
return -1;
return 0;
}
