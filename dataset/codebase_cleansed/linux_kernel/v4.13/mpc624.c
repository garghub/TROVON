static unsigned int mpc624_ai_get_sample(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct mpc624_private *devpriv = dev->private;
unsigned int data_out = devpriv->ai_speed;
unsigned int data_in = 0;
unsigned int bit;
int i;
udelay(1);
for (i = 0; i < 32; i++) {
outb(0, dev->iobase + MPC624_ADC);
udelay(1);
bit = (data_out & BIT(31)) ? MPC624_ADSDI : 0;
outb(bit, dev->iobase + MPC624_ADC);
udelay(1);
outb(MPC624_ADSCK | bit, dev->iobase + MPC624_ADC);
udelay(1);
data_in <<= 1;
data_in |= (inb(dev->iobase + MPC624_ADC) & MPC624_ADSDO) >> 4;
udelay(1);
data_out <<= 1;
}
if (data_in & MPC624_EOC_BIT)
dev_dbg(dev->class_dev, "EOC bit is set!");
if (data_in & MPC624_DMY_BIT)
dev_dbg(dev->class_dev, "DMY bit is set!");
if (data_in & MPC624_SGN_BIT) {
data_in &= 0x3fffffff;
} else {
data_in |= MPC624_SGN_BIT;
data_in = ~data_in;
data_in += 1;
data_in &= ~(MPC624_EOC_BIT | MPC624_DMY_BIT);
data_in = 0x20000000 - data_in;
}
return data_in;
}
static int mpc624_ai_eoc(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned long context)
{
unsigned char status;
status = inb(dev->iobase + MPC624_ADC);
if ((status & MPC624_ADBUSY) == 0)
return 0;
return -EBUSY;
}
static int mpc624_ai_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
int ret;
int i;
outb(insn->chanspec, dev->iobase + MPC624_GNMUXCH);
for (i = 0; i < insn->n; i++) {
outb(MPC624_ADSCK, dev->iobase + MPC624_ADC);
udelay(1);
outb(MPC624_ADCS | MPC624_ADSCK, dev->iobase + MPC624_ADC);
udelay(1);
outb(0, dev->iobase + MPC624_ADC);
udelay(1);
ret = comedi_timeout(dev, s, insn, mpc624_ai_eoc, 0);
if (ret)
return ret;
data[i] = mpc624_ai_get_sample(dev, s);
}
return insn->n;
}
static int mpc624_attach(struct comedi_device *dev, struct comedi_devconfig *it)
{
struct mpc624_private *devpriv;
struct comedi_subdevice *s;
int ret;
ret = comedi_request_region(dev, it->options[0], 0x10);
if (ret)
return ret;
devpriv = comedi_alloc_devpriv(dev, sizeof(*devpriv));
if (!devpriv)
return -ENOMEM;
switch (it->options[1]) {
case 0:
devpriv->ai_speed = MPC624_SPEED_3_52_KHZ;
break;
case 1:
devpriv->ai_speed = MPC624_SPEED_1_76_KHZ;
break;
case 2:
devpriv->ai_speed = MPC624_SPEED_880_HZ;
break;
case 3:
devpriv->ai_speed = MPC624_SPEED_440_HZ;
break;
case 4:
devpriv->ai_speed = MPC624_SPEED_220_HZ;
break;
case 5:
devpriv->ai_speed = MPC624_SPEED_110_HZ;
break;
case 6:
devpriv->ai_speed = MPC624_SPEED_55_HZ;
break;
case 7:
devpriv->ai_speed = MPC624_SPEED_27_5_HZ;
break;
case 8:
devpriv->ai_speed = MPC624_SPEED_13_75_HZ;
break;
case 9:
devpriv->ai_speed = MPC624_SPEED_6_875_HZ;
break;
default:
devpriv->ai_speed = MPC624_SPEED_3_52_KHZ;
}
ret = comedi_alloc_subdevices(dev, 1);
if (ret)
return ret;
s = &dev->subdevices[0];
s->type = COMEDI_SUBD_AI;
s->subdev_flags = SDF_READABLE | SDF_DIFF;
s->n_chan = 4;
s->maxdata = 0x3fffffff;
s->range_table = (it->options[1] == 0) ? &range_mpc624_bipolar1
: &range_mpc624_bipolar10;
s->insn_read = mpc624_ai_insn_read;
return 0;
}
