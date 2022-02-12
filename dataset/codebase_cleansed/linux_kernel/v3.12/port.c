static ssize_t connect_type_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct usb_port *port_dev = to_usb_port(dev);
char *result;
switch (port_dev->connect_type) {
case USB_PORT_CONNECT_TYPE_HOT_PLUG:
result = "hotplug";
break;
case USB_PORT_CONNECT_TYPE_HARD_WIRED:
result = "hardwired";
break;
case USB_PORT_NOT_USED:
result = "not used";
break;
default:
result = "unknown";
break;
}
return sprintf(buf, "%s\n", result);
}
static void usb_port_device_release(struct device *dev)
{
struct usb_port *port_dev = to_usb_port(dev);
kfree(port_dev);
}
static int usb_port_runtime_resume(struct device *dev)
{
struct usb_port *port_dev = to_usb_port(dev);
struct usb_device *hdev = to_usb_device(dev->parent->parent);
struct usb_interface *intf = to_usb_interface(dev->parent);
struct usb_hub *hub = usb_hub_to_struct_hub(hdev);
int port1 = port_dev->portnum;
int retval;
if (!hub)
return -EINVAL;
usb_autopm_get_interface(intf);
set_bit(port1, hub->busy_bits);
retval = usb_hub_set_port_power(hdev, hub, port1, true);
if (port_dev->child && !retval) {
retval = hub_port_debounce_be_connected(hub, port1);
if (retval < 0)
dev_dbg(&port_dev->dev, "can't get reconnection after setting port power on, status %d\n",
retval);
usb_clear_port_feature(hdev, port1, USB_PORT_FEAT_C_ENABLE);
retval = 0;
}
clear_bit(port1, hub->busy_bits);
usb_autopm_put_interface(intf);
return retval;
}
static int usb_port_runtime_suspend(struct device *dev)
{
struct usb_port *port_dev = to_usb_port(dev);
struct usb_device *hdev = to_usb_device(dev->parent->parent);
struct usb_interface *intf = to_usb_interface(dev->parent);
struct usb_hub *hub = usb_hub_to_struct_hub(hdev);
int port1 = port_dev->portnum;
int retval;
if (!hub)
return -EINVAL;
if (dev_pm_qos_flags(&port_dev->dev, PM_QOS_FLAG_NO_POWER_OFF)
== PM_QOS_FLAGS_ALL)
return -EAGAIN;
usb_autopm_get_interface(intf);
set_bit(port1, hub->busy_bits);
retval = usb_hub_set_port_power(hdev, hub, port1, false);
usb_clear_port_feature(hdev, port1, USB_PORT_FEAT_C_CONNECTION);
usb_clear_port_feature(hdev, port1, USB_PORT_FEAT_C_ENABLE);
clear_bit(port1, hub->busy_bits);
usb_autopm_put_interface(intf);
return retval;
}
int usb_hub_create_port_device(struct usb_hub *hub, int port1)
{
struct usb_port *port_dev = NULL;
int retval;
port_dev = kzalloc(sizeof(*port_dev), GFP_KERNEL);
if (!port_dev) {
retval = -ENOMEM;
goto exit;
}
hub->ports[port1 - 1] = port_dev;
port_dev->portnum = port1;
port_dev->power_is_on = true;
port_dev->dev.parent = hub->intfdev;
port_dev->dev.groups = port_dev_group;
port_dev->dev.type = &usb_port_device_type;
dev_set_name(&port_dev->dev, "port%d", port1);
retval = device_register(&port_dev->dev);
if (retval)
goto error_register;
pm_runtime_set_active(&port_dev->dev);
if (!dev_pm_qos_expose_flags(&port_dev->dev,
PM_QOS_FLAG_NO_POWER_OFF))
pm_runtime_enable(&port_dev->dev);
device_enable_async_suspend(&port_dev->dev);
return 0;
error_register:
put_device(&port_dev->dev);
exit:
return retval;
}
void usb_hub_remove_port_device(struct usb_hub *hub,
int port1)
{
device_unregister(&hub->ports[port1 - 1]->dev);
}
