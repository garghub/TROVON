static void qube_front_led_set(struct led_classdev *led_cdev,
enum led_brightness brightness)
{
if (brightness)
led_value = LED_FRONT_LEFT | LED_FRONT_RIGHT;
else
led_value = ~(LED_FRONT_LEFT | LED_FRONT_RIGHT);
writeb(led_value, led_port);
}
static int __devinit cobalt_qube_led_probe(struct platform_device *pdev)
{
struct resource *res;
int retval;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res)
return -EBUSY;
led_port = ioremap(res->start, resource_size(res));
if (!led_port)
return -ENOMEM;
led_value = LED_FRONT_LEFT | LED_FRONT_RIGHT;
writeb(led_value, led_port);
retval = led_classdev_register(&pdev->dev, &qube_front_led);
if (retval)
goto err_iounmap;
return 0;
err_iounmap:
iounmap(led_port);
led_port = NULL;
return retval;
}
static int __devexit cobalt_qube_led_remove(struct platform_device *pdev)
{
led_classdev_unregister(&qube_front_led);
if (led_port) {
iounmap(led_port);
led_port = NULL;
}
return 0;
}
static int __init cobalt_qube_led_init(void)
{
return platform_driver_register(&cobalt_qube_led_driver);
}
static void __exit cobalt_qube_led_exit(void)
{
platform_driver_unregister(&cobalt_qube_led_driver);
}
