static void dbg_led_set(struct led_classdev *cdev,
enum led_brightness b)
{
struct dbg_led *led = container_of(cdev, struct dbg_led, cdev);
u16 reg;
reg = __raw_readw(&fpga->leds);
if (b != LED_OFF)
reg |= led->mask;
else
reg &= ~led->mask;
__raw_writew(reg, &fpga->leds);
}
static enum led_brightness dbg_led_get(struct led_classdev *cdev)
{
struct dbg_led *led = container_of(cdev, struct dbg_led, cdev);
u16 reg;
reg = __raw_readw(&fpga->leds);
return (reg & led->mask) ? LED_FULL : LED_OFF;
}
static int fpga_probe(struct platform_device *pdev)
{
struct resource *iomem;
int i;
iomem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!iomem)
return -ENODEV;
fpga = ioremap(iomem->start, resource_size(iomem));
__raw_writew(0xff, &fpga->leds);
for (i = 0; i < ARRAY_SIZE(dbg_leds); i++) {
struct dbg_led *led;
led = kzalloc(sizeof(*led), GFP_KERNEL);
if (!led)
break;
led->cdev.name = dbg_leds[i].name;
led->cdev.brightness_set = dbg_led_set;
led->cdev.brightness_get = dbg_led_get;
led->cdev.default_trigger = dbg_leds[i].trigger;
led->mask = BIT(i);
if (led_classdev_register(NULL, &led->cdev) < 0) {
kfree(led);
break;
}
}
return 0;
}
static int fpga_suspend_noirq(struct device *dev)
{
fpga_led_state = __raw_readw(&fpga->leds);
__raw_writew(0xff, &fpga->leds);
return 0;
}
static int fpga_resume_noirq(struct device *dev)
{
__raw_writew(~fpga_led_state, &fpga->leds);
return 0;
}
static int __init fpga_init(void)
{
if (machine_is_omap_h4()
|| machine_is_omap_h3()
|| machine_is_omap_h2()
|| machine_is_omap_perseus2()
)
return platform_driver_register(&led_driver);
return 0;
}
