static int upd78f0730_send_ctl(struct usb_serial_port *port,
const void *data, int size)
{
struct usb_device *usbdev = port->serial->dev;
void *buf;
int res;
if (size <= 0 || !data)
return -EINVAL;
buf = kmemdup(data, size, GFP_KERNEL);
if (!buf)
return -ENOMEM;
res = usb_control_msg(usbdev, usb_sndctrlpipe(usbdev, 0), 0x00,
USB_TYPE_VENDOR | USB_RECIP_DEVICE | USB_DIR_OUT,
0x0000, 0x0000, buf, size, USB_CTRL_SET_TIMEOUT);
kfree(buf);
if (res != size) {
struct device *dev = &port->dev;
dev_err(dev, "failed to send control request %02x: %d\n",
*(u8 *)data, res);
if (res >= 0)
res = -EIO;
return res;
}
return 0;
}
static int upd78f0730_port_probe(struct usb_serial_port *port)
{
struct upd78f0730_port_private *private;
private = kzalloc(sizeof(*private), GFP_KERNEL);
if (!private)
return -ENOMEM;
mutex_init(&private->lock);
usb_set_serial_port_data(port, private);
return 0;
}
static int upd78f0730_port_remove(struct usb_serial_port *port)
{
struct upd78f0730_port_private *private;
private = usb_get_serial_port_data(port);
mutex_destroy(&private->lock);
kfree(private);
return 0;
}
static int upd78f0730_tiocmget(struct tty_struct *tty)
{
struct device *dev = tty->dev;
struct upd78f0730_port_private *private;
struct usb_serial_port *port = tty->driver_data;
int signals;
int res;
private = usb_get_serial_port_data(port);
mutex_lock(&private->lock);
signals = private->line_signals;
mutex_unlock(&private->lock);
res = ((signals & UPD78F0730_DTR) ? TIOCM_DTR : 0) |
((signals & UPD78F0730_RTS) ? TIOCM_RTS : 0);
dev_dbg(dev, "%s - res = %x\n", __func__, res);
return res;
}
static int upd78f0730_tiocmset(struct tty_struct *tty,
unsigned int set, unsigned int clear)
{
struct device *dev = tty->dev;
struct usb_serial_port *port = tty->driver_data;
struct upd78f0730_port_private *private;
struct upd78f0730_set_dtr_rts request;
int res;
private = usb_get_serial_port_data(port);
mutex_lock(&private->lock);
if (set & TIOCM_DTR) {
private->line_signals |= UPD78F0730_DTR;
dev_dbg(dev, "%s - set DTR\n", __func__);
}
if (set & TIOCM_RTS) {
private->line_signals |= UPD78F0730_RTS;
dev_dbg(dev, "%s - set RTS\n", __func__);
}
if (clear & TIOCM_DTR) {
private->line_signals &= ~UPD78F0730_DTR;
dev_dbg(dev, "%s - clear DTR\n", __func__);
}
if (clear & TIOCM_RTS) {
private->line_signals &= ~UPD78F0730_RTS;
dev_dbg(dev, "%s - clear RTS\n", __func__);
}
request.opcode = UPD78F0730_CMD_SET_DTR_RTS;
request.params = private->line_signals;
res = upd78f0730_send_ctl(port, &request, sizeof(request));
mutex_unlock(&private->lock);
return res;
}
static void upd78f0730_break_ctl(struct tty_struct *tty, int break_state)
{
struct device *dev = tty->dev;
struct upd78f0730_port_private *private;
struct usb_serial_port *port = tty->driver_data;
struct upd78f0730_set_dtr_rts request;
private = usb_get_serial_port_data(port);
mutex_lock(&private->lock);
if (break_state) {
private->line_signals |= UPD78F0730_BREAK;
dev_dbg(dev, "%s - set BREAK\n", __func__);
} else {
private->line_signals &= ~UPD78F0730_BREAK;
dev_dbg(dev, "%s - clear BREAK\n", __func__);
}
request.opcode = UPD78F0730_CMD_SET_DTR_RTS;
request.params = private->line_signals;
upd78f0730_send_ctl(port, &request, sizeof(request));
mutex_unlock(&private->lock);
}
static void upd78f0730_dtr_rts(struct usb_serial_port *port, int on)
{
struct tty_struct *tty = port->port.tty;
unsigned int set = 0;
unsigned int clear = 0;
if (on)
set = TIOCM_DTR | TIOCM_RTS;
else
clear = TIOCM_DTR | TIOCM_RTS;
upd78f0730_tiocmset(tty, set, clear);
}
static speed_t upd78f0730_get_baud_rate(struct tty_struct *tty)
{
const speed_t baud_rate = tty_get_baud_rate(tty);
static const speed_t supported[] = {
0, 2400, 4800, 9600, 19200, 38400, 57600, 115200, 153600
};
int i;
for (i = ARRAY_SIZE(supported) - 1; i >= 0; i--) {
if (baud_rate == supported[i])
return baud_rate;
}
tty_encode_baud_rate(tty, 9600, 9600);
return tty_get_baud_rate(tty);
}
static void upd78f0730_set_termios(struct tty_struct *tty,
struct usb_serial_port *port,
struct ktermios *old_termios)
{
struct device *dev = &port->dev;
struct upd78f0730_line_control request;
speed_t baud_rate;
if (old_termios && !tty_termios_hw_change(&tty->termios, old_termios))
return;
if (C_BAUD(tty) == B0)
upd78f0730_dtr_rts(port, 0);
else if (old_termios && (old_termios->c_cflag & CBAUD) == B0)
upd78f0730_dtr_rts(port, 1);
baud_rate = upd78f0730_get_baud_rate(tty);
request.opcode = UPD78F0730_CMD_LINE_CONTROL;
request.baud_rate = cpu_to_le32(baud_rate);
request.params = 0;
dev_dbg(dev, "%s - baud rate = %d\n", __func__, baud_rate);
switch (C_CSIZE(tty)) {
case CS7:
request.params |= UPD78F0730_DATA_SIZE_7_BITS;
dev_dbg(dev, "%s - 7 data bits\n", __func__);
break;
default:
tty->termios.c_cflag &= ~CSIZE;
tty->termios.c_cflag |= CS8;
dev_warn(dev, "data size is not supported, using 8 bits\n");
case CS8:
request.params |= UPD78F0730_DATA_SIZE_8_BITS;
dev_dbg(dev, "%s - 8 data bits\n", __func__);
break;
}
if (C_PARENB(tty)) {
if (C_PARODD(tty)) {
request.params |= UPD78F0730_PARITY_ODD;
dev_dbg(dev, "%s - odd parity\n", __func__);
} else {
request.params |= UPD78F0730_PARITY_EVEN;
dev_dbg(dev, "%s - even parity\n", __func__);
}
if (C_CMSPAR(tty)) {
tty->termios.c_cflag &= ~CMSPAR;
dev_warn(dev, "MARK/SPACE parity is not supported\n");
}
} else {
request.params |= UPD78F0730_PARITY_NONE;
dev_dbg(dev, "%s - no parity\n", __func__);
}
if (C_CSTOPB(tty)) {
request.params |= UPD78F0730_STOP_BIT_2_BIT;
dev_dbg(dev, "%s - 2 stop bits\n", __func__);
} else {
request.params |= UPD78F0730_STOP_BIT_1_BIT;
dev_dbg(dev, "%s - 1 stop bit\n", __func__);
}
if (C_CRTSCTS(tty)) {
tty->termios.c_cflag &= ~CRTSCTS;
dev_warn(dev, "RTSCTS flow control is not supported\n");
}
if (I_IXOFF(tty) || I_IXON(tty)) {
tty->termios.c_iflag &= ~(IXOFF | IXON);
dev_warn(dev, "XON/XOFF flow control is not supported\n");
}
request.params |= UPD78F0730_FLOW_CONTROL_NONE;
dev_dbg(dev, "%s - no flow control\n", __func__);
upd78f0730_send_ctl(port, &request, sizeof(request));
}
static int upd78f0730_open(struct tty_struct *tty, struct usb_serial_port *port)
{
static const struct upd78f0730_open_close request = {
.opcode = UPD78F0730_CMD_OPEN_CLOSE,
.state = UPD78F0730_PORT_OPEN
};
int res;
res = upd78f0730_send_ctl(port, &request, sizeof(request));
if (res)
return res;
if (tty)
upd78f0730_set_termios(tty, port, NULL);
return usb_serial_generic_open(tty, port);
}
static void upd78f0730_close(struct usb_serial_port *port)
{
static const struct upd78f0730_open_close request = {
.opcode = UPD78F0730_CMD_OPEN_CLOSE,
.state = UPD78F0730_PORT_CLOSE
};
usb_serial_generic_close(port);
upd78f0730_send_ctl(port, &request, sizeof(request));
}
