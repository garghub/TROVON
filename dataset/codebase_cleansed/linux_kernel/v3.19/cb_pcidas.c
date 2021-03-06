static inline unsigned int DAC_RANGE(unsigned int channel, unsigned int range)
{
return (range & 0x3) << (8 + 2 * (channel & 0x1));
}
static inline unsigned int DAC_RANGE_MASK(unsigned int channel)
{
return 0x3 << (8 + 2 * (channel & 0x1));
}
static inline unsigned int DAC_CHAN_EN(unsigned int channel)
{
return 1 << (5 + (channel & 0x1));
}
static inline unsigned int DAC_DATA_REG(unsigned int channel)
{
return 2 * (channel & 0x1);
}
static inline unsigned int cal_enable_bits(struct comedi_device *dev)
{
struct cb_pcidas_private *devpriv = dev->private;
return CAL_EN_BIT | CAL_SRC_BITS(devpriv->calibration_source);
}
static int cb_pcidas_ai_eoc(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned long context)
{
struct cb_pcidas_private *devpriv = dev->private;
unsigned int status;
status = inw(devpriv->control_status + ADCMUX_CONT);
if (status & EOC)
return 0;
return -EBUSY;
}
static int cb_pcidas_ai_rinsn(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct cb_pcidas_private *devpriv = dev->private;
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned int range = CR_RANGE(insn->chanspec);
unsigned int aref = CR_AREF(insn->chanspec);
unsigned int bits;
int ret;
int n;
if (insn->chanspec & CR_ALT_SOURCE) {
outw(cal_enable_bits(dev),
devpriv->control_status + CALIBRATION_REG);
chan = 0;
} else {
outw(0, devpriv->control_status + CALIBRATION_REG);
}
bits = BEGIN_SCAN(chan) | END_SCAN(chan) | GAIN_BITS(range);
if (range & IS_UNIPOLAR)
bits |= UNIP;
if (aref != AREF_DIFF)
bits |= SE;
outw(bits, devpriv->control_status + ADCMUX_CONT);
outw(0, devpriv->adc_fifo + ADCFIFOCLR);
for (n = 0; n < insn->n; n++) {
outw(0, devpriv->adc_fifo + ADCDATA);
ret = comedi_timeout(dev, s, insn, cb_pcidas_ai_eoc, 0);
if (ret)
return ret;
data[n] = inw(devpriv->adc_fifo + ADCDATA);
}
return n;
}
static int ai_config_insn(struct comedi_device *dev, struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct cb_pcidas_private *devpriv = dev->private;
int id = data[0];
unsigned int source = data[1];
switch (id) {
case INSN_CONFIG_ALT_SOURCE:
if (source >= 8) {
dev_err(dev->class_dev,
"invalid calibration source: %i\n",
source);
return -EINVAL;
}
devpriv->calibration_source = source;
break;
default:
return -EINVAL;
}
return insn->n;
}
static int cb_pcidas_ao_nofifo_winsn(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct cb_pcidas_private *devpriv = dev->private;
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned int range = CR_RANGE(insn->chanspec);
unsigned long flags;
spin_lock_irqsave(&dev->spinlock, flags);
devpriv->ao_control_bits &= (~DAC_MODE_UPDATE_BOTH &
~DAC_RANGE_MASK(chan));
devpriv->ao_control_bits |= (DACEN | DAC_RANGE(chan, range));
outw(devpriv->ao_control_bits, devpriv->control_status + DAC_CSR);
spin_unlock_irqrestore(&dev->spinlock, flags);
s->readback[chan] = data[0];
outw(data[0], devpriv->ao_registers + DAC_DATA_REG(chan));
return insn->n;
}
static int cb_pcidas_ao_fifo_winsn(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct cb_pcidas_private *devpriv = dev->private;
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned int range = CR_RANGE(insn->chanspec);
unsigned long flags;
outw(0, devpriv->ao_registers + DACFIFOCLR);
spin_lock_irqsave(&dev->spinlock, flags);
devpriv->ao_control_bits &= (~DAC_CHAN_EN(0) & ~DAC_CHAN_EN(1) &
~DAC_RANGE_MASK(chan) & ~DAC_PACER_MASK);
devpriv->ao_control_bits |= (DACEN | DAC_RANGE(chan, range) |
DAC_CHAN_EN(chan) | DAC_START);
outw(devpriv->ao_control_bits, devpriv->control_status + DAC_CSR);
spin_unlock_irqrestore(&dev->spinlock, flags);
s->readback[chan] = data[0];
outw(data[0], devpriv->ao_registers + DACDATA);
return insn->n;
}
static int wait_for_nvram_ready(unsigned long s5933_base_addr)
{
static const int timeout = 1000;
unsigned int i;
for (i = 0; i < timeout; i++) {
if ((inb(s5933_base_addr +
AMCC_OP_REG_MCSR_NVCMD) & MCSR_NV_BUSY)
== 0)
return 0;
udelay(1);
}
return -1;
}
static int nvram_read(struct comedi_device *dev, unsigned int address,
uint8_t *data)
{
struct cb_pcidas_private *devpriv = dev->private;
unsigned long iobase = devpriv->s5933_config;
if (wait_for_nvram_ready(iobase) < 0)
return -ETIMEDOUT;
outb(MCSR_NV_ENABLE | MCSR_NV_LOAD_LOW_ADDR,
iobase + AMCC_OP_REG_MCSR_NVCMD);
outb(address & 0xff, iobase + AMCC_OP_REG_MCSR_NVDATA);
outb(MCSR_NV_ENABLE | MCSR_NV_LOAD_HIGH_ADDR,
iobase + AMCC_OP_REG_MCSR_NVCMD);
outb((address >> 8) & 0xff, iobase + AMCC_OP_REG_MCSR_NVDATA);
outb(MCSR_NV_ENABLE | MCSR_NV_READ, iobase + AMCC_OP_REG_MCSR_NVCMD);
if (wait_for_nvram_ready(iobase) < 0)
return -ETIMEDOUT;
*data = inb(iobase + AMCC_OP_REG_MCSR_NVDATA);
return 0;
}
static int eeprom_read_insn(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
uint8_t nvram_data;
int retval;
retval = nvram_read(dev, CR_CHAN(insn->chanspec), &nvram_data);
if (retval < 0)
return retval;
data[0] = nvram_data;
return 1;
}
static void write_calibration_bitstream(struct comedi_device *dev,
unsigned int register_bits,
unsigned int bitstream,
unsigned int bitstream_length)
{
struct cb_pcidas_private *devpriv = dev->private;
static const int write_delay = 1;
unsigned int bit;
for (bit = 1 << (bitstream_length - 1); bit; bit >>= 1) {
if (bitstream & bit)
register_bits |= SERIAL_DATA_IN_BIT;
else
register_bits &= ~SERIAL_DATA_IN_BIT;
udelay(write_delay);
outw(register_bits, devpriv->control_status + CALIBRATION_REG);
}
}
static void caldac_8800_write(struct comedi_device *dev,
unsigned int chan, uint8_t val)
{
struct cb_pcidas_private *devpriv = dev->private;
static const int bitstream_length = 11;
unsigned int bitstream = ((chan & 0x7) << 8) | val;
static const int caldac_8800_udelay = 1;
write_calibration_bitstream(dev, cal_enable_bits(dev), bitstream,
bitstream_length);
udelay(caldac_8800_udelay);
outw(cal_enable_bits(dev) | SELECT_8800_BIT,
devpriv->control_status + CALIBRATION_REG);
udelay(caldac_8800_udelay);
outw(cal_enable_bits(dev), devpriv->control_status + CALIBRATION_REG);
}
static int cb_pcidas_caldac_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned int chan = CR_CHAN(insn->chanspec);
if (insn->n) {
unsigned int val = data[insn->n - 1];
if (s->readback[chan] != val) {
caldac_8800_write(dev, chan, val);
s->readback[chan] = val;
}
}
return insn->n;
}
static void dac08_write(struct comedi_device *dev, unsigned int value)
{
struct cb_pcidas_private *devpriv = dev->private;
value &= 0xff;
value |= cal_enable_bits(dev);
outw(value, devpriv->control_status + CALIBRATION_REG);
udelay(1);
outw(value | SELECT_DAC08_BIT,
devpriv->control_status + CALIBRATION_REG);
udelay(1);
outw(value, devpriv->control_status + CALIBRATION_REG);
udelay(1);
}
static int cb_pcidas_dac08_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned int chan = CR_CHAN(insn->chanspec);
if (insn->n) {
unsigned int val = data[insn->n - 1];
if (s->readback[chan] != val) {
dac08_write(dev, val);
s->readback[chan] = val;
}
}
return insn->n;
}
static int trimpot_7376_write(struct comedi_device *dev, uint8_t value)
{
struct cb_pcidas_private *devpriv = dev->private;
static const int bitstream_length = 7;
unsigned int bitstream = value & 0x7f;
unsigned int register_bits;
static const int ad7376_udelay = 1;
register_bits = cal_enable_bits(dev) | SELECT_TRIMPOT_BIT;
udelay(ad7376_udelay);
outw(register_bits, devpriv->control_status + CALIBRATION_REG);
write_calibration_bitstream(dev, register_bits, bitstream,
bitstream_length);
udelay(ad7376_udelay);
outw(cal_enable_bits(dev), devpriv->control_status + CALIBRATION_REG);
return 0;
}
static int trimpot_8402_write(struct comedi_device *dev, unsigned int channel,
uint8_t value)
{
struct cb_pcidas_private *devpriv = dev->private;
static const int bitstream_length = 10;
unsigned int bitstream = ((channel & 0x3) << 8) | (value & 0xff);
unsigned int register_bits;
static const int ad8402_udelay = 1;
register_bits = cal_enable_bits(dev) | SELECT_TRIMPOT_BIT;
udelay(ad8402_udelay);
outw(register_bits, devpriv->control_status + CALIBRATION_REG);
write_calibration_bitstream(dev, register_bits, bitstream,
bitstream_length);
udelay(ad8402_udelay);
outw(cal_enable_bits(dev), devpriv->control_status + CALIBRATION_REG);
return 0;
}
static void cb_pcidas_trimpot_write(struct comedi_device *dev,
unsigned int chan, unsigned int val)
{
const struct cb_pcidas_board *thisboard = dev->board_ptr;
switch (thisboard->trimpot) {
case AD7376:
trimpot_7376_write(dev, val);
break;
case AD8402:
trimpot_8402_write(dev, chan, val);
break;
default:
dev_err(dev->class_dev, "driver bug?\n");
break;
}
}
static int cb_pcidas_trimpot_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned int chan = CR_CHAN(insn->chanspec);
if (insn->n) {
unsigned int val = data[insn->n - 1];
if (s->readback[chan] != val) {
cb_pcidas_trimpot_write(dev, chan, val);
s->readback[chan] = val;
}
}
return insn->n;
}
static int cb_pcidas_ai_check_chanlist(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_cmd *cmd)
{
unsigned int chan0 = CR_CHAN(cmd->chanlist[0]);
unsigned int range0 = CR_RANGE(cmd->chanlist[0]);
int i;
for (i = 1; i < cmd->chanlist_len; i++) {
unsigned int chan = CR_CHAN(cmd->chanlist[i]);
unsigned int range = CR_RANGE(cmd->chanlist[i]);
if (chan != (chan0 + i) % s->n_chan) {
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
static int cb_pcidas_ai_cmdtest(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_cmd *cmd)
{
const struct cb_pcidas_board *thisboard = dev->board_ptr;
struct cb_pcidas_private *devpriv = dev->private;
int err = 0;
unsigned int arg;
err |= cfc_check_trigger_src(&cmd->start_src, TRIG_NOW | TRIG_EXT);
err |= cfc_check_trigger_src(&cmd->scan_begin_src,
TRIG_FOLLOW | TRIG_TIMER | TRIG_EXT);
err |= cfc_check_trigger_src(&cmd->convert_src,
TRIG_TIMER | TRIG_NOW | TRIG_EXT);
err |= cfc_check_trigger_src(&cmd->scan_end_src, TRIG_COUNT);
err |= cfc_check_trigger_src(&cmd->stop_src, TRIG_COUNT | TRIG_NONE);
if (err)
return 1;
err |= cfc_check_trigger_is_unique(cmd->start_src);
err |= cfc_check_trigger_is_unique(cmd->scan_begin_src);
err |= cfc_check_trigger_is_unique(cmd->convert_src);
err |= cfc_check_trigger_is_unique(cmd->stop_src);
if (cmd->scan_begin_src == TRIG_FOLLOW && cmd->convert_src == TRIG_NOW)
err |= -EINVAL;
if (cmd->scan_begin_src != TRIG_FOLLOW && cmd->convert_src != TRIG_NOW)
err |= -EINVAL;
if (cmd->start_src == TRIG_EXT &&
(cmd->convert_src == TRIG_EXT || cmd->scan_begin_src == TRIG_EXT))
err |= -EINVAL;
if (err)
return 2;
switch (cmd->start_src) {
case TRIG_NOW:
err |= cfc_check_trigger_arg_is(&cmd->start_arg, 0);
break;
case TRIG_EXT:
if ((cmd->start_arg
& (CR_FLAGS_MASK & ~(CR_EDGE | CR_INVERT))) != 0) {
cmd->start_arg &= ~(CR_FLAGS_MASK &
~(CR_EDGE | CR_INVERT));
err |= -EINVAL;
}
if (!thisboard->is_1602 && (cmd->start_arg & CR_INVERT)) {
cmd->start_arg &= (CR_FLAGS_MASK & ~CR_INVERT);
err |= -EINVAL;
}
break;
}
if (cmd->scan_begin_src == TRIG_TIMER)
err |= cfc_check_trigger_arg_min(&cmd->scan_begin_arg,
thisboard->ai_speed * cmd->chanlist_len);
if (cmd->convert_src == TRIG_TIMER)
err |= cfc_check_trigger_arg_min(&cmd->convert_arg,
thisboard->ai_speed);
err |= cfc_check_trigger_arg_is(&cmd->scan_end_arg, cmd->chanlist_len);
if (cmd->stop_src == TRIG_COUNT)
err |= cfc_check_trigger_arg_min(&cmd->stop_arg, 1);
else
err |= cfc_check_trigger_arg_is(&cmd->stop_arg, 0);
if (err)
return 3;
if (cmd->scan_begin_src == TRIG_TIMER) {
arg = cmd->scan_begin_arg;
i8253_cascade_ns_to_timer(I8254_OSC_BASE_10MHZ,
&devpriv->divisor1,
&devpriv->divisor2,
&arg, cmd->flags);
err |= cfc_check_trigger_arg_is(&cmd->scan_begin_arg, arg);
}
if (cmd->convert_src == TRIG_TIMER) {
arg = cmd->convert_arg;
i8253_cascade_ns_to_timer(I8254_OSC_BASE_10MHZ,
&devpriv->divisor1,
&devpriv->divisor2,
&arg, cmd->flags);
err |= cfc_check_trigger_arg_is(&cmd->convert_arg, arg);
}
if (err)
return 4;
if (cmd->chanlist && cmd->chanlist_len > 0)
err |= cb_pcidas_ai_check_chanlist(dev, s, cmd);
if (err)
return 5;
return 0;
}
static void cb_pcidas_ai_load_counters(struct comedi_device *dev)
{
struct cb_pcidas_private *devpriv = dev->private;
unsigned long timer_base = dev->iobase + ADC8254;
i8254_set_mode(timer_base, 0, 1, I8254_MODE2 | I8254_BINARY);
i8254_set_mode(timer_base, 0, 2, I8254_MODE2 | I8254_BINARY);
i8254_write(timer_base, 0, 1, devpriv->divisor1);
i8254_write(timer_base, 0, 2, devpriv->divisor2);
}
static int cb_pcidas_ai_cmd(struct comedi_device *dev,
struct comedi_subdevice *s)
{
const struct cb_pcidas_board *thisboard = dev->board_ptr;
struct cb_pcidas_private *devpriv = dev->private;
struct comedi_async *async = s->async;
struct comedi_cmd *cmd = &async->cmd;
unsigned int bits;
unsigned long flags;
outw(0, devpriv->control_status + CALIBRATION_REG);
outw(0, devpriv->control_status + TRIG_CONTSTAT);
outw(0, devpriv->adc_fifo + ADCFIFOCLR);
bits = BEGIN_SCAN(CR_CHAN(cmd->chanlist[0])) |
END_SCAN(CR_CHAN(cmd->chanlist[cmd->chanlist_len - 1])) |
GAIN_BITS(CR_RANGE(cmd->chanlist[0]));
if (CR_RANGE(cmd->chanlist[0]) & IS_UNIPOLAR)
bits |= UNIP;
if (CR_AREF(cmd->chanlist[0]) != AREF_DIFF)
bits |= SE;
if (cmd->convert_src == TRIG_EXT || cmd->scan_begin_src == TRIG_EXT)
bits |= PACER_EXT_RISE;
else
bits |= PACER_INT;
outw(bits, devpriv->control_status + ADCMUX_CONT);
if (cmd->scan_begin_src == TRIG_TIMER || cmd->convert_src == TRIG_TIMER)
cb_pcidas_ai_load_counters(dev);
spin_lock_irqsave(&dev->spinlock, flags);
devpriv->adc_fifo_bits |= INTE;
devpriv->adc_fifo_bits &= ~INT_MASK;
if (cmd->flags & CMDF_WAKE_EOS) {
if (cmd->convert_src == TRIG_NOW && cmd->chanlist_len > 1) {
devpriv->adc_fifo_bits |= INT_EOS;
} else {
devpriv->adc_fifo_bits |= INT_FNE;
}
} else {
devpriv->adc_fifo_bits |= INT_FHF;
}
outw(devpriv->adc_fifo_bits | EOAI | INT | LADFUL,
devpriv->control_status + INT_ADCFIFO);
spin_unlock_irqrestore(&dev->spinlock, flags);
bits = 0;
if (cmd->start_src == TRIG_NOW) {
bits |= SW_TRIGGER;
} else {
bits |= EXT_TRIGGER | TGEN | XTRCL;
if (thisboard->is_1602) {
if (cmd->start_arg & CR_INVERT)
bits |= TGPOL;
if (cmd->start_arg & CR_EDGE)
bits |= TGSEL;
}
}
if (cmd->convert_src == TRIG_NOW && cmd->chanlist_len > 1)
bits |= BURSTE;
outw(bits, devpriv->control_status + TRIG_CONTSTAT);
return 0;
}
static int cb_pcidas_ao_check_chanlist(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_cmd *cmd)
{
unsigned int chan0 = CR_CHAN(cmd->chanlist[0]);
if (cmd->chanlist_len > 1) {
unsigned int chan1 = CR_CHAN(cmd->chanlist[1]);
if (chan0 != 0 || chan1 != 1) {
dev_dbg(dev->class_dev,
"channels must be ordered channel 0, channel 1 in chanlist\n");
return -EINVAL;
}
}
return 0;
}
static int cb_pcidas_ao_cmdtest(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_cmd *cmd)
{
const struct cb_pcidas_board *thisboard = dev->board_ptr;
struct cb_pcidas_private *devpriv = dev->private;
int err = 0;
unsigned int arg;
err |= cfc_check_trigger_src(&cmd->start_src, TRIG_INT);
err |= cfc_check_trigger_src(&cmd->scan_begin_src,
TRIG_TIMER | TRIG_EXT);
err |= cfc_check_trigger_src(&cmd->convert_src, TRIG_NOW);
err |= cfc_check_trigger_src(&cmd->scan_end_src, TRIG_COUNT);
err |= cfc_check_trigger_src(&cmd->stop_src, TRIG_COUNT | TRIG_NONE);
if (err)
return 1;
err |= cfc_check_trigger_is_unique(cmd->scan_begin_src);
err |= cfc_check_trigger_is_unique(cmd->stop_src);
if (err)
return 2;
err |= cfc_check_trigger_arg_is(&cmd->start_arg, 0);
if (cmd->scan_begin_src == TRIG_TIMER)
err |= cfc_check_trigger_arg_min(&cmd->scan_begin_arg,
thisboard->ao_scan_speed);
err |= cfc_check_trigger_arg_is(&cmd->scan_end_arg, cmd->chanlist_len);
if (cmd->stop_src == TRIG_COUNT)
err |= cfc_check_trigger_arg_min(&cmd->stop_arg, 1);
else
err |= cfc_check_trigger_arg_is(&cmd->stop_arg, 0);
if (err)
return 3;
if (cmd->scan_begin_src == TRIG_TIMER) {
arg = cmd->scan_begin_arg;
i8253_cascade_ns_to_timer(I8254_OSC_BASE_10MHZ,
&devpriv->ao_divisor1,
&devpriv->ao_divisor2,
&arg, cmd->flags);
err |= cfc_check_trigger_arg_is(&cmd->scan_begin_arg, arg);
}
if (err)
return 4;
if (cmd->chanlist && cmd->chanlist_len > 0)
err |= cb_pcidas_ao_check_chanlist(dev, s, cmd);
if (err)
return 5;
return 0;
}
static int cb_pcidas_cancel(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct cb_pcidas_private *devpriv = dev->private;
unsigned long flags;
spin_lock_irqsave(&dev->spinlock, flags);
devpriv->adc_fifo_bits &= ~INTE & ~EOAIE;
outw(devpriv->adc_fifo_bits, devpriv->control_status + INT_ADCFIFO);
spin_unlock_irqrestore(&dev->spinlock, flags);
outw(0, devpriv->control_status + TRIG_CONTSTAT);
outw(0, devpriv->control_status + ADCMUX_CONT);
return 0;
}
static void cb_pcidas_ao_load_fifo(struct comedi_device *dev,
struct comedi_subdevice *s,
unsigned int nsamples)
{
struct cb_pcidas_private *devpriv = dev->private;
unsigned int nbytes;
nsamples = comedi_nsamples_left(s, nsamples);
nbytes = comedi_buf_read_samples(s, devpriv->ao_buffer, nsamples);
nsamples = comedi_bytes_to_samples(s, nbytes);
outsw(devpriv->ao_registers + DACDATA, devpriv->ao_buffer, nsamples);
}
static int cb_pcidas_ao_inttrig(struct comedi_device *dev,
struct comedi_subdevice *s,
unsigned int trig_num)
{
const struct cb_pcidas_board *thisboard = dev->board_ptr;
struct cb_pcidas_private *devpriv = dev->private;
struct comedi_async *async = s->async;
struct comedi_cmd *cmd = &async->cmd;
unsigned long flags;
if (trig_num != cmd->start_arg)
return -EINVAL;
cb_pcidas_ao_load_fifo(dev, s, thisboard->fifo_size);
spin_lock_irqsave(&dev->spinlock, flags);
devpriv->adc_fifo_bits |= DAEMIE | DAHFIE;
outw(devpriv->adc_fifo_bits | DAEMI | DAHFI,
devpriv->control_status + INT_ADCFIFO);
devpriv->ao_control_bits |= DAC_START | DACEN | DAC_EMPTY;
outw(devpriv->ao_control_bits, devpriv->control_status + DAC_CSR);
spin_unlock_irqrestore(&dev->spinlock, flags);
async->inttrig = NULL;
return 0;
}
static void cb_pcidas_ao_load_counters(struct comedi_device *dev)
{
struct cb_pcidas_private *devpriv = dev->private;
unsigned long timer_base = dev->iobase + DAC8254;
i8254_set_mode(timer_base, 0, 1, I8254_MODE2 | I8254_BINARY);
i8254_set_mode(timer_base, 0, 2, I8254_MODE2 | I8254_BINARY);
i8254_write(timer_base, 0, 1, devpriv->ao_divisor1);
i8254_write(timer_base, 0, 2, devpriv->ao_divisor2);
}
static int cb_pcidas_ao_cmd(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct cb_pcidas_private *devpriv = dev->private;
struct comedi_async *async = s->async;
struct comedi_cmd *cmd = &async->cmd;
unsigned int i;
unsigned long flags;
spin_lock_irqsave(&dev->spinlock, flags);
for (i = 0; i < cmd->chanlist_len; i++) {
devpriv->ao_control_bits |=
DAC_CHAN_EN(CR_CHAN(cmd->chanlist[i]));
devpriv->ao_control_bits |= DAC_RANGE(CR_CHAN(cmd->chanlist[i]),
CR_RANGE(cmd->
chanlist[i]));
}
outw(devpriv->ao_control_bits, devpriv->control_status + DAC_CSR);
spin_unlock_irqrestore(&dev->spinlock, flags);
outw(0, devpriv->ao_registers + DACFIFOCLR);
if (cmd->scan_begin_src == TRIG_TIMER)
cb_pcidas_ao_load_counters(dev);
spin_lock_irqsave(&dev->spinlock, flags);
switch (cmd->scan_begin_src) {
case TRIG_TIMER:
devpriv->ao_control_bits |= DAC_PACER_INT;
break;
case TRIG_EXT:
devpriv->ao_control_bits |= DAC_PACER_EXT_RISE;
break;
default:
spin_unlock_irqrestore(&dev->spinlock, flags);
dev_err(dev->class_dev, "error setting dac pacer source\n");
return -1;
}
spin_unlock_irqrestore(&dev->spinlock, flags);
async->inttrig = cb_pcidas_ao_inttrig;
return 0;
}
static int cb_pcidas_ao_cancel(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct cb_pcidas_private *devpriv = dev->private;
unsigned long flags;
spin_lock_irqsave(&dev->spinlock, flags);
devpriv->adc_fifo_bits &= ~DAHFIE & ~DAEMIE;
outw(devpriv->adc_fifo_bits, devpriv->control_status + INT_ADCFIFO);
devpriv->ao_control_bits &= ~DACEN & ~DAC_PACER_MASK;
outw(devpriv->ao_control_bits, devpriv->control_status + DAC_CSR);
spin_unlock_irqrestore(&dev->spinlock, flags);
return 0;
}
static void handle_ao_interrupt(struct comedi_device *dev, unsigned int status)
{
const struct cb_pcidas_board *thisboard = dev->board_ptr;
struct cb_pcidas_private *devpriv = dev->private;
struct comedi_subdevice *s = dev->write_subdev;
struct comedi_async *async = s->async;
struct comedi_cmd *cmd = &async->cmd;
unsigned long flags;
if (status & DAEMI) {
spin_lock_irqsave(&dev->spinlock, flags);
outw(devpriv->adc_fifo_bits | DAEMI,
devpriv->control_status + INT_ADCFIFO);
spin_unlock_irqrestore(&dev->spinlock, flags);
if (inw(devpriv->ao_registers + DAC_CSR) & DAC_EMPTY) {
if (cmd->stop_src == TRIG_COUNT &&
async->scans_done >= cmd->stop_arg) {
async->events |= COMEDI_CB_EOA;
} else {
dev_err(dev->class_dev, "dac fifo underflow\n");
async->events |= COMEDI_CB_ERROR;
}
}
} else if (status & DAHFI) {
cb_pcidas_ao_load_fifo(dev, s, thisboard->fifo_size / 2);
spin_lock_irqsave(&dev->spinlock, flags);
outw(devpriv->adc_fifo_bits | DAHFI,
devpriv->control_status + INT_ADCFIFO);
spin_unlock_irqrestore(&dev->spinlock, flags);
}
comedi_handle_events(dev, s);
}
static irqreturn_t cb_pcidas_interrupt(int irq, void *d)
{
struct comedi_device *dev = (struct comedi_device *)d;
const struct cb_pcidas_board *thisboard = dev->board_ptr;
struct cb_pcidas_private *devpriv = dev->private;
struct comedi_subdevice *s = dev->read_subdev;
struct comedi_async *async;
struct comedi_cmd *cmd;
int status, s5933_status;
int half_fifo = thisboard->fifo_size / 2;
unsigned int num_samples, i;
static const int timeout = 10000;
unsigned long flags;
if (!dev->attached)
return IRQ_NONE;
async = s->async;
cmd = &async->cmd;
s5933_status = inl(devpriv->s5933_config + AMCC_OP_REG_INTCSR);
if ((INTCSR_INTR_ASSERTED & s5933_status) == 0)
return IRQ_NONE;
inl_p(devpriv->s5933_config + AMCC_OP_REG_IMB4);
outl(devpriv->s5933_intcsr_bits | INTCSR_INBOX_INTR_STATUS,
devpriv->s5933_config + AMCC_OP_REG_INTCSR);
status = inw(devpriv->control_status + INT_ADCFIFO);
if (status & (DAHFI | DAEMI))
handle_ao_interrupt(dev, status);
if (status & ADHFI) {
num_samples = comedi_nsamples_left(s, half_fifo);
insw(devpriv->adc_fifo + ADCDATA, devpriv->ai_buffer,
num_samples);
comedi_buf_write_samples(s, devpriv->ai_buffer, num_samples);
if (cmd->stop_src == TRIG_COUNT &&
async->scans_done >= cmd->stop_arg)
async->events |= COMEDI_CB_EOA;
spin_lock_irqsave(&dev->spinlock, flags);
outw(devpriv->adc_fifo_bits | INT,
devpriv->control_status + INT_ADCFIFO);
spin_unlock_irqrestore(&dev->spinlock, flags);
} else if (status & (ADNEI | EOBI)) {
for (i = 0; i < timeout; i++) {
unsigned short val;
if ((ADNE & inw(devpriv->control_status +
INT_ADCFIFO)) == 0)
break;
val = inw(devpriv->adc_fifo);
comedi_buf_write_samples(s, &val, 1);
if (cmd->stop_src == TRIG_COUNT &&
async->scans_done >= cmd->stop_arg) {
async->events |= COMEDI_CB_EOA;
break;
}
}
spin_lock_irqsave(&dev->spinlock, flags);
outw(devpriv->adc_fifo_bits | INT,
devpriv->control_status + INT_ADCFIFO);
spin_unlock_irqrestore(&dev->spinlock, flags);
} else if (status & EOAI) {
dev_err(dev->class_dev,
"bug! encountered end of acquisition interrupt?\n");
spin_lock_irqsave(&dev->spinlock, flags);
outw(devpriv->adc_fifo_bits | EOAI,
devpriv->control_status + INT_ADCFIFO);
spin_unlock_irqrestore(&dev->spinlock, flags);
}
if (status & LADFUL) {
dev_err(dev->class_dev, "fifo overflow\n");
spin_lock_irqsave(&dev->spinlock, flags);
outw(devpriv->adc_fifo_bits | LADFUL,
devpriv->control_status + INT_ADCFIFO);
spin_unlock_irqrestore(&dev->spinlock, flags);
async->events |= COMEDI_CB_EOA | COMEDI_CB_ERROR;
}
comedi_handle_events(dev, s);
return IRQ_HANDLED;
}
static int cb_pcidas_auto_attach(struct comedi_device *dev,
unsigned long context)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
const struct cb_pcidas_board *thisboard = NULL;
struct cb_pcidas_private *devpriv;
struct comedi_subdevice *s;
int i;
int ret;
if (context < ARRAY_SIZE(cb_pcidas_boards))
thisboard = &cb_pcidas_boards[context];
if (!thisboard)
return -ENODEV;
dev->board_ptr = thisboard;
dev->board_name = thisboard->name;
devpriv = comedi_alloc_devpriv(dev, sizeof(*devpriv));
if (!devpriv)
return -ENOMEM;
ret = comedi_pci_enable(dev);
if (ret)
return ret;
devpriv->s5933_config = pci_resource_start(pcidev, 0);
devpriv->control_status = pci_resource_start(pcidev, 1);
devpriv->adc_fifo = pci_resource_start(pcidev, 2);
dev->iobase = pci_resource_start(pcidev, 3);
if (thisboard->ao_nchan)
devpriv->ao_registers = pci_resource_start(pcidev, 4);
outl(INTCSR_INBOX_INTR_STATUS,
devpriv->s5933_config + AMCC_OP_REG_INTCSR);
ret = request_irq(pcidev->irq, cb_pcidas_interrupt, IRQF_SHARED,
dev->board_name, dev);
if (ret) {
dev_dbg(dev->class_dev, "unable to allocate irq %d\n",
pcidev->irq);
return ret;
}
dev->irq = pcidev->irq;
ret = comedi_alloc_subdevices(dev, 7);
if (ret)
return ret;
s = &dev->subdevices[0];
dev->read_subdev = s;
s->type = COMEDI_SUBD_AI;
s->subdev_flags = SDF_READABLE | SDF_GROUND | SDF_DIFF | SDF_CMD_READ;
s->n_chan = thisboard->ai_nchan;
s->len_chanlist = thisboard->ai_nchan;
s->maxdata = (1 << thisboard->ai_bits) - 1;
s->range_table = thisboard->ranges;
s->insn_read = cb_pcidas_ai_rinsn;
s->insn_config = ai_config_insn;
s->do_cmd = cb_pcidas_ai_cmd;
s->do_cmdtest = cb_pcidas_ai_cmdtest;
s->cancel = cb_pcidas_cancel;
s = &dev->subdevices[1];
if (thisboard->ao_nchan) {
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE | SDF_GROUND;
s->n_chan = thisboard->ao_nchan;
s->maxdata = (1 << thisboard->ai_bits) - 1;
s->range_table = &cb_pcidas_ao_ranges;
s->insn_write = cb_pcidas_ao_nofifo_winsn;
ret = comedi_alloc_subdev_readback(s);
if (ret)
return ret;
if (thisboard->has_ao_fifo) {
dev->write_subdev = s;
s->subdev_flags |= SDF_CMD_WRITE;
s->insn_write = cb_pcidas_ao_fifo_winsn;
s->do_cmdtest = cb_pcidas_ao_cmdtest;
s->do_cmd = cb_pcidas_ao_cmd;
s->cancel = cb_pcidas_ao_cancel;
}
} else {
s->type = COMEDI_SUBD_UNUSED;
}
s = &dev->subdevices[2];
ret = subdev_8255_init(dev, s, NULL, DIO_8255);
if (ret)
return ret;
s = &dev->subdevices[3];
s->type = COMEDI_SUBD_MEMORY;
s->subdev_flags = SDF_READABLE | SDF_INTERNAL;
s->n_chan = 256;
s->maxdata = 0xff;
s->insn_read = eeprom_read_insn;
s = &dev->subdevices[4];
s->type = COMEDI_SUBD_CALIB;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE | SDF_INTERNAL;
s->n_chan = NUM_CHANNELS_8800;
s->maxdata = 0xff;
s->insn_write = cb_pcidas_caldac_insn_write;
ret = comedi_alloc_subdev_readback(s);
if (ret)
return ret;
for (i = 0; i < s->n_chan; i++) {
caldac_8800_write(dev, i, s->maxdata / 2);
s->readback[i] = s->maxdata / 2;
}
s = &dev->subdevices[5];
s->type = COMEDI_SUBD_CALIB;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE | SDF_INTERNAL;
if (thisboard->trimpot == AD7376) {
s->n_chan = NUM_CHANNELS_7376;
s->maxdata = 0x7f;
} else {
s->n_chan = NUM_CHANNELS_8402;
s->maxdata = 0xff;
}
s->insn_write = cb_pcidas_trimpot_insn_write;
ret = comedi_alloc_subdev_readback(s);
if (ret)
return ret;
for (i = 0; i < s->n_chan; i++) {
cb_pcidas_trimpot_write(dev, i, s->maxdata / 2);
s->readback[i] = s->maxdata / 2;
}
s = &dev->subdevices[6];
if (thisboard->has_dac08) {
s->type = COMEDI_SUBD_CALIB;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE | SDF_INTERNAL;
s->n_chan = NUM_CHANNELS_DAC08;
s->maxdata = 0xff;
s->insn_write = cb_pcidas_dac08_insn_write;
ret = comedi_alloc_subdev_readback(s);
if (ret)
return ret;
for (i = 0; i < s->n_chan; i++) {
dac08_write(dev, s->maxdata / 2);
s->readback[i] = s->maxdata / 2;
}
} else
s->type = COMEDI_SUBD_UNUSED;
inl(devpriv->s5933_config + AMCC_OP_REG_IMB4);
devpriv->s5933_intcsr_bits =
INTCSR_INBOX_BYTE(3) | INTCSR_INBOX_SELECT(3) |
INTCSR_INBOX_FULL_INT;
outl(devpriv->s5933_intcsr_bits | INTCSR_INBOX_INTR_STATUS,
devpriv->s5933_config + AMCC_OP_REG_INTCSR);
return 0;
}
static void cb_pcidas_detach(struct comedi_device *dev)
{
struct cb_pcidas_private *devpriv = dev->private;
if (devpriv && devpriv->s5933_config) {
outl(INTCSR_INBOX_INTR_STATUS,
devpriv->s5933_config + AMCC_OP_REG_INTCSR);
}
comedi_pci_detach(dev);
}
static int cb_pcidas_pci_probe(struct pci_dev *dev,
const struct pci_device_id *id)
{
return comedi_pci_auto_config(dev, &cb_pcidas_driver,
id->driver_data);
}
