static unsigned int labpc_inb(struct comedi_device *dev, unsigned long reg)
{
return inb(dev->iobase + reg);
}
static void labpc_outb(struct comedi_device *dev,
unsigned int byte, unsigned long reg)
{
outb(byte, dev->iobase + reg);
}
static unsigned int labpc_readb(struct comedi_device *dev, unsigned long reg)
{
return readb(dev->mmio + reg);
}
static void labpc_writeb(struct comedi_device *dev,
unsigned int byte, unsigned long reg)
{
writeb(byte, dev->mmio + reg);
}
static void labpc_counter_load(struct comedi_device *dev,
unsigned long reg,
unsigned int counter_number,
unsigned int count,
unsigned int mode)
{
if (dev->mmio) {
i8254_mm_set_mode(dev->mmio + reg, 0, counter_number, mode);
i8254_mm_write(dev->mmio + reg, 0, counter_number, count);
} else {
i8254_set_mode(dev->iobase + reg, 0, counter_number, mode);
i8254_write(dev->iobase + reg, 0, counter_number, count);
}
}
static void labpc_counter_set_mode(struct comedi_device *dev,
unsigned long reg,
unsigned int counter_number,
unsigned int mode)
{
if (dev->mmio)
i8254_mm_set_mode(dev->mmio + reg, 0, counter_number, mode);
else
i8254_set_mode(dev->iobase + reg, 0, counter_number, mode);
}
static int labpc_cancel(struct comedi_device *dev, struct comedi_subdevice *s)
{
struct labpc_private *devpriv = dev->private;
unsigned long flags;
spin_lock_irqsave(&dev->spinlock, flags);
devpriv->cmd2 &= ~(CMD2_SWTRIG | CMD2_HWTRIG | CMD2_PRETRIG);
devpriv->write_byte(dev, devpriv->cmd2, CMD2_REG);
spin_unlock_irqrestore(&dev->spinlock, flags);
devpriv->cmd3 = 0;
devpriv->write_byte(dev, devpriv->cmd3, CMD3_REG);
return 0;
}
static void labpc_ai_set_chan_and_gain(struct comedi_device *dev,
enum scan_mode mode,
unsigned int chan,
unsigned int range,
unsigned int aref)
{
const struct labpc_boardinfo *board = dev->board_ptr;
struct labpc_private *devpriv = dev->private;
if (board->is_labpc1200) {
range += (range > 0) + (range > 7);
}
if ((mode == MODE_SINGLE_CHAN || mode == MODE_SINGLE_CHAN_INTERVAL) &&
aref == AREF_DIFF)
chan *= 2;
devpriv->cmd1 = CMD1_MA(chan);
devpriv->cmd1 |= CMD1_GAIN(range);
devpriv->write_byte(dev, devpriv->cmd1, CMD1_REG);
}
static void labpc_setup_cmd6_reg(struct comedi_device *dev,
struct comedi_subdevice *s,
enum scan_mode mode,
enum transfer_type xfer,
unsigned int range,
unsigned int aref,
bool ena_intr)
{
const struct labpc_boardinfo *board = dev->board_ptr;
struct labpc_private *devpriv = dev->private;
if (!board->is_labpc1200)
return;
if (aref != AREF_GROUND)
devpriv->cmd6 |= CMD6_NRSE;
else
devpriv->cmd6 &= ~CMD6_NRSE;
if (comedi_range_is_unipolar(s, range))
devpriv->cmd6 |= CMD6_ADCUNI;
else
devpriv->cmd6 &= ~CMD6_ADCUNI;
if (xfer == fifo_half_full_transfer)
devpriv->cmd6 |= CMD6_HFINTEN;
else
devpriv->cmd6 &= ~CMD6_HFINTEN;
if (ena_intr)
devpriv->cmd6 |= CMD6_DQINTEN;
else
devpriv->cmd6 &= ~CMD6_DQINTEN;
if (mode == MODE_MULT_CHAN_UP)
devpriv->cmd6 |= CMD6_SCANUP;
else
devpriv->cmd6 &= ~CMD6_SCANUP;
devpriv->write_byte(dev, devpriv->cmd6, CMD6_REG);
}
static unsigned int labpc_read_adc_fifo(struct comedi_device *dev)
{
struct labpc_private *devpriv = dev->private;
unsigned int lsb = devpriv->read_byte(dev, ADC_FIFO_REG);
unsigned int msb = devpriv->read_byte(dev, ADC_FIFO_REG);
return (msb << 8) | lsb;
}
static void labpc_clear_adc_fifo(struct comedi_device *dev)
{
struct labpc_private *devpriv = dev->private;
devpriv->write_byte(dev, 0x1, ADC_FIFO_CLEAR_REG);
labpc_read_adc_fifo(dev);
}
static int labpc_ai_eoc(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned long context)
{
struct labpc_private *devpriv = dev->private;
devpriv->stat1 = devpriv->read_byte(dev, STAT1_REG);
if (devpriv->stat1 & STAT1_DAVAIL)
return 0;
return -EBUSY;
}
static int labpc_ai_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct labpc_private *devpriv = dev->private;
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned int range = CR_RANGE(insn->chanspec);
unsigned int aref = CR_AREF(insn->chanspec);
int ret;
int i;
labpc_cancel(dev, s);
labpc_ai_set_chan_and_gain(dev, MODE_SINGLE_CHAN, chan, range, aref);
labpc_setup_cmd6_reg(dev, s, MODE_SINGLE_CHAN, fifo_not_empty_transfer,
range, aref, false);
devpriv->cmd4 = 0;
devpriv->cmd4 |= CMD4_ECLKRCV;
if (aref == AREF_DIFF)
devpriv->cmd4 |= CMD4_SEDIFF;
devpriv->write_byte(dev, devpriv->cmd4, CMD4_REG);
labpc_counter_set_mode(dev, COUNTER_A_BASE_REG, 0, I8254_MODE2);
labpc_clear_adc_fifo(dev);
for (i = 0; i < insn->n; i++) {
devpriv->write_byte(dev, 0x1, ADC_START_CONVERT_REG);
ret = comedi_timeout(dev, s, insn, labpc_ai_eoc, 0);
if (ret)
return ret;
data[i] = labpc_read_adc_fifo(dev);
}
return insn->n;
}
static bool labpc_use_continuous_mode(const struct comedi_cmd *cmd,
enum scan_mode mode)
{
if (mode == MODE_SINGLE_CHAN || cmd->scan_begin_src == TRIG_FOLLOW)
return true;
return false;
}
static unsigned int labpc_ai_convert_period(const struct comedi_cmd *cmd,
enum scan_mode mode)
{
if (cmd->convert_src != TRIG_TIMER)
return 0;
if (mode == MODE_SINGLE_CHAN && cmd->scan_begin_src == TRIG_TIMER)
return cmd->scan_begin_arg;
return cmd->convert_arg;
}
static void labpc_set_ai_convert_period(struct comedi_cmd *cmd,
enum scan_mode mode, unsigned int ns)
{
if (cmd->convert_src != TRIG_TIMER)
return;
if (mode == MODE_SINGLE_CHAN &&
cmd->scan_begin_src == TRIG_TIMER) {
cmd->scan_begin_arg = ns;
if (cmd->convert_arg > cmd->scan_begin_arg)
cmd->convert_arg = cmd->scan_begin_arg;
} else {
cmd->convert_arg = ns;
}
}
static unsigned int labpc_ai_scan_period(const struct comedi_cmd *cmd,
enum scan_mode mode)
{
if (cmd->scan_begin_src != TRIG_TIMER)
return 0;
if (mode == MODE_SINGLE_CHAN && cmd->convert_src == TRIG_TIMER)
return 0;
return cmd->scan_begin_arg;
}
static void labpc_set_ai_scan_period(struct comedi_cmd *cmd,
enum scan_mode mode, unsigned int ns)
{
if (cmd->scan_begin_src != TRIG_TIMER)
return;
if (mode == MODE_SINGLE_CHAN && cmd->convert_src == TRIG_TIMER)
return;
cmd->scan_begin_arg = ns;
}
static void labpc_adc_timing(struct comedi_device *dev, struct comedi_cmd *cmd,
enum scan_mode mode)
{
struct labpc_private *devpriv = dev->private;
const int max_counter_value = 0x10000;
const int min_counter_value = 2;
unsigned int base_period;
unsigned int scan_period;
unsigned int convert_period;
convert_period = labpc_ai_convert_period(cmd, mode);
scan_period = labpc_ai_scan_period(cmd, mode);
if (convert_period && scan_period) {
devpriv->divisor_b0 = (scan_period - 1) /
(I8254_OSC_BASE_2MHZ * max_counter_value) + 1;
if (devpriv->divisor_b0 < min_counter_value)
devpriv->divisor_b0 = min_counter_value;
if (devpriv->divisor_b0 > max_counter_value)
devpriv->divisor_b0 = max_counter_value;
base_period = I8254_OSC_BASE_2MHZ * devpriv->divisor_b0;
switch (cmd->flags & CMDF_ROUND_MASK) {
default:
case CMDF_ROUND_NEAREST:
devpriv->divisor_a0 =
(convert_period + (base_period / 2)) / base_period;
devpriv->divisor_b1 =
(scan_period + (base_period / 2)) / base_period;
break;
case CMDF_ROUND_UP:
devpriv->divisor_a0 =
(convert_period + (base_period - 1)) / base_period;
devpriv->divisor_b1 =
(scan_period + (base_period - 1)) / base_period;
break;
case CMDF_ROUND_DOWN:
devpriv->divisor_a0 = convert_period / base_period;
devpriv->divisor_b1 = scan_period / base_period;
break;
}
if (devpriv->divisor_a0 < min_counter_value)
devpriv->divisor_a0 = min_counter_value;
if (devpriv->divisor_a0 > max_counter_value)
devpriv->divisor_a0 = max_counter_value;
if (devpriv->divisor_b1 < min_counter_value)
devpriv->divisor_b1 = min_counter_value;
if (devpriv->divisor_b1 > max_counter_value)
devpriv->divisor_b1 = max_counter_value;
labpc_set_ai_convert_period(cmd, mode,
base_period * devpriv->divisor_a0);
labpc_set_ai_scan_period(cmd, mode,
base_period * devpriv->divisor_b1);
} else if (scan_period) {
i8253_cascade_ns_to_timer(I8254_OSC_BASE_2MHZ,
&devpriv->divisor_b1,
&devpriv->divisor_b0,
&scan_period, cmd->flags);
labpc_set_ai_scan_period(cmd, mode, scan_period);
} else if (convert_period) {
i8253_cascade_ns_to_timer(I8254_OSC_BASE_2MHZ,
&devpriv->divisor_a0,
&devpriv->divisor_b0,
&convert_period, cmd->flags);
labpc_set_ai_convert_period(cmd, mode, convert_period);
}
}
static enum scan_mode labpc_ai_scan_mode(const struct comedi_cmd *cmd)
{
unsigned int chan0;
unsigned int chan1;
if (cmd->chanlist_len == 1)
return MODE_SINGLE_CHAN;
if (cmd->chanlist == NULL)
return MODE_MULT_CHAN_UP;
chan0 = CR_CHAN(cmd->chanlist[0]);
chan1 = CR_CHAN(cmd->chanlist[1]);
if (chan0 < chan1)
return MODE_MULT_CHAN_UP;
if (chan0 > chan1)
return MODE_MULT_CHAN_DOWN;
return MODE_SINGLE_CHAN_INTERVAL;
}
static int labpc_ai_check_chanlist(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_cmd *cmd)
{
enum scan_mode mode = labpc_ai_scan_mode(cmd);
unsigned int chan0 = CR_CHAN(cmd->chanlist[0]);
unsigned int range0 = CR_RANGE(cmd->chanlist[0]);
unsigned int aref0 = CR_AREF(cmd->chanlist[0]);
int i;
if (mode == MODE_SINGLE_CHAN)
return 0;
for (i = 0; i < cmd->chanlist_len; i++) {
unsigned int chan = CR_CHAN(cmd->chanlist[i]);
unsigned int range = CR_RANGE(cmd->chanlist[i]);
unsigned int aref = CR_AREF(cmd->chanlist[i]);
switch (mode) {
case MODE_SINGLE_CHAN:
break;
case MODE_SINGLE_CHAN_INTERVAL:
if (chan != chan0) {
dev_dbg(dev->class_dev,
"channel scanning order specified in chanlist is not supported by hardware\n");
return -EINVAL;
}
break;
case MODE_MULT_CHAN_UP:
if (chan != i) {
dev_dbg(dev->class_dev,
"channel scanning order specified in chanlist is not supported by hardware\n");
return -EINVAL;
}
break;
case MODE_MULT_CHAN_DOWN:
if (chan != (cmd->chanlist_len - i - 1)) {
dev_dbg(dev->class_dev,
"channel scanning order specified in chanlist is not supported by hardware\n");
return -EINVAL;
}
break;
}
if (range != range0) {
dev_dbg(dev->class_dev,
"entries in chanlist must all have the same range\n");
return -EINVAL;
}
if (aref != aref0) {
dev_dbg(dev->class_dev,
"entries in chanlist must all have the same reference\n");
return -EINVAL;
}
}
return 0;
}
static int labpc_ai_cmdtest(struct comedi_device *dev,
struct comedi_subdevice *s, struct comedi_cmd *cmd)
{
const struct labpc_boardinfo *board = dev->board_ptr;
int err = 0;
int tmp, tmp2;
unsigned int stop_mask;
enum scan_mode mode;
err |= cfc_check_trigger_src(&cmd->start_src, TRIG_NOW | TRIG_EXT);
err |= cfc_check_trigger_src(&cmd->scan_begin_src,
TRIG_TIMER | TRIG_FOLLOW | TRIG_EXT);
err |= cfc_check_trigger_src(&cmd->convert_src, TRIG_TIMER | TRIG_EXT);
err |= cfc_check_trigger_src(&cmd->scan_end_src, TRIG_COUNT);
stop_mask = TRIG_COUNT | TRIG_NONE;
if (board->is_labpc1200)
stop_mask |= TRIG_EXT;
err |= cfc_check_trigger_src(&cmd->stop_src, stop_mask);
if (err)
return 1;
err |= cfc_check_trigger_is_unique(cmd->start_src);
err |= cfc_check_trigger_is_unique(cmd->scan_begin_src);
err |= cfc_check_trigger_is_unique(cmd->convert_src);
err |= cfc_check_trigger_is_unique(cmd->stop_src);
if (cmd->start_src == TRIG_EXT && cmd->stop_src == TRIG_EXT)
err++;
if (err)
return 2;
switch (cmd->start_src) {
case TRIG_NOW:
err |= cfc_check_trigger_arg_is(&cmd->start_arg, 0);
break;
case TRIG_EXT:
break;
}
if (!cmd->chanlist_len)
err |= -EINVAL;
err |= cfc_check_trigger_arg_is(&cmd->scan_end_arg, cmd->chanlist_len);
if (cmd->convert_src == TRIG_TIMER)
err |= cfc_check_trigger_arg_min(&cmd->convert_arg,
board->ai_speed);
if (cmd->scan_begin_src == TRIG_TIMER) {
if (cmd->convert_src == TRIG_TIMER)
err |= cfc_check_trigger_arg_min(&cmd->scan_begin_arg,
cmd->convert_arg * cmd->chanlist_len);
err |= cfc_check_trigger_arg_min(&cmd->scan_begin_arg,
board->ai_speed * cmd->chanlist_len);
}
switch (cmd->stop_src) {
case TRIG_COUNT:
err |= cfc_check_trigger_arg_min(&cmd->stop_arg, 1);
break;
case TRIG_NONE:
err |= cfc_check_trigger_arg_is(&cmd->stop_arg, 0);
break;
default:
break;
}
if (err)
return 3;
tmp = cmd->convert_arg;
tmp2 = cmd->scan_begin_arg;
mode = labpc_ai_scan_mode(cmd);
labpc_adc_timing(dev, cmd, mode);
if (tmp != cmd->convert_arg || tmp2 != cmd->scan_begin_arg)
err++;
if (err)
return 4;
if (cmd->chanlist && cmd->chanlist_len > 0)
err |= labpc_ai_check_chanlist(dev, s, cmd);
if (err)
return 5;
return 0;
}
static int labpc_ai_cmd(struct comedi_device *dev, struct comedi_subdevice *s)
{
const struct labpc_boardinfo *board = dev->board_ptr;
struct labpc_private *devpriv = dev->private;
struct comedi_async *async = s->async;
struct comedi_cmd *cmd = &async->cmd;
enum scan_mode mode = labpc_ai_scan_mode(cmd);
unsigned int chanspec = (mode == MODE_MULT_CHAN_UP) ?
cmd->chanlist[cmd->chanlist_len - 1] :
cmd->chanlist[0];
unsigned int chan = CR_CHAN(chanspec);
unsigned int range = CR_RANGE(chanspec);
unsigned int aref = CR_AREF(chanspec);
enum transfer_type xfer;
unsigned long flags;
labpc_cancel(dev, s);
if (cmd->stop_src == TRIG_COUNT)
devpriv->count = cmd->stop_arg * cmd->chanlist_len;
if (cmd->stop_src == TRIG_EXT) {
labpc_counter_load(dev, COUNTER_A_BASE_REG,
1, 3, I8254_MODE0);
} else {
labpc_counter_set_mode(dev, COUNTER_A_BASE_REG, 1, I8254_MODE0);
}
if (labpc_have_dma_chan(dev) &&
(cmd->flags & (CMDF_WAKE_EOS | CMDF_PRIORITY)) == 0)
xfer = isa_dma_transfer;
else if (
board->is_labpc1200 &&
(cmd->flags & CMDF_WAKE_EOS) == 0 &&
(cmd->stop_src != TRIG_COUNT || devpriv->count > 256))
xfer = fifo_half_full_transfer;
else
xfer = fifo_not_empty_transfer;
devpriv->current_transfer = xfer;
labpc_ai_set_chan_and_gain(dev, mode, chan, range, aref);
labpc_setup_cmd6_reg(dev, s, mode, xfer, range, aref,
(cmd->stop_src == TRIG_EXT));
if (mode == MODE_MULT_CHAN_UP || mode == MODE_MULT_CHAN_DOWN) {
devpriv->cmd1 |= CMD1_SCANEN;
udelay(1);
devpriv->write_byte(dev, devpriv->cmd1, CMD1_REG);
}
devpriv->write_byte(dev, cmd->chanlist_len, INTERVAL_COUNT_REG);
devpriv->write_byte(dev, 0x1, INTERVAL_STROBE_REG);
if (cmd->convert_src == TRIG_TIMER ||
cmd->scan_begin_src == TRIG_TIMER) {
labpc_adc_timing(dev, cmd, mode);
labpc_counter_load(dev, COUNTER_B_BASE_REG,
0, devpriv->divisor_b0, I8254_MODE3);
}
if (labpc_ai_convert_period(cmd, mode)) {
labpc_counter_load(dev, COUNTER_A_BASE_REG,
0, devpriv->divisor_a0, I8254_MODE2);
} else {
labpc_counter_set_mode(dev, COUNTER_A_BASE_REG, 0, I8254_MODE2);
}
if (labpc_ai_scan_period(cmd, mode)) {
labpc_counter_load(dev, COUNTER_B_BASE_REG,
1, devpriv->divisor_b1, I8254_MODE2);
}
labpc_clear_adc_fifo(dev);
if (xfer == isa_dma_transfer)
labpc_setup_dma(dev, s);
devpriv->cmd3 |= CMD3_ERRINTEN;
if (xfer == fifo_not_empty_transfer)
devpriv->cmd3 |= CMD3_FIFOINTEN;
devpriv->write_byte(dev, devpriv->cmd3, CMD3_REG);
devpriv->cmd4 = 0;
if (cmd->convert_src != TRIG_EXT)
devpriv->cmd4 |= CMD4_ECLKRCV;
if (!labpc_use_continuous_mode(cmd, mode)) {
devpriv->cmd4 |= CMD4_INTSCAN;
if (cmd->scan_begin_src == TRIG_EXT)
devpriv->cmd4 |= CMD4_EOIRCV;
}
if (aref == AREF_DIFF)
devpriv->cmd4 |= CMD4_SEDIFF;
devpriv->write_byte(dev, devpriv->cmd4, CMD4_REG);
spin_lock_irqsave(&dev->spinlock, flags);
devpriv->cmd2 |= CMD2_TBSEL;
devpriv->cmd2 &= ~(CMD2_SWTRIG | CMD2_HWTRIG | CMD2_PRETRIG);
if (cmd->start_src == TRIG_EXT)
devpriv->cmd2 |= CMD2_HWTRIG;
else
devpriv->cmd2 |= CMD2_SWTRIG;
if (cmd->stop_src == TRIG_EXT)
devpriv->cmd2 |= (CMD2_HWTRIG | CMD2_PRETRIG);
devpriv->write_byte(dev, devpriv->cmd2, CMD2_REG);
spin_unlock_irqrestore(&dev->spinlock, flags);
return 0;
}
static int labpc_drain_fifo(struct comedi_device *dev)
{
struct labpc_private *devpriv = dev->private;
struct comedi_async *async = dev->read_subdev->async;
struct comedi_cmd *cmd = &async->cmd;
unsigned short data;
const int timeout = 10000;
unsigned int i;
devpriv->stat1 = devpriv->read_byte(dev, STAT1_REG);
for (i = 0; (devpriv->stat1 & STAT1_DAVAIL) && i < timeout;
i++) {
if (cmd->stop_src == TRIG_COUNT) {
if (devpriv->count == 0)
break;
devpriv->count--;
}
data = labpc_read_adc_fifo(dev);
cfc_write_to_buffer(dev->read_subdev, data);
devpriv->stat1 = devpriv->read_byte(dev, STAT1_REG);
}
if (i == timeout) {
dev_err(dev->class_dev, "ai timeout, fifo never empties\n");
async->events |= COMEDI_CB_ERROR | COMEDI_CB_EOA;
return -1;
}
return 0;
}
static void labpc_drain_dregs(struct comedi_device *dev)
{
struct labpc_private *devpriv = dev->private;
if (devpriv->current_transfer == isa_dma_transfer)
labpc_drain_dma(dev);
labpc_drain_fifo(dev);
}
static irqreturn_t labpc_interrupt(int irq, void *d)
{
struct comedi_device *dev = d;
const struct labpc_boardinfo *board = dev->board_ptr;
struct labpc_private *devpriv = dev->private;
struct comedi_subdevice *s = dev->read_subdev;
struct comedi_async *async;
struct comedi_cmd *cmd;
if (!dev->attached) {
dev_err(dev->class_dev, "premature interrupt\n");
return IRQ_HANDLED;
}
async = s->async;
cmd = &async->cmd;
devpriv->stat1 = devpriv->read_byte(dev, STAT1_REG);
if (board->is_labpc1200)
devpriv->stat2 = devpriv->read_byte(dev, STAT2_REG);
if ((devpriv->stat1 & (STAT1_GATA0 | STAT1_CNTINT | STAT1_OVERFLOW |
STAT1_OVERRUN | STAT1_DAVAIL)) == 0 &&
(devpriv->stat2 & STAT2_OUTA1) == 0 &&
(devpriv->stat2 & STAT2_FIFONHF)) {
return IRQ_NONE;
}
if (devpriv->stat1 & STAT1_OVERRUN) {
devpriv->write_byte(dev, 0x1, ADC_FIFO_CLEAR_REG);
async->events |= COMEDI_CB_ERROR | COMEDI_CB_EOA;
cfc_handle_events(dev, s);
dev_err(dev->class_dev, "overrun\n");
return IRQ_HANDLED;
}
if (devpriv->current_transfer == isa_dma_transfer)
labpc_handle_dma_status(dev);
else
labpc_drain_fifo(dev);
if (devpriv->stat1 & STAT1_CNTINT) {
dev_err(dev->class_dev, "handled timer interrupt?\n");
devpriv->write_byte(dev, 0x1, TIMER_CLEAR_REG);
}
if (devpriv->stat1 & STAT1_OVERFLOW) {
devpriv->write_byte(dev, 0x1, ADC_FIFO_CLEAR_REG);
async->events |= COMEDI_CB_ERROR | COMEDI_CB_EOA;
cfc_handle_events(dev, s);
dev_err(dev->class_dev, "overflow\n");
return IRQ_HANDLED;
}
if (cmd->stop_src == TRIG_EXT) {
if (devpriv->stat2 & STAT2_OUTA1) {
labpc_drain_dregs(dev);
async->events |= COMEDI_CB_EOA;
}
}
if (cmd->stop_src == TRIG_COUNT) {
if (devpriv->count == 0)
async->events |= COMEDI_CB_EOA;
}
cfc_handle_events(dev, s);
return IRQ_HANDLED;
}
static int labpc_ao_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
const struct labpc_boardinfo *board = dev->board_ptr;
struct labpc_private *devpriv = dev->private;
int channel, range;
unsigned long flags;
int lsb, msb;
channel = CR_CHAN(insn->chanspec);
spin_lock_irqsave(&dev->spinlock, flags);
devpriv->cmd2 &= ~CMD2_LDAC(channel);
devpriv->write_byte(dev, devpriv->cmd2, CMD2_REG);
spin_unlock_irqrestore(&dev->spinlock, flags);
if (board->is_labpc1200) {
range = CR_RANGE(insn->chanspec);
if (comedi_range_is_unipolar(s, range))
devpriv->cmd6 |= CMD6_DACUNI(channel);
else
devpriv->cmd6 &= ~CMD6_DACUNI(channel);
devpriv->write_byte(dev, devpriv->cmd6, CMD6_REG);
}
lsb = data[0] & 0xff;
msb = (data[0] >> 8) & 0xff;
devpriv->write_byte(dev, lsb, DAC_LSB_REG(channel));
devpriv->write_byte(dev, msb, DAC_MSB_REG(channel));
devpriv->ao_value[channel] = data[0];
return 1;
}
static int labpc_ao_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct labpc_private *devpriv = dev->private;
data[0] = devpriv->ao_value[CR_CHAN(insn->chanspec)];
return 1;
}
static void labpc_serial_out(struct comedi_device *dev, unsigned int value,
unsigned int value_width)
{
struct labpc_private *devpriv = dev->private;
int i;
for (i = 1; i <= value_width; i++) {
devpriv->cmd5 &= ~CMD5_SCLK;
if (value & (1 << (value_width - i)))
devpriv->cmd5 |= CMD5_SDATA;
else
devpriv->cmd5 &= ~CMD5_SDATA;
udelay(1);
devpriv->write_byte(dev, devpriv->cmd5, CMD5_REG);
devpriv->cmd5 |= CMD5_SCLK;
udelay(1);
devpriv->write_byte(dev, devpriv->cmd5, CMD5_REG);
}
}
static unsigned int labpc_serial_in(struct comedi_device *dev)
{
struct labpc_private *devpriv = dev->private;
unsigned int value = 0;
int i;
const int value_width = 8;
for (i = 1; i <= value_width; i++) {
devpriv->cmd5 |= CMD5_SCLK;
udelay(1);
devpriv->write_byte(dev, devpriv->cmd5, CMD5_REG);
devpriv->cmd5 &= ~CMD5_SCLK;
udelay(1);
devpriv->write_byte(dev, devpriv->cmd5, CMD5_REG);
udelay(1);
devpriv->stat2 = devpriv->read_byte(dev, STAT2_REG);
if (devpriv->stat2 & STAT2_PROMOUT)
value |= 1 << (value_width - i);
}
return value;
}
static unsigned int labpc_eeprom_read(struct comedi_device *dev,
unsigned int address)
{
struct labpc_private *devpriv = dev->private;
unsigned int value;
const int read_instruction = 0x3;
const int write_length = 8;
devpriv->cmd5 &= ~CMD5_EEPROMCS;
udelay(1);
devpriv->write_byte(dev, devpriv->cmd5, CMD5_REG);
devpriv->cmd5 |= (CMD5_EEPROMCS | CMD5_WRTPRT);
udelay(1);
devpriv->write_byte(dev, devpriv->cmd5, CMD5_REG);
labpc_serial_out(dev, read_instruction, write_length);
labpc_serial_out(dev, address, write_length);
value = labpc_serial_in(dev);
devpriv->cmd5 &= ~(CMD5_EEPROMCS | CMD5_WRTPRT);
udelay(1);
devpriv->write_byte(dev, devpriv->cmd5, CMD5_REG);
return value;
}
static unsigned int labpc_eeprom_read_status(struct comedi_device *dev)
{
struct labpc_private *devpriv = dev->private;
unsigned int value;
const int read_status_instruction = 0x5;
const int write_length = 8;
devpriv->cmd5 &= ~CMD5_EEPROMCS;
udelay(1);
devpriv->write_byte(dev, devpriv->cmd5, CMD5_REG);
devpriv->cmd5 |= (CMD5_EEPROMCS | CMD5_WRTPRT);
udelay(1);
devpriv->write_byte(dev, devpriv->cmd5, CMD5_REG);
labpc_serial_out(dev, read_status_instruction, write_length);
value = labpc_serial_in(dev);
devpriv->cmd5 &= ~(CMD5_EEPROMCS | CMD5_WRTPRT);
udelay(1);
devpriv->write_byte(dev, devpriv->cmd5, CMD5_REG);
return value;
}
static int labpc_eeprom_write(struct comedi_device *dev,
unsigned int address, unsigned int value)
{
struct labpc_private *devpriv = dev->private;
const int write_enable_instruction = 0x6;
const int write_instruction = 0x2;
const int write_length = 8;
const int write_in_progress_bit = 0x1;
const int timeout = 10000;
int i;
for (i = 0; i < timeout; i++) {
if ((labpc_eeprom_read_status(dev) & write_in_progress_bit) ==
0)
break;
}
if (i == timeout) {
dev_err(dev->class_dev, "eeprom write timed out\n");
return -ETIME;
}
devpriv->eeprom_data[address] = value;
devpriv->cmd5 &= ~CMD5_EEPROMCS;
udelay(1);
devpriv->write_byte(dev, devpriv->cmd5, CMD5_REG);
devpriv->cmd5 |= (CMD5_EEPROMCS | CMD5_WRTPRT);
udelay(1);
devpriv->write_byte(dev, devpriv->cmd5, CMD5_REG);
labpc_serial_out(dev, write_enable_instruction, write_length);
devpriv->cmd5 &= ~CMD5_EEPROMCS;
udelay(1);
devpriv->write_byte(dev, devpriv->cmd5, CMD5_REG);
devpriv->cmd5 |= CMD5_EEPROMCS;
udelay(1);
devpriv->write_byte(dev, devpriv->cmd5, CMD5_REG);
labpc_serial_out(dev, write_instruction, write_length);
labpc_serial_out(dev, address, write_length);
labpc_serial_out(dev, value, write_length);
devpriv->cmd5 &= ~CMD5_EEPROMCS;
udelay(1);
devpriv->write_byte(dev, devpriv->cmd5, CMD5_REG);
devpriv->cmd5 &= ~(CMD5_EEPROMCS | CMD5_WRTPRT);
udelay(1);
devpriv->write_byte(dev, devpriv->cmd5, CMD5_REG);
return 0;
}
static void write_caldac(struct comedi_device *dev, unsigned int channel,
unsigned int value)
{
struct labpc_private *devpriv = dev->private;
if (value == devpriv->caldac[channel])
return;
devpriv->caldac[channel] = value;
devpriv->cmd5 &= ~(CMD5_CALDACLD | CMD5_EEPROMCS | CMD5_WRTPRT);
udelay(1);
devpriv->write_byte(dev, devpriv->cmd5, CMD5_REG);
labpc_serial_out(dev, channel, 4);
labpc_serial_out(dev, value, 8);
devpriv->cmd5 |= CMD5_CALDACLD;
udelay(1);
devpriv->write_byte(dev, devpriv->cmd5, CMD5_REG);
devpriv->cmd5 &= ~CMD5_CALDACLD;
udelay(1);
devpriv->write_byte(dev, devpriv->cmd5, CMD5_REG);
}
static int labpc_calib_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned int chan = CR_CHAN(insn->chanspec);
if (insn->n > 0)
write_caldac(dev, chan, data[insn->n - 1]);
return insn->n;
}
static int labpc_calib_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct labpc_private *devpriv = dev->private;
unsigned int chan = CR_CHAN(insn->chanspec);
int i;
for (i = 0; i < insn->n; i++)
data[i] = devpriv->caldac[chan];
return insn->n;
}
static int labpc_eeprom_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned int chan = CR_CHAN(insn->chanspec);
int ret;
if (chan < 16 || chan > 127)
return -EINVAL;
if (insn->n > 0) {
ret = labpc_eeprom_write(dev, chan, data[insn->n - 1]);
if (ret)
return ret;
}
return insn->n;
}
static int labpc_eeprom_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct labpc_private *devpriv = dev->private;
unsigned int chan = CR_CHAN(insn->chanspec);
int i;
for (i = 0; i < insn->n; i++)
data[i] = devpriv->eeprom_data[chan];
return insn->n;
}
int labpc_common_attach(struct comedi_device *dev,
unsigned int irq, unsigned long isr_flags)
{
const struct labpc_boardinfo *board = dev->board_ptr;
struct labpc_private *devpriv = dev->private;
struct comedi_subdevice *s;
int ret;
int i;
if (dev->mmio) {
devpriv->read_byte = labpc_readb;
devpriv->write_byte = labpc_writeb;
} else {
devpriv->read_byte = labpc_inb;
devpriv->write_byte = labpc_outb;
}
devpriv->write_byte(dev, devpriv->cmd1, CMD1_REG);
devpriv->write_byte(dev, devpriv->cmd2, CMD2_REG);
devpriv->write_byte(dev, devpriv->cmd3, CMD3_REG);
devpriv->write_byte(dev, devpriv->cmd4, CMD4_REG);
if (board->is_labpc1200) {
devpriv->write_byte(dev, devpriv->cmd5, CMD5_REG);
devpriv->write_byte(dev, devpriv->cmd6, CMD6_REG);
}
if (irq) {
ret = request_irq(irq, labpc_interrupt, isr_flags,
dev->board_name, dev);
if (ret == 0)
dev->irq = irq;
}
ret = comedi_alloc_subdevices(dev, 5);
if (ret)
return ret;
s = &dev->subdevices[0];
s->type = COMEDI_SUBD_AI;
s->subdev_flags = SDF_READABLE | SDF_GROUND | SDF_COMMON | SDF_DIFF;
s->n_chan = 8;
s->len_chanlist = 8;
s->maxdata = 0x0fff;
s->range_table = board->is_labpc1200 ?
&range_labpc_1200_ai : &range_labpc_plus_ai;
s->insn_read = labpc_ai_insn_read;
if (dev->irq) {
dev->read_subdev = s;
s->subdev_flags |= SDF_CMD_READ;
s->do_cmd = labpc_ai_cmd;
s->do_cmdtest = labpc_ai_cmdtest;
s->cancel = labpc_cancel;
}
s = &dev->subdevices[1];
if (board->has_ao) {
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE | SDF_GROUND;
s->n_chan = NUM_AO_CHAN;
s->maxdata = 0x0fff;
s->range_table = &range_labpc_ao;
s->insn_read = labpc_ao_insn_read;
s->insn_write = labpc_ao_insn_write;
for (i = 0; i < s->n_chan; i++) {
short lsb, msb;
devpriv->ao_value[i] = s->maxdata / 2;
lsb = devpriv->ao_value[i] & 0xff;
msb = (devpriv->ao_value[i] >> 8) & 0xff;
devpriv->write_byte(dev, lsb, DAC_LSB_REG(i));
devpriv->write_byte(dev, msb, DAC_MSB_REG(i));
}
} else {
s->type = COMEDI_SUBD_UNUSED;
}
s = &dev->subdevices[2];
if (dev->mmio)
ret = subdev_8255_mm_init(dev, s, NULL, DIO_BASE_REG);
else
ret = subdev_8255_init(dev, s, NULL, DIO_BASE_REG);
if (ret)
return ret;
s = &dev->subdevices[3];
if (board->is_labpc1200) {
s->type = COMEDI_SUBD_CALIB;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE | SDF_INTERNAL;
s->n_chan = 16;
s->maxdata = 0xff;
s->insn_read = labpc_calib_insn_read;
s->insn_write = labpc_calib_insn_write;
for (i = 0; i < s->n_chan; i++)
write_caldac(dev, i, s->maxdata / 2);
} else {
s->type = COMEDI_SUBD_UNUSED;
}
s = &dev->subdevices[4];
if (board->is_labpc1200) {
s->type = COMEDI_SUBD_MEMORY;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE | SDF_INTERNAL;
s->n_chan = EEPROM_SIZE;
s->maxdata = 0xff;
s->insn_read = labpc_eeprom_insn_read;
s->insn_write = labpc_eeprom_insn_write;
for (i = 0; i < s->n_chan; i++)
devpriv->eeprom_data[i] = labpc_eeprom_read(dev, i);
} else {
s->type = COMEDI_SUBD_UNUSED;
}
return 0;
}
static int __init labpc_common_init(void)
{
return 0;
}
static void __exit labpc_common_exit(void)
{
}
