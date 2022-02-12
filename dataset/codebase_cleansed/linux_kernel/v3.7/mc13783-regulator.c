static int mc13783_powermisc_rmw(struct mc13xxx_regulator_priv *priv, u32 mask,
u32 val)
{
struct mc13xxx *mc13783 = priv->mc13xxx;
int ret;
u32 valread;
BUG_ON(val & ~mask);
mc13xxx_lock(priv->mc13xxx);
ret = mc13xxx_reg_read(mc13783, MC13783_REG_POWERMISC, &valread);
if (ret)
goto out;
priv->powermisc_pwgt_state =
(priv->powermisc_pwgt_state & ~mask) | val;
priv->powermisc_pwgt_state &= MC13783_REG_POWERMISC_PWGTSPI_M;
valread = (valread & ~mask) | val;
valread = (valread & ~MC13783_REG_POWERMISC_PWGTSPI_M) |
priv->powermisc_pwgt_state;
ret = mc13xxx_reg_write(mc13783, MC13783_REG_POWERMISC, valread);
out:
mc13xxx_unlock(priv->mc13xxx);
return ret;
}
static int mc13783_gpo_regulator_enable(struct regulator_dev *rdev)
{
struct mc13xxx_regulator_priv *priv = rdev_get_drvdata(rdev);
struct mc13xxx_regulator *mc13xxx_regulators = priv->mc13xxx_regulators;
int id = rdev_get_id(rdev);
u32 en_val = mc13xxx_regulators[id].enable_bit;
dev_dbg(rdev_get_dev(rdev), "%s id: %d\n", __func__, id);
if (id == MC13783_REG_PWGT1SPI ||
id == MC13783_REG_PWGT2SPI)
en_val = 0;
return mc13783_powermisc_rmw(priv, mc13xxx_regulators[id].enable_bit,
en_val);
}
static int mc13783_gpo_regulator_disable(struct regulator_dev *rdev)
{
struct mc13xxx_regulator_priv *priv = rdev_get_drvdata(rdev);
struct mc13xxx_regulator *mc13xxx_regulators = priv->mc13xxx_regulators;
int id = rdev_get_id(rdev);
u32 dis_val = 0;
dev_dbg(rdev_get_dev(rdev), "%s id: %d\n", __func__, id);
if (id == MC13783_REG_PWGT1SPI ||
id == MC13783_REG_PWGT2SPI)
dis_val = mc13xxx_regulators[id].enable_bit;
return mc13783_powermisc_rmw(priv, mc13xxx_regulators[id].enable_bit,
dis_val);
}
static int mc13783_gpo_regulator_is_enabled(struct regulator_dev *rdev)
{
struct mc13xxx_regulator_priv *priv = rdev_get_drvdata(rdev);
struct mc13xxx_regulator *mc13xxx_regulators = priv->mc13xxx_regulators;
int ret, id = rdev_get_id(rdev);
unsigned int val;
mc13xxx_lock(priv->mc13xxx);
ret = mc13xxx_reg_read(priv->mc13xxx, mc13xxx_regulators[id].reg, &val);
mc13xxx_unlock(priv->mc13xxx);
if (ret)
return ret;
val = (val & ~MC13783_REG_POWERMISC_PWGTSPI_M) |
(priv->powermisc_pwgt_state ^ MC13783_REG_POWERMISC_PWGTSPI_M);
return (val & mc13xxx_regulators[id].enable_bit) != 0;
}
static int __devinit mc13783_regulator_probe(struct platform_device *pdev)
{
struct mc13xxx_regulator_priv *priv;
struct mc13xxx *mc13783 = dev_get_drvdata(pdev->dev.parent);
struct mc13xxx_regulator_platform_data *pdata =
dev_get_platdata(&pdev->dev);
struct mc13xxx_regulator_init_data *init_data;
struct regulator_config config = { };
int i, ret;
dev_dbg(&pdev->dev, "%s id %d\n", __func__, pdev->id);
if (!pdata)
return -EINVAL;
priv = devm_kzalloc(&pdev->dev, sizeof(*priv) +
pdata->num_regulators * sizeof(priv->regulators[0]),
GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->mc13xxx_regulators = mc13783_regulators;
priv->mc13xxx = mc13783;
for (i = 0; i < pdata->num_regulators; i++) {
struct regulator_desc *desc;
init_data = &pdata->regulators[i];
desc = &mc13783_regulators[init_data->id].desc;
config.dev = &pdev->dev;
config.init_data = init_data->init_data;
config.driver_data = priv;
priv->regulators[i] = regulator_register(desc, &config);
if (IS_ERR(priv->regulators[i])) {
dev_err(&pdev->dev, "failed to register regulator %s\n",
mc13783_regulators[i].desc.name);
ret = PTR_ERR(priv->regulators[i]);
goto err;
}
}
platform_set_drvdata(pdev, priv);
return 0;
err:
while (--i >= 0)
regulator_unregister(priv->regulators[i]);
return ret;
}
static int __devexit mc13783_regulator_remove(struct platform_device *pdev)
{
struct mc13xxx_regulator_priv *priv = platform_get_drvdata(pdev);
struct mc13xxx_regulator_platform_data *pdata =
dev_get_platdata(&pdev->dev);
int i;
platform_set_drvdata(pdev, NULL);
for (i = 0; i < pdata->num_regulators; i++)
regulator_unregister(priv->regulators[i]);
return 0;
}
static int __init mc13783_regulator_init(void)
{
return platform_driver_register(&mc13783_regulator_driver);
}
static void __exit mc13783_regulator_exit(void)
{
platform_driver_unregister(&mc13783_regulator_driver);
}
