static int __devinit cnt_driver_pci_probe(struct pci_dev *dev,
const struct pci_device_id *ent)
{
return comedi_pci_auto_config(dev, cnt_driver.driver_name);
}
static void __devexit cnt_driver_pci_remove(struct pci_dev *dev)
{
comedi_pci_auto_unconfig(dev);
}
static int __init cnt_driver_init_module(void)
{
int retval;
retval = comedi_driver_register(&cnt_driver);
if (retval < 0)
return retval;
cnt_driver_pci_driver.name = (char *)cnt_driver.driver_name;
return pci_register_driver(&cnt_driver_pci_driver);
}
static void __exit cnt_driver_cleanup_module(void)
{
pci_unregister_driver(&cnt_driver_pci_driver);
comedi_driver_unregister(&cnt_driver);
}
static int cnt_winsn(struct comedi_device *dev,
struct comedi_subdevice *s, struct comedi_insn *insn,
unsigned int *data)
{
int chan = CR_CHAN(insn->chanspec);
outb((unsigned char)((data[0] >> 24) & 0xff),
dev->iobase + chan * 0x20 + 0x10);
outb((unsigned char)((data[0] >> 16) & 0xff),
dev->iobase + chan * 0x20 + 0x0c);
outb((unsigned char)((data[0] >> 8) & 0xff),
dev->iobase + chan * 0x20 + 0x08);
outb((unsigned char)((data[0] >> 0) & 0xff),
dev->iobase + chan * 0x20 + 0x04);
return 1;
}
static int cnt_rinsn(struct comedi_device *dev,
struct comedi_subdevice *s, struct comedi_insn *insn,
unsigned int *data)
{
unsigned char a0, a1, a2, a3, a4;
int chan = CR_CHAN(insn->chanspec);
int result;
a0 = inb(dev->iobase + chan * 0x20);
a1 = inb(dev->iobase + chan * 0x20 + 0x04);
a2 = inb(dev->iobase + chan * 0x20 + 0x08);
a3 = inb(dev->iobase + chan * 0x20 + 0x0c);
a4 = inb(dev->iobase + chan * 0x20 + 0x10);
result = (a1 + (a2 * 256) + (a3 * 65536));
if (a4 > 0)
result = result - s->maxdata;
*data = (unsigned int)result;
return 1;
}
static int cnt_attach(struct comedi_device *dev, struct comedi_devconfig *it)
{
struct comedi_subdevice *subdevice;
struct pci_dev *pci_device = NULL;
struct cnt_board_struct *board;
unsigned long io_base;
int error, i;
error = alloc_private(dev, sizeof(struct cnt_device_private));
if (error < 0)
return error;
for_each_pci_dev(pci_device) {
if (pci_device->vendor == PCI_VENDOR_ID_KOLTER) {
for (i = 0; i < cnt_board_nbr; i++) {
if (cnt_boards[i].device_id ==
pci_device->device) {
if ((it->options[0] != 0)
|| (it->options[1] != 0)) {
if (pci_device->bus->number !=
it->options[0]
||
PCI_SLOT(pci_device->devfn)
!= it->options[1]) {
continue;
}
}
dev->board_ptr = cnt_boards + i;
board =
(struct cnt_board_struct *)
dev->board_ptr;
goto found;
}
}
}
}
printk(KERN_WARNING
"comedi%d: no supported board found! (req. bus/slot: %d/%d)\n",
dev->minor, it->options[0], it->options[1]);
return -EIO;
found:
printk(KERN_INFO
"comedi%d: found %s at PCI bus %d, slot %d\n", dev->minor,
board->name, pci_device->bus->number,
PCI_SLOT(pci_device->devfn));
devpriv->pcidev = pci_device;
dev->board_name = board->name;
error = comedi_pci_enable(pci_device, CNT_DRIVER_NAME);
if (error < 0) {
printk(KERN_WARNING "comedi%d: "
"failed to enable PCI device and request regions!\n",
dev->minor);
return error;
}
io_base = pci_resource_start(pci_device, 0);
dev->iobase = io_base;
error = alloc_subdevices(dev, 1);
if (error < 0)
return error;
subdevice = dev->subdevices + 0;
dev->read_subdev = subdevice;
subdevice->type = COMEDI_SUBD_COUNTER;
subdevice->subdev_flags = SDF_READABLE ;
subdevice->n_chan = board->cnt_channel_nbr;
subdevice->maxdata = (1 << board->cnt_bits) - 1;
subdevice->insn_read = cnt_rinsn;
subdevice->insn_write = cnt_winsn;
outb(3, dev->iobase + 248);
outb(0, dev->iobase);
outb(0, dev->iobase + 0x20);
outb(0, dev->iobase + 0x40);
printk(KERN_INFO "comedi%d: " CNT_DRIVER_NAME " attached.\n",
dev->minor);
return 0;
}
static int cnt_detach(struct comedi_device *dev)
{
if (devpriv && devpriv->pcidev) {
if (dev->iobase)
comedi_pci_disable(devpriv->pcidev);
pci_dev_put(devpriv->pcidev);
}
printk(KERN_INFO "comedi%d: " CNT_DRIVER_NAME " remove\n",
dev->minor);
return 0;
}
