static int da9063_clear_fault_log(struct da9063 *da9063)
{
int ret = 0;
int fault_log = 0;
ret = regmap_read(da9063->regmap, DA9063_REG_FAULT_LOG, &fault_log);
if (ret < 0) {
dev_err(da9063->dev, "Cannot read FAULT_LOG.\n");
return -EIO;
}
if (fault_log) {
if (fault_log & DA9063_TWD_ERROR)
dev_dbg(da9063->dev,
"Fault log entry detected: DA9063_TWD_ERROR\n");
if (fault_log & DA9063_POR)
dev_dbg(da9063->dev,
"Fault log entry detected: DA9063_POR\n");
if (fault_log & DA9063_VDD_FAULT)
dev_dbg(da9063->dev,
"Fault log entry detected: DA9063_VDD_FAULT\n");
if (fault_log & DA9063_VDD_START)
dev_dbg(da9063->dev,
"Fault log entry detected: DA9063_VDD_START\n");
if (fault_log & DA9063_TEMP_CRIT)
dev_dbg(da9063->dev,
"Fault log entry detected: DA9063_TEMP_CRIT\n");
if (fault_log & DA9063_KEY_RESET)
dev_dbg(da9063->dev,
"Fault log entry detected: DA9063_KEY_RESET\n");
if (fault_log & DA9063_NSHUTDOWN)
dev_dbg(da9063->dev,
"Fault log entry detected: DA9063_NSHUTDOWN\n");
if (fault_log & DA9063_WAIT_SHUT)
dev_dbg(da9063->dev,
"Fault log entry detected: DA9063_WAIT_SHUT\n");
}
ret = regmap_write(da9063->regmap,
DA9063_REG_FAULT_LOG,
fault_log);
if (ret < 0)
dev_err(da9063->dev,
"Cannot reset FAULT_LOG values %d\n", ret);
return ret;
}
int da9063_device_init(struct da9063 *da9063, unsigned int irq)
{
struct da9063_pdata *pdata = da9063->dev->platform_data;
int model, variant_id, variant_code;
int ret;
ret = da9063_clear_fault_log(da9063);
if (ret < 0)
dev_err(da9063->dev, "Cannot clear fault log\n");
if (pdata) {
da9063->flags = pdata->flags;
da9063->irq_base = pdata->irq_base;
} else {
da9063->flags = 0;
da9063->irq_base = -1;
}
da9063->chip_irq = irq;
if (pdata && pdata->init != NULL) {
ret = pdata->init(da9063);
if (ret != 0) {
dev_err(da9063->dev,
"Platform initialization failed.\n");
return ret;
}
}
ret = regmap_read(da9063->regmap, DA9063_REG_CHIP_ID, &model);
if (ret < 0) {
dev_err(da9063->dev, "Cannot read chip model id.\n");
return -EIO;
}
if (model != PMIC_DA9063) {
dev_err(da9063->dev, "Invalid chip model id: 0x%02x\n", model);
return -ENODEV;
}
ret = regmap_read(da9063->regmap, DA9063_REG_CHIP_VARIANT, &variant_id);
if (ret < 0) {
dev_err(da9063->dev, "Cannot read chip variant id.\n");
return -EIO;
}
variant_code = variant_id >> DA9063_CHIP_VARIANT_SHIFT;
dev_info(da9063->dev,
"Device detected (chip-ID: 0x%02X, var-ID: 0x%02X)\n",
model, variant_id);
if (variant_code < PMIC_DA9063_BB && variant_code != PMIC_DA9063_AD) {
dev_err(da9063->dev,
"Cannot support variant code: 0x%02X\n", variant_code);
return -ENODEV;
}
da9063->model = model;
da9063->variant_code = variant_code;
ret = da9063_irq_init(da9063);
if (ret) {
dev_err(da9063->dev, "Cannot initialize interrupts.\n");
return ret;
}
da9063->irq_base = regmap_irq_chip_get_base(da9063->regmap_irq);
ret = mfd_add_devices(da9063->dev, -1, da9063_devs,
ARRAY_SIZE(da9063_devs), NULL, da9063->irq_base,
NULL);
if (ret)
dev_err(da9063->dev, "Cannot add MFD cells\n");
return ret;
}
void da9063_device_exit(struct da9063 *da9063)
{
mfd_remove_devices(da9063->dev);
da9063_irq_exit(da9063);
}
