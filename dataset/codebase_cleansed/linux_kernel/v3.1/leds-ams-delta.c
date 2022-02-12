static void ams_delta_led_set(struct led_classdev *led_cdev,
enum led_brightness value)
{
struct ams_delta_led *led_dev =
container_of(led_cdev, struct ams_delta_led, cdev);
if (value)
ams_delta_latch1_write(led_dev->bitmask, led_dev->bitmask);
else
ams_delta_latch1_write(led_dev->bitmask, 0);
}
static int ams_delta_led_probe(struct platform_device *pdev)
{
int i, ret;
for (i = 0; i < ARRAY_SIZE(ams_delta_leds); i++) {
ams_delta_leds[i].cdev.flags |= LED_CORE_SUSPENDRESUME;
ret = led_classdev_register(&pdev->dev,
&ams_delta_leds[i].cdev);
if (ret < 0)
goto fail;
}
return 0;
fail:
while (--i >= 0)
led_classdev_unregister(&ams_delta_leds[i].cdev);
return ret;
}
static int ams_delta_led_remove(struct platform_device *pdev)
{
int i;
for (i = 0; i < ARRAY_SIZE(ams_delta_leds); i++)
led_classdev_unregister(&ams_delta_leds[i].cdev);
return 0;
}
static int __init ams_delta_led_init(void)
{
return platform_driver_register(&ams_delta_led_driver);
}
static void __exit ams_delta_led_exit(void)
{
platform_driver_unregister(&ams_delta_led_driver);
}
