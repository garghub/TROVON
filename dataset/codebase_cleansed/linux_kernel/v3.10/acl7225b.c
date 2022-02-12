static int acl7225b_do_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned long reg = (unsigned long)s->private;
unsigned int mask = data[0];
unsigned int bits = data[1];
if (mask) {
s->state &= ~mask;
s->state |= (bits & mask);
if (mask & 0x00ff)
outb(s->state & 0xff, dev->iobase + reg);
if (mask & 0xff00)
outb((s->state >> 8), dev->iobase + reg + 1);
}
data[1] = s->state;
return insn->n;
}
static int acl7225b_di_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned long reg = (unsigned long)s->private;
data[1] = inb(dev->iobase + reg) |
(inb(dev->iobase + reg + 1) << 8);
return insn->n;
}
static int acl7225b_attach(struct comedi_device *dev,
struct comedi_devconfig *it)
{
const struct acl7225b_boardinfo *board = comedi_board(dev);
struct comedi_subdevice *s;
int ret;
ret = comedi_request_region(dev, it->options[0], board->io_range);
if (ret)
return ret;
ret = comedi_alloc_subdevices(dev, 3);
if (ret)
return ret;
s = &dev->subdevices[0];
s->type = COMEDI_SUBD_DO;
s->subdev_flags = SDF_WRITABLE;
s->maxdata = 1;
s->n_chan = 16;
s->insn_bits = acl7225b_do_insn_bits;
s->range_table = &range_digital;
s->private = (void *)ACL7225_RIO_LO;
s = &dev->subdevices[1];
s->type = COMEDI_SUBD_DI;
s->subdev_flags = SDF_READABLE;
s->maxdata = 1;
s->n_chan = 16;
s->insn_bits = acl7225b_di_insn_bits;
s->range_table = &range_digital;
s->private = (void *)ACL7225_RIO_LO;
s = &dev->subdevices[2];
s->type = COMEDI_SUBD_DI;
s->subdev_flags = SDF_READABLE;
s->maxdata = 1;
s->n_chan = 16;
s->insn_bits = acl7225b_di_insn_bits;
s->range_table = &range_digital;
s->private = (void *)ACL7225_DI_LO;
return 0;
}
