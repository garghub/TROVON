static int das16cs_ai_eoc(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned long context)
{
unsigned int status;
status = inw(dev->iobase + DAS16CS_MISC1_REG);
if (status & DAS16CS_MISC1_EOC)
return 0;
return -EBUSY;
}
static int das16cs_ai_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct das16cs_private *devpriv = dev->private;
int chan = CR_CHAN(insn->chanspec);
int range = CR_RANGE(insn->chanspec);
int aref = CR_AREF(insn->chanspec);
int ret;
int i;
outw(DAS16CS_AI_MUX_SINGLE_CHAN(chan),
dev->iobase + DAS16CS_AI_MUX_REG);
devpriv->misc1 &= ~(DAS16CS_MISC1_INTE | DAS16CS_MISC1_INT_SRC_MASK |
DAS16CS_MISC1_AI_CONV_MASK);
if (aref == AREF_DIFF)
devpriv->misc1 &= ~DAS16CS_MISC1_SEDIFF;
else
devpriv->misc1 |= DAS16CS_MISC1_SEDIFF;
outw(devpriv->misc1, dev->iobase + DAS16CS_MISC1_REG);
devpriv->misc2 &= ~(DAS16CS_MISC2_BME | DAS16CS_MISC2_AI_GAIN_MASK);
switch (range) {
case 0:
devpriv->misc2 |= DAS16CS_MISC2_AI_GAIN_1;
break;
case 1:
devpriv->misc2 |= DAS16CS_MISC2_AI_GAIN_2;
break;
case 2:
devpriv->misc2 |= DAS16CS_MISC2_AI_GAIN_4;
break;
case 3:
devpriv->misc2 |= DAS16CS_MISC2_AI_GAIN_8;
break;
}
outw(devpriv->misc2, dev->iobase + DAS16CS_MISC2_REG);
for (i = 0; i < insn->n; i++) {
outw(0, dev->iobase + DAS16CS_AI_DATA_REG);
ret = comedi_timeout(dev, s, insn, das16cs_ai_eoc, 0);
if (ret)
return ret;
data[i] = inw(dev->iobase + DAS16CS_AI_DATA_REG);
}
return i;
}
static int das16cs_ao_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct das16cs_private *devpriv = dev->private;
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned int val = s->readback[chan];
unsigned short misc1;
int bit;
int i;
for (i = 0; i < insn->n; i++) {
val = data[i];
outw(devpriv->misc1, dev->iobase + DAS16CS_MISC1_REG);
udelay(1);
misc1 = devpriv->misc1 & ~DAS16CS_MISC1_DAC_MASK;
if (chan)
misc1 |= DAS16CS_MISC1_DAC0CS;
else
misc1 |= DAS16CS_MISC1_DAC1CS;
outw(misc1, dev->iobase + DAS16CS_MISC1_REG);
udelay(1);
for (bit = 15; bit >= 0; bit--) {
if ((val >> bit) & 0x1)
misc1 |= DAS16CS_MISC1_DACSD;
else
misc1 &= ~DAS16CS_MISC1_DACSD;
outw(misc1, dev->iobase + DAS16CS_MISC1_REG);
udelay(1);
outw(misc1 | DAS16CS_MISC1_DACCLK,
dev->iobase + DAS16CS_MISC1_REG);
udelay(1);
}
outw(misc1 | DAS16CS_MISC1_DAC0CS | DAS16CS_MISC1_DAC1CS,
dev->iobase + DAS16CS_MISC1_REG);
}
s->readback[chan] = val;
return insn->n;
}
static int das16cs_dio_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
if (comedi_dio_update_state(s, data))
outw(s->state, dev->iobase + DAS16CS_DIO_REG);
data[1] = inw(dev->iobase + DAS16CS_DIO_REG);
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
if (s->io_bits & 0xf0)
devpriv->misc2 |= DAS16CS_MISC2_UDIR;
else
devpriv->misc2 &= ~DAS16CS_MISC2_UDIR;
if (s->io_bits & 0x0f)
devpriv->misc2 |= DAS16CS_MISC2_LDIR;
else
devpriv->misc2 &= ~DAS16CS_MISC2_LDIR;
outw(devpriv->misc2, dev->iobase + DAS16CS_MISC2_REG);
return insn->n;
}
static int das16cs_counter_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct das16cs_private *devpriv = dev->private;
switch (data[0]) {
case INSN_CONFIG_SET_CLOCK_SRC:
switch (data[1]) {
case 0:
devpriv->misc2 |= DAS16CS_MISC2_CTR1;
break;
case 1:
devpriv->misc2 &= ~DAS16CS_MISC2_CTR1;
break;
default:
return -EINVAL;
}
outw(devpriv->misc2, dev->iobase + DAS16CS_MISC2_REG);
break;
case INSN_CONFIG_GET_CLOCK_SRC:
if (devpriv->misc2 & DAS16CS_MISC2_CTR1) {
data[1] = 0;
data[2] = I8254_OSC_BASE_100KHZ;
} else {
data[1] = 1;
data[2] = 0;
}
break;
default:
return -EINVAL;
}
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
devpriv = comedi_alloc_devpriv(dev, sizeof(*devpriv));
if (!devpriv)
return -ENOMEM;
dev->pacer = comedi_8254_init(dev->iobase + DAS16CS_TIMER_BASE,
I8254_OSC_BASE_10MHZ, I8254_IO16, 0);
if (!dev->pacer)
return -ENOMEM;
ret = comedi_alloc_subdevices(dev, 4);
if (ret)
return ret;
s = &dev->subdevices[0];
s->type = COMEDI_SUBD_AI;
s->subdev_flags = SDF_READABLE | SDF_GROUND | SDF_DIFF;
s->n_chan = 16;
s->maxdata = 0xffff;
s->range_table = &das16cs_ai_range;
s->insn_read = das16cs_ai_insn_read;
s = &dev->subdevices[1];
if (board->has_ao) {
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = 2;
s->maxdata = 0xffff;
s->range_table = &range_bipolar10;
s->insn_write = &das16cs_ao_insn_write;
ret = comedi_alloc_subdev_readback(s);
if (ret)
return ret;
} else {
s->type = COMEDI_SUBD_UNUSED;
}
s = &dev->subdevices[2];
s->type = COMEDI_SUBD_DIO;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE;
s->n_chan = board->has_4dio ? 4 : 8;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = das16cs_dio_insn_bits;
s->insn_config = das16cs_dio_insn_config;
s = &dev->subdevices[3];
comedi_8254_subdevice_init(s, dev->pacer);
dev->pacer->insn_config = das16cs_counter_insn_config;
comedi_8254_set_busy(dev->pacer, 1, true);
comedi_8254_set_busy(dev->pacer, 2, true);
return 0;
}
static int das16cs_pcmcia_attach(struct pcmcia_device *link)
{
return comedi_pcmcia_auto_config(link, &driver_das16cs);
}
