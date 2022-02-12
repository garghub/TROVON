static int sp_get_msix_irqs(struct sp_device *sp)
{
struct sp_pci *sp_pci = sp->dev_specific;
struct device *dev = sp->dev;
struct pci_dev *pdev = to_pci_dev(dev);
int v, ret;
for (v = 0; v < ARRAY_SIZE(sp_pci->msix_entry); v++)
sp_pci->msix_entry[v].entry = v;
ret = pci_enable_msix_range(pdev, sp_pci->msix_entry, 1, v);
if (ret < 0)
return ret;
sp_pci->msix_count = ret;
sp->use_tasklet = true;
sp->psp_irq = sp_pci->msix_entry[0].vector;
sp->ccp_irq = (sp_pci->msix_count > 1) ? sp_pci->msix_entry[1].vector
: sp_pci->msix_entry[0].vector;
return 0;
}
static int sp_get_msi_irq(struct sp_device *sp)
{
struct device *dev = sp->dev;
struct pci_dev *pdev = to_pci_dev(dev);
int ret;
ret = pci_enable_msi(pdev);
if (ret)
return ret;
sp->ccp_irq = pdev->irq;
sp->psp_irq = pdev->irq;
return 0;
}
static int sp_get_irqs(struct sp_device *sp)
{
struct device *dev = sp->dev;
int ret;
ret = sp_get_msix_irqs(sp);
if (!ret)
return 0;
dev_notice(dev, "could not enable MSI-X (%d), trying MSI\n", ret);
ret = sp_get_msi_irq(sp);
if (!ret)
return 0;
dev_notice(dev, "could not enable MSI (%d)\n", ret);
return ret;
}
static void sp_free_irqs(struct sp_device *sp)
{
struct sp_pci *sp_pci = sp->dev_specific;
struct device *dev = sp->dev;
struct pci_dev *pdev = to_pci_dev(dev);
if (sp_pci->msix_count)
pci_disable_msix(pdev);
else if (sp->psp_irq)
pci_disable_msi(pdev);
sp->ccp_irq = 0;
sp->psp_irq = 0;
}
static int sp_pci_probe(struct pci_dev *pdev, const struct pci_device_id *id)
{
struct sp_device *sp;
struct sp_pci *sp_pci;
struct device *dev = &pdev->dev;
void __iomem * const *iomap_table;
int bar_mask;
int ret;
ret = -ENOMEM;
sp = sp_alloc_struct(dev);
if (!sp)
goto e_err;
sp_pci = devm_kzalloc(dev, sizeof(*sp_pci), GFP_KERNEL);
if (!sp_pci)
goto e_err;
sp->dev_specific = sp_pci;
sp->dev_vdata = (struct sp_dev_vdata *)id->driver_data;
if (!sp->dev_vdata) {
ret = -ENODEV;
dev_err(dev, "missing driver data\n");
goto e_err;
}
ret = pcim_enable_device(pdev);
if (ret) {
dev_err(dev, "pcim_enable_device failed (%d)\n", ret);
goto e_err;
}
bar_mask = pci_select_bars(pdev, IORESOURCE_MEM);
ret = pcim_iomap_regions(pdev, bar_mask, "ccp");
if (ret) {
dev_err(dev, "pcim_iomap_regions failed (%d)\n", ret);
goto e_err;
}
iomap_table = pcim_iomap_table(pdev);
if (!iomap_table) {
dev_err(dev, "pcim_iomap_table failed\n");
ret = -ENOMEM;
goto e_err;
}
sp->io_map = iomap_table[sp->dev_vdata->bar];
if (!sp->io_map) {
dev_err(dev, "ioremap failed\n");
ret = -ENOMEM;
goto e_err;
}
ret = sp_get_irqs(sp);
if (ret)
goto e_err;
pci_set_master(pdev);
ret = dma_set_mask_and_coherent(dev, DMA_BIT_MASK(48));
if (ret) {
ret = dma_set_mask_and_coherent(dev, DMA_BIT_MASK(32));
if (ret) {
dev_err(dev, "dma_set_mask_and_coherent failed (%d)\n",
ret);
goto e_err;
}
}
dev_set_drvdata(dev, sp);
ret = sp_init(sp);
if (ret)
goto e_err;
dev_notice(dev, "enabled\n");
return 0;
e_err:
dev_notice(dev, "initialization failed\n");
return ret;
}
static void sp_pci_remove(struct pci_dev *pdev)
{
struct device *dev = &pdev->dev;
struct sp_device *sp = dev_get_drvdata(dev);
if (!sp)
return;
sp_destroy(sp);
sp_free_irqs(sp);
dev_notice(dev, "disabled\n");
}
static int sp_pci_suspend(struct pci_dev *pdev, pm_message_t state)
{
struct device *dev = &pdev->dev;
struct sp_device *sp = dev_get_drvdata(dev);
return sp_suspend(sp, state);
}
static int sp_pci_resume(struct pci_dev *pdev)
{
struct device *dev = &pdev->dev;
struct sp_device *sp = dev_get_drvdata(dev);
return sp_resume(sp);
}
int sp_pci_init(void)
{
return pci_register_driver(&sp_pci_driver);
}
void sp_pci_exit(void)
{
pci_unregister_driver(&sp_pci_driver);
}
