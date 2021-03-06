static void ams_idev_poll(struct input_polled_dev *dev)
{
struct input_dev *idev = dev->input;
s8 x, y, z;
mutex_lock(&ams_info.lock);
ams_sensors(&x, &y, &z);
x -= ams_info.xcalib;
y -= ams_info.ycalib;
z -= ams_info.zcalib;
input_report_abs(idev, ABS_X, invert ? -x : x);
input_report_abs(idev, ABS_Y, invert ? -y : y);
input_report_abs(idev, ABS_Z, z);
input_sync(idev);
mutex_unlock(&ams_info.lock);
}
static int ams_input_enable(void)
{
struct input_dev *input;
s8 x, y, z;
int error;
ams_sensors(&x, &y, &z);
ams_info.xcalib = x;
ams_info.ycalib = y;
ams_info.zcalib = z;
ams_info.idev = input_allocate_polled_device();
if (!ams_info.idev)
return -ENOMEM;
ams_info.idev->poll = ams_idev_poll;
ams_info.idev->poll_interval = 25;
input = ams_info.idev->input;
input->name = "Apple Motion Sensor";
input->id.bustype = ams_info.bustype;
input->id.vendor = 0;
input->dev.parent = &ams_info.of_dev->dev;
input_set_abs_params(input, ABS_X, -50, 50, 3, 0);
input_set_abs_params(input, ABS_Y, -50, 50, 3, 0);
input_set_abs_params(input, ABS_Z, -50, 50, 3, 0);
set_bit(EV_ABS, input->evbit);
set_bit(EV_KEY, input->evbit);
set_bit(BTN_TOUCH, input->keybit);
error = input_register_polled_device(ams_info.idev);
if (error) {
input_free_polled_device(ams_info.idev);
ams_info.idev = NULL;
return error;
}
joystick = 1;
return 0;
}
static void ams_input_disable(void)
{
if (ams_info.idev) {
input_unregister_polled_device(ams_info.idev);
input_free_polled_device(ams_info.idev);
ams_info.idev = NULL;
}
joystick = 0;
}
static ssize_t ams_input_show_joystick(struct device *dev,
struct device_attribute *attr, char *buf)
{
return sprintf(buf, "%d\n", joystick);
}
static ssize_t ams_input_store_joystick(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
unsigned long enable;
int error = 0;
int ret;
ret = kstrtoul(buf, 0, &enable);
if (ret)
return ret;
if (enable > 1)
return -EINVAL;
mutex_lock(&ams_input_mutex);
if (enable != joystick) {
if (enable)
error = ams_input_enable();
else
ams_input_disable();
}
mutex_unlock(&ams_input_mutex);
return error ? error : count;
}
int ams_input_init(void)
{
if (joystick)
ams_input_enable();
return device_create_file(&ams_info.of_dev->dev, &dev_attr_joystick);
}
void ams_input_exit(void)
{
device_remove_file(&ams_info.of_dev->dev, &dev_attr_joystick);
mutex_lock(&ams_input_mutex);
ams_input_disable();
mutex_unlock(&ams_input_mutex);
}
