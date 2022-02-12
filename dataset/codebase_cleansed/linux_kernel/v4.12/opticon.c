static void opticon_process_data_packet(struct usb_serial_port *port,
const unsigned char *buf, size_t len)
{
tty_insert_flip_string(&port->port, buf, len);
tty_flip_buffer_push(&port->port);
}
static void opticon_process_status_packet(struct usb_serial_port *port,
const unsigned char *buf, size_t len)
{
struct opticon_private *priv = usb_get_serial_port_data(port);
unsigned long flags;
spin_lock_irqsave(&priv->lock, flags);
if (buf[0] == 0x00)
priv->cts = false;
else
priv->cts = true;
spin_unlock_irqrestore(&priv->lock, flags);
}
static void opticon_process_read_urb(struct urb *urb)
{
struct usb_serial_port *port = urb->context;
const unsigned char *hdr = urb->transfer_buffer;
const unsigned char *data = hdr + 2;
size_t data_len = urb->actual_length - 2;
if (urb->actual_length <= 2) {
dev_dbg(&port->dev, "malformed packet received: %d bytes\n",
urb->actual_length);
return;
}
if ((hdr[0] == 0x00) && (hdr[1] == 0x00)) {
opticon_process_data_packet(port, data, data_len);
} else if ((hdr[0] == 0x00) && (hdr[1] == 0x01)) {
opticon_process_status_packet(port, data, data_len);
} else {
dev_dbg(&port->dev, "unknown packet received: %02x %02x\n",
hdr[0], hdr[1]);
}
}
static int send_control_msg(struct usb_serial_port *port, u8 requesttype,
u8 val)
{
struct usb_serial *serial = port->serial;
int retval;
u8 *buffer;
buffer = kzalloc(1, GFP_KERNEL);
if (!buffer)
return -ENOMEM;
buffer[0] = val;
retval = usb_control_msg(serial->dev, usb_sndctrlpipe(serial->dev, 0),
requesttype,
USB_DIR_OUT|USB_TYPE_VENDOR|USB_RECIP_INTERFACE,
0, 0, buffer, 1, 0);
kfree(buffer);
if (retval < 0)
return retval;
return 0;
}
static int opticon_open(struct tty_struct *tty, struct usb_serial_port *port)
{
struct opticon_private *priv = usb_get_serial_port_data(port);
unsigned long flags;
int res;
spin_lock_irqsave(&priv->lock, flags);
priv->rts = false;
spin_unlock_irqrestore(&priv->lock, flags);
send_control_msg(port, CONTROL_RTS, 0);
usb_clear_halt(port->serial->dev, port->read_urb->pipe);
res = usb_serial_generic_open(tty, port);
if (res)
return res;
send_control_msg(port, RESEND_CTS_STATE, 1);
return res;
}
static void opticon_write_control_callback(struct urb *urb)
{
struct usb_serial_port *port = urb->context;
struct opticon_private *priv = usb_get_serial_port_data(port);
int status = urb->status;
unsigned long flags;
kfree(urb->transfer_buffer);
kfree(urb->setup_packet);
if (status)
dev_dbg(&port->dev,
"%s - non-zero urb status received: %d\n",
__func__, status);
spin_lock_irqsave(&priv->lock, flags);
--priv->outstanding_urbs;
spin_unlock_irqrestore(&priv->lock, flags);
usb_serial_port_softint(port);
}
static int opticon_write(struct tty_struct *tty, struct usb_serial_port *port,
const unsigned char *buf, int count)
{
struct opticon_private *priv = usb_get_serial_port_data(port);
struct usb_serial *serial = port->serial;
struct urb *urb;
unsigned char *buffer;
unsigned long flags;
int status;
struct usb_ctrlrequest *dr;
spin_lock_irqsave(&priv->lock, flags);
if (priv->outstanding_urbs > URB_UPPER_LIMIT) {
spin_unlock_irqrestore(&priv->lock, flags);
dev_dbg(&port->dev, "%s - write limit hit\n", __func__);
return 0;
}
priv->outstanding_urbs++;
spin_unlock_irqrestore(&priv->lock, flags);
buffer = kmalloc(count, GFP_ATOMIC);
if (!buffer) {
count = -ENOMEM;
goto error_no_buffer;
}
urb = usb_alloc_urb(0, GFP_ATOMIC);
if (!urb) {
count = -ENOMEM;
goto error_no_urb;
}
memcpy(buffer, buf, count);
usb_serial_debug_data(&port->dev, __func__, count, buffer);
dr = kmalloc(sizeof(struct usb_ctrlrequest), GFP_ATOMIC);
if (!dr) {
count = -ENOMEM;
goto error_no_dr;
}
dr->bRequestType = USB_TYPE_VENDOR | USB_RECIP_INTERFACE | USB_DIR_OUT;
dr->bRequest = 0x01;
dr->wValue = 0;
dr->wIndex = 0;
dr->wLength = cpu_to_le16(count);
usb_fill_control_urb(urb, serial->dev,
usb_sndctrlpipe(serial->dev, 0),
(unsigned char *)dr, buffer, count,
opticon_write_control_callback, port);
status = usb_submit_urb(urb, GFP_ATOMIC);
if (status) {
dev_err(&port->dev,
"%s - usb_submit_urb(write endpoint) failed status = %d\n",
__func__, status);
count = status;
goto error;
}
usb_free_urb(urb);
return count;
error:
kfree(dr);
error_no_dr:
usb_free_urb(urb);
error_no_urb:
kfree(buffer);
error_no_buffer:
spin_lock_irqsave(&priv->lock, flags);
--priv->outstanding_urbs;
spin_unlock_irqrestore(&priv->lock, flags);
return count;
}
static int opticon_write_room(struct tty_struct *tty)
{
struct usb_serial_port *port = tty->driver_data;
struct opticon_private *priv = usb_get_serial_port_data(port);
unsigned long flags;
spin_lock_irqsave(&priv->lock, flags);
if (priv->outstanding_urbs > URB_UPPER_LIMIT * 2 / 3) {
spin_unlock_irqrestore(&priv->lock, flags);
dev_dbg(&port->dev, "%s - write limit hit\n", __func__);
return 0;
}
spin_unlock_irqrestore(&priv->lock, flags);
return 2048;
}
static int opticon_tiocmget(struct tty_struct *tty)
{
struct usb_serial_port *port = tty->driver_data;
struct opticon_private *priv = usb_get_serial_port_data(port);
unsigned long flags;
int result = 0;
spin_lock_irqsave(&priv->lock, flags);
if (priv->rts)
result |= TIOCM_RTS;
if (priv->cts)
result |= TIOCM_CTS;
spin_unlock_irqrestore(&priv->lock, flags);
dev_dbg(&port->dev, "%s - %x\n", __func__, result);
return result;
}
static int opticon_tiocmset(struct tty_struct *tty,
unsigned int set, unsigned int clear)
{
struct usb_serial_port *port = tty->driver_data;
struct opticon_private *priv = usb_get_serial_port_data(port);
unsigned long flags;
bool rts;
bool changed = false;
int ret;
spin_lock_irqsave(&priv->lock, flags);
rts = priv->rts;
if (set & TIOCM_RTS)
priv->rts = true;
if (clear & TIOCM_RTS)
priv->rts = false;
changed = rts ^ priv->rts;
spin_unlock_irqrestore(&priv->lock, flags);
if (!changed)
return 0;
ret = send_control_msg(port, CONTROL_RTS, !rts);
if (ret)
return usb_translate_errors(ret);
return 0;
}
static int get_serial_info(struct usb_serial_port *port,
struct serial_struct __user *serial)
{
struct serial_struct tmp;
memset(&tmp, 0x00, sizeof(tmp));
tmp.type = PORT_16550A;
tmp.line = port->minor;
tmp.port = 0;
tmp.irq = 0;
tmp.xmit_fifo_size = 1024;
tmp.baud_base = 9600;
tmp.close_delay = 5*HZ;
tmp.closing_wait = 30*HZ;
if (copy_to_user(serial, &tmp, sizeof(*serial)))
return -EFAULT;
return 0;
}
static int opticon_ioctl(struct tty_struct *tty,
unsigned int cmd, unsigned long arg)
{
struct usb_serial_port *port = tty->driver_data;
switch (cmd) {
case TIOCGSERIAL:
return get_serial_info(port,
(struct serial_struct __user *)arg);
}
return -ENOIOCTLCMD;
}
static int opticon_port_probe(struct usb_serial_port *port)
{
struct opticon_private *priv;
priv = kzalloc(sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
spin_lock_init(&priv->lock);
usb_set_serial_port_data(port, priv);
return 0;
}
static int opticon_port_remove(struct usb_serial_port *port)
{
struct opticon_private *priv = usb_get_serial_port_data(port);
kfree(priv);
return 0;
}
