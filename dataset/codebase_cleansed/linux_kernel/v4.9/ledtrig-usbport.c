static bool usbport_trig_usb_dev_observed(struct usbport_trig_data *usbport_data,
struct usb_device *usb_dev)
{
struct usbport_trig_port *port;
if (!usb_dev->parent)
return false;
list_for_each_entry(port, &usbport_data->ports, list) {
if (usb_dev->parent == port->hub &&
usb_dev->portnum == port->portnum)
return port->observed;
}
return false;
}
static int usbport_trig_usb_dev_check(struct usb_device *usb_dev, void *data)
{
struct usbport_trig_data *usbport_data = data;
if (usbport_trig_usb_dev_observed(usbport_data, usb_dev))
usbport_data->count++;
return 0;
}
static void usbport_trig_update_count(struct usbport_trig_data *usbport_data)
{
struct led_classdev *led_cdev = usbport_data->led_cdev;
usbport_data->count = 0;
usb_for_each_dev(usbport_data, usbport_trig_usb_dev_check);
led_cdev->brightness_set(led_cdev,
usbport_data->count ? LED_FULL : LED_OFF);
}
static ssize_t usbport_trig_port_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct usbport_trig_port *port = container_of(attr,
struct usbport_trig_port,
attr);
return sprintf(buf, "%d\n", port->observed) + 1;
}
static ssize_t usbport_trig_port_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
struct usbport_trig_port *port = container_of(attr,
struct usbport_trig_port,
attr);
if (!strcmp(buf, "0") || !strcmp(buf, "0\n"))
port->observed = 0;
else if (!strcmp(buf, "1") || !strcmp(buf, "1\n"))
port->observed = 1;
else
return -EINVAL;
usbport_trig_update_count(port->data);
return size;
}
static int usbport_trig_add_port(struct usbport_trig_data *usbport_data,
struct usb_device *usb_dev,
const char *hub_name, int portnum)
{
struct led_classdev *led_cdev = usbport_data->led_cdev;
struct usbport_trig_port *port;
size_t len;
int err;
port = kzalloc(sizeof(*port), GFP_KERNEL);
if (!port) {
err = -ENOMEM;
goto err_out;
}
port->data = usbport_data;
port->hub = usb_dev;
port->portnum = portnum;
len = strlen(hub_name) + 8;
port->port_name = kzalloc(len, GFP_KERNEL);
if (!port->port_name) {
err = -ENOMEM;
goto err_free_port;
}
snprintf(port->port_name, len, "%s-port%d", hub_name, portnum);
port->attr.attr.name = port->port_name;
port->attr.attr.mode = S_IRUSR | S_IWUSR;
port->attr.show = usbport_trig_port_show;
port->attr.store = usbport_trig_port_store;
err = sysfs_add_file_to_group(&led_cdev->dev->kobj, &port->attr.attr,
ports_group.name);
if (err)
goto err_free_port_name;
list_add_tail(&port->list, &usbport_data->ports);
return 0;
err_free_port_name:
kfree(port->port_name);
err_free_port:
kfree(port);
err_out:
return err;
}
static int usbport_trig_add_usb_dev_ports(struct usb_device *usb_dev,
void *data)
{
struct usbport_trig_data *usbport_data = data;
int i;
for (i = 1; i <= usb_dev->maxchild; i++)
usbport_trig_add_port(usbport_data, usb_dev,
dev_name(&usb_dev->dev), i);
return 0;
}
static void usbport_trig_remove_port(struct usbport_trig_data *usbport_data,
struct usbport_trig_port *port)
{
struct led_classdev *led_cdev = usbport_data->led_cdev;
list_del(&port->list);
sysfs_remove_file_from_group(&led_cdev->dev->kobj, &port->attr.attr,
ports_group.name);
kfree(port->port_name);
kfree(port);
}
static void usbport_trig_remove_usb_dev_ports(struct usbport_trig_data *usbport_data,
struct usb_device *usb_dev)
{
struct usbport_trig_port *port, *tmp;
list_for_each_entry_safe(port, tmp, &usbport_data->ports, list) {
if (port->hub == usb_dev)
usbport_trig_remove_port(usbport_data, port);
}
}
static int usbport_trig_notify(struct notifier_block *nb, unsigned long action,
void *data)
{
struct usbport_trig_data *usbport_data =
container_of(nb, struct usbport_trig_data, nb);
struct led_classdev *led_cdev = usbport_data->led_cdev;
struct usb_device *usb_dev = data;
bool observed;
observed = usbport_trig_usb_dev_observed(usbport_data, usb_dev);
switch (action) {
case USB_DEVICE_ADD:
usbport_trig_add_usb_dev_ports(usb_dev, usbport_data);
if (observed && usbport_data->count++ == 0)
led_cdev->brightness_set(led_cdev, LED_FULL);
return NOTIFY_OK;
case USB_DEVICE_REMOVE:
usbport_trig_remove_usb_dev_ports(usbport_data, usb_dev);
if (observed && --usbport_data->count == 0)
led_cdev->brightness_set(led_cdev, LED_OFF);
return NOTIFY_OK;
}
return NOTIFY_DONE;
}
static void usbport_trig_activate(struct led_classdev *led_cdev)
{
struct usbport_trig_data *usbport_data;
int err;
usbport_data = kzalloc(sizeof(*usbport_data), GFP_KERNEL);
if (!usbport_data)
return;
usbport_data->led_cdev = led_cdev;
INIT_LIST_HEAD(&usbport_data->ports);
err = sysfs_create_group(&led_cdev->dev->kobj, &ports_group);
if (err)
goto err_free;
usb_for_each_dev(usbport_data, usbport_trig_add_usb_dev_ports);
usbport_data->nb.notifier_call = usbport_trig_notify,
led_cdev->trigger_data = usbport_data;
usb_register_notify(&usbport_data->nb);
led_cdev->activated = true;
return;
err_free:
kfree(usbport_data);
}
static void usbport_trig_deactivate(struct led_classdev *led_cdev)
{
struct usbport_trig_data *usbport_data = led_cdev->trigger_data;
struct usbport_trig_port *port, *tmp;
if (!led_cdev->activated)
return;
list_for_each_entry_safe(port, tmp, &usbport_data->ports, list) {
usbport_trig_remove_port(usbport_data, port);
}
usb_unregister_notify(&usbport_data->nb);
sysfs_remove_group(&led_cdev->dev->kobj, &ports_group);
kfree(usbport_data);
led_cdev->activated = false;
}
static int __init usbport_trig_init(void)
{
return led_trigger_register(&usbport_led_trigger);
}
static void __exit usbport_trig_exit(void)
{
led_trigger_unregister(&usbport_led_trigger);
}
