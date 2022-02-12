static void free_imon_context(struct imon_context *context)
{
struct device *dev = context->driver->dev;
usb_free_urb(context->tx_urb);
usb_free_urb(context->rx_urb);
lirc_buffer_free(context->driver->rbuf);
kfree(context->driver->rbuf);
kfree(context->driver);
kfree(context);
dev_dbg(dev, "%s: iMON context freed\n", __func__);
}
static void deregister_from_lirc(struct imon_context *context)
{
int retval;
int minor = context->driver->minor;
retval = lirc_unregister_driver(minor);
if (retval)
dev_err(&context->usbdev->dev,
"unable to deregister from lirc(%d)", retval);
else
dev_info(&context->usbdev->dev,
"Deregistered iMON driver (minor:%d)\n", minor);
}
static int display_open(struct inode *inode, struct file *file)
{
struct usb_interface *interface;
struct imon_context *context = NULL;
int subminor;
int retval = 0;
mutex_lock(&driver_lock);
subminor = iminor(inode);
interface = usb_find_interface(&imon_driver, subminor);
if (!interface) {
pr_err("%s: could not find interface for minor %d\n",
__func__, subminor);
retval = -ENODEV;
goto exit;
}
context = usb_get_intfdata(interface);
if (!context) {
dev_err(&interface->dev, "no context found for minor %d\n",
subminor);
retval = -ENODEV;
goto exit;
}
mutex_lock(&context->ctx_lock);
if (!context->display) {
dev_err(&interface->dev,
"%s: display not supported by device\n", __func__);
retval = -ENODEV;
} else if (context->display_isopen) {
dev_err(&interface->dev,
"%s: display port is already open\n", __func__);
retval = -EBUSY;
} else {
context->display_isopen = 1;
file->private_data = context;
dev_info(context->driver->dev, "display port opened\n");
}
mutex_unlock(&context->ctx_lock);
exit:
mutex_unlock(&driver_lock);
return retval;
}
static int display_close(struct inode *inode, struct file *file)
{
struct imon_context *context = NULL;
int retval = 0;
context = file->private_data;
if (!context) {
pr_err("%s: no context for device\n", __func__);
return -ENODEV;
}
mutex_lock(&context->ctx_lock);
if (!context->display) {
dev_err(&context->usbdev->dev,
"%s: display not supported by device\n", __func__);
retval = -ENODEV;
} else if (!context->display_isopen) {
dev_err(&context->usbdev->dev,
"%s: display is not open\n", __func__);
retval = -EIO;
} else {
context->display_isopen = 0;
dev_info(context->driver->dev, "display port closed\n");
if (!context->dev_present && !context->ir_isopen) {
mutex_unlock(&context->ctx_lock);
free_imon_context(context);
return retval;
}
}
mutex_unlock(&context->ctx_lock);
return retval;
}
static int send_packet(struct imon_context *context)
{
unsigned int pipe;
int interval = 0;
int retval = 0;
pipe = usb_sndintpipe(context->usbdev,
context->tx_endpoint->bEndpointAddress);
interval = context->tx_endpoint->bInterval;
usb_fill_int_urb(context->tx_urb, context->usbdev, pipe,
context->usb_tx_buf,
sizeof(context->usb_tx_buf),
usb_tx_callback, context, interval);
context->tx_urb->actual_length = 0;
init_completion(&context->tx.finished);
atomic_set(&context->tx.busy, 1);
retval = usb_submit_urb(context->tx_urb, GFP_KERNEL);
if (retval) {
atomic_set(&context->tx.busy, 0);
dev_err(&context->usbdev->dev, "error submitting urb(%d)\n",
retval);
} else {
mutex_unlock(&context->ctx_lock);
retval = wait_for_completion_interruptible(
&context->tx.finished);
if (retval)
dev_err(&context->usbdev->dev,
"%s: task interrupted\n", __func__);
mutex_lock(&context->ctx_lock);
retval = context->tx.status;
if (retval)
dev_err(&context->usbdev->dev,
"packet tx failed (%d)\n", retval);
}
return retval;
}
static ssize_t vfd_write(struct file *file, const char __user *buf,
size_t n_bytes, loff_t *pos)
{
int i;
int offset;
int seq;
int retval = 0;
struct imon_context *context;
const unsigned char vfd_packet6[] = {
0x01, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF };
int *data_buf = NULL;
context = file->private_data;
if (!context) {
pr_err("%s: no context for device\n", __func__);
return -ENODEV;
}
mutex_lock(&context->ctx_lock);
if (!context->dev_present) {
dev_err(&context->usbdev->dev,
"%s: no iMON device present\n", __func__);
retval = -ENODEV;
goto exit;
}
if (n_bytes <= 0 || n_bytes > IMON_DATA_BUF_SZ - 3) {
dev_err(&context->usbdev->dev,
"%s: invalid payload size\n", __func__);
retval = -EINVAL;
goto exit;
}
data_buf = memdup_user(buf, n_bytes);
if (IS_ERR(data_buf)) {
retval = PTR_ERR(data_buf);
data_buf = NULL;
goto exit;
}
memcpy(context->tx.data_buf, data_buf, n_bytes);
for (i = n_bytes; i < IMON_DATA_BUF_SZ - 3; ++i)
context->tx.data_buf[i] = ' ';
for (i = IMON_DATA_BUF_SZ - 3; i < IMON_DATA_BUF_SZ; ++i)
context->tx.data_buf[i] = 0xFF;
offset = 0;
seq = 0;
do {
memcpy(context->usb_tx_buf, context->tx.data_buf + offset, 7);
context->usb_tx_buf[7] = (unsigned char) seq;
retval = send_packet(context);
if (retval) {
dev_err(&context->usbdev->dev,
"send packet failed for packet #%d\n",
seq / 2);
goto exit;
} else {
seq += 2;
offset += 7;
}
} while (offset < IMON_DATA_BUF_SZ);
if (context->vfd_proto_6p) {
memcpy(context->usb_tx_buf, &vfd_packet6, sizeof(vfd_packet6));
context->usb_tx_buf[7] = (unsigned char) seq;
retval = send_packet(context);
if (retval)
dev_err(&context->usbdev->dev,
"send packet failed for packet #%d\n",
seq / 2);
}
exit:
mutex_unlock(&context->ctx_lock);
kfree(data_buf);
return (!retval) ? n_bytes : retval;
}
static void usb_tx_callback(struct urb *urb)
{
struct imon_context *context;
if (!urb)
return;
context = (struct imon_context *)urb->context;
if (!context)
return;
context->tx.status = urb->status;
atomic_set(&context->tx.busy, 0);
complete(&context->tx.finished);
}
static int ir_open(void *data)
{
struct imon_context *context;
mutex_lock(&driver_lock);
context = data;
context->rx.count = 0;
context->rx.initial_space = 1;
context->rx.prev_bit = 0;
context->ir_isopen = 1;
dev_info(context->driver->dev, "IR port opened\n");
mutex_unlock(&driver_lock);
return 0;
}
static void ir_close(void *data)
{
struct imon_context *context;
context = data;
if (!context) {
pr_err("%s: no context for device\n", __func__);
return;
}
mutex_lock(&context->ctx_lock);
context->ir_isopen = 0;
dev_info(context->driver->dev, "IR port closed\n");
if (!context->dev_present) {
deregister_from_lirc(context);
if (!context->display_isopen) {
mutex_unlock(&context->ctx_lock);
free_imon_context(context);
return;
}
}
mutex_unlock(&context->ctx_lock);
}
static void submit_data(struct imon_context *context)
{
unsigned char buf[4];
int value = context->rx.count;
int i;
dev_dbg(context->driver->dev, "submitting data to LIRC\n");
value *= BIT_DURATION;
value &= PULSE_MASK;
if (context->rx.prev_bit)
value |= PULSE_BIT;
for (i = 0; i < 4; ++i)
buf[i] = value>>(i*8);
lirc_buffer_write(context->driver->rbuf, buf);
wake_up(&context->driver->rbuf->wait_poll);
}
static void imon_incoming_packet(struct imon_context *context,
struct urb *urb, int intf)
{
int len = urb->actual_length;
unsigned char *buf = urb->transfer_buffer;
struct device *dev = context->driver->dev;
int octet, bit;
unsigned char mask;
if (!context->ir_isopen)
return;
if (len != 8) {
dev_warn(dev, "imon %s: invalid incoming packet size (len = %d, intf%d)\n",
__func__, len, intf);
return;
}
if (debug)
dev_info(dev, "raw packet: %*ph\n", len, buf);
if (buf[7] == 1 && context->rx.initial_space) {
context->rx.prev_bit = 0;
context->rx.count = 4;
submit_data(context);
context->rx.count = 0;
}
for (octet = 0; octet < 5; ++octet) {
mask = 0x80;
for (bit = 0; bit < 8; ++bit) {
int curr_bit = !(buf[octet] & mask);
if (curr_bit != context->rx.prev_bit) {
if (context->rx.count) {
submit_data(context);
context->rx.count = 0;
}
context->rx.prev_bit = curr_bit;
}
++context->rx.count;
mask >>= 1;
}
}
if (buf[7] == 10) {
if (context->rx.count) {
submit_data(context);
context->rx.count = 0;
}
context->rx.initial_space = context->rx.prev_bit;
}
}
static void usb_rx_callback(struct urb *urb)
{
struct imon_context *context;
int intfnum = 0;
if (!urb)
return;
context = (struct imon_context *)urb->context;
if (!context)
return;
switch (urb->status) {
case -ENOENT:
return;
case 0:
imon_incoming_packet(context, urb, intfnum);
break;
default:
dev_warn(context->driver->dev, "imon %s: status(%d): ignored\n",
__func__, urb->status);
break;
}
usb_submit_urb(context->rx_urb, GFP_ATOMIC);
}
static int imon_probe(struct usb_interface *interface,
const struct usb_device_id *id)
{
struct usb_device *usbdev = NULL;
struct usb_host_interface *iface_desc = NULL;
struct usb_endpoint_descriptor *rx_endpoint = NULL;
struct usb_endpoint_descriptor *tx_endpoint = NULL;
struct urb *rx_urb = NULL;
struct urb *tx_urb = NULL;
struct lirc_driver *driver = NULL;
struct lirc_buffer *rbuf = NULL;
struct device *dev = &interface->dev;
int ifnum;
int lirc_minor = 0;
int num_endpts;
int retval = 0;
int display_ep_found = 0;
int ir_ep_found = 0;
int alloc_status = 0;
int vfd_proto_6p = 0;
struct imon_context *context = NULL;
int i;
u16 vendor, product;
mutex_lock(&driver_lock);
context = kzalloc(sizeof(struct imon_context), GFP_KERNEL);
if (!context) {
alloc_status = 1;
goto alloc_status_switch;
}
if (usb_match_id(interface, ir_only_list))
context->display = 0;
else
context->display = 1;
usbdev = usb_get_dev(interface_to_usbdev(interface));
iface_desc = interface->cur_altsetting;
num_endpts = iface_desc->desc.bNumEndpoints;
ifnum = iface_desc->desc.bInterfaceNumber;
vendor = le16_to_cpu(usbdev->descriptor.idVendor);
product = le16_to_cpu(usbdev->descriptor.idProduct);
dev_dbg(dev, "%s: found iMON device (%04x:%04x, intf%d)\n",
__func__, vendor, product, ifnum);
for (i = 0; i < num_endpts && !(ir_ep_found && display_ep_found); ++i) {
struct usb_endpoint_descriptor *ep;
int ep_dir;
int ep_type;
ep = &iface_desc->endpoint[i].desc;
ep_dir = ep->bEndpointAddress & USB_ENDPOINT_DIR_MASK;
ep_type = ep->bmAttributes & USB_ENDPOINT_XFERTYPE_MASK;
if (!ir_ep_found &&
ep_dir == USB_DIR_IN &&
ep_type == USB_ENDPOINT_XFER_INT) {
rx_endpoint = ep;
ir_ep_found = 1;
dev_dbg(dev, "%s: found IR endpoint\n", __func__);
} else if (!display_ep_found && ep_dir == USB_DIR_OUT &&
ep_type == USB_ENDPOINT_XFER_INT) {
tx_endpoint = ep;
display_ep_found = 1;
dev_dbg(dev, "%s: found display endpoint\n", __func__);
}
}
if (context->display == 0) {
display_ep_found = 0;
dev_dbg(dev, "%s: device has no display\n", __func__);
}
if (!ir_ep_found) {
dev_err(dev, "%s: no valid input (IR) endpoint found.\n",
__func__);
retval = -ENODEV;
alloc_status = 2;
goto alloc_status_switch;
}
if (display_ep_found) {
if (usb_match_id(interface, vfd_proto_6p_list))
vfd_proto_6p = 1;
dev_dbg(dev, "%s: vfd_proto_6p: %d\n",
__func__, vfd_proto_6p);
}
driver = kzalloc(sizeof(struct lirc_driver), GFP_KERNEL);
if (!driver) {
alloc_status = 2;
goto alloc_status_switch;
}
rbuf = kmalloc(sizeof(struct lirc_buffer), GFP_KERNEL);
if (!rbuf) {
alloc_status = 3;
goto alloc_status_switch;
}
if (lirc_buffer_init(rbuf, BUF_CHUNK_SIZE, BUF_SIZE)) {
dev_err(dev, "%s: lirc_buffer_init failed\n", __func__);
alloc_status = 4;
goto alloc_status_switch;
}
rx_urb = usb_alloc_urb(0, GFP_KERNEL);
if (!rx_urb) {
dev_err(dev, "%s: usb_alloc_urb failed for IR urb\n", __func__);
alloc_status = 5;
goto alloc_status_switch;
}
tx_urb = usb_alloc_urb(0, GFP_KERNEL);
if (!tx_urb) {
dev_err(dev, "%s: usb_alloc_urb failed for display urb\n",
__func__);
alloc_status = 6;
goto alloc_status_switch;
}
mutex_init(&context->ctx_lock);
context->vfd_proto_6p = vfd_proto_6p;
strcpy(driver->name, MOD_NAME);
driver->minor = -1;
driver->code_length = BUF_CHUNK_SIZE * 8;
driver->sample_rate = 0;
driver->features = LIRC_CAN_REC_MODE2;
driver->data = context;
driver->rbuf = rbuf;
driver->set_use_inc = ir_open;
driver->set_use_dec = ir_close;
driver->dev = &interface->dev;
driver->owner = THIS_MODULE;
mutex_lock(&context->ctx_lock);
context->driver = driver;
lirc_minor = lirc_register_driver(driver);
if (lirc_minor < 0) {
dev_err(dev, "%s: lirc_register_driver failed\n", __func__);
alloc_status = 7;
goto unlock;
} else
dev_info(dev, "Registered iMON driver (lirc minor: %d)\n",
lirc_minor);
driver->minor = lirc_minor;
context->usbdev = usbdev;
context->dev_present = 1;
context->rx_endpoint = rx_endpoint;
context->rx_urb = rx_urb;
context->tx_endpoint = tx_endpoint;
context->tx_urb = tx_urb;
if (display_ep_found)
context->display = 1;
usb_fill_int_urb(context->rx_urb, context->usbdev,
usb_rcvintpipe(context->usbdev,
context->rx_endpoint->bEndpointAddress),
context->usb_rx_buf, sizeof(context->usb_rx_buf),
usb_rx_callback, context,
context->rx_endpoint->bInterval);
retval = usb_submit_urb(context->rx_urb, GFP_KERNEL);
if (retval) {
dev_err(dev, "usb_submit_urb failed for intf0 (%d)\n", retval);
alloc_status = 8;
goto unlock;
}
usb_set_intfdata(interface, context);
if (context->display && ifnum == 0) {
dev_dbg(dev, "%s: Registering iMON display with sysfs\n",
__func__);
if (usb_register_dev(interface, &imon_class)) {
dev_info(dev, "%s: could not get a minor number for display\n",
__func__);
}
}
dev_info(dev, "iMON device (%04x:%04x, intf%d) on usb<%d:%d> initialized\n",
vendor, product, ifnum, usbdev->bus->busnum, usbdev->devnum);
unlock:
mutex_unlock(&context->ctx_lock);
alloc_status_switch:
switch (alloc_status) {
case 8:
lirc_unregister_driver(driver->minor);
case 7:
usb_free_urb(tx_urb);
case 6:
usb_free_urb(rx_urb);
case 5:
if (rbuf)
lirc_buffer_free(rbuf);
case 4:
kfree(rbuf);
case 3:
kfree(driver);
case 2:
kfree(context);
context = NULL;
case 1:
if (retval != -ENODEV)
retval = -ENOMEM;
break;
case 0:
retval = 0;
}
mutex_unlock(&driver_lock);
return retval;
}
static void imon_disconnect(struct usb_interface *interface)
{
struct imon_context *context;
int ifnum;
mutex_lock(&driver_lock);
context = usb_get_intfdata(interface);
ifnum = interface->cur_altsetting->desc.bInterfaceNumber;
mutex_lock(&context->ctx_lock);
usb_set_intfdata(interface, NULL);
if (atomic_read(&context->tx.busy)) {
usb_kill_urb(context->tx_urb);
complete_all(&context->tx.finished);
}
context->dev_present = 0;
usb_kill_urb(context->rx_urb);
if (context->display)
usb_deregister_dev(interface, &imon_class);
if (!context->ir_isopen && !context->dev_present) {
deregister_from_lirc(context);
mutex_unlock(&context->ctx_lock);
if (!context->display_isopen)
free_imon_context(context);
} else
mutex_unlock(&context->ctx_lock);
mutex_unlock(&driver_lock);
dev_info(&interface->dev, "%s: iMON device (intf%d) disconnected\n",
__func__, ifnum);
}
static int imon_suspend(struct usb_interface *intf, pm_message_t message)
{
struct imon_context *context = usb_get_intfdata(intf);
usb_kill_urb(context->rx_urb);
return 0;
}
static int imon_resume(struct usb_interface *intf)
{
struct imon_context *context = usb_get_intfdata(intf);
usb_fill_int_urb(context->rx_urb, context->usbdev,
usb_rcvintpipe(context->usbdev,
context->rx_endpoint->bEndpointAddress),
context->usb_rx_buf, sizeof(context->usb_rx_buf),
usb_rx_callback, context,
context->rx_endpoint->bInterval);
return usb_submit_urb(context->rx_urb, GFP_ATOMIC);
}
