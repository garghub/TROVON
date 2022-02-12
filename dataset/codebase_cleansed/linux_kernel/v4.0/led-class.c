static ssize_t brightness_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct led_classdev *led_cdev = dev_get_drvdata(dev);
led_update_brightness(led_cdev);
return sprintf(buf, "%u\n", led_cdev->brightness);
}
static ssize_t brightness_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t size)
{
struct led_classdev *led_cdev = dev_get_drvdata(dev);
unsigned long state;
ssize_t ret;
mutex_lock(&led_cdev->led_access);
if (led_sysfs_is_disabled(led_cdev)) {
ret = -EBUSY;
goto unlock;
}
ret = kstrtoul(buf, 10, &state);
if (ret)
goto unlock;
if (state == LED_OFF)
led_trigger_remove(led_cdev);
led_set_brightness(led_cdev, state);
ret = size;
unlock:
mutex_unlock(&led_cdev->led_access);
return ret;
}
static ssize_t max_brightness_show(struct device *dev,
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
led_set_brightness_async(led_cdev, LED_OFF);
return;
}
if (led_cdev->flags & LED_BLINK_ONESHOT_STOP) {
led_cdev->flags &= ~LED_BLINK_ONESHOT_STOP;
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
led_set_brightness_async(led_cdev, brightness);
if (led_cdev->flags & LED_BLINK_ONESHOT) {
if (led_cdev->flags & LED_BLINK_INVERT) {
if (brightness)
led_cdev->flags |= LED_BLINK_ONESHOT_STOP;
} else {
if (!brightness)
led_cdev->flags |= LED_BLINK_ONESHOT_STOP;
}
}
mod_timer(&led_cdev->blink_timer, jiffies + msecs_to_jiffies(delay));
}
static void set_brightness_delayed(struct work_struct *ws)
{
struct led_classdev *led_cdev =
container_of(ws, struct led_classdev, set_brightness_work);
led_stop_software_blink(led_cdev);
led_set_brightness_async(led_cdev, led_cdev->delayed_set_value);
}
void led_classdev_suspend(struct led_classdev *led_cdev)
{
led_cdev->flags |= LED_SUSPENDED;
led_cdev->brightness_set(led_cdev, 0);
}
void led_classdev_resume(struct led_classdev *led_cdev)
{
led_cdev->brightness_set(led_cdev, led_cdev->brightness);
if (led_cdev->flash_resume)
led_cdev->flash_resume(led_cdev);
led_cdev->flags &= ~LED_SUSPENDED;
}
static int led_suspend(struct device *dev)
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
led_cdev->dev = device_create_with_groups(leds_class, parent, 0,
led_cdev, led_cdev->groups,
"%s", led_cdev->name);
if (IS_ERR(led_cdev->dev))
return PTR_ERR(led_cdev->dev);
#ifdef CONFIG_LEDS_TRIGGERS
init_rwsem(&led_cdev->trigger_lock);
#endif
mutex_init(&led_cdev->led_access);
down_write(&leds_list_lock);
list_add_tail(&led_cdev->node, &leds_list);
up_write(&leds_list_lock);
if (!led_cdev->max_brightness)
led_cdev->max_brightness = LED_FULL;
led_cdev->flags |= SET_BRIGHTNESS_ASYNC;
led_update_brightness(led_cdev);
INIT_WORK(&led_cdev->set_brightness_work, set_brightness_delayed);
setup_timer(&led_cdev->blink_timer, led_timer_function,
(unsigned long)led_cdev);
#ifdef CONFIG_LEDS_TRIGGERS
led_trigger_set_default(led_cdev);
#endif
dev_dbg(parent, "Registered led device: %s\n",
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
cancel_work_sync(&led_cdev->set_brightness_work);
led_stop_software_blink(led_cdev);
led_set_brightness(led_cdev, LED_OFF);
device_unregister(led_cdev->dev);
down_write(&leds_list_lock);
list_del(&led_cdev->node);
up_write(&leds_list_lock);
mutex_destroy(&led_cdev->led_access);
}
static int __init leds_init(void)
{
leds_class = class_create(THIS_MODULE, "leds");
if (IS_ERR(leds_class))
return PTR_ERR(leds_class);
leds_class->pm = &leds_class_dev_pm_ops;
leds_class->dev_groups = led_groups;
return 0;
}
static void __exit leds_exit(void)
{
class_destroy(leds_class);
}
