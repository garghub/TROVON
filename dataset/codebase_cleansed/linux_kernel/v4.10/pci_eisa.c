static int __init pci_eisa_init(struct pci_dev *pdev)
{
int rc, i;
struct resource *res, *bus_res = NULL;
if ((rc = pci_enable_device (pdev))) {
dev_err(&pdev->dev, "Could not enable device\n");
return rc;
}
pci_bus_for_each_resource(pdev->bus, res, i)
if (res && (res->flags & IORESOURCE_IO)) {
bus_res = res;
break;
}
if (!bus_res) {
dev_err(&pdev->dev, "No resources available\n");
return -1;
}
pci_eisa_root.dev = &pdev->dev;
pci_eisa_root.res = bus_res;
pci_eisa_root.bus_base_addr = bus_res->start;
pci_eisa_root.slots = EISA_MAX_SLOTS;
pci_eisa_root.dma_mask = pdev->dma_mask;
dev_set_drvdata(pci_eisa_root.dev, &pci_eisa_root);
if (eisa_root_register (&pci_eisa_root)) {
dev_err(&pdev->dev, "Could not register EISA root\n");
return -1;
}
return 0;
}
static int __init pci_eisa_init_early(void)
{
struct pci_dev *dev = NULL;
int ret;
for_each_pci_dev(dev)
if ((dev->class >> 8) == PCI_CLASS_BRIDGE_EISA) {
ret = pci_eisa_init(dev);
if (ret)
return ret;
}
return 0;
}
