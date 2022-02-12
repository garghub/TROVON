static int mc13892_powermisc_rmw(struct mc13xxx_regulator_priv *priv, u32 mask,
u32 val)
{
struct mc13xxx *mc13892 = priv->mc13xxx;
int ret;
u32 valread;
BUG_ON(val & ~mask);
mc13xxx_lock(priv->mc13xxx);
ret = mc13xxx_reg_read(mc13892, MC13892_POWERMISC, &valread);
if (ret)
goto out;
priv->powermisc_pwgt_state =
(priv->powermisc_pwgt_state & ~mask) | val;
priv->powermisc_pwgt_state &= MC13892_POWERMISC_PWGTSPI_M;
valread = (valread & ~mask) | val;
valread = (valread & ~MC13892_POWERMISC_PWGTSPI_M) |
priv->powermisc_pwgt_state;
ret = mc13xxx_reg_write(mc13892, MC13892_POWERMISC, valread);
out:
mc13xxx_unlock(priv->mc13xxx);
return ret;
}
static int mc13892_gpo_regulator_enable(struct regulator_dev *rdev)
{
struct mc13xxx_regulator_priv *priv = rdev_get_drvdata(rdev);
int id = rdev_get_id(rdev);
u32 en_val = mc13892_regulators[id].enable_bit;
u32 mask = mc13892_regulators[id].enable_bit;
dev_dbg(rdev_get_dev(rdev), "%s id: %d\n", __func__, id);
if (id == MC13892_PWGT1SPI || id == MC13892_PWGT2SPI)
en_val = 0;
if (id == MC13892_GPO4)
mask |= MC13892_POWERMISC_GPO4ADINEN;
return mc13892_powermisc_rmw(priv, mask, en_val);
}
static int mc13892_gpo_regulator_disable(struct regulator_dev *rdev)
{
struct mc13xxx_regulator_priv *priv = rdev_get_drvdata(rdev);
int id = rdev_get_id(rdev);
u32 dis_val = 0;
dev_dbg(rdev_get_dev(rdev), "%s id: %d\n", __func__, id);
if (id == MC13892_PWGT1SPI || id == MC13892_PWGT2SPI)
dis_val = mc13892_regulators[id].enable_bit;
return mc13892_powermisc_rmw(priv, mc13892_regulators[id].enable_bit,
dis_val);
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
static int mc13892_sw_regulator_get_voltage_sel(struct regulator_dev *rdev)
{
struct mc13xxx_regulator_priv *priv = rdev_get_drvdata(rdev);
int ret, id = rdev_get_id(rdev);
unsigned int val, selector;
dev_dbg(rdev_get_dev(rdev), "%s id: %d\n", __func__, id);
mc13xxx_lock(priv->mc13xxx);
ret = mc13xxx_reg_read(priv->mc13xxx,
mc13892_regulators[id].vsel_reg, &val);
mc13xxx_unlock(priv->mc13xxx);
if (ret)
return ret;
selector = val & mc13892_regulators[id].vsel_mask;
if ((mc13892_regulators[id].vsel_reg != MC13892_SWITCHERS0) &&
(val & MC13892_SWITCHERS0_SWxHI)) {
selector += MC13892_SWxHI_SEL_OFFSET;
}
dev_dbg(rdev_get_dev(rdev), "%s id: %d val: 0x%08x selector: %d\n",
__func__, id, val, selector);
return selector;
}
static int mc13892_sw_regulator_set_voltage_sel(struct regulator_dev *rdev,
unsigned selector)
{
struct mc13xxx_regulator_priv *priv = rdev_get_drvdata(rdev);
int volt, mask, id = rdev_get_id(rdev);
u32 reg_value;
int ret;
volt = rdev->desc->volt_table[selector];
mask = mc13892_regulators[id].vsel_mask;
reg_value = selector;
if (mc13892_regulators[id].vsel_reg != MC13892_SWITCHERS0) {
mask |= MC13892_SWITCHERS0_SWxHI;
if (volt > 1375000) {
reg_value -= MC13892_SWxHI_SEL_OFFSET;
reg_value |= MC13892_SWITCHERS0_SWxHI;
} else {
reg_value &= ~MC13892_SWITCHERS0_SWxHI;
}
}
mc13xxx_lock(priv->mc13xxx);
ret = mc13xxx_reg_rmw(priv->mc13xxx, mc13892_regulators[id].vsel_reg,
mask, reg_value);
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
static int mc13892_regulator_probe(struct platform_device *pdev)
{
struct mc13xxx_regulator_priv *priv;
struct mc13xxx *mc13892 = dev_get_drvdata(pdev->dev.parent);
struct mc13xxx_regulator_platform_data *pdata =
dev_get_platdata(&pdev->dev);
struct mc13xxx_regulator_init_data *mc13xxx_data;
struct regulator_config config = { };
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
goto err_unlock;
if ((val & 0x0000FFFF) == 0x45d0) {
ret = mc13xxx_reg_rmw(mc13892, MC13892_SWITCHERS4,
MC13892_SWITCHERS4_SW1MODE_M |
MC13892_SWITCHERS4_SW2MODE_M,
MC13892_SWITCHERS4_SW1MODE_AUTO |
MC13892_SWITCHERS4_SW2MODE_AUTO);
if (ret)
goto err_unlock;
ret = mc13xxx_reg_rmw(mc13892, MC13892_SWITCHERS5,
MC13892_SWITCHERS5_SW3MODE_M |
MC13892_SWITCHERS5_SW4MODE_M,
MC13892_SWITCHERS5_SW3MODE_AUTO |
MC13892_SWITCHERS5_SW4MODE_AUTO);
if (ret)
goto err_unlock;
}
mc13xxx_unlock(mc13892);
mc13892_regulators[MC13892_VCAM].desc.ops->set_mode
= mc13892_vcam_set_mode;
mc13892_regulators[MC13892_VCAM].desc.ops->get_mode
= mc13892_vcam_get_mode;
mc13xxx_data = mc13xxx_parse_regulators_dt(pdev, mc13892_regulators,
ARRAY_SIZE(mc13892_regulators));
for (i = 0; i < priv->num_regulators; i++) {
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
config.dev = &pdev->dev;
config.init_data = init_data;
config.driver_data = priv;
config.of_node = node;
priv->regulators[i] = devm_regulator_register(&pdev->dev, desc,
&config);
if (IS_ERR(priv->regulators[i])) {
dev_err(&pdev->dev, "failed to register regulator %s\n",
mc13892_regulators[i].desc.name);
return PTR_ERR(priv->regulators[i]);
}
}
return 0;
err_unlock:
mc13xxx_unlock(mc13892);
return ret;
}
static int __init mc13892_regulator_init(void)
{
return platform_driver_register(&mc13892_regulator_driver);
}
static void __exit mc13892_regulator_exit(void)
{
platform_driver_unregister(&mc13892_regulator_driver);
}
