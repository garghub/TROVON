static ssize_t led_shot(struct device *dev,
struct device_attribute *attr, const char *buf, size_t size)
{
struct led_classdev *led_cdev = dev_get_drvdata(dev);
struct oneshot_trig_data *oneshot_data = led_cdev->trigger_data;
led_blink_set_oneshot(led_cdev,
&led_cdev->blink_delay_on, &led_cdev->blink_delay_off,
oneshot_data->invert);
return size;
}
static ssize_t led_invert_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct led_classdev *led_cdev = dev_get_drvdata(dev);
struct oneshot_trig_data *oneshot_data = led_cdev->trigger_data;
return sprintf(buf, "%u\n", oneshot_data->invert);
}
static ssize_t led_invert_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t size)
{
struct led_classdev *led_cdev = dev_get_drvdata(dev);
struct oneshot_trig_data *oneshot_data = led_cdev->trigger_data;
unsigned long state;
int ret;
ret = kstrtoul(buf, 0, &state);
if (ret)
return ret;
oneshot_data->invert = !!state;
if (oneshot_data->invert)
__led_set_brightness(led_cdev, LED_FULL);
else
__led_set_brightness(led_cdev, LED_OFF);
return size;
}
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
int ret;
ret = kstrtoul(buf, 0, &state);
if (ret)
return ret;
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
int ret;
ret = kstrtoul(buf, 0, &state);
if (ret)
return ret;
led_cdev->blink_delay_off = state;
return size;
}
static void oneshot_trig_activate(struct led_classdev *led_cdev)
{
struct oneshot_trig_data *oneshot_data;
int rc;
oneshot_data = kzalloc(sizeof(*oneshot_data), GFP_KERNEL);
if (!oneshot_data)
return;
led_cdev->trigger_data = oneshot_data;
rc = device_create_file(led_cdev->dev, &dev_attr_delay_on);
if (rc)
goto err_out_trig_data;
rc = device_create_file(led_cdev->dev, &dev_attr_delay_off);
if (rc)
goto err_out_delayon;
rc = device_create_file(led_cdev->dev, &dev_attr_invert);
if (rc)
goto err_out_delayoff;
rc = device_create_file(led_cdev->dev, &dev_attr_shot);
if (rc)
goto err_out_invert;
led_cdev->blink_delay_on = DEFAULT_DELAY;
led_cdev->blink_delay_off = DEFAULT_DELAY;
led_cdev->activated = true;
return;
err_out_invert:
device_remove_file(led_cdev->dev, &dev_attr_invert);
err_out_delayoff:
device_remove_file(led_cdev->dev, &dev_attr_delay_off);
err_out_delayon:
device_remove_file(led_cdev->dev, &dev_attr_delay_on);
err_out_trig_data:
kfree(led_cdev->trigger_data);
}
static void oneshot_trig_deactivate(struct led_classdev *led_cdev)
{
struct oneshot_trig_data *oneshot_data = led_cdev->trigger_data;
if (led_cdev->activated) {
device_remove_file(led_cdev->dev, &dev_attr_delay_on);
device_remove_file(led_cdev->dev, &dev_attr_delay_off);
device_remove_file(led_cdev->dev, &dev_attr_invert);
device_remove_file(led_cdev->dev, &dev_attr_shot);
kfree(oneshot_data);
led_cdev->activated = false;
}
led_set_brightness(led_cdev, LED_OFF);
}
static int __init oneshot_trig_init(void)
{
return led_trigger_register(&oneshot_led_trigger);
}
static void __exit oneshot_trig_exit(void)
{
led_trigger_unregister(&oneshot_led_trigger);
}
