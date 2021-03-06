static void dmm32at_ai_set_chanspec(struct comedi_device *dev,
struct comedi_subdevice *s,
unsigned int chanspec, int nchan)
{
unsigned int chan = CR_CHAN(chanspec);
unsigned int range = CR_RANGE(chanspec);
unsigned int last_chan = (chan + nchan - 1) % s->n_chan;
outb(DMM32AT_FIFO_CTRL_FIFORST, dev->iobase + DMM32AT_FIFO_CTRL_REG);
if (nchan > 1)
outb(DMM32AT_FIFO_CTRL_SCANEN,
dev->iobase + DMM32AT_FIFO_CTRL_REG);
outb(chan, dev->iobase + DMM32AT_AI_LO_CHAN_REG);
outb(last_chan, dev->iobase + DMM32AT_AI_HI_CHAN_REG);
outb(dmm32at_rangebits[range], dev->iobase + DMM32AT_AI_CFG_REG);
}
static unsigned int dmm32at_ai_get_sample(struct comedi_device *dev,
struct comedi_subdevice *s)
{
unsigned int val;
val = inb(dev->iobase + DMM32AT_AI_LSB_REG);
val |= (inb(dev->iobase + DMM32AT_AI_MSB_REG) << 8);
return comedi_offset_munge(s, val);
}
static int dmm32at_ai_status(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned long context)
{
unsigned char status;
status = inb(dev->iobase + context);
if ((status & DMM32AT_AI_STATUS_STS) == 0)
return 0;
return -EBUSY;
}
static int dmm32at_ai_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
int ret;
int i;
dmm32at_ai_set_chanspec(dev, s, insn->chanspec, 1);
ret = comedi_timeout(dev, s, insn, dmm32at_ai_status,
DMM32AT_AI_READBACK_REG);
if (ret)
return ret;
for (i = 0; i < insn->n; i++) {
outb(0xff, dev->iobase + DMM32AT_AI_START_CONV_REG);
ret = comedi_timeout(dev, s, insn, dmm32at_ai_status,
DMM32AT_AI_STATUS_REG);
if (ret)
return ret;
data[i] = dmm32at_ai_get_sample(dev, s);
}
return insn->n;
}
static int dmm32at_ai_check_chanlist(struct comedi_device *dev,
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
static int dmm32at_ai_cmdtest(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_cmd *cmd)
{
int err = 0;
unsigned int arg;
err |= cfc_check_trigger_src(&cmd->start_src, TRIG_NOW);
err |= cfc_check_trigger_src(&cmd->scan_begin_src, TRIG_TIMER);
err |= cfc_check_trigger_src(&cmd->convert_src, TRIG_TIMER);
err |= cfc_check_trigger_src(&cmd->scan_end_src, TRIG_COUNT);
err |= cfc_check_trigger_src(&cmd->stop_src, TRIG_COUNT | TRIG_NONE);
if (err)
return 1;
err |= cfc_check_trigger_is_unique(cmd->stop_src);
if (err)
return 2;
err |= cfc_check_trigger_arg_is(&cmd->start_arg, 0);
err |= cfc_check_trigger_arg_min(&cmd->scan_begin_arg, 1000000);
err |= cfc_check_trigger_arg_max(&cmd->scan_begin_arg, 1000000000);
if (cmd->convert_arg >= 17500)
cmd->convert_arg = 20000;
else if (cmd->convert_arg >= 12500)
cmd->convert_arg = 15000;
else if (cmd->convert_arg >= 7500)
cmd->convert_arg = 10000;
else
cmd->convert_arg = 5000;
err |= cfc_check_trigger_arg_is(&cmd->scan_end_arg, cmd->chanlist_len);
if (cmd->stop_src == TRIG_COUNT)
err |= cfc_check_trigger_arg_min(&cmd->stop_arg, 1);
else
err |= cfc_check_trigger_arg_is(&cmd->stop_arg, 0);
if (err)
return 3;
arg = cmd->convert_arg * cmd->scan_end_arg;
err |= cfc_check_trigger_arg_min(&cmd->scan_begin_arg, arg);
if (err)
return 4;
if (cmd->chanlist && cmd->chanlist_len > 0)
err |= dmm32at_ai_check_chanlist(dev, s, cmd);
if (err)
return 5;
return 0;
}
static void dmm32at_setaitimer(struct comedi_device *dev, unsigned int nansec)
{
unsigned char lo1, lo2, hi2;
unsigned short both2;
lo1 = 200;
both2 = nansec / 20000;
hi2 = (both2 & 0xff00) >> 8;
lo2 = both2 & 0x00ff;
outb(0, dev->iobase + DMM32AT_CTRDIO_CFG_REG);
outb(DMM32AT_CTRL_PAGE_8254, dev->iobase + DMM32AT_CTRL_REG);
outb(DMM32AT_CLKCT1, dev->iobase + DMM32AT_CLKCT);
outb(lo1, dev->iobase + DMM32AT_CLK1);
outb(DMM32AT_CLKCT2, dev->iobase + DMM32AT_CLKCT);
outb(lo2, dev->iobase + DMM32AT_CLK2);
outb(hi2, dev->iobase + DMM32AT_CLK2);
outb(DMM32AT_INTCLK_ADINT |
DMM32AT_INTCLK_CLKEN | DMM32AT_INTCLK_CLKSEL,
dev->iobase + DMM32AT_INTCLK_REG);
}
static int dmm32at_ai_cmd(struct comedi_device *dev, struct comedi_subdevice *s)
{
struct comedi_cmd *cmd = &s->async->cmd;
int ret;
dmm32at_ai_set_chanspec(dev, s, cmd->chanlist[0], cmd->chanlist_len);
outb(DMM32AT_CTRL_INTRST, dev->iobase + DMM32AT_CTRL_REG);
ret = comedi_timeout(dev, s, NULL, dmm32at_ai_status,
DMM32AT_AI_READBACK_REG);
if (ret)
return ret;
if (cmd->stop_src == TRIG_NONE || cmd->stop_arg > 1) {
dmm32at_setaitimer(dev, cmd->scan_begin_arg);
} else {
outb(DMM32AT_INTCLK_ADINT, dev->iobase + DMM32AT_INTCLK_REG);
outb(0xff, dev->iobase + DMM32AT_AI_START_CONV_REG);
}
return 0;
}
static int dmm32at_ai_cancel(struct comedi_device *dev,
struct comedi_subdevice *s)
{
outb(0x0, dev->iobase + DMM32AT_INTCLK_REG);
return 0;
}
static irqreturn_t dmm32at_isr(int irq, void *d)
{
struct comedi_device *dev = d;
unsigned char intstat;
unsigned int val;
int i;
if (!dev->attached) {
dev_err(dev->class_dev, "spurious interrupt\n");
return IRQ_HANDLED;
}
intstat = inb(dev->iobase + DMM32AT_INTCLK_REG);
if (intstat & DMM32AT_INTCLK_ADINT) {
struct comedi_subdevice *s = dev->read_subdev;
struct comedi_cmd *cmd = &s->async->cmd;
for (i = 0; i < cmd->chanlist_len; i++) {
val = dmm32at_ai_get_sample(dev, s);
comedi_buf_write_samples(s, &val, 1);
}
if (cmd->stop_src == TRIG_COUNT &&
s->async->scans_done >= cmd->stop_arg)
s->async->events |= COMEDI_CB_EOA;
comedi_handle_events(dev, s);
}
outb(DMM32AT_CTRL_INTRST, dev->iobase + DMM32AT_CTRL_REG);
return IRQ_HANDLED;
}
static int dmm32at_ao_eoc(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned long context)
{
unsigned char status;
status = inb(dev->iobase + DMM32AT_AUX_DI_REG);
if ((status & DMM32AT_AUX_DI_DACBUSY) == 0)
return 0;
return -EBUSY;
}
static int dmm32at_ao_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned int chan = CR_CHAN(insn->chanspec);
int i;
for (i = 0; i < insn->n; i++) {
unsigned int val = data[i];
int ret;
outb(val & 0xff, dev->iobase + DMM32AT_AO_LSB_REG);
outb((val >> 8) | DMM32AT_AO_MSB_DACH(chan),
dev->iobase + DMM32AT_AO_MSB_REG);
ret = comedi_timeout(dev, s, insn, dmm32at_ao_eoc, 0);
if (ret)
return ret;
inb(dev->iobase + DMM32AT_AO_MSB_REG);
s->readback[chan] = val;
}
return insn->n;
}
static int dmm32at_8255_io(struct comedi_device *dev,
int dir, int port, int data, unsigned long regbase)
{
outb(DMM32AT_CTRL_PAGE_8255, dev->iobase + DMM32AT_CTRL_REG);
if (dir) {
outb(data, dev->iobase + regbase + port);
return 0;
}
return inb(dev->iobase + regbase + port);
}
static int dmm32at_reset(struct comedi_device *dev)
{
unsigned char aihi, ailo, fifostat, aistat, intstat, airback;
outb(DMM32AT_CTRL_RESETA, dev->iobase + DMM32AT_CTRL_REG);
udelay(1000);
outb(0x0, dev->iobase + DMM32AT_FIFO_CTRL_REG);
outb(0x0, dev->iobase + DMM32AT_INTCLK_REG);
outb(0x80, dev->iobase + DMM32AT_AI_LO_CHAN_REG);
outb(0xff, dev->iobase + DMM32AT_AI_HI_CHAN_REG);
outb(DMM32AT_RANGE_U10, dev->iobase + DMM32AT_AI_CFG_REG);
udelay(100);
ailo = inb(dev->iobase + DMM32AT_AI_LO_CHAN_REG);
aihi = inb(dev->iobase + DMM32AT_AI_HI_CHAN_REG);
fifostat = inb(dev->iobase + DMM32AT_FIFO_STATUS_REG);
aistat = inb(dev->iobase + DMM32AT_AI_STATUS_REG);
intstat = inb(dev->iobase + DMM32AT_INTCLK_REG);
airback = inb(dev->iobase + DMM32AT_AI_READBACK_REG);
if (ailo != 0x00 || aihi != 0x1f ||
fifostat != DMM32AT_FIFO_STATUS_EF ||
aistat != (DMM32AT_AI_STATUS_SD1 | DMM32AT_AI_STATUS_SD0) ||
intstat != 0x00 || airback != 0x0c)
return -EIO;
return 0;
}
static int dmm32at_attach(struct comedi_device *dev,
struct comedi_devconfig *it)
{
struct comedi_subdevice *s;
int ret;
ret = comedi_request_region(dev, it->options[0], 0x10);
if (ret)
return ret;
ret = dmm32at_reset(dev);
if (ret) {
dev_err(dev->class_dev, "board detection failed\n");
return ret;
}
if (it->options[1]) {
ret = request_irq(it->options[1], dmm32at_isr, 0,
dev->board_name, dev);
if (ret == 0)
dev->irq = it->options[1];
}
ret = comedi_alloc_subdevices(dev, 3);
if (ret)
return ret;
s = &dev->subdevices[0];
s->type = COMEDI_SUBD_AI;
s->subdev_flags = SDF_READABLE | SDF_GROUND | SDF_DIFF;
s->n_chan = 32;
s->maxdata = 0xffff;
s->range_table = &dmm32at_airanges;
s->insn_read = dmm32at_ai_insn_read;
if (dev->irq) {
dev->read_subdev = s;
s->subdev_flags |= SDF_CMD_READ;
s->len_chanlist = s->n_chan;
s->do_cmd = dmm32at_ai_cmd;
s->do_cmdtest = dmm32at_ai_cmdtest;
s->cancel = dmm32at_ai_cancel;
}
s = &dev->subdevices[1];
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = 4;
s->maxdata = 0x0fff;
s->range_table = &dmm32at_aoranges;
s->insn_write = dmm32at_ao_insn_write;
ret = comedi_alloc_subdev_readback(s);
if (ret)
return ret;
s = &dev->subdevices[2];
ret = subdev_8255_init(dev, s, dmm32at_8255_io, DMM32AT_8255_IOBASE);
if (ret)
return ret;
return 0;
}
