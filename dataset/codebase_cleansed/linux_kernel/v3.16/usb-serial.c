struct usb_serial_port *usb_serial_port_get_by_minor(unsigned minor)
{
struct usb_serial *serial;
struct usb_serial_port *port;
mutex_lock(&table_lock);
port = idr_find(&serial_minors, minor);
if (!port)
goto exit;
serial = port->serial;
mutex_lock(&serial->disc_mutex);
if (serial->disconnected) {
mutex_unlock(&serial->disc_mutex);
port = NULL;
} else {
kref_get(&serial->kref);
}
exit:
mutex_unlock(&table_lock);
return port;
}
static int allocate_minors(struct usb_serial *serial, int num_ports)
{
struct usb_serial_port *port;
unsigned int i, j;
int minor;
dev_dbg(&serial->interface->dev, "%s %d\n", __func__, num_ports);
mutex_lock(&table_lock);
for (i = 0; i < num_ports; ++i) {
port = serial->port[i];
minor = idr_alloc(&serial_minors, port, 0, 0, GFP_KERNEL);
if (minor < 0)
goto error;
port->minor = minor;
port->port_number = i;
}
serial->minors_reserved = 1;
mutex_unlock(&table_lock);
return 0;
error:
for (j = 0; j < i; ++j)
idr_remove(&serial_minors, serial->port[j]->minor);
mutex_unlock(&table_lock);
return minor;
}
static void release_minors(struct usb_serial *serial)
{
int i;
mutex_lock(&table_lock);
for (i = 0; i < serial->num_ports; ++i)
idr_remove(&serial_minors, serial->port[i]->minor);
mutex_unlock(&table_lock);
serial->minors_reserved = 0;
}
static void destroy_serial(struct kref *kref)
{
struct usb_serial *serial;
struct usb_serial_port *port;
int i;
serial = to_usb_serial(kref);
if (serial->minors_reserved)
release_minors(serial);
if (serial->attached && serial->type->release)
serial->type->release(serial);
for (i = 0; i < serial->num_port_pointers; ++i) {
port = serial->port[i];
if (port) {
port->serial = NULL;
put_device(&port->dev);
}
}
usb_put_intf(serial->interface);
usb_put_dev(serial->dev);
kfree(serial);
}
void usb_serial_put(struct usb_serial *serial)
{
kref_put(&serial->kref, destroy_serial);
}
static int serial_install(struct tty_driver *driver, struct tty_struct *tty)
{
int idx = tty->index;
struct usb_serial *serial;
struct usb_serial_port *port;
int retval = -ENODEV;
port = usb_serial_port_get_by_minor(idx);
if (!port)
return retval;
serial = port->serial;
if (!try_module_get(serial->type->driver.owner))
goto error_module_get;
retval = usb_autopm_get_interface(serial->interface);
if (retval)
goto error_get_interface;
retval = tty_port_install(&port->port, driver, tty);
if (retval)
goto error_init_termios;
mutex_unlock(&serial->disc_mutex);
if (serial->type->init_termios)
serial->type->init_termios(tty);
tty->driver_data = port;
return retval;
error_init_termios:
usb_autopm_put_interface(serial->interface);
error_get_interface:
module_put(serial->type->driver.owner);
error_module_get:
usb_serial_put(serial);
mutex_unlock(&serial->disc_mutex);
return retval;
}
static int serial_port_activate(struct tty_port *tport, struct tty_struct *tty)
{
struct usb_serial_port *port =
container_of(tport, struct usb_serial_port, port);
struct usb_serial *serial = port->serial;
int retval;
mutex_lock(&serial->disc_mutex);
if (serial->disconnected)
retval = -ENODEV;
else
retval = port->serial->type->open(tty, port);
mutex_unlock(&serial->disc_mutex);
if (retval < 0)
retval = usb_translate_errors(retval);
return retval;
}
static int serial_open(struct tty_struct *tty, struct file *filp)
{
struct usb_serial_port *port = tty->driver_data;
dev_dbg(tty->dev, "%s\n", __func__);
return tty_port_open(&port->port, tty, filp);
}
static void serial_port_shutdown(struct tty_port *tport)
{
struct usb_serial_port *port =
container_of(tport, struct usb_serial_port, port);
struct usb_serial_driver *drv = port->serial->type;
if (drv->close)
drv->close(port);
}
static void serial_hangup(struct tty_struct *tty)
{
struct usb_serial_port *port = tty->driver_data;
dev_dbg(tty->dev, "%s\n", __func__);
tty_port_hangup(&port->port);
}
static void serial_close(struct tty_struct *tty, struct file *filp)
{
struct usb_serial_port *port = tty->driver_data;
dev_dbg(tty->dev, "%s\n", __func__);
tty_port_close(&port->port, tty, filp);
}
static void serial_cleanup(struct tty_struct *tty)
{
struct usb_serial_port *port = tty->driver_data;
struct usb_serial *serial;
struct module *owner;
dev_dbg(tty->dev, "%s\n", __func__);
if (port->port.console)
return;
tty->driver_data = NULL;
serial = port->serial;
owner = serial->type->driver.owner;
mutex_lock(&serial->disc_mutex);
if (!serial->disconnected)
usb_autopm_put_interface(serial->interface);
mutex_unlock(&serial->disc_mutex);
usb_serial_put(serial);
module_put(owner);
}
static int serial_write(struct tty_struct *tty, const unsigned char *buf,
int count)
{
struct usb_serial_port *port = tty->driver_data;
int retval = -ENODEV;
if (port->serial->dev->state == USB_STATE_NOTATTACHED)
goto exit;
dev_dbg(tty->dev, "%s - %d byte(s)\n", __func__, count);
retval = port->serial->type->write(tty, port, buf, count);
if (retval < 0)
retval = usb_translate_errors(retval);
exit:
return retval;
}
static int serial_write_room(struct tty_struct *tty)
{
struct usb_serial_port *port = tty->driver_data;
dev_dbg(tty->dev, "%s\n", __func__);
return port->serial->type->write_room(tty);
}
static int serial_chars_in_buffer(struct tty_struct *tty)
{
struct usb_serial_port *port = tty->driver_data;
struct usb_serial *serial = port->serial;
dev_dbg(tty->dev, "%s\n", __func__);
if (serial->disconnected)
return 0;
return serial->type->chars_in_buffer(tty);
}
static void serial_wait_until_sent(struct tty_struct *tty, int timeout)
{
struct usb_serial_port *port = tty->driver_data;
struct usb_serial *serial = port->serial;
dev_dbg(tty->dev, "%s\n", __func__);
if (!port->serial->type->wait_until_sent)
return;
mutex_lock(&serial->disc_mutex);
if (!serial->disconnected)
port->serial->type->wait_until_sent(tty, timeout);
mutex_unlock(&serial->disc_mutex);
}
static void serial_throttle(struct tty_struct *tty)
{
struct usb_serial_port *port = tty->driver_data;
dev_dbg(tty->dev, "%s\n", __func__);
if (port->serial->type->throttle)
port->serial->type->throttle(tty);
}
static void serial_unthrottle(struct tty_struct *tty)
{
struct usb_serial_port *port = tty->driver_data;
dev_dbg(tty->dev, "%s\n", __func__);
if (port->serial->type->unthrottle)
port->serial->type->unthrottle(tty);
}
static int serial_ioctl(struct tty_struct *tty,
unsigned int cmd, unsigned long arg)
{
struct usb_serial_port *port = tty->driver_data;
int retval = -ENOIOCTLCMD;
dev_dbg(tty->dev, "%s - cmd 0x%04x\n", __func__, cmd);
switch (cmd) {
case TIOCMIWAIT:
if (port->serial->type->tiocmiwait)
retval = port->serial->type->tiocmiwait(tty, arg);
break;
default:
if (port->serial->type->ioctl)
retval = port->serial->type->ioctl(tty, cmd, arg);
}
return retval;
}
static void serial_set_termios(struct tty_struct *tty, struct ktermios *old)
{
struct usb_serial_port *port = tty->driver_data;
dev_dbg(tty->dev, "%s\n", __func__);
if (port->serial->type->set_termios)
port->serial->type->set_termios(tty, port, old);
else
tty_termios_copy_hw(&tty->termios, old);
}
static int serial_break(struct tty_struct *tty, int break_state)
{
struct usb_serial_port *port = tty->driver_data;
dev_dbg(tty->dev, "%s\n", __func__);
if (port->serial->type->break_ctl)
port->serial->type->break_ctl(tty, break_state);
return 0;
}
static int serial_proc_show(struct seq_file *m, void *v)
{
struct usb_serial *serial;
struct usb_serial_port *port;
int i;
char tmp[40];
seq_puts(m, "usbserinfo:1.0 driver:2.0\n");
for (i = 0; i < USB_SERIAL_TTY_MINORS; ++i) {
port = usb_serial_port_get_by_minor(i);
if (port == NULL)
continue;
serial = port->serial;
seq_printf(m, "%d:", i);
if (serial->type->driver.owner)
seq_printf(m, " module:%s",
module_name(serial->type->driver.owner));
seq_printf(m, " name:\"%s\"",
serial->type->description);
seq_printf(m, " vendor:%04x product:%04x",
le16_to_cpu(serial->dev->descriptor.idVendor),
le16_to_cpu(serial->dev->descriptor.idProduct));
seq_printf(m, " num_ports:%d", serial->num_ports);
seq_printf(m, " port:%d", port->port_number);
usb_make_path(serial->dev, tmp, sizeof(tmp));
seq_printf(m, " path:%s", tmp);
seq_putc(m, '\n');
usb_serial_put(serial);
mutex_unlock(&serial->disc_mutex);
}
return 0;
}
static int serial_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, serial_proc_show, NULL);
}
static int serial_tiocmget(struct tty_struct *tty)
{
struct usb_serial_port *port = tty->driver_data;
dev_dbg(tty->dev, "%s\n", __func__);
if (port->serial->type->tiocmget)
return port->serial->type->tiocmget(tty);
return -EINVAL;
}
static int serial_tiocmset(struct tty_struct *tty,
unsigned int set, unsigned int clear)
{
struct usb_serial_port *port = tty->driver_data;
dev_dbg(tty->dev, "%s\n", __func__);
if (port->serial->type->tiocmset)
return port->serial->type->tiocmset(tty, set, clear);
return -EINVAL;
}
static int serial_get_icount(struct tty_struct *tty,
struct serial_icounter_struct *icount)
{
struct usb_serial_port *port = tty->driver_data;
dev_dbg(tty->dev, "%s\n", __func__);
if (port->serial->type->get_icount)
return port->serial->type->get_icount(tty, icount);
return -EINVAL;
}
void usb_serial_port_softint(struct usb_serial_port *port)
{
schedule_work(&port->work);
}
static void usb_serial_port_work(struct work_struct *work)
{
struct usb_serial_port *port =
container_of(work, struct usb_serial_port, work);
tty_port_tty_wakeup(&port->port);
}
static void usb_serial_port_poison_urbs(struct usb_serial_port *port)
{
int i;
for (i = 0; i < ARRAY_SIZE(port->read_urbs); ++i)
usb_poison_urb(port->read_urbs[i]);
for (i = 0; i < ARRAY_SIZE(port->write_urbs); ++i)
usb_poison_urb(port->write_urbs[i]);
usb_poison_urb(port->interrupt_in_urb);
usb_poison_urb(port->interrupt_out_urb);
}
static void usb_serial_port_unpoison_urbs(struct usb_serial_port *port)
{
int i;
for (i = 0; i < ARRAY_SIZE(port->read_urbs); ++i)
usb_unpoison_urb(port->read_urbs[i]);
for (i = 0; i < ARRAY_SIZE(port->write_urbs); ++i)
usb_unpoison_urb(port->write_urbs[i]);
usb_unpoison_urb(port->interrupt_in_urb);
usb_unpoison_urb(port->interrupt_out_urb);
}
static void usb_serial_port_release(struct device *dev)
{
struct usb_serial_port *port = to_usb_serial_port(dev);
int i;
dev_dbg(dev, "%s\n", __func__);
usb_free_urb(port->interrupt_in_urb);
usb_free_urb(port->interrupt_out_urb);
for (i = 0; i < ARRAY_SIZE(port->read_urbs); ++i) {
usb_free_urb(port->read_urbs[i]);
kfree(port->bulk_in_buffers[i]);
}
for (i = 0; i < ARRAY_SIZE(port->write_urbs); ++i) {
usb_free_urb(port->write_urbs[i]);
kfree(port->bulk_out_buffers[i]);
}
kfifo_free(&port->write_fifo);
kfree(port->interrupt_in_buffer);
kfree(port->interrupt_out_buffer);
tty_port_destroy(&port->port);
kfree(port);
}
static struct usb_serial *create_serial(struct usb_device *dev,
struct usb_interface *interface,
struct usb_serial_driver *driver)
{
struct usb_serial *serial;
serial = kzalloc(sizeof(*serial), GFP_KERNEL);
if (!serial)
return NULL;
serial->dev = usb_get_dev(dev);
serial->type = driver;
serial->interface = usb_get_intf(interface);
kref_init(&serial->kref);
mutex_init(&serial->disc_mutex);
serial->minors_reserved = 0;
return serial;
}
static const struct usb_device_id *match_dynamic_id(struct usb_interface *intf,
struct usb_serial_driver *drv)
{
struct usb_dynid *dynid;
spin_lock(&drv->dynids.lock);
list_for_each_entry(dynid, &drv->dynids.list, node) {
if (usb_match_one_id(intf, &dynid->id)) {
spin_unlock(&drv->dynids.lock);
return &dynid->id;
}
}
spin_unlock(&drv->dynids.lock);
return NULL;
}
static const struct usb_device_id *get_iface_id(struct usb_serial_driver *drv,
struct usb_interface *intf)
{
const struct usb_device_id *id;
id = usb_match_id(intf, drv->id_table);
if (id) {
dev_dbg(&intf->dev, "static descriptor matches\n");
goto exit;
}
id = match_dynamic_id(intf, drv);
if (id)
dev_dbg(&intf->dev, "dynamic descriptor matches\n");
exit:
return id;
}
static struct usb_serial_driver *search_serial_device(
struct usb_interface *iface)
{
const struct usb_device_id *id = NULL;
struct usb_serial_driver *drv;
struct usb_driver *driver = to_usb_driver(iface->dev.driver);
list_for_each_entry(drv, &usb_serial_driver_list, driver_list) {
if (drv->usb_driver == driver)
id = get_iface_id(drv, iface);
if (id)
return drv;
}
return NULL;
}
static int serial_port_carrier_raised(struct tty_port *port)
{
struct usb_serial_port *p = container_of(port, struct usb_serial_port, port);
struct usb_serial_driver *drv = p->serial->type;
if (drv->carrier_raised)
return drv->carrier_raised(p);
return 1;
}
static void serial_port_dtr_rts(struct tty_port *port, int on)
{
struct usb_serial_port *p = container_of(port, struct usb_serial_port, port);
struct usb_serial_driver *drv = p->serial->type;
if (drv->dtr_rts)
drv->dtr_rts(p, on);
}
static int usb_serial_probe(struct usb_interface *interface,
const struct usb_device_id *id)
{
struct device *ddev = &interface->dev;
struct usb_device *dev = interface_to_usbdev(interface);
struct usb_serial *serial = NULL;
struct usb_serial_port *port;
struct usb_host_interface *iface_desc;
struct usb_endpoint_descriptor *endpoint;
struct usb_endpoint_descriptor *interrupt_in_endpoint[MAX_NUM_PORTS];
struct usb_endpoint_descriptor *interrupt_out_endpoint[MAX_NUM_PORTS];
struct usb_endpoint_descriptor *bulk_in_endpoint[MAX_NUM_PORTS];
struct usb_endpoint_descriptor *bulk_out_endpoint[MAX_NUM_PORTS];
struct usb_serial_driver *type = NULL;
int retval;
int buffer_size;
int i;
int j;
int num_interrupt_in = 0;
int num_interrupt_out = 0;
int num_bulk_in = 0;
int num_bulk_out = 0;
int num_ports = 0;
int max_endpoints;
mutex_lock(&table_lock);
type = search_serial_device(interface);
if (!type) {
mutex_unlock(&table_lock);
dev_dbg(ddev, "none matched\n");
return -ENODEV;
}
if (!try_module_get(type->driver.owner)) {
mutex_unlock(&table_lock);
dev_err(ddev, "module get failed, exiting\n");
return -EIO;
}
mutex_unlock(&table_lock);
serial = create_serial(dev, interface, type);
if (!serial) {
module_put(type->driver.owner);
return -ENOMEM;
}
if (type->probe) {
const struct usb_device_id *id;
id = get_iface_id(type, interface);
retval = type->probe(serial, id);
if (retval) {
dev_dbg(ddev, "sub driver rejected device\n");
usb_serial_put(serial);
module_put(type->driver.owner);
return retval;
}
}
iface_desc = interface->cur_altsetting;
for (i = 0; i < iface_desc->desc.bNumEndpoints; ++i) {
endpoint = &iface_desc->endpoint[i].desc;
if (usb_endpoint_is_bulk_in(endpoint)) {
dev_dbg(ddev, "found bulk in on endpoint %d\n", i);
bulk_in_endpoint[num_bulk_in] = endpoint;
++num_bulk_in;
}
if (usb_endpoint_is_bulk_out(endpoint)) {
dev_dbg(ddev, "found bulk out on endpoint %d\n", i);
bulk_out_endpoint[num_bulk_out] = endpoint;
++num_bulk_out;
}
if (usb_endpoint_is_int_in(endpoint)) {
dev_dbg(ddev, "found interrupt in on endpoint %d\n", i);
interrupt_in_endpoint[num_interrupt_in] = endpoint;
++num_interrupt_in;
}
if (usb_endpoint_is_int_out(endpoint)) {
dev_dbg(ddev, "found interrupt out on endpoint %d\n", i);
interrupt_out_endpoint[num_interrupt_out] = endpoint;
++num_interrupt_out;
}
}
#if defined(CONFIG_USB_SERIAL_PL2303) || defined(CONFIG_USB_SERIAL_PL2303_MODULE)
if (((le16_to_cpu(dev->descriptor.idVendor) == PL2303_VENDOR_ID) &&
(le16_to_cpu(dev->descriptor.idProduct) == PL2303_PRODUCT_ID)) ||
((le16_to_cpu(dev->descriptor.idVendor) == ATEN_VENDOR_ID) &&
(le16_to_cpu(dev->descriptor.idProduct) == ATEN_PRODUCT_ID)) ||
((le16_to_cpu(dev->descriptor.idVendor) == ALCOR_VENDOR_ID) &&
(le16_to_cpu(dev->descriptor.idProduct) == ALCOR_PRODUCT_ID)) ||
((le16_to_cpu(dev->descriptor.idVendor) == SIEMENS_VENDOR_ID) &&
(le16_to_cpu(dev->descriptor.idProduct) == SIEMENS_PRODUCT_ID_EF81))) {
if (interface != dev->actconfig->interface[0]) {
iface_desc = dev->actconfig->interface[0]->cur_altsetting;
for (i = 0; i < iface_desc->desc.bNumEndpoints; ++i) {
endpoint = &iface_desc->endpoint[i].desc;
if (usb_endpoint_is_int_in(endpoint)) {
dev_dbg(ddev, "found interrupt in for Prolific device on separate interface\n");
interrupt_in_endpoint[num_interrupt_in] = endpoint;
++num_interrupt_in;
}
}
}
if (num_bulk_in == 0 || num_bulk_out == 0) {
dev_info(ddev, "PL-2303 hack: descriptors matched but endpoints did not\n");
usb_serial_put(serial);
module_put(type->driver.owner);
return -ENODEV;
}
}
#endif
#ifdef CONFIG_USB_SERIAL_GENERIC
if (type == &usb_serial_generic_device) {
num_ports = num_bulk_out;
if (num_ports == 0) {
dev_err(ddev, "Generic device with no bulk out, not allowed.\n");
usb_serial_put(serial);
module_put(type->driver.owner);
return -EIO;
}
dev_info(ddev, "The \"generic\" usb-serial driver is only for testing and one-off prototypes.\n");
dev_info(ddev, "Tell linux-usb@vger.kernel.org to add your device to a proper driver.\n");
}
#endif
if (!num_ports) {
if (type->calc_num_ports)
num_ports = type->calc_num_ports(serial);
if (!num_ports)
num_ports = type->num_ports;
}
serial->num_ports = num_ports;
serial->num_bulk_in = num_bulk_in;
serial->num_bulk_out = num_bulk_out;
serial->num_interrupt_in = num_interrupt_in;
serial->num_interrupt_out = num_interrupt_out;
dev_info(ddev, "%s converter detected\n", type->description);
max_endpoints = max(num_bulk_in, num_bulk_out);
max_endpoints = max(max_endpoints, num_interrupt_in);
max_endpoints = max(max_endpoints, num_interrupt_out);
max_endpoints = max(max_endpoints, (int)serial->num_ports);
serial->num_port_pointers = max_endpoints;
dev_dbg(ddev, "setting up %d port structure(s)\n", max_endpoints);
for (i = 0; i < max_endpoints; ++i) {
port = kzalloc(sizeof(struct usb_serial_port), GFP_KERNEL);
if (!port)
goto probe_error;
tty_port_init(&port->port);
port->port.ops = &serial_port_ops;
port->serial = serial;
spin_lock_init(&port->lock);
INIT_WORK(&port->work, usb_serial_port_work);
serial->port[i] = port;
port->dev.parent = &interface->dev;
port->dev.driver = NULL;
port->dev.bus = &usb_serial_bus_type;
port->dev.release = &usb_serial_port_release;
device_initialize(&port->dev);
}
for (i = 0; i < num_bulk_in; ++i) {
endpoint = bulk_in_endpoint[i];
port = serial->port[i];
buffer_size = max_t(int, serial->type->bulk_in_size,
usb_endpoint_maxp(endpoint));
port->bulk_in_size = buffer_size;
port->bulk_in_endpointAddress = endpoint->bEndpointAddress;
for (j = 0; j < ARRAY_SIZE(port->read_urbs); ++j) {
set_bit(j, &port->read_urbs_free);
port->read_urbs[j] = usb_alloc_urb(0, GFP_KERNEL);
if (!port->read_urbs[j])
goto probe_error;
port->bulk_in_buffers[j] = kmalloc(buffer_size,
GFP_KERNEL);
if (!port->bulk_in_buffers[j])
goto probe_error;
usb_fill_bulk_urb(port->read_urbs[j], dev,
usb_rcvbulkpipe(dev,
endpoint->bEndpointAddress),
port->bulk_in_buffers[j], buffer_size,
serial->type->read_bulk_callback,
port);
}
port->read_urb = port->read_urbs[0];
port->bulk_in_buffer = port->bulk_in_buffers[0];
}
for (i = 0; i < num_bulk_out; ++i) {
endpoint = bulk_out_endpoint[i];
port = serial->port[i];
if (kfifo_alloc(&port->write_fifo, PAGE_SIZE, GFP_KERNEL))
goto probe_error;
buffer_size = max_t(int, serial->type->bulk_out_size,
usb_endpoint_maxp(endpoint));
port->bulk_out_size = buffer_size;
port->bulk_out_endpointAddress = endpoint->bEndpointAddress;
for (j = 0; j < ARRAY_SIZE(port->write_urbs); ++j) {
set_bit(j, &port->write_urbs_free);
port->write_urbs[j] = usb_alloc_urb(0, GFP_KERNEL);
if (!port->write_urbs[j])
goto probe_error;
port->bulk_out_buffers[j] = kmalloc(buffer_size,
GFP_KERNEL);
if (!port->bulk_out_buffers[j])
goto probe_error;
usb_fill_bulk_urb(port->write_urbs[j], dev,
usb_sndbulkpipe(dev,
endpoint->bEndpointAddress),
port->bulk_out_buffers[j], buffer_size,
serial->type->write_bulk_callback,
port);
}
port->write_urb = port->write_urbs[0];
port->bulk_out_buffer = port->bulk_out_buffers[0];
}
if (serial->type->read_int_callback) {
for (i = 0; i < num_interrupt_in; ++i) {
endpoint = interrupt_in_endpoint[i];
port = serial->port[i];
port->interrupt_in_urb = usb_alloc_urb(0, GFP_KERNEL);
if (!port->interrupt_in_urb)
goto probe_error;
buffer_size = usb_endpoint_maxp(endpoint);
port->interrupt_in_endpointAddress =
endpoint->bEndpointAddress;
port->interrupt_in_buffer = kmalloc(buffer_size,
GFP_KERNEL);
if (!port->interrupt_in_buffer)
goto probe_error;
usb_fill_int_urb(port->interrupt_in_urb, dev,
usb_rcvintpipe(dev,
endpoint->bEndpointAddress),
port->interrupt_in_buffer, buffer_size,
serial->type->read_int_callback, port,
endpoint->bInterval);
}
} else if (num_interrupt_in) {
dev_dbg(ddev, "The device claims to support interrupt in transfers, but read_int_callback is not defined\n");
}
if (serial->type->write_int_callback) {
for (i = 0; i < num_interrupt_out; ++i) {
endpoint = interrupt_out_endpoint[i];
port = serial->port[i];
port->interrupt_out_urb = usb_alloc_urb(0, GFP_KERNEL);
if (!port->interrupt_out_urb)
goto probe_error;
buffer_size = usb_endpoint_maxp(endpoint);
port->interrupt_out_size = buffer_size;
port->interrupt_out_endpointAddress =
endpoint->bEndpointAddress;
port->interrupt_out_buffer = kmalloc(buffer_size,
GFP_KERNEL);
if (!port->interrupt_out_buffer)
goto probe_error;
usb_fill_int_urb(port->interrupt_out_urb, dev,
usb_sndintpipe(dev,
endpoint->bEndpointAddress),
port->interrupt_out_buffer, buffer_size,
serial->type->write_int_callback, port,
endpoint->bInterval);
}
} else if (num_interrupt_out) {
dev_dbg(ddev, "The device claims to support interrupt out transfers, but write_int_callback is not defined\n");
}
usb_set_intfdata(interface, serial);
if (type->attach) {
retval = type->attach(serial);
if (retval < 0)
goto probe_error;
serial->attached = 1;
if (retval > 0) {
serial->num_ports = 0;
goto exit;
}
} else {
serial->attached = 1;
}
serial->disconnected = 1;
if (allocate_minors(serial, num_ports)) {
dev_err(ddev, "No more free serial minor numbers\n");
goto probe_error;
}
for (i = 0; i < num_ports; ++i) {
port = serial->port[i];
dev_set_name(&port->dev, "ttyUSB%d", port->minor);
dev_dbg(ddev, "registering %s\n", dev_name(&port->dev));
device_enable_async_suspend(&port->dev);
retval = device_add(&port->dev);
if (retval)
dev_err(ddev, "Error registering port device, continuing\n");
}
serial->disconnected = 0;
usb_serial_console_init(serial->port[0]->minor);
exit:
module_put(type->driver.owner);
return 0;
probe_error:
usb_serial_put(serial);
module_put(type->driver.owner);
return -EIO;
}
static void usb_serial_disconnect(struct usb_interface *interface)
{
int i;
struct usb_serial *serial = usb_get_intfdata(interface);
struct device *dev = &interface->dev;
struct usb_serial_port *port;
struct tty_struct *tty;
usb_serial_console_disconnect(serial);
mutex_lock(&serial->disc_mutex);
serial->disconnected = 1;
mutex_unlock(&serial->disc_mutex);
for (i = 0; i < serial->num_ports; ++i) {
port = serial->port[i];
tty = tty_port_tty_get(&port->port);
if (tty) {
tty_vhangup(tty);
tty_kref_put(tty);
}
usb_serial_port_poison_urbs(port);
wake_up_interruptible(&port->port.delta_msr_wait);
cancel_work_sync(&port->work);
if (device_is_registered(&port->dev))
device_del(&port->dev);
}
if (serial->type->disconnect)
serial->type->disconnect(serial);
usb_serial_put(serial);
dev_info(dev, "device disconnected\n");
}
int usb_serial_suspend(struct usb_interface *intf, pm_message_t message)
{
struct usb_serial *serial = usb_get_intfdata(intf);
int i, r = 0;
serial->suspending = 1;
if (serial->type->suspend) {
r = serial->type->suspend(serial, message);
if (r < 0) {
serial->suspending = 0;
goto err_out;
}
}
for (i = 0; i < serial->num_ports; ++i)
usb_serial_port_poison_urbs(serial->port[i]);
err_out:
return r;
}
static void usb_serial_unpoison_port_urbs(struct usb_serial *serial)
{
int i;
for (i = 0; i < serial->num_ports; ++i)
usb_serial_port_unpoison_urbs(serial->port[i]);
}
int usb_serial_resume(struct usb_interface *intf)
{
struct usb_serial *serial = usb_get_intfdata(intf);
int rv;
usb_serial_unpoison_port_urbs(serial);
serial->suspending = 0;
if (serial->type->resume)
rv = serial->type->resume(serial);
else
rv = usb_serial_generic_resume(serial);
return rv;
}
static int usb_serial_reset_resume(struct usb_interface *intf)
{
struct usb_serial *serial = usb_get_intfdata(intf);
int rv;
usb_serial_unpoison_port_urbs(serial);
serial->suspending = 0;
if (serial->type->reset_resume) {
rv = serial->type->reset_resume(serial);
} else {
rv = -EOPNOTSUPP;
intf->needs_binding = 1;
}
return rv;
}
static int __init usb_serial_init(void)
{
int result;
usb_serial_tty_driver = alloc_tty_driver(USB_SERIAL_TTY_MINORS);
if (!usb_serial_tty_driver)
return -ENOMEM;
result = bus_register(&usb_serial_bus_type);
if (result) {
pr_err("%s - registering bus driver failed\n", __func__);
goto exit_bus;
}
usb_serial_tty_driver->driver_name = "usbserial";
usb_serial_tty_driver->name = "ttyUSB";
usb_serial_tty_driver->major = USB_SERIAL_TTY_MAJOR;
usb_serial_tty_driver->minor_start = 0;
usb_serial_tty_driver->type = TTY_DRIVER_TYPE_SERIAL;
usb_serial_tty_driver->subtype = SERIAL_TYPE_NORMAL;
usb_serial_tty_driver->flags = TTY_DRIVER_REAL_RAW |
TTY_DRIVER_DYNAMIC_DEV;
usb_serial_tty_driver->init_termios = tty_std_termios;
usb_serial_tty_driver->init_termios.c_cflag = B9600 | CS8 | CREAD
| HUPCL | CLOCAL;
usb_serial_tty_driver->init_termios.c_ispeed = 9600;
usb_serial_tty_driver->init_termios.c_ospeed = 9600;
tty_set_operations(usb_serial_tty_driver, &serial_ops);
result = tty_register_driver(usb_serial_tty_driver);
if (result) {
pr_err("%s - tty_register_driver failed\n", __func__);
goto exit_reg_driver;
}
result = usb_register(&usb_serial_driver);
if (result < 0) {
pr_err("%s - usb_register failed\n", __func__);
goto exit_tty;
}
result = usb_serial_generic_register();
if (result < 0) {
pr_err("%s - registering generic driver failed\n", __func__);
goto exit_generic;
}
return result;
exit_generic:
usb_deregister(&usb_serial_driver);
exit_tty:
tty_unregister_driver(usb_serial_tty_driver);
exit_reg_driver:
bus_unregister(&usb_serial_bus_type);
exit_bus:
pr_err("%s - returning with error %d\n", __func__, result);
put_tty_driver(usb_serial_tty_driver);
return result;
}
static void __exit usb_serial_exit(void)
{
usb_serial_console_exit();
usb_serial_generic_deregister();
usb_deregister(&usb_serial_driver);
tty_unregister_driver(usb_serial_tty_driver);
put_tty_driver(usb_serial_tty_driver);
bus_unregister(&usb_serial_bus_type);
}
static void usb_serial_operations_init(struct usb_serial_driver *device)
{
set_to_generic_if_null(device, open);
set_to_generic_if_null(device, write);
set_to_generic_if_null(device, close);
set_to_generic_if_null(device, write_room);
set_to_generic_if_null(device, chars_in_buffer);
if (device->tx_empty)
set_to_generic_if_null(device, wait_until_sent);
set_to_generic_if_null(device, read_bulk_callback);
set_to_generic_if_null(device, write_bulk_callback);
set_to_generic_if_null(device, process_read_urb);
set_to_generic_if_null(device, prepare_write_buffer);
}
static int usb_serial_register(struct usb_serial_driver *driver)
{
int retval;
if (usb_disabled())
return -ENODEV;
if (!driver->description)
driver->description = driver->driver.name;
if (!driver->usb_driver) {
WARN(1, "Serial driver %s has no usb_driver\n",
driver->description);
return -EINVAL;
}
usb_serial_operations_init(driver);
mutex_lock(&table_lock);
list_add(&driver->driver_list, &usb_serial_driver_list);
retval = usb_serial_bus_register(driver);
if (retval) {
pr_err("problem %d when registering driver %s\n", retval, driver->description);
list_del(&driver->driver_list);
} else {
pr_info("USB Serial support registered for %s\n", driver->description);
}
mutex_unlock(&table_lock);
return retval;
}
static void usb_serial_deregister(struct usb_serial_driver *device)
{
pr_info("USB Serial deregistering driver %s\n", device->description);
mutex_lock(&table_lock);
list_del(&device->driver_list);
mutex_unlock(&table_lock);
usb_serial_bus_deregister(device);
}
int usb_serial_register_drivers(struct usb_serial_driver *const serial_drivers[],
const char *name,
const struct usb_device_id *id_table)
{
int rc;
struct usb_driver *udriver;
struct usb_serial_driver * const *sd;
udriver = kzalloc(sizeof(*udriver), GFP_KERNEL);
if (!udriver)
return -ENOMEM;
udriver->name = name;
udriver->no_dynamic_id = 1;
udriver->supports_autosuspend = 1;
udriver->suspend = usb_serial_suspend;
udriver->resume = usb_serial_resume;
udriver->probe = usb_serial_probe;
udriver->disconnect = usb_serial_disconnect;
for (sd = serial_drivers; *sd; ++sd) {
if ((*sd)->reset_resume) {
udriver->reset_resume = usb_serial_reset_resume;
break;
}
}
rc = usb_register(udriver);
if (rc)
return rc;
for (sd = serial_drivers; *sd; ++sd) {
(*sd)->usb_driver = udriver;
rc = usb_serial_register(*sd);
if (rc)
goto failed;
}
udriver->id_table = id_table;
rc = driver_attach(&udriver->drvwrap.driver);
return 0;
failed:
while (sd-- > serial_drivers)
usb_serial_deregister(*sd);
usb_deregister(udriver);
return rc;
}
void usb_serial_deregister_drivers(struct usb_serial_driver *const serial_drivers[])
{
struct usb_driver *udriver = (*serial_drivers)->usb_driver;
for (; *serial_drivers; ++serial_drivers)
usb_serial_deregister(*serial_drivers);
usb_deregister(udriver);
kfree(udriver);
}
