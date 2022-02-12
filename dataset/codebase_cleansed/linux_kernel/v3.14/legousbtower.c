static char *legousbtower_devnode(struct device *dev, umode_t *mode)
{
return kasprintf(GFP_KERNEL, "usb/%s", dev_name(dev));
}
static inline void lego_usb_tower_debug_data(struct device *dev,
const char *function, int size,
const unsigned char *data)
{
dev_dbg(dev, "%s - length = %d, data = %*ph\n",
function, size, size, data);
}
static inline void tower_delete (struct lego_usb_tower *dev)
{
tower_abort_transfers (dev);
usb_free_urb(dev->interrupt_in_urb);
usb_free_urb(dev->interrupt_out_urb);
kfree (dev->read_buffer);
kfree (dev->interrupt_in_buffer);
kfree (dev->interrupt_out_buffer);
kfree (dev);
}
static int tower_open (struct inode *inode, struct file *file)
{
struct lego_usb_tower *dev = NULL;
int subminor;
int retval = 0;
struct usb_interface *interface;
struct tower_reset_reply reset_reply;
int result;
nonseekable_open(inode, file);
subminor = iminor(inode);
interface = usb_find_interface (&tower_driver, subminor);
if (!interface) {
pr_err("error, can't find device for minor %d\n", subminor);
retval = -ENODEV;
goto exit;
}
mutex_lock(&open_disc_mutex);
dev = usb_get_intfdata(interface);
if (!dev) {
mutex_unlock(&open_disc_mutex);
retval = -ENODEV;
goto exit;
}
if (mutex_lock_interruptible(&dev->lock)) {
mutex_unlock(&open_disc_mutex);
retval = -ERESTARTSYS;
goto exit;
}
if (dev->open_count) {
mutex_unlock(&open_disc_mutex);
retval = -EBUSY;
goto unlock_exit;
}
dev->open_count = 1;
mutex_unlock(&open_disc_mutex);
result = usb_control_msg (dev->udev,
usb_rcvctrlpipe(dev->udev, 0),
LEGO_USB_TOWER_REQUEST_RESET,
USB_TYPE_VENDOR | USB_DIR_IN | USB_RECIP_DEVICE,
0,
0,
&reset_reply,
sizeof(reset_reply),
1000);
if (result < 0) {
dev_err(&dev->udev->dev,
"LEGO USB Tower reset control request failed\n");
retval = result;
goto unlock_exit;
}
dev->read_buffer_length = 0;
dev->read_packet_length = 0;
usb_fill_int_urb (dev->interrupt_in_urb,
dev->udev,
usb_rcvintpipe(dev->udev, dev->interrupt_in_endpoint->bEndpointAddress),
dev->interrupt_in_buffer,
usb_endpoint_maxp(dev->interrupt_in_endpoint),
tower_interrupt_in_callback,
dev,
dev->interrupt_in_interval);
dev->interrupt_in_running = 1;
dev->interrupt_in_done = 0;
mb();
retval = usb_submit_urb (dev->interrupt_in_urb, GFP_KERNEL);
if (retval) {
dev_err(&dev->udev->dev,
"Couldn't submit interrupt_in_urb %d\n", retval);
dev->interrupt_in_running = 0;
dev->open_count = 0;
goto unlock_exit;
}
file->private_data = dev;
unlock_exit:
mutex_unlock(&dev->lock);
exit:
return retval;
}
static int tower_release (struct inode *inode, struct file *file)
{
struct lego_usb_tower *dev;
int retval = 0;
dev = file->private_data;
if (dev == NULL) {
retval = -ENODEV;
goto exit_nolock;
}
mutex_lock(&open_disc_mutex);
if (mutex_lock_interruptible(&dev->lock)) {
retval = -ERESTARTSYS;
goto exit;
}
if (dev->open_count != 1) {
dev_dbg(&dev->udev->dev, "%s: device not opened exactly once\n",
__func__);
retval = -ENODEV;
goto unlock_exit;
}
if (dev->udev == NULL) {
mutex_unlock(&dev->lock);
tower_delete (dev);
goto exit;
}
if (dev->interrupt_out_busy) {
wait_event_interruptible_timeout (dev->write_wait, !dev->interrupt_out_busy, 2 * HZ);
}
tower_abort_transfers (dev);
dev->open_count = 0;
unlock_exit:
mutex_unlock(&dev->lock);
exit:
mutex_unlock(&open_disc_mutex);
exit_nolock:
return retval;
}
static void tower_abort_transfers (struct lego_usb_tower *dev)
{
if (dev == NULL)
return;
if (dev->interrupt_in_running) {
dev->interrupt_in_running = 0;
mb();
if (dev->udev)
usb_kill_urb (dev->interrupt_in_urb);
}
if (dev->interrupt_out_busy && dev->udev)
usb_kill_urb(dev->interrupt_out_urb);
}
static void tower_check_for_read_packet (struct lego_usb_tower *dev)
{
spin_lock_irq (&dev->read_buffer_lock);
if (!packet_timeout
|| time_after(jiffies, dev->read_last_arrival + dev->packet_timeout_jiffies)
|| dev->read_buffer_length == read_buffer_size) {
dev->read_packet_length = dev->read_buffer_length;
}
dev->interrupt_in_done = 0;
spin_unlock_irq (&dev->read_buffer_lock);
}
static unsigned int tower_poll (struct file *file, poll_table *wait)
{
struct lego_usb_tower *dev;
unsigned int mask = 0;
dev = file->private_data;
if (!dev->udev)
return POLLERR | POLLHUP;
poll_wait(file, &dev->read_wait, wait);
poll_wait(file, &dev->write_wait, wait);
tower_check_for_read_packet(dev);
if (dev->read_packet_length > 0) {
mask |= POLLIN | POLLRDNORM;
}
if (!dev->interrupt_out_busy) {
mask |= POLLOUT | POLLWRNORM;
}
return mask;
}
static loff_t tower_llseek (struct file *file, loff_t off, int whence)
{
return -ESPIPE;
}
static ssize_t tower_read (struct file *file, char __user *buffer, size_t count, loff_t *ppos)
{
struct lego_usb_tower *dev;
size_t bytes_to_read;
int i;
int retval = 0;
unsigned long timeout = 0;
dev = file->private_data;
if (mutex_lock_interruptible(&dev->lock)) {
retval = -ERESTARTSYS;
goto exit;
}
if (dev->udev == NULL) {
retval = -ENODEV;
pr_err("No device or device unplugged %d\n", retval);
goto unlock_exit;
}
if (count == 0) {
dev_dbg(&dev->udev->dev, "read request of 0 bytes\n");
goto unlock_exit;
}
if (read_timeout) {
timeout = jiffies + read_timeout * HZ / 1000;
}
tower_check_for_read_packet (dev);
while (dev->read_packet_length == 0) {
if (file->f_flags & O_NONBLOCK) {
retval = -EAGAIN;
goto unlock_exit;
}
retval = wait_event_interruptible_timeout(dev->read_wait, dev->interrupt_in_done, dev->packet_timeout_jiffies);
if (retval < 0) {
goto unlock_exit;
}
if (read_timeout
&& (dev->read_buffer_length || dev->interrupt_out_busy)) {
timeout = jiffies + read_timeout * HZ / 1000;
}
if (read_timeout && time_after (jiffies, timeout)) {
retval = -ETIMEDOUT;
goto unlock_exit;
}
tower_check_for_read_packet (dev);
}
bytes_to_read = min(count, dev->read_packet_length);
if (copy_to_user (buffer, dev->read_buffer, bytes_to_read)) {
retval = -EFAULT;
goto unlock_exit;
}
spin_lock_irq (&dev->read_buffer_lock);
dev->read_buffer_length -= bytes_to_read;
dev->read_packet_length -= bytes_to_read;
for (i=0; i<dev->read_buffer_length; i++) {
dev->read_buffer[i] = dev->read_buffer[i+bytes_to_read];
}
spin_unlock_irq (&dev->read_buffer_lock);
retval = bytes_to_read;
unlock_exit:
mutex_unlock(&dev->lock);
exit:
return retval;
}
static ssize_t tower_write (struct file *file, const char __user *buffer, size_t count, loff_t *ppos)
{
struct lego_usb_tower *dev;
size_t bytes_to_write;
int retval = 0;
dev = file->private_data;
if (mutex_lock_interruptible(&dev->lock)) {
retval = -ERESTARTSYS;
goto exit;
}
if (dev->udev == NULL) {
retval = -ENODEV;
pr_err("No device or device unplugged %d\n", retval);
goto unlock_exit;
}
if (count == 0) {
dev_dbg(&dev->udev->dev, "write request of 0 bytes\n");
goto unlock_exit;
}
while (dev->interrupt_out_busy) {
if (file->f_flags & O_NONBLOCK) {
retval = -EAGAIN;
goto unlock_exit;
}
retval = wait_event_interruptible (dev->write_wait, !dev->interrupt_out_busy);
if (retval) {
goto unlock_exit;
}
}
bytes_to_write = min_t(int, count, write_buffer_size);
dev_dbg(&dev->udev->dev, "%s: count = %Zd, bytes_to_write = %Zd\n",
__func__, count, bytes_to_write);
if (copy_from_user (dev->interrupt_out_buffer, buffer, bytes_to_write)) {
retval = -EFAULT;
goto unlock_exit;
}
usb_fill_int_urb(dev->interrupt_out_urb,
dev->udev,
usb_sndintpipe(dev->udev, dev->interrupt_out_endpoint->bEndpointAddress),
dev->interrupt_out_buffer,
bytes_to_write,
tower_interrupt_out_callback,
dev,
dev->interrupt_out_interval);
dev->interrupt_out_busy = 1;
wmb();
retval = usb_submit_urb (dev->interrupt_out_urb, GFP_KERNEL);
if (retval) {
dev->interrupt_out_busy = 0;
dev_err(&dev->udev->dev,
"Couldn't submit interrupt_out_urb %d\n", retval);
goto unlock_exit;
}
retval = bytes_to_write;
unlock_exit:
mutex_unlock(&dev->lock);
exit:
return retval;
}
static void tower_interrupt_in_callback (struct urb *urb)
{
struct lego_usb_tower *dev = urb->context;
int status = urb->status;
int retval;
lego_usb_tower_debug_data(&dev->udev->dev, __func__,
urb->actual_length, urb->transfer_buffer);
if (status) {
if (status == -ENOENT ||
status == -ECONNRESET ||
status == -ESHUTDOWN) {
goto exit;
} else {
dev_dbg(&dev->udev->dev,
"%s: nonzero status received: %d\n", __func__,
status);
goto resubmit;
}
}
if (urb->actual_length > 0) {
spin_lock (&dev->read_buffer_lock);
if (dev->read_buffer_length + urb->actual_length < read_buffer_size) {
memcpy (dev->read_buffer + dev->read_buffer_length,
dev->interrupt_in_buffer,
urb->actual_length);
dev->read_buffer_length += urb->actual_length;
dev->read_last_arrival = jiffies;
dev_dbg(&dev->udev->dev, "%s: received %d bytes\n",
__func__, urb->actual_length);
} else {
pr_warn("read_buffer overflow, %d bytes dropped\n",
urb->actual_length);
}
spin_unlock (&dev->read_buffer_lock);
}
resubmit:
if (dev->interrupt_in_running && dev->udev) {
retval = usb_submit_urb (dev->interrupt_in_urb, GFP_ATOMIC);
if (retval)
dev_err(&dev->udev->dev,
"%s: usb_submit_urb failed (%d)\n",
__func__, retval);
}
exit:
dev->interrupt_in_done = 1;
wake_up_interruptible (&dev->read_wait);
}
static void tower_interrupt_out_callback (struct urb *urb)
{
struct lego_usb_tower *dev = urb->context;
int status = urb->status;
lego_usb_tower_debug_data(&dev->udev->dev, __func__,
urb->actual_length, urb->transfer_buffer);
if (status && !(status == -ENOENT ||
status == -ECONNRESET ||
status == -ESHUTDOWN)) {
dev_dbg(&dev->udev->dev,
"%s: nonzero write bulk status received: %d\n", __func__,
status);
}
dev->interrupt_out_busy = 0;
wake_up_interruptible(&dev->write_wait);
}
static int tower_probe (struct usb_interface *interface, const struct usb_device_id *id)
{
struct device *idev = &interface->dev;
struct usb_device *udev = interface_to_usbdev(interface);
struct lego_usb_tower *dev = NULL;
struct usb_host_interface *iface_desc;
struct usb_endpoint_descriptor* endpoint;
struct tower_get_version_reply get_version_reply;
int i;
int retval = -ENOMEM;
int result;
dev = kmalloc (sizeof(struct lego_usb_tower), GFP_KERNEL);
if (dev == NULL) {
dev_err(idev, "Out of memory\n");
goto exit;
}
mutex_init(&dev->lock);
dev->udev = udev;
dev->open_count = 0;
dev->read_buffer = NULL;
dev->read_buffer_length = 0;
dev->read_packet_length = 0;
spin_lock_init (&dev->read_buffer_lock);
dev->packet_timeout_jiffies = packet_timeout * HZ / 1000;
dev->read_last_arrival = jiffies;
init_waitqueue_head (&dev->read_wait);
init_waitqueue_head (&dev->write_wait);
dev->interrupt_in_buffer = NULL;
dev->interrupt_in_endpoint = NULL;
dev->interrupt_in_urb = NULL;
dev->interrupt_in_running = 0;
dev->interrupt_in_done = 0;
dev->interrupt_out_buffer = NULL;
dev->interrupt_out_endpoint = NULL;
dev->interrupt_out_urb = NULL;
dev->interrupt_out_busy = 0;
iface_desc = interface->cur_altsetting;
for (i = 0; i < iface_desc->desc.bNumEndpoints; ++i) {
endpoint = &iface_desc->endpoint[i].desc;
if (usb_endpoint_xfer_int(endpoint)) {
if (usb_endpoint_dir_in(endpoint))
dev->interrupt_in_endpoint = endpoint;
else
dev->interrupt_out_endpoint = endpoint;
}
}
if(dev->interrupt_in_endpoint == NULL) {
dev_err(idev, "interrupt in endpoint not found\n");
goto error;
}
if (dev->interrupt_out_endpoint == NULL) {
dev_err(idev, "interrupt out endpoint not found\n");
goto error;
}
dev->read_buffer = kmalloc (read_buffer_size, GFP_KERNEL);
if (!dev->read_buffer) {
dev_err(idev, "Couldn't allocate read_buffer\n");
goto error;
}
dev->interrupt_in_buffer = kmalloc (usb_endpoint_maxp(dev->interrupt_in_endpoint), GFP_KERNEL);
if (!dev->interrupt_in_buffer) {
dev_err(idev, "Couldn't allocate interrupt_in_buffer\n");
goto error;
}
dev->interrupt_in_urb = usb_alloc_urb(0, GFP_KERNEL);
if (!dev->interrupt_in_urb) {
dev_err(idev, "Couldn't allocate interrupt_in_urb\n");
goto error;
}
dev->interrupt_out_buffer = kmalloc (write_buffer_size, GFP_KERNEL);
if (!dev->interrupt_out_buffer) {
dev_err(idev, "Couldn't allocate interrupt_out_buffer\n");
goto error;
}
dev->interrupt_out_urb = usb_alloc_urb(0, GFP_KERNEL);
if (!dev->interrupt_out_urb) {
dev_err(idev, "Couldn't allocate interrupt_out_urb\n");
goto error;
}
dev->interrupt_in_interval = interrupt_in_interval ? interrupt_in_interval : dev->interrupt_in_endpoint->bInterval;
dev->interrupt_out_interval = interrupt_out_interval ? interrupt_out_interval : dev->interrupt_out_endpoint->bInterval;
usb_set_intfdata (interface, dev);
retval = usb_register_dev (interface, &tower_class);
if (retval) {
dev_err(idev, "Not able to get a minor for this device.\n");
usb_set_intfdata (interface, NULL);
goto error;
}
dev->minor = interface->minor;
dev_info(&interface->dev, "LEGO USB Tower #%d now attached to major "
"%d minor %d\n", (dev->minor - LEGO_USB_TOWER_MINOR_BASE),
USB_MAJOR, dev->minor);
result = usb_control_msg (udev,
usb_rcvctrlpipe(udev, 0),
LEGO_USB_TOWER_REQUEST_GET_VERSION,
USB_TYPE_VENDOR | USB_DIR_IN | USB_RECIP_DEVICE,
0,
0,
&get_version_reply,
sizeof(get_version_reply),
1000);
if (result < 0) {
dev_err(idev, "LEGO USB Tower get version control request failed\n");
retval = result;
goto error;
}
dev_info(&interface->dev, "LEGO USB Tower firmware version is %d.%d "
"build %d\n", get_version_reply.major,
get_version_reply.minor,
le16_to_cpu(get_version_reply.build_no));
exit:
return retval;
error:
tower_delete(dev);
return retval;
}
static void tower_disconnect (struct usb_interface *interface)
{
struct lego_usb_tower *dev;
int minor;
dev = usb_get_intfdata (interface);
mutex_lock(&open_disc_mutex);
usb_set_intfdata (interface, NULL);
minor = dev->minor;
usb_deregister_dev (interface, &tower_class);
mutex_lock(&dev->lock);
mutex_unlock(&open_disc_mutex);
if (!dev->open_count) {
mutex_unlock(&dev->lock);
tower_delete (dev);
} else {
dev->udev = NULL;
wake_up_interruptible_all(&dev->read_wait);
wake_up_interruptible_all(&dev->write_wait);
mutex_unlock(&dev->lock);
}
dev_info(&interface->dev, "LEGO USB Tower #%d now disconnected\n",
(minor - LEGO_USB_TOWER_MINOR_BASE));
}
