static void delete_context(struct sasem_context *context)
{
usb_free_urb(context->tx_urb);
usb_free_urb(context->rx_urb);
lirc_buffer_free(context->driver->rbuf);
kfree(context->driver->rbuf);
kfree(context->driver);
kfree(context);
if (debug)
printk(KERN_INFO "%s: context deleted\n", __func__);
}
static void deregister_from_lirc(struct sasem_context *context)
{
int retval;
int minor = context->driver->minor;
retval = lirc_unregister_driver(minor);
if (retval)
err("%s: unable to deregister from lirc (%d)",
__func__, retval);
else
printk(KERN_INFO "Deregistered Sasem driver (minor:%d)\n",
minor);
}
static int vfd_open(struct inode *inode, struct file *file)
{
struct usb_interface *interface;
struct sasem_context *context = NULL;
int subminor;
int retval = 0;
mutex_lock(&disconnect_lock);
subminor = iminor(inode);
interface = usb_find_interface(&sasem_driver, subminor);
if (!interface) {
err("%s: could not find interface for minor %d",
__func__, subminor);
retval = -ENODEV;
goto exit;
}
context = usb_get_intfdata(interface);
if (!context) {
err("%s: no context found for minor %d",
__func__, subminor);
retval = -ENODEV;
goto exit;
}
mutex_lock(&context->ctx_lock);
if (context->vfd_isopen) {
err("%s: VFD port is already open", __func__);
retval = -EBUSY;
} else {
context->vfd_isopen = 1;
file->private_data = context;
printk(KERN_INFO "VFD port opened\n");
}
mutex_unlock(&context->ctx_lock);
exit:
mutex_unlock(&disconnect_lock);
return retval;
}
static long vfd_ioctl(struct file *file, unsigned cmd, unsigned long arg)
{
struct sasem_context *context = NULL;
context = (struct sasem_context *) file->private_data;
if (!context) {
err("%s: no context for device", __func__);
return -ENODEV;
}
mutex_lock(&context->ctx_lock);
switch (cmd) {
case IOCTL_LCD_CONTRAST:
if (arg > 1000)
arg = 1000;
context->vfd_contrast = (unsigned int)arg;
break;
default:
printk(KERN_INFO "Unknown IOCTL command\n");
mutex_unlock(&context->ctx_lock);
return -ENOIOCTLCMD;
}
mutex_unlock(&context->ctx_lock);
return 0;
}
static int vfd_close(struct inode *inode, struct file *file)
{
struct sasem_context *context = NULL;
int retval = 0;
context = (struct sasem_context *) file->private_data;
if (!context) {
err("%s: no context for device", __func__);
return -ENODEV;
}
mutex_lock(&context->ctx_lock);
if (!context->vfd_isopen) {
err("%s: VFD is not open", __func__);
retval = -EIO;
} else {
context->vfd_isopen = 0;
printk(KERN_INFO "VFD port closed\n");
if (!context->dev_present && !context->ir_isopen) {
mutex_unlock(&context->ctx_lock);
delete_context(context);
return retval;
}
}
mutex_unlock(&context->ctx_lock);
return retval;
}
static int send_packet(struct sasem_context *context)
{
unsigned int pipe;
int interval = 0;
int retval = 0;
pipe = usb_sndintpipe(context->dev,
context->tx_endpoint->bEndpointAddress);
interval = context->tx_endpoint->bInterval;
usb_fill_int_urb(context->tx_urb, context->dev, pipe,
context->usb_tx_buf, sizeof(context->usb_tx_buf),
usb_tx_callback, context, interval);
context->tx_urb->actual_length = 0;
init_completion(&context->tx.finished);
atomic_set(&(context->tx.busy), 1);
retval = usb_submit_urb(context->tx_urb, GFP_KERNEL);
if (retval) {
atomic_set(&(context->tx.busy), 0);
err("%s: error submitting urb (%d)", __func__, retval);
} else {
mutex_unlock(&context->ctx_lock);
wait_for_completion(&context->tx.finished);
mutex_lock(&context->ctx_lock);
retval = context->tx.status;
if (retval)
err("%s: packet tx failed (%d)", __func__, retval);
}
return retval;
}
static ssize_t vfd_write(struct file *file, const char *buf,
size_t n_bytes, loff_t *pos)
{
int i;
int retval = 0;
struct sasem_context *context;
int *data_buf = NULL;
context = (struct sasem_context *) file->private_data;
if (!context) {
err("%s: no context for device", __func__);
return -ENODEV;
}
mutex_lock(&context->ctx_lock);
if (!context->dev_present) {
err("%s: no Sasem device present", __func__);
retval = -ENODEV;
goto exit;
}
if (n_bytes <= 0 || n_bytes > SASEM_DATA_BUF_SZ) {
err("%s: invalid payload size", __func__);
retval = -EINVAL;
goto exit;
}
data_buf = memdup_user(buf, n_bytes);
if (IS_ERR(data_buf)) {
retval = PTR_ERR(data_buf);
goto exit;
}
memcpy(context->tx.data_buf, data_buf, n_bytes);
for (i = n_bytes; i < SASEM_DATA_BUF_SZ; ++i)
context->tx.data_buf[i] = ' ';
for (i = 0; i < 9; i++) {
switch (i) {
case 0:
memcpy(context->usb_tx_buf, "\x07\0\0\0\0\0\0\0", 8);
context->usb_tx_buf[1] = (context->vfd_contrast) ?
(0x2B - (context->vfd_contrast - 1) / 250)
: 0x2B;
break;
case 1:
memcpy(context->usb_tx_buf, "\x09\x01\0\0\0\0\0\0", 8);
break;
case 2:
memcpy(context->usb_tx_buf, "\x0b\x01\0\0\0\0\0\0", 8);
break;
case 3:
memcpy(context->usb_tx_buf, context->tx.data_buf, 8);
break;
case 4:
memcpy(context->usb_tx_buf,
context->tx.data_buf + 8, 8);
break;
case 5:
memcpy(context->usb_tx_buf, "\x09\x01\0\0\0\0\0\0", 8);
break;
case 6:
memcpy(context->usb_tx_buf, "\x0b\x02\0\0\0\0\0\0", 8);
break;
case 7:
memcpy(context->usb_tx_buf,
context->tx.data_buf + 16, 8);
break;
case 8:
memcpy(context->usb_tx_buf,
context->tx.data_buf + 24, 8);
break;
}
retval = send_packet(context);
if (retval) {
err("%s: send packet failed for packet #%d",
__func__, i);
goto exit;
}
}
exit:
mutex_unlock(&context->ctx_lock);
kfree(data_buf);
return (!retval) ? n_bytes : retval;
}
static void usb_tx_callback(struct urb *urb)
{
struct sasem_context *context;
if (!urb)
return;
context = (struct sasem_context *) urb->context;
if (!context)
return;
context->tx.status = urb->status;
atomic_set(&context->tx.busy, 0);
complete(&context->tx.finished);
return;
}
static int ir_open(void *data)
{
int retval = 0;
struct sasem_context *context;
mutex_lock(&disconnect_lock);
context = (struct sasem_context *) data;
mutex_lock(&context->ctx_lock);
if (context->ir_isopen) {
err("%s: IR port is already open", __func__);
retval = -EBUSY;
goto exit;
}
usb_fill_int_urb(context->rx_urb, context->dev,
usb_rcvintpipe(context->dev,
context->rx_endpoint->bEndpointAddress),
context->usb_rx_buf, sizeof(context->usb_rx_buf),
usb_rx_callback, context, context->rx_endpoint->bInterval);
retval = usb_submit_urb(context->rx_urb, GFP_KERNEL);
if (retval)
err("%s: usb_submit_urb failed for ir_open (%d)",
__func__, retval);
else {
context->ir_isopen = 1;
printk(KERN_INFO "IR port opened\n");
}
exit:
mutex_unlock(&context->ctx_lock);
mutex_unlock(&disconnect_lock);
return retval;
}
static void ir_close(void *data)
{
struct sasem_context *context;
context = (struct sasem_context *)data;
if (!context) {
err("%s: no context for device", __func__);
return;
}
mutex_lock(&context->ctx_lock);
usb_kill_urb(context->rx_urb);
context->ir_isopen = 0;
printk(KERN_INFO "IR port closed\n");
if (!context->dev_present) {
deregister_from_lirc(context);
if (!context->vfd_isopen) {
mutex_unlock(&context->ctx_lock);
delete_context(context);
return;
}
}
mutex_unlock(&context->ctx_lock);
return;
}
static void incoming_packet(struct sasem_context *context,
struct urb *urb)
{
int len = urb->actual_length;
unsigned char *buf = urb->transfer_buffer;
long ms;
struct timeval tv;
int i;
if (len != 8) {
printk(KERN_WARNING "%s: invalid incoming packet size (%d)\n",
__func__, len);
return;
}
if (debug) {
printk(KERN_INFO "Incoming data: ");
for (i = 0; i < 8; ++i)
printk(KERN_CONT "%02x ", buf[i]);
printk(KERN_CONT "\n");
}
do_gettimeofday(&tv);
ms = (tv.tv_sec - context->presstime.tv_sec) * 1000 +
(tv.tv_usec - context->presstime.tv_usec) / 1000;
if (memcmp(buf, "\x08\0\0\0\0\0\0\0", 8) == 0) {
if ((ms < 250) && (context->codesaved != 0)) {
memcpy(buf, &context->lastcode, 8);
context->presstime.tv_sec = tv.tv_sec;
context->presstime.tv_usec = tv.tv_usec;
}
} else {
memcpy(&context->lastcode, buf, 8);
context->codesaved = 1;
context->presstime.tv_sec = tv.tv_sec;
context->presstime.tv_usec = tv.tv_usec;
}
lirc_buffer_write(context->driver->rbuf, buf);
wake_up(&context->driver->rbuf->wait_poll);
}
static void usb_rx_callback(struct urb *urb)
{
struct sasem_context *context;
if (!urb)
return;
context = (struct sasem_context *) urb->context;
if (!context)
return;
switch (urb->status) {
case -ENOENT:
return;
case 0:
if (context->ir_isopen)
incoming_packet(context, urb);
break;
default:
printk(KERN_WARNING "%s: status (%d): ignored",
__func__, urb->status);
break;
}
usb_submit_urb(context->rx_urb, GFP_ATOMIC);
return;
}
static int sasem_probe(struct usb_interface *interface,
const struct usb_device_id *id)
{
struct usb_device *dev = NULL;
struct usb_host_interface *iface_desc = NULL;
struct usb_endpoint_descriptor *rx_endpoint = NULL;
struct usb_endpoint_descriptor *tx_endpoint = NULL;
struct urb *rx_urb = NULL;
struct urb *tx_urb = NULL;
struct lirc_driver *driver = NULL;
struct lirc_buffer *rbuf = NULL;
int lirc_minor = 0;
int num_endpoints;
int retval = 0;
int vfd_ep_found;
int ir_ep_found;
int alloc_status;
struct sasem_context *context = NULL;
int i;
printk(KERN_INFO "%s: found Sasem device\n", __func__);
dev = usb_get_dev(interface_to_usbdev(interface));
iface_desc = interface->cur_altsetting;
num_endpoints = iface_desc->desc.bNumEndpoints;
ir_ep_found = 0;
vfd_ep_found = 0;
for (i = 0; i < num_endpoints && !(ir_ep_found && vfd_ep_found); ++i) {
struct usb_endpoint_descriptor *ep;
int ep_dir;
int ep_type;
ep = &iface_desc->endpoint [i].desc;
ep_dir = ep->bEndpointAddress & USB_ENDPOINT_DIR_MASK;
ep_type = ep->bmAttributes & USB_ENDPOINT_XFERTYPE_MASK;
if (!ir_ep_found &&
ep_dir == USB_DIR_IN &&
ep_type == USB_ENDPOINT_XFER_INT) {
rx_endpoint = ep;
ir_ep_found = 1;
if (debug)
printk(KERN_INFO "%s: found IR endpoint\n",
__func__);
} else if (!vfd_ep_found &&
ep_dir == USB_DIR_OUT &&
ep_type == USB_ENDPOINT_XFER_INT) {
tx_endpoint = ep;
vfd_ep_found = 1;
if (debug)
printk(KERN_INFO "%s: found VFD endpoint\n",
__func__);
}
}
if (!ir_ep_found) {
err("%s: no valid input (IR) endpoint found.", __func__);
retval = -ENODEV;
goto exit;
}
if (!vfd_ep_found)
printk(KERN_INFO "%s: no valid output (VFD) endpoint found.\n",
__func__);
alloc_status = 0;
context = kzalloc(sizeof(struct sasem_context), GFP_KERNEL);
if (!context) {
err("%s: kzalloc failed for context", __func__);
alloc_status = 1;
goto alloc_status_switch;
}
driver = kzalloc(sizeof(struct lirc_driver), GFP_KERNEL);
if (!driver) {
err("%s: kzalloc failed for lirc_driver", __func__);
alloc_status = 2;
goto alloc_status_switch;
}
rbuf = kmalloc(sizeof(struct lirc_buffer), GFP_KERNEL);
if (!rbuf) {
err("%s: kmalloc failed for lirc_buffer", __func__);
alloc_status = 3;
goto alloc_status_switch;
}
if (lirc_buffer_init(rbuf, BUF_CHUNK_SIZE, BUF_SIZE)) {
err("%s: lirc_buffer_init failed", __func__);
alloc_status = 4;
goto alloc_status_switch;
}
rx_urb = usb_alloc_urb(0, GFP_KERNEL);
if (!rx_urb) {
err("%s: usb_alloc_urb failed for IR urb", __func__);
alloc_status = 5;
goto alloc_status_switch;
}
if (vfd_ep_found) {
tx_urb = usb_alloc_urb(0, GFP_KERNEL);
if (!tx_urb) {
err("%s: usb_alloc_urb failed for VFD urb",
__func__);
alloc_status = 6;
goto alloc_status_switch;
}
}
mutex_init(&context->ctx_lock);
strcpy(driver->name, MOD_NAME);
driver->minor = -1;
driver->code_length = 64;
driver->sample_rate = 0;
driver->features = LIRC_CAN_REC_LIRCCODE;
driver->data = context;
driver->rbuf = rbuf;
driver->set_use_inc = ir_open;
driver->set_use_dec = ir_close;
driver->dev = &interface->dev;
driver->owner = THIS_MODULE;
mutex_lock(&context->ctx_lock);
lirc_minor = lirc_register_driver(driver);
if (lirc_minor < 0) {
err("%s: lirc_register_driver failed", __func__);
alloc_status = 7;
retval = lirc_minor;
goto unlock;
} else
printk(KERN_INFO "%s: Registered Sasem driver (minor:%d)\n",
__func__, lirc_minor);
driver->minor = lirc_minor;
context->dev = dev;
context->dev_present = 1;
context->rx_endpoint = rx_endpoint;
context->rx_urb = rx_urb;
if (vfd_ep_found) {
context->tx_endpoint = tx_endpoint;
context->tx_urb = tx_urb;
context->vfd_contrast = 1000;
}
context->driver = driver;
usb_set_intfdata(interface, context);
if (vfd_ep_found) {
if (debug)
printk(KERN_INFO "Registering VFD with sysfs\n");
if (usb_register_dev(interface, &sasem_class))
printk(KERN_INFO "%s: could not get a minor number "
"for VFD\n", __func__);
}
printk(KERN_INFO "%s: Sasem device on usb<%d:%d> initialized\n",
__func__, dev->bus->busnum, dev->devnum);
unlock:
mutex_unlock(&context->ctx_lock);
alloc_status_switch:
switch (alloc_status) {
case 7:
if (vfd_ep_found)
usb_free_urb(tx_urb);
case 6:
usb_free_urb(rx_urb);
case 5:
lirc_buffer_free(rbuf);
case 4:
kfree(rbuf);
case 3:
kfree(driver);
case 2:
kfree(context);
context = NULL;
case 1:
if (retval == 0)
retval = -ENOMEM;
}
exit:
return retval;
}
static void sasem_disconnect(struct usb_interface *interface)
{
struct sasem_context *context;
mutex_lock(&disconnect_lock);
context = usb_get_intfdata(interface);
mutex_lock(&context->ctx_lock);
printk(KERN_INFO "%s: Sasem device disconnected\n", __func__);
usb_set_intfdata(interface, NULL);
context->dev_present = 0;
usb_kill_urb(context->rx_urb);
if (atomic_read(&context->tx.busy)) {
usb_kill_urb(context->tx_urb);
wait_for_completion(&context->tx.finished);
}
if (!context->ir_isopen)
deregister_from_lirc(context);
usb_deregister_dev(interface, &sasem_class);
mutex_unlock(&context->ctx_lock);
if (!context->ir_isopen && !context->vfd_isopen)
delete_context(context);
mutex_unlock(&disconnect_lock);
}
static int __init sasem_init(void)
{
int rc;
printk(KERN_INFO MOD_DESC ", v" MOD_VERSION "\n");
printk(KERN_INFO MOD_AUTHOR "\n");
rc = usb_register(&sasem_driver);
if (rc < 0) {
err("%s: usb register failed (%d)", __func__, rc);
return -ENODEV;
}
return 0;
}
static void __exit sasem_exit(void)
{
usb_deregister(&sasem_driver);
printk(KERN_INFO "module removed. Goodbye!\n");
}
