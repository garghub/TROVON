static void bcma_pcie2_fixup_class(struct pci_dev *dev)
{
dev->class = PCI_CLASS_BRIDGE_PCI << 8;
}
static int iproc_pcie_bcma_map_irq(const struct pci_dev *dev, u8 slot, u8 pin)
{
struct pci_sys_data *sys = dev->sysdata;
struct iproc_pcie *pcie = sys->private_data;
struct bcma_device *bdev = container_of(pcie->dev, struct bcma_device, dev);
return bcma_core_irq(bdev, 5);
}
static int iproc_pcie_bcma_probe(struct bcma_device *bdev)
{
struct device *dev = &bdev->dev;
struct iproc_pcie *pcie;
LIST_HEAD(resources);
int ret;
pcie = devm_kzalloc(dev, sizeof(*pcie), GFP_KERNEL);
if (!pcie)
return -ENOMEM;
pcie->dev = dev;
pcie->type = IPROC_PCIE_PAXB_BCMA;
pcie->base = bdev->io_addr;
if (!pcie->base) {
dev_err(dev, "no controller registers\n");
return -ENOMEM;
}
pcie->base_addr = bdev->addr;
pcie->mem.start = bdev->addr_s[0];
pcie->mem.end = bdev->addr_s[0] + SZ_128M - 1;
pcie->mem.name = "PCIe MEM space";
pcie->mem.flags = IORESOURCE_MEM;
pci_add_resource(&resources, &pcie->mem);
pcie->map_irq = iproc_pcie_bcma_map_irq;
ret = iproc_pcie_setup(pcie, &resources);
if (ret) {
dev_err(dev, "PCIe controller setup failed\n");
pci_free_resource_list(&resources);
return ret;
}
bcma_set_drvdata(bdev, pcie);
return 0;
}
static void iproc_pcie_bcma_remove(struct bcma_device *bdev)
{
struct iproc_pcie *pcie = bcma_get_drvdata(bdev);
iproc_pcie_remove(pcie);
}
static int __init iproc_pcie_bcma_init(void)
{
return bcma_driver_register(&iproc_pcie_bcma_driver);
}
static void __exit iproc_pcie_bcma_exit(void)
{
bcma_driver_unregister(&iproc_pcie_bcma_driver);
}
