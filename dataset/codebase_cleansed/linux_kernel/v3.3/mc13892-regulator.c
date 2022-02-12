static int mc13892_powermisc_rmw(struct mc13xxx_regulator_priv *priv, u32 mask,
u32 val)
{
struct mc13xxx *mc13892 = priv->mc13xxx;
int ret;
u32 valread;
BUG_ON(val & ~mask);
ret = mc13xxx_reg_read(mc13892, MC13892_POWERMISC, &valread);
if (ret)
return ret;
priv->powermisc_pwgt_state =
(priv->powermisc_pwgt_state & ~mask) | val;
priv->powermisc_pwgt_state &= MC13892_POWERMISC_PWGTSPI_M;
valread = (valread & ~mask) | val;
valread = (valread & ~MC13892_POWERMISC_PWGTSPI_M) |
priv->powermisc_pwgt_state;
return mc13xxx_reg_write(mc13892, MC13892_POWERMISC, valread);
}
static int mc13892_gpo_regulator_enable(struct regulator_dev *rdev)
{
struct mc13xxx_regulator_priv *priv = rdev_get_drvdata(rdev);
int id = rdev_get_id(rdev);
int ret;
u32 en_val = mc13892_regulators[id].enable_bit;
u32 mask = mc13892_regulators[id].enable_bit;
dev_dbg(rdev_get_dev(rdev), "%s id: %d\n", __func__, id);
if (id == MC13892_PWGT1SPI || id == MC13892_PWGT2SPI)
en_val = 0;
if (id == MC13892_GPO4)
mask |= MC13892_POWERMISC_GPO4ADINEN;
mc13xxx_lock(priv->mc13xxx);
ret = mc13892_powermisc_rmw(priv, mask, en_val);
mc13xxx_unlock(priv->mc13xxx);
return ret;
}
static int mc13892_gpo_regulator_disable(struct regulator_dev *rdev)
{
struct mc13xxx_regulator_priv *priv = rdev_get_drvdata(rdev);
int id = rdev_get_id(rdev);
int ret;
u32 dis_val = 0;
dev_dbg(rdev_get_dev(rdev), "%s id: %d\n", __func__, id);
if (id == MC13892_PWGT1SPI || id == MC13892_PWGT2SPI)
dis_val = mc13892_regulators[id].enable_bit;
mc13xxx_lock(priv->mc13xxx);
ret = mc13892_powermisc_rmw(priv, mc13892_regulators[id].enable_bit,
dis_val);
mc13xxx_unlock(priv->mc13xxx);
return ret;
}
static int mc13892_gpo_regulator_is_enabled(struct regulator_dev *rdev)
{
struct mc13xxx_regulator_priv *priv = rdev_get_drvdata(rdev);
int ret, id = rdev_get_id(rdev);
unsigned int val;
mc13xxx_lock(priv->mc13xxx);
ret = mc13xxx_reg_read(priv->mc13xxx, mc13892_regulators[id].reg, &val);
mc13xxx_unlock(priv->mc13xxx);
if (ret)
return ret;
val = (val & ~MC13892_POWERMISC_PWGTSPI_M) |
(priv->powermisc_pwgt_state ^ MC13892_POWERMISC_PWGTSPI_M);
return (val & mc13892_regulators[id].enable_bit) != 0;
}
static int mc13892_sw_regulator_get_voltage(struct regulator_dev *rdev)
{
struct mc13xxx_regulator_priv *priv = rdev_get_drvdata(rdev);
int ret, id = rdev_get_id(rdev);
unsigned int val, hi;
dev_dbg(rdev_get_dev(rdev), "%s id: %d\n", __func__, id);
mc13xxx_lock(priv->mc13xxx);
ret = mc13xxx_reg_read(priv->mc13xxx,
mc13892_regulators[id].vsel_reg, &val);
mc13xxx_unlock(priv->mc13xxx);
if (ret)
return ret;
hi = val & MC13892_SWITCHERS0_SWxHI;
val = (val & mc13892_regulators[id].vsel_mask)
>> mc13892_regulators[id].vsel_shift;
dev_dbg(rdev_get_dev(rdev), "%s id: %d val: %d\n", __func__, id, val);
if (hi)
val = (25000 * val) + 1100000;
else
val = (25000 * val) + 600000;
return val;
}
static int mc13892_sw_regulator_set_voltage(struct regulator_dev *rdev,
int min_uV, int max_uV, unsigned *selector)
{
struct mc13xxx_regulator_priv *priv = rdev_get_drvdata(rdev);
int hi, value, mask, id = rdev_get_id(rdev);
u32 valread;
int ret;
dev_dbg(rdev_get_dev(rdev), "%s id: %d min_uV: %d max_uV: %d\n",
__func__, id, min_uV, max_uV);
value = mc13xxx_get_best_voltage_index(rdev, min_uV, max_uV);
dev_dbg(rdev_get_dev(rdev), "%s best value: %d\n", __func__, value);
if (value < 0)
return value;
value = mc13892_regulators[id].voltages[value];
mc13xxx_lock(priv->mc13xxx);
ret = mc13xxx_reg_read(priv->mc13xxx,
mc13892_regulators[id].vsel_reg, &valread);
if (ret)
goto err;
if (value > 1375000)
hi = 1;
else if (value < 1100000)
hi = 0;
else
hi = valread & MC13892_SWITCHERS0_SWxHI;
if (hi) {
value = (value - 1100000) / 25000;
value |= MC13892_SWITCHERS0_SWxHI;
} else
value = (value - 600000) / 25000;
mask = mc13892_regulators[id].vsel_mask | MC13892_SWITCHERS0_SWxHI;
valread = (valread & ~mask) |
(value << mc13892_regulators[id].vsel_shift);
ret = mc13xxx_reg_write(priv->mc13xxx, mc13892_regulators[id].vsel_reg,
valread);
err:
mc13xxx_unlock(priv->mc13xxx);
return ret;
}
static int mc13892_vcam_set_mode(struct regulator_dev *rdev, unsigned int mode)
{
unsigned int en_val = 0;
struct mc13xxx_regulator_priv *priv = rdev_get_drvdata(rdev);
int ret, id = rdev_get_id(rdev);
if (mode == REGULATOR_MODE_FAST)
en_val = MC13892_REGULATORMODE1_VCAMCONFIGEN;
mc13xxx_lock(priv->mc13xxx);
ret = mc13xxx_reg_rmw(priv->mc13xxx, mc13892_regulators[id].reg,
MC13892_REGULATORMODE1_VCAMCONFIGEN, en_val);
mc13xxx_unlock(priv->mc13xxx);
return ret;
}
static unsigned int mc13892_vcam_get_mode(struct regulator_dev *rdev)
{
struct mc13xxx_regulator_priv *priv = rdev_get_drvdata(rdev);
int ret, id = rdev_get_id(rdev);
unsigned int val;
mc13xxx_lock(priv->mc13xxx);
ret = mc13xxx_reg_read(priv->mc13xxx, mc13892_regulators[id].reg, &val);
mc13xxx_unlock(priv->mc13xxx);
if (ret)
return ret;
if (val & MC13892_REGULATORMODE1_VCAMCONFIGEN)
return REGULATOR_MODE_FAST;
return REGULATOR_MODE_NORMAL;
}
static int __devinit mc13892_regulator_probe(struct platform_device *pdev)
{
struct mc13xxx_regulator_priv *priv;
struct mc13xxx *mc13892 = dev_get_drvdata(pdev->dev.parent);
struct mc13xxx_regulator_platform_data *pdata =
dev_get_platdata(&pdev->dev);
struct mc13xxx_regulator_init_data *mc13xxx_data;
int i, ret;
int num_regulators = 0;
u32 val;
num_regulators = mc13xxx_get_num_regulators_dt(pdev);
if (num_regulators <= 0 && pdata)
num_regulators = pdata->num_regulators;
if (num_regulators <= 0)
return -EINVAL;
priv = devm_kzalloc(&pdev->dev, sizeof(*priv) +
num_regulators * sizeof(priv->regulators[0]),
GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->num_regulators = num_regulators;
priv->mc13xxx_regulators = mc13892_regulators;
priv->mc13xxx = mc13892;
platform_set_drvdata(pdev, priv);
mc13xxx_lock(mc13892);
ret = mc13xxx_reg_read(mc13892, MC13892_REVISION, &val);
if (ret)
goto err_free;
if ((val & 0x0000FFFF) == 0x45d0) {
ret = mc13xxx_reg_rmw(mc13892, MC13892_SWITCHERS4,
MC13892_SWITCHERS4_SW1MODE_M |
MC13892_SWITCHERS4_SW2MODE_M,
MC13892_SWITCHERS4_SW1MODE_AUTO |
MC13892_SWITCHERS4_SW2MODE_AUTO);
if (ret)
goto err_free;
ret = mc13xxx_reg_rmw(mc13892, MC13892_SWITCHERS5,
MC13892_SWITCHERS5_SW3MODE_M |
MC13892_SWITCHERS5_SW4MODE_M,
MC13892_SWITCHERS5_SW3MODE_AUTO |
MC13892_SWITCHERS5_SW4MODE_AUTO);
if (ret)
goto err_free;
}
mc13xxx_unlock(mc13892);
mc13892_regulators[MC13892_VCAM].desc.ops->set_mode
= mc13892_vcam_set_mode;
mc13892_regulators[MC13892_VCAM].desc.ops->get_mode
= mc13892_vcam_get_mode;
mc13xxx_data = mc13xxx_parse_regulators_dt(pdev, mc13892_regulators,
ARRAY_SIZE(mc13892_regulators));
for (i = 0; i < num_regulators; i++) {
struct regulator_init_data *init_data;
struct regulator_desc *desc;
struct device_node *node = NULL;
int id;
if (mc13xxx_data) {
id = mc13xxx_data[i].id;
init_data = mc13xxx_data[i].init_data;
node = mc13xxx_data[i].node;
} else {
id = pdata->regulators[i].id;
init_data = pdata->regulators[i].init_data;
}
desc = &mc13892_regulators[id].desc;
priv->regulators[i] = regulator_register(
desc, &pdev->dev, init_data, priv, node);
if (IS_ERR(priv->regulators[i])) {
dev_err(&pdev->dev, "failed to register regulator %s\n",
mc13892_regulators[i].desc.name);
ret = PTR_ERR(priv->regulators[i]);
goto err;
}
}
return 0;
err:
while (--i >= 0)
regulator_unregister(priv->regulators[i]);
err_free:
mc13xxx_unlock(mc13892);
return ret;
}
static int __devexit mc13892_regulator_remove(struct platform_device *pdev)
{
struct mc13xxx_regulator_priv *priv = platform_get_drvdata(pdev);
int i;
platform_set_drvdata(pdev, NULL);
for (i = 0; i < priv->num_regulators; i++)
regulator_unregister(priv->regulators[i]);
return 0;
}
static int __init mc13892_regulator_init(void)
{
return platform_driver_register(&mc13892_regulator_driver);
}
static void __exit mc13892_regulator_exit(void)
{
platform_driver_unregister(&mc13892_regulator_driver);
}
