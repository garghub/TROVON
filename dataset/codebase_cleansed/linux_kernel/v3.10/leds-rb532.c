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
static int rb532_led_probe(struct platform_device *pdev)
{
return led_classdev_register(&pdev->dev, &rb532_uled);
}
static int rb532_led_remove(struct platform_device *pdev)
{
led_classdev_unregister(&rb532_uled);
return 0;
}
