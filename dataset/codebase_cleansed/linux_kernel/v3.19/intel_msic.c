int intel_msic_reg_read(unsigned short reg, u8 *val)
{
return intel_scu_ipc_ioread8(reg, val);
}
int intel_msic_reg_write(unsigned short reg, u8 val)
{
return intel_scu_ipc_iowrite8(reg, val);
}
int intel_msic_reg_update(unsigned short reg, u8 val, u8 mask)
{
return intel_scu_ipc_update_register(reg, val, mask);
}
int intel_msic_bulk_read(unsigned short *reg, u8 *buf, size_t count)
{
if (WARN_ON(count > SCU_IPC_RWBUF_LIMIT))
return -EINVAL;
return intel_scu_ipc_readv(reg, buf, count);
}
int intel_msic_bulk_write(unsigned short *reg, u8 *buf, size_t count)
{
if (WARN_ON(count > SCU_IPC_RWBUF_LIMIT))
return -EINVAL;
return intel_scu_ipc_writev(reg, buf, count);
}
int intel_msic_irq_read(struct intel_msic *msic, unsigned short reg, u8 *val)
{
if (WARN_ON(reg < INTEL_MSIC_IRQLVL1 || reg > INTEL_MSIC_RESETIRQ2))
return -EINVAL;
*val = readb(msic->irq_base + (reg - INTEL_MSIC_IRQLVL1));
return 0;
}
static int intel_msic_init_devices(struct intel_msic *msic)
{
struct platform_device *pdev = msic->pdev;
struct intel_msic_platform_data *pdata = dev_get_platdata(&pdev->dev);
int ret, i;
if (pdata->gpio) {
struct mfd_cell *cell = &msic_devs[INTEL_MSIC_BLOCK_GPIO];
cell->platform_data = pdata->gpio;
cell->pdata_size = sizeof(*pdata->gpio);
}
if (pdata->ocd) {
unsigned gpio = pdata->ocd->gpio;
ret = devm_gpio_request_one(&pdev->dev, gpio,
GPIOF_IN, "ocd_gpio");
if (ret) {
dev_err(&pdev->dev, "failed to register OCD GPIO\n");
return ret;
}
ret = gpio_to_irq(gpio);
if (ret < 0) {
dev_err(&pdev->dev, "no IRQ number for OCD GPIO\n");
return ret;
}
pdata->irq[INTEL_MSIC_BLOCK_OCD] = ret;
}
for (i = 0; i < ARRAY_SIZE(msic_devs); i++) {
if (!pdata->irq[i])
continue;
ret = mfd_add_devices(&pdev->dev, -1, &msic_devs[i], 1, NULL,
pdata->irq[i], NULL);
if (ret)
goto fail;
}
ret = mfd_add_devices(&pdev->dev, 0, msic_other_devs,
ARRAY_SIZE(msic_other_devs), NULL, 0, NULL);
if (ret)
goto fail;
return 0;
fail:
mfd_remove_devices(&pdev->dev);
return ret;
}
static void intel_msic_remove_devices(struct intel_msic *msic)
{
struct platform_device *pdev = msic->pdev;
mfd_remove_devices(&pdev->dev);
}
static int intel_msic_probe(struct platform_device *pdev)
{
struct intel_msic_platform_data *pdata = dev_get_platdata(&pdev->dev);
struct intel_msic *msic;
struct resource *res;
u8 id0, id1;
int ret;
if (!pdata) {
dev_err(&pdev->dev, "no platform data passed\n");
return -EINVAL;
}
ret = intel_scu_ipc_ioread8(INTEL_MSIC_ID0, &id0);
if (ret) {
dev_err(&pdev->dev, "failed to identify the MSIC chip (ID0)\n");
return -ENXIO;
}
ret = intel_scu_ipc_ioread8(INTEL_MSIC_ID1, &id1);
if (ret) {
dev_err(&pdev->dev, "failed to identify the MSIC chip (ID1)\n");
return -ENXIO;
}
if (MSIC_VENDOR(id0) != MSIC_VENDOR(id1)) {
dev_err(&pdev->dev, "invalid vendor ID: %x, %x\n", id0, id1);
return -ENXIO;
}
msic = devm_kzalloc(&pdev->dev, sizeof(*msic), GFP_KERNEL);
if (!msic)
return -ENOMEM;
msic->vendor = MSIC_VENDOR(id0);
msic->version = MSIC_VERSION(id0);
msic->pdev = pdev;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
msic->irq_base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(msic->irq_base))
return PTR_ERR(msic->irq_base);
platform_set_drvdata(pdev, msic);
ret = intel_msic_init_devices(msic);
if (ret) {
dev_err(&pdev->dev, "failed to initialize MSIC devices\n");
return ret;
}
dev_info(&pdev->dev, "Intel MSIC version %c%d (vendor %#x)\n",
MSIC_MAJOR(msic->version), MSIC_MINOR(msic->version),
msic->vendor);
return 0;
}
static int intel_msic_remove(struct platform_device *pdev)
{
struct intel_msic *msic = platform_get_drvdata(pdev);
intel_msic_remove_devices(msic);
return 0;
}
