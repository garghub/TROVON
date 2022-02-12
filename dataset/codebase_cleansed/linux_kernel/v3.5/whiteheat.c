static int whiteheat_firmware_download(struct usb_serial *serial,
const struct usb_device_id *id)
{
int response, ret = -ENOENT;
const struct firmware *loader_fw = NULL, *firmware_fw = NULL;
const struct ihex_binrec *record;
if (request_ihex_firmware(&firmware_fw, "whiteheat.fw",
&serial->dev->dev)) {
dev_err(&serial->dev->dev,
"%s - request \"whiteheat.fw\" failed\n", __func__);
goto out;
}
if (request_ihex_firmware(&loader_fw, "whiteheat_loader.fw",
&serial->dev->dev)) {
dev_err(&serial->dev->dev,
"%s - request \"whiteheat_loader.fw\" failed\n",
__func__);
goto out;
}
ret = 0;
response = ezusb_set_reset (serial, 1);
record = (const struct ihex_binrec *)loader_fw->data;
while (record) {
response = ezusb_writememory (serial, be32_to_cpu(record->addr),
(unsigned char *)record->data,
be16_to_cpu(record->len), 0xa0);
if (response < 0) {
dev_err(&serial->dev->dev, "%s - ezusb_writememory "
"failed for loader (%d %04X %p %d)\n",
__func__, response, be32_to_cpu(record->addr),
record->data, be16_to_cpu(record->len));
break;
}
record = ihex_next_binrec(record);
}
response = ezusb_set_reset(serial, 0);
record = (const struct ihex_binrec *)firmware_fw->data;
while (record && be32_to_cpu(record->addr) < 0x1b40)
record = ihex_next_binrec(record);
while (record) {
response = ezusb_writememory (serial, be32_to_cpu(record->addr),
(unsigned char *)record->data,
be16_to_cpu(record->len), 0xa3);
if (response < 0) {
dev_err(&serial->dev->dev, "%s - ezusb_writememory "
"failed for first firmware step "
"(%d %04X %p %d)\n", __func__, response,
be32_to_cpu(record->addr), record->data,
be16_to_cpu(record->len));
break;
}
++record;
}
response = ezusb_set_reset(serial, 1);
record = (const struct ihex_binrec *)firmware_fw->data;
while (record && be32_to_cpu(record->addr) < 0x1b40) {
response = ezusb_writememory (serial, be32_to_cpu(record->addr),
(unsigned char *)record->data,
be16_to_cpu(record->len), 0xa0);
if (response < 0) {
dev_err(&serial->dev->dev, "%s - ezusb_writememory "
"failed for second firmware step "
"(%d %04X %p %d)\n", __func__, response,
be32_to_cpu(record->addr), record->data,
be16_to_cpu(record->len));
break;
}
++record;
}
ret = 0;
response = ezusb_set_reset (serial, 0);
out:
release_firmware(loader_fw);
release_firmware(firmware_fw);
return ret;
}
static int whiteheat_firmware_attach(struct usb_serial *serial)
{
return 1;
}
static int whiteheat_attach(struct usb_serial *serial)
{
struct usb_serial_port *command_port;
struct whiteheat_command_private *command_info;
struct usb_serial_port *port;
struct whiteheat_private *info;
struct whiteheat_hw_info *hw_info;
int pipe;
int ret;
int alen;
__u8 *command;
__u8 *result;
int i;
command_port = serial->port[COMMAND_PORT];
pipe = usb_sndbulkpipe(serial->dev,
command_port->bulk_out_endpointAddress);
command = kmalloc(2, GFP_KERNEL);
if (!command)
goto no_command_buffer;
command[0] = WHITEHEAT_GET_HW_INFO;
command[1] = 0;
result = kmalloc(sizeof(*hw_info) + 1, GFP_KERNEL);
if (!result)
goto no_result_buffer;
usb_clear_halt(serial->dev, pipe);
ret = usb_bulk_msg(serial->dev, pipe, command, 2,
&alen, COMMAND_TIMEOUT_MS);
if (ret) {
dev_err(&serial->dev->dev, "%s: Couldn't send command [%d]\n",
serial->type->description, ret);
goto no_firmware;
} else if (alen != 2) {
dev_err(&serial->dev->dev, "%s: Send command incomplete [%d]\n",
serial->type->description, alen);
goto no_firmware;
}
pipe = usb_rcvbulkpipe(serial->dev,
command_port->bulk_in_endpointAddress);
usb_clear_halt(serial->dev, pipe);
ret = usb_bulk_msg(serial->dev, pipe, result,
sizeof(*hw_info) + 1, &alen, COMMAND_TIMEOUT_MS);
if (ret) {
dev_err(&serial->dev->dev, "%s: Couldn't get results [%d]\n",
serial->type->description, ret);
goto no_firmware;
} else if (alen != sizeof(*hw_info) + 1) {
dev_err(&serial->dev->dev, "%s: Get results incomplete [%d]\n",
serial->type->description, alen);
goto no_firmware;
} else if (result[0] != command[0]) {
dev_err(&serial->dev->dev, "%s: Command failed [%d]\n",
serial->type->description, result[0]);
goto no_firmware;
}
hw_info = (struct whiteheat_hw_info *)&result[1];
dev_info(&serial->dev->dev, "%s: Firmware v%d.%02d\n",
serial->type->description,
hw_info->sw_major_rev, hw_info->sw_minor_rev);
for (i = 0; i < serial->num_ports; i++) {
port = serial->port[i];
info = kmalloc(sizeof(struct whiteheat_private), GFP_KERNEL);
if (info == NULL) {
dev_err(&port->dev,
"%s: Out of memory for port structures\n",
serial->type->description);
goto no_private;
}
info->mcr = 0;
usb_set_serial_port_data(port, info);
}
command_info = kmalloc(sizeof(struct whiteheat_command_private),
GFP_KERNEL);
if (command_info == NULL) {
dev_err(&serial->dev->dev,
"%s: Out of memory for port structures\n",
serial->type->description);
goto no_command_private;
}
mutex_init(&command_info->mutex);
command_info->port_running = 0;
init_waitqueue_head(&command_info->wait_command);
usb_set_serial_port_data(command_port, command_info);
command_port->write_urb->complete = command_port_write_callback;
command_port->read_urb->complete = command_port_read_callback;
kfree(result);
kfree(command);
return 0;
no_firmware:
dev_err(&serial->dev->dev,
"%s: Unable to retrieve firmware version, try replugging\n",
serial->type->description);
dev_err(&serial->dev->dev,
"%s: If the firmware is not running (status led not blinking)\n",
serial->type->description);
dev_err(&serial->dev->dev,
"%s: please contact support@connecttech.com\n",
serial->type->description);
kfree(result);
return -ENODEV;
no_command_private:
for (i = serial->num_ports - 1; i >= 0; i--) {
port = serial->port[i];
info = usb_get_serial_port_data(port);
kfree(info);
no_private:
;
}
kfree(result);
no_result_buffer:
kfree(command);
no_command_buffer:
return -ENOMEM;
}
static void whiteheat_release(struct usb_serial *serial)
{
struct usb_serial_port *command_port;
struct whiteheat_private *info;
int i;
command_port = serial->port[COMMAND_PORT];
kfree(usb_get_serial_port_data(command_port));
for (i = 0; i < serial->num_ports; i++) {
info = usb_get_serial_port_data(serial->port[i]);
kfree(info);
}
}
static int whiteheat_open(struct tty_struct *tty, struct usb_serial_port *port)
{
int retval;
retval = start_command_port(port->serial);
if (retval)
goto exit;
retval = firm_open(port);
if (retval) {
stop_command_port(port->serial);
goto exit;
}
retval = firm_purge(port, WHITEHEAT_PURGE_RX | WHITEHEAT_PURGE_TX);
if (retval) {
firm_close(port);
stop_command_port(port->serial);
goto exit;
}
if (tty)
firm_setup_port(tty);
usb_clear_halt(port->serial->dev, port->read_urb->pipe);
usb_clear_halt(port->serial->dev, port->write_urb->pipe);
retval = usb_serial_generic_open(tty, port);
if (retval) {
firm_close(port);
stop_command_port(port->serial);
goto exit;
}
exit:
return retval;
}
static void whiteheat_close(struct usb_serial_port *port)
{
firm_report_tx_done(port);
firm_close(port);
usb_serial_generic_close(port);
stop_command_port(port->serial);
}
static int whiteheat_tiocmget(struct tty_struct *tty)
{
struct usb_serial_port *port = tty->driver_data;
struct whiteheat_private *info = usb_get_serial_port_data(port);
unsigned int modem_signals = 0;
firm_get_dtr_rts(port);
if (info->mcr & UART_MCR_DTR)
modem_signals |= TIOCM_DTR;
if (info->mcr & UART_MCR_RTS)
modem_signals |= TIOCM_RTS;
return modem_signals;
}
static int whiteheat_tiocmset(struct tty_struct *tty,
unsigned int set, unsigned int clear)
{
struct usb_serial_port *port = tty->driver_data;
struct whiteheat_private *info = usb_get_serial_port_data(port);
if (set & TIOCM_RTS)
info->mcr |= UART_MCR_RTS;
if (set & TIOCM_DTR)
info->mcr |= UART_MCR_DTR;
if (clear & TIOCM_RTS)
info->mcr &= ~UART_MCR_RTS;
if (clear & TIOCM_DTR)
info->mcr &= ~UART_MCR_DTR;
firm_set_dtr(port, info->mcr & UART_MCR_DTR);
firm_set_rts(port, info->mcr & UART_MCR_RTS);
return 0;
}
static int whiteheat_ioctl(struct tty_struct *tty,
unsigned int cmd, unsigned long arg)
{
struct usb_serial_port *port = tty->driver_data;
struct serial_struct serstruct;
void __user *user_arg = (void __user *)arg;
dbg("%s - port %d, cmd 0x%.4x", __func__, port->number, cmd);
switch (cmd) {
case TIOCGSERIAL:
memset(&serstruct, 0, sizeof(serstruct));
serstruct.type = PORT_16654;
serstruct.line = port->serial->minor;
serstruct.port = port->number;
serstruct.flags = ASYNC_SKIP_TEST | ASYNC_AUTO_IRQ;
serstruct.xmit_fifo_size = kfifo_size(&port->write_fifo);
serstruct.custom_divisor = 0;
serstruct.baud_base = 460800;
serstruct.close_delay = CLOSING_DELAY;
serstruct.closing_wait = CLOSING_DELAY;
if (copy_to_user(user_arg, &serstruct, sizeof(serstruct)))
return -EFAULT;
break;
default:
break;
}
return -ENOIOCTLCMD;
}
static void whiteheat_set_termios(struct tty_struct *tty,
struct usb_serial_port *port, struct ktermios *old_termios)
{
firm_setup_port(tty);
}
static void whiteheat_break_ctl(struct tty_struct *tty, int break_state)
{
struct usb_serial_port *port = tty->driver_data;
firm_set_break(port, break_state);
}
static void command_port_write_callback(struct urb *urb)
{
int status = urb->status;
if (status) {
dbg("nonzero urb status: %d", status);
return;
}
}
static void command_port_read_callback(struct urb *urb)
{
struct usb_serial_port *command_port = urb->context;
struct whiteheat_command_private *command_info;
int status = urb->status;
unsigned char *data = urb->transfer_buffer;
int result;
command_info = usb_get_serial_port_data(command_port);
if (!command_info) {
dbg("%s - command_info is NULL, exiting.", __func__);
return;
}
if (status) {
dbg("%s - nonzero urb status: %d", __func__, status);
if (status != -ENOENT)
command_info->command_finished = WHITEHEAT_CMD_FAILURE;
wake_up(&command_info->wait_command);
return;
}
usb_serial_debug_data(debug, &command_port->dev,
__func__, urb->actual_length, data);
if (data[0] == WHITEHEAT_CMD_COMPLETE) {
command_info->command_finished = WHITEHEAT_CMD_COMPLETE;
wake_up(&command_info->wait_command);
} else if (data[0] == WHITEHEAT_CMD_FAILURE) {
command_info->command_finished = WHITEHEAT_CMD_FAILURE;
wake_up(&command_info->wait_command);
} else if (data[0] == WHITEHEAT_EVENT) {
dbg("%s - event received", __func__);
} else if (data[0] == WHITEHEAT_GET_DTR_RTS) {
memcpy(command_info->result_buffer, &data[1],
urb->actual_length - 1);
command_info->command_finished = WHITEHEAT_CMD_COMPLETE;
wake_up(&command_info->wait_command);
} else
dbg("%s - bad reply from firmware", __func__);
result = usb_submit_urb(command_port->read_urb, GFP_ATOMIC);
if (result)
dbg("%s - failed resubmitting read urb, error %d",
__func__, result);
}
static int firm_send_command(struct usb_serial_port *port, __u8 command,
__u8 *data, __u8 datasize)
{
struct usb_serial_port *command_port;
struct whiteheat_command_private *command_info;
struct whiteheat_private *info;
__u8 *transfer_buffer;
int retval = 0;
int t;
dbg("%s - command %d", __func__, command);
command_port = port->serial->port[COMMAND_PORT];
command_info = usb_get_serial_port_data(command_port);
mutex_lock(&command_info->mutex);
command_info->command_finished = false;
transfer_buffer = (__u8 *)command_port->write_urb->transfer_buffer;
transfer_buffer[0] = command;
memcpy(&transfer_buffer[1], data, datasize);
command_port->write_urb->transfer_buffer_length = datasize + 1;
retval = usb_submit_urb(command_port->write_urb, GFP_NOIO);
if (retval) {
dbg("%s - submit urb failed", __func__);
goto exit;
}
t = wait_event_timeout(command_info->wait_command,
(bool)command_info->command_finished, COMMAND_TIMEOUT);
if (!t)
usb_kill_urb(command_port->write_urb);
if (command_info->command_finished == false) {
dbg("%s - command timed out.", __func__);
retval = -ETIMEDOUT;
goto exit;
}
if (command_info->command_finished == WHITEHEAT_CMD_FAILURE) {
dbg("%s - command failed.", __func__);
retval = -EIO;
goto exit;
}
if (command_info->command_finished == WHITEHEAT_CMD_COMPLETE) {
dbg("%s - command completed.", __func__);
switch (command) {
case WHITEHEAT_GET_DTR_RTS:
info = usb_get_serial_port_data(port);
memcpy(&info->mcr, command_info->result_buffer,
sizeof(struct whiteheat_dr_info));
break;
}
}
exit:
mutex_unlock(&command_info->mutex);
return retval;
}
static int firm_open(struct usb_serial_port *port)
{
struct whiteheat_simple open_command;
open_command.port = port->number - port->serial->minor + 1;
return firm_send_command(port, WHITEHEAT_OPEN,
(__u8 *)&open_command, sizeof(open_command));
}
static int firm_close(struct usb_serial_port *port)
{
struct whiteheat_simple close_command;
close_command.port = port->number - port->serial->minor + 1;
return firm_send_command(port, WHITEHEAT_CLOSE,
(__u8 *)&close_command, sizeof(close_command));
}
static void firm_setup_port(struct tty_struct *tty)
{
struct usb_serial_port *port = tty->driver_data;
struct whiteheat_port_settings port_settings;
unsigned int cflag = tty->termios->c_cflag;
port_settings.port = port->number + 1;
switch (cflag & CSIZE) {
case CS5: port_settings.bits = 5; break;
case CS6: port_settings.bits = 6; break;
case CS7: port_settings.bits = 7; break;
default:
case CS8: port_settings.bits = 8; break;
}
dbg("%s - data bits = %d", __func__, port_settings.bits);
if (cflag & PARENB)
if (cflag & CMSPAR)
if (cflag & PARODD)
port_settings.parity = WHITEHEAT_PAR_MARK;
else
port_settings.parity = WHITEHEAT_PAR_SPACE;
else
if (cflag & PARODD)
port_settings.parity = WHITEHEAT_PAR_ODD;
else
port_settings.parity = WHITEHEAT_PAR_EVEN;
else
port_settings.parity = WHITEHEAT_PAR_NONE;
dbg("%s - parity = %c", __func__, port_settings.parity);
if (cflag & CSTOPB)
port_settings.stop = 2;
else
port_settings.stop = 1;
dbg("%s - stop bits = %d", __func__, port_settings.stop);
if (cflag & CRTSCTS)
port_settings.hflow = (WHITEHEAT_HFLOW_CTS |
WHITEHEAT_HFLOW_RTS);
else
port_settings.hflow = WHITEHEAT_HFLOW_NONE;
dbg("%s - hardware flow control = %s %s %s %s", __func__,
(port_settings.hflow & WHITEHEAT_HFLOW_CTS) ? "CTS" : "",
(port_settings.hflow & WHITEHEAT_HFLOW_RTS) ? "RTS" : "",
(port_settings.hflow & WHITEHEAT_HFLOW_DSR) ? "DSR" : "",
(port_settings.hflow & WHITEHEAT_HFLOW_DTR) ? "DTR" : "");
if (I_IXOFF(tty))
port_settings.sflow = WHITEHEAT_SFLOW_RXTX;
else
port_settings.sflow = WHITEHEAT_SFLOW_NONE;
dbg("%s - software flow control = %c", __func__, port_settings.sflow);
port_settings.xon = START_CHAR(tty);
port_settings.xoff = STOP_CHAR(tty);
dbg("%s - XON = %2x, XOFF = %2x",
__func__, port_settings.xon, port_settings.xoff);
port_settings.baud = tty_get_baud_rate(tty);
dbg("%s - baud rate = %d", __func__, port_settings.baud);
tty_encode_baud_rate(tty, port_settings.baud, port_settings.baud);
port_settings.lloop = 0;
firm_send_command(port, WHITEHEAT_SETUP_PORT,
(__u8 *)&port_settings, sizeof(port_settings));
}
static int firm_set_rts(struct usb_serial_port *port, __u8 onoff)
{
struct whiteheat_set_rdb rts_command;
rts_command.port = port->number - port->serial->minor + 1;
rts_command.state = onoff;
return firm_send_command(port, WHITEHEAT_SET_RTS,
(__u8 *)&rts_command, sizeof(rts_command));
}
static int firm_set_dtr(struct usb_serial_port *port, __u8 onoff)
{
struct whiteheat_set_rdb dtr_command;
dtr_command.port = port->number - port->serial->minor + 1;
dtr_command.state = onoff;
return firm_send_command(port, WHITEHEAT_SET_DTR,
(__u8 *)&dtr_command, sizeof(dtr_command));
}
static int firm_set_break(struct usb_serial_port *port, __u8 onoff)
{
struct whiteheat_set_rdb break_command;
break_command.port = port->number - port->serial->minor + 1;
break_command.state = onoff;
return firm_send_command(port, WHITEHEAT_SET_BREAK,
(__u8 *)&break_command, sizeof(break_command));
}
static int firm_purge(struct usb_serial_port *port, __u8 rxtx)
{
struct whiteheat_purge purge_command;
purge_command.port = port->number - port->serial->minor + 1;
purge_command.what = rxtx;
return firm_send_command(port, WHITEHEAT_PURGE,
(__u8 *)&purge_command, sizeof(purge_command));
}
static int firm_get_dtr_rts(struct usb_serial_port *port)
{
struct whiteheat_simple get_dr_command;
get_dr_command.port = port->number - port->serial->minor + 1;
return firm_send_command(port, WHITEHEAT_GET_DTR_RTS,
(__u8 *)&get_dr_command, sizeof(get_dr_command));
}
static int firm_report_tx_done(struct usb_serial_port *port)
{
struct whiteheat_simple close_command;
close_command.port = port->number - port->serial->minor + 1;
return firm_send_command(port, WHITEHEAT_REPORT_TX_DONE,
(__u8 *)&close_command, sizeof(close_command));
}
static int start_command_port(struct usb_serial *serial)
{
struct usb_serial_port *command_port;
struct whiteheat_command_private *command_info;
int retval = 0;
command_port = serial->port[COMMAND_PORT];
command_info = usb_get_serial_port_data(command_port);
mutex_lock(&command_info->mutex);
if (!command_info->port_running) {
usb_clear_halt(serial->dev, command_port->read_urb->pipe);
retval = usb_submit_urb(command_port->read_urb, GFP_KERNEL);
if (retval) {
dev_err(&serial->dev->dev,
"%s - failed submitting read urb, error %d\n",
__func__, retval);
goto exit;
}
}
command_info->port_running++;
exit:
mutex_unlock(&command_info->mutex);
return retval;
}
static void stop_command_port(struct usb_serial *serial)
{
struct usb_serial_port *command_port;
struct whiteheat_command_private *command_info;
command_port = serial->port[COMMAND_PORT];
command_info = usb_get_serial_port_data(command_port);
mutex_lock(&command_info->mutex);
command_info->port_running--;
if (!command_info->port_running)
usb_kill_urb(command_port->read_urb);
mutex_unlock(&command_info->mutex);
}
