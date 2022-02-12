static void ebsa285_led_set(struct led_classdev *cdev,
enum led_brightness b)
{
struct ebsa285_led *led = container_of(cdev,
struct ebsa285_led, cdev);
if (b != LED_OFF)
*XBUS_LEDS |= led->mask;
else
*XBUS_LEDS &= ~led->mask;
}
static enum led_brightness ebsa285_led_get(struct led_classdev *cdev)
{
struct ebsa285_led *led = container_of(cdev,
struct ebsa285_led, cdev);
return (*XBUS_LEDS & led->mask) ? LED_FULL : LED_OFF;
}
static int __init ebsa285_leds_init(void)
{
int i;
if (machine_is_ebsa285())
return -ENODEV;
*XBUS_LEDS |= XBUS_LED_AMBER | XBUS_LED_GREEN | XBUS_LED_RED;
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
