static void pcl812_start_pacer(struct comedi_device *dev, bool load_timers)
{
struct pcl812_private *devpriv = dev->private;
unsigned long timer_base = dev->iobase + PCL812_TIMER_BASE;
i8254_set_mode(timer_base, 0, 2, I8254_MODE2 | I8254_BINARY);
i8254_set_mode(timer_base, 0, 1, I8254_MODE2 | I8254_BINARY);
udelay(1);
if (load_timers) {
i8254_write(timer_base, 0, 2, devpriv->divisor2);
i8254_write(timer_base, 0, 1, devpriv->divisor1);
}
}
static void pcl812_ai_setup_dma(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct pcl812_private *devpriv = dev->private;
struct comedi_cmd *cmd = &s->async->cmd;
unsigned int dma_flags;
unsigned int bytes;
if (devpriv->ai_eos) {
devpriv->dmabytestomove[0] = cfc_bytes_per_scan(s);
devpriv->dmabytestomove[1] = cfc_bytes_per_scan(s);
devpriv->dma_runs_to_end = 1;
} else {
devpriv->dmabytestomove[0] = devpriv->hwdmasize;
devpriv->dmabytestomove[1] = devpriv->hwdmasize;
if (s->async->prealloc_bufsz < devpriv->hwdmasize) {
devpriv->dmabytestomove[0] =
s->async->prealloc_bufsz;
devpriv->dmabytestomove[1] =
s->async->prealloc_bufsz;
}
if (cmd->stop_src == TRIG_NONE) {
devpriv->dma_runs_to_end = 1;
} else {
bytes = cmd->stop_arg * cfc_bytes_per_scan(s);
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
if (devpriv->dmabytestomove[0] > devpriv->hwdmasize) {
devpriv->dmabytestomove[0] = devpriv->hwdmasize;
devpriv->ai_eos = 0;
}
if (devpriv->dmabytestomove[1] > devpriv->hwdmasize) {
devpriv->dmabytestomove[1] = devpriv->hwdmasize;
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
static void pcl812_ai_setup_next_dma(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct pcl812_private *devpriv = dev->private;
unsigned long dma_flags;
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
}
static void pcl812_ai_set_chan_range(struct comedi_device *dev,
unsigned int chanspec, char wait)
{
struct pcl812_private *devpriv = dev->private;
unsigned int chan = CR_CHAN(chanspec);
unsigned int range = CR_RANGE(chanspec);
unsigned int mux = 0;
if (chanspec == devpriv->last_ai_chanspec)
return;
devpriv->last_ai_chanspec = chanspec;
if (devpriv->use_mpc508) {
if (devpriv->use_diff) {
mux |= PCL812_MUX_CS0 | PCL812_MUX_CS1;
} else {
if (chan < 8)
mux |= PCL812_MUX_CS0;
else
mux |= PCL812_MUX_CS1;
}
}
outb(mux | PCL812_MUX_CHAN(chan), dev->iobase + PCL812_MUX_REG);
outb(range + devpriv->range_correction, dev->iobase + PCL812_RANGE_REG);
if (wait)
udelay(devpriv->max_812_ai_mode0_rangewait);
}
static void pcl812_ai_clear_eoc(struct comedi_device *dev)
{
outb(0, dev->iobase + PCL812_STATUS_REG);
}
static void pcl812_ai_soft_trig(struct comedi_device *dev)
{
outb(255, dev->iobase + PCL812_SOFTTRIG_REG);
}
static unsigned int pcl812_ai_get_sample(struct comedi_device *dev,
struct comedi_subdevice *s)
{
unsigned int val;
val = inb(dev->iobase + PCL812_AI_MSB_REG) << 8;
val |= inb(dev->iobase + PCL812_AI_LSB_REG);
return val & s->maxdata;
}
static int pcl812_ai_eoc(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned long context)
{
unsigned int status;
if (s->maxdata > 0x0fff) {
status = inb(dev->iobase + PCL812_STATUS_REG);
if ((status & PCL812_STATUS_DRDY) == 0)
return 0;
} else {
status = inb(dev->iobase + PCL812_AI_MSB_REG);
if ((status & PCL812_AI_MSB_DRDY) == 0)
return 0;
}
return -EBUSY;
}
static int pcl812_ai_cmdtest(struct comedi_device *dev,
struct comedi_subdevice *s, struct comedi_cmd *cmd)
{
const struct pcl812_board *board = dev->board_ptr;
struct pcl812_private *devpriv = dev->private;
int err = 0;
unsigned int flags;
unsigned int arg;
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
err |= cfc_check_trigger_arg_is(&cmd->scan_end_arg, cmd->chanlist_len);
if (cmd->stop_src == TRIG_COUNT)
err |= cfc_check_trigger_arg_min(&cmd->stop_arg, 1);
else
err |= cfc_check_trigger_arg_is(&cmd->stop_arg, 0);
if (err)
return 3;
if (cmd->convert_src == TRIG_TIMER) {
arg = cmd->convert_arg;
i8253_cascade_ns_to_timer(I8254_OSC_BASE_2MHZ,
&devpriv->divisor1,
&devpriv->divisor2,
&arg, cmd->flags);
err |= cfc_check_trigger_arg_is(&cmd->convert_arg, arg);
}
if (err)
return 4;
return 0;
}
static int pcl812_ai_cmd(struct comedi_device *dev, struct comedi_subdevice *s)
{
struct pcl812_private *devpriv = dev->private;
struct comedi_cmd *cmd = &s->async->cmd;
unsigned int ctrl = 0;
unsigned int i;
pcl812_start_pacer(dev, false);
pcl812_ai_set_chan_range(dev, cmd->chanlist[0], 1);
if (devpriv->dma) {
devpriv->ai_dma = 1;
for (i = 1; i < cmd->chanlist_len; i++)
if (cmd->chanlist[0] != cmd->chanlist[i]) {
devpriv->ai_dma = 0;
break;
}
} else {
devpriv->ai_dma = 0;
}
devpriv->ai_act_scan = 0;
devpriv->ai_poll_ptr = 0;
s->async->cur_chan = 0;
if (cmd->flags & CMDF_WAKE_EOS) {
devpriv->ai_eos = 1;
if (cmd->chanlist_len == 1)
devpriv->ai_dma = 0;
}
if (devpriv->ai_dma)
pcl812_ai_setup_dma(dev, s);
switch (cmd->convert_src) {
case TRIG_TIMER:
pcl812_start_pacer(dev, true);
break;
}
if (devpriv->ai_dma)
ctrl |= PCL812_CTRL_PACER_DMA_TRIG;
else
ctrl |= PCL812_CTRL_PACER_EOC_TRIG;
outb(devpriv->mode_reg_int | ctrl, dev->iobase + PCL812_CTRL_REG);
return 0;
}
static bool pcl812_ai_next_chan(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct pcl812_private *devpriv = dev->private;
struct comedi_cmd *cmd = &s->async->cmd;
s->async->events |= COMEDI_CB_BLOCK;
s->async->cur_chan++;
if (s->async->cur_chan >= cmd->chanlist_len) {
s->async->cur_chan = 0;
devpriv->ai_act_scan++;
s->async->events |= COMEDI_CB_EOS;
}
if (cmd->stop_src == TRIG_COUNT &&
devpriv->ai_act_scan >= cmd->stop_arg) {
s->async->events |= COMEDI_CB_EOA;
return false;
}
return true;
}
static void pcl812_handle_eoc(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct comedi_cmd *cmd = &s->async->cmd;
unsigned int next_chan;
if (pcl812_ai_eoc(dev, s, NULL, 0)) {
dev_dbg(dev->class_dev, "A/D cmd IRQ without DRDY!\n");
s->async->events |= COMEDI_CB_EOA | COMEDI_CB_ERROR;
return;
}
comedi_buf_put(s, pcl812_ai_get_sample(dev, s));
next_chan = s->async->cur_chan + 1;
if (next_chan >= cmd->chanlist_len)
next_chan = 0;
if (cmd->chanlist[s->async->cur_chan] != cmd->chanlist[next_chan])
pcl812_ai_set_chan_range(dev, cmd->chanlist[next_chan], 0);
pcl812_ai_next_chan(dev, s);
}
static void transfer_from_dma_buf(struct comedi_device *dev,
struct comedi_subdevice *s,
unsigned short *ptr,
unsigned int bufptr, unsigned int len)
{
unsigned int i;
for (i = len; i; i--) {
comedi_buf_put(s, ptr[bufptr++]);
if (!pcl812_ai_next_chan(dev, s))
break;
}
}
static void pcl812_handle_dma(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct pcl812_private *devpriv = dev->private;
int len, bufptr;
unsigned short *ptr;
ptr = (unsigned short *)devpriv->dmabuf[devpriv->next_dma_buf];
len = (devpriv->dmabytestomove[devpriv->next_dma_buf] >> 1) -
devpriv->ai_poll_ptr;
pcl812_ai_setup_next_dma(dev, s);
bufptr = devpriv->ai_poll_ptr;
devpriv->ai_poll_ptr = 0;
transfer_from_dma_buf(dev, s, ptr, bufptr, len);
}
static irqreturn_t pcl812_interrupt(int irq, void *d)
{
struct comedi_device *dev = d;
struct comedi_subdevice *s = dev->read_subdev;
struct pcl812_private *devpriv = dev->private;
if (!dev->attached) {
pcl812_ai_clear_eoc(dev);
return IRQ_HANDLED;
}
if (devpriv->ai_dma)
pcl812_handle_dma(dev, s);
else
pcl812_handle_eoc(dev, s);
pcl812_ai_clear_eoc(dev);
cfc_handle_events(dev, s);
return IRQ_HANDLED;
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
return comedi_buf_n_bytes_ready(s);
}
static int pcl812_ai_cancel(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct pcl812_private *devpriv = dev->private;
if (devpriv->ai_dma)
disable_dma(devpriv->dma);
outb(devpriv->mode_reg_int | PCL812_CTRL_DISABLE_TRIG,
dev->iobase + PCL812_CTRL_REG);
pcl812_start_pacer(dev, false);
pcl812_ai_clear_eoc(dev);
return 0;
}
static int pcl812_ai_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct pcl812_private *devpriv = dev->private;
int ret = 0;
int i;
outb(devpriv->mode_reg_int | PCL812_CTRL_SOFT_TRIG,
dev->iobase + PCL812_CTRL_REG);
pcl812_ai_set_chan_range(dev, insn->chanspec, 1);
for (i = 0; i < insn->n; i++) {
pcl812_ai_clear_eoc(dev);
pcl812_ai_soft_trig(dev);
ret = comedi_timeout(dev, s, insn, pcl812_ai_eoc, 0);
if (ret)
break;
data[i] = pcl812_ai_get_sample(dev, s);
}
outb(devpriv->mode_reg_int | PCL812_CTRL_DISABLE_TRIG,
dev->iobase + PCL812_CTRL_REG);
pcl812_ai_clear_eoc(dev);
return ret ? ret : insn->n;
}
static int pcl812_ao_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned int val = s->readback[chan];
int i;
for (i = 0; i < insn->n; i++) {
val = data[i];
outb(val & 0xff, dev->iobase + PCL812_AO_LSB_REG(chan));
outb((val >> 8) & 0x0f, dev->iobase + PCL812_AO_MSB_REG(chan));
}
s->readback[chan] = val;
return insn->n;
}
static int pcl812_di_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
data[1] = inb(dev->iobase + PCL812_DI_LSB_REG) |
(inb(dev->iobase + PCL812_DI_MSB_REG) << 8);
return insn->n;
}
static int pcl812_do_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
if (comedi_dio_update_state(s, data)) {
outb(s->state & 0xff, dev->iobase + PCL812_DO_LSB_REG);
outb((s->state >> 8), dev->iobase + PCL812_DO_MSB_REG);
}
data[1] = s->state;
return insn->n;
}
static void pcl812_reset(struct comedi_device *dev)
{
const struct pcl812_board *board = dev->board_ptr;
struct pcl812_private *devpriv = dev->private;
unsigned int chan;
outb(devpriv->mode_reg_int | PCL812_CTRL_DISABLE_TRIG,
dev->iobase + PCL812_CTRL_REG);
pcl812_ai_clear_eoc(dev);
if (board->IRQbits)
pcl812_start_pacer(dev, false);
devpriv->last_ai_chanspec = CR_PACK(16, 0, 0);
pcl812_ai_set_chan_range(dev, CR_PACK(0, 0, 0), 0);
for (chan = 0; chan < board->n_aochan; chan++) {
outb(0, dev->iobase + PCL812_AO_LSB_REG(chan));
outb(0, dev->iobase + PCL812_AO_MSB_REG(chan));
}
if (board->has_dio) {
outb(0, dev->iobase + PCL812_DO_MSB_REG);
outb(0, dev->iobase + PCL812_DO_LSB_REG);
}
}
static void pcl812_set_ai_range_table(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_devconfig *it)
{
const struct pcl812_board *board = dev->board_ptr;
struct pcl812_private *devpriv = dev->private;
s->range_table = board->rangelist_ai;
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
}
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
}
break;
}
}
static int pcl812_attach(struct comedi_device *dev, struct comedi_devconfig *it)
{
const struct pcl812_board *board = dev->board_ptr;
struct pcl812_private *devpriv;
struct comedi_subdevice *s;
int n_subdevices;
int subdev;
int ret;
int i;
devpriv = comedi_alloc_devpriv(dev, sizeof(*devpriv));
if (!devpriv)
return -ENOMEM;
ret = comedi_request_region(dev, it->options[0], 0x10);
if (ret)
return ret;
if ((1 << it->options[1]) & board->IRQbits) {
ret = request_irq(it->options[1], pcl812_interrupt, 0,
dev->board_name, dev);
if (ret == 0)
dev->irq = it->options[1];
}
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
devpriv->dmapages = 1;
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
switch (board->board_type) {
case boardA821:
if (it->options[2] == 1)
devpriv->use_diff = 1;
break;
case boardACL8112:
case boardACL8216:
if (it->options[4] == 1)
devpriv->use_diff = 1;
break;
}
n_subdevices = 1;
if (board->n_aochan > 0)
n_subdevices++;
if (board->has_dio)
n_subdevices += 2;
ret = comedi_alloc_subdevices(dev, n_subdevices);
if (ret)
return ret;
subdev = 0;
s = &dev->subdevices[subdev];
s->type = COMEDI_SUBD_AI;
s->subdev_flags = SDF_READABLE;
if (devpriv->use_diff) {
s->subdev_flags |= SDF_DIFF;
s->n_chan = board->n_aichan / 2;
} else {
s->subdev_flags |= SDF_GROUND;
s->n_chan = board->n_aichan;
}
s->maxdata = board->has_16bit_ai ? 0xffff : 0x0fff;
pcl812_set_ai_range_table(dev, s, it);
s->insn_read = pcl812_ai_insn_read;
if (dev->irq) {
dev->read_subdev = s;
s->subdev_flags |= SDF_CMD_READ;
s->len_chanlist = MAX_CHANLIST_LEN;
s->do_cmdtest = pcl812_ai_cmdtest;
s->do_cmd = pcl812_ai_cmd;
s->poll = pcl812_ai_poll;
s->cancel = pcl812_ai_cancel;
}
devpriv->use_mpc508 = board->has_mpc508_mux;
subdev++;
if (board->n_aochan > 0) {
s = &dev->subdevices[subdev];
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITABLE | SDF_GROUND;
s->n_chan = board->n_aochan;
s->maxdata = 0xfff;
s->range_table = &range_unipolar5;
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
s->insn_write = pcl812_ao_insn_write;
s->insn_read = comedi_readback_insn_read;
ret = comedi_alloc_subdev_readback(s);
if (ret)
return ret;
subdev++;
}
if (board->has_dio) {
s = &dev->subdevices[subdev];
s->type = COMEDI_SUBD_DI;
s->subdev_flags = SDF_READABLE;
s->n_chan = 16;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = pcl812_di_insn_bits;
subdev++;
s = &dev->subdevices[subdev];
s->type = COMEDI_SUBD_DO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = 16;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = pcl812_do_insn_bits;
subdev++;
}
switch (board->board_type) {
case boardACL8216:
case boardPCL812PG:
case boardPCL812:
case boardACL8112:
devpriv->max_812_ai_mode0_rangewait = 1;
if (it->options[3] > 0)
devpriv->use_ext_trg = 1;
break;
case boardA821:
devpriv->max_812_ai_mode0_rangewait = 1;
devpriv->mode_reg_int = (dev->irq << 4) & 0xf0;
break;
case boardPCL813B:
case boardPCL813:
case boardISO813:
case boardACL8113:
devpriv->max_812_ai_mode0_rangewait = 5;
break;
}
pcl812_reset(dev);
return 0;
}
static void pcl812_detach(struct comedi_device *dev)
{
struct pcl812_private *devpriv = dev->private;
if (devpriv) {
if (devpriv->dmabuf[0])
free_pages(devpriv->dmabuf[0], devpriv->dmapages);
if (devpriv->dmabuf[1])
free_pages(devpriv->dmabuf[1], devpriv->dmapages);
if (devpriv->dma)
free_dma(devpriv->dma);
}
comedi_legacy_detach(dev);
}
