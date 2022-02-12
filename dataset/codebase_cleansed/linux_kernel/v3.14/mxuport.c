static int mxuport_prepare_write_buffer(struct usb_serial_port *port,
void *dest, size_t size)
{
u8 *buf = dest;
int count;
count = kfifo_out_locked(&port->write_fifo, buf + HEADER_SIZE,
size - HEADER_SIZE,
&port->lock);
put_unaligned_be16(port->port_number, buf);
put_unaligned_be16(count, buf + 2);
dev_dbg(&port->dev, "%s - size %zd count %d\n", __func__,
size, count);
return count + HEADER_SIZE;
}
static int mxuport_recv_ctrl_urb(struct usb_serial *serial,
u8 request, u16 value, u16 index,
u8 *data, size_t size)
{
int status;
status = usb_control_msg(serial->dev,
usb_rcvctrlpipe(serial->dev, 0),
request,
(USB_DIR_IN | USB_TYPE_VENDOR |
USB_RECIP_DEVICE), value, index,
data, size,
USB_CTRL_GET_TIMEOUT);
if (status < 0) {
dev_err(&serial->interface->dev,
"%s - usb_control_msg failed (%d)\n",
__func__, status);
return status;
}
if (status != size) {
dev_err(&serial->interface->dev,
"%s - short read (%d / %zd)\n",
__func__, status, size);
return -EIO;
}
return status;
}
static int mxuport_send_ctrl_data_urb(struct usb_serial *serial,
u8 request,
u16 value, u16 index,
u8 *data, size_t size)
{
int status;
status = usb_control_msg(serial->dev,
usb_sndctrlpipe(serial->dev, 0),
request,
(USB_DIR_OUT | USB_TYPE_VENDOR |
USB_RECIP_DEVICE), value, index,
data, size,
USB_CTRL_SET_TIMEOUT);
if (status < 0) {
dev_err(&serial->interface->dev,
"%s - usb_control_msg failed (%d)\n",
__func__, status);
return status;
}
if (status != size) {
dev_err(&serial->interface->dev,
"%s - short write (%d / %zd)\n",
__func__, status, size);
return -EIO;
}
return 0;
}
static int mxuport_send_ctrl_urb(struct usb_serial *serial,
u8 request, u16 value, u16 index)
{
return mxuport_send_ctrl_data_urb(serial, request, value, index,
NULL, 0);
}
static void mxuport_throttle(struct tty_struct *tty)
{
struct usb_serial_port *port = tty->driver_data;
struct usb_serial *serial = port->serial;
dev_dbg(&port->dev, "%s\n", __func__);
mxuport_send_ctrl_urb(serial, RQ_VENDOR_SET_RX_HOST_EN,
0, port->port_number);
}
static void mxuport_unthrottle(struct tty_struct *tty)
{
struct usb_serial_port *port = tty->driver_data;
struct usb_serial *serial = port->serial;
dev_dbg(&port->dev, "%s\n", __func__);
mxuport_send_ctrl_urb(serial, RQ_VENDOR_SET_RX_HOST_EN,
1, port->port_number);
}
static void mxuport_process_read_urb_data(struct usb_serial_port *port,
char *data, int size)
{
int i;
if (!port->port.console || !port->sysrq) {
tty_insert_flip_string(&port->port, data, size);
} else {
for (i = 0; i < size; i++, data++) {
if (!usb_serial_handle_sysrq_char(port, *data))
tty_insert_flip_char(&port->port, *data,
TTY_NORMAL);
}
}
tty_flip_buffer_push(&port->port);
}
static void mxuport_msr_event(struct usb_serial_port *port, u8 buf[4])
{
struct mxuport_port *mxport = usb_get_serial_port_data(port);
u8 rcv_msr_hold = buf[2] & 0xF0;
u16 rcv_msr_event = get_unaligned_be16(buf);
unsigned long flags;
if (rcv_msr_event == 0)
return;
spin_lock_irqsave(&mxport->spinlock, flags);
dev_dbg(&port->dev, "%s - current MSR status = 0x%x\n",
__func__, mxport->msr_state);
if (rcv_msr_hold & UART_MSR_CTS) {
mxport->msr_state |= UART_MSR_CTS;
dev_dbg(&port->dev, "%s - CTS high\n", __func__);
} else {
mxport->msr_state &= ~UART_MSR_CTS;
dev_dbg(&port->dev, "%s - CTS low\n", __func__);
}
if (rcv_msr_hold & UART_MSR_DSR) {
mxport->msr_state |= UART_MSR_DSR;
dev_dbg(&port->dev, "%s - DSR high\n", __func__);
} else {
mxport->msr_state &= ~UART_MSR_DSR;
dev_dbg(&port->dev, "%s - DSR low\n", __func__);
}
if (rcv_msr_hold & UART_MSR_DCD) {
mxport->msr_state |= UART_MSR_DCD;
dev_dbg(&port->dev, "%s - DCD high\n", __func__);
} else {
mxport->msr_state &= ~UART_MSR_DCD;
dev_dbg(&port->dev, "%s - DCD low\n", __func__);
}
spin_unlock_irqrestore(&mxport->spinlock, flags);
if (rcv_msr_event &
(SERIAL_EV_CTS | SERIAL_EV_DSR | SERIAL_EV_RLSD)) {
if (rcv_msr_event & SERIAL_EV_CTS) {
port->icount.cts++;
dev_dbg(&port->dev, "%s - CTS change\n", __func__);
}
if (rcv_msr_event & SERIAL_EV_DSR) {
port->icount.dsr++;
dev_dbg(&port->dev, "%s - DSR change\n", __func__);
}
if (rcv_msr_event & SERIAL_EV_RLSD) {
port->icount.dcd++;
dev_dbg(&port->dev, "%s - DCD change\n", __func__);
}
wake_up_interruptible(&port->port.delta_msr_wait);
}
}
static void mxuport_lsr_event(struct usb_serial_port *port, u8 buf[4])
{
u8 lsr_event = buf[2];
if (lsr_event & UART_LSR_BI) {
port->icount.brk++;
dev_dbg(&port->dev, "%s - break error\n", __func__);
}
if (lsr_event & UART_LSR_FE) {
port->icount.frame++;
dev_dbg(&port->dev, "%s - frame error\n", __func__);
}
if (lsr_event & UART_LSR_PE) {
port->icount.parity++;
dev_dbg(&port->dev, "%s - parity error\n", __func__);
}
if (lsr_event & UART_LSR_OE) {
port->icount.overrun++;
dev_dbg(&port->dev, "%s - overrun error\n", __func__);
}
}
static void mxuport_process_read_urb_event(struct usb_serial_port *port,
u8 buf[4], u32 event)
{
dev_dbg(&port->dev, "%s - receive event : %04x\n", __func__, event);
switch (event) {
case UPORT_EVENT_SEND_NEXT:
break;
case UPORT_EVENT_MSR:
mxuport_msr_event(port, buf);
break;
case UPORT_EVENT_LSR:
mxuport_lsr_event(port, buf);
break;
case UPORT_EVENT_MCR:
break;
default:
dev_dbg(&port->dev, "Unexpected event\n");
break;
}
}
static void mxuport_process_read_urb_demux_data(struct urb *urb)
{
struct usb_serial_port *port = urb->context;
struct usb_serial *serial = port->serial;
u8 *data = urb->transfer_buffer;
u8 *end = data + urb->actual_length;
struct usb_serial_port *demux_port;
u8 *ch;
u16 rcv_port;
u16 rcv_len;
while (data < end) {
if (data + HEADER_SIZE > end) {
dev_warn(&port->dev, "%s - message with short header\n",
__func__);
return;
}
rcv_port = get_unaligned_be16(data);
if (rcv_port >= serial->num_ports) {
dev_warn(&port->dev, "%s - message for invalid port\n",
__func__);
return;
}
demux_port = serial->port[rcv_port];
rcv_len = get_unaligned_be16(data + 2);
if (!rcv_len || data + HEADER_SIZE + rcv_len > end) {
dev_warn(&port->dev, "%s - short data\n", __func__);
return;
}
if (test_bit(ASYNCB_INITIALIZED, &demux_port->port.flags)) {
ch = data + HEADER_SIZE;
mxuport_process_read_urb_data(demux_port, ch, rcv_len);
} else {
dev_dbg(&demux_port->dev, "%s - data for closed port\n",
__func__);
}
data += HEADER_SIZE + rcv_len;
}
}
static void mxuport_process_read_urb_demux_event(struct urb *urb)
{
struct usb_serial_port *port = urb->context;
struct usb_serial *serial = port->serial;
u8 *data = urb->transfer_buffer;
u8 *end = data + urb->actual_length;
struct usb_serial_port *demux_port;
u8 *ch;
u16 rcv_port;
u16 rcv_event;
while (data < end) {
if (data + EVENT_LENGTH > end) {
dev_warn(&port->dev, "%s - message with short event\n",
__func__);
return;
}
rcv_port = get_unaligned_be16(data);
if (rcv_port >= serial->num_ports) {
dev_warn(&port->dev, "%s - message for invalid port\n",
__func__);
return;
}
demux_port = serial->port[rcv_port];
if (test_bit(ASYNCB_INITIALIZED, &demux_port->port.flags)) {
ch = data + HEADER_SIZE;
rcv_event = get_unaligned_be16(data + 2);
mxuport_process_read_urb_event(demux_port, ch,
rcv_event);
} else {
dev_dbg(&demux_port->dev,
"%s - event for closed port\n", __func__);
}
data += EVENT_LENGTH;
}
}
static void mxuport_process_read_urb(struct urb *urb)
{
struct usb_serial_port *port = urb->context;
struct usb_serial *serial = port->serial;
if (port == serial->port[0])
mxuport_process_read_urb_demux_data(urb);
if (port == serial->port[1])
mxuport_process_read_urb_demux_event(urb);
}
static bool mxuport_tx_empty(struct usb_serial_port *port)
{
struct usb_serial *serial = port->serial;
bool is_empty = true;
u32 txlen;
u8 *len_buf;
int err;
len_buf = kzalloc(4, GFP_KERNEL);
if (!len_buf)
goto out;
err = mxuport_recv_ctrl_urb(serial, RQ_VENDOR_GET_OUTQUEUE, 0,
port->port_number, len_buf, 4);
if (err < 0)
goto out;
txlen = get_unaligned_be32(len_buf);
dev_dbg(&port->dev, "%s - tx len = %u\n", __func__, txlen);
if (txlen != 0)
is_empty = false;
out:
kfree(len_buf);
return is_empty;
}
static int mxuport_set_mcr(struct usb_serial_port *port, u8 mcr_state)
{
struct usb_serial *serial = port->serial;
int err;
dev_dbg(&port->dev, "%s - %02x\n", __func__, mcr_state);
err = mxuport_send_ctrl_urb(serial, RQ_VENDOR_SET_MCR,
mcr_state, port->port_number);
if (err)
dev_err(&port->dev, "%s - failed to change MCR\n", __func__);
return err;
}
static int mxuport_set_dtr(struct usb_serial_port *port, int on)
{
struct mxuport_port *mxport = usb_get_serial_port_data(port);
struct usb_serial *serial = port->serial;
int err;
mutex_lock(&mxport->mutex);
err = mxuport_send_ctrl_urb(serial, RQ_VENDOR_SET_DTR,
!!on, port->port_number);
if (!err) {
if (on)
mxport->mcr_state |= UART_MCR_DTR;
else
mxport->mcr_state &= ~UART_MCR_DTR;
}
mutex_unlock(&mxport->mutex);
return err;
}
static int mxuport_set_rts(struct usb_serial_port *port, u8 state)
{
struct mxuport_port *mxport = usb_get_serial_port_data(port);
struct usb_serial *serial = port->serial;
int err;
u8 mcr_state;
mutex_lock(&mxport->mutex);
mcr_state = mxport->mcr_state;
switch (state) {
case MX_RTS_DISABLE:
mcr_state &= ~UART_MCR_RTS;
break;
case MX_RTS_ENABLE:
mcr_state |= UART_MCR_RTS;
break;
case MX_RTS_HW:
break;
default:
err = -EINVAL;
goto out;
}
err = mxuport_send_ctrl_urb(serial, RQ_VENDOR_SET_RTS,
state, port->port_number);
if (!err)
mxport->mcr_state = mcr_state;
out:
mutex_unlock(&mxport->mutex);
return err;
}
static void mxuport_dtr_rts(struct usb_serial_port *port, int on)
{
struct mxuport_port *mxport = usb_get_serial_port_data(port);
u8 mcr_state;
int err;
mutex_lock(&mxport->mutex);
mcr_state = mxport->mcr_state;
if (on)
mcr_state |= (UART_MCR_RTS | UART_MCR_DTR);
else
mcr_state &= ~(UART_MCR_RTS | UART_MCR_DTR);
err = mxuport_set_mcr(port, mcr_state);
if (!err)
mxport->mcr_state = mcr_state;
mutex_unlock(&mxport->mutex);
}
static int mxuport_tiocmset(struct tty_struct *tty, unsigned int set,
unsigned int clear)
{
struct usb_serial_port *port = tty->driver_data;
struct mxuport_port *mxport = usb_get_serial_port_data(port);
int err;
u8 mcr_state;
mutex_lock(&mxport->mutex);
mcr_state = mxport->mcr_state;
if (set & TIOCM_RTS)
mcr_state |= UART_MCR_RTS;
if (set & TIOCM_DTR)
mcr_state |= UART_MCR_DTR;
if (clear & TIOCM_RTS)
mcr_state &= ~UART_MCR_RTS;
if (clear & TIOCM_DTR)
mcr_state &= ~UART_MCR_DTR;
err = mxuport_set_mcr(port, mcr_state);
if (!err)
mxport->mcr_state = mcr_state;
mutex_unlock(&mxport->mutex);
return err;
}
static int mxuport_tiocmget(struct tty_struct *tty)
{
struct mxuport_port *mxport;
struct usb_serial_port *port = tty->driver_data;
unsigned int result;
unsigned long flags;
unsigned int msr;
unsigned int mcr;
mxport = usb_get_serial_port_data(port);
mutex_lock(&mxport->mutex);
spin_lock_irqsave(&mxport->spinlock, flags);
msr = mxport->msr_state;
mcr = mxport->mcr_state;
spin_unlock_irqrestore(&mxport->spinlock, flags);
mutex_unlock(&mxport->mutex);
result = (((mcr & UART_MCR_DTR) ? TIOCM_DTR : 0) |
((mcr & UART_MCR_RTS) ? TIOCM_RTS : 0) |
((msr & UART_MSR_CTS) ? TIOCM_CTS : 0) |
((msr & UART_MSR_DCD) ? TIOCM_CAR : 0) |
((msr & UART_MSR_RI) ? TIOCM_RI : 0) |
((msr & UART_MSR_DSR) ? TIOCM_DSR : 0));
dev_dbg(&port->dev, "%s - 0x%04x\n", __func__, result);
return result;
}
static int mxuport_set_termios_flow(struct tty_struct *tty,
struct ktermios *old_termios,
struct usb_serial_port *port,
struct usb_serial *serial)
{
u8 xon = START_CHAR(tty);
u8 xoff = STOP_CHAR(tty);
int enable;
int err;
u8 *buf;
u8 rts;
buf = kmalloc(2, GFP_KERNEL);
if (!buf)
return -ENOMEM;
if (I_IXOFF(tty) || I_IXON(tty)) {
enable = 1;
buf[0] = xon;
buf[1] = xoff;
err = mxuport_send_ctrl_data_urb(serial, RQ_VENDOR_SET_CHARS,
0, port->port_number,
buf, 2);
if (err)
goto out;
dev_dbg(&port->dev, "%s - XON = 0x%02x, XOFF = 0x%02x\n",
__func__, xon, xoff);
} else {
enable = 0;
}
err = mxuport_send_ctrl_urb(serial, RQ_VENDOR_SET_XONXOFF,
enable, port->port_number);
if (err)
goto out;
rts = MX_RTS_NO_CHANGE;
if (!old_termios ||
C_CRTSCTS(tty) != (old_termios->c_cflag & CRTSCTS)) {
if (C_CRTSCTS(tty))
rts = MX_RTS_HW;
else
rts = MX_RTS_ENABLE;
}
if (C_BAUD(tty)) {
if (old_termios && (old_termios->c_cflag & CBAUD) == B0) {
if (C_CRTSCTS(tty))
rts = MX_RTS_HW;
else
rts = MX_RTS_ENABLE;
mxuport_set_dtr(port, 1);
}
} else {
rts = MX_RTS_DISABLE;
mxuport_set_dtr(port, 0);
}
if (rts != MX_RTS_NO_CHANGE)
err = mxuport_set_rts(port, rts);
out:
kfree(buf);
return err;
}
static void mxuport_set_termios(struct tty_struct *tty,
struct usb_serial_port *port,
struct ktermios *old_termios)
{
struct usb_serial *serial = port->serial;
u8 *buf;
u8 data_bits;
u8 stop_bits;
u8 parity;
int baud;
int err;
if (old_termios &&
!tty_termios_hw_change(&tty->termios, old_termios) &&
tty->termios.c_iflag == old_termios->c_iflag) {
dev_dbg(&port->dev, "%s - nothing to change\n", __func__);
return;
}
buf = kmalloc(4, GFP_KERNEL);
if (!buf)
return;
switch (C_CSIZE(tty)) {
case CS5:
data_bits = MX_WORDLENGTH_5;
break;
case CS6:
data_bits = MX_WORDLENGTH_6;
break;
case CS7:
data_bits = MX_WORDLENGTH_7;
break;
case CS8:
default:
data_bits = MX_WORDLENGTH_8;
break;
}
if (C_PARENB(tty)) {
if (C_CMSPAR(tty)) {
if (C_PARODD(tty))
parity = MX_PARITY_MARK;
else
parity = MX_PARITY_SPACE;
} else {
if (C_PARODD(tty))
parity = MX_PARITY_ODD;
else
parity = MX_PARITY_EVEN;
}
} else {
parity = MX_PARITY_NONE;
}
if (C_CSTOPB(tty))
stop_bits = MX_STOP_BITS_2;
else
stop_bits = MX_STOP_BITS_1;
buf[0] = data_bits;
buf[1] = parity;
buf[2] = stop_bits;
buf[3] = 0;
err = mxuport_send_ctrl_data_urb(serial, RQ_VENDOR_SET_LINE,
0, port->port_number, buf, 4);
if (err)
goto out;
err = mxuport_set_termios_flow(tty, old_termios, port, serial);
if (err)
goto out;
baud = tty_get_baud_rate(tty);
if (!baud)
baud = 9600;
put_unaligned_le32(baud, buf);
err = mxuport_send_ctrl_data_urb(serial, RQ_VENDOR_SET_BAUD,
0, port->port_number,
buf, 4);
if (err)
goto out;
dev_dbg(&port->dev, "baud_rate : %d\n", baud);
dev_dbg(&port->dev, "data_bits : %d\n", data_bits);
dev_dbg(&port->dev, "parity : %d\n", parity);
dev_dbg(&port->dev, "stop_bits : %d\n", stop_bits);
out:
kfree(buf);
}
static int mxuport_calc_num_ports(struct usb_serial *serial)
{
unsigned long features = (unsigned long)usb_get_serial_data(serial);
if (features & MX_UPORT_2_PORT)
return 2;
if (features & MX_UPORT_4_PORT)
return 4;
if (features & MX_UPORT_8_PORT)
return 8;
if (features & MX_UPORT_16_PORT)
return 16;
return 0;
}
static int mxuport_get_fw_version(struct usb_serial *serial, u32 *version)
{
u8 *ver_buf;
int err;
ver_buf = kzalloc(4, GFP_KERNEL);
if (!ver_buf)
return -ENOMEM;
err = mxuport_recv_ctrl_urb(serial, RQ_VENDOR_GET_VERSION, 0, 0,
ver_buf, 4);
if (err != 4) {
err = -EIO;
goto out;
}
*version = (ver_buf[0] << 16) | (ver_buf[1] << 8) | ver_buf[2];
err = 0;
out:
kfree(ver_buf);
return err;
}
static int mxuport_download_fw(struct usb_serial *serial,
const struct firmware *fw_p)
{
u8 *fw_buf;
size_t txlen;
size_t fwidx;
int err;
fw_buf = kmalloc(DOWN_BLOCK_SIZE, GFP_KERNEL);
if (!fw_buf)
return -ENOMEM;
dev_dbg(&serial->interface->dev, "Starting firmware download...\n");
err = mxuport_send_ctrl_urb(serial, RQ_VENDOR_START_FW_DOWN, 0, 0);
if (err)
goto out;
fwidx = 0;
do {
txlen = min_t(size_t, (fw_p->size - fwidx), DOWN_BLOCK_SIZE);
memcpy(fw_buf, &fw_p->data[fwidx], txlen);
err = mxuport_send_ctrl_data_urb(serial, RQ_VENDOR_FW_DATA,
0, 0, fw_buf, txlen);
if (err) {
mxuport_send_ctrl_urb(serial, RQ_VENDOR_STOP_FW_DOWN,
0, 0);
goto out;
}
fwidx += txlen;
usleep_range(1000, 2000);
} while (fwidx < fw_p->size);
msleep(1000);
err = mxuport_send_ctrl_urb(serial, RQ_VENDOR_STOP_FW_DOWN, 0, 0);
if (err)
goto out;
msleep(1000);
err = mxuport_send_ctrl_urb(serial, RQ_VENDOR_QUERY_FW_READY, 0, 0);
out:
kfree(fw_buf);
return err;
}
static int mxuport_probe(struct usb_serial *serial,
const struct usb_device_id *id)
{
u16 productid = le16_to_cpu(serial->dev->descriptor.idProduct);
const struct firmware *fw_p = NULL;
u32 version;
int local_ver;
char buf[32];
int err;
err = mxuport_send_ctrl_urb(serial, RQ_VENDOR_QUERY_FW_CONFIG, 0, 0);
if (err) {
mxuport_send_ctrl_urb(serial, RQ_VENDOR_RESET_DEVICE, 0, 0);
return err;
}
err = mxuport_get_fw_version(serial, &version);
if (err < 0)
return err;
dev_dbg(&serial->interface->dev, "Device firmware version v%x.%x.%x\n",
(version & 0xff0000) >> 16,
(version & 0xff00) >> 8,
(version & 0xff));
snprintf(buf, sizeof(buf) - 1, "moxa/moxa-%04x.fw", productid);
err = request_firmware(&fw_p, buf, &serial->interface->dev);
if (err) {
dev_warn(&serial->interface->dev, "Firmware %s not found\n",
buf);
err = 0;
} else {
local_ver = ((fw_p->data[VER_ADDR_1] << 16) |
(fw_p->data[VER_ADDR_2] << 8) |
fw_p->data[VER_ADDR_3]);
dev_dbg(&serial->interface->dev,
"Available firmware version v%x.%x.%x\n",
fw_p->data[VER_ADDR_1], fw_p->data[VER_ADDR_2],
fw_p->data[VER_ADDR_3]);
if (local_ver > version) {
err = mxuport_download_fw(serial, fw_p);
if (err)
goto out;
err = mxuport_get_fw_version(serial, &version);
if (err < 0)
goto out;
}
}
dev_info(&serial->interface->dev,
"Using device firmware version v%x.%x.%x\n",
(version & 0xff0000) >> 16,
(version & 0xff00) >> 8,
(version & 0xff));
usb_set_serial_data(serial, (void *)id->driver_info);
out:
if (fw_p)
release_firmware(fw_p);
return err;
}
static int mxuport_port_probe(struct usb_serial_port *port)
{
struct usb_serial *serial = port->serial;
struct mxuport_port *mxport;
int err;
mxport = devm_kzalloc(&port->dev, sizeof(struct mxuport_port),
GFP_KERNEL);
if (!mxport)
return -ENOMEM;
mutex_init(&mxport->mutex);
spin_lock_init(&mxport->spinlock);
usb_set_serial_port_data(port, mxport);
err = mxuport_send_ctrl_urb(serial, RQ_VENDOR_SET_FIFO_DISABLE,
0, port->port_number);
if (err)
return err;
err = mxuport_send_ctrl_urb(serial, RQ_VENDOR_SET_HIGH_PERFOR,
0, port->port_number);
if (err)
return err;
err = mxuport_send_ctrl_urb(serial, RQ_VENDOR_SET_INTERFACE,
MX_INT_RS232,
port->port_number);
if (err)
return err;
return 0;
}
static int mxuport_alloc_write_urb(struct usb_serial *serial,
struct usb_serial_port *port,
struct usb_serial_port *port0,
int j)
{
struct usb_device *dev = interface_to_usbdev(serial->interface);
set_bit(j, &port->write_urbs_free);
port->write_urbs[j] = usb_alloc_urb(0, GFP_KERNEL);
if (!port->write_urbs[j])
return -ENOMEM;
port->bulk_out_buffers[j] = kmalloc(port0->bulk_out_size, GFP_KERNEL);
if (!port->bulk_out_buffers[j])
return -ENOMEM;
usb_fill_bulk_urb(port->write_urbs[j], dev,
usb_sndbulkpipe(dev, port->bulk_out_endpointAddress),
port->bulk_out_buffers[j],
port->bulk_out_size,
serial->type->write_bulk_callback,
port);
return 0;
}
static int mxuport_alloc_write_urbs(struct usb_serial *serial,
struct usb_serial_port *port,
struct usb_serial_port *port0)
{
int j;
int ret;
for (j = 0; j < ARRAY_SIZE(port->write_urbs); ++j) {
ret = mxuport_alloc_write_urb(serial, port, port0, j);
if (ret)
return ret;
}
return 0;
}
static int mxuport_attach(struct usb_serial *serial)
{
struct usb_serial_port *port0 = serial->port[0];
struct usb_serial_port *port1 = serial->port[1];
struct usb_serial_port *port;
int err;
int i;
int j;
for (i = 1; i < serial->num_bulk_out; ++i) {
port = serial->port[i];
for (j = 0; j < ARRAY_SIZE(port->write_urbs); ++j) {
usb_free_urb(port->write_urbs[j]);
kfree(port->bulk_out_buffers[j]);
port->write_urbs[j] = NULL;
port->bulk_out_buffers[j] = NULL;
}
port->write_urbs_free = 0;
}
for (i = 1; i < serial->num_ports; ++i) {
port = serial->port[i];
port->bulk_out_size = port0->bulk_out_size;
port->bulk_out_endpointAddress =
port0->bulk_out_endpointAddress;
err = mxuport_alloc_write_urbs(serial, port, port0);
if (err)
return err;
port->write_urb = port->write_urbs[0];
port->bulk_out_buffer = port->bulk_out_buffers[0];
if (!kfifo_initialized(&port->write_fifo)) {
err = kfifo_alloc(&port->write_fifo, PAGE_SIZE,
GFP_KERNEL);
if (err)
return err;
}
}
err = usb_serial_generic_submit_read_urbs(port0, GFP_KERNEL);
if (err)
return err;
err = usb_serial_generic_submit_read_urbs(port1, GFP_KERNEL);
if (err) {
usb_serial_generic_close(port0);
return err;
}
return 0;
}
static int mxuport_open(struct tty_struct *tty, struct usb_serial_port *port)
{
struct mxuport_port *mxport = usb_get_serial_port_data(port);
struct usb_serial *serial = port->serial;
int err;
err = mxuport_send_ctrl_urb(serial, RQ_VENDOR_SET_RX_HOST_EN,
1, port->port_number);
if (err)
return err;
err = mxuport_send_ctrl_urb(serial, RQ_VENDOR_SET_OPEN,
1, port->port_number);
if (err) {
mxuport_send_ctrl_urb(serial, RQ_VENDOR_SET_RX_HOST_EN,
0, port->port_number);
return err;
}
mxuport_set_termios(tty, port, NULL);
mxport->msr_state = 0;
return err;
}
static void mxuport_close(struct usb_serial_port *port)
{
struct usb_serial *serial = port->serial;
mxuport_send_ctrl_urb(serial, RQ_VENDOR_SET_OPEN, 0,
port->port_number);
mxuport_send_ctrl_urb(serial, RQ_VENDOR_SET_RX_HOST_EN, 0,
port->port_number);
}
static void mxuport_break_ctl(struct tty_struct *tty, int break_state)
{
struct usb_serial_port *port = tty->driver_data;
struct usb_serial *serial = port->serial;
int enable;
if (break_state == -1) {
enable = 1;
dev_dbg(&port->dev, "%s - sending break\n", __func__);
} else {
enable = 0;
dev_dbg(&port->dev, "%s - clearing break\n", __func__);
}
mxuport_send_ctrl_urb(serial, RQ_VENDOR_SET_BREAK,
enable, port->port_number);
}
static int mxuport_resume(struct usb_serial *serial)
{
struct usb_serial_port *port;
int c = 0;
int i;
int r;
for (i = 0; i < 2; i++) {
port = serial->port[i];
r = usb_serial_generic_submit_read_urbs(port, GFP_NOIO);
if (r < 0)
c++;
}
for (i = 0; i < serial->num_ports; i++) {
port = serial->port[i];
if (!test_bit(ASYNCB_INITIALIZED, &port->port.flags))
continue;
r = usb_serial_generic_write_start(port, GFP_NOIO);
if (r < 0)
c++;
}
return c ? -EIO : 0;
}
