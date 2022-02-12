static int usb_serial_device_match(struct device *dev,
struct device_driver *drv)
{
struct usb_serial_driver *driver;
const struct usb_serial_port *port;
port = to_usb_serial_port(dev);
if (!port)
return 0;
driver = to_usb_serial_driver(drv);
if (driver == port->serial->type)
return 1;
return 0;
}
static ssize_t show_port_number(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct usb_serial_port *port = to_usb_serial_port(dev);
return sprintf(buf, "%d\n", port->number - port->serial->minor);
}
static int usb_serial_device_probe(struct device *dev)
{
struct usb_serial_driver *driver;
struct usb_serial_port *port;
int retval = 0;
int minor;
port = to_usb_serial_port(dev);
if (!port) {
retval = -ENODEV;
goto exit;
}
driver = port->serial->type;
if (driver->port_probe) {
retval = driver->port_probe(port);
if (retval)
goto exit;
}
retval = device_create_file(dev, &dev_attr_port_number);
if (retval) {
if (driver->port_remove)
retval = driver->port_remove(port);
goto exit;
}
minor = port->number;
tty_register_device(usb_serial_tty_driver, minor, dev);
dev_info(&port->serial->dev->dev,
"%s converter now attached to ttyUSB%d\n",
driver->description, minor);
exit:
return retval;
}
static int usb_serial_device_remove(struct device *dev)
{
struct usb_serial_driver *driver;
struct usb_serial_port *port;
int retval = 0;
int minor;
port = to_usb_serial_port(dev);
if (!port)
return -ENODEV;
device_remove_file(&port->dev, &dev_attr_port_number);
driver = port->serial->type;
if (driver->port_remove)
retval = driver->port_remove(port);
minor = port->number;
tty_unregister_device(usb_serial_tty_driver, minor);
dev_info(dev, "%s converter now disconnected from ttyUSB%d\n",
driver->description, minor);
return retval;
}
static ssize_t store_new_id(struct device_driver *driver,
const char *buf, size_t count)
{
struct usb_serial_driver *usb_drv = to_usb_serial_driver(driver);
ssize_t retval = usb_store_new_id(&usb_drv->dynids, driver, buf, count);
if (retval >= 0 && usb_drv->usb_driver != NULL)
retval = usb_store_new_id(&usb_drv->usb_driver->dynids,
&usb_drv->usb_driver->drvwrap.driver,
buf, count);
return retval;
}
static ssize_t show_dynids(struct device_driver *driver, char *buf)
{
struct usb_serial_driver *usb_drv = to_usb_serial_driver(driver);
return usb_show_dynids(&usb_drv->dynids, buf);
}
static void free_dynids(struct usb_serial_driver *drv)
{
struct usb_dynid *dynid, *n;
spin_lock(&drv->dynids.lock);
list_for_each_entry_safe(dynid, n, &drv->dynids.list, node) {
list_del(&dynid->node);
kfree(dynid);
}
spin_unlock(&drv->dynids.lock);
}
static inline void free_dynids(struct usb_serial_driver *drv)
{
}
int usb_serial_bus_register(struct usb_serial_driver *driver)
{
int retval;
driver->driver.bus = &usb_serial_bus_type;
spin_lock_init(&driver->dynids.lock);
INIT_LIST_HEAD(&driver->dynids.list);
retval = driver_register(&driver->driver);
return retval;
}
void usb_serial_bus_deregister(struct usb_serial_driver *driver)
{
free_dynids(driver);
driver_unregister(&driver->driver);
}
