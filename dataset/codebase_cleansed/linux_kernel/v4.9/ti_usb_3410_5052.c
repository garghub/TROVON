static int ti_startup(struct usb_serial *serial)
{
struct ti_device *tdev;
struct usb_device *dev = serial->dev;
struct usb_host_interface *cur_altsetting;
int num_endpoints;
u16 vid, pid;
int status;
dev_dbg(&dev->dev,
"%s - product 0x%4X, num configurations %d, configuration value %d\n",
__func__, le16_to_cpu(dev->descriptor.idProduct),
dev->descriptor.bNumConfigurations,
dev->actconfig->desc.bConfigurationValue);
tdev = kzalloc(sizeof(struct ti_device), GFP_KERNEL);
if (!tdev)
return -ENOMEM;
mutex_init(&tdev->td_open_close_lock);
tdev->td_serial = serial;
usb_set_serial_data(serial, tdev);
if (serial->type == &ti_1port_device)
tdev->td_is_3410 = 1;
dev_dbg(&dev->dev, "%s - device type is %s\n", __func__,
tdev->td_is_3410 ? "3410" : "5052");
vid = le16_to_cpu(dev->descriptor.idVendor);
pid = le16_to_cpu(dev->descriptor.idProduct);
if (vid == MXU1_VENDOR_ID) {
switch (pid) {
case MXU1_1130_PRODUCT_ID:
case MXU1_1131_PRODUCT_ID:
tdev->td_rs485_only = true;
break;
}
}
cur_altsetting = serial->interface->cur_altsetting;
num_endpoints = cur_altsetting->desc.bNumEndpoints;
if (dev->descriptor.bNumConfigurations == 1 && num_endpoints == 1) {
status = ti_download_firmware(tdev);
if (status != 0)
goto free_tdev;
if (tdev->td_is_3410) {
msleep_interruptible(100);
usb_reset_device(dev);
}
status = -ENODEV;
goto free_tdev;
}
if (dev->actconfig->desc.bConfigurationValue == TI_BOOT_CONFIG) {
status = usb_driver_set_configuration(dev, TI_ACTIVE_CONFIG);
status = status ? status : -ENODEV;
goto free_tdev;
}
return 0;
free_tdev:
kfree(tdev);
usb_set_serial_data(serial, NULL);
return status;
}
static void ti_release(struct usb_serial *serial)
{
struct ti_device *tdev = usb_get_serial_data(serial);
kfree(tdev);
}
static int ti_port_probe(struct usb_serial_port *port)
{
struct ti_port *tport;
tport = kzalloc(sizeof(*tport), GFP_KERNEL);
if (!tport)
return -ENOMEM;
spin_lock_init(&tport->tp_lock);
if (port == port->serial->port[0])
tport->tp_uart_base_addr = TI_UART1_BASE_ADDR;
else
tport->tp_uart_base_addr = TI_UART2_BASE_ADDR;
port->port.closing_wait = msecs_to_jiffies(10 * closing_wait);
tport->tp_port = port;
tport->tp_tdev = usb_get_serial_data(port->serial);
if (tport->tp_tdev->td_rs485_only)
tport->tp_uart_mode = TI_UART_485_RECEIVER_DISABLED;
else
tport->tp_uart_mode = TI_UART_232;
usb_set_serial_port_data(port, tport);
port->port.drain_delay = 3;
return 0;
}
static int ti_port_remove(struct usb_serial_port *port)
{
struct ti_port *tport;
tport = usb_get_serial_port_data(port);
kfree(tport);
return 0;
}
static int ti_open(struct tty_struct *tty, struct usb_serial_port *port)
{
struct ti_port *tport = usb_get_serial_port_data(port);
struct ti_device *tdev;
struct usb_device *dev;
struct urb *urb;
int port_number;
int status;
u16 open_settings;
open_settings = (TI_PIPE_MODE_CONTINUOUS |
TI_PIPE_TIMEOUT_ENABLE |
(TI_TRANSFER_TIMEOUT << 2));
dev = port->serial->dev;
tdev = tport->tp_tdev;
if (mutex_lock_interruptible(&tdev->td_open_close_lock))
return -ERESTARTSYS;
port_number = port->port_number;
tport->tp_msr = 0;
tport->tp_shadow_mcr |= (TI_MCR_RTS | TI_MCR_DTR);
if (tdev->td_open_port_count == 0) {
dev_dbg(&port->dev, "%s - start interrupt in urb\n", __func__);
urb = tdev->td_serial->port[0]->interrupt_in_urb;
if (!urb) {
dev_err(&port->dev, "%s - no interrupt urb\n", __func__);
status = -EINVAL;
goto release_lock;
}
urb->context = tdev;
status = usb_submit_urb(urb, GFP_KERNEL);
if (status) {
dev_err(&port->dev, "%s - submit interrupt urb failed, %d\n", __func__, status);
goto release_lock;
}
}
if (tty)
ti_set_termios(tty, port, &tty->termios);
status = ti_command_out_sync(tdev, TI_OPEN_PORT,
(__u8)(TI_UART1_PORT + port_number), open_settings, NULL, 0);
if (status) {
dev_err(&port->dev, "%s - cannot send open command, %d\n",
__func__, status);
goto unlink_int_urb;
}
status = ti_command_out_sync(tdev, TI_START_PORT,
(__u8)(TI_UART1_PORT + port_number), 0, NULL, 0);
if (status) {
dev_err(&port->dev, "%s - cannot send start command, %d\n",
__func__, status);
goto unlink_int_urb;
}
status = ti_command_out_sync(tdev, TI_PURGE_PORT,
(__u8)(TI_UART1_PORT + port_number), TI_PURGE_INPUT, NULL, 0);
if (status) {
dev_err(&port->dev, "%s - cannot clear input buffers, %d\n",
__func__, status);
goto unlink_int_urb;
}
status = ti_command_out_sync(tdev, TI_PURGE_PORT,
(__u8)(TI_UART1_PORT + port_number), TI_PURGE_OUTPUT, NULL, 0);
if (status) {
dev_err(&port->dev, "%s - cannot clear output buffers, %d\n",
__func__, status);
goto unlink_int_urb;
}
usb_clear_halt(dev, port->write_urb->pipe);
usb_clear_halt(dev, port->read_urb->pipe);
if (tty)
ti_set_termios(tty, port, &tty->termios);
status = ti_command_out_sync(tdev, TI_OPEN_PORT,
(__u8)(TI_UART1_PORT + port_number), open_settings, NULL, 0);
if (status) {
dev_err(&port->dev, "%s - cannot send open command (2), %d\n",
__func__, status);
goto unlink_int_urb;
}
status = ti_command_out_sync(tdev, TI_START_PORT,
(__u8)(TI_UART1_PORT + port_number), 0, NULL, 0);
if (status) {
dev_err(&port->dev, "%s - cannot send start command (2), %d\n",
__func__, status);
goto unlink_int_urb;
}
urb = port->read_urb;
if (!urb) {
dev_err(&port->dev, "%s - no read urb\n", __func__);
status = -EINVAL;
goto unlink_int_urb;
}
tport->tp_read_urb_state = TI_READ_URB_RUNNING;
urb->context = tport;
status = usb_submit_urb(urb, GFP_KERNEL);
if (status) {
dev_err(&port->dev, "%s - submit read urb failed, %d\n",
__func__, status);
goto unlink_int_urb;
}
tport->tp_is_open = 1;
++tdev->td_open_port_count;
goto release_lock;
unlink_int_urb:
if (tdev->td_open_port_count == 0)
usb_kill_urb(port->serial->port[0]->interrupt_in_urb);
release_lock:
mutex_unlock(&tdev->td_open_close_lock);
return status;
}
static void ti_close(struct usb_serial_port *port)
{
struct ti_device *tdev;
struct ti_port *tport;
int port_number;
int status;
int do_unlock;
unsigned long flags;
tdev = usb_get_serial_data(port->serial);
tport = usb_get_serial_port_data(port);
tport->tp_is_open = 0;
usb_kill_urb(port->read_urb);
usb_kill_urb(port->write_urb);
tport->tp_write_urb_in_use = 0;
spin_lock_irqsave(&tport->tp_lock, flags);
kfifo_reset_out(&port->write_fifo);
spin_unlock_irqrestore(&tport->tp_lock, flags);
port_number = port->port_number;
status = ti_command_out_sync(tdev, TI_CLOSE_PORT,
(__u8)(TI_UART1_PORT + port_number), 0, NULL, 0);
if (status)
dev_err(&port->dev,
"%s - cannot send close port command, %d\n"
, __func__, status);
do_unlock = !mutex_lock_interruptible(&tdev->td_open_close_lock);
--tport->tp_tdev->td_open_port_count;
if (tport->tp_tdev->td_open_port_count <= 0) {
usb_kill_urb(port->serial->port[0]->interrupt_in_urb);
tport->tp_tdev->td_open_port_count = 0;
}
if (do_unlock)
mutex_unlock(&tdev->td_open_close_lock);
}
static int ti_write(struct tty_struct *tty, struct usb_serial_port *port,
const unsigned char *data, int count)
{
struct ti_port *tport = usb_get_serial_port_data(port);
if (count == 0) {
return 0;
}
if (!tport->tp_is_open)
return -ENODEV;
count = kfifo_in_locked(&port->write_fifo, data, count,
&tport->tp_lock);
ti_send(tport);
return count;
}
static int ti_write_room(struct tty_struct *tty)
{
struct usb_serial_port *port = tty->driver_data;
struct ti_port *tport = usb_get_serial_port_data(port);
int room = 0;
unsigned long flags;
spin_lock_irqsave(&tport->tp_lock, flags);
room = kfifo_avail(&port->write_fifo);
spin_unlock_irqrestore(&tport->tp_lock, flags);
dev_dbg(&port->dev, "%s - returns %d\n", __func__, room);
return room;
}
static int ti_chars_in_buffer(struct tty_struct *tty)
{
struct usb_serial_port *port = tty->driver_data;
struct ti_port *tport = usb_get_serial_port_data(port);
int chars = 0;
unsigned long flags;
spin_lock_irqsave(&tport->tp_lock, flags);
chars = kfifo_len(&port->write_fifo);
spin_unlock_irqrestore(&tport->tp_lock, flags);
dev_dbg(&port->dev, "%s - returns %d\n", __func__, chars);
return chars;
}
static bool ti_tx_empty(struct usb_serial_port *port)
{
struct ti_port *tport = usb_get_serial_port_data(port);
int ret;
u8 lsr;
ret = ti_get_lsr(tport, &lsr);
if (!ret && !(lsr & TI_LSR_TX_EMPTY))
return false;
return true;
}
static void ti_throttle(struct tty_struct *tty)
{
struct usb_serial_port *port = tty->driver_data;
struct ti_port *tport = usb_get_serial_port_data(port);
if (I_IXOFF(tty) || C_CRTSCTS(tty))
ti_stop_read(tport, tty);
}
static void ti_unthrottle(struct tty_struct *tty)
{
struct usb_serial_port *port = tty->driver_data;
struct ti_port *tport = usb_get_serial_port_data(port);
int status;
if (I_IXOFF(tty) || C_CRTSCTS(tty)) {
status = ti_restart_read(tport, tty);
if (status)
dev_err(&port->dev, "%s - cannot restart read, %d\n",
__func__, status);
}
}
static int ti_ioctl(struct tty_struct *tty,
unsigned int cmd, unsigned long arg)
{
struct usb_serial_port *port = tty->driver_data;
struct ti_port *tport = usb_get_serial_port_data(port);
switch (cmd) {
case TIOCGSERIAL:
return ti_get_serial_info(tport,
(struct serial_struct __user *)arg);
case TIOCSSERIAL:
return ti_set_serial_info(tty, tport,
(struct serial_struct __user *)arg);
}
return -ENOIOCTLCMD;
}
static void ti_set_termios(struct tty_struct *tty,
struct usb_serial_port *port, struct ktermios *old_termios)
{
struct ti_port *tport = usb_get_serial_port_data(port);
struct ti_uart_config *config;
tcflag_t cflag, iflag;
int baud;
int status;
int port_number = port->port_number;
unsigned int mcr;
u16 wbaudrate;
u16 wflags = 0;
cflag = tty->termios.c_cflag;
iflag = tty->termios.c_iflag;
dev_dbg(&port->dev, "%s - cflag %08x, iflag %08x\n", __func__, cflag, iflag);
dev_dbg(&port->dev, "%s - old clfag %08x, old iflag %08x\n", __func__,
old_termios->c_cflag, old_termios->c_iflag);
config = kmalloc(sizeof(*config), GFP_KERNEL);
if (!config)
return;
wflags |= TI_UART_ENABLE_MS_INTS;
wflags |= TI_UART_ENABLE_AUTO_START_DMA;
config->bUartMode = tport->tp_uart_mode;
switch (C_CSIZE(tty)) {
case CS5:
config->bDataBits = TI_UART_5_DATA_BITS;
break;
case CS6:
config->bDataBits = TI_UART_6_DATA_BITS;
break;
case CS7:
config->bDataBits = TI_UART_7_DATA_BITS;
break;
default:
case CS8:
config->bDataBits = TI_UART_8_DATA_BITS;
break;
}
tty->termios.c_cflag &= ~CMSPAR;
if (C_PARENB(tty)) {
if (C_PARODD(tty)) {
wflags |= TI_UART_ENABLE_PARITY_CHECKING;
config->bParity = TI_UART_ODD_PARITY;
} else {
wflags |= TI_UART_ENABLE_PARITY_CHECKING;
config->bParity = TI_UART_EVEN_PARITY;
}
} else {
wflags &= ~TI_UART_ENABLE_PARITY_CHECKING;
config->bParity = TI_UART_NO_PARITY;
}
if (C_CSTOPB(tty))
config->bStopBits = TI_UART_2_STOP_BITS;
else
config->bStopBits = TI_UART_1_STOP_BITS;
if (C_CRTSCTS(tty)) {
if ((C_BAUD(tty)) != B0)
wflags |= TI_UART_ENABLE_RTS_IN;
wflags |= TI_UART_ENABLE_CTS_OUT;
} else {
ti_restart_read(tport, tty);
}
if (I_IXOFF(tty) || I_IXON(tty)) {
config->cXon = START_CHAR(tty);
config->cXoff = STOP_CHAR(tty);
if (I_IXOFF(tty))
wflags |= TI_UART_ENABLE_X_IN;
else
ti_restart_read(tport, tty);
if (I_IXON(tty))
wflags |= TI_UART_ENABLE_X_OUT;
}
baud = tty_get_baud_rate(tty);
if (!baud)
baud = 9600;
if (tport->tp_tdev->td_is_3410)
wbaudrate = (923077 + baud/2) / baud;
else
wbaudrate = (461538 + baud/2) / baud;
if ((C_BAUD(tty)) != B0)
tty_encode_baud_rate(tty, baud, baud);
dev_dbg(&port->dev,
"%s - BaudRate=%d, wBaudRate=%d, wFlags=0x%04X, bDataBits=%d, bParity=%d, bStopBits=%d, cXon=%d, cXoff=%d, bUartMode=%d\n",
__func__, baud, wbaudrate, wflags,
config->bDataBits, config->bParity, config->bStopBits,
config->cXon, config->cXoff, config->bUartMode);
config->wBaudRate = cpu_to_be16(wbaudrate);
config->wFlags = cpu_to_be16(wflags);
status = ti_command_out_sync(tport->tp_tdev, TI_SET_CONFIG,
(__u8)(TI_UART1_PORT + port_number), 0, (__u8 *)config,
sizeof(*config));
if (status)
dev_err(&port->dev, "%s - cannot set config on port %d, %d\n",
__func__, port_number, status);
mcr = tport->tp_shadow_mcr;
if (C_BAUD(tty) == B0)
mcr &= ~(TI_MCR_DTR | TI_MCR_RTS);
status = ti_set_mcr(tport, mcr);
if (status)
dev_err(&port->dev,
"%s - cannot set modem control on port %d, %d\n",
__func__, port_number, status);
kfree(config);
}
static int ti_tiocmget(struct tty_struct *tty)
{
struct usb_serial_port *port = tty->driver_data;
struct ti_port *tport = usb_get_serial_port_data(port);
unsigned int result;
unsigned int msr;
unsigned int mcr;
unsigned long flags;
spin_lock_irqsave(&tport->tp_lock, flags);
msr = tport->tp_msr;
mcr = tport->tp_shadow_mcr;
spin_unlock_irqrestore(&tport->tp_lock, flags);
result = ((mcr & TI_MCR_DTR) ? TIOCM_DTR : 0)
| ((mcr & TI_MCR_RTS) ? TIOCM_RTS : 0)
| ((mcr & TI_MCR_LOOP) ? TIOCM_LOOP : 0)
| ((msr & TI_MSR_CTS) ? TIOCM_CTS : 0)
| ((msr & TI_MSR_CD) ? TIOCM_CAR : 0)
| ((msr & TI_MSR_RI) ? TIOCM_RI : 0)
| ((msr & TI_MSR_DSR) ? TIOCM_DSR : 0);
dev_dbg(&port->dev, "%s - 0x%04X\n", __func__, result);
return result;
}
static int ti_tiocmset(struct tty_struct *tty,
unsigned int set, unsigned int clear)
{
struct usb_serial_port *port = tty->driver_data;
struct ti_port *tport = usb_get_serial_port_data(port);
unsigned int mcr;
unsigned long flags;
spin_lock_irqsave(&tport->tp_lock, flags);
mcr = tport->tp_shadow_mcr;
if (set & TIOCM_RTS)
mcr |= TI_MCR_RTS;
if (set & TIOCM_DTR)
mcr |= TI_MCR_DTR;
if (set & TIOCM_LOOP)
mcr |= TI_MCR_LOOP;
if (clear & TIOCM_RTS)
mcr &= ~TI_MCR_RTS;
if (clear & TIOCM_DTR)
mcr &= ~TI_MCR_DTR;
if (clear & TIOCM_LOOP)
mcr &= ~TI_MCR_LOOP;
spin_unlock_irqrestore(&tport->tp_lock, flags);
return ti_set_mcr(tport, mcr);
}
static void ti_break(struct tty_struct *tty, int break_state)
{
struct usb_serial_port *port = tty->driver_data;
struct ti_port *tport = usb_get_serial_port_data(port);
int status;
dev_dbg(&port->dev, "%s - state = %d\n", __func__, break_state);
status = ti_write_byte(port, tport->tp_tdev,
tport->tp_uart_base_addr + TI_UART_OFFSET_LCR,
TI_LCR_BREAK, break_state == -1 ? TI_LCR_BREAK : 0);
if (status)
dev_dbg(&port->dev, "%s - error setting break, %d\n", __func__, status);
}
static int ti_get_port_from_code(unsigned char code)
{
return (code >> 4) - 3;
}
static int ti_get_func_from_code(unsigned char code)
{
return code & 0x0f;
}
static void ti_interrupt_callback(struct urb *urb)
{
struct ti_device *tdev = urb->context;
struct usb_serial_port *port;
struct usb_serial *serial = tdev->td_serial;
struct ti_port *tport;
struct device *dev = &urb->dev->dev;
unsigned char *data = urb->transfer_buffer;
int length = urb->actual_length;
int port_number;
int function;
int status = urb->status;
int retval;
u8 msr;
switch (status) {
case 0:
break;
case -ECONNRESET:
case -ENOENT:
case -ESHUTDOWN:
dev_dbg(dev, "%s - urb shutting down, %d\n", __func__, status);
return;
default:
dev_err(dev, "%s - nonzero urb status, %d\n", __func__, status);
goto exit;
}
if (length != 2) {
dev_dbg(dev, "%s - bad packet size, %d\n", __func__, length);
goto exit;
}
if (data[0] == TI_CODE_HARDWARE_ERROR) {
dev_err(dev, "%s - hardware error, %d\n", __func__, data[1]);
goto exit;
}
port_number = ti_get_port_from_code(data[0]);
function = ti_get_func_from_code(data[0]);
dev_dbg(dev, "%s - port_number %d, function %d, data 0x%02X\n",
__func__, port_number, function, data[1]);
if (port_number >= serial->num_ports) {
dev_err(dev, "%s - bad port number, %d\n",
__func__, port_number);
goto exit;
}
port = serial->port[port_number];
tport = usb_get_serial_port_data(port);
if (!tport)
goto exit;
switch (function) {
case TI_CODE_DATA_ERROR:
dev_err(dev, "%s - DATA ERROR, port %d, data 0x%02X\n",
__func__, port_number, data[1]);
break;
case TI_CODE_MODEM_STATUS:
msr = data[1];
dev_dbg(dev, "%s - port %d, msr 0x%02X\n", __func__, port_number, msr);
ti_handle_new_msr(tport, msr);
break;
default:
dev_err(dev, "%s - unknown interrupt code, 0x%02X\n",
__func__, data[1]);
break;
}
exit:
retval = usb_submit_urb(urb, GFP_ATOMIC);
if (retval)
dev_err(dev, "%s - resubmit interrupt urb failed, %d\n",
__func__, retval);
}
static void ti_bulk_in_callback(struct urb *urb)
{
struct ti_port *tport = urb->context;
struct usb_serial_port *port = tport->tp_port;
struct device *dev = &urb->dev->dev;
int status = urb->status;
int retval = 0;
switch (status) {
case 0:
break;
case -ECONNRESET:
case -ENOENT:
case -ESHUTDOWN:
dev_dbg(dev, "%s - urb shutting down, %d\n", __func__, status);
return;
default:
dev_err(dev, "%s - nonzero urb status, %d\n",
__func__, status);
}
if (status == -EPIPE)
goto exit;
if (status) {
dev_err(dev, "%s - stopping read!\n", __func__);
return;
}
if (urb->actual_length) {
usb_serial_debug_data(dev, __func__, urb->actual_length,
urb->transfer_buffer);
if (!tport->tp_is_open)
dev_dbg(dev, "%s - port closed, dropping data\n",
__func__);
else
ti_recv(port, urb->transfer_buffer, urb->actual_length);
spin_lock(&tport->tp_lock);
port->icount.rx += urb->actual_length;
spin_unlock(&tport->tp_lock);
}
exit:
spin_lock(&tport->tp_lock);
if (tport->tp_read_urb_state == TI_READ_URB_RUNNING)
retval = usb_submit_urb(urb, GFP_ATOMIC);
else if (tport->tp_read_urb_state == TI_READ_URB_STOPPING)
tport->tp_read_urb_state = TI_READ_URB_STOPPED;
spin_unlock(&tport->tp_lock);
if (retval)
dev_err(dev, "%s - resubmit read urb failed, %d\n",
__func__, retval);
}
static void ti_bulk_out_callback(struct urb *urb)
{
struct ti_port *tport = urb->context;
struct usb_serial_port *port = tport->tp_port;
int status = urb->status;
tport->tp_write_urb_in_use = 0;
switch (status) {
case 0:
break;
case -ECONNRESET:
case -ENOENT:
case -ESHUTDOWN:
dev_dbg(&port->dev, "%s - urb shutting down, %d\n", __func__, status);
return;
default:
dev_err_console(port, "%s - nonzero urb status, %d\n",
__func__, status);
}
ti_send(tport);
}
static void ti_recv(struct usb_serial_port *port, unsigned char *data,
int length)
{
int cnt;
do {
cnt = tty_insert_flip_string(&port->port, data, length);
if (cnt < length) {
dev_err(&port->dev, "%s - dropping data, %d bytes lost\n",
__func__, length - cnt);
if (cnt == 0)
break;
}
tty_flip_buffer_push(&port->port);
data += cnt;
length -= cnt;
} while (length > 0);
}
static void ti_send(struct ti_port *tport)
{
int count, result;
struct usb_serial_port *port = tport->tp_port;
unsigned long flags;
spin_lock_irqsave(&tport->tp_lock, flags);
if (tport->tp_write_urb_in_use)
goto unlock;
count = kfifo_out(&port->write_fifo,
port->write_urb->transfer_buffer,
port->bulk_out_size);
if (count == 0)
goto unlock;
tport->tp_write_urb_in_use = 1;
spin_unlock_irqrestore(&tport->tp_lock, flags);
usb_serial_debug_data(&port->dev, __func__, count,
port->write_urb->transfer_buffer);
usb_fill_bulk_urb(port->write_urb, port->serial->dev,
usb_sndbulkpipe(port->serial->dev,
port->bulk_out_endpointAddress),
port->write_urb->transfer_buffer, count,
ti_bulk_out_callback, tport);
result = usb_submit_urb(port->write_urb, GFP_ATOMIC);
if (result) {
dev_err_console(port, "%s - submit write urb failed, %d\n",
__func__, result);
tport->tp_write_urb_in_use = 0;
} else {
spin_lock_irqsave(&tport->tp_lock, flags);
port->icount.tx += count;
spin_unlock_irqrestore(&tport->tp_lock, flags);
}
tty_port_tty_wakeup(&port->port);
return;
unlock:
spin_unlock_irqrestore(&tport->tp_lock, flags);
return;
}
static int ti_set_mcr(struct ti_port *tport, unsigned int mcr)
{
unsigned long flags;
int status;
status = ti_write_byte(tport->tp_port, tport->tp_tdev,
tport->tp_uart_base_addr + TI_UART_OFFSET_MCR,
TI_MCR_RTS | TI_MCR_DTR | TI_MCR_LOOP, mcr);
spin_lock_irqsave(&tport->tp_lock, flags);
if (!status)
tport->tp_shadow_mcr = mcr;
spin_unlock_irqrestore(&tport->tp_lock, flags);
return status;
}
static int ti_get_lsr(struct ti_port *tport, u8 *lsr)
{
int size, status;
struct ti_device *tdev = tport->tp_tdev;
struct usb_serial_port *port = tport->tp_port;
int port_number = port->port_number;
struct ti_port_status *data;
size = sizeof(struct ti_port_status);
data = kmalloc(size, GFP_KERNEL);
if (!data)
return -ENOMEM;
status = ti_command_in_sync(tdev, TI_GET_PORT_STATUS,
(__u8)(TI_UART1_PORT+port_number), 0, (__u8 *)data, size);
if (status) {
dev_err(&port->dev,
"%s - get port status command failed, %d\n",
__func__, status);
goto free_data;
}
dev_dbg(&port->dev, "%s - lsr 0x%02X\n", __func__, data->bLSR);
*lsr = data->bLSR;
free_data:
kfree(data);
return status;
}
static int ti_get_serial_info(struct ti_port *tport,
struct serial_struct __user *ret_arg)
{
struct usb_serial_port *port = tport->tp_port;
struct serial_struct ret_serial;
unsigned cwait;
if (!ret_arg)
return -EFAULT;
cwait = port->port.closing_wait;
if (cwait != ASYNC_CLOSING_WAIT_NONE)
cwait = jiffies_to_msecs(cwait) / 10;
memset(&ret_serial, 0, sizeof(ret_serial));
ret_serial.type = PORT_16550A;
ret_serial.line = port->minor;
ret_serial.port = port->port_number;
ret_serial.xmit_fifo_size = kfifo_size(&port->write_fifo);
ret_serial.baud_base = tport->tp_tdev->td_is_3410 ? 921600 : 460800;
ret_serial.closing_wait = cwait;
if (copy_to_user(ret_arg, &ret_serial, sizeof(*ret_arg)))
return -EFAULT;
return 0;
}
static int ti_set_serial_info(struct tty_struct *tty, struct ti_port *tport,
struct serial_struct __user *new_arg)
{
struct serial_struct new_serial;
unsigned cwait;
if (copy_from_user(&new_serial, new_arg, sizeof(new_serial)))
return -EFAULT;
cwait = new_serial.closing_wait;
if (cwait != ASYNC_CLOSING_WAIT_NONE)
cwait = msecs_to_jiffies(10 * new_serial.closing_wait);
tport->tp_port->port.closing_wait = cwait;
return 0;
}
static void ti_handle_new_msr(struct ti_port *tport, u8 msr)
{
struct async_icount *icount;
struct tty_struct *tty;
unsigned long flags;
dev_dbg(&tport->tp_port->dev, "%s - msr 0x%02X\n", __func__, msr);
if (msr & TI_MSR_DELTA_MASK) {
spin_lock_irqsave(&tport->tp_lock, flags);
icount = &tport->tp_port->icount;
if (msr & TI_MSR_DELTA_CTS)
icount->cts++;
if (msr & TI_MSR_DELTA_DSR)
icount->dsr++;
if (msr & TI_MSR_DELTA_CD)
icount->dcd++;
if (msr & TI_MSR_DELTA_RI)
icount->rng++;
wake_up_interruptible(&tport->tp_port->port.delta_msr_wait);
spin_unlock_irqrestore(&tport->tp_lock, flags);
}
tport->tp_msr = msr & TI_MSR_MASK;
tty = tty_port_tty_get(&tport->tp_port->port);
if (tty && C_CRTSCTS(tty)) {
if (msr & TI_MSR_CTS)
tty_wakeup(tty);
}
tty_kref_put(tty);
}
static void ti_stop_read(struct ti_port *tport, struct tty_struct *tty)
{
unsigned long flags;
spin_lock_irqsave(&tport->tp_lock, flags);
if (tport->tp_read_urb_state == TI_READ_URB_RUNNING)
tport->tp_read_urb_state = TI_READ_URB_STOPPING;
spin_unlock_irqrestore(&tport->tp_lock, flags);
}
static int ti_restart_read(struct ti_port *tport, struct tty_struct *tty)
{
struct urb *urb;
int status = 0;
unsigned long flags;
spin_lock_irqsave(&tport->tp_lock, flags);
if (tport->tp_read_urb_state == TI_READ_URB_STOPPED) {
tport->tp_read_urb_state = TI_READ_URB_RUNNING;
urb = tport->tp_port->read_urb;
spin_unlock_irqrestore(&tport->tp_lock, flags);
urb->context = tport;
status = usb_submit_urb(urb, GFP_KERNEL);
} else {
tport->tp_read_urb_state = TI_READ_URB_RUNNING;
spin_unlock_irqrestore(&tport->tp_lock, flags);
}
return status;
}
static int ti_command_out_sync(struct ti_device *tdev, __u8 command,
__u16 moduleid, __u16 value, __u8 *data, int size)
{
int status;
status = usb_control_msg(tdev->td_serial->dev,
usb_sndctrlpipe(tdev->td_serial->dev, 0), command,
(USB_TYPE_VENDOR | USB_RECIP_DEVICE | USB_DIR_OUT),
value, moduleid, data, size, 1000);
if (status == size)
status = 0;
if (status > 0)
status = -ECOMM;
return status;
}
static int ti_command_in_sync(struct ti_device *tdev, __u8 command,
__u16 moduleid, __u16 value, __u8 *data, int size)
{
int status;
status = usb_control_msg(tdev->td_serial->dev,
usb_rcvctrlpipe(tdev->td_serial->dev, 0), command,
(USB_TYPE_VENDOR | USB_RECIP_DEVICE | USB_DIR_IN),
value, moduleid, data, size, 1000);
if (status == size)
status = 0;
if (status > 0)
status = -ECOMM;
return status;
}
static int ti_write_byte(struct usb_serial_port *port,
struct ti_device *tdev, unsigned long addr,
u8 mask, u8 byte)
{
int status;
unsigned int size;
struct ti_write_data_bytes *data;
dev_dbg(&port->dev, "%s - addr 0x%08lX, mask 0x%02X, byte 0x%02X\n", __func__,
addr, mask, byte);
size = sizeof(struct ti_write_data_bytes) + 2;
data = kmalloc(size, GFP_KERNEL);
if (!data)
return -ENOMEM;
data->bAddrType = TI_RW_DATA_ADDR_XDATA;
data->bDataType = TI_RW_DATA_BYTE;
data->bDataCounter = 1;
data->wBaseAddrHi = cpu_to_be16(addr>>16);
data->wBaseAddrLo = cpu_to_be16(addr);
data->bData[0] = mask;
data->bData[1] = byte;
status = ti_command_out_sync(tdev, TI_WRITE_DATA, TI_RAM_PORT, 0,
(__u8 *)data, size);
if (status < 0)
dev_err(&port->dev, "%s - failed, %d\n", __func__, status);
kfree(data);
return status;
}
static int ti_do_download(struct usb_device *dev, int pipe,
u8 *buffer, int size)
{
int pos;
u8 cs = 0;
int done;
struct ti_firmware_header *header;
int status = 0;
int len;
for (pos = sizeof(struct ti_firmware_header); pos < size; pos++)
cs = (u8)(cs + buffer[pos]);
header = (struct ti_firmware_header *)buffer;
header->wLength = cpu_to_le16(size - sizeof(*header));
header->bCheckSum = cs;
dev_dbg(&dev->dev, "%s - downloading firmware\n", __func__);
for (pos = 0; pos < size; pos += done) {
len = min(size - pos, TI_DOWNLOAD_MAX_PACKET_SIZE);
status = usb_bulk_msg(dev, pipe, buffer + pos, len,
&done, 1000);
if (status)
break;
}
return status;
}
static int ti_download_firmware(struct ti_device *tdev)
{
int status;
int buffer_size;
u8 *buffer;
struct usb_device *dev = tdev->td_serial->dev;
unsigned int pipe = usb_sndbulkpipe(dev,
tdev->td_serial->port[0]->bulk_out_endpointAddress);
const struct firmware *fw_p;
char buf[32];
if (le16_to_cpu(dev->descriptor.idVendor) == MXU1_VENDOR_ID) {
snprintf(buf,
sizeof(buf),
"moxa/moxa-%04x.fw",
le16_to_cpu(dev->descriptor.idProduct));
status = request_firmware(&fw_p, buf, &dev->dev);
goto check_firmware;
}
sprintf(buf, "ti_usb-v%04x-p%04x.fw",
le16_to_cpu(dev->descriptor.idVendor),
le16_to_cpu(dev->descriptor.idProduct));
status = request_firmware(&fw_p, buf, &dev->dev);
if (status != 0) {
buf[0] = '\0';
if (le16_to_cpu(dev->descriptor.idVendor) == MTS_VENDOR_ID) {
switch (le16_to_cpu(dev->descriptor.idProduct)) {
case MTS_CDMA_PRODUCT_ID:
strcpy(buf, "mts_cdma.fw");
break;
case MTS_GSM_PRODUCT_ID:
strcpy(buf, "mts_gsm.fw");
break;
case MTS_EDGE_PRODUCT_ID:
strcpy(buf, "mts_edge.fw");
break;
case MTS_MT9234MU_PRODUCT_ID:
strcpy(buf, "mts_mt9234mu.fw");
break;
case MTS_MT9234ZBA_PRODUCT_ID:
strcpy(buf, "mts_mt9234zba.fw");
break;
case MTS_MT9234ZBAOLD_PRODUCT_ID:
strcpy(buf, "mts_mt9234zba.fw");
break; }
}
if (buf[0] == '\0') {
if (tdev->td_is_3410)
strcpy(buf, "ti_3410.fw");
else
strcpy(buf, "ti_5052.fw");
}
status = request_firmware(&fw_p, buf, &dev->dev);
}
check_firmware:
if (status) {
dev_err(&dev->dev, "%s - firmware not found\n", __func__);
return -ENOENT;
}
if (fw_p->size > TI_FIRMWARE_BUF_SIZE) {
dev_err(&dev->dev, "%s - firmware too large %zu\n", __func__, fw_p->size);
release_firmware(fw_p);
return -ENOENT;
}
buffer_size = TI_FIRMWARE_BUF_SIZE + sizeof(struct ti_firmware_header);
buffer = kmalloc(buffer_size, GFP_KERNEL);
if (buffer) {
memcpy(buffer, fw_p->data, fw_p->size);
memset(buffer + fw_p->size, 0xff, buffer_size - fw_p->size);
status = ti_do_download(dev, pipe, buffer, fw_p->size);
kfree(buffer);
} else {
status = -ENOMEM;
}
release_firmware(fw_p);
if (status) {
dev_err(&dev->dev, "%s - error downloading firmware, %d\n",
__func__, status);
return status;
}
dev_dbg(&dev->dev, "%s - download successful\n", __func__);
return 0;
}
