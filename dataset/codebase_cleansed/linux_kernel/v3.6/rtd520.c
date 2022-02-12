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
printk(KERN_INFO "\ncomedi: %s: failed to probe fifo size.\n",
DRV_NAME);
return -EIO;
}
writel(0, devpriv->las0 + LAS0_ADC_FIFO_CLEAR);
if (fifo_size != 0x400 && fifo_size != 0x2000) {
printk
(KERN_INFO "\ncomedi: %s: unexpected fifo size of %i, expected 1024 or 8192.\n",
DRV_NAME, fifo_size);
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
if (ii >= RTD_ADC_TIMEOUT) {
DPRINTK
("rtd520: Error: ADC never finished! FifoStatus=0x%x\n",
stat ^ 0x6666);
return -ETIMEDOUT;
}
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
#if 0
if (!(readl(devpriv->las0 + LAS0_ADC) & FS_ADC_NOT_EMPTY)) {
DPRINTK("comedi: READ OOPS on %d of %d\n", ii + 1,
count);
break;
}
#endif
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
void abort_dma(struct comedi_device *dev, unsigned int channel)
{
struct rtdPrivate *devpriv = dev->private;
unsigned long dma_cs_addr;
uint8_t status;
unsigned int ii;
dma_cs_addr = (unsigned long)devpriv->lcfg
+ ((channel == 0) ? LCFG_DMACSR0 : LCFG_DMACSR1);
status = readb(dma_cs_addr);
if ((status & PLX_DMA_EN_BIT) == 0) {
DPRINTK("rtd520: AbortDma on non-active channel %d (0x%x)\n",
channel, status);
goto abortDmaExit;
}
for (ii = 0; (status & PLX_DMA_DONE_BIT) && ii < RTD_DMA_TIMEOUT; ii++) {
WAIT_QUIETLY;
status = readb(dma_cs_addr);
}
if (status & PLX_DMA_DONE_BIT) {
printk("rtd520: Timeout waiting for dma %i done clear\n",
channel);
goto abortDmaExit;
}
writeb(0, dma_cs_addr);
udelay(1);
writeb(PLX_DMA_ABORT_BIT, dma_cs_addr);
status = readb(dma_cs_addr);
for (ii = 0;
(status & PLX_DMA_DONE_BIT) == 0 && ii < RTD_DMA_TIMEOUT; ii++) {
status = readb(dma_cs_addr);
WAIT_QUIETLY;
}
if ((status & PLX_DMA_DONE_BIT) == 0) {
printk("rtd520: Timeout waiting for dma %i done set\n",
channel);
}
abortDmaExit:
}
static irqreturn_t rtd_interrupt(int irq,
void *d)
{
struct comedi_device *dev = d;
struct comedi_subdevice *s = dev->subdevices + 0;
struct rtdPrivate *devpriv = dev->private;
u32 overrun;
u16 status;
u16 fifoStatus;
if (!dev->attached)
return IRQ_NONE;
devpriv->intCount++;
fifoStatus = readl(devpriv->las0 + LAS0_ADC);
if (!(fifoStatus & FS_ADC_NOT_FULL)) {
DPRINTK("rtd520: FIFO full! fifo_status=0x%x\n", (fifoStatus ^ 0x6666) & 0x7777);
goto abortTransfer;
}
#ifdef USE_DMA
if (devpriv->flags & DMA0_ACTIVE) {
u32 istatus = readl(devpriv->lcfg + LCFG_ITCSR);
if (istatus & ICS_DMA0_A) {
if (ai_process_dma(dev, s) < 0) {
DPRINTK
("rtd520: comedi read buffer overflow (DMA) with %ld to go!\n",
devpriv->aiCount);
devpriv->dma0Control &= ~PLX_DMA_START_BIT;
devpriv->dma0Control |= PLX_CLEAR_DMA_INTR_BIT;
writeb(devpriv->dma0Control,
devpriv->lcfg + LCFG_DMACSR0);
goto abortTransfer;
}
devpriv->dma0Control &= ~PLX_DMA_START_BIT;
devpriv->dma0Control |= PLX_CLEAR_DMA_INTR_BIT;
writeb(devpriv->dma0Control,
devpriv->lcfg + LCFG_DMACSR0);
if (0 == devpriv->aiCount) {
DPRINTK("rtd520: Samples Done (DMA).\n");
goto transferDone;
}
comedi_event(dev, s);
} else {
}
}
#endif
status = readw(devpriv->las0 + LAS0_IT);
if (0 == status)
return IRQ_HANDLED;
if (status & IRQM_ADC_ABOUT_CNT) {
if (!(fifoStatus & FS_ADC_HEMPTY)) {
if (ai_read_n(dev, s, devpriv->fifoLen / 2) < 0) {
DPRINTK
("rtd520: comedi read buffer overflow (1/2FIFO) with %ld to go!\n",
devpriv->aiCount);
goto abortTransfer;
}
if (0 == devpriv->aiCount) {
DPRINTK("rtd520: Samples Done (1/2). fifo_status was 0x%x\n", (fifoStatus ^ 0x6666) & 0x7777);
goto transferDone;
}
comedi_event(dev, s);
} else if (devpriv->transCount > 0) {
if (fifoStatus & FS_ADC_NOT_EMPTY) {
if (ai_read_n(dev, s, devpriv->transCount) < 0) {
DPRINTK
("rtd520: comedi read buffer overflow (N) with %ld to go!\n",
devpriv->aiCount);
goto abortTransfer;
}
if (0 == devpriv->aiCount) {
DPRINTK
("rtd520: Samples Done (N). fifo_status was 0x%x\n",
(fifoStatus ^ 0x6666) & 0x7777);
goto transferDone;
}
comedi_event(dev, s);
}
} else {
DPRINTK
("rtd520: Sample int. Wait for 1/2. fifo_status 0x%x\n",
(fifoStatus ^ 0x6666) & 0x7777);
}
} else {
DPRINTK("rtd520: unknown interrupt source!\n");
}
overrun = readl(devpriv->las0 + LAS0_OVERRUN) & 0xffff;
if (overrun) {
DPRINTK
("rtd520: Interrupt overrun with %ld to go! over_status=0x%x\n",
devpriv->aiCount, overrun);
goto abortTransfer;
}
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
#ifdef USE_DMA
if (devpriv->flags & DMA0_ACTIVE) {
writel(readl(devpriv->lcfg + LCFG_ITCSR) & ~ICS_DMA0_E,
devpriv->lcfg + LCFG_ITCSR);
abort_dma(dev, 0);
devpriv->flags &= ~DMA0_ACTIVE;
if (devpriv->aiCount > 0) {
DPRINTK("rtd520: Lost DMA data! %ld remain\n",
devpriv->aiCount);
}
}
#endif
if (devpriv->aiCount > 0) {
fifoStatus = readl(devpriv->las0 + LAS0_ADC);
DPRINTK("rtd520: Finishing up. %ld remain, fifoStat=%x\n", devpriv->aiCount, (fifoStatus ^ 0x6666) & 0x7777);
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
DPRINTK
("rtd520: Acquisition complete. %ld ints, intStat=%x, overStat=%x\n",
devpriv->intCount, status, overrun);
return IRQ_HANDLED;
}
static int rtd_ai_cmdtest(struct comedi_device *dev,
struct comedi_subdevice *s, struct comedi_cmd *cmd)
{
int err = 0;
int tmp;
tmp = cmd->start_src;
cmd->start_src &= TRIG_NOW;
if (!cmd->start_src || tmp != cmd->start_src)
err++;
tmp = cmd->scan_begin_src;
cmd->scan_begin_src &= TRIG_TIMER | TRIG_EXT;
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
if (cmd->scan_begin_src != TRIG_TIMER &&
cmd->scan_begin_src != TRIG_EXT) {
err++;
}
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
if (cmd->scan_begin_src == TRIG_TIMER) {
if (1 == cmd->chanlist_len) {
if (cmd->scan_begin_arg < RTD_MAX_SPEED_1) {
cmd->scan_begin_arg = RTD_MAX_SPEED_1;
rtd_ns_to_timer(&cmd->scan_begin_arg,
TRIG_ROUND_UP);
err++;
}
if (cmd->scan_begin_arg > RTD_MIN_SPEED_1) {
cmd->scan_begin_arg = RTD_MIN_SPEED_1;
rtd_ns_to_timer(&cmd->scan_begin_arg,
TRIG_ROUND_DOWN);
err++;
}
} else {
if (cmd->scan_begin_arg < RTD_MAX_SPEED) {
cmd->scan_begin_arg = RTD_MAX_SPEED;
rtd_ns_to_timer(&cmd->scan_begin_arg,
TRIG_ROUND_UP);
err++;
}
if (cmd->scan_begin_arg > RTD_MIN_SPEED) {
cmd->scan_begin_arg = RTD_MIN_SPEED;
rtd_ns_to_timer(&cmd->scan_begin_arg,
TRIG_ROUND_DOWN);
err++;
}
}
} else {
if (cmd->scan_begin_arg > 9) {
cmd->scan_begin_arg = 9;
err++;
}
}
if (cmd->convert_src == TRIG_TIMER) {
if (1 == cmd->chanlist_len) {
if (cmd->convert_arg < RTD_MAX_SPEED_1) {
cmd->convert_arg = RTD_MAX_SPEED_1;
rtd_ns_to_timer(&cmd->convert_arg,
TRIG_ROUND_UP);
err++;
}
if (cmd->convert_arg > RTD_MIN_SPEED_1) {
cmd->convert_arg = RTD_MIN_SPEED_1;
rtd_ns_to_timer(&cmd->convert_arg,
TRIG_ROUND_DOWN);
err++;
}
} else {
if (cmd->convert_arg < RTD_MAX_SPEED) {
cmd->convert_arg = RTD_MAX_SPEED;
rtd_ns_to_timer(&cmd->convert_arg,
TRIG_ROUND_UP);
err++;
}
if (cmd->convert_arg > RTD_MIN_SPEED) {
cmd->convert_arg = RTD_MIN_SPEED;
rtd_ns_to_timer(&cmd->convert_arg,
TRIG_ROUND_DOWN);
err++;
}
}
} else {
if (cmd->convert_arg > 9) {
cmd->convert_arg = 9;
err++;
}
}
#if 0
if (cmd->scan_end_arg != cmd->chanlist_len) {
cmd->scan_end_arg = cmd->chanlist_len;
err++;
}
#endif
if (cmd->stop_src == TRIG_COUNT) {
} else {
if (cmd->stop_arg != 0) {
cmd->stop_arg = 0;
err++;
}
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
#ifdef USE_DMA
if (devpriv->flags & DMA0_ACTIVE) {
writel(readl(devpriv->lcfg + LCFG_ITCSR) & ~ICS_DMA0_E,
devpriv->lcfg + LCFG_ITCSR);
abort_dma(dev, 0);
devpriv->flags &= ~DMA0_ACTIVE;
if (readl(devpriv->lcfg + LCFG_ITCSR) & ICS_DMA0_A) {
devpriv->dma0Control = PLX_CLEAR_DMA_INTR_BIT;
writeb(devpriv->dma0Control,
devpriv->lcfg + LCFG_DMACSR0);
}
}
writel(0, devpriv->las0 + LAS0_DMA0_RESET);
#endif
writel(0, devpriv->las0 + LAS0_ADC_FIFO_CLEAR);
writel(0, devpriv->las0 + LAS0_OVERRUN);
devpriv->intCount = 0;
if (!dev->irq) {
DPRINTK("rtd520: ERROR! No interrupt available!\n");
return -ENXIO;
}
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
DPRINTK
("rtd520: scanLen=%d transferCount=%d fifoLen=%d\n scanTime(ns)=%d flags=0x%x\n",
cmd->chanlist_len, devpriv->transCount, devpriv->fifoLen,
cmd->scan_begin_arg, devpriv->flags);
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
default:
DPRINTK("rtd520: Warning! ignoring stop_src mode %d\n",
cmd->stop_src);
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
default:
DPRINTK("rtd520: Warning! ignoring scan_begin_src mode %d\n",
cmd->scan_begin_src);
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
default:
DPRINTK("rtd520: Warning! ignoring convert_src mode %d\n",
cmd->convert_src);
}
devpriv->intClearMask = ~0;
writew(devpriv->intClearMask, devpriv->las0 + LAS0_CLEAR);
readw(devpriv->las0 + LAS0_CLEAR);
if (devpriv->transCount > 0) {
devpriv->intMask = IRQM_ADC_ABOUT_CNT;
writew(devpriv->intMask, devpriv->las0 + LAS0_IT);
DPRINTK("rtd520: Transferring every %d\n", devpriv->transCount);
} else {
#ifdef USE_DMA
devpriv->flags |= DMA0_ACTIVE;
devpriv->dma0Offset = 0;
writel(DMA_MODE_BITS, devpriv->lcfg + LCFG_DMAMODE0);
writel(devpriv->dma0Chain[DMA_CHAIN_COUNT - 1].next,
devpriv->lcfg + LCFG_DMADPR0);
writel(DMAS_ADFIFO_HALF_FULL, devpriv->las0 + LAS0_DMA0_SRC);
writel(readl(devpriv->lcfg + LCFG_ITCSR) | ICS_DMA0_E,
devpriv->lcfg + LCFG_ITCSR);
devpriv->dma0Control = PLX_DMA_EN_BIT;
writeb(devpriv->dma0Control,
devpriv->lcfg + LCFG_DMACSR0);
devpriv->dma0Control |= PLX_DMA_START_BIT;
writeb(devpriv->dma0Control,
devpriv->lcfg + LCFG_DMACSR0);
DPRINTK("rtd520: Using DMA0 transfers. plxInt %x RtdInt %x\n",
readl(devpriv->lcfg + LCFG_ITCSR), devpriv->intMask);
#else
devpriv->intMask = IRQM_ADC_ABOUT_CNT;
writew(devpriv->intMask, devpriv->las0 + LAS0_IT);
DPRINTK("rtd520: Transferring every 1/2 FIFO\n");
#endif
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
#ifdef USE_DMA
if (devpriv->flags & DMA0_ACTIVE) {
writel(readl(devpriv->lcfg + LCFG_ITCSR) & ~ICS_DMA0_E,
devpriv->lcfg + LCFG_ITCSR);
abort_dma(dev, 0);
devpriv->flags &= ~DMA0_ACTIVE;
}
#endif
status = readw(devpriv->las0 + LAS0_IT);
overrun = readl(devpriv->las0 + LAS0_OVERRUN) & 0xffff;
DPRINTK
("rtd520: Acquisition canceled. %ld ints, intStat=%x, overStat=%x\n",
devpriv->intCount, status, overrun);
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
DPRINTK
("comedi: rtd520 DAC chan=%d range=%d writing %d as 0x%x\n",
chan, range, data[i], val);
writew(val, devpriv->las1 +
((chan == 0) ? LAS1_DAC1_FIFO : LAS1_DAC2_FIFO));
writew(0, devpriv->las0 + ((chan == 0) ? LAS0_DAC1 : LAS0_DAC2));
devpriv->aoValue[chan] = data[i];
for (ii = 0; ii < RTD_DAC_TIMEOUT; ++ii) {
stat = readl(devpriv->las0 + LAS0_ADC);
if (stat & ((0 == chan) ? FS_DAC1_NOT_EMPTY :
FS_DAC2_NOT_EMPTY))
break;
WAIT_QUIETLY;
}
if (ii >= RTD_DAC_TIMEOUT) {
DPRINTK
("rtd520: Error: DAC never finished! FifoStatus=0x%x\n",
stat ^ 0x6666);
return -ETIMEDOUT;
}
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
DPRINTK("rtd520: port_0_direction=0x%x (1 means out)\n", s->io_bits);
devpriv->dioStatus = 0x01;
writew(devpriv->dioStatus, devpriv->las0 + LAS0_DIO_STATUS);
writew(s->io_bits & 0xff, devpriv->las0 + LAS0_DIO0_CTRL);
devpriv->dioStatus = 0x00;
writew(devpriv->dioStatus, devpriv->las0 + LAS0_DIO_STATUS);
return 1;
}
static struct pci_dev *rtd_find_pci(struct comedi_device *dev,
struct comedi_devconfig *it)
{
const struct rtdBoard *thisboard;
struct pci_dev *pcidev = NULL;
int bus = it->options[0];
int slot = it->options[1];
int i;
for_each_pci_dev(pcidev) {
if (pcidev->vendor != PCI_VENDOR_ID_RTD)
continue;
if (bus || slot) {
if (pcidev->bus->number != bus ||
PCI_SLOT(pcidev->devfn) != slot)
continue;
}
for (i = 0; i < ARRAY_SIZE(rtd520Boards); i++) {
thisboard = &rtd520Boards[i];
if (pcidev->device == thisboard->device_id) {
dev->board_ptr = thisboard;
return pcidev;
}
}
}
dev_warn(dev->class_dev,
"no supported board found! (req. bus/slot: %d/%d)\n",
bus, slot);
return NULL;
}
static int rtd_attach(struct comedi_device *dev, struct comedi_devconfig *it)
{
const struct rtdBoard *thisboard;
struct rtdPrivate *devpriv;
struct pci_dev *pcidev;
struct comedi_subdevice *s;
resource_size_t pci_base;
int ret;
#ifdef USE_DMA
int index;
#endif
printk(KERN_INFO "comedi%d: rtd520 attaching.\n", dev->minor);
#if defined(CONFIG_COMEDI_DEBUG) && defined(USE_DMA)
if (0 == comedi_debug)
comedi_debug = 1;
#endif
if (alloc_private(dev, sizeof(struct rtdPrivate)) < 0)
return -ENOMEM;
devpriv = dev->private;
pcidev = rtd_find_pci(dev, it);
if (!pcidev)
return -EIO;
comedi_set_hw_dev(dev, &pcidev->dev);
thisboard = comedi_board(dev);
dev->board_name = thisboard->name;
ret = comedi_pci_enable(pcidev, DRV_NAME);
if (ret < 0) {
printk(KERN_INFO "Failed to enable PCI device and request regions.\n");
return ret;
}
dev->iobase = 1;
pci_base = pci_resource_start(pcidev, LAS0_PCIINDEX);
devpriv->las0 = ioremap_nocache(pci_base, LAS0_PCISIZE);
pci_base = pci_resource_start(pcidev, LAS1_PCIINDEX);
devpriv->las1 = ioremap_nocache(pci_base, LAS1_PCISIZE);
pci_base = pci_resource_start(pcidev, LCFG_PCIINDEX);
devpriv->lcfg = ioremap_nocache(pci_base, LCFG_PCISIZE);
if (!devpriv->las0 || !devpriv->las1 || !devpriv->lcfg)
return -ENOMEM;
{
unsigned char pci_latency;
u16 revision;
pci_read_config_word(pcidev, PCI_REVISION_ID,
&revision);
DPRINTK("%s: PCI revision %d.\n", dev->board_name, revision);
pci_read_config_byte(pcidev,
PCI_LATENCY_TIMER, &pci_latency);
if (pci_latency < 32) {
printk(KERN_INFO "%s: PCI latency changed from %d to %d\n",
dev->board_name, pci_latency, 32);
pci_write_config_byte(pcidev,
PCI_LATENCY_TIMER, 32);
} else {
DPRINTK("rtd520: PCI latency = %d\n", pci_latency);
}
}
printk(KERN_INFO "%s:", dev->board_name);
ret = comedi_alloc_subdevices(dev, 4);
if (ret)
return ret;
s = dev->subdevices + 0;
dev->read_subdev = s;
s->type = COMEDI_SUBD_AI;
s->subdev_flags =
SDF_READABLE | SDF_GROUND | SDF_COMMON | SDF_DIFF | SDF_CMD_READ;
s->n_chan = thisboard->aiChans;
s->maxdata = (1 << thisboard->aiBits) - 1;
if (thisboard->aiMaxGain <= 32)
s->range_table = &rtd_ai_7520_range;
else
s->range_table = &rtd_ai_4520_range;
s->len_chanlist = RTD_MAX_CHANLIST;
s->insn_read = rtd_ai_rinsn;
s->do_cmd = rtd_ai_cmd;
s->do_cmdtest = rtd_ai_cmdtest;
s->cancel = rtd_ai_cancel;
s = dev->subdevices + 1;
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = 2;
s->maxdata = (1 << thisboard->aiBits) - 1;
s->range_table = &rtd_ao_range;
s->insn_write = rtd_ao_winsn;
s->insn_read = rtd_ao_rinsn;
s = dev->subdevices + 2;
s->type = COMEDI_SUBD_DIO;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE;
s->n_chan = 8;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = rtd_dio_insn_bits;
s->insn_config = rtd_dio_insn_config;
s = dev->subdevices + 3;
s->type = COMEDI_SUBD_COUNTER;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE;
s->n_chan = 3;
s->maxdata = 0xffff;
writel(0, devpriv->las0 + LAS0_BOARD_RESET);
udelay(100);
writel(0, devpriv->lcfg + LCFG_ITCSR);
devpriv->intMask = 0;
writew(devpriv->intMask, devpriv->las0 + LAS0_IT);
devpriv->intClearMask = ~0;
writew(devpriv->intClearMask, devpriv->las0 + LAS0_CLEAR);
readw(devpriv->las0 + LAS0_CLEAR);
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
ret = request_irq(pcidev->irq, rtd_interrupt,
IRQF_SHARED, DRV_NAME, dev);
if (ret < 0) {
printk("Could not get interrupt! (%u)\n",
pcidev->irq);
return ret;
}
dev->irq = pcidev->irq;
printk(KERN_INFO "( irq=%u )", dev->irq);
ret = rtd520_probe_fifo_depth(dev);
if (ret < 0)
return ret;
devpriv->fifoLen = ret;
printk("( fifoLen=%d )", devpriv->fifoLen);
#ifdef USE_DMA
if (dev->irq > 0) {
printk("( DMA buff=%d )\n", DMA_CHAIN_COUNT);
devpriv->dma0Offset = 0;
for (index = 0; index < DMA_CHAIN_COUNT; index++) {
devpriv->dma0Buff[index] =
pci_alloc_consistent(pcidev,
sizeof(u16) *
devpriv->fifoLen / 2,
&devpriv->
dma0BuffPhysAddr[index]);
if (devpriv->dma0Buff[index] == NULL) {
ret = -ENOMEM;
goto rtd_attach_die_error;
}
}
devpriv->dma0Chain =
pci_alloc_consistent(pcidev,
sizeof(struct plx_dma_desc) *
DMA_CHAIN_COUNT,
&devpriv->dma0ChainPhysAddr);
for (index = 0; index < DMA_CHAIN_COUNT; index++) {
devpriv->dma0Chain[index].pci_start_addr =
devpriv->dma0BuffPhysAddr[index];
devpriv->dma0Chain[index].local_start_addr =
DMALADDR_ADC;
devpriv->dma0Chain[index].transfer_size =
sizeof(u16) * devpriv->fifoLen / 2;
devpriv->dma0Chain[index].next =
(devpriv->dma0ChainPhysAddr + ((index +
1) %
(DMA_CHAIN_COUNT))
* sizeof(devpriv->dma0Chain[0]))
| DMA_TRANSFER_BITS;
}
if (devpriv->dma0Chain == NULL) {
ret = -ENOMEM;
goto rtd_attach_die_error;
}
writel(DMA_MODE_BITS, devpriv->lcfg + LCFG_DMAMODE0);
writel(DMAS_ADFIFO_HALF_FULL, devpriv->las0 + LAS0_DMA0_SRC);
} else {
printk(KERN_INFO "( no IRQ->no DMA )");
}
#endif
if (dev->irq)
writel(ICS_PIE | ICS_PLIE, devpriv->lcfg + LCFG_ITCSR);
printk("\ncomedi%d: rtd520 driver attached.\n", dev->minor);
return 1;
}
static void rtd_detach(struct comedi_device *dev)
{
struct rtdPrivate *devpriv = dev->private;
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
#ifdef USE_DMA
int index;
#endif
if (devpriv) {
#ifdef USE_DMA
if (devpriv->lcfg) {
devpriv->dma0Control = 0;
devpriv->dma1Control = 0;
writeb(devpriv->dma0Control,
devpriv->lcfg + LCFG_DMACSR0);
writeb(devpriv->dma1Control,
devpriv->lcfg + LCFG_DMACSR1);
writel(ICS_PIE | ICS_PLIE, devpriv->lcfg + LCFG_ITCSR);
}
#endif
if (devpriv->las0) {
writel(0, devpriv->las0 + LAS0_BOARD_RESET);
devpriv->intMask = 0;
writew(devpriv->intMask, devpriv->las0 + LAS0_IT);
devpriv->intClearMask = ~0;
writew(devpriv->intClearMask,
devpriv->las0 + LAS0_CLEAR);
readw(devpriv->las0 + LAS0_CLEAR);
}
#ifdef USE_DMA
for (index = 0; index < DMA_CHAIN_COUNT; index++) {
if (NULL != devpriv->dma0Buff[index]) {
pci_free_consistent(pcidev,
sizeof(u16) *
devpriv->fifoLen / 2,
devpriv->dma0Buff[index],
devpriv->
dma0BuffPhysAddr[index]);
devpriv->dma0Buff[index] = NULL;
}
}
if (NULL != devpriv->dma0Chain) {
pci_free_consistent(pcidev,
sizeof(struct plx_dma_desc) *
DMA_CHAIN_COUNT, devpriv->dma0Chain,
devpriv->dma0ChainPhysAddr);
devpriv->dma0Chain = NULL;
}
#endif
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
pci_dev_put(pcidev);
}
}
static int __devinit rtd520_pci_probe(struct pci_dev *dev,
const struct pci_device_id *ent)
{
return comedi_pci_auto_config(dev, &rtd520_driver);
}
static void __devexit rtd520_pci_remove(struct pci_dev *dev)
{
comedi_pci_auto_unconfig(dev);
}
