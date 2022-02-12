static inline int timer_period(void)
{
return HZ / 20;
}
static void das16_ai_setup_dma(struct comedi_device *dev,
struct comedi_subdevice *s,
unsigned int unread_samples)
{
struct das16_private_struct *devpriv = dev->private;
struct comedi_isadma *dma = devpriv->dma;
struct comedi_isadma_desc *desc = &dma->desc[dma->cur_dma];
unsigned int max_samples = comedi_bytes_to_samples(s, desc->maxsize);
unsigned int nsamples;
nsamples = comedi_nsamples_left(s, max_samples + unread_samples);
if (nsamples > unread_samples) {
nsamples -= unread_samples;
desc->size = comedi_samples_to_bytes(s, nsamples);
comedi_isadma_program(desc);
}
}
static void das16_interrupt(struct comedi_device *dev)
{
struct das16_private_struct *devpriv = dev->private;
struct comedi_subdevice *s = dev->read_subdev;
struct comedi_async *async = s->async;
struct comedi_cmd *cmd = &async->cmd;
struct comedi_isadma *dma = devpriv->dma;
struct comedi_isadma_desc *desc = &dma->desc[dma->cur_dma];
unsigned long spin_flags;
unsigned int residue;
unsigned int nbytes;
unsigned int nsamples;
spin_lock_irqsave(&dev->spinlock, spin_flags);
if (!(devpriv->ctrl_reg & DAS16_CTRL_DMAE)) {
spin_unlock_irqrestore(&dev->spinlock, spin_flags);
return;
}
residue = comedi_isadma_disable_on_sample(desc->chan,
comedi_bytes_per_sample(s));
if (residue > desc->size) {
dev_err(dev->class_dev, "residue > transfer size!\n");
async->events |= COMEDI_CB_ERROR;
nbytes = 0;
} else {
nbytes = desc->size - residue;
}
nsamples = comedi_bytes_to_samples(s, nbytes);
if (nsamples) {
dma->cur_dma = 1 - dma->cur_dma;
das16_ai_setup_dma(dev, s, nsamples);
}
spin_unlock_irqrestore(&dev->spinlock, spin_flags);
comedi_buf_write_samples(s, desc->virt_addr, nsamples);
if (cmd->stop_src == TRIG_COUNT && async->scans_done >= cmd->stop_arg)
async->events |= COMEDI_CB_EOA;
comedi_handle_events(dev, s);
}
static void das16_timer_interrupt(unsigned long arg)
{
struct comedi_device *dev = (struct comedi_device *)arg;
struct das16_private_struct *devpriv = dev->private;
unsigned long flags;
das16_interrupt(dev);
spin_lock_irqsave(&dev->spinlock, flags);
if (devpriv->timer_running)
mod_timer(&devpriv->timer, jiffies + timer_period());
spin_unlock_irqrestore(&dev->spinlock, flags);
}
static void das16_ai_set_mux_range(struct comedi_device *dev,
unsigned int first_chan,
unsigned int last_chan,
unsigned int range)
{
const struct das16_board *board = dev->board_ptr;
outb(first_chan | (last_chan << 4), dev->iobase + DAS16_MUX_REG);
if (board->ai_pg == das16_pg_none)
return;
outb((das16_gainlists[board->ai_pg])[range],
dev->iobase + DAS16_GAIN_REG);
}
static int das16_ai_check_chanlist(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_cmd *cmd)
{
unsigned int chan0 = CR_CHAN(cmd->chanlist[0]);
unsigned int range0 = CR_RANGE(cmd->chanlist[0]);
int i;
for (i = 1; i < cmd->chanlist_len; i++) {
unsigned int chan = CR_CHAN(cmd->chanlist[i]);
unsigned int range = CR_RANGE(cmd->chanlist[i]);
if (chan != ((chan0 + i) % s->n_chan)) {
dev_dbg(dev->class_dev,
"entries in chanlist must be consecutive channels, counting upwards\n");
return -EINVAL;
}
if (range != range0) {
dev_dbg(dev->class_dev,
"entries in chanlist must all have the same gain\n");
return -EINVAL;
}
}
return 0;
}
static int das16_cmd_test(struct comedi_device *dev, struct comedi_subdevice *s,
struct comedi_cmd *cmd)
{
const struct das16_board *board = dev->board_ptr;
struct das16_private_struct *devpriv = dev->private;
int err = 0;
unsigned int trig_mask;
unsigned int arg;
err |= cfc_check_trigger_src(&cmd->start_src, TRIG_NOW);
trig_mask = TRIG_FOLLOW;
if (devpriv->can_burst)
trig_mask |= TRIG_TIMER | TRIG_EXT;
err |= cfc_check_trigger_src(&cmd->scan_begin_src, trig_mask);
trig_mask = TRIG_TIMER | TRIG_EXT;
if (devpriv->can_burst)
trig_mask |= TRIG_NOW;
err |= cfc_check_trigger_src(&cmd->convert_src, trig_mask);
err |= cfc_check_trigger_src(&cmd->scan_end_src, TRIG_COUNT);
err |= cfc_check_trigger_src(&cmd->stop_src, TRIG_COUNT | TRIG_NONE);
if (err)
return 1;
err |= cfc_check_trigger_is_unique(cmd->scan_begin_src);
err |= cfc_check_trigger_is_unique(cmd->convert_src);
err |= cfc_check_trigger_is_unique(cmd->stop_src);
if (cmd->scan_begin_src == TRIG_FOLLOW && cmd->convert_src == TRIG_NOW)
err |= -EINVAL;
if (cmd->scan_begin_src != TRIG_FOLLOW && cmd->convert_src != TRIG_NOW)
err |= -EINVAL;
if (err)
return 2;
err |= cfc_check_trigger_arg_is(&cmd->start_arg, 0);
if (cmd->scan_begin_src == TRIG_FOLLOW)
err |= cfc_check_trigger_arg_is(&cmd->scan_begin_arg, 0);
err |= cfc_check_trigger_arg_is(&cmd->scan_end_arg, cmd->chanlist_len);
if (cmd->scan_begin_src == TRIG_TIMER)
err |= cfc_check_trigger_arg_min(&cmd->scan_begin_arg,
board->ai_speed * cmd->chanlist_len);
if (cmd->convert_src == TRIG_TIMER)
err |= cfc_check_trigger_arg_min(&cmd->convert_arg,
board->ai_speed);
if (cmd->stop_src == TRIG_COUNT)
err |= cfc_check_trigger_arg_min(&cmd->stop_arg, 1);
else
err |= cfc_check_trigger_arg_is(&cmd->stop_arg, 0);
if (err)
return 3;
if (cmd->scan_begin_src == TRIG_TIMER) {
arg = cmd->scan_begin_arg;
i8253_cascade_ns_to_timer(devpriv->clockbase,
&devpriv->divisor1,
&devpriv->divisor2,
&arg, cmd->flags);
err |= cfc_check_trigger_arg_is(&cmd->scan_begin_arg, arg);
}
if (cmd->convert_src == TRIG_TIMER) {
arg = cmd->convert_arg;
i8253_cascade_ns_to_timer(devpriv->clockbase,
&devpriv->divisor1,
&devpriv->divisor2,
&arg, cmd->flags);
err |= cfc_check_trigger_arg_is(&cmd->convert_arg, arg);
}
if (err)
return 4;
if (cmd->chanlist && cmd->chanlist_len > 0)
err |= das16_ai_check_chanlist(dev, s, cmd);
if (err)
return 5;
return 0;
}
static unsigned int das16_set_pacer(struct comedi_device *dev, unsigned int ns,
unsigned int flags)
{
struct das16_private_struct *devpriv = dev->private;
unsigned long timer_base = dev->iobase + DAS16_TIMER_BASE_REG;
i8253_cascade_ns_to_timer(devpriv->clockbase,
&devpriv->divisor1, &devpriv->divisor2,
&ns, flags);
i8254_set_mode(timer_base, 0, 1, I8254_MODE2 | I8254_BINARY);
i8254_set_mode(timer_base, 0, 2, I8254_MODE2 | I8254_BINARY);
i8254_write(timer_base, 0, 1, devpriv->divisor1);
i8254_write(timer_base, 0, 2, devpriv->divisor2);
return ns;
}
static int das16_cmd_exec(struct comedi_device *dev, struct comedi_subdevice *s)
{
struct das16_private_struct *devpriv = dev->private;
struct comedi_isadma *dma = devpriv->dma;
struct comedi_async *async = s->async;
struct comedi_cmd *cmd = &async->cmd;
unsigned int first_chan = CR_CHAN(cmd->chanlist[0]);
unsigned int last_chan = CR_CHAN(cmd->chanlist[cmd->chanlist_len - 1]);
unsigned int range = CR_RANGE(cmd->chanlist[0]);
unsigned int byte;
unsigned long flags;
if (cmd->flags & CMDF_PRIORITY) {
dev_err(dev->class_dev,
"isa dma transfers cannot be performed with CMDF_PRIORITY, aborting\n");
return -1;
}
if (devpriv->can_burst)
outb(DAS1600_CONV_DISABLE, dev->iobase + DAS1600_CONV_REG);
das16_ai_set_mux_range(dev, first_chan, last_chan, range);
cmd->convert_arg = das16_set_pacer(dev, cmd->convert_arg, cmd->flags);
byte = 0;
if (devpriv->can_burst) {
if (cmd->convert_src == TRIG_NOW) {
outb(DAS1600_BURST_VAL,
dev->iobase + DAS1600_BURST_REG);
byte |= DAS16_PACER_BURST_LEN(cmd->chanlist_len - 1);
} else {
outb(0, dev->iobase + DAS1600_BURST_REG);
}
}
outb(byte, dev->iobase + DAS16_PACER_REG);
dma->cur_dma = 0;
das16_ai_setup_dma(dev, s, 0);
spin_lock_irqsave(&dev->spinlock, flags);
devpriv->timer_running = 1;
devpriv->timer.expires = jiffies + timer_period();
add_timer(&devpriv->timer);
devpriv->ctrl_reg &= ~(DAS16_CTRL_INTE | DAS16_CTRL_PACING_MASK);
devpriv->ctrl_reg |= DAS16_CTRL_DMAE;
if (cmd->convert_src == TRIG_EXT)
devpriv->ctrl_reg |= DAS16_CTRL_EXT_PACER;
else
devpriv->ctrl_reg |= DAS16_CTRL_INT_PACER;
outb(devpriv->ctrl_reg, dev->iobase + DAS16_CTRL_REG);
if (devpriv->can_burst)
outb(0, dev->iobase + DAS1600_CONV_REG);
spin_unlock_irqrestore(&dev->spinlock, flags);
return 0;
}
static int das16_cancel(struct comedi_device *dev, struct comedi_subdevice *s)
{
struct das16_private_struct *devpriv = dev->private;
struct comedi_isadma *dma = devpriv->dma;
unsigned long flags;
spin_lock_irqsave(&dev->spinlock, flags);
devpriv->ctrl_reg &= ~(DAS16_CTRL_INTE | DAS16_CTRL_DMAE |
DAS16_CTRL_PACING_MASK);
outb(devpriv->ctrl_reg, dev->iobase + DAS16_CTRL_REG);
comedi_isadma_disable(dma->chan);
if (devpriv->timer_running) {
devpriv->timer_running = 0;
del_timer(&devpriv->timer);
}
if (devpriv->can_burst)
outb(0, dev->iobase + DAS1600_BURST_REG);
spin_unlock_irqrestore(&dev->spinlock, flags);
return 0;
}
static void das16_ai_munge(struct comedi_device *dev,
struct comedi_subdevice *s, void *array,
unsigned int num_bytes,
unsigned int start_chan_index)
{
unsigned short *data = array;
unsigned int num_samples = comedi_bytes_to_samples(s, num_bytes);
unsigned int i;
for (i = 0; i < num_samples; i++) {
data[i] = le16_to_cpu(data[i]);
if (s->maxdata == 0x0fff)
data[i] >>= 4;
data[i] &= s->maxdata;
}
}
static int das16_ai_eoc(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned long context)
{
unsigned int status;
status = inb(dev->iobase + DAS16_STATUS_REG);
if ((status & DAS16_STATUS_BUSY) == 0)
return 0;
return -EBUSY;
}
static int das16_ai_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned int range = CR_RANGE(insn->chanspec);
unsigned int val;
int ret;
int i;
das16_ai_set_mux_range(dev, chan, chan, range);
for (i = 0; i < insn->n; i++) {
outb_p(0, dev->iobase + DAS16_TRIG_REG);
ret = comedi_timeout(dev, s, insn, das16_ai_eoc, 0);
if (ret)
return ret;
val = inb(dev->iobase + DAS16_AI_MSB_REG) << 8;
val |= inb(dev->iobase + DAS16_AI_LSB_REG);
if (s->maxdata == 0x0fff)
val >>= 4;
val &= s->maxdata;
data[i] = val;
}
return insn->n;
}
static int das16_ao_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned int chan = CR_CHAN(insn->chanspec);
int i;
for (i = 0; i < insn->n; i++) {
unsigned int val = data[i];
s->readback[chan] = val;
val <<= 4;
outb(val & 0xff, dev->iobase + DAS16_AO_LSB_REG(chan));
outb((val >> 8) & 0xff, dev->iobase + DAS16_AO_MSB_REG(chan));
}
return insn->n;
}
static int das16_di_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
data[1] = inb(dev->iobase + DAS16_DIO_REG) & 0xf;
return insn->n;
}
static int das16_do_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
if (comedi_dio_update_state(s, data))
outb(s->state, dev->iobase + DAS16_DIO_REG);
data[1] = s->state;
return insn->n;
}
static int das16_probe(struct comedi_device *dev, struct comedi_devconfig *it)
{
const struct das16_board *board = dev->board_ptr;
int diobits;
diobits = inb(dev->iobase + DAS16_DIO_REG) & 0xf0;
if (board->id != diobits) {
dev_err(dev->class_dev,
"requested board's id bits are incorrect (0x%x != 0x%x)\n",
board->id, diobits);
return -EINVAL;
}
return 0;
}
static void das16_reset(struct comedi_device *dev)
{
outb(0, dev->iobase + DAS16_STATUS_REG);
outb(0, dev->iobase + DAS16_CTRL_REG);
outb(0, dev->iobase + DAS16_PACER_REG);
outb(0, dev->iobase + DAS16_TIMER_BASE_REG + i8254_control_reg);
}
static void das16_alloc_dma(struct comedi_device *dev, unsigned int dma_chan)
{
struct das16_private_struct *devpriv = dev->private;
if (!(dma_chan == 1 || dma_chan == 3))
return;
devpriv->dma = comedi_isadma_alloc(dev, 2, dma_chan, dma_chan,
DAS16_DMA_SIZE, COMEDI_ISADMA_READ);
if (devpriv->dma) {
init_timer(&devpriv->timer);
devpriv->timer.function = das16_timer_interrupt;
devpriv->timer.data = (unsigned long)dev;
}
}
static void das16_free_dma(struct comedi_device *dev)
{
struct das16_private_struct *devpriv = dev->private;
if (devpriv) {
if (devpriv->timer.data)
del_timer_sync(&devpriv->timer);
comedi_isadma_free(devpriv->dma);
}
}
static const struct comedi_lrange *das16_ai_range(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_devconfig *it,
unsigned int pg_type,
unsigned int status)
{
unsigned int min = it->options[4];
unsigned int max = it->options[5];
if (pg_type == das16_pg_none && (min || max)) {
struct comedi_lrange *lrange;
struct comedi_krange *krange;
lrange = comedi_alloc_spriv(s,
sizeof(*lrange) + sizeof(*krange));
if (!lrange)
return &range_unknown;
lrange->length = 1;
krange = lrange->range;
krange->min = min;
krange->max = max;
krange->flags = UNIT_volt;
return lrange;
}
if (status & DAS16_STATUS_UNIPOLAR)
return das16_ai_uni_lranges[pg_type];
return das16_ai_bip_lranges[pg_type];
}
static const struct comedi_lrange *das16_ao_range(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_devconfig *it)
{
unsigned int min = it->options[6];
unsigned int max = it->options[7];
if (min || max) {
struct comedi_lrange *lrange;
struct comedi_krange *krange;
lrange = comedi_alloc_spriv(s,
sizeof(*lrange) + sizeof(*krange));
if (!lrange)
return &range_unknown;
lrange->length = 1;
krange = lrange->range;
krange->min = min;
krange->max = max;
krange->flags = UNIT_volt;
return lrange;
}
return &range_unknown;
}
static int das16_attach(struct comedi_device *dev, struct comedi_devconfig *it)
{
const struct das16_board *board = dev->board_ptr;
struct das16_private_struct *devpriv;
struct comedi_subdevice *s;
unsigned int status;
int ret;
if (it->options[3]) {
if (it->options[3] != 0 &&
it->options[3] != 1 && it->options[3] != 10) {
dev_err(dev->class_dev,
"Invalid option. Master clock must be set to 1 or 10 (MHz)\n");
return -EINVAL;
}
}
devpriv = comedi_alloc_devpriv(dev, sizeof(*devpriv));
if (!devpriv)
return -ENOMEM;
if (board->size < 0x400) {
ret = comedi_request_region(dev, it->options[0], board->size);
if (ret)
return ret;
} else {
ret = comedi_request_region(dev, it->options[0], 0x10);
if (ret)
return ret;
ret = __comedi_request_region(dev, dev->iobase + 0x400,
board->size & 0x3ff);
if (ret)
return ret;
devpriv->extra_iobase = dev->iobase + 0x400;
devpriv->can_burst = 1;
}
if (das16_probe(dev, it))
return -EINVAL;
if (devpriv->can_burst) {
status = inb(dev->iobase + DAS1600_STATUS_REG);
if (status & DAS1600_STATUS_CLK_10MHZ)
devpriv->clockbase = I8254_OSC_BASE_10MHZ;
else
devpriv->clockbase = I8254_OSC_BASE_1MHZ;
} else {
if (it->options[3])
devpriv->clockbase = I8254_OSC_BASE_1MHZ /
it->options[3];
else
devpriv->clockbase = I8254_OSC_BASE_1MHZ;
}
das16_alloc_dma(dev, it->options[2]);
ret = comedi_alloc_subdevices(dev, 4 + board->has_8255);
if (ret)
return ret;
status = inb(dev->iobase + DAS16_STATUS_REG);
s = &dev->subdevices[0];
s->type = COMEDI_SUBD_AI;
s->subdev_flags = SDF_READABLE;
if (status & DAS16_STATUS_MUXBIT) {
s->subdev_flags |= SDF_GROUND;
s->n_chan = 16;
} else {
s->subdev_flags |= SDF_DIFF;
s->n_chan = 8;
}
s->len_chanlist = s->n_chan;
s->maxdata = board->ai_maxdata;
s->range_table = das16_ai_range(dev, s, it, board->ai_pg, status);
s->insn_read = das16_ai_insn_read;
if (devpriv->dma) {
dev->read_subdev = s;
s->subdev_flags |= SDF_CMD_READ;
s->do_cmdtest = das16_cmd_test;
s->do_cmd = das16_cmd_exec;
s->cancel = das16_cancel;
s->munge = das16_ai_munge;
}
s = &dev->subdevices[1];
if (board->has_ao) {
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = 2;
s->maxdata = 0x0fff;
s->range_table = das16_ao_range(dev, s, it);
s->insn_write = das16_ao_insn_write;
ret = comedi_alloc_subdev_readback(s);
if (ret)
return ret;
} else {
s->type = COMEDI_SUBD_UNUSED;
}
s = &dev->subdevices[2];
s->type = COMEDI_SUBD_DI;
s->subdev_flags = SDF_READABLE;
s->n_chan = 4;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = das16_di_insn_bits;
s = &dev->subdevices[3];
s->type = COMEDI_SUBD_DO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = 4;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = das16_do_insn_bits;
outb(s->state, dev->iobase + DAS16_DIO_REG);
if (board->has_8255) {
s = &dev->subdevices[4];
ret = subdev_8255_init(dev, s, NULL, board->i8255_offset);
if (ret)
return ret;
}
das16_reset(dev);
devpriv->ctrl_reg = DAS16_CTRL_IRQ(dev->irq);
outb(devpriv->ctrl_reg, dev->iobase + DAS16_CTRL_REG);
if (devpriv->can_burst) {
outb(DAS1600_ENABLE_VAL, dev->iobase + DAS1600_ENABLE_REG);
outb(0, dev->iobase + DAS1600_CONV_REG);
outb(0, dev->iobase + DAS1600_BURST_REG);
}
return 0;
}
static void das16_detach(struct comedi_device *dev)
{
const struct das16_board *board = dev->board_ptr;
struct das16_private_struct *devpriv = dev->private;
if (devpriv) {
if (dev->iobase)
das16_reset(dev);
das16_free_dma(dev);
if (devpriv->extra_iobase)
release_region(devpriv->extra_iobase,
board->size & 0x3ff);
}
comedi_legacy_detach(dev);
}
