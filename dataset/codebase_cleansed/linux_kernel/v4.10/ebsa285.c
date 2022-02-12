static void ebsa285_led_set(struct led_classdev *cdev,
enum led_brightness b)
{
struct ebsa285_led *led = container_of(cdev,
struct ebsa285_led, cdev);
if (b == LED_OFF)
hw_led_state |= led->mask;
else
hw_led_state &= ~led->mask;
writeb(hw_led_state, xbus);
}
static enum led_brightness ebsa285_led_get(struct led_classdev *cdev)
{
struct ebsa285_led *led = container_of(cdev,
struct ebsa285_led, cdev);
return hw_led_state & led->mask ? LED_OFF : LED_FULL;
}
static int __init ebsa285_leds_init(void)
{
int i;
if (!machine_is_ebsa285())
return -ENODEV;
xbus = ioremap(XBUS_CS2, SZ_4K);
if (!xbus)
return -ENOMEM;
hw_led_state = XBUS_AMBER_L | XBUS_GREEN_L | XBUS_RED_L;
writeb(hw_led_state, xbus);
for (i = 0; i < ARRAY_SIZE(ebsa285_leds); i++) {
struct ebsa285_led *led;
led = kzalloc(sizeof(*led), GFP_KERNEL);
if (!led)
break;
led->cdev.name = ebsa285_leds[i].name;
led->cdev.brightness_set = ebsa285_led_set;
led->cdev.brightness_get = ebsa285_led_get;
led->cdev.default_trigger = ebsa285_leds[i].trigger;
led->mask = BIT(i);
if (led_classdev_register(NULL, &led->cdev) < 0) {
kfree(led);
break;
}
}
return 0;
}
