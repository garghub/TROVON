static int poc_attach(struct comedi_device *dev, struct comedi_devconfig *it)
{
struct comedi_subdevice *s;
unsigned long iobase;
unsigned int iosize;
iobase = it->options[0];
printk(KERN_INFO "comedi%d: poc: using %s iobase 0x%lx\n", dev->minor,
this_board->name, iobase);
dev->board_name = this_board->name;
if (iobase == 0) {
printk(KERN_ERR "io base address required\n");
return -EINVAL;
}
iosize = this_board->iosize;
if (!request_region(iobase, iosize, "dac02")) {
printk(KERN_ERR "I/O port conflict: failed to allocate ports "
"0x%lx to 0x%lx\n", iobase, iobase + iosize - 1);
return -EIO;
}
dev->iobase = iobase;
if (alloc_subdevices(dev, 1) < 0)
return -ENOMEM;
if (alloc_private(dev, sizeof(unsigned int) * this_board->n_chan) < 0)
return -ENOMEM;
s = dev->subdevices + 0;
s->type = this_board->type;
s->n_chan = this_board->n_chan;
s->maxdata = (1 << this_board->n_bits) - 1;
s->range_table = this_board->range;
s->insn_write = this_board->winsn;
s->insn_read = this_board->rinsn;
s->insn_bits = this_board->insnbits;
if (s->type == COMEDI_SUBD_AO || s->type == COMEDI_SUBD_DO)
s->subdev_flags = SDF_WRITABLE;
return 0;
}
static int poc_detach(struct comedi_device *dev)
{
if (dev->iobase)
release_region(dev->iobase, this_board->iosize);
printk(KERN_INFO "comedi%d: dac02: remove\n", dev->minor);
return 0;
}
static int readback_insn(struct comedi_device *dev, struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
int chan;
chan = CR_CHAN(insn->chanspec);
data[0] = ((unsigned int *)dev->private)[chan];
return 1;
}
static int dac02_ao_winsn(struct comedi_device *dev, struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
int temp;
int chan;
int output;
chan = CR_CHAN(insn->chanspec);
((unsigned int *)dev->private)[chan] = data[0];
output = data[0];
#ifdef wrong
if ((CR_RANGE(insn->chanspec) & 0x2) == 0)
output = ~output;
#endif
temp = (output << 4) & 0xf0;
outb(temp, dev->iobase + DAC02_LSB(chan));
temp = (output >> 4) & 0xff;
outb(temp, dev->iobase + DAC02_MSB(chan));
return 1;
}
static int pcl733_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
if (insn->n != 2)
return -EINVAL;
data[1] = inb(dev->iobase + 0);
data[1] |= (inb(dev->iobase + 1) << 8);
data[1] |= (inb(dev->iobase + 2) << 16);
data[1] |= (inb(dev->iobase + 3) << 24);
return 2;
}
static int pcl734_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
if (insn->n != 2)
return -EINVAL;
if (data[0]) {
s->state &= ~data[0];
s->state |= (data[0] & data[1]);
if ((data[0] >> 0) & 0xff)
outb((s->state >> 0) & 0xff, dev->iobase + 0);
if ((data[0] >> 8) & 0xff)
outb((s->state >> 8) & 0xff, dev->iobase + 1);
if ((data[0] >> 16) & 0xff)
outb((s->state >> 16) & 0xff, dev->iobase + 2);
if ((data[0] >> 24) & 0xff)
outb((s->state >> 24) & 0xff, dev->iobase + 3);
}
data[1] = s->state;
return 2;
}
static int __init driver_poc_init_module(void)
{
return comedi_driver_register(&driver_poc);
}
static void __exit driver_poc_cleanup_module(void)
{
comedi_driver_unregister(&driver_poc);
}
