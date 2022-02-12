static int tps6105x_regulator_enable(struct regulator_dev *rdev)
{
struct tps6105x *tps6105x = rdev_get_drvdata(rdev);
int ret;
ret = tps6105x_mask_and_set(tps6105x, TPS6105X_REG_0,
TPS6105X_REG0_MODE_MASK,
TPS6105X_REG0_MODE_VOLTAGE << TPS6105X_REG0_MODE_SHIFT);
if (ret)
return ret;
return 0;
}
static int tps6105x_regulator_disable(struct regulator_dev *rdev)
{
struct tps6105x *tps6105x = rdev_get_drvdata(rdev);
int ret;
ret = tps6105x_mask_and_set(tps6105x, TPS6105X_REG_0,
TPS6105X_REG0_MODE_MASK,
TPS6105X_REG0_MODE_SHUTDOWN << TPS6105X_REG0_MODE_SHIFT);
if (ret)
return ret;
return 0;
}
static int tps6105x_regulator_is_enabled(struct regulator_dev *rdev)
{
struct tps6105x *tps6105x = rdev_get_drvdata(rdev);
u8 regval;
int ret;
ret = tps6105x_get(tps6105x, TPS6105X_REG_0, &regval);
if (ret)
return ret;
regval &= TPS6105X_REG0_MODE_MASK;
regval >>= TPS6105X_REG0_MODE_SHIFT;
if (regval == TPS6105X_REG0_MODE_VOLTAGE)
return 1;
return 0;
}
static int tps6105x_regulator_get_voltage_sel(struct regulator_dev *rdev)
{
struct tps6105x *tps6105x = rdev_get_drvdata(rdev);
u8 regval;
int ret;
ret = tps6105x_get(tps6105x, TPS6105X_REG_0, &regval);
if (ret)
return ret;
regval &= TPS6105X_REG0_VOLTAGE_MASK;
regval >>= TPS6105X_REG0_VOLTAGE_SHIFT;
return (int) regval;
}
static int tps6105x_regulator_set_voltage_sel(struct regulator_dev *rdev,
unsigned selector)
{
struct tps6105x *tps6105x = rdev_get_drvdata(rdev);
int ret;
ret = tps6105x_mask_and_set(tps6105x, TPS6105X_REG_0,
TPS6105X_REG0_VOLTAGE_MASK,
selector << TPS6105X_REG0_VOLTAGE_SHIFT);
if (ret)
return ret;
return 0;
}
static int tps6105x_regulator_list_voltage(struct regulator_dev *rdev,
unsigned selector)
{
if (selector >= ARRAY_SIZE(tps6105x_voltages))
return -EINVAL;
return tps6105x_voltages[selector];
}
static int __devinit tps6105x_regulator_probe(struct platform_device *pdev)
{
struct tps6105x *tps6105x = dev_get_platdata(&pdev->dev);
struct tps6105x_platform_data *pdata = tps6105x->pdata;
int ret;
if (pdata->mode != TPS6105X_MODE_VOLTAGE) {
dev_info(&pdev->dev,
"chip not in voltage mode mode, exit probe \n");
return 0;
}
tps6105x->regulator = regulator_register(&tps6105x_regulator_desc,
&tps6105x->client->dev,
pdata->regulator_data, tps6105x);
if (IS_ERR(tps6105x->regulator)) {
ret = PTR_ERR(tps6105x->regulator);
dev_err(&tps6105x->client->dev,
"failed to register regulator\n");
return ret;
}
platform_set_drvdata(pdev, tps6105x);
return 0;
}
static int __devexit tps6105x_regulator_remove(struct platform_device *pdev)
{
struct tps6105x *tps6105x = dev_get_platdata(&pdev->dev);
regulator_unregister(tps6105x->regulator);
return 0;
}
static __init int tps6105x_regulator_init(void)
{
return platform_driver_register(&tps6105x_regulator_driver);
}
static __exit void tps6105x_regulator_exit(void)
{
platform_driver_unregister(&tps6105x_regulator_driver);
}
