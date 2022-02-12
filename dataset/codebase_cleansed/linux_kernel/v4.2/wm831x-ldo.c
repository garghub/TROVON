static irqreturn_t wm831x_ldo_uv_irq(int irq, void *data)
{
struct wm831x_ldo *ldo = data;
regulator_notifier_call_chain(ldo->regulator,
REGULATOR_EVENT_UNDER_VOLTAGE,
NULL);
return IRQ_HANDLED;
}
static int wm831x_gp_ldo_set_suspend_voltage(struct regulator_dev *rdev,
int uV)
{
struct wm831x_ldo *ldo = rdev_get_drvdata(rdev);
struct wm831x *wm831x = ldo->wm831x;
int sel, reg = ldo->base + WM831X_LDO_SLEEP_CONTROL;
sel = regulator_map_voltage_linear_range(rdev, uV, uV);
if (sel < 0)
return sel;
return wm831x_set_bits(wm831x, reg, WM831X_LDO1_ON_VSEL_MASK, sel);
}
static unsigned int wm831x_gp_ldo_get_mode(struct regulator_dev *rdev)
{
struct wm831x_ldo *ldo = rdev_get_drvdata(rdev);
struct wm831x *wm831x = ldo->wm831x;
int ctrl_reg = ldo->base + WM831X_LDO_CONTROL;
int on_reg = ldo->base + WM831X_LDO_ON_CONTROL;
int ret;
ret = wm831x_reg_read(wm831x, on_reg);
if (ret < 0)
return ret;
if (!(ret & WM831X_LDO1_ON_MODE))
return REGULATOR_MODE_NORMAL;
ret = wm831x_reg_read(wm831x, ctrl_reg);
if (ret < 0)
return ret;
if (ret & WM831X_LDO1_LP_MODE)
return REGULATOR_MODE_STANDBY;
else
return REGULATOR_MODE_IDLE;
}
static int wm831x_gp_ldo_set_mode(struct regulator_dev *rdev,
unsigned int mode)
{
struct wm831x_ldo *ldo = rdev_get_drvdata(rdev);
struct wm831x *wm831x = ldo->wm831x;
int ctrl_reg = ldo->base + WM831X_LDO_CONTROL;
int on_reg = ldo->base + WM831X_LDO_ON_CONTROL;
int ret;
switch (mode) {
case REGULATOR_MODE_NORMAL:
ret = wm831x_set_bits(wm831x, on_reg,
WM831X_LDO1_ON_MODE, 0);
if (ret < 0)
return ret;
break;
case REGULATOR_MODE_IDLE:
ret = wm831x_set_bits(wm831x, ctrl_reg,
WM831X_LDO1_LP_MODE, 0);
if (ret < 0)
return ret;
ret = wm831x_set_bits(wm831x, on_reg,
WM831X_LDO1_ON_MODE,
WM831X_LDO1_ON_MODE);
if (ret < 0)
return ret;
break;
case REGULATOR_MODE_STANDBY:
ret = wm831x_set_bits(wm831x, ctrl_reg,
WM831X_LDO1_LP_MODE,
WM831X_LDO1_LP_MODE);
if (ret < 0)
return ret;
ret = wm831x_set_bits(wm831x, on_reg,
WM831X_LDO1_ON_MODE,
WM831X_LDO1_ON_MODE);
if (ret < 0)
return ret;
break;
default:
return -EINVAL;
}
return 0;
}
static int wm831x_gp_ldo_get_status(struct regulator_dev *rdev)
{
struct wm831x_ldo *ldo = rdev_get_drvdata(rdev);
struct wm831x *wm831x = ldo->wm831x;
int mask = 1 << rdev_get_id(rdev);
int ret;
ret = wm831x_reg_read(wm831x, WM831X_LDO_STATUS);
if (ret < 0)
return ret;
if (!(ret & mask))
return REGULATOR_STATUS_OFF;
ret = wm831x_reg_read(wm831x, WM831X_LDO_UV_STATUS);
if (ret < 0)
return ret;
if (ret & mask)
return REGULATOR_STATUS_ERROR;
ret = wm831x_gp_ldo_get_mode(rdev);
if (ret < 0)
return ret;
else
return regulator_mode_to_status(ret);
}
static unsigned int wm831x_gp_ldo_get_optimum_mode(struct regulator_dev *rdev,
int input_uV,
int output_uV, int load_uA)
{
if (load_uA < 20000)
return REGULATOR_MODE_STANDBY;
if (load_uA < 50000)
return REGULATOR_MODE_IDLE;
return REGULATOR_MODE_NORMAL;
}
static int wm831x_gp_ldo_probe(struct platform_device *pdev)
{
struct wm831x *wm831x = dev_get_drvdata(pdev->dev.parent);
struct wm831x_pdata *pdata = dev_get_platdata(wm831x->dev);
struct regulator_config config = { };
int id;
struct wm831x_ldo *ldo;
struct resource *res;
int ret, irq;
if (pdata && pdata->wm831x_num)
id = (pdata->wm831x_num * 10) + 1;
else
id = 0;
id = pdev->id - id;
dev_dbg(&pdev->dev, "Probing LDO%d\n", id + 1);
ldo = devm_kzalloc(&pdev->dev, sizeof(struct wm831x_ldo), GFP_KERNEL);
if (!ldo)
return -ENOMEM;
ldo->wm831x = wm831x;
res = platform_get_resource(pdev, IORESOURCE_REG, 0);
if (res == NULL) {
dev_err(&pdev->dev, "No REG resource\n");
ret = -EINVAL;
goto err;
}
ldo->base = res->start;
snprintf(ldo->name, sizeof(ldo->name), "LDO%d", id + 1);
ldo->desc.name = ldo->name;
snprintf(ldo->supply_name, sizeof(ldo->supply_name),
"LDO%dVDD", id + 1);
ldo->desc.supply_name = ldo->supply_name;
ldo->desc.id = id;
ldo->desc.type = REGULATOR_VOLTAGE;
ldo->desc.n_voltages = 32;
ldo->desc.ops = &wm831x_gp_ldo_ops;
ldo->desc.owner = THIS_MODULE;
ldo->desc.vsel_reg = ldo->base + WM831X_LDO_ON_CONTROL;
ldo->desc.vsel_mask = WM831X_LDO1_ON_VSEL_MASK;
ldo->desc.enable_reg = WM831X_LDO_ENABLE;
ldo->desc.enable_mask = 1 << id;
ldo->desc.bypass_reg = ldo->base;
ldo->desc.bypass_mask = WM831X_LDO1_SWI;
ldo->desc.linear_ranges = wm831x_gp_ldo_ranges;
ldo->desc.n_linear_ranges = ARRAY_SIZE(wm831x_gp_ldo_ranges);
config.dev = pdev->dev.parent;
if (pdata)
config.init_data = pdata->ldo[id];
config.driver_data = ldo;
config.regmap = wm831x->regmap;
ldo->regulator = devm_regulator_register(&pdev->dev, &ldo->desc,
&config);
if (IS_ERR(ldo->regulator)) {
ret = PTR_ERR(ldo->regulator);
dev_err(wm831x->dev, "Failed to register LDO%d: %d\n",
id + 1, ret);
goto err;
}
irq = wm831x_irq(wm831x, platform_get_irq_byname(pdev, "UV"));
ret = devm_request_threaded_irq(&pdev->dev, irq, NULL,
wm831x_ldo_uv_irq,
IRQF_TRIGGER_RISING | IRQF_ONESHOT,
ldo->name,
ldo);
if (ret != 0) {
dev_err(&pdev->dev, "Failed to request UV IRQ %d: %d\n",
irq, ret);
goto err;
}
platform_set_drvdata(pdev, ldo);
return 0;
err:
return ret;
}
static int wm831x_aldo_set_suspend_voltage(struct regulator_dev *rdev,
int uV)
{
struct wm831x_ldo *ldo = rdev_get_drvdata(rdev);
struct wm831x *wm831x = ldo->wm831x;
int sel, reg = ldo->base + WM831X_LDO_SLEEP_CONTROL;
sel = regulator_map_voltage_linear_range(rdev, uV, uV);
if (sel < 0)
return sel;
return wm831x_set_bits(wm831x, reg, WM831X_LDO7_ON_VSEL_MASK, sel);
}
static unsigned int wm831x_aldo_get_mode(struct regulator_dev *rdev)
{
struct wm831x_ldo *ldo = rdev_get_drvdata(rdev);
struct wm831x *wm831x = ldo->wm831x;
int on_reg = ldo->base + WM831X_LDO_ON_CONTROL;
int ret;
ret = wm831x_reg_read(wm831x, on_reg);
if (ret < 0)
return 0;
if (ret & WM831X_LDO7_ON_MODE)
return REGULATOR_MODE_IDLE;
else
return REGULATOR_MODE_NORMAL;
}
static int wm831x_aldo_set_mode(struct regulator_dev *rdev,
unsigned int mode)
{
struct wm831x_ldo *ldo = rdev_get_drvdata(rdev);
struct wm831x *wm831x = ldo->wm831x;
int on_reg = ldo->base + WM831X_LDO_ON_CONTROL;
int ret;
switch (mode) {
case REGULATOR_MODE_NORMAL:
ret = wm831x_set_bits(wm831x, on_reg, WM831X_LDO7_ON_MODE, 0);
if (ret < 0)
return ret;
break;
case REGULATOR_MODE_IDLE:
ret = wm831x_set_bits(wm831x, on_reg, WM831X_LDO7_ON_MODE,
WM831X_LDO7_ON_MODE);
if (ret < 0)
return ret;
break;
default:
return -EINVAL;
}
return 0;
}
static int wm831x_aldo_get_status(struct regulator_dev *rdev)
{
struct wm831x_ldo *ldo = rdev_get_drvdata(rdev);
struct wm831x *wm831x = ldo->wm831x;
int mask = 1 << rdev_get_id(rdev);
int ret;
ret = wm831x_reg_read(wm831x, WM831X_LDO_STATUS);
if (ret < 0)
return ret;
if (!(ret & mask))
return REGULATOR_STATUS_OFF;
ret = wm831x_reg_read(wm831x, WM831X_LDO_UV_STATUS);
if (ret < 0)
return ret;
if (ret & mask)
return REGULATOR_STATUS_ERROR;
ret = wm831x_aldo_get_mode(rdev);
if (ret < 0)
return ret;
else
return regulator_mode_to_status(ret);
}
static int wm831x_aldo_probe(struct platform_device *pdev)
{
struct wm831x *wm831x = dev_get_drvdata(pdev->dev.parent);
struct wm831x_pdata *pdata = dev_get_platdata(wm831x->dev);
struct regulator_config config = { };
int id;
struct wm831x_ldo *ldo;
struct resource *res;
int ret, irq;
if (pdata && pdata->wm831x_num)
id = (pdata->wm831x_num * 10) + 1;
else
id = 0;
id = pdev->id - id;
dev_dbg(&pdev->dev, "Probing LDO%d\n", id + 1);
ldo = devm_kzalloc(&pdev->dev, sizeof(struct wm831x_ldo), GFP_KERNEL);
if (!ldo)
return -ENOMEM;
ldo->wm831x = wm831x;
res = platform_get_resource(pdev, IORESOURCE_REG, 0);
if (res == NULL) {
dev_err(&pdev->dev, "No REG resource\n");
ret = -EINVAL;
goto err;
}
ldo->base = res->start;
snprintf(ldo->name, sizeof(ldo->name), "LDO%d", id + 1);
ldo->desc.name = ldo->name;
snprintf(ldo->supply_name, sizeof(ldo->supply_name),
"LDO%dVDD", id + 1);
ldo->desc.supply_name = ldo->supply_name;
ldo->desc.id = id;
ldo->desc.type = REGULATOR_VOLTAGE;
ldo->desc.n_voltages = 32;
ldo->desc.linear_ranges = wm831x_aldo_ranges;
ldo->desc.n_linear_ranges = ARRAY_SIZE(wm831x_aldo_ranges);
ldo->desc.ops = &wm831x_aldo_ops;
ldo->desc.owner = THIS_MODULE;
ldo->desc.vsel_reg = ldo->base + WM831X_LDO_ON_CONTROL;
ldo->desc.vsel_mask = WM831X_LDO7_ON_VSEL_MASK;
ldo->desc.enable_reg = WM831X_LDO_ENABLE;
ldo->desc.enable_mask = 1 << id;
ldo->desc.bypass_reg = ldo->base;
ldo->desc.bypass_mask = WM831X_LDO7_SWI;
config.dev = pdev->dev.parent;
if (pdata)
config.init_data = pdata->ldo[id];
config.driver_data = ldo;
config.regmap = wm831x->regmap;
ldo->regulator = devm_regulator_register(&pdev->dev, &ldo->desc,
&config);
if (IS_ERR(ldo->regulator)) {
ret = PTR_ERR(ldo->regulator);
dev_err(wm831x->dev, "Failed to register LDO%d: %d\n",
id + 1, ret);
goto err;
}
irq = wm831x_irq(wm831x, platform_get_irq_byname(pdev, "UV"));
ret = devm_request_threaded_irq(&pdev->dev, irq, NULL,
wm831x_ldo_uv_irq,
IRQF_TRIGGER_RISING | IRQF_ONESHOT,
ldo->name, ldo);
if (ret != 0) {
dev_err(&pdev->dev, "Failed to request UV IRQ %d: %d\n",
irq, ret);
goto err;
}
platform_set_drvdata(pdev, ldo);
return 0;
err:
return ret;
}
static int wm831x_alive_ldo_set_suspend_voltage(struct regulator_dev *rdev,
int uV)
{
struct wm831x_ldo *ldo = rdev_get_drvdata(rdev);
struct wm831x *wm831x = ldo->wm831x;
int sel, reg = ldo->base + WM831X_ALIVE_LDO_SLEEP_CONTROL;
sel = regulator_map_voltage_linear(rdev, uV, uV);
if (sel < 0)
return sel;
return wm831x_set_bits(wm831x, reg, WM831X_LDO11_ON_VSEL_MASK, sel);
}
static int wm831x_alive_ldo_get_status(struct regulator_dev *rdev)
{
struct wm831x_ldo *ldo = rdev_get_drvdata(rdev);
struct wm831x *wm831x = ldo->wm831x;
int mask = 1 << rdev_get_id(rdev);
int ret;
ret = wm831x_reg_read(wm831x, WM831X_LDO_STATUS);
if (ret < 0)
return ret;
if (ret & mask)
return REGULATOR_STATUS_ON;
else
return REGULATOR_STATUS_OFF;
}
static int wm831x_alive_ldo_probe(struct platform_device *pdev)
{
struct wm831x *wm831x = dev_get_drvdata(pdev->dev.parent);
struct wm831x_pdata *pdata = dev_get_platdata(wm831x->dev);
struct regulator_config config = { };
int id;
struct wm831x_ldo *ldo;
struct resource *res;
int ret;
if (pdata && pdata->wm831x_num)
id = (pdata->wm831x_num * 10) + 1;
else
id = 0;
id = pdev->id - id;
dev_dbg(&pdev->dev, "Probing LDO%d\n", id + 1);
ldo = devm_kzalloc(&pdev->dev, sizeof(struct wm831x_ldo), GFP_KERNEL);
if (!ldo)
return -ENOMEM;
ldo->wm831x = wm831x;
res = platform_get_resource(pdev, IORESOURCE_REG, 0);
if (res == NULL) {
dev_err(&pdev->dev, "No REG resource\n");
ret = -EINVAL;
goto err;
}
ldo->base = res->start;
snprintf(ldo->name, sizeof(ldo->name), "LDO%d", id + 1);
ldo->desc.name = ldo->name;
snprintf(ldo->supply_name, sizeof(ldo->supply_name),
"LDO%dVDD", id + 1);
ldo->desc.supply_name = ldo->supply_name;
ldo->desc.id = id;
ldo->desc.type = REGULATOR_VOLTAGE;
ldo->desc.n_voltages = WM831X_ALIVE_LDO_MAX_SELECTOR + 1;
ldo->desc.ops = &wm831x_alive_ldo_ops;
ldo->desc.owner = THIS_MODULE;
ldo->desc.vsel_reg = ldo->base + WM831X_ALIVE_LDO_ON_CONTROL;
ldo->desc.vsel_mask = WM831X_LDO11_ON_VSEL_MASK;
ldo->desc.enable_reg = WM831X_LDO_ENABLE;
ldo->desc.enable_mask = 1 << id;
ldo->desc.min_uV = 800000;
ldo->desc.uV_step = 50000;
ldo->desc.enable_time = 1000;
config.dev = pdev->dev.parent;
if (pdata)
config.init_data = pdata->ldo[id];
config.driver_data = ldo;
config.regmap = wm831x->regmap;
ldo->regulator = devm_regulator_register(&pdev->dev, &ldo->desc,
&config);
if (IS_ERR(ldo->regulator)) {
ret = PTR_ERR(ldo->regulator);
dev_err(wm831x->dev, "Failed to register LDO%d: %d\n",
id + 1, ret);
goto err;
}
platform_set_drvdata(pdev, ldo);
return 0;
err:
return ret;
}
static int __init wm831x_ldo_init(void)
{
int ret;
ret = platform_driver_register(&wm831x_gp_ldo_driver);
if (ret != 0)
pr_err("Failed to register WM831x GP LDO driver: %d\n", ret);
ret = platform_driver_register(&wm831x_aldo_driver);
if (ret != 0)
pr_err("Failed to register WM831x ALDO driver: %d\n", ret);
ret = platform_driver_register(&wm831x_alive_ldo_driver);
if (ret != 0)
pr_err("Failed to register WM831x alive LDO driver: %d\n",
ret);
return 0;
}
static void __exit wm831x_ldo_exit(void)
{
platform_driver_unregister(&wm831x_alive_ldo_driver);
platform_driver_unregister(&wm831x_aldo_driver);
platform_driver_unregister(&wm831x_gp_ldo_driver);
}
