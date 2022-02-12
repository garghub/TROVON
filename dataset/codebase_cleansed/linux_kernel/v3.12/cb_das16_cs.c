static irqreturn_t das16cs_interrupt(int irq, void *d)
{
return IRQ_HANDLED;
}
static int das16cs_ai_rinsn(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct das16cs_private *devpriv = dev->private;
int chan = CR_CHAN(insn->chanspec);
int range = CR_RANGE(insn->chanspec);
int aref = CR_AREF(insn->chanspec);
int i;
int to;
outw(chan, dev->iobase + DAS16CS_DIO_MUX);
devpriv->status1 &= ~0xf320;
devpriv->status1 |= (aref == AREF_DIFF) ? 0 : 0x0020;
outw(devpriv->status1, dev->iobase + DAS16CS_MISC1);
devpriv->status2 &= ~0xff00;
switch (range) {
case 0:
devpriv->status2 |= 0x800;
break;
case 1:
devpriv->status2 |= 0x000;
break;
case 2:
devpriv->status2 |= 0x100;
break;
case 3:
devpriv->status2 |= 0x200;
break;
}
outw(devpriv->status2, dev->iobase + DAS16CS_MISC2);
for (i = 0; i < insn->n; i++) {
outw(0, dev->iobase + DAS16CS_ADC_DATA);
#define TIMEOUT 1000
for (to = 0; to < TIMEOUT; to++) {
if (inw(dev->iobase + DAS16CS_MISC1) & 0x0080)
break;
}
if (to == TIMEOUT) {
dev_dbg(dev->class_dev, "cb_das16_cs: ai timeout\n");
return -ETIME;
}
data[i] = inw(dev->iobase + DAS16CS_ADC_DATA);
}
return i;
}
static int das16cs_ai_cmd(struct comedi_device *dev, struct comedi_subdevice *s)
{
return -EINVAL;
}
static int das16cs_ai_cmdtest(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_cmd *cmd)
{
int err = 0;
int tmp;
err |= cfc_check_trigger_src(&cmd->start_src, TRIG_NOW);
err |= cfc_check_trigger_src(&cmd->scan_begin_src,
TRIG_TIMER | TRIG_EXT);
err |= cfc_check_trigger_src(&cmd->convert_src,
TRIG_TIMER | TRIG_EXT);
err |= cfc_check_trigger_src(&cmd->scan_end_src, TRIG_COUNT);
err |= cfc_check_trigger_src(&cmd->stop_src, TRIG_COUNT | TRIG_NONE);
if (err)
return 1;
err |= cfc_check_trigger_is_unique(cmd->scan_begin_src);
err |= cfc_check_trigger_is_unique(cmd->convert_src);
err |= cfc_check_trigger_is_unique(cmd->stop_src);
if (err)
return 2;
err |= cfc_check_trigger_arg_is(&cmd->start_arg, 0);
#define MAX_SPEED 10000
#define MIN_SPEED 1000000000
if (cmd->scan_begin_src == TRIG_TIMER) {
err |= cfc_check_trigger_arg_min(&cmd->scan_begin_arg,
MAX_SPEED);
err |= cfc_check_trigger_arg_max(&cmd->scan_begin_arg,
MIN_SPEED);
} else {
err |= cfc_check_trigger_arg_max(&cmd->scan_begin_arg, 9);
}
if (cmd->convert_src == TRIG_TIMER) {
err |= cfc_check_trigger_arg_min(&cmd->convert_arg,
MAX_SPEED);
err |= cfc_check_trigger_arg_max(&cmd->convert_arg,
MIN_SPEED);
} else {
err |= cfc_check_trigger_arg_max(&cmd->convert_arg, 9);
}
err |= cfc_check_trigger_arg_is(&cmd->scan_end_arg, cmd->chanlist_len);
if (cmd->stop_src == TRIG_COUNT)
err |= cfc_check_trigger_arg_max(&cmd->stop_arg, 0x00ffffff);
else
err |= cfc_check_trigger_arg_is(&cmd->stop_arg, 0);
if (err)
return 3;
if (cmd->scan_begin_src == TRIG_TIMER) {
unsigned int div1 = 0, div2 = 0;
tmp = cmd->scan_begin_arg;
i8253_cascade_ns_to_timer(100, &div1, &div2,
&cmd->scan_begin_arg,
cmd->flags & TRIG_ROUND_MASK);
if (tmp != cmd->scan_begin_arg)
err++;
}
if (cmd->convert_src == TRIG_TIMER) {
unsigned int div1 = 0, div2 = 0;
tmp = cmd->convert_arg;
i8253_cascade_ns_to_timer(100, &div1, &div2,
&cmd->scan_begin_arg,
cmd->flags & TRIG_ROUND_MASK);
if (tmp != cmd->convert_arg)
err++;
if (cmd->scan_begin_src == TRIG_TIMER &&
cmd->scan_begin_arg <
cmd->convert_arg * cmd->scan_end_arg) {
cmd->scan_begin_arg =
cmd->convert_arg * cmd->scan_end_arg;
err++;
}
}
if (err)
return 4;
return 0;
}
static int das16cs_ao_winsn(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct das16cs_private *devpriv = dev->private;
int i;
int chan = CR_CHAN(insn->chanspec);
unsigned short status1;
unsigned short d;
int bit;
for (i = 0; i < insn->n; i++) {
devpriv->ao_readback[chan] = data[i];
d = data[i];
outw(devpriv->status1, dev->iobase + DAS16CS_MISC1);
udelay(1);
status1 = devpriv->status1 & ~0xf;
if (chan)
status1 |= 0x0001;
else
status1 |= 0x0008;
outw(status1, dev->iobase + DAS16CS_MISC1);
udelay(1);
for (bit = 15; bit >= 0; bit--) {
int b = (d >> bit) & 0x1;
b <<= 1;
outw(status1 | b | 0x0000, dev->iobase + DAS16CS_MISC1);
udelay(1);
outw(status1 | b | 0x0004, dev->iobase + DAS16CS_MISC1);
udelay(1);
}
outw(status1 | 0x9, dev->iobase + DAS16CS_MISC1);
}
return i;
}
static int das16cs_ao_rinsn(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct das16cs_private *devpriv = dev->private;
int i;
int chan = CR_CHAN(insn->chanspec);
for (i = 0; i < insn->n; i++)
data[i] = devpriv->ao_readback[chan];
return i;
}
static int das16cs_dio_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
if (data[0]) {
s->state &= ~data[0];
s->state |= data[0] & data[1];
outw(s->state, dev->iobase + DAS16CS_DIO);
}
data[1] = inw(dev->iobase + DAS16CS_DIO);
return insn->n;
}
static int das16cs_dio_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct das16cs_private *devpriv = dev->private;
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned int mask;
int ret;
if (chan < 4)
mask = 0x0f;
else
mask = 0xf0;
ret = comedi_dio_insn_config(dev, s, insn, data, mask);
if (ret)
return ret;
devpriv->status2 &= ~0x00c0;
devpriv->status2 |= (s->io_bits & 0xf0) ? 0x0080 : 0;
devpriv->status2 |= (s->io_bits & 0x0f) ? 0x0040 : 0;
outw(devpriv->status2, dev->iobase + DAS16CS_MISC2);
return insn->n;
}
static const void *das16cs_find_boardinfo(struct comedi_device *dev,
struct pcmcia_device *link)
{
const struct das16cs_board *board;
int i;
for (i = 0; i < ARRAY_SIZE(das16cs_boards); i++) {
board = &das16cs_boards[i];
if (board->device_id == link->card_id)
return board;
}
return NULL;
}
static int das16cs_auto_attach(struct comedi_device *dev,
unsigned long context)
{
struct pcmcia_device *link = comedi_to_pcmcia_dev(dev);
const struct das16cs_board *board;
struct das16cs_private *devpriv;
struct comedi_subdevice *s;
int ret;
board = das16cs_find_boardinfo(dev, link);
if (!board)
return -ENODEV;
dev->board_ptr = board;
dev->board_name = board->name;
link->config_flags |= CONF_AUTO_SET_IO | CONF_ENABLE_IRQ;
ret = comedi_pcmcia_enable(dev, NULL);
if (ret)
return ret;
dev->iobase = link->resource[0]->start;
link->priv = dev;
ret = pcmcia_request_irq(link, das16cs_interrupt);
if (ret)
return ret;
dev->irq = link->irq;
devpriv = comedi_alloc_devpriv(dev, sizeof(*devpriv));
if (!devpriv)
return -ENOMEM;
ret = comedi_alloc_subdevices(dev, 3);
if (ret)
return ret;
s = &dev->subdevices[0];
dev->read_subdev = s;
s->type = COMEDI_SUBD_AI;
s->subdev_flags = SDF_READABLE | SDF_GROUND | SDF_DIFF | SDF_CMD_READ;
s->n_chan = 16;
s->maxdata = 0xffff;
s->range_table = &das16cs_ai_range;
s->len_chanlist = 16;
s->insn_read = das16cs_ai_rinsn;
s->do_cmd = das16cs_ai_cmd;
s->do_cmdtest = das16cs_ai_cmdtest;
s = &dev->subdevices[1];
if (board->n_ao_chans) {
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = board->n_ao_chans;
s->maxdata = 0xffff;
s->range_table = &range_bipolar10;
s->insn_write = &das16cs_ao_winsn;
s->insn_read = &das16cs_ao_rinsn;
} else {
s->type = COMEDI_SUBD_UNUSED;
}
s = &dev->subdevices[2];
s->type = COMEDI_SUBD_DIO;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE;
s->n_chan = 8;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = das16cs_dio_insn_bits;
s->insn_config = das16cs_dio_insn_config;
dev_info(dev->class_dev, "%s: %s, I/O base=0x%04lx, irq=%u\n",
dev->driver->driver_name, dev->board_name,
dev->iobase, dev->irq);
return 0;
}
static int das16cs_pcmcia_attach(struct pcmcia_device *link)
{
return comedi_pcmcia_auto_config(link, &driver_das16cs);
}
