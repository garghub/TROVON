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
if ((rdev_get_id(rdev) >= S2MPS11_BUCK2 &&
rdev_get_id(rdev) <= S2MPS11_BUCK4) ||
rdev_get_id(rdev) == S2MPS11_BUCK6) {
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
static int s2mps14_regulator_enable(struct regulator_dev *rdev)
{
struct s2mps11_info *s2mps11 = rdev_get_drvdata(rdev);
unsigned int val;
switch (s2mps11->dev_type) {
case S2MPS13X:
case S2MPS14X:
if (test_bit(rdev_get_id(rdev), s2mps11->suspend_state))
val = S2MPS14_ENABLE_SUSPEND;
else if (gpio_is_valid(s2mps11->ext_control_gpio[rdev_get_id(rdev)]))
val = S2MPS14_ENABLE_EXT_CONTROL;
else
val = rdev->desc->enable_mask;
break;
case S2MPU02:
if (test_bit(rdev_get_id(rdev), s2mps11->suspend_state))
val = S2MPU02_ENABLE_SUSPEND;
else
val = rdev->desc->enable_mask;
break;
default:
return -EINVAL;
}
return regmap_update_bits(rdev->regmap, rdev->desc->enable_reg,
rdev->desc->enable_mask, val);
}
static int s2mps14_regulator_set_suspend_disable(struct regulator_dev *rdev)
{
int ret;
unsigned int val, state;
struct s2mps11_info *s2mps11 = rdev_get_drvdata(rdev);
int rdev_id = rdev_get_id(rdev);
switch (s2mps11->dev_type) {
case S2MPS13X:
case S2MPS14X:
switch (rdev_id) {
case S2MPS14_LDO3:
return 0;
default:
state = S2MPS14_ENABLE_SUSPEND;
break;
}
break;
case S2MPU02:
switch (rdev_id) {
case S2MPU02_LDO13:
case S2MPU02_LDO14:
case S2MPU02_LDO15:
case S2MPU02_LDO17:
case S2MPU02_BUCK7:
state = S2MPU02_DISABLE_SUSPEND;
break;
default:
state = S2MPU02_ENABLE_SUSPEND;
break;
}
break;
default:
return -EINVAL;
}
ret = regmap_read(rdev->regmap, rdev->desc->enable_reg, &val);
if (ret < 0)
return ret;
set_bit(rdev_get_id(rdev), s2mps11->suspend_state);
if (!(val & rdev->desc->enable_mask))
return 0;
return regmap_update_bits(rdev->regmap, rdev->desc->enable_reg,
rdev->desc->enable_mask, state);
}
static int s2mps14_pmic_enable_ext_control(struct s2mps11_info *s2mps11,
struct regulator_dev *rdev)
{
return regmap_update_bits(rdev->regmap, rdev->desc->enable_reg,
rdev->desc->enable_mask, S2MPS14_ENABLE_EXT_CONTROL);
}
static void s2mps14_pmic_dt_parse_ext_control_gpio(struct platform_device *pdev,
struct of_regulator_match *rdata, struct s2mps11_info *s2mps11)
{
int *gpio = s2mps11->ext_control_gpio;
unsigned int i;
unsigned int valid_regulators[3] = { S2MPS14_LDO10, S2MPS14_LDO11,
S2MPS14_LDO12 };
for (i = 0; i < ARRAY_SIZE(valid_regulators); i++) {
unsigned int reg = valid_regulators[i];
if (!rdata[reg].init_data || !rdata[reg].of_node)
continue;
gpio[reg] = of_get_named_gpio(rdata[reg].of_node,
"samsung,ext-control-gpios", 0);
if (gpio_is_valid(gpio[reg]))
dev_dbg(&pdev->dev, "Using GPIO %d for ext-control over %d/%s\n",
gpio[reg], reg, rdata[reg].name);
}
}
static int s2mps11_pmic_dt_parse(struct platform_device *pdev,
struct of_regulator_match *rdata, struct s2mps11_info *s2mps11,
unsigned int rdev_num)
{
struct device_node *reg_np;
reg_np = of_get_child_by_name(pdev->dev.parent->of_node, "regulators");
if (!reg_np) {
dev_err(&pdev->dev, "could not find regulators sub-node\n");
return -EINVAL;
}
of_regulator_match(&pdev->dev, reg_np, rdata, rdev_num);
if (s2mps11->dev_type == S2MPS14X)
s2mps14_pmic_dt_parse_ext_control_gpio(pdev, rdata, s2mps11);
of_node_put(reg_np);
return 0;
}
static int s2mpu02_set_ramp_delay(struct regulator_dev *rdev, int ramp_delay)
{
unsigned int ramp_val, ramp_shift, ramp_reg;
switch (rdev_get_id(rdev)) {
case S2MPU02_BUCK1:
ramp_shift = S2MPU02_BUCK1_RAMP_SHIFT;
break;
case S2MPU02_BUCK2:
ramp_shift = S2MPU02_BUCK2_RAMP_SHIFT;
break;
case S2MPU02_BUCK3:
ramp_shift = S2MPU02_BUCK3_RAMP_SHIFT;
break;
case S2MPU02_BUCK4:
ramp_shift = S2MPU02_BUCK4_RAMP_SHIFT;
break;
default:
return 0;
}
ramp_reg = S2MPU02_REG_RAMP1;
ramp_val = get_ramp_delay(ramp_delay);
return regmap_update_bits(rdev->regmap, ramp_reg,
S2MPU02_BUCK1234_RAMP_MASK << ramp_shift,
ramp_val << ramp_shift);
}
static int s2mps11_pmic_probe(struct platform_device *pdev)
{
struct sec_pmic_dev *iodev = dev_get_drvdata(pdev->dev.parent);
struct sec_platform_data *pdata = NULL;
struct of_regulator_match *rdata = NULL;
struct regulator_config config = { };
struct s2mps11_info *s2mps11;
unsigned int rdev_num = 0;
int i, ret = 0;
const struct regulator_desc *regulators;
s2mps11 = devm_kzalloc(&pdev->dev, sizeof(struct s2mps11_info),
GFP_KERNEL);
if (!s2mps11)
return -ENOMEM;
s2mps11->dev_type = platform_get_device_id(pdev)->driver_data;
switch (s2mps11->dev_type) {
case S2MPS11X:
rdev_num = ARRAY_SIZE(s2mps11_regulators);
regulators = s2mps11_regulators;
BUILD_BUG_ON(S2MPS_REGULATOR_MAX < ARRAY_SIZE(s2mps11_regulators));
break;
case S2MPS13X:
rdev_num = ARRAY_SIZE(s2mps13_regulators);
regulators = s2mps13_regulators;
BUILD_BUG_ON(S2MPS_REGULATOR_MAX < ARRAY_SIZE(s2mps13_regulators));
break;
case S2MPS14X:
rdev_num = ARRAY_SIZE(s2mps14_regulators);
regulators = s2mps14_regulators;
BUILD_BUG_ON(S2MPS_REGULATOR_MAX < ARRAY_SIZE(s2mps14_regulators));
break;
case S2MPS15X:
rdev_num = ARRAY_SIZE(s2mps15_regulators);
regulators = s2mps15_regulators;
BUILD_BUG_ON(S2MPS_REGULATOR_MAX < ARRAY_SIZE(s2mps15_regulators));
break;
case S2MPU02:
rdev_num = ARRAY_SIZE(s2mpu02_regulators);
regulators = s2mpu02_regulators;
BUILD_BUG_ON(S2MPS_REGULATOR_MAX < ARRAY_SIZE(s2mpu02_regulators));
break;
default:
dev_err(&pdev->dev, "Invalid device type: %u\n",
s2mps11->dev_type);
return -EINVAL;
}
s2mps11->ext_control_gpio = devm_kmalloc(&pdev->dev,
sizeof(*s2mps11->ext_control_gpio) * rdev_num,
GFP_KERNEL);
if (!s2mps11->ext_control_gpio)
return -ENOMEM;
for (i = 0; i < rdev_num; i++)
s2mps11->ext_control_gpio[i] = -EINVAL;
if (!iodev->dev->of_node) {
if (iodev->pdata) {
pdata = iodev->pdata;
goto common_reg;
} else {
dev_err(pdev->dev.parent,
"Platform data or DT node not supplied\n");
return -ENODEV;
}
}
rdata = kzalloc(sizeof(*rdata) * rdev_num, GFP_KERNEL);
if (!rdata)
return -ENOMEM;
for (i = 0; i < rdev_num; i++)
rdata[i].name = regulators[i].name;
ret = s2mps11_pmic_dt_parse(pdev, rdata, s2mps11, rdev_num);
if (ret)
goto out;
common_reg:
platform_set_drvdata(pdev, s2mps11);
config.dev = &pdev->dev;
config.regmap = iodev->regmap_pmic;
config.driver_data = s2mps11;
config.ena_gpio_flags = GPIOF_OUT_INIT_HIGH;
config.ena_gpio_initialized = true;
for (i = 0; i < rdev_num; i++) {
struct regulator_dev *regulator;
if (pdata) {
config.init_data = pdata->regulators[i].initdata;
config.of_node = pdata->regulators[i].reg_node;
} else {
config.init_data = rdata[i].init_data;
config.of_node = rdata[i].of_node;
}
config.ena_gpio = s2mps11->ext_control_gpio[i];
regulator = devm_regulator_register(&pdev->dev,
&regulators[i], &config);
if (IS_ERR(regulator)) {
ret = PTR_ERR(regulator);
dev_err(&pdev->dev, "regulator init failed for %d\n",
i);
goto out;
}
if (gpio_is_valid(s2mps11->ext_control_gpio[i])) {
ret = s2mps14_pmic_enable_ext_control(s2mps11,
regulator);
if (ret < 0) {
dev_err(&pdev->dev,
"failed to enable GPIO control over %s: %d\n",
regulator->desc->name, ret);
goto out;
}
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
