static int dt2817_dio_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned int chan = CR_CHAN(insn->chanspec);
unsigned int oe = 0;
unsigned int mask;
int ret;
if (chan < 8)
mask = 0x000000ff;
else if (chan < 16)
mask = 0x0000ff00;
else if (chan < 24)
mask = 0x00ff0000;
else
mask = 0xff000000;
ret = comedi_dio_insn_config(dev, s, insn, data, mask);
if (ret)
return ret;
if (s->io_bits & 0x000000ff)
oe |= 0x1;
if (s->io_bits & 0x0000ff00)
oe |= 0x2;
if (s->io_bits & 0x00ff0000)
oe |= 0x4;
if (s->io_bits & 0xff000000)
oe |= 0x8;
outb(oe, dev->iobase + DT2817_CR);
return insn->n;
}
static int dt2817_dio_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned long iobase = dev->iobase + DT2817_DATA;
unsigned int mask;
unsigned int val;
mask = comedi_dio_update_state(s, data);
if (mask) {
if (mask & 0x000000ff)
outb(s->state & 0xff, iobase + 0);
if (mask & 0x0000ff00)
outb((s->state >> 8) & 0xff, iobase + 1);
if (mask & 0x00ff0000)
outb((s->state >> 16) & 0xff, iobase + 2);
if (mask & 0xff000000)
outb((s->state >> 24) & 0xff, iobase + 3);
}
val = inb(iobase + 0);
val |= (inb(iobase + 1) << 8);
val |= (inb(iobase + 2) << 16);
val |= (inb(iobase + 3) << 24);
data[1] = val;
return insn->n;
}
static int dt2817_attach(struct comedi_device *dev, struct comedi_devconfig *it)
{
int ret;
struct comedi_subdevice *s;
ret = comedi_request_region(dev, it->options[0], DT2817_SIZE);
if (ret)
return ret;
ret = comedi_alloc_subdevices(dev, 1);
if (ret)
return ret;
s = &dev->subdevices[0];
s->n_chan = 32;
s->type = COMEDI_SUBD_DIO;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE;
s->range_table = &range_digital;
s->maxdata = 1;
s->insn_bits = dt2817_dio_insn_bits;
s->insn_config = dt2817_dio_insn_config;
s->state = 0;
outb(0, dev->iobase + DT2817_CR);
return 0;
}
