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
tmp = cmd->start_src;
cmd->start_src &= TRIG_NOW;
if (!cmd->start_src || tmp != cmd->start_src)
err++;
tmp = cmd->scan_begin_src;
cmd->scan_begin_src &= TRIG_TIMER | TRIG_EXT;
if (!cmd->scan_begin_src || tmp != cmd->scan_begin_src)
err++;
tmp = cmd->convert_src;
cmd->convert_src &= TRIG_TIMER | TRIG_EXT;
if (!cmd->convert_src || tmp != cmd->convert_src)
err++;
tmp = cmd->scan_end_src;
cmd->scan_end_src &= TRIG_COUNT;
if (!cmd->scan_end_src || tmp != cmd->scan_end_src)
err++;
tmp = cmd->stop_src;
cmd->stop_src &= TRIG_COUNT | TRIG_NONE;
if (!cmd->stop_src || tmp != cmd->stop_src)
err++;
if (err)
return 1;
if (cmd->scan_begin_src != TRIG_TIMER &&
cmd->scan_begin_src != TRIG_EXT)
err++;
if (cmd->convert_src != TRIG_TIMER && cmd->convert_src != TRIG_EXT)
err++;
if (cmd->stop_src != TRIG_COUNT && cmd->stop_src != TRIG_NONE)
err++;
if (err)
return 2;
if (cmd->start_arg != 0) {
cmd->start_arg = 0;
err++;
}
#define MAX_SPEED 10000
#define MIN_SPEED 1000000000
if (cmd->scan_begin_src == TRIG_TIMER) {
if (cmd->scan_begin_arg < MAX_SPEED) {
cmd->scan_begin_arg = MAX_SPEED;
err++;
}
if (cmd->scan_begin_arg > MIN_SPEED) {
cmd->scan_begin_arg = MIN_SPEED;
err++;
}
} else {
if (cmd->scan_begin_arg > 9) {
cmd->scan_begin_arg = 9;
err++;
}
}
if (cmd->convert_src == TRIG_TIMER) {
if (cmd->convert_arg < MAX_SPEED) {
cmd->convert_arg = MAX_SPEED;
err++;
}
if (cmd->convert_arg > MIN_SPEED) {
cmd->convert_arg = MIN_SPEED;
err++;
}
} else {
if (cmd->convert_arg > 9) {
cmd->convert_arg = 9;
err++;
}
}
if (cmd->scan_end_arg != cmd->chanlist_len) {
cmd->scan_end_arg = cmd->chanlist_len;
err++;
}
if (cmd->stop_src == TRIG_COUNT) {
if (cmd->stop_arg > 0x00ffffff) {
cmd->stop_arg = 0x00ffffff;
err++;
}
} else {
if (cmd->stop_arg != 0) {
cmd->stop_arg = 0;
err++;
}
}
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
struct comedi_insn *insn, unsigned int *data)
{
struct das16cs_private *devpriv = dev->private;
int chan = CR_CHAN(insn->chanspec);
int bits;
if (chan < 4)
bits = 0x0f;
else
bits = 0xf0;
switch (data[0]) {
case INSN_CONFIG_DIO_OUTPUT:
s->io_bits |= bits;
break;
case INSN_CONFIG_DIO_INPUT:
s->io_bits &= bits;
break;
case INSN_CONFIG_DIO_QUERY:
data[1] =
(s->io_bits & (1 << chan)) ? COMEDI_OUTPUT : COMEDI_INPUT;
return insn->n;
break;
default:
return -EINVAL;
break;
}
devpriv->status2 &= ~0x00c0;
devpriv->status2 |= (s->io_bits & 0xf0) ? 0x0080 : 0;
devpriv->status2 |= (s->io_bits & 0x0f) ? 0x0040 : 0;
outw(devpriv->status2, dev->iobase + DAS16CS_MISC2);
return insn->n;
}
static const struct das16cs_board *das16cs_probe(struct comedi_device *dev,
struct pcmcia_device *link)
{
int i;
for (i = 0; i < ARRAY_SIZE(das16cs_boards); i++) {
if (das16cs_boards[i].device_id == link->card_id)
return das16cs_boards + i;
}
dev_dbg(dev->class_dev, "unknown board!\n");
return NULL;
}
static int das16cs_attach(struct comedi_device *dev,
struct comedi_devconfig *it)
{
const struct das16cs_board *thisboard;
struct pcmcia_device *link;
struct comedi_subdevice *s;
int ret;
link = cur_dev;
if (!link)
return -EIO;
dev->board_ptr = das16cs_probe(dev, link);
if (!dev->board_ptr)
return -EIO;
thisboard = comedi_board(dev);
dev->board_name = thisboard->name;
dev->iobase = link->resource[0]->start;
ret = request_irq(link->irq, das16cs_interrupt,
IRQF_SHARED, "cb_das16_cs", dev);
if (ret < 0)
return ret;
dev->irq = link->irq;
if (alloc_private(dev, sizeof(struct das16cs_private)) < 0)
return -ENOMEM;
ret = comedi_alloc_subdevices(dev, 3);
if (ret)
return ret;
s = dev->subdevices + 0;
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
s = dev->subdevices + 1;
if (thisboard->n_ao_chans) {
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = thisboard->n_ao_chans;
s->maxdata = 0xffff;
s->range_table = &range_bipolar10;
s->insn_write = &das16cs_ao_winsn;
s->insn_read = &das16cs_ao_rinsn;
} else {
s->type = COMEDI_SUBD_UNUSED;
}
s = dev->subdevices + 2;
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
static void das16cs_detach(struct comedi_device *dev)
{
if (dev->irq)
free_irq(dev->irq, dev);
}
static int das16cs_pcmcia_config_loop(struct pcmcia_device *p_dev,
void *priv_data)
{
if (p_dev->config_index == 0)
return -EINVAL;
return pcmcia_request_io(p_dev);
}
static int das16cs_pcmcia_attach(struct pcmcia_device *link)
{
int ret;
link->config_flags |= CONF_ENABLE_IRQ | CONF_AUTO_SET_IO;
ret = pcmcia_loop_config(link, das16cs_pcmcia_config_loop, NULL);
if (ret)
goto failed;
if (!link->irq)
goto failed;
ret = pcmcia_enable_device(link);
if (ret)
goto failed;
cur_dev = link;
return 0;
failed:
pcmcia_disable_device(link);
return ret;
}
static void das16cs_pcmcia_detach(struct pcmcia_device *link)
{
pcmcia_disable_device(link);
cur_dev = NULL;
}
static int __init das16cs_init(void)
{
int ret;
ret = comedi_driver_register(&driver_das16cs);
if (ret < 0)
return ret;
ret = pcmcia_register_driver(&das16cs_driver);
if (ret < 0) {
comedi_driver_unregister(&driver_das16cs);
return ret;
}
return 0;
}
static void __exit das16cs_exit(void)
{
pcmcia_unregister_driver(&das16cs_driver);
comedi_driver_unregister(&driver_das16cs);
}
