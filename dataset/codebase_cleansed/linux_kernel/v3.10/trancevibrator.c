static ssize_t show_speed(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct usb_interface *intf = to_usb_interface(dev);
struct trancevibrator *tv = usb_get_intfdata(intf);
return sprintf(buf, "%d\n", tv->speed);
}
static ssize_t set_speed(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct usb_interface *intf = to_usb_interface(dev);
struct trancevibrator *tv = usb_get_intfdata(intf);
int temp, retval, old;
temp = simple_strtoul(buf, NULL, 10);
if (temp > 255)
temp = 255;
else if (temp < 0)
temp = 0;
old = tv->speed;
tv->speed = temp;
dev_dbg(&tv->udev->dev, "speed = %d\n", tv->speed);
retval = usb_control_msg(tv->udev, usb_sndctrlpipe(tv->udev, 0),
0x01,
USB_DIR_IN | USB_TYPE_VENDOR | USB_RECIP_OTHER,
tv->speed,
0, NULL, 0, USB_CTRL_GET_TIMEOUT);
if (retval) {
tv->speed = old;
dev_dbg(&tv->udev->dev, "retval = %d\n", retval);
return retval;
}
return count;
}
static int tv_probe(struct usb_interface *interface,
const struct usb_device_id *id)
{
struct usb_device *udev = interface_to_usbdev(interface);
struct trancevibrator *dev;
int retval;
dev = kzalloc(sizeof(struct trancevibrator), GFP_KERNEL);
if (dev == NULL) {
dev_err(&interface->dev, "Out of memory\n");
retval = -ENOMEM;
goto error;
}
dev->udev = usb_get_dev(udev);
usb_set_intfdata(interface, dev);
retval = device_create_file(&interface->dev, &dev_attr_speed);
if (retval)
goto error_create_file;
return 0;
error_create_file:
usb_put_dev(udev);
usb_set_intfdata(interface, NULL);
error:
kfree(dev);
return retval;
}
static void tv_disconnect(struct usb_interface *interface)
{
struct trancevibrator *dev;
dev = usb_get_intfdata (interface);
device_remove_file(&interface->dev, &dev_attr_speed);
usb_set_intfdata(interface, NULL);
usb_put_dev(dev->udev);
kfree(dev);
}
