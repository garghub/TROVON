static void rb532_led_set(struct led_classdev *cdev,
enum led_brightness brightness)
{
if (brightness)
set_latch_u5(LO_ULED, 0);
else
set_latch_u5(0, LO_ULED);
}
static enum led_brightness rb532_led_get(struct led_classdev *cdev)
{
return (get_latch_u5() & LO_ULED) ? LED_FULL : LED_OFF;
}
static int __devinit rb532_led_probe(struct platform_device *pdev)
{
return led_classdev_register(&pdev->dev, &rb532_uled);
}
static int __devexit rb532_led_remove(struct platform_device *pdev)
{
led_classdev_unregister(&rb532_uled);
return 0;
}
static int __init rb532_led_init(void)
{
return platform_driver_register(&rb532_led_driver);
}
static void __exit rb532_led_exit(void)
{
platform_driver_unregister(&rb532_led_driver);
}
