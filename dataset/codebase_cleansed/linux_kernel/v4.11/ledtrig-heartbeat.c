static void led_heartbeat_function(unsigned long data)
{
struct led_classdev *led_cdev = (struct led_classdev *) data;
struct heartbeat_trig_data *heartbeat_data = led_cdev->trigger_data;
unsigned long brightness = LED_OFF;
unsigned long delay = 0;
if (unlikely(panic_heartbeats)) {
led_set_brightness_nosleep(led_cdev, LED_OFF);
return;
}
if (test_and_clear_bit(LED_BLINK_BRIGHTNESS_CHANGE, &led_cdev->work_flags))
led_cdev->blink_brightness = led_cdev->new_blink_brightness;
switch (heartbeat_data->phase) {
case 0:
heartbeat_data->period = 300 +
(6720 << FSHIFT) / (5 * avenrun[0] + (7 << FSHIFT));
heartbeat_data->period =
msecs_to_jiffies(heartbeat_data->period);
delay = msecs_to_jiffies(70);
heartbeat_data->phase++;
if (!heartbeat_data->invert)
brightness = led_cdev->blink_brightness;
break;
case 1:
delay = heartbeat_data->period / 4 - msecs_to_jiffies(70);
heartbeat_data->phase++;
if (heartbeat_data->invert)
brightness = led_cdev->blink_brightness;
break;
case 2:
delay = msecs_to_jiffies(70);
heartbeat_data->phase++;
if (!heartbeat_data->invert)
brightness = led_cdev->blink_brightness;
break;
default:
delay = heartbeat_data->period - heartbeat_data->period / 4 -
msecs_to_jiffies(70);
heartbeat_data->phase = 0;
if (heartbeat_data->invert)
brightness = led_cdev->blink_brightness;
break;
}
led_set_brightness_nosleep(led_cdev, brightness);
mod_timer(&heartbeat_data->timer, jiffies + delay);
}
static ssize_t led_invert_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct led_classdev *led_cdev = dev_get_drvdata(dev);
struct heartbeat_trig_data *heartbeat_data = led_cdev->trigger_data;
return sprintf(buf, "%u\n", heartbeat_data->invert);
}
static ssize_t led_invert_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t size)
{
struct led_classdev *led_cdev = dev_get_drvdata(dev);
struct heartbeat_trig_data *heartbeat_data = led_cdev->trigger_data;
unsigned long state;
int ret;
ret = kstrtoul(buf, 0, &state);
if (ret)
return ret;
heartbeat_data->invert = !!state;
return size;
}
static void heartbeat_trig_activate(struct led_classdev *led_cdev)
{
struct heartbeat_trig_data *heartbeat_data;
int rc;
heartbeat_data = kzalloc(sizeof(*heartbeat_data), GFP_KERNEL);
if (!heartbeat_data)
return;
led_cdev->trigger_data = heartbeat_data;
rc = device_create_file(led_cdev->dev, &dev_attr_invert);
if (rc) {
kfree(led_cdev->trigger_data);
return;
}
setup_timer(&heartbeat_data->timer,
led_heartbeat_function, (unsigned long) led_cdev);
heartbeat_data->phase = 0;
if (!led_cdev->blink_brightness)
led_cdev->blink_brightness = led_cdev->max_brightness;
led_heartbeat_function(heartbeat_data->timer.data);
set_bit(LED_BLINK_SW, &led_cdev->work_flags);
led_cdev->activated = true;
}
static void heartbeat_trig_deactivate(struct led_classdev *led_cdev)
{
struct heartbeat_trig_data *heartbeat_data = led_cdev->trigger_data;
if (led_cdev->activated) {
del_timer_sync(&heartbeat_data->timer);
device_remove_file(led_cdev->dev, &dev_attr_invert);
kfree(heartbeat_data);
clear_bit(LED_BLINK_SW, &led_cdev->work_flags);
led_cdev->activated = false;
}
}
static int heartbeat_pm_notifier(struct notifier_block *nb,
unsigned long pm_event, void *unused)
{
int rc;
switch (pm_event) {
case PM_SUSPEND_PREPARE:
case PM_HIBERNATION_PREPARE:
case PM_RESTORE_PREPARE:
led_trigger_unregister(&heartbeat_led_trigger);
break;
case PM_POST_SUSPEND:
case PM_POST_HIBERNATION:
case PM_POST_RESTORE:
rc = led_trigger_register(&heartbeat_led_trigger);
if (rc)
pr_err("could not re-register heartbeat trigger\n");
break;
default:
break;
}
return NOTIFY_DONE;
}
static int heartbeat_reboot_notifier(struct notifier_block *nb,
unsigned long code, void *unused)
{
led_trigger_unregister(&heartbeat_led_trigger);
return NOTIFY_DONE;
}
static int heartbeat_panic_notifier(struct notifier_block *nb,
unsigned long code, void *unused)
{
panic_heartbeats = 1;
return NOTIFY_DONE;
}
static int __init heartbeat_trig_init(void)
{
int rc = led_trigger_register(&heartbeat_led_trigger);
if (!rc) {
atomic_notifier_chain_register(&panic_notifier_list,
&heartbeat_panic_nb);
register_reboot_notifier(&heartbeat_reboot_nb);
register_pm_notifier(&heartbeat_pm_nb);
}
return rc;
}
static void __exit heartbeat_trig_exit(void)
{
unregister_pm_notifier(&heartbeat_pm_nb);
unregister_reboot_notifier(&heartbeat_reboot_nb);
atomic_notifier_chain_unregister(&panic_notifier_list,
&heartbeat_panic_nb);
led_trigger_unregister(&heartbeat_led_trigger);
}
