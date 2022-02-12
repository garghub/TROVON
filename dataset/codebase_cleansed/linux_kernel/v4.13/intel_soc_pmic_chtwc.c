static int cht_wc_byte_reg_read(void *context, unsigned int reg,
unsigned int *val)
{
struct i2c_client *client = context;
int ret, orig_addr = client->addr;
if (!(reg & REG_ADDR_MASK)) {
dev_err(&client->dev, "Error I2C address not specified\n");
return -EINVAL;
}
client->addr = (reg & REG_ADDR_MASK) >> REG_ADDR_SHIFT;
ret = i2c_smbus_read_byte_data(client, reg & REG_OFFSET_MASK);
client->addr = orig_addr;
if (ret < 0)
return ret;
*val = ret;
return 0;
}
static int cht_wc_byte_reg_write(void *context, unsigned int reg,
unsigned int val)
{
struct i2c_client *client = context;
int ret, orig_addr = client->addr;
if (!(reg & REG_ADDR_MASK)) {
dev_err(&client->dev, "Error I2C address not specified\n");
return -EINVAL;
}
client->addr = (reg & REG_ADDR_MASK) >> REG_ADDR_SHIFT;
ret = i2c_smbus_write_byte_data(client, reg & REG_OFFSET_MASK, val);
client->addr = orig_addr;
return ret;
}
static int cht_wc_probe(struct i2c_client *client)
{
struct device *dev = &client->dev;
struct intel_soc_pmic *pmic;
acpi_status status;
unsigned long long hrv;
int ret;
status = acpi_evaluate_integer(ACPI_HANDLE(dev), "_HRV", NULL, &hrv);
if (ACPI_FAILURE(status)) {
dev_err(dev, "Failed to get PMIC hardware revision\n");
return -ENODEV;
}
if (hrv != CHT_WC_HRV) {
dev_err(dev, "Invalid PMIC hardware revision: %llu\n", hrv);
return -ENODEV;
}
if (client->irq < 0) {
dev_err(dev, "Invalid IRQ\n");
return -EINVAL;
}
pmic = devm_kzalloc(dev, sizeof(*pmic), GFP_KERNEL);
if (!pmic)
return -ENOMEM;
pmic->irq = client->irq;
pmic->dev = dev;
i2c_set_clientdata(client, pmic);
pmic->regmap = devm_regmap_init(dev, NULL, client, &cht_wc_regmap_cfg);
if (IS_ERR(pmic->regmap))
return PTR_ERR(pmic->regmap);
ret = devm_regmap_add_irq_chip(dev, pmic->regmap, pmic->irq,
IRQF_ONESHOT | IRQF_SHARED, 0,
&cht_wc_regmap_irq_chip,
&pmic->irq_chip_data);
if (ret)
return ret;
return devm_mfd_add_devices(dev, PLATFORM_DEVID_NONE,
cht_wc_dev, ARRAY_SIZE(cht_wc_dev), NULL, 0,
regmap_irq_get_domain(pmic->irq_chip_data));
}
static void cht_wc_shutdown(struct i2c_client *client)
{
struct intel_soc_pmic *pmic = i2c_get_clientdata(client);
disable_irq(pmic->irq);
}
static int __maybe_unused cht_wc_suspend(struct device *dev)
{
struct intel_soc_pmic *pmic = dev_get_drvdata(dev);
disable_irq(pmic->irq);
return 0;
}
static int __maybe_unused cht_wc_resume(struct device *dev)
{
struct intel_soc_pmic *pmic = dev_get_drvdata(dev);
enable_irq(pmic->irq);
return 0;
}
