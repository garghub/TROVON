static int klsi_105_chg_port_settings(struct usb_serial_port *port,
struct klsi_105_port_settings *settings)
{
int rc;
rc = usb_control_msg(port->serial->dev,
usb_sndctrlpipe(port->serial->dev, 0),
KL5KUSB105A_SIO_SET_DATA,
USB_TYPE_VENDOR | USB_DIR_OUT | USB_RECIP_INTERFACE,
0,
0,
settings,
sizeof(struct klsi_105_port_settings),
KLSI_TIMEOUT);
if (rc < 0)
dev_err(&port->dev,
"Change port settings failed (error = %d)\n", rc);
dev_info(&port->serial->dev->dev,
"%d byte block, baudrate %x, databits %d, u1 %d, u2 %d\n",
settings->pktlen, settings->baudrate, settings->databits,
settings->unknown1, settings->unknown2);
return rc;
}
static unsigned long klsi_105_status2linestate(const __u16 status)
{
unsigned long res = 0;
res = ((status & KL5KUSB105A_DSR) ? TIOCM_DSR : 0)
| ((status & KL5KUSB105A_CTS) ? TIOCM_CTS : 0)
;
return res;
}
static int klsi_105_get_line_state(struct usb_serial_port *port,
unsigned long *line_state_p)
{
int rc;
u8 *status_buf;
__u16 status;
dev_info(&port->serial->dev->dev, "sending SIO Poll request\n");
status_buf = kmalloc(KLSI_STATUSBUF_LEN, GFP_KERNEL);
if (!status_buf) {
dev_err(&port->dev, "%s - out of memory for status buffer.\n",
__func__);
return -ENOMEM;
}
status_buf[0] = 0xff;
status_buf[1] = 0xff;
rc = usb_control_msg(port->serial->dev,
usb_rcvctrlpipe(port->serial->dev, 0),
KL5KUSB105A_SIO_POLL,
USB_TYPE_VENDOR | USB_DIR_IN,
0,
0,
status_buf, KLSI_STATUSBUF_LEN,
10000
);
if (rc < 0)
dev_err(&port->dev, "Reading line status failed (error = %d)\n",
rc);
else {
status = get_unaligned_le16(status_buf);
dev_info(&port->serial->dev->dev, "read status %x %x",
status_buf[0], status_buf[1]);
*line_state_p = klsi_105_status2linestate(status);
}
kfree(status_buf);
return rc;
}
static int klsi_105_port_probe(struct usb_serial_port *port)
{
struct klsi_105_private *priv;
priv = kmalloc(sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->cfg.pktlen = 5;
priv->cfg.baudrate = kl5kusb105a_sio_b9600;
priv->cfg.databits = kl5kusb105a_dtb_8;
priv->cfg.unknown1 = 0;
priv->cfg.unknown2 = 1;
priv->line_state = 0;
spin_lock_init(&priv->lock);
usb_set_serial_port_data(port, priv);
return 0;
}
static int klsi_105_port_remove(struct usb_serial_port *port)
{
struct klsi_105_private *priv;
priv = usb_get_serial_port_data(port);
kfree(priv);
return 0;
}
static int klsi_105_open(struct tty_struct *tty, struct usb_serial_port *port)
{
struct klsi_105_private *priv = usb_get_serial_port_data(port);
int retval = 0;
int rc;
int i;
unsigned long line_state;
struct klsi_105_port_settings *cfg;
unsigned long flags;
cfg = kmalloc(sizeof(*cfg), GFP_KERNEL);
if (!cfg) {
dev_err(&port->dev, "%s - out of memory for config buffer.\n",
__func__);
return -ENOMEM;
}
cfg->pktlen = 5;
cfg->baudrate = kl5kusb105a_sio_b9600;
cfg->databits = kl5kusb105a_dtb_8;
cfg->unknown1 = 0;
cfg->unknown2 = 1;
klsi_105_chg_port_settings(port, cfg);
spin_lock_irqsave(&priv->lock, flags);
priv->termios.c_iflag = tty->termios.c_iflag;
priv->termios.c_oflag = tty->termios.c_oflag;
priv->termios.c_cflag = tty->termios.c_cflag;
priv->termios.c_lflag = tty->termios.c_lflag;
for (i = 0; i < NCCS; i++)
priv->termios.c_cc[i] = tty->termios.c_cc[i];
priv->cfg.pktlen = cfg->pktlen;
priv->cfg.baudrate = cfg->baudrate;
priv->cfg.databits = cfg->databits;
priv->cfg.unknown1 = cfg->unknown1;
priv->cfg.unknown2 = cfg->unknown2;
spin_unlock_irqrestore(&priv->lock, flags);
rc = usb_serial_generic_open(tty, port);
if (rc) {
retval = rc;
goto exit;
}
rc = usb_control_msg(port->serial->dev,
usb_sndctrlpipe(port->serial->dev, 0),
KL5KUSB105A_SIO_CONFIGURE,
USB_TYPE_VENDOR|USB_DIR_OUT|USB_RECIP_INTERFACE,
KL5KUSB105A_SIO_CONFIGURE_READ_ON,
0,
NULL,
0,
KLSI_TIMEOUT);
if (rc < 0) {
dev_err(&port->dev, "Enabling read failed (error = %d)\n", rc);
retval = rc;
} else
dev_dbg(&port->dev, "%s - enabled reading\n", __func__);
rc = klsi_105_get_line_state(port, &line_state);
if (rc >= 0) {
spin_lock_irqsave(&priv->lock, flags);
priv->line_state = line_state;
spin_unlock_irqrestore(&priv->lock, flags);
dev_dbg(&port->dev, "%s - read line state 0x%lx\n", __func__, line_state);
retval = 0;
} else
retval = rc;
exit:
kfree(cfg);
return retval;
}
static void klsi_105_close(struct usb_serial_port *port)
{
int rc;
rc = usb_control_msg(port->serial->dev,
usb_sndctrlpipe(port->serial->dev, 0),
KL5KUSB105A_SIO_CONFIGURE,
USB_TYPE_VENDOR | USB_DIR_OUT,
KL5KUSB105A_SIO_CONFIGURE_READ_OFF,
0,
NULL, 0,
KLSI_TIMEOUT);
if (rc < 0)
dev_err(&port->dev, "failed to disable read: %d\n", rc);
usb_serial_generic_close(port);
}
static int klsi_105_prepare_write_buffer(struct usb_serial_port *port,
void *dest, size_t size)
{
unsigned char *buf = dest;
int count;
count = kfifo_out_locked(&port->write_fifo, buf + KLSI_HDR_LEN, size,
&port->lock);
put_unaligned_le16(count, buf);
return count + KLSI_HDR_LEN;
}
static void klsi_105_process_read_urb(struct urb *urb)
{
struct usb_serial_port *port = urb->context;
unsigned char *data = urb->transfer_buffer;
unsigned len;
if (!urb->actual_length)
return;
if (urb->actual_length <= KLSI_HDR_LEN) {
dev_dbg(&port->dev, "%s - malformed packet\n", __func__);
return;
}
len = get_unaligned_le16(data);
if (len > urb->actual_length - KLSI_HDR_LEN) {
dev_dbg(&port->dev, "%s - packet length mismatch\n", __func__);
len = urb->actual_length - KLSI_HDR_LEN;
}
tty_insert_flip_string(&port->port, data + KLSI_HDR_LEN, len);
tty_flip_buffer_push(&port->port);
}
static void klsi_105_set_termios(struct tty_struct *tty,
struct usb_serial_port *port,
struct ktermios *old_termios)
{
struct klsi_105_private *priv = usb_get_serial_port_data(port);
struct device *dev = &port->dev;
unsigned int iflag = tty->termios.c_iflag;
unsigned int old_iflag = old_termios->c_iflag;
unsigned int cflag = tty->termios.c_cflag;
unsigned int old_cflag = old_termios->c_cflag;
struct klsi_105_port_settings *cfg;
unsigned long flags;
speed_t baud;
cfg = kmalloc(sizeof(*cfg), GFP_KERNEL);
if (!cfg) {
dev_err(dev, "%s - out of memory for config buffer.\n", __func__);
return;
}
spin_lock_irqsave(&priv->lock, flags);
baud = tty_get_baud_rate(tty);
if ((cflag & CBAUD) != (old_cflag & CBAUD)) {
if ((old_cflag & CBAUD) == B0) {
dev_dbg(dev, "%s: baud was B0\n", __func__);
#if 0
priv->control_state |= TIOCM_DTR;
if (!(old_cflag & CRTSCTS))
priv->control_state |= TIOCM_RTS;
mct_u232_set_modem_ctrl(serial, priv->control_state);
#endif
}
}
switch (baud) {
case 0:
break;
case 1200:
priv->cfg.baudrate = kl5kusb105a_sio_b1200;
break;
case 2400:
priv->cfg.baudrate = kl5kusb105a_sio_b2400;
break;
case 4800:
priv->cfg.baudrate = kl5kusb105a_sio_b4800;
break;
case 9600:
priv->cfg.baudrate = kl5kusb105a_sio_b9600;
break;
case 19200:
priv->cfg.baudrate = kl5kusb105a_sio_b19200;
break;
case 38400:
priv->cfg.baudrate = kl5kusb105a_sio_b38400;
break;
case 57600:
priv->cfg.baudrate = kl5kusb105a_sio_b57600;
break;
case 115200:
priv->cfg.baudrate = kl5kusb105a_sio_b115200;
break;
default:
dev_dbg(dev, "KLSI USB->Serial converter: unsupported baudrate request, using default of 9600");
priv->cfg.baudrate = kl5kusb105a_sio_b9600;
baud = 9600;
break;
}
if ((cflag & CBAUD) == B0) {
dev_dbg(dev, "%s: baud is B0\n", __func__);
;
#if 0
priv->control_state &= ~(TIOCM_DTR | TIOCM_RTS);
mct_u232_set_modem_ctrl(serial, priv->control_state);
#endif
}
tty_encode_baud_rate(tty, baud, baud);
if ((cflag & CSIZE) != (old_cflag & CSIZE)) {
switch (cflag & CSIZE) {
case CS5:
dev_dbg(dev, "%s - 5 bits/byte not supported\n", __func__);
spin_unlock_irqrestore(&priv->lock, flags);
goto err;
case CS6:
dev_dbg(dev, "%s - 6 bits/byte not supported\n", __func__);
spin_unlock_irqrestore(&priv->lock, flags);
goto err;
case CS7:
priv->cfg.databits = kl5kusb105a_dtb_7;
break;
case CS8:
priv->cfg.databits = kl5kusb105a_dtb_8;
break;
default:
dev_err(dev, "CSIZE was not CS5-CS8, using default of 8\n");
priv->cfg.databits = kl5kusb105a_dtb_8;
break;
}
}
if ((cflag & (PARENB|PARODD)) != (old_cflag & (PARENB|PARODD))
|| (cflag & CSTOPB) != (old_cflag & CSTOPB)) {
tty->termios.c_cflag &= ~(PARENB|PARODD|CSTOPB);
#if 0
priv->last_lcr = 0;
if (cflag & PARENB)
priv->last_lcr |= (cflag & PARODD) ?
MCT_U232_PARITY_ODD : MCT_U232_PARITY_EVEN;
else
priv->last_lcr |= MCT_U232_PARITY_NONE;
priv->last_lcr |= (cflag & CSTOPB) ?
MCT_U232_STOP_BITS_2 : MCT_U232_STOP_BITS_1;
mct_u232_set_line_ctrl(serial, priv->last_lcr);
#endif
;
}
if ((iflag & IXOFF) != (old_iflag & IXOFF)
|| (iflag & IXON) != (old_iflag & IXON)
|| (cflag & CRTSCTS) != (old_cflag & CRTSCTS)) {
tty->termios.c_cflag &= ~CRTSCTS;
#if 0
if ((iflag & IXOFF) || (iflag & IXON) || (cflag & CRTSCTS))
priv->control_state |= TIOCM_DTR | TIOCM_RTS;
else
priv->control_state &= ~(TIOCM_DTR | TIOCM_RTS);
mct_u232_set_modem_ctrl(serial, priv->control_state);
#endif
;
}
memcpy(cfg, &priv->cfg, sizeof(*cfg));
spin_unlock_irqrestore(&priv->lock, flags);
klsi_105_chg_port_settings(port, cfg);
err:
kfree(cfg);
}
static int klsi_105_tiocmget(struct tty_struct *tty)
{
struct usb_serial_port *port = tty->driver_data;
struct klsi_105_private *priv = usb_get_serial_port_data(port);
unsigned long flags;
int rc;
unsigned long line_state;
rc = klsi_105_get_line_state(port, &line_state);
if (rc < 0) {
dev_err(&port->dev,
"Reading line control failed (error = %d)\n", rc);
return rc;
}
spin_lock_irqsave(&priv->lock, flags);
priv->line_state = line_state;
spin_unlock_irqrestore(&priv->lock, flags);
dev_dbg(&port->dev, "%s - read line state 0x%lx\n", __func__, line_state);
return (int)line_state;
}
static int klsi_105_tiocmset(struct tty_struct *tty,
unsigned int set, unsigned int clear)
{
int retval = -EINVAL;
return retval;
}
