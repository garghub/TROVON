static int rtd_ns_to_timer_base(unsigned int *nanosec,
unsigned int flags, int base)
{
int divider;
switch (flags & CMDF_ROUND_MASK) {
case CMDF_ROUND_NEAREST:
default:
divider = DIV_ROUND_CLOSEST(*nanosec, base);
break;
case CMDF_ROUND_DOWN:
divider = (*nanosec) / base;
break;
case CMDF_ROUND_UP:
divider = DIV_ROUND_UP(*nanosec, base);
break;
}
if (divider < 2)
divider = 2;
*nanosec = base * divider;
return divider - 1;
}
static int rtd_ns_to_timer(unsigned int *ns, unsigned int flags)
{
return rtd_ns_to_timer_base(ns, flags, RTD_CLOCK_BASE);
}
static unsigned short rtd_convert_chan_gain(struct comedi_device *dev,
unsigned int chanspec, int index)
{
const struct rtd_boardinfo *board = dev->board_ptr;
unsigned int chan = CR_CHAN(chanspec);
unsigned int range = CR_RANGE(chanspec);
unsigned int aref = CR_AREF(chanspec);
unsigned short r = 0;
r |= chan & 0xf;
if (range < board->range_bip10) {
r |= 0x000;
r |= (range & 0x7) << 4;
} else if (range < board->range_uni10) {
r |= 0x100;
r |= ((range - board->range_bip10) & 0x7) << 4;
} else {
r |= 0x200;
r |= ((range - board->range_uni10) & 0x7) << 4;
}
switch (aref) {
case AREF_GROUND:
break;
case AREF_COMMON:
r |= 0x80;
break;
case AREF_DIFF:
r |= 0x400;
break;
case AREF_OTHER:
break;
}
return r;
}
static void rtd_load_channelgain_list(struct comedi_device *dev,
unsigned int n_chan, unsigned int *list)
{
if (n_chan > 1) {
int ii;
writel(0, dev->mmio + LAS0_CGT_CLEAR);
writel(1, dev->mmio + LAS0_CGT_ENABLE);
for (ii = 0; ii < n_chan; ii++) {
writel(rtd_convert_chan_gain(dev, list[ii], ii),
dev->mmio + LAS0_CGT_WRITE);
}
} else {
writel(0, dev->mmio + LAS0_CGT_ENABLE);
writel(rtd_convert_chan_gain(dev, list[0], 0),
dev->mmio + LAS0_CGL_WRITE);
}
}
static int rtd520_probe_fifo_depth(struct comedi_device *dev)
{
unsigned int chanspec = CR_PACK(0, 0, AREF_GROUND);
unsigned i;
static const unsigned limit = 0x2000;
unsigned fifo_size = 0;
writel(0, dev->mmio + LAS0_ADC_FIFO_CLEAR);
rtd_load_channelgain_list(dev, 1, &chanspec);
writel(0, dev->mmio + LAS0_ADC_CONVERSION);
for (i = 0; i < limit; ++i) {
unsigned fifo_status;
writew(0, dev->mmio + LAS0_ADC);
usleep_range(1, 1000);
fifo_status = readl(dev->mmio + LAS0_ADC);
if ((fifo_status & FS_ADC_HEMPTY) == 0) {
fifo_size = 2 * i;
break;
}
}
if (i == limit) {
dev_info(dev->class_dev, "failed to probe fifo size.\n");
return -EIO;
}
writel(0, dev->mmio + LAS0_ADC_FIFO_CLEAR);
if (fifo_size != 0x400 && fifo_size != 0x2000) {
dev_info(dev->class_dev,
"unexpected fifo size of %i, expected 1024 or 8192.\n",
fifo_size);
return -EIO;
}
return fifo_size;
}
static int rtd_ai_eoc(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned long context)
{
unsigned int status;
status = readl(dev->mmio + LAS0_ADC);
if (status & FS_ADC_NOT_EMPTY)
return 0;
return -EBUSY;
}
static int rtd_ai_rinsn(struct comedi_device *dev,
struct comedi_subdevice *s, struct comedi_insn *insn,
unsigned int *data)
{
struct rtd_private *devpriv = dev->private;
unsigned int range = CR_RANGE(insn->chanspec);
int ret;
int n;
writel(0, dev->mmio + LAS0_ADC_FIFO_CLEAR);
rtd_load_channelgain_list(dev, 1, &insn->chanspec);
writel(0, dev->mmio + LAS0_ADC_CONVERSION);
for (n = 0; n < insn->n; n++) {
unsigned short d;
writew(0, dev->mmio + LAS0_ADC);
ret = comedi_timeout(dev, s, insn, rtd_ai_eoc, 0);
if (ret)
return ret;
d = readw(devpriv->las1 + LAS1_ADC_FIFO);
d >>= 3;
if (comedi_range_is_bipolar(s, range))
d = comedi_offset_munge(s, d);
data[n] = d & s->maxdata;
}
return n;
}
static int ai_read_n(struct comedi_device *dev, struct comedi_subdevice *s,
int count)
{
struct rtd_private *devpriv = dev->private;
struct comedi_async *async = s->async;
struct comedi_cmd *cmd = &async->cmd;
int ii;
for (ii = 0; ii < count; ii++) {
unsigned int range = CR_RANGE(cmd->chanlist[async->cur_chan]);
unsigned short d;
if (devpriv->ai_count == 0) {
d = readw(devpriv->las1 + LAS1_ADC_FIFO);
continue;
}
d = readw(devpriv->las1 + LAS1_ADC_FIFO);
d >>= 3;
if (comedi_range_is_bipolar(s, range))
d = comedi_offset_munge(s, d);
d &= s->maxdata;
if (!comedi_buf_write_samples(s, &d, 1))
return -1;
if (devpriv->ai_count > 0)
devpriv->ai_count--;
}
return 0;
}
static irqreturn_t rtd_interrupt(int irq, void *d)
{
struct comedi_device *dev = d;
struct comedi_subdevice *s = dev->read_subdev;
struct rtd_private *devpriv = dev->private;
u32 overrun;
u16 status;
u16 fifo_status;
if (!dev->attached)
return IRQ_NONE;
fifo_status = readl(dev->mmio + LAS0_ADC);
if (!(fifo_status & FS_ADC_NOT_FULL))
goto xfer_abort;
status = readw(dev->mmio + LAS0_IT);
if (status == 0)
return IRQ_HANDLED;
if (status & IRQM_ADC_ABOUT_CNT) {
if (!(fifo_status & FS_ADC_HEMPTY)) {
if (ai_read_n(dev, s, devpriv->fifosz / 2) < 0)
goto xfer_abort;
if (devpriv->ai_count == 0)
goto xfer_done;
} else if (devpriv->xfer_count > 0) {
if (fifo_status & FS_ADC_NOT_EMPTY) {
if (ai_read_n(dev, s, devpriv->xfer_count) < 0)
goto xfer_abort;
if (devpriv->ai_count == 0)
goto xfer_done;
}
}
}
overrun = readl(dev->mmio + LAS0_OVERRUN) & 0xffff;
if (overrun)
goto xfer_abort;
writew(status, dev->mmio + LAS0_CLEAR);
readw(dev->mmio + LAS0_CLEAR);
comedi_handle_events(dev, s);
return IRQ_HANDLED;
xfer_abort:
s->async->events |= COMEDI_CB_ERROR;
xfer_done:
s->async->events |= COMEDI_CB_EOA;
status = readw(dev->mmio + LAS0_IT);
writew(status, dev->mmio + LAS0_CLEAR);
readw(dev->mmio + LAS0_CLEAR);
fifo_status = readl(dev->mmio + LAS0_ADC);
overrun = readl(dev->mmio + LAS0_OVERRUN) & 0xffff;
comedi_handle_events(dev, s);
return IRQ_HANDLED;
}
static int rtd_ai_cmdtest(struct comedi_device *dev,
struct comedi_subdevice *s, struct comedi_cmd *cmd)
{
int err = 0;
unsigned int arg;
err |= comedi_check_trigger_src(&cmd->start_src, TRIG_NOW);
err |= comedi_check_trigger_src(&cmd->scan_begin_src,
TRIG_TIMER | TRIG_EXT);
err |= comedi_check_trigger_src(&cmd->convert_src,
TRIG_TIMER | TRIG_EXT);
err |= comedi_check_trigger_src(&cmd->scan_end_src, TRIG_COUNT);
err |= comedi_check_trigger_src(&cmd->stop_src, TRIG_COUNT | TRIG_NONE);
if (err)
return 1;
err |= comedi_check_trigger_is_unique(cmd->scan_begin_src);
err |= comedi_check_trigger_is_unique(cmd->convert_src);
err |= comedi_check_trigger_is_unique(cmd->stop_src);
if (err)
return 2;
err |= comedi_check_trigger_arg_is(&cmd->start_arg, 0);
if (cmd->scan_begin_src == TRIG_TIMER) {
if (cmd->chanlist_len == 1) {
if (comedi_check_trigger_arg_min(&cmd->scan_begin_arg,
RTD_MAX_SPEED_1)) {
rtd_ns_to_timer(&cmd->scan_begin_arg,
CMDF_ROUND_UP);
err |= -EINVAL;
}
if (comedi_check_trigger_arg_max(&cmd->scan_begin_arg,
RTD_MIN_SPEED_1)) {
rtd_ns_to_timer(&cmd->scan_begin_arg,
CMDF_ROUND_DOWN);
err |= -EINVAL;
}
} else {
if (comedi_check_trigger_arg_min(&cmd->scan_begin_arg,
RTD_MAX_SPEED)) {
rtd_ns_to_timer(&cmd->scan_begin_arg,
CMDF_ROUND_UP);
err |= -EINVAL;
}
if (comedi_check_trigger_arg_max(&cmd->scan_begin_arg,
RTD_MIN_SPEED)) {
rtd_ns_to_timer(&cmd->scan_begin_arg,
CMDF_ROUND_DOWN);
err |= -EINVAL;
}
}
} else {
err |= comedi_check_trigger_arg_max(&cmd->scan_begin_arg, 9);
}
if (cmd->convert_src == TRIG_TIMER) {
if (cmd->chanlist_len == 1) {
if (comedi_check_trigger_arg_min(&cmd->convert_arg,
RTD_MAX_SPEED_1)) {
rtd_ns_to_timer(&cmd->convert_arg,
CMDF_ROUND_UP);
err |= -EINVAL;
}
if (comedi_check_trigger_arg_max(&cmd->convert_arg,
RTD_MIN_SPEED_1)) {
rtd_ns_to_timer(&cmd->convert_arg,
CMDF_ROUND_DOWN);
err |= -EINVAL;
}
} else {
if (comedi_check_trigger_arg_min(&cmd->convert_arg,
RTD_MAX_SPEED)) {
rtd_ns_to_timer(&cmd->convert_arg,
CMDF_ROUND_UP);
err |= -EINVAL;
}
if (comedi_check_trigger_arg_max(&cmd->convert_arg,
RTD_MIN_SPEED)) {
rtd_ns_to_timer(&cmd->convert_arg,
CMDF_ROUND_DOWN);
err |= -EINVAL;
}
}
} else {
err |= comedi_check_trigger_arg_max(&cmd->convert_arg, 9);
}
err |= comedi_check_trigger_arg_is(&cmd->scan_end_arg,
cmd->chanlist_len);
if (cmd->stop_src == TRIG_COUNT)
err |= comedi_check_trigger_arg_min(&cmd->stop_arg, 1);
else
err |= comedi_check_trigger_arg_is(&cmd->stop_arg, 0);
if (err)
return 3;
if (cmd->scan_begin_src == TRIG_TIMER) {
arg = cmd->scan_begin_arg;
rtd_ns_to_timer(&arg, cmd->flags);
err |= comedi_check_trigger_arg_is(&cmd->scan_begin_arg, arg);
}
if (cmd->convert_src == TRIG_TIMER) {
arg = cmd->convert_arg;
rtd_ns_to_timer(&arg, cmd->flags);
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
static int rtd_ai_cmd(struct comedi_device *dev, struct comedi_subdevice *s)
{
struct rtd_private *devpriv = dev->private;
struct comedi_cmd *cmd = &s->async->cmd;
int timer;
writel(0, dev->mmio + LAS0_PACER_STOP);
writel(0, dev->mmio + LAS0_PACER);
writel(0, dev->mmio + LAS0_ADC_CONVERSION);
writew(0, dev->mmio + LAS0_IT);
writel(0, dev->mmio + LAS0_ADC_FIFO_CLEAR);
writel(0, dev->mmio + LAS0_OVERRUN);
rtd_load_channelgain_list(dev, cmd->chanlist_len, cmd->chanlist);
if (cmd->chanlist_len > 1) {
writel(0, dev->mmio + LAS0_PACER_START);
writel(1, dev->mmio + LAS0_BURST_START);
writel(2, dev->mmio + LAS0_ADC_CONVERSION);
} else {
writel(0, dev->mmio + LAS0_PACER_START);
writel(1, dev->mmio + LAS0_ADC_CONVERSION);
}
writel((devpriv->fifosz / 2 - 1) & 0xffff, dev->mmio + LAS0_ACNT);
if (cmd->scan_begin_src == TRIG_TIMER) {
if (cmd->flags & CMDF_WAKE_EOS) {
devpriv->xfer_count = cmd->chanlist_len;
devpriv->flags |= SEND_EOS;
} else {
devpriv->xfer_count =
(TRANS_TARGET_PERIOD * cmd->chanlist_len) /
cmd->scan_begin_arg;
if (devpriv->xfer_count < cmd->chanlist_len) {
devpriv->xfer_count = cmd->chanlist_len;
} else {
devpriv->xfer_count =
(devpriv->xfer_count +
cmd->chanlist_len - 1)
/ cmd->chanlist_len;
devpriv->xfer_count *= cmd->chanlist_len;
}
devpriv->flags |= SEND_EOS;
}
if (devpriv->xfer_count >= (devpriv->fifosz / 2)) {
devpriv->xfer_count = 0;
devpriv->flags &= ~SEND_EOS;
} else {
writel((devpriv->xfer_count - 1) & 0xffff,
dev->mmio + LAS0_ACNT);
}
} else {
devpriv->xfer_count = 0;
devpriv->flags &= ~SEND_EOS;
}
writel(1, dev->mmio + LAS0_PACER_SELECT);
writel(1, dev->mmio + LAS0_ACNT_STOP_ENABLE);
switch (cmd->stop_src) {
case TRIG_COUNT:
devpriv->ai_count = cmd->stop_arg * cmd->chanlist_len;
if ((devpriv->xfer_count > 0) &&
(devpriv->xfer_count > devpriv->ai_count)) {
devpriv->xfer_count = devpriv->ai_count;
}
break;
case TRIG_NONE:
devpriv->ai_count = -1;
break;
}
switch (cmd->scan_begin_src) {
case TRIG_TIMER:
timer = rtd_ns_to_timer(&cmd->scan_begin_arg,
CMDF_ROUND_NEAREST);
writel(timer & 0xffffff, dev->mmio + LAS0_PCLK);
break;
case TRIG_EXT:
writel(1, dev->mmio + LAS0_PACER_START);
break;
}
switch (cmd->convert_src) {
case TRIG_TIMER:
if (cmd->chanlist_len > 1) {
timer = rtd_ns_to_timer(&cmd->convert_arg,
CMDF_ROUND_NEAREST);
writel(timer & 0x3ff, dev->mmio + LAS0_BCLK);
}
break;
case TRIG_EXT:
writel(2, dev->mmio + LAS0_BURST_START);
break;
}
writew(~0, dev->mmio + LAS0_CLEAR);
readw(dev->mmio + LAS0_CLEAR);
writew(IRQM_ADC_ABOUT_CNT, dev->mmio + LAS0_IT);
readl(dev->mmio + LAS0_PACER);
return 0;
}
static int rtd_ai_cancel(struct comedi_device *dev, struct comedi_subdevice *s)
{
struct rtd_private *devpriv = dev->private;
writel(0, dev->mmio + LAS0_PACER_STOP);
writel(0, dev->mmio + LAS0_PACER);
writel(0, dev->mmio + LAS0_ADC_CONVERSION);
writew(0, dev->mmio + LAS0_IT);
devpriv->ai_count = 0;
writel(0, dev->mmio + LAS0_ADC_FIFO_CLEAR);
return 0;
}
static int rtd_ao_eoc(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned long context)
{
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned int bit = (chan == 0) ? FS_DAC1_NOT_EMPTY : FS_DAC2_NOT_EMPTY;
unsigned int status;
status = readl(dev->mmio + LAS0_ADC);
if (status & bit)
return 0;
return -EBUSY;
}
static int rtd_ao_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct rtd_private *devpriv = dev->private;
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned int range = CR_RANGE(insn->chanspec);
int ret;
int i;
writew(range & 7, dev->mmio + LAS0_DAC_CTRL(chan));
for (i = 0; i < insn->n; ++i) {
unsigned int val = data[i];
if (comedi_range_is_bipolar(s, range)) {
val = comedi_offset_munge(s, val);
val |= (val & ((s->maxdata + 1) >> 1)) << 1;
}
val <<= 3;
writew(val, devpriv->las1 + LAS1_DAC_FIFO(chan));
writew(0, dev->mmio + LAS0_UPDATE_DAC(chan));
ret = comedi_timeout(dev, s, insn, rtd_ao_eoc, 0);
if (ret)
return ret;
s->readback[chan] = data[i];
}
return insn->n;
}
static int rtd_dio_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
if (comedi_dio_update_state(s, data))
writew(s->state & 0xff, dev->mmio + LAS0_DIO0);
data[1] = readw(dev->mmio + LAS0_DIO0) & 0xff;
return insn->n;
}
static int rtd_dio_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
int ret;
ret = comedi_dio_insn_config(dev, s, insn, data, 0);
if (ret)
return ret;
writew(0x01, dev->mmio + LAS0_DIO_STATUS);
writew(s->io_bits & 0xff, dev->mmio + LAS0_DIO0_CTRL);
writew(0x00, dev->mmio + LAS0_DIO_STATUS);
return insn->n;
}
static int rtd_counter_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct rtd_private *devpriv = dev->private;
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned int max_src;
unsigned int src;
switch (data[0]) {
case INSN_CONFIG_SET_GATE_SRC:
src = data[2];
max_src = (chan == 0) ? 3 : 4;
if (src > max_src)
return -EINVAL;
devpriv->timer_gate_src[chan] = src;
writeb(src, dev->mmio + LAS0_8254_GATE_SEL(chan));
break;
case INSN_CONFIG_GET_GATE_SRC:
data[2] = devpriv->timer_gate_src[chan];
break;
case INSN_CONFIG_SET_CLOCK_SRC:
src = data[1];
switch (chan) {
case 0:
max_src = 3;
break;
case 1:
max_src = 5;
break;
case 2:
max_src = 4;
break;
default:
return -EINVAL;
}
if (src > max_src)
return -EINVAL;
devpriv->timer_clk_src[chan] = src;
writeb(src, dev->mmio + LAS0_8254_CLK_SEL(chan));
break;
case INSN_CONFIG_GET_CLOCK_SRC:
src = devpriv->timer_clk_src[chan];
data[1] = devpriv->timer_clk_src[chan];
data[2] = (src == 0) ? RTD_CLOCK_BASE : 0;
break;
default:
return -EINVAL;
}
return insn->n;
}
static void rtd_reset(struct comedi_device *dev)
{
struct rtd_private *devpriv = dev->private;
writel(0, dev->mmio + LAS0_BOARD_RESET);
usleep_range(100, 1000);
writel(0, devpriv->lcfg + PLX_INTRCS_REG);
writew(0, dev->mmio + LAS0_IT);
writew(~0, dev->mmio + LAS0_CLEAR);
readw(dev->mmio + LAS0_CLEAR);
}
static void rtd_init_board(struct comedi_device *dev)
{
rtd_reset(dev);
writel(0, dev->mmio + LAS0_OVERRUN);
writel(0, dev->mmio + LAS0_CGT_CLEAR);
writel(0, dev->mmio + LAS0_ADC_FIFO_CLEAR);
writel(0, dev->mmio + LAS0_DAC_RESET(0));
writel(0, dev->mmio + LAS0_DAC_RESET(1));
writew(0, dev->mmio + LAS0_DIO_STATUS);
}
static void rtd_pci_latency_quirk(struct comedi_device *dev,
struct pci_dev *pcidev)
{
unsigned char pci_latency;
pci_read_config_byte(pcidev, PCI_LATENCY_TIMER, &pci_latency);
if (pci_latency < 32) {
dev_info(dev->class_dev,
"PCI latency changed from %d to %d\n",
pci_latency, 32);
pci_write_config_byte(pcidev, PCI_LATENCY_TIMER, 32);
}
}
static int rtd_auto_attach(struct comedi_device *dev,
unsigned long context)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
const struct rtd_boardinfo *board = NULL;
struct rtd_private *devpriv;
struct comedi_subdevice *s;
int ret;
if (context < ARRAY_SIZE(rtd520_boards))
board = &rtd520_boards[context];
if (!board)
return -ENODEV;
dev->board_ptr = board;
dev->board_name = board->name;
devpriv = comedi_alloc_devpriv(dev, sizeof(*devpriv));
if (!devpriv)
return -ENOMEM;
ret = comedi_pci_enable(dev);
if (ret)
return ret;
dev->mmio = pci_ioremap_bar(pcidev, 2);
devpriv->las1 = pci_ioremap_bar(pcidev, 3);
devpriv->lcfg = pci_ioremap_bar(pcidev, 0);
if (!dev->mmio || !devpriv->las1 || !devpriv->lcfg)
return -ENOMEM;
rtd_pci_latency_quirk(dev, pcidev);
if (pcidev->irq) {
ret = request_irq(pcidev->irq, rtd_interrupt, IRQF_SHARED,
dev->board_name, dev);
if (ret == 0)
dev->irq = pcidev->irq;
}
ret = comedi_alloc_subdevices(dev, 4);
if (ret)
return ret;
s = &dev->subdevices[0];
s->type = COMEDI_SUBD_AI;
s->subdev_flags = SDF_READABLE | SDF_GROUND | SDF_COMMON | SDF_DIFF;
s->n_chan = 16;
s->maxdata = 0x0fff;
s->range_table = board->ai_range;
s->len_chanlist = RTD_MAX_CHANLIST;
s->insn_read = rtd_ai_rinsn;
if (dev->irq) {
dev->read_subdev = s;
s->subdev_flags |= SDF_CMD_READ;
s->do_cmd = rtd_ai_cmd;
s->do_cmdtest = rtd_ai_cmdtest;
s->cancel = rtd_ai_cancel;
}
s = &dev->subdevices[1];
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = 2;
s->maxdata = 0x0fff;
s->range_table = &rtd_ao_range;
s->insn_write = rtd_ao_insn_write;
ret = comedi_alloc_subdev_readback(s);
if (ret)
return ret;
s = &dev->subdevices[2];
s->type = COMEDI_SUBD_DIO;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE;
s->n_chan = 8;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = rtd_dio_insn_bits;
s->insn_config = rtd_dio_insn_config;
s = &dev->subdevices[3];
dev->pacer = comedi_8254_mm_init(dev->mmio + LAS0_8254_TIMER_BASE,
RTD_CLOCK_BASE, I8254_IO8, 2);
if (!dev->pacer)
return -ENOMEM;
comedi_8254_subdevice_init(s, dev->pacer);
dev->pacer->insn_config = rtd_counter_insn_config;
rtd_init_board(dev);
ret = rtd520_probe_fifo_depth(dev);
if (ret < 0)
return ret;
devpriv->fifosz = ret;
if (dev->irq)
writel(ICS_PIE | ICS_PLIE, devpriv->lcfg + PLX_INTRCS_REG);
return 0;
}
static void rtd_detach(struct comedi_device *dev)
{
struct rtd_private *devpriv = dev->private;
if (devpriv) {
if (dev->mmio && devpriv->lcfg)
rtd_reset(dev);
if (dev->irq)
free_irq(dev->irq, dev);
if (dev->mmio)
iounmap(dev->mmio);
if (devpriv->las1)
iounmap(devpriv->las1);
if (devpriv->lcfg)
iounmap(devpriv->lcfg);
}
comedi_pci_disable(dev);
}
static int rtd520_pci_probe(struct pci_dev *dev,
const struct pci_device_id *id)
{
return comedi_pci_auto_config(dev, &rtd520_driver, id->driver_data);
}
