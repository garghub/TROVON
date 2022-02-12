static void ebsa285_led_set(struct led_classdev *cdev,
enum led_brightness b)
{
struct ebsa285_led *led = container_of(cdev,
struct ebsa285_led, cdev);
if (b == LED_OFF)
hw_led_state |= led->mask;
else
hw_led_state &= ~led->mask;
*XBUS_LEDS = hw_led_state;
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
hw_led_state = XBUS_LED_AMBER | XBUS_LED_GREEN | XBUS_LED_RED;
*XBUS_LEDS = hw_led_state;
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
