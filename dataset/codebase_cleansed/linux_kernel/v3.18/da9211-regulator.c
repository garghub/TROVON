static unsigned int da9211_buck_get_mode(struct regulator_dev *rdev)
{
int id = rdev_get_id(rdev);
struct da9211 *chip = rdev_get_drvdata(rdev);
unsigned int data;
int ret, mode = 0;
ret = regmap_read(chip->regmap, DA9211_REG_BUCKA_CONF+id, &data);
if (ret < 0)
return ret;
switch (data & 0x03) {
case DA9211_BUCK_MODE_SYNC:
mode = REGULATOR_MODE_FAST;
break;
case DA9211_BUCK_MODE_AUTO:
mode = REGULATOR_MODE_NORMAL;
break;
case DA9211_BUCK_MODE_SLEEP:
mode = REGULATOR_MODE_STANDBY;
break;
}
return mode;
}
static int da9211_buck_set_mode(struct regulator_dev *rdev,
unsigned int mode)
{
int id = rdev_get_id(rdev);
struct da9211 *chip = rdev_get_drvdata(rdev);
int val = 0;
switch (mode) {
case REGULATOR_MODE_FAST:
val = DA9211_BUCK_MODE_SYNC;
break;
case REGULATOR_MODE_NORMAL:
val = DA9211_BUCK_MODE_AUTO;
break;
case REGULATOR_MODE_STANDBY:
val = DA9211_BUCK_MODE_SLEEP;
break;
}
return regmap_update_bits(chip->regmap, DA9211_REG_BUCKA_CONF+id,
0x03, val);
}
static int da9211_set_current_limit(struct regulator_dev *rdev, int min,
int max)
{
int id = rdev_get_id(rdev);
struct da9211 *chip = rdev_get_drvdata(rdev);
int i, max_size;
const int *current_limits;
switch (chip->chip_id) {
case DA9211:
current_limits = da9211_current_limits;
max_size = ARRAY_SIZE(da9211_current_limits)-1;
break;
case DA9213:
current_limits = da9213_current_limits;
max_size = ARRAY_SIZE(da9213_current_limits)-1;
break;
default:
return -EINVAL;
}
for (i = max_size; i >= 0; i--) {
if (min <= current_limits[i] &&
max >= current_limits[i]) {
return regmap_update_bits(chip->regmap,
DA9211_REG_BUCK_ILIM,
(0x0F << id*4), (i << id*4));
}
}
return -EINVAL;
}
static int da9211_get_current_limit(struct regulator_dev *rdev)
{
int id = rdev_get_id(rdev);
struct da9211 *chip = rdev_get_drvdata(rdev);
unsigned int data;
int ret;
const int *current_limits;
switch (chip->chip_id) {
case DA9211:
current_limits = da9211_current_limits;
break;
case DA9213:
current_limits = da9213_current_limits;
break;
default:
return -EINVAL;
}
ret = regmap_read(chip->regmap, DA9211_REG_BUCK_ILIM, &data);
if (ret < 0)
return ret;
data = (data >> id*4) & 0x0F;
return current_limits[data];
}
static struct da9211_pdata *da9211_parse_regulators_dt(
struct device *dev)
{
struct da9211_pdata *pdata;
struct device_node *node;
int i, num, n;
node = of_get_child_by_name(dev->of_node, "regulators");
if (!node) {
dev_err(dev, "regulators node not found\n");
return ERR_PTR(-ENODEV);
}
num = of_regulator_match(dev, node, da9211_matches,
ARRAY_SIZE(da9211_matches));
of_node_put(node);
if (num < 0) {
dev_err(dev, "Failed to match regulators\n");
return ERR_PTR(-EINVAL);
}
pdata = devm_kzalloc(dev, sizeof(*pdata), GFP_KERNEL);
if (!pdata)
return ERR_PTR(-ENOMEM);
pdata->num_buck = num;
n = 0;
for (i = 0; i < ARRAY_SIZE(da9211_matches); i++) {
if (!da9211_matches[i].init_data)
continue;
pdata->init_data[n] = da9211_matches[i].init_data;
n++;
}
return pdata;
}
static struct da9211_pdata *da9211_parse_regulators_dt(
struct device *dev)
{
return ERR_PTR(-ENODEV);
}
static irqreturn_t da9211_irq_handler(int irq, void *data)
{
struct da9211 *chip = data;
int reg_val, err, ret = IRQ_NONE;
err = regmap_read(chip->regmap, DA9211_REG_EVENT_B, &reg_val);
if (err < 0)
goto error_i2c;
if (reg_val & DA9211_E_OV_CURR_A) {
regulator_notifier_call_chain(chip->rdev[0],
REGULATOR_EVENT_OVER_CURRENT,
rdev_get_drvdata(chip->rdev[0]));
err = regmap_write(chip->regmap, DA9211_REG_EVENT_B,
DA9211_E_OV_CURR_A);
if (err < 0)
goto error_i2c;
ret = IRQ_HANDLED;
}
if (reg_val & DA9211_E_OV_CURR_B) {
regulator_notifier_call_chain(chip->rdev[1],
REGULATOR_EVENT_OVER_CURRENT,
rdev_get_drvdata(chip->rdev[1]));
err = regmap_write(chip->regmap, DA9211_REG_EVENT_B,
DA9211_E_OV_CURR_B);
if (err < 0)
goto error_i2c;
ret = IRQ_HANDLED;
}
return ret;
error_i2c:
dev_err(chip->dev, "I2C error : %d\n", err);
return IRQ_NONE;
}
static int da9211_regulator_init(struct da9211 *chip)
{
struct regulator_config config = { };
int i, ret;
unsigned int data;
ret = regmap_read(chip->regmap, DA9211_REG_CONFIG_E, &data);
if (ret < 0) {
dev_err(chip->dev, "Failed to read CONTROL_E reg: %d\n", ret);
return ret;
}
data &= DA9211_SLAVE_SEL;
if ((chip->pdata->num_buck == 2 && data == 0x40)
|| (chip->pdata->num_buck == 1 && data == 0x00)) {
if (data == 0)
chip->num_regulator = 1;
else
chip->num_regulator = 2;
} else {
dev_err(chip->dev, "Configuration is mismatched\n");
return -EINVAL;
}
for (i = 0; i < chip->num_regulator; i++) {
config.init_data = chip->pdata->init_data[i];
config.dev = chip->dev;
config.driver_data = chip;
config.regmap = chip->regmap;
config.of_node = chip->dev->of_node;
chip->rdev[i] = devm_regulator_register(chip->dev,
&da9211_regulators[i], &config);
if (IS_ERR(chip->rdev[i])) {
dev_err(chip->dev,
"Failed to register DA9211 regulator\n");
return PTR_ERR(chip->rdev[i]);
}
if (chip->chip_irq != 0) {
ret = regmap_update_bits(chip->regmap,
DA9211_REG_MASK_B, DA9211_M_OV_CURR_A << i, 0);
if (ret < 0) {
dev_err(chip->dev,
"Failed to update mask reg: %d\n", ret);
return ret;
}
}
}
return 0;
}
static int da9211_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct da9211 *chip;
int error, ret;
unsigned int data;
chip = devm_kzalloc(&i2c->dev, sizeof(struct da9211), GFP_KERNEL);
if (!chip)
return -ENOMEM;
chip->dev = &i2c->dev;
chip->regmap = devm_regmap_init_i2c(i2c, &da9211_regmap_config);
if (IS_ERR(chip->regmap)) {
error = PTR_ERR(chip->regmap);
dev_err(chip->dev, "Failed to allocate register map: %d\n",
error);
return error;
}
i2c_set_clientdata(i2c, chip);
chip->pdata = i2c->dev.platform_data;
ret = regmap_read(chip->regmap, DA9211_REG_DEVICE_ID, &data);
if (ret < 0) {
dev_err(chip->dev, "Failed to read DEVICE_ID reg: %d\n", ret);
return ret;
}
switch (data) {
case DA9211_DEVICE_ID:
chip->chip_id = DA9211;
break;
case DA9213_DEVICE_ID:
chip->chip_id = DA9213;
break;
default:
dev_err(chip->dev, "Unsupported device id = 0x%x.\n", data);
return -ENODEV;
}
if (!chip->pdata)
chip->pdata = da9211_parse_regulators_dt(chip->dev);
if (IS_ERR(chip->pdata)) {
dev_err(chip->dev, "No regulators defined for the platform\n");
return PTR_ERR(chip->pdata);
}
chip->chip_irq = i2c->irq;
if (chip->chip_irq != 0) {
ret = devm_request_threaded_irq(chip->dev, chip->chip_irq, NULL,
da9211_irq_handler,
IRQF_TRIGGER_LOW|IRQF_ONESHOT,
"da9211", chip);
if (ret != 0) {
dev_err(chip->dev, "Failed to request IRQ: %d\n",
chip->chip_irq);
return ret;
}
} else {
dev_warn(chip->dev, "No IRQ configured\n");
}
ret = da9211_regulator_init(chip);
if (ret < 0)
dev_err(chip->dev, "Failed to initialize regulator: %d\n", ret);
return ret;
}
