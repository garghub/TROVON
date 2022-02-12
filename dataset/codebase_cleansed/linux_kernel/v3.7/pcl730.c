static int pcl730_do_insn(struct comedi_device *dev, struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
if (data[0]) {
s->state &= ~data[0];
s->state |= (data[0] & data[1]);
}
if (data[0] & 0x00ff)
outb(s->state & 0xff,
dev->iobase + ((unsigned long)s->private));
if (data[0] & 0xff00)
outb((s->state >> 8),
dev->iobase + ((unsigned long)s->private) + 1);
data[1] = s->state;
return insn->n;
}
static int pcl730_di_insn(struct comedi_device *dev, struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
data[1] = inb(dev->iobase + ((unsigned long)s->private)) |
(inb(dev->iobase + ((unsigned long)s->private) + 1) << 8);
return insn->n;
}
static int pcl730_attach(struct comedi_device *dev, struct comedi_devconfig *it)
{
const struct pcl730_board *board = comedi_board(dev);
struct comedi_subdevice *s;
unsigned long iobase;
unsigned int iorange;
int ret;
iobase = it->options[0];
iorange = board->io_range;
printk(KERN_INFO "comedi%d: pcl730: board=%s 0x%04lx ", dev->minor,
board->name, iobase);
if (!request_region(iobase, iorange, "pcl730")) {
printk("I/O port conflict\n");
return -EIO;
}
dev->board_name = board->name;
dev->iobase = iobase;
dev->irq = 0;
ret = comedi_alloc_subdevices(dev, 4);
if (ret)
return ret;
s = &dev->subdevices[0];
s->type = COMEDI_SUBD_DO;
s->subdev_flags = SDF_WRITABLE;
s->maxdata = 1;
s->n_chan = 16;
s->insn_bits = pcl730_do_insn;
s->range_table = &range_digital;
s->private = (void *)PCL730_IDIO_LO;
s = &dev->subdevices[1];
s->type = COMEDI_SUBD_DI;
s->subdev_flags = SDF_READABLE;
s->maxdata = 1;
s->n_chan = 16;
s->insn_bits = pcl730_di_insn;
s->range_table = &range_digital;
s->private = (void *)PCL730_IDIO_LO;
s = &dev->subdevices[2];
s->type = COMEDI_SUBD_DO;
s->subdev_flags = SDF_WRITABLE;
s->maxdata = 1;
s->n_chan = 16;
s->insn_bits = pcl730_do_insn;
s->range_table = &range_digital;
s->private = (void *)PCL730_DIO_LO;
s = &dev->subdevices[3];
s->type = COMEDI_SUBD_DI;
s->subdev_flags = SDF_READABLE;
s->maxdata = 1;
s->n_chan = 16;
s->insn_bits = pcl730_di_insn;
s->range_table = &range_digital;
s->private = (void *)PCL730_DIO_LO;
printk(KERN_INFO "\n");
return 0;
}
static void pcl730_detach(struct comedi_device *dev)
{
const struct pcl730_board *board = comedi_board(dev);
if (dev->iobase)
release_region(dev->iobase, board->io_range);
}
