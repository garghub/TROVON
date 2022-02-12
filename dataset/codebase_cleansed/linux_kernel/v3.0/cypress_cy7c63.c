static int vendor_command(struct cypress *dev, unsigned char request,
unsigned char address, unsigned char data)
{
int retval = 0;
unsigned int pipe;
unsigned char *iobuf;
iobuf = kzalloc(CYPRESS_MAX_REQSIZE, GFP_KERNEL);
if (!iobuf) {
dev_err(&dev->udev->dev, "Out of memory!\n");
retval = -ENOMEM;
goto error;
}
dev_dbg(&dev->udev->dev, "Sending usb_control_msg (data: %d)\n", data);
pipe = usb_rcvctrlpipe(dev->udev, 0);
retval = usb_control_msg(dev->udev, pipe, request,
USB_DIR_IN | USB_TYPE_VENDOR | USB_RECIP_OTHER,
address, data, iobuf, CYPRESS_MAX_REQSIZE,
USB_CTRL_GET_TIMEOUT);
switch (request) {
case CYPRESS_READ_PORT:
if (address == CYPRESS_READ_PORT_ID0) {
dev->port[0] = iobuf[1];
dev_dbg(&dev->udev->dev,
"READ_PORT0 returned: %d\n",
dev->port[0]);
}
else if (address == CYPRESS_READ_PORT_ID1) {
dev->port[1] = iobuf[1];
dev_dbg(&dev->udev->dev,
"READ_PORT1 returned: %d\n",
dev->port[1]);
}
break;
}
kfree(iobuf);
error:
return retval;
}
static ssize_t write_port(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count,
int port_num, int write_id)
{
int value = -1;
int result = 0;
struct usb_interface *intf = to_usb_interface(dev);
struct cypress *cyp = usb_get_intfdata(intf);
dev_dbg(&cyp->udev->dev, "WRITE_PORT%d called\n", port_num);
if (sscanf(buf, "%d", &value) < 1) {
result = -EINVAL;
goto error;
}
if (value < 0 || value > 255) {
result = -EINVAL;
goto error;
}
result = vendor_command(cyp, CYPRESS_WRITE_PORT, write_id,
(unsigned char)value);
dev_dbg(&cyp->udev->dev, "Result of vendor_command: %d\n\n", result);
error:
return result < 0 ? result : count;
}
static ssize_t set_port0_handler(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
return write_port(dev, attr, buf, count, 0, CYPRESS_WRITE_PORT_ID0);
}
static ssize_t set_port1_handler(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
return write_port(dev, attr, buf, count, 1, CYPRESS_WRITE_PORT_ID1);
}
static ssize_t read_port(struct device *dev, struct device_attribute *attr,
char *buf, int port_num, int read_id)
{
int result = 0;
struct usb_interface *intf = to_usb_interface(dev);
struct cypress *cyp = usb_get_intfdata(intf);
dev_dbg(&cyp->udev->dev, "READ_PORT%d called\n", port_num);
result = vendor_command(cyp, CYPRESS_READ_PORT, read_id, 0);
dev_dbg(&cyp->udev->dev, "Result of vendor_command: %d\n\n", result);
return sprintf(buf, "%d", cyp->port[port_num]);
}
static ssize_t get_port0_handler(struct device *dev,
struct device_attribute *attr, char *buf)
{
return read_port(dev, attr, buf, 0, CYPRESS_READ_PORT_ID0);
}
static ssize_t get_port1_handler(struct device *dev,
struct device_attribute *attr, char *buf)
{
return read_port(dev, attr, buf, 1, CYPRESS_READ_PORT_ID1);
}
static int cypress_probe(struct usb_interface *interface,
const struct usb_device_id *id)
{
struct cypress *dev = NULL;
int retval = -ENOMEM;
dev = kzalloc(sizeof(*dev), GFP_KERNEL);
if (dev == NULL) {
dev_err(&interface->dev, "Out of memory!\n");
goto error_mem;
}
dev->udev = usb_get_dev(interface_to_usbdev(interface));
usb_set_intfdata(interface, dev);
retval = device_create_file(&interface->dev, &dev_attr_port0);
if (retval)
goto error;
retval = device_create_file(&interface->dev, &dev_attr_port1);
if (retval)
goto error;
dev_info(&interface->dev,
"Cypress CY7C63xxx device now attached\n");
return 0;
error:
device_remove_file(&interface->dev, &dev_attr_port0);
device_remove_file(&interface->dev, &dev_attr_port1);
usb_set_intfdata(interface, NULL);
usb_put_dev(dev->udev);
kfree(dev);
error_mem:
return retval;
}
static void cypress_disconnect(struct usb_interface *interface)
{
struct cypress *dev;
dev = usb_get_intfdata(interface);
device_remove_file(&interface->dev, &dev_attr_port0);
device_remove_file(&interface->dev, &dev_attr_port1);
usb_set_intfdata(interface, NULL);
usb_put_dev(dev->udev);
dev_info(&interface->dev,
"Cypress CY7C63xxx device now disconnected\n");
kfree(dev);
}
static int __init cypress_init(void)
{
int result;
result = usb_register(&cypress_driver);
if (result)
printk(KERN_ERR KBUILD_MODNAME ": usb_register failed! "
"Error number: %d\n", result);
return result;
}
static void __exit cypress_exit(void)
{
usb_deregister(&cypress_driver);
}
