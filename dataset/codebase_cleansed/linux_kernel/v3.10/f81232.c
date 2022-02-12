static void f81232_update_line_status(struct usb_serial_port *port,
unsigned char *data,
unsigned int actual_length)
{
}
static void f81232_read_int_callback(struct urb *urb)
{
struct usb_serial_port *port = urb->context;
unsigned char *data = urb->transfer_buffer;
unsigned int actual_length = urb->actual_length;
int status = urb->status;
int retval;
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
usb_serial_debug_data(&port->dev, __func__,
urb->actual_length, urb->transfer_buffer);
f81232_update_line_status(port, data, actual_length);
exit:
retval = usb_submit_urb(urb, GFP_ATOMIC);
if (retval)
dev_err(&urb->dev->dev,
"%s - usb_submit_urb failed with result %d\n",
__func__, retval);
}
static void f81232_process_read_urb(struct urb *urb)
{
struct usb_serial_port *port = urb->context;
struct f81232_private *priv = usb_get_serial_port_data(port);
unsigned char *data = urb->transfer_buffer;
char tty_flag = TTY_NORMAL;
unsigned long flags;
u8 line_status;
int i;
spin_lock_irqsave(&priv->lock, flags);
line_status = priv->line_status;
priv->line_status &= ~UART_STATE_TRANSIENT_MASK;
spin_unlock_irqrestore(&priv->lock, flags);
wake_up_interruptible(&port->port.delta_msr_wait);
if (!urb->actual_length)
return;
if (line_status & UART_BREAK_ERROR)
tty_flag = TTY_BREAK;
else if (line_status & UART_PARITY_ERROR)
tty_flag = TTY_PARITY;
else if (line_status & UART_FRAME_ERROR)
tty_flag = TTY_FRAME;
dev_dbg(&port->dev, "%s - tty_flag = %d\n", __func__, tty_flag);
if (line_status & UART_OVERRUN_ERROR)
tty_insert_flip_char(&port->port, 0, TTY_OVERRUN);
if (port->port.console && port->sysrq) {
for (i = 0; i < urb->actual_length; ++i)
if (!usb_serial_handle_sysrq_char(port, data[i]))
tty_insert_flip_char(&port->port, data[i],
tty_flag);
} else {
tty_insert_flip_string_fixed_flag(&port->port, data, tty_flag,
urb->actual_length);
}
tty_flip_buffer_push(&port->port);
}
static int set_control_lines(struct usb_device *dev, u8 value)
{
return 0;
}
static void f81232_break_ctl(struct tty_struct *tty, int break_state)
{
}
static void f81232_set_termios(struct tty_struct *tty,
struct usb_serial_port *port, struct ktermios *old_termios)
{
if (old_termios && !tty_termios_hw_change(&tty->termios, old_termios))
return;
if (old_termios)
tty_termios_copy_hw(&tty->termios, old_termios);
}
static int f81232_tiocmget(struct tty_struct *tty)
{
return 0;
}
static int f81232_tiocmset(struct tty_struct *tty,
unsigned int set, unsigned int clear)
{
return 0;
}
static int f81232_open(struct tty_struct *tty, struct usb_serial_port *port)
{
int result;
if (tty)
f81232_set_termios(tty, port, NULL);
result = usb_submit_urb(port->interrupt_in_urb, GFP_KERNEL);
if (result) {
dev_err(&port->dev, "%s - failed submitting interrupt urb,"
" error %d\n", __func__, result);
return result;
}
result = usb_serial_generic_open(tty, port);
if (result) {
usb_kill_urb(port->interrupt_in_urb);
return result;
}
port->port.drain_delay = 256;
return 0;
}
static void f81232_close(struct usb_serial_port *port)
{
usb_serial_generic_close(port);
usb_kill_urb(port->interrupt_in_urb);
}
static void f81232_dtr_rts(struct usb_serial_port *port, int on)
{
struct f81232_private *priv = usb_get_serial_port_data(port);
unsigned long flags;
u8 control;
spin_lock_irqsave(&priv->lock, flags);
if (on)
priv->line_control |= (CONTROL_DTR | CONTROL_RTS);
else
priv->line_control &= ~(CONTROL_DTR | CONTROL_RTS);
control = priv->line_control;
spin_unlock_irqrestore(&priv->lock, flags);
set_control_lines(port->serial->dev, control);
}
static int f81232_carrier_raised(struct usb_serial_port *port)
{
struct f81232_private *priv = usb_get_serial_port_data(port);
if (priv->line_status & UART_DCD)
return 1;
return 0;
}
static int f81232_tiocmiwait(struct tty_struct *tty, unsigned long arg)
{
struct usb_serial_port *port = tty->driver_data;
struct f81232_private *priv = usb_get_serial_port_data(port);
unsigned long flags;
unsigned int prevstatus;
unsigned int status;
unsigned int changed;
spin_lock_irqsave(&priv->lock, flags);
prevstatus = priv->line_status;
spin_unlock_irqrestore(&priv->lock, flags);
while (1) {
interruptible_sleep_on(&port->port.delta_msr_wait);
if (signal_pending(current))
return -ERESTARTSYS;
if (port->serial->disconnected)
return -EIO;
spin_lock_irqsave(&priv->lock, flags);
status = priv->line_status;
spin_unlock_irqrestore(&priv->lock, flags);
changed = prevstatus ^ status;
if (((arg & TIOCM_RNG) && (changed & UART_RING)) ||
((arg & TIOCM_DSR) && (changed & UART_DSR)) ||
((arg & TIOCM_CD) && (changed & UART_DCD)) ||
((arg & TIOCM_CTS) && (changed & UART_CTS))) {
return 0;
}
prevstatus = status;
}
return 0;
}
static int f81232_ioctl(struct tty_struct *tty,
unsigned int cmd, unsigned long arg)
{
struct serial_struct ser;
struct usb_serial_port *port = tty->driver_data;
dev_dbg(&port->dev, "%s (%d) cmd = 0x%04x\n", __func__,
port->number, cmd);
switch (cmd) {
case TIOCGSERIAL:
memset(&ser, 0, sizeof ser);
ser.type = PORT_16654;
ser.line = port->serial->minor;
ser.port = port->number;
ser.baud_base = 460800;
if (copy_to_user((void __user *)arg, &ser, sizeof ser))
return -EFAULT;
return 0;
default:
dev_dbg(&port->dev, "%s not supported = 0x%04x\n",
__func__, cmd);
break;
}
return -ENOIOCTLCMD;
}
static int f81232_port_probe(struct usb_serial_port *port)
{
struct f81232_private *priv;
priv = kzalloc(sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
spin_lock_init(&priv->lock);
usb_set_serial_port_data(port, priv);
return 0;
}
static int f81232_port_remove(struct usb_serial_port *port)
{
struct f81232_private *priv;
priv = usb_get_serial_port_data(port);
kfree(priv);
return 0;
}
