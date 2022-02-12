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
static int pci_8255_auto_attach(struct comedi_device *dev,
unsigned long context)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
const struct pci_8255_boardinfo *board = NULL;
struct pci_8255_private *devpriv;
struct comedi_subdevice *s;
bool is_mmio;
int ret;
int i;
if (context < ARRAY_SIZE(pci_8255_boards))
board = &pci_8255_boards[context];
if (!board)
return -ENODEV;
dev->board_ptr = board;
dev->board_name = board->name;
devpriv = comedi_alloc_devpriv(dev, sizeof(*devpriv));
if (!devpriv)
return -ENOMEM;
ret = comedi_pci_enable(dev);
if (ret)
return ret;
is_mmio = (pci_resource_flags(pcidev, board->dio_badr) &
IORESOURCE_MEM) != 0;
if (is_mmio) {
devpriv->mmio_base = pci_ioremap_bar(pcidev, board->dio_badr);
if (!devpriv->mmio_base)
return -ENOMEM;
} else {
dev->iobase = pci_resource_start(pcidev, board->dio_badr);
}
ret = comedi_alloc_subdevices(dev, board->n_8255);
if (ret)
return ret;
for (i = 0; i < board->n_8255; i++) {
unsigned long iobase;
s = &dev->subdevices[i];
if (is_mmio) {
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
struct pci_8255_private *devpriv = dev->private;
if (devpriv && devpriv->mmio_base)
iounmap(devpriv->mmio_base);
comedi_pci_disable(dev);
}
static int pci_8255_pci_probe(struct pci_dev *dev,
const struct pci_device_id *id)
{
return comedi_pci_auto_config(dev, &pci_8255_driver, id->driver_data);
}
