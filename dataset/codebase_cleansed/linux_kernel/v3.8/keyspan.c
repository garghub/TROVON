static void keyspan_break_ctl(struct tty_struct *tty, int break_state)
{
struct usb_serial_port *port = tty->driver_data;
struct keyspan_port_private *p_priv;
p_priv = usb_get_serial_port_data(port);
if (break_state == -1)
p_priv->break_on = 1;
else
p_priv->break_on = 0;
keyspan_send_setup(port, 0);
}
static void keyspan_set_termios(struct tty_struct *tty,
struct usb_serial_port *port, struct ktermios *old_termios)
{
int baud_rate, device_port;
struct keyspan_port_private *p_priv;
const struct keyspan_device_details *d_details;
unsigned int cflag;
p_priv = usb_get_serial_port_data(port);
d_details = p_priv->device_details;
cflag = tty->termios.c_cflag;
device_port = port->number - port->serial->minor;
baud_rate = tty_get_baud_rate(tty);
if (d_details->calculate_baud_rate(port, baud_rate, d_details->baudclk,
NULL, NULL, NULL, device_port) == KEYSPAN_BAUD_RATE_OK) {
p_priv->baud = baud_rate;
} else
baud_rate = tty_termios_baud_rate(old_termios);
tty_encode_baud_rate(tty, baud_rate, baud_rate);
p_priv->cflag = cflag;
p_priv->flow_control = (cflag & CRTSCTS) ? flow_cts : flow_none;
tty->termios.c_cflag &= ~CMSPAR;
keyspan_send_setup(port, 0);
}
static int keyspan_tiocmget(struct tty_struct *tty)
{
struct usb_serial_port *port = tty->driver_data;
struct keyspan_port_private *p_priv = usb_get_serial_port_data(port);
unsigned int value;
value = ((p_priv->rts_state) ? TIOCM_RTS : 0) |
((p_priv->dtr_state) ? TIOCM_DTR : 0) |
((p_priv->cts_state) ? TIOCM_CTS : 0) |
((p_priv->dsr_state) ? TIOCM_DSR : 0) |
((p_priv->dcd_state) ? TIOCM_CAR : 0) |
((p_priv->ri_state) ? TIOCM_RNG : 0);
return value;
}
static int keyspan_tiocmset(struct tty_struct *tty,
unsigned int set, unsigned int clear)
{
struct usb_serial_port *port = tty->driver_data;
struct keyspan_port_private *p_priv = usb_get_serial_port_data(port);
if (set & TIOCM_RTS)
p_priv->rts_state = 1;
if (set & TIOCM_DTR)
p_priv->dtr_state = 1;
if (clear & TIOCM_RTS)
p_priv->rts_state = 0;
if (clear & TIOCM_DTR)
p_priv->dtr_state = 0;
keyspan_send_setup(port, 0);
return 0;
}
static int keyspan_write(struct tty_struct *tty,
struct usb_serial_port *port, const unsigned char *buf, int count)
{
struct keyspan_port_private *p_priv;
const struct keyspan_device_details *d_details;
int flip;
int left, todo;
struct urb *this_urb;
int err, maxDataLen, dataOffset;
p_priv = usb_get_serial_port_data(port);
d_details = p_priv->device_details;
if (d_details->msg_format == msg_usa90) {
maxDataLen = 64;
dataOffset = 0;
} else {
maxDataLen = 63;
dataOffset = 1;
}
dev_dbg(&port->dev, "%s - for port %d (%d chars), flip=%d\n",
__func__, port->number, count, p_priv->out_flip);
for (left = count; left > 0; left -= todo) {
todo = left;
if (todo > maxDataLen)
todo = maxDataLen;
flip = p_priv->out_flip;
this_urb = p_priv->out_urbs[flip];
if (this_urb == NULL) {
dev_dbg(&port->dev, "%s - no output urb :(\n", __func__);
return count;
}
dev_dbg(&port->dev, "%s - endpoint %d flip %d\n",
__func__, usb_pipeendpoint(this_urb->pipe), flip);
if (this_urb->status == -EINPROGRESS) {
if (time_before(jiffies,
p_priv->tx_start_time[flip] + 10 * HZ))
break;
usb_unlink_urb(this_urb);
break;
}
((char *)this_urb->transfer_buffer)[0] = 0;
memcpy(this_urb->transfer_buffer + dataOffset, buf, todo);
buf += todo;
this_urb->transfer_buffer_length = todo + dataOffset;
err = usb_submit_urb(this_urb, GFP_ATOMIC);
if (err != 0)
dev_dbg(&port->dev, "usb_submit_urb(write bulk) failed (%d)\n", err);
p_priv->tx_start_time[flip] = jiffies;
p_priv->out_flip = (flip + 1) & d_details->outdat_endp_flip;
}
return count - left;
}
static void usa26_indat_callback(struct urb *urb)
{
int i, err;
int endpoint;
struct usb_serial_port *port;
struct tty_struct *tty;
unsigned char *data = urb->transfer_buffer;
int status = urb->status;
endpoint = usb_pipeendpoint(urb->pipe);
if (status) {
dev_dbg(&urb->dev->dev,"%s - nonzero status: %x on endpoint %d.\n",
__func__, status, endpoint);
return;
}
port = urb->context;
tty = tty_port_tty_get(&port->port);
if (tty && urb->actual_length) {
if ((data[0] & 0x80) == 0) {
if (data[0] & RXERROR_OVERRUN)
err = TTY_OVERRUN;
else
err = 0;
for (i = 1; i < urb->actual_length ; ++i)
tty_insert_flip_char(tty, data[i], err);
} else {
dev_dbg(&port->dev, "%s - RX error!!!!\n", __func__);
for (i = 0; i + 1 < urb->actual_length; i += 2) {
int stat = data[i], flag = 0;
if (stat & RXERROR_OVERRUN)
flag |= TTY_OVERRUN;
if (stat & RXERROR_FRAMING)
flag |= TTY_FRAME;
if (stat & RXERROR_PARITY)
flag |= TTY_PARITY;
tty_insert_flip_char(tty, data[i+1], flag);
}
}
tty_flip_buffer_push(tty);
}
tty_kref_put(tty);
err = usb_submit_urb(urb, GFP_ATOMIC);
if (err != 0)
dev_dbg(&port->dev, "%s - resubmit read urb failed. (%d)\n", __func__, err);
}
static void usa2x_outdat_callback(struct urb *urb)
{
struct usb_serial_port *port;
struct keyspan_port_private *p_priv;
port = urb->context;
p_priv = usb_get_serial_port_data(port);
dev_dbg(&port->dev, "%s - urb %d\n", __func__, urb == p_priv->out_urbs[1]);
usb_serial_port_softint(port);
}
static void usa26_inack_callback(struct urb *urb)
{
}
static void usa26_outcont_callback(struct urb *urb)
{
struct usb_serial_port *port;
struct keyspan_port_private *p_priv;
port = urb->context;
p_priv = usb_get_serial_port_data(port);
if (p_priv->resend_cont) {
dev_dbg(&port->dev, "%s - sending setup\n", __func__);
keyspan_usa26_send_setup(port->serial, port,
p_priv->resend_cont - 1);
}
}
static void usa26_instat_callback(struct urb *urb)
{
unsigned char *data = urb->transfer_buffer;
struct keyspan_usa26_portStatusMessage *msg;
struct usb_serial *serial;
struct usb_serial_port *port;
struct keyspan_port_private *p_priv;
struct tty_struct *tty;
int old_dcd_state, err;
int status = urb->status;
serial = urb->context;
if (status) {
dev_dbg(&urb->dev->dev, "%s - nonzero status: %x\n", __func__, status);
return;
}
if (urb->actual_length != 9) {
dev_dbg(&urb->dev->dev, "%s - %d byte report??\n", __func__, urb->actual_length);
goto exit;
}
msg = (struct keyspan_usa26_portStatusMessage *)data;
#if 0
dev_dbg(&urb->dev->dev,
"%s - port status: port %d cts %d dcd %d dsr %d ri %d toff %d txoff %d rxen %d cr %d",
__func__, msg->port, msg->hskia_cts, msg->gpia_dcd, msg->dsr,
msg->ri, msg->_txOff, msg->_txXoff, msg->rxEnabled,
msg->controlResponse);
#endif
if (msg->port >= serial->num_ports) {
dev_dbg(&urb->dev->dev, "%s - Unexpected port number %d\n", __func__, msg->port);
goto exit;
}
port = serial->port[msg->port];
p_priv = usb_get_serial_port_data(port);
old_dcd_state = p_priv->dcd_state;
p_priv->cts_state = ((msg->hskia_cts) ? 1 : 0);
p_priv->dsr_state = ((msg->dsr) ? 1 : 0);
p_priv->dcd_state = ((msg->gpia_dcd) ? 1 : 0);
p_priv->ri_state = ((msg->ri) ? 1 : 0);
if (old_dcd_state != p_priv->dcd_state) {
tty = tty_port_tty_get(&port->port);
if (tty && !C_CLOCAL(tty))
tty_hangup(tty);
tty_kref_put(tty);
}
err = usb_submit_urb(urb, GFP_ATOMIC);
if (err != 0)
dev_dbg(&port->dev, "%s - resubmit read urb failed. (%d)\n", __func__, err);
exit: ;
}
static void usa26_glocont_callback(struct urb *urb)
{
}
static void usa28_indat_callback(struct urb *urb)
{
int err;
struct usb_serial_port *port;
struct tty_struct *tty;
unsigned char *data;
struct keyspan_port_private *p_priv;
int status = urb->status;
port = urb->context;
p_priv = usb_get_serial_port_data(port);
data = urb->transfer_buffer;
if (urb != p_priv->in_urbs[p_priv->in_flip])
return;
do {
if (status) {
dev_dbg(&urb->dev->dev, "%s - nonzero status: %x on endpoint %d.\n",
__func__, status, usb_pipeendpoint(urb->pipe));
return;
}
port = urb->context;
p_priv = usb_get_serial_port_data(port);
data = urb->transfer_buffer;
tty = tty_port_tty_get(&port->port);
if (tty && urb->actual_length) {
tty_insert_flip_string(tty, data, urb->actual_length);
tty_flip_buffer_push(tty);
}
tty_kref_put(tty);
err = usb_submit_urb(urb, GFP_ATOMIC);
if (err != 0)
dev_dbg(&port->dev, "%s - resubmit read urb failed. (%d)\n",
__func__, err);
p_priv->in_flip ^= 1;
urb = p_priv->in_urbs[p_priv->in_flip];
} while (urb->status != -EINPROGRESS);
}
static void usa28_inack_callback(struct urb *urb)
{
}
static void usa28_outcont_callback(struct urb *urb)
{
struct usb_serial_port *port;
struct keyspan_port_private *p_priv;
port = urb->context;
p_priv = usb_get_serial_port_data(port);
if (p_priv->resend_cont) {
dev_dbg(&port->dev, "%s - sending setup\n", __func__);
keyspan_usa28_send_setup(port->serial, port,
p_priv->resend_cont - 1);
}
}
static void usa28_instat_callback(struct urb *urb)
{
int err;
unsigned char *data = urb->transfer_buffer;
struct keyspan_usa28_portStatusMessage *msg;
struct usb_serial *serial;
struct usb_serial_port *port;
struct keyspan_port_private *p_priv;
struct tty_struct *tty;
int old_dcd_state;
int status = urb->status;
serial = urb->context;
if (status) {
dev_dbg(&urb->dev->dev, "%s - nonzero status: %x\n", __func__, status);
return;
}
if (urb->actual_length != sizeof(struct keyspan_usa28_portStatusMessage)) {
dev_dbg(&urb->dev->dev, "%s - bad length %d\n", __func__, urb->actual_length);
goto exit;
}
msg = (struct keyspan_usa28_portStatusMessage *)data;
if (msg->port >= serial->num_ports) {
dev_dbg(&urb->dev->dev, "%s - Unexpected port number %d\n", __func__, msg->port);
goto exit;
}
port = serial->port[msg->port];
p_priv = usb_get_serial_port_data(port);
old_dcd_state = p_priv->dcd_state;
p_priv->cts_state = ((msg->cts) ? 1 : 0);
p_priv->dsr_state = ((msg->dsr) ? 1 : 0);
p_priv->dcd_state = ((msg->dcd) ? 1 : 0);
p_priv->ri_state = ((msg->ri) ? 1 : 0);
if (old_dcd_state != p_priv->dcd_state && old_dcd_state) {
tty = tty_port_tty_get(&port->port);
if (tty && !C_CLOCAL(tty))
tty_hangup(tty);
tty_kref_put(tty);
}
err = usb_submit_urb(urb, GFP_ATOMIC);
if (err != 0)
dev_dbg(&port->dev, "%s - resubmit read urb failed. (%d)\n", __func__, err);
exit: ;
}
static void usa28_glocont_callback(struct urb *urb)
{
}
static void usa49_glocont_callback(struct urb *urb)
{
struct usb_serial *serial;
struct usb_serial_port *port;
struct keyspan_port_private *p_priv;
int i;
serial = urb->context;
for (i = 0; i < serial->num_ports; ++i) {
port = serial->port[i];
p_priv = usb_get_serial_port_data(port);
if (p_priv->resend_cont) {
dev_dbg(&port->dev, "%s - sending setup\n", __func__);
keyspan_usa49_send_setup(serial, port,
p_priv->resend_cont - 1);
break;
}
}
}
static void usa49_instat_callback(struct urb *urb)
{
int err;
unsigned char *data = urb->transfer_buffer;
struct keyspan_usa49_portStatusMessage *msg;
struct usb_serial *serial;
struct usb_serial_port *port;
struct keyspan_port_private *p_priv;
int old_dcd_state;
int status = urb->status;
serial = urb->context;
if (status) {
dev_dbg(&urb->dev->dev, "%s - nonzero status: %x\n", __func__, status);
return;
}
if (urb->actual_length !=
sizeof(struct keyspan_usa49_portStatusMessage)) {
dev_dbg(&urb->dev->dev, "%s - bad length %d\n", __func__, urb->actual_length);
goto exit;
}
msg = (struct keyspan_usa49_portStatusMessage *)data;
if (msg->portNumber >= serial->num_ports) {
dev_dbg(&urb->dev->dev, "%s - Unexpected port number %d\n",
__func__, msg->portNumber);
goto exit;
}
port = serial->port[msg->portNumber];
p_priv = usb_get_serial_port_data(port);
old_dcd_state = p_priv->dcd_state;
p_priv->cts_state = ((msg->cts) ? 1 : 0);
p_priv->dsr_state = ((msg->dsr) ? 1 : 0);
p_priv->dcd_state = ((msg->dcd) ? 1 : 0);
p_priv->ri_state = ((msg->ri) ? 1 : 0);
if (old_dcd_state != p_priv->dcd_state && old_dcd_state) {
struct tty_struct *tty = tty_port_tty_get(&port->port);
if (tty && !C_CLOCAL(tty))
tty_hangup(tty);
tty_kref_put(tty);
}
err = usb_submit_urb(urb, GFP_ATOMIC);
if (err != 0)
dev_dbg(&port->dev, "%s - resubmit read urb failed. (%d)\n", __func__, err);
exit: ;
}
static void usa49_inack_callback(struct urb *urb)
{
}
static void usa49_indat_callback(struct urb *urb)
{
int i, err;
int endpoint;
struct usb_serial_port *port;
struct tty_struct *tty;
unsigned char *data = urb->transfer_buffer;
int status = urb->status;
endpoint = usb_pipeendpoint(urb->pipe);
if (status) {
dev_dbg(&urb->dev->dev, "%s - nonzero status: %x on endpoint %d.\n",
__func__, status, endpoint);
return;
}
port = urb->context;
tty = tty_port_tty_get(&port->port);
if (tty && urb->actual_length) {
if ((data[0] & 0x80) == 0) {
tty_insert_flip_string(tty, data + 1,
urb->actual_length - 1);
} else {
for (i = 0; i + 1 < urb->actual_length; i += 2) {
int stat = data[i], flag = 0;
if (stat & RXERROR_OVERRUN)
flag |= TTY_OVERRUN;
if (stat & RXERROR_FRAMING)
flag |= TTY_FRAME;
if (stat & RXERROR_PARITY)
flag |= TTY_PARITY;
tty_insert_flip_char(tty, data[i+1], flag);
}
}
tty_flip_buffer_push(tty);
}
tty_kref_put(tty);
err = usb_submit_urb(urb, GFP_ATOMIC);
if (err != 0)
dev_dbg(&port->dev, "%s - resubmit read urb failed. (%d)\n", __func__, err);
}
static void usa49wg_indat_callback(struct urb *urb)
{
int i, len, x, err;
struct usb_serial *serial;
struct usb_serial_port *port;
struct tty_struct *tty;
unsigned char *data = urb->transfer_buffer;
int status = urb->status;
serial = urb->context;
if (status) {
dev_dbg(&urb->dev->dev, "%s - nonzero status: %x\n", __func__, status);
return;
}
i = 0;
len = 0;
if (urb->actual_length) {
while (i < urb->actual_length) {
if (data[i] >= serial->num_ports) {
dev_dbg(&urb->dev->dev, "%s - Unexpected port number %d\n",
__func__, data[i]);
return;
}
port = serial->port[data[i++]];
tty = tty_port_tty_get(&port->port);
len = data[i++];
if ((data[i] & 0x80) == 0) {
i++;
for (x = 1; x < len ; ++x)
tty_insert_flip_char(tty, data[i++], 0);
} else {
for (x = 0; x + 1 < len; x += 2) {
int stat = data[i], flag = 0;
if (stat & RXERROR_OVERRUN)
flag |= TTY_OVERRUN;
if (stat & RXERROR_FRAMING)
flag |= TTY_FRAME;
if (stat & RXERROR_PARITY)
flag |= TTY_PARITY;
tty_insert_flip_char(tty,
data[i+1], flag);
i += 2;
}
}
tty_flip_buffer_push(tty);
tty_kref_put(tty);
}
}
err = usb_submit_urb(urb, GFP_ATOMIC);
if (err != 0)
dev_dbg(&urb->dev->dev, "%s - resubmit read urb failed. (%d)\n", __func__, err);
}
static void usa49_outcont_callback(struct urb *urb)
{
}
static void usa90_indat_callback(struct urb *urb)
{
int i, err;
int endpoint;
struct usb_serial_port *port;
struct keyspan_port_private *p_priv;
struct tty_struct *tty;
unsigned char *data = urb->transfer_buffer;
int status = urb->status;
endpoint = usb_pipeendpoint(urb->pipe);
if (status) {
dev_dbg(&urb->dev->dev, "%s - nonzero status: %x on endpoint %d.\n",
__func__, status, endpoint);
return;
}
port = urb->context;
p_priv = usb_get_serial_port_data(port);
if (urb->actual_length) {
tty = tty_port_tty_get(&port->port);
if (p_priv->baud > 57600)
tty_insert_flip_string(tty, data, urb->actual_length);
else {
if ((data[0] & 0x80) == 0) {
if (data[0] & RXERROR_OVERRUN)
err = TTY_OVERRUN;
else
err = 0;
for (i = 1; i < urb->actual_length ; ++i)
tty_insert_flip_char(tty, data[i],
err);
} else {
dev_dbg(&port->dev, "%s - RX error!!!!\n", __func__);
for (i = 0; i + 1 < urb->actual_length; i += 2) {
int stat = data[i], flag = 0;
if (stat & RXERROR_OVERRUN)
flag |= TTY_OVERRUN;
if (stat & RXERROR_FRAMING)
flag |= TTY_FRAME;
if (stat & RXERROR_PARITY)
flag |= TTY_PARITY;
tty_insert_flip_char(tty, data[i+1],
flag);
}
}
}
tty_flip_buffer_push(tty);
tty_kref_put(tty);
}
err = usb_submit_urb(urb, GFP_ATOMIC);
if (err != 0)
dev_dbg(&port->dev, "%s - resubmit read urb failed. (%d)\n", __func__, err);
}
static void usa90_instat_callback(struct urb *urb)
{
unsigned char *data = urb->transfer_buffer;
struct keyspan_usa90_portStatusMessage *msg;
struct usb_serial *serial;
struct usb_serial_port *port;
struct keyspan_port_private *p_priv;
struct tty_struct *tty;
int old_dcd_state, err;
int status = urb->status;
serial = urb->context;
if (status) {
dev_dbg(&urb->dev->dev, "%s - nonzero status: %x\n", __func__, status);
return;
}
if (urb->actual_length < 14) {
dev_dbg(&urb->dev->dev, "%s - %d byte report??\n", __func__, urb->actual_length);
goto exit;
}
msg = (struct keyspan_usa90_portStatusMessage *)data;
port = serial->port[0];
p_priv = usb_get_serial_port_data(port);
old_dcd_state = p_priv->dcd_state;
p_priv->cts_state = ((msg->cts) ? 1 : 0);
p_priv->dsr_state = ((msg->dsr) ? 1 : 0);
p_priv->dcd_state = ((msg->dcd) ? 1 : 0);
p_priv->ri_state = ((msg->ri) ? 1 : 0);
if (old_dcd_state != p_priv->dcd_state && old_dcd_state) {
tty = tty_port_tty_get(&port->port);
if (tty && !C_CLOCAL(tty))
tty_hangup(tty);
tty_kref_put(tty);
}
err = usb_submit_urb(urb, GFP_ATOMIC);
if (err != 0)
dev_dbg(&port->dev, "%s - resubmit read urb failed. (%d)\n", __func__, err);
exit:
;
}
static void usa90_outcont_callback(struct urb *urb)
{
struct usb_serial_port *port;
struct keyspan_port_private *p_priv;
port = urb->context;
p_priv = usb_get_serial_port_data(port);
if (p_priv->resend_cont) {
dev_dbg(&urb->dev->dev, "%s - sending setup\n", __func__);
keyspan_usa90_send_setup(port->serial, port,
p_priv->resend_cont - 1);
}
}
static void usa67_instat_callback(struct urb *urb)
{
int err;
unsigned char *data = urb->transfer_buffer;
struct keyspan_usa67_portStatusMessage *msg;
struct usb_serial *serial;
struct usb_serial_port *port;
struct keyspan_port_private *p_priv;
int old_dcd_state;
int status = urb->status;
serial = urb->context;
if (status) {
dev_dbg(&urb->dev->dev, "%s - nonzero status: %x\n", __func__, status);
return;
}
if (urb->actual_length !=
sizeof(struct keyspan_usa67_portStatusMessage)) {
dev_dbg(&urb->dev->dev, "%s - bad length %d\n", __func__, urb->actual_length);
return;
}
msg = (struct keyspan_usa67_portStatusMessage *)data;
if (msg->port >= serial->num_ports) {
dev_dbg(&urb->dev->dev, "%s - Unexpected port number %d\n", __func__, msg->port);
return;
}
port = serial->port[msg->port];
p_priv = usb_get_serial_port_data(port);
old_dcd_state = p_priv->dcd_state;
p_priv->cts_state = ((msg->hskia_cts) ? 1 : 0);
p_priv->dcd_state = ((msg->gpia_dcd) ? 1 : 0);
if (old_dcd_state != p_priv->dcd_state && old_dcd_state) {
struct tty_struct *tty = tty_port_tty_get(&port->port);
if (tty && !C_CLOCAL(tty))
tty_hangup(tty);
tty_kref_put(tty);
}
err = usb_submit_urb(urb, GFP_ATOMIC);
if (err != 0)
dev_dbg(&port->dev, "%s - resubmit read urb failed. (%d)\n", __func__, err);
}
static void usa67_glocont_callback(struct urb *urb)
{
struct usb_serial *serial;
struct usb_serial_port *port;
struct keyspan_port_private *p_priv;
int i;
serial = urb->context;
for (i = 0; i < serial->num_ports; ++i) {
port = serial->port[i];
p_priv = usb_get_serial_port_data(port);
if (p_priv->resend_cont) {
dev_dbg(&port->dev, "%s - sending setup\n", __func__);
keyspan_usa67_send_setup(serial, port,
p_priv->resend_cont - 1);
break;
}
}
}
static int keyspan_write_room(struct tty_struct *tty)
{
struct usb_serial_port *port = tty->driver_data;
struct keyspan_port_private *p_priv;
const struct keyspan_device_details *d_details;
int flip;
int data_len;
struct urb *this_urb;
p_priv = usb_get_serial_port_data(port);
d_details = p_priv->device_details;
if (d_details->msg_format == msg_usa90)
data_len = 64;
else
data_len = 63;
flip = p_priv->out_flip;
this_urb = p_priv->out_urbs[flip];
if (this_urb != NULL) {
if (this_urb->status != -EINPROGRESS)
return data_len;
flip = (flip + 1) & d_details->outdat_endp_flip;
this_urb = p_priv->out_urbs[flip];
if (this_urb != NULL) {
if (this_urb->status != -EINPROGRESS)
return data_len;
}
}
return 0;
}
static int keyspan_open(struct tty_struct *tty, struct usb_serial_port *port)
{
struct keyspan_port_private *p_priv;
const struct keyspan_device_details *d_details;
int i, err;
int baud_rate, device_port;
struct urb *urb;
unsigned int cflag = 0;
p_priv = usb_get_serial_port_data(port);
d_details = p_priv->device_details;
p_priv->rts_state = 1;
p_priv->dtr_state = 1;
p_priv->baud = 9600;
p_priv->old_baud = 0;
p_priv->old_cflag = 0;
p_priv->out_flip = 0;
p_priv->in_flip = 0;
for (i = 0; i < 2; i++) {
urb = p_priv->in_urbs[i];
if (urb == NULL)
continue;
usb_clear_halt(urb->dev, urb->pipe);
err = usb_submit_urb(urb, GFP_KERNEL);
if (err != 0)
dev_dbg(&port->dev, "%s - submit urb %d failed (%d)\n", __func__, i, err);
}
for (i = 0; i < 2; i++) {
urb = p_priv->out_urbs[i];
if (urb == NULL)
continue;
}
device_port = port->number - port->serial->minor;
if (tty) {
cflag = tty->termios.c_cflag;
baud_rate = tty_get_baud_rate(tty);
if (baud_rate >= 0
&& d_details->calculate_baud_rate(port, baud_rate, d_details->baudclk,
NULL, NULL, NULL, device_port) == KEYSPAN_BAUD_RATE_OK) {
p_priv->baud = baud_rate;
}
}
p_priv->cflag = cflag;
p_priv->flow_control = (cflag & CRTSCTS) ? flow_cts : flow_none;
keyspan_send_setup(port, 1);
return 0;
}
static inline void stop_urb(struct urb *urb)
{
if (urb && urb->status == -EINPROGRESS)
usb_kill_urb(urb);
}
static void keyspan_dtr_rts(struct usb_serial_port *port, int on)
{
struct keyspan_port_private *p_priv = usb_get_serial_port_data(port);
p_priv->rts_state = on;
p_priv->dtr_state = on;
keyspan_send_setup(port, 0);
}
static void keyspan_close(struct usb_serial_port *port)
{
int i;
struct usb_serial *serial = port->serial;
struct keyspan_port_private *p_priv;
p_priv = usb_get_serial_port_data(port);
p_priv->rts_state = 0;
p_priv->dtr_state = 0;
if (serial->dev) {
keyspan_send_setup(port, 2);
mdelay(100);
}
p_priv->out_flip = 0;
p_priv->in_flip = 0;
if (serial->dev) {
stop_urb(p_priv->inack_urb);
for (i = 0; i < 2; i++) {
stop_urb(p_priv->in_urbs[i]);
stop_urb(p_priv->out_urbs[i]);
}
}
}
static int keyspan_fake_startup(struct usb_serial *serial)
{
char *fw_name;
dev_dbg(&serial->dev->dev, "Keyspan startup version %04x product %04x\n",
le16_to_cpu(serial->dev->descriptor.bcdDevice),
le16_to_cpu(serial->dev->descriptor.idProduct));
if ((le16_to_cpu(serial->dev->descriptor.bcdDevice) & 0x8000)
!= 0x8000) {
dev_dbg(&serial->dev->dev, "Firmware already loaded. Quitting.\n");
return 1;
}
switch (le16_to_cpu(serial->dev->descriptor.idProduct)) {
case keyspan_usa28_pre_product_id:
fw_name = "keyspan/usa28.fw";
break;
case keyspan_usa28x_pre_product_id:
fw_name = "keyspan/usa28x.fw";
break;
case keyspan_usa28xa_pre_product_id:
fw_name = "keyspan/usa28xa.fw";
break;
case keyspan_usa28xb_pre_product_id:
fw_name = "keyspan/usa28xb.fw";
break;
case keyspan_usa19_pre_product_id:
fw_name = "keyspan/usa19.fw";
break;
case keyspan_usa19qi_pre_product_id:
fw_name = "keyspan/usa19qi.fw";
break;
case keyspan_mpr_pre_product_id:
fw_name = "keyspan/mpr.fw";
break;
case keyspan_usa19qw_pre_product_id:
fw_name = "keyspan/usa19qw.fw";
break;
case keyspan_usa18x_pre_product_id:
fw_name = "keyspan/usa18x.fw";
break;
case keyspan_usa19w_pre_product_id:
fw_name = "keyspan/usa19w.fw";
break;
case keyspan_usa49w_pre_product_id:
fw_name = "keyspan/usa49w.fw";
break;
case keyspan_usa49wlc_pre_product_id:
fw_name = "keyspan/usa49wlc.fw";
break;
default:
dev_err(&serial->dev->dev, "Unknown product ID (%04x)\n",
le16_to_cpu(serial->dev->descriptor.idProduct));
return 1;
}
dev_dbg(&serial->dev->dev, "Uploading Keyspan %s firmware.\n", fw_name);
if (ezusb_fx1_ihex_firmware_download(serial->dev, fw_name) < 0) {
dev_err(&serial->dev->dev, "failed to load firmware \"%s\"\n",
fw_name);
return -ENOENT;
}
return 1;
}
static struct usb_endpoint_descriptor const *find_ep(struct usb_serial const *serial,
int endpoint)
{
struct usb_host_interface *iface_desc;
struct usb_endpoint_descriptor *ep;
int i;
iface_desc = serial->interface->cur_altsetting;
for (i = 0; i < iface_desc->desc.bNumEndpoints; ++i) {
ep = &iface_desc->endpoint[i].desc;
if (ep->bEndpointAddress == endpoint)
return ep;
}
dev_warn(&serial->interface->dev, "found no endpoint descriptor for "
"endpoint %x\n", endpoint);
return NULL;
}
static struct urb *keyspan_setup_urb(struct usb_serial *serial, int endpoint,
int dir, void *ctx, char *buf, int len,
void (*callback)(struct urb *))
{
struct urb *urb;
struct usb_endpoint_descriptor const *ep_desc;
char const *ep_type_name;
if (endpoint == -1)
return NULL;
dev_dbg(&serial->interface->dev, "%s - alloc for endpoint %d.\n", __func__, endpoint);
urb = usb_alloc_urb(0, GFP_KERNEL);
if (urb == NULL) {
dev_dbg(&serial->interface->dev, "%s - alloc for endpoint %d failed.\n", __func__, endpoint);
return NULL;
}
if (endpoint == 0) {
return urb;
}
ep_desc = find_ep(serial, endpoint);
if (!ep_desc) {
return urb;
}
if (usb_endpoint_xfer_int(ep_desc)) {
ep_type_name = "INT";
usb_fill_int_urb(urb, serial->dev,
usb_sndintpipe(serial->dev, endpoint) | dir,
buf, len, callback, ctx,
ep_desc->bInterval);
} else if (usb_endpoint_xfer_bulk(ep_desc)) {
ep_type_name = "BULK";
usb_fill_bulk_urb(urb, serial->dev,
usb_sndbulkpipe(serial->dev, endpoint) | dir,
buf, len, callback, ctx);
} else {
dev_warn(&serial->interface->dev,
"unsupported endpoint type %x\n",
usb_endpoint_type(ep_desc));
usb_free_urb(urb);
return NULL;
}
dev_dbg(&serial->interface->dev, "%s - using urb %p for %s endpoint %x\n",
__func__, urb, ep_type_name, endpoint);
return urb;
}
static void keyspan_setup_urbs(struct usb_serial *serial)
{
struct keyspan_serial_private *s_priv;
const struct keyspan_device_details *d_details;
struct callbacks *cback;
s_priv = usb_get_serial_data(serial);
d_details = s_priv->device_details;
cback = &keyspan_callbacks[d_details->msg_format];
s_priv->instat_urb = keyspan_setup_urb
(serial, d_details->instat_endpoint, USB_DIR_IN,
serial, s_priv->instat_buf, INSTAT_BUFLEN,
cback->instat_callback);
s_priv->indat_urb = keyspan_setup_urb
(serial, d_details->indat_endpoint, USB_DIR_IN,
serial, s_priv->indat_buf, INDAT49W_BUFLEN,
usa49wg_indat_callback);
s_priv->glocont_urb = keyspan_setup_urb
(serial, d_details->glocont_endpoint, USB_DIR_OUT,
serial, s_priv->glocont_buf, GLOCONT_BUFLEN,
cback->glocont_callback);
}
static int keyspan_usa19_calc_baud(struct usb_serial_port *port,
u32 baud_rate, u32 baudclk, u8 *rate_hi,
u8 *rate_low, u8 *prescaler, int portnum)
{
u32 b16,
div,
cnt;
dev_dbg(&port->dev, "%s - %d.\n", __func__, baud_rate);
b16 = baud_rate * 16L;
if (b16 == 0)
return KEYSPAN_INVALID_BAUD_RATE;
if (baud_rate > 57600)
return KEYSPAN_INVALID_BAUD_RATE;
div = baudclk / b16;
if (div == 0)
return KEYSPAN_INVALID_BAUD_RATE;
else
cnt = 0 - div;
if (div > 0xffff)
return KEYSPAN_INVALID_BAUD_RATE;
if (rate_low)
*rate_low = (u8) (cnt & 0xff);
if (rate_hi)
*rate_hi = (u8) ((cnt >> 8) & 0xff);
if (rate_low && rate_hi)
dev_dbg(&port->dev, "%s - %d %02x %02x.\n",
__func__, baud_rate, *rate_hi, *rate_low);
return KEYSPAN_BAUD_RATE_OK;
}
static int keyspan_usa19hs_calc_baud(struct usb_serial_port *port,
u32 baud_rate, u32 baudclk, u8 *rate_hi,
u8 *rate_low, u8 *prescaler, int portnum)
{
u32 b16,
div;
dev_dbg(&port->dev, "%s - %d.\n", __func__, baud_rate);
b16 = baud_rate * 16L;
if (b16 == 0)
return KEYSPAN_INVALID_BAUD_RATE;
div = baudclk / b16;
if (div == 0)
return KEYSPAN_INVALID_BAUD_RATE;
if (div > 0xffff)
return KEYSPAN_INVALID_BAUD_RATE;
if (rate_low)
*rate_low = (u8) (div & 0xff);
if (rate_hi)
*rate_hi = (u8) ((div >> 8) & 0xff);
if (rate_low && rate_hi)
dev_dbg(&port->dev, "%s - %d %02x %02x.\n",
__func__, baud_rate, *rate_hi, *rate_low);
return KEYSPAN_BAUD_RATE_OK;
}
static int keyspan_usa19w_calc_baud(struct usb_serial_port *port,
u32 baud_rate, u32 baudclk, u8 *rate_hi,
u8 *rate_low, u8 *prescaler, int portnum)
{
u32 b16,
clk,
div,
res,
diff,
smallest_diff;
u8 best_prescaler;
int i;
dev_dbg(&port->dev, "%s - %d.\n", __func__, baud_rate);
b16 = baud_rate * 16L;
if (b16 == 0)
return KEYSPAN_INVALID_BAUD_RATE;
smallest_diff = 0xffffffff;
best_prescaler = 0;
for (i = 8; i <= 0xff; ++i) {
clk = (baudclk * 8) / (u32) i;
div = clk / b16;
if (div == 0)
continue;
res = clk / div;
diff = (res > b16) ? (res-b16) : (b16-res);
if (diff < smallest_diff) {
best_prescaler = i;
smallest_diff = diff;
}
}
if (best_prescaler == 0)
return KEYSPAN_INVALID_BAUD_RATE;
clk = (baudclk * 8) / (u32) best_prescaler;
div = clk / b16;
if (rate_low)
*rate_low = (u8) (div & 0xff);
if (rate_hi)
*rate_hi = (u8) ((div >> 8) & 0xff);
if (prescaler) {
*prescaler = best_prescaler;
}
return KEYSPAN_BAUD_RATE_OK;
}
static int keyspan_usa28_calc_baud(struct usb_serial_port *port,
u32 baud_rate, u32 baudclk, u8 *rate_hi,
u8 *rate_low, u8 *prescaler, int portnum)
{
u32 b16,
div,
cnt;
dev_dbg(&port->dev, "%s - %d.\n", __func__, baud_rate);
b16 = baud_rate * 16L;
if (b16 == 0)
return KEYSPAN_INVALID_BAUD_RATE;
div = KEYSPAN_USA28_BAUDCLK / b16;
if (div == 0)
return KEYSPAN_INVALID_BAUD_RATE;
else
cnt = 0 - div;
if (portnum == 0) {
if (div > 0xffff)
return KEYSPAN_INVALID_BAUD_RATE;
} else {
if (portnum == 1) {
if (div > 0xff)
return KEYSPAN_INVALID_BAUD_RATE;
} else
return KEYSPAN_INVALID_BAUD_RATE;
}
if (rate_low)
*rate_low = (u8) (cnt & 0xff);
if (rate_hi)
*rate_hi = (u8) ((cnt >> 8) & 0xff);
dev_dbg(&port->dev, "%s - %d OK.\n", __func__, baud_rate);
return KEYSPAN_BAUD_RATE_OK;
}
static int keyspan_usa26_send_setup(struct usb_serial *serial,
struct usb_serial_port *port,
int reset_port)
{
struct keyspan_usa26_portControlMessage msg;
struct keyspan_serial_private *s_priv;
struct keyspan_port_private *p_priv;
const struct keyspan_device_details *d_details;
int outcont_urb;
struct urb *this_urb;
int device_port, err;
dev_dbg(&port->dev, "%s reset=%d\n", __func__, reset_port);
s_priv = usb_get_serial_data(serial);
p_priv = usb_get_serial_port_data(port);
d_details = s_priv->device_details;
device_port = port->number - port->serial->minor;
outcont_urb = d_details->outcont_endpoints[port->number];
this_urb = p_priv->outcont_urb;
dev_dbg(&port->dev, "%s - endpoint %d\n", __func__, usb_pipeendpoint(this_urb->pipe));
if (this_urb == NULL) {
dev_dbg(&port->dev, "%s - oops no urb.\n", __func__);
return -1;
}
if ((reset_port + 1) > p_priv->resend_cont)
p_priv->resend_cont = reset_port + 1;
if (this_urb->status == -EINPROGRESS) {
mdelay(5);
return -1;
}
memset(&msg, 0, sizeof(struct keyspan_usa26_portControlMessage));
if (p_priv->old_baud != p_priv->baud) {
p_priv->old_baud = p_priv->baud;
msg.setClocking = 0xff;
if (d_details->calculate_baud_rate(port, p_priv->baud, d_details->baudclk,
&msg.baudHi, &msg.baudLo, &msg.prescaler,
device_port) == KEYSPAN_INVALID_BAUD_RATE) {
dev_dbg(&port->dev, "%s - Invalid baud rate %d requested, using 9600.\n",
__func__, p_priv->baud);
msg.baudLo = 0;
msg.baudHi = 125;
msg.prescaler = 10;
}
msg.setPrescaler = 0xff;
}
msg.lcr = (p_priv->cflag & CSTOPB) ? STOPBITS_678_2 : STOPBITS_5678_1;
switch (p_priv->cflag & CSIZE) {
case CS5:
msg.lcr |= USA_DATABITS_5;
break;
case CS6:
msg.lcr |= USA_DATABITS_6;
break;
case CS7:
msg.lcr |= USA_DATABITS_7;
break;
case CS8:
msg.lcr |= USA_DATABITS_8;
break;
}
if (p_priv->cflag & PARENB) {
msg.lcr |= (p_priv->cflag & PARODD) ?
USA_PARITY_ODD : USA_PARITY_EVEN;
}
msg.setLcr = 0xff;
msg.ctsFlowControl = (p_priv->flow_control == flow_cts);
msg.xonFlowControl = 0;
msg.setFlowControl = 0xff;
msg.forwardingLength = 16;
msg.xonChar = 17;
msg.xoffChar = 19;
if (reset_port == 1) {
msg._txOn = 1;
msg._txOff = 0;
msg.txFlush = 0;
msg.txBreak = 0;
msg.rxOn = 1;
msg.rxOff = 0;
msg.rxFlush = 1;
msg.rxForward = 0;
msg.returnStatus = 0;
msg.resetDataToggle = 0xff;
}
else if (reset_port == 2) {
msg._txOn = 0;
msg._txOff = 1;
msg.txFlush = 0;
msg.txBreak = 0;
msg.rxOn = 0;
msg.rxOff = 1;
msg.rxFlush = 1;
msg.rxForward = 0;
msg.returnStatus = 0;
msg.resetDataToggle = 0;
}
else {
msg._txOn = (!p_priv->break_on);
msg._txOff = 0;
msg.txFlush = 0;
msg.txBreak = (p_priv->break_on);
msg.rxOn = 0;
msg.rxOff = 0;
msg.rxFlush = 0;
msg.rxForward = 0;
msg.returnStatus = 0;
msg.resetDataToggle = 0x0;
}
msg.setTxTriState_setRts = 0xff;
msg.txTriState_rts = p_priv->rts_state;
msg.setHskoa_setDtr = 0xff;
msg.hskoa_dtr = p_priv->dtr_state;
p_priv->resend_cont = 0;
memcpy(this_urb->transfer_buffer, &msg, sizeof(msg));
this_urb->transfer_buffer_length = sizeof(msg);
err = usb_submit_urb(this_urb, GFP_ATOMIC);
if (err != 0)
dev_dbg(&port->dev, "%s - usb_submit_urb(setup) failed (%d)\n", __func__, err);
#if 0
else {
dev_dbg(&port->dev, "%s - usb_submit_urb(%d) OK %d bytes (end %d)\n", __func__
outcont_urb, this_urb->transfer_buffer_length,
usb_pipeendpoint(this_urb->pipe));
}
#endif
return 0;
}
static int keyspan_usa28_send_setup(struct usb_serial *serial,
struct usb_serial_port *port,
int reset_port)
{
struct keyspan_usa28_portControlMessage msg;
struct keyspan_serial_private *s_priv;
struct keyspan_port_private *p_priv;
const struct keyspan_device_details *d_details;
struct urb *this_urb;
int device_port, err;
s_priv = usb_get_serial_data(serial);
p_priv = usb_get_serial_port_data(port);
d_details = s_priv->device_details;
device_port = port->number - port->serial->minor;
this_urb = p_priv->outcont_urb;
if (this_urb == NULL) {
dev_dbg(&port->dev, "%s - oops no urb.\n", __func__);
return -1;
}
if ((reset_port + 1) > p_priv->resend_cont)
p_priv->resend_cont = reset_port + 1;
if (this_urb->status == -EINPROGRESS) {
dev_dbg(&port->dev, "%s already writing\n", __func__);
mdelay(5);
return -1;
}
memset(&msg, 0, sizeof(struct keyspan_usa28_portControlMessage));
msg.setBaudRate = 1;
if (d_details->calculate_baud_rate(port, p_priv->baud, d_details->baudclk,
&msg.baudHi, &msg.baudLo, NULL,
device_port) == KEYSPAN_INVALID_BAUD_RATE) {
dev_dbg(&port->dev, "%s - Invalid baud rate requested %d.\n",
__func__, p_priv->baud);
msg.baudLo = 0xff;
msg.baudHi = 0xb2;
}
msg.parity = 0;
msg.ctsFlowControl = (p_priv->flow_control == flow_cts);
msg.xonFlowControl = 0;
msg.rts = p_priv->rts_state;
msg.dtr = p_priv->dtr_state;
msg.forwardingLength = 16;
msg.forwardMs = 10;
msg.breakThreshold = 45;
msg.xonChar = 17;
msg.xoffChar = 19;
if (reset_port == 1) {
msg._txOn = 1;
msg._txOff = 0;
msg.txFlush = 0;
msg.txForceXoff = 0;
msg.txBreak = 0;
msg.rxOn = 1;
msg.rxOff = 0;
msg.rxFlush = 1;
msg.rxForward = 0;
msg.returnStatus = 0;
msg.resetDataToggle = 0xff;
}
else if (reset_port == 2) {
msg._txOn = 0;
msg._txOff = 1;
msg.txFlush = 0;
msg.txForceXoff = 0;
msg.txBreak = 0;
msg.rxOn = 0;
msg.rxOff = 1;
msg.rxFlush = 1;
msg.rxForward = 0;
msg.returnStatus = 0;
msg.resetDataToggle = 0;
}
else {
msg._txOn = (!p_priv->break_on);
msg._txOff = 0;
msg.txFlush = 0;
msg.txForceXoff = 0;
msg.txBreak = (p_priv->break_on);
msg.rxOn = 0;
msg.rxOff = 0;
msg.rxFlush = 0;
msg.rxForward = 0;
msg.returnStatus = 0;
msg.resetDataToggle = 0x0;
}
p_priv->resend_cont = 0;
memcpy(this_urb->transfer_buffer, &msg, sizeof(msg));
this_urb->transfer_buffer_length = sizeof(msg);
err = usb_submit_urb(this_urb, GFP_ATOMIC);
if (err != 0)
dev_dbg(&port->dev, "%s - usb_submit_urb(setup) failed\n", __func__);
#if 0
else {
dev_dbg(&port->dev, "%s - usb_submit_urb(setup) OK %d bytes\n", __func__,
this_urb->transfer_buffer_length);
}
#endif
return 0;
}
static int keyspan_usa49_send_setup(struct usb_serial *serial,
struct usb_serial_port *port,
int reset_port)
{
struct keyspan_usa49_portControlMessage msg;
struct usb_ctrlrequest *dr = NULL;
struct keyspan_serial_private *s_priv;
struct keyspan_port_private *p_priv;
const struct keyspan_device_details *d_details;
struct urb *this_urb;
int err, device_port;
s_priv = usb_get_serial_data(serial);
p_priv = usb_get_serial_port_data(port);
d_details = s_priv->device_details;
this_urb = s_priv->glocont_urb;
device_port = port->number - port->serial->minor;
if (this_urb == NULL) {
dev_dbg(&port->dev, "%s - oops no urb for port %d.\n", __func__, port->number);
return -1;
}
dev_dbg(&port->dev, "%s - endpoint %d port %d (%d)\n",
__func__, usb_pipeendpoint(this_urb->pipe),
port->number, device_port);
if ((reset_port + 1) > p_priv->resend_cont)
p_priv->resend_cont = reset_port + 1;
if (this_urb->status == -EINPROGRESS) {
mdelay(5);
return -1;
}
memset(&msg, 0, sizeof(struct keyspan_usa49_portControlMessage));
msg.portNumber = device_port;
if (p_priv->old_baud != p_priv->baud) {
p_priv->old_baud = p_priv->baud;
msg.setClocking = 0xff;
if (d_details->calculate_baud_rate(port, p_priv->baud, d_details->baudclk,
&msg.baudHi, &msg.baudLo, &msg.prescaler,
device_port) == KEYSPAN_INVALID_BAUD_RATE) {
dev_dbg(&port->dev, "%s - Invalid baud rate %d requested, using 9600.\n",
__func__, p_priv->baud);
msg.baudLo = 0;
msg.baudHi = 125;
msg.prescaler = 10;
}
}
msg.lcr = (p_priv->cflag & CSTOPB) ? STOPBITS_678_2 : STOPBITS_5678_1;
switch (p_priv->cflag & CSIZE) {
case CS5:
msg.lcr |= USA_DATABITS_5;
break;
case CS6:
msg.lcr |= USA_DATABITS_6;
break;
case CS7:
msg.lcr |= USA_DATABITS_7;
break;
case CS8:
msg.lcr |= USA_DATABITS_8;
break;
}
if (p_priv->cflag & PARENB) {
msg.lcr |= (p_priv->cflag & PARODD) ?
USA_PARITY_ODD : USA_PARITY_EVEN;
}
msg.setLcr = 0xff;
msg.ctsFlowControl = (p_priv->flow_control == flow_cts);
msg.xonFlowControl = 0;
msg.setFlowControl = 0xff;
msg.forwardingLength = 16;
msg.xonChar = 17;
msg.xoffChar = 19;
if (reset_port == 1) {
msg._txOn = 1;
msg._txOff = 0;
msg.txFlush = 0;
msg.txBreak = 0;
msg.rxOn = 1;
msg.rxOff = 0;
msg.rxFlush = 1;
msg.rxForward = 0;
msg.returnStatus = 0;
msg.resetDataToggle = 0xff;
msg.enablePort = 1;
msg.disablePort = 0;
}
else if (reset_port == 2) {
msg._txOn = 0;
msg._txOff = 1;
msg.txFlush = 0;
msg.txBreak = 0;
msg.rxOn = 0;
msg.rxOff = 1;
msg.rxFlush = 1;
msg.rxForward = 0;
msg.returnStatus = 0;
msg.resetDataToggle = 0;
msg.enablePort = 0;
msg.disablePort = 1;
}
else {
msg._txOn = (!p_priv->break_on);
msg._txOff = 0;
msg.txFlush = 0;
msg.txBreak = (p_priv->break_on);
msg.rxOn = 0;
msg.rxOff = 0;
msg.rxFlush = 0;
msg.rxForward = 0;
msg.returnStatus = 0;
msg.resetDataToggle = 0x0;
msg.enablePort = 0;
msg.disablePort = 0;
}
msg.setRts = 0xff;
msg.rts = p_priv->rts_state;
msg.setDtr = 0xff;
msg.dtr = p_priv->dtr_state;
p_priv->resend_cont = 0;
if (d_details->product_id == keyspan_usa49wg_product_id) {
dr = (void *)(s_priv->ctrl_buf);
dr->bRequestType = USB_TYPE_VENDOR | USB_DIR_OUT;
dr->bRequest = 0xB0; ;
dr->wValue = 0;
dr->wIndex = 0;
dr->wLength = cpu_to_le16(sizeof(msg));
memcpy(s_priv->glocont_buf, &msg, sizeof(msg));
usb_fill_control_urb(this_urb, serial->dev,
usb_sndctrlpipe(serial->dev, 0),
(unsigned char *)dr, s_priv->glocont_buf,
sizeof(msg), usa49_glocont_callback, serial);
} else {
memcpy(this_urb->transfer_buffer, &msg, sizeof(msg));
this_urb->transfer_buffer_length = sizeof(msg);
}
err = usb_submit_urb(this_urb, GFP_ATOMIC);
if (err != 0)
dev_dbg(&port->dev, "%s - usb_submit_urb(setup) failed (%d)\n", __func__, err);
#if 0
else {
dev_dbg(&port->dev, "%s - usb_submit_urb(%d) OK %d bytes (end %d)\n", __func__,
outcont_urb, this_urb->transfer_buffer_length,
usb_pipeendpoint(this_urb->pipe));
}
#endif
return 0;
}
static int keyspan_usa90_send_setup(struct usb_serial *serial,
struct usb_serial_port *port,
int reset_port)
{
struct keyspan_usa90_portControlMessage msg;
struct keyspan_serial_private *s_priv;
struct keyspan_port_private *p_priv;
const struct keyspan_device_details *d_details;
struct urb *this_urb;
int err;
u8 prescaler;
s_priv = usb_get_serial_data(serial);
p_priv = usb_get_serial_port_data(port);
d_details = s_priv->device_details;
this_urb = p_priv->outcont_urb;
if (this_urb == NULL) {
dev_dbg(&port->dev, "%s - oops no urb.\n", __func__);
return -1;
}
if ((reset_port + 1) > p_priv->resend_cont)
p_priv->resend_cont = reset_port + 1;
if (this_urb->status == -EINPROGRESS) {
dev_dbg(&port->dev, "%s already writing\n", __func__);
mdelay(5);
return -1;
}
memset(&msg, 0, sizeof(struct keyspan_usa90_portControlMessage));
if (p_priv->old_baud != p_priv->baud) {
p_priv->old_baud = p_priv->baud;
msg.setClocking = 0x01;
if (d_details->calculate_baud_rate(port, p_priv->baud, d_details->baudclk,
&msg.baudHi, &msg.baudLo, &prescaler, 0) == KEYSPAN_INVALID_BAUD_RATE) {
dev_dbg(&port->dev, "%s - Invalid baud rate %d requested, using 9600.\n",
__func__, p_priv->baud);
p_priv->baud = 9600;
d_details->calculate_baud_rate(port, p_priv->baud, d_details->baudclk,
&msg.baudHi, &msg.baudLo, &prescaler, 0);
}
msg.setRxMode = 1;
msg.setTxMode = 1;
}
if (p_priv->baud > 57600) {
msg.rxMode = RXMODE_DMA;
msg.txMode = TXMODE_DMA;
} else {
msg.rxMode = RXMODE_BYHAND;
msg.txMode = TXMODE_BYHAND;
}
msg.lcr = (p_priv->cflag & CSTOPB) ? STOPBITS_678_2 : STOPBITS_5678_1;
switch (p_priv->cflag & CSIZE) {
case CS5:
msg.lcr |= USA_DATABITS_5;
break;
case CS6:
msg.lcr |= USA_DATABITS_6;
break;
case CS7:
msg.lcr |= USA_DATABITS_7;
break;
case CS8:
msg.lcr |= USA_DATABITS_8;
break;
}
if (p_priv->cflag & PARENB) {
msg.lcr |= (p_priv->cflag & PARODD) ?
USA_PARITY_ODD : USA_PARITY_EVEN;
}
if (p_priv->old_cflag != p_priv->cflag) {
p_priv->old_cflag = p_priv->cflag;
msg.setLcr = 0x01;
}
if (p_priv->flow_control == flow_cts)
msg.txFlowControl = TXFLOW_CTS;
msg.setTxFlowControl = 0x01;
msg.setRxFlowControl = 0x01;
msg.rxForwardingLength = 16;
msg.rxForwardingTimeout = 16;
msg.txAckSetting = 0;
msg.xonChar = 17;
msg.xoffChar = 19;
if (reset_port == 1) {
msg.portEnabled = 1;
msg.rxFlush = 1;
msg.txBreak = (p_priv->break_on);
}
else if (reset_port == 2)
msg.portEnabled = 0;
else {
msg.portEnabled = 1;
msg.txBreak = (p_priv->break_on);
}
msg.setRts = 0x01;
msg.rts = p_priv->rts_state;
msg.setDtr = 0x01;
msg.dtr = p_priv->dtr_state;
p_priv->resend_cont = 0;
memcpy(this_urb->transfer_buffer, &msg, sizeof(msg));
this_urb->transfer_buffer_length = sizeof(msg);
err = usb_submit_urb(this_urb, GFP_ATOMIC);
if (err != 0)
dev_dbg(&port->dev, "%s - usb_submit_urb(setup) failed (%d)\n", __func__, err);
return 0;
}
static int keyspan_usa67_send_setup(struct usb_serial *serial,
struct usb_serial_port *port,
int reset_port)
{
struct keyspan_usa67_portControlMessage msg;
struct keyspan_serial_private *s_priv;
struct keyspan_port_private *p_priv;
const struct keyspan_device_details *d_details;
struct urb *this_urb;
int err, device_port;
s_priv = usb_get_serial_data(serial);
p_priv = usb_get_serial_port_data(port);
d_details = s_priv->device_details;
this_urb = s_priv->glocont_urb;
device_port = port->number - port->serial->minor;
if (this_urb == NULL) {
dev_dbg(&port->dev, "%s - oops no urb for port %d.\n", __func__,
port->number);
return -1;
}
if ((reset_port + 1) > p_priv->resend_cont)
p_priv->resend_cont = reset_port + 1;
if (this_urb->status == -EINPROGRESS) {
mdelay(5);
return -1;
}
memset(&msg, 0, sizeof(struct keyspan_usa67_portControlMessage));
msg.port = device_port;
if (p_priv->old_baud != p_priv->baud) {
p_priv->old_baud = p_priv->baud;
msg.setClocking = 0xff;
if (d_details->calculate_baud_rate(port, p_priv->baud, d_details->baudclk,
&msg.baudHi, &msg.baudLo, &msg.prescaler,
device_port) == KEYSPAN_INVALID_BAUD_RATE) {
dev_dbg(&port->dev, "%s - Invalid baud rate %d requested, using 9600.\n",
__func__, p_priv->baud);
msg.baudLo = 0;
msg.baudHi = 125;
msg.prescaler = 10;
}
msg.setPrescaler = 0xff;
}
msg.lcr = (p_priv->cflag & CSTOPB) ? STOPBITS_678_2 : STOPBITS_5678_1;
switch (p_priv->cflag & CSIZE) {
case CS5:
msg.lcr |= USA_DATABITS_5;
break;
case CS6:
msg.lcr |= USA_DATABITS_6;
break;
case CS7:
msg.lcr |= USA_DATABITS_7;
break;
case CS8:
msg.lcr |= USA_DATABITS_8;
break;
}
if (p_priv->cflag & PARENB) {
msg.lcr |= (p_priv->cflag & PARODD) ?
USA_PARITY_ODD : USA_PARITY_EVEN;
}
msg.setLcr = 0xff;
msg.ctsFlowControl = (p_priv->flow_control == flow_cts);
msg.xonFlowControl = 0;
msg.setFlowControl = 0xff;
msg.forwardingLength = 16;
msg.xonChar = 17;
msg.xoffChar = 19;
if (reset_port == 1) {
msg._txOn = 1;
msg._txOff = 0;
msg.txFlush = 0;
msg.txBreak = 0;
msg.rxOn = 1;
msg.rxOff = 0;
msg.rxFlush = 1;
msg.rxForward = 0;
msg.returnStatus = 0;
msg.resetDataToggle = 0xff;
} else if (reset_port == 2) {
msg._txOn = 0;
msg._txOff = 1;
msg.txFlush = 0;
msg.txBreak = 0;
msg.rxOn = 0;
msg.rxOff = 1;
msg.rxFlush = 1;
msg.rxForward = 0;
msg.returnStatus = 0;
msg.resetDataToggle = 0;
} else {
msg._txOn = (!p_priv->break_on);
msg._txOff = 0;
msg.txFlush = 0;
msg.txBreak = (p_priv->break_on);
msg.rxOn = 0;
msg.rxOff = 0;
msg.rxFlush = 0;
msg.rxForward = 0;
msg.returnStatus = 0;
msg.resetDataToggle = 0x0;
}
msg.setTxTriState_setRts = 0xff;
msg.txTriState_rts = p_priv->rts_state;
msg.setHskoa_setDtr = 0xff;
msg.hskoa_dtr = p_priv->dtr_state;
p_priv->resend_cont = 0;
memcpy(this_urb->transfer_buffer, &msg, sizeof(msg));
this_urb->transfer_buffer_length = sizeof(msg);
err = usb_submit_urb(this_urb, GFP_ATOMIC);
if (err != 0)
dev_dbg(&port->dev, "%s - usb_submit_urb(setup) failed (%d)\n", __func__, err);
return 0;
}
static void keyspan_send_setup(struct usb_serial_port *port, int reset_port)
{
struct usb_serial *serial = port->serial;
struct keyspan_serial_private *s_priv;
const struct keyspan_device_details *d_details;
s_priv = usb_get_serial_data(serial);
d_details = s_priv->device_details;
switch (d_details->msg_format) {
case msg_usa26:
keyspan_usa26_send_setup(serial, port, reset_port);
break;
case msg_usa28:
keyspan_usa28_send_setup(serial, port, reset_port);
break;
case msg_usa49:
keyspan_usa49_send_setup(serial, port, reset_port);
break;
case msg_usa90:
keyspan_usa90_send_setup(serial, port, reset_port);
break;
case msg_usa67:
keyspan_usa67_send_setup(serial, port, reset_port);
break;
}
}
static int keyspan_startup(struct usb_serial *serial)
{
int i, err;
struct keyspan_serial_private *s_priv;
const struct keyspan_device_details *d_details;
for (i = 0; (d_details = keyspan_devices[i]) != NULL; ++i)
if (d_details->product_id ==
le16_to_cpu(serial->dev->descriptor.idProduct))
break;
if (d_details == NULL) {
dev_err(&serial->dev->dev, "%s - unknown product id %x\n",
__func__, le16_to_cpu(serial->dev->descriptor.idProduct));
return 1;
}
s_priv = kzalloc(sizeof(struct keyspan_serial_private), GFP_KERNEL);
if (!s_priv) {
dev_dbg(&serial->dev->dev, "%s - kmalloc for keyspan_serial_private failed.\n", __func__);
return -ENOMEM;
}
s_priv->device_details = d_details;
usb_set_serial_data(serial, s_priv);
keyspan_setup_urbs(serial);
if (s_priv->instat_urb != NULL) {
err = usb_submit_urb(s_priv->instat_urb, GFP_KERNEL);
if (err != 0)
dev_dbg(&serial->dev->dev, "%s - submit instat urb failed %d\n", __func__, err);
}
if (s_priv->indat_urb != NULL) {
err = usb_submit_urb(s_priv->indat_urb, GFP_KERNEL);
if (err != 0)
dev_dbg(&serial->dev->dev, "%s - submit indat urb failed %d\n", __func__, err);
}
return 0;
}
static void keyspan_disconnect(struct usb_serial *serial)
{
struct keyspan_serial_private *s_priv;
s_priv = usb_get_serial_data(serial);
stop_urb(s_priv->instat_urb);
stop_urb(s_priv->glocont_urb);
stop_urb(s_priv->indat_urb);
}
static void keyspan_release(struct usb_serial *serial)
{
struct keyspan_serial_private *s_priv;
s_priv = usb_get_serial_data(serial);
usb_free_urb(s_priv->instat_urb);
usb_free_urb(s_priv->indat_urb);
usb_free_urb(s_priv->glocont_urb);
kfree(s_priv);
}
static int keyspan_port_probe(struct usb_serial_port *port)
{
struct usb_serial *serial = port->serial;
struct keyspan_serial_private *s_priv;
struct keyspan_port_private *p_priv;
const struct keyspan_device_details *d_details;
struct callbacks *cback;
int endp;
int port_num;
int i;
s_priv = usb_get_serial_data(serial);
d_details = s_priv->device_details;
p_priv = kzalloc(sizeof(*p_priv), GFP_KERNEL);
if (!p_priv)
return -ENOMEM;
p_priv->device_details = d_details;
cback = &keyspan_callbacks[d_details->msg_format];
port_num = port->number - port->serial->minor;
endp = d_details->indat_endpoints[port_num];
for (i = 0; i <= d_details->indat_endp_flip; ++i, ++endp) {
p_priv->in_urbs[i] = keyspan_setup_urb(serial, endp,
USB_DIR_IN, port,
p_priv->in_buffer[i], 64,
cback->indat_callback);
}
endp = d_details->outdat_endpoints[port_num];
for (i = 0; i <= d_details->outdat_endp_flip; ++i, ++endp) {
p_priv->out_urbs[i] = keyspan_setup_urb(serial, endp,
USB_DIR_OUT, port,
p_priv->out_buffer[i], 64,
cback->outdat_callback);
}
p_priv->inack_urb = keyspan_setup_urb(serial,
d_details->inack_endpoints[port_num],
USB_DIR_IN, port,
p_priv->inack_buffer, 1,
cback->inack_callback);
p_priv->outcont_urb = keyspan_setup_urb(serial,
d_details->outcont_endpoints[port_num],
USB_DIR_OUT, port,
p_priv->outcont_buffer, 64,
cback->outcont_callback);
usb_set_serial_port_data(port, p_priv);
return 0;
}
static int keyspan_port_remove(struct usb_serial_port *port)
{
struct keyspan_port_private *p_priv;
int i;
p_priv = usb_get_serial_port_data(port);
stop_urb(p_priv->inack_urb);
stop_urb(p_priv->outcont_urb);
for (i = 0; i < 2; i++) {
stop_urb(p_priv->in_urbs[i]);
stop_urb(p_priv->out_urbs[i]);
}
usb_free_urb(p_priv->inack_urb);
usb_free_urb(p_priv->outcont_urb);
for (i = 0; i < 2; i++) {
usb_free_urb(p_priv->in_urbs[i]);
usb_free_urb(p_priv->out_urbs[i]);
}
kfree(p_priv);
return 0;
}
