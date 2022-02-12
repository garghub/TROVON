static int s5m8767_list_voltage(struct regulator_dev *rdev,
unsigned int selector)
{
const struct s5m_voltage_desc *desc;
int reg_id = rdev_get_id(rdev);
int val;
if (reg_id >= ARRAY_SIZE(reg_voltage_map) || reg_id < 0)
return -EINVAL;
desc = reg_voltage_map[reg_id];
if (desc == NULL)
return -EINVAL;
val = desc->min + desc->step * selector;
if (val > desc->max)
return -EINVAL;
return val;
}
static int s5m8767_get_register(struct regulator_dev *rdev, int *reg)
{
int reg_id = rdev_get_id(rdev);
switch (reg_id) {
case S5M8767_LDO1 ... S5M8767_LDO2:
*reg = S5M8767_REG_LDO1CTRL + (reg_id - S5M8767_LDO1);
break;
case S5M8767_LDO3 ... S5M8767_LDO28:
*reg = S5M8767_REG_LDO3CTRL + (reg_id - S5M8767_LDO3);
break;
case S5M8767_BUCK1:
*reg = S5M8767_REG_BUCK1CTRL1;
break;
case S5M8767_BUCK2 ... S5M8767_BUCK4:
*reg = S5M8767_REG_BUCK2CTRL + (reg_id - S5M8767_BUCK2) * 9;
break;
case S5M8767_BUCK5:
*reg = S5M8767_REG_BUCK5CTRL1;
break;
case S5M8767_BUCK6 ... S5M8767_BUCK9:
*reg = S5M8767_REG_BUCK6CTRL1 + (reg_id - S5M8767_BUCK6) * 2;
break;
default:
return -EINVAL;
}
return 0;
}
static int s5m8767_reg_is_enabled(struct regulator_dev *rdev)
{
struct s5m8767_info *s5m8767 = rdev_get_drvdata(rdev);
int ret, reg;
int mask = 0xc0, pattern = 0xc0;
u8 val;
ret = s5m8767_get_register(rdev, &reg);
if (ret == -EINVAL)
return 1;
else if (ret)
return ret;
ret = s5m_reg_read(s5m8767->iodev, reg, &val);
if (ret)
return ret;
return (val & mask) == pattern;
}
static int s5m8767_reg_enable(struct regulator_dev *rdev)
{
struct s5m8767_info *s5m8767 = rdev_get_drvdata(rdev);
int ret, reg;
int mask = 0xc0, pattern = 0xc0;
ret = s5m8767_get_register(rdev, &reg);
if (ret)
return ret;
return s5m_reg_update(s5m8767->iodev, reg, pattern, mask);
}
static int s5m8767_reg_disable(struct regulator_dev *rdev)
{
struct s5m8767_info *s5m8767 = rdev_get_drvdata(rdev);
int ret, reg;
int mask = 0xc0, pattern = 0xc0;
ret = s5m8767_get_register(rdev, &reg);
if (ret)
return ret;
return s5m_reg_update(s5m8767->iodev, reg, ~pattern, mask);
}
static int s5m8767_get_voltage_register(struct regulator_dev *rdev, int *_reg)
{
struct s5m8767_info *s5m8767 = rdev_get_drvdata(rdev);
int reg_id = rdev_get_id(rdev);
int reg;
switch (reg_id) {
case S5M8767_LDO1 ... S5M8767_LDO2:
reg = S5M8767_REG_LDO1CTRL + (reg_id - S5M8767_LDO1);
break;
case S5M8767_LDO3 ... S5M8767_LDO28:
reg = S5M8767_REG_LDO3CTRL + (reg_id - S5M8767_LDO3);
break;
case S5M8767_BUCK1:
reg = S5M8767_REG_BUCK1CTRL2;
break;
case S5M8767_BUCK2:
reg = S5M8767_REG_BUCK2DVS1;
if (s5m8767->buck2_gpiodvs)
reg += s5m8767->buck_gpioindex;
break;
case S5M8767_BUCK3:
reg = S5M8767_REG_BUCK3DVS1;
if (s5m8767->buck3_gpiodvs)
reg += s5m8767->buck_gpioindex;
break;
case S5M8767_BUCK4:
reg = S5M8767_REG_BUCK4DVS1;
if (s5m8767->buck4_gpiodvs)
reg += s5m8767->buck_gpioindex;
break;
case S5M8767_BUCK5:
reg = S5M8767_REG_BUCK5CTRL2;
break;
case S5M8767_BUCK6 ... S5M8767_BUCK9:
reg = S5M8767_REG_BUCK6CTRL2 + (reg_id - S5M8767_BUCK6) * 2;
break;
default:
return -EINVAL;
}
*_reg = reg;
return 0;
}
static int s5m8767_get_voltage_sel(struct regulator_dev *rdev)
{
struct s5m8767_info *s5m8767 = rdev_get_drvdata(rdev);
int reg, mask, ret;
int reg_id = rdev_get_id(rdev);
u8 val;
ret = s5m8767_get_voltage_register(rdev, &reg);
if (ret)
return ret;
mask = (reg_id < S5M8767_BUCK1) ? 0x3f : 0xff;
ret = s5m_reg_read(s5m8767->iodev, reg, &val);
if (ret)
return ret;
val &= mask;
return val;
}
static int s5m8767_convert_voltage_to_sel(
const struct s5m_voltage_desc *desc,
int min_vol, int max_vol)
{
int selector = 0;
if (desc == NULL)
return -EINVAL;
if (max_vol < desc->min || min_vol > desc->max)
return -EINVAL;
selector = (min_vol - desc->min) / desc->step;
if (desc->min + desc->step * selector > max_vol)
return -EINVAL;
return selector;
}
static int s5m8767_set_voltage(struct regulator_dev *rdev,
int min_uV, int max_uV, unsigned *selector)
{
struct s5m8767_info *s5m8767 = rdev_get_drvdata(rdev);
const struct s5m_voltage_desc *desc;
int reg_id = rdev_get_id(rdev);
int sel, reg, mask, ret;
u8 val;
switch (reg_id) {
case S5M8767_LDO1 ... S5M8767_LDO28:
mask = 0x3f;
break;
case S5M8767_BUCK1 ... S5M8767_BUCK6:
mask = 0xff;
break;
case S5M8767_BUCK7 ... S5M8767_BUCK8:
return -EINVAL;
case S5M8767_BUCK9:
mask = 0xff;
break;
default:
return -EINVAL;
}
desc = reg_voltage_map[reg_id];
sel = s5m8767_convert_voltage_to_sel(desc, min_uV, max_uV);
if (sel < 0)
return sel;
ret = s5m8767_get_voltage_register(rdev, &reg);
if (ret)
return ret;
s5m_reg_read(s5m8767->iodev, reg, &val);
val &= ~mask;
val |= sel;
ret = s5m_reg_write(s5m8767->iodev, reg, val);
*selector = sel;
return ret;
}
static inline void s5m8767_set_high(struct s5m8767_info *s5m8767)
{
int temp_index = s5m8767->buck_gpioindex;
gpio_set_value(s5m8767->buck_gpios[0], (temp_index >> 2) & 0x1);
gpio_set_value(s5m8767->buck_gpios[1], (temp_index >> 1) & 0x1);
gpio_set_value(s5m8767->buck_gpios[2], temp_index & 0x1);
}
static inline void s5m8767_set_low(struct s5m8767_info *s5m8767)
{
int temp_index = s5m8767->buck_gpioindex;
gpio_set_value(s5m8767->buck_gpios[2], temp_index & 0x1);
gpio_set_value(s5m8767->buck_gpios[1], (temp_index >> 1) & 0x1);
gpio_set_value(s5m8767->buck_gpios[0], (temp_index >> 2) & 0x1);
}
static int s5m8767_set_voltage_buck(struct regulator_dev *rdev,
int min_uV, int max_uV, unsigned *selector)
{
struct s5m8767_info *s5m8767 = rdev_get_drvdata(rdev);
int reg_id = rdev_get_id(rdev);
const struct s5m_voltage_desc *desc;
int new_val, old_val, i = 0;
if (reg_id < S5M8767_BUCK1 || reg_id > S5M8767_BUCK6)
return -EINVAL;
switch (reg_id) {
case S5M8767_BUCK1:
return s5m8767_set_voltage(rdev, min_uV, max_uV, selector);
case S5M8767_BUCK2 ... S5M8767_BUCK4:
break;
case S5M8767_BUCK5 ... S5M8767_BUCK6:
return s5m8767_set_voltage(rdev, min_uV, max_uV, selector);
case S5M8767_BUCK9:
return s5m8767_set_voltage(rdev, min_uV, max_uV, selector);
}
desc = reg_voltage_map[reg_id];
new_val = s5m8767_convert_voltage_to_sel(desc, min_uV, max_uV);
if (new_val < 0)
return new_val;
switch (reg_id) {
case S5M8767_BUCK2:
if (s5m8767->buck2_gpiodvs) {
while (s5m8767->buck2_vol[i] != new_val)
i++;
} else
return s5m8767_set_voltage(rdev, min_uV,
max_uV, selector);
break;
case S5M8767_BUCK3:
if (s5m8767->buck3_gpiodvs) {
while (s5m8767->buck3_vol[i] != new_val)
i++;
} else
return s5m8767_set_voltage(rdev, min_uV,
max_uV, selector);
break;
case S5M8767_BUCK4:
if (s5m8767->buck3_gpiodvs) {
while (s5m8767->buck4_vol[i] != new_val)
i++;
} else
return s5m8767_set_voltage(rdev, min_uV,
max_uV, selector);
break;
}
old_val = s5m8767->buck_gpioindex;
s5m8767->buck_gpioindex = i;
if (i > old_val)
s5m8767_set_high(s5m8767);
else
s5m8767_set_low(s5m8767);
*selector = new_val;
return 0;
}
static int s5m8767_set_voltage_time_sel(struct regulator_dev *rdev,
unsigned int old_sel,
unsigned int new_sel)
{
struct s5m8767_info *s5m8767 = rdev_get_drvdata(rdev);
const struct s5m_voltage_desc *desc;
int reg_id = rdev_get_id(rdev);
desc = reg_voltage_map[reg_id];
if (old_sel < new_sel)
return DIV_ROUND_UP(desc->step * (new_sel - old_sel),
s5m8767->ramp_delay * 1000);
return 0;
}
static __devinit int s5m8767_pmic_probe(struct platform_device *pdev)
{
struct s5m87xx_dev *iodev = dev_get_drvdata(pdev->dev.parent);
struct s5m_platform_data *pdata = dev_get_platdata(iodev->dev);
struct regulator_dev **rdev;
struct s5m8767_info *s5m8767;
int i, ret, size;
if (!pdata) {
dev_err(pdev->dev.parent, "Platform data not supplied\n");
return -ENODEV;
}
if (pdata->buck2_gpiodvs) {
if (pdata->buck3_gpiodvs || pdata->buck4_gpiodvs) {
dev_err(&pdev->dev, "S5M8767 GPIO DVS NOT VALID\n");
return -EINVAL;
}
}
if (pdata->buck3_gpiodvs) {
if (pdata->buck2_gpiodvs || pdata->buck4_gpiodvs) {
dev_err(&pdev->dev, "S5M8767 GPIO DVS NOT VALID\n");
return -EINVAL;
}
}
if (pdata->buck4_gpiodvs) {
if (pdata->buck2_gpiodvs || pdata->buck3_gpiodvs) {
dev_err(&pdev->dev, "S5M8767 GPIO DVS NOT VALID\n");
return -EINVAL;
}
}
s5m8767 = devm_kzalloc(&pdev->dev, sizeof(struct s5m8767_info),
GFP_KERNEL);
if (!s5m8767)
return -ENOMEM;
size = sizeof(struct regulator_dev *) * (S5M8767_REG_MAX - 2);
s5m8767->rdev = devm_kzalloc(&pdev->dev, size, GFP_KERNEL);
if (!s5m8767->rdev)
return -ENOMEM;
rdev = s5m8767->rdev;
s5m8767->dev = &pdev->dev;
s5m8767->iodev = iodev;
s5m8767->num_regulators = S5M8767_REG_MAX - 2;
platform_set_drvdata(pdev, s5m8767);
s5m8767->buck_gpioindex = pdata->buck_default_idx;
s5m8767->buck2_gpiodvs = pdata->buck2_gpiodvs;
s5m8767->buck3_gpiodvs = pdata->buck3_gpiodvs;
s5m8767->buck4_gpiodvs = pdata->buck4_gpiodvs;
s5m8767->buck_gpios[0] = pdata->buck_gpios[0];
s5m8767->buck_gpios[1] = pdata->buck_gpios[1];
s5m8767->buck_gpios[2] = pdata->buck_gpios[2];
s5m8767->ramp_delay = pdata->buck_ramp_delay;
s5m8767->buck2_ramp = pdata->buck2_ramp_enable;
s5m8767->buck3_ramp = pdata->buck3_ramp_enable;
s5m8767->buck4_ramp = pdata->buck4_ramp_enable;
for (i = 0; i < 8; i++) {
if (s5m8767->buck2_gpiodvs) {
s5m8767->buck2_vol[i] =
s5m8767_convert_voltage_to_sel(
&buck_voltage_val2,
pdata->buck2_voltage[i],
pdata->buck2_voltage[i] +
buck_voltage_val2.step);
}
if (s5m8767->buck3_gpiodvs) {
s5m8767->buck3_vol[i] =
s5m8767_convert_voltage_to_sel(
&buck_voltage_val2,
pdata->buck3_voltage[i],
pdata->buck3_voltage[i] +
buck_voltage_val2.step);
}
if (s5m8767->buck4_gpiodvs) {
s5m8767->buck4_vol[i] =
s5m8767_convert_voltage_to_sel(
&buck_voltage_val2,
pdata->buck4_voltage[i],
pdata->buck4_voltage[i] +
buck_voltage_val2.step);
}
}
if (pdata->buck2_gpiodvs || pdata->buck3_gpiodvs ||
pdata->buck4_gpiodvs) {
if (gpio_is_valid(pdata->buck_gpios[0]) &&
gpio_is_valid(pdata->buck_gpios[1]) &&
gpio_is_valid(pdata->buck_gpios[2])) {
ret = gpio_request(pdata->buck_gpios[0],
"S5M8767 SET1");
if (ret == -EBUSY)
dev_warn(&pdev->dev, "Duplicated gpio request for SET1\n");
ret = gpio_request(pdata->buck_gpios[1],
"S5M8767 SET2");
if (ret == -EBUSY)
dev_warn(&pdev->dev, "Duplicated gpio request for SET2\n");
ret = gpio_request(pdata->buck_gpios[2],
"S5M8767 SET3");
if (ret == -EBUSY)
dev_warn(&pdev->dev, "Duplicated gpio request for SET3\n");
gpio_direction_output(pdata->buck_gpios[0],
(s5m8767->buck_gpioindex >> 2) & 0x1);
gpio_direction_output(pdata->buck_gpios[1],
(s5m8767->buck_gpioindex >> 1) & 0x1);
gpio_direction_output(pdata->buck_gpios[2],
(s5m8767->buck_gpioindex >> 0) & 0x1);
ret = 0;
} else {
dev_err(&pdev->dev, "GPIO NOT VALID\n");
ret = -EINVAL;
return ret;
}
}
s5m_reg_update(s5m8767->iodev, S5M8767_REG_BUCK2CTRL,
(pdata->buck2_gpiodvs) ? (1 << 1) : (0 << 1), 1 << 1);
s5m_reg_update(s5m8767->iodev, S5M8767_REG_BUCK3CTRL,
(pdata->buck3_gpiodvs) ? (1 << 1) : (0 << 1), 1 << 1);
s5m_reg_update(s5m8767->iodev, S5M8767_REG_BUCK4CTRL,
(pdata->buck4_gpiodvs) ? (1 << 1) : (0 << 1), 1 << 1);
for (i = 0; i < 8; i++) {
if (s5m8767->buck2_gpiodvs) {
s5m_reg_write(s5m8767->iodev, S5M8767_REG_BUCK2DVS1 + i,
s5m8767->buck2_vol[i]);
}
if (s5m8767->buck3_gpiodvs) {
s5m_reg_write(s5m8767->iodev, S5M8767_REG_BUCK3DVS1 + i,
s5m8767->buck3_vol[i]);
}
if (s5m8767->buck4_gpiodvs) {
s5m_reg_write(s5m8767->iodev, S5M8767_REG_BUCK4DVS1 + i,
s5m8767->buck4_vol[i]);
}
}
s5m_reg_update(s5m8767->iodev, S5M8767_REG_BUCK2CTRL, 0x78, 0xff);
s5m_reg_update(s5m8767->iodev, S5M8767_REG_BUCK3CTRL, 0x58, 0xff);
s5m_reg_update(s5m8767->iodev, S5M8767_REG_BUCK4CTRL, 0x78, 0xff);
if (s5m8767->buck2_ramp)
s5m_reg_update(s5m8767->iodev, S5M8767_REG_DVSRAMP, 0x08, 0x08);
if (s5m8767->buck3_ramp)
s5m_reg_update(s5m8767->iodev, S5M8767_REG_DVSRAMP, 0x04, 0x04);
if (s5m8767->buck4_ramp)
s5m_reg_update(s5m8767->iodev, S5M8767_REG_DVSRAMP, 0x02, 0x02);
if (s5m8767->buck2_ramp || s5m8767->buck3_ramp
|| s5m8767->buck4_ramp) {
switch (s5m8767->ramp_delay) {
case 15:
s5m_reg_update(s5m8767->iodev, S5M8767_REG_DVSRAMP,
0xc0, 0xf0);
break;
case 25:
s5m_reg_update(s5m8767->iodev, S5M8767_REG_DVSRAMP,
0xd0, 0xf0);
break;
case 50:
s5m_reg_update(s5m8767->iodev, S5M8767_REG_DVSRAMP,
0xe0, 0xf0);
break;
case 100:
s5m_reg_update(s5m8767->iodev, S5M8767_REG_DVSRAMP,
0xf0, 0xf0);
break;
default:
s5m_reg_update(s5m8767->iodev, S5M8767_REG_DVSRAMP,
0x90, 0xf0);
}
}
for (i = 0; i < pdata->num_regulators; i++) {
const struct s5m_voltage_desc *desc;
int id = pdata->regulators[i].id;
desc = reg_voltage_map[id];
if (desc)
regulators[id].n_voltages =
(desc->max - desc->min) / desc->step + 1;
rdev[i] = regulator_register(&regulators[id], s5m8767->dev,
pdata->regulators[i].initdata, s5m8767, NULL);
if (IS_ERR(rdev[i])) {
ret = PTR_ERR(rdev[i]);
dev_err(s5m8767->dev, "regulator init failed for %d\n",
id);
rdev[i] = NULL;
goto err;
}
}
return 0;
err:
for (i = 0; i < s5m8767->num_regulators; i++)
if (rdev[i])
regulator_unregister(rdev[i]);
return ret;
}
static int __devexit s5m8767_pmic_remove(struct platform_device *pdev)
{
struct s5m8767_info *s5m8767 = platform_get_drvdata(pdev);
struct regulator_dev **rdev = s5m8767->rdev;
int i;
for (i = 0; i < s5m8767->num_regulators; i++)
if (rdev[i])
regulator_unregister(rdev[i]);
return 0;
}
static int __init s5m8767_pmic_init(void)
{
return platform_driver_register(&s5m8767_pmic_driver);
}
static void __exit s5m8767_pmic_exit(void)
{
platform_driver_unregister(&s5m8767_pmic_driver);
}
