static void ddb_irq_disable(struct ddb *dev)
{
ddbwritel(dev, 0, INTERRUPT_ENABLE);
ddbwritel(dev, 0, MSI1_ENABLE);
}
static void ddb_irq_exit(struct ddb *dev)
{
ddb_irq_disable(dev);
if (dev->msi == 2)
free_irq(dev->pdev->irq + 1, dev);
free_irq(dev->pdev->irq, dev);
#ifdef CONFIG_PCI_MSI
if (dev->msi)
pci_disable_msi(dev->pdev);
#endif
}
static void ddb_remove(struct pci_dev *pdev)
{
struct ddb *dev = (struct ddb *) pci_get_drvdata(pdev);
ddb_device_destroy(dev);
ddb_ports_detach(dev);
ddb_i2c_release(dev);
ddb_irq_exit(dev);
ddb_ports_release(dev);
ddb_buffers_free(dev);
ddb_unmap(dev);
pci_set_drvdata(pdev, NULL);
pci_disable_device(pdev);
}
static void ddb_irq_msi(struct ddb *dev, int nr)
{
int stat;
if (msi && pci_msi_enabled()) {
stat = pci_alloc_irq_vectors(dev->pdev, 1, nr, PCI_IRQ_MSI);
if (stat >= 1) {
dev->msi = stat;
dev_info(dev->dev, "using %d MSI interrupt(s)\n",
dev->msi);
} else
dev_info(dev->dev, "MSI not available.\n");
}
}
static int ddb_irq_init(struct ddb *dev)
{
int stat;
int irq_flag = IRQF_SHARED;
ddbwritel(dev, 0x00000000, INTERRUPT_ENABLE);
ddbwritel(dev, 0x00000000, MSI1_ENABLE);
ddbwritel(dev, 0x00000000, MSI2_ENABLE);
ddbwritel(dev, 0x00000000, MSI3_ENABLE);
ddbwritel(dev, 0x00000000, MSI4_ENABLE);
ddbwritel(dev, 0x00000000, MSI5_ENABLE);
ddbwritel(dev, 0x00000000, MSI6_ENABLE);
ddbwritel(dev, 0x00000000, MSI7_ENABLE);
#ifdef CONFIG_PCI_MSI
ddb_irq_msi(dev, 2);
if (dev->msi)
irq_flag = 0;
if (dev->msi == 2) {
stat = request_irq(dev->pdev->irq, ddb_irq_handler0,
irq_flag, "ddbridge", (void *) dev);
if (stat < 0)
return stat;
stat = request_irq(dev->pdev->irq + 1, ddb_irq_handler1,
irq_flag, "ddbridge", (void *) dev);
if (stat < 0) {
free_irq(dev->pdev->irq, dev);
return stat;
}
} else
#endif
{
stat = request_irq(dev->pdev->irq, ddb_irq_handler,
irq_flag, "ddbridge", (void *) dev);
if (stat < 0)
return stat;
}
if (dev->msi == 2) {
ddbwritel(dev, 0x0fffff00, INTERRUPT_ENABLE);
ddbwritel(dev, 0x0000000f, MSI1_ENABLE);
} else {
ddbwritel(dev, 0x0fffff0f, INTERRUPT_ENABLE);
ddbwritel(dev, 0x00000000, MSI1_ENABLE);
}
return stat;
}
static int ddb_probe(struct pci_dev *pdev,
const struct pci_device_id *id)
{
struct ddb *dev;
int stat = 0;
if (pci_enable_device(pdev) < 0)
return -ENODEV;
pci_set_master(pdev);
if (pci_set_dma_mask(pdev, DMA_BIT_MASK(64)))
if (pci_set_dma_mask(pdev, DMA_BIT_MASK(32)))
return -ENODEV;
dev = vzalloc(sizeof(struct ddb));
if (dev == NULL)
return -ENOMEM;
mutex_init(&dev->mutex);
dev->has_dma = 1;
dev->pdev = pdev;
dev->dev = &pdev->dev;
pci_set_drvdata(pdev, dev);
dev->link[0].ids.vendor = id->vendor;
dev->link[0].ids.device = id->device;
dev->link[0].ids.subvendor = id->subvendor;
dev->link[0].ids.subdevice = pdev->subsystem_device;
dev->link[0].dev = dev;
dev->link[0].info = get_ddb_info(id->vendor, id->device,
id->subvendor, pdev->subsystem_device);
dev_info(&pdev->dev, "detected %s\n", dev->link[0].info->name);
dev->regs_len = pci_resource_len(dev->pdev, 0);
dev->regs = ioremap(pci_resource_start(dev->pdev, 0),
pci_resource_len(dev->pdev, 0));
if (!dev->regs) {
dev_err(&pdev->dev, "not enough memory for register map\n");
stat = -ENOMEM;
goto fail;
}
if (ddbreadl(dev, 0) == 0xffffffff) {
dev_err(&pdev->dev, "cannot read registers\n");
stat = -ENODEV;
goto fail;
}
dev->link[0].ids.hwid = ddbreadl(dev, 0);
dev->link[0].ids.regmapid = ddbreadl(dev, 4);
dev_info(&pdev->dev, "HW %08x REGMAP %08x\n",
dev->link[0].ids.hwid, dev->link[0].ids.regmapid);
ddbwritel(dev, 0, DMA_BASE_READ);
ddbwritel(dev, 0, DMA_BASE_WRITE);
stat = ddb_irq_init(dev);
if (stat < 0)
goto fail0;
if (ddb_init(dev) == 0)
return 0;
ddb_irq_exit(dev);
fail0:
dev_err(&pdev->dev, "fail0\n");
if (dev->msi)
pci_disable_msi(dev->pdev);
fail:
dev_err(&pdev->dev, "fail\n");
ddb_unmap(dev);
pci_set_drvdata(pdev, NULL);
pci_disable_device(pdev);
return -1;
}
static __init int module_init_ddbridge(void)
{
int stat = -1;
pr_info("Digital Devices PCIE bridge driver "
DDBRIDGE_VERSION
", Copyright (C) 2010-17 Digital Devices GmbH\n");
if (ddb_class_create() < 0)
return -1;
ddb_wq = create_workqueue("ddbridge");
if (ddb_wq == NULL)
goto exit1;
stat = pci_register_driver(&ddb_pci_driver);
if (stat < 0)
goto exit2;
return stat;
exit2:
destroy_workqueue(ddb_wq);
exit1:
ddb_class_destroy();
return stat;
}
static __exit void module_exit_ddbridge(void)
{
pci_unregister_driver(&ddb_pci_driver);
destroy_workqueue(ddb_wq);
ddb_class_destroy();
}
