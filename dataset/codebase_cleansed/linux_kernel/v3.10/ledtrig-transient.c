static void transient_timer_function(unsigned long data)
{
struct led_classdev *led_cdev = (struct led_classdev *) data;
struct transient_trig_data *transient_data = led_cdev->trigger_data;
transient_data->activate = 0;
__led_set_brightness(led_cdev, transient_data->restore_state);
}
static ssize_t transient_activate_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct led_classdev *led_cdev = dev_get_drvdata(dev);
struct transient_trig_data *transient_data = led_cdev->trigger_data;
return sprintf(buf, "%d\n", transient_data->activate);
}
static ssize_t transient_activate_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t size)
{
struct led_classdev *led_cdev = dev_get_drvdata(dev);
struct transient_trig_data *transient_data = led_cdev->trigger_data;
unsigned long state;
ssize_t ret;
ret = kstrtoul(buf, 10, &state);
if (ret)
return ret;
if (state != 1 && state != 0)
return -EINVAL;
if (state == 0 && transient_data->activate == 1) {
del_timer(&transient_data->timer);
transient_data->activate = state;
__led_set_brightness(led_cdev, transient_data->restore_state);
return size;
}
if (state == 1 && transient_data->activate == 0 &&
transient_data->duration != 0) {
transient_data->activate = state;
__led_set_brightness(led_cdev, transient_data->state);
transient_data->restore_state =
(transient_data->state == LED_FULL) ? LED_OFF : LED_FULL;
mod_timer(&transient_data->timer,
jiffies + transient_data->duration);
}
return size;
}
static ssize_t transient_duration_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct led_classdev *led_cdev = dev_get_drvdata(dev);
struct transient_trig_data *transient_data = led_cdev->trigger_data;
return sprintf(buf, "%lu\n", transient_data->duration);
}
static ssize_t transient_duration_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t size)
{
struct led_classdev *led_cdev = dev_get_drvdata(dev);
struct transient_trig_data *transient_data = led_cdev->trigger_data;
unsigned long state;
ssize_t ret;
ret = kstrtoul(buf, 10, &state);
if (ret)
return ret;
transient_data->duration = state;
return size;
}
static ssize_t transient_state_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct led_classdev *led_cdev = dev_get_drvdata(dev);
struct transient_trig_data *transient_data = led_cdev->trigger_data;
int state;
state = (transient_data->state == LED_FULL) ? 1 : 0;
return sprintf(buf, "%d\n", state);
}
static ssize_t transient_state_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t size)
{
struct led_classdev *led_cdev = dev_get_drvdata(dev);
struct transient_trig_data *transient_data = led_cdev->trigger_data;
unsigned long state;
ssize_t ret;
ret = kstrtoul(buf, 10, &state);
if (ret)
return ret;
if (state != 1 && state != 0)
return -EINVAL;
transient_data->state = (state == 1) ? LED_FULL : LED_OFF;
return size;
}
static void transient_trig_activate(struct led_classdev *led_cdev)
{
int rc;
struct transient_trig_data *tdata;
tdata = kzalloc(sizeof(struct transient_trig_data), GFP_KERNEL);
if (!tdata) {
dev_err(led_cdev->dev,
"unable to allocate transient trigger\n");
return;
}
led_cdev->trigger_data = tdata;
rc = device_create_file(led_cdev->dev, &dev_attr_activate);
if (rc)
goto err_out;
rc = device_create_file(led_cdev->dev, &dev_attr_duration);
if (rc)
goto err_out_duration;
rc = device_create_file(led_cdev->dev, &dev_attr_state);
if (rc)
goto err_out_state;
setup_timer(&tdata->timer, transient_timer_function,
(unsigned long) led_cdev);
led_cdev->activated = true;
return;
err_out_state:
device_remove_file(led_cdev->dev, &dev_attr_duration);
err_out_duration:
device_remove_file(led_cdev->dev, &dev_attr_activate);
err_out:
dev_err(led_cdev->dev, "unable to register transient trigger\n");
led_cdev->trigger_data = NULL;
kfree(tdata);
}
static void transient_trig_deactivate(struct led_classdev *led_cdev)
{
struct transient_trig_data *transient_data = led_cdev->trigger_data;
if (led_cdev->activated) {
del_timer_sync(&transient_data->timer);
__led_set_brightness(led_cdev, transient_data->restore_state);
device_remove_file(led_cdev->dev, &dev_attr_activate);
device_remove_file(led_cdev->dev, &dev_attr_duration);
device_remove_file(led_cdev->dev, &dev_attr_state);
led_cdev->trigger_data = NULL;
led_cdev->activated = false;
kfree(transient_data);
}
}
static int __init transient_trig_init(void)
{
return led_trigger_register(&transient_trigger);
}
static void __exit transient_trig_exit(void)
{
led_trigger_unregister(&transient_trigger);
}
