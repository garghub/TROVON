static void reset_counters(struct comedi_device *dev)
{
outw(0xFFC2, dev->iobase + AM9513A_COM_REG);
outw(0xFF02, dev->iobase + AM9513A_COM_REG);
outw(0x4, dev->iobase + AM9513A_DATA_REG);
outw(0xFF0A, dev->iobase + AM9513A_COM_REG);
outw(0x3, dev->iobase + AM9513A_DATA_REG);
outw(0xFF42, dev->iobase + AM9513A_COM_REG);
outw(0xFF42, dev->iobase + AM9513A_COM_REG);
outw(0xFFC4, dev->iobase + AM9513A_COM_REG);
outw(0xFF03, dev->iobase + AM9513A_COM_REG);
outw(0x4, dev->iobase + AM9513A_DATA_REG);
outw(0xFF0B, dev->iobase + AM9513A_COM_REG);
outw(0x3, dev->iobase + AM9513A_DATA_REG);
outw(0xFF44, dev->iobase + AM9513A_COM_REG);
outw(0xFF44, dev->iobase + AM9513A_COM_REG);
outw(0xFFC8, dev->iobase + AM9513A_COM_REG);
outw(0xFF04, dev->iobase + AM9513A_COM_REG);
outw(0x4, dev->iobase + AM9513A_DATA_REG);
outw(0xFF0C, dev->iobase + AM9513A_COM_REG);
outw(0x3, dev->iobase + AM9513A_DATA_REG);
outw(0xFF48, dev->iobase + AM9513A_COM_REG);
outw(0xFF48, dev->iobase + AM9513A_COM_REG);
outw(0xFFD0, dev->iobase + AM9513A_COM_REG);
outw(0xFF05, dev->iobase + AM9513A_COM_REG);
outw(0x4, dev->iobase + AM9513A_DATA_REG);
outw(0xFF0D, dev->iobase + AM9513A_COM_REG);
outw(0x3, dev->iobase + AM9513A_DATA_REG);
outw(0xFF50, dev->iobase + AM9513A_COM_REG);
outw(0xFF50, dev->iobase + AM9513A_COM_REG);
outw(0, dev->iobase + AD_CLEAR_REG);
}
static void reset_atmio16d(struct comedi_device *dev)
{
struct atmio16d_private *devpriv = dev->private;
int i;
outw(0, dev->iobase + COM_REG_1);
outw(0, dev->iobase + COM_REG_2);
outw(0, dev->iobase + MUX_GAIN_REG);
outw(0xFFFF, dev->iobase + AM9513A_COM_REG);
outw(0xFFEF, dev->iobase + AM9513A_COM_REG);
outw(0xFF17, dev->iobase + AM9513A_COM_REG);
outw(0xF000, dev->iobase + AM9513A_DATA_REG);
for (i = 1; i <= 5; ++i) {
outw(0xFF00 + i, dev->iobase + AM9513A_COM_REG);
outw(0x0004, dev->iobase + AM9513A_DATA_REG);
outw(0xFF08 + i, dev->iobase + AM9513A_COM_REG);
outw(0x3, dev->iobase + AM9513A_DATA_REG);
}
outw(0xFF5F, dev->iobase + AM9513A_COM_REG);
outw(0, dev->iobase + AD_CLEAR_REG);
outw(0, dev->iobase + INT2CLR_REG);
devpriv->com_reg_1_state |= 1;
outw(devpriv->com_reg_1_state, dev->iobase + COM_REG_1);
devpriv->adc_coding = adc_straight;
outw(2048, dev->iobase + DAC0_REG);
outw(2048, dev->iobase + DAC1_REG);
}
static irqreturn_t atmio16d_interrupt(int irq, void *d)
{
struct comedi_device *dev = d;
struct comedi_subdevice *s = &dev->subdevices[0];
comedi_buf_put(s->async, inw(dev->iobase + AD_FIFO_REG));
comedi_event(dev, s);
return IRQ_HANDLED;
}
static int atmio16d_ai_cmdtest(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_cmd *cmd)
{
int err = 0;
err |= cfc_check_trigger_src(&cmd->start_src, TRIG_NOW);
err |= cfc_check_trigger_src(&cmd->scan_begin_src,
TRIG_FOLLOW | TRIG_TIMER);
err |= cfc_check_trigger_src(&cmd->convert_src, TRIG_TIMER);
err |= cfc_check_trigger_src(&cmd->scan_end_src, TRIG_COUNT);
err |= cfc_check_trigger_src(&cmd->stop_src, TRIG_COUNT | TRIG_NONE);
if (err)
return 1;
err |= cfc_check_trigger_is_unique(cmd->scan_begin_src);
err |= cfc_check_trigger_is_unique(cmd->stop_src);
if (err)
return 2;
err |= cfc_check_trigger_arg_is(&cmd->start_arg, 0);
if (cmd->scan_begin_src == TRIG_FOLLOW) {
err |= cfc_check_trigger_arg_is(&cmd->scan_begin_arg, 0);
} else {
#if 0
err |= cfc_check_trigger_arg_is(&cmd->scan_begin_arg, 0);
#endif
}
err |= cfc_check_trigger_arg_min(&cmd->convert_arg, 10000);
#if 0
err |= cfc_check_trigger_arg_max(&cmd->convert_arg, SLOWEST_TIMER);
#endif
err |= cfc_check_trigger_arg_is(&cmd->scan_end_arg, cmd->chanlist_len);
if (cmd->stop_src == TRIG_COUNT) {
} else {
err |= cfc_check_trigger_arg_is(&cmd->stop_arg, 0);
}
if (err)
return 3;
return 0;
}
static int atmio16d_ai_cmd(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct atmio16d_private *devpriv = dev->private;
struct comedi_cmd *cmd = &s->async->cmd;
unsigned int timer, base_clock;
unsigned int sample_count, tmp, chan, gain;
int i;
reset_counters(dev);
s->async->cur_chan = 0;
if (cmd->chanlist_len < 2) {
devpriv->com_reg_1_state &= ~COMREG1_SCANEN;
outw(devpriv->com_reg_1_state, dev->iobase + COM_REG_1);
} else {
devpriv->com_reg_1_state |= COMREG1_SCANEN;
devpriv->com_reg_2_state |= COMREG2_SCN2;
outw(devpriv->com_reg_1_state, dev->iobase + COM_REG_1);
outw(devpriv->com_reg_2_state, dev->iobase + COM_REG_2);
}
for (i = 0; i < cmd->chanlist_len; ++i) {
chan = CR_CHAN(cmd->chanlist[i]);
gain = CR_RANGE(cmd->chanlist[i]);
outw(i, dev->iobase + MUX_CNTR_REG);
tmp = chan | (gain << 6);
if (i == cmd->scan_end_arg - 1)
tmp |= 0x0010;
outw(tmp, dev->iobase + MUX_GAIN_REG);
}
if (cmd->convert_arg < 65536000) {
base_clock = CLOCK_1_MHZ;
timer = cmd->convert_arg / 1000;
} else if (cmd->convert_arg < 655360000) {
base_clock = CLOCK_100_KHZ;
timer = cmd->convert_arg / 10000;
} else if (cmd->convert_arg <= 0xffffffff ) {
base_clock = CLOCK_10_KHZ;
timer = cmd->convert_arg / 100000;
} else if (cmd->convert_arg <= 0xffffffff ) {
base_clock = CLOCK_1_KHZ;
timer = cmd->convert_arg / 1000000;
}
outw(0xFF03, dev->iobase + AM9513A_COM_REG);
outw(base_clock, dev->iobase + AM9513A_DATA_REG);
outw(0xFF0B, dev->iobase + AM9513A_COM_REG);
outw(0x2, dev->iobase + AM9513A_DATA_REG);
outw(0xFF44, dev->iobase + AM9513A_COM_REG);
outw(0xFFF3, dev->iobase + AM9513A_COM_REG);
outw(timer, dev->iobase + AM9513A_DATA_REG);
outw(0xFF24, dev->iobase + AM9513A_COM_REG);
sample_count = cmd->stop_arg * cmd->scan_end_arg;
outw(0xFF04, dev->iobase + AM9513A_COM_REG);
outw(0x1025, dev->iobase + AM9513A_DATA_REG);
outw(0xFF0C, dev->iobase + AM9513A_COM_REG);
if (sample_count < 65536) {
outw(sample_count, dev->iobase + AM9513A_DATA_REG);
outw(0xFF48, dev->iobase + AM9513A_COM_REG);
outw(0xFFF4, dev->iobase + AM9513A_COM_REG);
outw(0xFF28, dev->iobase + AM9513A_COM_REG);
devpriv->com_reg_1_state &= ~COMREG1_1632CNT;
outw(devpriv->com_reg_1_state, dev->iobase + COM_REG_1);
} else {
tmp = sample_count & 0xFFFF;
if (tmp)
outw(tmp - 1, dev->iobase + AM9513A_DATA_REG);
else
outw(0xFFFF, dev->iobase + AM9513A_DATA_REG);
outw(0xFF48, dev->iobase + AM9513A_COM_REG);
outw(0, dev->iobase + AM9513A_DATA_REG);
outw(0xFF28, dev->iobase + AM9513A_COM_REG);
outw(0xFF05, dev->iobase + AM9513A_COM_REG);
outw(0x25, dev->iobase + AM9513A_DATA_REG);
outw(0xFF0D, dev->iobase + AM9513A_COM_REG);
tmp = sample_count & 0xFFFF;
if ((tmp == 0) || (tmp == 1)) {
outw((sample_count >> 16) & 0xFFFF,
dev->iobase + AM9513A_DATA_REG);
} else {
outw(((sample_count >> 16) & 0xFFFF) + 1,
dev->iobase + AM9513A_DATA_REG);
}
outw(0xFF70, dev->iobase + AM9513A_COM_REG);
devpriv->com_reg_1_state |= COMREG1_1632CNT;
outw(devpriv->com_reg_1_state, dev->iobase + COM_REG_1);
}
if (cmd->chanlist_len > 1) {
if (cmd->scan_begin_arg < 65536000) {
base_clock = CLOCK_1_MHZ;
timer = cmd->scan_begin_arg / 1000;
} else if (cmd->scan_begin_arg < 655360000) {
base_clock = CLOCK_100_KHZ;
timer = cmd->scan_begin_arg / 10000;
} else if (cmd->scan_begin_arg < 0xffffffff ) {
base_clock = CLOCK_10_KHZ;
timer = cmd->scan_begin_arg / 100000;
} else if (cmd->scan_begin_arg < 0xffffffff ) {
base_clock = CLOCK_1_KHZ;
timer = cmd->scan_begin_arg / 1000000;
}
outw(0xFF02, dev->iobase + AM9513A_COM_REG);
outw(base_clock, dev->iobase + AM9513A_DATA_REG);
outw(0xFF0A, dev->iobase + AM9513A_COM_REG);
outw(0x2, dev->iobase + AM9513A_DATA_REG);
outw(0xFF42, dev->iobase + AM9513A_COM_REG);
outw(0xFFF2, dev->iobase + AM9513A_COM_REG);
outw(timer, dev->iobase + AM9513A_DATA_REG);
outw(0xFF22, dev->iobase + AM9513A_COM_REG);
}
outw(0, dev->iobase + AD_CLEAR_REG);
outw(0, dev->iobase + MUX_CNTR_REG);
outw(0, dev->iobase + INT2CLR_REG);
devpriv->com_reg_1_state |= COMREG1_DAQEN;
outw(devpriv->com_reg_1_state, dev->iobase + COM_REG_1);
devpriv->com_reg_1_state |= COMREG1_CONVINTEN;
devpriv->com_reg_2_state |= COMREG2_INTEN;
outw(devpriv->com_reg_1_state, dev->iobase + COM_REG_1);
outw(devpriv->com_reg_2_state, dev->iobase + COM_REG_2);
outw(0, dev->iobase + START_DAQ_REG);
return 0;
}
static int atmio16d_ai_cancel(struct comedi_device *dev,
struct comedi_subdevice *s)
{
reset_atmio16d(dev);
return 0;
}
static int atmio16d_ai_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct atmio16d_private *devpriv = dev->private;
int i, t;
int chan;
int gain;
int status;
chan = CR_CHAN(insn->chanspec);
gain = CR_RANGE(insn->chanspec);
outw(chan | (gain << 6), dev->iobase + MUX_GAIN_REG);
for (i = 0; i < insn->n; i++) {
outw(0, dev->iobase + START_CONVERT_REG);
for (t = 0; t < ATMIO16D_TIMEOUT; t++) {
status = inw(dev->iobase + STAT_REG);
if (status & STAT_AD_CONVAVAIL) {
data[i] = inw(dev->iobase + AD_FIFO_REG);
if (devpriv->adc_coding == adc_2comp)
data[i] ^= 0x800;
break;
}
if (status & STAT_AD_OVERFLOW) {
printk(KERN_INFO "atmio16d: a/d FIFO overflow\n");
outw(0, dev->iobase + AD_CLEAR_REG);
return -ETIME;
}
}
if (t == ATMIO16D_TIMEOUT) {
printk(KERN_INFO "atmio16d: timeout\n");
return -ETIME;
}
}
return i;
}
static int atmio16d_ao_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct atmio16d_private *devpriv = dev->private;
int i;
for (i = 0; i < insn->n; i++)
data[i] = devpriv->ao_readback[CR_CHAN(insn->chanspec)];
return i;
}
static int atmio16d_ao_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct atmio16d_private *devpriv = dev->private;
int i;
int chan;
int d;
chan = CR_CHAN(insn->chanspec);
for (i = 0; i < insn->n; i++) {
d = data[i];
switch (chan) {
case 0:
if (devpriv->dac0_coding == dac_2comp)
d ^= 0x800;
outw(d, dev->iobase + DAC0_REG);
break;
case 1:
if (devpriv->dac1_coding == dac_2comp)
d ^= 0x800;
outw(d, dev->iobase + DAC1_REG);
break;
default:
return -EINVAL;
}
devpriv->ao_readback[chan] = data[i];
}
return i;
}
static int atmio16d_dio_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
if (data[0]) {
s->state &= ~data[0];
s->state |= (data[0] | data[1]);
outw(s->state, dev->iobase + MIO_16_DIG_OUT_REG);
}
data[1] = inw(dev->iobase + MIO_16_DIG_IN_REG);
return insn->n;
}
static int atmio16d_dio_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct atmio16d_private *devpriv = dev->private;
int i;
int mask;
for (i = 0; i < insn->n; i++) {
mask = (CR_CHAN(insn->chanspec) < 4) ? 0x0f : 0xf0;
s->io_bits &= ~mask;
if (data[i])
s->io_bits |= mask;
}
devpriv->com_reg_2_state &= ~(COMREG2_DOUTEN0 | COMREG2_DOUTEN1);
if (s->io_bits & 0x0f)
devpriv->com_reg_2_state |= COMREG2_DOUTEN0;
if (s->io_bits & 0xf0)
devpriv->com_reg_2_state |= COMREG2_DOUTEN1;
outw(devpriv->com_reg_2_state, dev->iobase + COM_REG_2);
return i;
}
static int atmio16d_attach(struct comedi_device *dev,
struct comedi_devconfig *it)
{
const struct atmio16_board_t *board = comedi_board(dev);
struct atmio16d_private *devpriv;
struct comedi_subdevice *s;
unsigned int irq;
int ret;
ret = comedi_request_region(dev, it->options[0], ATMIO16D_SIZE);
if (ret)
return ret;
ret = comedi_alloc_subdevices(dev, 4);
if (ret)
return ret;
devpriv = kzalloc(sizeof(*devpriv), GFP_KERNEL);
if (!devpriv)
return -ENOMEM;
dev->private = devpriv;
reset_atmio16d(dev);
irq = it->options[1];
if (irq) {
ret = request_irq(irq, atmio16d_interrupt, 0, "atmio16d", dev);
if (ret < 0) {
printk(KERN_INFO "failed to allocate irq %u\n", irq);
return ret;
}
dev->irq = irq;
printk(KERN_INFO "( irq = %u )\n", irq);
} else {
printk(KERN_INFO "( no irq )");
}
devpriv->adc_mux = it->options[5];
devpriv->adc_range = it->options[6];
devpriv->dac0_range = it->options[7];
devpriv->dac0_reference = it->options[8];
devpriv->dac0_coding = it->options[9];
devpriv->dac1_range = it->options[10];
devpriv->dac1_reference = it->options[11];
devpriv->dac1_coding = it->options[12];
s = &dev->subdevices[0];
dev->read_subdev = s;
s->type = COMEDI_SUBD_AI;
s->subdev_flags = SDF_READABLE | SDF_GROUND | SDF_CMD_READ;
s->n_chan = (devpriv->adc_mux ? 16 : 8);
s->len_chanlist = 16;
s->insn_read = atmio16d_ai_insn_read;
s->do_cmdtest = atmio16d_ai_cmdtest;
s->do_cmd = atmio16d_ai_cmd;
s->cancel = atmio16d_ai_cancel;
s->maxdata = 0xfff;
switch (devpriv->adc_range) {
case adc_bipolar10:
s->range_table = &range_atmio16d_ai_10_bipolar;
break;
case adc_bipolar5:
s->range_table = &range_atmio16d_ai_5_bipolar;
break;
case adc_unipolar10:
s->range_table = &range_atmio16d_ai_unipolar;
break;
}
s = &dev->subdevices[1];
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = 2;
s->insn_read = atmio16d_ao_insn_read;
s->insn_write = atmio16d_ao_insn_write;
s->maxdata = 0xfff;
s->range_table_list = devpriv->ao_range_type_list;
switch (devpriv->dac0_range) {
case dac_bipolar:
devpriv->ao_range_type_list[0] = &range_bipolar10;
break;
case dac_unipolar:
devpriv->ao_range_type_list[0] = &range_unipolar10;
break;
}
switch (devpriv->dac1_range) {
case dac_bipolar:
devpriv->ao_range_type_list[1] = &range_bipolar10;
break;
case dac_unipolar:
devpriv->ao_range_type_list[1] = &range_unipolar10;
break;
}
s = &dev->subdevices[2];
s->type = COMEDI_SUBD_DIO;
s->subdev_flags = SDF_WRITABLE | SDF_READABLE;
s->n_chan = 8;
s->insn_bits = atmio16d_dio_insn_bits;
s->insn_config = atmio16d_dio_insn_config;
s->maxdata = 1;
s->range_table = &range_digital;
s = &dev->subdevices[3];
if (board->has_8255)
subdev_8255_init(dev, s, NULL, dev->iobase);
else
s->type = COMEDI_SUBD_UNUSED;
#if 0
s = &dev->subdevices[4];
s->type = COMEDI_SUBD_TIMER;
s->n_chan = 0;
s->maxdata = 0
#endif
printk("\n");
return 0;
}
static void atmio16d_detach(struct comedi_device *dev)
{
comedi_spriv_free(dev, 3);
reset_atmio16d(dev);
comedi_legacy_detach(dev);
}
