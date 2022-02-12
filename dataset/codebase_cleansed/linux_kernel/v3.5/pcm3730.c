static int pcm3730_do_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
if (insn->n != 2)
return -EINVAL;
if (data[0]) {
s->state &= ~data[0];
s->state |= (data[0] & data[1]);
outb(s->state, dev->iobase + (unsigned long)(s->private));
}
data[1] = s->state;
return 2;
}
static int pcm3730_di_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
if (insn->n != 2)
return -EINVAL;
data[1] = inb(dev->iobase + (unsigned long)(s->private));
return 2;
}
static int pcm3730_attach(struct comedi_device *dev,
struct comedi_devconfig *it)
{
struct comedi_subdevice *s;
unsigned long iobase;
iobase = it->options[0];
printk(KERN_INFO "comedi%d: pcm3730: 0x%04lx ", dev->minor, iobase);
if (!request_region(iobase, PCM3730_SIZE, "pcm3730")) {
printk("I/O port conflict\n");
return -EIO;
}
dev->iobase = iobase;
dev->board_name = "pcm3730";
dev->iobase = dev->iobase;
dev->irq = 0;
if (alloc_subdevices(dev, 6) < 0)
return -ENOMEM;
s = dev->subdevices + 0;
s->type = COMEDI_SUBD_DO;
s->subdev_flags = SDF_WRITABLE;
s->maxdata = 1;
s->n_chan = 8;
s->insn_bits = pcm3730_do_insn_bits;
s->range_table = &range_digital;
s->private = (void *)PCM3730_DOA;
s = dev->subdevices + 1;
s->type = COMEDI_SUBD_DO;
s->subdev_flags = SDF_WRITABLE;
s->maxdata = 1;
s->n_chan = 8;
s->insn_bits = pcm3730_do_insn_bits;
s->range_table = &range_digital;
s->private = (void *)PCM3730_DOB;
s = dev->subdevices + 2;
s->type = COMEDI_SUBD_DO;
s->subdev_flags = SDF_WRITABLE;
s->maxdata = 1;
s->n_chan = 8;
s->insn_bits = pcm3730_do_insn_bits;
s->range_table = &range_digital;
s->private = (void *)PCM3730_DOC;
s = dev->subdevices + 3;
s->type = COMEDI_SUBD_DI;
s->subdev_flags = SDF_READABLE;
s->maxdata = 1;
s->n_chan = 8;
s->insn_bits = pcm3730_di_insn_bits;
s->range_table = &range_digital;
s->private = (void *)PCM3730_DIA;
s = dev->subdevices + 4;
s->type = COMEDI_SUBD_DI;
s->subdev_flags = SDF_READABLE;
s->maxdata = 1;
s->n_chan = 8;
s->insn_bits = pcm3730_di_insn_bits;
s->range_table = &range_digital;
s->private = (void *)PCM3730_DIB;
s = dev->subdevices + 5;
s->type = COMEDI_SUBD_DI;
s->subdev_flags = SDF_READABLE;
s->maxdata = 1;
s->n_chan = 8;
s->insn_bits = pcm3730_di_insn_bits;
s->range_table = &range_digital;
s->private = (void *)PCM3730_DIC;
printk(KERN_INFO "\n");
return 0;
}
static void pcm3730_detach(struct comedi_device *dev)
{
if (dev->iobase)
release_region(dev->iobase, PCM3730_SIZE);
}
