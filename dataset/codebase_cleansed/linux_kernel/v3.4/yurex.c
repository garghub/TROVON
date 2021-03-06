static void yurex_control_callback(struct urb *urb)
{
struct usb_yurex *dev = urb->context;
int status = urb->status;
if (status) {
err("%s - control failed: %d\n", __func__, status);
wake_up_interruptible(&dev->waitq);
return;
}
}
static void yurex_delete(struct kref *kref)
{
struct usb_yurex *dev = to_yurex_dev(kref);
dbg("yurex_delete");
usb_put_dev(dev->udev);
if (dev->cntl_urb) {
usb_kill_urb(dev->cntl_urb);
kfree(dev->cntl_req);
if (dev->cntl_buffer)
usb_free_coherent(dev->udev, YUREX_BUF_SIZE,
dev->cntl_buffer, dev->cntl_urb->transfer_dma);
usb_free_urb(dev->cntl_urb);
}
if (dev->urb) {
usb_kill_urb(dev->urb);
if (dev->int_buffer)
usb_free_coherent(dev->udev, YUREX_BUF_SIZE,
dev->int_buffer, dev->urb->transfer_dma);
usb_free_urb(dev->urb);
}
kfree(dev);
}
static void yurex_interrupt(struct urb *urb)
{
struct usb_yurex *dev = urb->context;
unsigned char *buf = dev->int_buffer;
int status = urb->status;
unsigned long flags;
int retval, i;
switch (status) {
case 0:
break;
case -EOVERFLOW:
err("%s - overflow with length %d, actual length is %d",
__func__, YUREX_BUF_SIZE, dev->urb->actual_length);
case -ECONNRESET:
case -ENOENT:
case -ESHUTDOWN:
case -EILSEQ:
return;
default:
err("%s - unknown status received: %d", __func__, status);
goto exit;
}
switch (buf[0]) {
case CMD_COUNT:
case CMD_READ:
if (buf[6] == CMD_EOF) {
spin_lock_irqsave(&dev->lock, flags);
dev->bbu = 0;
for (i = 1; i < 6; i++) {
dev->bbu += buf[i];
if (i != 5)
dev->bbu <<= 8;
}
dbg("%s count: %lld", __func__, dev->bbu);
spin_unlock_irqrestore(&dev->lock, flags);
kill_fasync(&dev->async_queue, SIGIO, POLL_IN);
}
else
dbg("data format error - no EOF");
break;
case CMD_ACK:
dbg("%s ack: %c", __func__, buf[1]);
wake_up_interruptible(&dev->waitq);
break;
}
exit:
retval = usb_submit_urb(dev->urb, GFP_ATOMIC);
if (retval) {
err("%s - usb_submit_urb failed: %d",
__func__, retval);
}
}
static int yurex_probe(struct usb_interface *interface, const struct usb_device_id *id)
{
struct usb_yurex *dev;
struct usb_host_interface *iface_desc;
struct usb_endpoint_descriptor *endpoint;
int retval = -ENOMEM;
int i;
DEFINE_WAIT(wait);
dev = kzalloc(sizeof(*dev), GFP_KERNEL);
if (!dev) {
err("Out of memory");
goto error;
}
kref_init(&dev->kref);
mutex_init(&dev->io_mutex);
spin_lock_init(&dev->lock);
init_waitqueue_head(&dev->waitq);
dev->udev = usb_get_dev(interface_to_usbdev(interface));
dev->interface = interface;
iface_desc = interface->cur_altsetting;
for (i = 0; i < iface_desc->desc.bNumEndpoints; i++) {
endpoint = &iface_desc->endpoint[i].desc;
if (usb_endpoint_is_int_in(endpoint)) {
dev->int_in_endpointAddr = endpoint->bEndpointAddress;
break;
}
}
if (!dev->int_in_endpointAddr) {
retval = -ENODEV;
err("Could not find endpoints");
goto error;
}
dev->cntl_urb = usb_alloc_urb(0, GFP_KERNEL);
if (!dev->cntl_urb) {
err("Could not allocate control URB");
goto error;
}
dev->cntl_req = kmalloc(YUREX_BUF_SIZE, GFP_KERNEL);
if (!dev->cntl_req) {
err("Could not allocate cntl_req");
goto error;
}
dev->cntl_buffer = usb_alloc_coherent(dev->udev, YUREX_BUF_SIZE,
GFP_KERNEL,
&dev->cntl_urb->transfer_dma);
if (!dev->cntl_buffer) {
err("Could not allocate cntl_buffer");
goto error;
}
dev->cntl_req->bRequestType = USB_DIR_OUT | USB_TYPE_CLASS |
USB_RECIP_INTERFACE;
dev->cntl_req->bRequest = HID_REQ_SET_REPORT;
dev->cntl_req->wValue = cpu_to_le16((HID_OUTPUT_REPORT + 1) << 8);
dev->cntl_req->wIndex = cpu_to_le16(iface_desc->desc.bInterfaceNumber);
dev->cntl_req->wLength = cpu_to_le16(YUREX_BUF_SIZE);
usb_fill_control_urb(dev->cntl_urb, dev->udev,
usb_sndctrlpipe(dev->udev, 0),
(void *)dev->cntl_req, dev->cntl_buffer,
YUREX_BUF_SIZE, yurex_control_callback, dev);
dev->cntl_urb->transfer_flags |= URB_NO_TRANSFER_DMA_MAP;
dev->urb = usb_alloc_urb(0, GFP_KERNEL);
if (!dev->urb) {
err("Could not allocate URB");
goto error;
}
dev->int_buffer = usb_alloc_coherent(dev->udev, YUREX_BUF_SIZE,
GFP_KERNEL, &dev->urb->transfer_dma);
if (!dev->int_buffer) {
err("Could not allocate int_buffer");
goto error;
}
usb_fill_int_urb(dev->urb, dev->udev,
usb_rcvintpipe(dev->udev, dev->int_in_endpointAddr),
dev->int_buffer, YUREX_BUF_SIZE, yurex_interrupt,
dev, 1);
dev->urb->transfer_flags |= URB_NO_TRANSFER_DMA_MAP;
if (usb_submit_urb(dev->urb, GFP_KERNEL)) {
retval = -EIO;
err("Could not submitting URB");
goto error;
}
usb_set_intfdata(interface, dev);
retval = usb_register_dev(interface, &yurex_class);
if (retval) {
err("Not able to get a minor for this device.");
usb_set_intfdata(interface, NULL);
goto error;
}
dev->bbu = -1;
dev_info(&interface->dev,
"USB YUREX device now attached to Yurex #%d\n",
interface->minor);
return 0;
error:
if (dev)
kref_put(&dev->kref, yurex_delete);
return retval;
}
static void yurex_disconnect(struct usb_interface *interface)
{
struct usb_yurex *dev;
int minor = interface->minor;
dev = usb_get_intfdata(interface);
usb_set_intfdata(interface, NULL);
usb_deregister_dev(interface, &yurex_class);
mutex_lock(&dev->io_mutex);
dev->interface = NULL;
mutex_unlock(&dev->io_mutex);
kill_fasync(&dev->async_queue, SIGIO, POLL_IN);
wake_up_interruptible(&dev->waitq);
kref_put(&dev->kref, yurex_delete);
dev_info(&interface->dev, "USB YUREX #%d now disconnected\n", minor);
}
static int yurex_fasync(int fd, struct file *file, int on)
{
struct usb_yurex *dev;
dev = (struct usb_yurex *)file->private_data;
return fasync_helper(fd, file, on, &dev->async_queue);
}
static int yurex_open(struct inode *inode, struct file *file)
{
struct usb_yurex *dev;
struct usb_interface *interface;
int subminor;
int retval = 0;
subminor = iminor(inode);
interface = usb_find_interface(&yurex_driver, subminor);
if (!interface) {
err("%s - error, can't find device for minor %d",
__func__, subminor);
retval = -ENODEV;
goto exit;
}
dev = usb_get_intfdata(interface);
if (!dev) {
retval = -ENODEV;
goto exit;
}
kref_get(&dev->kref);
mutex_lock(&dev->io_mutex);
file->private_data = dev;
mutex_unlock(&dev->io_mutex);
exit:
return retval;
}
static int yurex_release(struct inode *inode, struct file *file)
{
struct usb_yurex *dev;
dev = (struct usb_yurex *)file->private_data;
if (dev == NULL)
return -ENODEV;
yurex_fasync(-1, file, 0);
kref_put(&dev->kref, yurex_delete);
return 0;
}
static ssize_t yurex_read(struct file *file, char *buffer, size_t count, loff_t *ppos)
{
struct usb_yurex *dev;
int retval = 0;
int bytes_read = 0;
char in_buffer[20];
unsigned long flags;
dev = (struct usb_yurex *)file->private_data;
mutex_lock(&dev->io_mutex);
if (!dev->interface) {
retval = -ENODEV;
goto exit;
}
spin_lock_irqsave(&dev->lock, flags);
bytes_read = snprintf(in_buffer, 20, "%lld\n", dev->bbu);
spin_unlock_irqrestore(&dev->lock, flags);
if (*ppos < bytes_read) {
if (copy_to_user(buffer, in_buffer + *ppos, bytes_read - *ppos))
retval = -EFAULT;
else {
retval = bytes_read - *ppos;
*ppos += bytes_read;
}
}
exit:
mutex_unlock(&dev->io_mutex);
return retval;
}
static ssize_t yurex_write(struct file *file, const char *user_buffer, size_t count, loff_t *ppos)
{
struct usb_yurex *dev;
int i, set = 0, retval = 0;
char buffer[16];
char *data = buffer;
unsigned long long c, c2 = 0;
signed long timeout = 0;
DEFINE_WAIT(wait);
count = min(sizeof(buffer), count);
dev = (struct usb_yurex *)file->private_data;
if (count == 0)
goto error;
mutex_lock(&dev->io_mutex);
if (!dev->interface) {
mutex_unlock(&dev->io_mutex);
retval = -ENODEV;
goto error;
}
if (copy_from_user(buffer, user_buffer, count)) {
mutex_unlock(&dev->io_mutex);
retval = -EFAULT;
goto error;
}
memset(dev->cntl_buffer, CMD_PADDING, YUREX_BUF_SIZE);
switch (buffer[0]) {
case CMD_ANIMATE:
case CMD_LED:
dev->cntl_buffer[0] = buffer[0];
dev->cntl_buffer[1] = buffer[1];
dev->cntl_buffer[2] = CMD_EOF;
break;
case CMD_READ:
case CMD_VERSION:
dev->cntl_buffer[0] = buffer[0];
dev->cntl_buffer[1] = 0x00;
dev->cntl_buffer[2] = CMD_EOF;
break;
case CMD_SET:
data++;
case '0' ... '9':
set = 1;
c = c2 = simple_strtoull(data, NULL, 0);
dev->cntl_buffer[0] = CMD_SET;
for (i = 1; i < 6; i++) {
dev->cntl_buffer[i] = (c>>32) & 0xff;
c <<= 8;
}
buffer[6] = CMD_EOF;
break;
default:
mutex_unlock(&dev->io_mutex);
return -EINVAL;
}
prepare_to_wait(&dev->waitq, &wait, TASK_INTERRUPTIBLE);
dbg("%s - submit %c", __func__, dev->cntl_buffer[0]);
retval = usb_submit_urb(dev->cntl_urb, GFP_KERNEL);
if (retval >= 0)
timeout = schedule_timeout(YUREX_WRITE_TIMEOUT);
finish_wait(&dev->waitq, &wait);
mutex_unlock(&dev->io_mutex);
if (retval < 0) {
err("%s - failed to send bulk msg, error %d", __func__, retval);
goto error;
}
if (set && timeout)
dev->bbu = c2;
return timeout ? count : -EIO;
error:
return retval;
}
