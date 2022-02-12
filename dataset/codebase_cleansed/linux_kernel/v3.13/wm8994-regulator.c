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
static int wm8994_ldo_probe(struct platform_device *pdev)
{
struct wm8994 *wm8994 = dev_get_drvdata(pdev->dev.parent);
struct wm8994_pdata *pdata = dev_get_platdata(wm8994->dev);
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
ldo->supply = wm8994_ldo_consumer[id];
ldo->supply.dev_name = dev_name(wm8994->dev);
config.dev = wm8994->dev;
config.driver_data = ldo;
config.regmap = wm8994->regmap;
config.init_data = &ldo->init_data;
if (pdata)
config.ena_gpio = pdata->ldo[id].enable;
else if (wm8994->dev->of_node)
config.ena_gpio = wm8994->pdata.ldo[id].enable;
if (!pdata || !pdata->ldo[id].init_data || wm8994->dev->of_node) {
dev_dbg(wm8994->dev, "Using default init data, supply %s %s\n",
ldo->supply.dev_name, ldo->supply.supply);
ldo->init_data = wm8994_ldo_default[id];
ldo->init_data.consumer_supplies = &ldo->supply;
if (!config.ena_gpio)
ldo->init_data.constraints.valid_ops_mask = 0;
} else {
ldo->init_data = *pdata->ldo[id].init_data;
}
ldo->regulator = devm_regulator_register(&pdev->dev,
&wm8994_ldo_desc[id],
&config);
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
