static int pcl816_ai_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
int n;
int timeout;
DPRINTK("mode 0 analog input\n");
outb(0, dev->iobase + PCL816_CONTROL);
outb(0, dev->iobase + PCL816_CLRINT);
outb(CR_CHAN(insn->chanspec) & 0xf, dev->iobase + PCL816_MUX);
outb(CR_RANGE(insn->chanspec), dev->iobase + PCL816_RANGE);
for (n = 0; n < insn->n; n++) {
outb(0, dev->iobase + PCL816_AD_LO);
timeout = 100;
while (timeout--) {
if (!(inb(dev->iobase + PCL816_STATUS) &
PCL816_STATUS_DRDY_MASK)) {
data[n] =
((inb(dev->iobase +
PCL816_AD_HI) << 8) |
(inb(dev->iobase + PCL816_AD_LO)));
outb(0, dev->iobase + PCL816_CLRINT);
break;
}
udelay(1);
}
if (!timeout) {
comedi_error(dev, "A/D insn timeout\n");
data[0] = 0;
outb(0, dev->iobase + PCL816_CLRINT);
return -EIO;
}
}
return n;
}
static irqreturn_t interrupt_pcl816_ai_mode13_int(int irq, void *d)
{
struct comedi_device *dev = d;
struct pcl816_private *devpriv = dev->private;
struct comedi_subdevice *s = &dev->subdevices[0];
int low, hi;
int timeout = 50;
while (timeout--) {
if (!(inb(dev->iobase + PCL816_STATUS) &
PCL816_STATUS_DRDY_MASK))
break;
udelay(1);
}
if (!timeout) {
outb(0, dev->iobase + PCL816_CLRINT);
comedi_error(dev, "A/D mode1/3 IRQ without DRDY!");
pcl816_ai_cancel(dev, s);
s->async->events |= COMEDI_CB_EOA | COMEDI_CB_ERROR;
comedi_event(dev, s);
return IRQ_HANDLED;
}
low = inb(dev->iobase + PCL816_AD_LO);
hi = inb(dev->iobase + PCL816_AD_HI);
comedi_buf_put(s->async, (hi << 8) | low);
outb(0, dev->iobase + PCL816_CLRINT);
if (++devpriv->ai_act_chanlist_pos >= devpriv->ai_act_chanlist_len)
devpriv->ai_act_chanlist_pos = 0;
s->async->cur_chan++;
if (s->async->cur_chan >= devpriv->ai_n_chan) {
s->async->cur_chan = 0;
devpriv->ai_act_scan++;
}
if (!devpriv->ai_neverending)
if (devpriv->ai_act_scan >= devpriv->ai_scans) {
pcl816_ai_cancel(dev, s);
s->async->events |= COMEDI_CB_EOA;
}
comedi_event(dev, s);
return IRQ_HANDLED;
}
static void transfer_from_dma_buf(struct comedi_device *dev,
struct comedi_subdevice *s, short *ptr,
unsigned int bufptr, unsigned int len)
{
struct pcl816_private *devpriv = dev->private;
int i;
s->async->events = 0;
for (i = 0; i < len; i++) {
comedi_buf_put(s->async, ptr[bufptr++]);
if (++devpriv->ai_act_chanlist_pos >=
devpriv->ai_act_chanlist_len) {
devpriv->ai_act_chanlist_pos = 0;
}
s->async->cur_chan++;
if (s->async->cur_chan >= devpriv->ai_n_chan) {
s->async->cur_chan = 0;
devpriv->ai_act_scan++;
}
if (!devpriv->ai_neverending)
if (devpriv->ai_act_scan >= devpriv->ai_scans) {
pcl816_ai_cancel(dev, s);
s->async->events |= COMEDI_CB_EOA;
s->async->events |= COMEDI_CB_BLOCK;
break;
}
}
comedi_event(dev, s);
}
static irqreturn_t interrupt_pcl816_ai_mode13_dma(int irq, void *d)
{
struct comedi_device *dev = d;
struct pcl816_private *devpriv = dev->private;
struct comedi_subdevice *s = &dev->subdevices[0];
int len, bufptr, this_dma_buf;
unsigned long dma_flags;
short *ptr;
disable_dma(devpriv->dma);
this_dma_buf = devpriv->next_dma_buf;
if ((devpriv->dma_runs_to_end > -1) || devpriv->ai_neverending) {
devpriv->next_dma_buf = 1 - devpriv->next_dma_buf;
set_dma_mode(devpriv->dma, DMA_MODE_READ);
dma_flags = claim_dma_lock();
set_dma_addr(devpriv->dma,
devpriv->hwdmaptr[devpriv->next_dma_buf]);
if (devpriv->dma_runs_to_end) {
set_dma_count(devpriv->dma,
devpriv->hwdmasize[devpriv->
next_dma_buf]);
} else {
set_dma_count(devpriv->dma, devpriv->last_dma_run);
}
release_dma_lock(dma_flags);
enable_dma(devpriv->dma);
}
devpriv->dma_runs_to_end--;
outb(0, dev->iobase + PCL816_CLRINT);
ptr = (short *)devpriv->dmabuf[this_dma_buf];
len = (devpriv->hwdmasize[0] >> 1) - devpriv->ai_poll_ptr;
bufptr = devpriv->ai_poll_ptr;
devpriv->ai_poll_ptr = 0;
transfer_from_dma_buf(dev, s, ptr, bufptr, len);
return IRQ_HANDLED;
}
static irqreturn_t interrupt_pcl816(int irq, void *d)
{
struct comedi_device *dev = d;
struct pcl816_private *devpriv = dev->private;
DPRINTK("<I>");
if (!dev->attached) {
comedi_error(dev, "premature interrupt");
return IRQ_HANDLED;
}
switch (devpriv->int816_mode) {
case INT_TYPE_AI1_DMA:
case INT_TYPE_AI3_DMA:
return interrupt_pcl816_ai_mode13_dma(irq, d);
case INT_TYPE_AI1_INT:
case INT_TYPE_AI3_INT:
return interrupt_pcl816_ai_mode13_int(irq, d);
}
outb(0, dev->iobase + PCL816_CLRINT);
if (!dev->irq || !devpriv->irq_free || !devpriv->irq_blocked ||
!devpriv->int816_mode) {
if (devpriv->irq_was_now_closed) {
devpriv->irq_was_now_closed = 0;
return IRQ_HANDLED;
}
comedi_error(dev, "bad IRQ!");
return IRQ_NONE;
}
comedi_error(dev, "IRQ from unknown source!");
return IRQ_NONE;
}
static void pcl816_cmdtest_out(int e, struct comedi_cmd *cmd)
{
printk(KERN_INFO "pcl816 e=%d startsrc=%x scansrc=%x convsrc=%x\n", e,
cmd->start_src, cmd->scan_begin_src, cmd->convert_src);
printk(KERN_INFO "pcl816 e=%d startarg=%d scanarg=%d convarg=%d\n", e,
cmd->start_arg, cmd->scan_begin_arg, cmd->convert_arg);
printk(KERN_INFO "pcl816 e=%d stopsrc=%x scanend=%x\n", e,
cmd->stop_src, cmd->scan_end_src);
printk(KERN_INFO "pcl816 e=%d stoparg=%d scanendarg=%d chanlistlen=%d\n",
e, cmd->stop_arg, cmd->scan_end_arg, cmd->chanlist_len);
}
static int pcl816_ai_cmdtest(struct comedi_device *dev,
struct comedi_subdevice *s, struct comedi_cmd *cmd)
{
const struct pcl816_board *board = comedi_board(dev);
int err = 0;
int tmp, divisor1 = 0, divisor2 = 0;
DEBUG(printk(KERN_INFO "pcl816 pcl812_ai_cmdtest\n");
pcl816_cmdtest_out(-1, cmd);
);
err |= cfc_check_trigger_src(&cmd->start_src, TRIG_NOW);
err |= cfc_check_trigger_src(&cmd->scan_begin_src, TRIG_FOLLOW);
err |= cfc_check_trigger_src(&cmd->convert_src, TRIG_EXT | TRIG_TIMER);
err |= cfc_check_trigger_src(&cmd->scan_end_src, TRIG_COUNT);
err |= cfc_check_trigger_src(&cmd->stop_src, TRIG_COUNT | TRIG_NONE);
if (err)
return 1;
err |= cfc_check_trigger_is_unique(cmd->convert_src);
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
err |= cfc_check_trigger_arg_is(&cmd->scan_end_arg, cmd->chanlist_len);
if (cmd->stop_src == TRIG_COUNT)
err |= cfc_check_trigger_arg_min(&cmd->stop_arg, 1);
else
err |= cfc_check_trigger_arg_is(&cmd->stop_arg, 0);
if (err)
return 3;
if (cmd->convert_src == TRIG_TIMER) {
tmp = cmd->convert_arg;
i8253_cascade_ns_to_timer(board->i8254_osc_base,
&divisor1, &divisor2,
&cmd->convert_arg,
cmd->flags & TRIG_ROUND_MASK);
if (cmd->convert_arg < board->ai_ns_min)
cmd->convert_arg = board->ai_ns_min;
if (tmp != cmd->convert_arg)
err++;
}
if (err)
return 4;
if (cmd->chanlist) {
if (!check_channel_list(dev, s, cmd->chanlist,
cmd->chanlist_len))
return 5;
}
return 0;
}
static int pcl816_ai_cmd(struct comedi_device *dev, struct comedi_subdevice *s)
{
const struct pcl816_board *board = comedi_board(dev);
struct pcl816_private *devpriv = dev->private;
unsigned int divisor1 = 0, divisor2 = 0, dma_flags, bytes, dmairq;
struct comedi_cmd *cmd = &s->async->cmd;
unsigned int seglen;
if (cmd->start_src != TRIG_NOW)
return -EINVAL;
if (cmd->scan_begin_src != TRIG_FOLLOW)
return -EINVAL;
if (cmd->scan_end_src != TRIG_COUNT)
return -EINVAL;
if (cmd->scan_end_arg != cmd->chanlist_len)
return -EINVAL;
if (devpriv->irq_blocked)
return -EBUSY;
if (cmd->convert_src == TRIG_TIMER) {
if (cmd->convert_arg < board->ai_ns_min)
cmd->convert_arg = board->ai_ns_min;
i8253_cascade_ns_to_timer(board->i8254_osc_base, &divisor1,
&divisor2, &cmd->convert_arg,
cmd->flags & TRIG_ROUND_MASK);
if (divisor1 == 1) {
divisor1 = 2;
divisor2 /= 2;
}
if (divisor2 == 1) {
divisor2 = 2;
divisor1 /= 2;
}
}
start_pacer(dev, -1, 0, 0);
seglen = check_channel_list(dev, s, cmd->chanlist, cmd->chanlist_len);
if (seglen < 1)
return -EINVAL;
setup_channel_list(dev, s, cmd->chanlist, seglen);
udelay(1);
devpriv->ai_n_chan = cmd->chanlist_len;
devpriv->ai_act_scan = 0;
s->async->cur_chan = 0;
devpriv->irq_blocked = 1;
devpriv->ai_poll_ptr = 0;
devpriv->irq_was_now_closed = 0;
if (cmd->stop_src == TRIG_COUNT) {
devpriv->ai_scans = cmd->stop_arg;
devpriv->ai_neverending = 0;
} else {
devpriv->ai_scans = 0;
devpriv->ai_neverending = 1;
}
if ((cmd->flags & TRIG_WAKE_EOS)) {
printk(KERN_INFO
"pl816: You wankt WAKE_EOS but I dont want handle it");
}
if (devpriv->dma) {
bytes = devpriv->hwdmasize[0];
if (!devpriv->ai_neverending) {
bytes = s->async->cmd.chanlist_len *
s->async->cmd.chanlist_len *
sizeof(short);
devpriv->dma_runs_to_end = bytes /
devpriv->hwdmasize[0];
devpriv->last_dma_run = bytes % devpriv->hwdmasize[0];
devpriv->dma_runs_to_end--;
if (devpriv->dma_runs_to_end >= 0)
bytes = devpriv->hwdmasize[0];
} else
devpriv->dma_runs_to_end = -1;
devpriv->next_dma_buf = 0;
set_dma_mode(devpriv->dma, DMA_MODE_READ);
dma_flags = claim_dma_lock();
clear_dma_ff(devpriv->dma);
set_dma_addr(devpriv->dma, devpriv->hwdmaptr[0]);
set_dma_count(devpriv->dma, bytes);
release_dma_lock(dma_flags);
enable_dma(devpriv->dma);
}
start_pacer(dev, 1, divisor1, divisor2);
dmairq = ((devpriv->dma & 0x3) << 4) | (dev->irq & 0x7);
switch (cmd->convert_src) {
case TRIG_TIMER:
devpriv->int816_mode = INT_TYPE_AI1_DMA;
outb(0x32, dev->iobase + PCL816_CONTROL);
outb(dmairq, dev->iobase + PCL816_STATUS);
break;
default:
devpriv->int816_mode = INT_TYPE_AI3_DMA;
outb(0x34, dev->iobase + PCL816_CONTROL);
outb(dmairq, dev->iobase + PCL816_STATUS);
break;
}
DPRINTK("pcl816 END: pcl812_ai_cmd()\n");
return 0;
}
static int pcl816_ai_poll(struct comedi_device *dev, struct comedi_subdevice *s)
{
struct pcl816_private *devpriv = dev->private;
unsigned long flags;
unsigned int top1, top2, i;
if (!devpriv->dma)
return 0;
spin_lock_irqsave(&dev->spinlock, flags);
for (i = 0; i < 20; i++) {
top1 = get_dma_residue(devpriv->dma);
top2 = get_dma_residue(devpriv->dma);
if (top1 == top2)
break;
}
if (top1 != top2) {
spin_unlock_irqrestore(&dev->spinlock, flags);
return 0;
}
top1 = devpriv->hwdmasize[0] - top1;
top1 >>= 1;
top2 = top1 - devpriv->ai_poll_ptr;
if (top2 < 1) {
spin_unlock_irqrestore(&dev->spinlock, flags);
return 0;
}
transfer_from_dma_buf(dev, s,
(short *)devpriv->dmabuf[devpriv->next_dma_buf],
devpriv->ai_poll_ptr, top2);
devpriv->ai_poll_ptr = top1;
spin_unlock_irqrestore(&dev->spinlock, flags);
return s->async->buf_write_count - s->async->buf_read_count;
}
static int pcl816_ai_cancel(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct pcl816_private *devpriv = dev->private;
if (devpriv->irq_blocked > 0) {
switch (devpriv->int816_mode) {
case INT_TYPE_AI1_DMA:
case INT_TYPE_AI3_DMA:
disable_dma(devpriv->dma);
case INT_TYPE_AI1_INT:
case INT_TYPE_AI3_INT:
outb(inb(dev->iobase + PCL816_CONTROL) & 0x73,
dev->iobase + PCL816_CONTROL);
udelay(1);
outb(0, dev->iobase + PCL816_CONTROL);
outb(0xb0, dev->iobase + PCL816_CTRCTL);
outb(0x70, dev->iobase + PCL816_CTRCTL);
outb(0, dev->iobase + PCL816_AD_LO);
inb(dev->iobase + PCL816_AD_LO);
inb(dev->iobase + PCL816_AD_HI);
outb(0, dev->iobase + PCL816_CLRINT);
outb(0, dev->iobase + PCL816_CONTROL);
devpriv->irq_blocked = 0;
devpriv->irq_was_now_closed = devpriv->int816_mode;
devpriv->int816_mode = 0;
devpriv->last_int_sub = s;
break;
}
}
DEBUG(printk("comedi: pcl816_ai_cancel() successful\n");)
return 0;
}
static int pcl816_check(unsigned long iobase)
{
outb(0x00, iobase + PCL816_MUX);
udelay(1);
if (inb(iobase + PCL816_MUX) != 0x00)
return 1;
outb(0x55, iobase + PCL816_MUX);
udelay(1);
if (inb(iobase + PCL816_MUX) != 0x55)
return 1;
outb(0x00, iobase + PCL816_MUX);
udelay(1);
outb(0x18, iobase + PCL816_CONTROL);
udelay(1);
if (inb(iobase + PCL816_CONTROL) != 0x18)
return 1;
return 0;
}
static void pcl816_reset(struct comedi_device *dev)
{
outb(0, dev->iobase + PCL816_CONTROL);
outb(0, dev->iobase + PCL816_MUX);
outb(0, dev->iobase + PCL816_CLRINT);
outb(0xb0, dev->iobase + PCL816_CTRCTL);
outb(0x70, dev->iobase + PCL816_CTRCTL);
outb(0x30, dev->iobase + PCL816_CTRCTL);
outb(0, dev->iobase + PCL816_RANGE);
}
static void
start_pacer(struct comedi_device *dev, int mode, unsigned int divisor1,
unsigned int divisor2)
{
outb(0x32, dev->iobase + PCL816_CTRCTL);
outb(0xff, dev->iobase + PCL816_CTR0);
outb(0x00, dev->iobase + PCL816_CTR0);
udelay(1);
outb(0xb4, dev->iobase + PCL816_CTRCTL);
outb(0x74, dev->iobase + PCL816_CTRCTL);
udelay(1);
if (mode == 1) {
DPRINTK("mode %d, divisor1 %d, divisor2 %d\n", mode, divisor1,
divisor2);
outb(divisor2 & 0xff, dev->iobase + PCL816_CTR2);
outb((divisor2 >> 8) & 0xff, dev->iobase + PCL816_CTR2);
outb(divisor1 & 0xff, dev->iobase + PCL816_CTR1);
outb((divisor1 >> 8) & 0xff, dev->iobase + PCL816_CTR1);
}
}
static int
check_channel_list(struct comedi_device *dev,
struct comedi_subdevice *s, unsigned int *chanlist,
unsigned int chanlen)
{
unsigned int chansegment[16];
unsigned int i, nowmustbechan, seglen, segpos;
if (chanlen < 1) {
comedi_error(dev, "range/channel list is empty!");
return 0;
}
if (chanlen > 1) {
chansegment[0] = chanlist[0];
for (i = 1, seglen = 1; i < chanlen; i++, seglen++) {
DEBUG(printk(KERN_INFO "%d. %d %d\n", i,
CR_CHAN(chanlist[i]),
CR_RANGE(chanlist[i]));)
if (chanlist[0] == chanlist[i])
break;
nowmustbechan =
(CR_CHAN(chansegment[i - 1]) + 1) % chanlen;
if (nowmustbechan != CR_CHAN(chanlist[i])) {
printk(KERN_WARNING
"comedi%d: pcl816: channel list must "
"be continuous! chanlist[%i]=%d but "
"must be %d or %d!\n", dev->minor,
i, CR_CHAN(chanlist[i]), nowmustbechan,
CR_CHAN(chanlist[0]));
return 0;
}
chansegment[i] = chanlist[i];
}
for (i = 0, segpos = 0; i < chanlen; i++) {
DEBUG(printk("%d %d=%d %d\n",
CR_CHAN(chansegment[i % seglen]),
CR_RANGE(chansegment[i % seglen]),
CR_CHAN(chanlist[i]),
CR_RANGE(chanlist[i]));)
if (chanlist[i] != chansegment[i % seglen]) {
printk(KERN_WARNING
"comedi%d: pcl816: bad channel or range"
" number! chanlist[%i]=%d,%d,%d and not"
" %d,%d,%d!\n", dev->minor, i,
CR_CHAN(chansegment[i]),
CR_RANGE(chansegment[i]),
CR_AREF(chansegment[i]),
CR_CHAN(chanlist[i % seglen]),
CR_RANGE(chanlist[i % seglen]),
CR_AREF(chansegment[i % seglen]));
return 0;
}
}
} else {
seglen = 1;
}
return seglen;
}
static void
setup_channel_list(struct comedi_device *dev,
struct comedi_subdevice *s, unsigned int *chanlist,
unsigned int seglen)
{
struct pcl816_private *devpriv = dev->private;
unsigned int i;
devpriv->ai_act_chanlist_len = seglen;
devpriv->ai_act_chanlist_pos = 0;
for (i = 0; i < seglen; i++) {
devpriv->ai_act_chanlist[i] = CR_CHAN(chanlist[i]);
outb(CR_CHAN(chanlist[0]) & 0xf, dev->iobase + PCL816_MUX);
outb(CR_RANGE(chanlist[0]), dev->iobase + PCL816_RANGE);
}
udelay(1);
outb(devpriv->ai_act_chanlist[0] |
(devpriv->ai_act_chanlist[seglen - 1] << 4),
dev->iobase + PCL816_MUX);
}
static int pcl816_attach(struct comedi_device *dev, struct comedi_devconfig *it)
{
const struct pcl816_board *board = comedi_board(dev);
struct pcl816_private *devpriv;
int ret;
unsigned int irq, dma;
unsigned long pages;
struct comedi_subdevice *s;
ret = comedi_request_region(dev, it->options[0], board->io_range);
if (ret)
return ret;
if (pcl816_check(dev->iobase)) {
printk(KERN_ERR ", I cann't detect board. FAIL!\n");
return -EIO;
}
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
if (request_irq(irq, interrupt_pcl816, 0,
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
if (irq)
devpriv->irq_free = 1;
else
devpriv->irq_free = 0;
devpriv->irq_blocked = 0;
devpriv->int816_mode = 0;
dma = 0;
devpriv->dma = dma;
if (!devpriv->irq_free)
goto no_dma;
if (board->DMAbits != 0) {
dma = it->options[2];
if (dma < 1)
goto no_dma;
if (((1 << dma) & board->DMAbits) == 0) {
printk(", DMA is out of allowed range, FAIL!\n");
return -EINVAL;
}
ret = request_dma(dma, dev->board_name);
if (ret) {
printk(KERN_ERR
", unable to allocate DMA %u, FAIL!\n", dma);
return -EBUSY;
}
devpriv->dma = dma;
printk(KERN_INFO ", dma=%u", dma);
pages = 2;
devpriv->dmabuf[0] = __get_dma_pages(GFP_KERNEL, pages);
if (!devpriv->dmabuf[0]) {
printk(", unable to allocate DMA buffer, FAIL!\n");
return -EBUSY;
}
devpriv->dmapages[0] = pages;
devpriv->hwdmaptr[0] = virt_to_bus((void *)devpriv->dmabuf[0]);
devpriv->hwdmasize[0] = (1 << pages) * PAGE_SIZE;
devpriv->dmabuf[1] = __get_dma_pages(GFP_KERNEL, pages);
if (!devpriv->dmabuf[1]) {
printk(KERN_ERR
", unable to allocate DMA buffer, "
"FAIL!\n");
return -EBUSY;
}
devpriv->dmapages[1] = pages;
devpriv->hwdmaptr[1] = virt_to_bus((void *)devpriv->dmabuf[1]);
devpriv->hwdmasize[1] = (1 << pages) * PAGE_SIZE;
}
no_dma:
ret = comedi_alloc_subdevices(dev, 1);
if (ret)
return ret;
s = &dev->subdevices[0];
if (board->n_aichan > 0) {
s->type = COMEDI_SUBD_AI;
devpriv->sub_ai = s;
dev->read_subdev = s;
s->subdev_flags = SDF_READABLE | SDF_CMD_READ;
s->n_chan = board->n_aichan;
s->subdev_flags |= SDF_DIFF;
s->maxdata = board->ai_maxdata;
s->len_chanlist = board->ai_chanlist;
s->range_table = board->ai_range_type;
s->cancel = pcl816_ai_cancel;
s->do_cmdtest = pcl816_ai_cmdtest;
s->do_cmd = pcl816_ai_cmd;
s->poll = pcl816_ai_poll;
s->insn_read = pcl816_ai_insn_read;
} else {
s->type = COMEDI_SUBD_UNUSED;
}
#if 0
case COMEDI_SUBD_AO:
s->subdev_flags = SDF_WRITABLE | SDF_GROUND;
s->n_chan = board->n_aochan;
s->maxdata = board->ao_maxdata;
s->len_chanlist = board->ao_chanlist;
s->range_table = board->ao_range_type;
break;
case COMEDI_SUBD_DI:
s->subdev_flags = SDF_READABLE;
s->n_chan = board->n_dichan;
s->maxdata = 1;
s->len_chanlist = board->n_dichan;
s->range_table = &range_digital;
break;
case COMEDI_SUBD_DO:
s->subdev_flags = SDF_WRITABLE;
s->n_chan = board->n_dochan;
s->maxdata = 1;
s->len_chanlist = board->n_dochan;
s->range_table = &range_digital;
break;
#endif
pcl816_reset(dev);
printk("\n");
return 0;
}
static void pcl816_detach(struct comedi_device *dev)
{
struct pcl816_private *devpriv = dev->private;
if (dev->private) {
pcl816_ai_cancel(dev, devpriv->sub_ai);
pcl816_reset(dev);
if (devpriv->dma)
free_dma(devpriv->dma);
if (devpriv->dmabuf[0])
free_pages(devpriv->dmabuf[0], devpriv->dmapages[0]);
if (devpriv->dmabuf[1])
free_pages(devpriv->dmabuf[1], devpriv->dmapages[1]);
}
comedi_legacy_detach(dev);
}
