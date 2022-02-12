static int visor_open(struct tty_struct *tty, struct usb_serial_port *port)
{
int result = 0;
if (!port->read_urb) {
dev_err(&port->dev, "Device lied about number of ports, please use a lower one.\n");
return -ENODEV;
}
result = usb_serial_generic_open(tty, port);
if (result)
goto exit;
if (port->interrupt_in_urb) {
dev_dbg(&port->dev, "adding interrupt input for treo\n");
result = usb_submit_urb(port->interrupt_in_urb, GFP_KERNEL);
if (result)
dev_err(&port->dev,
"%s - failed submitting interrupt urb, error %d\n",
__func__, result);
}
exit:
return result;
}
static void visor_close(struct usb_serial_port *port)
{
unsigned char *transfer_buffer;
usb_serial_generic_close(port);
usb_kill_urb(port->interrupt_in_urb);
transfer_buffer = kmalloc(0x12, GFP_KERNEL);
if (!transfer_buffer)
return;
usb_control_msg(port->serial->dev,
usb_rcvctrlpipe(port->serial->dev, 0),
VISOR_CLOSE_NOTIFICATION, 0xc2,
0x0000, 0x0000,
transfer_buffer, 0x12, 300);
kfree(transfer_buffer);
}
static void visor_read_int_callback(struct urb *urb)
{
struct usb_serial_port *port = urb->context;
int status = urb->status;
int result;
switch (status) {
case 0:
break;
case -ECONNRESET:
case -ENOENT:
case -ESHUTDOWN:
dev_dbg(&port->dev, "%s - urb shutting down with status: %d\n",
__func__, status);
return;
default:
dev_dbg(&port->dev, "%s - nonzero urb status received: %d\n",
__func__, status);
goto exit;
}
usb_serial_debug_data(&port->dev, __func__, urb->actual_length,
urb->transfer_buffer);
exit:
result = usb_submit_urb(urb, GFP_ATOMIC);
if (result)
dev_err(&urb->dev->dev,
"%s - Error %d submitting interrupt urb\n",
__func__, result);
}
static int palm_os_3_probe(struct usb_serial *serial,
const struct usb_device_id *id)
{
struct device *dev = &serial->dev->dev;
struct visor_connection_info *connection_info;
unsigned char *transfer_buffer;
char *string;
int retval = 0;
int i;
int num_ports = 0;
transfer_buffer = kmalloc(sizeof(*connection_info), GFP_KERNEL);
if (!transfer_buffer)
return -ENOMEM;
retval = usb_control_msg(serial->dev,
usb_rcvctrlpipe(serial->dev, 0),
VISOR_GET_CONNECTION_INFORMATION,
0xc2, 0x0000, 0x0000, transfer_buffer,
sizeof(*connection_info), 300);
if (retval < 0) {
dev_err(dev, "%s - error %d getting connection information\n",
__func__, retval);
goto exit;
}
if (retval == sizeof(*connection_info)) {
connection_info = (struct visor_connection_info *)
transfer_buffer;
num_ports = le16_to_cpu(connection_info->num_ports);
for (i = 0; i < num_ports; ++i) {
switch (
connection_info->connections[i].port_function_id) {
case VISOR_FUNCTION_GENERIC:
string = "Generic";
break;
case VISOR_FUNCTION_DEBUGGER:
string = "Debugger";
break;
case VISOR_FUNCTION_HOTSYNC:
string = "HotSync";
break;
case VISOR_FUNCTION_CONSOLE:
string = "Console";
break;
case VISOR_FUNCTION_REMOTE_FILE_SYS:
string = "Remote File System";
break;
default:
string = "unknown";
break;
}
dev_info(dev, "%s: port %d, is for %s use\n",
serial->type->description,
connection_info->connections[i].port, string);
}
}
if (num_ports == 0 || num_ports > 2) {
dev_warn(dev, "%s: No valid connect info available\n",
serial->type->description);
num_ports = 2;
}
dev_info(dev, "%s: Number of ports: %d\n", serial->type->description,
num_ports);
usb_set_serial_data(serial, (void *)(long)num_ports);
retval = usb_control_msg(serial->dev,
usb_rcvctrlpipe(serial->dev, 0),
VISOR_REQUEST_BYTES_AVAILABLE,
0xc2, 0x0000, 0x0005, transfer_buffer,
0x02, 300);
if (retval < 0)
dev_err(dev, "%s - error %d getting bytes available request\n",
__func__, retval);
retval = 0;
exit:
kfree(transfer_buffer);
return retval;
}
static int palm_os_4_probe(struct usb_serial *serial,
const struct usb_device_id *id)
{
struct device *dev = &serial->dev->dev;
struct palm_ext_connection_info *connection_info;
unsigned char *transfer_buffer;
int retval;
transfer_buffer = kmalloc(sizeof(*connection_info), GFP_KERNEL);
if (!transfer_buffer)
return -ENOMEM;
retval = usb_control_msg(serial->dev,
usb_rcvctrlpipe(serial->dev, 0),
PALM_GET_EXT_CONNECTION_INFORMATION,
0xc2, 0x0000, 0x0000, transfer_buffer,
sizeof(*connection_info), 300);
if (retval < 0)
dev_err(dev, "%s - error %d getting connection info\n",
__func__, retval);
else
usb_serial_debug_data(dev, __func__, retval, transfer_buffer);
kfree(transfer_buffer);
return 0;
}
static int visor_probe(struct usb_serial *serial,
const struct usb_device_id *id)
{
int retval = 0;
int (*startup)(struct usb_serial *serial,
const struct usb_device_id *id);
if (id->idVendor == SAMSUNG_VENDOR_ID &&
id->idProduct == SAMSUNG_SPH_I500_ID &&
serial->dev->descriptor.bDeviceClass == USB_CLASS_COMM &&
serial->dev->descriptor.bDeviceSubClass ==
USB_CDC_SUBCLASS_ACM)
return -ENODEV;
if (serial->dev->actconfig->desc.bConfigurationValue != 1) {
dev_err(&serial->dev->dev, "active config #%d != 1 ??\n",
serial->dev->actconfig->desc.bConfigurationValue);
return -ENODEV;
}
if (id->driver_info) {
startup = (void *)id->driver_info;
retval = startup(serial, id);
}
return retval;
}
static int visor_calc_num_ports(struct usb_serial *serial,
struct usb_serial_endpoints *epds)
{
unsigned int vid = le16_to_cpu(serial->dev->descriptor.idVendor);
int num_ports = (int)(long)(usb_get_serial_data(serial));
if (num_ports)
usb_set_serial_data(serial, NULL);
if (!(vid == HANDSPRING_VENDOR_ID || vid == KYOCERA_VENDOR_ID) ||
epds->num_interrupt_in == 0)
goto out;
if (epds->num_bulk_in < 2 || epds->num_interrupt_in < 2) {
dev_err(&serial->interface->dev, "missing endpoints\n");
return -ENODEV;
}
swap(epds->bulk_in[0], epds->bulk_in[1]);
swap(epds->interrupt_in[0], epds->interrupt_in[1]);
out:
return num_ports;
}
static int clie_5_calc_num_ports(struct usb_serial *serial,
struct usb_serial_endpoints *epds)
{
epds->bulk_out[0] = epds->bulk_out[1];
return serial->type->num_ports;
}
static int clie_3_5_startup(struct usb_serial *serial)
{
struct device *dev = &serial->dev->dev;
int result;
u8 *data;
data = kmalloc(1, GFP_KERNEL);
if (!data)
return -ENOMEM;
result = usb_control_msg(serial->dev, usb_rcvctrlpipe(serial->dev, 0),
USB_REQ_GET_CONFIGURATION, USB_DIR_IN,
0, 0, data, 1, 3000);
if (result < 0) {
dev_err(dev, "%s: get config number failed: %d\n",
__func__, result);
goto out;
}
if (result != 1) {
dev_err(dev, "%s: get config number bad return length: %d\n",
__func__, result);
result = -EIO;
goto out;
}
result = usb_control_msg(serial->dev, usb_rcvctrlpipe(serial->dev, 0),
USB_REQ_GET_INTERFACE,
USB_DIR_IN | USB_RECIP_INTERFACE,
0, 0, data, 1, 3000);
if (result < 0) {
dev_err(dev, "%s: get interface number failed: %d\n",
__func__, result);
goto out;
}
if (result != 1) {
dev_err(dev,
"%s: get interface number bad return length: %d\n",
__func__, result);
result = -EIO;
goto out;
}
result = 0;
out:
kfree(data);
return result;
}
