static int intel_quark_register_i2c_clk(struct intel_quark_mfd *quark_mfd)
{
struct pci_dev *pdev = quark_mfd->pdev;
struct clk_lookup *i2c_clk_lookup;
struct clk *i2c_clk;
int ret;
i2c_clk_lookup = devm_kcalloc(&pdev->dev, INTEL_QUARK_I2C_NCLK,
sizeof(*i2c_clk_lookup), GFP_KERNEL);
if (!i2c_clk_lookup)
return -ENOMEM;
i2c_clk_lookup[0].dev_id = INTEL_QUARK_I2C_CONTROLLER_CLK;
i2c_clk = clk_register_fixed_rate(&pdev->dev,
INTEL_QUARK_I2C_CONTROLLER_CLK, NULL,
CLK_IS_ROOT, INTEL_QUARK_I2C_CLK_HZ);
quark_mfd->i2c_clk_lookup = i2c_clk_lookup;
quark_mfd->i2c_clk = i2c_clk;
ret = clk_register_clkdevs(i2c_clk, i2c_clk_lookup,
INTEL_QUARK_I2C_NCLK);
if (ret)
dev_err(&pdev->dev, "Fixed clk register failed: %d\n", ret);
return ret;
}
static void intel_quark_unregister_i2c_clk(struct pci_dev *pdev)
{
struct intel_quark_mfd *quark_mfd = dev_get_drvdata(&pdev->dev);
if (!quark_mfd->i2c_clk || !quark_mfd->i2c_clk_lookup)
return;
clkdev_drop(quark_mfd->i2c_clk_lookup);
clk_unregister(quark_mfd->i2c_clk);
}
static int intel_quark_i2c_setup(struct pci_dev *pdev, struct mfd_cell *cell)
{
const char *board_name = dmi_get_system_info(DMI_BOARD_NAME);
const struct i2c_mode_info *info;
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
if (board_name) {
for (info = platform_i2c_mode_info; info->name; info++) {
if (!strcmp(board_name, info->name)) {
pdata->i2c_scl_freq = info->i2c_scl_freq;
break;
}
}
}
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
pdata->properties->node = NULL;
pdata->properties->name = "intel-quark-x1000-gpio-portA";
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
quark_mfd->pdev = pdev;
ret = intel_quark_register_i2c_clk(quark_mfd);
if (ret)
return ret;
dev_set_drvdata(&pdev->dev, quark_mfd);
ret = intel_quark_i2c_setup(pdev, &intel_quark_mfd_cells[1]);
if (ret)
return ret;
ret = intel_quark_gpio_setup(pdev, &intel_quark_mfd_cells[0]);
if (ret)
return ret;
return mfd_add_devices(&pdev->dev, 0, intel_quark_mfd_cells,
ARRAY_SIZE(intel_quark_mfd_cells), NULL, 0,
NULL);
}
static void intel_quark_mfd_remove(struct pci_dev *pdev)
{
intel_quark_unregister_i2c_clk(pdev);
mfd_remove_devices(&pdev->dev);
}
