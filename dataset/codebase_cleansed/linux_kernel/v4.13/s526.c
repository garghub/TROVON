static void s526_gpct_write(struct comedi_device *dev,
unsigned int chan, unsigned int val)
{
outw((val >> 16) & 0xffff, dev->iobase + S526_GPCT_MSB_REG(chan));
outw(val & 0xffff, dev->iobase + S526_GPCT_LSB_REG(chan));
}
static unsigned int s526_gpct_read(struct comedi_device *dev,
unsigned int chan)
{
unsigned int val;
val = inw(dev->iobase + S526_GPCT_LSB_REG(chan)) & 0xffff;
val |= (inw(dev->iobase + S526_GPCT_MSB_REG(chan)) & 0xff) << 16;
return val;
}
static int s526_gpct_rinsn(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned int chan = CR_CHAN(insn->chanspec);
int i;
for (i = 0; i < insn->n; i++)
data[i] = s526_gpct_read(dev, chan);
return insn->n;
}
static int s526_gpct_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct s526_private *devpriv = dev->private;
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned int val;
switch (data[0]) {
case INSN_CONFIG_GPCT_QUADRATURE_ENCODER:
devpriv->gpct_config[chan] = data[0];
#if 1
val = data[1] & 0xffff;
outw(val, dev->iobase + S526_GPCT_MODE_REG(chan));
if ((val & S526_GPCT_MODE_AUTOLOAD_MASK) ==
S526_GPCT_MODE_AUTOLOAD_NONE) {
outw(S526_GPCT_CTRL_CT_RESET,
dev->iobase + S526_GPCT_CTRL_REG(chan));
}
#else
val = S526_GPCT_MODE_CTDIR_CTRL_QUAD;
if (data[1] == GPCT_X2)
val |= S526_GPCT_MODE_CLK_SRC_QUADX2;
else if (data[1] == GPCT_X4)
val |= S526_GPCT_MODE_CLK_SRC_QUADX4;
else
val |= S526_GPCT_MODE_CLK_SRC_QUADX1;
if (data[3] == GPCT_RESET_COUNTER_ON_INDEX) {
val |= S526_GPCT_MODE_AUTOLOAD_IXRISE;
}
val = data[1] & 0xffff;
outw(val, dev->iobase + S526_GPCT_MODE_REG(chan));
s526_gpct_write(dev, chan, data[2]);
if (data[3])
outw(data[3] & 0xffff,
dev->iobase + S526_GPCT_CTRL_REG(chan));
if ((val & S526_GPCT_MODE_AUTOLOAD_MASK) ==
S526_GPCT_MODE_AUTOLOAD_NONE) {
outw(S526_GPCT_CTRL_CT_RESET,
dev->iobase + S526_GPCT_CTRL_REG(chan));
outw(S526_GPCT_CTRL_CT_LOAD,
dev->iobase + S526_GPCT_CTRL_REG(chan));
}
#endif
break;
case INSN_CONFIG_GPCT_SINGLE_PULSE_GENERATOR:
devpriv->gpct_config[chan] = data[0];
val = data[1] & 0xffff;
val &= ~S526_GPCT_MODE_PR_SELECT_MASK;
val |= S526_GPCT_MODE_PR_SELECT_PR0;
outw(val, dev->iobase + S526_GPCT_MODE_REG(chan));
s526_gpct_write(dev, chan, data[2]);
val = data[1] & 0xffff;
val &= ~S526_GPCT_MODE_PR_SELECT_MASK;
val |= S526_GPCT_MODE_PR_SELECT_PR1;
outw(val, dev->iobase + S526_GPCT_MODE_REG(chan));
s526_gpct_write(dev, chan, data[3]);
if (data[4]) {
val = data[4] & 0xffff;
outw(val, dev->iobase + S526_GPCT_CTRL_REG(chan));
}
break;
case INSN_CONFIG_GPCT_PULSE_TRAIN_GENERATOR:
devpriv->gpct_config[chan] = data[0];
val = data[1] & 0xffff;
val &= ~S526_GPCT_MODE_PR_SELECT_MASK;
val |= S526_GPCT_MODE_PR_SELECT_PR0;
outw(val, dev->iobase + S526_GPCT_MODE_REG(chan));
s526_gpct_write(dev, chan, data[2]);
val = data[1] & 0xffff;
val &= ~S526_GPCT_MODE_PR_SELECT_MASK;
val |= S526_GPCT_MODE_PR_SELECT_PR1;
outw(val, dev->iobase + S526_GPCT_MODE_REG(chan));
s526_gpct_write(dev, chan, data[3]);
if (data[4]) {
val = data[4] & 0xffff;
outw(val, dev->iobase + S526_GPCT_CTRL_REG(chan));
}
break;
default:
return -EINVAL;
}
return insn->n;
}
static int s526_gpct_winsn(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct s526_private *devpriv = dev->private;
unsigned int chan = CR_CHAN(insn->chanspec);
inw(dev->iobase + S526_GPCT_MODE_REG(chan));
switch (devpriv->gpct_config[chan]) {
case INSN_CONFIG_GPCT_PULSE_TRAIN_GENERATOR:
if ((data[1] <= data[0]) || !data[0])
return -EINVAL;
case INSN_CONFIG_GPCT_QUADRATURE_ENCODER:
case INSN_CONFIG_GPCT_SINGLE_PULSE_GENERATOR:
s526_gpct_write(dev, chan, data[0]);
break;
default:
return -EINVAL;
}
return insn->n;
}
static int s526_eoc(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned long context)
{
unsigned int status;
status = inw(dev->iobase + S526_INT_STATUS_REG);
if (status & context) {
outw(context, dev->iobase + S526_INT_STATUS_REG);
return 0;
}
return -EBUSY;
}
static int s526_ai_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct s526_private *devpriv = dev->private;
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned int ctrl;
unsigned int val;
int ret;
int i;
ctrl = S526_AI_CTRL_CONV(chan) | S526_AI_CTRL_READ(chan) |
S526_AI_CTRL_START;
if (ctrl != devpriv->ai_ctrl) {
devpriv->ai_ctrl = ctrl;
ctrl |= S526_AI_CTRL_DELAY;
}
for (i = 0; i < insn->n; i++) {
outw(ctrl, dev->iobase + S526_AI_CTRL_REG);
ctrl &= ~S526_AI_CTRL_DELAY;
ret = comedi_timeout(dev, s, insn, s526_eoc, S526_INT_AI);
if (ret)
return ret;
val = inw(dev->iobase + S526_AI_REG);
data[i] = comedi_offset_munge(s, val);
}
return insn->n;
}
static int s526_ao_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned int ctrl = S526_AO_CTRL_CHAN(chan);
unsigned int val = s->readback[chan];
int ret;
int i;
outw(ctrl, dev->iobase + S526_AO_CTRL_REG);
ctrl |= S526_AO_CTRL_START;
for (i = 0; i < insn->n; i++) {
val = data[i];
outw(val, dev->iobase + S526_AO_REG);
outw(ctrl, dev->iobase + S526_AO_CTRL_REG);
ret = comedi_timeout(dev, s, insn, s526_eoc, S526_INT_AO);
if (ret)
return ret;
}
s->readback[chan] = val;
return insn->n;
}
static int s526_dio_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
if (comedi_dio_update_state(s, data))
outw(s->state, dev->iobase + S526_DIO_CTRL_REG);
data[1] = inw(dev->iobase + S526_DIO_CTRL_REG) & 0xff;
return insn->n;
}
static int s526_dio_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
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
if (s->io_bits & 0x0f)
s->state |= S526_DIO_CTRL_GRP1_OUT;
else
s->state &= ~S526_DIO_CTRL_GRP1_OUT;
if (s->io_bits & 0xf0)
s->state |= S526_DIO_CTRL_GRP2_OUT;
else
s->state &= ~S526_DIO_CTRL_GRP2_OUT;
outw(s->state, dev->iobase + S526_DIO_CTRL_REG);
return insn->n;
}
static int s526_attach(struct comedi_device *dev, struct comedi_devconfig *it)
{
struct s526_private *devpriv;
struct comedi_subdevice *s;
int ret;
ret = comedi_request_region(dev, it->options[0], 0x40);
if (ret)
return ret;
devpriv = comedi_alloc_devpriv(dev, sizeof(*devpriv));
if (!devpriv)
return -ENOMEM;
ret = comedi_alloc_subdevices(dev, 4);
if (ret)
return ret;
s = &dev->subdevices[0];
s->type = COMEDI_SUBD_COUNTER;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE | SDF_LSAMPL;
s->n_chan = 4;
s->maxdata = 0x00ffffff;
s->insn_read = s526_gpct_rinsn;
s->insn_config = s526_gpct_insn_config;
s->insn_write = s526_gpct_winsn;
s = &dev->subdevices[1];
s->type = COMEDI_SUBD_AI;
s->subdev_flags = SDF_READABLE | SDF_DIFF;
s->n_chan = 10;
s->maxdata = 0xffff;
s->range_table = &range_bipolar10;
s->len_chanlist = 16;
s->insn_read = s526_ai_insn_read;
s = &dev->subdevices[2];
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = 4;
s->maxdata = 0xffff;
s->range_table = &range_bipolar10;
s->insn_write = s526_ao_insn_write;
ret = comedi_alloc_subdev_readback(s);
if (ret)
return ret;
s = &dev->subdevices[3];
s->type = COMEDI_SUBD_DIO;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE;
s->n_chan = 8;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = s526_dio_insn_bits;
s->insn_config = s526_dio_insn_config;
return 0;
}
