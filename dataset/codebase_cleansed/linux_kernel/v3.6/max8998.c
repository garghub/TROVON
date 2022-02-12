static int max8998_get_enable_register(struct regulator_dev *rdev,
int *reg, int *shift)
{
int ldo = rdev_get_id(rdev);
switch (ldo) {
case MAX8998_LDO2 ... MAX8998_LDO5:
*reg = MAX8998_REG_ONOFF1;
*shift = 3 - (ldo - MAX8998_LDO2);
break;
case MAX8998_LDO6 ... MAX8998_LDO13:
*reg = MAX8998_REG_ONOFF2;
*shift = 7 - (ldo - MAX8998_LDO6);
break;
case MAX8998_LDO14 ... MAX8998_LDO17:
*reg = MAX8998_REG_ONOFF3;
*shift = 7 - (ldo - MAX8998_LDO14);
break;
case MAX8998_BUCK1 ... MAX8998_BUCK4:
*reg = MAX8998_REG_ONOFF1;
*shift = 7 - (ldo - MAX8998_BUCK1);
break;
case MAX8998_EN32KHZ_AP ... MAX8998_ENVICHG:
*reg = MAX8998_REG_ONOFF4;
*shift = 7 - (ldo - MAX8998_EN32KHZ_AP);
break;
case MAX8998_ESAFEOUT1 ... MAX8998_ESAFEOUT2:
*reg = MAX8998_REG_CHGR2;
*shift = 7 - (ldo - MAX8998_ESAFEOUT1);
break;
default:
return -EINVAL;
}
return 0;
}
static int max8998_ldo_is_enabled(struct regulator_dev *rdev)
{
struct max8998_data *max8998 = rdev_get_drvdata(rdev);
struct i2c_client *i2c = max8998->iodev->i2c;
int ret, reg, shift = 8;
u8 val;
ret = max8998_get_enable_register(rdev, &reg, &shift);
if (ret)
return ret;
ret = max8998_read_reg(i2c, reg, &val);
if (ret)
return ret;
return val & (1 << shift);
}
static int max8998_ldo_enable(struct regulator_dev *rdev)
{
struct max8998_data *max8998 = rdev_get_drvdata(rdev);
struct i2c_client *i2c = max8998->iodev->i2c;
int reg, shift = 8, ret;
ret = max8998_get_enable_register(rdev, &reg, &shift);
if (ret)
return ret;
return max8998_update_reg(i2c, reg, 1<<shift, 1<<shift);
}
static int max8998_ldo_disable(struct regulator_dev *rdev)
{
struct max8998_data *max8998 = rdev_get_drvdata(rdev);
struct i2c_client *i2c = max8998->iodev->i2c;
int reg, shift = 8, ret;
ret = max8998_get_enable_register(rdev, &reg, &shift);
if (ret)
return ret;
return max8998_update_reg(i2c, reg, 0, 1<<shift);
}
static int max8998_get_voltage_register(struct regulator_dev *rdev,
int *_reg, int *_shift, int *_mask)
{
int ldo = rdev_get_id(rdev);
struct max8998_data *max8998 = rdev_get_drvdata(rdev);
int reg, shift = 0, mask = 0xff;
switch (ldo) {
case MAX8998_LDO2 ... MAX8998_LDO3:
reg = MAX8998_REG_LDO2_LDO3;
mask = 0xf;
if (ldo == MAX8998_LDO2)
shift = 4;
else
shift = 0;
break;
case MAX8998_LDO4 ... MAX8998_LDO7:
reg = MAX8998_REG_LDO4 + (ldo - MAX8998_LDO4);
break;
case MAX8998_LDO8 ... MAX8998_LDO9:
reg = MAX8998_REG_LDO8_LDO9;
mask = 0xf;
if (ldo == MAX8998_LDO8)
shift = 4;
else
shift = 0;
break;
case MAX8998_LDO10 ... MAX8998_LDO11:
reg = MAX8998_REG_LDO10_LDO11;
if (ldo == MAX8998_LDO10) {
shift = 5;
mask = 0x7;
} else {
shift = 0;
mask = 0x1f;
}
break;
case MAX8998_LDO12 ... MAX8998_LDO17:
reg = MAX8998_REG_LDO12 + (ldo - MAX8998_LDO12);
break;
case MAX8998_BUCK1:
reg = MAX8998_REG_BUCK1_VOLTAGE1 + max8998->buck1_idx;
break;
case MAX8998_BUCK2:
reg = MAX8998_REG_BUCK2_VOLTAGE1 + max8998->buck2_idx;
break;
case MAX8998_BUCK3:
reg = MAX8998_REG_BUCK3;
break;
case MAX8998_BUCK4:
reg = MAX8998_REG_BUCK4;
break;
default:
return -EINVAL;
}
*_reg = reg;
*_shift = shift;
*_mask = mask;
return 0;
}
static int max8998_get_voltage_sel(struct regulator_dev *rdev)
{
struct max8998_data *max8998 = rdev_get_drvdata(rdev);
struct i2c_client *i2c = max8998->iodev->i2c;
int reg, shift = 0, mask, ret;
u8 val;
ret = max8998_get_voltage_register(rdev, &reg, &shift, &mask);
if (ret)
return ret;
ret = max8998_read_reg(i2c, reg, &val);
if (ret)
return ret;
val >>= shift;
val &= mask;
return val;
}
static int max8998_set_voltage_ldo_sel(struct regulator_dev *rdev,
unsigned selector)
{
struct max8998_data *max8998 = rdev_get_drvdata(rdev);
struct i2c_client *i2c = max8998->iodev->i2c;
int reg, shift = 0, mask, ret;
ret = max8998_get_voltage_register(rdev, &reg, &shift, &mask);
if (ret)
return ret;
ret = max8998_update_reg(i2c, reg, selector<<shift, mask<<shift);
return ret;
}
static inline void buck1_gpio_set(int gpio1, int gpio2, int v)
{
gpio_set_value(gpio1, v & 0x1);
gpio_set_value(gpio2, (v >> 1) & 0x1);
}
static inline void buck2_gpio_set(int gpio, int v)
{
gpio_set_value(gpio, v & 0x1);
}
static int max8998_set_voltage_buck_sel(struct regulator_dev *rdev,
unsigned selector)
{
struct max8998_data *max8998 = rdev_get_drvdata(rdev);
struct max8998_platform_data *pdata =
dev_get_platdata(max8998->iodev->dev);
struct i2c_client *i2c = max8998->iodev->i2c;
int buck = rdev_get_id(rdev);
int reg, shift = 0, mask, ret;
int j, previous_sel;
static u8 buck1_last_val;
ret = max8998_get_voltage_register(rdev, &reg, &shift, &mask);
if (ret)
return ret;
previous_sel = max8998_get_voltage_sel(rdev);
if (previous_sel == selector) {
dev_dbg(max8998->dev, "No voltage change, old:%d, new:%d\n",
regulator_list_voltage_linear(rdev, previous_sel),
regulator_list_voltage_linear(rdev, selector));
return ret;
}
switch (buck) {
case MAX8998_BUCK1:
dev_dbg(max8998->dev,
"BUCK1, selector:%d, buck1_vol1:%d, buck1_vol2:%d\n"
"buck1_vol3:%d, buck1_vol4:%d\n",
selector, max8998->buck1_vol[0], max8998->buck1_vol[1],
max8998->buck1_vol[2], max8998->buck1_vol[3]);
if (gpio_is_valid(pdata->buck1_set1) &&
gpio_is_valid(pdata->buck1_set2)) {
for (j = 0; j < ARRAY_SIZE(max8998->buck1_vol); j++) {
if (max8998->buck1_vol[j] == selector) {
max8998->buck1_idx = j;
buck1_gpio_set(pdata->buck1_set1,
pdata->buck1_set2, j);
goto buck1_exit;
}
}
if (pdata->buck_voltage_lock)
return -EINVAL;
max8998->buck1_idx = (buck1_last_val % 2) + 2;
dev_dbg(max8998->dev, "max8998->buck1_idx:%d\n",
max8998->buck1_idx);
max8998->buck1_vol[max8998->buck1_idx] = selector;
ret = max8998_get_voltage_register(rdev, &reg,
&shift,
&mask);
ret = max8998_write_reg(i2c, reg, selector);
buck1_gpio_set(pdata->buck1_set1,
pdata->buck1_set2, max8998->buck1_idx);
buck1_last_val++;
buck1_exit:
dev_dbg(max8998->dev, "%s: SET1:%d, SET2:%d\n",
i2c->name, gpio_get_value(pdata->buck1_set1),
gpio_get_value(pdata->buck1_set2));
break;
} else {
ret = max8998_write_reg(i2c, reg, selector);
}
break;
case MAX8998_BUCK2:
dev_dbg(max8998->dev,
"BUCK2, selector:%d buck2_vol1:%d, buck2_vol2:%d\n",
selector, max8998->buck2_vol[0], max8998->buck2_vol[1]);
if (gpio_is_valid(pdata->buck2_set3)) {
for (j = 0; j < ARRAY_SIZE(max8998->buck2_vol); j++) {
if (max8998->buck2_vol[j] == selector) {
max8998->buck2_idx = j;
buck2_gpio_set(pdata->buck2_set3, j);
goto buck2_exit;
}
}
if (pdata->buck_voltage_lock)
return -EINVAL;
max8998_get_voltage_register(rdev,
&reg, &shift, &mask);
ret = max8998_write_reg(i2c, reg, selector);
max8998->buck2_vol[max8998->buck2_idx] = selector;
buck2_gpio_set(pdata->buck2_set3, max8998->buck2_idx);
buck2_exit:
dev_dbg(max8998->dev, "%s: SET3:%d\n", i2c->name,
gpio_get_value(pdata->buck2_set3));
} else {
ret = max8998_write_reg(i2c, reg, selector);
}
break;
case MAX8998_BUCK3:
case MAX8998_BUCK4:
ret = max8998_update_reg(i2c, reg, selector<<shift,
mask<<shift);
break;
}
return ret;
}
static int max8998_set_voltage_buck_time_sel(struct regulator_dev *rdev,
unsigned int old_selector,
unsigned int new_selector)
{
struct max8998_data *max8998 = rdev_get_drvdata(rdev);
struct i2c_client *i2c = max8998->iodev->i2c;
const struct voltage_map_desc *desc;
int buck = rdev_get_id(rdev);
u8 val = 0;
int difference, ret;
if (buck < MAX8998_BUCK1 || buck > MAX8998_BUCK4)
return -EINVAL;
desc = ldo_voltage_map[buck];
ret = max8998_read_reg(i2c, MAX8998_REG_ONOFF4, &val);
if (ret)
return ret;
if (max8998->iodev->type == TYPE_MAX8998 && !(val & MAX8998_ENRAMP))
return 0;
difference = (new_selector - old_selector) * desc->step;
if (difference > 0)
return difference / ((val & 0x0f) + 1);
return 0;
}
static __devinit int max8998_pmic_probe(struct platform_device *pdev)
{
struct max8998_dev *iodev = dev_get_drvdata(pdev->dev.parent);
struct max8998_platform_data *pdata = dev_get_platdata(iodev->dev);
struct regulator_config config = { };
struct regulator_dev **rdev;
struct max8998_data *max8998;
struct i2c_client *i2c;
int i, ret, size;
if (!pdata) {
dev_err(pdev->dev.parent, "No platform init data supplied\n");
return -ENODEV;
}
max8998 = devm_kzalloc(&pdev->dev, sizeof(struct max8998_data),
GFP_KERNEL);
if (!max8998)
return -ENOMEM;
size = sizeof(struct regulator_dev *) * pdata->num_regulators;
max8998->rdev = devm_kzalloc(&pdev->dev, size, GFP_KERNEL);
if (!max8998->rdev)
return -ENOMEM;
rdev = max8998->rdev;
max8998->dev = &pdev->dev;
max8998->iodev = iodev;
max8998->num_regulators = pdata->num_regulators;
platform_set_drvdata(pdev, max8998);
i2c = max8998->iodev->i2c;
max8998->buck1_idx = pdata->buck1_default_idx;
max8998->buck2_idx = pdata->buck2_default_idx;
if (gpio_is_valid(pdata->buck1_set1) &&
gpio_is_valid(pdata->buck1_set2)) {
if (!pdata->buck1_set1) {
printk(KERN_ERR "MAX8998 SET1 GPIO defined as 0 !\n");
WARN_ON(!pdata->buck1_set1);
ret = -EIO;
goto err_out;
}
if (!pdata->buck1_set2) {
printk(KERN_ERR "MAX8998 SET2 GPIO defined as 0 !\n");
WARN_ON(!pdata->buck1_set2);
ret = -EIO;
goto err_out;
}
gpio_request(pdata->buck1_set1, "MAX8998 BUCK1_SET1");
gpio_direction_output(pdata->buck1_set1,
max8998->buck1_idx & 0x1);
gpio_request(pdata->buck1_set2, "MAX8998 BUCK1_SET2");
gpio_direction_output(pdata->buck1_set2,
(max8998->buck1_idx >> 1) & 0x1);
i = 0;
while (buck12_voltage_map_desc.min +
buck12_voltage_map_desc.step*i
< (pdata->buck1_voltage1 / 1000))
i++;
max8998->buck1_vol[0] = i;
ret = max8998_write_reg(i2c, MAX8998_REG_BUCK1_VOLTAGE1, i);
if (ret)
goto err_out;
i = 0;
while (buck12_voltage_map_desc.min +
buck12_voltage_map_desc.step*i
< (pdata->buck1_voltage2 / 1000))
i++;
max8998->buck1_vol[1] = i;
ret = max8998_write_reg(i2c, MAX8998_REG_BUCK1_VOLTAGE2, i);
if (ret)
goto err_out;
i = 0;
while (buck12_voltage_map_desc.min +
buck12_voltage_map_desc.step*i
< (pdata->buck1_voltage3 / 1000))
i++;
max8998->buck1_vol[2] = i;
ret = max8998_write_reg(i2c, MAX8998_REG_BUCK1_VOLTAGE3, i);
if (ret)
goto err_out;
i = 0;
while (buck12_voltage_map_desc.min +
buck12_voltage_map_desc.step*i
< (pdata->buck1_voltage4 / 1000))
i++;
max8998->buck1_vol[3] = i;
ret = max8998_write_reg(i2c, MAX8998_REG_BUCK1_VOLTAGE4, i);
if (ret)
goto err_out;
}
if (gpio_is_valid(pdata->buck2_set3)) {
if (!pdata->buck2_set3) {
printk(KERN_ERR "MAX8998 SET3 GPIO defined as 0 !\n");
WARN_ON(!pdata->buck2_set3);
ret = -EIO;
goto err_out;
}
gpio_request(pdata->buck2_set3, "MAX8998 BUCK2_SET3");
gpio_direction_output(pdata->buck2_set3,
max8998->buck2_idx & 0x1);
i = 0;
while (buck12_voltage_map_desc.min +
buck12_voltage_map_desc.step*i
< (pdata->buck2_voltage1 / 1000))
i++;
max8998->buck2_vol[0] = i;
ret = max8998_write_reg(i2c, MAX8998_REG_BUCK2_VOLTAGE1, i);
if (ret)
goto err_out;
i = 0;
while (buck12_voltage_map_desc.min +
buck12_voltage_map_desc.step*i
< (pdata->buck2_voltage2 / 1000))
i++;
max8998->buck2_vol[1] = i;
ret = max8998_write_reg(i2c, MAX8998_REG_BUCK2_VOLTAGE2, i);
if (ret)
goto err_out;
}
for (i = 0; i < pdata->num_regulators; i++) {
const struct voltage_map_desc *desc;
int id = pdata->regulators[i].id;
int index = id - MAX8998_LDO2;
desc = ldo_voltage_map[id];
if (desc && regulators[index].ops != &max8998_others_ops) {
int count = (desc->max - desc->min) / desc->step + 1;
regulators[index].n_voltages = count;
regulators[index].min_uV = desc->min * 1000;
regulators[index].uV_step = desc->step * 1000;
}
config.dev = max8998->dev;
config.init_data = pdata->regulators[i].initdata;
config.driver_data = max8998;
rdev[i] = regulator_register(&regulators[index], &config);
if (IS_ERR(rdev[i])) {
ret = PTR_ERR(rdev[i]);
dev_err(max8998->dev, "regulator init failed\n");
rdev[i] = NULL;
goto err;
}
}
return 0;
err:
while (--i >= 0)
regulator_unregister(rdev[i]);
err_out:
return ret;
}
static int __devexit max8998_pmic_remove(struct platform_device *pdev)
{
struct max8998_data *max8998 = platform_get_drvdata(pdev);
struct regulator_dev **rdev = max8998->rdev;
int i;
for (i = 0; i < max8998->num_regulators; i++)
regulator_unregister(rdev[i]);
return 0;
}
static int __init max8998_pmic_init(void)
{
return platform_driver_register(&max8998_pmic_driver);
}
static void __exit max8998_pmic_cleanup(void)
{
platform_driver_unregister(&max8998_pmic_driver);
}
