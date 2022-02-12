static int tpkbd_input_mapping(struct hid_device *hdev,
struct hid_input *hi, struct hid_field *field,
struct hid_usage *usage, unsigned long **bit, int *max)
{
struct usbhid_device *uhdev;
uhdev = (struct usbhid_device *) hdev->driver_data;
if (uhdev->ifnum == 1 && usage->hid == (HID_UP_BUTTON | 0x0010)) {
map_key_clear(KEY_MICMUTE);
return 1;
}
return 0;
}
static int tpkbd_features_set(struct hid_device *hdev)
{
struct hid_report *report;
struct tpkbd_data_pointer *data_pointer = hid_get_drvdata(hdev);
report = hdev->report_enum[HID_FEATURE_REPORT].report_id_hash[4];
report->field[0]->value[0] = data_pointer->press_to_select ? 0x01 : 0x02;
report->field[0]->value[0] |= data_pointer->dragging ? 0x04 : 0x08;
report->field[0]->value[0] |= data_pointer->release_to_select ? 0x10 : 0x20;
report->field[0]->value[0] |= data_pointer->select_right ? 0x80 : 0x40;
report->field[1]->value[0] = 0x03;
report->field[2]->value[0] = data_pointer->sensitivity;
report->field[3]->value[0] = data_pointer->press_speed;
hid_hw_request(hdev, report, HID_REQ_SET_REPORT);
return 0;
}
static ssize_t pointer_press_to_select_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct hid_device *hdev = container_of(dev, struct hid_device, dev);
struct tpkbd_data_pointer *data_pointer = hid_get_drvdata(hdev);
return snprintf(buf, PAGE_SIZE, "%u\n", data_pointer->press_to_select);
}
static ssize_t pointer_press_to_select_store(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t count)
{
struct hid_device *hdev = container_of(dev, struct hid_device, dev);
struct tpkbd_data_pointer *data_pointer = hid_get_drvdata(hdev);
int value;
if (kstrtoint(buf, 10, &value))
return -EINVAL;
if (value < 0 || value > 1)
return -EINVAL;
data_pointer->press_to_select = value;
tpkbd_features_set(hdev);
return count;
}
static ssize_t pointer_dragging_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct hid_device *hdev = container_of(dev, struct hid_device, dev);
struct tpkbd_data_pointer *data_pointer = hid_get_drvdata(hdev);
return snprintf(buf, PAGE_SIZE, "%u\n", data_pointer->dragging);
}
static ssize_t pointer_dragging_store(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t count)
{
struct hid_device *hdev = container_of(dev, struct hid_device, dev);
struct tpkbd_data_pointer *data_pointer = hid_get_drvdata(hdev);
int value;
if (kstrtoint(buf, 10, &value))
return -EINVAL;
if (value < 0 || value > 1)
return -EINVAL;
data_pointer->dragging = value;
tpkbd_features_set(hdev);
return count;
}
static ssize_t pointer_release_to_select_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct hid_device *hdev = container_of(dev, struct hid_device, dev);
struct tpkbd_data_pointer *data_pointer = hid_get_drvdata(hdev);
return snprintf(buf, PAGE_SIZE, "%u\n", data_pointer->release_to_select);
}
static ssize_t pointer_release_to_select_store(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t count)
{
struct hid_device *hdev = container_of(dev, struct hid_device, dev);
struct tpkbd_data_pointer *data_pointer = hid_get_drvdata(hdev);
int value;
if (kstrtoint(buf, 10, &value))
return -EINVAL;
if (value < 0 || value > 1)
return -EINVAL;
data_pointer->release_to_select = value;
tpkbd_features_set(hdev);
return count;
}
static ssize_t pointer_select_right_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct hid_device *hdev = container_of(dev, struct hid_device, dev);
struct tpkbd_data_pointer *data_pointer = hid_get_drvdata(hdev);
return snprintf(buf, PAGE_SIZE, "%u\n", data_pointer->select_right);
}
static ssize_t pointer_select_right_store(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t count)
{
struct hid_device *hdev = container_of(dev, struct hid_device, dev);
struct tpkbd_data_pointer *data_pointer = hid_get_drvdata(hdev);
int value;
if (kstrtoint(buf, 10, &value))
return -EINVAL;
if (value < 0 || value > 1)
return -EINVAL;
data_pointer->select_right = value;
tpkbd_features_set(hdev);
return count;
}
static ssize_t pointer_sensitivity_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct hid_device *hdev = container_of(dev, struct hid_device, dev);
struct tpkbd_data_pointer *data_pointer = hid_get_drvdata(hdev);
return snprintf(buf, PAGE_SIZE, "%u\n",
data_pointer->sensitivity);
}
static ssize_t pointer_sensitivity_store(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t count)
{
struct hid_device *hdev = container_of(dev, struct hid_device, dev);
struct tpkbd_data_pointer *data_pointer = hid_get_drvdata(hdev);
int value;
if (kstrtoint(buf, 10, &value) || value < 1 || value > 255)
return -EINVAL;
data_pointer->sensitivity = value;
tpkbd_features_set(hdev);
return count;
}
static ssize_t pointer_press_speed_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct hid_device *hdev = container_of(dev, struct hid_device, dev);
struct tpkbd_data_pointer *data_pointer = hid_get_drvdata(hdev);
return snprintf(buf, PAGE_SIZE, "%u\n",
data_pointer->press_speed);
}
static ssize_t pointer_press_speed_store(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t count)
{
struct hid_device *hdev = container_of(dev, struct hid_device, dev);
struct tpkbd_data_pointer *data_pointer = hid_get_drvdata(hdev);
int value;
if (kstrtoint(buf, 10, &value) || value < 1 || value > 255)
return -EINVAL;
data_pointer->press_speed = value;
tpkbd_features_set(hdev);
return count;
}
static enum led_brightness tpkbd_led_brightness_get(
struct led_classdev *led_cdev)
{
struct device *dev = led_cdev->dev->parent;
struct hid_device *hdev = container_of(dev, struct hid_device, dev);
struct tpkbd_data_pointer *data_pointer = hid_get_drvdata(hdev);
int led_nr = 0;
if (led_cdev == &data_pointer->led_micmute)
led_nr = 1;
return data_pointer->led_state & (1 << led_nr)
? LED_FULL
: LED_OFF;
}
static void tpkbd_led_brightness_set(struct led_classdev *led_cdev,
enum led_brightness value)
{
struct device *dev = led_cdev->dev->parent;
struct hid_device *hdev = container_of(dev, struct hid_device, dev);
struct tpkbd_data_pointer *data_pointer = hid_get_drvdata(hdev);
struct hid_report *report;
int led_nr = 0;
if (led_cdev == &data_pointer->led_micmute)
led_nr = 1;
if (value == LED_OFF)
data_pointer->led_state &= ~(1 << led_nr);
else
data_pointer->led_state |= 1 << led_nr;
report = hdev->report_enum[HID_OUTPUT_REPORT].report_id_hash[3];
report->field[0]->value[0] = (data_pointer->led_state >> 0) & 1;
report->field[0]->value[1] = (data_pointer->led_state >> 1) & 1;
hid_hw_request(hdev, report, HID_REQ_SET_REPORT);
}
static int tpkbd_probe_tp(struct hid_device *hdev)
{
struct device *dev = &hdev->dev;
struct tpkbd_data_pointer *data_pointer;
size_t name_sz = strlen(dev_name(dev)) + 16;
char *name_mute, *name_micmute;
int i, ret;
for (i = 0; i < 4; i++) {
if (!hid_validate_values(hdev, HID_FEATURE_REPORT, 4, i, 1))
return -ENODEV;
}
if (!hid_validate_values(hdev, HID_OUTPUT_REPORT, 3, 0, 2))
return -ENODEV;
if (sysfs_create_group(&hdev->dev.kobj,
&tpkbd_attr_group_pointer)) {
hid_warn(hdev, "Could not create sysfs group\n");
}
data_pointer = kzalloc(sizeof(struct tpkbd_data_pointer), GFP_KERNEL);
if (data_pointer == NULL) {
hid_err(hdev, "Could not allocate memory for driver data\n");
return -ENOMEM;
}
data_pointer->sensitivity = 0xa0;
data_pointer->press_speed = 0x38;
name_mute = kzalloc(name_sz, GFP_KERNEL);
if (name_mute == NULL) {
hid_err(hdev, "Could not allocate memory for led data\n");
ret = -ENOMEM;
goto err;
}
snprintf(name_mute, name_sz, "%s:amber:mute", dev_name(dev));
name_micmute = kzalloc(name_sz, GFP_KERNEL);
if (name_micmute == NULL) {
hid_err(hdev, "Could not allocate memory for led data\n");
ret = -ENOMEM;
goto err2;
}
snprintf(name_micmute, name_sz, "%s:amber:micmute", dev_name(dev));
hid_set_drvdata(hdev, data_pointer);
data_pointer->led_mute.name = name_mute;
data_pointer->led_mute.brightness_get = tpkbd_led_brightness_get;
data_pointer->led_mute.brightness_set = tpkbd_led_brightness_set;
data_pointer->led_mute.dev = dev;
led_classdev_register(dev, &data_pointer->led_mute);
data_pointer->led_micmute.name = name_micmute;
data_pointer->led_micmute.brightness_get = tpkbd_led_brightness_get;
data_pointer->led_micmute.brightness_set = tpkbd_led_brightness_set;
data_pointer->led_micmute.dev = dev;
led_classdev_register(dev, &data_pointer->led_micmute);
tpkbd_features_set(hdev);
return 0;
err2:
kfree(name_mute);
err:
kfree(data_pointer);
return ret;
}
static int tpkbd_probe(struct hid_device *hdev,
const struct hid_device_id *id)
{
int ret;
struct usbhid_device *uhdev;
ret = hid_parse(hdev);
if (ret) {
hid_err(hdev, "hid_parse failed\n");
goto err;
}
ret = hid_hw_start(hdev, HID_CONNECT_DEFAULT);
if (ret) {
hid_err(hdev, "hid_hw_start failed\n");
goto err;
}
uhdev = (struct usbhid_device *) hdev->driver_data;
if (uhdev->ifnum == 1) {
ret = tpkbd_probe_tp(hdev);
if (ret)
goto err_hid;
}
return 0;
err_hid:
hid_hw_stop(hdev);
err:
return ret;
}
static void tpkbd_remove_tp(struct hid_device *hdev)
{
struct tpkbd_data_pointer *data_pointer = hid_get_drvdata(hdev);
sysfs_remove_group(&hdev->dev.kobj,
&tpkbd_attr_group_pointer);
led_classdev_unregister(&data_pointer->led_micmute);
led_classdev_unregister(&data_pointer->led_mute);
hid_set_drvdata(hdev, NULL);
kfree(data_pointer->led_micmute.name);
kfree(data_pointer->led_mute.name);
kfree(data_pointer);
}
static void tpkbd_remove(struct hid_device *hdev)
{
struct usbhid_device *uhdev;
uhdev = (struct usbhid_device *) hdev->driver_data;
if (uhdev->ifnum == 1)
tpkbd_remove_tp(hdev);
hid_hw_stop(hdev);
}
