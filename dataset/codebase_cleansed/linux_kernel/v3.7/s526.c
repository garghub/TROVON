static int s526_gpct_rinsn(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned long chan_iobase = dev->iobase + chan * 8;
unsigned int lo;
unsigned int hi;
int i;
for (i = 0; i < insn->n; i++) {
lo = inw(chan_iobase + REG_C0L) & 0xffff;
hi = inw(chan_iobase + REG_C0H) & 0xff;
data[i] = (hi << 16) | lo;
}
return insn->n;
}
static int s526_gpct_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct s526_private *devpriv = dev->private;
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned long chan_iobase = dev->iobase + chan * 8;
unsigned int val;
union cmReg cmReg;
switch (data[0]) {
case INSN_CONFIG_GPCT_QUADRATURE_ENCODER:
devpriv->gpct_config[chan] = data[0];
#if 0
cmReg.reg.coutSource = 0;
cmReg.reg.coutPolarity = 1;
cmReg.reg.autoLoadResetRcap = 0;
cmReg.reg.hwCtEnableSource = 3;
cmReg.reg.ctEnableCtrl = 2;
cmReg.reg.clockSource = 2;
cmReg.reg.countDir = 1;
cmReg.reg.countDirCtrl = 1;
cmReg.reg.outputRegLatchCtrl = 0;
cmReg.reg.preloadRegSel = 0;
cmReg.reg.reserved = 0;
outw(cmReg.value, chan_iobase + REG_C0M);
outw(0x0001, chan_iobase + REG_C0H);
outw(0x3C68, chan_iobase + REG_C0L);
outw(0x8000, chan_iobase + REG_C0C);
outw(0x4000, chan_iobase + REG_C0C);
outw(0x0008, chan_iobase + REG_C0C);
#endif
#if 1
cmReg.value = data[1] & 0xffff;
outw(cmReg.value, chan_iobase + REG_C0M);
if (cmReg.reg.autoLoadResetRcap == 0) {
outw(0x8000, chan_iobase + REG_C0C);
}
#else
cmReg.reg.countDirCtrl = 0;
if (data[1] == GPCT_X2)
cmReg.reg.clockSource = 1;
else if (data[1] == GPCT_X4)
cmReg.reg.clockSource = 2;
else
cmReg.reg.clockSource = 0;
if (data[3] == GPCT_RESET_COUNTER_ON_INDEX)
cmReg.reg.autoLoadResetRcap = 4;
cmReg.value = data[1] & 0xffff;
outw(cmReg.value, chan_iobase + REG_C0M);
val = (data[2] >> 16) & 0xffff;
outw(val, chan_iobase + REG_C0H);
val = data[2] & 0xffff;
outw(val, chan_iobase + REG_C0L);
if (data[3]) {
val = data[3] & 0xffff;
outw(val, chan_iobase + REG_C0C);
}
if (cmReg.reg.autoLoadResetRcap == 0) {
outw(0x8000, chan_iobase + REG_C0C);
outw(0x4000, chan_iobase + REG_C0C);
}
#endif
break;
case INSN_CONFIG_GPCT_SINGLE_PULSE_GENERATOR:
devpriv->gpct_config[chan] = data[0];
cmReg.value = data[1] & 0xffff;
cmReg.reg.preloadRegSel = 0;
outw(cmReg.value, chan_iobase + REG_C0M);
val = (data[2] >> 16) & 0xffff;
outw(val, chan_iobase + REG_C0H);
val = data[2] & 0xffff;
outw(val, chan_iobase + REG_C0L);
cmReg.value = data[1] & 0xffff;
cmReg.reg.preloadRegSel = 1;
outw(cmReg.value, chan_iobase + REG_C0M);
val = (data[3] >> 16) & 0xffff;
outw(val, chan_iobase + REG_C0H);
val = data[3] & 0xffff;
outw(val, chan_iobase + REG_C0L);
if (data[4]) {
val = data[4] & 0xffff;
outw(val, chan_iobase + REG_C0C);
}
break;
case INSN_CONFIG_GPCT_PULSE_TRAIN_GENERATOR:
devpriv->gpct_config[chan] = data[0];
cmReg.value = data[1] & 0xffff;
cmReg.reg.preloadRegSel = 0;
outw(cmReg.value, chan_iobase + REG_C0M);
val = (data[2] >> 16) & 0xffff;
outw(val, chan_iobase + REG_C0H);
val = data[2] & 0xffff;
outw(val, chan_iobase + REG_C0L);
cmReg.value = data[1] & 0xffff;
cmReg.reg.preloadRegSel = 1;
outw(cmReg.value, chan_iobase + REG_C0M);
val = (data[3] >> 16) & 0xffff;
outw(val, chan_iobase + REG_C0H);
val = data[3] & 0xffff;
outw(val, chan_iobase + REG_C0L);
if (data[4]) {
val = data[4] & 0xffff;
outw(val, chan_iobase + REG_C0C);
}
break;
default:
return -EINVAL;
break;
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
unsigned long chan_iobase = dev->iobase + chan * 8;
inw(chan_iobase + REG_C0M);
switch (devpriv->gpct_config[chan]) {
case INSN_CONFIG_GPCT_PULSE_TRAIN_GENERATOR:
if ((data[1] <= data[0]) || !data[0])
return -EINVAL;
case INSN_CONFIG_GPCT_QUADRATURE_ENCODER:
case INSN_CONFIG_GPCT_SINGLE_PULSE_GENERATOR:
outw((data[0] >> 16) & 0xffff, chan_iobase + REG_C0H);
outw(data[0] & 0xffff, chan_iobase + REG_C0L);
break;
default:
return -EINVAL;
}
return insn->n;
}
static int s526_ai_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct s526_private *devpriv = dev->private;
int result = -EINVAL;
if (insn->n < 1)
return result;
result = insn->n;
outw(ISR_ADC_DONE, dev->iobase + REG_IER);
devpriv->ai_config = (data[0] & 0x3ff) << 5;
if (data[1] > 0)
devpriv->ai_config |= 0x8000;
devpriv->ai_config |= 0x0001;
return result;
}
static int s526_ai_rinsn(struct comedi_device *dev, struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct s526_private *devpriv = dev->private;
unsigned int chan = CR_CHAN(insn->chanspec);
int n, i;
unsigned short value;
unsigned int d;
unsigned int status;
value = (devpriv->ai_config & 0x8000) |
((1 << 5) << chan) | (chan << 1) | 0x0001;
for (n = 0; n < insn->n; n++) {
outw(value, dev->iobase + REG_ADC);
#define TIMEOUT 100
for (i = 0; i < TIMEOUT; i++) {
status = inw(dev->iobase + REG_ISR);
if (status & ISR_ADC_DONE) {
outw(ISR_ADC_DONE, dev->iobase + REG_ISR);
break;
}
}
if (i == TIMEOUT)
return -ETIMEDOUT;
d = inw(dev->iobase + REG_ADD);
data[n] = d ^ 0x8000;
}
return n;
}
static int s526_ao_winsn(struct comedi_device *dev, struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct s526_private *devpriv = dev->private;
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned short val;
int i;
val = chan << 1;
outw(val, dev->iobase + REG_DAC);
for (i = 0; i < insn->n; i++) {
outw(data[i], dev->iobase + REG_ADD);
devpriv->ao_readback[chan] = data[i];
outw(val + 1, dev->iobase + REG_DAC);
}
return i;
}
static int s526_ao_rinsn(struct comedi_device *dev, struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct s526_private *devpriv = dev->private;
unsigned int chan = CR_CHAN(insn->chanspec);
int i;
for (i = 0; i < insn->n; i++)
data[i] = devpriv->ao_readback[chan];
return i;
}
static int s526_dio_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
if (data[0]) {
s->state &= ~data[0];
s->state |= data[0] & data[1];
outw(s->state, dev->iobase + REG_DIO);
}
data[1] = inw(dev->iobase + REG_DIO) & 0xff;
return insn->n;
}
static int s526_dio_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
unsigned int chan = CR_CHAN(insn->chanspec);
int group, mask;
group = chan >> 2;
mask = 0xF << (group << 2);
switch (data[0]) {
case INSN_CONFIG_DIO_OUTPUT:
s->state |= 1 << (group + 10);
s->io_bits |= mask;
break;
case INSN_CONFIG_DIO_INPUT:
s->state &= ~(1 << (group + 10));
s->io_bits &= ~mask;
break;
case INSN_CONFIG_DIO_QUERY:
data[1] = (s->io_bits & mask) ? COMEDI_OUTPUT : COMEDI_INPUT;
return insn->n;
default:
return -EINVAL;
}
outw(s->state, dev->iobase + REG_DIO);
return 1;
}
static int s526_attach(struct comedi_device *dev, struct comedi_devconfig *it)
{
struct s526_private *devpriv;
struct comedi_subdevice *s;
int iobase;
int ret;
dev->board_name = dev->driver->driver_name;
iobase = it->options[0];
if (!iobase || !request_region(iobase, S526_IOSIZE, dev->board_name)) {
comedi_error(dev, "I/O port conflict");
return -EIO;
}
dev->iobase = iobase;
ret = alloc_private(dev, sizeof(*devpriv));
if (ret)
return ret;
devpriv = dev->private;
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
s->insn_read = s526_ai_rinsn;
s->insn_config = s526_ai_insn_config;
s = &dev->subdevices[2];
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = 4;
s->maxdata = 0xffff;
s->range_table = &range_bipolar10;
s->insn_write = s526_ao_winsn;
s->insn_read = s526_ao_rinsn;
s = &dev->subdevices[3];
s->type = COMEDI_SUBD_DIO;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE;
s->n_chan = 8;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = s526_dio_insn_bits;
s->insn_config = s526_dio_insn_config;
dev_info(dev->class_dev, "%s attached\n", dev->board_name);
return 1;
}
static void s526_detach(struct comedi_device *dev)
{
if (dev->iobase > 0)
release_region(dev->iobase, S526_IOSIZE);
}
