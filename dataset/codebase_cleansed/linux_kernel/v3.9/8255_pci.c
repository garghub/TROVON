static int pci_8255_mmio(int dir, int port, int data, unsigned long iobase)
{
void __iomem *mmio_base = (void __iomem *)iobase;
if (dir) {
writeb(data, mmio_base + port);
return 0;
} else {
return readb(mmio_base + port);
}
}
static const void *pci_8255_find_boardinfo(struct comedi_device *dev,
struct pci_dev *pcidev)
{
const struct pci_8255_boardinfo *board;
int i;
for (i = 0; i < ARRAY_SIZE(pci_8255_boards); i++) {
board = &pci_8255_boards[i];
if (pcidev->vendor == board->vendor &&
pcidev->device == board->device)
return board;
}
return NULL;
}
static int pci_8255_auto_attach(struct comedi_device *dev,
unsigned long context_unused)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
const struct pci_8255_boardinfo *board;
struct pci_8255_private *devpriv;
struct comedi_subdevice *s;
resource_size_t iobase;
unsigned long len;
int ret;
int i;
board = pci_8255_find_boardinfo(dev, pcidev);
if (!board)
return -ENODEV;
dev->board_ptr = board;
dev->board_name = board->name;
devpriv = kzalloc(sizeof(*devpriv), GFP_KERNEL);
if (!devpriv)
return -ENOMEM;
dev->private = devpriv;
ret = comedi_pci_enable(pcidev, dev->board_name);
if (ret)
return ret;
iobase = pci_resource_start(pcidev, board->dio_badr);
len = pci_resource_len(pcidev, board->dio_badr);
if (board->is_mmio) {
devpriv->mmio_base = ioremap(iobase, len);
if (!devpriv->mmio_base)
return -ENOMEM;
}
dev->iobase = iobase;
ret = comedi_alloc_subdevices(dev, board->n_8255);
if (ret)
return ret;
for (i = 0; i < board->n_8255; i++) {
s = &dev->subdevices[i];
if (board->is_mmio) {
iobase = (unsigned long)(devpriv->mmio_base + (i * 4));
ret = subdev_8255_init(dev, s, pci_8255_mmio, iobase);
} else {
iobase = dev->iobase + (i * 4);
ret = subdev_8255_init(dev, s, NULL, iobase);
}
if (ret)
return ret;
}
dev_info(dev->class_dev, "%s attached (%d digital i/o channels)\n",
dev->board_name, board->n_8255 * 24);
return 0;
}
static void pci_8255_detach(struct comedi_device *dev)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
const struct pci_8255_boardinfo *board = comedi_board(dev);
struct pci_8255_private *devpriv = dev->private;
struct comedi_subdevice *s;
int i;
if (!board || !devpriv)
return;
if (dev->subdevices) {
for (i = 0; i < board->n_8255; i++) {
s = &dev->subdevices[i];
subdev_8255_cleanup(dev, s);
}
}
if (pcidev) {
if (devpriv->mmio_base)
iounmap(devpriv->mmio_base);
if (dev->iobase)
comedi_pci_disable(pcidev);
}
}
static int pci_8255_pci_probe(struct pci_dev *dev,
const struct pci_device_id *ent)
{
return comedi_pci_auto_config(dev, &pci_8255_driver);
}
