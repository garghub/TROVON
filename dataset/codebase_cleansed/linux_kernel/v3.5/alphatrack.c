static void usb_alphatrack_abort_transfers(struct usb_alphatrack *dev)
{
if (dev->interrupt_in_running) {
dev->interrupt_in_running = 0;
if (dev->intf)
usb_kill_urb(dev->interrupt_in_urb);
}
if (dev->interrupt_out_busy)
if (dev->intf)
usb_kill_urb(dev->interrupt_out_urb);
}
static void usb_alphatrack_delete(struct usb_alphatrack *dev)
{
usb_alphatrack_abort_transfers(dev);
usb_free_urb(dev->interrupt_in_urb);
usb_free_urb(dev->interrupt_out_urb);
kfree(dev->ring_buffer);
kfree(dev->interrupt_in_buffer);
kfree(dev->interrupt_out_buffer);
kfree(dev);
}
static void usb_alphatrack_interrupt_in_callback(struct urb *urb)
{
struct usb_alphatrack *dev = urb->context;
unsigned int next_ring_head;
int retval = -1;
if (urb->status) {
if (urb->status == -ENOENT ||
urb->status == -ECONNRESET || urb->status == -ESHUTDOWN) {
goto exit;
} else {
dbg_info(&dev->intf->dev,
"%s: nonzero status received: %d\n", __func__,
urb->status);
goto resubmit;
}
}
if (urb->actual_length != INPUT_CMD_SIZE) {
dev_warn(&dev->intf->dev,
"Urb length was %d bytes!!"
"Do something intelligent\n", urb->actual_length);
} else {
alphatrack_ocmd_info(&dev->intf->dev,
&(*dev->ring_buffer)[dev->ring_tail].cmd,
"%s", "bla");
if (memcmp
(dev->interrupt_in_buffer, dev->oldi_buffer,
INPUT_CMD_SIZE) == 0) {
goto resubmit;
}
memcpy(dev->oldi_buffer, dev->interrupt_in_buffer,
INPUT_CMD_SIZE);
#if SUPPRESS_EXTRA_OFFLINE_EVENTS
if (dev->offline == 2 && dev->interrupt_in_buffer[1] == 0xff)
goto resubmit;
if (dev->offline == 1 && dev->interrupt_in_buffer[1] == 0xff) {
dev->offline = 2;
goto resubmit;
}
if (dev->offline > 0 && dev->interrupt_in_buffer[1] != 0xff)
dev->offline = 0;
if (dev->offline == 0 && dev->interrupt_in_buffer[1] == 0xff)
dev->offline = 1;
#endif
dbg_info(&dev->intf->dev, "%s: head, tail are %x, %x\n",
__func__, dev->ring_head, dev->ring_tail);
next_ring_head = (dev->ring_head + 1) % ring_buffer_size;
if (next_ring_head != dev->ring_tail) {
memcpy(&((*dev->ring_buffer)[dev->ring_head]),
dev->interrupt_in_buffer, urb->actual_length);
dev->ring_head = next_ring_head;
retval = 0;
memset(dev->interrupt_in_buffer, 0, urb->actual_length);
} else {
dev_warn(&dev->intf->dev,
"Ring buffer overflow, %d bytes dropped\n",
urb->actual_length);
memset(dev->interrupt_in_buffer, 0, urb->actual_length);
}
}
resubmit:
if (dev->interrupt_in_running && dev->intf) {
retval = usb_submit_urb(dev->interrupt_in_urb, GFP_ATOMIC);
if (retval)
dev_err(&dev->intf->dev,
"usb_submit_urb failed (%d)\n", retval);
}
exit:
dev->interrupt_in_done = 1;
wake_up_interruptible(&dev->read_wait);
}
static void usb_alphatrack_interrupt_out_callback(struct urb *urb)
{
struct usb_alphatrack *dev = urb->context;
if (urb->status && !(urb->status == -ENOENT ||
urb->status == -ECONNRESET ||
urb->status == -ESHUTDOWN))
dbg_info(&dev->intf->dev,
"%s - nonzero write interrupt status received: %d\n",
__func__, urb->status);
atomic_dec(&dev->writes_pending);
dev->interrupt_out_busy = 0;
wake_up_interruptible(&dev->write_wait);
}
static int usb_alphatrack_open(struct inode *inode, struct file *file)
{
struct usb_alphatrack *dev;
int subminor;
int retval = 0;
struct usb_interface *interface;
nonseekable_open(inode, file);
subminor = iminor(inode);
mutex_lock(&disconnect_mutex);
interface = usb_find_interface(&usb_alphatrack_driver, subminor);
if (!interface) {
printk(KERN_ERR "%s - error, can't find device for minor %d\n",
__func__, subminor);
retval = -ENODEV;
goto unlock_disconnect_exit;
}
dev = usb_get_intfdata(interface);
if (!dev) {
retval = -ENODEV;
goto unlock_disconnect_exit;
}
if (mutex_lock_interruptible(&dev->mtx)) {
retval = -ERESTARTSYS;
goto unlock_disconnect_exit;
}
if (dev->open_count) {
retval = -EBUSY;
goto unlock_exit;
}
dev->open_count = 1;
dev->ring_head = 0;
dev->ring_tail = 0;
usb_fill_int_urb(dev->interrupt_in_urb,
interface_to_usbdev(interface),
usb_rcvintpipe(interface_to_usbdev(interface),
dev->interrupt_in_endpoint->
bEndpointAddress),
dev->interrupt_in_buffer,
dev->interrupt_in_endpoint_size,
usb_alphatrack_interrupt_in_callback, dev,
dev->interrupt_in_interval);
dev->interrupt_in_running = 1;
dev->interrupt_in_done = 0;
dev->enable = 1;
dev->offline = 0;
retval = usb_submit_urb(dev->interrupt_in_urb, GFP_KERNEL);
if (retval) {
dev_err(&interface->dev,
"Couldn't submit interrupt_in_urb %d\n", retval);
dev->interrupt_in_running = 0;
dev->open_count = 0;
goto unlock_exit;
}
file->private_data = dev;
unlock_exit:
mutex_unlock(&dev->mtx);
unlock_disconnect_exit:
mutex_unlock(&disconnect_mutex);
return retval;
}
static int usb_alphatrack_release(struct inode *inode, struct file *file)
{
struct usb_alphatrack *dev;
int retval = 0;
dev = file->private_data;
if (dev == NULL) {
retval = -ENODEV;
goto exit;
}
if (mutex_lock_interruptible(&dev->mtx)) {
retval = -ERESTARTSYS;
goto exit;
}
if (dev->open_count != 1) {
retval = -ENODEV;
goto unlock_exit;
}
if (dev->intf == NULL) {
mutex_unlock(&dev->mtx);
usb_alphatrack_delete(dev);
retval = -ENODEV;
goto exit;
}
if (dev->interrupt_out_busy)
wait_event_interruptible_timeout(dev->write_wait,
!dev->interrupt_out_busy,
2 * HZ);
usb_alphatrack_abort_transfers(dev);
dev->open_count = 0;
unlock_exit:
mutex_unlock(&dev->mtx);
exit:
return retval;
}
static unsigned int usb_alphatrack_poll(struct file *file, poll_table *wait)
{
struct usb_alphatrack *dev;
unsigned int mask = 0;
dev = file->private_data;
poll_wait(file, &dev->read_wait, wait);
poll_wait(file, &dev->write_wait, wait);
if (dev->ring_head != dev->ring_tail)
mask |= POLLIN | POLLRDNORM;
if (!dev->interrupt_out_busy)
mask |= POLLOUT | POLLWRNORM;
return mask;
}
static ssize_t usb_alphatrack_read(struct file *file, char __user *buffer,
size_t count, loff_t *ppos)
{
struct usb_alphatrack *dev;
int retval = 0;
int c = 0;
dev = file->private_data;
if (count == 0)
goto exit;
if (mutex_lock_interruptible(&dev->mtx)) {
retval = -ERESTARTSYS;
goto exit;
}
if (dev->intf == NULL) {
retval = -ENODEV;
printk(KERN_ERR "%s: No device or device unplugged %d\n",
__func__, retval);
goto unlock_exit;
}
while (dev->ring_head == dev->ring_tail) {
if (file->f_flags & O_NONBLOCK) {
retval = -EAGAIN;
goto unlock_exit;
}
dev->interrupt_in_done = 0;
retval =
wait_event_interruptible(dev->read_wait,
dev->interrupt_in_done);
if (retval < 0)
goto unlock_exit;
}
alphatrack_ocmd_info(&dev->intf->dev,
&(*dev->ring_buffer)[dev->ring_tail].cmd, "%s",
": copying to userspace");
c = 0;
while ((c < count) && (dev->ring_tail != dev->ring_head)) {
if (copy_to_user
(&buffer[c], &(*dev->ring_buffer)[dev->ring_tail],
INPUT_CMD_SIZE)) {
retval = -EFAULT;
goto unlock_exit;
}
dev->ring_tail = (dev->ring_tail + 1) % ring_buffer_size;
c += INPUT_CMD_SIZE;
dbg_info(&dev->intf->dev, "%s: head, tail are %x, %x\n",
__func__, dev->ring_head, dev->ring_tail);
}
retval = c;
unlock_exit:
mutex_unlock(&dev->mtx);
exit:
return retval;
}
static ssize_t usb_alphatrack_write(struct file *file,
const char __user *buffer, size_t count,
loff_t *ppos)
{
struct usb_alphatrack *dev;
size_t bytes_to_write;
int retval = 0;
dev = file->private_data;
if (count == 0)
goto exit;
if (mutex_lock_interruptible(&dev->mtx)) {
retval = -ERESTARTSYS;
goto exit;
}
if (dev->intf == NULL) {
retval = -ENODEV;
printk(KERN_ERR "%s: No device or device unplugged %d\n",
__func__, retval);
goto unlock_exit;
}
if (dev->interrupt_out_busy) {
if (file->f_flags & O_NONBLOCK) {
retval = -EAGAIN;
goto unlock_exit;
}
retval =
wait_event_interruptible(dev->write_wait,
!dev->interrupt_out_busy);
if (retval < 0)
goto unlock_exit;
}
bytes_to_write =
min(count, write_buffer_size * dev->interrupt_out_endpoint_size);
if (bytes_to_write < count)
dev_warn(&dev->intf->dev,
"Write buffer overflow, %zd bytes dropped\n",
count - bytes_to_write);
dbg_info(&dev->intf->dev, "%s: count = %zd, bytes_to_write = %zd\n",
__func__, count, bytes_to_write);
if (copy_from_user(dev->interrupt_out_buffer, buffer, bytes_to_write)) {
retval = -EFAULT;
goto unlock_exit;
}
if (dev->interrupt_out_endpoint == NULL) {
dev_err(&dev->intf->dev, "Endpoint should not be be null!\n");
goto unlock_exit;
}
usb_fill_int_urb(dev->interrupt_out_urb,
interface_to_usbdev(dev->intf),
usb_sndintpipe(interface_to_usbdev(dev->intf),
dev->interrupt_out_endpoint->
bEndpointAddress),
dev->interrupt_out_buffer, bytes_to_write,
usb_alphatrack_interrupt_out_callback, dev,
dev->interrupt_out_interval);
dev->interrupt_out_busy = 1;
atomic_inc(&dev->writes_pending);
wmb();
retval = usb_submit_urb(dev->interrupt_out_urb, GFP_KERNEL);
if (retval) {
dev->interrupt_out_busy = 0;
dev_err(&dev->intf->dev,
"Couldn't submit interrupt_out_urb %d\n", retval);
atomic_dec(&dev->writes_pending);
goto unlock_exit;
}
retval = bytes_to_write;
unlock_exit:
mutex_unlock(&dev->mtx);
exit:
return retval;
}
static int usb_alphatrack_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
struct usb_device *udev = interface_to_usbdev(intf);
struct usb_alphatrack *dev = NULL;
struct usb_host_interface *iface_desc;
struct usb_endpoint_descriptor *endpoint;
int i;
int true_size;
int retval = -ENOMEM;
dev = kzalloc(sizeof(*dev), GFP_KERNEL);
if (dev == NULL) {
dev_err(&intf->dev, "Out of memory\n");
goto exit;
}
mutex_init(&dev->mtx);
dev->intf = intf;
init_waitqueue_head(&dev->read_wait);
init_waitqueue_head(&dev->write_wait);
iface_desc = intf->cur_altsetting;
for (i = 0; i < iface_desc->desc.bNumEndpoints; ++i) {
endpoint = &iface_desc->endpoint[i].desc;
if (usb_endpoint_is_int_in(endpoint))
dev->interrupt_in_endpoint = endpoint;
if (usb_endpoint_is_int_out(endpoint))
dev->interrupt_out_endpoint = endpoint;
}
if (dev->interrupt_in_endpoint == NULL) {
dev_err(&intf->dev, "Interrupt in endpoint not found\n");
goto error;
}
if (dev->interrupt_out_endpoint == NULL)
dev_warn(&intf->dev,
"Interrupt out endpoint not found"
"(using control endpoint instead)\n");
dev->interrupt_in_endpoint_size =
le16_to_cpu(dev->interrupt_in_endpoint->wMaxPacketSize);
if (dev->interrupt_in_endpoint_size != 64)
dev_warn(&intf->dev, "Interrupt in endpoint size is not 64!\n");
if (ring_buffer_size == 0)
ring_buffer_size = RING_BUFFER_SIZE;
true_size = min(ring_buffer_size, RING_BUFFER_SIZE);
dev->ring_buffer =
kmalloc((true_size * sizeof(struct alphatrack_icmd)), GFP_KERNEL);
if (!dev->ring_buffer) {
dev_err(&intf->dev,
"Couldn't allocate input ring_buffer of size %d\n",
true_size);
goto error;
}
dev->interrupt_in_buffer =
kmalloc(dev->interrupt_in_endpoint_size, GFP_KERNEL);
if (!dev->interrupt_in_buffer) {
dev_err(&intf->dev, "Couldn't allocate interrupt_in_buffer\n");
goto error;
}
dev->oldi_buffer = kmalloc(dev->interrupt_in_endpoint_size, GFP_KERNEL);
if (!dev->oldi_buffer) {
dev_err(&intf->dev, "Couldn't allocate old buffer\n");
goto error;
}
dev->interrupt_in_urb = usb_alloc_urb(0, GFP_KERNEL);
if (!dev->interrupt_in_urb) {
dev_err(&intf->dev, "Couldn't allocate interrupt_in_urb\n");
goto error;
}
dev->interrupt_out_endpoint_size =
dev->interrupt_out_endpoint ? le16_to_cpu(dev->
interrupt_out_endpoint->
wMaxPacketSize) : udev->
descriptor.bMaxPacketSize0;
if (dev->interrupt_out_endpoint_size != 64)
dev_warn(&intf->dev,
"Interrupt out endpoint size is not 64!)\n");
if (write_buffer_size == 0)
write_buffer_size = WRITE_BUFFER_SIZE;
true_size = min(write_buffer_size, WRITE_BUFFER_SIZE);
dev->interrupt_out_buffer =
kmalloc(true_size * dev->interrupt_out_endpoint_size, GFP_KERNEL);
if (!dev->interrupt_out_buffer) {
dev_err(&intf->dev, "Couldn't allocate interrupt_out_buffer\n");
goto error;
}
dev->write_buffer =
kmalloc(true_size * sizeof(struct alphatrack_ocmd), GFP_KERNEL);
if (!dev->write_buffer) {
dev_err(&intf->dev, "Couldn't allocate write_buffer\n");
goto error;
}
dev->interrupt_out_urb = usb_alloc_urb(0, GFP_KERNEL);
if (!dev->interrupt_out_urb) {
dev_err(&intf->dev, "Couldn't allocate interrupt_out_urb\n");
goto error;
}
dev->interrupt_in_interval =
min_interrupt_in_interval >
dev->interrupt_in_endpoint->
bInterval ? min_interrupt_in_interval : dev->interrupt_in_endpoint->
bInterval;
if (dev->interrupt_out_endpoint)
dev->interrupt_out_interval =
min_interrupt_out_interval >
dev->interrupt_out_endpoint->
bInterval ? min_interrupt_out_interval : dev->
interrupt_out_endpoint->bInterval;
usb_set_intfdata(intf, dev);
atomic_set(&dev->writes_pending, 0);
retval = usb_register_dev(intf, &usb_alphatrack_class);
if (retval) {
dev_err(&intf->dev,
"Not able to get a minor for this device.\n");
usb_set_intfdata(intf, NULL);
goto error;
}
dev_info(&intf->dev,
"Alphatrack Device #%d now attached to major %d minor %d\n",
(intf->minor - USB_ALPHATRACK_MINOR_BASE), USB_MAJOR,
intf->minor);
exit:
return retval;
error:
usb_alphatrack_delete(dev);
return retval;
}
static void usb_alphatrack_disconnect(struct usb_interface *intf)
{
struct usb_alphatrack *dev;
int minor;
mutex_lock(&disconnect_mutex);
dev = usb_get_intfdata(intf);
usb_set_intfdata(intf, NULL);
mutex_lock(&dev->mtx);
minor = intf->minor;
usb_deregister_dev(intf, &usb_alphatrack_class);
if (!dev->open_count) {
mutex_unlock(&dev->mtx);
usb_alphatrack_delete(dev);
} else {
dev->intf = NULL;
mutex_unlock(&dev->mtx);
}
atomic_set(&dev->writes_pending, 0);
mutex_unlock(&disconnect_mutex);
dev_info(&intf->dev, "Alphatrack Surface #%d now disconnected\n",
(minor - USB_ALPHATRACK_MINOR_BASE));
}
