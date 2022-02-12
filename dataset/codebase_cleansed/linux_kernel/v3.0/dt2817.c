static int __init driver_dt2817_init_module(void)
{
return comedi_driver_register(&driver_dt2817);
}
static void __exit driver_dt2817_cleanup_module(void)
{
comedi_driver_unregister(&driver_dt2817);
}
static int dt2817_dio_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
int mask;
int chan;
int oe = 0;
if (insn->n != 1)
return -EINVAL;
chan = CR_CHAN(insn->chanspec);
if (chan < 8)
mask = 0xff;
else if (chan < 16)
mask = 0xff00;
else if (chan < 24)
mask = 0xff0000;
else
mask = 0xff000000;
if (data[0])
s->io_bits |= mask;
else
s->io_bits &= ~mask;
if (s->io_bits & 0x000000ff)
oe |= 0x1;
if (s->io_bits & 0x0000ff00)
oe |= 0x2;
if (s->io_bits & 0x00ff0000)
oe |= 0x4;
if (s->io_bits & 0xff000000)
oe |= 0x8;
outb(oe, dev->iobase + DT2817_CR);
return 1;
}
static int dt2817_dio_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
unsigned int changed;
if (data[0]) {
changed = s->state;
s->state &= ~data[0];
s->state |= (data[0] & data[1]);
changed ^= s->state;
changed &= s->io_bits;
if (changed & 0x000000ff)
outb(s->state & 0xff, dev->iobase + DT2817_DATA + 0);
if (changed & 0x0000ff00)
outb((s->state >> 8) & 0xff,
dev->iobase + DT2817_DATA + 1);
if (changed & 0x00ff0000)
outb((s->state >> 16) & 0xff,
dev->iobase + DT2817_DATA + 2);
if (changed & 0xff000000)
outb((s->state >> 24) & 0xff,
dev->iobase + DT2817_DATA + 3);
}
data[1] = inb(dev->iobase + DT2817_DATA + 0);
data[1] |= (inb(dev->iobase + DT2817_DATA + 1) << 8);
data[1] |= (inb(dev->iobase + DT2817_DATA + 2) << 16);
data[1] |= (inb(dev->iobase + DT2817_DATA + 3) << 24);
return 2;
}
static int dt2817_attach(struct comedi_device *dev, struct comedi_devconfig *it)
{
int ret;
struct comedi_subdevice *s;
unsigned long iobase;
iobase = it->options[0];
printk(KERN_INFO "comedi%d: dt2817: 0x%04lx ", dev->minor, iobase);
if (!request_region(iobase, DT2817_SIZE, "dt2817")) {
printk("I/O port conflict\n");
return -EIO;
}
dev->iobase = iobase;
dev->board_name = "dt2817";
ret = alloc_subdevices(dev, 1);
if (ret < 0)
return ret;
s = dev->subdevices + 0;
s->n_chan = 32;
s->type = COMEDI_SUBD_DIO;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE;
s->range_table = &range_digital;
s->maxdata = 1;
s->insn_bits = dt2817_dio_insn_bits;
s->insn_config = dt2817_dio_insn_config;
s->state = 0;
outb(0, dev->iobase + DT2817_CR);
printk(KERN_INFO "\n");
return 0;
}
static int dt2817_detach(struct comedi_device *dev)
{
printk(KERN_INFO "comedi%d: dt2817: remove\n", dev->minor);
if (dev->iobase)
release_region(dev->iobase, DT2817_SIZE);
return 0;
}
