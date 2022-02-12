static int spcp8x5_probe(struct usb_serial *serial,
const struct usb_device_id *id)
{
usb_set_serial_data(serial, (void *)id);
return 0;
}
static int spcp8x5_attach(struct usb_serial *serial)
{
unsigned char num_ports = serial->num_ports;
if (serial->num_bulk_in < num_ports ||
serial->num_bulk_out < num_ports) {
dev_err(&serial->interface->dev, "missing endpoints\n");
return -ENODEV;
}
return 0;
}
static int spcp8x5_port_probe(struct usb_serial_port *port)
{
const struct usb_device_id *id = usb_get_serial_data(port->serial);
struct spcp8x5_private *priv;
priv = kzalloc(sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
spin_lock_init(&priv->lock);
priv->quirks = id->driver_info;
usb_set_serial_port_data(port, priv);
port->port.drain_delay = 256;
return 0;
}
static int spcp8x5_port_remove(struct usb_serial_port *port)
{
struct spcp8x5_private *priv;
priv = usb_get_serial_port_data(port);
kfree(priv);
return 0;
}
static int spcp8x5_set_ctrl_line(struct usb_serial_port *port, u8 mcr)
{
struct spcp8x5_private *priv = usb_get_serial_port_data(port);
struct usb_device *dev = port->serial->dev;
int retval;
if (priv->quirks & SPCP825_QUIRK_NO_UART_STATUS)
return -EPERM;
retval = usb_control_msg(dev, usb_sndctrlpipe(dev, 0),
SET_UART_STATUS_TYPE, SET_UART_STATUS,
mcr, 0x04, NULL, 0, 100);
if (retval != 0) {
dev_err(&port->dev, "failed to set control lines: %d\n",
retval);
}
return retval;
}
static int spcp8x5_get_msr(struct usb_serial_port *port, u8 *status)
{
struct spcp8x5_private *priv = usb_get_serial_port_data(port);
struct usb_device *dev = port->serial->dev;
u8 *buf;
int ret;
if (priv->quirks & SPCP825_QUIRK_NO_UART_STATUS)
return -EPERM;
buf = kzalloc(1, GFP_KERNEL);
if (!buf)
return -ENOMEM;
ret = usb_control_msg(dev, usb_rcvctrlpipe(dev, 0),
GET_UART_STATUS, GET_UART_STATUS_TYPE,
0, GET_UART_STATUS_MSR, buf, 1, 100);
if (ret < 0)
dev_err(&port->dev, "failed to get modem status: %d\n", ret);
dev_dbg(&port->dev, "0xc0:0x22:0:6 %d - 0x02%x\n", ret, *buf);
*status = *buf;
kfree(buf);
return ret;
}
static void spcp8x5_set_work_mode(struct usb_serial_port *port, u16 value,
u16 index)
{
struct spcp8x5_private *priv = usb_get_serial_port_data(port);
struct usb_device *dev = port->serial->dev;
int ret;
if (priv->quirks & SPCP825_QUIRK_NO_WORK_MODE)
return;
ret = usb_control_msg(dev, usb_sndctrlpipe(dev, 0),
SET_WORKING_MODE_TYPE, SET_WORKING_MODE,
value, index, NULL, 0, 100);
dev_dbg(&port->dev, "value = %#x , index = %#x\n", value, index);
if (ret < 0)
dev_err(&port->dev, "failed to set work mode: %d\n", ret);
}
static int spcp8x5_carrier_raised(struct usb_serial_port *port)
{
u8 msr;
int ret;
ret = spcp8x5_get_msr(port, &msr);
if (ret || msr & MSR_STATUS_LINE_DCD)
return 1;
return 0;
}
static void spcp8x5_dtr_rts(struct usb_serial_port *port, int on)
{
struct spcp8x5_private *priv = usb_get_serial_port_data(port);
unsigned long flags;
u8 control;
spin_lock_irqsave(&priv->lock, flags);
if (on)
priv->line_control = MCR_CONTROL_LINE_DTR
| MCR_CONTROL_LINE_RTS;
else
priv->line_control &= ~ (MCR_CONTROL_LINE_DTR
| MCR_CONTROL_LINE_RTS);
control = priv->line_control;
spin_unlock_irqrestore(&priv->lock, flags);
spcp8x5_set_ctrl_line(port, control);
}
static void spcp8x5_init_termios(struct tty_struct *tty)
{
tty->termios = tty_std_termios;
tty->termios.c_cflag = B115200 | CS8 | CREAD | HUPCL | CLOCAL;
tty->termios.c_ispeed = 115200;
tty->termios.c_ospeed = 115200;
}
static void spcp8x5_set_termios(struct tty_struct *tty,
struct usb_serial_port *port, struct ktermios *old_termios)
{
struct usb_serial *serial = port->serial;
struct spcp8x5_private *priv = usb_get_serial_port_data(port);
unsigned long flags;
unsigned int cflag = tty->termios.c_cflag;
unsigned short uartdata;
unsigned char buf[2] = {0, 0};
int baud;
int i;
u8 control;
if (old_termios && !tty_termios_hw_change(&tty->termios, old_termios))
return;
spin_lock_irqsave(&priv->lock, flags);
control = priv->line_control;
if (old_termios && (old_termios->c_cflag & CBAUD) == B0) {
priv->line_control |= MCR_DTR;
if (!(old_termios->c_cflag & CRTSCTS))
priv->line_control |= MCR_RTS;
}
if (control != priv->line_control) {
control = priv->line_control;
spin_unlock_irqrestore(&priv->lock, flags);
spcp8x5_set_ctrl_line(port, control);
} else {
spin_unlock_irqrestore(&priv->lock, flags);
}
baud = tty_get_baud_rate(tty);
switch (baud) {
case 300: buf[0] = 0x00; break;
case 600: buf[0] = 0x01; break;
case 1200: buf[0] = 0x02; break;
case 2400: buf[0] = 0x03; break;
case 4800: buf[0] = 0x04; break;
case 9600: buf[0] = 0x05; break;
case 19200: buf[0] = 0x07; break;
case 38400: buf[0] = 0x09; break;
case 57600: buf[0] = 0x0a; break;
case 115200: buf[0] = 0x0b; break;
case 230400: buf[0] = 0x0c; break;
case 460800: buf[0] = 0x0d; break;
case 921600: buf[0] = 0x0e; break;
case 3000000: buf[0] = 0x11; break;
case 0:
case 1000000:
buf[0] = 0x0b; break;
default:
dev_err(&port->dev, "unsupported baudrate, using 9600\n");
}
switch (cflag & CSIZE) {
case CS5:
buf[1] |= SET_UART_FORMAT_SIZE_5;
break;
case CS6:
buf[1] |= SET_UART_FORMAT_SIZE_6;
break;
case CS7:
buf[1] |= SET_UART_FORMAT_SIZE_7;
break;
default:
case CS8:
buf[1] |= SET_UART_FORMAT_SIZE_8;
break;
}
buf[1] |= (cflag & CSTOPB) ? SET_UART_FORMAT_STOP_2 :
SET_UART_FORMAT_STOP_1;
if (cflag & PARENB) {
buf[1] |= (cflag & PARODD) ?
SET_UART_FORMAT_PAR_ODD : SET_UART_FORMAT_PAR_EVEN ;
} else {
buf[1] |= SET_UART_FORMAT_PAR_NONE;
}
uartdata = buf[0] | buf[1]<<8;
i = usb_control_msg(serial->dev, usb_sndctrlpipe(serial->dev, 0),
SET_UART_FORMAT_TYPE, SET_UART_FORMAT,
uartdata, 0, NULL, 0, 100);
if (i < 0)
dev_err(&port->dev, "Set UART format %#x failed (error = %d)\n",
uartdata, i);
dev_dbg(&port->dev, "0x21:0x40:0:0 %d\n", i);
if (cflag & CRTSCTS) {
spcp8x5_set_work_mode(port, 0x000a, SET_WORKING_MODE_U2C);
}
}
static int spcp8x5_open(struct tty_struct *tty, struct usb_serial_port *port)
{
struct usb_serial *serial = port->serial;
struct spcp8x5_private *priv = usb_get_serial_port_data(port);
int ret;
usb_clear_halt(serial->dev, port->write_urb->pipe);
usb_clear_halt(serial->dev, port->read_urb->pipe);
ret = usb_control_msg(serial->dev, usb_sndctrlpipe(serial->dev, 0),
0x09, 0x00,
0x01, 0x00, NULL, 0x00, 100);
if (ret)
return ret;
spcp8x5_set_ctrl_line(port, priv->line_control);
if (tty)
spcp8x5_set_termios(tty, port, NULL);
return usb_serial_generic_open(tty, port);
}
static int spcp8x5_tiocmset(struct tty_struct *tty,
unsigned int set, unsigned int clear)
{
struct usb_serial_port *port = tty->driver_data;
struct spcp8x5_private *priv = usb_get_serial_port_data(port);
unsigned long flags;
u8 control;
spin_lock_irqsave(&priv->lock, flags);
if (set & TIOCM_RTS)
priv->line_control |= MCR_RTS;
if (set & TIOCM_DTR)
priv->line_control |= MCR_DTR;
if (clear & TIOCM_RTS)
priv->line_control &= ~MCR_RTS;
if (clear & TIOCM_DTR)
priv->line_control &= ~MCR_DTR;
control = priv->line_control;
spin_unlock_irqrestore(&priv->lock, flags);
return spcp8x5_set_ctrl_line(port, control);
}
static int spcp8x5_tiocmget(struct tty_struct *tty)
{
struct usb_serial_port *port = tty->driver_data;
struct spcp8x5_private *priv = usb_get_serial_port_data(port);
unsigned long flags;
unsigned int mcr;
u8 status;
unsigned int result;
result = spcp8x5_get_msr(port, &status);
if (result)
return result;
spin_lock_irqsave(&priv->lock, flags);
mcr = priv->line_control;
spin_unlock_irqrestore(&priv->lock, flags);
result = ((mcr & MCR_DTR) ? TIOCM_DTR : 0)
| ((mcr & MCR_RTS) ? TIOCM_RTS : 0)
| ((status & MSR_STATUS_LINE_CTS) ? TIOCM_CTS : 0)
| ((status & MSR_STATUS_LINE_DSR) ? TIOCM_DSR : 0)
| ((status & MSR_STATUS_LINE_RI) ? TIOCM_RI : 0)
| ((status & MSR_STATUS_LINE_DCD) ? TIOCM_CD : 0);
return result;
}
