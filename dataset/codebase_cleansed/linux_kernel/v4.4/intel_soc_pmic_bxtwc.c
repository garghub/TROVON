static int regmap_ipc_byte_reg_read(void *context, unsigned int reg,
unsigned int *val)
{
int ret;
int i2c_addr;
u8 ipc_in[2];
u8 ipc_out[4];
struct intel_soc_pmic *pmic = context;
if (reg & REG_ADDR_MASK)
i2c_addr = (reg & REG_ADDR_MASK) >> REG_ADDR_SHIFT;
else {
i2c_addr = BXTWC_DEVICE1_ADDR;
if (!i2c_addr) {
dev_err(pmic->dev, "I2C address not set\n");
return -EINVAL;
}
}
reg &= REG_OFFSET_MASK;
ipc_in[0] = reg;
ipc_in[1] = i2c_addr;
ret = intel_pmc_ipc_command(PMC_IPC_PMIC_ACCESS,
PMC_IPC_PMIC_ACCESS_READ,
ipc_in, sizeof(ipc_in), (u32 *)ipc_out, 1);
if (ret) {
dev_err(pmic->dev, "Failed to read from PMIC\n");
return ret;
}
*val = ipc_out[0];
return 0;
}
static int regmap_ipc_byte_reg_write(void *context, unsigned int reg,
unsigned int val)
{
int ret;
int i2c_addr;
u8 ipc_in[3];
struct intel_soc_pmic *pmic = context;
if (reg & REG_ADDR_MASK)
i2c_addr = (reg & REG_ADDR_MASK) >> REG_ADDR_SHIFT;
else {
i2c_addr = BXTWC_DEVICE1_ADDR;
if (!i2c_addr) {
dev_err(pmic->dev, "I2C address not set\n");
return -EINVAL;
}
}
reg &= REG_OFFSET_MASK;
ipc_in[0] = reg;
ipc_in[1] = i2c_addr;
ipc_in[2] = val;
ret = intel_pmc_ipc_command(PMC_IPC_PMIC_ACCESS,
PMC_IPC_PMIC_ACCESS_WRITE,
ipc_in, sizeof(ipc_in), NULL, 0);
if (ret) {
dev_err(pmic->dev, "Failed to write to PMIC\n");
return ret;
}
return 0;
}
static ssize_t bxtwc_reg_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
return sprintf(buf, "0x%lx\n", bxtwc_reg_addr);
}
static ssize_t bxtwc_reg_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
if (kstrtoul(buf, 0, &bxtwc_reg_addr)) {
dev_err(dev, "Invalid register address\n");
return -EINVAL;
}
return (ssize_t)count;
}
static ssize_t bxtwc_val_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
int ret;
unsigned int val;
struct intel_soc_pmic *pmic = dev_get_drvdata(dev);
ret = regmap_read(pmic->regmap, bxtwc_reg_addr, &val);
if (ret < 0) {
dev_err(dev, "Failed to read 0x%lx\n", bxtwc_reg_addr);
return -EIO;
}
return sprintf(buf, "0x%02x\n", val);
}
static ssize_t bxtwc_val_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
int ret;
unsigned int val;
struct intel_soc_pmic *pmic = dev_get_drvdata(dev);
ret = kstrtouint(buf, 0, &val);
if (ret)
return ret;
ret = regmap_write(pmic->regmap, bxtwc_reg_addr, val);
if (ret) {
dev_err(dev, "Failed to write value 0x%02x to address 0x%lx",
val, bxtwc_reg_addr);
return -EIO;
}
return count;
}
static int bxtwc_probe(struct platform_device *pdev)
{
int ret;
acpi_handle handle;
acpi_status status;
unsigned long long hrv;
struct intel_soc_pmic *pmic;
handle = ACPI_HANDLE(&pdev->dev);
status = acpi_evaluate_integer(handle, "_HRV", NULL, &hrv);
if (ACPI_FAILURE(status)) {
dev_err(&pdev->dev, "Failed to get PMIC hardware revision\n");
return -ENODEV;
}
if (hrv != BROXTON_PMIC_WC_HRV) {
dev_err(&pdev->dev, "Invalid PMIC hardware revision: %llu\n",
hrv);
return -ENODEV;
}
pmic = devm_kzalloc(&pdev->dev, sizeof(*pmic), GFP_KERNEL);
if (!pmic)
return -ENOMEM;
ret = platform_get_irq(pdev, 0);
if (ret < 0) {
dev_err(&pdev->dev, "Invalid IRQ\n");
return ret;
}
pmic->irq = ret;
dev_set_drvdata(&pdev->dev, pmic);
pmic->dev = &pdev->dev;
pmic->regmap = devm_regmap_init(&pdev->dev, NULL, pmic,
&bxtwc_regmap_config);
if (IS_ERR(pmic->regmap)) {
ret = PTR_ERR(pmic->regmap);
dev_err(&pdev->dev, "Failed to initialise regmap: %d\n", ret);
return ret;
}
ret = regmap_add_irq_chip(pmic->regmap, pmic->irq,
IRQF_ONESHOT | IRQF_SHARED,
0, &bxtwc_regmap_irq_chip,
&pmic->irq_chip_data);
if (ret) {
dev_err(&pdev->dev, "Failed to add IRQ chip\n");
return ret;
}
ret = regmap_add_irq_chip(pmic->regmap, pmic->irq,
IRQF_ONESHOT | IRQF_SHARED,
0, &bxtwc_regmap_irq_chip_level2,
&pmic->irq_chip_data_level2);
if (ret) {
dev_err(&pdev->dev, "Failed to add secondary IRQ chip\n");
goto err_irq_chip_level2;
}
ret = mfd_add_devices(&pdev->dev, PLATFORM_DEVID_NONE, bxt_wc_dev,
ARRAY_SIZE(bxt_wc_dev), NULL, 0,
NULL);
if (ret) {
dev_err(&pdev->dev, "Failed to add devices\n");
goto err_mfd;
}
ret = sysfs_create_group(&pdev->dev.kobj, &bxtwc_group);
if (ret) {
dev_err(&pdev->dev, "Failed to create sysfs group %d\n", ret);
goto err_sysfs;
}
return 0;
err_sysfs:
mfd_remove_devices(&pdev->dev);
err_mfd:
regmap_del_irq_chip(pmic->irq, pmic->irq_chip_data_level2);
err_irq_chip_level2:
regmap_del_irq_chip(pmic->irq, pmic->irq_chip_data);
return ret;
}
static int bxtwc_remove(struct platform_device *pdev)
{
struct intel_soc_pmic *pmic = dev_get_drvdata(&pdev->dev);
sysfs_remove_group(&pdev->dev.kobj, &bxtwc_group);
mfd_remove_devices(&pdev->dev);
regmap_del_irq_chip(pmic->irq, pmic->irq_chip_data);
regmap_del_irq_chip(pmic->irq, pmic->irq_chip_data_level2);
return 0;
}
static void bxtwc_shutdown(struct platform_device *pdev)
{
struct intel_soc_pmic *pmic = dev_get_drvdata(&pdev->dev);
disable_irq(pmic->irq);
}
static int bxtwc_suspend(struct device *dev)
{
struct intel_soc_pmic *pmic = dev_get_drvdata(dev);
disable_irq(pmic->irq);
return 0;
}
static int bxtwc_resume(struct device *dev)
{
struct intel_soc_pmic *pmic = dev_get_drvdata(dev);
enable_irq(pmic->irq);
return 0;
}
