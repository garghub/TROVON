static int intel_quark_register_i2c_clk(struct device *dev)
{
struct intel_quark_mfd *quark_mfd = dev_get_drvdata(dev);
struct clk *i2c_clk;
i2c_clk = clk_register_fixed_rate(dev,
INTEL_QUARK_I2C_CONTROLLER_CLK, NULL,
0, INTEL_QUARK_I2C_CLK_HZ);
if (IS_ERR(i2c_clk))
return PTR_ERR(i2c_clk);
quark_mfd->i2c_clk = i2c_clk;
quark_mfd->i2c_clk_lookup = clkdev_create(i2c_clk, NULL,
INTEL_QUARK_I2C_CONTROLLER_CLK);
if (!quark_mfd->i2c_clk_lookup) {
clk_unregister(quark_mfd->i2c_clk);
dev_err(dev, "Fixed clk register failed\n");
return -ENOMEM;
}
return 0;
}
static void intel_quark_unregister_i2c_clk(struct device *dev)
{
struct intel_quark_mfd *quark_mfd = dev_get_drvdata(dev);
if (!quark_mfd->i2c_clk_lookup)
return;
clkdev_drop(quark_mfd->i2c_clk_lookup);
clk_unregister(quark_mfd->i2c_clk);
}
static int intel_quark_i2c_setup(struct pci_dev *pdev, struct mfd_cell *cell)
{
const struct dmi_system_id *dmi_id;
struct dw_i2c_platform_data *pdata;
struct resource *res = (struct resource *)cell->resources;
struct device *dev = &pdev->dev;
res[INTEL_QUARK_IORES_MEM].start =
pci_resource_start(pdev, MFD_I2C_BAR);
res[INTEL_QUARK_IORES_MEM].end =
pci_resource_end(pdev, MFD_I2C_BAR);
res[INTEL_QUARK_IORES_IRQ].start = pdev->irq;
res[INTEL_QUARK_IORES_IRQ].end = pdev->irq;
pdata = devm_kzalloc(dev, sizeof(*pdata), GFP_KERNEL);
if (!pdata)
return -ENOMEM;
pdata->i2c_scl_freq = 100000;
dmi_id = dmi_first_match(dmi_platform_info);
if (dmi_id)
pdata->i2c_scl_freq = (uintptr_t)dmi_id->driver_data;
cell->platform_data = pdata;
cell->pdata_size = sizeof(*pdata);
return 0;
}
static int intel_quark_gpio_setup(struct pci_dev *pdev, struct mfd_cell *cell)
{
struct dwapb_platform_data *pdata;
struct resource *res = (struct resource *)cell->resources;
struct device *dev = &pdev->dev;
res[INTEL_QUARK_IORES_MEM].start =
pci_resource_start(pdev, MFD_GPIO_BAR);
res[INTEL_QUARK_IORES_MEM].end =
pci_resource_end(pdev, MFD_GPIO_BAR);
pdata = devm_kzalloc(dev, sizeof(*pdata), GFP_KERNEL);
if (!pdata)
return -ENOMEM;
pdata->nports = INTEL_QUARK_GPIO_NPORTS;
pdata->properties = devm_kcalloc(dev, pdata->nports,
sizeof(*pdata->properties),
GFP_KERNEL);
if (!pdata->properties)
return -ENOMEM;
pdata->properties->fwnode = NULL;
pdata->properties->idx = 0;
pdata->properties->ngpio = INTEL_QUARK_MFD_NGPIO;
pdata->properties->gpio_base = INTEL_QUARK_MFD_GPIO_BASE;
pdata->properties->irq = pdev->irq;
pdata->properties->irq_shared = true;
cell->platform_data = pdata;
cell->pdata_size = sizeof(*pdata);
return 0;
}
static int intel_quark_mfd_probe(struct pci_dev *pdev,
const struct pci_device_id *id)
{
struct intel_quark_mfd *quark_mfd;
int ret;
ret = pcim_enable_device(pdev);
if (ret)
return ret;
quark_mfd = devm_kzalloc(&pdev->dev, sizeof(*quark_mfd), GFP_KERNEL);
if (!quark_mfd)
return -ENOMEM;
quark_mfd->dev = &pdev->dev;
dev_set_drvdata(&pdev->dev, quark_mfd);
ret = intel_quark_register_i2c_clk(&pdev->dev);
if (ret)
return ret;
ret = intel_quark_i2c_setup(pdev, &intel_quark_mfd_cells[1]);
if (ret)
goto err_unregister_i2c_clk;
ret = intel_quark_gpio_setup(pdev, &intel_quark_mfd_cells[0]);
if (ret)
goto err_unregister_i2c_clk;
ret = mfd_add_devices(&pdev->dev, 0, intel_quark_mfd_cells,
ARRAY_SIZE(intel_quark_mfd_cells), NULL, 0,
NULL);
if (ret)
goto err_unregister_i2c_clk;
return 0;
err_unregister_i2c_clk:
intel_quark_unregister_i2c_clk(&pdev->dev);
return ret;
}
static void intel_quark_mfd_remove(struct pci_dev *pdev)
{
intel_quark_unregister_i2c_clk(&pdev->dev);
mfd_remove_devices(&pdev->dev);
}
