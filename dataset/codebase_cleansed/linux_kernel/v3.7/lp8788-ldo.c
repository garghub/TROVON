static enum lp8788_enable_mode
lp8788_get_ldo_enable_mode(struct lp8788_ldo *ldo, enum lp8788_ldo_id id)
{
int ret;
u8 val, mask;
ret = lp8788_read_byte(ldo->lp, LP8788_EN_SEL, &val);
if (ret)
return ret;
switch (id) {
case DLDO7:
mask = LP8788_EN_SEL_DLDO7_M;
break;
case DLDO9:
case DLDO11:
mask = LP8788_EN_SEL_DLDO911_M;
break;
case ALDO1:
mask = LP8788_EN_SEL_ALDO1_M;
break;
case ALDO2 ... ALDO4:
mask = LP8788_EN_SEL_ALDO234_M;
break;
case ALDO5:
mask = LP8788_EN_SEL_ALDO5_M;
break;
case ALDO7:
mask = LP8788_EN_SEL_ALDO7_M;
break;
default:
return REGISTER;
}
return val & mask ? EXTPIN : REGISTER;
}
static int lp8788_ldo_ctrl_by_extern_pin(struct lp8788_ldo *ldo, int pinstate)
{
struct lp8788_ldo_enable_pin *pin = ldo->en_pin;
if (!pin)
return -EINVAL;
if (gpio_is_valid(pin->gpio))
gpio_set_value(pin->gpio, pinstate);
return 0;
}
static int lp8788_ldo_is_enabled_by_extern_pin(struct lp8788_ldo *ldo)
{
struct lp8788_ldo_enable_pin *pin = ldo->en_pin;
if (!pin)
return -EINVAL;
return gpio_get_value(pin->gpio) ? 1 : 0;
}
static int lp8788_ldo_enable(struct regulator_dev *rdev)
{
struct lp8788_ldo *ldo = rdev_get_drvdata(rdev);
enum lp8788_ldo_id id = rdev_get_id(rdev);
enum lp8788_enable_mode mode = lp8788_get_ldo_enable_mode(ldo, id);
switch (mode) {
case EXTPIN:
return lp8788_ldo_ctrl_by_extern_pin(ldo, ENABLE);
case REGISTER:
return regulator_enable_regmap(rdev);
default:
return -EINVAL;
}
}
static int lp8788_ldo_disable(struct regulator_dev *rdev)
{
struct lp8788_ldo *ldo = rdev_get_drvdata(rdev);
enum lp8788_ldo_id id = rdev_get_id(rdev);
enum lp8788_enable_mode mode = lp8788_get_ldo_enable_mode(ldo, id);
switch (mode) {
case EXTPIN:
return lp8788_ldo_ctrl_by_extern_pin(ldo, DISABLE);
case REGISTER:
return regulator_disable_regmap(rdev);
default:
return -EINVAL;
}
}
static int lp8788_ldo_is_enabled(struct regulator_dev *rdev)
{
struct lp8788_ldo *ldo = rdev_get_drvdata(rdev);
enum lp8788_ldo_id id = rdev_get_id(rdev);
enum lp8788_enable_mode mode = lp8788_get_ldo_enable_mode(ldo, id);
switch (mode) {
case EXTPIN:
return lp8788_ldo_is_enabled_by_extern_pin(ldo);
case REGISTER:
return regulator_is_enabled_regmap(rdev);
default:
return -EINVAL;
}
}
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
static int lp8788_ldo_fixed_get_voltage(struct regulator_dev *rdev)
{
enum lp8788_ldo_id id = rdev_get_id(rdev);
switch (id) {
case ALDO2 ... ALDO5:
return 2850000;
case DLDO12:
case ALDO8 ... ALDO9:
return 2500000;
case ALDO10:
return 1100000;
default:
return -EINVAL;
}
}
static int lp8788_gpio_request_ldo_en(struct lp8788_ldo *ldo,
enum lp8788_ext_ldo_en_id id)
{
struct device *dev = ldo->lp->dev;
struct lp8788_ldo_enable_pin *pin = ldo->en_pin;
int ret, gpio, pinstate;
char *name[] = {
[EN_ALDO1] = "LP8788_EN_ALDO1",
[EN_ALDO234] = "LP8788_EN_ALDO234",
[EN_ALDO5] = "LP8788_EN_ALDO5",
[EN_ALDO7] = "LP8788_EN_ALDO7",
[EN_DLDO7] = "LP8788_EN_DLDO7",
[EN_DLDO911] = "LP8788_EN_DLDO911",
};
gpio = pin->gpio;
if (!gpio_is_valid(gpio)) {
dev_err(dev, "invalid gpio: %d\n", gpio);
return -EINVAL;
}
pinstate = pin->init_state;
ret = devm_gpio_request_one(dev, gpio, pinstate, name[id]);
if (ret == -EBUSY) {
dev_warn(dev, "gpio%d already used\n", gpio);
return 0;
}
return ret;
}
static int lp8788_config_ldo_enable_mode(struct lp8788_ldo *ldo,
enum lp8788_ldo_id id)
{
int ret;
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
u8 val[] = {
[EN_ALDO1] = 0 << 5,
[EN_ALDO234] = 0 << 4,
[EN_ALDO5] = 0 << 3,
[EN_ALDO7] = 0 << 2,
[EN_DLDO7] = 0 << 1,
[EN_DLDO911] = 0 << 0,
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
ret = lp8788_gpio_request_ldo_en(ldo, enable_id);
if (ret)
goto set_default_ldo_enable_mode;
return ret;
set_default_ldo_enable_mode:
return lp8788_update_bits(lp, LP8788_EN_SEL, en_mask[enable_id],
val[enable_id]);
}
static __devinit int lp8788_dldo_probe(struct platform_device *pdev)
{
struct lp8788 *lp = dev_get_drvdata(pdev->dev.parent);
int id = pdev->id;
struct lp8788_ldo *ldo;
struct regulator_config cfg = { };
struct regulator_dev *rdev;
int ret;
ldo = devm_kzalloc(lp->dev, sizeof(struct lp8788_ldo), GFP_KERNEL);
if (!ldo)
return -ENOMEM;
ldo->lp = lp;
ret = lp8788_config_ldo_enable_mode(ldo, lp8788_dldo_id[id]);
if (ret)
return ret;
cfg.dev = lp->dev;
cfg.init_data = lp->pdata ? lp->pdata->dldo_data[id] : NULL;
cfg.driver_data = ldo;
cfg.regmap = lp->regmap;
rdev = regulator_register(&lp8788_dldo_desc[id], &cfg);
if (IS_ERR(rdev)) {
ret = PTR_ERR(rdev);
dev_err(lp->dev, "DLDO%d regulator register err = %d\n",
id + 1, ret);
return ret;
}
ldo->regulator = rdev;
platform_set_drvdata(pdev, ldo);
return 0;
}
static int __devexit lp8788_dldo_remove(struct platform_device *pdev)
{
struct lp8788_ldo *ldo = platform_get_drvdata(pdev);
platform_set_drvdata(pdev, NULL);
regulator_unregister(ldo->regulator);
return 0;
}
static __devinit int lp8788_aldo_probe(struct platform_device *pdev)
{
struct lp8788 *lp = dev_get_drvdata(pdev->dev.parent);
int id = pdev->id;
struct lp8788_ldo *ldo;
struct regulator_config cfg = { };
struct regulator_dev *rdev;
int ret;
ldo = devm_kzalloc(lp->dev, sizeof(struct lp8788_ldo), GFP_KERNEL);
if (!ldo)
return -ENOMEM;
ldo->lp = lp;
ret = lp8788_config_ldo_enable_mode(ldo, lp8788_aldo_id[id]);
if (ret)
return ret;
cfg.dev = lp->dev;
cfg.init_data = lp->pdata ? lp->pdata->aldo_data[id] : NULL;
cfg.driver_data = ldo;
cfg.regmap = lp->regmap;
rdev = regulator_register(&lp8788_aldo_desc[id], &cfg);
if (IS_ERR(rdev)) {
ret = PTR_ERR(rdev);
dev_err(lp->dev, "ALDO%d regulator register err = %d\n",
id + 1, ret);
return ret;
}
ldo->regulator = rdev;
platform_set_drvdata(pdev, ldo);
return 0;
}
static int __devexit lp8788_aldo_remove(struct platform_device *pdev)
{
struct lp8788_ldo *ldo = platform_get_drvdata(pdev);
platform_set_drvdata(pdev, NULL);
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
