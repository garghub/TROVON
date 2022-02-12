static inline struct s3c24xx_gpio_led *pdev_to_gpio(struct platform_device *dev)
{
return platform_get_drvdata(dev);
}
static inline struct s3c24xx_gpio_led *to_gpio(struct led_classdev *led_cdev)
{
return container_of(led_cdev, struct s3c24xx_gpio_led, cdev);
}
static void s3c24xx_led_set(struct led_classdev *led_cdev,
enum led_brightness value)
{
struct s3c24xx_gpio_led *led = to_gpio(led_cdev);
struct s3c24xx_led_platdata *pd = led->pdata;
int state = (value ? 1 : 0) ^ (pd->flags & S3C24XX_LEDF_ACTLOW);
gpio_set_value(pd->gpio, state);
if (pd->flags & S3C24XX_LEDF_TRISTATE) {
if (value)
gpio_direction_output(pd->gpio, state);
else
gpio_direction_input(pd->gpio);
}
}
static int s3c24xx_led_remove(struct platform_device *dev)
{
struct s3c24xx_gpio_led *led = pdev_to_gpio(dev);
led_classdev_unregister(&led->cdev);
return 0;
}
static int s3c24xx_led_probe(struct platform_device *dev)
{
struct s3c24xx_led_platdata *pdata = dev_get_platdata(&dev->dev);
struct s3c24xx_gpio_led *led;
int ret;
led = devm_kzalloc(&dev->dev, sizeof(struct s3c24xx_gpio_led),
GFP_KERNEL);
if (!led)
return -ENOMEM;
platform_set_drvdata(dev, led);
led->cdev.brightness_set = s3c24xx_led_set;
led->cdev.default_trigger = pdata->def_trigger;
led->cdev.name = pdata->name;
led->cdev.flags |= LED_CORE_SUSPENDRESUME;
led->pdata = pdata;
ret = devm_gpio_request(&dev->dev, pdata->gpio, "S3C24XX_LED");
if (ret < 0)
return ret;
s3c_gpio_setpull(pdata->gpio, S3C_GPIO_PULL_NONE);
if (pdata->flags & S3C24XX_LEDF_TRISTATE)
gpio_direction_input(pdata->gpio);
else
gpio_direction_output(pdata->gpio,
pdata->flags & S3C24XX_LEDF_ACTLOW ? 1 : 0);
ret = led_classdev_register(&dev->dev, &led->cdev);
if (ret < 0)
dev_err(&dev->dev, "led_classdev_register failed\n");
return ret;
}
