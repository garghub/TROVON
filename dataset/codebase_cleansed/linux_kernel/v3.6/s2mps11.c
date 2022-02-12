static int get_ramp_delay(int ramp_delay)
{
unsigned char cnt = 0;
ramp_delay /= 6;
while (true) {
ramp_delay = ramp_delay >> 1;
if (ramp_delay == 0)
break;
cnt++;
}
return cnt;
}
static __devinit int s2mps11_pmic_probe(struct platform_device *pdev)
{
struct sec_pmic_dev *iodev = dev_get_drvdata(pdev->dev.parent);
struct sec_platform_data *pdata = dev_get_platdata(iodev->dev);
struct regulator_config config = { };
struct regulator_dev **rdev;
struct s2mps11_info *s2mps11;
int i, ret, size;
unsigned char ramp_enable, ramp_reg = 0;
if (!pdata) {
dev_err(pdev->dev.parent, "Platform data not supplied\n");
return -ENODEV;
}
s2mps11 = devm_kzalloc(&pdev->dev, sizeof(struct s2mps11_info),
GFP_KERNEL);
if (!s2mps11)
return -ENOMEM;
size = sizeof(struct regulator_dev *) * S2MPS11_REGULATOR_MAX;
s2mps11->rdev = devm_kzalloc(&pdev->dev, size, GFP_KERNEL);
if (!s2mps11->rdev) {
return -ENOMEM;
}
rdev = s2mps11->rdev;
platform_set_drvdata(pdev, s2mps11);
s2mps11->ramp_delay2 = pdata->buck2_ramp_delay;
s2mps11->ramp_delay34 = pdata->buck34_ramp_delay;
s2mps11->ramp_delay5 = pdata->buck5_ramp_delay;
s2mps11->ramp_delay16 = pdata->buck16_ramp_delay;
s2mps11->ramp_delay7810 = pdata->buck7810_ramp_delay;
s2mps11->ramp_delay9 = pdata->buck9_ramp_delay;
s2mps11->buck6_ramp = pdata->buck6_ramp_enable;
s2mps11->buck2_ramp = pdata->buck2_ramp_enable;
s2mps11->buck3_ramp = pdata->buck3_ramp_enable;
s2mps11->buck4_ramp = pdata->buck4_ramp_enable;
ramp_enable = (s2mps11->buck2_ramp << 3) | (s2mps11->buck3_ramp << 2) |
(s2mps11->buck4_ramp << 1) | s2mps11->buck6_ramp ;
if (ramp_enable) {
if (s2mps11->buck2_ramp)
ramp_reg |= get_ramp_delay(s2mps11->ramp_delay2) >> 6;
if (s2mps11->buck3_ramp || s2mps11->buck4_ramp)
ramp_reg |= get_ramp_delay(s2mps11->ramp_delay34) >> 4;
sec_reg_write(iodev, S2MPS11_REG_RAMP, ramp_reg | ramp_enable);
}
ramp_reg &= 0x00;
ramp_reg |= get_ramp_delay(s2mps11->ramp_delay5) >> 6;
ramp_reg |= get_ramp_delay(s2mps11->ramp_delay16) >> 4;
ramp_reg |= get_ramp_delay(s2mps11->ramp_delay7810) >> 2;
ramp_reg |= get_ramp_delay(s2mps11->ramp_delay9);
sec_reg_write(iodev, S2MPS11_REG_RAMP_BUCK, ramp_reg);
for (i = 0; i < S2MPS11_REGULATOR_MAX; i++) {
config.dev = &pdev->dev;
config.regmap = iodev->regmap;
config.init_data = pdata->regulators[i].initdata;
config.driver_data = s2mps11;
rdev[i] = regulator_register(&regulators[i], &config);
if (IS_ERR(rdev[i])) {
ret = PTR_ERR(rdev[i]);
dev_err(&pdev->dev, "regulator init failed for %d\n",
i);
rdev[i] = NULL;
goto err;
}
}
return 0;
err:
for (i = 0; i < S2MPS11_REGULATOR_MAX; i++)
if (rdev[i])
regulator_unregister(rdev[i]);
return ret;
}
static int __devexit s2mps11_pmic_remove(struct platform_device *pdev)
{
struct s2mps11_info *s2mps11 = platform_get_drvdata(pdev);
struct regulator_dev **rdev = s2mps11->rdev;
int i;
for (i = 0; i < S2MPS11_REGULATOR_MAX; i++)
if (rdev[i])
regulator_unregister(rdev[i]);
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
