static int rk808_buck1_2_get_voltage_sel_regmap(struct regulator_dev *rdev)
{
struct rk808_regulator_data *pdata = rdev_get_drvdata(rdev);
int id = rdev->desc->id - RK808_ID_DCDC1;
struct gpio_desc *gpio = pdata->dvs_gpio[id];
unsigned int val;
int ret;
if (!gpio || gpiod_get_value(gpio) == 0)
return regulator_get_voltage_sel_regmap(rdev);
ret = regmap_read(rdev->regmap,
rdev->desc->vsel_reg + RK808_DVS_REG_OFFSET,
&val);
if (ret != 0)
return ret;
val &= rdev->desc->vsel_mask;
val >>= ffs(rdev->desc->vsel_mask) - 1;
return val;
}
static int rk808_buck1_2_i2c_set_voltage_sel(struct regulator_dev *rdev,
unsigned sel)
{
int ret, delta_sel;
unsigned int old_sel, tmp, val, mask = rdev->desc->vsel_mask;
ret = regmap_read(rdev->regmap, rdev->desc->vsel_reg, &val);
if (ret != 0)
return ret;
tmp = val & ~mask;
old_sel = val & mask;
old_sel >>= ffs(mask) - 1;
delta_sel = sel - old_sel;
while (delta_sel > MAX_STEPS_ONE_TIME) {
old_sel += MAX_STEPS_ONE_TIME;
val = old_sel << (ffs(mask) - 1);
val |= tmp;
ret = regmap_write(rdev->regmap, rdev->desc->vsel_reg, val);
delta_sel = sel - old_sel;
}
sel <<= ffs(mask) - 1;
val = tmp | sel;
ret = regmap_write(rdev->regmap, rdev->desc->vsel_reg, val);
udelay(1);
return ret;
}
static int rk808_buck1_2_set_voltage_sel(struct regulator_dev *rdev,
unsigned sel)
{
struct rk808_regulator_data *pdata = rdev_get_drvdata(rdev);
int id = rdev->desc->id - RK808_ID_DCDC1;
struct gpio_desc *gpio = pdata->dvs_gpio[id];
unsigned int reg = rdev->desc->vsel_reg;
unsigned old_sel;
int ret, gpio_level;
if (!gpio)
return rk808_buck1_2_i2c_set_voltage_sel(rdev, sel);
gpio_level = gpiod_get_value(gpio);
if (gpio_level == 0) {
reg += RK808_DVS_REG_OFFSET;
ret = regmap_read(rdev->regmap, rdev->desc->vsel_reg, &old_sel);
} else {
ret = regmap_read(rdev->regmap,
reg + RK808_DVS_REG_OFFSET,
&old_sel);
}
if (ret != 0)
return ret;
sel <<= ffs(rdev->desc->vsel_mask) - 1;
sel |= old_sel & ~rdev->desc->vsel_mask;
ret = regmap_write(rdev->regmap, reg, sel);
if (ret)
return ret;
gpiod_set_value(gpio, !gpio_level);
return ret;
}
static int rk808_buck1_2_set_voltage_time_sel(struct regulator_dev *rdev,
unsigned int old_selector,
unsigned int new_selector)
{
struct rk808_regulator_data *pdata = rdev_get_drvdata(rdev);
int id = rdev->desc->id - RK808_ID_DCDC1;
struct gpio_desc *gpio = pdata->dvs_gpio[id];
if (!gpio)
return 0;
return regulator_set_voltage_time_sel(rdev, old_selector, new_selector);
}
static int rk808_set_ramp_delay(struct regulator_dev *rdev, int ramp_delay)
{
unsigned int ramp_value = RK808_RAMP_RATE_10MV_PER_US;
unsigned int reg = rk808_buck_config_regs[rdev->desc->id -
RK808_ID_DCDC1];
switch (ramp_delay) {
case 1 ... 2000:
ramp_value = RK808_RAMP_RATE_2MV_PER_US;
break;
case 2001 ... 4000:
ramp_value = RK808_RAMP_RATE_4MV_PER_US;
break;
case 4001 ... 6000:
ramp_value = RK808_RAMP_RATE_6MV_PER_US;
break;
case 6001 ... 10000:
break;
default:
pr_warn("%s ramp_delay: %d not supported, setting 10000\n",
rdev->desc->name, ramp_delay);
}
return regmap_update_bits(rdev->regmap, reg,
RK808_RAMP_RATE_MASK, ramp_value);
}
static int rk808_set_suspend_voltage(struct regulator_dev *rdev, int uv)
{
unsigned int reg;
int sel = regulator_map_voltage_linear(rdev, uv, uv);
if (sel < 0)
return -EINVAL;
reg = rdev->desc->vsel_reg + RK808_SLP_REG_OFFSET;
return regmap_update_bits(rdev->regmap, reg,
rdev->desc->vsel_mask,
sel);
}
static int rk808_set_suspend_voltage_range(struct regulator_dev *rdev, int uv)
{
unsigned int reg;
int sel = regulator_map_voltage_linear_range(rdev, uv, uv);
if (sel < 0)
return -EINVAL;
reg = rdev->desc->vsel_reg + RK808_SLP_REG_OFFSET;
return regmap_update_bits(rdev->regmap, reg,
rdev->desc->vsel_mask,
sel);
}
static int rk808_set_suspend_enable(struct regulator_dev *rdev)
{
unsigned int reg;
reg = rdev->desc->enable_reg + RK808_SLP_SET_OFF_REG_OFFSET;
return regmap_update_bits(rdev->regmap, reg,
rdev->desc->enable_mask,
0);
}
static int rk808_set_suspend_disable(struct regulator_dev *rdev)
{
unsigned int reg;
reg = rdev->desc->enable_reg + RK808_SLP_SET_OFF_REG_OFFSET;
return regmap_update_bits(rdev->regmap, reg,
rdev->desc->enable_mask,
rdev->desc->enable_mask);
}
static int rk808_regulator_dt_parse_pdata(struct device *dev,
struct device *client_dev,
struct regmap *map,
struct rk808_regulator_data *pdata)
{
struct device_node *np;
int tmp, ret = 0, i;
np = of_get_child_by_name(client_dev->of_node, "regulators");
if (!np)
return -ENXIO;
for (i = 0; i < ARRAY_SIZE(pdata->dvs_gpio); i++) {
pdata->dvs_gpio[i] =
devm_gpiod_get_index_optional(client_dev, "dvs", i,
GPIOD_OUT_LOW);
if (IS_ERR(pdata->dvs_gpio[i])) {
ret = PTR_ERR(pdata->dvs_gpio[i]);
dev_err(dev, "failed to get dvs%d gpio (%d)\n", i, ret);
goto dt_parse_end;
}
if (!pdata->dvs_gpio[i]) {
dev_warn(dev, "there is no dvs%d gpio\n", i);
continue;
}
tmp = i ? RK808_DVS2_POL : RK808_DVS1_POL;
ret = regmap_update_bits(map, RK808_IO_POL_REG, tmp,
gpiod_is_active_low(pdata->dvs_gpio[i]) ?
0 : tmp);
}
dt_parse_end:
of_node_put(np);
return ret;
}
static int rk808_regulator_probe(struct platform_device *pdev)
{
struct rk808 *rk808 = dev_get_drvdata(pdev->dev.parent);
struct i2c_client *client = rk808->i2c;
struct regulator_config config = {};
struct regulator_dev *rk808_rdev;
struct rk808_regulator_data *pdata;
int ret, i;
pdata = devm_kzalloc(&pdev->dev, sizeof(*pdata), GFP_KERNEL);
if (!pdata)
return -ENOMEM;
ret = rk808_regulator_dt_parse_pdata(&pdev->dev, &client->dev,
rk808->regmap, pdata);
if (ret < 0)
return ret;
platform_set_drvdata(pdev, pdata);
config.dev = &client->dev;
config.driver_data = pdata;
config.regmap = rk808->regmap;
for (i = 0; i < RK808_NUM_REGULATORS; i++) {
rk808_rdev = devm_regulator_register(&pdev->dev,
&rk808_reg[i], &config);
if (IS_ERR(rk808_rdev)) {
dev_err(&client->dev,
"failed to register %d regulator\n", i);
return PTR_ERR(rk808_rdev);
}
}
return 0;
}
