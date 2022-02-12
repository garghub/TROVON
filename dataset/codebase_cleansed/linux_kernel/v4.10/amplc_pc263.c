static int pc263_do_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
if (comedi_dio_update_state(s, data)) {
outb(s->state & 0xff, dev->iobase + PC263_DO_0_7_REG);
outb((s->state >> 8) & 0xff, dev->iobase + PC263_DO_8_15_REG);
}
data[1] = s->state;
return insn->n;
}
static int pc263_attach(struct comedi_device *dev, struct comedi_devconfig *it)
{
struct comedi_subdevice *s;
int ret;
ret = comedi_request_region(dev, it->options[0], 0x2);
if (ret)
return ret;
ret = comedi_alloc_subdevices(dev, 1);
if (ret)
return ret;
s = &dev->subdevices[0];
s->type = COMEDI_SUBD_DO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = 16;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = pc263_do_insn_bits;
s->state = inb(dev->iobase + PC263_DO_0_7_REG) |
(inb(dev->iobase + PC263_DO_8_15_REG) << 8);
return 0;
}
