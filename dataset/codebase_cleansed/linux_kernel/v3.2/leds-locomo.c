static void locomoled_brightness_set(struct led_classdev *led_cdev,
enum led_brightness value, int offset)
{
struct locomo_dev *locomo_dev = LOCOMO_DEV(led_cdev->dev->parent);
unsigned long flags;
local_irq_save(flags);
if (value)
locomo_writel(LOCOMO_LPT_TOFH, locomo_dev->mapbase + offset);
else
locomo_writel(LOCOMO_LPT_TOFL, locomo_dev->mapbase + offset);
local_irq_restore(flags);
}
static void locomoled_brightness_set0(struct led_classdev *led_cdev,
enum led_brightness value)
{
locomoled_brightness_set(led_cdev, value, LOCOMO_LPT0);
}
static void locomoled_brightness_set1(struct led_classdev *led_cdev,
enum led_brightness value)
{
locomoled_brightness_set(led_cdev, value, LOCOMO_LPT1);
}
static int locomoled_probe(struct locomo_dev *ldev)
{
int ret;
ret = led_classdev_register(&ldev->dev, &locomo_led0);
if (ret < 0)
return ret;
ret = led_classdev_register(&ldev->dev, &locomo_led1);
if (ret < 0)
led_classdev_unregister(&locomo_led0);
return ret;
}
static int locomoled_remove(struct locomo_dev *dev)
{
led_classdev_unregister(&locomo_led0);
led_classdev_unregister(&locomo_led1);
return 0;
}
static int __init locomoled_init(void)
{
return locomo_driver_register(&locomoled_driver);
}
