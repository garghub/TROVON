void rt2x00leds_led_quality(struct rt2x00_dev *rt2x00dev, int rssi)
{
struct rt2x00_led *led = &rt2x00dev->led_qual;
unsigned int brightness;
if ((led->type != LED_TYPE_QUALITY) || !(led->flags & LED_REGISTERED))
return;
rssi += rt2x00dev->rssi_offset;
if (rssi <= 30)
rssi = 0;
else if (rssi <= 39)
rssi = 1;
else if (rssi <= 49)
rssi = 2;
else if (rssi <= 53)
rssi = 3;
else if (rssi <= 63)
rssi = 4;
else
rssi = 5;
brightness = ((LED_FULL / 6) * rssi) + 1;
if (brightness != led->led_dev.brightness) {
led->led_dev.brightness_set(&led->led_dev, brightness);
led->led_dev.brightness = brightness;
}
}
static void rt2x00led_led_simple(struct rt2x00_led *led, bool enabled)
{
unsigned int brightness = enabled ? LED_FULL : LED_OFF;
if (!(led->flags & LED_REGISTERED))
return;
led->led_dev.brightness_set(&led->led_dev, brightness);
led->led_dev.brightness = brightness;
}
void rt2x00led_led_activity(struct rt2x00_dev *rt2x00dev, bool enabled)
{
if (rt2x00dev->led_qual.type == LED_TYPE_ACTIVITY)
rt2x00led_led_simple(&rt2x00dev->led_qual, enabled);
}
void rt2x00leds_led_assoc(struct rt2x00_dev *rt2x00dev, bool enabled)
{
if (rt2x00dev->led_assoc.type == LED_TYPE_ASSOC)
rt2x00led_led_simple(&rt2x00dev->led_assoc, enabled);
}
void rt2x00leds_led_radio(struct rt2x00_dev *rt2x00dev, bool enabled)
{
if (rt2x00dev->led_radio.type == LED_TYPE_RADIO)
rt2x00led_led_simple(&rt2x00dev->led_radio, enabled);
}
static int rt2x00leds_register_led(struct rt2x00_dev *rt2x00dev,
struct rt2x00_led *led,
const char *name)
{
struct device *device = wiphy_dev(rt2x00dev->hw->wiphy);
int retval;
led->led_dev.name = name;
led->led_dev.brightness = LED_OFF;
retval = led_classdev_register(device, &led->led_dev);
if (retval) {
ERROR(rt2x00dev, "Failed to register led handler.\n");
return retval;
}
led->flags |= LED_REGISTERED;
return 0;
}
void rt2x00leds_register(struct rt2x00_dev *rt2x00dev)
{
char name[36];
int retval;
unsigned long on_period;
unsigned long off_period;
const char *phy_name = wiphy_name(rt2x00dev->hw->wiphy);
if (rt2x00dev->led_radio.flags & LED_INITIALIZED) {
snprintf(name, sizeof(name), "%s-%s::radio",
rt2x00dev->ops->name, phy_name);
retval = rt2x00leds_register_led(rt2x00dev,
&rt2x00dev->led_radio,
name);
if (retval)
goto exit_fail;
}
if (rt2x00dev->led_assoc.flags & LED_INITIALIZED) {
snprintf(name, sizeof(name), "%s-%s::assoc",
rt2x00dev->ops->name, phy_name);
retval = rt2x00leds_register_led(rt2x00dev,
&rt2x00dev->led_assoc,
name);
if (retval)
goto exit_fail;
}
if (rt2x00dev->led_qual.flags & LED_INITIALIZED) {
snprintf(name, sizeof(name), "%s-%s::quality",
rt2x00dev->ops->name, phy_name);
retval = rt2x00leds_register_led(rt2x00dev,
&rt2x00dev->led_qual,
name);
if (retval)
goto exit_fail;
}
if (rt2x00dev->led_radio.led_dev.blink_set) {
on_period = 70;
off_period = 30;
rt2x00dev->led_radio.led_dev.blink_set(
&rt2x00dev->led_radio.led_dev, &on_period, &off_period);
}
return;
exit_fail:
rt2x00leds_unregister(rt2x00dev);
}
static void rt2x00leds_unregister_led(struct rt2x00_led *led)
{
led_classdev_unregister(&led->led_dev);
if (!(led->led_dev.flags & LED_SUSPENDED))
led->led_dev.brightness_set(&led->led_dev, LED_OFF);
led->flags &= ~LED_REGISTERED;
}
void rt2x00leds_unregister(struct rt2x00_dev *rt2x00dev)
{
if (rt2x00dev->led_qual.flags & LED_REGISTERED)
rt2x00leds_unregister_led(&rt2x00dev->led_qual);
if (rt2x00dev->led_assoc.flags & LED_REGISTERED)
rt2x00leds_unregister_led(&rt2x00dev->led_assoc);
if (rt2x00dev->led_radio.flags & LED_REGISTERED)
rt2x00leds_unregister_led(&rt2x00dev->led_radio);
}
static inline void rt2x00leds_suspend_led(struct rt2x00_led *led)
{
led_classdev_suspend(&led->led_dev);
led->led_dev.brightness_set(&led->led_dev, LED_OFF);
led->led_dev.brightness = LED_OFF;
}
void rt2x00leds_suspend(struct rt2x00_dev *rt2x00dev)
{
if (rt2x00dev->led_qual.flags & LED_REGISTERED)
rt2x00leds_suspend_led(&rt2x00dev->led_qual);
if (rt2x00dev->led_assoc.flags & LED_REGISTERED)
rt2x00leds_suspend_led(&rt2x00dev->led_assoc);
if (rt2x00dev->led_radio.flags & LED_REGISTERED)
rt2x00leds_suspend_led(&rt2x00dev->led_radio);
}
static inline void rt2x00leds_resume_led(struct rt2x00_led *led)
{
led_classdev_resume(&led->led_dev);
led->led_dev.brightness_set(&led->led_dev, LED_OFF);
led->led_dev.brightness = LED_OFF;
}
void rt2x00leds_resume(struct rt2x00_dev *rt2x00dev)
{
if (rt2x00dev->led_radio.flags & LED_REGISTERED)
rt2x00leds_resume_led(&rt2x00dev->led_radio);
if (rt2x00dev->led_assoc.flags & LED_REGISTERED)
rt2x00leds_resume_led(&rt2x00dev->led_assoc);
if (rt2x00dev->led_qual.flags & LED_REGISTERED)
rt2x00leds_resume_led(&rt2x00dev->led_qual);
}
