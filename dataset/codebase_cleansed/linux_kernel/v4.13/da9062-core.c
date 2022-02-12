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
int device_id, variant_id, variant_mrc, variant_vrc;
char *type;
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
variant_vrc = (variant_id & DA9062AA_VRC_MASK) >> DA9062AA_VRC_SHIFT;
switch (variant_vrc) {
case DA9062_PMIC_VARIANT_VRC_DA9061:
type = "DA9061";
break;
case DA9062_PMIC_VARIANT_VRC_DA9062:
type = "DA9062";
break;
default:
type = "Unknown";
break;
}
dev_info(chip->dev,
"Device detected (device-ID: 0x%02X, var-ID: 0x%02X, %s)\n",
device_id, variant_id, type);
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
const struct of_device_id *match;
unsigned int irq_base;
const struct mfd_cell *cell;
const struct regmap_irq_chip *irq_chip;
const struct regmap_config *config;
int cell_num;
int ret;
chip = devm_kzalloc(&i2c->dev, sizeof(*chip), GFP_KERNEL);
if (!chip)
return -ENOMEM;
if (i2c->dev.of_node) {
match = of_match_node(da9062_dt_ids, i2c->dev.of_node);
if (!match)
return -EINVAL;
chip->chip_type = (uintptr_t)match->data;
} else {
chip->chip_type = id->driver_data;
}
i2c_set_clientdata(i2c, chip);
chip->dev = &i2c->dev;
if (!i2c->irq) {
dev_err(chip->dev, "No IRQ configured\n");
return -EINVAL;
}
switch (chip->chip_type) {
case COMPAT_TYPE_DA9061:
cell = da9061_devs;
cell_num = ARRAY_SIZE(da9061_devs);
irq_chip = &da9061_irq_chip;
config = &da9061_regmap_config;
break;
case COMPAT_TYPE_DA9062:
cell = da9062_devs;
cell_num = ARRAY_SIZE(da9062_devs);
irq_chip = &da9062_irq_chip;
config = &da9062_regmap_config;
break;
default:
dev_err(chip->dev, "Unrecognised chip type\n");
return -ENODEV;
}
chip->regmap = devm_regmap_init_i2c(i2c, config);
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
-1, irq_chip,
&chip->regmap_irq);
if (ret) {
dev_err(chip->dev, "Failed to request IRQ %d: %d\n",
i2c->irq, ret);
return ret;
}
irq_base = regmap_irq_chip_get_base(chip->regmap_irq);
ret = mfd_add_devices(chip->dev, PLATFORM_DEVID_NONE, cell,
cell_num, NULL, irq_base,
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
