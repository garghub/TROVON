static inline int timer_period(void)
{
return HZ / 20;
}
static void das16_ai_enable(struct comedi_device *dev,
unsigned int mode, unsigned int src)
{
struct das16_private_struct *devpriv = dev->private;
devpriv->ctrl_reg &= ~(DAS16_CTRL_INTE |
DAS16_CTRL_DMAE |
DAS16_CTRL_PACING_MASK);
devpriv->ctrl_reg |= mode;
if (src == TRIG_EXT)
devpriv->ctrl_reg |= DAS16_CTRL_EXT_PACER;
else
devpriv->ctrl_reg |= DAS16_CTRL_INT_PACER;
outb(devpriv->ctrl_reg, dev->iobase + DAS16_CTRL_REG);
}
static void das16_ai_disable(struct comedi_device *dev)
{
struct das16_private_struct *devpriv = dev->private;
devpriv->ctrl_reg &= ~(DAS16_CTRL_INTE |
DAS16_CTRL_DMAE |
DAS16_CTRL_PACING_MASK);
outb(devpriv->ctrl_reg, dev->iobase + DAS16_CTRL_REG);
}
static int disable_dma_on_even(struct comedi_device *dev)
{
struct das16_private_struct *devpriv = dev->private;
int residue;
int i;
static const int disable_limit = 100;
static const int enable_timeout = 100;
disable_dma(devpriv->dma_chan);
residue = get_dma_residue(devpriv->dma_chan);
for (i = 0; i < disable_limit && (residue % 2); ++i) {
int j;
enable_dma(devpriv->dma_chan);
for (j = 0; j < enable_timeout; ++j) {
int new_residue;
udelay(2);
new_residue = get_dma_residue(devpriv->dma_chan);
if (new_residue != residue)
break;
}
disable_dma(devpriv->dma_chan);
residue = get_dma_residue(devpriv->dma_chan);
}
if (i == disable_limit) {
dev_err(dev->class_dev,
"failed to get an even dma transfer, could be trouble\n");
}
return residue;
}
static void das16_interrupt(struct comedi_device *dev)
{
struct das16_private_struct *devpriv = dev->private;
struct comedi_subdevice *s = dev->read_subdev;
struct comedi_async *async = s->async;
struct comedi_cmd *cmd = &async->cmd;
unsigned long spin_flags;
unsigned long dma_flags;
int num_bytes, residue;
int buffer_index;
spin_lock_irqsave(&dev->spinlock, spin_flags);
if (!(devpriv->ctrl_reg & DAS16_CTRL_DMAE)) {
spin_unlock_irqrestore(&dev->spinlock, spin_flags);
return;
}
dma_flags = claim_dma_lock();
clear_dma_ff(devpriv->dma_chan);
residue = disable_dma_on_even(dev);
if (residue > devpriv->dma_transfer_size) {
dev_err(dev->class_dev, "residue > transfer size!\n");
async->events |= COMEDI_CB_ERROR | COMEDI_CB_EOA;
num_bytes = 0;
} else
num_bytes = devpriv->dma_transfer_size - residue;
if (cmd->stop_src == TRIG_COUNT &&
num_bytes >= devpriv->adc_byte_count) {
num_bytes = devpriv->adc_byte_count;
async->events |= COMEDI_CB_EOA;
}
buffer_index = devpriv->current_buffer;
devpriv->current_buffer = (devpriv->current_buffer + 1) % 2;
devpriv->adc_byte_count -= num_bytes;
if ((async->events & COMEDI_CB_EOA) == 0) {
set_dma_addr(devpriv->dma_chan,
devpriv->dma_buffer_addr[devpriv->current_buffer]);
set_dma_count(devpriv->dma_chan, devpriv->dma_transfer_size);
enable_dma(devpriv->dma_chan);
}
release_dma_lock(dma_flags);
spin_unlock_irqrestore(&dev->spinlock, spin_flags);
cfc_write_array_to_buffer(s,
devpriv->dma_buffer[buffer_index], num_bytes);
cfc_handle_events(dev, s);
}
static void das16_timer_interrupt(unsigned long arg)
{
struct comedi_device *dev = (struct comedi_device *)arg;
struct das16_private_struct *devpriv = dev->private;
das16_interrupt(dev);
if (devpriv->timer_running)
mod_timer(&devpriv->timer, jiffies + timer_period());
}
static int das16_cmd_test(struct comedi_device *dev, struct comedi_subdevice *s,
struct comedi_cmd *cmd)
{
const struct das16_board *board = comedi_board(dev);
struct das16_private_struct *devpriv = dev->private;
int err = 0, tmp;
int gain, start_chan, i;
int mask;
err |= cfc_check_trigger_src(&cmd->start_src, TRIG_NOW);
mask = TRIG_FOLLOW;
if (devpriv->can_burst)
mask |= TRIG_TIMER | TRIG_EXT;
err |= cfc_check_trigger_src(&cmd->scan_begin_src, mask);
tmp = cmd->convert_src;
mask = TRIG_TIMER | TRIG_EXT;
if (devpriv->can_burst)
mask |= TRIG_NOW;
err |= cfc_check_trigger_src(&cmd->convert_src, mask);
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
if (cmd->stop_src == TRIG_NONE)
err |= cfc_check_trigger_arg_is(&cmd->stop_arg, 0);
if (err)
return 3;
if (cmd->scan_begin_src == TRIG_TIMER) {
unsigned int tmp = cmd->scan_begin_arg;
i8253_cascade_ns_to_timer(devpriv->clockbase,
&devpriv->divisor1,
&devpriv->divisor2,
&cmd->scan_begin_arg, cmd->flags);
err += (tmp != cmd->scan_begin_arg);
}
if (cmd->convert_src == TRIG_TIMER) {
unsigned int tmp = cmd->convert_arg;
i8253_cascade_ns_to_timer(devpriv->clockbase,
&devpriv->divisor1,
&devpriv->divisor2,
&cmd->convert_arg, cmd->flags);
err += (tmp != cmd->convert_arg);
}
if (err)
return 4;
if (cmd->chanlist) {
gain = CR_RANGE(cmd->chanlist[0]);
start_chan = CR_CHAN(cmd->chanlist[0]);
for (i = 1; i < cmd->chanlist_len; i++) {
if (CR_CHAN(cmd->chanlist[i]) !=
(start_chan + i) % s->n_chan) {
dev_err(dev->class_dev,
"entries in chanlist must be consecutive channels, counting upwards\n");
err++;
}
if (CR_RANGE(cmd->chanlist[i]) != gain) {
dev_err(dev->class_dev,
"entries in chanlist must all have the same gain\n");
err++;
}
}
}
if (err)
return 5;
return 0;
}
static unsigned int das16_set_pacer(struct comedi_device *dev, unsigned int ns,
int rounding_flags)
{
struct das16_private_struct *devpriv = dev->private;
unsigned long timer_base = dev->iobase + DAS16_TIMER_BASE_REG;
i8253_cascade_ns_to_timer(devpriv->clockbase,
&devpriv->divisor1, &devpriv->divisor2,
&ns, rounding_flags);
i8254_load(timer_base, 0, 1, devpriv->divisor1, 2);
i8254_load(timer_base, 0, 2, devpriv->divisor2, 2);
return ns;
}
static int das16_cmd_exec(struct comedi_device *dev, struct comedi_subdevice *s)
{
const struct das16_board *board = comedi_board(dev);
struct das16_private_struct *devpriv = dev->private;
struct comedi_async *async = s->async;
struct comedi_cmd *cmd = &async->cmd;
unsigned int byte;
unsigned long flags;
int range;
if (cmd->flags & TRIG_RT) {
dev_err(dev->class_dev,
"isa dma transfers cannot be performed with TRIG_RT, aborting\n");
return -1;
}
devpriv->adc_byte_count =
cmd->stop_arg * cmd->chanlist_len * sizeof(uint16_t);
if (devpriv->can_burst)
outb(DAS1600_CONV_DISABLE, dev->iobase + DAS1600_CONV_REG);
byte = CR_CHAN(cmd->chanlist[0]);
byte |= CR_CHAN(cmd->chanlist[cmd->chanlist_len - 1]) << 4;
outb(byte, dev->iobase + DAS16_MUX_REG);
if (board->ai_pg != das16_pg_none) {
range = CR_RANGE(cmd->chanlist[0]);
outb((das16_gainlists[board->ai_pg])[range],
dev->iobase + DAS16_GAIN_REG);
}
cmd->convert_arg =
das16_set_pacer(dev, cmd->convert_arg,
cmd->flags & TRIG_ROUND_MASK);
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
flags = claim_dma_lock();
disable_dma(devpriv->dma_chan);
clear_dma_ff(devpriv->dma_chan);
devpriv->current_buffer = 0;
set_dma_addr(devpriv->dma_chan,
devpriv->dma_buffer_addr[devpriv->current_buffer]);
devpriv->dma_transfer_size = DAS16_DMA_SIZE;
set_dma_count(devpriv->dma_chan, devpriv->dma_transfer_size);
enable_dma(devpriv->dma_chan);
release_dma_lock(flags);
devpriv->timer_running = 1;
devpriv->timer.expires = jiffies + timer_period();
add_timer(&devpriv->timer);
das16_ai_enable(dev, DAS16_CTRL_DMAE, cmd->convert_src);
if (devpriv->can_burst)
outb(0, dev->iobase + DAS1600_CONV_REG);
return 0;
}
static int das16_cancel(struct comedi_device *dev, struct comedi_subdevice *s)
{
struct das16_private_struct *devpriv = dev->private;
unsigned long flags;
spin_lock_irqsave(&dev->spinlock, flags);
das16_ai_disable(dev);
disable_dma(devpriv->dma_chan);
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
unsigned int i, num_samples = num_bytes / sizeof(short);
unsigned short *data = array;
for (i = 0; i < num_samples; i++) {
data[i] = le16_to_cpu(data[i]);
if (s->maxdata == 0x0fff)
data[i] >>= 4;
data[i] &= s->maxdata;
}
}
static int das16_ai_wait_for_conv(struct comedi_device *dev,
unsigned int timeout)
{
unsigned int status;
int i;
for (i = 0; i < timeout; i++) {
status = inb(dev->iobase + DAS16_STATUS_REG);
if (!(status & DAS16_STATUS_BUSY))
return 0;
}
return -ETIME;
}
static int das16_ai_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
const struct das16_board *board = comedi_board(dev);
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned int range = CR_RANGE(insn->chanspec);
unsigned int val;
int ret;
int i;
das16_ai_disable(dev);
outb(chan | (chan << 4), dev->iobase + DAS16_MUX_REG);
if (board->ai_pg != das16_pg_none) {
outb((das16_gainlists[board->ai_pg])[range],
dev->iobase + DAS16_GAIN_REG);
}
for (i = 0; i < insn->n; i++) {
outb_p(0, dev->iobase + DAS16_TRIG_REG);
ret = das16_ai_wait_for_conv(dev, 1000);
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
unsigned int val;
int i;
for (i = 0; i < insn->n; i++) {
val = data[i];
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
const struct das16_board *board = comedi_board(dev);
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
static int das16_attach(struct comedi_device *dev, struct comedi_devconfig *it)
{
const struct das16_board *board = comedi_board(dev);
struct das16_private_struct *devpriv;
struct comedi_subdevice *s;
struct comedi_lrange *lrange;
struct comedi_krange *krange;
unsigned int dma_chan = it->options[2];
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
if (dma_chan == 1 || dma_chan == 3) {
unsigned long flags;
int i;
if (request_dma(dma_chan, dev->board_name)) {
dev_err(dev->class_dev,
"failed to request dma channel %i\n",
dma_chan);
return -EINVAL;
}
devpriv->dma_chan = dma_chan;
for (i = 0; i < 2; i++) {
void *p;
p = pci_alloc_consistent(NULL, DAS16_DMA_SIZE,
&devpriv->dma_buffer_addr[i]);
if (!p)
return -ENOMEM;
devpriv->dma_buffer[i] = p;
}
flags = claim_dma_lock();
disable_dma(devpriv->dma_chan);
set_dma_mode(devpriv->dma_chan, DMA_MODE_READ);
release_dma_lock(flags);
init_timer(&devpriv->timer);
devpriv->timer.function = das16_timer_interrupt;
devpriv->timer.data = (unsigned long)dev;
}
if (board->ai_pg == das16_pg_none &&
(it->options[4] || it->options[5])) {
lrange = kzalloc(sizeof(*lrange) + sizeof(*krange), GFP_KERNEL);
if (!lrange)
return -ENOMEM;
devpriv->user_ai_range_table = lrange;
lrange->length = 1;
krange = devpriv->user_ai_range_table->range;
krange->min = it->options[4];
krange->max = it->options[5];
krange->flags = UNIT_volt;
}
if (it->options[6] || it->options[7]) {
lrange = kzalloc(sizeof(*lrange) + sizeof(*krange), GFP_KERNEL);
if (!lrange)
return -ENOMEM;
devpriv->user_ao_range_table = lrange;
lrange->length = 1;
krange = devpriv->user_ao_range_table->range;
krange->min = it->options[6];
krange->max = it->options[7];
krange->flags = UNIT_volt;
}
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
if (devpriv->user_ai_range_table) {
s->range_table = devpriv->user_ai_range_table;
} else if (status & DAS16_STATUS_UNIPOLAR) {
s->range_table = das16_ai_uni_lranges[board->ai_pg];
} else {
s->range_table = das16_ai_bip_lranges[board->ai_pg];
}
s->insn_read = das16_ai_insn_read;
if (devpriv->dma_chan) {
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
s->range_table = devpriv->user_ao_range_table;
s->insn_write = das16_ao_insn_write;
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
ret = subdev_8255_init(dev, s, NULL,
dev->iobase + board->i8255_offset);
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
const struct das16_board *board = comedi_board(dev);
struct das16_private_struct *devpriv = dev->private;
int i;
if (devpriv) {
if (dev->iobase)
das16_reset(dev);
for (i = 0; i < 2; i++) {
if (devpriv->dma_buffer[i])
pci_free_consistent(NULL, DAS16_DMA_SIZE,
devpriv->dma_buffer[i],
devpriv->
dma_buffer_addr[i]);
}
if (devpriv->dma_chan)
free_dma(devpriv->dma_chan);
kfree(devpriv->user_ai_range_table);
kfree(devpriv->user_ao_range_table);
if (devpriv->extra_iobase)
release_region(devpriv->extra_iobase,
board->size & 0x3ff);
}
comedi_legacy_detach(dev);
}
