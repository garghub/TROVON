static int cp210x_get_config(struct usb_serial_port *port, u8 request,
unsigned int *data, int size)
{
struct usb_serial *serial = port->serial;
struct cp210x_port_private *port_priv = usb_get_serial_port_data(port);
__le32 *buf;
int result, i, length;
length = (((size - 1) | 3) + 1) / 4;
buf = kcalloc(length, sizeof(__le32), GFP_KERNEL);
if (!buf)
return -ENOMEM;
result = usb_control_msg(serial->dev, usb_rcvctrlpipe(serial->dev, 0),
request, REQTYPE_INTERFACE_TO_HOST, 0x0000,
port_priv->bInterfaceNumber, buf, size,
USB_CTRL_GET_TIMEOUT);
for (i = 0; i < length; i++)
data[i] = le32_to_cpu(buf[i]);
kfree(buf);
if (result != size) {
dev_dbg(&port->dev, "%s - Unable to send config request, request=0x%x size=%d result=%d\n",
__func__, request, size, result);
if (result > 0)
result = -EPROTO;
return result;
}
return 0;
}
static int cp210x_set_config(struct usb_serial_port *port, u8 request,
unsigned int *data, int size)
{
struct usb_serial *serial = port->serial;
struct cp210x_port_private *port_priv = usb_get_serial_port_data(port);
__le32 *buf;
int result, i, length;
length = (((size - 1) | 3) + 1) / 4;
buf = kmalloc(length * sizeof(__le32), GFP_KERNEL);
if (!buf)
return -ENOMEM;
for (i = 0; i < length; i++)
buf[i] = cpu_to_le32(data[i]);
if (size > 2) {
result = usb_control_msg(serial->dev,
usb_sndctrlpipe(serial->dev, 0),
request, REQTYPE_HOST_TO_INTERFACE, 0x0000,
port_priv->bInterfaceNumber, buf, size,
USB_CTRL_SET_TIMEOUT);
} else {
result = usb_control_msg(serial->dev,
usb_sndctrlpipe(serial->dev, 0),
request, REQTYPE_HOST_TO_INTERFACE, data[0],
port_priv->bInterfaceNumber, NULL, 0,
USB_CTRL_SET_TIMEOUT);
}
kfree(buf);
if ((size > 2 && result != size) || result < 0) {
dev_dbg(&port->dev, "%s - Unable to send request, request=0x%x size=%d result=%d\n",
__func__, request, size, result);
if (result > 0)
result = -EPROTO;
return result;
}
return 0;
}
static inline int cp210x_set_config_single(struct usb_serial_port *port,
u8 request, unsigned int data)
{
return cp210x_set_config(port, request, &data, 2);
}
static int cp210x_detect_swapped_line_ctl(struct usb_serial_port *port)
{
struct cp210x_port_private *port_priv = usb_get_serial_port_data(port);
unsigned int line_ctl_save;
unsigned int line_ctl_test;
int err;
err = cp210x_get_config(port, CP210X_GET_LINE_CTL, &line_ctl_save, 2);
if (err)
return err;
line_ctl_test = 0x800;
err = cp210x_set_config(port, CP210X_SET_LINE_CTL, &line_ctl_test, 2);
if (err)
return err;
err = cp210x_get_config(port, CP210X_GET_LINE_CTL, &line_ctl_test, 2);
if (err)
return err;
if (line_ctl_test == 8) {
port_priv->has_swapped_line_ctl = true;
line_ctl_save = swab16((u16)line_ctl_save);
}
return cp210x_set_config(port, CP210X_SET_LINE_CTL, &line_ctl_save, 2);
}
static int cp210x_get_line_ctl(struct usb_serial_port *port, unsigned int *ctl)
{
struct cp210x_port_private *port_priv = usb_get_serial_port_data(port);
int err;
err = cp210x_get_config(port, CP210X_GET_LINE_CTL, ctl, 2);
if (err)
return err;
if (port_priv->has_swapped_line_ctl)
*ctl = swab16((u16)(*ctl));
return 0;
}
static unsigned int cp210x_quantise_baudrate(unsigned int baud)
{
if (baud <= 300)
baud = 300;
else if (baud <= 600) baud = 600;
else if (baud <= 1200) baud = 1200;
else if (baud <= 1800) baud = 1800;
else if (baud <= 2400) baud = 2400;
else if (baud <= 4000) baud = 4000;
else if (baud <= 4803) baud = 4800;
else if (baud <= 7207) baud = 7200;
else if (baud <= 9612) baud = 9600;
else if (baud <= 14428) baud = 14400;
else if (baud <= 16062) baud = 16000;
else if (baud <= 19250) baud = 19200;
else if (baud <= 28912) baud = 28800;
else if (baud <= 38601) baud = 38400;
else if (baud <= 51558) baud = 51200;
else if (baud <= 56280) baud = 56000;
else if (baud <= 58053) baud = 57600;
else if (baud <= 64111) baud = 64000;
else if (baud <= 77608) baud = 76800;
else if (baud <= 117028) baud = 115200;
else if (baud <= 129347) baud = 128000;
else if (baud <= 156868) baud = 153600;
else if (baud <= 237832) baud = 230400;
else if (baud <= 254234) baud = 250000;
else if (baud <= 273066) baud = 256000;
else if (baud <= 491520) baud = 460800;
else if (baud <= 567138) baud = 500000;
else if (baud <= 670254) baud = 576000;
else if (baud < 1000000)
baud = 921600;
else if (baud > 2000000)
baud = 2000000;
return baud;
}
static int cp210x_open(struct tty_struct *tty, struct usb_serial_port *port)
{
int result;
result = cp210x_set_config_single(port, CP210X_IFC_ENABLE,
UART_ENABLE);
if (result) {
dev_err(&port->dev, "%s - Unable to enable UART\n", __func__);
return result;
}
cp210x_get_termios(tty, port);
if (tty)
cp210x_change_speed(tty, port, NULL);
return usb_serial_generic_open(tty, port);
}
static void cp210x_close(struct usb_serial_port *port)
{
unsigned int purge_ctl;
usb_serial_generic_close(port);
purge_ctl = PURGE_ALL;
cp210x_set_config(port, CP210X_PURGE, &purge_ctl, 2);
cp210x_set_config_single(port, CP210X_IFC_ENABLE, UART_DISABLE);
}
static int cp210x_get_tx_queue_byte_count(struct usb_serial_port *port,
u32 *count)
{
struct usb_serial *serial = port->serial;
struct cp210x_port_private *port_priv = usb_get_serial_port_data(port);
struct cp210x_comm_status *sts;
int result;
sts = kmalloc(sizeof(*sts), GFP_KERNEL);
if (!sts)
return -ENOMEM;
result = usb_control_msg(serial->dev, usb_rcvctrlpipe(serial->dev, 0),
CP210X_GET_COMM_STATUS, REQTYPE_INTERFACE_TO_HOST,
0, port_priv->bInterfaceNumber, sts, sizeof(*sts),
USB_CTRL_GET_TIMEOUT);
if (result == sizeof(*sts)) {
*count = le32_to_cpu(sts->ulAmountInOutQueue);
result = 0;
} else {
dev_err(&port->dev, "failed to get comm status: %d\n", result);
if (result >= 0)
result = -EPROTO;
}
kfree(sts);
return result;
}
static bool cp210x_tx_empty(struct usb_serial_port *port)
{
int err;
u32 count;
err = cp210x_get_tx_queue_byte_count(port, &count);
if (err)
return true;
return !count;
}
static void cp210x_get_termios(struct tty_struct *tty,
struct usb_serial_port *port)
{
unsigned int baud;
if (tty) {
cp210x_get_termios_port(tty->driver_data,
&tty->termios.c_cflag, &baud);
tty_encode_baud_rate(tty, baud, baud);
} else {
unsigned int cflag;
cflag = 0;
cp210x_get_termios_port(port, &cflag, &baud);
}
}
static void cp210x_get_termios_port(struct usb_serial_port *port,
unsigned int *cflagp, unsigned int *baudp)
{
struct device *dev = &port->dev;
unsigned int cflag, modem_ctl[4];
unsigned int baud;
unsigned int bits;
cp210x_get_config(port, CP210X_GET_BAUDRATE, &baud, 4);
dev_dbg(dev, "%s - baud rate = %d\n", __func__, baud);
*baudp = baud;
cflag = *cflagp;
cp210x_get_line_ctl(port, &bits);
cflag &= ~CSIZE;
switch (bits & BITS_DATA_MASK) {
case BITS_DATA_5:
dev_dbg(dev, "%s - data bits = 5\n", __func__);
cflag |= CS5;
break;
case BITS_DATA_6:
dev_dbg(dev, "%s - data bits = 6\n", __func__);
cflag |= CS6;
break;
case BITS_DATA_7:
dev_dbg(dev, "%s - data bits = 7\n", __func__);
cflag |= CS7;
break;
case BITS_DATA_8:
dev_dbg(dev, "%s - data bits = 8\n", __func__);
cflag |= CS8;
break;
case BITS_DATA_9:
dev_dbg(dev, "%s - data bits = 9 (not supported, using 8 data bits)\n", __func__);
cflag |= CS8;
bits &= ~BITS_DATA_MASK;
bits |= BITS_DATA_8;
cp210x_set_config(port, CP210X_SET_LINE_CTL, &bits, 2);
break;
default:
dev_dbg(dev, "%s - Unknown number of data bits, using 8\n", __func__);
cflag |= CS8;
bits &= ~BITS_DATA_MASK;
bits |= BITS_DATA_8;
cp210x_set_config(port, CP210X_SET_LINE_CTL, &bits, 2);
break;
}
switch (bits & BITS_PARITY_MASK) {
case BITS_PARITY_NONE:
dev_dbg(dev, "%s - parity = NONE\n", __func__);
cflag &= ~PARENB;
break;
case BITS_PARITY_ODD:
dev_dbg(dev, "%s - parity = ODD\n", __func__);
cflag |= (PARENB|PARODD);
break;
case BITS_PARITY_EVEN:
dev_dbg(dev, "%s - parity = EVEN\n", __func__);
cflag &= ~PARODD;
cflag |= PARENB;
break;
case BITS_PARITY_MARK:
dev_dbg(dev, "%s - parity = MARK\n", __func__);
cflag |= (PARENB|PARODD|CMSPAR);
break;
case BITS_PARITY_SPACE:
dev_dbg(dev, "%s - parity = SPACE\n", __func__);
cflag &= ~PARODD;
cflag |= (PARENB|CMSPAR);
break;
default:
dev_dbg(dev, "%s - Unknown parity mode, disabling parity\n", __func__);
cflag &= ~PARENB;
bits &= ~BITS_PARITY_MASK;
cp210x_set_config(port, CP210X_SET_LINE_CTL, &bits, 2);
break;
}
cflag &= ~CSTOPB;
switch (bits & BITS_STOP_MASK) {
case BITS_STOP_1:
dev_dbg(dev, "%s - stop bits = 1\n", __func__);
break;
case BITS_STOP_1_5:
dev_dbg(dev, "%s - stop bits = 1.5 (not supported, using 1 stop bit)\n", __func__);
bits &= ~BITS_STOP_MASK;
cp210x_set_config(port, CP210X_SET_LINE_CTL, &bits, 2);
break;
case BITS_STOP_2:
dev_dbg(dev, "%s - stop bits = 2\n", __func__);
cflag |= CSTOPB;
break;
default:
dev_dbg(dev, "%s - Unknown number of stop bits, using 1 stop bit\n", __func__);
bits &= ~BITS_STOP_MASK;
cp210x_set_config(port, CP210X_SET_LINE_CTL, &bits, 2);
break;
}
cp210x_get_config(port, CP210X_GET_FLOW, modem_ctl, 16);
if (modem_ctl[0] & 0x0008) {
dev_dbg(dev, "%s - flow control = CRTSCTS\n", __func__);
cflag |= CRTSCTS;
} else {
dev_dbg(dev, "%s - flow control = NONE\n", __func__);
cflag &= ~CRTSCTS;
}
*cflagp = cflag;
}
static void cp210x_change_speed(struct tty_struct *tty,
struct usb_serial_port *port, struct ktermios *old_termios)
{
u32 baud;
baud = tty->termios.c_ospeed;
baud = cp210x_quantise_baudrate(baud);
dev_dbg(&port->dev, "%s - setting baud rate to %u\n", __func__, baud);
if (cp210x_set_config(port, CP210X_SET_BAUDRATE, &baud,
sizeof(baud))) {
dev_warn(&port->dev, "failed to set baud rate to %u\n", baud);
if (old_termios)
baud = old_termios->c_ospeed;
else
baud = 9600;
}
tty_encode_baud_rate(tty, baud, baud);
}
static void cp210x_set_termios(struct tty_struct *tty,
struct usb_serial_port *port, struct ktermios *old_termios)
{
struct device *dev = &port->dev;
unsigned int cflag, old_cflag;
unsigned int bits;
unsigned int modem_ctl[4];
cflag = tty->termios.c_cflag;
old_cflag = old_termios->c_cflag;
if (tty->termios.c_ospeed != old_termios->c_ospeed)
cp210x_change_speed(tty, port, old_termios);
if ((cflag & CSIZE) != (old_cflag & CSIZE)) {
cp210x_get_line_ctl(port, &bits);
bits &= ~BITS_DATA_MASK;
switch (cflag & CSIZE) {
case CS5:
bits |= BITS_DATA_5;
dev_dbg(dev, "%s - data bits = 5\n", __func__);
break;
case CS6:
bits |= BITS_DATA_6;
dev_dbg(dev, "%s - data bits = 6\n", __func__);
break;
case CS7:
bits |= BITS_DATA_7;
dev_dbg(dev, "%s - data bits = 7\n", __func__);
break;
case CS8:
bits |= BITS_DATA_8;
dev_dbg(dev, "%s - data bits = 8\n", __func__);
break;
default:
dev_dbg(dev, "cp210x driver does not support the number of bits requested, using 8 bit mode\n");
bits |= BITS_DATA_8;
break;
}
if (cp210x_set_config(port, CP210X_SET_LINE_CTL, &bits, 2))
dev_dbg(dev, "Number of data bits requested not supported by device\n");
}
if ((cflag & (PARENB|PARODD|CMSPAR)) !=
(old_cflag & (PARENB|PARODD|CMSPAR))) {
cp210x_get_line_ctl(port, &bits);
bits &= ~BITS_PARITY_MASK;
if (cflag & PARENB) {
if (cflag & CMSPAR) {
if (cflag & PARODD) {
bits |= BITS_PARITY_MARK;
dev_dbg(dev, "%s - parity = MARK\n", __func__);
} else {
bits |= BITS_PARITY_SPACE;
dev_dbg(dev, "%s - parity = SPACE\n", __func__);
}
} else {
if (cflag & PARODD) {
bits |= BITS_PARITY_ODD;
dev_dbg(dev, "%s - parity = ODD\n", __func__);
} else {
bits |= BITS_PARITY_EVEN;
dev_dbg(dev, "%s - parity = EVEN\n", __func__);
}
}
}
if (cp210x_set_config(port, CP210X_SET_LINE_CTL, &bits, 2))
dev_dbg(dev, "Parity mode not supported by device\n");
}
if ((cflag & CSTOPB) != (old_cflag & CSTOPB)) {
cp210x_get_line_ctl(port, &bits);
bits &= ~BITS_STOP_MASK;
if (cflag & CSTOPB) {
bits |= BITS_STOP_2;
dev_dbg(dev, "%s - stop bits = 2\n", __func__);
} else {
bits |= BITS_STOP_1;
dev_dbg(dev, "%s - stop bits = 1\n", __func__);
}
if (cp210x_set_config(port, CP210X_SET_LINE_CTL, &bits, 2))
dev_dbg(dev, "Number of stop bits requested not supported by device\n");
}
if ((cflag & CRTSCTS) != (old_cflag & CRTSCTS)) {
cp210x_get_config(port, CP210X_GET_FLOW, modem_ctl, 16);
dev_dbg(dev, "%s - read modem controls = 0x%.4x 0x%.4x 0x%.4x 0x%.4x\n",
__func__, modem_ctl[0], modem_ctl[1],
modem_ctl[2], modem_ctl[3]);
if (cflag & CRTSCTS) {
modem_ctl[0] &= ~0x7B;
modem_ctl[0] |= 0x09;
modem_ctl[1] = 0x80;
dev_dbg(dev, "%s - flow control = CRTSCTS\n", __func__);
} else {
modem_ctl[0] &= ~0x7B;
modem_ctl[0] |= 0x01;
modem_ctl[1] |= 0x40;
dev_dbg(dev, "%s - flow control = NONE\n", __func__);
}
dev_dbg(dev, "%s - write modem controls = 0x%.4x 0x%.4x 0x%.4x 0x%.4x\n",
__func__, modem_ctl[0], modem_ctl[1],
modem_ctl[2], modem_ctl[3]);
cp210x_set_config(port, CP210X_SET_FLOW, modem_ctl, 16);
}
}
static int cp210x_tiocmset(struct tty_struct *tty,
unsigned int set, unsigned int clear)
{
struct usb_serial_port *port = tty->driver_data;
return cp210x_tiocmset_port(port, set, clear);
}
static int cp210x_tiocmset_port(struct usb_serial_port *port,
unsigned int set, unsigned int clear)
{
unsigned int control = 0;
if (set & TIOCM_RTS) {
control |= CONTROL_RTS;
control |= CONTROL_WRITE_RTS;
}
if (set & TIOCM_DTR) {
control |= CONTROL_DTR;
control |= CONTROL_WRITE_DTR;
}
if (clear & TIOCM_RTS) {
control &= ~CONTROL_RTS;
control |= CONTROL_WRITE_RTS;
}
if (clear & TIOCM_DTR) {
control &= ~CONTROL_DTR;
control |= CONTROL_WRITE_DTR;
}
dev_dbg(&port->dev, "%s - control = 0x%.4x\n", __func__, control);
return cp210x_set_config(port, CP210X_SET_MHS, &control, 2);
}
static void cp210x_dtr_rts(struct usb_serial_port *p, int on)
{
if (on)
cp210x_tiocmset_port(p, TIOCM_DTR|TIOCM_RTS, 0);
else
cp210x_tiocmset_port(p, 0, TIOCM_DTR|TIOCM_RTS);
}
static int cp210x_tiocmget(struct tty_struct *tty)
{
struct usb_serial_port *port = tty->driver_data;
unsigned int control;
int result;
cp210x_get_config(port, CP210X_GET_MDMSTS, &control, 1);
result = ((control & CONTROL_DTR) ? TIOCM_DTR : 0)
|((control & CONTROL_RTS) ? TIOCM_RTS : 0)
|((control & CONTROL_CTS) ? TIOCM_CTS : 0)
|((control & CONTROL_DSR) ? TIOCM_DSR : 0)
|((control & CONTROL_RING)? TIOCM_RI : 0)
|((control & CONTROL_DCD) ? TIOCM_CD : 0);
dev_dbg(&port->dev, "%s - control = 0x%.2x\n", __func__, control);
return result;
}
static void cp210x_break_ctl(struct tty_struct *tty, int break_state)
{
struct usb_serial_port *port = tty->driver_data;
unsigned int state;
if (break_state == 0)
state = BREAK_OFF;
else
state = BREAK_ON;
dev_dbg(&port->dev, "%s - turning break %s\n", __func__,
state == BREAK_OFF ? "off" : "on");
cp210x_set_config(port, CP210X_SET_BREAK, &state, 2);
}
static int cp210x_port_probe(struct usb_serial_port *port)
{
struct usb_serial *serial = port->serial;
struct usb_host_interface *cur_altsetting;
struct cp210x_port_private *port_priv;
int ret;
port_priv = kzalloc(sizeof(*port_priv), GFP_KERNEL);
if (!port_priv)
return -ENOMEM;
cur_altsetting = serial->interface->cur_altsetting;
port_priv->bInterfaceNumber = cur_altsetting->desc.bInterfaceNumber;
usb_set_serial_port_data(port, port_priv);
ret = cp210x_detect_swapped_line_ctl(port);
if (ret) {
kfree(port_priv);
return ret;
}
return 0;
}
static int cp210x_port_remove(struct usb_serial_port *port)
{
struct cp210x_port_private *port_priv;
port_priv = usb_get_serial_port_data(port);
kfree(port_priv);
return 0;
}
