static int mpc624_ai_rinsn(struct comedi_device *dev,
struct comedi_subdevice *s, struct comedi_insn *insn,
unsigned int *data)
{
struct mpc624_private *devpriv = dev->private;
int n, i;
unsigned long int data_in, data_out;
unsigned char ucPort;
outb(insn->chanspec, dev->iobase + MPC624_GNMUXCH);
for (n = 0; n < insn->n; n++) {
outb(MPC624_ADSCK, dev->iobase + MPC624_ADC);
udelay(1);
outb(MPC624_ADCS | MPC624_ADSCK, dev->iobase + MPC624_ADC);
udelay(1);
outb(0, dev->iobase + MPC624_ADC);
udelay(1);
for (i = 0; i < TIMEOUT; i++) {
ucPort = inb(dev->iobase + MPC624_ADC);
if (ucPort & MPC624_ADBUSY)
udelay(1000);
else
break;
}
if (i == TIMEOUT)
return -ETIMEDOUT;
data_in = 0;
data_out = devpriv->ulConvertionRate;
udelay(1);
for (i = 0; i < 32; i++) {
outb(0, dev->iobase + MPC624_ADC);
udelay(1);
if (data_out & (1 << 31)) {
outb(MPC624_ADSDI, dev->iobase + MPC624_ADC);
udelay(1);
outb(MPC624_ADSCK | MPC624_ADSDI,
dev->iobase + MPC624_ADC);
} else {
outb(0, dev->iobase + MPC624_ADC);
udelay(1);
outb(MPC624_ADSCK, dev->iobase + MPC624_ADC);
}
udelay(1);
data_in <<= 1;
data_in |=
(inb(dev->iobase + MPC624_ADC) & MPC624_ADSDO) >> 4;
udelay(1);
data_out <<= 1;
}
if (data_in & MPC624_EOC_BIT)
dev_dbg(dev->class_dev,
"EOC bit is set (data_in=%lu)!", data_in);
if (data_in & MPC624_DMY_BIT)
dev_dbg(dev->class_dev,
"DMY bit is set (data_in=%lu)!", data_in);
if (data_in & MPC624_SGN_BIT) {
data_in &= 0x3FFFFFFF;
data[n] = data_in;
} else {
data_in |= MPC624_SGN_BIT;
data_in = ~data_in;
data_in += 1;
data_in &= ~(MPC624_EOC_BIT | MPC624_DMY_BIT);
data_in = 0x20000000 - data_in;
data[n] = data_in;
}
}
return n;
}
static int mpc624_attach(struct comedi_device *dev, struct comedi_devconfig *it)
{
struct mpc624_private *devpriv;
struct comedi_subdevice *s;
int ret;
ret = comedi_request_region(dev, it->options[0], MPC624_SIZE);
if (ret)
return ret;
devpriv = comedi_alloc_devpriv(dev, sizeof(*devpriv));
if (!devpriv)
return -ENOMEM;
switch (it->options[1]) {
case 0:
devpriv->ulConvertionRate = MPC624_SPEED_3_52_kHz;
break;
case 1:
devpriv->ulConvertionRate = MPC624_SPEED_1_76_kHz;
break;
case 2:
devpriv->ulConvertionRate = MPC624_SPEED_880_Hz;
break;
case 3:
devpriv->ulConvertionRate = MPC624_SPEED_440_Hz;
break;
case 4:
devpriv->ulConvertionRate = MPC624_SPEED_220_Hz;
break;
case 5:
devpriv->ulConvertionRate = MPC624_SPEED_110_Hz;
break;
case 6:
devpriv->ulConvertionRate = MPC624_SPEED_55_Hz;
break;
case 7:
devpriv->ulConvertionRate = MPC624_SPEED_27_5_Hz;
break;
case 8:
devpriv->ulConvertionRate = MPC624_SPEED_13_75_Hz;
break;
case 9:
devpriv->ulConvertionRate = MPC624_SPEED_6_875_Hz;
break;
default:
devpriv->ulConvertionRate = MPC624_SPEED_3_52_kHz;
}
ret = comedi_alloc_subdevices(dev, 1);
if (ret)
return ret;
s = &dev->subdevices[0];
s->type = COMEDI_SUBD_AI;
s->subdev_flags = SDF_READABLE | SDF_DIFF;
s->n_chan = 8;
switch (it->options[1]) {
default:
s->maxdata = 0x3FFFFFFF;
}
switch (it->options[1]) {
case 0:
s->range_table = &range_mpc624_bipolar1;
break;
default:
s->range_table = &range_mpc624_bipolar10;
}
s->len_chanlist = 1;
s->insn_read = mpc624_ai_rinsn;
return 1;
}
