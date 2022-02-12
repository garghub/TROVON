int da9063_device_init(struct da9063 *da9063, unsigned int irq)
{
struct da9063_pdata *pdata = da9063->dev->platform_data;
int model, revision;
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
ret = regmap_read(da9063->regmap, DA9063_REG_CHIP_VARIANT, &revision);
if (ret < 0) {
dev_err(da9063->dev, "Cannot read chip revision id.\n");
return -EIO;
}
revision >>= DA9063_CHIP_VARIANT_SHIFT;
if (revision != 3) {
dev_err(da9063->dev, "Unknown chip revision: %d\n", revision);
return -ENODEV;
}
da9063->model = model;
da9063->revision = revision;
dev_info(da9063->dev,
"Device detected (model-ID: 0x%02X rev-ID: 0x%02X)\n",
model, revision);
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
