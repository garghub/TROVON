static int dt2811_ai_insn(struct comedi_device *dev, struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
int chan = CR_CHAN(insn->chanspec);
int timeout = DT2811_TIMEOUT;
int i;
for (i = 0; i < insn->n; i++) {
outb(chan, dev->iobase + DT2811_ADGCR);
while (timeout
&& inb(dev->iobase + DT2811_ADCSR) & DT2811_ADBUSY)
timeout--;
if (!timeout)
return -ETIME;
data[i] = inb(dev->iobase + DT2811_ADDATLO);
data[i] |= inb(dev->iobase + DT2811_ADDATHI) << 8;
data[i] &= 0xfff;
}
return i;
}
static int dt2811_ao_insn(struct comedi_device *dev, struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct dt2811_private *devpriv = dev->private;
int i;
int chan;
chan = CR_CHAN(insn->chanspec);
for (i = 0; i < insn->n; i++) {
outb(data[i] & 0xff, dev->iobase + DT2811_DADAT0LO + 2 * chan);
outb((data[i] >> 8) & 0xff,
dev->iobase + DT2811_DADAT0HI + 2 * chan);
devpriv->ao_readback[chan] = data[i];
}
return i;
}
static int dt2811_ao_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct dt2811_private *devpriv = dev->private;
int i;
int chan;
chan = CR_CHAN(insn->chanspec);
for (i = 0; i < insn->n; i++)
data[i] = devpriv->ao_readback[chan];
return i;
}
static int dt2811_di_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
data[1] = inb(dev->iobase + DT2811_DIO);
return insn->n;
}
static int dt2811_do_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
if (comedi_dio_update_state(s, data))
outb(s->state, dev->iobase + DT2811_DIO);
data[1] = s->state;
return insn->n;
}
static int dt2811_attach(struct comedi_device *dev, struct comedi_devconfig *it)
{
const struct dt2811_board *board = comedi_board(dev);
struct dt2811_private *devpriv;
int ret;
struct comedi_subdevice *s;
ret = comedi_request_region(dev, it->options[0], DT2811_SIZE);
if (ret)
return ret;
#if 0
outb(0, dev->iobase + DT2811_ADCSR);
udelay(100);
i = inb(dev->iobase + DT2811_ADDATLO);
i = inb(dev->iobase + DT2811_ADDATHI);
#endif
ret = comedi_alloc_subdevices(dev, 4);
if (ret)
return ret;
devpriv = comedi_alloc_devpriv(dev, sizeof(*devpriv));
if (!devpriv)
return -ENOMEM;
switch (it->options[2]) {
case 0:
devpriv->adc_mux = adc_singleended;
break;
case 1:
devpriv->adc_mux = adc_diff;
break;
case 2:
devpriv->adc_mux = adc_pseudo_diff;
break;
default:
devpriv->adc_mux = adc_singleended;
break;
}
switch (it->options[4]) {
case 0:
devpriv->dac_range[0] = dac_bipolar_5;
break;
case 1:
devpriv->dac_range[0] = dac_bipolar_2_5;
break;
case 2:
devpriv->dac_range[0] = dac_unipolar_5;
break;
default:
devpriv->dac_range[0] = dac_bipolar_5;
break;
}
switch (it->options[5]) {
case 0:
devpriv->dac_range[1] = dac_bipolar_5;
break;
case 1:
devpriv->dac_range[1] = dac_bipolar_2_5;
break;
case 2:
devpriv->dac_range[1] = dac_unipolar_5;
break;
default:
devpriv->dac_range[1] = dac_bipolar_5;
break;
}
s = &dev->subdevices[0];
s->type = COMEDI_SUBD_AI;
s->subdev_flags = SDF_READABLE | SDF_GROUND;
s->n_chan = devpriv->adc_mux == adc_diff ? 8 : 16;
s->insn_read = dt2811_ai_insn;
s->maxdata = 0xfff;
switch (it->options[3]) {
case 0:
default:
s->range_table = board->bip_5;
break;
case 1:
s->range_table = board->bip_2_5;
break;
case 2:
s->range_table = board->unip_5;
break;
}
s = &dev->subdevices[1];
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = 2;
s->insn_write = dt2811_ao_insn;
s->insn_read = dt2811_ao_insn_read;
s->maxdata = 0xfff;
s->range_table_list = devpriv->range_type_list;
devpriv->range_type_list[0] = dac_range_types[devpriv->dac_range[0]];
devpriv->range_type_list[1] = dac_range_types[devpriv->dac_range[1]];
s = &dev->subdevices[2];
s->type = COMEDI_SUBD_DI;
s->subdev_flags = SDF_READABLE;
s->n_chan = 8;
s->insn_bits = dt2811_di_insn_bits;
s->maxdata = 1;
s->range_table = &range_digital;
s = &dev->subdevices[3];
s->type = COMEDI_SUBD_DO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = 8;
s->insn_bits = dt2811_do_insn_bits;
s->maxdata = 1;
s->state = 0;
s->range_table = &range_digital;
return 0;
}
