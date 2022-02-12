static void net48xx_error_led_set(struct led_classdev *led_cdev,
enum led_brightness value)
{
scx200_gpio_ops.gpio_set(NET48XX_ERROR_LED_GPIO, value ? 1 : 0);
}
static int net48xx_led_probe(struct platform_device *pdev)
{
return led_classdev_register(&pdev->dev, &net48xx_error_led);
}
static int net48xx_led_remove(struct platform_device *pdev)
{
led_classdev_unregister(&net48xx_error_led);
return 0;
}
static int __init net48xx_led_init(void)
{
int ret;
if (!scx200_gpio_ops.dev) {
ret = -ENODEV;
goto out;
}
ret = platform_driver_register(&net48xx_led_driver);
if (ret < 0)
goto out;
pdev = platform_device_register_simple(DRVNAME, -1, NULL, 0);
if (IS_ERR(pdev)) {
ret = PTR_ERR(pdev);
platform_driver_unregister(&net48xx_led_driver);
goto out;
}
out:
return ret;
}
static void __exit net48xx_led_exit(void)
{
platform_device_unregister(pdev);
platform_driver_unregister(&net48xx_led_driver);
}
