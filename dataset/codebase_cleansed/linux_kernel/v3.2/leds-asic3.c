static void brightness_set(struct led_classdev *cdev,
enum led_brightness value)
{
struct platform_device *pdev = to_platform_device(cdev->dev->parent);
const struct mfd_cell *cell = mfd_get_cell(pdev);
struct asic3 *asic = dev_get_drvdata(pdev->dev.parent);
u32 timebase;
unsigned int base;
timebase = (value == LED_OFF) ? 0 : (LED_EN|0x4);
base = led_n_base[cell->id];
asic3_write_register(asic, (base + ASIC3_LED_PeriodTime), 32);
asic3_write_register(asic, (base + ASIC3_LED_DutyTime), 32);
asic3_write_register(asic, (base + ASIC3_LED_AutoStopCount), 0);
asic3_write_register(asic, (base + ASIC3_LED_TimeBase), timebase);
}
static int blink_set(struct led_classdev *cdev,
unsigned long *delay_on,
unsigned long *delay_off)
{
struct platform_device *pdev = to_platform_device(cdev->dev->parent);
const struct mfd_cell *cell = mfd_get_cell(pdev);
struct asic3 *asic = dev_get_drvdata(pdev->dev.parent);
u32 on;
u32 off;
unsigned int base;
if (*delay_on > MAX_MS || *delay_off > MAX_MS)
return -EINVAL;
if (*delay_on == 0 && *delay_off == 0) {
on = MS_TO_CLK(500);
off = MS_TO_CLK(500);
} else {
on = MS_TO_CLK(*delay_on);
off = MS_TO_CLK(*delay_off);
if ((on + off) > MAX_CLK)
return -EINVAL;
}
base = led_n_base[cell->id];
asic3_write_register(asic, (base + ASIC3_LED_PeriodTime), (on + off));
asic3_write_register(asic, (base + ASIC3_LED_DutyTime), on);
asic3_write_register(asic, (base + ASIC3_LED_AutoStopCount), 0);
asic3_write_register(asic, (base + ASIC3_LED_TimeBase), (LED_EN|0x4));
*delay_on = CLK_TO_MS(on);
*delay_off = CLK_TO_MS(off);
return 0;
}
static int __devinit asic3_led_probe(struct platform_device *pdev)
{
struct asic3_led *led = pdev->dev.platform_data;
int ret;
ret = mfd_cell_enable(pdev);
if (ret < 0)
goto ret0;
led->cdev = kzalloc(sizeof(struct led_classdev), GFP_KERNEL);
if (!led->cdev) {
ret = -ENOMEM;
goto ret1;
}
led->cdev->name = led->name;
led->cdev->flags = LED_CORE_SUSPENDRESUME;
led->cdev->brightness_set = brightness_set;
led->cdev->blink_set = blink_set;
led->cdev->default_trigger = led->default_trigger;
ret = led_classdev_register(&pdev->dev, led->cdev);
if (ret < 0)
goto ret2;
return 0;
ret2:
kfree(led->cdev);
ret1:
(void) mfd_cell_disable(pdev);
ret0:
return ret;
}
static int __devexit asic3_led_remove(struct platform_device *pdev)
{
struct asic3_led *led = pdev->dev.platform_data;
led_classdev_unregister(led->cdev);
kfree(led->cdev);
return mfd_cell_disable(pdev);
}
static int asic3_led_suspend(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
const struct mfd_cell *cell = mfd_get_cell(pdev);
int ret;
ret = 0;
if (cell->suspend)
ret = (*cell->suspend)(pdev);
return ret;
}
static int asic3_led_resume(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
const struct mfd_cell *cell = mfd_get_cell(pdev);
int ret;
ret = 0;
if (cell->resume)
ret = (*cell->resume)(pdev);
return ret;
}
static int __init asic3_led_init(void)
{
return platform_driver_register(&asic3_led_driver);
}
static void __exit asic3_led_exit(void)
{
platform_driver_unregister(&asic3_led_driver);
}
