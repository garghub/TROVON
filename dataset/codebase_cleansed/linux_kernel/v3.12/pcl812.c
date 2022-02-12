static int pcl812_ai_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct pcl812_private *devpriv = dev->private;
int n;
int timeout, hi;
outb(devpriv->mode_reg_int | 1, dev->iobase + PCL812_MODE);
setup_range_channel(dev, s, insn->chanspec, 1);
for (n = 0; n < insn->n; n++) {
outb(255, dev->iobase + PCL812_SOFTTRIG);
udelay(5);
timeout = 50;
while (timeout--) {
hi = inb(dev->iobase + PCL812_AD_HI);
if (!(hi & PCL812_DRDY))
goto conv_finish;
udelay(1);
}
printk
("comedi%d: pcl812: (%s at 0x%lx) A/D insn read timeout\n",
dev->minor, dev->board_name, dev->iobase);
outb(devpriv->mode_reg_int | 0, dev->iobase + PCL812_MODE);
return -ETIME;
conv_finish:
data[n] = ((hi & 0xf) << 8) | inb(dev->iobase + PCL812_AD_LO);
}
outb(devpriv->mode_reg_int | 0, dev->iobase + PCL812_MODE);
return n;
}
static int acl8216_ai_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
int n;
int timeout;
outb(1, dev->iobase + PCL812_MODE);
setup_range_channel(dev, s, insn->chanspec, 1);
for (n = 0; n < insn->n; n++) {
outb(255, dev->iobase + PCL812_SOFTTRIG);
udelay(5);
timeout = 50;
while (timeout--) {
if (!(inb(dev->iobase + ACL8216_STATUS) & ACL8216_DRDY))
goto conv_finish;
udelay(1);
}
printk
("comedi%d: pcl812: (%s at 0x%lx) A/D insn read timeout\n",
dev->minor, dev->board_name, dev->iobase);
outb(0, dev->iobase + PCL812_MODE);
return -ETIME;
conv_finish:
data[n] =
(inb(dev->iobase +
PCL812_AD_HI) << 8) | inb(dev->iobase + PCL812_AD_LO);
}
outb(0, dev->iobase + PCL812_MODE);
return n;
}
static int pcl812_ao_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct pcl812_private *devpriv = dev->private;
int chan = CR_CHAN(insn->chanspec);
int i;
for (i = 0; i < insn->n; i++) {
outb((data[i] & 0xff),
dev->iobase + (chan ? PCL812_DA2_LO : PCL812_DA1_LO));
outb((data[i] >> 8) & 0x0f,
dev->iobase + (chan ? PCL812_DA2_HI : PCL812_DA1_HI));
devpriv->ao_readback[chan] = data[i];
}
return i;
}
static int pcl812_ao_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct pcl812_private *devpriv = dev->private;
int chan = CR_CHAN(insn->chanspec);
int i;
for (i = 0; i < insn->n; i++)
data[i] = devpriv->ao_readback[chan];
return i;
}
static int pcl812_di_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
data[1] = inb(dev->iobase + PCL812_DI_LO);
data[1] |= inb(dev->iobase + PCL812_DI_HI) << 8;
return insn->n;
}
static int pcl812_do_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
if (data[0]) {
s->state &= ~data[0];
s->state |= data[0] & data[1];
outb(s->state & 0xff, dev->iobase + PCL812_DO_LO);
outb((s->state >> 8), dev->iobase + PCL812_DO_HI);
}
data[1] = s->state;
return insn->n;
}
static int pcl812_ai_cmdtest(struct comedi_device *dev,
struct comedi_subdevice *s, struct comedi_cmd *cmd)
{
const struct pcl812_board *board = comedi_board(dev);
struct pcl812_private *devpriv = dev->private;
int err = 0;
unsigned int flags;
int tmp, divisor1, divisor2;
err |= cfc_check_trigger_src(&cmd->start_src, TRIG_NOW);
err |= cfc_check_trigger_src(&cmd->scan_begin_src, TRIG_FOLLOW);
if (devpriv->use_ext_trg)
flags = TRIG_EXT;
else
flags = TRIG_TIMER;
err |= cfc_check_trigger_src(&cmd->convert_src, flags);
err |= cfc_check_trigger_src(&cmd->scan_end_src, TRIG_COUNT);
err |= cfc_check_trigger_src(&cmd->stop_src, TRIG_COUNT | TRIG_NONE);
if (err)
return 1;
err |= cfc_check_trigger_is_unique(cmd->stop_src);
if (err)
return 2;
err |= cfc_check_trigger_arg_is(&cmd->start_arg, 0);
err |= cfc_check_trigger_arg_is(&cmd->scan_begin_arg, 0);
if (cmd->convert_src == TRIG_TIMER)
err |= cfc_check_trigger_arg_min(&cmd->convert_arg,
board->ai_ns_min);
else
err |= cfc_check_trigger_arg_is(&cmd->convert_arg, 0);
err |= cfc_check_trigger_arg_min(&cmd->chanlist_len, 1);
err |= cfc_check_trigger_arg_max(&cmd->chanlist_len, MAX_CHANLIST_LEN);
err |= cfc_check_trigger_arg_is(&cmd->scan_end_arg, cmd->chanlist_len);
if (cmd->stop_src == TRIG_COUNT)
err |= cfc_check_trigger_arg_min(&cmd->stop_arg, 1);
else
err |= cfc_check_trigger_arg_is(&cmd->stop_arg, 0);
if (err)
return 3;
if (cmd->convert_src == TRIG_TIMER) {
tmp = cmd->convert_arg;
i8253_cascade_ns_to_timer(board->i8254_osc_base, &divisor1,
&divisor2, &cmd->convert_arg,
cmd->flags & TRIG_ROUND_MASK);
if (cmd->convert_arg < board->ai_ns_min)
cmd->convert_arg = board->ai_ns_min;
if (tmp != cmd->convert_arg)
err++;
}
if (err)
return 4;
return 0;
}
static int pcl812_ai_cmd(struct comedi_device *dev, struct comedi_subdevice *s)
{
const struct pcl812_board *board = comedi_board(dev);
struct pcl812_private *devpriv = dev->private;
unsigned int divisor1 = 0, divisor2 = 0, i, dma_flags, bytes;
struct comedi_cmd *cmd = &s->async->cmd;
if (cmd->start_src != TRIG_NOW)
return -EINVAL;
if (cmd->scan_begin_src != TRIG_FOLLOW)
return -EINVAL;
if (devpriv->use_ext_trg) {
if (cmd->convert_src != TRIG_EXT)
return -EINVAL;
} else {
if (cmd->convert_src != TRIG_TIMER)
return -EINVAL;
}
if (cmd->scan_end_src != TRIG_COUNT)
return -EINVAL;
if (cmd->scan_end_arg != cmd->chanlist_len)
return -EINVAL;
if (cmd->chanlist_len > MAX_CHANLIST_LEN)
return -EINVAL;
if (cmd->convert_src == TRIG_TIMER) {
if (cmd->convert_arg < board->ai_ns_min)
cmd->convert_arg = board->ai_ns_min;
i8253_cascade_ns_to_timer(board->i8254_osc_base,
&divisor1, &divisor2,
&cmd->convert_arg,
cmd->flags & TRIG_ROUND_MASK);
}
start_pacer(dev, -1, 0, 0);
devpriv->ai_n_chan = cmd->chanlist_len;
memcpy(devpriv->ai_chanlist, cmd->chanlist,
sizeof(unsigned int) * cmd->scan_end_arg);
setup_range_channel(dev, s, devpriv->ai_chanlist[0], 1);
if (devpriv->dma) {
devpriv->ai_dma = 1;
for (i = 1; i < devpriv->ai_n_chan; i++)
if (devpriv->ai_chanlist[0] != devpriv->ai_chanlist[i]) {
devpriv->ai_dma = 0;
break;
}
} else
devpriv->ai_dma = 0;
devpriv->ai_flags = cmd->flags;
devpriv->ai_data_len = s->async->prealloc_bufsz;
devpriv->ai_data = s->async->prealloc_buf;
if (cmd->stop_src == TRIG_COUNT) {
devpriv->ai_scans = cmd->stop_arg;
devpriv->ai_neverending = 0;
} else {
devpriv->ai_scans = 0;
devpriv->ai_neverending = 1;
}
devpriv->ai_act_scan = 0;
devpriv->ai_poll_ptr = 0;
s->async->cur_chan = 0;
if ((devpriv->ai_flags & TRIG_WAKE_EOS)) {
devpriv->ai_eos = 1;
if (devpriv->ai_n_chan == 1)
devpriv->ai_dma = 0;
}
if (devpriv->ai_dma) {
if (devpriv->ai_eos) {
devpriv->dmabytestomove[0] =
devpriv->ai_n_chan * sizeof(short);
devpriv->dmabytestomove[1] =
devpriv->ai_n_chan * sizeof(short);
devpriv->dma_runs_to_end = 1;
} else {
devpriv->dmabytestomove[0] = devpriv->hwdmasize[0];
devpriv->dmabytestomove[1] = devpriv->hwdmasize[1];
if (devpriv->ai_data_len < devpriv->hwdmasize[0])
devpriv->dmabytestomove[0] =
devpriv->ai_data_len;
if (devpriv->ai_data_len < devpriv->hwdmasize[1])
devpriv->dmabytestomove[1] =
devpriv->ai_data_len;
if (devpriv->ai_neverending) {
devpriv->dma_runs_to_end = 1;
} else {
bytes = devpriv->ai_n_chan *
devpriv->ai_scans * sizeof(short);
devpriv->dma_runs_to_end =
bytes / devpriv->dmabytestomove[0];
devpriv->last_dma_run =
bytes % devpriv->dmabytestomove[0];
if (devpriv->dma_runs_to_end == 0)
devpriv->dmabytestomove[0] =
devpriv->last_dma_run;
devpriv->dma_runs_to_end--;
}
}
if (devpriv->dmabytestomove[0] > devpriv->hwdmasize[0]) {
devpriv->dmabytestomove[0] = devpriv->hwdmasize[0];
devpriv->ai_eos = 0;
}
if (devpriv->dmabytestomove[1] > devpriv->hwdmasize[1]) {
devpriv->dmabytestomove[1] = devpriv->hwdmasize[1];
devpriv->ai_eos = 0;
}
devpriv->next_dma_buf = 0;
set_dma_mode(devpriv->dma, DMA_MODE_READ);
dma_flags = claim_dma_lock();
clear_dma_ff(devpriv->dma);
set_dma_addr(devpriv->dma, devpriv->hwdmaptr[0]);
set_dma_count(devpriv->dma, devpriv->dmabytestomove[0]);
release_dma_lock(dma_flags);
enable_dma(devpriv->dma);
}
switch (cmd->convert_src) {
case TRIG_TIMER:
start_pacer(dev, 1, divisor1, divisor2);
break;
}
if (devpriv->ai_dma)
outb(devpriv->mode_reg_int | 2, dev->iobase + PCL812_MODE);
else
outb(devpriv->mode_reg_int | 6, dev->iobase + PCL812_MODE);
return 0;
}
static irqreturn_t interrupt_pcl812_ai_int(int irq, void *d)
{
char err = 1;
unsigned int mask, timeout;
struct comedi_device *dev = d;
struct pcl812_private *devpriv = dev->private;
struct comedi_subdevice *s = &dev->subdevices[0];
unsigned int next_chan;
s->async->events = 0;
timeout = 50;
if (devpriv->ai_is16b) {
mask = 0xffff;
while (timeout--) {
if (!(inb(dev->iobase + ACL8216_STATUS) & ACL8216_DRDY)) {
err = 0;
break;
}
udelay(1);
}
} else {
mask = 0x0fff;
while (timeout--) {
if (!(inb(dev->iobase + PCL812_AD_HI) & PCL812_DRDY)) {
err = 0;
break;
}
udelay(1);
}
}
if (err) {
printk
("comedi%d: pcl812: (%s at 0x%lx) "
"A/D cmd IRQ without DRDY!\n",
dev->minor, dev->board_name, dev->iobase);
pcl812_ai_cancel(dev, s);
s->async->events |= COMEDI_CB_EOA | COMEDI_CB_ERROR;
comedi_event(dev, s);
return IRQ_HANDLED;
}
comedi_buf_put(s->async,
((inb(dev->iobase + PCL812_AD_HI) << 8) |
inb(dev->iobase + PCL812_AD_LO)) & mask);
next_chan = s->async->cur_chan + 1;
if (next_chan >= devpriv->ai_n_chan)
next_chan = 0;
if (devpriv->ai_chanlist[s->async->cur_chan] !=
devpriv->ai_chanlist[next_chan])
setup_range_channel(dev, s, devpriv->ai_chanlist[next_chan], 0);
outb(0, dev->iobase + PCL812_CLRINT);
s->async->cur_chan = next_chan;
if (next_chan == 0) {
devpriv->ai_act_scan++;
if (!(devpriv->ai_neverending))
if (devpriv->ai_act_scan >= devpriv->ai_scans) {
pcl812_ai_cancel(dev, s);
s->async->events |= COMEDI_CB_EOA;
}
}
comedi_event(dev, s);
return IRQ_HANDLED;
}
static void transfer_from_dma_buf(struct comedi_device *dev,
struct comedi_subdevice *s, short *ptr,
unsigned int bufptr, unsigned int len)
{
struct pcl812_private *devpriv = dev->private;
unsigned int i;
s->async->events = 0;
for (i = len; i; i--) {
comedi_buf_put(s->async, ptr[bufptr++]);
s->async->cur_chan++;
if (s->async->cur_chan >= devpriv->ai_n_chan) {
s->async->cur_chan = 0;
devpriv->ai_act_scan++;
if (!devpriv->ai_neverending)
if (devpriv->ai_act_scan >= devpriv->ai_scans) {
pcl812_ai_cancel(dev, s);
s->async->events |= COMEDI_CB_EOA;
break;
}
}
}
comedi_event(dev, s);
}
static irqreturn_t interrupt_pcl812_ai_dma(int irq, void *d)
{
struct comedi_device *dev = d;
struct pcl812_private *devpriv = dev->private;
struct comedi_subdevice *s = &dev->subdevices[0];
unsigned long dma_flags;
int len, bufptr;
short *ptr;
ptr = (short *)devpriv->dmabuf[devpriv->next_dma_buf];
len = (devpriv->dmabytestomove[devpriv->next_dma_buf] >> 1) -
devpriv->ai_poll_ptr;
devpriv->next_dma_buf = 1 - devpriv->next_dma_buf;
disable_dma(devpriv->dma);
set_dma_mode(devpriv->dma, DMA_MODE_READ);
dma_flags = claim_dma_lock();
set_dma_addr(devpriv->dma, devpriv->hwdmaptr[devpriv->next_dma_buf]);
if (devpriv->ai_eos) {
set_dma_count(devpriv->dma,
devpriv->dmabytestomove[devpriv->next_dma_buf]);
} else {
if (devpriv->dma_runs_to_end) {
set_dma_count(devpriv->dma,
devpriv->dmabytestomove[devpriv->
next_dma_buf]);
} else {
set_dma_count(devpriv->dma, devpriv->last_dma_run);
}
devpriv->dma_runs_to_end--;
}
release_dma_lock(dma_flags);
enable_dma(devpriv->dma);
outb(0, dev->iobase + PCL812_CLRINT);
bufptr = devpriv->ai_poll_ptr;
devpriv->ai_poll_ptr = 0;
transfer_from_dma_buf(dev, s, ptr, bufptr, len);
return IRQ_HANDLED;
}
static irqreturn_t interrupt_pcl812(int irq, void *d)
{
struct comedi_device *dev = d;
struct pcl812_private *devpriv = dev->private;
if (!dev->attached) {
comedi_error(dev, "spurious interrupt");
return IRQ_HANDLED;
}
if (devpriv->ai_dma)
return interrupt_pcl812_ai_dma(irq, d);
else
return interrupt_pcl812_ai_int(irq, d);
}
static int pcl812_ai_poll(struct comedi_device *dev, struct comedi_subdevice *s)
{
struct pcl812_private *devpriv = dev->private;
unsigned long flags;
unsigned int top1, top2, i;
if (!devpriv->ai_dma)
return 0;
spin_lock_irqsave(&dev->spinlock, flags);
for (i = 0; i < 10; i++) {
top1 = get_dma_residue(devpriv->ai_dma);
top2 = get_dma_residue(devpriv->ai_dma);
if (top1 == top2)
break;
}
if (top1 != top2) {
spin_unlock_irqrestore(&dev->spinlock, flags);
return 0;
}
top1 = devpriv->dmabytestomove[1 - devpriv->next_dma_buf] - top1;
top1 >>= 1;
top2 = top1 - devpriv->ai_poll_ptr;
if (top2 < 1) {
spin_unlock_irqrestore(&dev->spinlock, flags);
return 0;
}
transfer_from_dma_buf(dev, s,
(void *)devpriv->dmabuf[1 -
devpriv->next_dma_buf],
devpriv->ai_poll_ptr, top2);
devpriv->ai_poll_ptr = top1;
spin_unlock_irqrestore(&dev->spinlock, flags);
return s->async->buf_write_count - s->async->buf_read_count;
}
static void setup_range_channel(struct comedi_device *dev,
struct comedi_subdevice *s,
unsigned int rangechan, char wait)
{
struct pcl812_private *devpriv = dev->private;
unsigned char chan_reg = CR_CHAN(rangechan);
unsigned char gain_reg = CR_RANGE(rangechan) +
devpriv->range_correction;
if ((chan_reg == devpriv->old_chan_reg)
&& (gain_reg == devpriv->old_gain_reg))
return;
devpriv->old_chan_reg = chan_reg;
devpriv->old_gain_reg = gain_reg;
if (devpriv->use_MPC) {
if (devpriv->use_diff) {
chan_reg = chan_reg | 0x30;
} else {
if (chan_reg & 0x80)
chan_reg = chan_reg | 0x20;
else
chan_reg = chan_reg | 0x10;
}
}
outb(chan_reg, dev->iobase + PCL812_MUX);
outb(gain_reg, dev->iobase + PCL812_GAIN);
if (wait)
udelay(devpriv->max_812_ai_mode0_rangewait);
}
static void start_pacer(struct comedi_device *dev, int mode,
unsigned int divisor1, unsigned int divisor2)
{
outb(0xb4, dev->iobase + PCL812_CTRCTL);
outb(0x74, dev->iobase + PCL812_CTRCTL);
udelay(1);
if (mode == 1) {
outb(divisor2 & 0xff, dev->iobase + PCL812_CTR2);
outb((divisor2 >> 8) & 0xff, dev->iobase + PCL812_CTR2);
outb(divisor1 & 0xff, dev->iobase + PCL812_CTR1);
outb((divisor1 >> 8) & 0xff, dev->iobase + PCL812_CTR1);
}
}
static int pcl812_ai_cancel(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct pcl812_private *devpriv = dev->private;
if (devpriv->ai_dma)
disable_dma(devpriv->dma);
outb(0, dev->iobase + PCL812_CLRINT);
outb(devpriv->mode_reg_int | 0, dev->iobase + PCL812_MODE);
start_pacer(dev, -1, 0, 0);
outb(0, dev->iobase + PCL812_CLRINT);
return 0;
}
static void pcl812_reset(struct comedi_device *dev)
{
const struct pcl812_board *board = comedi_board(dev);
struct pcl812_private *devpriv = dev->private;
outb(0, dev->iobase + PCL812_MUX);
outb(0 + devpriv->range_correction, dev->iobase + PCL812_GAIN);
devpriv->old_chan_reg = -1;
devpriv->old_gain_reg = -1;
switch (board->board_type) {
case boardPCL812PG:
case boardPCL812:
case boardACL8112:
case boardACL8216:
outb(0, dev->iobase + PCL812_DA2_LO);
outb(0, dev->iobase + PCL812_DA2_HI);
case boardA821:
outb(0, dev->iobase + PCL812_DA1_LO);
outb(0, dev->iobase + PCL812_DA1_HI);
start_pacer(dev, -1, 0, 0);
outb(0, dev->iobase + PCL812_DO_HI);
outb(0, dev->iobase + PCL812_DO_LO);
outb(devpriv->mode_reg_int | 0, dev->iobase + PCL812_MODE);
outb(0, dev->iobase + PCL812_CLRINT);
break;
case boardPCL813B:
case boardPCL813:
case boardISO813:
case boardACL8113:
udelay(5);
break;
}
udelay(5);
}
static int pcl812_attach(struct comedi_device *dev, struct comedi_devconfig *it)
{
const struct pcl812_board *board = comedi_board(dev);
struct pcl812_private *devpriv;
int ret, subdev;
unsigned int irq;
unsigned int dma;
unsigned long pages;
struct comedi_subdevice *s;
int n_subdevices;
ret = comedi_request_region(dev, it->options[0], board->io_range);
if (ret)
return ret;
devpriv = comedi_alloc_devpriv(dev, sizeof(*devpriv));
if (!devpriv)
return -ENOMEM;
irq = 0;
if (board->IRQbits != 0) {
irq = it->options[1];
if (irq) {
if (((1 << irq) & board->IRQbits) == 0) {
printk
(", IRQ %u is out of allowed range, "
"DISABLING IT", irq);
irq = 0;
} else {
if (request_irq(irq, interrupt_pcl812, 0,
dev->board_name, dev)) {
printk
(", unable to allocate IRQ %u, "
"DISABLING IT", irq);
irq = 0;
} else {
printk(KERN_INFO ", irq=%u", irq);
}
}
}
}
dev->irq = irq;
dma = 0;
devpriv->dma = dma;
if (!dev->irq)
goto no_dma;
if (board->DMAbits != 0) {
dma = it->options[2];
if (((1 << dma) & board->DMAbits) == 0) {
printk(", DMA is out of allowed range, FAIL!\n");
return -EINVAL;
}
ret = request_dma(dma, dev->board_name);
if (ret) {
printk(KERN_ERR ", unable to allocate DMA %u, FAIL!\n",
dma);
return -EBUSY;
}
devpriv->dma = dma;
printk(KERN_INFO ", dma=%u", dma);
pages = 1;
devpriv->dmabuf[0] = __get_dma_pages(GFP_KERNEL, pages);
if (!devpriv->dmabuf[0]) {
printk(", unable to allocate DMA buffer, FAIL!\n");
return -EBUSY;
}
devpriv->dmapages[0] = pages;
devpriv->hwdmaptr[0] = virt_to_bus((void *)devpriv->dmabuf[0]);
devpriv->hwdmasize[0] = PAGE_SIZE * (1 << pages);
devpriv->dmabuf[1] = __get_dma_pages(GFP_KERNEL, pages);
if (!devpriv->dmabuf[1]) {
printk(KERN_ERR ", unable to allocate DMA buffer, FAIL!\n");
return -EBUSY;
}
devpriv->dmapages[1] = pages;
devpriv->hwdmaptr[1] = virt_to_bus((void *)devpriv->dmabuf[1]);
devpriv->hwdmasize[1] = PAGE_SIZE * (1 << pages);
}
no_dma:
n_subdevices = 0;
if (board->n_aichan > 0)
n_subdevices++;
if (board->n_aochan > 0)
n_subdevices++;
if (board->n_dichan > 0)
n_subdevices++;
if (board->n_dochan > 0)
n_subdevices++;
ret = comedi_alloc_subdevices(dev, n_subdevices);
if (ret)
return ret;
subdev = 0;
if (board->n_aichan > 0) {
s = &dev->subdevices[subdev];
s->type = COMEDI_SUBD_AI;
s->subdev_flags = SDF_READABLE;
switch (board->board_type) {
case boardA821:
if (it->options[2] == 1) {
s->n_chan = board->n_aichan_diff;
s->subdev_flags |= SDF_DIFF;
devpriv->use_diff = 1;
} else {
s->n_chan = board->n_aichan;
s->subdev_flags |= SDF_GROUND;
}
break;
case boardACL8112:
case boardACL8216:
if (it->options[4] == 1) {
s->n_chan = board->n_aichan_diff;
s->subdev_flags |= SDF_DIFF;
devpriv->use_diff = 1;
} else {
s->n_chan = board->n_aichan;
s->subdev_flags |= SDF_GROUND;
}
break;
default:
s->n_chan = board->n_aichan;
s->subdev_flags |= SDF_GROUND;
break;
}
s->maxdata = board->ai_maxdata;
s->len_chanlist = MAX_CHANLIST_LEN;
s->range_table = board->rangelist_ai;
if (board->board_type == boardACL8216)
s->insn_read = acl8216_ai_insn_read;
else
s->insn_read = pcl812_ai_insn_read;
devpriv->use_MPC = board->haveMPC508;
s->cancel = pcl812_ai_cancel;
if (dev->irq) {
dev->read_subdev = s;
s->subdev_flags |= SDF_CMD_READ;
s->do_cmdtest = pcl812_ai_cmdtest;
s->do_cmd = pcl812_ai_cmd;
s->poll = pcl812_ai_poll;
}
switch (board->board_type) {
case boardPCL812PG:
if (it->options[4] == 1)
s->range_table = &range_pcl812pg2_ai;
break;
case boardPCL812:
switch (it->options[4]) {
case 0:
s->range_table = &range_bipolar10;
break;
case 1:
s->range_table = &range_bipolar5;
break;
case 2:
s->range_table = &range_bipolar2_5;
break;
case 3:
s->range_table = &range812_bipolar1_25;
break;
case 4:
s->range_table = &range812_bipolar0_625;
break;
case 5:
s->range_table = &range812_bipolar0_3125;
break;
default:
s->range_table = &range_bipolar10;
break;
printk
(", incorrect range number %d, changing "
"to 0 (+/-10V)", it->options[4]);
break;
}
break;
break;
case boardPCL813B:
if (it->options[1] == 1)
s->range_table = &range_pcl813b2_ai;
break;
case boardISO813:
switch (it->options[1]) {
case 0:
s->range_table = &range_iso813_1_ai;
break;
case 1:
s->range_table = &range_iso813_1_2_ai;
break;
case 2:
s->range_table = &range_iso813_2_ai;
devpriv->range_correction = 1;
break;
case 3:
s->range_table = &range_iso813_2_2_ai;
devpriv->range_correction = 1;
break;
default:
s->range_table = &range_iso813_1_ai;
break;
printk
(", incorrect range number %d, "
"changing to 0 ", it->options[1]);
break;
}
break;
case boardACL8113:
switch (it->options[1]) {
case 0:
s->range_table = &range_acl8113_1_ai;
break;
case 1:
s->range_table = &range_acl8113_1_2_ai;
break;
case 2:
s->range_table = &range_acl8113_2_ai;
devpriv->range_correction = 1;
break;
case 3:
s->range_table = &range_acl8113_2_2_ai;
devpriv->range_correction = 1;
break;
default:
s->range_table = &range_acl8113_1_ai;
break;
printk
(", incorrect range number %d, "
"changing to 0 ", it->options[1]);
break;
}
break;
}
subdev++;
}
if (board->n_aochan > 0) {
s = &dev->subdevices[subdev];
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITABLE | SDF_GROUND;
s->n_chan = board->n_aochan;
s->maxdata = 0xfff;
s->len_chanlist = 1;
s->range_table = board->rangelist_ao;
s->insn_read = pcl812_ao_insn_read;
s->insn_write = pcl812_ao_insn_write;
switch (board->board_type) {
case boardA821:
if (it->options[3] == 1)
s->range_table = &range_unipolar10;
break;
case boardPCL812:
case boardACL8112:
case boardPCL812PG:
case boardACL8216:
if (it->options[5] == 1)
s->range_table = &range_unipolar10;
if (it->options[5] == 2)
s->range_table = &range_unknown;
break;
}
subdev++;
}
if (board->n_dichan > 0) {
s = &dev->subdevices[subdev];
s->type = COMEDI_SUBD_DI;
s->subdev_flags = SDF_READABLE;
s->n_chan = board->n_dichan;
s->maxdata = 1;
s->len_chanlist = board->n_dichan;
s->range_table = &range_digital;
s->insn_bits = pcl812_di_insn_bits;
subdev++;
}
if (board->n_dochan > 0) {
s = &dev->subdevices[subdev];
s->type = COMEDI_SUBD_DO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = board->n_dochan;
s->maxdata = 1;
s->len_chanlist = board->n_dochan;
s->range_table = &range_digital;
s->insn_bits = pcl812_do_insn_bits;
subdev++;
}
switch (board->board_type) {
case boardACL8216:
devpriv->ai_is16b = 1;
case boardPCL812PG:
case boardPCL812:
case boardACL8112:
devpriv->max_812_ai_mode0_rangewait = 1;
if (it->options[3] > 0)
devpriv->use_ext_trg = 1;
break;
case boardA821:
devpriv->max_812_ai_mode0_rangewait = 1;
devpriv->mode_reg_int = (irq << 4) & 0xf0;
break;
case boardPCL813B:
case boardPCL813:
case boardISO813:
case boardACL8113:
devpriv->max_812_ai_mode0_rangewait = 5;
break;
}
printk(KERN_INFO "\n");
devpriv->valid = 1;
pcl812_reset(dev);
return 0;
}
static void pcl812_detach(struct comedi_device *dev)
{
struct pcl812_private *devpriv = dev->private;
if (devpriv) {
if (devpriv->dmabuf[0])
free_pages(devpriv->dmabuf[0], devpriv->dmapages[0]);
if (devpriv->dmabuf[1])
free_pages(devpriv->dmabuf[1], devpriv->dmapages[1]);
if (devpriv->dma)
free_dma(devpriv->dma);
}
comedi_legacy_detach(dev);
}
