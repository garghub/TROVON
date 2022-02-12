static int pcmda12_attach(struct comedi_device *dev,
struct comedi_devconfig *it)
{
struct comedi_subdevice *s;
unsigned long iobase;
iobase = it->options[0];
printk(KERN_INFO
"comedi%d: %s: io: %lx %s ", dev->minor, driver.driver_name,
iobase, it->options[1] ? "simultaneous xfer mode enabled" : "");
if (!request_region(iobase, IOSIZE, driver.driver_name)) {
printk("I/O port conflict\n");
return -EIO;
}
dev->iobase = iobase;
dev->board_name = thisboard->name;
if (alloc_private(dev, sizeof(struct pcmda12_private)) < 0) {
printk(KERN_ERR "cannot allocate private data structure\n");
return -ENOMEM;
}
devpriv->simultaneous_xfer_mode = it->options[1];
if (alloc_subdevices(dev, 1) < 0) {
printk(KERN_ERR "cannot allocate subdevice data structures\n");
return -ENOMEM;
}
s = dev->subdevices;
s->private = NULL;
s->maxdata = (0x1 << BITS) - 1;
s->range_table = &pcmda12_ranges;
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE;
s->n_chan = CHANS;
s->insn_write = &ao_winsn;
s->insn_read = &ao_rinsn;
zero_chans(dev);
printk(KERN_INFO "attached\n");
return 1;
}
static int pcmda12_detach(struct comedi_device *dev)
{
printk(KERN_INFO
"comedi%d: %s: remove\n", dev->minor, driver.driver_name);
if (dev->iobase)
release_region(dev->iobase, IOSIZE);
return 0;
}
static void zero_chans(struct comedi_device *dev)
{
int i;
for (i = 0; i < CHANS; ++i) {
outb(0, LSB_PORT(i));
outb(0, MSB_PORT(i));
}
inb(LSB_PORT(0));
}
static int ao_winsn(struct comedi_device *dev, struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
int i;
int chan = CR_CHAN(insn->chanspec);
for (i = 0; i < insn->n; ++i) {
outb(LSB(data[i]), LSB_PORT(chan));
outb(MSB(data[i]), MSB_PORT(chan));
devpriv->ao_readback[chan] = data[i];
if (!devpriv->simultaneous_xfer_mode)
inb(LSB_PORT(chan));
}
return i;
}
static int ao_rinsn(struct comedi_device *dev, struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
int i;
int chan = CR_CHAN(insn->chanspec);
for (i = 0; i < insn->n; i++) {
if (devpriv->simultaneous_xfer_mode)
inb(LSB_PORT(chan));
data[i] = devpriv->ao_readback[chan];
}
return i;
}
static int __init driver_init_module(void)
{
return comedi_driver_register(&driver);
}
static void __exit driver_cleanup_module(void)
{
comedi_driver_unregister(&driver);
}
