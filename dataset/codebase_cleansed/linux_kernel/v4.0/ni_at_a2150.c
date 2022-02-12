static irqreturn_t a2150_interrupt(int irq, void *d)
{
struct comedi_device *dev = d;
struct a2150_private *devpriv = dev->private;
struct comedi_isadma *dma = devpriv->dma;
struct comedi_isadma_desc *desc = &dma->desc[0];
struct comedi_subdevice *s = dev->read_subdev;
struct comedi_async *async = s->async;
struct comedi_cmd *cmd = &async->cmd;
unsigned short *buf = desc->virt_addr;
unsigned int max_points, num_points, residue, leftover;
unsigned short dpnt;
int status;
int i;
if (!dev->attached)
return IRQ_HANDLED;
status = inw(dev->iobase + STATUS_REG);
if ((status & INTR_BIT) == 0)
return IRQ_NONE;
if (status & OVFL_BIT) {
async->events |= COMEDI_CB_ERROR;
comedi_handle_events(dev, s);
}
if ((status & DMA_TC_BIT) == 0) {
async->events |= COMEDI_CB_ERROR;
comedi_handle_events(dev, s);
return IRQ_HANDLED;
}
residue = comedi_isadma_disable(desc->chan);
max_points = comedi_bytes_to_samples(s, desc->size);
num_points = max_points - comedi_bytes_to_samples(s, residue);
if (devpriv->count < num_points && cmd->stop_src == TRIG_COUNT)
num_points = devpriv->count;
leftover = 0;
if (cmd->stop_src == TRIG_NONE) {
leftover = comedi_bytes_to_samples(s, desc->size);
} else if (devpriv->count > max_points) {
leftover = devpriv->count - max_points;
if (leftover > max_points)
leftover = max_points;
}
if (residue)
leftover = 0;
for (i = 0; i < num_points; i++) {
dpnt = buf[i];
dpnt ^= 0x8000;
comedi_buf_write_samples(s, &dpnt, 1);
if (cmd->stop_src == TRIG_COUNT) {
if (--devpriv->count == 0) {
async->events |= COMEDI_CB_EOA;
break;
}
}
}
if (leftover) {
desc->size = comedi_samples_to_bytes(s, leftover);
comedi_isadma_program(desc);
}
comedi_handle_events(dev, s);
outw(0x00, dev->iobase + DMA_TC_CLEAR_REG);
return IRQ_HANDLED;
}
static int a2150_cancel(struct comedi_device *dev, struct comedi_subdevice *s)
{
struct a2150_private *devpriv = dev->private;
struct comedi_isadma *dma = devpriv->dma;
struct comedi_isadma_desc *desc = &dma->desc[0];
devpriv->irq_dma_bits &= ~DMA_INTR_EN_BIT & ~DMA_EN_BIT;
outw(devpriv->irq_dma_bits, dev->iobase + IRQ_DMA_CNTRL_REG);
comedi_isadma_disable(desc->chan);
outw(0, dev->iobase + FIFO_RESET_REG);
return 0;
}
static int a2150_get_timing(struct comedi_device *dev, unsigned int *period,
unsigned int flags)
{
const struct a2150_board *thisboard = dev->board_ptr;
struct a2150_private *devpriv = dev->private;
int lub, glb, temp;
int lub_divisor_shift, lub_index, glb_divisor_shift, glb_index;
int i, j;
lub_divisor_shift = 3;
lub_index = 0;
lub = thisboard->clock[lub_index] * (1 << lub_divisor_shift);
glb_divisor_shift = 0;
glb_index = thisboard->num_clocks - 1;
glb = thisboard->clock[glb_index] * (1 << glb_divisor_shift);
if (*period < glb)
*period = glb;
if (*period > lub)
*period = lub;
for (i = 0; i < 4; i++) {
for (j = 0; j < thisboard->num_clocks; j++) {
temp = thisboard->clock[j] * (1 << i);
if (temp < lub && temp >= *period) {
lub_divisor_shift = i;
lub_index = j;
lub = temp;
}
if (temp > glb && temp <= *period) {
glb_divisor_shift = i;
glb_index = j;
glb = temp;
}
}
}
switch (flags & CMDF_ROUND_MASK) {
case CMDF_ROUND_NEAREST:
default:
if (lub - *period < *period - glb)
*period = lub;
else
*period = glb;
break;
case CMDF_ROUND_UP:
*period = lub;
break;
case CMDF_ROUND_DOWN:
*period = glb;
break;
}
devpriv->config_bits &= ~CLOCK_MASK;
if (*period == lub) {
devpriv->config_bits |=
CLOCK_SELECT_BITS(lub_index) |
CLOCK_DIVISOR_BITS(lub_divisor_shift);
} else {
devpriv->config_bits |=
CLOCK_SELECT_BITS(glb_index) |
CLOCK_DIVISOR_BITS(glb_divisor_shift);
}
return 0;
}
static int a2150_set_chanlist(struct comedi_device *dev,
unsigned int start_channel,
unsigned int num_channels)
{
struct a2150_private *devpriv = dev->private;
if (start_channel + num_channels > 4)
return -1;
devpriv->config_bits &= ~CHANNEL_MASK;
switch (num_channels) {
case 1:
devpriv->config_bits |= CHANNEL_BITS(0x4 | start_channel);
break;
case 2:
if (start_channel == 0)
devpriv->config_bits |= CHANNEL_BITS(0x2);
else if (start_channel == 2)
devpriv->config_bits |= CHANNEL_BITS(0x3);
else
return -1;
break;
case 4:
devpriv->config_bits |= CHANNEL_BITS(0x1);
break;
default:
return -1;
}
return 0;
}
static int a2150_ai_check_chanlist(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_cmd *cmd)
{
unsigned int chan0 = CR_CHAN(cmd->chanlist[0]);
unsigned int aref0 = CR_AREF(cmd->chanlist[0]);
int i;
if (cmd->chanlist_len == 2 && (chan0 == 1 || chan0 == 3)) {
dev_dbg(dev->class_dev,
"length 2 chanlist must be channels 0,1 or channels 2,3\n");
return -EINVAL;
}
if (cmd->chanlist_len == 3) {
dev_dbg(dev->class_dev,
"chanlist must have 1,2 or 4 channels\n");
return -EINVAL;
}
for (i = 1; i < cmd->chanlist_len; i++) {
unsigned int chan = CR_CHAN(cmd->chanlist[i]);
unsigned int aref = CR_AREF(cmd->chanlist[i]);
if (chan != (chan0 + i)) {
dev_dbg(dev->class_dev,
"entries in chanlist must be consecutive channels, counting upwards\n");
return -EINVAL;
}
if (chan == 2)
aref0 = aref;
if (aref != aref0) {
dev_dbg(dev->class_dev,
"channels 0/1 and 2/3 must have the same analog reference\n");
return -EINVAL;
}
}
return 0;
}
static int a2150_ai_cmdtest(struct comedi_device *dev,
struct comedi_subdevice *s, struct comedi_cmd *cmd)
{
const struct a2150_board *thisboard = dev->board_ptr;
int err = 0;
unsigned int arg;
err |= cfc_check_trigger_src(&cmd->start_src, TRIG_NOW | TRIG_EXT);
err |= cfc_check_trigger_src(&cmd->scan_begin_src, TRIG_TIMER);
err |= cfc_check_trigger_src(&cmd->convert_src, TRIG_NOW);
err |= cfc_check_trigger_src(&cmd->scan_end_src, TRIG_COUNT);
err |= cfc_check_trigger_src(&cmd->stop_src, TRIG_COUNT | TRIG_NONE);
if (err)
return 1;
err |= cfc_check_trigger_is_unique(cmd->start_src);
err |= cfc_check_trigger_is_unique(cmd->stop_src);
if (err)
return 2;
err |= cfc_check_trigger_arg_is(&cmd->start_arg, 0);
if (cmd->convert_src == TRIG_TIMER)
err |= cfc_check_trigger_arg_min(&cmd->convert_arg,
thisboard->ai_speed);
err |= cfc_check_trigger_arg_min(&cmd->chanlist_len, 1);
err |= cfc_check_trigger_arg_is(&cmd->scan_end_arg, cmd->chanlist_len);
if (cmd->stop_src == TRIG_COUNT)
err |= cfc_check_trigger_arg_min(&cmd->stop_arg, 1);
else
err |= cfc_check_trigger_arg_is(&cmd->stop_arg, 0);
if (err)
return 3;
if (cmd->scan_begin_src == TRIG_TIMER) {
arg = cmd->scan_begin_arg;
a2150_get_timing(dev, &arg, cmd->flags);
err |= cfc_check_trigger_arg_is(&cmd->scan_begin_arg, arg);
}
if (err)
return 4;
if (cmd->chanlist && cmd->chanlist_len > 0)
err |= a2150_ai_check_chanlist(dev, s, cmd);
if (err)
return 5;
return 0;
}
static int a2150_ai_cmd(struct comedi_device *dev, struct comedi_subdevice *s)
{
struct a2150_private *devpriv = dev->private;
struct comedi_isadma *dma = devpriv->dma;
struct comedi_isadma_desc *desc = &dma->desc[0];
struct comedi_async *async = s->async;
struct comedi_cmd *cmd = &async->cmd;
unsigned long timer_base = dev->iobase + I8253_BASE_REG;
unsigned int old_config_bits = devpriv->config_bits;
unsigned int trigger_bits;
if (cmd->flags & CMDF_PRIORITY) {
dev_err(dev->class_dev,
"dma incompatible with hard real-time interrupt (CMDF_PRIORITY), aborting\n");
return -1;
}
outw(0, dev->iobase + FIFO_RESET_REG);
if (a2150_set_chanlist(dev, CR_CHAN(cmd->chanlist[0]),
cmd->chanlist_len) < 0)
return -1;
if (CR_AREF(cmd->chanlist[0]) == AREF_OTHER)
devpriv->config_bits |= AC0_BIT;
else
devpriv->config_bits &= ~AC0_BIT;
if (CR_AREF(cmd->chanlist[2]) == AREF_OTHER)
devpriv->config_bits |= AC1_BIT;
else
devpriv->config_bits &= ~AC1_BIT;
a2150_get_timing(dev, &cmd->scan_begin_arg, cmd->flags);
outw(devpriv->config_bits, dev->iobase + CONFIG_REG);
devpriv->count = cmd->stop_arg * cmd->chanlist_len;
comedi_isadma_disable(desc->chan);
#define ONE_THIRD_SECOND 333333333
desc->size = comedi_bytes_per_sample(s) * cmd->chanlist_len *
ONE_THIRD_SECOND / cmd->scan_begin_arg;
if (desc->size > desc->maxsize)
desc->size = desc->maxsize;
if (desc->size < comedi_bytes_per_sample(s))
desc->size = comedi_bytes_per_sample(s);
desc->size -= desc->size % comedi_bytes_per_sample(s);
comedi_isadma_program(desc);
outw(0x00, dev->iobase + DMA_TC_CLEAR_REG);
devpriv->irq_dma_bits |= DMA_INTR_EN_BIT | DMA_EN_BIT;
outw(devpriv->irq_dma_bits, dev->iobase + IRQ_DMA_CNTRL_REG);
i8254_set_mode(timer_base, 0, 2, I8254_MODE0 | I8254_BINARY);
i8254_write(timer_base, 0, 2, 72);
trigger_bits = 0;
if (cmd->start_src == TRIG_NOW &&
(old_config_bits & CLOCK_MASK) !=
(devpriv->config_bits & CLOCK_MASK)) {
trigger_bits |= DELAY_TRIGGER_BITS;
} else {
trigger_bits |= POST_TRIGGER_BITS;
}
if (cmd->start_src == TRIG_EXT) {
trigger_bits |= HW_TRIG_EN;
} else if (cmd->start_src == TRIG_OTHER) {
dev_err(dev->class_dev, "you shouldn't see this?\n");
}
outw(trigger_bits, dev->iobase + TRIGGER_REG);
if (cmd->start_src == TRIG_NOW)
outw(0, dev->iobase + FIFO_START_REG);
return 0;
}
static int a2150_ai_eoc(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned long context)
{
unsigned int status;
status = inw(dev->iobase + STATUS_REG);
if (status & FNE_BIT)
return 0;
return -EBUSY;
}
static int a2150_ai_rinsn(struct comedi_device *dev, struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct a2150_private *devpriv = dev->private;
unsigned int n;
int ret;
outw(0, dev->iobase + FIFO_RESET_REG);
if (a2150_set_chanlist(dev, CR_CHAN(insn->chanspec), 1) < 0)
return -1;
devpriv->config_bits &= ~AC0_BIT;
devpriv->config_bits &= ~AC1_BIT;
outw(devpriv->config_bits, dev->iobase + CONFIG_REG);
devpriv->irq_dma_bits &= ~DMA_INTR_EN_BIT & ~DMA_EN_BIT;
outw(devpriv->irq_dma_bits, dev->iobase + IRQ_DMA_CNTRL_REG);
outw(0, dev->iobase + TRIGGER_REG);
outw(0, dev->iobase + FIFO_START_REG);
for (n = 0; n < 36; n++) {
ret = comedi_timeout(dev, s, insn, a2150_ai_eoc, 0);
if (ret)
return ret;
inw(dev->iobase + FIFO_DATA_REG);
}
for (n = 0; n < insn->n; n++) {
ret = comedi_timeout(dev, s, insn, a2150_ai_eoc, 0);
if (ret)
return ret;
data[n] = inw(dev->iobase + FIFO_DATA_REG);
data[n] ^= 0x8000;
}
outw(0, dev->iobase + FIFO_RESET_REG);
return n;
}
static void a2150_alloc_irq_and_dma(struct comedi_device *dev,
struct comedi_devconfig *it)
{
struct a2150_private *devpriv = dev->private;
unsigned int irq_num = it->options[1];
unsigned int dma_chan = it->options[2];
if (irq_num > 15 || dma_chan > 7 ||
!((1 << irq_num) & 0xdef8) || !((1 << dma_chan) & 0xef))
return;
if (request_irq(irq_num, a2150_interrupt, 0, dev->board_name, dev))
return;
devpriv->dma = comedi_isadma_alloc(dev, 1, dma_chan, dma_chan,
A2150_DMA_BUFFER_SIZE,
COMEDI_ISADMA_READ);
if (!devpriv->dma) {
free_irq(irq_num, dev);
} else {
dev->irq = irq_num;
devpriv->irq_dma_bits = IRQ_LVL_BITS(irq_num) |
DMA_CHAN_BITS(dma_chan);
}
}
static void a2150_free_dma(struct comedi_device *dev)
{
struct a2150_private *devpriv = dev->private;
if (devpriv)
comedi_isadma_free(devpriv->dma);
}
static int a2150_probe(struct comedi_device *dev)
{
int status = inw(dev->iobase + STATUS_REG);
return ID_BITS(status);
}
static int a2150_attach(struct comedi_device *dev, struct comedi_devconfig *it)
{
const struct a2150_board *thisboard;
struct a2150_private *devpriv;
struct comedi_subdevice *s;
static const int timeout = 2000;
int i;
int ret;
devpriv = comedi_alloc_devpriv(dev, sizeof(*devpriv));
if (!devpriv)
return -ENOMEM;
ret = comedi_request_region(dev, it->options[0], 0x1c);
if (ret)
return ret;
i = a2150_probe(dev);
if (i >= ARRAY_SIZE(a2150_boards))
return -ENODEV;
dev->board_ptr = a2150_boards + i;
thisboard = dev->board_ptr;
dev->board_name = thisboard->name;
a2150_alloc_irq_and_dma(dev, it);
ret = comedi_alloc_subdevices(dev, 1);
if (ret)
return ret;
s = &dev->subdevices[0];
s->type = COMEDI_SUBD_AI;
s->subdev_flags = SDF_READABLE | SDF_GROUND | SDF_OTHER;
s->n_chan = 4;
s->maxdata = 0xffff;
s->range_table = &range_a2150;
s->insn_read = a2150_ai_rinsn;
if (dev->irq) {
dev->read_subdev = s;
s->subdev_flags |= SDF_CMD_READ;
s->len_chanlist = s->n_chan;
s->do_cmd = a2150_ai_cmd;
s->do_cmdtest = a2150_ai_cmdtest;
s->cancel = a2150_cancel;
}
outw(HW_COUNT_DISABLE, dev->iobase + I8253_MODE_REG);
outw(devpriv->irq_dma_bits, dev->iobase + IRQ_DMA_CNTRL_REG);
outw_p(DPD_BIT | APD_BIT, dev->iobase + CONFIG_REG);
outw_p(DPD_BIT, dev->iobase + CONFIG_REG);
devpriv->config_bits = 0;
outw(devpriv->config_bits, dev->iobase + CONFIG_REG);
for (i = 0; i < timeout; i++) {
if ((DCAL_BIT & inw(dev->iobase + STATUS_REG)) == 0)
break;
udelay(1000);
}
if (i == timeout) {
dev_err(dev->class_dev,
"timed out waiting for offset calibration to complete\n");
return -ETIME;
}
devpriv->config_bits |= ENABLE0_BIT | ENABLE1_BIT;
outw(devpriv->config_bits, dev->iobase + CONFIG_REG);
return 0;
}
static void a2150_detach(struct comedi_device *dev)
{
if (dev->iobase)
outw(APD_BIT | DPD_BIT, dev->iobase + CONFIG_REG);
a2150_free_dma(dev);
comedi_legacy_detach(dev);
}
