static int get_ramp_delay(int ramp_delay)
{
unsigned char cnt = 0;
ramp_delay /= 6250;
while (true) {
ramp_delay = ramp_delay >> 1;
if (ramp_delay == 0)
break;
cnt++;
}
if (cnt > 3)
cnt = 3;
return cnt;
}
static int s2mpa01_regulator_set_voltage_time_sel(struct regulator_dev *rdev,
unsigned int old_selector,
unsigned int new_selector)
{
struct s2mpa01_info *s2mpa01 = rdev_get_drvdata(rdev);
unsigned int ramp_delay = 0;
int old_volt, new_volt;
switch (rdev_get_id(rdev)) {
case S2MPA01_BUCK2:
case S2MPA01_BUCK4:
ramp_delay = s2mpa01->ramp_delay24;
break;
case S2MPA01_BUCK3:
ramp_delay = s2mpa01->ramp_delay3;
break;
case S2MPA01_BUCK5:
ramp_delay = s2mpa01->ramp_delay5;
break;
case S2MPA01_BUCK1:
case S2MPA01_BUCK6:
ramp_delay = s2mpa01->ramp_delay16;
break;
case S2MPA01_BUCK7:
ramp_delay = s2mpa01->ramp_delay7;
break;
case S2MPA01_BUCK8:
case S2MPA01_BUCK9:
case S2MPA01_BUCK10:
ramp_delay = s2mpa01->ramp_delay8910;
break;
}
if (ramp_delay == 0)
ramp_delay = rdev->desc->ramp_delay;
old_volt = rdev->desc->min_uV + (rdev->desc->uV_step * old_selector);
new_volt = rdev->desc->min_uV + (rdev->desc->uV_step * new_selector);
return DIV_ROUND_UP(abs(new_volt - old_volt), ramp_delay);
}
static int s2mpa01_set_ramp_delay(struct regulator_dev *rdev, int ramp_delay)
{
struct s2mpa01_info *s2mpa01 = rdev_get_drvdata(rdev);
unsigned int ramp_val, ramp_shift, ramp_reg = S2MPA01_REG_RAMP2;
unsigned int ramp_enable = 1, enable_shift = 0;
int ret;
switch (rdev_get_id(rdev)) {
case S2MPA01_BUCK1:
enable_shift = S2MPA01_BUCK1_RAMP_EN_SHIFT;
if (!ramp_delay) {
ramp_enable = 0;
break;
}
if (ramp_delay > s2mpa01->ramp_delay16)
s2mpa01->ramp_delay16 = ramp_delay;
else
ramp_delay = s2mpa01->ramp_delay16;
ramp_shift = S2MPA01_BUCK16_RAMP_SHIFT;
break;
case S2MPA01_BUCK2:
enable_shift = S2MPA01_BUCK2_RAMP_EN_SHIFT;
if (!ramp_delay) {
ramp_enable = 0;
break;
}
if (ramp_delay > s2mpa01->ramp_delay24)
s2mpa01->ramp_delay24 = ramp_delay;
else
ramp_delay = s2mpa01->ramp_delay24;
ramp_shift = S2MPA01_BUCK24_RAMP_SHIFT;
ramp_reg = S2MPA01_REG_RAMP1;
break;
case S2MPA01_BUCK3:
enable_shift = S2MPA01_BUCK3_RAMP_EN_SHIFT;
if (!ramp_delay) {
ramp_enable = 0;
break;
}
s2mpa01->ramp_delay3 = ramp_delay;
ramp_shift = S2MPA01_BUCK3_RAMP_SHIFT;
ramp_reg = S2MPA01_REG_RAMP1;
break;
case S2MPA01_BUCK4:
enable_shift = S2MPA01_BUCK4_RAMP_EN_SHIFT;
if (!ramp_delay) {
ramp_enable = 0;
break;
}
if (ramp_delay > s2mpa01->ramp_delay24)
s2mpa01->ramp_delay24 = ramp_delay;
else
ramp_delay = s2mpa01->ramp_delay24;
ramp_shift = S2MPA01_BUCK24_RAMP_SHIFT;
ramp_reg = S2MPA01_REG_RAMP1;
break;
case S2MPA01_BUCK5:
s2mpa01->ramp_delay5 = ramp_delay;
ramp_shift = S2MPA01_BUCK5_RAMP_SHIFT;
break;
case S2MPA01_BUCK6:
if (ramp_delay > s2mpa01->ramp_delay16)
s2mpa01->ramp_delay16 = ramp_delay;
else
ramp_delay = s2mpa01->ramp_delay16;
ramp_shift = S2MPA01_BUCK16_RAMP_SHIFT;
break;
case S2MPA01_BUCK7:
s2mpa01->ramp_delay7 = ramp_delay;
ramp_shift = S2MPA01_BUCK7_RAMP_SHIFT;
break;
case S2MPA01_BUCK8:
case S2MPA01_BUCK9:
case S2MPA01_BUCK10:
if (ramp_delay > s2mpa01->ramp_delay8910)
s2mpa01->ramp_delay8910 = ramp_delay;
else
ramp_delay = s2mpa01->ramp_delay8910;
ramp_shift = S2MPA01_BUCK8910_RAMP_SHIFT;
break;
default:
return 0;
}
if (!ramp_enable)
goto ramp_disable;
if (rdev_get_id(rdev) >= S2MPA01_BUCK1 &&
rdev_get_id(rdev) <= S2MPA01_BUCK4) {
ret = regmap_update_bits(rdev->regmap, S2MPA01_REG_RAMP1,
1 << enable_shift, 1 << enable_shift);
if (ret) {
dev_err(&rdev->dev, "failed to enable ramp rate\n");
return ret;
}
}
ramp_val = get_ramp_delay(ramp_delay);
return regmap_update_bits(rdev->regmap, ramp_reg, 0x3 << ramp_shift,
ramp_val << ramp_shift);
ramp_disable:
return regmap_update_bits(rdev->regmap, S2MPA01_REG_RAMP1,
1 << enable_shift, 0);
}
static int s2mpa01_pmic_probe(struct platform_device *pdev)
{
struct sec_pmic_dev *iodev = dev_get_drvdata(pdev->dev.parent);
struct sec_platform_data *pdata = dev_get_platdata(iodev->dev);
struct of_regulator_match rdata[S2MPA01_REGULATOR_MAX] = { };
struct device_node *reg_np = NULL;
struct regulator_config config = { };
struct s2mpa01_info *s2mpa01;
int i;
s2mpa01 = devm_kzalloc(&pdev->dev, sizeof(*s2mpa01), GFP_KERNEL);
if (!s2mpa01)
return -ENOMEM;
for (i = 0; i < S2MPA01_REGULATOR_CNT; i++)
rdata[i].name = regulators[i].name;
if (iodev->dev->of_node) {
reg_np = of_get_child_by_name(iodev->dev->of_node,
"regulators");
if (!reg_np) {
dev_err(&pdev->dev,
"could not find regulators sub-node\n");
return -EINVAL;
}
of_regulator_match(&pdev->dev, reg_np, rdata,
S2MPA01_REGULATOR_MAX);
of_node_put(reg_np);
}
platform_set_drvdata(pdev, s2mpa01);
config.dev = &pdev->dev;
config.regmap = iodev->regmap_pmic;
config.driver_data = s2mpa01;
for (i = 0; i < S2MPA01_REGULATOR_MAX; i++) {
struct regulator_dev *rdev;
if (pdata)
config.init_data = pdata->regulators[i].initdata;
else
config.init_data = rdata[i].init_data;
if (reg_np)
config.of_node = rdata[i].of_node;
rdev = devm_regulator_register(&pdev->dev,
&regulators[i], &config);
if (IS_ERR(rdev)) {
dev_err(&pdev->dev, "regulator init failed for %d\n",
i);
return PTR_ERR(rdev);
}
}
return 0;
}
