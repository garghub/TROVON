static uint kovaplus_convert_event_cpi(uint value)
{
return (value == 7 ? 4 : (value == 4 ? 3 : value));
}
static void kovaplus_profile_activated(struct kovaplus_device *kovaplus,
uint new_profile_index)
{
kovaplus->actual_profile = new_profile_index;
kovaplus->actual_cpi = kovaplus->profile_settings[new_profile_index].cpi_startup_level;
kovaplus->actual_x_sensitivity = kovaplus->profile_settings[new_profile_index].sensitivity_x;
kovaplus->actual_y_sensitivity = kovaplus->profile_settings[new_profile_index].sensitivity_y;
}
static int kovaplus_send_control(struct usb_device *usb_dev, uint value,
enum kovaplus_control_requests request)
{
int retval;
struct kovaplus_control control;
if ((request == KOVAPLUS_CONTROL_REQUEST_PROFILE_SETTINGS ||
request == KOVAPLUS_CONTROL_REQUEST_PROFILE_BUTTONS) &&
value > 4)
return -EINVAL;
control.command = KOVAPLUS_COMMAND_CONTROL;
control.value = value;
control.request = request;
retval = roccat_common_send(usb_dev, KOVAPLUS_COMMAND_CONTROL,
&control, sizeof(struct kovaplus_control));
return retval;
}
static int kovaplus_receive_control_status(struct usb_device *usb_dev)
{
int retval;
struct kovaplus_control control;
do {
retval = roccat_common_receive(usb_dev, KOVAPLUS_COMMAND_CONTROL,
&control, sizeof(struct kovaplus_control));
if (retval)
return retval;
if (control.value == KOVAPLUS_CONTROL_REQUEST_STATUS_OK)
return 0;
if (control.value == KOVAPLUS_CONTROL_REQUEST_STATUS_WAIT) {
msleep(500);
continue;
}
if (control.value == KOVAPLUS_CONTROL_REQUEST_STATUS_OVERLOAD)
return -EINVAL;
hid_err(usb_dev, "roccat_common_receive_control_status: "
"unknown response value 0x%x\n", control.value);
return -EINVAL;
} while (1);
}
static int kovaplus_send(struct usb_device *usb_dev, uint command,
void const *buf, uint size)
{
int retval;
retval = roccat_common_send(usb_dev, command, buf, size);
if (retval)
return retval;
msleep(100);
return kovaplus_receive_control_status(usb_dev);
}
static int kovaplus_select_profile(struct usb_device *usb_dev, uint number,
enum kovaplus_control_requests request)
{
return kovaplus_send_control(usb_dev, number, request);
}
static int kovaplus_get_info(struct usb_device *usb_dev,
struct kovaplus_info *buf)
{
return roccat_common_receive(usb_dev, KOVAPLUS_COMMAND_INFO,
buf, sizeof(struct kovaplus_info));
}
static int kovaplus_get_profile_settings(struct usb_device *usb_dev,
struct kovaplus_profile_settings *buf, uint number)
{
int retval;
retval = kovaplus_select_profile(usb_dev, number,
KOVAPLUS_CONTROL_REQUEST_PROFILE_SETTINGS);
if (retval)
return retval;
return roccat_common_receive(usb_dev, KOVAPLUS_COMMAND_PROFILE_SETTINGS,
buf, sizeof(struct kovaplus_profile_settings));
}
static int kovaplus_set_profile_settings(struct usb_device *usb_dev,
struct kovaplus_profile_settings const *settings)
{
return kovaplus_send(usb_dev, KOVAPLUS_COMMAND_PROFILE_SETTINGS,
settings, sizeof(struct kovaplus_profile_settings));
}
static int kovaplus_get_profile_buttons(struct usb_device *usb_dev,
struct kovaplus_profile_buttons *buf, int number)
{
int retval;
retval = kovaplus_select_profile(usb_dev, number,
KOVAPLUS_CONTROL_REQUEST_PROFILE_BUTTONS);
if (retval)
return retval;
return roccat_common_receive(usb_dev, KOVAPLUS_COMMAND_PROFILE_BUTTONS,
buf, sizeof(struct kovaplus_profile_buttons));
}
static int kovaplus_set_profile_buttons(struct usb_device *usb_dev,
struct kovaplus_profile_buttons const *buttons)
{
return kovaplus_send(usb_dev, KOVAPLUS_COMMAND_PROFILE_BUTTONS,
buttons, sizeof(struct kovaplus_profile_buttons));
}
static int kovaplus_get_actual_profile(struct usb_device *usb_dev)
{
struct kovaplus_actual_profile buf;
int retval;
retval = roccat_common_receive(usb_dev, KOVAPLUS_COMMAND_ACTUAL_PROFILE,
&buf, sizeof(struct kovaplus_actual_profile));
return retval ? retval : buf.actual_profile;
}
static int kovaplus_set_actual_profile(struct usb_device *usb_dev,
int new_profile)
{
struct kovaplus_actual_profile buf;
buf.command = KOVAPLUS_COMMAND_ACTUAL_PROFILE;
buf.size = sizeof(struct kovaplus_actual_profile);
buf.actual_profile = new_profile;
return kovaplus_send(usb_dev, KOVAPLUS_COMMAND_ACTUAL_PROFILE,
&buf, sizeof(struct kovaplus_actual_profile));
}
static ssize_t kovaplus_sysfs_read_profilex_settings(struct file *fp,
struct kobject *kobj, struct bin_attribute *attr, char *buf,
loff_t off, size_t count)
{
struct device *dev =
container_of(kobj, struct device, kobj)->parent->parent;
struct kovaplus_device *kovaplus = hid_get_drvdata(dev_get_drvdata(dev));
if (off >= sizeof(struct kovaplus_profile_settings))
return 0;
if (off + count > sizeof(struct kovaplus_profile_settings))
count = sizeof(struct kovaplus_profile_settings) - off;
mutex_lock(&kovaplus->kovaplus_lock);
memcpy(buf, ((char const *)&kovaplus->profile_settings[*(uint *)(attr->private)]) + off,
count);
mutex_unlock(&kovaplus->kovaplus_lock);
return count;
}
static ssize_t kovaplus_sysfs_write_profile_settings(struct file *fp,
struct kobject *kobj, struct bin_attribute *attr, char *buf,
loff_t off, size_t count)
{
struct device *dev =
container_of(kobj, struct device, kobj)->parent->parent;
struct kovaplus_device *kovaplus = hid_get_drvdata(dev_get_drvdata(dev));
struct usb_device *usb_dev = interface_to_usbdev(to_usb_interface(dev));
int retval = 0;
int difference;
int profile_index;
struct kovaplus_profile_settings *profile_settings;
if (off != 0 || count != sizeof(struct kovaplus_profile_settings))
return -EINVAL;
profile_index = ((struct kovaplus_profile_settings const *)buf)->profile_index;
profile_settings = &kovaplus->profile_settings[profile_index];
mutex_lock(&kovaplus->kovaplus_lock);
difference = memcmp(buf, profile_settings,
sizeof(struct kovaplus_profile_settings));
if (difference) {
retval = kovaplus_set_profile_settings(usb_dev,
(struct kovaplus_profile_settings const *)buf);
if (!retval)
memcpy(profile_settings, buf,
sizeof(struct kovaplus_profile_settings));
}
mutex_unlock(&kovaplus->kovaplus_lock);
if (retval)
return retval;
return sizeof(struct kovaplus_profile_settings);
}
static ssize_t kovaplus_sysfs_read_profilex_buttons(struct file *fp,
struct kobject *kobj, struct bin_attribute *attr, char *buf,
loff_t off, size_t count)
{
struct device *dev =
container_of(kobj, struct device, kobj)->parent->parent;
struct kovaplus_device *kovaplus = hid_get_drvdata(dev_get_drvdata(dev));
if (off >= sizeof(struct kovaplus_profile_buttons))
return 0;
if (off + count > sizeof(struct kovaplus_profile_buttons))
count = sizeof(struct kovaplus_profile_buttons) - off;
mutex_lock(&kovaplus->kovaplus_lock);
memcpy(buf, ((char const *)&kovaplus->profile_buttons[*(uint *)(attr->private)]) + off,
count);
mutex_unlock(&kovaplus->kovaplus_lock);
return count;
}
static ssize_t kovaplus_sysfs_write_profile_buttons(struct file *fp,
struct kobject *kobj, struct bin_attribute *attr, char *buf,
loff_t off, size_t count)
{
struct device *dev =
container_of(kobj, struct device, kobj)->parent->parent;
struct kovaplus_device *kovaplus = hid_get_drvdata(dev_get_drvdata(dev));
struct usb_device *usb_dev = interface_to_usbdev(to_usb_interface(dev));
int retval = 0;
int difference;
uint profile_index;
struct kovaplus_profile_buttons *profile_buttons;
if (off != 0 || count != sizeof(struct kovaplus_profile_buttons))
return -EINVAL;
profile_index = ((struct kovaplus_profile_buttons const *)buf)->profile_index;
profile_buttons = &kovaplus->profile_buttons[profile_index];
mutex_lock(&kovaplus->kovaplus_lock);
difference = memcmp(buf, profile_buttons,
sizeof(struct kovaplus_profile_buttons));
if (difference) {
retval = kovaplus_set_profile_buttons(usb_dev,
(struct kovaplus_profile_buttons const *)buf);
if (!retval)
memcpy(profile_buttons, buf,
sizeof(struct kovaplus_profile_buttons));
}
mutex_unlock(&kovaplus->kovaplus_lock);
if (retval)
return retval;
return sizeof(struct kovaplus_profile_buttons);
}
static ssize_t kovaplus_sysfs_show_actual_profile(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct kovaplus_device *kovaplus =
hid_get_drvdata(dev_get_drvdata(dev->parent->parent));
return snprintf(buf, PAGE_SIZE, "%d\n", kovaplus->actual_profile);
}
static ssize_t kovaplus_sysfs_set_actual_profile(struct device *dev,
struct device_attribute *attr, char const *buf, size_t size)
{
struct kovaplus_device *kovaplus;
struct usb_device *usb_dev;
unsigned long profile;
int retval;
struct kovaplus_roccat_report roccat_report;
dev = dev->parent->parent;
kovaplus = hid_get_drvdata(dev_get_drvdata(dev));
usb_dev = interface_to_usbdev(to_usb_interface(dev));
retval = strict_strtoul(buf, 10, &profile);
if (retval)
return retval;
if (profile >= 5)
return -EINVAL;
mutex_lock(&kovaplus->kovaplus_lock);
retval = kovaplus_set_actual_profile(usb_dev, profile);
if (retval) {
mutex_unlock(&kovaplus->kovaplus_lock);
return retval;
}
kovaplus_profile_activated(kovaplus, profile);
roccat_report.type = KOVAPLUS_MOUSE_REPORT_BUTTON_TYPE_PROFILE_1;
roccat_report.profile = profile + 1;
roccat_report.button = 0;
roccat_report.data1 = profile + 1;
roccat_report.data2 = 0;
roccat_report_event(kovaplus->chrdev_minor,
(uint8_t const *)&roccat_report);
mutex_unlock(&kovaplus->kovaplus_lock);
return size;
}
static ssize_t kovaplus_sysfs_show_actual_cpi(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct kovaplus_device *kovaplus =
hid_get_drvdata(dev_get_drvdata(dev->parent->parent));
return snprintf(buf, PAGE_SIZE, "%d\n", kovaplus->actual_cpi);
}
static ssize_t kovaplus_sysfs_show_actual_sensitivity_x(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct kovaplus_device *kovaplus =
hid_get_drvdata(dev_get_drvdata(dev->parent->parent));
return snprintf(buf, PAGE_SIZE, "%d\n", kovaplus->actual_x_sensitivity);
}
static ssize_t kovaplus_sysfs_show_actual_sensitivity_y(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct kovaplus_device *kovaplus =
hid_get_drvdata(dev_get_drvdata(dev->parent->parent));
return snprintf(buf, PAGE_SIZE, "%d\n", kovaplus->actual_y_sensitivity);
}
static ssize_t kovaplus_sysfs_show_firmware_version(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct kovaplus_device *kovaplus =
hid_get_drvdata(dev_get_drvdata(dev->parent->parent));
return snprintf(buf, PAGE_SIZE, "%d\n", kovaplus->info.firmware_version);
}
static int kovaplus_init_kovaplus_device_struct(struct usb_device *usb_dev,
struct kovaplus_device *kovaplus)
{
int retval, i;
static uint wait = 70;
mutex_init(&kovaplus->kovaplus_lock);
retval = kovaplus_get_info(usb_dev, &kovaplus->info);
if (retval)
return retval;
for (i = 0; i < 5; ++i) {
msleep(wait);
retval = kovaplus_get_profile_settings(usb_dev,
&kovaplus->profile_settings[i], i);
if (retval)
return retval;
msleep(wait);
retval = kovaplus_get_profile_buttons(usb_dev,
&kovaplus->profile_buttons[i], i);
if (retval)
return retval;
}
msleep(wait);
retval = kovaplus_get_actual_profile(usb_dev);
if (retval < 0)
return retval;
kovaplus_profile_activated(kovaplus, retval);
return 0;
}
static int kovaplus_init_specials(struct hid_device *hdev)
{
struct usb_interface *intf = to_usb_interface(hdev->dev.parent);
struct usb_device *usb_dev = interface_to_usbdev(intf);
struct kovaplus_device *kovaplus;
int retval;
if (intf->cur_altsetting->desc.bInterfaceProtocol
== USB_INTERFACE_PROTOCOL_MOUSE) {
kovaplus = kzalloc(sizeof(*kovaplus), GFP_KERNEL);
if (!kovaplus) {
hid_err(hdev, "can't alloc device descriptor\n");
return -ENOMEM;
}
hid_set_drvdata(hdev, kovaplus);
retval = kovaplus_init_kovaplus_device_struct(usb_dev, kovaplus);
if (retval) {
hid_err(hdev, "couldn't init struct kovaplus_device\n");
goto exit_free;
}
retval = roccat_connect(kovaplus_class, hdev,
sizeof(struct kovaplus_roccat_report));
if (retval < 0) {
hid_err(hdev, "couldn't init char dev\n");
} else {
kovaplus->chrdev_minor = retval;
kovaplus->roccat_claimed = 1;
}
} else {
hid_set_drvdata(hdev, NULL);
}
return 0;
exit_free:
kfree(kovaplus);
return retval;
}
static void kovaplus_remove_specials(struct hid_device *hdev)
{
struct usb_interface *intf = to_usb_interface(hdev->dev.parent);
struct kovaplus_device *kovaplus;
if (intf->cur_altsetting->desc.bInterfaceProtocol
== USB_INTERFACE_PROTOCOL_MOUSE) {
kovaplus = hid_get_drvdata(hdev);
if (kovaplus->roccat_claimed)
roccat_disconnect(kovaplus->chrdev_minor);
kfree(kovaplus);
}
}
static int kovaplus_probe(struct hid_device *hdev,
const struct hid_device_id *id)
{
int retval;
retval = hid_parse(hdev);
if (retval) {
hid_err(hdev, "parse failed\n");
goto exit;
}
retval = hid_hw_start(hdev, HID_CONNECT_DEFAULT);
if (retval) {
hid_err(hdev, "hw start failed\n");
goto exit;
}
retval = kovaplus_init_specials(hdev);
if (retval) {
hid_err(hdev, "couldn't install mouse\n");
goto exit_stop;
}
return 0;
exit_stop:
hid_hw_stop(hdev);
exit:
return retval;
}
static void kovaplus_remove(struct hid_device *hdev)
{
kovaplus_remove_specials(hdev);
hid_hw_stop(hdev);
}
static void kovaplus_keep_values_up_to_date(struct kovaplus_device *kovaplus,
u8 const *data)
{
struct kovaplus_mouse_report_button const *button_report;
if (data[0] != KOVAPLUS_MOUSE_REPORT_NUMBER_BUTTON)
return;
button_report = (struct kovaplus_mouse_report_button const *)data;
switch (button_report->type) {
case KOVAPLUS_MOUSE_REPORT_BUTTON_TYPE_PROFILE_1:
kovaplus_profile_activated(kovaplus, button_report->data1 - 1);
break;
case KOVAPLUS_MOUSE_REPORT_BUTTON_TYPE_CPI:
kovaplus->actual_cpi = kovaplus_convert_event_cpi(button_report->data1);
case KOVAPLUS_MOUSE_REPORT_BUTTON_TYPE_SENSITIVITY:
kovaplus->actual_x_sensitivity = button_report->data1;
kovaplus->actual_y_sensitivity = button_report->data2;
}
}
static void kovaplus_report_to_chrdev(struct kovaplus_device const *kovaplus,
u8 const *data)
{
struct kovaplus_roccat_report roccat_report;
struct kovaplus_mouse_report_button const *button_report;
if (data[0] != KOVAPLUS_MOUSE_REPORT_NUMBER_BUTTON)
return;
button_report = (struct kovaplus_mouse_report_button const *)data;
if (button_report->type == KOVAPLUS_MOUSE_REPORT_BUTTON_TYPE_PROFILE_2)
return;
roccat_report.type = button_report->type;
roccat_report.profile = kovaplus->actual_profile + 1;
if (roccat_report.type == KOVAPLUS_MOUSE_REPORT_BUTTON_TYPE_MACRO ||
roccat_report.type == KOVAPLUS_MOUSE_REPORT_BUTTON_TYPE_SHORTCUT ||
roccat_report.type == KOVAPLUS_MOUSE_REPORT_BUTTON_TYPE_QUICKLAUNCH ||
roccat_report.type == KOVAPLUS_MOUSE_REPORT_BUTTON_TYPE_TIMER)
roccat_report.button = button_report->data1;
else
roccat_report.button = 0;
if (roccat_report.type == KOVAPLUS_MOUSE_REPORT_BUTTON_TYPE_CPI)
roccat_report.data1 = kovaplus_convert_event_cpi(button_report->data1);
else
roccat_report.data1 = button_report->data1;
roccat_report.data2 = button_report->data2;
roccat_report_event(kovaplus->chrdev_minor,
(uint8_t const *)&roccat_report);
}
static int kovaplus_raw_event(struct hid_device *hdev,
struct hid_report *report, u8 *data, int size)
{
struct usb_interface *intf = to_usb_interface(hdev->dev.parent);
struct kovaplus_device *kovaplus = hid_get_drvdata(hdev);
if (intf->cur_altsetting->desc.bInterfaceProtocol
!= USB_INTERFACE_PROTOCOL_MOUSE)
return 0;
if (kovaplus == NULL)
return 0;
kovaplus_keep_values_up_to_date(kovaplus, data);
if (kovaplus->roccat_claimed)
kovaplus_report_to_chrdev(kovaplus, data);
return 0;
}
static int __init kovaplus_init(void)
{
int retval;
kovaplus_class = class_create(THIS_MODULE, "kovaplus");
if (IS_ERR(kovaplus_class))
return PTR_ERR(kovaplus_class);
kovaplus_class->dev_attrs = kovaplus_attributes;
kovaplus_class->dev_bin_attrs = kovaplus_bin_attributes;
retval = hid_register_driver(&kovaplus_driver);
if (retval)
class_destroy(kovaplus_class);
return retval;
}
static void __exit kovaplus_exit(void)
{
hid_unregister_driver(&kovaplus_driver);
class_destroy(kovaplus_class);
}
