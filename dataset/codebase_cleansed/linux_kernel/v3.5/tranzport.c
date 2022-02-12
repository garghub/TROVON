static void usb_tranzport_abort_transfers(struct usb_tranzport *dev)
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
static void usb_tranzport_delete(struct usb_tranzport *dev)
{
usb_tranzport_abort_transfers(dev);
if (dev->intf != NULL) {
device_remove_file(&dev->intf->dev, &dev_attr_enable);
device_remove_file(&dev->intf->dev, &dev_attr_offline);
device_remove_file(&dev->intf->dev, &dev_attr_compress_wheel);
}
usb_free_urb(dev->interrupt_in_urb);
usb_free_urb(dev->interrupt_out_urb);
kfree(dev->ring_buffer);
kfree(dev->interrupt_in_buffer);
kfree(dev->interrupt_out_buffer);
kfree(dev);
}
static void usb_tranzport_interrupt_in_callback(struct urb *urb)
{
struct usb_tranzport *dev = urb->context;
unsigned int next_ring_head;
int retval = -1;
if (urb->status) {
if (urb->status == -ENOENT ||
urb->status == -ECONNRESET ||
urb->status == -ESHUTDOWN) {
goto exit;
} else {
dbg_info(&dev->intf->dev,
"%s: nonzero status received: %d\n",
__func__, urb->status);
goto resubmit;
}
}
if (urb->actual_length != 8) {
dev_warn(&dev->intf->dev,
"Urb length was %d bytes!!"
"Do something intelligent\n",
urb->actual_length);
} else {
dbg_info(&dev->intf->dev,
"%s: received: %02x%02x%02x%02x%02x%02x%02x%02x\n",
__func__, dev->interrupt_in_buffer[0],
dev->interrupt_in_buffer[1],
dev->interrupt_in_buffer[2],
dev->interrupt_in_buffer[3],
dev->interrupt_in_buffer[4],
dev->interrupt_in_buffer[5],
dev->interrupt_in_buffer[6],
dev->interrupt_in_buffer[7]);
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
static void usb_tranzport_interrupt_out_callback(struct urb *urb)
{
struct usb_tranzport *dev = urb->context;
if (urb->status && !(urb->status == -ENOENT ||
urb->status == -ECONNRESET ||
urb->status == -ESHUTDOWN))
dbg_info(&dev->intf->dev,
"%s - nonzero write interrupt status received: %d\n",
__func__, urb->status);
dev->interrupt_out_busy = 0;
wake_up_interruptible(&dev->write_wait);
}
static int usb_tranzport_open(struct inode *inode, struct file *file)
{
struct usb_tranzport *dev;
int subminor;
int retval = 0;
struct usb_interface *interface;
nonseekable_open(inode, file);
subminor = iminor(inode);
mutex_lock(&disconnect_mutex);
interface = usb_find_interface(&usb_tranzport_driver, subminor);
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
usb_tranzport_interrupt_in_callback, dev,
dev->interrupt_in_interval);
dev->interrupt_in_running = 1;
dev->interrupt_in_done = 0;
dev->enable = 1;
dev->offline = 0;
dev->compress_wheel = 1;
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
static int usb_tranzport_release(struct inode *inode, struct file *file)
{
struct usb_tranzport *dev;
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
usb_tranzport_delete(dev);
retval = -ENODEV;
goto exit;
}
if (dev->interrupt_out_busy)
wait_event_interruptible_timeout(dev->write_wait,
!dev->interrupt_out_busy,
2 * HZ);
usb_tranzport_abort_transfers(dev);
dev->open_count = 0;
unlock_exit:
mutex_unlock(&dev->mtx);
exit:
return retval;
}
static unsigned int usb_tranzport_poll(struct file *file, poll_table *wait)
{
struct usb_tranzport *dev;
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
static ssize_t usb_tranzport_read(struct file *file, char __user *buffer,
size_t count, loff_t *ppos)
{
struct usb_tranzport *dev;
int retval = 0;
#if BUFFERED_READS
int c = 0;
#endif
#if COMPRESS_WHEEL_EVENTS
signed char oldwheel;
signed char newwheel;
int cancompress = 1;
int next_tail;
#endif
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
retval = wait_event_interruptible(dev->read_wait,
dev->interrupt_in_done);
if (retval < 0)
goto unlock_exit;
}
dbg_info(&dev->intf->dev,
"%s: copying to userspace: "
"%02x%02x%02x%02x%02x%02x%02x%02x\n",
__func__,
(*dev->ring_buffer)[dev->ring_tail].cmd[0],
(*dev->ring_buffer)[dev->ring_tail].cmd[1],
(*dev->ring_buffer)[dev->ring_tail].cmd[2],
(*dev->ring_buffer)[dev->ring_tail].cmd[3],
(*dev->ring_buffer)[dev->ring_tail].cmd[4],
(*dev->ring_buffer)[dev->ring_tail].cmd[5],
(*dev->ring_buffer)[dev->ring_tail].cmd[6],
(*dev->ring_buffer)[dev->ring_tail].cmd[7]);
#if BUFFERED_READS
c = 0;
while ((c < count) && (dev->ring_tail != dev->ring_head)) {
#if COMPRESS_WHEEL_EVENTS
next_tail = (dev->ring_tail+1) % ring_buffer_size;
if (dev->compress_wheel)
cancompress = 1;
while (dev->ring_head != next_tail && cancompress == 1) {
newwheel = (*dev->ring_buffer)[next_tail].cmd[6];
oldwheel = (*dev->ring_buffer)[dev->ring_tail].cmd[6];
dbg_info(&dev->intf->dev,
"%s: trying to compress: "
"%02x%02x%02x%02x%02x%02x%02x%02x\n",
__func__,
(*dev->ring_buffer)[dev->ring_tail].cmd[0],
(*dev->ring_buffer)[dev->ring_tail].cmd[1],
(*dev->ring_buffer)[dev->ring_tail].cmd[2],
(*dev->ring_buffer)[dev->ring_tail].cmd[3],
(*dev->ring_buffer)[dev->ring_tail].cmd[4],
(*dev->ring_buffer)[dev->ring_tail].cmd[5],
(*dev->ring_buffer)[dev->ring_tail].cmd[6],
(*dev->ring_buffer)[dev->ring_tail].cmd[7]);
if (((*dev->ring_buffer)[dev->ring_tail].cmd[6] != 0 &&
(*dev->ring_buffer)[next_tail].cmd[6] != 0) &&
((newwheel > 0 && oldwheel > 0) ||
(newwheel < 0 && oldwheel < 0)) &&
((*dev->ring_buffer)[dev->ring_tail].cmd[2] ==
(*dev->ring_buffer)[next_tail].cmd[2]) &&
((*dev->ring_buffer)[dev->ring_tail].cmd[3] ==
(*dev->ring_buffer)[next_tail].cmd[3]) &&
((*dev->ring_buffer)[dev->ring_tail].cmd[4] ==
(*dev->ring_buffer)[next_tail].cmd[4]) &&
((*dev->ring_buffer)[dev->ring_tail].cmd[5] ==
(*dev->ring_buffer)[next_tail].cmd[5])) {
dbg_info(&dev->intf->dev,
"%s: should compress: "
"%02x%02x%02x%02x%02x%02x%02x%02x\n",
__func__,
(*dev->ring_buffer)[dev->ring_tail].
cmd[0],
(*dev->ring_buffer)[dev->ring_tail].
cmd[1],
(*dev->ring_buffer)[dev->ring_tail].
cmd[2],
(*dev->ring_buffer)[dev->ring_tail].
cmd[3],
(*dev->ring_buffer)[dev->ring_tail].
cmd[4],
(*dev->ring_buffer)[dev->ring_tail].
cmd[5],
(*dev->ring_buffer)[dev->ring_tail].
cmd[6],
(*dev->ring_buffer)[dev->ring_tail].
cmd[7]);
newwheel += oldwheel;
if (oldwheel > 0 && !(newwheel > 0)) {
newwheel = 0x7f;
cancompress = 0;
}
if (oldwheel < 0 && !(newwheel < 0)) {
newwheel = 0x80;
cancompress = 0;
}
(*dev->ring_buffer)[next_tail].cmd[6] =
newwheel;
dev->ring_tail = next_tail;
next_tail =
(dev->ring_tail + 1) % ring_buffer_size;
} else {
cancompress = 0;
}
}
#endif
if (copy_to_user(
&buffer[c],
&(*dev->ring_buffer)[dev->ring_tail], 8)) {
retval = -EFAULT;
goto unlock_exit;
}
dev->ring_tail = (dev->ring_tail + 1) % ring_buffer_size;
c += 8;
dbg_info(&dev->intf->dev,
"%s: head, tail are %x, %x\n",
__func__, dev->ring_head, dev->ring_tail);
}
retval = c;
#else
retval = -EFAULT;
goto unlock_exit;
}
ssize_t usb_tranzport_write(struct file *file,
const char __user *buffer, size_t count,
loff_t *ppos)
{
struct usb_tranzport *dev;
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
retval = wait_event_interruptible(dev->write_wait,
!dev->interrupt_out_busy);
if (retval < 0)
goto unlock_exit;
}
bytes_to_write = min(count,
write_buffer_size *
dev->interrupt_out_endpoint_size);
if (bytes_to_write < count)
dev_warn(&dev->intf->dev,
"Write buffer overflow, %zd bytes dropped\n",
count - bytes_to_write);
dbg_info(&dev->intf->dev,
"%s: count = %zd, bytes_to_write = %zd\n", __func__,
count, bytes_to_write);
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
usb_tranzport_interrupt_out_callback, dev,
dev->interrupt_out_interval);
dev->interrupt_out_busy = 1;
wmb();
retval = usb_submit_urb(dev->interrupt_out_urb, GFP_KERNEL);
if (retval) {
dev->interrupt_out_busy = 0;
dev_err(&dev->intf->dev,
"Couldn't submit interrupt_out_urb %d\n", retval);
goto unlock_exit;
}
retval = bytes_to_write;
unlock_exit:
mutex_unlock(&dev->mtx);
exit:
return retval;
}
static int usb_tranzport_probe(struct usb_interface *intf,
const struct usb_device_id *id) {
struct usb_device *udev = interface_to_usbdev(intf);
struct usb_tranzport *dev = NULL;
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
if (dev->interrupt_in_endpoint_size != 8)
dev_warn(&intf->dev, "Interrupt in endpoint size is not 8!\n");
if (ring_buffer_size == 0)
ring_buffer_size = RING_BUFFER_SIZE;
true_size = min(ring_buffer_size, RING_BUFFER_SIZE);
dev->ring_buffer =
kmalloc((true_size * sizeof(struct tranzport_cmd)) + 8, GFP_KERNEL);
if (!dev->ring_buffer) {
dev_err(&intf->dev,
"Couldn't allocate ring_buffer size %d\n", true_size);
goto error;
}
dev->interrupt_in_buffer =
kmalloc(dev->interrupt_in_endpoint_size, GFP_KERNEL);
if (!dev->interrupt_in_buffer) {
dev_err(&intf->dev, "Couldn't allocate interrupt_in_buffer\n");
goto error;
}
dev->interrupt_in_urb = usb_alloc_urb(0, GFP_KERNEL);
if (!dev->interrupt_in_urb) {
dev_err(&intf->dev, "Couldn't allocate interrupt_in_urb\n");
goto error;
}
dev->interrupt_out_endpoint_size =
dev->interrupt_out_endpoint ?
le16_to_cpu(dev->interrupt_out_endpoint->wMaxPacketSize) :
udev->descriptor.bMaxPacketSize0;
if (dev->interrupt_out_endpoint_size != 8)
dev_warn(&intf->dev,
"Interrupt out endpoint size is not 8!)\n");
dev->interrupt_out_buffer =
kmalloc(write_buffer_size * dev->interrupt_out_endpoint_size,
GFP_KERNEL);
if (!dev->interrupt_out_buffer) {
dev_err(&intf->dev, "Couldn't allocate interrupt_out_buffer\n");
goto error;
}
dev->interrupt_out_urb = usb_alloc_urb(0, GFP_KERNEL);
if (!dev->interrupt_out_urb) {
dev_err(&intf->dev, "Couldn't allocate interrupt_out_urb\n");
goto error;
}
dev->interrupt_in_interval =
min_interrupt_in_interval >
dev->interrupt_in_endpoint->bInterval ? min_interrupt_in_interval
: dev->interrupt_in_endpoint->bInterval;
if (dev->interrupt_out_endpoint) {
dev->interrupt_out_interval =
min_interrupt_out_interval >
dev->interrupt_out_endpoint->bInterval ?
min_interrupt_out_interval :
dev->interrupt_out_endpoint->bInterval;
}
usb_set_intfdata(intf, dev);
retval = usb_register_dev(intf, &usb_tranzport_class);
if (retval) {
dev_err(&intf->dev,
"Not able to get a minor for this device.\n");
usb_set_intfdata(intf, NULL);
goto error;
}
retval = device_create_file(&intf->dev, &dev_attr_compress_wheel);
if (retval)
goto error;
retval = device_create_file(&intf->dev, &dev_attr_enable);
if (retval)
goto error;
retval = device_create_file(&intf->dev, &dev_attr_offline);
if (retval)
goto error;
dev_info(&intf->dev,
"Tranzport Device #%d now attached to major %d minor %d\n",
(intf->minor - USB_TRANZPORT_MINOR_BASE), USB_MAJOR,
intf->minor);
exit:
return retval;
error:
usb_tranzport_delete(dev);
return retval;
}
static void usb_tranzport_disconnect(struct usb_interface *intf)
{
struct usb_tranzport *dev;
int minor;
mutex_lock(&disconnect_mutex);
dev = usb_get_intfdata(intf);
usb_set_intfdata(intf, NULL);
mutex_lock(&dev->mtx);
minor = intf->minor;
usb_deregister_dev(intf, &usb_tranzport_class);
if (!dev->open_count) {
mutex_unlock(&dev->mtx);
usb_tranzport_delete(dev);
} else {
dev->intf = NULL;
mutex_unlock(&dev->mtx);
}
mutex_unlock(&disconnect_mutex);
dev_info(&intf->dev, "Tranzport Surface #%d now disconnected\n",
(minor - USB_TRANZPORT_MINOR_BASE));
}
