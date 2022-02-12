static int rtd_ns_to_timer_base(unsigned int *nanosec,
int round_mode, int base)
{
int divider;
switch (round_mode) {
case TRIG_ROUND_NEAREST:
default:
divider = (*nanosec + base / 2) / base;
break;
case TRIG_ROUND_DOWN:
divider = (*nanosec) / base;
break;
case TRIG_ROUND_UP:
divider = (*nanosec + base - 1) / base;
break;
}
if (divider < 2)
divider = 2;
*nanosec = base * divider;
return divider - 1;
}
static int rtd_ns_to_timer(unsigned int *ns, int round_mode)
{
return rtd_ns_to_timer_base(ns, round_mode, RTD_CLOCK_BASE);
}
static unsigned short rtdConvertChanGain(struct comedi_device *dev,
unsigned int comediChan, int chanIndex)
{
const struct rtdBoard *thisboard = comedi_board(dev);
struct rtdPrivate *devpriv = dev->private;
unsigned int chan, range, aref;
unsigned short r = 0;
chan = CR_CHAN(comediChan);
range = CR_RANGE(comediChan);
aref = CR_AREF(comediChan);
r |= chan & 0xf;
if (range < thisboard->range10Start) {
r |= 0x000;
r |= (range & 0x7) << 4;
CHAN_ARRAY_SET(devpriv->chanBipolar, chanIndex);
} else if (range < thisboard->rangeUniStart) {
r |= 0x100;
r |= ((range - thisboard->range10Start) & 0x7) << 4;
CHAN_ARRAY_SET(devpriv->chanBipolar, chanIndex);
} else {
r |= 0x200;
r |= ((range - thisboard->rangeUniStart) & 0x7) << 4;
CHAN_ARRAY_CLEAR(devpriv->chanBipolar, chanIndex);
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
struct rtdPrivate *devpriv = dev->private;
if (n_chan > 1) {
int ii;
writel(0, devpriv->las0 + LAS0_CGT_CLEAR);
writel(1, devpriv->las0 + LAS0_CGT_ENABLE);
for (ii = 0; ii < n_chan; ii++) {
writel(rtdConvertChanGain(dev, list[ii], ii),
devpriv->las0 + LAS0_CGT_WRITE);
}
} else {
writel(0, devpriv->las0 + LAS0_CGT_ENABLE);
writel(rtdConvertChanGain(dev, list[0], 0),
devpriv->las0 + LAS0_CGL_WRITE);
}
}
static int rtd520_probe_fifo_depth(struct comedi_device *dev)
{
struct rtdPrivate *devpriv = dev->private;
unsigned int chanspec = CR_PACK(0, 0, AREF_GROUND);
unsigned i;
static const unsigned limit = 0x2000;
unsigned fifo_size = 0;
writel(0, devpriv->las0 + LAS0_ADC_FIFO_CLEAR);
rtd_load_channelgain_list(dev, 1, &chanspec);
writel(0, devpriv->las0 + LAS0_ADC_CONVERSION);
for (i = 0; i < limit; ++i) {
unsigned fifo_status;
writew(0, devpriv->las0 + LAS0_ADC);
udelay(1);
fifo_status = readl(devpriv->las0 + LAS0_ADC);
if ((fifo_status & FS_ADC_HEMPTY) == 0) {
fifo_size = 2 * i;
break;
}
}
if (i == limit) {
dev_info(dev->class_dev, "failed to probe fifo size.\n");
return -EIO;
}
writel(0, devpriv->las0 + LAS0_ADC_FIFO_CLEAR);
if (fifo_size != 0x400 && fifo_size != 0x2000) {
dev_info(dev->class_dev,
"unexpected fifo size of %i, expected 1024 or 8192.\n",
fifo_size);
return -EIO;
}
return fifo_size;
}
static int rtd_ai_rinsn(struct comedi_device *dev,
struct comedi_subdevice *s, struct comedi_insn *insn,
unsigned int *data)
{
struct rtdPrivate *devpriv = dev->private;
int n, ii;
int stat;
writel(0, devpriv->las0 + LAS0_ADC_FIFO_CLEAR);
rtd_load_channelgain_list(dev, 1, &insn->chanspec);
writel(0, devpriv->las0 + LAS0_ADC_CONVERSION);
for (n = 0; n < insn->n; n++) {
s16 d;
writew(0, devpriv->las0 + LAS0_ADC);
for (ii = 0; ii < RTD_ADC_TIMEOUT; ++ii) {
stat = readl(devpriv->las0 + LAS0_ADC);
if (stat & FS_ADC_NOT_EMPTY)
break;
WAIT_QUIETLY;
}
if (ii >= RTD_ADC_TIMEOUT)
return -ETIMEDOUT;
d = readw(devpriv->las1 + LAS1_ADC_FIFO);
d = d >> 3;
if (CHAN_ARRAY_TEST(devpriv->chanBipolar, 0))
data[n] = d + 2048;
else
data[n] = d;
}
return n;
}
static int ai_read_n(struct comedi_device *dev, struct comedi_subdevice *s,
int count)
{
struct rtdPrivate *devpriv = dev->private;
int ii;
for (ii = 0; ii < count; ii++) {
short sample;
s16 d;
if (0 == devpriv->aiCount) {
d = readw(devpriv->las1 + LAS1_ADC_FIFO);
continue;
}
d = readw(devpriv->las1 + LAS1_ADC_FIFO);
d = d >> 3;
if (CHAN_ARRAY_TEST(devpriv->chanBipolar, s->async->cur_chan)) {
sample = d + 2048;
} else
sample = d;
if (!comedi_buf_put(s->async, sample))
return -1;
if (devpriv->aiCount > 0)
devpriv->aiCount--;
}
return 0;
}
static int ai_read_dregs(struct comedi_device *dev, struct comedi_subdevice *s)
{
struct rtdPrivate *devpriv = dev->private;
while (readl(devpriv->las0 + LAS0_ADC) & FS_ADC_NOT_EMPTY) {
short sample;
s16 d = readw(devpriv->las1 + LAS1_ADC_FIFO);
if (0 == devpriv->aiCount) {
continue;
}
d = d >> 3;
if (CHAN_ARRAY_TEST(devpriv->chanBipolar, s->async->cur_chan)) {
sample = d + 2048;
} else
sample = d;
if (!comedi_buf_put(s->async, sample))
return -1;
if (devpriv->aiCount > 0)
devpriv->aiCount--;
}
return 0;
}
static irqreturn_t rtd_interrupt(int irq,
void *d)
{
struct comedi_device *dev = d;
struct comedi_subdevice *s = &dev->subdevices[0];
struct rtdPrivate *devpriv = dev->private;
u32 overrun;
u16 status;
u16 fifoStatus;
if (!dev->attached)
return IRQ_NONE;
fifoStatus = readl(devpriv->las0 + LAS0_ADC);
if (!(fifoStatus & FS_ADC_NOT_FULL))
goto abortTransfer;
status = readw(devpriv->las0 + LAS0_IT);
if (0 == status)
return IRQ_HANDLED;
if (status & IRQM_ADC_ABOUT_CNT) {
if (!(fifoStatus & FS_ADC_HEMPTY)) {
if (ai_read_n(dev, s, devpriv->fifoLen / 2) < 0)
goto abortTransfer;
if (0 == devpriv->aiCount)
goto transferDone;
comedi_event(dev, s);
} else if (devpriv->transCount > 0) {
if (fifoStatus & FS_ADC_NOT_EMPTY) {
if (ai_read_n(dev, s, devpriv->transCount) < 0)
goto abortTransfer;
if (0 == devpriv->aiCount)
goto transferDone;
comedi_event(dev, s);
}
}
}
overrun = readl(devpriv->las0 + LAS0_OVERRUN) & 0xffff;
if (overrun)
goto abortTransfer;
devpriv->intClearMask = status;
writew(devpriv->intClearMask, devpriv->las0 + LAS0_CLEAR);
readw(devpriv->las0 + LAS0_CLEAR);
return IRQ_HANDLED;
abortTransfer:
writel(0, devpriv->las0 + LAS0_ADC_FIFO_CLEAR);
s->async->events |= COMEDI_CB_ERROR;
devpriv->aiCount = 0;
transferDone:
writel(0, devpriv->las0 + LAS0_PACER_STOP);
writel(0, devpriv->las0 + LAS0_PACER);
writel(0, devpriv->las0 + LAS0_ADC_CONVERSION);
devpriv->intMask = 0;
writew(devpriv->intMask, devpriv->las0 + LAS0_IT);
if (devpriv->aiCount > 0) {
fifoStatus = readl(devpriv->las0 + LAS0_ADC);
ai_read_dregs(dev, s);
}
s->async->events |= COMEDI_CB_EOA;
comedi_event(dev, s);
status = readw(devpriv->las0 + LAS0_IT);
devpriv->intClearMask = status;
writew(devpriv->intClearMask, devpriv->las0 + LAS0_CLEAR);
readw(devpriv->las0 + LAS0_CLEAR);
fifoStatus = readl(devpriv->las0 + LAS0_ADC);
overrun = readl(devpriv->las0 + LAS0_OVERRUN) & 0xffff;
return IRQ_HANDLED;
}
static int rtd_ai_cmdtest(struct comedi_device *dev,
struct comedi_subdevice *s, struct comedi_cmd *cmd)
{
int err = 0;
int tmp;
err |= cfc_check_trigger_src(&cmd->start_src, TRIG_NOW);
err |= cfc_check_trigger_src(&cmd->scan_begin_src,
TRIG_TIMER | TRIG_EXT);
err |= cfc_check_trigger_src(&cmd->convert_src, TRIG_TIMER | TRIG_EXT);
err |= cfc_check_trigger_src(&cmd->scan_end_src, TRIG_COUNT);
err |= cfc_check_trigger_src(&cmd->stop_src, TRIG_COUNT | TRIG_NONE);
if (err)
return 1;
err |= cfc_check_trigger_is_unique(cmd->scan_begin_src);
err |= cfc_check_trigger_is_unique(cmd->convert_src);
err |= cfc_check_trigger_is_unique(cmd->stop_src);
if (err)
return 2;
err |= cfc_check_trigger_arg_is(&cmd->start_arg, 0);
if (cmd->scan_begin_src == TRIG_TIMER) {
if (1 == cmd->chanlist_len) {
if (cfc_check_trigger_arg_min(&cmd->scan_begin_arg,
RTD_MAX_SPEED_1)) {
rtd_ns_to_timer(&cmd->scan_begin_arg,
TRIG_ROUND_UP);
err |= -EINVAL;
}
if (cfc_check_trigger_arg_max(&cmd->scan_begin_arg,
RTD_MIN_SPEED_1)) {
rtd_ns_to_timer(&cmd->scan_begin_arg,
TRIG_ROUND_DOWN);
err |= -EINVAL;
}
} else {
if (cfc_check_trigger_arg_min(&cmd->scan_begin_arg,
RTD_MAX_SPEED)) {
rtd_ns_to_timer(&cmd->scan_begin_arg,
TRIG_ROUND_UP);
err |= -EINVAL;
}
if (cfc_check_trigger_arg_max(&cmd->scan_begin_arg,
RTD_MIN_SPEED)) {
rtd_ns_to_timer(&cmd->scan_begin_arg,
TRIG_ROUND_DOWN);
err |= -EINVAL;
}
}
} else {
err |= cfc_check_trigger_arg_max(&cmd->scan_begin_arg, 9);
}
if (cmd->convert_src == TRIG_TIMER) {
if (1 == cmd->chanlist_len) {
if (cfc_check_trigger_arg_min(&cmd->convert_arg,
RTD_MAX_SPEED_1)) {
rtd_ns_to_timer(&cmd->convert_arg,
TRIG_ROUND_UP);
err |= -EINVAL;
}
if (cfc_check_trigger_arg_max(&cmd->convert_arg,
RTD_MIN_SPEED_1)) {
rtd_ns_to_timer(&cmd->convert_arg,
TRIG_ROUND_DOWN);
err |= -EINVAL;
}
} else {
if (cfc_check_trigger_arg_min(&cmd->convert_arg,
RTD_MAX_SPEED)) {
rtd_ns_to_timer(&cmd->convert_arg,
TRIG_ROUND_UP);
err |= -EINVAL;
}
if (cfc_check_trigger_arg_max(&cmd->convert_arg,
RTD_MIN_SPEED)) {
rtd_ns_to_timer(&cmd->convert_arg,
TRIG_ROUND_DOWN);
err |= -EINVAL;
}
}
} else {
err |= cfc_check_trigger_arg_max(&cmd->convert_arg, 9);
}
if (cmd->stop_src == TRIG_COUNT) {
} else {
err |= cfc_check_trigger_arg_is(&cmd->stop_arg, 0);
}
if (err)
return 3;
if (cmd->chanlist_len > RTD_MAX_CHANLIST) {
cmd->chanlist_len = RTD_MAX_CHANLIST;
err++;
}
if (cmd->scan_begin_src == TRIG_TIMER) {
tmp = cmd->scan_begin_arg;
rtd_ns_to_timer(&cmd->scan_begin_arg,
cmd->flags & TRIG_ROUND_MASK);
if (tmp != cmd->scan_begin_arg)
err++;
}
if (cmd->convert_src == TRIG_TIMER) {
tmp = cmd->convert_arg;
rtd_ns_to_timer(&cmd->convert_arg,
cmd->flags & TRIG_ROUND_MASK);
if (tmp != cmd->convert_arg)
err++;
if (cmd->scan_begin_src == TRIG_TIMER
&& (cmd->scan_begin_arg
< (cmd->convert_arg * cmd->scan_end_arg))) {
cmd->scan_begin_arg =
cmd->convert_arg * cmd->scan_end_arg;
err++;
}
}
if (err)
return 4;
return 0;
}
static int rtd_ai_cmd(struct comedi_device *dev, struct comedi_subdevice *s)
{
struct rtdPrivate *devpriv = dev->private;
struct comedi_cmd *cmd = &s->async->cmd;
int timer;
writel(0, devpriv->las0 + LAS0_PACER_STOP);
writel(0, devpriv->las0 + LAS0_PACER);
writel(0, devpriv->las0 + LAS0_ADC_CONVERSION);
devpriv->intMask = 0;
writew(devpriv->intMask, devpriv->las0 + LAS0_IT);
writel(0, devpriv->las0 + LAS0_ADC_FIFO_CLEAR);
writel(0, devpriv->las0 + LAS0_OVERRUN);
rtd_load_channelgain_list(dev, cmd->chanlist_len, cmd->chanlist);
if (cmd->chanlist_len > 1) {
writel(0, devpriv->las0 + LAS0_PACER_START);
writel(1, devpriv->las0 + LAS0_BURST_START);
writel(2, devpriv->las0 + LAS0_ADC_CONVERSION);
} else {
writel(0, devpriv->las0 + LAS0_PACER_START);
writel(1, devpriv->las0 + LAS0_ADC_CONVERSION);
}
writel((devpriv->fifoLen / 2 - 1) & 0xffff, devpriv->las0 + LAS0_ACNT);
if (TRIG_TIMER == cmd->scan_begin_src) {
if (cmd->flags & TRIG_WAKE_EOS) {
devpriv->transCount = cmd->chanlist_len;
devpriv->flags |= SEND_EOS;
} else {
devpriv->transCount
=
(TRANS_TARGET_PERIOD * cmd->chanlist_len) /
cmd->scan_begin_arg;
if (devpriv->transCount < cmd->chanlist_len) {
devpriv->transCount = cmd->chanlist_len;
} else {
devpriv->transCount =
(devpriv->transCount +
cmd->chanlist_len - 1)
/ cmd->chanlist_len;
devpriv->transCount *= cmd->chanlist_len;
}
devpriv->flags |= SEND_EOS;
}
if (devpriv->transCount >= (devpriv->fifoLen / 2)) {
devpriv->transCount = 0;
devpriv->flags &= ~SEND_EOS;
} else {
writel((devpriv->transCount - 1) & 0xffff,
devpriv->las0 + LAS0_ACNT);
}
} else {
devpriv->transCount = 0;
devpriv->flags &= ~SEND_EOS;
}
writel(1, devpriv->las0 + LAS0_PACER_SELECT);
writel(1, devpriv->las0 + LAS0_ACNT_STOP_ENABLE);
switch (cmd->stop_src) {
case TRIG_COUNT:
devpriv->aiCount = cmd->stop_arg * cmd->chanlist_len;
if ((devpriv->transCount > 0)
&& (devpriv->transCount > devpriv->aiCount)) {
devpriv->transCount = devpriv->aiCount;
}
break;
case TRIG_NONE:
devpriv->aiCount = -1;
break;
}
switch (cmd->scan_begin_src) {
case TRIG_TIMER:
timer = rtd_ns_to_timer(&cmd->scan_begin_arg,
TRIG_ROUND_NEAREST);
writel(timer & 0xffffff, devpriv->las0 + LAS0_PCLK);
break;
case TRIG_EXT:
writel(1, devpriv->las0 + LAS0_PACER_START);
break;
}
switch (cmd->convert_src) {
case TRIG_TIMER:
if (cmd->chanlist_len > 1) {
timer = rtd_ns_to_timer(&cmd->convert_arg,
TRIG_ROUND_NEAREST);
writel(timer & 0x3ff, devpriv->las0 + LAS0_BCLK);
}
break;
case TRIG_EXT:
writel(2, devpriv->las0 + LAS0_BURST_START);
break;
}
devpriv->intClearMask = ~0;
writew(devpriv->intClearMask, devpriv->las0 + LAS0_CLEAR);
readw(devpriv->las0 + LAS0_CLEAR);
if (devpriv->transCount > 0) {
devpriv->intMask = IRQM_ADC_ABOUT_CNT;
writew(devpriv->intMask, devpriv->las0 + LAS0_IT);
} else {
devpriv->intMask = IRQM_ADC_ABOUT_CNT;
writew(devpriv->intMask, devpriv->las0 + LAS0_IT);
}
readl(devpriv->las0 + LAS0_PACER);
return 0;
}
static int rtd_ai_cancel(struct comedi_device *dev, struct comedi_subdevice *s)
{
struct rtdPrivate *devpriv = dev->private;
u32 overrun;
u16 status;
writel(0, devpriv->las0 + LAS0_PACER_STOP);
writel(0, devpriv->las0 + LAS0_PACER);
writel(0, devpriv->las0 + LAS0_ADC_CONVERSION);
devpriv->intMask = 0;
writew(devpriv->intMask, devpriv->las0 + LAS0_IT);
devpriv->aiCount = 0;
status = readw(devpriv->las0 + LAS0_IT);
overrun = readl(devpriv->las0 + LAS0_OVERRUN) & 0xffff;
return 0;
}
static int rtd_ao_winsn(struct comedi_device *dev,
struct comedi_subdevice *s, struct comedi_insn *insn,
unsigned int *data)
{
struct rtdPrivate *devpriv = dev->private;
int i;
int chan = CR_CHAN(insn->chanspec);
int range = CR_RANGE(insn->chanspec);
writew(range & 7, devpriv->las0 +
((chan == 0) ? LAS0_DAC1_CTRL : LAS0_DAC2_CTRL));
for (i = 0; i < insn->n; ++i) {
int val = data[i] << 3;
int stat = 0;
int ii;
if ((range > 1)
&& (data[i] < 2048)) {
val = (((int)data[i]) - 2048) << 3;
} else {
val = data[i] << 3;
}
writew(val, devpriv->las1 +
((chan == 0) ? LAS1_DAC1_FIFO : LAS1_DAC2_FIFO));
writew(0, devpriv->las0 +
((chan == 0) ? LAS0_DAC1 : LAS0_DAC2));
devpriv->aoValue[chan] = data[i];
for (ii = 0; ii < RTD_DAC_TIMEOUT; ++ii) {
stat = readl(devpriv->las0 + LAS0_ADC);
if (stat & ((0 == chan) ? FS_DAC1_NOT_EMPTY :
FS_DAC2_NOT_EMPTY))
break;
WAIT_QUIETLY;
}
if (ii >= RTD_DAC_TIMEOUT)
return -ETIMEDOUT;
}
return i;
}
static int rtd_ao_rinsn(struct comedi_device *dev,
struct comedi_subdevice *s, struct comedi_insn *insn,
unsigned int *data)
{
struct rtdPrivate *devpriv = dev->private;
int i;
int chan = CR_CHAN(insn->chanspec);
for (i = 0; i < insn->n; i++)
data[i] = devpriv->aoValue[chan];
return i;
}
static int rtd_dio_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct rtdPrivate *devpriv = dev->private;
if (data[0]) {
s->state &= ~data[0];
s->state |= data[0] & data[1];
writew(s->state & 0xff, devpriv->las0 + LAS0_DIO0);
}
data[1] = readw(devpriv->las0 + LAS0_DIO0) & 0xff;
return insn->n;
}
static int rtd_dio_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct rtdPrivate *devpriv = dev->private;
int chan = CR_CHAN(insn->chanspec);
switch (data[0]) {
case INSN_CONFIG_DIO_OUTPUT:
s->io_bits |= 1 << chan;
break;
case INSN_CONFIG_DIO_INPUT:
s->io_bits &= ~(1 << chan);
break;
case INSN_CONFIG_DIO_QUERY:
data[1] =
(s->io_bits & (1 << chan)) ? COMEDI_OUTPUT : COMEDI_INPUT;
return insn->n;
break;
default:
return -EINVAL;
}
devpriv->dioStatus = 0x01;
writew(devpriv->dioStatus, devpriv->las0 + LAS0_DIO_STATUS);
writew(s->io_bits & 0xff, devpriv->las0 + LAS0_DIO0_CTRL);
devpriv->dioStatus = 0x00;
writew(devpriv->dioStatus, devpriv->las0 + LAS0_DIO_STATUS);
return 1;
}
static void rtd_reset(struct comedi_device *dev)
{
struct rtdPrivate *devpriv = dev->private;
writel(0, devpriv->las0 + LAS0_BOARD_RESET);
udelay(100);
writel(0, devpriv->lcfg + LCFG_ITCSR);
devpriv->intMask = 0;
writew(devpriv->intMask, devpriv->las0 + LAS0_IT);
devpriv->intClearMask = ~0;
writew(devpriv->intClearMask, devpriv->las0 + LAS0_CLEAR);
readw(devpriv->las0 + LAS0_CLEAR);
}
static void rtd_init_board(struct comedi_device *dev)
{
struct rtdPrivate *devpriv = dev->private;
rtd_reset(dev);
writel(0, devpriv->las0 + LAS0_OVERRUN);
writel(0, devpriv->las0 + LAS0_CGT_CLEAR);
writel(0, devpriv->las0 + LAS0_ADC_FIFO_CLEAR);
writel(0, devpriv->las0 + LAS0_DAC1_RESET);
writel(0, devpriv->las0 + LAS0_DAC2_RESET);
devpriv->dioStatus = 0;
writew(devpriv->dioStatus, devpriv->las0 + LAS0_DIO_STATUS);
devpriv->utcCtrl[0] = (0 << 6) | 0x30;
devpriv->utcCtrl[1] = (1 << 6) | 0x30;
devpriv->utcCtrl[2] = (2 << 6) | 0x30;
devpriv->utcCtrl[3] = (3 << 6) | 0x00;
writeb(devpriv->utcCtrl[0], devpriv->las0 + LAS0_UTC_CTRL);
writeb(devpriv->utcCtrl[1], devpriv->las0 + LAS0_UTC_CTRL);
writeb(devpriv->utcCtrl[2], devpriv->las0 + LAS0_UTC_CTRL);
writeb(devpriv->utcCtrl[3], devpriv->las0 + LAS0_UTC_CTRL);
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
static const void *rtd_find_boardinfo(struct comedi_device *dev,
struct pci_dev *pcidev)
{
const struct rtdBoard *thisboard;
int i;
for (i = 0; i < ARRAY_SIZE(rtd520Boards); i++) {
thisboard = &rtd520Boards[i];
if (pcidev->device == thisboard->device_id)
return thisboard;
}
return NULL;
}
static int rtd_auto_attach(struct comedi_device *dev,
unsigned long context_unused)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
const struct rtdBoard *thisboard;
struct rtdPrivate *devpriv;
struct comedi_subdevice *s;
int ret;
thisboard = rtd_find_boardinfo(dev, pcidev);
if (!thisboard)
return -ENODEV;
dev->board_ptr = thisboard;
dev->board_name = thisboard->name;
devpriv = kzalloc(sizeof(*devpriv), GFP_KERNEL);
if (!devpriv)
return -ENOMEM;
dev->private = devpriv;
ret = comedi_pci_enable(pcidev, dev->board_name);
if (ret)
return ret;
dev->iobase = 1;
devpriv->las0 = ioremap_nocache(pci_resource_start(pcidev, 2),
pci_resource_len(pcidev, 2));
devpriv->las1 = ioremap_nocache(pci_resource_start(pcidev, 3),
pci_resource_len(pcidev, 3));
devpriv->lcfg = ioremap_nocache(pci_resource_start(pcidev, 0),
pci_resource_len(pcidev, 0));
if (!devpriv->las0 || !devpriv->las1 || !devpriv->lcfg)
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
s->range_table = thisboard->ai_range;
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
s->insn_write = rtd_ao_winsn;
s->insn_read = rtd_ao_rinsn;
s = &dev->subdevices[2];
s->type = COMEDI_SUBD_DIO;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE;
s->n_chan = 8;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = rtd_dio_insn_bits;
s->insn_config = rtd_dio_insn_config;
s = &dev->subdevices[3];
s->type = COMEDI_SUBD_COUNTER;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE;
s->n_chan = 3;
s->maxdata = 0xffff;
rtd_init_board(dev);
ret = rtd520_probe_fifo_depth(dev);
if (ret < 0)
return ret;
devpriv->fifoLen = ret;
if (dev->irq)
writel(ICS_PIE | ICS_PLIE, devpriv->lcfg + LCFG_ITCSR);
dev_info(dev->class_dev, "%s attached\n", dev->board_name);
return 0;
}
static void rtd_detach(struct comedi_device *dev)
{
struct rtdPrivate *devpriv = dev->private;
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
if (devpriv) {
if (devpriv->las0 && devpriv->lcfg)
rtd_reset(dev);
if (dev->irq) {
writel(readl(devpriv->lcfg + LCFG_ITCSR) &
~(ICS_PLIE | ICS_DMA0_E | ICS_DMA1_E),
devpriv->lcfg + LCFG_ITCSR);
free_irq(dev->irq, dev);
}
if (devpriv->las0)
iounmap(devpriv->las0);
if (devpriv->las1)
iounmap(devpriv->las1);
if (devpriv->lcfg)
iounmap(devpriv->lcfg);
}
if (pcidev) {
if (dev->iobase)
comedi_pci_disable(pcidev);
}
}
static int rtd520_pci_probe(struct pci_dev *dev,
const struct pci_device_id *ent)
{
return comedi_pci_auto_config(dev, &rtd520_driver);
}
static void rtd520_pci_remove(struct pci_dev *dev)
{
comedi_pci_auto_unconfig(dev);
}
