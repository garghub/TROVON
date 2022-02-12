static int rti802_ao_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct rti802_private *devpriv = dev->private;
unsigned int chan = CR_CHAN(insn->chanspec);
int i;
for (i = 0; i < insn->n; i++)
data[i] = devpriv->ao_readback[chan];
return insn->n;
}
static int rti802_ao_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct rti802_private *devpriv = dev->private;
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned int val;
int i;
outb(chan, dev->iobase + RTI802_SELECT);
for (i = 0; i < insn->n; i++) {
val = data[i];
devpriv->ao_readback[chan] = val;
if (devpriv->dac_coding[chan] == dac_2comp)
val = comedi_offset_munge(s, val);
outb(val & 0xff, dev->iobase + RTI802_DATALOW);
outb((val >> 8) & 0xff, dev->iobase + RTI802_DATAHIGH);
}
return insn->n;
}
static int rti802_attach(struct comedi_device *dev, struct comedi_devconfig *it)
{
struct rti802_private *devpriv;
struct comedi_subdevice *s;
int i;
int ret;
ret = comedi_request_region(dev, it->options[0], 0x04);
if (ret)
return ret;
devpriv = comedi_alloc_devpriv(dev, sizeof(*devpriv));
if (!devpriv)
return -ENOMEM;
ret = comedi_alloc_subdevices(dev, 1);
if (ret)
return ret;
s = &dev->subdevices[0];
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITABLE;
s->maxdata = 0xfff;
s->n_chan = 8;
s->insn_read = rti802_ao_insn_read;
s->insn_write = rti802_ao_insn_write;
s->range_table_list = devpriv->range_type_list;
for (i = 0; i < 8; i++) {
devpriv->dac_coding[i] = (it->options[3 + 2 * i])
? (dac_straight) : (dac_2comp);
devpriv->range_type_list[i] = (it->options[2 + 2 * i])
? &range_unipolar10 : &range_bipolar10;
}
return 0;
}
