static void led_update_brightness(struct led_classdev *led_cdev)
{
if (led_cdev->brightness_get)
led_cdev->brightness = led_cdev->brightness_get(led_cdev);
}
static ssize_t led_brightness_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct led_classdev *led_cdev = dev_get_drvdata(dev);
led_update_brightness(led_cdev);
return sprintf(buf, "%u\n", led_cdev->brightness);
}
static ssize_t led_brightness_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t size)
{
struct led_classdev *led_cdev = dev_get_drvdata(dev);
ssize_t ret = -EINVAL;
char *after;
unsigned long state = simple_strtoul(buf, &after, 10);
size_t count = after - buf;
if (isspace(*after))
count++;
if (count == size) {
ret = count;
if (state == LED_OFF)
led_trigger_remove(led_cdev);
led_set_brightness(led_cdev, state);
}
return ret;
}
static ssize_t led_max_brightness_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct led_classdev *led_cdev = dev_get_drvdata(dev);
return sprintf(buf, "%u\n", led_cdev->max_brightness);
}
static void led_timer_function(unsigned long data)
{
struct led_classdev *led_cdev = (void *)data;
unsigned long brightness;
unsigned long delay;
if (!led_cdev->blink_delay_on || !led_cdev->blink_delay_off) {
led_set_brightness(led_cdev, LED_OFF);
return;
}
brightness = led_get_brightness(led_cdev);
if (!brightness) {
brightness = led_cdev->blink_brightness;
delay = led_cdev->blink_delay_on;
} else {
led_cdev->blink_brightness = brightness;
brightness = LED_OFF;
delay = led_cdev->blink_delay_off;
}
led_set_brightness(led_cdev, brightness);
mod_timer(&led_cdev->blink_timer, jiffies + msecs_to_jiffies(delay));
}
static void led_stop_software_blink(struct led_classdev *led_cdev)
{
del_timer_sync(&led_cdev->blink_timer);
led_cdev->blink_delay_on = 0;
led_cdev->blink_delay_off = 0;
}
static void led_set_software_blink(struct led_classdev *led_cdev,
unsigned long delay_on,
unsigned long delay_off)
{
int current_brightness;
current_brightness = led_get_brightness(led_cdev);
if (current_brightness)
led_cdev->blink_brightness = current_brightness;
if (!led_cdev->blink_brightness)
led_cdev->blink_brightness = led_cdev->max_brightness;
if (led_get_trigger_data(led_cdev) &&
delay_on == led_cdev->blink_delay_on &&
delay_off == led_cdev->blink_delay_off)
return;
led_stop_software_blink(led_cdev);
led_cdev->blink_delay_on = delay_on;
led_cdev->blink_delay_off = delay_off;
if (!delay_on)
return;
if (!delay_off) {
led_set_brightness(led_cdev, led_cdev->blink_brightness);
return;
}
mod_timer(&led_cdev->blink_timer, jiffies + 1);
}
void led_classdev_suspend(struct led_classdev *led_cdev)
{
led_cdev->flags |= LED_SUSPENDED;
led_cdev->brightness_set(led_cdev, 0);
}
void led_classdev_resume(struct led_classdev *led_cdev)
{
led_cdev->brightness_set(led_cdev, led_cdev->brightness);
led_cdev->flags &= ~LED_SUSPENDED;
}
static int led_suspend(struct device *dev, pm_message_t state)
{
struct led_classdev *led_cdev = dev_get_drvdata(dev);
if (led_cdev->flags & LED_CORE_SUSPENDRESUME)
led_classdev_suspend(led_cdev);
return 0;
}
static int led_resume(struct device *dev)
{
struct led_classdev *led_cdev = dev_get_drvdata(dev);
if (led_cdev->flags & LED_CORE_SUSPENDRESUME)
led_classdev_resume(led_cdev);
return 0;
}
int led_classdev_register(struct device *parent, struct led_classdev *led_cdev)
{
led_cdev->dev = device_create(leds_class, parent, 0, led_cdev,
"%s", led_cdev->name);
if (IS_ERR(led_cdev->dev))
return PTR_ERR(led_cdev->dev);
#ifdef CONFIG_LEDS_TRIGGERS
init_rwsem(&led_cdev->trigger_lock);
#endif
down_write(&leds_list_lock);
list_add_tail(&led_cdev->node, &leds_list);
up_write(&leds_list_lock);
if (!led_cdev->max_brightness)
led_cdev->max_brightness = LED_FULL;
led_update_brightness(led_cdev);
init_timer(&led_cdev->blink_timer);
led_cdev->blink_timer.function = led_timer_function;
led_cdev->blink_timer.data = (unsigned long)led_cdev;
#ifdef CONFIG_LEDS_TRIGGERS
led_trigger_set_default(led_cdev);
#endif
printk(KERN_DEBUG "Registered led device: %s\n",
led_cdev->name);
return 0;
}
void led_classdev_unregister(struct led_classdev *led_cdev)
{
#ifdef CONFIG_LEDS_TRIGGERS
down_write(&led_cdev->trigger_lock);
if (led_cdev->trigger)
led_trigger_set(led_cdev, NULL);
up_write(&led_cdev->trigger_lock);
#endif
led_brightness_set(led_cdev, LED_OFF);
device_unregister(led_cdev->dev);
down_write(&leds_list_lock);
list_del(&led_cdev->node);
up_write(&leds_list_lock);
}
void led_blink_set(struct led_classdev *led_cdev,
unsigned long *delay_on,
unsigned long *delay_off)
{
if (led_cdev->blink_set &&
!led_cdev->blink_set(led_cdev, delay_on, delay_off))
return;
if (!*delay_on && !*delay_off)
*delay_on = *delay_off = 500;
led_set_software_blink(led_cdev, *delay_on, *delay_off);
}
void led_brightness_set(struct led_classdev *led_cdev,
enum led_brightness brightness)
{
led_stop_software_blink(led_cdev);
led_cdev->brightness_set(led_cdev, brightness);
}
static int __init leds_init(void)
{
leds_class = class_create(THIS_MODULE, "leds");
if (IS_ERR(leds_class))
return PTR_ERR(leds_class);
leds_class->suspend = led_suspend;
leds_class->resume = led_resume;
leds_class->dev_attrs = led_class_attrs;
return 0;
}
static void __exit leds_exit(void)
{
class_destroy(leds_class);
}
