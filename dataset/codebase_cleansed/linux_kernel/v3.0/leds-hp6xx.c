static void hp6xxled_green_set(struct led_classdev *led_cdev,
enum led_brightness value)
{
u8 v8;
v8 = inb(PKDR);
if (value)
outb(v8 & (~PKDR_LED_GREEN), PKDR);
else
outb(v8 | PKDR_LED_GREEN, PKDR);
}
static void hp6xxled_red_set(struct led_classdev *led_cdev,
enum led_brightness value)
{
u16 v16;
v16 = inw(HD64461_GPBDR);
if (value)
outw(v16 & (~HD64461_GPBDR_LED_RED), HD64461_GPBDR);
else
outw(v16 | HD64461_GPBDR_LED_RED, HD64461_GPBDR);
}
static int hp6xxled_probe(struct platform_device *pdev)
{
int ret;
ret = led_classdev_register(&pdev->dev, &hp6xx_red_led);
if (ret < 0)
return ret;
ret = led_classdev_register(&pdev->dev, &hp6xx_green_led);
if (ret < 0)
led_classdev_unregister(&hp6xx_red_led);
return ret;
}
static int hp6xxled_remove(struct platform_device *pdev)
{
led_classdev_unregister(&hp6xx_red_led);
led_classdev_unregister(&hp6xx_green_led);
return 0;
}
static int __init hp6xxled_init(void)
{
return platform_driver_register(&hp6xxled_driver);
}
static void __exit hp6xxled_exit(void)
{
platform_driver_unregister(&hp6xxled_driver);
}
