static void lp8788_buck1_set_dvs(struct lp8788_buck *buck)
{
struct lp8788_buck1_dvs *dvs = (struct lp8788_buck1_dvs *)buck->dvs;
enum lp8788_dvs_state pinstate;
if (!dvs)
return;
pinstate = dvs->vsel == DVS_SEL_V0 ? DVS_LOW : DVS_HIGH;
if (gpio_is_valid(dvs->gpio))
gpio_set_value(dvs->gpio, pinstate);
}
static void lp8788_buck2_set_dvs(struct lp8788_buck *buck)
{
struct lp8788_buck2_dvs *dvs = (struct lp8788_buck2_dvs *)buck->dvs;
enum lp8788_dvs_state pin1, pin2;
if (!dvs)
return;
switch (dvs->vsel) {
case DVS_SEL_V0:
pin1 = DVS_LOW;
pin2 = DVS_LOW;
break;
case DVS_SEL_V1:
pin1 = DVS_HIGH;
pin2 = DVS_LOW;
break;
case DVS_SEL_V2:
pin1 = DVS_LOW;
pin2 = DVS_HIGH;
break;
case DVS_SEL_V3:
pin1 = DVS_HIGH;
pin2 = DVS_HIGH;
break;
default:
return;
}
if (gpio_is_valid(dvs->gpio[0]))
gpio_set_value(dvs->gpio[0], pin1);
if (gpio_is_valid(dvs->gpio[1]))
gpio_set_value(dvs->gpio[1], pin2);
}
static void lp8788_set_dvs(struct lp8788_buck *buck, enum lp8788_buck_id id)
{
switch (id) {
case BUCK1:
lp8788_buck1_set_dvs(buck);
break;
case BUCK2:
lp8788_buck2_set_dvs(buck);
break;
default:
break;
}
}
static enum lp8788_dvs_mode
lp8788_get_buck_dvs_ctrl_mode(struct lp8788_buck *buck, enum lp8788_buck_id id)
{
u8 val, mask;
switch (id) {
case BUCK1:
mask = LP8788_BUCK1_DVS_SEL_M;
break;
case BUCK2:
mask = LP8788_BUCK2_DVS_SEL_M;
break;
default:
return REGISTER;
}
lp8788_read_byte(buck->lp, LP8788_BUCK_DVS_SEL, &val);
return val & mask ? REGISTER : EXTPIN;
}
static bool lp8788_is_valid_buck_addr(u8 addr)
{
switch (addr) {
case LP8788_BUCK1_VOUT0:
case LP8788_BUCK1_VOUT1:
case LP8788_BUCK1_VOUT2:
case LP8788_BUCK1_VOUT3:
case LP8788_BUCK2_VOUT0:
case LP8788_BUCK2_VOUT1:
case LP8788_BUCK2_VOUT2:
case LP8788_BUCK2_VOUT3:
return true;
default:
return false;
}
}
static u8 lp8788_select_buck_vout_addr(struct lp8788_buck *buck,
enum lp8788_buck_id id)
{
enum lp8788_dvs_mode mode = lp8788_get_buck_dvs_ctrl_mode(buck, id);
struct lp8788_buck1_dvs *b1_dvs;
struct lp8788_buck2_dvs *b2_dvs;
u8 val, idx, addr;
int pin1, pin2;
switch (id) {
case BUCK1:
if (mode == EXTPIN) {
b1_dvs = (struct lp8788_buck1_dvs *)buck->dvs;
if (!b1_dvs)
goto err;
idx = gpio_get_value(b1_dvs->gpio) ? 1 : 0;
} else {
lp8788_read_byte(buck->lp, LP8788_BUCK_DVS_SEL, &val);
idx = (val & LP8788_BUCK1_DVS_M) >> LP8788_BUCK1_DVS_S;
}
addr = buck1_vout_addr[idx];
break;
case BUCK2:
if (mode == EXTPIN) {
b2_dvs = (struct lp8788_buck2_dvs *)buck->dvs;
if (!b2_dvs)
goto err;
pin1 = gpio_get_value(b2_dvs->gpio[0]);
pin2 = gpio_get_value(b2_dvs->gpio[1]);
if (pin1 == PIN_LOW && pin2 == PIN_LOW)
idx = 0;
else if (pin1 == PIN_LOW && pin2 == PIN_HIGH)
idx = 2;
else if (pin1 == PIN_HIGH && pin2 == PIN_LOW)
idx = 1;
else
idx = 3;
} else {
lp8788_read_byte(buck->lp, LP8788_BUCK_DVS_SEL, &val);
idx = (val & LP8788_BUCK2_DVS_M) >> LP8788_BUCK2_DVS_S;
}
addr = buck2_vout_addr[idx];
break;
default:
goto err;
}
return addr;
err:
return INVALID_ADDR;
}
static int lp8788_buck12_set_voltage_sel(struct regulator_dev *rdev,
unsigned selector)
{
struct lp8788_buck *buck = rdev_get_drvdata(rdev);
enum lp8788_buck_id id = rdev_get_id(rdev);
u8 addr;
if (buck->dvs)
lp8788_set_dvs(buck, id);
addr = lp8788_select_buck_vout_addr(buck, id);
if (!lp8788_is_valid_buck_addr(addr))
return -EINVAL;
return lp8788_update_bits(buck->lp, addr, LP8788_VOUT_M, selector);
}
static int lp8788_buck12_get_voltage_sel(struct regulator_dev *rdev)
{
struct lp8788_buck *buck = rdev_get_drvdata(rdev);
enum lp8788_buck_id id = rdev_get_id(rdev);
int ret;
u8 val, addr;
addr = lp8788_select_buck_vout_addr(buck, id);
if (!lp8788_is_valid_buck_addr(addr))
return -EINVAL;
ret = lp8788_read_byte(buck->lp, addr, &val);
if (ret)
return ret;
return val & LP8788_VOUT_M;
}
static int lp8788_buck_enable_time(struct regulator_dev *rdev)
{
struct lp8788_buck *buck = rdev_get_drvdata(rdev);
enum lp8788_buck_id id = rdev_get_id(rdev);
u8 val, addr = LP8788_BUCK1_TIMESTEP + id;
if (lp8788_read_byte(buck->lp, addr, &val))
return -EINVAL;
val = (val & LP8788_STARTUP_TIME_M) >> LP8788_STARTUP_TIME_S;
return ENABLE_TIME_USEC * val;
}
static int lp8788_buck_set_mode(struct regulator_dev *rdev, unsigned int mode)
{
struct lp8788_buck *buck = rdev_get_drvdata(rdev);
enum lp8788_buck_id id = rdev_get_id(rdev);
u8 mask, val;
mask = BUCK_FPWM_MASK(id);
switch (mode) {
case REGULATOR_MODE_FAST:
val = LP8788_FORCE_PWM << BUCK_FPWM_SHIFT(id);
break;
case REGULATOR_MODE_NORMAL:
val = LP8788_AUTO_PWM << BUCK_FPWM_SHIFT(id);
break;
default:
return -EINVAL;
}
return lp8788_update_bits(buck->lp, LP8788_BUCK_PWM, mask, val);
}
static unsigned int lp8788_buck_get_mode(struct regulator_dev *rdev)
{
struct lp8788_buck *buck = rdev_get_drvdata(rdev);
enum lp8788_buck_id id = rdev_get_id(rdev);
u8 val;
int ret;
ret = lp8788_read_byte(buck->lp, LP8788_BUCK_PWM, &val);
if (ret)
return ret;
return val & BUCK_FPWM_MASK(id) ?
REGULATOR_MODE_FAST : REGULATOR_MODE_NORMAL;
}
static int _gpio_request(struct lp8788_buck *buck, int gpio, char *name)
{
struct device *dev = buck->lp->dev;
if (!gpio_is_valid(gpio)) {
dev_err(dev, "invalid gpio: %d\n", gpio);
return -EINVAL;
}
return devm_gpio_request_one(dev, gpio, DVS_LOW, name);
}
static int lp8788_dvs_gpio_request(struct lp8788_buck *buck,
enum lp8788_buck_id id)
{
struct lp8788_platform_data *pdata = buck->lp->pdata;
char *b1_name = "LP8788_B1_DVS";
char *b2_name[] = { "LP8788_B2_DVS1", "LP8788_B2_DVS2" };
int i, gpio, ret;
switch (id) {
case BUCK1:
gpio = pdata->buck1_dvs->gpio;
ret = _gpio_request(buck, gpio, b1_name);
if (ret)
return ret;
buck->dvs = pdata->buck1_dvs;
break;
case BUCK2:
for (i = 0 ; i < LP8788_NUM_BUCK2_DVS ; i++) {
gpio = pdata->buck2_dvs->gpio[i];
ret = _gpio_request(buck, gpio, b2_name[i]);
if (ret)
return ret;
}
buck->dvs = pdata->buck2_dvs;
break;
default:
break;
}
return 0;
}
static int lp8788_init_dvs(struct lp8788_buck *buck, enum lp8788_buck_id id)
{
struct lp8788_platform_data *pdata = buck->lp->pdata;
u8 mask[] = { LP8788_BUCK1_DVS_SEL_M, LP8788_BUCK2_DVS_SEL_M };
u8 val[] = { LP8788_BUCK1_DVS_PIN, LP8788_BUCK2_DVS_PIN };
u8 default_dvs_mode[] = { LP8788_BUCK1_DVS_I2C, LP8788_BUCK2_DVS_I2C };
if (id == BUCK3 || id == BUCK4)
return 0;
if (!pdata)
goto set_default_dvs_mode;
if ((id == BUCK1 && !pdata->buck1_dvs) ||
(id == BUCK2 && !pdata->buck2_dvs))
goto set_default_dvs_mode;
if (lp8788_dvs_gpio_request(buck, id))
goto set_default_dvs_mode;
return lp8788_update_bits(buck->lp, LP8788_BUCK_DVS_SEL, mask[id],
val[id]);
set_default_dvs_mode:
return lp8788_update_bits(buck->lp, LP8788_BUCK_DVS_SEL, mask[id],
default_dvs_mode[id]);
}
static __devinit int lp8788_buck_probe(struct platform_device *pdev)
{
struct lp8788 *lp = dev_get_drvdata(pdev->dev.parent);
int id = pdev->id;
struct lp8788_buck *buck;
struct regulator_config cfg = { };
struct regulator_dev *rdev;
int ret;
buck = devm_kzalloc(lp->dev, sizeof(struct lp8788_buck), GFP_KERNEL);
if (!buck)
return -ENOMEM;
buck->lp = lp;
ret = lp8788_init_dvs(buck, id);
if (ret)
return ret;
cfg.dev = lp->dev;
cfg.init_data = lp->pdata ? lp->pdata->buck_data[id] : NULL;
cfg.driver_data = buck;
cfg.regmap = lp->regmap;
rdev = regulator_register(&lp8788_buck_desc[id], &cfg);
if (IS_ERR(rdev)) {
ret = PTR_ERR(rdev);
dev_err(lp->dev, "BUCK%d regulator register err = %d\n",
id + 1, ret);
return ret;
}
buck->regulator = rdev;
platform_set_drvdata(pdev, buck);
return 0;
}
static int __devexit lp8788_buck_remove(struct platform_device *pdev)
{
struct lp8788_buck *buck = platform_get_drvdata(pdev);
platform_set_drvdata(pdev, NULL);
regulator_unregister(buck->regulator);
return 0;
}
static int __init lp8788_buck_init(void)
{
return platform_driver_register(&lp8788_buck_driver);
}
static void __exit lp8788_buck_exit(void)
{
platform_driver_unregister(&lp8788_buck_driver);
}
