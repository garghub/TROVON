static int wm8400_ldo_list_voltage(struct regulator_dev *dev,
unsigned selector)
{
if (selector > WM8400_LDO1_VSEL_MASK)
return -EINVAL;
if (selector < 15)
return 900000 + (selector * 50000);
else
return 1700000 + ((selector - 15) * 100000);
}
static int wm8400_ldo_map_voltage(struct regulator_dev *dev,
int min_uV, int max_uV)
{
u16 val;
int volt;
if (min_uV < 900000 || min_uV > 3300000)
return -EINVAL;
if (min_uV < 1700000)
val = DIV_ROUND_UP(min_uV - 900000, 50000);
else
val = DIV_ROUND_UP(min_uV - 1700000, 100000) + 15;
volt = wm8400_ldo_list_voltage(dev, val);
if (volt < min_uV || volt > max_uV)
return -EINVAL;
return val;
}
static unsigned int wm8400_dcdc_get_mode(struct regulator_dev *dev)
{
struct wm8400 *wm8400 = rdev_get_drvdata(dev);
int offset = (rdev_get_id(dev) - WM8400_DCDC1) * 2;
u16 data[2];
int ret;
ret = wm8400_block_read(wm8400, WM8400_DCDC1_CONTROL_1 + offset, 2,
data);
if (ret != 0)
return 0;
if (data[0] & WM8400_DC1_SLEEP)
return REGULATOR_MODE_STANDBY;
if (!(data[0] & WM8400_DC1_ACTIVE))
return REGULATOR_MODE_IDLE;
if (data[1] & WM8400_DC1_FRC_PWM)
return REGULATOR_MODE_FAST;
else
return REGULATOR_MODE_NORMAL;
}
static int wm8400_dcdc_set_mode(struct regulator_dev *dev, unsigned int mode)
{
struct wm8400 *wm8400 = rdev_get_drvdata(dev);
int offset = (rdev_get_id(dev) - WM8400_DCDC1) * 2;
int ret;
switch (mode) {
case REGULATOR_MODE_FAST:
ret = wm8400_set_bits(wm8400, WM8400_DCDC1_CONTROL_2 + offset,
WM8400_DC1_FRC_PWM, WM8400_DC1_FRC_PWM);
if (ret != 0)
return ret;
return wm8400_set_bits(wm8400, WM8400_DCDC1_CONTROL_1 + offset,
WM8400_DC1_ACTIVE | WM8400_DC1_SLEEP,
WM8400_DC1_ACTIVE);
case REGULATOR_MODE_NORMAL:
ret = wm8400_set_bits(wm8400, WM8400_DCDC1_CONTROL_2 + offset,
WM8400_DC1_FRC_PWM, 0);
if (ret != 0)
return ret;
return wm8400_set_bits(wm8400, WM8400_DCDC1_CONTROL_1 + offset,
WM8400_DC1_ACTIVE | WM8400_DC1_SLEEP,
WM8400_DC1_ACTIVE);
case REGULATOR_MODE_IDLE:
return wm8400_set_bits(wm8400, WM8400_DCDC1_CONTROL_1 + offset,
WM8400_DC1_ACTIVE | WM8400_DC1_SLEEP, 0);
default:
return -EINVAL;
}
}
static unsigned int wm8400_dcdc_get_optimum_mode(struct regulator_dev *dev,
int input_uV, int output_uV,
int load_uA)
{
return REGULATOR_MODE_NORMAL;
}
static int __devinit wm8400_regulator_probe(struct platform_device *pdev)
{
struct wm8400 *wm8400 = container_of(pdev, struct wm8400, regulators[pdev->id]);
struct regulator_config config = { };
struct regulator_dev *rdev;
config.dev = &pdev->dev;
config.init_data = pdev->dev.platform_data;
config.driver_data = wm8400;
config.regmap = wm8400->regmap;
rdev = regulator_register(&regulators[pdev->id], &config);
if (IS_ERR(rdev))
return PTR_ERR(rdev);
platform_set_drvdata(pdev, rdev);
return 0;
}
static int __devexit wm8400_regulator_remove(struct platform_device *pdev)
{
struct regulator_dev *rdev = platform_get_drvdata(pdev);
platform_set_drvdata(pdev, NULL);
regulator_unregister(rdev);
return 0;
}
int wm8400_register_regulator(struct device *dev, int reg,
struct regulator_init_data *initdata)
{
struct wm8400 *wm8400 = dev_get_drvdata(dev);
if (wm8400->regulators[reg].name)
return -EBUSY;
initdata->driver_data = wm8400;
wm8400->regulators[reg].name = "wm8400-regulator";
wm8400->regulators[reg].id = reg;
wm8400->regulators[reg].dev.parent = dev;
wm8400->regulators[reg].dev.platform_data = initdata;
return platform_device_register(&wm8400->regulators[reg]);
}
static int __init wm8400_regulator_init(void)
{
return platform_driver_register(&wm8400_regulator_driver);
}
static void __exit wm8400_regulator_exit(void)
{
platform_driver_unregister(&wm8400_regulator_driver);
}
