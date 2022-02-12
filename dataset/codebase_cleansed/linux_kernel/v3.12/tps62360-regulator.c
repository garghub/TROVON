static bool find_voltage_set_register(struct tps62360_chip *tps,
int req_vsel, int *vset_reg_id)
{
int i;
bool found = false;
int new_vset_reg = tps->lru_index[3];
int found_index = 3;
for (i = 0; i < 4; ++i) {
if (tps->curr_vset_vsel[tps->lru_index[i]] == req_vsel) {
new_vset_reg = tps->lru_index[i];
found_index = i;
found = true;
goto update_lru_index;
}
}
update_lru_index:
for (i = found_index; i > 0; i--)
tps->lru_index[i] = tps->lru_index[i - 1];
tps->lru_index[0] = new_vset_reg;
*vset_reg_id = new_vset_reg;
return found;
}
static int tps62360_dcdc_get_voltage_sel(struct regulator_dev *dev)
{
struct tps62360_chip *tps = rdev_get_drvdata(dev);
int vsel;
unsigned int data;
int ret;
ret = regmap_read(tps->regmap, REG_VSET0 + tps->curr_vset_id, &data);
if (ret < 0) {
dev_err(tps->dev, "%s(): register %d read failed with err %d\n",
__func__, REG_VSET0 + tps->curr_vset_id, ret);
return ret;
}
vsel = (int)data & tps->voltage_reg_mask;
return vsel;
}
static int tps62360_dcdc_set_voltage_sel(struct regulator_dev *dev,
unsigned selector)
{
struct tps62360_chip *tps = rdev_get_drvdata(dev);
int ret;
bool found = false;
int new_vset_id = tps->curr_vset_id;
if (tps->valid_gpios)
found = find_voltage_set_register(tps, selector, &new_vset_id);
if (!found) {
ret = regmap_update_bits(tps->regmap, REG_VSET0 + new_vset_id,
tps->voltage_reg_mask, selector);
if (ret < 0) {
dev_err(tps->dev,
"%s(): register %d update failed with err %d\n",
__func__, REG_VSET0 + new_vset_id, ret);
return ret;
}
tps->curr_vset_id = new_vset_id;
tps->curr_vset_vsel[new_vset_id] = selector;
}
if (tps->valid_gpios) {
gpio_set_value_cansleep(tps->vsel0_gpio, new_vset_id & 0x1);
gpio_set_value_cansleep(tps->vsel1_gpio,
(new_vset_id >> 1) & 0x1);
}
return 0;
}
static int tps62360_set_mode(struct regulator_dev *rdev, unsigned int mode)
{
struct tps62360_chip *tps = rdev_get_drvdata(rdev);
int i;
int val;
int ret;
switch (mode) {
case REGULATOR_MODE_FAST:
val = FORCE_PWM_ENABLE;
break;
case REGULATOR_MODE_NORMAL:
val = 0;
break;
default:
return -EINVAL;
}
if (!tps->valid_gpios) {
ret = regmap_update_bits(tps->regmap,
REG_VSET0 + tps->curr_vset_id, FORCE_PWM_ENABLE, val);
if (ret < 0)
dev_err(tps->dev,
"%s(): register %d update failed with err %d\n",
__func__, REG_VSET0 + tps->curr_vset_id, ret);
return ret;
}
for (i = 0; i < 4; ++i) {
ret = regmap_update_bits(tps->regmap,
REG_VSET0 + i, FORCE_PWM_ENABLE, val);
if (ret < 0) {
dev_err(tps->dev,
"%s(): register %d update failed with err %d\n",
__func__, REG_VSET0 + i, ret);
return ret;
}
}
return ret;
}
static unsigned int tps62360_get_mode(struct regulator_dev *rdev)
{
struct tps62360_chip *tps = rdev_get_drvdata(rdev);
unsigned int data;
int ret;
ret = regmap_read(tps->regmap, REG_VSET0 + tps->curr_vset_id, &data);
if (ret < 0) {
dev_err(tps->dev, "%s(): register %d read failed with err %d\n",
__func__, REG_VSET0 + tps->curr_vset_id, ret);
return ret;
}
return (data & FORCE_PWM_ENABLE) ?
REGULATOR_MODE_FAST : REGULATOR_MODE_NORMAL;
}
static int tps62360_init_dcdc(struct tps62360_chip *tps,
struct tps62360_regulator_platform_data *pdata)
{
int ret;
unsigned int ramp_ctrl;
if (tps->en_internal_pulldn)
ret = regmap_write(tps->regmap, REG_CONTROL, 0xE0);
else
ret = regmap_write(tps->regmap, REG_CONTROL, 0x0);
if (ret < 0) {
dev_err(tps->dev,
"%s(): register %d write failed with err %d\n",
__func__, REG_CONTROL, ret);
return ret;
}
ret = regmap_update_bits(tps->regmap, REG_RAMPCTRL, BIT(2), 0);
if (ret < 0) {
dev_err(tps->dev,
"%s(): register %d update failed with err %d\n",
__func__, REG_RAMPCTRL, ret);
return ret;
}
ret = regmap_read(tps->regmap, REG_RAMPCTRL, &ramp_ctrl);
if (ret < 0) {
dev_err(tps->dev,
"%s(): register %d read failed with err %d\n",
__func__, REG_RAMPCTRL, ret);
return ret;
}
ramp_ctrl = (ramp_ctrl >> 5) & 0x7;
tps->desc.ramp_delay = DIV_ROUND_UP(32000, BIT(ramp_ctrl));
return ret;
}
static struct tps62360_regulator_platform_data *
of_get_tps62360_platform_data(struct device *dev)
{
struct tps62360_regulator_platform_data *pdata;
struct device_node *np = dev->of_node;
pdata = devm_kzalloc(dev, sizeof(*pdata), GFP_KERNEL);
if (!pdata) {
dev_err(dev, "Memory alloc failed for platform data\n");
return NULL;
}
pdata->reg_init_data = of_get_regulator_init_data(dev, dev->of_node);
if (!pdata->reg_init_data) {
dev_err(dev, "Not able to get OF regulator init data\n");
return NULL;
}
pdata->vsel0_gpio = of_get_named_gpio(np, "vsel0-gpio", 0);
pdata->vsel1_gpio = of_get_named_gpio(np, "vsel1-gpio", 0);
if (of_find_property(np, "ti,vsel0-state-high", NULL))
pdata->vsel0_def_state = 1;
if (of_find_property(np, "ti,vsel1-state-high", NULL))
pdata->vsel1_def_state = 1;
if (of_find_property(np, "ti,enable-pull-down", NULL))
pdata->en_internal_pulldn = true;
if (of_find_property(np, "ti,enable-vout-discharge", NULL))
pdata->en_discharge = true;
return pdata;
}
static int tps62360_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct regulator_config config = { };
struct tps62360_regulator_platform_data *pdata;
struct regulator_dev *rdev;
struct tps62360_chip *tps;
int ret;
int i;
int chip_id;
pdata = dev_get_platdata(&client->dev);
if (client->dev.of_node) {
const struct of_device_id *match;
match = of_match_device(of_match_ptr(tps62360_of_match),
&client->dev);
if (!match) {
dev_err(&client->dev, "Error: No device match found\n");
return -ENODEV;
}
chip_id = (int)match->data;
if (!pdata)
pdata = of_get_tps62360_platform_data(&client->dev);
} else if (id) {
chip_id = id->driver_data;
} else {
dev_err(&client->dev, "No device tree match or id table match found\n");
return -ENODEV;
}
if (!pdata) {
dev_err(&client->dev, "%s(): Platform data not found\n",
__func__);
return -EIO;
}
tps = devm_kzalloc(&client->dev, sizeof(*tps), GFP_KERNEL);
if (!tps) {
dev_err(&client->dev, "%s(): Memory allocation failed\n",
__func__);
return -ENOMEM;
}
tps->en_discharge = pdata->en_discharge;
tps->en_internal_pulldn = pdata->en_internal_pulldn;
tps->vsel0_gpio = pdata->vsel0_gpio;
tps->vsel1_gpio = pdata->vsel1_gpio;
tps->dev = &client->dev;
switch (chip_id) {
case TPS62360:
case TPS62362:
tps->desc.min_uV = TPS62360_BASE_VOLTAGE;
tps->voltage_reg_mask = 0x3F;
tps->desc.n_voltages = TPS62360_N_VOLTAGES;
break;
case TPS62361:
case TPS62363:
tps->desc.min_uV = TPS62361_BASE_VOLTAGE;
tps->voltage_reg_mask = 0x7F;
tps->desc.n_voltages = TPS62361_N_VOLTAGES;
break;
default:
return -ENODEV;
}
tps->desc.name = client->name;
tps->desc.id = 0;
tps->desc.ops = &tps62360_dcdc_ops;
tps->desc.type = REGULATOR_VOLTAGE;
tps->desc.owner = THIS_MODULE;
tps->desc.uV_step = 10000;
tps->regmap = devm_regmap_init_i2c(client, &tps62360_regmap_config);
if (IS_ERR(tps->regmap)) {
ret = PTR_ERR(tps->regmap);
dev_err(&client->dev,
"%s(): regmap allocation failed with err %d\n",
__func__, ret);
return ret;
}
i2c_set_clientdata(client, tps);
tps->curr_vset_id = (pdata->vsel1_def_state & 1) * 2 +
(pdata->vsel0_def_state & 1);
tps->lru_index[0] = tps->curr_vset_id;
tps->valid_gpios = false;
if (gpio_is_valid(tps->vsel0_gpio) && gpio_is_valid(tps->vsel1_gpio)) {
int gpio_flags;
gpio_flags = (pdata->vsel0_def_state) ?
GPIOF_OUT_INIT_HIGH : GPIOF_OUT_INIT_LOW;
ret = devm_gpio_request_one(&client->dev, tps->vsel0_gpio,
gpio_flags, "tps62360-vsel0");
if (ret) {
dev_err(&client->dev,
"%s(): Could not obtain vsel0 GPIO %d: %d\n",
__func__, tps->vsel0_gpio, ret);
return ret;
}
gpio_flags = (pdata->vsel1_def_state) ?
GPIOF_OUT_INIT_HIGH : GPIOF_OUT_INIT_LOW;
ret = devm_gpio_request_one(&client->dev, tps->vsel1_gpio,
gpio_flags, "tps62360-vsel1");
if (ret) {
dev_err(&client->dev,
"%s(): Could not obtain vsel1 GPIO %d: %d\n",
__func__, tps->vsel1_gpio, ret);
return ret;
}
tps->valid_gpios = true;
for (i = 0; i < 4; ++i)
tps->lru_index[i] = i;
tps->lru_index[0] = tps->curr_vset_id;
tps->lru_index[tps->curr_vset_id] = 0;
}
ret = tps62360_init_dcdc(tps, pdata);
if (ret < 0) {
dev_err(tps->dev, "%s(): Init failed with err = %d\n",
__func__, ret);
return ret;
}
config.dev = &client->dev;
config.init_data = pdata->reg_init_data;
config.driver_data = tps;
config.of_node = client->dev.of_node;
rdev = regulator_register(&tps->desc, &config);
if (IS_ERR(rdev)) {
dev_err(tps->dev,
"%s(): regulator register failed with err %s\n",
__func__, id->name);
return PTR_ERR(rdev);
}
tps->rdev = rdev;
return 0;
}
static int tps62360_remove(struct i2c_client *client)
{
struct tps62360_chip *tps = i2c_get_clientdata(client);
regulator_unregister(tps->rdev);
return 0;
}
static void tps62360_shutdown(struct i2c_client *client)
{
struct tps62360_chip *tps = i2c_get_clientdata(client);
int st;
if (!tps->en_discharge)
return;
st = regmap_update_bits(tps->regmap, REG_RAMPCTRL, BIT(2), BIT(2));
if (st < 0)
dev_err(tps->dev,
"%s(): register %d update failed with err %d\n",
__func__, REG_RAMPCTRL, st);
}
static int __init tps62360_init(void)
{
return i2c_add_driver(&tps62360_i2c_driver);
}
static void __exit tps62360_cleanup(void)
{
i2c_del_driver(&tps62360_i2c_driver);
}
