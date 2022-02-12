static int subdev_8255_cb(int dir, int port, int data, unsigned long arg)
{
unsigned long iobase = arg;
if (dir) {
outb(data, iobase + port);
return 0;
} else {
return inb(iobase + port);
}
}
static int subdev_8255mapped_cb(int dir, int port, int data,
unsigned long iobase)
{
int movport = SIZE_8255 * (iobase >> 12);
iobase &= 0x0fff;
if (dir) {
outb(port + movport, iobase);
outb(data, iobase + 1);
return 0;
} else {
outb(port + movport, iobase);
return inb(iobase + 1);
}
}
static int pcl724_attach(struct comedi_device *dev, struct comedi_devconfig *it)
{
unsigned long iobase;
unsigned int iorange;
int ret, i, n_subdevices;
#ifdef PCL724_IRQ
unsigned int irq;
#endif
iobase = it->options[0];
iorange = this_board->io_range;
if ((this_board->can_have96) && ((it->options[1] == 1)
|| (it->options[1] == 96)))
iorange = PCL722_96_SIZE;
printk(KERN_INFO "comedi%d: pcl724: board=%s, 0x%03lx ", dev->minor,
this_board->name, iobase);
if (!request_region(iobase, iorange, "pcl724")) {
printk("I/O port conflict\n");
return -EIO;
}
dev->iobase = iobase;
dev->board_name = this_board->name;
#ifdef PCL724_IRQ
irq = 0;
if (this_board->IRQbits != 0) {
irq = it->options[1];
if (irq) {
if (((1 << irq) & this_board->IRQbits) == 0) {
printk(KERN_WARNING
", IRQ %u is out of allowed range, "
"DISABLING IT", irq);
irq = 0;
} else {
if (request_irq
(irq, interrupt_pcl724, 0, "pcl724", dev)) {
printk(KERN_WARNING
", unable to allocate IRQ %u, "
"DISABLING IT", irq);
irq = 0;
} else {
printk(", irq=%u", irq);
}
}
}
}
dev->irq = irq;
#endif
printk("\n");
n_subdevices = this_board->numofports;
if ((this_board->can_have96) && ((it->options[1] == 1)
|| (it->options[1] == 96)))
n_subdevices = 4;
ret = alloc_subdevices(dev, n_subdevices);
if (ret < 0)
return ret;
for (i = 0; i < dev->n_subdevices; i++) {
if (this_board->is_pet48) {
subdev_8255_init(dev, dev->subdevices + i,
subdev_8255mapped_cb,
(unsigned long)(dev->iobase +
i * 0x1000));
} else
subdev_8255_init(dev, dev->subdevices + i,
subdev_8255_cb,
(unsigned long)(dev->iobase +
SIZE_8255 * i));
}
return 0;
}
static void pcl724_detach(struct comedi_device *dev)
{
int i;
for (i = 0; i < dev->n_subdevices; i++)
subdev_8255_cleanup(dev, dev->subdevices + i);
#ifdef PCL724_IRQ
if (dev->irq)
free_irq(dev->irq, dev);
#endif
release_region(dev->iobase, this_board->io_range);
}
