static ssize_t lua_sysfs_read(struct file *fp, struct kobject *kobj,
char *buf, loff_t off, size_t count,
size_t real_size, uint command)
{
struct device *dev = kobj_to_dev(kobj);
struct lua_device *lua = hid_get_drvdata(dev_get_drvdata(dev));
struct usb_device *usb_dev = interface_to_usbdev(to_usb_interface(dev));
int retval;
if (off >= real_size)
return 0;
if (off != 0 || count != real_size)
return -EINVAL;
mutex_lock(&lua->lua_lock);
retval = roccat_common2_receive(usb_dev, command, buf, real_size);
mutex_unlock(&lua->lua_lock);
return retval ? retval : real_size;
}
static ssize_t lua_sysfs_write(struct file *fp, struct kobject *kobj,
void const *buf, loff_t off, size_t count,
size_t real_size, uint command)
{
struct device *dev = kobj_to_dev(kobj);
struct lua_device *lua = hid_get_drvdata(dev_get_drvdata(dev));
struct usb_device *usb_dev = interface_to_usbdev(to_usb_interface(dev));
int retval;
if (off != 0 || count != real_size)
return -EINVAL;
mutex_lock(&lua->lua_lock);
retval = roccat_common2_send(usb_dev, command, buf, real_size);
mutex_unlock(&lua->lua_lock);
return retval ? retval : real_size;
}
static int lua_create_sysfs_attributes(struct usb_interface *intf)
{
return sysfs_create_bin_file(&intf->dev.kobj, &lua_control_attr);
}
static void lua_remove_sysfs_attributes(struct usb_interface *intf)
{
sysfs_remove_bin_file(&intf->dev.kobj, &lua_control_attr);
}
static int lua_init_lua_device_struct(struct usb_device *usb_dev,
struct lua_device *lua)
{
mutex_init(&lua->lua_lock);
return 0;
}
static int lua_init_specials(struct hid_device *hdev)
{
struct usb_interface *intf = to_usb_interface(hdev->dev.parent);
struct usb_device *usb_dev = interface_to_usbdev(intf);
struct lua_device *lua;
int retval;
lua = kzalloc(sizeof(*lua), GFP_KERNEL);
if (!lua) {
hid_err(hdev, "can't alloc device descriptor\n");
return -ENOMEM;
}
hid_set_drvdata(hdev, lua);
retval = lua_init_lua_device_struct(usb_dev, lua);
if (retval) {
hid_err(hdev, "couldn't init struct lua_device\n");
goto exit;
}
retval = lua_create_sysfs_attributes(intf);
if (retval) {
hid_err(hdev, "cannot create sysfs files\n");
goto exit;
}
return 0;
exit:
kfree(lua);
return retval;
}
static void lua_remove_specials(struct hid_device *hdev)
{
struct usb_interface *intf = to_usb_interface(hdev->dev.parent);
struct lua_device *lua;
lua_remove_sysfs_attributes(intf);
lua = hid_get_drvdata(hdev);
kfree(lua);
}
static int lua_probe(struct hid_device *hdev,
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
retval = lua_init_specials(hdev);
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
static void lua_remove(struct hid_device *hdev)
{
lua_remove_specials(hdev);
hid_hw_stop(hdev);
}
