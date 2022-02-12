static void qube_front_led_set(struct led_classdev *led_cdev,
enum led_brightness brightness)
{
if (brightness)
led_value = LED_FRONT_LEFT | LED_FRONT_RIGHT;
else
led_value = ~(LED_FRONT_LEFT | LED_FRONT_RIGHT);
writeb(led_value, led_port);
}
static int cobalt_qube_led_probe(struct platform_device *pdev)
{
struct resource *res;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res)
return -EBUSY;
led_port = devm_ioremap(&pdev->dev, res->start, resource_size(res));
if (!led_port)
return -ENOMEM;
led_value = LED_FRONT_LEFT | LED_FRONT_RIGHT;
writeb(led_value, led_port);
return devm_led_classdev_register(&pdev->dev, &qube_front_led);
}
