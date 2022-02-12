static int max8925_set_voltage_sel(struct regulator_dev *rdev,
unsigned int selector)
{
struct max8925_regulator_info *info = rdev_get_drvdata(rdev);
unsigned char mask = rdev->desc->n_voltages - 1;
return max8925_set_bits(info->i2c, info->vol_reg, mask, selector);
}
static int max8925_get_voltage_sel(struct regulator_dev *rdev)
{
struct max8925_regulator_info *info = rdev_get_drvdata(rdev);
unsigned char data, mask;
int ret;
ret = max8925_reg_read(info->i2c, info->vol_reg);
if (ret < 0)
return ret;
mask = rdev->desc->n_voltages - 1;
data = ret & mask;
return data;
}
static int max8925_enable(struct regulator_dev *rdev)
{
struct max8925_regulator_info *info = rdev_get_drvdata(rdev);
return max8925_set_bits(info->i2c, info->enable_reg,
LDO_SEQ_MASK << LDO_SEQ_SHIFT |
LDO_I2C_EN_MASK << LDO_I2C_EN_SHIFT,
LDO_SEQ_I2C << LDO_SEQ_SHIFT |
LDO_I2C_EN << LDO_I2C_EN_SHIFT);
}
static int max8925_disable(struct regulator_dev *rdev)
{
struct max8925_regulator_info *info = rdev_get_drvdata(rdev);
return max8925_set_bits(info->i2c, info->enable_reg,
LDO_SEQ_MASK << LDO_SEQ_SHIFT |
LDO_I2C_EN_MASK << LDO_I2C_EN_SHIFT,
LDO_SEQ_I2C << LDO_SEQ_SHIFT);
}
static int max8925_is_enabled(struct regulator_dev *rdev)
{
struct max8925_regulator_info *info = rdev_get_drvdata(rdev);
int ldo_seq, ret;
ret = max8925_reg_read(info->i2c, info->enable_reg);
if (ret < 0)
return ret;
ldo_seq = (ret >> LDO_SEQ_SHIFT) & LDO_SEQ_MASK;
if (ldo_seq != LDO_SEQ_I2C)
return 1;
else
return ret & (LDO_I2C_EN_MASK << LDO_I2C_EN_SHIFT);
}
static int max8925_set_dvm_voltage(struct regulator_dev *rdev, int uV)
{
struct max8925_regulator_info *info = rdev_get_drvdata(rdev);
unsigned char data, mask;
if (uV < SD1_DVM_VMIN || uV > SD1_DVM_VMAX)
return -EINVAL;
data = DIV_ROUND_UP(uV - SD1_DVM_VMIN, SD1_DVM_STEP);
data <<= SD1_DVM_SHIFT;
mask = 3 << SD1_DVM_SHIFT;
return max8925_set_bits(info->i2c, info->enable_reg, mask, data);
}
static int max8925_set_dvm_enable(struct regulator_dev *rdev)
{
struct max8925_regulator_info *info = rdev_get_drvdata(rdev);
return max8925_set_bits(info->i2c, info->vol_reg, 1 << SD1_DVM_EN,
1 << SD1_DVM_EN);
}
static int max8925_set_dvm_disable(struct regulator_dev *rdev)
{
struct max8925_regulator_info *info = rdev_get_drvdata(rdev);
return max8925_set_bits(info->i2c, info->vol_reg, 1 << SD1_DVM_EN, 0);
}
static int max8925_regulator_dt_init(struct platform_device *pdev,
struct max8925_regulator_info *info,
struct regulator_config *config,
int ridx)
{
struct device_node *nproot, *np;
int rcount;
nproot = of_node_get(pdev->dev.parent->of_node);
if (!nproot)
return -ENODEV;
np = of_find_node_by_name(nproot, "regulators");
if (!np) {
dev_err(&pdev->dev, "failed to find regulators node\n");
return -ENODEV;
}
rcount = of_regulator_match(&pdev->dev, np,
&max8925_regulator_matches[ridx], 1);
of_node_put(np);
if (rcount < 0)
return -ENODEV;
config->init_data = max8925_regulator_matches[ridx].init_data;
config->of_node = max8925_regulator_matches[ridx].of_node;
return 0;
}
static int max8925_regulator_probe(struct platform_device *pdev)
{
struct max8925_chip *chip = dev_get_drvdata(pdev->dev.parent);
struct regulator_init_data *pdata = pdev->dev.platform_data;
struct regulator_config config = { };
struct max8925_regulator_info *ri;
struct resource *res;
struct regulator_dev *rdev;
int i, regulator_idx;
res = platform_get_resource(pdev, IORESOURCE_REG, 0);
if (!res) {
dev_err(&pdev->dev, "No REG resource!\n");
return -EINVAL;
}
for (i = 0; i < ARRAY_SIZE(max8925_regulator_info); i++) {
ri = &max8925_regulator_info[i];
if (ri->vol_reg == res->start) {
regulator_idx = i;
break;
}
}
if (i == ARRAY_SIZE(max8925_regulator_info)) {
dev_err(&pdev->dev, "Failed to find regulator %llu\n",
(unsigned long long)res->start);
return -EINVAL;
}
ri->i2c = chip->i2c;
ri->chip = chip;
config.dev = &pdev->dev;
config.driver_data = ri;
if (max8925_regulator_dt_init(pdev, ri, &config, regulator_idx))
if (pdata)
config.init_data = pdata;
rdev = regulator_register(&ri->desc, &config);
if (IS_ERR(rdev)) {
dev_err(&pdev->dev, "failed to register regulator %s\n",
ri->desc.name);
return PTR_ERR(rdev);
}
platform_set_drvdata(pdev, rdev);
return 0;
}
static int max8925_regulator_remove(struct platform_device *pdev)
{
struct regulator_dev *rdev = platform_get_drvdata(pdev);
platform_set_drvdata(pdev, NULL);
regulator_unregister(rdev);
return 0;
}
static int __init max8925_regulator_init(void)
{
return platform_driver_register(&max8925_regulator_driver);
}
static void __exit max8925_regulator_exit(void)
{
platform_driver_unregister(&max8925_regulator_driver);
}
