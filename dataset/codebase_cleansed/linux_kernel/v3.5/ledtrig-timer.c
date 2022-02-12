static ssize_t led_delay_on_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct led_classdev *led_cdev = dev_get_drvdata(dev);
return sprintf(buf, "%lu\n", led_cdev->blink_delay_on);
}
static ssize_t led_delay_on_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t size)
{
struct led_classdev *led_cdev = dev_get_drvdata(dev);
unsigned long state;
ssize_t ret = -EINVAL;
ret = kstrtoul(buf, 10, &state);
if (ret)
return ret;
led_blink_set(led_cdev, &state, &led_cdev->blink_delay_off);
led_cdev->blink_delay_on = state;
return size;
}
static ssize_t led_delay_off_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct led_classdev *led_cdev = dev_get_drvdata(dev);
return sprintf(buf, "%lu\n", led_cdev->blink_delay_off);
}
static ssize_t led_delay_off_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t size)
{
struct led_classdev *led_cdev = dev_get_drvdata(dev);
unsigned long state;
ssize_t ret = -EINVAL;
ret = kstrtoul(buf, 10, &state);
if (ret)
return ret;
led_blink_set(led_cdev, &led_cdev->blink_delay_on, &state);
led_cdev->blink_delay_off = state;
return size;
}
static void timer_trig_activate(struct led_classdev *led_cdev)
{
int rc;
led_cdev->trigger_data = NULL;
rc = device_create_file(led_cdev->dev, &dev_attr_delay_on);
if (rc)
return;
rc = device_create_file(led_cdev->dev, &dev_attr_delay_off);
if (rc)
goto err_out_delayon;
led_blink_set(led_cdev, &led_cdev->blink_delay_on,
&led_cdev->blink_delay_off);
led_cdev->activated = true;
return;
err_out_delayon:
device_remove_file(led_cdev->dev, &dev_attr_delay_on);
}
static void timer_trig_deactivate(struct led_classdev *led_cdev)
{
if (led_cdev->activated) {
device_remove_file(led_cdev->dev, &dev_attr_delay_on);
device_remove_file(led_cdev->dev, &dev_attr_delay_off);
led_cdev->activated = false;
}
led_brightness_set(led_cdev, LED_OFF);
}
static int __init timer_trig_init(void)
{
return led_trigger_register(&timer_led_trigger);
}
static void __exit timer_trig_exit(void)
{
led_trigger_unregister(&timer_led_trigger);
}
