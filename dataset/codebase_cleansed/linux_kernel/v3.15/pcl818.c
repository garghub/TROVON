static void pcl818_start_pacer(struct comedi_device *dev, bool load_counters)
{
struct pcl818_private *devpriv = dev->private;
unsigned long timer_base = dev->iobase + PCL818_TIMER_BASE;
i8254_set_mode(timer_base, 0, 2, I8254_MODE2 | I8254_BINARY);
i8254_set_mode(timer_base, 0, 1, I8254_MODE2 | I8254_BINARY);
udelay(1);
if (load_counters) {
i8254_write(timer_base, 0, 2, devpriv->divisor2);
i8254_write(timer_base, 0, 1, devpriv->divisor1);
}
}
static void pcl818_ai_setup_dma(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct pcl818_private *devpriv = dev->private;
struct comedi_cmd *cmd = &s->async->cmd;
unsigned int flags;
unsigned int bytes;
disable_dma(devpriv->dma);
bytes = devpriv->hwdmasize;
if (cmd->stop_src == TRIG_COUNT) {
bytes = cmd->chanlist_len * cmd->stop_arg * sizeof(short);
devpriv->dma_runs_to_end = bytes / devpriv->hwdmasize;
devpriv->last_dma_run = bytes % devpriv->hwdmasize;
devpriv->dma_runs_to_end--;
if (devpriv->dma_runs_to_end >= 0)
bytes = devpriv->hwdmasize;
}
devpriv->next_dma_buf = 0;
set_dma_mode(devpriv->dma, DMA_MODE_READ);
flags = claim_dma_lock();
clear_dma_ff(devpriv->dma);
set_dma_addr(devpriv->dma, devpriv->hwdmaptr[0]);
set_dma_count(devpriv->dma, bytes);
release_dma_lock(flags);
enable_dma(devpriv->dma);
}
static void pcl818_ai_setup_next_dma(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct pcl818_private *devpriv = dev->private;
struct comedi_cmd *cmd = &s->async->cmd;
unsigned long flags;
disable_dma(devpriv->dma);
devpriv->next_dma_buf = 1 - devpriv->next_dma_buf;
if (devpriv->dma_runs_to_end > -1 || cmd->stop_src == TRIG_NONE) {
set_dma_mode(devpriv->dma, DMA_MODE_READ);
flags = claim_dma_lock();
set_dma_addr(devpriv->dma,
devpriv->hwdmaptr[devpriv->next_dma_buf]);
if (devpriv->dma_runs_to_end || cmd->stop_src == TRIG_NONE)
set_dma_count(devpriv->dma, devpriv->hwdmasize);
else
set_dma_count(devpriv->dma, devpriv->last_dma_run);
release_dma_lock(flags);
enable_dma(devpriv->dma);
}
devpriv->dma_runs_to_end--;
}
static void pcl818_ai_set_chan_range(struct comedi_device *dev,
unsigned int chan,
unsigned int range)
{
outb(chan, dev->iobase + PCL818_MUX_REG);
outb(range, dev->iobase + PCL818_RANGE_REG);
}
static void pcl818_ai_set_chan_scan(struct comedi_device *dev,
unsigned int first_chan,
unsigned int last_chan)
{
outb(PCL818_MUX_SCAN(first_chan, last_chan),
dev->iobase + PCL818_MUX_REG);
}
static void pcl818_ai_setup_chanlist(struct comedi_device *dev,
unsigned int *chanlist,
unsigned int seglen)
{
struct pcl818_private *devpriv = dev->private;
unsigned int first_chan = CR_CHAN(chanlist[0]);
unsigned int last_chan;
unsigned int range;
int i;
devpriv->act_chanlist_len = seglen;
devpriv->act_chanlist_pos = 0;
for (i = 0; i < seglen; i++) {
last_chan = CR_CHAN(chanlist[i]);
range = CR_RANGE(chanlist[i]);
devpriv->act_chanlist[i] = last_chan;
pcl818_ai_set_chan_range(dev, last_chan, range);
}
udelay(1);
pcl818_ai_set_chan_scan(dev, first_chan, last_chan);
}
static void pcl818_ai_clear_eoc(struct comedi_device *dev)
{
outb(0, dev->iobase + PCL818_STATUS_REG);
}
static void pcl818_ai_soft_trig(struct comedi_device *dev)
{
outb(0, dev->iobase + PCL818_AI_LSB_REG);
}
static unsigned int pcl818_ai_get_fifo_sample(struct comedi_device *dev,
struct comedi_subdevice *s,
unsigned int *chan)
{
unsigned int val;
val = inb(dev->iobase + PCL818_FI_DATALO);
val |= (inb(dev->iobase + PCL818_FI_DATAHI) << 8);
if (chan)
*chan = val & 0xf;
return (val >> 4) & s->maxdata;
}
static unsigned int pcl818_ai_get_sample(struct comedi_device *dev,
struct comedi_subdevice *s,
unsigned int *chan)
{
unsigned int val;
val = inb(dev->iobase + PCL818_AI_MSB_REG) << 8;
val |= inb(dev->iobase + PCL818_AI_LSB_REG);
if (chan)
*chan = val & 0xf;
return (val >> 4) & s->maxdata;
}
static int pcl818_ai_eoc(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned long context)
{
unsigned int status;
status = inb(dev->iobase + PCL818_STATUS_REG);
if (status & PCL818_STATUS_INT)
return 0;
return -EBUSY;
}
static bool pcl818_ai_dropout(struct comedi_device *dev,
struct comedi_subdevice *s,
unsigned int chan)
{
struct pcl818_private *devpriv = dev->private;
unsigned int expected_chan;
expected_chan = devpriv->act_chanlist[devpriv->act_chanlist_pos];
if (chan != expected_chan) {
dev_dbg(dev->class_dev,
"A/D mode1/3 %s - channel dropout %d!=%d !\n",
(devpriv->dma) ? "DMA" :
(devpriv->usefifo) ? "FIFO" : "IRQ",
chan, expected_chan);
s->async->events |= COMEDI_CB_EOA | COMEDI_CB_ERROR;
return true;
}
return false;
}
static bool pcl818_ai_next_chan(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct pcl818_private *devpriv = dev->private;
struct comedi_cmd *cmd = &s->async->cmd;
s->async->events |= COMEDI_CB_BLOCK;
devpriv->act_chanlist_pos++;
if (devpriv->act_chanlist_pos >= devpriv->act_chanlist_len)
devpriv->act_chanlist_pos = 0;
s->async->cur_chan++;
if (s->async->cur_chan >= cmd->chanlist_len) {
s->async->cur_chan = 0;
devpriv->ai_act_scan--;
s->async->events |= COMEDI_CB_EOS;
}
if (cmd->stop_src == TRIG_COUNT && devpriv->ai_act_scan == 0) {
s->async->events |= COMEDI_CB_EOA;
return false;
}
return true;
}
static void pcl818_handle_eoc(struct comedi_device *dev,
struct comedi_subdevice *s)
{
unsigned int chan;
unsigned int val;
if (pcl818_ai_eoc(dev, s, NULL, 0)) {
comedi_error(dev, "A/D mode1/3 IRQ without DRDY!");
s->async->events |= COMEDI_CB_EOA | COMEDI_CB_ERROR;
return;
}
val = pcl818_ai_get_sample(dev, s, &chan);
if (pcl818_ai_dropout(dev, s, chan))
return;
comedi_buf_put(s->async, val);
pcl818_ai_next_chan(dev, s);
}
static void pcl818_handle_dma(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct pcl818_private *devpriv = dev->private;
unsigned short *ptr;
unsigned int chan;
unsigned int val;
int i, len, bufptr;
pcl818_ai_setup_next_dma(dev, s);
ptr = (unsigned short *)devpriv->dmabuf[1 - devpriv->next_dma_buf];
len = devpriv->hwdmasize >> 1;
bufptr = 0;
for (i = 0; i < len; i++) {
val = ptr[bufptr++];
chan = val & 0xf;
val = (val >> 4) & s->maxdata;
if (pcl818_ai_dropout(dev, s, chan))
break;
comedi_buf_put(s->async, val);
if (!pcl818_ai_next_chan(dev, s))
break;
}
}
static void pcl818_handle_fifo(struct comedi_device *dev,
struct comedi_subdevice *s)
{
unsigned int status;
unsigned int chan;
unsigned int val;
int i, len;
status = inb(dev->iobase + PCL818_FI_STATUS);
if (status & 4) {
comedi_error(dev, "A/D mode1/3 FIFO overflow!");
s->async->events |= COMEDI_CB_EOA | COMEDI_CB_ERROR;
return;
}
if (status & 1) {
comedi_error(dev, "A/D mode1/3 FIFO interrupt without data!");
s->async->events |= COMEDI_CB_EOA | COMEDI_CB_ERROR;
return;
}
if (status & 2)
len = 512;
else
len = 0;
for (i = 0; i < len; i++) {
val = pcl818_ai_get_fifo_sample(dev, s, &chan);
if (pcl818_ai_dropout(dev, s, chan))
break;
comedi_buf_put(s->async, val);
if (!pcl818_ai_next_chan(dev, s))
break;
}
}
static irqreturn_t pcl818_interrupt(int irq, void *d)
{
struct comedi_device *dev = d;
struct pcl818_private *devpriv = dev->private;
struct comedi_subdevice *s = dev->read_subdev;
if (!dev->attached || !devpriv->ai_cmd_running) {
pcl818_ai_clear_eoc(dev);
return IRQ_HANDLED;
}
if (devpriv->ai_cmd_canceled) {
devpriv->ai_act_scan = 0;
s->cancel(dev, s);
return IRQ_HANDLED;
}
if (devpriv->dma)
pcl818_handle_dma(dev, s);
else if (devpriv->usefifo)
pcl818_handle_fifo(dev, s);
else
pcl818_handle_eoc(dev, s);
pcl818_ai_clear_eoc(dev);
cfc_handle_events(dev, s);
return IRQ_HANDLED;
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
dev_dbg(dev->class_dev,
"channel list must be continuous! chanlist[%i]=%d but must be %d or %d!\n",
i, CR_CHAN(chanlist[i]), nowmustbechan,
CR_CHAN(chanlist[0]));
return 0;
}
chansegment[i] = chanlist[i];
}
for (i = 0, segpos = 0; i < n_chan; i++) {
if (chanlist[i] != chansegment[i % seglen]) {
dev_dbg(dev->class_dev,
"bad channel or range number! chanlist[%i]=%d,%d,%d and not %d,%d,%d!\n",
i, CR_CHAN(chansegment[i]),
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
static int check_single_ended(unsigned int port)
{
if (inb(port + PCL818_STATUS_REG) & PCL818_STATUS_MUX)
return 1;
return 0;
}
static int ai_cmdtest(struct comedi_device *dev, struct comedi_subdevice *s,
struct comedi_cmd *cmd)
{
const struct pcl818_board *board = comedi_board(dev);
struct pcl818_private *devpriv = dev->private;
int err = 0;
int tmp;
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
i8253_cascade_ns_to_timer(devpriv->i8253_osc_base,
&devpriv->divisor1,
&devpriv->divisor2,
&cmd->convert_arg, cmd->flags);
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
static int pcl818_ai_cmd(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct pcl818_private *devpriv = dev->private;
struct comedi_cmd *cmd = &s->async->cmd;
unsigned int ctrl = 0;
unsigned int seglen;
if (devpriv->ai_cmd_running)
return -EBUSY;
pcl818_start_pacer(dev, false);
seglen = check_channel_list(dev, s, cmd->chanlist, cmd->chanlist_len);
if (seglen < 1)
return -EINVAL;
pcl818_ai_setup_chanlist(dev, cmd->chanlist, seglen);
devpriv->ai_data_len = s->async->prealloc_bufsz;
devpriv->ai_act_scan = cmd->stop_arg;
devpriv->ai_act_chan = 0;
devpriv->ai_cmd_running = 1;
devpriv->ai_cmd_canceled = 0;
devpriv->act_chanlist_pos = 0;
devpriv->dma_runs_to_end = 0;
if (cmd->convert_src == TRIG_TIMER)
ctrl |= PCL818_CTRL_PACER_TRIG;
else
ctrl |= PCL818_CTRL_EXT_TRIG;
outb(PCL818_CNTENABLE_PACER_ENA, dev->iobase + PCL818_CNTENABLE_REG);
if (devpriv->dma) {
pcl818_ai_setup_dma(dev, s);
ctrl |= PCL818_CTRL_INTE | PCL818_CTRL_IRQ(dev->irq) |
PCL818_CTRL_DMAE;
} else if (devpriv->usefifo) {
outb(1, dev->iobase + PCL818_FI_ENABLE);
} else {
ctrl |= PCL818_CTRL_INTE | PCL818_CTRL_IRQ(dev->irq);
}
outb(ctrl, dev->iobase + PCL818_CTRL_REG);
if (cmd->convert_src == TRIG_TIMER)
pcl818_start_pacer(dev, true);
return 0;
}
static int pcl818_ai_cancel(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct pcl818_private *devpriv = dev->private;
struct comedi_cmd *cmd = &s->async->cmd;
if (!devpriv->ai_cmd_running)
return 0;
if (devpriv->dma) {
if (cmd->stop_src == TRIG_NONE ||
(cmd->stop_src == TRIG_COUNT && devpriv->ai_act_scan > 0)) {
if (!devpriv->ai_cmd_canceled) {
devpriv->ai_cmd_canceled = 1;
return 0;
}
}
disable_dma(devpriv->dma);
}
outb(PCL818_CTRL_DISABLE_TRIG, dev->iobase + PCL818_CTRL_REG);
pcl818_start_pacer(dev, false);
pcl818_ai_clear_eoc(dev);
if (devpriv->usefifo) {
outb(0, dev->iobase + PCL818_FI_INTCLR);
outb(0, dev->iobase + PCL818_FI_FLUSH);
outb(0, dev->iobase + PCL818_FI_ENABLE);
}
devpriv->ai_cmd_running = 0;
devpriv->ai_cmd_canceled = 0;
return 0;
}
static int pcl818_ai_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned int range = CR_RANGE(insn->chanspec);
int ret = 0;
int i;
outb(PCL818_CTRL_SOFT_TRIG, dev->iobase + PCL818_CTRL_REG);
pcl818_ai_set_chan_range(dev, chan, range);
pcl818_ai_set_chan_scan(dev, chan, chan);
for (i = 0; i < insn->n; i++) {
pcl818_ai_clear_eoc(dev);
pcl818_ai_soft_trig(dev);
ret = comedi_timeout(dev, s, insn, pcl818_ai_eoc, 0);
if (ret)
break;
data[i] = pcl818_ai_get_sample(dev, s, NULL);
}
pcl818_ai_clear_eoc(dev);
return ret ? ret : insn->n;
}
static int pcl818_ao_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct pcl818_private *devpriv = dev->private;
unsigned int chan = CR_CHAN(insn->chanspec);
int i;
for (i = 0; i < insn->n; i++) {
devpriv->ao_readback[chan] = data[i];
outb((data[i] & 0x000f) << 4,
dev->iobase + PCL818_AO_LSB_REG(chan));
outb((data[i] & 0x0ff0) >> 4,
dev->iobase + PCL818_AO_MSB_REG(chan));
}
return insn->n;
}
static int pcl818_ao_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct pcl818_private *devpriv = dev->private;
unsigned int chan = CR_CHAN(insn->chanspec);
int i;
for (i = 0; i < insn->n; i++)
data[i] = devpriv->ao_readback[chan];
return insn->n;
}
static int pcl818_di_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
data[1] = inb(dev->iobase + PCL818_DO_DI_LSB_REG) |
(inb(dev->iobase + PCL818_DO_DI_MSB_REG) << 8);
return insn->n;
}
static int pcl818_do_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
if (comedi_dio_update_state(s, data)) {
outb(s->state & 0xff, dev->iobase + PCL818_DO_DI_LSB_REG);
outb((s->state >> 8), dev->iobase + PCL818_DO_DI_MSB_REG);
}
data[1] = s->state;
return insn->n;
}
static void pcl818_reset(struct comedi_device *dev)
{
const struct pcl818_board *board = comedi_board(dev);
unsigned long timer_base = dev->iobase + PCL818_TIMER_BASE;
unsigned int chan;
if (board->has_fifo) {
outb(0, dev->iobase + PCL818_FI_INTCLR);
outb(0, dev->iobase + PCL818_FI_FLUSH);
outb(0, dev->iobase + PCL818_FI_ENABLE);
}
outb(PCL818_CTRL_DISABLE_TRIG, dev->iobase + PCL818_CTRL_REG);
pcl818_ai_clear_eoc(dev);
pcl818_ai_set_chan_range(dev, 0, 0);
outb(PCL818_CNTENABLE_PACER_ENA, dev->iobase + PCL818_CNTENABLE_REG);
i8254_set_mode(timer_base, 0, 2, I8254_MODE0 | I8254_BINARY);
i8254_set_mode(timer_base, 0, 1, I8254_MODE0 | I8254_BINARY);
i8254_set_mode(timer_base, 0, 0, I8254_MODE0 | I8254_BINARY);
for (chan = 0; chan < board->n_aochan; chan++) {
outb(0, dev->iobase + PCL818_AO_LSB_REG(chan));
outb(0, dev->iobase + PCL818_AO_MSB_REG(chan));
}
outb(0, dev->iobase + PCL818_DO_DI_MSB_REG);
outb(0, dev->iobase + PCL818_DO_DI_LSB_REG);
}
static void pcl818_set_ai_range_table(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_devconfig *it)
{
const struct pcl818_board *board = comedi_board(dev);
s->range_table = board->ai_range_type;
if (board->is_818) {
if (it->options[4] == 1 || it->options[4] == 10) {
s->range_table = &range_pcl818l_h_ai;
}
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
static int pcl818_attach(struct comedi_device *dev, struct comedi_devconfig *it)
{
const struct pcl818_board *board = comedi_board(dev);
struct pcl818_private *devpriv;
struct comedi_subdevice *s;
int ret;
int i;
devpriv = comedi_alloc_devpriv(dev, sizeof(*devpriv));
if (!devpriv)
return -ENOMEM;
ret = comedi_request_region(dev, it->options[0],
board->has_fifo ? 0x20 : 0x10);
if (ret)
return ret;
if (it->options[1] >= 2 && it->options[1] <= 7) {
ret = request_irq(it->options[1], pcl818_interrupt, 0,
dev->board_name, dev);
if (ret == 0)
dev->irq = it->options[1];
}
if (dev->irq && board->has_fifo && it->options[2] == -1)
devpriv->usefifo = 1;
if (dev->irq && board->has_dma &&
(it->options[2] == 3 || it->options[2] == 1)) {
ret = request_dma(it->options[2], dev->board_name);
if (ret) {
dev_err(dev->class_dev,
"unable to request DMA channel %d\n",
it->options[2]);
return -EBUSY;
}
devpriv->dma = it->options[2];
devpriv->dmapages = 2;
devpriv->hwdmasize = (1 << devpriv->dmapages) * PAGE_SIZE;
for (i = 0; i < 2; i++) {
unsigned long dmabuf;
dmabuf = __get_dma_pages(GFP_KERNEL, devpriv->dmapages);
if (!dmabuf)
return -ENOMEM;
devpriv->dmabuf[i] = dmabuf;
devpriv->hwdmaptr[i] = virt_to_bus((void *)dmabuf);
}
}
ret = comedi_alloc_subdevices(dev, 4);
if (ret)
return ret;
s = &dev->subdevices[0];
s->type = COMEDI_SUBD_AI;
s->subdev_flags = SDF_READABLE;
if (check_single_ended(dev->iobase)) {
s->n_chan = 16;
s->subdev_flags |= SDF_COMMON | SDF_GROUND;
} else {
s->n_chan = 8;
s->subdev_flags |= SDF_DIFF;
}
s->maxdata = 0x0fff;
pcl818_set_ai_range_table(dev, s, it);
s->insn_read = pcl818_ai_insn_read;
if (dev->irq) {
dev->read_subdev = s;
s->subdev_flags |= SDF_CMD_READ;
s->len_chanlist = s->n_chan;
s->do_cmdtest = ai_cmdtest;
s->do_cmd = pcl818_ai_cmd;
s->cancel = pcl818_ai_cancel;
}
s = &dev->subdevices[1];
if (board->n_aochan) {
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITABLE | SDF_GROUND;
s->n_chan = board->n_aochan;
s->maxdata = 0x0fff;
s->range_table = &range_unipolar5;
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
} else {
s->type = COMEDI_SUBD_UNUSED;
}
s = &dev->subdevices[2];
s->type = COMEDI_SUBD_DI;
s->subdev_flags = SDF_READABLE;
s->n_chan = 16;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = pcl818_di_insn_bits;
s = &dev->subdevices[3];
s->type = COMEDI_SUBD_DO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = 16;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = pcl818_do_insn_bits;
if ((it->options[3] == 0) || (it->options[3] == 10))
devpriv->i8253_osc_base = I8254_OSC_BASE_10MHZ;
else
devpriv->i8253_osc_base = I8254_OSC_BASE_1MHZ;
devpriv->ns_min = board->ns_min;
if (!board->is_818) {
if ((it->options[6] == 1) || (it->options[6] == 100))
devpriv->ns_min = 10000;
}
pcl818_reset(dev);
return 0;
}
static void pcl818_detach(struct comedi_device *dev)
{
struct pcl818_private *devpriv = dev->private;
if (devpriv) {
pcl818_ai_cancel(dev, dev->read_subdev);
pcl818_reset(dev);
if (devpriv->dma)
free_dma(devpriv->dma);
if (devpriv->dmabuf[0])
free_pages(devpriv->dmabuf[0], devpriv->dmapages);
if (devpriv->dmabuf[1])
free_pages(devpriv->dmabuf[1], devpriv->dmapages);
}
comedi_legacy_detach(dev);
}
