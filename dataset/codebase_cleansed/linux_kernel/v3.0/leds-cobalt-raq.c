static void raq_web_led_set(struct led_classdev *led_cdev,
enum led_brightness brightness)
{
unsigned long flags;
spin_lock_irqsave(&led_value_lock, flags);
if (brightness)
led_value |= LED_WEB;
else
led_value &= ~LED_WEB;
writeb(led_value, led_port);
spin_unlock_irqrestore(&led_value_lock, flags);
}
static void raq_power_off_led_set(struct led_classdev *led_cdev,
enum led_brightness brightness)
{
unsigned long flags;
spin_lock_irqsave(&led_value_lock, flags);
if (brightness)
led_value |= LED_POWER_OFF;
else
led_value &= ~LED_POWER_OFF;
writeb(led_value, led_port);
spin_unlock_irqrestore(&led_value_lock, flags);
}
static int __devinit cobalt_raq_led_probe(struct platform_device *pdev)
{
struct resource *res;
int retval;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res)
return -EBUSY;
led_port = ioremap(res->start, resource_size(res));
if (!led_port)
return -ENOMEM;
retval = led_classdev_register(&pdev->dev, &raq_power_off_led);
if (retval)
goto err_iounmap;
retval = led_classdev_register(&pdev->dev, &raq_web_led);
if (retval)
goto err_unregister;
return 0;
err_unregister:
led_classdev_unregister(&raq_power_off_led);
err_iounmap:
iounmap(led_port);
led_port = NULL;
return retval;
}
static int __devexit cobalt_raq_led_remove(struct platform_device *pdev)
{
led_classdev_unregister(&raq_power_off_led);
led_classdev_unregister(&raq_web_led);
if (led_port) {
iounmap(led_port);
led_port = NULL;
}
return 0;
}
static int __init cobalt_raq_led_init(void)
{
return platform_driver_register(&cobalt_raq_led_driver);
}
