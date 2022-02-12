static int da9210_set_current_limit(struct regulator_dev *rdev, int min_uA,
int max_uA)
{
struct da9210 *chip = rdev_get_drvdata(rdev);
unsigned int sel;
int i;
for (i = ARRAY_SIZE(da9210_buck_limits)-1; i >= 0; i--) {
if (min_uA <= da9210_buck_limits[i] &&
max_uA >= da9210_buck_limits[i]) {
sel = i;
sel = sel << DA9210_BUCK_ILIM_SHIFT;
return regmap_update_bits(chip->regmap,
DA9210_REG_BUCK_ILIM,
DA9210_BUCK_ILIM_MASK, sel);
}
}
return -EINVAL;
}
static int da9210_get_current_limit(struct regulator_dev *rdev)
{
struct da9210 *chip = rdev_get_drvdata(rdev);
unsigned int data;
unsigned int sel;
int ret;
ret = regmap_read(chip->regmap, DA9210_REG_BUCK_ILIM, &data);
if (ret < 0)
return ret;
sel = (data & DA9210_BUCK_ILIM_MASK) >> DA9210_BUCK_ILIM_SHIFT;
return da9210_buck_limits[sel];
}
static int da9210_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct da9210 *chip;
struct device *dev = &i2c->dev;
struct da9210_pdata *pdata = dev_get_platdata(dev);
struct regulator_dev *rdev = NULL;
struct regulator_config config = { };
int error;
chip = devm_kzalloc(&i2c->dev, sizeof(struct da9210), GFP_KERNEL);
if (NULL == chip) {
dev_err(&i2c->dev,
"Cannot kzalloc memory for regulator structure\n");
return -ENOMEM;
}
chip->regmap = devm_regmap_init_i2c(i2c, &da9210_regmap_config);
if (IS_ERR(chip->regmap)) {
error = PTR_ERR(chip->regmap);
dev_err(&i2c->dev, "Failed to allocate register map: %d\n",
error);
return error;
}
config.dev = &i2c->dev;
config.init_data = pdata ? &pdata->da9210_constraints :
of_get_regulator_init_data(dev, dev->of_node);
config.driver_data = chip;
config.regmap = chip->regmap;
config.of_node = dev->of_node;
rdev = devm_regulator_register(&i2c->dev, &da9210_reg, &config);
if (IS_ERR(rdev)) {
dev_err(&i2c->dev, "Failed to register DA9210 regulator\n");
return PTR_ERR(rdev);
}
chip->rdev = rdev;
i2c_set_clientdata(i2c, chip);
return 0;
}
