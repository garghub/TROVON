static int i2c_dw_pci_suspend(struct device *dev)
{
struct pci_dev *pdev = container_of(dev, struct pci_dev, dev);
struct dw_i2c_dev *i2c = pci_get_drvdata(pdev);
int err;
i2c_dw_disable(i2c);
err = pci_save_state(pdev);
if (err) {
dev_err(&pdev->dev, "pci_save_state failed\n");
return err;
}
err = pci_set_power_state(pdev, PCI_D3hot);
if (err) {
dev_err(&pdev->dev, "pci_set_power_state failed\n");
return err;
}
return 0;
}
static int i2c_dw_pci_resume(struct device *dev)
{
struct pci_dev *pdev = container_of(dev, struct pci_dev, dev);
struct dw_i2c_dev *i2c = pci_get_drvdata(pdev);
int err;
u32 enabled;
enabled = i2c_dw_is_enabled(i2c);
if (enabled)
return 0;
err = pci_set_power_state(pdev, PCI_D0);
if (err) {
dev_err(&pdev->dev, "pci_set_power_state() failed\n");
return err;
}
pci_restore_state(pdev);
i2c_dw_init(i2c);
return 0;
}
static int i2c_dw_pci_runtime_idle(struct device *dev)
{
int err = pm_schedule_suspend(dev, 500);
dev_dbg(dev, "runtime_idle called\n");
if (err != 0)
return 0;
return -EBUSY;
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
init_completion(&dev->cmd_complete);
mutex_init(&dev->lock);
dev->clk = NULL;
dev->controller = controller;
dev->get_clk_rate_khz = i2c_dw_get_clk_rate_khz;
dev->base = pcim_iomap_table(pdev)[0];
dev->dev = &pdev->dev;
dev->functionality =
I2C_FUNC_I2C |
I2C_FUNC_SMBUS_BYTE |
I2C_FUNC_SMBUS_BYTE_DATA |
I2C_FUNC_SMBUS_WORD_DATA |
I2C_FUNC_SMBUS_I2C_BLOCK;
dev->master_cfg = controller->bus_cfg;
pci_set_drvdata(pdev, dev);
dev->tx_fifo_depth = controller->tx_fifo_depth;
dev->rx_fifo_depth = controller->rx_fifo_depth;
r = i2c_dw_init(dev);
if (r)
return r;
adap = &dev->adapter;
i2c_set_adapdata(adap, dev);
adap->owner = THIS_MODULE;
adap->class = 0;
adap->algo = &i2c_dw_algo;
adap->dev.parent = &pdev->dev;
adap->nr = controller->bus_num;
snprintf(adap->name, sizeof(adap->name), "i2c-designware-pci-%d",
adap->nr);
r = devm_request_irq(&pdev->dev, pdev->irq, i2c_dw_isr, IRQF_SHARED,
adap->name, dev);
if (r) {
dev_err(&pdev->dev, "failure requesting irq %i\n", dev->irq);
return r;
}
i2c_dw_disable_int(dev);
i2c_dw_clear_int(dev);
r = i2c_add_numbered_adapter(adap);
if (r) {
dev_err(&pdev->dev, "failure adding adapter\n");
return r;
}
pm_runtime_set_autosuspend_delay(&pdev->dev, 1000);
pm_runtime_use_autosuspend(&pdev->dev);
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
