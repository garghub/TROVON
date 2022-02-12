static int da9062_clear_fault_log(struct da9062 *chip)
{
int ret;
int fault_log;
ret = regmap_read(chip->regmap, DA9062AA_FAULT_LOG, &fault_log);
if (ret < 0)
return ret;
if (fault_log) {
if (fault_log & DA9062AA_TWD_ERROR_MASK)
dev_dbg(chip->dev, "Fault log entry detected: TWD_ERROR\n");
if (fault_log & DA9062AA_POR_MASK)
dev_dbg(chip->dev, "Fault log entry detected: POR\n");
if (fault_log & DA9062AA_VDD_FAULT_MASK)
dev_dbg(chip->dev, "Fault log entry detected: VDD_FAULT\n");
if (fault_log & DA9062AA_VDD_START_MASK)
dev_dbg(chip->dev, "Fault log entry detected: VDD_START\n");
if (fault_log & DA9062AA_TEMP_CRIT_MASK)
dev_dbg(chip->dev, "Fault log entry detected: TEMP_CRIT\n");
if (fault_log & DA9062AA_KEY_RESET_MASK)
dev_dbg(chip->dev, "Fault log entry detected: KEY_RESET\n");
if (fault_log & DA9062AA_NSHUTDOWN_MASK)
dev_dbg(chip->dev, "Fault log entry detected: NSHUTDOWN\n");
if (fault_log & DA9062AA_WAIT_SHUT_MASK)
dev_dbg(chip->dev, "Fault log entry detected: WAIT_SHUT\n");
ret = regmap_write(chip->regmap, DA9062AA_FAULT_LOG,
fault_log);
}
return ret;
}
static int da9062_get_device_type(struct da9062 *chip)
{
int device_id, variant_id, variant_mrc;
int ret;
ret = regmap_read(chip->regmap, DA9062AA_DEVICE_ID, &device_id);
if (ret < 0) {
dev_err(chip->dev, "Cannot read chip ID.\n");
return -EIO;
}
if (device_id != DA9062_PMIC_DEVICE_ID) {
dev_err(chip->dev, "Invalid device ID: 0x%02x\n", device_id);
return -ENODEV;
}
ret = regmap_read(chip->regmap, DA9062AA_VARIANT_ID, &variant_id);
if (ret < 0) {
dev_err(chip->dev, "Cannot read chip variant id.\n");
return -EIO;
}
dev_info(chip->dev,
"Device detected (device-ID: 0x%02X, var-ID: 0x%02X)\n",
device_id, variant_id);
variant_mrc = (variant_id & DA9062AA_MRC_MASK) >> DA9062AA_MRC_SHIFT;
if (variant_mrc < DA9062_PMIC_VARIANT_MRC_AA) {
dev_err(chip->dev,
"Cannot support variant MRC: 0x%02X\n", variant_mrc);
return -ENODEV;
}
return ret;
}
static int da9062_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct da9062 *chip;
unsigned int irq_base;
int ret;
chip = devm_kzalloc(&i2c->dev, sizeof(*chip), GFP_KERNEL);
if (!chip)
return -ENOMEM;
i2c_set_clientdata(i2c, chip);
chip->dev = &i2c->dev;
if (!i2c->irq) {
dev_err(chip->dev, "No IRQ configured\n");
return -EINVAL;
}
chip->regmap = devm_regmap_init_i2c(i2c, &da9062_regmap_config);
if (IS_ERR(chip->regmap)) {
ret = PTR_ERR(chip->regmap);
dev_err(chip->dev, "Failed to allocate register map: %d\n",
ret);
return ret;
}
ret = da9062_clear_fault_log(chip);
if (ret < 0)
dev_warn(chip->dev, "Cannot clear fault log\n");
ret = da9062_get_device_type(chip);
if (ret)
return ret;
ret = regmap_add_irq_chip(chip->regmap, i2c->irq,
IRQF_TRIGGER_LOW | IRQF_ONESHOT | IRQF_SHARED,
-1, &da9062_irq_chip,
&chip->regmap_irq);
if (ret) {
dev_err(chip->dev, "Failed to request IRQ %d: %d\n",
i2c->irq, ret);
return ret;
}
irq_base = regmap_irq_chip_get_base(chip->regmap_irq);
ret = mfd_add_devices(chip->dev, PLATFORM_DEVID_NONE, da9062_devs,
ARRAY_SIZE(da9062_devs), NULL, irq_base,
NULL);
if (ret) {
dev_err(chip->dev, "Cannot register child devices\n");
regmap_del_irq_chip(i2c->irq, chip->regmap_irq);
return ret;
}
return ret;
}
static int da9062_i2c_remove(struct i2c_client *i2c)
{
struct da9062 *chip = i2c_get_clientdata(i2c);
mfd_remove_devices(chip->dev);
regmap_del_irq_chip(i2c->irq, chip->regmap_irq);
return 0;
}
