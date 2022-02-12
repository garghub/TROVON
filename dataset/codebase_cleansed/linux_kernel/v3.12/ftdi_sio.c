static unsigned short int ftdi_232am_baud_base_to_divisor(int baud, int base)
{
unsigned short int divisor;
int divisor3 = base / 2 / baud;
if ((divisor3 & 0x7) == 7)
divisor3++;
divisor = divisor3 >> 3;
divisor3 &= 0x7;
if (divisor3 == 1)
divisor |= 0xc000;
else if (divisor3 >= 4)
divisor |= 0x4000;
else if (divisor3 != 0)
divisor |= 0x8000;
else if (divisor == 1)
divisor = 0;
return divisor;
}
static unsigned short int ftdi_232am_baud_to_divisor(int baud)
{
return ftdi_232am_baud_base_to_divisor(baud, 48000000);
}
static __u32 ftdi_232bm_baud_base_to_divisor(int baud, int base)
{
static const unsigned char divfrac[8] = { 0, 3, 2, 4, 1, 5, 6, 7 };
__u32 divisor;
int divisor3 = base / 2 / baud;
divisor = divisor3 >> 3;
divisor |= (__u32)divfrac[divisor3 & 0x7] << 14;
if (divisor == 1)
divisor = 0;
else if (divisor == 0x4001)
divisor = 1;
return divisor;
}
static __u32 ftdi_232bm_baud_to_divisor(int baud)
{
return ftdi_232bm_baud_base_to_divisor(baud, 48000000);
}
static __u32 ftdi_2232h_baud_base_to_divisor(int baud, int base)
{
static const unsigned char divfrac[8] = { 0, 3, 2, 4, 1, 5, 6, 7 };
__u32 divisor;
int divisor3;
divisor3 = base * 8 / (baud * 10);
divisor = divisor3 >> 3;
divisor |= (__u32)divfrac[divisor3 & 0x7] << 14;
if (divisor == 1)
divisor = 0;
else if (divisor == 0x4001)
divisor = 1;
divisor |= 0x00020000;
return divisor;
}
static __u32 ftdi_2232h_baud_to_divisor(int baud)
{
return ftdi_2232h_baud_base_to_divisor(baud, 120000000);
}
static int update_mctrl(struct usb_serial_port *port, unsigned int set,
unsigned int clear)
{
struct ftdi_private *priv = usb_get_serial_port_data(port);
struct device *dev = &port->dev;
unsigned urb_value;
int rv;
if (((set | clear) & (TIOCM_DTR | TIOCM_RTS)) == 0) {
dev_dbg(dev, "%s - DTR|RTS not being set|cleared\n", __func__);
return 0;
}
clear &= ~set;
urb_value = 0;
if (clear & TIOCM_DTR)
urb_value |= FTDI_SIO_SET_DTR_LOW;
if (clear & TIOCM_RTS)
urb_value |= FTDI_SIO_SET_RTS_LOW;
if (set & TIOCM_DTR)
urb_value |= FTDI_SIO_SET_DTR_HIGH;
if (set & TIOCM_RTS)
urb_value |= FTDI_SIO_SET_RTS_HIGH;
rv = usb_control_msg(port->serial->dev,
usb_sndctrlpipe(port->serial->dev, 0),
FTDI_SIO_SET_MODEM_CTRL_REQUEST,
FTDI_SIO_SET_MODEM_CTRL_REQUEST_TYPE,
urb_value, priv->interface,
NULL, 0, WDR_TIMEOUT);
if (rv < 0) {
dev_dbg(dev, "%s Error from MODEM_CTRL urb: DTR %s, RTS %s\n",
__func__,
(set & TIOCM_DTR) ? "HIGH" : (clear & TIOCM_DTR) ? "LOW" : "unchanged",
(set & TIOCM_RTS) ? "HIGH" : (clear & TIOCM_RTS) ? "LOW" : "unchanged");
rv = usb_translate_errors(rv);
} else {
dev_dbg(dev, "%s - DTR %s, RTS %s\n", __func__,
(set & TIOCM_DTR) ? "HIGH" : (clear & TIOCM_DTR) ? "LOW" : "unchanged",
(set & TIOCM_RTS) ? "HIGH" : (clear & TIOCM_RTS) ? "LOW" : "unchanged");
priv->last_dtr_rts = (priv->last_dtr_rts & ~clear) | set;
}
return rv;
}
static __u32 get_ftdi_divisor(struct tty_struct *tty,
struct usb_serial_port *port)
{
struct ftdi_private *priv = usb_get_serial_port_data(port);
struct device *dev = &port->dev;
__u32 div_value = 0;
int div_okay = 1;
int baud;
baud = tty_get_baud_rate(tty);
dev_dbg(dev, "%s - tty_get_baud_rate reports speed %d\n", __func__, baud);
if (baud == 38400 &&
((priv->flags & ASYNC_SPD_MASK) == ASYNC_SPD_CUST) &&
(priv->custom_divisor)) {
baud = priv->baud_base / priv->custom_divisor;
dev_dbg(dev, "%s - custom divisor %d sets baud rate to %d\n",
__func__, priv->custom_divisor, baud);
}
if (!baud)
baud = 9600;
switch (priv->chip_type) {
case SIO:
switch (baud) {
case 300: div_value = ftdi_sio_b300; break;
case 600: div_value = ftdi_sio_b600; break;
case 1200: div_value = ftdi_sio_b1200; break;
case 2400: div_value = ftdi_sio_b2400; break;
case 4800: div_value = ftdi_sio_b4800; break;
case 9600: div_value = ftdi_sio_b9600; break;
case 19200: div_value = ftdi_sio_b19200; break;
case 38400: div_value = ftdi_sio_b38400; break;
case 57600: div_value = ftdi_sio_b57600; break;
case 115200: div_value = ftdi_sio_b115200; break;
}
if (div_value == 0) {
dev_dbg(dev, "%s - Baudrate (%d) requested is not supported\n",
__func__, baud);
div_value = ftdi_sio_b9600;
baud = 9600;
div_okay = 0;
}
break;
case FT8U232AM:
if (baud <= 3000000) {
div_value = ftdi_232am_baud_to_divisor(baud);
} else {
dev_dbg(dev, "%s - Baud rate too high!\n", __func__);
baud = 9600;
div_value = ftdi_232am_baud_to_divisor(9600);
div_okay = 0;
}
break;
case FT232BM:
case FT2232C:
case FT232RL:
case FTX:
if (baud <= 3000000) {
__u16 product_id = le16_to_cpu(
port->serial->dev->descriptor.idProduct);
if (((FTDI_NDI_HUC_PID == product_id) ||
(FTDI_NDI_SPECTRA_SCU_PID == product_id) ||
(FTDI_NDI_FUTURE_2_PID == product_id) ||
(FTDI_NDI_FUTURE_3_PID == product_id) ||
(FTDI_NDI_AURORA_SCU_PID == product_id)) &&
(baud == 19200)) {
baud = 1200000;
}
div_value = ftdi_232bm_baud_to_divisor(baud);
} else {
dev_dbg(dev, "%s - Baud rate too high!\n", __func__);
div_value = ftdi_232bm_baud_to_divisor(9600);
div_okay = 0;
baud = 9600;
}
break;
case FT2232H:
case FT4232H:
case FT232H:
if ((baud <= 12000000) && (baud >= 1200)) {
div_value = ftdi_2232h_baud_to_divisor(baud);
} else if (baud < 1200) {
div_value = ftdi_232bm_baud_to_divisor(baud);
} else {
dev_dbg(dev, "%s - Baud rate too high!\n", __func__);
div_value = ftdi_232bm_baud_to_divisor(9600);
div_okay = 0;
baud = 9600;
}
break;
}
if (div_okay) {
dev_dbg(dev, "%s - Baud rate set to %d (divisor 0x%lX) on chip %s\n",
__func__, baud, (unsigned long)div_value,
ftdi_chip_name[priv->chip_type]);
}
tty_encode_baud_rate(tty, baud, baud);
return div_value;
}
static int change_speed(struct tty_struct *tty, struct usb_serial_port *port)
{
struct ftdi_private *priv = usb_get_serial_port_data(port);
__u16 urb_value;
__u16 urb_index;
__u32 urb_index_value;
int rv;
urb_index_value = get_ftdi_divisor(tty, port);
urb_value = (__u16)urb_index_value;
urb_index = (__u16)(urb_index_value >> 16);
if ((priv->chip_type == FT2232C) || (priv->chip_type == FT2232H) ||
(priv->chip_type == FT4232H) || (priv->chip_type == FT232H)) {
urb_index = (__u16)((urb_index << 8) | priv->interface);
}
rv = usb_control_msg(port->serial->dev,
usb_sndctrlpipe(port->serial->dev, 0),
FTDI_SIO_SET_BAUDRATE_REQUEST,
FTDI_SIO_SET_BAUDRATE_REQUEST_TYPE,
urb_value, urb_index,
NULL, 0, WDR_SHORT_TIMEOUT);
return rv;
}
static int write_latency_timer(struct usb_serial_port *port)
{
struct ftdi_private *priv = usb_get_serial_port_data(port);
struct usb_device *udev = port->serial->dev;
int rv;
int l = priv->latency;
if (priv->flags & ASYNC_LOW_LATENCY)
l = 1;
dev_dbg(&port->dev, "%s: setting latency timer = %i\n", __func__, l);
rv = usb_control_msg(udev,
usb_sndctrlpipe(udev, 0),
FTDI_SIO_SET_LATENCY_TIMER_REQUEST,
FTDI_SIO_SET_LATENCY_TIMER_REQUEST_TYPE,
l, priv->interface,
NULL, 0, WDR_TIMEOUT);
if (rv < 0)
dev_err(&port->dev, "Unable to write latency timer: %i\n", rv);
return rv;
}
static int read_latency_timer(struct usb_serial_port *port)
{
struct ftdi_private *priv = usb_get_serial_port_data(port);
struct usb_device *udev = port->serial->dev;
unsigned char *buf;
int rv;
buf = kmalloc(1, GFP_KERNEL);
if (!buf)
return -ENOMEM;
rv = usb_control_msg(udev,
usb_rcvctrlpipe(udev, 0),
FTDI_SIO_GET_LATENCY_TIMER_REQUEST,
FTDI_SIO_GET_LATENCY_TIMER_REQUEST_TYPE,
0, priv->interface,
buf, 1, WDR_TIMEOUT);
if (rv < 0)
dev_err(&port->dev, "Unable to read latency timer: %i\n", rv);
else
priv->latency = buf[0];
kfree(buf);
return rv;
}
static int get_serial_info(struct usb_serial_port *port,
struct serial_struct __user *retinfo)
{
struct ftdi_private *priv = usb_get_serial_port_data(port);
struct serial_struct tmp;
if (!retinfo)
return -EFAULT;
memset(&tmp, 0, sizeof(tmp));
tmp.flags = priv->flags;
tmp.baud_base = priv->baud_base;
tmp.custom_divisor = priv->custom_divisor;
if (copy_to_user(retinfo, &tmp, sizeof(*retinfo)))
return -EFAULT;
return 0;
}
static int set_serial_info(struct tty_struct *tty,
struct usb_serial_port *port, struct serial_struct __user *newinfo)
{
struct ftdi_private *priv = usb_get_serial_port_data(port);
struct serial_struct new_serial;
struct ftdi_private old_priv;
if (copy_from_user(&new_serial, newinfo, sizeof(new_serial)))
return -EFAULT;
mutex_lock(&priv->cfg_lock);
old_priv = *priv;
if (!capable(CAP_SYS_ADMIN)) {
if (((new_serial.flags & ~ASYNC_USR_MASK) !=
(priv->flags & ~ASYNC_USR_MASK))) {
mutex_unlock(&priv->cfg_lock);
return -EPERM;
}
priv->flags = ((priv->flags & ~ASYNC_USR_MASK) |
(new_serial.flags & ASYNC_USR_MASK));
priv->custom_divisor = new_serial.custom_divisor;
goto check_and_exit;
}
if (new_serial.baud_base != priv->baud_base) {
mutex_unlock(&priv->cfg_lock);
return -EINVAL;
}
priv->flags = ((priv->flags & ~ASYNC_FLAGS) |
(new_serial.flags & ASYNC_FLAGS));
priv->custom_divisor = new_serial.custom_divisor;
write_latency_timer(port);
check_and_exit:
if ((old_priv.flags & ASYNC_SPD_MASK) !=
(priv->flags & ASYNC_SPD_MASK)) {
if ((priv->flags & ASYNC_SPD_MASK) == ASYNC_SPD_HI)
tty->alt_speed = 57600;
else if ((priv->flags & ASYNC_SPD_MASK) == ASYNC_SPD_VHI)
tty->alt_speed = 115200;
else if ((priv->flags & ASYNC_SPD_MASK) == ASYNC_SPD_SHI)
tty->alt_speed = 230400;
else if ((priv->flags & ASYNC_SPD_MASK) == ASYNC_SPD_WARP)
tty->alt_speed = 460800;
else
tty->alt_speed = 0;
}
if (((old_priv.flags & ASYNC_SPD_MASK) !=
(priv->flags & ASYNC_SPD_MASK)) ||
(((priv->flags & ASYNC_SPD_MASK) == ASYNC_SPD_CUST) &&
(old_priv.custom_divisor != priv->custom_divisor))) {
change_speed(tty, port);
mutex_unlock(&priv->cfg_lock);
}
else
mutex_unlock(&priv->cfg_lock);
return 0;
}
static int get_lsr_info(struct usb_serial_port *port,
struct serial_struct __user *retinfo)
{
struct ftdi_private *priv = usb_get_serial_port_data(port);
unsigned int result = 0;
if (!retinfo)
return -EFAULT;
if (priv->transmit_empty)
result = TIOCSER_TEMT;
if (copy_to_user(retinfo, &result, sizeof(unsigned int)))
return -EFAULT;
return 0;
}
static void ftdi_determine_type(struct usb_serial_port *port)
{
struct ftdi_private *priv = usb_get_serial_port_data(port);
struct usb_serial *serial = port->serial;
struct usb_device *udev = serial->dev;
unsigned version;
unsigned interfaces;
priv->baud_base = 48000000 / 2;
version = le16_to_cpu(udev->descriptor.bcdDevice);
interfaces = udev->actconfig->desc.bNumInterfaces;
dev_dbg(&port->dev, "%s: bcdDevice = 0x%x, bNumInterfaces = %u\n", __func__,
version, interfaces);
if (interfaces > 1) {
int inter;
if (version == 0x0800) {
priv->chip_type = FT4232H;
priv->baud_base = 120000000 / 2;
} else if (version == 0x0700) {
priv->chip_type = FT2232H;
priv->baud_base = 120000000 / 2;
} else
priv->chip_type = FT2232C;
inter = serial->interface->altsetting->desc.bInterfaceNumber;
if (inter == 0) {
priv->interface = INTERFACE_A;
} else if (inter == 1) {
priv->interface = INTERFACE_B;
} else if (inter == 2) {
priv->interface = INTERFACE_C;
} else if (inter == 3) {
priv->interface = INTERFACE_D;
}
if (version < 0x500) {
dev_dbg(&port->dev,
"%s: something fishy - bcdDevice too low for multi-interface device\n",
__func__);
}
} else if (version < 0x200) {
priv->chip_type = SIO;
priv->baud_base = 12000000 / 16;
} else if (version < 0x400) {
priv->chip_type = FT8U232AM;
} else if (version < 0x600) {
priv->chip_type = FT232BM;
} else if (version < 0x900) {
priv->chip_type = FT232RL;
} else if (version < 0x1000) {
priv->chip_type = FT232H;
} else {
priv->chip_type = FTX;
}
dev_info(&udev->dev, "Detected %s\n", ftdi_chip_name[priv->chip_type]);
}
static void ftdi_set_max_packet_size(struct usb_serial_port *port)
{
struct ftdi_private *priv = usb_get_serial_port_data(port);
struct usb_serial *serial = port->serial;
struct usb_device *udev = serial->dev;
struct usb_interface *interface = serial->interface;
struct usb_endpoint_descriptor *ep_desc = &interface->cur_altsetting->endpoint[1].desc;
unsigned num_endpoints;
int i;
num_endpoints = interface->cur_altsetting->desc.bNumEndpoints;
dev_info(&udev->dev, "Number of endpoints %d\n", num_endpoints);
for (i = 0; i < num_endpoints; i++) {
dev_info(&udev->dev, "Endpoint %d MaxPacketSize %d\n", i+1,
interface->cur_altsetting->endpoint[i].desc.wMaxPacketSize);
ep_desc = &interface->cur_altsetting->endpoint[i].desc;
if (ep_desc->wMaxPacketSize == 0) {
ep_desc->wMaxPacketSize = cpu_to_le16(0x40);
dev_info(&udev->dev, "Overriding wMaxPacketSize on endpoint %d\n", i);
}
}
priv->max_packet_size = usb_endpoint_maxp(ep_desc);
dev_info(&udev->dev, "Setting MaxPacketSize %d\n", priv->max_packet_size);
}
static ssize_t latency_timer_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct usb_serial_port *port = to_usb_serial_port(dev);
struct ftdi_private *priv = usb_get_serial_port_data(port);
if (priv->flags & ASYNC_LOW_LATENCY)
return sprintf(buf, "1\n");
else
return sprintf(buf, "%i\n", priv->latency);
}
static ssize_t latency_timer_store(struct device *dev,
struct device_attribute *attr,
const char *valbuf, size_t count)
{
struct usb_serial_port *port = to_usb_serial_port(dev);
struct ftdi_private *priv = usb_get_serial_port_data(port);
int v = simple_strtoul(valbuf, NULL, 10);
int rv;
priv->latency = v;
rv = write_latency_timer(port);
if (rv < 0)
return -EIO;
return count;
}
static ssize_t store_event_char(struct device *dev,
struct device_attribute *attr, const char *valbuf, size_t count)
{
struct usb_serial_port *port = to_usb_serial_port(dev);
struct ftdi_private *priv = usb_get_serial_port_data(port);
struct usb_device *udev = port->serial->dev;
int v = simple_strtoul(valbuf, NULL, 10);
int rv;
dev_dbg(&port->dev, "%s: setting event char = %i\n", __func__, v);
rv = usb_control_msg(udev,
usb_sndctrlpipe(udev, 0),
FTDI_SIO_SET_EVENT_CHAR_REQUEST,
FTDI_SIO_SET_EVENT_CHAR_REQUEST_TYPE,
v, priv->interface,
NULL, 0, WDR_TIMEOUT);
if (rv < 0) {
dev_dbg(&port->dev, "Unable to write event character: %i\n", rv);
return -EIO;
}
return count;
}
static int create_sysfs_attrs(struct usb_serial_port *port)
{
struct ftdi_private *priv = usb_get_serial_port_data(port);
int retval = 0;
if (priv->chip_type != SIO) {
dev_dbg(&port->dev, "sysfs attributes for %s\n", ftdi_chip_name[priv->chip_type]);
retval = device_create_file(&port->dev, &dev_attr_event_char);
if ((!retval) &&
(priv->chip_type == FT232BM ||
priv->chip_type == FT2232C ||
priv->chip_type == FT232RL ||
priv->chip_type == FT2232H ||
priv->chip_type == FT4232H ||
priv->chip_type == FT232H ||
priv->chip_type == FTX)) {
retval = device_create_file(&port->dev,
&dev_attr_latency_timer);
}
}
return retval;
}
static void remove_sysfs_attrs(struct usb_serial_port *port)
{
struct ftdi_private *priv = usb_get_serial_port_data(port);
if (priv->chip_type != SIO) {
device_remove_file(&port->dev, &dev_attr_event_char);
if (priv->chip_type == FT232BM ||
priv->chip_type == FT2232C ||
priv->chip_type == FT232RL ||
priv->chip_type == FT2232H ||
priv->chip_type == FT4232H ||
priv->chip_type == FT232H ||
priv->chip_type == FTX) {
device_remove_file(&port->dev, &dev_attr_latency_timer);
}
}
}
static int ftdi_sio_probe(struct usb_serial *serial,
const struct usb_device_id *id)
{
struct ftdi_sio_quirk *quirk =
(struct ftdi_sio_quirk *)id->driver_info;
if (quirk && quirk->probe) {
int ret = quirk->probe(serial);
if (ret != 0)
return ret;
}
usb_set_serial_data(serial, (void *)id->driver_info);
return 0;
}
static int ftdi_sio_port_probe(struct usb_serial_port *port)
{
struct ftdi_private *priv;
struct ftdi_sio_quirk *quirk = usb_get_serial_data(port->serial);
priv = kzalloc(sizeof(struct ftdi_private), GFP_KERNEL);
if (!priv) {
dev_err(&port->dev, "%s- kmalloc(%Zd) failed.\n", __func__,
sizeof(struct ftdi_private));
return -ENOMEM;
}
mutex_init(&priv->cfg_lock);
priv->flags = ASYNC_LOW_LATENCY;
if (quirk && quirk->port_probe)
quirk->port_probe(priv);
usb_set_serial_port_data(port, priv);
ftdi_determine_type(port);
ftdi_set_max_packet_size(port);
if (read_latency_timer(port) < 0)
priv->latency = 16;
write_latency_timer(port);
create_sysfs_attrs(port);
return 0;
}
static void ftdi_USB_UIRT_setup(struct ftdi_private *priv)
{
priv->flags |= ASYNC_SPD_CUST;
priv->custom_divisor = 77;
priv->force_baud = 38400;
}
static void ftdi_HE_TIRA1_setup(struct ftdi_private *priv)
{
priv->flags |= ASYNC_SPD_CUST;
priv->custom_divisor = 240;
priv->force_baud = 38400;
priv->force_rtscts = 1;
}
static int ftdi_NDI_device_setup(struct usb_serial *serial)
{
struct usb_device *udev = serial->dev;
int latency = ndi_latency_timer;
if (latency == 0)
latency = 1;
if (latency > 99)
latency = 99;
dev_dbg(&udev->dev, "%s setting NDI device latency to %d\n", __func__, latency);
dev_info(&udev->dev, "NDI device with a latency value of %d\n", latency);
usb_control_msg(udev, usb_sndctrlpipe(udev, 0),
FTDI_SIO_SET_LATENCY_TIMER_REQUEST,
FTDI_SIO_SET_LATENCY_TIMER_REQUEST_TYPE,
latency, 0, NULL, 0, WDR_TIMEOUT);
return 0;
}
static int ftdi_jtag_probe(struct usb_serial *serial)
{
struct usb_device *udev = serial->dev;
struct usb_interface *interface = serial->interface;
if (interface == udev->actconfig->interface[0]) {
dev_info(&udev->dev,
"Ignoring serial port reserved for JTAG\n");
return -ENODEV;
}
return 0;
}
static int ftdi_8u2232c_probe(struct usb_serial *serial)
{
struct usb_device *udev = serial->dev;
if ((udev->manufacturer && !strcmp(udev->manufacturer, "CALAO Systems")) ||
(udev->product && !strcmp(udev->product, "BeagleBone/XDS100V2")))
return ftdi_jtag_probe(serial);
return 0;
}
static int ftdi_stmclite_probe(struct usb_serial *serial)
{
struct usb_device *udev = serial->dev;
struct usb_interface *interface = serial->interface;
if (interface == udev->actconfig->interface[0] ||
interface == udev->actconfig->interface[1]) {
dev_info(&udev->dev, "Ignoring serial port reserved for JTAG\n");
return -ENODEV;
}
return 0;
}
static int ftdi_mtxorb_hack_setup(struct usb_serial *serial)
{
struct usb_host_endpoint *ep = serial->dev->ep_in[1];
struct usb_endpoint_descriptor *ep_desc = &ep->desc;
if (ep->enabled && ep_desc->wMaxPacketSize == 0) {
ep_desc->wMaxPacketSize = cpu_to_le16(0x40);
dev_info(&serial->dev->dev,
"Fixing invalid wMaxPacketSize on read pipe\n");
}
return 0;
}
static int ftdi_sio_port_remove(struct usb_serial_port *port)
{
struct ftdi_private *priv = usb_get_serial_port_data(port);
remove_sysfs_attrs(port);
kfree(priv);
return 0;
}
static int ftdi_open(struct tty_struct *tty, struct usb_serial_port *port)
{
struct usb_device *dev = port->serial->dev;
struct ftdi_private *priv = usb_get_serial_port_data(port);
usb_control_msg(dev, usb_sndctrlpipe(dev, 0),
FTDI_SIO_RESET_REQUEST, FTDI_SIO_RESET_REQUEST_TYPE,
FTDI_SIO_RESET_SIO,
priv->interface, NULL, 0, WDR_TIMEOUT);
if (tty)
ftdi_set_termios(tty, port, NULL);
return usb_serial_generic_open(tty, port);
}
static void ftdi_dtr_rts(struct usb_serial_port *port, int on)
{
struct ftdi_private *priv = usb_get_serial_port_data(port);
if (!on) {
if (usb_control_msg(port->serial->dev,
usb_sndctrlpipe(port->serial->dev, 0),
FTDI_SIO_SET_FLOW_CTRL_REQUEST,
FTDI_SIO_SET_FLOW_CTRL_REQUEST_TYPE,
0, priv->interface, NULL, 0,
WDR_TIMEOUT) < 0) {
dev_err(&port->dev, "error from flowcontrol urb\n");
}
}
if (on)
set_mctrl(port, TIOCM_DTR | TIOCM_RTS);
else
clear_mctrl(port, TIOCM_DTR | TIOCM_RTS);
}
static int ftdi_prepare_write_buffer(struct usb_serial_port *port,
void *dest, size_t size)
{
struct ftdi_private *priv;
int count;
unsigned long flags;
priv = usb_get_serial_port_data(port);
if (priv->chip_type == SIO) {
unsigned char *buffer = dest;
int i, len, c;
count = 0;
spin_lock_irqsave(&port->lock, flags);
for (i = 0; i < size - 1; i += priv->max_packet_size) {
len = min_t(int, size - i, priv->max_packet_size) - 1;
c = kfifo_out(&port->write_fifo, &buffer[i + 1], len);
if (!c)
break;
port->icount.tx += c;
buffer[i] = (c << 2) + 1;
count += c + 1;
}
spin_unlock_irqrestore(&port->lock, flags);
} else {
count = kfifo_out_locked(&port->write_fifo, dest, size,
&port->lock);
port->icount.tx += count;
}
return count;
}
static int ftdi_process_packet(struct usb_serial_port *port,
struct ftdi_private *priv, char *packet, int len)
{
int i;
char status;
char flag;
char *ch;
if (len < 2) {
dev_dbg(&port->dev, "malformed packet\n");
return 0;
}
status = packet[0] & FTDI_STATUS_B0_MASK;
if (status != priv->prev_status) {
char diff_status = status ^ priv->prev_status;
if (diff_status & FTDI_RS0_CTS)
port->icount.cts++;
if (diff_status & FTDI_RS0_DSR)
port->icount.dsr++;
if (diff_status & FTDI_RS0_RI)
port->icount.rng++;
if (diff_status & FTDI_RS0_RLSD)
port->icount.dcd++;
wake_up_interruptible(&port->port.delta_msr_wait);
priv->prev_status = status;
}
flag = TTY_NORMAL;
if (packet[1] & FTDI_RS_ERR_MASK) {
if (packet[1] & FTDI_RS_BI) {
flag = TTY_BREAK;
port->icount.brk++;
usb_serial_handle_break(port);
} else if (packet[1] & FTDI_RS_PE) {
flag = TTY_PARITY;
port->icount.parity++;
} else if (packet[1] & FTDI_RS_FE) {
flag = TTY_FRAME;
port->icount.frame++;
}
if (packet[1] & FTDI_RS_OE) {
port->icount.overrun++;
tty_insert_flip_char(&port->port, 0, TTY_OVERRUN);
}
}
if (packet[1] & FTDI_RS_TEMT)
priv->transmit_empty = 1;
else
priv->transmit_empty = 0;
len -= 2;
if (!len)
return 0;
port->icount.rx += len;
ch = packet + 2;
if (port->port.console && port->sysrq) {
for (i = 0; i < len; i++, ch++) {
if (!usb_serial_handle_sysrq_char(port, *ch))
tty_insert_flip_char(&port->port, *ch, flag);
}
} else {
tty_insert_flip_string_fixed_flag(&port->port, ch, flag, len);
}
return len;
}
static void ftdi_process_read_urb(struct urb *urb)
{
struct usb_serial_port *port = urb->context;
struct ftdi_private *priv = usb_get_serial_port_data(port);
char *data = (char *)urb->transfer_buffer;
int i;
int len;
int count = 0;
for (i = 0; i < urb->actual_length; i += priv->max_packet_size) {
len = min_t(int, urb->actual_length - i, priv->max_packet_size);
count += ftdi_process_packet(port, priv, &data[i], len);
}
if (count)
tty_flip_buffer_push(&port->port);
}
static void ftdi_break_ctl(struct tty_struct *tty, int break_state)
{
struct usb_serial_port *port = tty->driver_data;
struct ftdi_private *priv = usb_get_serial_port_data(port);
__u16 urb_value;
if (break_state)
urb_value = priv->last_set_data_urb_value | FTDI_SIO_SET_BREAK;
else
urb_value = priv->last_set_data_urb_value;
if (usb_control_msg(port->serial->dev,
usb_sndctrlpipe(port->serial->dev, 0),
FTDI_SIO_SET_DATA_REQUEST,
FTDI_SIO_SET_DATA_REQUEST_TYPE,
urb_value , priv->interface,
NULL, 0, WDR_TIMEOUT) < 0) {
dev_err(&port->dev, "%s FAILED to enable/disable break state (state was %d)\n",
__func__, break_state);
}
dev_dbg(&port->dev, "%s break state is %d - urb is %d\n", __func__,
break_state, urb_value);
}
static bool ftdi_tx_empty(struct usb_serial_port *port)
{
unsigned char buf[2];
int ret;
ret = ftdi_get_modem_status(port, buf);
if (ret == 2) {
if (!(buf[1] & FTDI_RS_TEMT))
return false;
}
return true;
}
static void ftdi_set_termios(struct tty_struct *tty,
struct usb_serial_port *port, struct ktermios *old_termios)
{
struct usb_device *dev = port->serial->dev;
struct device *ddev = &port->dev;
struct ftdi_private *priv = usb_get_serial_port_data(port);
struct ktermios *termios = &tty->termios;
unsigned int cflag = termios->c_cflag;
__u16 urb_value;
unsigned int iflag = termios->c_iflag;
unsigned char vstop;
unsigned char vstart;
if (priv->force_baud && ((termios->c_cflag & CBAUD) != B0)) {
dev_dbg(ddev, "%s: forcing baud rate for this device\n", __func__);
tty_encode_baud_rate(tty, priv->force_baud,
priv->force_baud);
}
if (priv->force_rtscts) {
dev_dbg(ddev, "%s: forcing rtscts for this device\n", __func__);
termios->c_cflag |= CRTSCTS;
}
cflag = termios->c_cflag;
if (!old_termios)
goto no_skip;
if (old_termios->c_cflag == termios->c_cflag
&& old_termios->c_ispeed == termios->c_ispeed
&& old_termios->c_ospeed == termios->c_ospeed)
goto no_c_cflag_changes;
if ((old_termios->c_cflag & (CSIZE|PARODD|PARENB|CMSPAR|CSTOPB)) ==
(termios->c_cflag & (CSIZE|PARODD|PARENB|CMSPAR|CSTOPB)))
goto no_data_parity_stop_changes;
no_skip:
urb_value = 0;
urb_value |= (cflag & CSTOPB ? FTDI_SIO_SET_DATA_STOP_BITS_2 :
FTDI_SIO_SET_DATA_STOP_BITS_1);
if (cflag & PARENB) {
if (cflag & CMSPAR)
urb_value |= cflag & PARODD ?
FTDI_SIO_SET_DATA_PARITY_MARK :
FTDI_SIO_SET_DATA_PARITY_SPACE;
else
urb_value |= cflag & PARODD ?
FTDI_SIO_SET_DATA_PARITY_ODD :
FTDI_SIO_SET_DATA_PARITY_EVEN;
} else {
urb_value |= FTDI_SIO_SET_DATA_PARITY_NONE;
}
if (cflag & CSIZE) {
switch (cflag & CSIZE) {
case CS7:
urb_value |= 7;
dev_dbg(ddev, "Setting CS7\n");
break;
case CS8:
urb_value |= 8;
dev_dbg(ddev, "Setting CS8\n");
break;
default:
dev_err(ddev, "CSIZE was set but not CS7-CS8\n");
}
}
priv->last_set_data_urb_value = urb_value;
if (usb_control_msg(dev, usb_sndctrlpipe(dev, 0),
FTDI_SIO_SET_DATA_REQUEST,
FTDI_SIO_SET_DATA_REQUEST_TYPE,
urb_value , priv->interface,
NULL, 0, WDR_SHORT_TIMEOUT) < 0) {
dev_err(ddev, "%s FAILED to set databits/stopbits/parity\n",
__func__);
}
no_data_parity_stop_changes:
if ((cflag & CBAUD) == B0) {
if (usb_control_msg(dev, usb_sndctrlpipe(dev, 0),
FTDI_SIO_SET_FLOW_CTRL_REQUEST,
FTDI_SIO_SET_FLOW_CTRL_REQUEST_TYPE,
0, priv->interface,
NULL, 0, WDR_TIMEOUT) < 0) {
dev_err(ddev, "%s error from disable flowcontrol urb\n",
__func__);
}
clear_mctrl(port, TIOCM_DTR | TIOCM_RTS);
} else {
mutex_lock(&priv->cfg_lock);
if (change_speed(tty, port))
dev_err(ddev, "%s urb failed to set baudrate\n", __func__);
mutex_unlock(&priv->cfg_lock);
if (old_termios && (old_termios->c_cflag & CBAUD) == B0)
set_mctrl(port, TIOCM_DTR | TIOCM_RTS);
}
no_c_cflag_changes:
if (cflag & CRTSCTS) {
dev_dbg(ddev, "%s Setting to CRTSCTS flow control\n", __func__);
if (usb_control_msg(dev,
usb_sndctrlpipe(dev, 0),
FTDI_SIO_SET_FLOW_CTRL_REQUEST,
FTDI_SIO_SET_FLOW_CTRL_REQUEST_TYPE,
0 , (FTDI_SIO_RTS_CTS_HS | priv->interface),
NULL, 0, WDR_TIMEOUT) < 0) {
dev_err(ddev, "urb failed to set to rts/cts flow control\n");
}
} else {
if (iflag & IXOFF) {
dev_dbg(ddev, "%s request to enable xonxoff iflag=%04x\n",
__func__, iflag);
vstart = termios->c_cc[VSTART];
vstop = termios->c_cc[VSTOP];
urb_value = (vstop << 8) | (vstart);
if (usb_control_msg(dev,
usb_sndctrlpipe(dev, 0),
FTDI_SIO_SET_FLOW_CTRL_REQUEST,
FTDI_SIO_SET_FLOW_CTRL_REQUEST_TYPE,
urb_value , (FTDI_SIO_XON_XOFF_HS
| priv->interface),
NULL, 0, WDR_TIMEOUT) < 0) {
dev_err(&port->dev, "urb failed to set to "
"xon/xoff flow control\n");
}
} else {
dev_dbg(ddev, "%s Turning off hardware flow control\n", __func__);
if (usb_control_msg(dev,
usb_sndctrlpipe(dev, 0),
FTDI_SIO_SET_FLOW_CTRL_REQUEST,
FTDI_SIO_SET_FLOW_CTRL_REQUEST_TYPE,
0, priv->interface,
NULL, 0, WDR_TIMEOUT) < 0) {
dev_err(ddev, "urb failed to clear flow control\n");
}
}
}
}
static int ftdi_get_modem_status(struct usb_serial_port *port,
unsigned char status[2])
{
struct ftdi_private *priv = usb_get_serial_port_data(port);
unsigned char *buf;
int len;
int ret;
buf = kmalloc(2, GFP_KERNEL);
if (!buf)
return -ENOMEM;
switch (priv->chip_type) {
case SIO:
len = 1;
break;
case FT8U232AM:
case FT232BM:
case FT2232C:
case FT232RL:
case FT2232H:
case FT4232H:
case FT232H:
case FTX:
len = 2;
break;
default:
ret = -EFAULT;
goto out;
}
ret = usb_control_msg(port->serial->dev,
usb_rcvctrlpipe(port->serial->dev, 0),
FTDI_SIO_GET_MODEM_STATUS_REQUEST,
FTDI_SIO_GET_MODEM_STATUS_REQUEST_TYPE,
0, priv->interface,
buf, len, WDR_TIMEOUT);
if (ret < 0) {
dev_err(&port->dev, "failed to get modem status: %d\n", ret);
ret = usb_translate_errors(ret);
goto out;
}
status[0] = buf[0];
if (ret > 1)
status[1] = buf[1];
else
status[1] = 0;
dev_dbg(&port->dev, "%s - 0x%02x%02x\n", __func__, status[0],
status[1]);
out:
kfree(buf);
return ret;
}
static int ftdi_tiocmget(struct tty_struct *tty)
{
struct usb_serial_port *port = tty->driver_data;
struct ftdi_private *priv = usb_get_serial_port_data(port);
unsigned char buf[2];
int ret;
ret = ftdi_get_modem_status(port, buf);
if (ret < 0)
return ret;
ret = (buf[0] & FTDI_SIO_DSR_MASK ? TIOCM_DSR : 0) |
(buf[0] & FTDI_SIO_CTS_MASK ? TIOCM_CTS : 0) |
(buf[0] & FTDI_SIO_RI_MASK ? TIOCM_RI : 0) |
(buf[0] & FTDI_SIO_RLSD_MASK ? TIOCM_CD : 0) |
priv->last_dtr_rts;
return ret;
}
static int ftdi_tiocmset(struct tty_struct *tty,
unsigned int set, unsigned int clear)
{
struct usb_serial_port *port = tty->driver_data;
return update_mctrl(port, set, clear);
}
static int ftdi_ioctl(struct tty_struct *tty,
unsigned int cmd, unsigned long arg)
{
struct usb_serial_port *port = tty->driver_data;
dev_dbg(&port->dev, "%s cmd 0x%04x\n", __func__, cmd);
switch (cmd) {
case TIOCGSERIAL:
return get_serial_info(port,
(struct serial_struct __user *) arg);
case TIOCSSERIAL:
return set_serial_info(tty, port,
(struct serial_struct __user *) arg);
case TIOCSERGETLSR:
return get_lsr_info(port, (struct serial_struct __user *)arg);
break;
default:
break;
}
dev_dbg(&port->dev, "%s arg not supported - it was 0x%04x - check /usr/include/asm/ioctls.h\n",
__func__, cmd);
return -ENOIOCTLCMD;
}
