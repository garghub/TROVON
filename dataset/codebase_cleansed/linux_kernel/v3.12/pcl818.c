static int pcl818_ai_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
int n;
int timeout;
outb(0, dev->iobase + PCL818_CONTROL);
outb(muxonechan[CR_CHAN(insn->chanspec)], dev->iobase + PCL818_MUX);
outb(CR_RANGE(insn->chanspec), dev->iobase + PCL818_RANGE);
for (n = 0; n < insn->n; n++) {
outb(0, dev->iobase + PCL818_CLRINT);
outb(0, dev->iobase + PCL818_AD_LO);
timeout = 100;
while (timeout--) {
if (inb(dev->iobase + PCL818_STATUS) & 0x10)
goto conv_finish;
udelay(1);
}
comedi_error(dev, "A/D insn timeout");
outb(0, dev->iobase + PCL818_CLRINT);
return -EIO;
conv_finish:
data[n] = ((inb(dev->iobase + PCL818_AD_HI) << 4) |
(inb(dev->iobase + PCL818_AD_LO) >> 4));
}
return n;
}
static int pcl818_ao_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct pcl818_private *devpriv = dev->private;
int n;
int chan = CR_CHAN(insn->chanspec);
for (n = 0; n < insn->n; n++)
data[n] = devpriv->ao_readback[chan];
return n;
}
static int pcl818_ao_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct pcl818_private *devpriv = dev->private;
int n;
int chan = CR_CHAN(insn->chanspec);
for (n = 0; n < insn->n; n++) {
devpriv->ao_readback[chan] = data[n];
outb((data[n] & 0x000f) << 4, dev->iobase +
(chan ? PCL718_DA2_LO : PCL818_DA_LO));
outb((data[n] & 0x0ff0) >> 4, dev->iobase +
(chan ? PCL718_DA2_HI : PCL818_DA_HI));
}
return n;
}
static int pcl818_di_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
data[1] = inb(dev->iobase + PCL818_DI_LO) |
(inb(dev->iobase + PCL818_DI_HI) << 8);
return insn->n;
}
static int pcl818_do_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
s->state &= ~data[0];
s->state |= (data[0] & data[1]);
outb(s->state & 0xff, dev->iobase + PCL818_DO_LO);
outb((s->state >> 8), dev->iobase + PCL818_DO_HI);
data[1] = s->state;
return insn->n;
}
static irqreturn_t interrupt_pcl818_ai_mode13_int(int irq, void *d)
{
struct comedi_device *dev = d;
struct pcl818_private *devpriv = dev->private;
struct comedi_subdevice *s = &dev->subdevices[0];
int low;
int timeout = 50;
while (timeout--) {
if (inb(dev->iobase + PCL818_STATUS) & 0x10)
goto conv_finish;
udelay(1);
}
outb(0, dev->iobase + PCL818_STATUS);
comedi_error(dev, "A/D mode1/3 IRQ without DRDY!");
pcl818_ai_cancel(dev, s);
s->async->events |= COMEDI_CB_EOA | COMEDI_CB_ERROR;
comedi_event(dev, s);
return IRQ_HANDLED;
conv_finish:
low = inb(dev->iobase + PCL818_AD_LO);
comedi_buf_put(s->async, ((inb(dev->iobase + PCL818_AD_HI) << 4) | (low >> 4)));
outb(0, dev->iobase + PCL818_CLRINT);
if ((low & 0xf) != devpriv->act_chanlist[devpriv->act_chanlist_pos]) {
printk
("comedi: A/D mode1/3 IRQ - channel dropout %x!=%x !\n",
(low & 0xf),
devpriv->act_chanlist[devpriv->act_chanlist_pos]);
pcl818_ai_cancel(dev, s);
s->async->events |= COMEDI_CB_EOA | COMEDI_CB_ERROR;
comedi_event(dev, s);
return IRQ_HANDLED;
}
devpriv->act_chanlist_pos++;
if (devpriv->act_chanlist_pos >= devpriv->act_chanlist_len)
devpriv->act_chanlist_pos = 0;
s->async->cur_chan++;
if (s->async->cur_chan >= devpriv->ai_n_chan) {
s->async->cur_chan = 0;
devpriv->ai_act_scan--;
}
if (!devpriv->neverending_ai) {
if (devpriv->ai_act_scan == 0) {
pcl818_ai_cancel(dev, s);
s->async->events |= COMEDI_CB_EOA;
}
}
comedi_event(dev, s);
return IRQ_HANDLED;
}
static irqreturn_t interrupt_pcl818_ai_mode13_dma(int irq, void *d)
{
struct comedi_device *dev = d;
struct pcl818_private *devpriv = dev->private;
struct comedi_subdevice *s = &dev->subdevices[0];
int i, len, bufptr;
unsigned long flags;
short *ptr;
disable_dma(devpriv->dma);
devpriv->next_dma_buf = 1 - devpriv->next_dma_buf;
if ((devpriv->dma_runs_to_end) > -1 || devpriv->neverending_ai) {
set_dma_mode(devpriv->dma, DMA_MODE_READ);
flags = claim_dma_lock();
set_dma_addr(devpriv->dma,
devpriv->hwdmaptr[devpriv->next_dma_buf]);
if (devpriv->dma_runs_to_end || devpriv->neverending_ai) {
set_dma_count(devpriv->dma,
devpriv->hwdmasize[devpriv->
next_dma_buf]);
} else {
set_dma_count(devpriv->dma, devpriv->last_dma_run);
}
release_dma_lock(flags);
enable_dma(devpriv->dma);
}
printk("comedi: A/D mode1/3 IRQ \n");
devpriv->dma_runs_to_end--;
outb(0, dev->iobase + PCL818_CLRINT);
ptr = (short *)devpriv->dmabuf[1 - devpriv->next_dma_buf];
len = devpriv->hwdmasize[0] >> 1;
bufptr = 0;
for (i = 0; i < len; i++) {
if ((ptr[bufptr] & 0xf) != devpriv->act_chanlist[devpriv->act_chanlist_pos]) {
printk
("comedi: A/D mode1/3 DMA - channel dropout %d(card)!=%d(chanlist) at %d !\n",
(ptr[bufptr] & 0xf),
devpriv->act_chanlist[devpriv->act_chanlist_pos],
devpriv->act_chanlist_pos);
pcl818_ai_cancel(dev, s);
s->async->events |= COMEDI_CB_EOA | COMEDI_CB_ERROR;
comedi_event(dev, s);
return IRQ_HANDLED;
}
comedi_buf_put(s->async, ptr[bufptr++] >> 4);
devpriv->act_chanlist_pos++;
if (devpriv->act_chanlist_pos >= devpriv->act_chanlist_len)
devpriv->act_chanlist_pos = 0;
s->async->cur_chan++;
if (s->async->cur_chan >= devpriv->ai_n_chan) {
s->async->cur_chan = 0;
devpriv->ai_act_scan--;
}
if (!devpriv->neverending_ai)
if (devpriv->ai_act_scan == 0) {
pcl818_ai_cancel(dev, s);
s->async->events |= COMEDI_CB_EOA;
comedi_event(dev, s);
return IRQ_HANDLED;
}
}
if (len > 0)
comedi_event(dev, s);
return IRQ_HANDLED;
}
static irqreturn_t interrupt_pcl818_ai_mode13_fifo(int irq, void *d)
{
struct comedi_device *dev = d;
struct pcl818_private *devpriv = dev->private;
struct comedi_subdevice *s = &dev->subdevices[0];
int i, len, lo;
outb(0, dev->iobase + PCL818_FI_INTCLR);
lo = inb(dev->iobase + PCL818_FI_STATUS);
if (lo & 4) {
comedi_error(dev, "A/D mode1/3 FIFO overflow!");
pcl818_ai_cancel(dev, s);
s->async->events |= COMEDI_CB_EOA | COMEDI_CB_ERROR;
comedi_event(dev, s);
return IRQ_HANDLED;
}
if (lo & 1) {
comedi_error(dev, "A/D mode1/3 FIFO interrupt without data!");
pcl818_ai_cancel(dev, s);
s->async->events |= COMEDI_CB_EOA | COMEDI_CB_ERROR;
comedi_event(dev, s);
return IRQ_HANDLED;
}
if (lo & 2)
len = 512;
else
len = 0;
for (i = 0; i < len; i++) {
lo = inb(dev->iobase + PCL818_FI_DATALO);
if ((lo & 0xf) != devpriv->act_chanlist[devpriv->act_chanlist_pos]) {
printk
("comedi: A/D mode1/3 FIFO - channel dropout %d!=%d !\n",
(lo & 0xf),
devpriv->act_chanlist[devpriv->act_chanlist_pos]);
pcl818_ai_cancel(dev, s);
s->async->events |= COMEDI_CB_EOA | COMEDI_CB_ERROR;
comedi_event(dev, s);
return IRQ_HANDLED;
}
comedi_buf_put(s->async, (lo >> 4) | (inb(dev->iobase + PCL818_FI_DATAHI) << 4));
devpriv->act_chanlist_pos++;
if (devpriv->act_chanlist_pos >= devpriv->act_chanlist_len)
devpriv->act_chanlist_pos = 0;
s->async->cur_chan++;
if (s->async->cur_chan >= devpriv->ai_n_chan) {
s->async->cur_chan = 0;
devpriv->ai_act_scan--;
}
if (!devpriv->neverending_ai)
if (devpriv->ai_act_scan == 0) {
pcl818_ai_cancel(dev, s);
s->async->events |= COMEDI_CB_EOA;
comedi_event(dev, s);
return IRQ_HANDLED;
}
}
if (len > 0)
comedi_event(dev, s);
return IRQ_HANDLED;
}
static irqreturn_t interrupt_pcl818(int irq, void *d)
{
struct comedi_device *dev = d;
struct pcl818_private *devpriv = dev->private;
if (!dev->attached) {
comedi_error(dev, "premature interrupt");
return IRQ_HANDLED;
}
if (devpriv->irq_blocked && devpriv->irq_was_now_closed) {
if ((devpriv->neverending_ai || (!devpriv->neverending_ai &&
devpriv->ai_act_scan > 0)) &&
(devpriv->ai_mode == INT_TYPE_AI1_DMA ||
devpriv->ai_mode == INT_TYPE_AI3_DMA)) {
struct comedi_subdevice *s = &dev->subdevices[0];
devpriv->ai_act_scan = 0;
devpriv->neverending_ai = 0;
pcl818_ai_cancel(dev, s);
}
outb(0, dev->iobase + PCL818_CLRINT);
return IRQ_HANDLED;
}
switch (devpriv->ai_mode) {
case INT_TYPE_AI1_DMA:
case INT_TYPE_AI3_DMA:
return interrupt_pcl818_ai_mode13_dma(irq, d);
case INT_TYPE_AI1_INT:
case INT_TYPE_AI3_INT:
return interrupt_pcl818_ai_mode13_int(irq, d);
case INT_TYPE_AI1_FIFO:
case INT_TYPE_AI3_FIFO:
return interrupt_pcl818_ai_mode13_fifo(irq, d);
#ifdef PCL818_MODE13_AO
case INT_TYPE_AO1_INT:
case INT_TYPE_AO3_INT:
return interrupt_pcl818_ao_mode13_int(irq, d);
#endif
default:
break;
}
outb(0, dev->iobase + PCL818_CLRINT);
if ((!dev->irq) || (!devpriv->irq_free) || (!devpriv->irq_blocked)
|| (!devpriv->ai_mode)) {
comedi_error(dev, "bad IRQ!");
return IRQ_NONE;
}
comedi_error(dev, "IRQ from unknown source!");
return IRQ_NONE;
}
static void pcl818_ai_mode13dma_int(int mode, struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct pcl818_private *devpriv = dev->private;
unsigned int flags;
unsigned int bytes;
printk("mode13dma_int, mode: %d\n", mode);
disable_dma(devpriv->dma);
bytes = devpriv->hwdmasize[0];
if (!devpriv->neverending_ai) {
bytes = devpriv->ai_n_chan * devpriv->ai_scans * sizeof(short);
devpriv->dma_runs_to_end = bytes / devpriv->hwdmasize[0];
devpriv->last_dma_run = bytes % devpriv->hwdmasize[0];
devpriv->dma_runs_to_end--;
if (devpriv->dma_runs_to_end >= 0)
bytes = devpriv->hwdmasize[0];
}
devpriv->next_dma_buf = 0;
set_dma_mode(devpriv->dma, DMA_MODE_READ);
flags = claim_dma_lock();
clear_dma_ff(devpriv->dma);
set_dma_addr(devpriv->dma, devpriv->hwdmaptr[0]);
set_dma_count(devpriv->dma, bytes);
release_dma_lock(flags);
enable_dma(devpriv->dma);
if (mode == 1) {
devpriv->ai_mode = INT_TYPE_AI1_DMA;
outb(0x87 | (dev->irq << 4), dev->iobase + PCL818_CONTROL);
} else {
devpriv->ai_mode = INT_TYPE_AI3_DMA;
outb(0x86 | (dev->irq << 4), dev->iobase + PCL818_CONTROL);
};
}
static int pcl818_ai_cmd_mode(int mode, struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct pcl818_private *devpriv = dev->private;
struct comedi_cmd *cmd = &s->async->cmd;
int divisor1 = 0, divisor2 = 0;
unsigned int seglen;
dev_dbg(dev->class_dev, "pcl818_ai_cmd_mode()\n");
if (!dev->irq) {
comedi_error(dev, "IRQ not defined!");
return -EINVAL;
}
if (devpriv->irq_blocked)
return -EBUSY;
start_pacer(dev, -1, 0, 0);
seglen = check_channel_list(dev, s, devpriv->ai_chanlist,
devpriv->ai_n_chan);
if (seglen < 1)
return -EINVAL;
setup_channel_list(dev, s, devpriv->ai_chanlist,
devpriv->ai_n_chan, seglen);
udelay(1);
devpriv->ai_act_scan = devpriv->ai_scans;
devpriv->ai_act_chan = 0;
devpriv->irq_blocked = 1;
devpriv->irq_was_now_closed = 0;
devpriv->neverending_ai = 0;
devpriv->act_chanlist_pos = 0;
devpriv->dma_runs_to_end = 0;
if ((devpriv->ai_scans == 0) || (devpriv->ai_scans == -1))
devpriv->neverending_ai = 1;
if (mode == 1) {
i8253_cascade_ns_to_timer(devpriv->i8253_osc_base, &divisor1,
&divisor2, &cmd->convert_arg,
TRIG_ROUND_NEAREST);
if (divisor1 == 1) {
divisor1 = 2;
divisor2 /= 2;
}
if (divisor2 == 1) {
divisor2 = 2;
divisor1 /= 2;
}
}
outb(0, dev->iobase + PCL818_CNTENABLE);
switch (devpriv->dma) {
case 1:
case 3:
pcl818_ai_mode13dma_int(mode, dev, s);
break;
case 0:
if (!devpriv->usefifo) {
if (mode == 1) {
devpriv->ai_mode = INT_TYPE_AI1_INT;
outb(0x83 | (dev->irq << 4),
dev->iobase + PCL818_CONTROL);
} else {
devpriv->ai_mode = INT_TYPE_AI3_INT;
outb(0x82 | (dev->irq << 4),
dev->iobase + PCL818_CONTROL);
}
} else {
outb(1, dev->iobase + PCL818_FI_ENABLE);
if (mode == 1) {
devpriv->ai_mode = INT_TYPE_AI1_FIFO;
outb(0x03, dev->iobase + PCL818_CONTROL);
} else {
devpriv->ai_mode = INT_TYPE_AI3_FIFO;
outb(0x02, dev->iobase + PCL818_CONTROL);
}
}
}
start_pacer(dev, mode, divisor1, divisor2);
dev_dbg(dev->class_dev, "pcl818_ai_cmd_mode() end\n");
return 0;
}
static void start_pacer(struct comedi_device *dev, int mode,
unsigned int divisor1, unsigned int divisor2)
{
outb(0xb4, dev->iobase + PCL818_CTRCTL);
outb(0x74, dev->iobase + PCL818_CTRCTL);
udelay(1);
if (mode == 1) {
outb(divisor2 & 0xff, dev->iobase + PCL818_CTR2);
outb((divisor2 >> 8) & 0xff, dev->iobase + PCL818_CTR2);
outb(divisor1 & 0xff, dev->iobase + PCL818_CTR1);
outb((divisor1 >> 8) & 0xff, dev->iobase + PCL818_CTR1);
}
}
static int check_channel_list(struct comedi_device *dev,
struct comedi_subdevice *s,
unsigned int *chanlist, unsigned int n_chan)
{
unsigned int chansegment[16];
unsigned int i, nowmustbechan, seglen, segpos;
if (n_chan < 1) {
comedi_error(dev, "range/channel list is empty!");
return 0;
}
if (n_chan > 1) {
chansegment[0] = chanlist[0];
for (i = 1, seglen = 1; i < n_chan; i++, seglen++) {
if (chanlist[0] == chanlist[i])
break;
nowmustbechan =
(CR_CHAN(chansegment[i - 1]) + 1) % s->n_chan;
if (nowmustbechan != CR_CHAN(chanlist[i])) {
printk
("comedi%d: pcl818: channel list must be continuous! chanlist[%i]=%d but must be %d or %d!\n",
dev->minor, i, CR_CHAN(chanlist[i]),
nowmustbechan, CR_CHAN(chanlist[0]));
return 0;
}
chansegment[i] = chanlist[i];
}
for (i = 0, segpos = 0; i < n_chan; i++) {
if (chanlist[i] != chansegment[i % seglen]) {
printk
("comedi%d: pcl818: bad channel or range number! chanlist[%i]=%d,%d,%d and not %d,%d,%d!\n",
dev->minor, i, CR_CHAN(chansegment[i]),
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
printk("check_channel_list: seglen %d\n", seglen);
return seglen;
}
static void setup_channel_list(struct comedi_device *dev,
struct comedi_subdevice *s,
unsigned int *chanlist, unsigned int n_chan,
unsigned int seglen)
{
struct pcl818_private *devpriv = dev->private;
int i;
devpriv->act_chanlist_len = seglen;
devpriv->act_chanlist_pos = 0;
for (i = 0; i < seglen; i++) {
devpriv->act_chanlist[i] = CR_CHAN(chanlist[i]);
outb(muxonechan[CR_CHAN(chanlist[i])], dev->iobase + PCL818_MUX);
outb(CR_RANGE(chanlist[i]), dev->iobase + PCL818_RANGE);
}
udelay(1);
outb(devpriv->act_chanlist[0] | (devpriv->act_chanlist[seglen -
1] << 4),
dev->iobase + PCL818_MUX);
}
static int check_single_ended(unsigned int port)
{
if (inb(port + PCL818_STATUS) & 0x20)
return 1;
return 0;
}
static int ai_cmdtest(struct comedi_device *dev, struct comedi_subdevice *s,
struct comedi_cmd *cmd)
{
const struct pcl818_board *board = comedi_board(dev);
struct pcl818_private *devpriv = dev->private;
int err = 0;
int tmp, divisor1 = 0, divisor2 = 0;
err |= cfc_check_trigger_src(&cmd->start_src, TRIG_NOW);
err |= cfc_check_trigger_src(&cmd->scan_begin_src, TRIG_FOLLOW);
err |= cfc_check_trigger_src(&cmd->convert_src, TRIG_TIMER | TRIG_EXT);
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
board->ns_min);
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
i8253_cascade_ns_to_timer(devpriv->i8253_osc_base, &divisor1,
&divisor2, &cmd->convert_arg,
cmd->flags & TRIG_ROUND_MASK);
if (cmd->convert_arg < board->ns_min)
cmd->convert_arg = board->ns_min;
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
static int ai_cmd(struct comedi_device *dev, struct comedi_subdevice *s)
{
struct pcl818_private *devpriv = dev->private;
struct comedi_cmd *cmd = &s->async->cmd;
int retval;
dev_dbg(dev->class_dev, "pcl818_ai_cmd()\n");
devpriv->ai_n_chan = cmd->chanlist_len;
devpriv->ai_chanlist = cmd->chanlist;
devpriv->ai_flags = cmd->flags;
devpriv->ai_data_len = s->async->prealloc_bufsz;
devpriv->ai_data = s->async->prealloc_buf;
devpriv->ai_timer1 = 0;
devpriv->ai_timer2 = 0;
if (cmd->stop_src == TRIG_COUNT)
devpriv->ai_scans = cmd->stop_arg;
else
devpriv->ai_scans = 0;
if (cmd->scan_begin_src == TRIG_FOLLOW) {
if (cmd->convert_src == TRIG_TIMER) {
devpriv->ai_timer1 = cmd->convert_arg;
retval = pcl818_ai_cmd_mode(1, dev, s);
dev_dbg(dev->class_dev, "pcl818_ai_cmd() end\n");
return retval;
}
if (cmd->convert_src == TRIG_EXT) {
return pcl818_ai_cmd_mode(3, dev, s);
}
}
return -1;
}
static int pcl818_ai_cancel(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct pcl818_private *devpriv = dev->private;
if (devpriv->irq_blocked > 0) {
dev_dbg(dev->class_dev, "pcl818_ai_cancel()\n");
devpriv->irq_was_now_closed = 1;
switch (devpriv->ai_mode) {
case INT_TYPE_AI1_DMA:
case INT_TYPE_AI3_DMA:
if (devpriv->neverending_ai ||
(!devpriv->neverending_ai &&
devpriv->ai_act_scan > 0)) {
goto end;
}
disable_dma(devpriv->dma);
case INT_TYPE_AI1_INT:
case INT_TYPE_AI3_INT:
case INT_TYPE_AI1_FIFO:
case INT_TYPE_AI3_FIFO:
#ifdef PCL818_MODE13_AO
case INT_TYPE_AO1_INT:
case INT_TYPE_AO3_INT:
#endif
outb(inb(dev->iobase + PCL818_CONTROL) & 0x73, dev->iobase + PCL818_CONTROL);
udelay(1);
start_pacer(dev, -1, 0, 0);
outb(0, dev->iobase + PCL818_AD_LO);
inb(dev->iobase + PCL818_AD_LO);
inb(dev->iobase + PCL818_AD_HI);
outb(0, dev->iobase + PCL818_CLRINT);
outb(0, dev->iobase + PCL818_CONTROL);
if (devpriv->usefifo) {
outb(0, dev->iobase + PCL818_FI_INTCLR);
outb(0, dev->iobase + PCL818_FI_FLUSH);
outb(0, dev->iobase + PCL818_FI_ENABLE);
}
devpriv->irq_blocked = 0;
devpriv->last_int_sub = s;
devpriv->neverending_ai = 0;
devpriv->ai_mode = 0;
devpriv->irq_was_now_closed = 0;
break;
}
}
end:
dev_dbg(dev->class_dev, "pcl818_ai_cancel() end\n");
return 0;
}
static int pcl818_check(unsigned long iobase)
{
outb(0x00, iobase + PCL818_MUX);
udelay(1);
if (inb(iobase + PCL818_MUX) != 0x00)
return 1;
outb(0x55, iobase + PCL818_MUX);
udelay(1);
if (inb(iobase + PCL818_MUX) != 0x55)
return 1;
outb(0x00, iobase + PCL818_MUX);
udelay(1);
outb(0x18, iobase + PCL818_CONTROL);
udelay(1);
if (inb(iobase + PCL818_CONTROL) != 0x18)
return 1;
return 0;
}
static void pcl818_reset(struct comedi_device *dev)
{
const struct pcl818_board *board = comedi_board(dev);
struct pcl818_private *devpriv = dev->private;
if (devpriv->usefifo) {
outb(0, dev->iobase + PCL818_FI_INTCLR);
outb(0, dev->iobase + PCL818_FI_FLUSH);
outb(0, dev->iobase + PCL818_FI_ENABLE);
}
outb(0, dev->iobase + PCL818_DA_LO);
outb(0, dev->iobase + PCL818_DA_HI);
udelay(1);
outb(0, dev->iobase + PCL818_DO_HI);
outb(0, dev->iobase + PCL818_DO_LO);
udelay(1);
outb(0, dev->iobase + PCL818_CONTROL);
outb(0, dev->iobase + PCL818_CNTENABLE);
outb(0, dev->iobase + PCL818_MUX);
outb(0, dev->iobase + PCL818_CLRINT);
outb(0xb0, dev->iobase + PCL818_CTRCTL);
outb(0x70, dev->iobase + PCL818_CTRCTL);
outb(0x30, dev->iobase + PCL818_CTRCTL);
if (board->is_818) {
outb(0, dev->iobase + PCL818_RANGE);
} else {
outb(0, dev->iobase + PCL718_DA2_LO);
outb(0, dev->iobase + PCL718_DA2_HI);
}
}
static int pcl818_attach(struct comedi_device *dev, struct comedi_devconfig *it)
{
const struct pcl818_board *board = comedi_board(dev);
struct pcl818_private *devpriv;
int ret;
unsigned int irq;
int dma;
unsigned long pages;
struct comedi_subdevice *s;
devpriv = comedi_alloc_devpriv(dev, sizeof(*devpriv));
if (!devpriv)
return -ENOMEM;
devpriv->io_range = board->io_range;
if ((board->fifo) && (it->options[2] == -1)) {
devpriv->io_range = PCLx1xFIFO_RANGE;
devpriv->usefifo = 1;
}
ret = comedi_request_region(dev, it->options[0], devpriv->io_range);
if (ret)
return ret;
if (pcl818_check(dev->iobase)) {
comedi_error(dev, "I can't detect board. FAIL!\n");
return -EIO;
}
irq = 0;
if (board->IRQbits != 0) {
irq = it->options[1];
if (irq) {
if (((1 << irq) & board->IRQbits) == 0) {
printk
(", IRQ %u is out of allowed range, DISABLING IT",
irq);
irq = 0;
} else {
if (request_irq(irq, interrupt_pcl818, 0,
dev->board_name, dev)) {
printk
(", unable to allocate IRQ %u, DISABLING IT",
irq);
irq = 0;
} else {
printk(KERN_DEBUG "irq=%u", irq);
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
devpriv->ai_mode = 0;
dma = 0;
devpriv->dma = dma;
if (!devpriv->irq_free)
goto no_dma;
if (board->DMAbits != 0) {
dma = it->options[2];
if (dma < 1)
goto no_dma;
if (((1 << dma) & board->DMAbits) == 0) {
printk(KERN_ERR "DMA is out of allowed range, FAIL!\n");
return -EINVAL;
}
ret = request_dma(dma, dev->board_name);
if (ret)
return -EBUSY;
devpriv->dma = dma;
pages = 2;
devpriv->dmabuf[0] = __get_dma_pages(GFP_KERNEL, pages);
if (!devpriv->dmabuf[0])
return -EBUSY;
devpriv->dmapages[0] = pages;
devpriv->hwdmaptr[0] = virt_to_bus((void *)devpriv->dmabuf[0]);
devpriv->hwdmasize[0] = (1 << pages) * PAGE_SIZE;
devpriv->dmabuf[1] = __get_dma_pages(GFP_KERNEL, pages);
if (!devpriv->dmabuf[1])
return -EBUSY;
devpriv->dmapages[1] = pages;
devpriv->hwdmaptr[1] = virt_to_bus((void *)devpriv->dmabuf[1]);
devpriv->hwdmasize[1] = (1 << pages) * PAGE_SIZE;
}
no_dma:
ret = comedi_alloc_subdevices(dev, 4);
if (ret)
return ret;
s = &dev->subdevices[0];
if (!board->n_aichan_se) {
s->type = COMEDI_SUBD_UNUSED;
} else {
s->type = COMEDI_SUBD_AI;
devpriv->sub_ai = s;
s->subdev_flags = SDF_READABLE;
if (check_single_ended(dev->iobase)) {
s->n_chan = board->n_aichan_se;
s->subdev_flags |= SDF_COMMON | SDF_GROUND;
printk(", %dchans S.E. DAC", s->n_chan);
} else {
s->n_chan = board->n_aichan_diff;
s->subdev_flags |= SDF_DIFF;
printk(", %dchans DIFF DAC", s->n_chan);
}
s->maxdata = board->ai_maxdata;
s->len_chanlist = s->n_chan;
s->range_table = board->ai_range_type;
s->cancel = pcl818_ai_cancel;
s->insn_read = pcl818_ai_insn_read;
if (irq) {
dev->read_subdev = s;
s->subdev_flags |= SDF_CMD_READ;
s->do_cmdtest = ai_cmdtest;
s->do_cmd = ai_cmd;
}
if (board->is_818) {
if ((it->options[4] == 1) || (it->options[4] == 10))
s->range_table = &range_pcl818l_h_ai;
} else {
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
s->range_table = &range718_bipolar1;
break;
case 4:
s->range_table = &range718_bipolar0_5;
break;
case 6:
s->range_table = &range_unipolar10;
break;
case 7:
s->range_table = &range_unipolar5;
break;
case 8:
s->range_table = &range718_unipolar2;
break;
case 9:
s->range_table = &range718_unipolar1;
break;
default:
s->range_table = &range_unknown;
break;
}
}
}
s = &dev->subdevices[1];
if (!board->n_aochan) {
s->type = COMEDI_SUBD_UNUSED;
} else {
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITABLE | SDF_GROUND;
s->n_chan = board->n_aochan;
s->maxdata = board->ao_maxdata;
s->len_chanlist = board->n_aochan;
s->range_table = board->ao_range_type;
s->insn_read = pcl818_ao_insn_read;
s->insn_write = pcl818_ao_insn_write;
if (board->is_818) {
if ((it->options[4] == 1) || (it->options[4] == 10))
s->range_table = &range_unipolar10;
if (it->options[4] == 2)
s->range_table = &range_unknown;
} else {
if ((it->options[5] == 1) || (it->options[5] == 10))
s->range_table = &range_unipolar10;
if (it->options[5] == 2)
s->range_table = &range_unknown;
}
}
s = &dev->subdevices[2];
if (!board->n_dichan) {
s->type = COMEDI_SUBD_UNUSED;
} else {
s->type = COMEDI_SUBD_DI;
s->subdev_flags = SDF_READABLE;
s->n_chan = board->n_dichan;
s->maxdata = 1;
s->len_chanlist = board->n_dichan;
s->range_table = &range_digital;
s->insn_bits = pcl818_di_insn_bits;
}
s = &dev->subdevices[3];
if (!board->n_dochan) {
s->type = COMEDI_SUBD_UNUSED;
} else {
s->type = COMEDI_SUBD_DO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = board->n_dochan;
s->maxdata = 1;
s->len_chanlist = board->n_dochan;
s->range_table = &range_digital;
s->insn_bits = pcl818_do_insn_bits;
}
if ((it->options[3] == 0) || (it->options[3] == 10))
devpriv->i8253_osc_base = 100;
else
devpriv->i8253_osc_base = 1000;
devpriv->ns_min = board->ns_min;
if (!board->is_818) {
if ((it->options[6] == 1) || (it->options[6] == 100))
devpriv->ns_min = 10000;
}
pcl818_reset(dev);
printk("\n");
return 0;
}
static void pcl818_detach(struct comedi_device *dev)
{
struct pcl818_private *devpriv = dev->private;
if (devpriv) {
pcl818_ai_cancel(dev, devpriv->sub_ai);
pcl818_reset(dev);
if (devpriv->dma)
free_dma(devpriv->dma);
if (devpriv->dmabuf[0])
free_pages(devpriv->dmabuf[0], devpriv->dmapages[0]);
if (devpriv->dmabuf[1])
free_pages(devpriv->dmabuf[1], devpriv->dmapages[1]);
}
comedi_legacy_detach(dev);
}
