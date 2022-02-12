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
static int s2mps11_regulator_set_voltage_time_sel(struct regulator_dev *rdev,
unsigned int old_selector,
unsigned int new_selector)
{
struct s2mps11_info *s2mps11 = rdev_get_drvdata(rdev);
unsigned int ramp_delay = 0;
int old_volt, new_volt;
switch (rdev_get_id(rdev)) {
case S2MPS11_BUCK2:
ramp_delay = s2mps11->ramp_delay2;
break;
case S2MPS11_BUCK3:
case S2MPS11_BUCK4:
ramp_delay = s2mps11->ramp_delay34;
break;
case S2MPS11_BUCK5:
ramp_delay = s2mps11->ramp_delay5;
break;
case S2MPS11_BUCK6:
case S2MPS11_BUCK1:
ramp_delay = s2mps11->ramp_delay16;
break;
case S2MPS11_BUCK7:
case S2MPS11_BUCK8:
case S2MPS11_BUCK10:
ramp_delay = s2mps11->ramp_delay7810;
break;
case S2MPS11_BUCK9:
ramp_delay = s2mps11->ramp_delay9;
}
if (ramp_delay == 0)
ramp_delay = rdev->desc->ramp_delay;
old_volt = rdev->desc->min_uV + (rdev->desc->uV_step * old_selector);
new_volt = rdev->desc->min_uV + (rdev->desc->uV_step * new_selector);
return DIV_ROUND_UP(abs(new_volt - old_volt), ramp_delay);
}
static int s2mps11_set_ramp_delay(struct regulator_dev *rdev, int ramp_delay)
{
struct s2mps11_info *s2mps11 = rdev_get_drvdata(rdev);
unsigned int ramp_val, ramp_shift, ramp_reg = S2MPS11_REG_RAMP_BUCK;
unsigned int ramp_enable = 1, enable_shift = 0;
int ret;
switch (rdev_get_id(rdev)) {
case S2MPS11_BUCK1:
if (ramp_delay > s2mps11->ramp_delay16)
s2mps11->ramp_delay16 = ramp_delay;
else
ramp_delay = s2mps11->ramp_delay16;
ramp_shift = S2MPS11_BUCK16_RAMP_SHIFT;
break;
case S2MPS11_BUCK2:
enable_shift = S2MPS11_BUCK2_RAMP_EN_SHIFT;
if (!ramp_delay) {
ramp_enable = 0;
break;
}
s2mps11->ramp_delay2 = ramp_delay;
ramp_shift = S2MPS11_BUCK2_RAMP_SHIFT;
ramp_reg = S2MPS11_REG_RAMP;
break;
case S2MPS11_BUCK3:
enable_shift = S2MPS11_BUCK3_RAMP_EN_SHIFT;
if (!ramp_delay) {
ramp_enable = 0;
break;
}
if (ramp_delay > s2mps11->ramp_delay34)
s2mps11->ramp_delay34 = ramp_delay;
else
ramp_delay = s2mps11->ramp_delay34;
ramp_shift = S2MPS11_BUCK34_RAMP_SHIFT;
ramp_reg = S2MPS11_REG_RAMP;
break;
case S2MPS11_BUCK4:
enable_shift = S2MPS11_BUCK4_RAMP_EN_SHIFT;
if (!ramp_delay) {
ramp_enable = 0;
break;
}
if (ramp_delay > s2mps11->ramp_delay34)
s2mps11->ramp_delay34 = ramp_delay;
else
ramp_delay = s2mps11->ramp_delay34;
ramp_shift = S2MPS11_BUCK34_RAMP_SHIFT;
ramp_reg = S2MPS11_REG_RAMP;
break;
case S2MPS11_BUCK5:
s2mps11->ramp_delay5 = ramp_delay;
ramp_shift = S2MPS11_BUCK5_RAMP_SHIFT;
break;
case S2MPS11_BUCK6:
enable_shift = S2MPS11_BUCK6_RAMP_EN_SHIFT;
if (!ramp_delay) {
ramp_enable = 0;
break;
}
if (ramp_delay > s2mps11->ramp_delay16)
s2mps11->ramp_delay16 = ramp_delay;
else
ramp_delay = s2mps11->ramp_delay16;
ramp_shift = S2MPS11_BUCK16_RAMP_SHIFT;
break;
case S2MPS11_BUCK7:
case S2MPS11_BUCK8:
case S2MPS11_BUCK10:
if (ramp_delay > s2mps11->ramp_delay7810)
s2mps11->ramp_delay7810 = ramp_delay;
else
ramp_delay = s2mps11->ramp_delay7810;
ramp_shift = S2MPS11_BUCK7810_RAMP_SHIFT;
break;
case S2MPS11_BUCK9:
s2mps11->ramp_delay9 = ramp_delay;
ramp_shift = S2MPS11_BUCK9_RAMP_SHIFT;
break;
default:
return 0;
}
if (!ramp_enable)
goto ramp_disable;
ret = regmap_update_bits(rdev->regmap, S2MPS11_REG_RAMP,
1 << enable_shift, 1 << enable_shift);
if (ret) {
dev_err(&rdev->dev, "failed to enable ramp rate\n");
return ret;
}
ramp_val = get_ramp_delay(ramp_delay);
return regmap_update_bits(rdev->regmap, ramp_reg, 0x3 << ramp_shift,
ramp_val << ramp_shift);
ramp_disable:
return regmap_update_bits(rdev->regmap, S2MPS11_REG_RAMP,
1 << enable_shift, 0);
}
static int s2mps14_regulator_enable(struct regulator_dev *rdev)
{
struct s2mps11_info *s2mps11 = rdev_get_drvdata(rdev);
unsigned int val;
if (s2mps11->s2mps14_suspend_state & (1 << rdev_get_id(rdev)))
val = S2MPS14_ENABLE_SUSPEND;
else
val = rdev->desc->enable_mask;
return regmap_update_bits(rdev->regmap, rdev->desc->enable_reg,
rdev->desc->enable_mask, val);
}
static int s2mps14_regulator_set_suspend_disable(struct regulator_dev *rdev)
{
int ret;
unsigned int val;
struct s2mps11_info *s2mps11 = rdev_get_drvdata(rdev);
if (rdev_get_id(rdev) == S2MPS14_LDO3)
return 0;
ret = regmap_read(rdev->regmap, rdev->desc->enable_reg, &val);
if (ret < 0)
return ret;
s2mps11->s2mps14_suspend_state |= (1 << rdev_get_id(rdev));
if (!(val & rdev->desc->enable_mask))
return 0;
return regmap_update_bits(rdev->regmap, rdev->desc->enable_reg,
rdev->desc->enable_mask, S2MPS14_ENABLE_SUSPEND);
}
static int s2mps11_pmic_probe(struct platform_device *pdev)
{
struct sec_pmic_dev *iodev = dev_get_drvdata(pdev->dev.parent);
struct sec_platform_data *pdata = iodev->pdata;
struct of_regulator_match *rdata = NULL;
struct device_node *reg_np = NULL;
struct regulator_config config = { };
struct s2mps11_info *s2mps11;
int i, ret = 0;
const struct regulator_desc *regulators;
enum sec_device_type dev_type;
s2mps11 = devm_kzalloc(&pdev->dev, sizeof(struct s2mps11_info),
GFP_KERNEL);
if (!s2mps11)
return -ENOMEM;
dev_type = platform_get_device_id(pdev)->driver_data;
switch (dev_type) {
case S2MPS11X:
s2mps11->rdev_num = ARRAY_SIZE(s2mps11_regulators);
regulators = s2mps11_regulators;
break;
case S2MPS14X:
s2mps11->rdev_num = ARRAY_SIZE(s2mps14_regulators);
regulators = s2mps14_regulators;
break;
default:
dev_err(&pdev->dev, "Invalid device type: %u\n", dev_type);
return -EINVAL;
};
if (!iodev->dev->of_node) {
if (pdata) {
goto common_reg;
} else {
dev_err(pdev->dev.parent,
"Platform data or DT node not supplied\n");
return -ENODEV;
}
}
rdata = kzalloc(sizeof(*rdata) * s2mps11->rdev_num, GFP_KERNEL);
if (!rdata)
return -ENOMEM;
for (i = 0; i < s2mps11->rdev_num; i++)
rdata[i].name = regulators[i].name;
reg_np = of_get_child_by_name(iodev->dev->of_node, "regulators");
if (!reg_np) {
dev_err(&pdev->dev, "could not find regulators sub-node\n");
ret = -EINVAL;
goto out;
}
of_regulator_match(&pdev->dev, reg_np, rdata, s2mps11->rdev_num);
of_node_put(reg_np);
common_reg:
platform_set_drvdata(pdev, s2mps11);
config.dev = &pdev->dev;
config.regmap = iodev->regmap_pmic;
config.driver_data = s2mps11;
for (i = 0; i < s2mps11->rdev_num; i++) {
struct regulator_dev *regulator;
if (!reg_np) {
config.init_data = pdata->regulators[i].initdata;
config.of_node = pdata->regulators[i].reg_node;
} else {
config.init_data = rdata[i].init_data;
config.of_node = rdata[i].of_node;
}
regulator = devm_regulator_register(&pdev->dev,
&regulators[i], &config);
if (IS_ERR(regulator)) {
ret = PTR_ERR(regulator);
dev_err(&pdev->dev, "regulator init failed for %d\n",
i);
goto out;
}
}
out:
kfree(rdata);
return ret;
}
static int __init s2mps11_pmic_init(void)
{
return platform_driver_register(&s2mps11_pmic_driver);
}
static void __exit s2mps11_pmic_exit(void)
{
platform_driver_unregister(&s2mps11_pmic_driver);
}
