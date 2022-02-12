static int vendor_command(struct usb_device *dev, unsigned char request,
unsigned char value, unsigned char index,
void *buf, int size)
{
return usb_control_msg(dev, usb_rcvctrlpipe(dev, 0),
request,
USB_DIR_IN | USB_TYPE_VENDOR | USB_RECIP_OTHER,
value,
index, buf, size,
USB_CTRL_GET_TIMEOUT);
}
static ssize_t show_brightness(struct device *dev, struct device_attribute *attr, char *buf)
{
struct usb_interface *intf = to_usb_interface(dev);
struct usb_cytherm *cytherm = usb_get_intfdata(intf);
return sprintf(buf, "%i", cytherm->brightness);
}
static ssize_t set_brightness(struct device *dev, struct device_attribute *attr, const char *buf,
size_t count)
{
struct usb_interface *intf = to_usb_interface(dev);
struct usb_cytherm *cytherm = usb_get_intfdata(intf);
unsigned char *buffer;
int retval;
buffer = kmalloc(8, GFP_KERNEL);
if (!buffer)
return 0;
cytherm->brightness = simple_strtoul(buf, NULL, 10);
if (cytherm->brightness > 0xFF)
cytherm->brightness = 0xFF;
else if (cytherm->brightness < 0)
cytherm->brightness = 0;
retval = vendor_command(cytherm->udev, WRITE_RAM, BRIGHTNESS,
cytherm->brightness, buffer, 8);
if (retval)
dev_dbg(&cytherm->udev->dev, "retval = %d\n", retval);
retval = vendor_command(cytherm->udev, WRITE_RAM, BRIGHTNESS_SEM,
0x01, buffer, 8);
if (retval)
dev_dbg(&cytherm->udev->dev, "retval = %d\n", retval);
kfree(buffer);
return count;
}
static ssize_t show_temp(struct device *dev, struct device_attribute *attr, char *buf)
{
struct usb_interface *intf = to_usb_interface(dev);
struct usb_cytherm *cytherm = usb_get_intfdata(intf);
int retval;
unsigned char *buffer;
int temp, sign;
buffer = kmalloc(8, GFP_KERNEL);
if (!buffer)
return 0;
retval = vendor_command(cytherm->udev, READ_RAM, TEMP, 0, buffer, 8);
if (retval)
dev_dbg(&cytherm->udev->dev, "retval = %d\n", retval);
temp = buffer[1];
retval = vendor_command(cytherm->udev, READ_RAM, SIGN, 0, buffer, 8);
if (retval)
dev_dbg(&cytherm->udev->dev, "retval = %d\n", retval);
sign = buffer[1];
kfree(buffer);
return sprintf(buf, "%c%i.%i", sign ? '-' : '+', temp >> 1,
5*(temp - ((temp >> 1) << 1)));
}
static ssize_t set_temp(struct device *dev, struct device_attribute *attr, const char *buf, size_t count)
{
return count;
}
static ssize_t show_button(struct device *dev, struct device_attribute *attr, char *buf)
{
struct usb_interface *intf = to_usb_interface(dev);
struct usb_cytherm *cytherm = usb_get_intfdata(intf);
int retval;
unsigned char *buffer;
buffer = kmalloc(8, GFP_KERNEL);
if (!buffer)
return 0;
retval = vendor_command(cytherm->udev, READ_RAM, BUTTON, 0, buffer, 8);
if (retval)
dev_dbg(&cytherm->udev->dev, "retval = %d\n", retval);
retval = buffer[1];
kfree(buffer);
if (retval)
return sprintf(buf, "1");
else
return sprintf(buf, "0");
}
static ssize_t set_button(struct device *dev, struct device_attribute *attr, const char *buf, size_t count)
{
return count;
}
static ssize_t show_port0(struct device *dev, struct device_attribute *attr, char *buf)
{
struct usb_interface *intf = to_usb_interface(dev);
struct usb_cytherm *cytherm = usb_get_intfdata(intf);
int retval;
unsigned char *buffer;
buffer = kmalloc(8, GFP_KERNEL);
if (!buffer)
return 0;
retval = vendor_command(cytherm->udev, READ_PORT, 0, 0, buffer, 8);
if (retval)
dev_dbg(&cytherm->udev->dev, "retval = %d\n", retval);
retval = buffer[1];
kfree(buffer);
return sprintf(buf, "%d", retval);
}
static ssize_t set_port0(struct device *dev, struct device_attribute *attr, const char *buf, size_t count)
{
struct usb_interface *intf = to_usb_interface(dev);
struct usb_cytherm *cytherm = usb_get_intfdata(intf);
unsigned char *buffer;
int retval;
int tmp;
buffer = kmalloc(8, GFP_KERNEL);
if (!buffer)
return 0;
tmp = simple_strtoul(buf, NULL, 10);
if (tmp > 0xFF)
tmp = 0xFF;
else if (tmp < 0)
tmp = 0;
retval = vendor_command(cytherm->udev, WRITE_PORT, 0,
tmp, buffer, 8);
if (retval)
dev_dbg(&cytherm->udev->dev, "retval = %d\n", retval);
kfree(buffer);
return count;
}
static ssize_t show_port1(struct device *dev, struct device_attribute *attr, char *buf)
{
struct usb_interface *intf = to_usb_interface(dev);
struct usb_cytherm *cytherm = usb_get_intfdata(intf);
int retval;
unsigned char *buffer;
buffer = kmalloc(8, GFP_KERNEL);
if (!buffer)
return 0;
retval = vendor_command(cytherm->udev, READ_PORT, 1, 0, buffer, 8);
if (retval)
dev_dbg(&cytherm->udev->dev, "retval = %d\n", retval);
retval = buffer[1];
kfree(buffer);
return sprintf(buf, "%d", retval);
}
static ssize_t set_port1(struct device *dev, struct device_attribute *attr, const char *buf, size_t count)
{
struct usb_interface *intf = to_usb_interface(dev);
struct usb_cytherm *cytherm = usb_get_intfdata(intf);
unsigned char *buffer;
int retval;
int tmp;
buffer = kmalloc(8, GFP_KERNEL);
if (!buffer)
return 0;
tmp = simple_strtoul(buf, NULL, 10);
if (tmp > 0xFF)
tmp = 0xFF;
else if (tmp < 0)
tmp = 0;
retval = vendor_command(cytherm->udev, WRITE_PORT, 1,
tmp, buffer, 8);
if (retval)
dev_dbg(&cytherm->udev->dev, "retval = %d\n", retval);
kfree(buffer);
return count;
}
static int cytherm_probe(struct usb_interface *interface,
const struct usb_device_id *id)
{
struct usb_device *udev = interface_to_usbdev(interface);
struct usb_cytherm *dev = NULL;
int retval = -ENOMEM;
dev = kzalloc (sizeof(struct usb_cytherm), GFP_KERNEL);
if (!dev)
goto error_mem;
dev->udev = usb_get_dev(udev);
usb_set_intfdata (interface, dev);
dev->brightness = 0xFF;
retval = device_create_file(&interface->dev, &dev_attr_brightness);
if (retval)
goto error;
retval = device_create_file(&interface->dev, &dev_attr_temp);
if (retval)
goto error;
retval = device_create_file(&interface->dev, &dev_attr_button);
if (retval)
goto error;
retval = device_create_file(&interface->dev, &dev_attr_port0);
if (retval)
goto error;
retval = device_create_file(&interface->dev, &dev_attr_port1);
if (retval)
goto error;
dev_info (&interface->dev,
"Cypress thermometer device now attached\n");
return 0;
error:
device_remove_file(&interface->dev, &dev_attr_brightness);
device_remove_file(&interface->dev, &dev_attr_temp);
device_remove_file(&interface->dev, &dev_attr_button);
device_remove_file(&interface->dev, &dev_attr_port0);
device_remove_file(&interface->dev, &dev_attr_port1);
usb_set_intfdata (interface, NULL);
usb_put_dev(dev->udev);
kfree(dev);
error_mem:
return retval;
}
static void cytherm_disconnect(struct usb_interface *interface)
{
struct usb_cytherm *dev;
dev = usb_get_intfdata (interface);
device_remove_file(&interface->dev, &dev_attr_brightness);
device_remove_file(&interface->dev, &dev_attr_temp);
device_remove_file(&interface->dev, &dev_attr_button);
device_remove_file(&interface->dev, &dev_attr_port0);
device_remove_file(&interface->dev, &dev_attr_port1);
usb_set_intfdata (interface, NULL);
usb_put_dev(dev->udev);
kfree(dev);
dev_info(&interface->dev, "Cypress thermometer now disconnected\n");
}
