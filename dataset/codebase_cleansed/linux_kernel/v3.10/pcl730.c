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
int ret;
ret = comedi_request_region(dev, it->options[0], board->io_range);
if (ret)
return ret;
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
