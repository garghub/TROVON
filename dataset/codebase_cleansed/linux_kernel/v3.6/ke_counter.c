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
static struct pci_dev *cnt_find_pci_dev(struct comedi_device *dev,
struct comedi_devconfig *it)
{
const struct cnt_board_struct *board;
struct pci_dev *pcidev = NULL;
int bus = it->options[0];
int slot = it->options[1];
int i;
for_each_pci_dev(pcidev) {
if (bus || slot) {
if (pcidev->bus->number != bus ||
PCI_SLOT(pcidev->devfn) != slot)
continue;
}
if (pcidev->vendor != PCI_VENDOR_ID_KOLTER)
continue;
for (i = 0; i < ARRAY_SIZE(cnt_boards); i++) {
board = &cnt_boards[i];
if (board->device_id != pcidev->device)
continue;
dev->board_ptr = board;
return pcidev;
}
}
dev_err(dev->class_dev,
"No supported board found! (req. bus %d, slot %d)\n",
bus, slot);
return NULL;
}
static int cnt_attach(struct comedi_device *dev, struct comedi_devconfig *it)
{
const struct cnt_board_struct *board;
struct pci_dev *pcidev;
struct comedi_subdevice *subdevice;
unsigned long io_base;
int error;
pcidev = cnt_find_pci_dev(dev, it);
if (!pcidev)
return -EIO;
comedi_set_hw_dev(dev, &pcidev->dev);
board = comedi_board(dev);
dev->board_name = board->name;
error = comedi_pci_enable(pcidev, CNT_DRIVER_NAME);
if (error < 0) {
printk(KERN_WARNING "comedi%d: "
"failed to enable PCI device and request regions!\n",
dev->minor);
return error;
}
io_base = pci_resource_start(pcidev, 0);
dev->iobase = io_base;
error = comedi_alloc_subdevices(dev, 1);
if (error)
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
static void cnt_detach(struct comedi_device *dev)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
if (pcidev) {
if (dev->iobase)
comedi_pci_disable(pcidev);
pci_dev_put(pcidev);
}
}
static int __devinit ke_counter_pci_probe(struct pci_dev *dev,
const struct pci_device_id *ent)
{
return comedi_pci_auto_config(dev, &ke_counter_driver);
}
static void __devexit ke_counter_pci_remove(struct pci_dev *dev)
{
comedi_pci_auto_unconfig(dev);
}
