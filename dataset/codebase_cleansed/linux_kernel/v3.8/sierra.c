static int sierra_set_power_state(struct usb_device *udev, __u16 swiState)
{
return usb_control_msg(udev, usb_sndctrlpipe(udev, 0),
SWIMS_USB_REQUEST_SetPower,
USB_TYPE_VENDOR,
swiState,
0,
NULL,
0,
USB_CTRL_SET_TIMEOUT);
}
static int sierra_vsc_set_nmea(struct usb_device *udev, __u16 enable)
{
return usb_control_msg(udev, usb_sndctrlpipe(udev, 0),
SWIMS_USB_REQUEST_SetNmea,
USB_TYPE_VENDOR,
enable,
0x0000,
NULL,
0,
USB_CTRL_SET_TIMEOUT);
}
static int sierra_calc_num_ports(struct usb_serial *serial)
{
int num_ports = 0;
u8 ifnum, numendpoints;
ifnum = serial->interface->cur_altsetting->desc.bInterfaceNumber;
numendpoints = serial->interface->cur_altsetting->desc.bNumEndpoints;
if (ifnum == 0x99)
num_ports = 0;
else if (numendpoints <= 3)
num_ports = 1;
else
num_ports = (numendpoints-1)/2;
return num_ports;
}
static int is_blacklisted(const u8 ifnum,
const struct sierra_iface_info *blacklist)
{
const u8 *info;
int i;
if (blacklist) {
info = blacklist->ifaceinfo;
for (i = 0; i < blacklist->infolen; i++) {
if (info[i] == ifnum)
return 1;
}
}
return 0;
}
static int is_himemory(const u8 ifnum,
const struct sierra_iface_info *himemorylist)
{
const u8 *info;
int i;
if (himemorylist) {
info = himemorylist->ifaceinfo;
for (i=0; i < himemorylist->infolen; i++) {
if (info[i] == ifnum)
return 1;
}
}
return 0;
}
static int sierra_calc_interface(struct usb_serial *serial)
{
int interface;
struct usb_interface *p_interface;
struct usb_host_interface *p_host_interface;
p_interface = serial->interface;
p_host_interface = p_interface->cur_altsetting;
interface = p_host_interface->desc.bInterfaceNumber;
return interface;
}
static int sierra_probe(struct usb_serial *serial,
const struct usb_device_id *id)
{
int result = 0;
struct usb_device *udev;
u8 ifnum;
udev = serial->dev;
ifnum = sierra_calc_interface(serial);
if (serial->interface->num_altsetting == 2) {
dev_dbg(&udev->dev, "Selecting alt setting for interface %d\n",
ifnum);
usb_set_interface(udev, ifnum, 1);
}
ifnum = sierra_calc_interface(serial);
if (is_blacklisted(ifnum,
(struct sierra_iface_info *)id->driver_info)) {
dev_dbg(&serial->dev->dev,
"Ignoring blacklisted interface #%d\n", ifnum);
return -ENODEV;
}
return result;
}
static int sierra_send_setup(struct usb_serial_port *port)
{
struct usb_serial *serial = port->serial;
struct sierra_port_private *portdata;
__u16 interface = 0;
int val = 0;
int do_send = 0;
int retval;
portdata = usb_get_serial_port_data(port);
if (portdata->dtr_state)
val |= 0x01;
if (portdata->rts_state)
val |= 0x02;
if (serial->num_ports == 1) {
interface = sierra_calc_interface(serial);
if (port->interrupt_in_urb) {
do_send = 1;
}
}
else {
if (port->bulk_out_endpointAddress == 2)
interface = 0;
else if (port->bulk_out_endpointAddress == 4)
interface = 1;
else if (port->bulk_out_endpointAddress == 5)
interface = 2;
do_send = 1;
}
if (!do_send)
return 0;
retval = usb_autopm_get_interface(serial->interface);
if (retval < 0)
return retval;
retval = usb_control_msg(serial->dev, usb_rcvctrlpipe(serial->dev, 0),
0x22, 0x21, val, interface, NULL, 0, USB_CTRL_SET_TIMEOUT);
usb_autopm_put_interface(serial->interface);
return retval;
}
static void sierra_set_termios(struct tty_struct *tty,
struct usb_serial_port *port, struct ktermios *old_termios)
{
tty_termios_copy_hw(&tty->termios, old_termios);
sierra_send_setup(port);
}
static int sierra_tiocmget(struct tty_struct *tty)
{
struct usb_serial_port *port = tty->driver_data;
unsigned int value;
struct sierra_port_private *portdata;
portdata = usb_get_serial_port_data(port);
value = ((portdata->rts_state) ? TIOCM_RTS : 0) |
((portdata->dtr_state) ? TIOCM_DTR : 0) |
((portdata->cts_state) ? TIOCM_CTS : 0) |
((portdata->dsr_state) ? TIOCM_DSR : 0) |
((portdata->dcd_state) ? TIOCM_CAR : 0) |
((portdata->ri_state) ? TIOCM_RNG : 0);
return value;
}
static int sierra_tiocmset(struct tty_struct *tty,
unsigned int set, unsigned int clear)
{
struct usb_serial_port *port = tty->driver_data;
struct sierra_port_private *portdata;
portdata = usb_get_serial_port_data(port);
if (set & TIOCM_RTS)
portdata->rts_state = 1;
if (set & TIOCM_DTR)
portdata->dtr_state = 1;
if (clear & TIOCM_RTS)
portdata->rts_state = 0;
if (clear & TIOCM_DTR)
portdata->dtr_state = 0;
return sierra_send_setup(port);
}
static void sierra_release_urb(struct urb *urb)
{
struct usb_serial_port *port;
if (urb) {
port = urb->context;
kfree(urb->transfer_buffer);
usb_free_urb(urb);
}
}
static void sierra_outdat_callback(struct urb *urb)
{
struct usb_serial_port *port = urb->context;
struct sierra_port_private *portdata = usb_get_serial_port_data(port);
struct sierra_intf_private *intfdata;
int status = urb->status;
intfdata = port->serial->private;
kfree(urb->transfer_buffer);
usb_autopm_put_interface_async(port->serial->interface);
if (status)
dev_dbg(&port->dev, "%s - nonzero write bulk status "
"received: %d\n", __func__, status);
spin_lock(&portdata->lock);
--portdata->outstanding_urbs;
spin_unlock(&portdata->lock);
spin_lock(&intfdata->susp_lock);
--intfdata->in_flight;
spin_unlock(&intfdata->susp_lock);
usb_serial_port_softint(port);
}
static int sierra_write(struct tty_struct *tty, struct usb_serial_port *port,
const unsigned char *buf, int count)
{
struct sierra_port_private *portdata;
struct sierra_intf_private *intfdata;
struct usb_serial *serial = port->serial;
unsigned long flags;
unsigned char *buffer;
struct urb *urb;
size_t writesize = min((size_t)count, (size_t)MAX_TRANSFER);
int retval = 0;
if (count == 0)
return 0;
portdata = usb_get_serial_port_data(port);
intfdata = serial->private;
dev_dbg(&port->dev, "%s: write (%zd bytes)\n", __func__, writesize);
spin_lock_irqsave(&portdata->lock, flags);
dev_dbg(&port->dev, "%s - outstanding_urbs: %d\n", __func__,
portdata->outstanding_urbs);
if (portdata->outstanding_urbs > portdata->num_out_urbs) {
spin_unlock_irqrestore(&portdata->lock, flags);
dev_dbg(&port->dev, "%s - write limit hit\n", __func__);
return 0;
}
portdata->outstanding_urbs++;
dev_dbg(&port->dev, "%s - 1, outstanding_urbs: %d\n", __func__,
portdata->outstanding_urbs);
spin_unlock_irqrestore(&portdata->lock, flags);
retval = usb_autopm_get_interface_async(serial->interface);
if (retval < 0) {
spin_lock_irqsave(&portdata->lock, flags);
portdata->outstanding_urbs--;
spin_unlock_irqrestore(&portdata->lock, flags);
goto error_simple;
}
buffer = kmalloc(writesize, GFP_ATOMIC);
if (!buffer) {
dev_err(&port->dev, "out of memory\n");
retval = -ENOMEM;
goto error_no_buffer;
}
urb = usb_alloc_urb(0, GFP_ATOMIC);
if (!urb) {
dev_err(&port->dev, "no more free urbs\n");
retval = -ENOMEM;
goto error_no_urb;
}
memcpy(buffer, buf, writesize);
usb_serial_debug_data(&port->dev, __func__, writesize, buffer);
usb_fill_bulk_urb(urb, serial->dev,
usb_sndbulkpipe(serial->dev,
port->bulk_out_endpointAddress),
buffer, writesize, sierra_outdat_callback, port);
urb->transfer_flags |= URB_ZERO_PACKET;
spin_lock_irqsave(&intfdata->susp_lock, flags);
if (intfdata->suspended) {
usb_anchor_urb(urb, &portdata->delayed);
spin_unlock_irqrestore(&intfdata->susp_lock, flags);
goto skip_power;
} else {
usb_anchor_urb(urb, &portdata->active);
}
retval = usb_submit_urb(urb, GFP_ATOMIC);
if (retval) {
usb_unanchor_urb(urb);
spin_unlock_irqrestore(&intfdata->susp_lock, flags);
dev_err(&port->dev, "%s - usb_submit_urb(write bulk) failed "
"with status = %d\n", __func__, retval);
goto error;
} else {
intfdata->in_flight++;
spin_unlock_irqrestore(&intfdata->susp_lock, flags);
}
skip_power:
usb_free_urb(urb);
return writesize;
error:
usb_free_urb(urb);
error_no_urb:
kfree(buffer);
error_no_buffer:
spin_lock_irqsave(&portdata->lock, flags);
--portdata->outstanding_urbs;
dev_dbg(&port->dev, "%s - 2. outstanding_urbs: %d\n", __func__,
portdata->outstanding_urbs);
spin_unlock_irqrestore(&portdata->lock, flags);
usb_autopm_put_interface_async(serial->interface);
error_simple:
return retval;
}
static void sierra_indat_callback(struct urb *urb)
{
int err;
int endpoint;
struct usb_serial_port *port;
struct tty_struct *tty;
unsigned char *data = urb->transfer_buffer;
int status = urb->status;
endpoint = usb_pipeendpoint(urb->pipe);
port = urb->context;
if (status) {
dev_dbg(&port->dev, "%s: nonzero status: %d on"
" endpoint %02x\n", __func__, status, endpoint);
} else {
if (urb->actual_length) {
tty = tty_port_tty_get(&port->port);
if (tty) {
tty_insert_flip_string(tty, data,
urb->actual_length);
tty_flip_buffer_push(tty);
tty_kref_put(tty);
usb_serial_debug_data(&port->dev, __func__,
urb->actual_length, data);
}
} else {
dev_dbg(&port->dev, "%s: empty read urb"
" received\n", __func__);
}
}
if (status != -ESHUTDOWN && status != -EPERM) {
usb_mark_last_busy(port->serial->dev);
err = usb_submit_urb(urb, GFP_ATOMIC);
if (err && err != -EPERM)
dev_err(&port->dev, "resubmit read urb failed."
"(%d)\n", err);
}
}
static void sierra_instat_callback(struct urb *urb)
{
int err;
int status = urb->status;
struct usb_serial_port *port = urb->context;
struct sierra_port_private *portdata = usb_get_serial_port_data(port);
struct usb_serial *serial = port->serial;
dev_dbg(&port->dev, "%s: urb %p port %p has data %p\n", __func__,
urb, port, portdata);
if (status == 0) {
struct usb_ctrlrequest *req_pkt =
(struct usb_ctrlrequest *)urb->transfer_buffer;
if (!req_pkt) {
dev_dbg(&port->dev, "%s: NULL req_pkt\n",
__func__);
return;
}
if ((req_pkt->bRequestType == 0xA1) &&
(req_pkt->bRequest == 0x20)) {
int old_dcd_state;
unsigned char signals = *((unsigned char *)
urb->transfer_buffer +
sizeof(struct usb_ctrlrequest));
struct tty_struct *tty;
dev_dbg(&port->dev, "%s: signal x%x\n", __func__,
signals);
old_dcd_state = portdata->dcd_state;
portdata->cts_state = 1;
portdata->dcd_state = ((signals & 0x01) ? 1 : 0);
portdata->dsr_state = ((signals & 0x02) ? 1 : 0);
portdata->ri_state = ((signals & 0x08) ? 1 : 0);
tty = tty_port_tty_get(&port->port);
if (tty && !C_CLOCAL(tty) &&
old_dcd_state && !portdata->dcd_state)
tty_hangup(tty);
tty_kref_put(tty);
} else {
dev_dbg(&port->dev, "%s: type %x req %x\n",
__func__, req_pkt->bRequestType,
req_pkt->bRequest);
}
} else
dev_dbg(&port->dev, "%s: error %d\n", __func__, status);
if (status != -ESHUTDOWN && status != -ENOENT) {
usb_mark_last_busy(serial->dev);
err = usb_submit_urb(urb, GFP_ATOMIC);
if (err && err != -EPERM)
dev_err(&port->dev, "%s: resubmit intr urb "
"failed. (%d)\n", __func__, err);
}
}
static int sierra_write_room(struct tty_struct *tty)
{
struct usb_serial_port *port = tty->driver_data;
struct sierra_port_private *portdata = usb_get_serial_port_data(port);
unsigned long flags;
spin_lock_irqsave(&portdata->lock, flags);
if (portdata->outstanding_urbs > (portdata->num_out_urbs * 2) / 3) {
spin_unlock_irqrestore(&portdata->lock, flags);
dev_dbg(&port->dev, "%s - write limit hit\n", __func__);
return 0;
}
spin_unlock_irqrestore(&portdata->lock, flags);
return 2048;
}
static void sierra_stop_rx_urbs(struct usb_serial_port *port)
{
int i;
struct sierra_port_private *portdata = usb_get_serial_port_data(port);
for (i = 0; i < portdata->num_in_urbs; i++)
usb_kill_urb(portdata->in_urbs[i]);
usb_kill_urb(port->interrupt_in_urb);
}
static int sierra_submit_rx_urbs(struct usb_serial_port *port, gfp_t mem_flags)
{
int ok_cnt;
int err = -EINVAL;
int i;
struct urb *urb;
struct sierra_port_private *portdata = usb_get_serial_port_data(port);
ok_cnt = 0;
for (i = 0; i < portdata->num_in_urbs; i++) {
urb = portdata->in_urbs[i];
if (!urb)
continue;
err = usb_submit_urb(urb, mem_flags);
if (err) {
dev_err(&port->dev, "%s: submit urb failed: %d\n",
__func__, err);
} else {
ok_cnt++;
}
}
if (ok_cnt && port->interrupt_in_urb) {
err = usb_submit_urb(port->interrupt_in_urb, mem_flags);
if (err) {
dev_err(&port->dev, "%s: submit intr urb failed: %d\n",
__func__, err);
}
}
if (ok_cnt > 0)
return 0;
else
return err;
}
static struct urb *sierra_setup_urb(struct usb_serial *serial, int endpoint,
int dir, void *ctx, int len,
gfp_t mem_flags,
usb_complete_t callback)
{
struct urb *urb;
u8 *buf;
if (endpoint == -1)
return NULL;
urb = usb_alloc_urb(0, mem_flags);
if (urb == NULL) {
dev_dbg(&serial->dev->dev, "%s: alloc for endpoint %d failed\n",
__func__, endpoint);
return NULL;
}
buf = kmalloc(len, mem_flags);
if (buf) {
usb_fill_bulk_urb(urb, serial->dev,
usb_sndbulkpipe(serial->dev, endpoint) | dir,
buf, len, callback, ctx);
dev_dbg(&serial->dev->dev, "%s %c u : %p d:%p\n", __func__,
dir == USB_DIR_IN ? 'i' : 'o', urb, buf);
} else {
dev_dbg(&serial->dev->dev, "%s %c u:%p d:%p\n", __func__,
dir == USB_DIR_IN ? 'i' : 'o', urb, buf);
sierra_release_urb(urb);
urb = NULL;
}
return urb;
}
static void sierra_close(struct usb_serial_port *port)
{
int i;
struct usb_serial *serial = port->serial;
struct sierra_port_private *portdata;
struct sierra_intf_private *intfdata = port->serial->private;
portdata = usb_get_serial_port_data(port);
portdata->rts_state = 0;
portdata->dtr_state = 0;
if (serial->dev) {
mutex_lock(&serial->disc_mutex);
if (!serial->disconnected) {
serial->interface->needs_remote_wakeup = 0;
if (!usb_autopm_get_interface(serial->interface))
sierra_send_setup(port);
else
usb_autopm_get_interface_no_resume(serial->interface);
}
mutex_unlock(&serial->disc_mutex);
spin_lock_irq(&intfdata->susp_lock);
portdata->opened = 0;
spin_unlock_irq(&intfdata->susp_lock);
sierra_stop_rx_urbs(port);
for (i = 0; i < portdata->num_in_urbs; i++) {
sierra_release_urb(portdata->in_urbs[i]);
portdata->in_urbs[i] = NULL;
}
}
}
static int sierra_open(struct tty_struct *tty, struct usb_serial_port *port)
{
struct sierra_port_private *portdata;
struct usb_serial *serial = port->serial;
struct sierra_intf_private *intfdata = serial->private;
int i;
int err;
int endpoint;
struct urb *urb;
portdata = usb_get_serial_port_data(port);
portdata->rts_state = 1;
portdata->dtr_state = 1;
endpoint = port->bulk_in_endpointAddress;
for (i = 0; i < portdata->num_in_urbs; i++) {
urb = sierra_setup_urb(serial, endpoint, USB_DIR_IN, port,
IN_BUFLEN, GFP_KERNEL,
sierra_indat_callback);
portdata->in_urbs[i] = urb;
}
usb_clear_halt(serial->dev,
usb_sndbulkpipe(serial->dev, endpoint) | USB_DIR_IN);
err = sierra_submit_rx_urbs(port, GFP_KERNEL);
if (err) {
sierra_close(port);
if (!serial->disconnected)
usb_autopm_put_interface(serial->interface);
return err;
}
sierra_send_setup(port);
serial->interface->needs_remote_wakeup = 1;
spin_lock_irq(&intfdata->susp_lock);
portdata->opened = 1;
spin_unlock_irq(&intfdata->susp_lock);
usb_autopm_put_interface(serial->interface);
return 0;
}
static void sierra_dtr_rts(struct usb_serial_port *port, int on)
{
struct usb_serial *serial = port->serial;
struct sierra_port_private *portdata;
portdata = usb_get_serial_port_data(port);
portdata->rts_state = on;
portdata->dtr_state = on;
if (serial->dev) {
mutex_lock(&serial->disc_mutex);
if (!serial->disconnected)
sierra_send_setup(port);
mutex_unlock(&serial->disc_mutex);
}
}
static int sierra_startup(struct usb_serial *serial)
{
struct sierra_intf_private *intfdata;
intfdata = kzalloc(sizeof(*intfdata), GFP_KERNEL);
if (!intfdata)
return -ENOMEM;
spin_lock_init(&intfdata->susp_lock);
usb_set_serial_data(serial, intfdata);
sierra_set_power_state(serial->dev, 0x0000);
if (nmea)
sierra_vsc_set_nmea(serial->dev, 1);
return 0;
}
static void sierra_release(struct usb_serial *serial)
{
struct sierra_intf_private *intfdata;
intfdata = usb_get_serial_data(serial);
kfree(intfdata);
}
static int sierra_port_probe(struct usb_serial_port *port)
{
struct usb_serial *serial = port->serial;
struct sierra_port_private *portdata;
const struct sierra_iface_info *himemoryp;
u8 ifnum;
portdata = kzalloc(sizeof(*portdata), GFP_KERNEL);
if (!portdata)
return -ENOMEM;
spin_lock_init(&portdata->lock);
init_usb_anchor(&portdata->active);
init_usb_anchor(&portdata->delayed);
portdata->num_out_urbs = N_OUT_URB;
portdata->num_in_urbs = N_IN_URB;
if (serial->num_ports == 1) {
ifnum = sierra_calc_interface(serial);
himemoryp = &typeB_interface_list;
} else {
ifnum = port->number - serial->minor;
himemoryp = &typeA_interface_list;
}
if (is_himemory(ifnum, himemoryp)) {
portdata->num_out_urbs = N_OUT_URB_HM;
portdata->num_in_urbs = N_IN_URB_HM;
}
dev_dbg(&port->dev,
"Memory usage (urbs) interface #%d, in=%d, out=%d\n",
ifnum, portdata->num_in_urbs, portdata->num_out_urbs);
usb_set_serial_port_data(port, portdata);
return 0;
}
static int sierra_port_remove(struct usb_serial_port *port)
{
struct sierra_port_private *portdata;
portdata = usb_get_serial_port_data(port);
kfree(portdata);
return 0;
}
static void stop_read_write_urbs(struct usb_serial *serial)
{
int i;
struct usb_serial_port *port;
struct sierra_port_private *portdata;
for (i = 0; i < serial->num_ports; ++i) {
port = serial->port[i];
portdata = usb_get_serial_port_data(port);
sierra_stop_rx_urbs(port);
usb_kill_anchored_urbs(&portdata->active);
}
}
static int sierra_suspend(struct usb_serial *serial, pm_message_t message)
{
struct sierra_intf_private *intfdata;
int b;
if (PMSG_IS_AUTO(message)) {
intfdata = serial->private;
spin_lock_irq(&intfdata->susp_lock);
b = intfdata->in_flight;
if (b) {
spin_unlock_irq(&intfdata->susp_lock);
return -EBUSY;
} else {
intfdata->suspended = 1;
spin_unlock_irq(&intfdata->susp_lock);
}
}
stop_read_write_urbs(serial);
return 0;
}
static int sierra_resume(struct usb_serial *serial)
{
struct usb_serial_port *port;
struct sierra_intf_private *intfdata = serial->private;
struct sierra_port_private *portdata;
struct urb *urb;
int ec = 0;
int i, err;
spin_lock_irq(&intfdata->susp_lock);
for (i = 0; i < serial->num_ports; i++) {
port = serial->port[i];
portdata = usb_get_serial_port_data(port);
while ((urb = usb_get_from_anchor(&portdata->delayed))) {
usb_anchor_urb(urb, &portdata->active);
intfdata->in_flight++;
err = usb_submit_urb(urb, GFP_ATOMIC);
if (err < 0) {
intfdata->in_flight--;
usb_unanchor_urb(urb);
usb_scuttle_anchored_urbs(&portdata->delayed);
break;
}
}
if (portdata->opened) {
err = sierra_submit_rx_urbs(port, GFP_ATOMIC);
if (err)
ec++;
}
}
intfdata->suspended = 0;
spin_unlock_irq(&intfdata->susp_lock);
return ec ? -EIO : 0;
}
