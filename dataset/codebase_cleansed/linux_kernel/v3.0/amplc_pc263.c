static int
pc263_find_pci(struct comedi_device *dev, int bus, int slot,
struct pci_dev **pci_dev_p)
{
struct pci_dev *pci_dev = NULL;
*pci_dev_p = NULL;
for (pci_dev = pci_get_device(PCI_VENDOR_ID_AMPLICON, PCI_ANY_ID, NULL);
pci_dev != NULL;
pci_dev = pci_get_device(PCI_VENDOR_ID_AMPLICON,
PCI_ANY_ID, pci_dev)) {
if (bus || slot) {
if (bus != pci_dev->bus->number
|| slot != PCI_SLOT(pci_dev->devfn))
continue;
}
if (thisboard->model == anypci_model) {
int i;
for (i = 0; i < ARRAY_SIZE(pc263_boards); i++) {
if (pc263_boards[i].bustype != pci_bustype)
continue;
if (pci_dev->device == pc263_boards[i].devid) {
dev->board_ptr = &pc263_boards[i];
break;
}
}
if (i == ARRAY_SIZE(pc263_boards))
continue;
} else {
if (pci_dev->device != thisboard->devid)
continue;
}
*pci_dev_p = pci_dev;
return 0;
}
if (bus || slot) {
printk(KERN_ERR
"comedi%d: error! no %s found at pci %02x:%02x!\n",
dev->minor, thisboard->name, bus, slot);
} else {
printk(KERN_ERR "comedi%d: error! no %s found!\n",
dev->minor, thisboard->name);
}
return -EIO;
}
static int pc263_attach(struct comedi_device *dev, struct comedi_devconfig *it)
{
struct comedi_subdevice *s;
unsigned long iobase = 0;
#ifdef CONFIG_COMEDI_PCI
struct pci_dev *pci_dev = NULL;
int bus = 0, slot = 0;
#endif
int ret;
printk(KERN_DEBUG "comedi%d: %s: attach\n", dev->minor,
PC263_DRIVER_NAME);
#ifdef CONFIG_COMEDI_PCI
ret = alloc_private(dev, sizeof(struct pc263_private));
if (ret < 0) {
printk(KERN_ERR "comedi%d: error! out of memory!\n",
dev->minor);
return ret;
}
#endif
switch (thisboard->bustype) {
case isa_bustype:
iobase = it->options[0];
break;
#ifdef CONFIG_COMEDI_PCI
case pci_bustype:
bus = it->options[0];
slot = it->options[1];
ret = pc263_find_pci(dev, bus, slot, &pci_dev);
if (ret < 0)
return ret;
devpriv->pci_dev = pci_dev;
break;
#endif
default:
printk(KERN_ERR
"comedi%d: %s: BUG! cannot determine board type!\n",
dev->minor, PC263_DRIVER_NAME);
return -EINVAL;
break;
}
dev->board_name = thisboard->name;
#ifdef CONFIG_COMEDI_PCI
if (pci_dev) {
ret = comedi_pci_enable(pci_dev, PC263_DRIVER_NAME);
if (ret < 0) {
printk(KERN_ERR
"comedi%d: error! cannot enable PCI device and "
"request regions!\n",
dev->minor);
return ret;
}
iobase = pci_resource_start(pci_dev, 2);
} else
#endif
{
ret = pc263_request_region(dev->minor, iobase, PC263_IO_SIZE);
if (ret < 0)
return ret;
}
dev->iobase = iobase;
ret = alloc_subdevices(dev, 1);
if (ret < 0) {
printk(KERN_ERR "comedi%d: error! out of memory!\n",
dev->minor);
return ret;
}
s = dev->subdevices + 0;
s->type = COMEDI_SUBD_DIO;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE;
s->n_chan = 16;
s->maxdata = 1;
s->range_table = &range_digital;
s->insn_bits = pc263_dio_insn_bits;
s->insn_config = pc263_dio_insn_config;
s->io_bits = 0xffff;
s->state = inb(dev->iobase);
s->state = s->state | (inb(dev->iobase) << 8);
printk(KERN_INFO "comedi%d: %s ", dev->minor, dev->board_name);
if (thisboard->bustype == isa_bustype) {
printk("(base %#lx) ", iobase);
} else {
#ifdef CONFIG_COMEDI_PCI
printk("(pci %s) ", pci_name(pci_dev));
#endif
}
printk("attached\n");
return 1;
}
static int pc263_detach(struct comedi_device *dev)
{
printk(KERN_DEBUG "comedi%d: %s: detach\n", dev->minor,
PC263_DRIVER_NAME);
#ifdef CONFIG_COMEDI_PCI
if (devpriv) {
#endif
#ifdef CONFIG_COMEDI_PCI
if (devpriv->pci_dev) {
if (dev->iobase)
comedi_pci_disable(devpriv->pci_dev);
pci_dev_put(devpriv->pci_dev);
} else
#endif
{
if (dev->iobase)
release_region(dev->iobase, PC263_IO_SIZE);
}
}
if (dev->board_name) {
printk(KERN_INFO "comedi%d: %s removed\n",
dev->minor, dev->board_name);
}
return 0;
}
static int pc263_request_region(unsigned minor, unsigned long from,
unsigned long extent)
{
if (!from || !request_region(from, extent, PC263_DRIVER_NAME)) {
printk(KERN_ERR "comedi%d: I/O port conflict (%#lx,%lu)!\n",
minor, from, extent);
return -EIO;
}
return 0;
}
static int pc263_dio_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
if (insn->n != 2)
return -EINVAL;
if (data[0]) {
s->state &= ~data[0];
s->state |= data[0] & data[1];
outb(s->state & 0xFF, dev->iobase);
outb(s->state >> 8, dev->iobase + 1);
}
data[1] = s->state;
return 2;
}
static int pc263_dio_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
if (insn->n != 1)
return -EINVAL;
return 1;
}
static int __devinit driver_amplc_pc263_pci_probe(struct pci_dev *dev,
const struct pci_device_id
*ent)
{
return comedi_pci_auto_config(dev, driver_amplc_pc263.driver_name);
}
static void __devexit driver_amplc_pc263_pci_remove(struct pci_dev *dev)
{
comedi_pci_auto_unconfig(dev);
}
static int __init driver_amplc_pc263_init_module(void)
{
int retval;
retval = comedi_driver_register(&driver_amplc_pc263);
if (retval < 0)
return retval;
driver_amplc_pc263_pci_driver.name =
(char *)driver_amplc_pc263.driver_name;
return pci_register_driver(&driver_amplc_pc263_pci_driver);
}
static void __exit driver_amplc_pc263_cleanup_module(void)
{
pci_unregister_driver(&driver_amplc_pc263_pci_driver);
comedi_driver_unregister(&driver_amplc_pc263);
}
static int __init driver_amplc_pc263_init_module(void)
{
return comedi_driver_register(&driver_amplc_pc263);
}
static void __exit driver_amplc_pc263_cleanup_module(void)
{
comedi_driver_unregister(&driver_amplc_pc263);
}
