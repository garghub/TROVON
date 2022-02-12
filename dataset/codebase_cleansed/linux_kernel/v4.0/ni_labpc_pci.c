static int labpc_pci_mite_init(struct pci_dev *pcidev)
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
static int labpc_pci_auto_attach(struct comedi_device *dev,
unsigned long context)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
const struct labpc_boardinfo *board = NULL;
int ret;
if (context < ARRAY_SIZE(labpc_pci_boards))
board = &labpc_pci_boards[context];
if (!board)
return -ENODEV;
dev->board_ptr = board;
dev->board_name = board->name;
ret = comedi_pci_enable(dev);
if (ret)
return ret;
ret = labpc_pci_mite_init(pcidev);
if (ret)
return ret;
dev->mmio = pci_ioremap_bar(pcidev, 1);
if (!dev->mmio)
return -ENOMEM;
return labpc_common_attach(dev, pcidev->irq, IRQF_SHARED);
}
static int labpc_pci_probe(struct pci_dev *dev,
const struct pci_device_id *id)
{
return comedi_pci_auto_config(dev, &labpc_pci_comedi_driver,
id->driver_data);
}
