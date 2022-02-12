static void versatile_led_set(struct led_classdev *cdev,
enum led_brightness b)
{
struct versatile_led *led = container_of(cdev,
struct versatile_led, cdev);
u32 reg = readl(led->base);
if (b != LED_OFF)
reg |= led->mask;
else
reg &= ~led->mask;
writel(reg, led->base);
}
static enum led_brightness versatile_led_get(struct led_classdev *cdev)
{
struct versatile_led *led = container_of(cdev,
struct versatile_led, cdev);
u32 reg = readl(led->base);
return (reg & led->mask) ? LED_FULL : LED_OFF;
}
static int versatile_leds_probe(struct platform_device *dev)
{
int i;
struct resource *res;
void __iomem *base;
res = platform_get_resource(dev, IORESOURCE_MEM, 0);
base = devm_ioremap_resource(&dev->dev, res);
if (IS_ERR(base))
return PTR_ERR(base);
writel(0, base);
for (i = 0; i < ARRAY_SIZE(versatile_leds); i++) {
struct versatile_led *led;
led = kzalloc(sizeof(*led), GFP_KERNEL);
if (!led)
break;
led->base = base;
led->cdev.name = versatile_leds[i].name;
led->cdev.brightness_set = versatile_led_set;
led->cdev.brightness_get = versatile_led_get;
led->cdev.default_trigger = versatile_leds[i].trigger;
led->mask = BIT(i);
if (led_classdev_register(NULL, &led->cdev) < 0) {
kfree(led);
break;
}
}
return 0;
}
