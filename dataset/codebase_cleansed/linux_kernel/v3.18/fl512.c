static int fl512_ai_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned int val;
int i;
outb(chan, dev->iobase + FL512_AI_MUX_REG);
for (i = 0; i < insn->n; i++) {
outb(0, dev->iobase + FL512_AI_START_CONV_REG);
udelay(30);
val = inb(dev->iobase + FL512_AI_LSB_REG);
val |= (inb(dev->iobase + FL512_AI_MSB_REG) << 8);
val &= s->maxdata;
data[i] = val;
}
return insn->n;
}
static int fl512_ao_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned int val = s->readback[chan];
int i;
for (i = 0; i < insn->n; i++) {
val = data[i];
outb(val & 0x0ff, dev->iobase + FL512_AO_DATA_REG(chan));
outb((val >> 8) & 0xf, dev->iobase + FL512_AO_DATA_REG(chan));
inb(dev->iobase + FL512_AO_TRIG_REG(chan));
}
s->readback[chan] = val;
return insn->n;
}
static int fl512_attach(struct comedi_device *dev, struct comedi_devconfig *it)
{
struct comedi_subdevice *s;
int ret;
ret = comedi_request_region(dev, it->options[0], 0x10);
if (ret)
return ret;
ret = comedi_alloc_subdevices(dev, 2);
if (ret)
return ret;
s = &dev->subdevices[0];
s->type = COMEDI_SUBD_AI;
s->subdev_flags = SDF_READABLE | SDF_GROUND;
s->n_chan = 16;
s->maxdata = 0x0fff;
s->range_table = &range_fl512;
s->insn_read = fl512_ai_insn_read;
s = &dev->subdevices[1];
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = 2;
s->maxdata = 0x0fff;
s->range_table = &range_fl512;
s->insn_write = fl512_ao_insn_write;
s->insn_read = comedi_readback_insn_read;
ret = comedi_alloc_subdev_readback(s);
if (ret)
return ret;
return 0;
}
