int da9063_device_init(struct da9063 *da9063, unsigned int irq)
{
struct da9063_pdata *pdata = da9063->dev->platform_data;
int model, variant_id, variant_code;
int ret;
if (pdata) {
da9063->flags = pdata->flags;
da9063->irq_base = pdata->irq_base;
} else {
da9063->flags = 0;
da9063->irq_base = 0;
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
