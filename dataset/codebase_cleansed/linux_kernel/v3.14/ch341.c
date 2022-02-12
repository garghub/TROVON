static int ch341_control_out(struct usb_device *dev, u8 request,
u16 value, u16 index)
{
int r;
dev_dbg(&dev->dev, "ch341_control_out(%02x,%02x,%04x,%04x)\n",
USB_DIR_OUT|0x40, (int)request, (int)value, (int)index);
r = usb_control_msg(dev, usb_sndctrlpipe(dev, 0), request,
USB_TYPE_VENDOR | USB_RECIP_DEVICE | USB_DIR_OUT,
value, index, NULL, 0, DEFAULT_TIMEOUT);
return r;
}
static int ch341_control_in(struct usb_device *dev,
u8 request, u16 value, u16 index,
char *buf, unsigned bufsize)
{
int r;
dev_dbg(&dev->dev, "ch341_control_in(%02x,%02x,%04x,%04x,%p,%u)\n",
USB_DIR_IN|0x40, (int)request, (int)value, (int)index, buf,
(int)bufsize);
r = usb_control_msg(dev, usb_rcvctrlpipe(dev, 0), request,
USB_TYPE_VENDOR | USB_RECIP_DEVICE | USB_DIR_IN,
value, index, buf, bufsize, DEFAULT_TIMEOUT);
return r;
}
static int ch341_set_baudrate(struct usb_device *dev,
struct ch341_private *priv)
{
short a, b;
int r;
unsigned long factor;
short divisor;
if (!priv->baud_rate)
return -EINVAL;
factor = (CH341_BAUDBASE_FACTOR / priv->baud_rate);
divisor = CH341_BAUDBASE_DIVMAX;
while ((factor > 0xfff0) && divisor) {
factor >>= 3;
divisor--;
}
if (factor > 0xfff0)
return -EINVAL;
factor = 0x10000 - factor;
a = (factor & 0xff00) | divisor;
b = factor & 0xff;
r = ch341_control_out(dev, 0x9a, 0x1312, a);
if (!r)
r = ch341_control_out(dev, 0x9a, 0x0f2c, b);
return r;
}
static int ch341_set_handshake(struct usb_device *dev, u8 control)
{
return ch341_control_out(dev, 0xa4, ~control, 0);
}
static int ch341_get_status(struct usb_device *dev, struct ch341_private *priv)
{
char *buffer;
int r;
const unsigned size = 8;
unsigned long flags;
buffer = kmalloc(size, GFP_KERNEL);
if (!buffer)
return -ENOMEM;
r = ch341_control_in(dev, 0x95, 0x0706, 0, buffer, size);
if (r < 0)
goto out;
if (r == 2) {
r = 0;
spin_lock_irqsave(&priv->lock, flags);
priv->line_status = (~(*buffer)) & CH341_BITS_MODEM_STAT;
spin_unlock_irqrestore(&priv->lock, flags);
} else
r = -EPROTO;
out: kfree(buffer);
return r;
}
static int ch341_configure(struct usb_device *dev, struct ch341_private *priv)
{
char *buffer;
int r;
const unsigned size = 8;
buffer = kmalloc(size, GFP_KERNEL);
if (!buffer)
return -ENOMEM;
r = ch341_control_in(dev, 0x5f, 0, 0, buffer, size);
if (r < 0)
goto out;
r = ch341_control_out(dev, 0xa1, 0, 0);
if (r < 0)
goto out;
r = ch341_set_baudrate(dev, priv);
if (r < 0)
goto out;
r = ch341_control_in(dev, 0x95, 0x2518, 0, buffer, size);
if (r < 0)
goto out;
r = ch341_control_out(dev, 0x9a, 0x2518, 0x0050);
if (r < 0)
goto out;
r = ch341_get_status(dev, priv);
if (r < 0)
goto out;
r = ch341_control_out(dev, 0xa1, 0x501f, 0xd90a);
if (r < 0)
goto out;
r = ch341_set_baudrate(dev, priv);
if (r < 0)
goto out;
r = ch341_set_handshake(dev, priv->line_control);
if (r < 0)
goto out;
r = ch341_get_status(dev, priv);
out: kfree(buffer);
return r;
}
static int ch341_port_probe(struct usb_serial_port *port)
{
struct ch341_private *priv;
int r;
priv = kzalloc(sizeof(struct ch341_private), GFP_KERNEL);
if (!priv)
return -ENOMEM;
spin_lock_init(&priv->lock);
priv->baud_rate = DEFAULT_BAUD_RATE;
priv->line_control = CH341_BIT_RTS | CH341_BIT_DTR;
r = ch341_configure(port->serial->dev, priv);
if (r < 0)
goto error;
usb_set_serial_port_data(port, priv);
return 0;
error: kfree(priv);
return r;
}
static int ch341_port_remove(struct usb_serial_port *port)
{
struct ch341_private *priv;
priv = usb_get_serial_port_data(port);
kfree(priv);
return 0;
}
static int ch341_carrier_raised(struct usb_serial_port *port)
{
struct ch341_private *priv = usb_get_serial_port_data(port);
if (priv->line_status & CH341_BIT_DCD)
return 1;
return 0;
}
static void ch341_dtr_rts(struct usb_serial_port *port, int on)
{
struct ch341_private *priv = usb_get_serial_port_data(port);
unsigned long flags;
spin_lock_irqsave(&priv->lock, flags);
if (on)
priv->line_control |= CH341_BIT_RTS | CH341_BIT_DTR;
else
priv->line_control &= ~(CH341_BIT_RTS | CH341_BIT_DTR);
spin_unlock_irqrestore(&priv->lock, flags);
ch341_set_handshake(port->serial->dev, priv->line_control);
}
static void ch341_close(struct usb_serial_port *port)
{
usb_serial_generic_close(port);
usb_kill_urb(port->interrupt_in_urb);
}
static int ch341_open(struct tty_struct *tty, struct usb_serial_port *port)
{
struct usb_serial *serial = port->serial;
struct ch341_private *priv = usb_get_serial_port_data(port);
int r;
priv->baud_rate = DEFAULT_BAUD_RATE;
r = ch341_configure(serial->dev, priv);
if (r)
goto out;
r = ch341_set_handshake(serial->dev, priv->line_control);
if (r)
goto out;
r = ch341_set_baudrate(serial->dev, priv);
if (r)
goto out;
dev_dbg(&port->dev, "%s - submitting interrupt urb", __func__);
r = usb_submit_urb(port->interrupt_in_urb, GFP_KERNEL);
if (r) {
dev_err(&port->dev, "%s - failed submitting interrupt urb,"
" error %d\n", __func__, r);
ch341_close(port);
goto out;
}
r = usb_serial_generic_open(tty, port);
out: return r;
}
static void ch341_set_termios(struct tty_struct *tty,
struct usb_serial_port *port, struct ktermios *old_termios)
{
struct ch341_private *priv = usb_get_serial_port_data(port);
unsigned baud_rate;
unsigned long flags;
baud_rate = tty_get_baud_rate(tty);
priv->baud_rate = baud_rate;
if (baud_rate) {
spin_lock_irqsave(&priv->lock, flags);
priv->line_control |= (CH341_BIT_DTR | CH341_BIT_RTS);
spin_unlock_irqrestore(&priv->lock, flags);
ch341_set_baudrate(port->serial->dev, priv);
} else {
spin_lock_irqsave(&priv->lock, flags);
priv->line_control &= ~(CH341_BIT_DTR | CH341_BIT_RTS);
spin_unlock_irqrestore(&priv->lock, flags);
}
ch341_set_handshake(port->serial->dev, priv->line_control);
}
static void ch341_break_ctl(struct tty_struct *tty, int break_state)
{
const uint16_t ch341_break_reg =
CH341_REG_BREAK1 | ((uint16_t) CH341_REG_BREAK2 << 8);
struct usb_serial_port *port = tty->driver_data;
int r;
uint16_t reg_contents;
uint8_t *break_reg;
break_reg = kmalloc(2, GFP_KERNEL);
if (!break_reg)
return;
r = ch341_control_in(port->serial->dev, CH341_REQ_READ_REG,
ch341_break_reg, 0, break_reg, 2);
if (r < 0) {
dev_err(&port->dev, "%s - USB control read error (%d)\n",
__func__, r);
goto out;
}
dev_dbg(&port->dev, "%s - initial ch341 break register contents - reg1: %x, reg2: %x\n",
__func__, break_reg[0], break_reg[1]);
if (break_state != 0) {
dev_dbg(&port->dev, "%s - Enter break state requested\n", __func__);
break_reg[0] &= ~CH341_NBREAK_BITS_REG1;
break_reg[1] &= ~CH341_NBREAK_BITS_REG2;
} else {
dev_dbg(&port->dev, "%s - Leave break state requested\n", __func__);
break_reg[0] |= CH341_NBREAK_BITS_REG1;
break_reg[1] |= CH341_NBREAK_BITS_REG2;
}
dev_dbg(&port->dev, "%s - New ch341 break register contents - reg1: %x, reg2: %x\n",
__func__, break_reg[0], break_reg[1]);
reg_contents = get_unaligned_le16(break_reg);
r = ch341_control_out(port->serial->dev, CH341_REQ_WRITE_REG,
ch341_break_reg, reg_contents);
if (r < 0)
dev_err(&port->dev, "%s - USB control write error (%d)\n",
__func__, r);
out:
kfree(break_reg);
}
static int ch341_tiocmset(struct tty_struct *tty,
unsigned int set, unsigned int clear)
{
struct usb_serial_port *port = tty->driver_data;
struct ch341_private *priv = usb_get_serial_port_data(port);
unsigned long flags;
u8 control;
spin_lock_irqsave(&priv->lock, flags);
if (set & TIOCM_RTS)
priv->line_control |= CH341_BIT_RTS;
if (set & TIOCM_DTR)
priv->line_control |= CH341_BIT_DTR;
if (clear & TIOCM_RTS)
priv->line_control &= ~CH341_BIT_RTS;
if (clear & TIOCM_DTR)
priv->line_control &= ~CH341_BIT_DTR;
control = priv->line_control;
spin_unlock_irqrestore(&priv->lock, flags);
return ch341_set_handshake(port->serial->dev, control);
}
static void ch341_update_line_status(struct usb_serial_port *port,
unsigned char *data, size_t len)
{
struct ch341_private *priv = usb_get_serial_port_data(port);
struct tty_struct *tty;
unsigned long flags;
u8 status;
u8 delta;
if (len < 4)
return;
status = ~data[2] & CH341_BITS_MODEM_STAT;
spin_lock_irqsave(&priv->lock, flags);
delta = status ^ priv->line_status;
priv->line_status = status;
spin_unlock_irqrestore(&priv->lock, flags);
if (data[1] & CH341_MULT_STAT)
dev_dbg(&port->dev, "%s - multiple status change\n", __func__);
if (!delta)
return;
if (delta & CH341_BIT_CTS)
port->icount.cts++;
if (delta & CH341_BIT_DSR)
port->icount.dsr++;
if (delta & CH341_BIT_RI)
port->icount.rng++;
if (delta & CH341_BIT_DCD) {
port->icount.dcd++;
tty = tty_port_tty_get(&port->port);
if (tty) {
usb_serial_handle_dcd_change(port, tty,
status & CH341_BIT_DCD);
tty_kref_put(tty);
}
}
wake_up_interruptible(&port->port.delta_msr_wait);
}
static void ch341_read_int_callback(struct urb *urb)
{
struct usb_serial_port *port = urb->context;
unsigned char *data = urb->transfer_buffer;
unsigned int len = urb->actual_length;
int status;
switch (urb->status) {
case 0:
break;
case -ECONNRESET:
case -ENOENT:
case -ESHUTDOWN:
dev_dbg(&urb->dev->dev, "%s - urb shutting down: %d\n",
__func__, urb->status);
return;
default:
dev_dbg(&urb->dev->dev, "%s - nonzero urb status: %d\n",
__func__, urb->status);
goto exit;
}
usb_serial_debug_data(&port->dev, __func__, len, data);
ch341_update_line_status(port, data, len);
exit:
status = usb_submit_urb(urb, GFP_ATOMIC);
if (status) {
dev_err(&urb->dev->dev, "%s - usb_submit_urb failed: %d\n",
__func__, status);
}
}
static int ch341_tiocmget(struct tty_struct *tty)
{
struct usb_serial_port *port = tty->driver_data;
struct ch341_private *priv = usb_get_serial_port_data(port);
unsigned long flags;
u8 mcr;
u8 status;
unsigned int result;
spin_lock_irqsave(&priv->lock, flags);
mcr = priv->line_control;
status = priv->line_status;
spin_unlock_irqrestore(&priv->lock, flags);
result = ((mcr & CH341_BIT_DTR) ? TIOCM_DTR : 0)
| ((mcr & CH341_BIT_RTS) ? TIOCM_RTS : 0)
| ((status & CH341_BIT_CTS) ? TIOCM_CTS : 0)
| ((status & CH341_BIT_DSR) ? TIOCM_DSR : 0)
| ((status & CH341_BIT_RI) ? TIOCM_RI : 0)
| ((status & CH341_BIT_DCD) ? TIOCM_CD : 0);
dev_dbg(&port->dev, "%s - result = %x\n", __func__, result);
return result;
}
static int ch341_reset_resume(struct usb_serial *serial)
{
struct ch341_private *priv;
priv = usb_get_serial_port_data(serial->port[0]);
ch341_configure(serial->dev, priv);
return 0;
}
