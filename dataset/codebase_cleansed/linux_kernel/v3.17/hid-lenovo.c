static int lenovo_input_mapping_tpkbd(struct hid_device *hdev,
struct hid_input *hi, struct hid_field *field,
struct hid_usage *usage, unsigned long **bit, int *max)
{
if (usage->hid == (HID_UP_BUTTON | 0x0010)) {
hid_set_drvdata(hdev, (void *)1);
map_key_clear(KEY_MICMUTE);
return 1;
}
return 0;
}
static int lenovo_input_mapping_cptkbd(struct hid_device *hdev,
struct hid_input *hi, struct hid_field *field,
struct hid_usage *usage, unsigned long **bit, int *max)
{
if ((usage->hid & HID_USAGE_PAGE) == HID_UP_MSVENDOR ||
(usage->hid & HID_USAGE_PAGE) == HID_UP_LNVENDOR) {
set_bit(EV_REP, hi->input->evbit);
switch (usage->hid & HID_USAGE) {
case 0x00f1:
map_key_clear(KEY_MICMUTE);
return 1;
case 0x00f2:
map_key_clear(KEY_BRIGHTNESSDOWN);
return 1;
case 0x00f3:
map_key_clear(KEY_BRIGHTNESSUP);
return 1;
case 0x00f4:
map_key_clear(KEY_SWITCHVIDEOMODE);
return 1;
case 0x00f5:
map_key_clear(KEY_WLAN);
return 1;
case 0x00f6:
map_key_clear(KEY_CONFIG);
return 1;
case 0x00f8:
map_key_clear(KEY_SCALE);
return 1;
case 0x00fa:
map_key_clear(KEY_FN_ESC);
return 1;
case 0x00fb:
map_key_clear(KEY_FILE);
return 1;
}
}
return 0;
}
static int lenovo_input_mapping(struct hid_device *hdev,
struct hid_input *hi, struct hid_field *field,
struct hid_usage *usage, unsigned long **bit, int *max)
{
switch (hdev->product) {
case USB_DEVICE_ID_LENOVO_TPKBD:
return lenovo_input_mapping_tpkbd(hdev, hi, field,
usage, bit, max);
case USB_DEVICE_ID_LENOVO_CUSBKBD:
case USB_DEVICE_ID_LENOVO_CBTKBD:
return lenovo_input_mapping_cptkbd(hdev, hi, field,
usage, bit, max);
default:
return 0;
}
}
static int lenovo_send_cmd_cptkbd(struct hid_device *hdev,
unsigned char byte2, unsigned char byte3)
{
int ret;
unsigned char buf[] = {0x18, byte2, byte3};
switch (hdev->product) {
case USB_DEVICE_ID_LENOVO_CUSBKBD:
ret = hid_hw_raw_request(hdev, 0x13, buf, sizeof(buf),
HID_FEATURE_REPORT, HID_REQ_SET_REPORT);
break;
case USB_DEVICE_ID_LENOVO_CBTKBD:
ret = hid_hw_output_report(hdev, buf, sizeof(buf));
break;
default:
ret = -EINVAL;
break;
}
return ret < 0 ? ret : 0;
}
static void lenovo_features_set_cptkbd(struct hid_device *hdev)
{
int ret;
struct lenovo_drvdata_cptkbd *cptkbd_data = hid_get_drvdata(hdev);
ret = lenovo_send_cmd_cptkbd(hdev, 0x05, cptkbd_data->fn_lock);
if (ret)
hid_err(hdev, "Fn-lock setting failed: %d\n", ret);
}
static ssize_t attr_fn_lock_show_cptkbd(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct hid_device *hdev = container_of(dev, struct hid_device, dev);
struct lenovo_drvdata_cptkbd *cptkbd_data = hid_get_drvdata(hdev);
return snprintf(buf, PAGE_SIZE, "%u\n", cptkbd_data->fn_lock);
}
static ssize_t attr_fn_lock_store_cptkbd(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t count)
{
struct hid_device *hdev = container_of(dev, struct hid_device, dev);
struct lenovo_drvdata_cptkbd *cptkbd_data = hid_get_drvdata(hdev);
int value;
if (kstrtoint(buf, 10, &value))
return -EINVAL;
if (value < 0 || value > 1)
return -EINVAL;
cptkbd_data->fn_lock = !!value;
lenovo_features_set_cptkbd(hdev);
return count;
}
static int lenovo_raw_event(struct hid_device *hdev,
struct hid_report *report, u8 *data, int size)
{
if (unlikely(hdev->product == USB_DEVICE_ID_LENOVO_CUSBKBD
&& size == 3
&& data[0] == 0x15
&& data[1] == 0x94
&& data[2] == 0x01)) {
data[1] = 0x0;
data[2] = 0x4;
}
return 0;
}
static int lenovo_features_set_tpkbd(struct hid_device *hdev)
{
struct hid_report *report;
struct lenovo_drvdata_tpkbd *data_pointer = hid_get_drvdata(hdev);
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
static ssize_t attr_press_to_select_show_tpkbd(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct hid_device *hdev = container_of(dev, struct hid_device, dev);
struct lenovo_drvdata_tpkbd *data_pointer = hid_get_drvdata(hdev);
return snprintf(buf, PAGE_SIZE, "%u\n", data_pointer->press_to_select);
}
static ssize_t attr_press_to_select_store_tpkbd(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t count)
{
struct hid_device *hdev = container_of(dev, struct hid_device, dev);
struct lenovo_drvdata_tpkbd *data_pointer = hid_get_drvdata(hdev);
int value;
if (kstrtoint(buf, 10, &value))
return -EINVAL;
if (value < 0 || value > 1)
return -EINVAL;
data_pointer->press_to_select = value;
lenovo_features_set_tpkbd(hdev);
return count;
}
static ssize_t attr_dragging_show_tpkbd(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct hid_device *hdev = container_of(dev, struct hid_device, dev);
struct lenovo_drvdata_tpkbd *data_pointer = hid_get_drvdata(hdev);
return snprintf(buf, PAGE_SIZE, "%u\n", data_pointer->dragging);
}
static ssize_t attr_dragging_store_tpkbd(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t count)
{
struct hid_device *hdev = container_of(dev, struct hid_device, dev);
struct lenovo_drvdata_tpkbd *data_pointer = hid_get_drvdata(hdev);
int value;
if (kstrtoint(buf, 10, &value))
return -EINVAL;
if (value < 0 || value > 1)
return -EINVAL;
data_pointer->dragging = value;
lenovo_features_set_tpkbd(hdev);
return count;
}
static ssize_t attr_release_to_select_show_tpkbd(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct hid_device *hdev = container_of(dev, struct hid_device, dev);
struct lenovo_drvdata_tpkbd *data_pointer = hid_get_drvdata(hdev);
return snprintf(buf, PAGE_SIZE, "%u\n", data_pointer->release_to_select);
}
static ssize_t attr_release_to_select_store_tpkbd(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t count)
{
struct hid_device *hdev = container_of(dev, struct hid_device, dev);
struct lenovo_drvdata_tpkbd *data_pointer = hid_get_drvdata(hdev);
int value;
if (kstrtoint(buf, 10, &value))
return -EINVAL;
if (value < 0 || value > 1)
return -EINVAL;
data_pointer->release_to_select = value;
lenovo_features_set_tpkbd(hdev);
return count;
}
static ssize_t attr_select_right_show_tpkbd(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct hid_device *hdev = container_of(dev, struct hid_device, dev);
struct lenovo_drvdata_tpkbd *data_pointer = hid_get_drvdata(hdev);
return snprintf(buf, PAGE_SIZE, "%u\n", data_pointer->select_right);
}
static ssize_t attr_select_right_store_tpkbd(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t count)
{
struct hid_device *hdev = container_of(dev, struct hid_device, dev);
struct lenovo_drvdata_tpkbd *data_pointer = hid_get_drvdata(hdev);
int value;
if (kstrtoint(buf, 10, &value))
return -EINVAL;
if (value < 0 || value > 1)
return -EINVAL;
data_pointer->select_right = value;
lenovo_features_set_tpkbd(hdev);
return count;
}
static ssize_t attr_sensitivity_show_tpkbd(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct hid_device *hdev = container_of(dev, struct hid_device, dev);
struct lenovo_drvdata_tpkbd *data_pointer = hid_get_drvdata(hdev);
return snprintf(buf, PAGE_SIZE, "%u\n",
data_pointer->sensitivity);
}
static ssize_t attr_sensitivity_store_tpkbd(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t count)
{
struct hid_device *hdev = container_of(dev, struct hid_device, dev);
struct lenovo_drvdata_tpkbd *data_pointer = hid_get_drvdata(hdev);
int value;
if (kstrtoint(buf, 10, &value) || value < 1 || value > 255)
return -EINVAL;
data_pointer->sensitivity = value;
lenovo_features_set_tpkbd(hdev);
return count;
}
static ssize_t attr_press_speed_show_tpkbd(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct hid_device *hdev = container_of(dev, struct hid_device, dev);
struct lenovo_drvdata_tpkbd *data_pointer = hid_get_drvdata(hdev);
return snprintf(buf, PAGE_SIZE, "%u\n",
data_pointer->press_speed);
}
static ssize_t attr_press_speed_store_tpkbd(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t count)
{
struct hid_device *hdev = container_of(dev, struct hid_device, dev);
struct lenovo_drvdata_tpkbd *data_pointer = hid_get_drvdata(hdev);
int value;
if (kstrtoint(buf, 10, &value) || value < 1 || value > 255)
return -EINVAL;
data_pointer->press_speed = value;
lenovo_features_set_tpkbd(hdev);
return count;
}
static enum led_brightness lenovo_led_brightness_get_tpkbd(
struct led_classdev *led_cdev)
{
struct device *dev = led_cdev->dev->parent;
struct hid_device *hdev = container_of(dev, struct hid_device, dev);
struct lenovo_drvdata_tpkbd *data_pointer = hid_get_drvdata(hdev);
int led_nr = 0;
if (led_cdev == &data_pointer->led_micmute)
led_nr = 1;
return data_pointer->led_state & (1 << led_nr)
? LED_FULL
: LED_OFF;
}
static void lenovo_led_brightness_set_tpkbd(struct led_classdev *led_cdev,
enum led_brightness value)
{
struct device *dev = led_cdev->dev->parent;
struct hid_device *hdev = container_of(dev, struct hid_device, dev);
struct lenovo_drvdata_tpkbd *data_pointer = hid_get_drvdata(hdev);
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
static int lenovo_probe_tpkbd(struct hid_device *hdev)
{
struct device *dev = &hdev->dev;
struct lenovo_drvdata_tpkbd *data_pointer;
size_t name_sz = strlen(dev_name(dev)) + 16;
char *name_mute, *name_micmute;
int i;
int ret;
if (!hid_get_drvdata(hdev))
return 0;
hid_set_drvdata(hdev, NULL);
for (i = 0; i < 4; i++) {
if (!hid_validate_values(hdev, HID_FEATURE_REPORT, 4, i, 1))
return -ENODEV;
}
if (!hid_validate_values(hdev, HID_OUTPUT_REPORT, 3, 0, 2))
return -ENODEV;
ret = sysfs_create_group(&hdev->dev.kobj, &lenovo_attr_group_tpkbd);
if (ret)
hid_warn(hdev, "Could not create sysfs group: %d\n", ret);
data_pointer = devm_kzalloc(&hdev->dev,
sizeof(struct lenovo_drvdata_tpkbd),
GFP_KERNEL);
if (data_pointer == NULL) {
hid_err(hdev, "Could not allocate memory for driver data\n");
return -ENOMEM;
}
data_pointer->sensitivity = 0xa0;
data_pointer->press_speed = 0x38;
name_mute = devm_kzalloc(&hdev->dev, name_sz, GFP_KERNEL);
name_micmute = devm_kzalloc(&hdev->dev, name_sz, GFP_KERNEL);
if (name_mute == NULL || name_micmute == NULL) {
hid_err(hdev, "Could not allocate memory for led data\n");
return -ENOMEM;
}
snprintf(name_mute, name_sz, "%s:amber:mute", dev_name(dev));
snprintf(name_micmute, name_sz, "%s:amber:micmute", dev_name(dev));
hid_set_drvdata(hdev, data_pointer);
data_pointer->led_mute.name = name_mute;
data_pointer->led_mute.brightness_get = lenovo_led_brightness_get_tpkbd;
data_pointer->led_mute.brightness_set = lenovo_led_brightness_set_tpkbd;
data_pointer->led_mute.dev = dev;
led_classdev_register(dev, &data_pointer->led_mute);
data_pointer->led_micmute.name = name_micmute;
data_pointer->led_micmute.brightness_get =
lenovo_led_brightness_get_tpkbd;
data_pointer->led_micmute.brightness_set =
lenovo_led_brightness_set_tpkbd;
data_pointer->led_micmute.dev = dev;
led_classdev_register(dev, &data_pointer->led_micmute);
lenovo_features_set_tpkbd(hdev);
return 0;
}
static int lenovo_probe_cptkbd(struct hid_device *hdev)
{
int ret;
struct lenovo_drvdata_cptkbd *cptkbd_data;
if (hdev->product == USB_DEVICE_ID_LENOVO_CUSBKBD
&& hdev->type != HID_TYPE_USBMOUSE) {
hid_dbg(hdev, "Ignoring keyboard half of device\n");
return 0;
}
cptkbd_data = devm_kzalloc(&hdev->dev,
sizeof(*cptkbd_data),
GFP_KERNEL);
if (cptkbd_data == NULL) {
hid_err(hdev, "can't alloc keyboard descriptor\n");
return -ENOMEM;
}
hid_set_drvdata(hdev, cptkbd_data);
ret = lenovo_send_cmd_cptkbd(hdev, 0x01, 0x03);
if (ret)
hid_warn(hdev, "Failed to switch F7/9/11 mode: %d\n", ret);
cptkbd_data->fn_lock = true;
lenovo_features_set_cptkbd(hdev);
ret = sysfs_create_group(&hdev->dev.kobj, &lenovo_attr_group_cptkbd);
if (ret)
hid_warn(hdev, "Could not create sysfs group: %d\n", ret);
return 0;
}
static int lenovo_probe(struct hid_device *hdev,
const struct hid_device_id *id)
{
int ret;
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
switch (hdev->product) {
case USB_DEVICE_ID_LENOVO_TPKBD:
ret = lenovo_probe_tpkbd(hdev);
break;
case USB_DEVICE_ID_LENOVO_CUSBKBD:
case USB_DEVICE_ID_LENOVO_CBTKBD:
ret = lenovo_probe_cptkbd(hdev);
break;
default:
ret = 0;
break;
}
if (ret)
goto err_hid;
return 0;
err_hid:
hid_hw_stop(hdev);
err:
return ret;
}
static void lenovo_remove_tpkbd(struct hid_device *hdev)
{
struct lenovo_drvdata_tpkbd *data_pointer = hid_get_drvdata(hdev);
if (data_pointer == NULL)
return;
sysfs_remove_group(&hdev->dev.kobj,
&lenovo_attr_group_tpkbd);
led_classdev_unregister(&data_pointer->led_micmute);
led_classdev_unregister(&data_pointer->led_mute);
hid_set_drvdata(hdev, NULL);
}
static void lenovo_remove_cptkbd(struct hid_device *hdev)
{
sysfs_remove_group(&hdev->dev.kobj,
&lenovo_attr_group_cptkbd);
}
static void lenovo_remove(struct hid_device *hdev)
{
switch (hdev->product) {
case USB_DEVICE_ID_LENOVO_TPKBD:
lenovo_remove_tpkbd(hdev);
break;
case USB_DEVICE_ID_LENOVO_CUSBKBD:
case USB_DEVICE_ID_LENOVO_CBTKBD:
lenovo_remove_cptkbd(hdev);
break;
}
hid_hw_stop(hdev);
}
