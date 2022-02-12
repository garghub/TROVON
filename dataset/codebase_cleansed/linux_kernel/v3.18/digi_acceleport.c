static long cond_wait_interruptible_timeout_irqrestore(
wait_queue_head_t *q, long timeout,
spinlock_t *lock, unsigned long flags)
__releases(lock)
{
DEFINE_WAIT(wait);
prepare_to_wait(q, &wait, TASK_INTERRUPTIBLE);
spin_unlock_irqrestore(lock, flags);
timeout = schedule_timeout(timeout);
finish_wait(q, &wait);
return timeout;
}
static void digi_wakeup_write_lock(struct work_struct *work)
{
struct digi_port *priv =
container_of(work, struct digi_port, dp_wakeup_work);
struct usb_serial_port *port = priv->dp_port;
unsigned long flags;
spin_lock_irqsave(&priv->dp_port_lock, flags);
tty_port_tty_wakeup(&port->port);
spin_unlock_irqrestore(&priv->dp_port_lock, flags);
}
static int digi_write_oob_command(struct usb_serial_port *port,
unsigned char *buf, int count, int interruptible)
{
int ret = 0;
int len;
struct usb_serial_port *oob_port = (struct usb_serial_port *)((struct digi_serial *)(usb_get_serial_data(port->serial)))->ds_oob_port;
struct digi_port *oob_priv = usb_get_serial_port_data(oob_port);
unsigned long flags = 0;
dev_dbg(&port->dev,
"digi_write_oob_command: TOP: port=%d, count=%d\n",
oob_priv->dp_port_num, count);
spin_lock_irqsave(&oob_priv->dp_port_lock, flags);
while (count > 0) {
while (oob_priv->dp_write_urb_in_use) {
cond_wait_interruptible_timeout_irqrestore(
&oob_port->write_wait, DIGI_RETRY_TIMEOUT,
&oob_priv->dp_port_lock, flags);
if (interruptible && signal_pending(current))
return -EINTR;
spin_lock_irqsave(&oob_priv->dp_port_lock, flags);
}
len = min(count, oob_port->bulk_out_size);
if (len > 4)
len &= ~3;
memcpy(oob_port->write_urb->transfer_buffer, buf, len);
oob_port->write_urb->transfer_buffer_length = len;
ret = usb_submit_urb(oob_port->write_urb, GFP_ATOMIC);
if (ret == 0) {
oob_priv->dp_write_urb_in_use = 1;
count -= len;
buf += len;
}
}
spin_unlock_irqrestore(&oob_priv->dp_port_lock, flags);
if (ret)
dev_err(&port->dev, "%s: usb_submit_urb failed, ret=%d\n",
__func__, ret);
return ret;
}
static int digi_write_inb_command(struct usb_serial_port *port,
unsigned char *buf, int count, unsigned long timeout)
{
int ret = 0;
int len;
struct digi_port *priv = usb_get_serial_port_data(port);
unsigned char *data = port->write_urb->transfer_buffer;
unsigned long flags = 0;
dev_dbg(&port->dev, "digi_write_inb_command: TOP: port=%d, count=%d\n",
priv->dp_port_num, count);
if (timeout)
timeout += jiffies;
else
timeout = ULONG_MAX;
spin_lock_irqsave(&priv->dp_port_lock, flags);
while (count > 0 && ret == 0) {
while (priv->dp_write_urb_in_use &&
time_before(jiffies, timeout)) {
cond_wait_interruptible_timeout_irqrestore(
&port->write_wait, DIGI_RETRY_TIMEOUT,
&priv->dp_port_lock, flags);
if (signal_pending(current))
return -EINTR;
spin_lock_irqsave(&priv->dp_port_lock, flags);
}
len = min(count, port->bulk_out_size-2-priv->dp_out_buf_len);
if (len > 4)
len &= ~3;
if (priv->dp_out_buf_len > 0) {
data[0] = DIGI_CMD_SEND_DATA;
data[1] = priv->dp_out_buf_len;
memcpy(data + 2, priv->dp_out_buf,
priv->dp_out_buf_len);
memcpy(data + 2 + priv->dp_out_buf_len, buf, len);
port->write_urb->transfer_buffer_length
= priv->dp_out_buf_len + 2 + len;
} else {
memcpy(data, buf, len);
port->write_urb->transfer_buffer_length = len;
}
ret = usb_submit_urb(port->write_urb, GFP_ATOMIC);
if (ret == 0) {
priv->dp_write_urb_in_use = 1;
priv->dp_out_buf_len = 0;
count -= len;
buf += len;
}
}
spin_unlock_irqrestore(&priv->dp_port_lock, flags);
if (ret)
dev_err(&port->dev,
"%s: usb_submit_urb failed, ret=%d, port=%d\n",
__func__, ret, priv->dp_port_num);
return ret;
}
static int digi_set_modem_signals(struct usb_serial_port *port,
unsigned int modem_signals, int interruptible)
{
int ret;
struct digi_port *port_priv = usb_get_serial_port_data(port);
struct usb_serial_port *oob_port = (struct usb_serial_port *) ((struct digi_serial *)(usb_get_serial_data(port->serial)))->ds_oob_port;
struct digi_port *oob_priv = usb_get_serial_port_data(oob_port);
unsigned char *data = oob_port->write_urb->transfer_buffer;
unsigned long flags = 0;
dev_dbg(&port->dev,
"digi_set_modem_signals: TOP: port=%d, modem_signals=0x%x\n",
port_priv->dp_port_num, modem_signals);
spin_lock_irqsave(&oob_priv->dp_port_lock, flags);
spin_lock(&port_priv->dp_port_lock);
while (oob_priv->dp_write_urb_in_use) {
spin_unlock(&port_priv->dp_port_lock);
cond_wait_interruptible_timeout_irqrestore(
&oob_port->write_wait, DIGI_RETRY_TIMEOUT,
&oob_priv->dp_port_lock, flags);
if (interruptible && signal_pending(current))
return -EINTR;
spin_lock_irqsave(&oob_priv->dp_port_lock, flags);
spin_lock(&port_priv->dp_port_lock);
}
data[0] = DIGI_CMD_SET_DTR_SIGNAL;
data[1] = port_priv->dp_port_num;
data[2] = (modem_signals & TIOCM_DTR) ?
DIGI_DTR_ACTIVE : DIGI_DTR_INACTIVE;
data[3] = 0;
data[4] = DIGI_CMD_SET_RTS_SIGNAL;
data[5] = port_priv->dp_port_num;
data[6] = (modem_signals & TIOCM_RTS) ?
DIGI_RTS_ACTIVE : DIGI_RTS_INACTIVE;
data[7] = 0;
oob_port->write_urb->transfer_buffer_length = 8;
ret = usb_submit_urb(oob_port->write_urb, GFP_ATOMIC);
if (ret == 0) {
oob_priv->dp_write_urb_in_use = 1;
port_priv->dp_modem_signals =
(port_priv->dp_modem_signals&~(TIOCM_DTR|TIOCM_RTS))
| (modem_signals&(TIOCM_DTR|TIOCM_RTS));
}
spin_unlock(&port_priv->dp_port_lock);
spin_unlock_irqrestore(&oob_priv->dp_port_lock, flags);
if (ret)
dev_err(&port->dev, "%s: usb_submit_urb failed, ret=%d\n",
__func__, ret);
return ret;
}
static int digi_transmit_idle(struct usb_serial_port *port,
unsigned long timeout)
{
int ret;
unsigned char buf[2];
struct digi_port *priv = usb_get_serial_port_data(port);
unsigned long flags = 0;
spin_lock_irqsave(&priv->dp_port_lock, flags);
priv->dp_transmit_idle = 0;
spin_unlock_irqrestore(&priv->dp_port_lock, flags);
buf[0] = DIGI_CMD_TRANSMIT_IDLE;
buf[1] = 0;
timeout += jiffies;
ret = digi_write_inb_command(port, buf, 2, timeout - jiffies);
if (ret != 0)
return ret;
spin_lock_irqsave(&priv->dp_port_lock, flags);
while (time_before(jiffies, timeout) && !priv->dp_transmit_idle) {
cond_wait_interruptible_timeout_irqrestore(
&priv->dp_transmit_idle_wait, DIGI_RETRY_TIMEOUT,
&priv->dp_port_lock, flags);
if (signal_pending(current))
return -EINTR;
spin_lock_irqsave(&priv->dp_port_lock, flags);
}
priv->dp_transmit_idle = 0;
spin_unlock_irqrestore(&priv->dp_port_lock, flags);
return 0;
}
static void digi_rx_throttle(struct tty_struct *tty)
{
unsigned long flags;
struct usb_serial_port *port = tty->driver_data;
struct digi_port *priv = usb_get_serial_port_data(port);
spin_lock_irqsave(&priv->dp_port_lock, flags);
priv->dp_throttled = 1;
priv->dp_throttle_restart = 0;
spin_unlock_irqrestore(&priv->dp_port_lock, flags);
}
static void digi_rx_unthrottle(struct tty_struct *tty)
{
int ret = 0;
unsigned long flags;
struct usb_serial_port *port = tty->driver_data;
struct digi_port *priv = usb_get_serial_port_data(port);
spin_lock_irqsave(&priv->dp_port_lock, flags);
if (priv->dp_throttle_restart)
ret = usb_submit_urb(port->read_urb, GFP_ATOMIC);
priv->dp_throttled = 0;
priv->dp_throttle_restart = 0;
spin_unlock_irqrestore(&priv->dp_port_lock, flags);
if (ret)
dev_err(&port->dev,
"%s: usb_submit_urb failed, ret=%d, port=%d\n",
__func__, ret, priv->dp_port_num);
}
static void digi_set_termios(struct tty_struct *tty,
struct usb_serial_port *port, struct ktermios *old_termios)
{
struct digi_port *priv = usb_get_serial_port_data(port);
struct device *dev = &port->dev;
unsigned int iflag = tty->termios.c_iflag;
unsigned int cflag = tty->termios.c_cflag;
unsigned int old_iflag = old_termios->c_iflag;
unsigned int old_cflag = old_termios->c_cflag;
unsigned char buf[32];
unsigned int modem_signals;
int arg, ret;
int i = 0;
speed_t baud;
dev_dbg(dev,
"digi_set_termios: TOP: port=%d, iflag=0x%x, old_iflag=0x%x, cflag=0x%x, old_cflag=0x%x\n",
priv->dp_port_num, iflag, old_iflag, cflag, old_cflag);
baud = tty_get_baud_rate(tty);
if (baud != tty_termios_baud_rate(old_termios)) {
arg = -1;
if ((old_cflag&CBAUD) == B0) {
modem_signals = TIOCM_DTR;
if (!(tty->termios.c_cflag & CRTSCTS) ||
!test_bit(TTY_THROTTLED, &tty->flags))
modem_signals |= TIOCM_RTS;
digi_set_modem_signals(port, modem_signals, 1);
}
switch (baud) {
case 0: digi_set_modem_signals(port, 0, 1); break;
case 50: arg = DIGI_BAUD_50; break;
case 75: arg = DIGI_BAUD_75; break;
case 110: arg = DIGI_BAUD_110; break;
case 150: arg = DIGI_BAUD_150; break;
case 200: arg = DIGI_BAUD_200; break;
case 300: arg = DIGI_BAUD_300; break;
case 600: arg = DIGI_BAUD_600; break;
case 1200: arg = DIGI_BAUD_1200; break;
case 1800: arg = DIGI_BAUD_1800; break;
case 2400: arg = DIGI_BAUD_2400; break;
case 4800: arg = DIGI_BAUD_4800; break;
case 9600: arg = DIGI_BAUD_9600; break;
case 19200: arg = DIGI_BAUD_19200; break;
case 38400: arg = DIGI_BAUD_38400; break;
case 57600: arg = DIGI_BAUD_57600; break;
case 115200: arg = DIGI_BAUD_115200; break;
case 230400: arg = DIGI_BAUD_230400; break;
case 460800: arg = DIGI_BAUD_460800; break;
default:
arg = DIGI_BAUD_9600;
baud = 9600;
break;
}
if (arg != -1) {
buf[i++] = DIGI_CMD_SET_BAUD_RATE;
buf[i++] = priv->dp_port_num;
buf[i++] = arg;
buf[i++] = 0;
}
}
tty->termios.c_cflag &= ~CMSPAR;
if ((cflag&(PARENB|PARODD)) != (old_cflag&(PARENB|PARODD))) {
if (cflag&PARENB) {
if (cflag&PARODD)
arg = DIGI_PARITY_ODD;
else
arg = DIGI_PARITY_EVEN;
} else {
arg = DIGI_PARITY_NONE;
}
buf[i++] = DIGI_CMD_SET_PARITY;
buf[i++] = priv->dp_port_num;
buf[i++] = arg;
buf[i++] = 0;
}
if ((cflag&CSIZE) != (old_cflag&CSIZE)) {
arg = -1;
switch (cflag&CSIZE) {
case CS5: arg = DIGI_WORD_SIZE_5; break;
case CS6: arg = DIGI_WORD_SIZE_6; break;
case CS7: arg = DIGI_WORD_SIZE_7; break;
case CS8: arg = DIGI_WORD_SIZE_8; break;
default:
dev_dbg(dev,
"digi_set_termios: can't handle word size %d\n",
(cflag&CSIZE));
break;
}
if (arg != -1) {
buf[i++] = DIGI_CMD_SET_WORD_SIZE;
buf[i++] = priv->dp_port_num;
buf[i++] = arg;
buf[i++] = 0;
}
}
if ((cflag&CSTOPB) != (old_cflag&CSTOPB)) {
if ((cflag&CSTOPB))
arg = DIGI_STOP_BITS_2;
else
arg = DIGI_STOP_BITS_1;
buf[i++] = DIGI_CMD_SET_STOP_BITS;
buf[i++] = priv->dp_port_num;
buf[i++] = arg;
buf[i++] = 0;
}
if ((iflag&IXOFF) != (old_iflag&IXOFF)
|| (cflag&CRTSCTS) != (old_cflag&CRTSCTS)) {
arg = 0;
if (iflag&IXOFF)
arg |= DIGI_INPUT_FLOW_CONTROL_XON_XOFF;
else
arg &= ~DIGI_INPUT_FLOW_CONTROL_XON_XOFF;
if (cflag&CRTSCTS) {
arg |= DIGI_INPUT_FLOW_CONTROL_RTS;
buf[i++] = DIGI_CMD_SET_RTS_SIGNAL;
buf[i++] = priv->dp_port_num;
buf[i++] = DIGI_RTS_ACTIVE;
buf[i++] = 0;
} else {
arg &= ~DIGI_INPUT_FLOW_CONTROL_RTS;
}
buf[i++] = DIGI_CMD_SET_INPUT_FLOW_CONTROL;
buf[i++] = priv->dp_port_num;
buf[i++] = arg;
buf[i++] = 0;
}
if ((iflag & IXON) != (old_iflag & IXON)
|| (cflag & CRTSCTS) != (old_cflag & CRTSCTS)) {
arg = 0;
if (iflag & IXON)
arg |= DIGI_OUTPUT_FLOW_CONTROL_XON_XOFF;
else
arg &= ~DIGI_OUTPUT_FLOW_CONTROL_XON_XOFF;
if (cflag & CRTSCTS) {
arg |= DIGI_OUTPUT_FLOW_CONTROL_CTS;
} else {
arg &= ~DIGI_OUTPUT_FLOW_CONTROL_CTS;
}
buf[i++] = DIGI_CMD_SET_OUTPUT_FLOW_CONTROL;
buf[i++] = priv->dp_port_num;
buf[i++] = arg;
buf[i++] = 0;
}
if ((cflag & CREAD) != (old_cflag & CREAD)) {
if (cflag & CREAD)
arg = DIGI_ENABLE;
else
arg = DIGI_DISABLE;
buf[i++] = DIGI_CMD_RECEIVE_ENABLE;
buf[i++] = priv->dp_port_num;
buf[i++] = arg;
buf[i++] = 0;
}
ret = digi_write_oob_command(port, buf, i, 1);
if (ret != 0)
dev_dbg(dev, "digi_set_termios: write oob failed, ret=%d\n", ret);
tty_encode_baud_rate(tty, baud, baud);
}
static void digi_break_ctl(struct tty_struct *tty, int break_state)
{
struct usb_serial_port *port = tty->driver_data;
unsigned char buf[4];
buf[0] = DIGI_CMD_BREAK_CONTROL;
buf[1] = 2;
buf[2] = break_state ? 1 : 0;
buf[3] = 0;
digi_write_inb_command(port, buf, 4, 0);
}
static int digi_tiocmget(struct tty_struct *tty)
{
struct usb_serial_port *port = tty->driver_data;
struct digi_port *priv = usb_get_serial_port_data(port);
unsigned int val;
unsigned long flags;
spin_lock_irqsave(&priv->dp_port_lock, flags);
val = priv->dp_modem_signals;
spin_unlock_irqrestore(&priv->dp_port_lock, flags);
return val;
}
static int digi_tiocmset(struct tty_struct *tty,
unsigned int set, unsigned int clear)
{
struct usb_serial_port *port = tty->driver_data;
struct digi_port *priv = usb_get_serial_port_data(port);
unsigned int val;
unsigned long flags;
spin_lock_irqsave(&priv->dp_port_lock, flags);
val = (priv->dp_modem_signals & ~clear) | set;
spin_unlock_irqrestore(&priv->dp_port_lock, flags);
return digi_set_modem_signals(port, val, 1);
}
static int digi_write(struct tty_struct *tty, struct usb_serial_port *port,
const unsigned char *buf, int count)
{
int ret, data_len, new_len;
struct digi_port *priv = usb_get_serial_port_data(port);
unsigned char *data = port->write_urb->transfer_buffer;
unsigned long flags = 0;
dev_dbg(&port->dev,
"digi_write: TOP: port=%d, count=%d, in_interrupt=%ld\n",
priv->dp_port_num, count, in_interrupt());
count = min(count, port->bulk_out_size-2);
count = min(64, count);
spin_lock_irqsave(&priv->dp_port_lock, flags);
if (priv->dp_write_urb_in_use) {
if (count == 1 && priv->dp_out_buf_len < DIGI_OUT_BUF_SIZE) {
priv->dp_out_buf[priv->dp_out_buf_len++] = *buf;
new_len = 1;
} else {
new_len = 0;
}
spin_unlock_irqrestore(&priv->dp_port_lock, flags);
return new_len;
}
new_len = min(count, port->bulk_out_size-2-priv->dp_out_buf_len);
data_len = new_len + priv->dp_out_buf_len;
if (data_len == 0) {
spin_unlock_irqrestore(&priv->dp_port_lock, flags);
return 0;
}
port->write_urb->transfer_buffer_length = data_len+2;
*data++ = DIGI_CMD_SEND_DATA;
*data++ = data_len;
memcpy(data, priv->dp_out_buf, priv->dp_out_buf_len);
data += priv->dp_out_buf_len;
memcpy(data, buf, new_len);
ret = usb_submit_urb(port->write_urb, GFP_ATOMIC);
if (ret == 0) {
priv->dp_write_urb_in_use = 1;
ret = new_len;
priv->dp_out_buf_len = 0;
}
spin_unlock_irqrestore(&priv->dp_port_lock, flags);
if (ret < 0)
dev_err_console(port,
"%s: usb_submit_urb failed, ret=%d, port=%d\n",
__func__, ret, priv->dp_port_num);
dev_dbg(&port->dev, "digi_write: returning %d\n", ret);
return ret;
}
static void digi_write_bulk_callback(struct urb *urb)
{
struct usb_serial_port *port = urb->context;
struct usb_serial *serial;
struct digi_port *priv;
struct digi_serial *serial_priv;
int ret = 0;
int status = urb->status;
if (port == NULL || (priv = usb_get_serial_port_data(port)) == NULL) {
pr_err("%s: port or port->private is NULL, status=%d\n",
__func__, status);
return;
}
serial = port->serial;
if (serial == NULL || (serial_priv = usb_get_serial_data(serial)) == NULL) {
dev_err(&port->dev,
"%s: serial or serial->private is NULL, status=%d\n",
__func__, status);
return;
}
if (priv->dp_port_num == serial_priv->ds_oob_port_num) {
dev_dbg(&port->dev, "digi_write_bulk_callback: oob callback\n");
spin_lock(&priv->dp_port_lock);
priv->dp_write_urb_in_use = 0;
wake_up_interruptible(&port->write_wait);
spin_unlock(&priv->dp_port_lock);
return;
}
spin_lock(&priv->dp_port_lock);
priv->dp_write_urb_in_use = 0;
if (priv->dp_out_buf_len > 0) {
*((unsigned char *)(port->write_urb->transfer_buffer))
= (unsigned char)DIGI_CMD_SEND_DATA;
*((unsigned char *)(port->write_urb->transfer_buffer) + 1)
= (unsigned char)priv->dp_out_buf_len;
port->write_urb->transfer_buffer_length =
priv->dp_out_buf_len + 2;
memcpy(port->write_urb->transfer_buffer + 2, priv->dp_out_buf,
priv->dp_out_buf_len);
ret = usb_submit_urb(port->write_urb, GFP_ATOMIC);
if (ret == 0) {
priv->dp_write_urb_in_use = 1;
priv->dp_out_buf_len = 0;
}
}
tty_port_tty_wakeup(&port->port);
schedule_work(&priv->dp_wakeup_work);
spin_unlock(&priv->dp_port_lock);
if (ret && ret != -EPERM)
dev_err_console(port,
"%s: usb_submit_urb failed, ret=%d, port=%d\n",
__func__, ret, priv->dp_port_num);
}
static int digi_write_room(struct tty_struct *tty)
{
struct usb_serial_port *port = tty->driver_data;
struct digi_port *priv = usb_get_serial_port_data(port);
int room;
unsigned long flags = 0;
spin_lock_irqsave(&priv->dp_port_lock, flags);
if (priv->dp_write_urb_in_use)
room = 0;
else
room = port->bulk_out_size - 2 - priv->dp_out_buf_len;
spin_unlock_irqrestore(&priv->dp_port_lock, flags);
dev_dbg(&port->dev, "digi_write_room: port=%d, room=%d\n", priv->dp_port_num, room);
return room;
}
static int digi_chars_in_buffer(struct tty_struct *tty)
{
struct usb_serial_port *port = tty->driver_data;
struct digi_port *priv = usb_get_serial_port_data(port);
if (priv->dp_write_urb_in_use) {
dev_dbg(&port->dev, "digi_chars_in_buffer: port=%d, chars=%d\n",
priv->dp_port_num, port->bulk_out_size - 2);
return 256;
} else {
dev_dbg(&port->dev, "digi_chars_in_buffer: port=%d, chars=%d\n",
priv->dp_port_num, priv->dp_out_buf_len);
return priv->dp_out_buf_len;
}
}
static void digi_dtr_rts(struct usb_serial_port *port, int on)
{
digi_set_modem_signals(port, on * (TIOCM_DTR|TIOCM_RTS), 1);
}
static int digi_open(struct tty_struct *tty, struct usb_serial_port *port)
{
int ret;
unsigned char buf[32];
struct digi_port *priv = usb_get_serial_port_data(port);
struct ktermios not_termios;
if (digi_startup_device(port->serial) != 0)
return -ENXIO;
buf[0] = DIGI_CMD_READ_INPUT_SIGNALS;
buf[1] = priv->dp_port_num;
buf[2] = DIGI_ENABLE;
buf[3] = 0;
buf[4] = DIGI_CMD_IFLUSH_FIFO;
buf[5] = priv->dp_port_num;
buf[6] = DIGI_FLUSH_TX | DIGI_FLUSH_RX;
buf[7] = 0;
ret = digi_write_oob_command(port, buf, 8, 1);
if (ret != 0)
dev_dbg(&port->dev, "digi_open: write oob failed, ret=%d\n", ret);
if (tty) {
not_termios.c_cflag = ~tty->termios.c_cflag;
not_termios.c_iflag = ~tty->termios.c_iflag;
digi_set_termios(tty, port, &not_termios);
}
return 0;
}
static void digi_close(struct usb_serial_port *port)
{
DEFINE_WAIT(wait);
int ret;
unsigned char buf[32];
struct digi_port *priv = usb_get_serial_port_data(port);
mutex_lock(&port->serial->disc_mutex);
if (port->serial->disconnected)
goto exit;
digi_transmit_idle(port, DIGI_CLOSE_TIMEOUT);
buf[0] = DIGI_CMD_SET_INPUT_FLOW_CONTROL;
buf[1] = priv->dp_port_num;
buf[2] = DIGI_DISABLE;
buf[3] = 0;
buf[4] = DIGI_CMD_SET_OUTPUT_FLOW_CONTROL;
buf[5] = priv->dp_port_num;
buf[6] = DIGI_DISABLE;
buf[7] = 0;
buf[8] = DIGI_CMD_READ_INPUT_SIGNALS;
buf[9] = priv->dp_port_num;
buf[10] = DIGI_DISABLE;
buf[11] = 0;
buf[12] = DIGI_CMD_RECEIVE_ENABLE;
buf[13] = priv->dp_port_num;
buf[14] = DIGI_DISABLE;
buf[15] = 0;
buf[16] = DIGI_CMD_IFLUSH_FIFO;
buf[17] = priv->dp_port_num;
buf[18] = DIGI_FLUSH_TX | DIGI_FLUSH_RX;
buf[19] = 0;
ret = digi_write_oob_command(port, buf, 20, 0);
if (ret != 0)
dev_dbg(&port->dev, "digi_close: write oob failed, ret=%d\n",
ret);
prepare_to_wait(&priv->dp_flush_wait, &wait,
TASK_INTERRUPTIBLE);
schedule_timeout(DIGI_CLOSE_TIMEOUT);
finish_wait(&priv->dp_flush_wait, &wait);
usb_kill_urb(port->write_urb);
exit:
spin_lock_irq(&priv->dp_port_lock);
priv->dp_write_urb_in_use = 0;
wake_up_interruptible(&priv->dp_close_wait);
spin_unlock_irq(&priv->dp_port_lock);
mutex_unlock(&port->serial->disc_mutex);
}
static int digi_startup_device(struct usb_serial *serial)
{
int i, ret = 0;
struct digi_serial *serial_priv = usb_get_serial_data(serial);
struct usb_serial_port *port;
spin_lock(&serial_priv->ds_serial_lock);
if (serial_priv->ds_device_started) {
spin_unlock(&serial_priv->ds_serial_lock);
return 0;
}
serial_priv->ds_device_started = 1;
spin_unlock(&serial_priv->ds_serial_lock);
for (i = 0; i < serial->type->num_ports + 1; i++) {
port = serial->port[i];
ret = usb_submit_urb(port->read_urb, GFP_KERNEL);
if (ret != 0) {
dev_err(&port->dev,
"%s: usb_submit_urb failed, ret=%d, port=%d\n",
__func__, ret, i);
break;
}
}
return ret;
}
static int digi_port_init(struct usb_serial_port *port, unsigned port_num)
{
struct digi_port *priv;
priv = kzalloc(sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
spin_lock_init(&priv->dp_port_lock);
priv->dp_port_num = port_num;
init_waitqueue_head(&priv->dp_transmit_idle_wait);
init_waitqueue_head(&priv->dp_flush_wait);
init_waitqueue_head(&priv->dp_close_wait);
INIT_WORK(&priv->dp_wakeup_work, digi_wakeup_write_lock);
priv->dp_port = port;
init_waitqueue_head(&port->write_wait);
usb_set_serial_port_data(port, priv);
return 0;
}
static int digi_startup(struct usb_serial *serial)
{
struct digi_serial *serial_priv;
int ret;
serial_priv = kzalloc(sizeof(*serial_priv), GFP_KERNEL);
if (!serial_priv)
return -ENOMEM;
spin_lock_init(&serial_priv->ds_serial_lock);
serial_priv->ds_oob_port_num = serial->type->num_ports;
serial_priv->ds_oob_port = serial->port[serial_priv->ds_oob_port_num];
ret = digi_port_init(serial_priv->ds_oob_port,
serial_priv->ds_oob_port_num);
if (ret) {
kfree(serial_priv);
return ret;
}
usb_set_serial_data(serial, serial_priv);
return 0;
}
static void digi_disconnect(struct usb_serial *serial)
{
int i;
for (i = 0; i < serial->type->num_ports + 1; i++) {
usb_kill_urb(serial->port[i]->read_urb);
usb_kill_urb(serial->port[i]->write_urb);
}
}
static void digi_release(struct usb_serial *serial)
{
struct digi_serial *serial_priv;
struct digi_port *priv;
serial_priv = usb_get_serial_data(serial);
priv = usb_get_serial_port_data(serial_priv->ds_oob_port);
kfree(priv);
kfree(serial_priv);
}
static int digi_port_probe(struct usb_serial_port *port)
{
return digi_port_init(port, port->port_number);
}
static int digi_port_remove(struct usb_serial_port *port)
{
struct digi_port *priv;
priv = usb_get_serial_port_data(port);
kfree(priv);
return 0;
}
static void digi_read_bulk_callback(struct urb *urb)
{
struct usb_serial_port *port = urb->context;
struct digi_port *priv;
struct digi_serial *serial_priv;
int ret;
int status = urb->status;
if (port == NULL)
return;
priv = usb_get_serial_port_data(port);
if (priv == NULL) {
dev_err(&port->dev, "%s: port->private is NULL, status=%d\n",
__func__, status);
return;
}
if (port->serial == NULL ||
(serial_priv = usb_get_serial_data(port->serial)) == NULL) {
dev_err(&port->dev, "%s: serial is bad or serial->private "
"is NULL, status=%d\n", __func__, status);
return;
}
if (status) {
dev_err(&port->dev,
"%s: nonzero read bulk status: status=%d, port=%d\n",
__func__, status, priv->dp_port_num);
return;
}
if (priv->dp_port_num == serial_priv->ds_oob_port_num) {
if (digi_read_oob_callback(urb) != 0)
return;
} else {
if (digi_read_inb_callback(urb) != 0)
return;
}
ret = usb_submit_urb(urb, GFP_ATOMIC);
if (ret != 0 && ret != -EPERM) {
dev_err(&port->dev,
"%s: failed resubmitting urb, ret=%d, port=%d\n",
__func__, ret, priv->dp_port_num);
}
}
static int digi_read_inb_callback(struct urb *urb)
{
struct usb_serial_port *port = urb->context;
struct digi_port *priv = usb_get_serial_port_data(port);
int opcode = ((unsigned char *)urb->transfer_buffer)[0];
int len = ((unsigned char *)urb->transfer_buffer)[1];
int port_status = ((unsigned char *)urb->transfer_buffer)[2];
unsigned char *data = ((unsigned char *)urb->transfer_buffer) + 3;
int flag, throttled;
int status = urb->status;
if (urb->status == -ENOENT)
return 0;
if (urb->actual_length != len + 2) {
dev_err(&port->dev, "%s: INCOMPLETE OR MULTIPLE PACKET, "
"status=%d, port=%d, opcode=%d, len=%d, "
"actual_length=%d, status=%d\n", __func__, status,
priv->dp_port_num, opcode, len, urb->actual_length,
port_status);
return -1;
}
spin_lock(&priv->dp_port_lock);
throttled = priv->dp_throttled;
if (throttled)
priv->dp_throttle_restart = 1;
if (opcode == DIGI_CMD_RECEIVE_DATA) {
flag = 0;
if (port_status & DIGI_OVERRUN_ERROR)
tty_insert_flip_char(&port->port, 0, TTY_OVERRUN);
if (port_status & DIGI_BREAK_ERROR)
flag = TTY_BREAK;
else if (port_status & DIGI_PARITY_ERROR)
flag = TTY_PARITY;
else if (port_status & DIGI_FRAMING_ERROR)
flag = TTY_FRAME;
--len;
if (len > 0) {
tty_insert_flip_string_fixed_flag(&port->port, data,
flag, len);
tty_flip_buffer_push(&port->port);
}
}
spin_unlock(&priv->dp_port_lock);
if (opcode == DIGI_CMD_RECEIVE_DISABLE)
dev_dbg(&port->dev, "%s: got RECEIVE_DISABLE\n", __func__);
else if (opcode != DIGI_CMD_RECEIVE_DATA)
dev_dbg(&port->dev, "%s: unknown opcode: %d\n", __func__, opcode);
return throttled ? 1 : 0;
}
static int digi_read_oob_callback(struct urb *urb)
{
struct usb_serial_port *port = urb->context;
struct usb_serial *serial = port->serial;
struct tty_struct *tty;
struct digi_port *priv = usb_get_serial_port_data(port);
int opcode, line, status, val;
int i;
unsigned int rts;
for (i = 0; i < urb->actual_length - 3;) {
opcode = ((unsigned char *)urb->transfer_buffer)[i++];
line = ((unsigned char *)urb->transfer_buffer)[i++];
status = ((unsigned char *)urb->transfer_buffer)[i++];
val = ((unsigned char *)urb->transfer_buffer)[i++];
dev_dbg(&port->dev, "digi_read_oob_callback: opcode=%d, line=%d, status=%d, val=%d\n",
opcode, line, status, val);
if (status != 0 || line >= serial->type->num_ports)
continue;
port = serial->port[line];
priv = usb_get_serial_port_data(port);
if (priv == NULL)
return -1;
tty = tty_port_tty_get(&port->port);
rts = 0;
if (tty)
rts = tty->termios.c_cflag & CRTSCTS;
if (tty && opcode == DIGI_CMD_READ_INPUT_SIGNALS) {
spin_lock(&priv->dp_port_lock);
if (val & DIGI_READ_INPUT_SIGNALS_CTS) {
priv->dp_modem_signals |= TIOCM_CTS;
if (rts)
tty_port_tty_wakeup(&port->port);
} else {
priv->dp_modem_signals &= ~TIOCM_CTS;
}
if (val & DIGI_READ_INPUT_SIGNALS_DSR)
priv->dp_modem_signals |= TIOCM_DSR;
else
priv->dp_modem_signals &= ~TIOCM_DSR;
if (val & DIGI_READ_INPUT_SIGNALS_RI)
priv->dp_modem_signals |= TIOCM_RI;
else
priv->dp_modem_signals &= ~TIOCM_RI;
if (val & DIGI_READ_INPUT_SIGNALS_DCD)
priv->dp_modem_signals |= TIOCM_CD;
else
priv->dp_modem_signals &= ~TIOCM_CD;
spin_unlock(&priv->dp_port_lock);
} else if (opcode == DIGI_CMD_TRANSMIT_IDLE) {
spin_lock(&priv->dp_port_lock);
priv->dp_transmit_idle = 1;
wake_up_interruptible(&priv->dp_transmit_idle_wait);
spin_unlock(&priv->dp_port_lock);
} else if (opcode == DIGI_CMD_IFLUSH_FIFO) {
wake_up_interruptible(&priv->dp_flush_wait);
}
tty_kref_put(tty);
}
return 0;
}
