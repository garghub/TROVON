static int i2c_dw_pci_suspend(struct device *dev)
{
struct pci_dev *pdev = to_pci_dev(dev);
i2c_dw_disable(pci_get_drvdata(pdev));
return 0;
}
static int i2c_dw_pci_resume(struct device *dev)
{
struct pci_dev *pdev = to_pci_dev(dev);
return i2c_dw_init(pci_get_drvdata(pdev));
}
static u32 i2c_dw_get_clk_rate_khz(struct dw_i2c_dev *dev)
{
return dev->controller->clk_khz;
}
static int i2c_dw_pci_probe(struct pci_dev *pdev,
const struct pci_device_id *id)
{
struct dw_i2c_dev *dev;
struct i2c_adapter *adap;
int r;
struct dw_pci_controller *controller;
struct dw_scl_sda_cfg *cfg;
if (id->driver_data >= ARRAY_SIZE(dw_pci_controllers)) {
dev_err(&pdev->dev, "%s: invalid driver data %ld\n", __func__,
id->driver_data);
return -EINVAL;
}
controller = &dw_pci_controllers[id->driver_data];
r = pcim_enable_device(pdev);
if (r) {
dev_err(&pdev->dev, "Failed to enable I2C PCI device (%d)\n",
r);
return r;
}
r = pcim_iomap_regions(pdev, 1 << 0, pci_name(pdev));
if (r) {
dev_err(&pdev->dev, "I/O memory remapping failed\n");
return r;
}
dev = devm_kzalloc(&pdev->dev, sizeof(struct dw_i2c_dev), GFP_KERNEL);
if (!dev)
return -ENOMEM;
dev->clk = NULL;
dev->controller = controller;
dev->get_clk_rate_khz = i2c_dw_get_clk_rate_khz;
dev->base = pcim_iomap_table(pdev)[0];
dev->dev = &pdev->dev;
dev->irq = pdev->irq;
dev->functionality = controller->functionality |
DW_DEFAULT_FUNCTIONALITY;
dev->master_cfg = controller->bus_cfg;
if (controller->scl_sda_cfg) {
cfg = controller->scl_sda_cfg;
dev->ss_hcnt = cfg->ss_hcnt;
dev->fs_hcnt = cfg->fs_hcnt;
dev->ss_lcnt = cfg->ss_lcnt;
dev->fs_lcnt = cfg->fs_lcnt;
dev->sda_hold_time = cfg->sda_hold;
}
pci_set_drvdata(pdev, dev);
dev->tx_fifo_depth = controller->tx_fifo_depth;
dev->rx_fifo_depth = controller->rx_fifo_depth;
adap = &dev->adapter;
adap->owner = THIS_MODULE;
adap->class = 0;
ACPI_COMPANION_SET(&adap->dev, ACPI_COMPANION(&pdev->dev));
adap->nr = controller->bus_num;
r = i2c_dw_probe(dev);
if (r)
return r;
pm_runtime_set_autosuspend_delay(&pdev->dev, 1000);
pm_runtime_use_autosuspend(&pdev->dev);
pm_runtime_put_autosuspend(&pdev->dev);
pm_runtime_allow(&pdev->dev);
return 0;
}
static void i2c_dw_pci_remove(struct pci_dev *pdev)
{
struct dw_i2c_dev *dev = pci_get_drvdata(pdev);
i2c_dw_disable(dev);
pm_runtime_forbid(&pdev->dev);
pm_runtime_get_noresume(&pdev->dev);
i2c_del_adapter(&dev->adapter);
}
