static ssize_t show_configuration_string(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct usb_device *udev;
struct usb_host_config *actconfig;
udev = to_usb_device(dev);
actconfig = udev->actconfig;
if ((!actconfig) || (!actconfig->string))
return 0;
return sprintf(buf, "%s\n", actconfig->string);
}
static ssize_t
set_bConfigurationValue(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct usb_device *udev = to_usb_device(dev);
int config, value;
if (sscanf(buf, "%d", &config) != 1 || config < -1 || config > 255)
return -EINVAL;
usb_lock_device(udev);
value = usb_set_configuration(udev, config);
usb_unlock_device(udev);
return (value < 0) ? value : count;
}
static ssize_t
show_speed(struct device *dev, struct device_attribute *attr, char *buf)
{
struct usb_device *udev;
char *speed;
udev = to_usb_device(dev);
switch (udev->speed) {
case USB_SPEED_LOW:
speed = "1.5";
break;
case USB_SPEED_UNKNOWN:
case USB_SPEED_FULL:
speed = "12";
break;
case USB_SPEED_HIGH:
speed = "480";
break;
case USB_SPEED_WIRELESS:
speed = "480";
break;
case USB_SPEED_SUPER:
speed = "5000";
break;
default:
speed = "unknown";
}
return sprintf(buf, "%s\n", speed);
}
static ssize_t
show_busnum(struct device *dev, struct device_attribute *attr, char *buf)
{
struct usb_device *udev;
udev = to_usb_device(dev);
return sprintf(buf, "%d\n", udev->bus->busnum);
}
static ssize_t
show_devnum(struct device *dev, struct device_attribute *attr, char *buf)
{
struct usb_device *udev;
udev = to_usb_device(dev);
return sprintf(buf, "%d\n", udev->devnum);
}
static ssize_t
show_devpath(struct device *dev, struct device_attribute *attr, char *buf)
{
struct usb_device *udev;
udev = to_usb_device(dev);
return sprintf(buf, "%s\n", udev->devpath);
}
static ssize_t
show_version(struct device *dev, struct device_attribute *attr, char *buf)
{
struct usb_device *udev;
u16 bcdUSB;
udev = to_usb_device(dev);
bcdUSB = le16_to_cpu(udev->descriptor.bcdUSB);
return sprintf(buf, "%2x.%02x\n", bcdUSB >> 8, bcdUSB & 0xff);
}
static ssize_t
show_maxchild(struct device *dev, struct device_attribute *attr, char *buf)
{
struct usb_device *udev;
udev = to_usb_device(dev);
return sprintf(buf, "%d\n", udev->maxchild);
}
static ssize_t
show_quirks(struct device *dev, struct device_attribute *attr, char *buf)
{
struct usb_device *udev;
udev = to_usb_device(dev);
return sprintf(buf, "0x%x\n", udev->quirks);
}
static ssize_t
show_avoid_reset_quirk(struct device *dev, struct device_attribute *attr, char *buf)
{
struct usb_device *udev;
udev = to_usb_device(dev);
return sprintf(buf, "%d\n", !!(udev->quirks & USB_QUIRK_RESET_MORPHS));
}
static ssize_t
set_avoid_reset_quirk(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct usb_device *udev = to_usb_device(dev);
int config;
if (sscanf(buf, "%d", &config) != 1 || config < 0 || config > 1)
return -EINVAL;
usb_lock_device(udev);
if (config)
udev->quirks |= USB_QUIRK_RESET_MORPHS;
else
udev->quirks &= ~USB_QUIRK_RESET_MORPHS;
usb_unlock_device(udev);
return count;
}
static ssize_t
show_urbnum(struct device *dev, struct device_attribute *attr, char *buf)
{
struct usb_device *udev;
udev = to_usb_device(dev);
return sprintf(buf, "%d\n", atomic_read(&udev->urbnum));
}
static ssize_t
show_persist(struct device *dev, struct device_attribute *attr, char *buf)
{
struct usb_device *udev = to_usb_device(dev);
return sprintf(buf, "%d\n", udev->persist_enabled);
}
static ssize_t
set_persist(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct usb_device *udev = to_usb_device(dev);
int value;
if (udev->descriptor.bDeviceClass == USB_CLASS_HUB)
return -EPERM;
if (sscanf(buf, "%d", &value) != 1)
return -EINVAL;
usb_lock_device(udev);
udev->persist_enabled = !!value;
usb_unlock_device(udev);
return count;
}
static int add_persist_attributes(struct device *dev)
{
int rc = 0;
if (is_usb_device(dev)) {
struct usb_device *udev = to_usb_device(dev);
if (udev->descriptor.bDeviceClass != USB_CLASS_HUB)
rc = sysfs_add_file_to_group(&dev->kobj,
&dev_attr_persist.attr,
power_group_name);
}
return rc;
}
static void remove_persist_attributes(struct device *dev)
{
sysfs_remove_file_from_group(&dev->kobj,
&dev_attr_persist.attr,
power_group_name);
}
static ssize_t
show_connected_duration(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct usb_device *udev = to_usb_device(dev);
return sprintf(buf, "%u\n",
jiffies_to_msecs(jiffies - udev->connect_time));
}
static ssize_t
show_active_duration(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct usb_device *udev = to_usb_device(dev);
int duration;
if (udev->state != USB_STATE_SUSPENDED)
duration = jiffies_to_msecs(jiffies + udev->active_duration);
else
duration = jiffies_to_msecs(udev->active_duration);
return sprintf(buf, "%u\n", duration);
}
static ssize_t
show_autosuspend(struct device *dev, struct device_attribute *attr, char *buf)
{
return sprintf(buf, "%d\n", dev->power.autosuspend_delay / 1000);
}
static ssize_t
set_autosuspend(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
int value;
if (sscanf(buf, "%d", &value) != 1 || value >= INT_MAX/1000 ||
value <= -INT_MAX/1000)
return -EINVAL;
pm_runtime_set_autosuspend_delay(dev, value * 1000);
return count;
}
static void warn_level(void) {
static int level_warned;
if (!level_warned) {
level_warned = 1;
printk(KERN_WARNING "WARNING! power/level is deprecated; "
"use power/control instead\n");
}
}
static ssize_t
show_level(struct device *dev, struct device_attribute *attr, char *buf)
{
struct usb_device *udev = to_usb_device(dev);
const char *p = auto_string;
warn_level();
if (udev->state != USB_STATE_SUSPENDED && !udev->dev.power.runtime_auto)
p = on_string;
return sprintf(buf, "%s\n", p);
}
static ssize_t
set_level(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct usb_device *udev = to_usb_device(dev);
int len = count;
char *cp;
int rc = count;
warn_level();
cp = memchr(buf, '\n', count);
if (cp)
len = cp - buf;
usb_lock_device(udev);
if (len == sizeof on_string - 1 &&
strncmp(buf, on_string, len) == 0)
usb_disable_autosuspend(udev);
else if (len == sizeof auto_string - 1 &&
strncmp(buf, auto_string, len) == 0)
usb_enable_autosuspend(udev);
else
rc = -EINVAL;
usb_unlock_device(udev);
return rc;
}
static int add_power_attributes(struct device *dev)
{
int rc = 0;
if (is_usb_device(dev))
rc = sysfs_merge_group(&dev->kobj, &power_attr_group);
return rc;
}
static void remove_power_attributes(struct device *dev)
{
sysfs_unmerge_group(&dev->kobj, &power_attr_group);
}
static ssize_t usb_dev_authorized_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct usb_device *usb_dev = to_usb_device(dev);
return snprintf(buf, PAGE_SIZE, "%u\n", usb_dev->authorized);
}
static ssize_t usb_dev_authorized_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
ssize_t result;
struct usb_device *usb_dev = to_usb_device(dev);
unsigned val;
result = sscanf(buf, "%u\n", &val);
if (result != 1)
result = -EINVAL;
else if (val == 0)
result = usb_deauthorize_device(usb_dev);
else
result = usb_authorize_device(usb_dev);
return result < 0? result : size;
}
static ssize_t usb_remove_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct usb_device *udev = to_usb_device(dev);
int rc = 0;
usb_lock_device(udev);
if (udev->state != USB_STATE_NOTATTACHED) {
usb_set_configuration(udev, -1);
rc = usb_remove_device(udev);
}
if (rc == 0)
rc = count;
usb_unlock_device(udev);
return rc;
}
static mode_t dev_string_attrs_are_visible(struct kobject *kobj,
struct attribute *a, int n)
{
struct device *dev = container_of(kobj, struct device, kobj);
struct usb_device *udev = to_usb_device(dev);
if (a == &dev_attr_manufacturer.attr) {
if (udev->manufacturer == NULL)
return 0;
} else if (a == &dev_attr_product.attr) {
if (udev->product == NULL)
return 0;
} else if (a == &dev_attr_serial.attr) {
if (udev->serial == NULL)
return 0;
}
return a->mode;
}
static ssize_t
read_descriptors(struct file *filp, struct kobject *kobj,
struct bin_attribute *attr,
char *buf, loff_t off, size_t count)
{
struct device *dev = container_of(kobj, struct device, kobj);
struct usb_device *udev = to_usb_device(dev);
size_t nleft = count;
size_t srclen, n;
int cfgno;
void *src;
for (cfgno = -1; cfgno < udev->descriptor.bNumConfigurations &&
nleft > 0; ++cfgno) {
if (cfgno < 0) {
src = &udev->descriptor;
srclen = sizeof(struct usb_device_descriptor);
} else {
src = udev->rawdescriptors[cfgno];
srclen = __le16_to_cpu(udev->config[cfgno].desc.
wTotalLength);
}
if (off < srclen) {
n = min(nleft, srclen - (size_t) off);
memcpy(buf, src + off, n);
nleft -= n;
buf += n;
off = 0;
} else {
off -= srclen;
}
}
return count - nleft;
}
int usb_create_sysfs_dev_files(struct usb_device *udev)
{
struct device *dev = &udev->dev;
int retval;
retval = device_create_bin_file(dev, &dev_bin_attr_descriptors);
if (retval)
goto error;
retval = add_persist_attributes(dev);
if (retval)
goto error;
retval = add_power_attributes(dev);
if (retval)
goto error;
return retval;
error:
usb_remove_sysfs_dev_files(udev);
return retval;
}
void usb_remove_sysfs_dev_files(struct usb_device *udev)
{
struct device *dev = &udev->dev;
remove_power_attributes(dev);
remove_persist_attributes(dev);
device_remove_bin_file(dev, &dev_bin_attr_descriptors);
}
static ssize_t show_interface_string(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct usb_interface *intf;
char *string;
intf = to_usb_interface(dev);
string = intf->cur_altsetting->string;
barrier();
if (!string)
return 0;
return sprintf(buf, "%s\n", string);
}
static ssize_t show_modalias(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct usb_interface *intf;
struct usb_device *udev;
struct usb_host_interface *alt;
intf = to_usb_interface(dev);
udev = interface_to_usbdev(intf);
alt = intf->cur_altsetting;
return sprintf(buf, "usb:v%04Xp%04Xd%04Xdc%02Xdsc%02Xdp%02X"
"ic%02Xisc%02Xip%02X\n",
le16_to_cpu(udev->descriptor.idVendor),
le16_to_cpu(udev->descriptor.idProduct),
le16_to_cpu(udev->descriptor.bcdDevice),
udev->descriptor.bDeviceClass,
udev->descriptor.bDeviceSubClass,
udev->descriptor.bDeviceProtocol,
alt->desc.bInterfaceClass,
alt->desc.bInterfaceSubClass,
alt->desc.bInterfaceProtocol);
}
static ssize_t show_supports_autosuspend(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct usb_interface *intf;
struct usb_device *udev;
int ret;
intf = to_usb_interface(dev);
udev = interface_to_usbdev(intf);
usb_lock_device(udev);
if (!intf->dev.driver ||
to_usb_driver(intf->dev.driver)->supports_autosuspend)
ret = sprintf(buf, "%u\n", 1);
else
ret = sprintf(buf, "%u\n", 0);
usb_unlock_device(udev);
return ret;
}
static mode_t intf_assoc_attrs_are_visible(struct kobject *kobj,
struct attribute *a, int n)
{
struct device *dev = container_of(kobj, struct device, kobj);
struct usb_interface *intf = to_usb_interface(dev);
if (intf->intf_assoc == NULL)
return 0;
return a->mode;
}
void usb_create_sysfs_intf_files(struct usb_interface *intf)
{
struct usb_device *udev = interface_to_usbdev(intf);
struct usb_host_interface *alt = intf->cur_altsetting;
if (intf->sysfs_files_created || intf->unregistering)
return;
if (!alt->string && !(udev->quirks & USB_QUIRK_CONFIG_INTF_STRINGS))
alt->string = usb_cache_string(udev, alt->desc.iInterface);
if (alt->string && device_create_file(&intf->dev, &dev_attr_interface))
;
intf->sysfs_files_created = 1;
}
void usb_remove_sysfs_intf_files(struct usb_interface *intf)
{
if (!intf->sysfs_files_created)
return;
device_remove_file(&intf->dev, &dev_attr_interface);
intf->sysfs_files_created = 0;
}
