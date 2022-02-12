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
static int rk808_regulator_probe(struct platform_device *pdev)
{
struct rk808 *rk808 = dev_get_drvdata(pdev->dev.parent);
struct i2c_client *client = rk808->i2c;
struct device_node *reg_np;
struct regulator_config config = {};
struct regulator_dev *rk808_rdev;
int ret, i;
reg_np = of_get_child_by_name(client->dev.of_node, "regulators");
if (!reg_np)
return -ENXIO;
ret = of_regulator_match(&pdev->dev, reg_np, rk808_reg_matches,
RK808_NUM_REGULATORS);
of_node_put(reg_np);
if (ret < 0)
return ret;
for (i = 0; i < RK808_NUM_REGULATORS; i++) {
if (!rk808_reg_matches[i].init_data ||
!rk808_reg_matches[i].of_node)
continue;
config.dev = &client->dev;
config.driver_data = rk808;
config.regmap = rk808->regmap;
config.of_node = rk808_reg_matches[i].of_node;
config.init_data = rk808_reg_matches[i].init_data;
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
