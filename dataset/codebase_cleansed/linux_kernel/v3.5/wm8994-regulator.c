static int wm8994_ldo_enable(struct regulator_dev *rdev)
{
struct wm8994_ldo *ldo = rdev_get_drvdata(rdev);
if (!ldo->enable)
return 0;
gpio_set_value_cansleep(ldo->enable, 1);
ldo->is_enabled = true;
return 0;
}
static int wm8994_ldo_disable(struct regulator_dev *rdev)
{
struct wm8994_ldo *ldo = rdev_get_drvdata(rdev);
if (!ldo->enable)
return -EINVAL;
gpio_set_value_cansleep(ldo->enable, 0);
ldo->is_enabled = false;
return 0;
}
static int wm8994_ldo_is_enabled(struct regulator_dev *rdev)
{
struct wm8994_ldo *ldo = rdev_get_drvdata(rdev);
return ldo->is_enabled;
}
static int wm8994_ldo_enable_time(struct regulator_dev *rdev)
{
return 3000;
}
static int wm8994_ldo1_list_voltage(struct regulator_dev *rdev,
unsigned int selector)
{
if (selector > WM8994_LDO1_MAX_SELECTOR)
return -EINVAL;
return (selector * 100000) + 2400000;
}
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
if (pdata->ldo[id].enable && gpio_is_valid(pdata->ldo[id].enable)) {
ldo->enable = pdata->ldo[id].enable;
ret = gpio_request_one(ldo->enable, 0, "WM8994 LDO enable");
if (ret < 0) {
dev_err(&pdev->dev, "Failed to get enable GPIO: %d\n",
ret);
goto err;
}
} else
ldo->is_enabled = true;
config.dev = wm8994->dev;
config.driver_data = ldo;
config.regmap = wm8994->regmap;
if (pdata)
config.init_data = pdata->ldo[id].init_data;
ldo->regulator = regulator_register(&wm8994_ldo_desc[id], &config);
if (IS_ERR(ldo->regulator)) {
ret = PTR_ERR(ldo->regulator);
dev_err(wm8994->dev, "Failed to register LDO%d: %d\n",
id + 1, ret);
goto err_gpio;
}
platform_set_drvdata(pdev, ldo);
return 0;
err_gpio:
if (gpio_is_valid(ldo->enable))
gpio_free(ldo->enable);
err:
return ret;
}
static __devexit int wm8994_ldo_remove(struct platform_device *pdev)
{
struct wm8994_ldo *ldo = platform_get_drvdata(pdev);
platform_set_drvdata(pdev, NULL);
regulator_unregister(ldo->regulator);
if (gpio_is_valid(ldo->enable))
gpio_free(ldo->enable);
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
