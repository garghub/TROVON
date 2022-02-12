static int wm8994_ldo2_list_voltage(struct regulator_dev *rdev,
unsigned int selector)
{
struct wm8994_ldo *ldo = rdev_get_drvdata(rdev);
if (selector > WM8994_LDO2_MAX_SELECTOR)
return -EINVAL;
switch (ldo->wm8994->type) {
case WM8994:
return (selector * 100000) + 900000;
case WM8958:
return (selector * 100000) + 1000000;
case WM1811:
switch (selector) {
case 0:
return -EINVAL;
default:
return (selector * 100000) + 950000;
}
break;
default:
return -EINVAL;
}
}
static __devinit int wm8994_ldo_probe(struct platform_device *pdev)
{
struct wm8994 *wm8994 = dev_get_drvdata(pdev->dev.parent);
struct wm8994_pdata *pdata = wm8994->dev->platform_data;
int id = pdev->id % ARRAY_SIZE(pdata->ldo);
struct regulator_config config = { };
struct wm8994_ldo *ldo;
int ret;
dev_dbg(&pdev->dev, "Probing LDO%d\n", id + 1);
ldo = devm_kzalloc(&pdev->dev, sizeof(struct wm8994_ldo), GFP_KERNEL);
if (ldo == NULL) {
dev_err(&pdev->dev, "Unable to allocate private data\n");
return -ENOMEM;
}
ldo->wm8994 = wm8994;
config.dev = wm8994->dev;
config.driver_data = ldo;
config.regmap = wm8994->regmap;
if (pdata) {
config.init_data = pdata->ldo[id].init_data;
config.ena_gpio = pdata->ldo[id].enable;
}
ldo->regulator = regulator_register(&wm8994_ldo_desc[id], &config);
if (IS_ERR(ldo->regulator)) {
ret = PTR_ERR(ldo->regulator);
dev_err(wm8994->dev, "Failed to register LDO%d: %d\n",
id + 1, ret);
goto err;
}
platform_set_drvdata(pdev, ldo);
return 0;
err:
return ret;
}
static __devexit int wm8994_ldo_remove(struct platform_device *pdev)
{
struct wm8994_ldo *ldo = platform_get_drvdata(pdev);
platform_set_drvdata(pdev, NULL);
regulator_unregister(ldo->regulator);
return 0;
}
static int __init wm8994_ldo_init(void)
{
int ret;
ret = platform_driver_register(&wm8994_ldo_driver);
if (ret != 0)
pr_err("Failed to register Wm8994 GP LDO driver: %d\n", ret);
return ret;
}
static void __exit wm8994_ldo_exit(void)
{
platform_driver_unregister(&wm8994_ldo_driver);
}
