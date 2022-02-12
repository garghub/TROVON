static int cp210x_read_reg_block(struct usb_serial_port *port, u8 req,
void *buf, int bufsize)
{
struct usb_serial *serial = port->serial;
struct cp210x_port_private *port_priv = usb_get_serial_port_data(port);
void *dmabuf;
int result;
dmabuf = kmalloc(bufsize, GFP_KERNEL);
if (!dmabuf) {
memset(buf, 0, bufsize);
return -ENOMEM;
}
result = usb_control_msg(serial->dev, usb_rcvctrlpipe(serial->dev, 0),
req, REQTYPE_INTERFACE_TO_HOST, 0,
port_priv->bInterfaceNumber, dmabuf, bufsize,
USB_CTRL_SET_TIMEOUT);
if (result == bufsize) {
memcpy(buf, dmabuf, bufsize);
result = 0;
} else {
dev_err(&port->dev, "failed get req 0x%x size %d status: %d\n",
req, bufsize, result);
if (result >= 0)
result = -EPROTO;
memset(buf, 0, bufsize);
}
kfree(dmabuf);
return result;
}
static int cp210x_read_u32_reg(struct usb_serial_port *port, u8 req, u32 *val)
{
__le32 le32_val;
int err;
err = cp210x_read_reg_block(port, req, &le32_val, sizeof(le32_val));
if (err) {
*val = 0;
return err;
}
*val = le32_to_cpu(le32_val);
return 0;
}
static int cp210x_read_u16_reg(struct usb_serial_port *port, u8 req, u16 *val)
{
__le16 le16_val;
int err;
err = cp210x_read_reg_block(port, req, &le16_val, sizeof(le16_val));
if (err)
return err;
*val = le16_to_cpu(le16_val);
return 0;
}
static int cp210x_read_u8_reg(struct usb_serial_port *port, u8 req, u8 *val)
{
return cp210x_read_reg_block(port, req, val, sizeof(*val));
}
static int cp210x_write_u16_reg(struct usb_serial_port *port, u8 req, u16 val)
{
struct usb_serial *serial = port->serial;
struct cp210x_port_private *port_priv = usb_get_serial_port_data(port);
int result;
result = usb_control_msg(serial->dev, usb_sndctrlpipe(serial->dev, 0),
req, REQTYPE_HOST_TO_INTERFACE, val,
port_priv->bInterfaceNumber, NULL, 0,
USB_CTRL_SET_TIMEOUT);
if (result < 0) {
dev_err(&port->dev, "failed set request 0x%x status: %d\n",
req, result);
}
return result;
}
static int cp210x_write_reg_block(struct usb_serial_port *port, u8 req,
void *buf, int bufsize)
{
struct usb_serial *serial = port->serial;
struct cp210x_port_private *port_priv = usb_get_serial_port_data(port);
void *dmabuf;
int result;
dmabuf = kmalloc(bufsize, GFP_KERNEL);
if (!dmabuf)
return -ENOMEM;
memcpy(dmabuf, buf, bufsize);
result = usb_control_msg(serial->dev, usb_sndctrlpipe(serial->dev, 0),
req, REQTYPE_HOST_TO_INTERFACE, 0,
port_priv->bInterfaceNumber, dmabuf, bufsize,
USB_CTRL_SET_TIMEOUT);
kfree(dmabuf);
if (result == bufsize) {
result = 0;
} else {
dev_err(&port->dev, "failed set req 0x%x size %d status: %d\n",
req, bufsize, result);
if (result >= 0)
result = -EPROTO;
}
return result;
}
static int cp210x_write_u32_reg(struct usb_serial_port *port, u8 req, u32 val)
{
__le32 le32_val;
le32_val = cpu_to_le32(val);
return cp210x_write_reg_block(port, req, &le32_val, sizeof(le32_val));
}
static int cp210x_detect_swapped_line_ctl(struct usb_serial_port *port)
{
struct cp210x_port_private *port_priv = usb_get_serial_port_data(port);
u16 line_ctl_save;
u16 line_ctl_test;
int err;
err = cp210x_read_u16_reg(port, CP210X_GET_LINE_CTL, &line_ctl_save);
if (err)
return err;
err = cp210x_write_u16_reg(port, CP210X_SET_LINE_CTL, 0x800);
if (err)
return err;
err = cp210x_read_u16_reg(port, CP210X_GET_LINE_CTL, &line_ctl_test);
if (err)
return err;
if (line_ctl_test == 8) {
port_priv->has_swapped_line_ctl = true;
line_ctl_save = swab16(line_ctl_save);
}
return cp210x_write_u16_reg(port, CP210X_SET_LINE_CTL, line_ctl_save);
}
static int cp210x_get_line_ctl(struct usb_serial_port *port, u16 *ctl)
{
struct cp210x_port_private *port_priv = usb_get_serial_port_data(port);
int err;
err = cp210x_read_u16_reg(port, CP210X_GET_LINE_CTL, ctl);
if (err)
return err;
if (port_priv->has_swapped_line_ctl)
*ctl = swab16(*ctl);
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
result = cp210x_write_u16_reg(port, CP210X_IFC_ENABLE, UART_ENABLE);
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
usb_serial_generic_close(port);
cp210x_write_u16_reg(port, CP210X_PURGE, PURGE_ALL);
cp210x_write_u16_reg(port, CP210X_IFC_ENABLE, UART_DISABLE);
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
unsigned int cflag;
u8 modem_ctl[16];
u32 baud;
u16 bits;
cp210x_read_u32_reg(port, CP210X_GET_BAUDRATE, &baud);
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
cp210x_write_u16_reg(port, CP210X_SET_LINE_CTL, bits);
break;
default:
dev_dbg(dev, "%s - Unknown number of data bits, using 8\n", __func__);
cflag |= CS8;
bits &= ~BITS_DATA_MASK;
bits |= BITS_DATA_8;
cp210x_write_u16_reg(port, CP210X_SET_LINE_CTL, bits);
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
cp210x_write_u16_reg(port, CP210X_SET_LINE_CTL, bits);
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
cp210x_write_u16_reg(port, CP210X_SET_LINE_CTL, bits);
break;
case BITS_STOP_2:
dev_dbg(dev, "%s - stop bits = 2\n", __func__);
cflag |= CSTOPB;
break;
default:
dev_dbg(dev, "%s - Unknown number of stop bits, using 1 stop bit\n", __func__);
bits &= ~BITS_STOP_MASK;
cp210x_write_u16_reg(port, CP210X_SET_LINE_CTL, bits);
break;
}
cp210x_read_reg_block(port, CP210X_GET_FLOW, modem_ctl,
sizeof(modem_ctl));
if (modem_ctl[0] & 0x08) {
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
if (cp210x_write_u32_reg(port, CP210X_SET_BAUDRATE, baud)) {
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
u16 bits;
u8 modem_ctl[16];
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
if (cp210x_write_u16_reg(port, CP210X_SET_LINE_CTL, bits))
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
if (cp210x_write_u16_reg(port, CP210X_SET_LINE_CTL, bits))
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
if (cp210x_write_u16_reg(port, CP210X_SET_LINE_CTL, bits))
dev_dbg(dev, "Number of stop bits requested not supported by device\n");
}
if ((cflag & CRTSCTS) != (old_cflag & CRTSCTS)) {
cp210x_read_reg_block(port, CP210X_GET_FLOW, modem_ctl,
sizeof(modem_ctl));
dev_dbg(dev, "%s - read modem controls = %02x .. .. .. %02x .. .. %02x\n",
__func__, modem_ctl[0], modem_ctl[4], modem_ctl[7]);
if (cflag & CRTSCTS) {
modem_ctl[0] &= ~0x7B;
modem_ctl[0] |= 0x09;
modem_ctl[4] = 0x80;
modem_ctl[5] = 0;
modem_ctl[6] = 0;
modem_ctl[7] = 0;
dev_dbg(dev, "%s - flow control = CRTSCTS\n", __func__);
} else {
modem_ctl[0] &= ~0x7B;
modem_ctl[0] |= 0x01;
modem_ctl[4] |= 0x40;
dev_dbg(dev, "%s - flow control = NONE\n", __func__);
}
dev_dbg(dev, "%s - write modem controls = %02x .. .. .. %02x .. .. %02x\n",
__func__, modem_ctl[0], modem_ctl[4], modem_ctl[7]);
cp210x_write_reg_block(port, CP210X_SET_FLOW, modem_ctl,
sizeof(modem_ctl));
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
u16 control = 0;
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
return cp210x_write_u16_reg(port, CP210X_SET_MHS, control);
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
u8 control;
int result;
cp210x_read_u8_reg(port, CP210X_GET_MDMSTS, &control);
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
u16 state;
if (break_state == 0)
state = BREAK_OFF;
else
state = BREAK_ON;
dev_dbg(&port->dev, "%s - turning break %s\n", __func__,
state == BREAK_OFF ? "off" : "on");
cp210x_write_u16_reg(port, CP210X_SET_BREAK, state);
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
