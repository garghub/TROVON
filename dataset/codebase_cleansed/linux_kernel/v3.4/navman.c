static void navman_read_int_callback(struct urb *urb)
{
struct usb_serial_port *port = urb->context;
unsigned char *data = urb->transfer_buffer;
struct tty_struct *tty;
int status = urb->status;
int result;
switch (status) {
case 0:
break;
case -ECONNRESET:
case -ENOENT:
case -ESHUTDOWN:
dbg("%s - urb shutting down with status: %d",
__func__, status);
return;
default:
dbg("%s - nonzero urb status received: %d",
__func__, status);
goto exit;
}
usb_serial_debug_data(debug, &port->dev, __func__,
urb->actual_length, data);
tty = tty_port_tty_get(&port->port);
if (tty && urb->actual_length) {
tty_insert_flip_string(tty, data, urb->actual_length);
tty_flip_buffer_push(tty);
}
tty_kref_put(tty);
exit:
result = usb_submit_urb(urb, GFP_ATOMIC);
if (result)
dev_err(&urb->dev->dev,
"%s - Error %d submitting interrupt urb\n",
__func__, result);
}
static int navman_open(struct tty_struct *tty, struct usb_serial_port *port)
{
int result = 0;
dbg("%s - port %d", __func__, port->number);
if (port->interrupt_in_urb) {
dbg("%s - adding interrupt input for treo", __func__);
result = usb_submit_urb(port->interrupt_in_urb, GFP_KERNEL);
if (result)
dev_err(&port->dev,
"%s - failed submitting interrupt urb, error %d\n",
__func__, result);
}
return result;
}
static void navman_close(struct usb_serial_port *port)
{
dbg("%s - port %d", __func__, port->number);
usb_kill_urb(port->interrupt_in_urb);
}
static int navman_write(struct tty_struct *tty, struct usb_serial_port *port,
const unsigned char *buf, int count)
{
dbg("%s - port %d", __func__, port->number);
return -EOPNOTSUPP;
}
