static int pci_8255_mite_init(struct pci_dev *pcidev)
{
void __iomem *mite_base;
u32 main_phys_addr;
mite_base = pci_ioremap_bar(pcidev, 0);
if (!mite_base)
return -ENOMEM;
main_phys_addr = pci_resource_start(pcidev, 1);
writel(main_phys_addr | WENAB, mite_base + MITE_IODWBSR);
iounmap(mite_base);
return 0;
}
static int pci_8255_mmio(int dir, int port, int data, unsigned long iobase)
{
void __iomem *mmio_base = (void __iomem *)iobase;
if (dir) {
writeb(data, mmio_base + port);
return 0;
}
return readb(mmio_base + port);
}
static int pci_8255_auto_attach(struct comedi_device *dev,
unsigned long context)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
const struct pci_8255_boardinfo *board = NULL;
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
ret = comedi_pci_enable(dev);
if (ret)
return ret;
if (board->has_mite) {
ret = pci_8255_mite_init(pcidev);
if (ret)
return ret;
}
is_mmio = (pci_resource_flags(pcidev, board->dio_badr) &
IORESOURCE_MEM) != 0;
if (is_mmio) {
dev->mmio = pci_ioremap_bar(pcidev, board->dio_badr);
if (!dev->mmio)
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
iobase = (unsigned long)(dev->mmio + (i * 4));
ret = subdev_8255_init(dev, s, pci_8255_mmio, iobase);
} else {
iobase = dev->iobase + (i * 4);
ret = subdev_8255_init(dev, s, NULL, iobase);
}
if (ret)
return ret;
}
return 0;
}
static void pci_8255_detach(struct comedi_device *dev)
{
if (dev->mmio)
iounmap(dev->mmio);
comedi_pci_disable(dev);
}
static int pci_8255_pci_probe(struct pci_dev *dev,
const struct pci_device_id *id)
{
return comedi_pci_auto_config(dev, &pci_8255_driver, id->driver_data);
}
