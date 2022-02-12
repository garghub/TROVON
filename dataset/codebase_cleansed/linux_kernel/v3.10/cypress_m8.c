static inline bool is_frwd(struct usb_device *dev)
{
return ((le16_to_cpu(dev->descriptor.idVendor) == VENDOR_ID_FRWD) &&
(le16_to_cpu(dev->descriptor.idProduct) == PRODUCT_ID_CYPHIDCOM_FRWD));
}
static int analyze_baud_rate(struct usb_serial_port *port, speed_t new_rate)
{
struct cypress_private *priv;
priv = usb_get_serial_port_data(port);
if (unstable_bauds)
return new_rate;
if (is_frwd(port->serial->dev))
return new_rate;
if (port->serial->dev->speed == USB_SPEED_LOW) {
if (new_rate > 4800) {
dev_dbg(&port->dev,
"%s - failed setting baud rate, device incapable speed %d\n",
__func__, new_rate);
return -1;
}
}
switch (priv->chiptype) {
case CT_EARTHMATE:
if (new_rate <= 600) {
dev_dbg(&port->dev,
"%s - failed setting baud rate, unsupported speed of %d on Earthmate GPS",
__func__, new_rate);
return -1;
}
break;
default:
break;
}
return new_rate;
}
static int cypress_serial_control(struct tty_struct *tty,
struct usb_serial_port *port, speed_t baud_rate, int data_bits,
int stop_bits, int parity_enable, int parity_type, int reset,
int cypress_request_type)
{
int new_baudrate = 0, retval = 0, tries = 0;
struct cypress_private *priv;
struct device *dev = &port->dev;
u8 *feature_buffer;
const unsigned int feature_len = 5;
unsigned long flags;
priv = usb_get_serial_port_data(port);
if (!priv->comm_is_ok)
return -ENODEV;
feature_buffer = kcalloc(feature_len, sizeof(u8), GFP_KERNEL);
if (!feature_buffer)
return -ENOMEM;
switch (cypress_request_type) {
case CYPRESS_SET_CONFIG:
new_baudrate = priv->baud_rate;
if (baud_rate && baud_rate != priv->baud_rate) {
dev_dbg(dev, "%s - baud rate is changing\n", __func__);
retval = analyze_baud_rate(port, baud_rate);
if (retval >= 0) {
new_baudrate = retval;
dev_dbg(dev, "%s - New baud rate set to %d\n",
__func__, new_baudrate);
}
}
dev_dbg(dev, "%s - baud rate is being sent as %d\n", __func__,
new_baudrate);
put_unaligned_le32(new_baudrate, feature_buffer);
feature_buffer[4] |= data_bits;
feature_buffer[4] |= (stop_bits << 3);
feature_buffer[4] |= (parity_enable << 4);
feature_buffer[4] |= (parity_type << 5);
feature_buffer[4] |= (reset << 7);
dev_dbg(dev, "%s - device is being sent this feature report:\n", __func__);
dev_dbg(dev, "%s - %02X - %02X - %02X - %02X - %02X\n", __func__,
feature_buffer[0], feature_buffer[1],
feature_buffer[2], feature_buffer[3],
feature_buffer[4]);
do {
retval = usb_control_msg(port->serial->dev,
usb_sndctrlpipe(port->serial->dev, 0),
HID_REQ_SET_REPORT,
USB_DIR_OUT | USB_RECIP_INTERFACE | USB_TYPE_CLASS,
0x0300, 0, feature_buffer,
feature_len, 500);
if (tries++ >= 3)
break;
} while (retval != feature_len &&
retval != -ENODEV);
if (retval != feature_len) {
dev_err(dev, "%s - failed sending serial line settings - %d\n",
__func__, retval);
cypress_set_dead(port);
} else {
spin_lock_irqsave(&priv->lock, flags);
priv->baud_rate = new_baudrate;
priv->current_config = feature_buffer[4];
spin_unlock_irqrestore(&priv->lock, flags);
if (baud_rate)
tty_encode_baud_rate(tty,
new_baudrate, new_baudrate);
}
break;
case CYPRESS_GET_CONFIG:
if (priv->get_cfg_unsafe) {
retval = -ENOTTY;
goto out;
}
dev_dbg(dev, "%s - retreiving serial line settings\n", __func__);
do {
retval = usb_control_msg(port->serial->dev,
usb_rcvctrlpipe(port->serial->dev, 0),
HID_REQ_GET_REPORT,
USB_DIR_IN | USB_RECIP_INTERFACE | USB_TYPE_CLASS,
0x0300, 0, feature_buffer,
feature_len, 500);
if (tries++ >= 3)
break;
} while (retval != feature_len
&& retval != -ENODEV);
if (retval != feature_len) {
dev_err(dev, "%s - failed to retrieve serial line settings - %d\n",
__func__, retval);
cypress_set_dead(port);
goto out;
} else {
spin_lock_irqsave(&priv->lock, flags);
priv->current_config = feature_buffer[4];
priv->baud_rate = get_unaligned_le32(feature_buffer);
spin_unlock_irqrestore(&priv->lock, flags);
}
}
spin_lock_irqsave(&priv->lock, flags);
++priv->cmd_count;
spin_unlock_irqrestore(&priv->lock, flags);
out:
kfree(feature_buffer);
return retval;
}
static void cypress_set_dead(struct usb_serial_port *port)
{
struct cypress_private *priv = usb_get_serial_port_data(port);
unsigned long flags;
spin_lock_irqsave(&priv->lock, flags);
if (!priv->comm_is_ok) {
spin_unlock_irqrestore(&priv->lock, flags);
return;
}
priv->comm_is_ok = 0;
spin_unlock_irqrestore(&priv->lock, flags);
dev_err(&port->dev, "cypress_m8 suspending failing port %d - "
"interval might be too short\n", port->number);
}
static int cypress_generic_port_probe(struct usb_serial_port *port)
{
struct usb_serial *serial = port->serial;
struct cypress_private *priv;
priv = kzalloc(sizeof(struct cypress_private), GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->comm_is_ok = !0;
spin_lock_init(&priv->lock);
if (kfifo_alloc(&priv->write_fifo, CYPRESS_BUF_SIZE, GFP_KERNEL)) {
kfree(priv);
return -ENOMEM;
}
if (!is_frwd(serial->dev))
usb_reset_configuration(serial->dev);
priv->cmd_ctrl = 0;
priv->line_control = 0;
priv->termios_initialized = 0;
priv->rx_flags = 0;
if (port->interrupt_out_size > 9)
priv->pkt_fmt = packet_format_1;
else
priv->pkt_fmt = packet_format_2;
if (interval > 0) {
priv->write_urb_interval = interval;
priv->read_urb_interval = interval;
dev_dbg(&port->dev, "%s - read & write intervals forced to %d\n",
__func__, interval);
} else {
priv->write_urb_interval = port->interrupt_out_urb->interval;
priv->read_urb_interval = port->interrupt_in_urb->interval;
dev_dbg(&port->dev, "%s - intervals: read=%d write=%d\n",
__func__, priv->read_urb_interval,
priv->write_urb_interval);
}
usb_set_serial_port_data(port, priv);
return 0;
}
static int cypress_earthmate_port_probe(struct usb_serial_port *port)
{
struct usb_serial *serial = port->serial;
struct cypress_private *priv;
int ret;
ret = cypress_generic_port_probe(port);
if (ret) {
dev_dbg(&port->dev, "%s - Failed setting up port\n", __func__);
return ret;
}
priv = usb_get_serial_port_data(port);
priv->chiptype = CT_EARTHMATE;
priv->pkt_fmt = packet_format_1;
if (serial->dev->descriptor.idProduct !=
cpu_to_le16(PRODUCT_ID_EARTHMATEUSB)) {
dev_dbg(&port->dev,
"%s - Marking this device as unsafe for GET_CONFIG commands\n",
__func__);
priv->get_cfg_unsafe = !0;
}
return 0;
}
static int cypress_hidcom_port_probe(struct usb_serial_port *port)
{
struct cypress_private *priv;
int ret;
ret = cypress_generic_port_probe(port);
if (ret) {
dev_dbg(&port->dev, "%s - Failed setting up port\n", __func__);
return ret;
}
priv = usb_get_serial_port_data(port);
priv->chiptype = CT_CYPHIDCOM;
return 0;
}
static int cypress_ca42v2_port_probe(struct usb_serial_port *port)
{
struct cypress_private *priv;
int ret;
ret = cypress_generic_port_probe(port);
if (ret) {
dev_dbg(&port->dev, "%s - Failed setting up port\n", __func__);
return ret;
}
priv = usb_get_serial_port_data(port);
priv->chiptype = CT_CA42V2;
return 0;
}
static int cypress_port_remove(struct usb_serial_port *port)
{
struct cypress_private *priv;
priv = usb_get_serial_port_data(port);
kfifo_free(&priv->write_fifo);
kfree(priv);
return 0;
}
static int cypress_open(struct tty_struct *tty, struct usb_serial_port *port)
{
struct cypress_private *priv = usb_get_serial_port_data(port);
struct usb_serial *serial = port->serial;
unsigned long flags;
int result = 0;
if (!priv->comm_is_ok)
return -EIO;
usb_clear_halt(serial->dev, 0x81);
usb_clear_halt(serial->dev, 0x02);
spin_lock_irqsave(&priv->lock, flags);
priv->bytes_in = 0;
priv->bytes_out = 0;
priv->cmd_count = 0;
priv->rx_flags = 0;
spin_unlock_irqrestore(&priv->lock, flags);
cypress_send(port);
if (tty)
cypress_set_termios(tty, port, &priv->tmp_termios);
if (!port->interrupt_in_urb) {
dev_err(&port->dev, "%s - interrupt_in_urb is empty!\n",
__func__);
return -1;
}
usb_fill_int_urb(port->interrupt_in_urb, serial->dev,
usb_rcvintpipe(serial->dev, port->interrupt_in_endpointAddress),
port->interrupt_in_urb->transfer_buffer,
port->interrupt_in_urb->transfer_buffer_length,
cypress_read_int_callback, port, priv->read_urb_interval);
result = usb_submit_urb(port->interrupt_in_urb, GFP_KERNEL);
if (result) {
dev_err(&port->dev,
"%s - failed submitting read urb, error %d\n",
__func__, result);
cypress_set_dead(port);
}
port->port.drain_delay = 256;
return result;
}
static void cypress_dtr_rts(struct usb_serial_port *port, int on)
{
struct cypress_private *priv = usb_get_serial_port_data(port);
spin_lock_irq(&priv->lock);
if (on == 0)
priv->line_control = 0;
else
priv->line_control = CONTROL_DTR | CONTROL_RTS;
priv->cmd_ctrl = 1;
spin_unlock_irq(&priv->lock);
cypress_write(NULL, port, NULL, 0);
}
static void cypress_close(struct usb_serial_port *port)
{
struct cypress_private *priv = usb_get_serial_port_data(port);
unsigned long flags;
spin_lock_irqsave(&priv->lock, flags);
kfifo_reset_out(&priv->write_fifo);
spin_unlock_irqrestore(&priv->lock, flags);
dev_dbg(&port->dev, "%s - stopping urbs\n", __func__);
usb_kill_urb(port->interrupt_in_urb);
usb_kill_urb(port->interrupt_out_urb);
if (stats)
dev_info(&port->dev, "Statistics: %d Bytes In | %d Bytes Out | %d Commands Issued\n",
priv->bytes_in, priv->bytes_out, priv->cmd_count);
}
static int cypress_write(struct tty_struct *tty, struct usb_serial_port *port,
const unsigned char *buf, int count)
{
struct cypress_private *priv = usb_get_serial_port_data(port);
dev_dbg(&port->dev, "%s - port %d, %d bytes\n", __func__, port->number, count);
if (priv->cmd_ctrl) {
count = 0;
goto finish;
}
if (!count)
return count;
count = kfifo_in_locked(&priv->write_fifo, buf, count, &priv->lock);
finish:
cypress_send(port);
return count;
}
static void cypress_send(struct usb_serial_port *port)
{
int count = 0, result, offset, actual_size;
struct cypress_private *priv = usb_get_serial_port_data(port);
struct device *dev = &port->dev;
unsigned long flags;
if (!priv->comm_is_ok)
return;
dev_dbg(dev, "%s - interrupt out size is %d\n", __func__,
port->interrupt_out_size);
spin_lock_irqsave(&priv->lock, flags);
if (priv->write_urb_in_use) {
dev_dbg(dev, "%s - can't write, urb in use\n", __func__);
spin_unlock_irqrestore(&priv->lock, flags);
return;
}
spin_unlock_irqrestore(&priv->lock, flags);
memset(port->interrupt_out_urb->transfer_buffer, 0,
port->interrupt_out_size);
spin_lock_irqsave(&priv->lock, flags);
switch (priv->pkt_fmt) {
default:
case packet_format_1:
offset = 2;
port->interrupt_out_buffer[0] = priv->line_control;
break;
case packet_format_2:
offset = 1;
port->interrupt_out_buffer[0] = priv->line_control;
break;
}
if (priv->line_control & CONTROL_RESET)
priv->line_control &= ~CONTROL_RESET;
if (priv->cmd_ctrl) {
priv->cmd_count++;
dev_dbg(dev, "%s - line control command being issued\n", __func__);
spin_unlock_irqrestore(&priv->lock, flags);
goto send;
} else
spin_unlock_irqrestore(&priv->lock, flags);
count = kfifo_out_locked(&priv->write_fifo,
&port->interrupt_out_buffer[offset],
port->interrupt_out_size - offset,
&priv->lock);
if (count == 0)
return;
switch (priv->pkt_fmt) {
default:
case packet_format_1:
port->interrupt_out_buffer[1] = count;
break;
case packet_format_2:
port->interrupt_out_buffer[0] |= count;
}
dev_dbg(dev, "%s - count is %d\n", __func__, count);
send:
spin_lock_irqsave(&priv->lock, flags);
priv->write_urb_in_use = 1;
spin_unlock_irqrestore(&priv->lock, flags);
if (priv->cmd_ctrl)
actual_size = 1;
else
actual_size = count +
(priv->pkt_fmt == packet_format_1 ? 2 : 1);
usb_serial_debug_data(dev, __func__, port->interrupt_out_size,
port->interrupt_out_urb->transfer_buffer);
usb_fill_int_urb(port->interrupt_out_urb, port->serial->dev,
usb_sndintpipe(port->serial->dev, port->interrupt_out_endpointAddress),
port->interrupt_out_buffer, port->interrupt_out_size,
cypress_write_int_callback, port, priv->write_urb_interval);
result = usb_submit_urb(port->interrupt_out_urb, GFP_ATOMIC);
if (result) {
dev_err_console(port,
"%s - failed submitting write urb, error %d\n",
__func__, result);
priv->write_urb_in_use = 0;
cypress_set_dead(port);
}
spin_lock_irqsave(&priv->lock, flags);
if (priv->cmd_ctrl)
priv->cmd_ctrl = 0;
priv->bytes_out += count;
spin_unlock_irqrestore(&priv->lock, flags);
usb_serial_port_softint(port);
}
static int cypress_write_room(struct tty_struct *tty)
{
struct usb_serial_port *port = tty->driver_data;
struct cypress_private *priv = usb_get_serial_port_data(port);
int room = 0;
unsigned long flags;
spin_lock_irqsave(&priv->lock, flags);
room = kfifo_avail(&priv->write_fifo);
spin_unlock_irqrestore(&priv->lock, flags);
dev_dbg(&port->dev, "%s - returns %d\n", __func__, room);
return room;
}
static int cypress_tiocmget(struct tty_struct *tty)
{
struct usb_serial_port *port = tty->driver_data;
struct cypress_private *priv = usb_get_serial_port_data(port);
__u8 status, control;
unsigned int result = 0;
unsigned long flags;
spin_lock_irqsave(&priv->lock, flags);
control = priv->line_control;
status = priv->current_status;
spin_unlock_irqrestore(&priv->lock, flags);
result = ((control & CONTROL_DTR) ? TIOCM_DTR : 0)
| ((control & CONTROL_RTS) ? TIOCM_RTS : 0)
| ((status & UART_CTS) ? TIOCM_CTS : 0)
| ((status & UART_DSR) ? TIOCM_DSR : 0)
| ((status & UART_RI) ? TIOCM_RI : 0)
| ((status & UART_CD) ? TIOCM_CD : 0);
dev_dbg(&port->dev, "%s - result = %x\n", __func__, result);
return result;
}
static int cypress_tiocmset(struct tty_struct *tty,
unsigned int set, unsigned int clear)
{
struct usb_serial_port *port = tty->driver_data;
struct cypress_private *priv = usb_get_serial_port_data(port);
unsigned long flags;
spin_lock_irqsave(&priv->lock, flags);
if (set & TIOCM_RTS)
priv->line_control |= CONTROL_RTS;
if (set & TIOCM_DTR)
priv->line_control |= CONTROL_DTR;
if (clear & TIOCM_RTS)
priv->line_control &= ~CONTROL_RTS;
if (clear & TIOCM_DTR)
priv->line_control &= ~CONTROL_DTR;
priv->cmd_ctrl = 1;
spin_unlock_irqrestore(&priv->lock, flags);
return cypress_write(tty, port, NULL, 0);
}
static int cypress_tiocmiwait(struct tty_struct *tty, unsigned long arg)
{
struct usb_serial_port *port = tty->driver_data;
struct cypress_private *priv = usb_get_serial_port_data(port);
char diff;
for (;;) {
interruptible_sleep_on(&port->port.delta_msr_wait);
if (signal_pending(current))
return -ERESTARTSYS;
if (port->serial->disconnected)
return -EIO;
diff = priv->diff_status;
if (diff == 0)
return -EIO;
priv->diff_status = 0;
if (((arg & TIOCM_RNG) && (diff & UART_RI)) ||
((arg & TIOCM_DSR) && (diff & UART_DSR)) ||
((arg & TIOCM_CD) && (diff & UART_CD)) ||
((arg & TIOCM_CTS) && (diff & UART_CTS)))
return 0;
}
return 0;
}
static void cypress_set_termios(struct tty_struct *tty,
struct usb_serial_port *port, struct ktermios *old_termios)
{
struct cypress_private *priv = usb_get_serial_port_data(port);
struct device *dev = &port->dev;
int data_bits, stop_bits, parity_type, parity_enable;
unsigned cflag, iflag;
unsigned long flags;
__u8 oldlines;
int linechange = 0;
spin_lock_irqsave(&priv->lock, flags);
if (!priv->termios_initialized) {
if (priv->chiptype == CT_EARTHMATE) {
tty->termios = tty_std_termios;
tty->termios.c_cflag = B4800 | CS8 | CREAD | HUPCL |
CLOCAL;
tty->termios.c_ispeed = 4800;
tty->termios.c_ospeed = 4800;
} else if (priv->chiptype == CT_CYPHIDCOM) {
tty->termios = tty_std_termios;
tty->termios.c_cflag = B9600 | CS8 | CREAD | HUPCL |
CLOCAL;
tty->termios.c_ispeed = 9600;
tty->termios.c_ospeed = 9600;
} else if (priv->chiptype == CT_CA42V2) {
tty->termios = tty_std_termios;
tty->termios.c_cflag = B9600 | CS8 | CREAD | HUPCL |
CLOCAL;
tty->termios.c_ispeed = 9600;
tty->termios.c_ospeed = 9600;
}
priv->termios_initialized = 1;
}
spin_unlock_irqrestore(&priv->lock, flags);
tty->termios.c_cflag &= ~(CMSPAR|CRTSCTS);
cflag = tty->termios.c_cflag;
iflag = tty->termios.c_iflag;
if (old_termios) {
spin_lock_irqsave(&priv->lock, flags);
priv->tmp_termios = tty->termios;
spin_unlock_irqrestore(&priv->lock, flags);
}
stop_bits = cflag & CSTOPB ? 1 : 0;
if (cflag & PARENB) {
parity_enable = 1;
parity_type = cflag & PARODD ? 1 : 0;
} else
parity_enable = parity_type = 0;
switch (cflag & CSIZE) {
case CS5:
data_bits = 0;
break;
case CS6:
data_bits = 1;
break;
case CS7:
data_bits = 2;
break;
case CS8:
data_bits = 3;
break;
default:
dev_err(dev, "%s - CSIZE was set, but not CS5-CS8\n", __func__);
data_bits = 3;
}
spin_lock_irqsave(&priv->lock, flags);
oldlines = priv->line_control;
if ((cflag & CBAUD) == B0) {
dev_dbg(dev, "%s - dropping the lines, baud rate 0bps\n", __func__);
priv->line_control &= ~(CONTROL_DTR | CONTROL_RTS);
} else
priv->line_control = (CONTROL_DTR | CONTROL_RTS);
spin_unlock_irqrestore(&priv->lock, flags);
dev_dbg(dev, "%s - sending %d stop_bits, %d parity_enable, %d parity_type, %d data_bits (+5)\n",
__func__, stop_bits, parity_enable, parity_type, data_bits);
cypress_serial_control(tty, port, tty_get_baud_rate(tty),
data_bits, stop_bits,
parity_enable, parity_type,
0, CYPRESS_SET_CONFIG);
cypress_serial_control(tty, port, 0, 0, 0, 0, 0, 0, CYPRESS_GET_CONFIG);
spin_lock_irqsave(&priv->lock, flags);
if (priv->chiptype == CT_EARTHMATE && priv->baud_rate == 4800) {
dev_dbg(dev, "Using custom termios settings for a baud rate of 4800bps.\n");
tty->termios.c_iflag
&= ~(IGNBRK
| BRKINT
| PARMRK
| ISTRIP
| INLCR
| IGNCR
| ICRNL
| IXON);
tty->termios.c_oflag
&= ~OPOST;
tty->termios.c_lflag
&= ~(ECHO
| ECHONL
| ICANON
| ISIG
| IEXTEN);
}
linechange = (priv->line_control != oldlines);
spin_unlock_irqrestore(&priv->lock, flags);
if (linechange) {
priv->cmd_ctrl = 1;
cypress_write(tty, port, NULL, 0);
}
}
static int cypress_chars_in_buffer(struct tty_struct *tty)
{
struct usb_serial_port *port = tty->driver_data;
struct cypress_private *priv = usb_get_serial_port_data(port);
int chars = 0;
unsigned long flags;
spin_lock_irqsave(&priv->lock, flags);
chars = kfifo_len(&priv->write_fifo);
spin_unlock_irqrestore(&priv->lock, flags);
dev_dbg(&port->dev, "%s - returns %d\n", __func__, chars);
return chars;
}
static void cypress_throttle(struct tty_struct *tty)
{
struct usb_serial_port *port = tty->driver_data;
struct cypress_private *priv = usb_get_serial_port_data(port);
spin_lock_irq(&priv->lock);
priv->rx_flags = THROTTLED;
spin_unlock_irq(&priv->lock);
}
static void cypress_unthrottle(struct tty_struct *tty)
{
struct usb_serial_port *port = tty->driver_data;
struct cypress_private *priv = usb_get_serial_port_data(port);
int actually_throttled, result;
spin_lock_irq(&priv->lock);
actually_throttled = priv->rx_flags & ACTUALLY_THROTTLED;
priv->rx_flags = 0;
spin_unlock_irq(&priv->lock);
if (!priv->comm_is_ok)
return;
if (actually_throttled) {
result = usb_submit_urb(port->interrupt_in_urb, GFP_KERNEL);
if (result) {
dev_err(&port->dev, "%s - failed submitting read urb, "
"error %d\n", __func__, result);
cypress_set_dead(port);
}
}
}
static void cypress_read_int_callback(struct urb *urb)
{
struct usb_serial_port *port = urb->context;
struct cypress_private *priv = usb_get_serial_port_data(port);
struct device *dev = &urb->dev->dev;
struct tty_struct *tty;
unsigned char *data = urb->transfer_buffer;
unsigned long flags;
char tty_flag = TTY_NORMAL;
int havedata = 0;
int bytes = 0;
int result;
int i = 0;
int status = urb->status;
switch (status) {
case 0:
break;
case -ECONNRESET:
case -ENOENT:
case -ESHUTDOWN:
return;
case -EPIPE:
default:
dev_err(dev, "%s - unexpected nonzero read status received: %d\n",
__func__, status);
cypress_set_dead(port);
return;
}
spin_lock_irqsave(&priv->lock, flags);
if (priv->rx_flags & THROTTLED) {
dev_dbg(dev, "%s - now throttling\n", __func__);
priv->rx_flags |= ACTUALLY_THROTTLED;
spin_unlock_irqrestore(&priv->lock, flags);
return;
}
spin_unlock_irqrestore(&priv->lock, flags);
tty = tty_port_tty_get(&port->port);
if (!tty) {
dev_dbg(dev, "%s - bad tty pointer - exiting\n", __func__);
return;
}
spin_lock_irqsave(&priv->lock, flags);
result = urb->actual_length;
switch (priv->pkt_fmt) {
default:
case packet_format_1:
priv->current_status = data[0] & 0xF8;
bytes = data[1] + 2;
i = 2;
if (bytes > 2)
havedata = 1;
break;
case packet_format_2:
priv->current_status = data[0] & 0xF8;
bytes = (data[0] & 0x07) + 1;
i = 1;
if (bytes > 1)
havedata = 1;
break;
}
spin_unlock_irqrestore(&priv->lock, flags);
if (result < bytes) {
dev_dbg(dev,
"%s - wrong packet size - received %d bytes but packet said %d bytes\n",
__func__, result, bytes);
goto continue_read;
}
usb_serial_debug_data(&port->dev, __func__, urb->actual_length, data);
spin_lock_irqsave(&priv->lock, flags);
if (priv->current_status != priv->prev_status) {
priv->diff_status |= priv->current_status ^
priv->prev_status;
wake_up_interruptible(&port->port.delta_msr_wait);
priv->prev_status = priv->current_status;
}
spin_unlock_irqrestore(&priv->lock, flags);
if (tty && !(tty->termios.c_cflag & CLOCAL) &&
!(priv->current_status & UART_CD)) {
dev_dbg(dev, "%s - calling hangup\n", __func__);
tty_hangup(tty);
goto continue_read;
}
spin_lock_irqsave(&priv->lock, flags);
if (priv->current_status & CYP_ERROR) {
spin_unlock_irqrestore(&priv->lock, flags);
tty_flag = TTY_PARITY;
dev_dbg(dev, "%s - Parity Error detected\n", __func__);
} else
spin_unlock_irqrestore(&priv->lock, flags);
if (bytes > i) {
tty_insert_flip_string_fixed_flag(&port->port, data + i,
tty_flag, bytes - i);
tty_flip_buffer_push(&port->port);
}
spin_lock_irqsave(&priv->lock, flags);
priv->bytes_in += bytes;
spin_unlock_irqrestore(&priv->lock, flags);
continue_read:
tty_kref_put(tty);
if (priv->comm_is_ok) {
usb_fill_int_urb(port->interrupt_in_urb, port->serial->dev,
usb_rcvintpipe(port->serial->dev,
port->interrupt_in_endpointAddress),
port->interrupt_in_urb->transfer_buffer,
port->interrupt_in_urb->transfer_buffer_length,
cypress_read_int_callback, port,
priv->read_urb_interval);
result = usb_submit_urb(port->interrupt_in_urb, GFP_ATOMIC);
if (result && result != -EPERM) {
dev_err(dev, "%s - failed resubmitting read urb, error %d\n",
__func__, result);
cypress_set_dead(port);
}
}
}
static void cypress_write_int_callback(struct urb *urb)
{
struct usb_serial_port *port = urb->context;
struct cypress_private *priv = usb_get_serial_port_data(port);
struct device *dev = &urb->dev->dev;
int result;
int status = urb->status;
switch (status) {
case 0:
break;
case -ECONNRESET:
case -ENOENT:
case -ESHUTDOWN:
dev_dbg(dev, "%s - urb shutting down with status: %d\n",
__func__, status);
priv->write_urb_in_use = 0;
return;
case -EPIPE:
if (!priv->comm_is_ok)
break;
usb_clear_halt(port->serial->dev, 0x02);
dev_dbg(dev, "%s - nonzero write bulk status received: %d\n",
__func__, status);
port->interrupt_out_urb->transfer_buffer_length = 1;
result = usb_submit_urb(port->interrupt_out_urb, GFP_ATOMIC);
if (!result)
return;
dev_err(dev, "%s - failed resubmitting write urb, error %d\n",
__func__, result);
cypress_set_dead(port);
break;
default:
dev_err(dev, "%s - unexpected nonzero write status received: %d\n",
__func__, status);
cypress_set_dead(port);
break;
}
priv->write_urb_in_use = 0;
cypress_send(port);
}
