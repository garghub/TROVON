static int __init driver_rti802_init_module(void)
{
return comedi_driver_register(&driver_rti802);
}
static void __exit driver_rti802_cleanup_module(void)
{
comedi_driver_unregister(&driver_rti802);
}
static int rti802_ao_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
int i;
for (i = 0; i < insn->n; i++)
data[i] = devpriv->ao_readback[CR_CHAN(insn->chanspec)];
return i;
}
static int rti802_ao_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
int i, d;
int chan = CR_CHAN(insn->chanspec);
for (i = 0; i < insn->n; i++) {
d = devpriv->ao_readback[chan] = data[i];
if (devpriv->dac_coding[chan] == dac_2comp)
d ^= 0x800;
outb(chan, dev->iobase + RTI802_SELECT);
outb(d & 0xff, dev->iobase + RTI802_DATALOW);
outb(d >> 8, dev->iobase + RTI802_DATAHIGH);
}
return i;
}
static int rti802_attach(struct comedi_device *dev, struct comedi_devconfig *it)
{
struct comedi_subdevice *s;
int i;
unsigned long iobase;
iobase = it->options[0];
printk(KERN_INFO "comedi%d: rti802: 0x%04lx ", dev->minor, iobase);
if (!request_region(iobase, RTI802_SIZE, "rti802")) {
printk(KERN_WARNING "I/O port conflict\n");
return -EIO;
}
dev->iobase = iobase;
dev->board_name = "rti802";
if (alloc_subdevices(dev, 1) < 0
|| alloc_private(dev, sizeof(struct rti802_private))) {
return -ENOMEM;
}
s = dev->subdevices;
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITABLE;
s->maxdata = 0xfff;
s->n_chan = 8;
s->insn_read = rti802_ao_insn_read;
s->insn_write = rti802_ao_insn_write;
s->range_table_list = devpriv->range_type_list;
for (i = 0; i < 8; i++) {
devpriv->dac_coding[i] = (it->options[3 + 2 * i])
? (dac_straight)
: (dac_2comp);
devpriv->range_type_list[i] = (it->options[2 + 2 * i])
? &range_unipolar10 : &range_bipolar10;
}
return 0;
}
static int rti802_detach(struct comedi_device *dev)
{
printk(KERN_INFO "comedi%d: rti802: remove\n", dev->minor);
if (dev->iobase)
release_region(dev->iobase, RTI802_SIZE);
return 0;
}
