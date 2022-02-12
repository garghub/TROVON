static void keyspan_pda_wakeup_write(struct work_struct *work)
{
struct keyspan_pda_private *priv =
container_of(work, struct keyspan_pda_private, wakeup_work);
struct usb_serial_port *port = priv->port;
tty_port_tty_wakeup(&port->port);
}
static void keyspan_pda_request_unthrottle(struct work_struct *work)
{
struct keyspan_pda_private *priv =
container_of(work, struct keyspan_pda_private, unthrottle_work);
struct usb_serial *serial = priv->serial;
int result;
result = usb_control_msg(serial->dev,
usb_sndctrlpipe(serial->dev, 0),
7,
USB_TYPE_VENDOR | USB_RECIP_INTERFACE
| USB_DIR_OUT,
16,
0,
NULL,
0,
2000);
if (result < 0)
dev_dbg(&serial->dev->dev, "%s - error %d from usb_control_msg\n",
__func__, result);
}
static void keyspan_pda_rx_interrupt(struct urb *urb)
{
struct usb_serial_port *port = urb->context;
unsigned char *data = urb->transfer_buffer;
int retval;
int status = urb->status;
struct keyspan_pda_private *priv;
priv = usb_get_serial_port_data(port);
switch (status) {
case 0:
break;
case -ECONNRESET:
case -ENOENT:
case -ESHUTDOWN:
dev_dbg(&urb->dev->dev, "%s - urb shutting down with status: %d\n", __func__, status);
return;
default:
dev_dbg(&urb->dev->dev, "%s - nonzero urb status received: %d\n", __func__, status);
goto exit;
}
switch (data[0]) {
case 0:
if (urb->actual_length) {
tty_insert_flip_string(&port->port, data + 1,
urb->actual_length - 1);
tty_flip_buffer_push(&port->port);
}
break;
case 1:
dev_dbg(&port->dev, "rx int, d1=%d, d2=%d\n", data[1], data[2]);
switch (data[1]) {
case 1:
break;
case 2:
priv->tx_throttled = 0;
schedule_work(&priv->wakeup_work);
break;
default:
break;
}
break;
default:
break;
}
exit:
retval = usb_submit_urb(urb, GFP_ATOMIC);
if (retval)
dev_err(&port->dev,
"%s - usb_submit_urb failed with result %d\n",
__func__, retval);
}
static void keyspan_pda_rx_throttle(struct tty_struct *tty)
{
struct usb_serial_port *port = tty->driver_data;
usb_kill_urb(port->interrupt_in_urb);
}
static void keyspan_pda_rx_unthrottle(struct tty_struct *tty)
{
struct usb_serial_port *port = tty->driver_data;
if (usb_submit_urb(port->interrupt_in_urb, GFP_KERNEL))
dev_dbg(&port->dev, "usb_submit_urb(read urb) failed\n");
}
static speed_t keyspan_pda_setbaud(struct usb_serial *serial, speed_t baud)
{
int rc;
int bindex;
switch (baud) {
case 110:
bindex = 0;
break;
case 300:
bindex = 1;
break;
case 1200:
bindex = 2;
break;
case 2400:
bindex = 3;
break;
case 4800:
bindex = 4;
break;
case 9600:
bindex = 5;
break;
case 19200:
bindex = 6;
break;
case 38400:
bindex = 7;
break;
case 57600:
bindex = 8;
break;
case 115200:
bindex = 9;
break;
default:
bindex = 5;
baud = 9600;
}
rc = usb_control_msg(serial->dev, usb_sndctrlpipe(serial->dev, 0),
0,
USB_TYPE_VENDOR
| USB_RECIP_INTERFACE
| USB_DIR_OUT,
bindex,
0,
NULL,
0,
2000);
if (rc < 0)
return 0;
return baud;
}
static void keyspan_pda_break_ctl(struct tty_struct *tty, int break_state)
{
struct usb_serial_port *port = tty->driver_data;
struct usb_serial *serial = port->serial;
int value;
int result;
if (break_state == -1)
value = 1;
else
value = 0;
result = usb_control_msg(serial->dev, usb_sndctrlpipe(serial->dev, 0),
4,
USB_TYPE_VENDOR | USB_RECIP_INTERFACE | USB_DIR_OUT,
value, 0, NULL, 0, 2000);
if (result < 0)
dev_dbg(&port->dev, "%s - error %d from usb_control_msg\n",
__func__, result);
}
static void keyspan_pda_set_termios(struct tty_struct *tty,
struct usb_serial_port *port, struct ktermios *old_termios)
{
struct usb_serial *serial = port->serial;
speed_t speed;
speed = tty_get_baud_rate(tty);
speed = keyspan_pda_setbaud(serial, speed);
if (speed == 0) {
dev_dbg(&port->dev, "can't handle requested baud rate\n");
speed = tty_termios_baud_rate(old_termios);
}
tty_termios_copy_hw(&tty->termios, old_termios);
tty_encode_baud_rate(tty, speed, speed);
}
static int keyspan_pda_get_modem_info(struct usb_serial *serial,
unsigned char *value)
{
int rc;
u8 *data;
data = kmalloc(1, GFP_KERNEL);
if (!data)
return -ENOMEM;
rc = usb_control_msg(serial->dev, usb_rcvctrlpipe(serial->dev, 0),
3,
USB_TYPE_VENDOR|USB_RECIP_INTERFACE|USB_DIR_IN,
0, 0, data, 1, 2000);
if (rc >= 0)
*value = *data;
kfree(data);
return rc;
}
static int keyspan_pda_set_modem_info(struct usb_serial *serial,
unsigned char value)
{
int rc;
rc = usb_control_msg(serial->dev, usb_sndctrlpipe(serial->dev, 0),
3,
USB_TYPE_VENDOR|USB_RECIP_INTERFACE|USB_DIR_OUT,
value, 0, NULL, 0, 2000);
return rc;
}
static int keyspan_pda_tiocmget(struct tty_struct *tty)
{
struct usb_serial_port *port = tty->driver_data;
struct usb_serial *serial = port->serial;
int rc;
unsigned char status;
int value;
rc = keyspan_pda_get_modem_info(serial, &status);
if (rc < 0)
return rc;
value =
((status & (1<<7)) ? TIOCM_DTR : 0) |
((status & (1<<6)) ? TIOCM_CAR : 0) |
((status & (1<<5)) ? TIOCM_RNG : 0) |
((status & (1<<4)) ? TIOCM_DSR : 0) |
((status & (1<<3)) ? TIOCM_CTS : 0) |
((status & (1<<2)) ? TIOCM_RTS : 0);
return value;
}
static int keyspan_pda_tiocmset(struct tty_struct *tty,
unsigned int set, unsigned int clear)
{
struct usb_serial_port *port = tty->driver_data;
struct usb_serial *serial = port->serial;
int rc;
unsigned char status;
rc = keyspan_pda_get_modem_info(serial, &status);
if (rc < 0)
return rc;
if (set & TIOCM_RTS)
status |= (1<<2);
if (set & TIOCM_DTR)
status |= (1<<7);
if (clear & TIOCM_RTS)
status &= ~(1<<2);
if (clear & TIOCM_DTR)
status &= ~(1<<7);
rc = keyspan_pda_set_modem_info(serial, status);
return rc;
}
static int keyspan_pda_write(struct tty_struct *tty,
struct usb_serial_port *port, const unsigned char *buf, int count)
{
struct usb_serial *serial = port->serial;
int request_unthrottle = 0;
int rc = 0;
struct keyspan_pda_private *priv;
priv = usb_get_serial_port_data(port);
if (count == 0) {
dev_dbg(&port->dev, "write request of 0 bytes\n");
return 0;
}
spin_lock_bh(&port->lock);
if (!test_bit(0, &port->write_urbs_free) || priv->tx_throttled) {
spin_unlock_bh(&port->lock);
return 0;
}
clear_bit(0, &port->write_urbs_free);
spin_unlock_bh(&port->lock);
count = (count > port->bulk_out_size) ? port->bulk_out_size : count;
if (count > priv->tx_room && !in_interrupt()) {
u8 *room;
room = kmalloc(1, GFP_KERNEL);
if (!room) {
rc = -ENOMEM;
goto exit;
}
rc = usb_control_msg(serial->dev,
usb_rcvctrlpipe(serial->dev, 0),
6,
USB_TYPE_VENDOR | USB_RECIP_INTERFACE
| USB_DIR_IN,
0,
0,
room,
1,
2000);
if (rc > 0) {
dev_dbg(&port->dev, "roomquery says %d\n", *room);
priv->tx_room = *room;
}
kfree(room);
if (rc < 0) {
dev_dbg(&port->dev, "roomquery failed\n");
goto exit;
}
if (rc == 0) {
dev_dbg(&port->dev, "roomquery returned 0 bytes\n");
rc = -EIO;
goto exit;
}
}
if (count > priv->tx_room) {
count = priv->tx_room;
request_unthrottle = 1;
}
if (count) {
memcpy(port->write_urb->transfer_buffer, buf, count);
port->write_urb->transfer_buffer_length = count;
priv->tx_room -= count;
rc = usb_submit_urb(port->write_urb, GFP_ATOMIC);
if (rc) {
dev_dbg(&port->dev, "usb_submit_urb(write bulk) failed\n");
goto exit;
}
} else {
request_unthrottle = 1;
}
if (request_unthrottle) {
priv->tx_throttled = 1;
schedule_work(&priv->unthrottle_work);
}
rc = count;
exit:
if (rc < 0)
set_bit(0, &port->write_urbs_free);
return rc;
}
static void keyspan_pda_write_bulk_callback(struct urb *urb)
{
struct usb_serial_port *port = urb->context;
struct keyspan_pda_private *priv;
set_bit(0, &port->write_urbs_free);
priv = usb_get_serial_port_data(port);
schedule_work(&priv->wakeup_work);
}
static int keyspan_pda_write_room(struct tty_struct *tty)
{
struct usb_serial_port *port = tty->driver_data;
struct keyspan_pda_private *priv;
priv = usb_get_serial_port_data(port);
return priv->tx_room;
}
static int keyspan_pda_chars_in_buffer(struct tty_struct *tty)
{
struct usb_serial_port *port = tty->driver_data;
struct keyspan_pda_private *priv;
unsigned long flags;
int ret = 0;
priv = usb_get_serial_port_data(port);
spin_lock_irqsave(&port->lock, flags);
if (!test_bit(0, &port->write_urbs_free) || priv->tx_throttled)
ret = 256;
spin_unlock_irqrestore(&port->lock, flags);
return ret;
}
static void keyspan_pda_dtr_rts(struct usb_serial_port *port, int on)
{
struct usb_serial *serial = port->serial;
if (on)
keyspan_pda_set_modem_info(serial, (1 << 7) | (1 << 2));
else
keyspan_pda_set_modem_info(serial, 0);
}
static int keyspan_pda_open(struct tty_struct *tty,
struct usb_serial_port *port)
{
struct usb_serial *serial = port->serial;
u8 *room;
int rc = 0;
struct keyspan_pda_private *priv;
room = kmalloc(1, GFP_KERNEL);
if (!room)
return -ENOMEM;
rc = usb_control_msg(serial->dev, usb_rcvctrlpipe(serial->dev, 0),
6,
USB_TYPE_VENDOR | USB_RECIP_INTERFACE
| USB_DIR_IN,
0,
0,
room,
1,
2000);
if (rc < 0) {
dev_dbg(&port->dev, "%s - roomquery failed\n", __func__);
goto error;
}
if (rc == 0) {
dev_dbg(&port->dev, "%s - roomquery returned 0 bytes\n", __func__);
rc = -EIO;
goto error;
}
priv = usb_get_serial_port_data(port);
priv->tx_room = *room;
priv->tx_throttled = *room ? 0 : 1;
rc = usb_submit_urb(port->interrupt_in_urb, GFP_KERNEL);
if (rc) {
dev_dbg(&port->dev, "%s - usb_submit_urb(read int) failed\n", __func__);
goto error;
}
error:
kfree(room);
return rc;
}
static void keyspan_pda_close(struct usb_serial_port *port)
{
usb_kill_urb(port->write_urb);
usb_kill_urb(port->interrupt_in_urb);
}
static int keyspan_pda_fake_startup(struct usb_serial *serial)
{
int response;
const char *fw_name;
response = ezusb_fx1_set_reset(serial->dev, 1);
if (0) { ; }
#ifdef KEYSPAN
else if (le16_to_cpu(serial->dev->descriptor.idVendor) == KEYSPAN_VENDOR_ID)
fw_name = "keyspan_pda/keyspan_pda.fw";
#endif
#ifdef XIRCOM
else if ((le16_to_cpu(serial->dev->descriptor.idVendor) == XIRCOM_VENDOR_ID) ||
(le16_to_cpu(serial->dev->descriptor.idVendor) == ENTREGA_VENDOR_ID))
fw_name = "keyspan_pda/xircom_pgs.fw";
#endif
else {
dev_err(&serial->dev->dev, "%s: unknown vendor, aborting.\n",
__func__);
return -ENODEV;
}
if (ezusb_fx1_ihex_firmware_download(serial->dev, fw_name) < 0) {
dev_err(&serial->dev->dev, "failed to load firmware \"%s\"\n",
fw_name);
return -ENOENT;
}
return 1;
}
static int keyspan_pda_port_probe(struct usb_serial_port *port)
{
struct keyspan_pda_private *priv;
priv = kmalloc(sizeof(struct keyspan_pda_private), GFP_KERNEL);
if (!priv)
return -ENOMEM;
INIT_WORK(&priv->wakeup_work, keyspan_pda_wakeup_write);
INIT_WORK(&priv->unthrottle_work, keyspan_pda_request_unthrottle);
priv->serial = port->serial;
priv->port = port;
usb_set_serial_port_data(port, priv);
return 0;
}
static int keyspan_pda_port_remove(struct usb_serial_port *port)
{
struct keyspan_pda_private *priv;
priv = usb_get_serial_port_data(port);
kfree(priv);
return 0;
}
