static void ot200_led_brightness_set(struct led_classdev *led_cdev,
enum led_brightness value)
{
struct ot200_led *led = container_of(led_cdev, struct ot200_led, cdev);
u8 *val;
unsigned long flags;
spin_lock_irqsave(&value_lock, flags);
if (led->port == 0x49)
val = &leds_front;
else if (led->port == 0x5a)
val = &leds_back;
else
BUG();
if (value == LED_OFF)
*val &= ~led->mask;
else
*val |= led->mask;
outb(*val, led->port);
spin_unlock_irqrestore(&value_lock, flags);
}
static int ot200_led_probe(struct platform_device *pdev)
{
int i;
int ret;
for (i = 0; i < ARRAY_SIZE(leds); i++) {
leds[i].cdev.name = leds[i].name;
leds[i].cdev.brightness_set = ot200_led_brightness_set;
ret = devm_led_classdev_register(&pdev->dev, &leds[i].cdev);
if (ret < 0)
return ret;
}
leds_front = 0;
leds_back = BIT(1);
outb(leds_front, 0x49);
outb(leds_back, 0x5a);
return 0;
}
