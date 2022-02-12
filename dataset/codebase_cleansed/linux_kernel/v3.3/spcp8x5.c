static int spcp8x5_startup(struct usb_serial *serial)
{
struct spcp8x5_private *priv;
int i;
enum spcp8x5_type type = SPCP825_007_TYPE;
u16 product = le16_to_cpu(serial->dev->descriptor.idProduct);
if (product == 0x0201)
type = SPCP825_007_TYPE;
else if (product == 0x0231)
type = SPCP835_TYPE;
else if (product == 0x0235)
type = SPCP825_008_TYPE;
else if (product == 0x0204)
type = SPCP825_INTERMATIC_TYPE;
else if (product == 0x0471 &&
serial->dev->descriptor.idVendor == cpu_to_le16(0x081e))
type = SPCP825_PHILIP_TYPE;
dev_dbg(&serial->dev->dev, "device type = %d\n", (int)type);
for (i = 0; i < serial->num_ports; ++i) {
priv = kzalloc(sizeof(struct spcp8x5_private), GFP_KERNEL);
if (!priv)
goto cleanup;
spin_lock_init(&priv->lock);
init_waitqueue_head(&priv->delta_msr_wait);
priv->type = type;
usb_set_serial_port_data(serial->port[i] , priv);
}
return 0;
cleanup:
for (--i; i >= 0; --i) {
priv = usb_get_serial_port_data(serial->port[i]);
kfree(priv);
usb_set_serial_port_data(serial->port[i] , NULL);
}
return -ENOMEM;
}
static void spcp8x5_release(struct usb_serial *serial)
{
int i;
for (i = 0; i < serial->num_ports; i++)
kfree(usb_get_serial_port_data(serial->port[i]));
}
static int spcp8x5_set_ctrlLine(struct usb_device *dev, u8 value,
enum spcp8x5_type type)
{
int retval;
u8 mcr = 0 ;
if (type == SPCP825_007_TYPE)
return -EPERM;
mcr = (unsigned short)value;
retval = usb_control_msg(dev, usb_sndctrlpipe(dev, 0),
SET_UART_STATUS_TYPE, SET_UART_STATUS,
mcr, 0x04, NULL, 0, 100);
if (retval != 0)
dev_dbg(&dev->dev, "usb_control_msg return %#x\n", retval);
return retval;
}
static int spcp8x5_get_msr(struct usb_device *dev, u8 *status,
enum spcp8x5_type type)
{
u8 *status_buffer;
int ret;
if (type == SPCP825_007_TYPE)
return -EPERM;
if (status == NULL)
return -EINVAL;
status_buffer = kmalloc(1, GFP_KERNEL);
if (!status_buffer)
return -ENOMEM;
status_buffer[0] = status[0];
ret = usb_control_msg(dev, usb_rcvctrlpipe(dev, 0),
GET_UART_STATUS, GET_UART_STATUS_TYPE,
0, GET_UART_STATUS_MSR, status_buffer, 1, 100);
if (ret < 0)
dev_dbg(&dev->dev, "Get MSR = 0x%p failed (error = %d)",
status_buffer, ret);
dev_dbg(&dev->dev, "0xc0:0x22:0:6 %d - 0x%p ", ret, status_buffer);
status[0] = status_buffer[0];
kfree(status_buffer);
return ret;
}
static void spcp8x5_set_workMode(struct usb_device *dev, u16 value,
u16 index, enum spcp8x5_type type)
{
int ret;
if (type == SPCP825_007_TYPE)
return;
ret = usb_control_msg(dev, usb_sndctrlpipe(dev, 0),
SET_WORKING_MODE_TYPE, SET_WORKING_MODE,
value, index, NULL, 0, 100);
dev_dbg(&dev->dev, "value = %#x , index = %#x\n", value, index);
if (ret < 0)
dev_dbg(&dev->dev,
"RTSCTS usb_control_msg(enable flowctrl) = %d\n", ret);
}
static int spcp8x5_carrier_raised(struct usb_serial_port *port)
{
struct spcp8x5_private *priv = usb_get_serial_port_data(port);
if (priv->line_status & MSR_STATUS_LINE_DCD)
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
spcp8x5_set_ctrlLine(port->serial->dev, control , priv->type);
}
static void spcp8x5_init_termios(struct tty_struct *tty)
{
*(tty->termios) = tty_std_termios;
tty->termios->c_cflag = B115200 | CS8 | CREAD | HUPCL | CLOCAL;
tty->termios->c_ispeed = 115200;
tty->termios->c_ospeed = 115200;
}
static void spcp8x5_set_termios(struct tty_struct *tty,
struct usb_serial_port *port, struct ktermios *old_termios)
{
struct usb_serial *serial = port->serial;
struct spcp8x5_private *priv = usb_get_serial_port_data(port);
unsigned long flags;
unsigned int cflag = tty->termios->c_cflag;
unsigned int old_cflag = old_termios->c_cflag;
unsigned short uartdata;
unsigned char buf[2] = {0, 0};
int baud;
int i;
u8 control;
if (!tty_termios_hw_change(tty->termios, old_termios))
return;
spin_lock_irqsave(&priv->lock, flags);
control = priv->line_control;
if ((old_cflag & CBAUD) == B0) {
priv->line_control |= MCR_DTR;
if (!(old_cflag & CRTSCTS))
priv->line_control |= MCR_RTS;
}
if (control != priv->line_control) {
control = priv->line_control;
spin_unlock_irqrestore(&priv->lock, flags);
spcp8x5_set_ctrlLine(serial->dev, control , priv->type);
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
dev_err(&port->dev, "spcp825 driver does not support the "
"baudrate requested, using default of 9600.\n");
}
if (cflag & CSIZE) {
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
}
buf[1] |= (cflag & CSTOPB) ? SET_UART_FORMAT_STOP_2 :
SET_UART_FORMAT_STOP_1;
if (cflag & PARENB) {
buf[1] |= (cflag & PARODD) ?
SET_UART_FORMAT_PAR_ODD : SET_UART_FORMAT_PAR_EVEN ;
} else
buf[1] |= SET_UART_FORMAT_PAR_NONE;
uartdata = buf[0] | buf[1]<<8;
i = usb_control_msg(serial->dev, usb_sndctrlpipe(serial->dev, 0),
SET_UART_FORMAT_TYPE, SET_UART_FORMAT,
uartdata, 0, NULL, 0, 100);
if (i < 0)
dev_err(&port->dev, "Set UART format %#x failed (error = %d)\n",
uartdata, i);
dbg("0x21:0x40:0:0 %d", i);
if (cflag & CRTSCTS) {
spcp8x5_set_workMode(serial->dev, 0x000a,
SET_WORKING_MODE_U2C, priv->type);
}
}
static int spcp8x5_open(struct tty_struct *tty, struct usb_serial_port *port)
{
struct ktermios tmp_termios;
struct usb_serial *serial = port->serial;
struct spcp8x5_private *priv = usb_get_serial_port_data(port);
int ret;
unsigned long flags;
u8 status = 0x30;
dbg("%s - port %d", __func__, port->number);
usb_clear_halt(serial->dev, port->write_urb->pipe);
usb_clear_halt(serial->dev, port->read_urb->pipe);
ret = usb_control_msg(serial->dev, usb_sndctrlpipe(serial->dev, 0),
0x09, 0x00,
0x01, 0x00, NULL, 0x00, 100);
if (ret)
return ret;
spcp8x5_set_ctrlLine(serial->dev, priv->line_control , priv->type);
if (tty)
spcp8x5_set_termios(tty, port, &tmp_termios);
spcp8x5_get_msr(serial->dev, &status, priv->type);
spin_lock_irqsave(&priv->lock, flags);
priv->line_status = status & 0xf0 ;
spin_unlock_irqrestore(&priv->lock, flags);
port->port.drain_delay = 256;
return usb_serial_generic_open(tty, port);
}
static void spcp8x5_process_read_urb(struct urb *urb)
{
struct usb_serial_port *port = urb->context;
struct spcp8x5_private *priv = usb_get_serial_port_data(port);
struct tty_struct *tty;
unsigned char *data = urb->transfer_buffer;
unsigned long flags;
u8 status;
char tty_flag;
tty_flag = TTY_NORMAL;
spin_lock_irqsave(&priv->lock, flags);
status = priv->line_status;
priv->line_status &= ~UART_STATE_TRANSIENT_MASK;
spin_unlock_irqrestore(&priv->lock, flags);
wake_up_interruptible(&priv->delta_msr_wait);
if (!urb->actual_length)
return;
tty = tty_port_tty_get(&port->port);
if (!tty)
return;
if (status & UART_STATE_TRANSIENT_MASK) {
if (status & UART_BREAK_ERROR)
tty_flag = TTY_BREAK;
else if (status & UART_PARITY_ERROR)
tty_flag = TTY_PARITY;
else if (status & UART_FRAME_ERROR)
tty_flag = TTY_FRAME;
dev_dbg(&port->dev, "tty_flag = %d\n", tty_flag);
if (status & UART_OVERRUN_ERROR)
tty_insert_flip_char(tty, 0, TTY_OVERRUN);
if (status & UART_DCD)
usb_serial_handle_dcd_change(port, tty,
priv->line_status & MSR_STATUS_LINE_DCD);
}
tty_insert_flip_string_fixed_flag(tty, data, tty_flag,
urb->actual_length);
tty_flip_buffer_push(tty);
tty_kref_put(tty);
}
static int spcp8x5_wait_modem_info(struct usb_serial_port *port,
unsigned int arg)
{
struct spcp8x5_private *priv = usb_get_serial_port_data(port);
unsigned long flags;
unsigned int prevstatus;
unsigned int status;
unsigned int changed;
spin_lock_irqsave(&priv->lock, flags);
prevstatus = priv->line_status;
spin_unlock_irqrestore(&priv->lock, flags);
while (1) {
interruptible_sleep_on(&priv->delta_msr_wait);
if (signal_pending(current))
return -ERESTARTSYS;
spin_lock_irqsave(&priv->lock, flags);
status = priv->line_status;
spin_unlock_irqrestore(&priv->lock, flags);
changed = prevstatus^status;
if (((arg & TIOCM_RNG) && (changed & MSR_STATUS_LINE_RI)) ||
((arg & TIOCM_DSR) && (changed & MSR_STATUS_LINE_DSR)) ||
((arg & TIOCM_CD) && (changed & MSR_STATUS_LINE_DCD)) ||
((arg & TIOCM_CTS) && (changed & MSR_STATUS_LINE_CTS)))
return 0;
prevstatus = status;
}
return 0;
}
static int spcp8x5_ioctl(struct tty_struct *tty,
unsigned int cmd, unsigned long arg)
{
struct usb_serial_port *port = tty->driver_data;
dbg("%s (%d) cmd = 0x%04x", __func__, port->number, cmd);
switch (cmd) {
case TIOCMIWAIT:
dbg("%s (%d) TIOCMIWAIT", __func__, port->number);
return spcp8x5_wait_modem_info(port, arg);
default:
dbg("%s not supported = 0x%04x", __func__, cmd);
break;
}
return -ENOIOCTLCMD;
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
return spcp8x5_set_ctrlLine(port->serial->dev, control , priv->type);
}
static int spcp8x5_tiocmget(struct tty_struct *tty)
{
struct usb_serial_port *port = tty->driver_data;
struct spcp8x5_private *priv = usb_get_serial_port_data(port);
unsigned long flags;
unsigned int mcr;
unsigned int status;
unsigned int result;
spin_lock_irqsave(&priv->lock, flags);
mcr = priv->line_control;
status = priv->line_status;
spin_unlock_irqrestore(&priv->lock, flags);
result = ((mcr & MCR_DTR) ? TIOCM_DTR : 0)
| ((mcr & MCR_RTS) ? TIOCM_RTS : 0)
| ((status & MSR_STATUS_LINE_CTS) ? TIOCM_CTS : 0)
| ((status & MSR_STATUS_LINE_DSR) ? TIOCM_DSR : 0)
| ((status & MSR_STATUS_LINE_RI) ? TIOCM_RI : 0)
| ((status & MSR_STATUS_LINE_DCD) ? TIOCM_CD : 0);
return result;
}
static int __init spcp8x5_init(void)
{
int retval;
retval = usb_serial_register(&spcp8x5_device);
if (retval)
goto failed_usb_serial_register;
retval = usb_register(&spcp8x5_driver);
if (retval)
goto failed_usb_register;
printk(KERN_INFO KBUILD_MODNAME ": " DRIVER_VERSION ":"
DRIVER_DESC "\n");
return 0;
failed_usb_register:
usb_serial_deregister(&spcp8x5_device);
failed_usb_serial_register:
return retval;
}
static void __exit spcp8x5_exit(void)
{
usb_deregister(&spcp8x5_driver);
usb_serial_deregister(&spcp8x5_device);
}
