static void dt3k_send_cmd(struct comedi_device *dev, unsigned int cmd)
{
struct dt3k_private *devpriv = dev->private;
int i;
unsigned int status = 0;
writew(cmd, devpriv->io_addr + DPR_Command_Mbx);
for (i = 0; i < TIMEOUT; i++) {
status = readw(devpriv->io_addr + DPR_Command_Mbx);
if ((status & DT3000_COMPLETION_MASK) != DT3000_NOTPROCESSED)
break;
udelay(1);
}
if ((status & DT3000_COMPLETION_MASK) != DT3000_NOERROR)
dev_dbg(dev->class_dev, "%s: timeout/error status=0x%04x\n",
__func__, status);
}
static unsigned int dt3k_readsingle(struct comedi_device *dev,
unsigned int subsys, unsigned int chan,
unsigned int gain)
{
struct dt3k_private *devpriv = dev->private;
writew(subsys, devpriv->io_addr + DPR_SubSys);
writew(chan, devpriv->io_addr + DPR_Params(0));
writew(gain, devpriv->io_addr + DPR_Params(1));
dt3k_send_cmd(dev, CMD_READSINGLE);
return readw(devpriv->io_addr + DPR_Params(2));
}
static void dt3k_writesingle(struct comedi_device *dev, unsigned int subsys,
unsigned int chan, unsigned int data)
{
struct dt3k_private *devpriv = dev->private;
writew(subsys, devpriv->io_addr + DPR_SubSys);
writew(chan, devpriv->io_addr + DPR_Params(0));
writew(0, devpriv->io_addr + DPR_Params(1));
writew(data, devpriv->io_addr + DPR_Params(2));
dt3k_send_cmd(dev, CMD_WRITESINGLE);
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
front = readw(devpriv->io_addr + DPR_AD_Buf_Front);
count = front - devpriv->ai_front;
if (count < 0)
count += AI_FIFO_DEPTH;
rear = devpriv->ai_rear;
for (i = 0; i < count; i++) {
data = readw(devpriv->io_addr + DPR_ADC_buffer + rear);
comedi_buf_put(s, data);
rear++;
if (rear >= AI_FIFO_DEPTH)
rear = 0;
}
devpriv->ai_rear = rear;
writew(rear, devpriv->io_addr + DPR_AD_Buf_Rear);
}
static int dt3k_ai_cancel(struct comedi_device *dev, struct comedi_subdevice *s)
{
struct dt3k_private *devpriv = dev->private;
writew(SUBS_AI, devpriv->io_addr + DPR_SubSys);
dt3k_send_cmd(dev, CMD_STOP);
writew(0, devpriv->io_addr + DPR_Int_Mask);
return 0;
}
static irqreturn_t dt3k_interrupt(int irq, void *d)
{
struct comedi_device *dev = d;
struct dt3k_private *devpriv = dev->private;
struct comedi_subdevice *s = dev->read_subdev;
unsigned int status;
if (!dev->attached)
return IRQ_NONE;
status = readw(devpriv->io_addr + DPR_Intr_Flag);
if (status & DT3000_ADFULL) {
dt3k_ai_empty_fifo(dev, s);
s->async->events |= COMEDI_CB_BLOCK;
}
if (status & (DT3000_ADSWERR | DT3000_ADHWERR))
s->async->events |= COMEDI_CB_ERROR | COMEDI_CB_EOA;
debug_n_ints++;
if (debug_n_ints >= 10)
s->async->events |= COMEDI_CB_EOA;
cfc_handle_events(dev, s);
return IRQ_HANDLED;
}
static int dt3k_ns_to_timer(unsigned int timer_base, unsigned int *nanosec,
unsigned int round_mode)
{
int divider, base, prescale;
for (prescale = 0; prescale < 16; prescale++) {
base = timer_base * (prescale + 1);
switch (round_mode) {
case TRIG_ROUND_NEAREST:
default:
divider = (*nanosec + base / 2) / base;
break;
case TRIG_ROUND_DOWN:
divider = (*nanosec) / base;
break;
case TRIG_ROUND_UP:
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
const struct dt3k_boardtype *this_board = comedi_board(dev);
int err = 0;
unsigned int arg;
err |= cfc_check_trigger_src(&cmd->start_src, TRIG_NOW);
err |= cfc_check_trigger_src(&cmd->scan_begin_src, TRIG_TIMER);
err |= cfc_check_trigger_src(&cmd->convert_src, TRIG_TIMER);
err |= cfc_check_trigger_src(&cmd->scan_end_src, TRIG_COUNT);
err |= cfc_check_trigger_src(&cmd->stop_src, TRIG_COUNT);
if (err)
return 1;
if (err)
return 2;
err |= cfc_check_trigger_arg_is(&cmd->start_arg, 0);
if (cmd->scan_begin_src == TRIG_TIMER) {
err |= cfc_check_trigger_arg_min(&cmd->scan_begin_arg,
this_board->ai_speed);
err |= cfc_check_trigger_arg_max(&cmd->scan_begin_arg,
100 * 16 * 65535);
}
if (cmd->convert_src == TRIG_TIMER) {
err |= cfc_check_trigger_arg_min(&cmd->convert_arg,
this_board->ai_speed);
err |= cfc_check_trigger_arg_max(&cmd->convert_arg,
50 * 16 * 65535);
}
err |= cfc_check_trigger_arg_is(&cmd->scan_end_arg, cmd->chanlist_len);
if (cmd->stop_src == TRIG_COUNT)
err |= cfc_check_trigger_arg_max(&cmd->stop_arg, 0x00ffffff);
else
err |= cfc_check_trigger_arg_is(&cmd->stop_arg, 0);
if (err)
return 3;
if (cmd->scan_begin_src == TRIG_TIMER) {
arg = cmd->scan_begin_arg;
dt3k_ns_to_timer(100, &arg, cmd->flags & TRIG_ROUND_MASK);
err |= cfc_check_trigger_arg_is(&cmd->scan_begin_arg, arg);
}
if (cmd->convert_src == TRIG_TIMER) {
arg = cmd->convert_arg;
dt3k_ns_to_timer(50, &arg, cmd->flags & TRIG_ROUND_MASK);
err |= cfc_check_trigger_arg_is(&cmd->convert_arg, arg);
if (cmd->scan_begin_src == TRIG_TIMER) {
arg = cmd->convert_arg * cmd->scan_end_arg;
err |= cfc_check_trigger_arg_min(&cmd->scan_begin_arg,
arg);
}
}
if (err)
return 4;
return 0;
}
static int dt3k_ai_cmd(struct comedi_device *dev, struct comedi_subdevice *s)
{
struct dt3k_private *devpriv = dev->private;
struct comedi_cmd *cmd = &s->async->cmd;
int i;
unsigned int chan, range, aref;
unsigned int divider;
unsigned int tscandiv;
unsigned int mode;
for (i = 0; i < cmd->chanlist_len; i++) {
chan = CR_CHAN(cmd->chanlist[i]);
range = CR_RANGE(cmd->chanlist[i]);
writew((range << 6) | chan,
devpriv->io_addr + DPR_ADC_buffer + i);
}
aref = CR_AREF(cmd->chanlist[0]);
writew(cmd->scan_end_arg, devpriv->io_addr + DPR_Params(0));
if (cmd->convert_src == TRIG_TIMER) {
divider = dt3k_ns_to_timer(50, &cmd->convert_arg,
cmd->flags & TRIG_ROUND_MASK);
writew((divider >> 16), devpriv->io_addr + DPR_Params(1));
writew((divider & 0xffff), devpriv->io_addr + DPR_Params(2));
}
if (cmd->scan_begin_src == TRIG_TIMER) {
tscandiv = dt3k_ns_to_timer(100, &cmd->scan_begin_arg,
cmd->flags & TRIG_ROUND_MASK);
writew((tscandiv >> 16), devpriv->io_addr + DPR_Params(3));
writew((tscandiv & 0xffff), devpriv->io_addr + DPR_Params(4));
}
mode = DT3000_AD_RETRIG_INTERNAL | 0 | 0;
writew(mode, devpriv->io_addr + DPR_Params(5));
writew(aref == AREF_DIFF, devpriv->io_addr + DPR_Params(6));
writew(AI_FIFO_DEPTH / 2, devpriv->io_addr + DPR_Params(7));
writew(SUBS_AI, devpriv->io_addr + DPR_SubSys);
dt3k_send_cmd(dev, CMD_CONFIG);
writew(DT3000_ADFULL | DT3000_ADSWERR | DT3000_ADHWERR,
devpriv->io_addr + DPR_Int_Mask);
debug_n_ints = 0;
writew(SUBS_AI, devpriv->io_addr + DPR_SubSys);
dt3k_send_cmd(dev, CMD_START);
return 0;
}
static int dt3k_ai_insn(struct comedi_device *dev, struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
int i;
unsigned int chan, gain, aref;
chan = CR_CHAN(insn->chanspec);
gain = CR_RANGE(insn->chanspec);
aref = CR_AREF(insn->chanspec);
for (i = 0; i < insn->n; i++)
data[i] = dt3k_readsingle(dev, SUBS_AI, chan, gain);
return i;
}
static int dt3k_ao_insn(struct comedi_device *dev, struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct dt3k_private *devpriv = dev->private;
int i;
unsigned int chan;
chan = CR_CHAN(insn->chanspec);
for (i = 0; i < insn->n; i++) {
dt3k_writesingle(dev, SUBS_AO, chan, data[i]);
devpriv->ao_readback[chan] = data[i];
}
return i;
}
static int dt3k_ao_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct dt3k_private *devpriv = dev->private;
int i;
unsigned int chan;
chan = CR_CHAN(insn->chanspec);
for (i = 0; i < insn->n; i++)
data[i] = devpriv->ao_readback[chan];
return i;
}
static void dt3k_dio_config(struct comedi_device *dev, int bits)
{
struct dt3k_private *devpriv = dev->private;
writew(SUBS_DOUT, devpriv->io_addr + DPR_SubSys);
writew(bits, devpriv->io_addr + DPR_Params(0));
#if 0
writew(0, devpriv->io_addr + DPR_Params(1));
writew(0, devpriv->io_addr + DPR_Params(2));
#endif
dt3k_send_cmd(dev, CMD_CONFIG);
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
dt3k_writesingle(dev, SUBS_DOUT, 0, s->state);
data[1] = dt3k_readsingle(dev, SUBS_DIN, 0, 0);
return insn->n;
}
static int dt3k_mem_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct dt3k_private *devpriv = dev->private;
unsigned int addr = CR_CHAN(insn->chanspec);
int i;
for (i = 0; i < insn->n; i++) {
writew(SUBS_MEM, devpriv->io_addr + DPR_SubSys);
writew(addr, devpriv->io_addr + DPR_Params(0));
writew(1, devpriv->io_addr + DPR_Params(1));
dt3k_send_cmd(dev, CMD_READCODE);
data[i] = readw(devpriv->io_addr + DPR_Params(2));
}
return i;
}
static int dt3000_auto_attach(struct comedi_device *dev,
unsigned long context)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
const struct dt3k_boardtype *this_board = NULL;
struct dt3k_private *devpriv;
struct comedi_subdevice *s;
int ret = 0;
if (context < ARRAY_SIZE(dt3k_boardtypes))
this_board = &dt3k_boardtypes[context];
if (!this_board)
return -ENODEV;
dev->board_ptr = this_board;
dev->board_name = this_board->name;
devpriv = comedi_alloc_devpriv(dev, sizeof(*devpriv));
if (!devpriv)
return -ENOMEM;
ret = comedi_pci_enable(dev);
if (ret < 0)
return ret;
devpriv->io_addr = pci_ioremap_bar(pcidev, 0);
if (!devpriv->io_addr)
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
s->n_chan = this_board->adchan;
s->insn_read = dt3k_ai_insn;
s->maxdata = (1 << this_board->adbits) - 1;
s->range_table = &range_dt3000_ai;
if (dev->irq) {
dev->read_subdev = s;
s->subdev_flags |= SDF_CMD_READ;
s->len_chanlist = 512;
s->do_cmd = dt3k_ai_cmd;
s->do_cmdtest = dt3k_ai_cmdtest;
s->cancel = dt3k_ai_cancel;
}
s = &dev->subdevices[1];
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = 2;
s->insn_read = dt3k_ao_insn_read;
s->insn_write = dt3k_ao_insn;
s->maxdata = (1 << this_board->dabits) - 1;
s->len_chanlist = 1;
s->range_table = &range_bipolar10;
s = &dev->subdevices[2];
s->type = COMEDI_SUBD_DIO;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE;
s->n_chan = 8;
s->insn_config = dt3k_dio_insn_config;
s->insn_bits = dt3k_dio_insn_bits;
s->maxdata = 1;
s->len_chanlist = 8;
s->range_table = &range_digital;
s = &dev->subdevices[3];
s->type = COMEDI_SUBD_MEMORY;
s->subdev_flags = SDF_READABLE;
s->n_chan = 0x1000;
s->insn_read = dt3k_mem_insn_read;
s->maxdata = 0xff;
s->len_chanlist = 1;
s->range_table = &range_unknown;
#if 0
s = &dev->subdevices[4];
s->type = COMEDI_SUBD_PROC;
#endif
return 0;
}
static void dt3000_detach(struct comedi_device *dev)
{
struct dt3k_private *devpriv = dev->private;
if (dev->irq)
free_irq(dev->irq, dev);
if (devpriv) {
if (devpriv->io_addr)
iounmap(devpriv->io_addr);
}
comedi_pci_disable(dev);
}
static int dt3000_pci_probe(struct pci_dev *dev,
const struct pci_device_id *id)
{
return comedi_pci_auto_config(dev, &dt3000_driver, id->driver_data);
}
