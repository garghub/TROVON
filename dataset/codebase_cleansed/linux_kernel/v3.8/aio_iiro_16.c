static int aio_iiro_16_dio_insn_bits_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
if (data[0]) {
s->state &= ~data[0];
s->state |= data[0] & data[1];
outb(s->state & 0xff, dev->iobase + AIO_IIRO_16_RELAY_0_7);
outb((s->state >> 8) & 0xff,
dev->iobase + AIO_IIRO_16_RELAY_8_15);
}
data[1] = s->state;
return insn->n;
}
static int aio_iiro_16_dio_insn_bits_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
data[1] = 0;
data[1] |= inb(dev->iobase + AIO_IIRO_16_INPUT_0_7);
data[1] |= inb(dev->iobase + AIO_IIRO_16_INPUT_8_15) << 8;
return insn->n;
}
static int aio_iiro_16_attach(struct comedi_device *dev,
struct comedi_devconfig *it)
{
int iobase;
struct comedi_subdevice *s;
int ret;
printk(KERN_INFO "comedi%d: aio_iiro_16: ", dev->minor);
dev->board_name = dev->driver->driver_name;
iobase = it->options[0];
if (!request_region(iobase, AIO_IIRO_16_SIZE, dev->board_name)) {
printk("I/O port conflict");
return -EIO;
}
dev->iobase = iobase;
ret = comedi_alloc_subdevices(dev, 2);
if (ret)
return ret;
s = &dev->subdevices[0];
s->type = COMEDI_SUBD_DIO;
s->subdev_flags = SDF_WRITABLE;
s->n_chan = 16;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = aio_iiro_16_dio_insn_bits_write;
s = &dev->subdevices[1];
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
