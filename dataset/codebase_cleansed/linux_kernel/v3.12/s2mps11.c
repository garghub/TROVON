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
switch (rdev->desc->id) {
case S2MPS11_BUCK2:
ramp_delay = s2mps11->ramp_delay2;
break;
case S2MPS11_BUCK3:
ramp_delay = s2mps11->ramp_delay34;
break;
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
switch (rdev->desc->id) {
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
if (enable_shift) {
ret = regmap_update_bits(rdev->regmap, S2MPS11_REG_RAMP,
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
return regmap_update_bits(rdev->regmap, S2MPS11_REG_RAMP,
1 << enable_shift, 0);
}
static int s2mps11_pmic_probe(struct platform_device *pdev)
{
struct sec_pmic_dev *iodev = dev_get_drvdata(pdev->dev.parent);
struct sec_platform_data *pdata = dev_get_platdata(iodev->dev);
struct of_regulator_match rdata[S2MPS11_REGULATOR_MAX];
struct device_node *reg_np = NULL;
struct regulator_config config = { };
struct s2mps11_info *s2mps11;
int i, ret;
s2mps11 = devm_kzalloc(&pdev->dev, sizeof(struct s2mps11_info),
GFP_KERNEL);
if (!s2mps11)
return -ENOMEM;
if (!iodev->dev->of_node) {
if (pdata) {
goto common_reg;
} else {
dev_err(pdev->dev.parent,
"Platform data or DT node not supplied\n");
return -ENODEV;
}
}
for (i = 0; i < S2MPS11_REGULATOR_CNT; i++)
rdata[i].name = regulators[i].name;
reg_np = of_find_node_by_name(iodev->dev->of_node, "regulators");
if (!reg_np) {
dev_err(&pdev->dev, "could not find regulators sub-node\n");
return -EINVAL;
}
of_regulator_match(&pdev->dev, reg_np, rdata, S2MPS11_REGULATOR_MAX);
common_reg:
platform_set_drvdata(pdev, s2mps11);
config.dev = &pdev->dev;
config.regmap = iodev->regmap;
config.driver_data = s2mps11;
for (i = 0; i < S2MPS11_REGULATOR_MAX; i++) {
if (!reg_np) {
config.init_data = pdata->regulators[i].initdata;
} else {
config.init_data = rdata[i].init_data;
config.of_node = rdata[i].of_node;
}
s2mps11->rdev[i] = regulator_register(&regulators[i], &config);
if (IS_ERR(s2mps11->rdev[i])) {
ret = PTR_ERR(s2mps11->rdev[i]);
dev_err(&pdev->dev, "regulator init failed for %d\n",
i);
s2mps11->rdev[i] = NULL;
goto err;
}
}
return 0;
err:
for (i = 0; i < S2MPS11_REGULATOR_MAX; i++)
regulator_unregister(s2mps11->rdev[i]);
return ret;
}
static int s2mps11_pmic_remove(struct platform_device *pdev)
{
struct s2mps11_info *s2mps11 = platform_get_drvdata(pdev);
int i;
for (i = 0; i < S2MPS11_REGULATOR_MAX; i++)
regulator_unregister(s2mps11->rdev[i]);
return 0;
}
static int __init s2mps11_pmic_init(void)
{
return platform_driver_register(&s2mps11_pmic_driver);
}
static void __exit s2mps11_pmic_exit(void)
{
platform_driver_unregister(&s2mps11_pmic_driver);
}
