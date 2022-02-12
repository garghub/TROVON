static void wrap_power_led_set(struct led_classdev *led_cdev,
enum led_brightness value)
{
if (value)
scx200_gpio_set_low(WRAP_POWER_LED_GPIO);
else
scx200_gpio_set_high(WRAP_POWER_LED_GPIO);
}
static void wrap_error_led_set(struct led_classdev *led_cdev,
enum led_brightness value)
{
if (value)
scx200_gpio_set_low(WRAP_ERROR_LED_GPIO);
else
scx200_gpio_set_high(WRAP_ERROR_LED_GPIO);
}
static void wrap_extra_led_set(struct led_classdev *led_cdev,
enum led_brightness value)
{
if (value)
scx200_gpio_set_low(WRAP_EXTRA_LED_GPIO);
else
scx200_gpio_set_high(WRAP_EXTRA_LED_GPIO);
}
static int wrap_led_probe(struct platform_device *pdev)
{
int ret;
ret = led_classdev_register(&pdev->dev, &wrap_power_led);
if (ret < 0)
return ret;
ret = led_classdev_register(&pdev->dev, &wrap_error_led);
if (ret < 0)
goto err1;
ret = led_classdev_register(&pdev->dev, &wrap_extra_led);
if (ret < 0)
goto err2;
return ret;
err2:
led_classdev_unregister(&wrap_error_led);
err1:
led_classdev_unregister(&wrap_power_led);
return ret;
}
static int wrap_led_remove(struct platform_device *pdev)
{
led_classdev_unregister(&wrap_power_led);
led_classdev_unregister(&wrap_error_led);
led_classdev_unregister(&wrap_extra_led);
return 0;
}
static int __init wrap_led_init(void)
{
int ret;
if (!scx200_gpio_present()) {
ret = -ENODEV;
goto out;
}
ret = platform_driver_register(&wrap_led_driver);
if (ret < 0)
goto out;
pdev = platform_device_register_simple(DRVNAME, -1, NULL, 0);
if (IS_ERR(pdev)) {
ret = PTR_ERR(pdev);
platform_driver_unregister(&wrap_led_driver);
goto out;
}
out:
return ret;
}
static void __exit wrap_led_exit(void)
{
platform_device_unregister(pdev);
platform_driver_unregister(&wrap_led_driver);
}
