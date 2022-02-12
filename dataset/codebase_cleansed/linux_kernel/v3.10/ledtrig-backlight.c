static int fb_notifier_callback(struct notifier_block *p,
unsigned long event, void *data)
{
struct bl_trig_notifier *n = container_of(p,
struct bl_trig_notifier, notifier);
struct led_classdev *led = n->led;
struct fb_event *fb_event = data;
int *blank = fb_event->data;
int new_status = *blank ? BLANK : UNBLANK;
switch (event) {
case FB_EVENT_BLANK:
if (new_status == n->old_status)
break;
if ((n->old_status == UNBLANK) ^ n->invert) {
n->brightness = led->brightness;
__led_set_brightness(led, LED_OFF);
} else {
__led_set_brightness(led, n->brightness);
}
n->old_status = new_status;
break;
}
return 0;
}
static ssize_t bl_trig_invert_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct led_classdev *led = dev_get_drvdata(dev);
struct bl_trig_notifier *n = led->trigger_data;
return sprintf(buf, "%u\n", n->invert);
}
static ssize_t bl_trig_invert_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t num)
{
struct led_classdev *led = dev_get_drvdata(dev);
struct bl_trig_notifier *n = led->trigger_data;
unsigned long invert;
int ret;
ret = kstrtoul(buf, 10, &invert);
if (ret < 0)
return ret;
if (invert > 1)
return -EINVAL;
n->invert = invert;
if ((n->old_status == BLANK) ^ n->invert)
__led_set_brightness(led, LED_OFF);
else
__led_set_brightness(led, n->brightness);
return num;
}
static void bl_trig_activate(struct led_classdev *led)
{
int ret;
struct bl_trig_notifier *n;
n = kzalloc(sizeof(struct bl_trig_notifier), GFP_KERNEL);
led->trigger_data = n;
if (!n) {
dev_err(led->dev, "unable to allocate backlight trigger\n");
return;
}
ret = device_create_file(led->dev, &dev_attr_inverted);
if (ret)
goto err_invert;
n->led = led;
n->brightness = led->brightness;
n->old_status = UNBLANK;
n->notifier.notifier_call = fb_notifier_callback;
ret = fb_register_client(&n->notifier);
if (ret)
dev_err(led->dev, "unable to register backlight trigger\n");
led->activated = true;
return;
err_invert:
led->trigger_data = NULL;
kfree(n);
}
static void bl_trig_deactivate(struct led_classdev *led)
{
struct bl_trig_notifier *n =
(struct bl_trig_notifier *) led->trigger_data;
if (led->activated) {
device_remove_file(led->dev, &dev_attr_inverted);
fb_unregister_client(&n->notifier);
kfree(n);
led->activated = false;
}
}
static int __init bl_trig_init(void)
{
return led_trigger_register(&bl_led_trigger);
}
static void __exit bl_trig_exit(void)
{
led_trigger_unregister(&bl_led_trigger);
}
