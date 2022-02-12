static int aio_iiro_16_dio_insn_bits_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
if (insn->n != 2)
return -EINVAL;
if (data[0]) {
s->state &= ~data[0];
s->state |= data[0] & data[1];
outb(s->state & 0xff, dev->iobase + AIO_IIRO_16_RELAY_0_7);
outb((s->state >> 8) & 0xff,
dev->iobase + AIO_IIRO_16_RELAY_8_15);
}
data[1] = s->state;
return 2;
}
static int aio_iiro_16_dio_insn_bits_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
if (insn->n != 2)
return -EINVAL;
data[1] = 0;
data[1] |= inb(dev->iobase + AIO_IIRO_16_INPUT_0_7);
data[1] |= inb(dev->iobase + AIO_IIRO_16_INPUT_8_15) << 8;
return 2;
}
static int aio_iiro_16_attach(struct comedi_device *dev,
struct comedi_devconfig *it)
{
int iobase;
struct comedi_subdevice *s;
printk(KERN_INFO "comedi%d: aio_iiro_16: ", dev->minor);
dev->board_name = thisboard->name;
iobase = it->options[0];
if (!request_region(iobase, AIO_IIRO_16_SIZE, dev->board_name)) {
printk("I/O port conflict");
return -EIO;
}
dev->iobase = iobase;
if (alloc_private(dev, sizeof(struct aio_iiro_16_private)) < 0)
return -ENOMEM;
if (alloc_subdevices(dev, 2) < 0)
return -ENOMEM;
s = dev->subdevices + 0;
s->type = COMEDI_SUBD_DIO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = 16;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = aio_iiro_16_dio_insn_bits_write;
s = dev->subdevices + 1;
s->type = COMEDI_SUBD_DIO;
s->subdev_flags = SDF_READABLE;
s->n_chan = 16;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = aio_iiro_16_dio_insn_bits_read;
printk("attached\n");
return 1;
}
static void aio_iiro_16_detach(struct comedi_device *dev)
{
if (dev->iobase)
release_region(dev->iobase, AIO_IIRO_16_SIZE);
}
