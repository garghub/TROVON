static int lp8788_ldo_enable_time(struct regulator_dev *rdev)
{
struct lp8788_ldo *ldo = rdev_get_drvdata(rdev);
enum lp8788_ldo_id id = rdev_get_id(rdev);
u8 val, addr = LP8788_DLDO1_TIMESTEP + id;
if (lp8788_read_byte(ldo->lp, addr, &val))
return -EINVAL;
val = (val & LP8788_STARTUP_TIME_M) >> LP8788_STARTUP_TIME_S;
return ENABLE_TIME_USEC * val;
}
static int lp8788_config_ldo_enable_mode(struct platform_device *pdev,
struct lp8788_ldo *ldo,
enum lp8788_ldo_id id)
{
struct lp8788 *lp = ldo->lp;
struct lp8788_platform_data *pdata = lp->pdata;
enum lp8788_ext_ldo_en_id enable_id;
u8 en_mask[] = {
[EN_ALDO1] = LP8788_EN_SEL_ALDO1_M,
[EN_ALDO234] = LP8788_EN_SEL_ALDO234_M,
[EN_ALDO5] = LP8788_EN_SEL_ALDO5_M,
[EN_ALDO7] = LP8788_EN_SEL_ALDO7_M,
[EN_DLDO7] = LP8788_EN_SEL_DLDO7_M,
[EN_DLDO911] = LP8788_EN_SEL_DLDO911_M,
};
switch (id) {
case DLDO7:
enable_id = EN_DLDO7;
break;
case DLDO9:
case DLDO11:
enable_id = EN_DLDO911;
break;
case ALDO1:
enable_id = EN_ALDO1;
break;
case ALDO2 ... ALDO4:
enable_id = EN_ALDO234;
break;
case ALDO5:
enable_id = EN_ALDO5;
break;
case ALDO7:
enable_id = EN_ALDO7;
break;
default:
return 0;
}
if (!pdata || !pdata->ldo_pin || !pdata->ldo_pin[enable_id])
goto set_default_ldo_enable_mode;
ldo->en_pin = pdata->ldo_pin[enable_id];
return 0;
set_default_ldo_enable_mode:
return lp8788_update_bits(lp, LP8788_EN_SEL, en_mask[enable_id], 0);
}
static int lp8788_dldo_probe(struct platform_device *pdev)
{
struct lp8788 *lp = dev_get_drvdata(pdev->dev.parent);
int id = pdev->id;
struct lp8788_ldo *ldo;
struct regulator_config cfg = { };
struct regulator_dev *rdev;
int ret;
ldo = devm_kzalloc(&pdev->dev, sizeof(struct lp8788_ldo), GFP_KERNEL);
if (!ldo)
return -ENOMEM;
ldo->lp = lp;
ret = lp8788_config_ldo_enable_mode(pdev, ldo, id);
if (ret)
return ret;
if (ldo->en_pin) {
cfg.ena_gpio = ldo->en_pin->gpio;
cfg.ena_gpio_flags = ldo->en_pin->init_state;
}
cfg.dev = pdev->dev.parent;
cfg.init_data = lp->pdata ? lp->pdata->dldo_data[id] : NULL;
cfg.driver_data = ldo;
cfg.regmap = lp->regmap;
rdev = regulator_register(&lp8788_dldo_desc[id], &cfg);
if (IS_ERR(rdev)) {
ret = PTR_ERR(rdev);
dev_err(&pdev->dev, "DLDO%d regulator register err = %d\n",
id + 1, ret);
return ret;
}
ldo->regulator = rdev;
platform_set_drvdata(pdev, ldo);
return 0;
}
static int lp8788_dldo_remove(struct platform_device *pdev)
{
struct lp8788_ldo *ldo = platform_get_drvdata(pdev);
regulator_unregister(ldo->regulator);
return 0;
}
static int lp8788_aldo_probe(struct platform_device *pdev)
{
struct lp8788 *lp = dev_get_drvdata(pdev->dev.parent);
int id = pdev->id;
struct lp8788_ldo *ldo;
struct regulator_config cfg = { };
struct regulator_dev *rdev;
int ret;
ldo = devm_kzalloc(&pdev->dev, sizeof(struct lp8788_ldo), GFP_KERNEL);
if (!ldo)
return -ENOMEM;
ldo->lp = lp;
ret = lp8788_config_ldo_enable_mode(pdev, ldo, id + ALDO1);
if (ret)
return ret;
if (ldo->en_pin) {
cfg.ena_gpio = ldo->en_pin->gpio;
cfg.ena_gpio_flags = ldo->en_pin->init_state;
}
cfg.dev = pdev->dev.parent;
cfg.init_data = lp->pdata ? lp->pdata->aldo_data[id] : NULL;
cfg.driver_data = ldo;
cfg.regmap = lp->regmap;
rdev = regulator_register(&lp8788_aldo_desc[id], &cfg);
if (IS_ERR(rdev)) {
ret = PTR_ERR(rdev);
dev_err(&pdev->dev, "ALDO%d regulator register err = %d\n",
id + 1, ret);
return ret;
}
ldo->regulator = rdev;
platform_set_drvdata(pdev, ldo);
return 0;
}
static int lp8788_aldo_remove(struct platform_device *pdev)
{
struct lp8788_ldo *ldo = platform_get_drvdata(pdev);
regulator_unregister(ldo->regulator);
return 0;
}
static int __init lp8788_ldo_init(void)
{
int ret;
ret = platform_driver_register(&lp8788_dldo_driver);
if (ret)
return ret;
return platform_driver_register(&lp8788_aldo_driver);
}
static void __exit lp8788_ldo_exit(void)
{
platform_driver_unregister(&lp8788_aldo_driver);
platform_driver_unregister(&lp8788_dldo_driver);
}
