static void dt3k_send_cmd(struct comedi_device *dev, unsigned int cmd)
{
int i;
unsigned int status = 0;
writew(cmd, dev->mmio + DPR_CMD_MBX);
for (i = 0; i < DPR_CMD_TIMEOUT; i++) {
status = readw(dev->mmio + DPR_CMD_MBX);
status &= DPR_CMD_COMPLETION_MASK;
if (status != DPR_CMD_NOTPROCESSED)
break;
udelay(1);
}
if (status != DPR_CMD_NOERROR)
dev_dbg(dev->class_dev, "%s: timeout/error status=0x%04x\n",
__func__, status);
}
static unsigned int dt3k_readsingle(struct comedi_device *dev,
unsigned int subsys, unsigned int chan,
unsigned int gain)
{
writew(subsys, dev->mmio + DPR_SUBSYS);
writew(chan, dev->mmio + DPR_PARAMS(0));
writew(gain, dev->mmio + DPR_PARAMS(1));
dt3k_send_cmd(dev, DPR_CMD_READSINGLE);
return readw(dev->mmio + DPR_PARAMS(2));
}
static void dt3k_writesingle(struct comedi_device *dev, unsigned int subsys,
unsigned int chan, unsigned int data)
{
writew(subsys, dev->mmio + DPR_SUBSYS);
writew(chan, dev->mmio + DPR_PARAMS(0));
writew(0, dev->mmio + DPR_PARAMS(1));
writew(data, dev->mmio + DPR_PARAMS(2));
dt3k_send_cmd(dev, DPR_CMD_WRITESINGLE);
}
static void dt3k_ai_empty_fifo(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct dt3k_private *devpriv = dev->private;
int front;
int rear;
int count;
int i;
unsigned short data;
front = readw(dev->mmio + DPR_AD_BUF_FRONT);
count = front - devpriv->ai_front;
if (count < 0)
count += DPR_AI_FIFO_DEPTH;
rear = devpriv->ai_rear;
for (i = 0; i < count; i++) {
data = readw(dev->mmio + DPR_ADC_BUFFER + rear);
comedi_buf_write_samples(s, &data, 1);
rear++;
if (rear >= DPR_AI_FIFO_DEPTH)
rear = 0;
}
devpriv->ai_rear = rear;
writew(rear, dev->mmio + DPR_AD_BUF_REAR);
}
static int dt3k_ai_cancel(struct comedi_device *dev,
struct comedi_subdevice *s)
{
writew(DPR_SUBSYS_AI, dev->mmio + DPR_SUBSYS);
dt3k_send_cmd(dev, DPR_CMD_STOP);
writew(0, dev->mmio + DPR_INT_MASK);
return 0;
}
static irqreturn_t dt3k_interrupt(int irq, void *d)
{
struct comedi_device *dev = d;
struct comedi_subdevice *s = dev->read_subdev;
unsigned int status;
if (!dev->attached)
return IRQ_NONE;
status = readw(dev->mmio + DPR_INTR_FLAG);
if (status & DPR_INTR_ADFULL)
dt3k_ai_empty_fifo(dev, s);
if (status & (DPR_INTR_ADSWERR | DPR_INTR_ADHWERR))
s->async->events |= COMEDI_CB_ERROR;
debug_n_ints++;
if (debug_n_ints >= 10)
s->async->events |= COMEDI_CB_EOA;
comedi_handle_events(dev, s);
return IRQ_HANDLED;
}
static int dt3k_ns_to_timer(unsigned int timer_base, unsigned int *nanosec,
unsigned int flags)
{
int divider, base, prescale;
for (prescale = 0; prescale < 16; prescale++) {
base = timer_base * (prescale + 1);
switch (flags & CMDF_ROUND_MASK) {
case CMDF_ROUND_NEAREST:
default:
divider = DIV_ROUND_CLOSEST(*nanosec, base);
break;
case CMDF_ROUND_DOWN:
divider = (*nanosec) / base;
break;
case CMDF_ROUND_UP:
divider = (*nanosec) / base;
break;
}
if (divider < 65536) {
*nanosec = divider * base;
return (prescale << 16) | (divider);
}
}
prescale = 15;
base = timer_base * (1 << prescale);
divider = 65535;
*nanosec = divider * base;
return (prescale << 16) | (divider);
}
static int dt3k_ai_cmdtest(struct comedi_device *dev,
struct comedi_subdevice *s, struct comedi_cmd *cmd)
{
const struct dt3k_boardtype *board = dev->board_ptr;
int err = 0;
unsigned int arg;
err |= comedi_check_trigger_src(&cmd->start_src, TRIG_NOW);
err |= comedi_check_trigger_src(&cmd->scan_begin_src, TRIG_TIMER);
err |= comedi_check_trigger_src(&cmd->convert_src, TRIG_TIMER);
err |= comedi_check_trigger_src(&cmd->scan_end_src, TRIG_COUNT);
err |= comedi_check_trigger_src(&cmd->stop_src, TRIG_COUNT);
if (err)
return 1;
err |= comedi_check_trigger_arg_is(&cmd->start_arg, 0);
if (cmd->scan_begin_src == TRIG_TIMER) {
err |= comedi_check_trigger_arg_min(&cmd->scan_begin_arg,
board->ai_speed);
err |= comedi_check_trigger_arg_max(&cmd->scan_begin_arg,
100 * 16 * 65535);
}
if (cmd->convert_src == TRIG_TIMER) {
err |= comedi_check_trigger_arg_min(&cmd->convert_arg,
board->ai_speed);
err |= comedi_check_trigger_arg_max(&cmd->convert_arg,
50 * 16 * 65535);
}
err |= comedi_check_trigger_arg_is(&cmd->scan_end_arg,
cmd->chanlist_len);
if (cmd->stop_src == TRIG_COUNT)
err |= comedi_check_trigger_arg_max(&cmd->stop_arg, 0x00ffffff);
else
err |= comedi_check_trigger_arg_is(&cmd->stop_arg, 0);
if (err)
return 3;
if (cmd->scan_begin_src == TRIG_TIMER) {
arg = cmd->scan_begin_arg;
dt3k_ns_to_timer(100, &arg, cmd->flags);
err |= comedi_check_trigger_arg_is(&cmd->scan_begin_arg, arg);
}
if (cmd->convert_src == TRIG_TIMER) {
arg = cmd->convert_arg;
dt3k_ns_to_timer(50, &arg, cmd->flags);
err |= comedi_check_trigger_arg_is(&cmd->convert_arg, arg);
if (cmd->scan_begin_src == TRIG_TIMER) {
arg = cmd->convert_arg * cmd->scan_end_arg;
err |= comedi_check_trigger_arg_min(&cmd->
scan_begin_arg,
arg);
}
}
if (err)
return 4;
return 0;
}
static int dt3k_ai_cmd(struct comedi_device *dev, struct comedi_subdevice *s)
{
struct comedi_cmd *cmd = &s->async->cmd;
int i;
unsigned int chan, range, aref;
unsigned int divider;
unsigned int tscandiv;
for (i = 0; i < cmd->chanlist_len; i++) {
chan = CR_CHAN(cmd->chanlist[i]);
range = CR_RANGE(cmd->chanlist[i]);
writew((range << 6) | chan, dev->mmio + DPR_ADC_BUFFER + i);
}
aref = CR_AREF(cmd->chanlist[0]);
writew(cmd->scan_end_arg, dev->mmio + DPR_PARAMS(0));
if (cmd->convert_src == TRIG_TIMER) {
divider = dt3k_ns_to_timer(50, &cmd->convert_arg, cmd->flags);
writew((divider >> 16), dev->mmio + DPR_PARAMS(1));
writew((divider & 0xffff), dev->mmio + DPR_PARAMS(2));
}
if (cmd->scan_begin_src == TRIG_TIMER) {
tscandiv = dt3k_ns_to_timer(100, &cmd->scan_begin_arg,
cmd->flags);
writew((tscandiv >> 16), dev->mmio + DPR_PARAMS(3));
writew((tscandiv & 0xffff), dev->mmio + DPR_PARAMS(4));
}
writew(DPR_PARAM5_AD_TRIG_INT_RETRIG, dev->mmio + DPR_PARAMS(5));
writew((aref == AREF_DIFF) ? DPR_PARAM6_AD_DIFF : 0,
dev->mmio + DPR_PARAMS(6));
writew(DPR_AI_FIFO_DEPTH / 2, dev->mmio + DPR_PARAMS(7));
writew(DPR_SUBSYS_AI, dev->mmio + DPR_SUBSYS);
dt3k_send_cmd(dev, DPR_CMD_CONFIG);
writew(DPR_INTR_ADFULL | DPR_INTR_ADSWERR | DPR_INTR_ADHWERR,
dev->mmio + DPR_INT_MASK);
debug_n_ints = 0;
writew(DPR_SUBSYS_AI, dev->mmio + DPR_SUBSYS);
dt3k_send_cmd(dev, DPR_CMD_START);
return 0;
}
static int dt3k_ai_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
int i;
unsigned int chan, gain, aref;
chan = CR_CHAN(insn->chanspec);
gain = CR_RANGE(insn->chanspec);
aref = CR_AREF(insn->chanspec);
for (i = 0; i < insn->n; i++)
data[i] = dt3k_readsingle(dev, DPR_SUBSYS_AI, chan, gain);
return i;
}
static int dt3k_ao_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned int val = s->readback[chan];
int i;
for (i = 0; i < insn->n; i++) {
val = data[i];
dt3k_writesingle(dev, DPR_SUBSYS_AO, chan, val);
}
s->readback[chan] = val;
return insn->n;
}
static void dt3k_dio_config(struct comedi_device *dev, int bits)
{
writew(DPR_SUBSYS_DOUT, dev->mmio + DPR_SUBSYS);
writew(bits, dev->mmio + DPR_PARAMS(0));
dt3k_send_cmd(dev, DPR_CMD_CONFIG);
}
static int dt3k_dio_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned int mask;
int ret;
if (chan < 4)
mask = 0x0f;
else
mask = 0xf0;
ret = comedi_dio_insn_config(dev, s, insn, data, mask);
if (ret)
return ret;
dt3k_dio_config(dev, (s->io_bits & 0x01) | ((s->io_bits & 0x10) >> 3));
return insn->n;
}
static int dt3k_dio_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
if (comedi_dio_update_state(s, data))
dt3k_writesingle(dev, DPR_SUBSYS_DOUT, 0, s->state);
data[1] = dt3k_readsingle(dev, DPR_SUBSYS_DIN, 0, 0);
return insn->n;
}
static int dt3k_mem_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned int addr = CR_CHAN(insn->chanspec);
int i;
for (i = 0; i < insn->n; i++) {
writew(DPR_SUBSYS_MEM, dev->mmio + DPR_SUBSYS);
writew(addr, dev->mmio + DPR_PARAMS(0));
writew(1, dev->mmio + DPR_PARAMS(1));
dt3k_send_cmd(dev, DPR_CMD_READCODE);
data[i] = readw(dev->mmio + DPR_PARAMS(2));
}
return i;
}
static int dt3000_auto_attach(struct comedi_device *dev,
unsigned long context)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
const struct dt3k_boardtype *board = NULL;
struct dt3k_private *devpriv;
struct comedi_subdevice *s;
int ret = 0;
if (context < ARRAY_SIZE(dt3k_boardtypes))
board = &dt3k_boardtypes[context];
if (!board)
return -ENODEV;
dev->board_ptr = board;
dev->board_name = board->name;
devpriv = comedi_alloc_devpriv(dev, sizeof(*devpriv));
if (!devpriv)
return -ENOMEM;
ret = comedi_pci_enable(dev);
if (ret < 0)
return ret;
dev->mmio = pci_ioremap_bar(pcidev, 0);
if (!dev->mmio)
return -ENOMEM;
if (pcidev->irq) {
ret = request_irq(pcidev->irq, dt3k_interrupt, IRQF_SHARED,
dev->board_name, dev);
if (ret == 0)
dev->irq = pcidev->irq;
}
ret = comedi_alloc_subdevices(dev, 4);
if (ret)
return ret;
s = &dev->subdevices[0];
s->type = COMEDI_SUBD_AI;
s->subdev_flags = SDF_READABLE | SDF_GROUND | SDF_DIFF;
s->n_chan = board->adchan;
s->maxdata = board->ai_is_16bit ? 0xffff : 0x0fff;
s->range_table = &range_dt3000_ai;
s->insn_read = dt3k_ai_insn_read;
if (dev->irq) {
dev->read_subdev = s;
s->subdev_flags |= SDF_CMD_READ;
s->len_chanlist = 512;
s->do_cmd = dt3k_ai_cmd;
s->do_cmdtest = dt3k_ai_cmdtest;
s->cancel = dt3k_ai_cancel;
}
s = &dev->subdevices[1];
if (board->has_ao) {
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = 2;
s->maxdata = 0x0fff;
s->range_table = &range_bipolar10;
s->insn_write = dt3k_ao_insn_write;
ret = comedi_alloc_subdev_readback(s);
if (ret)
return ret;
} else {
s->type = COMEDI_SUBD_UNUSED;
}
s = &dev->subdevices[2];
s->type = COMEDI_SUBD_DIO;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE;
s->n_chan = 8;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_config = dt3k_dio_insn_config;
s->insn_bits = dt3k_dio_insn_bits;
s = &dev->subdevices[3];
s->type = COMEDI_SUBD_MEMORY;
s->subdev_flags = SDF_READABLE;
s->n_chan = 0x1000;
s->maxdata = 0xff;
s->range_table = &range_unknown;
s->insn_read = dt3k_mem_insn_read;
return 0;
}
static int dt3000_pci_probe(struct pci_dev *dev,
const struct pci_device_id *id)
{
return comedi_pci_auto_config(dev, &dt3000_driver, id->driver_data);
}
