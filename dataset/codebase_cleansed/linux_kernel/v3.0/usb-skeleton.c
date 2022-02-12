static void skel_delete(struct kref *kref)
{
struct usb_skel *dev = to_skel_dev(kref);
usb_free_urb(dev->bulk_in_urb);
usb_put_dev(dev->udev);
kfree(dev->bulk_in_buffer);
kfree(dev);
}
static int skel_open(struct inode *inode, struct file *file)
{
struct usb_skel *dev;
struct usb_interface *interface;
int subminor;
int retval = 0;
subminor = iminor(inode);
interface = usb_find_interface(&skel_driver, subminor);
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
if (!dev->open_count++) {
retval = usb_autopm_get_interface(interface);
if (retval) {
dev->open_count--;
mutex_unlock(&dev->io_mutex);
kref_put(&dev->kref, skel_delete);
goto exit;
}
}
file->private_data = dev;
mutex_unlock(&dev->io_mutex);
exit:
return retval;
}
static int skel_release(struct inode *inode, struct file *file)
{
struct usb_skel *dev;
dev = file->private_data;
if (dev == NULL)
return -ENODEV;
mutex_lock(&dev->io_mutex);
if (!--dev->open_count && dev->interface)
usb_autopm_put_interface(dev->interface);
mutex_unlock(&dev->io_mutex);
kref_put(&dev->kref, skel_delete);
return 0;
}
static int skel_flush(struct file *file, fl_owner_t id)
{
struct usb_skel *dev;
int res;
dev = file->private_data;
if (dev == NULL)
return -ENODEV;
mutex_lock(&dev->io_mutex);
skel_draw_down(dev);
spin_lock_irq(&dev->err_lock);
res = dev->errors ? (dev->errors == -EPIPE ? -EPIPE : -EIO) : 0;
dev->errors = 0;
spin_unlock_irq(&dev->err_lock);
mutex_unlock(&dev->io_mutex);
return res;
}
static void skel_read_bulk_callback(struct urb *urb)
{
struct usb_skel *dev;
dev = urb->context;
spin_lock(&dev->err_lock);
if (urb->status) {
if (!(urb->status == -ENOENT ||
urb->status == -ECONNRESET ||
urb->status == -ESHUTDOWN))
err("%s - nonzero write bulk status received: %d",
__func__, urb->status);
dev->errors = urb->status;
} else {
dev->bulk_in_filled = urb->actual_length;
}
dev->ongoing_read = 0;
spin_unlock(&dev->err_lock);
complete(&dev->bulk_in_completion);
}
static int skel_do_read_io(struct usb_skel *dev, size_t count)
{
int rv;
usb_fill_bulk_urb(dev->bulk_in_urb,
dev->udev,
usb_rcvbulkpipe(dev->udev,
dev->bulk_in_endpointAddr),
dev->bulk_in_buffer,
min(dev->bulk_in_size, count),
skel_read_bulk_callback,
dev);
spin_lock_irq(&dev->err_lock);
dev->ongoing_read = 1;
spin_unlock_irq(&dev->err_lock);
rv = usb_submit_urb(dev->bulk_in_urb, GFP_KERNEL);
if (rv < 0) {
err("%s - failed submitting read urb, error %d",
__func__, rv);
dev->bulk_in_filled = 0;
rv = (rv == -ENOMEM) ? rv : -EIO;
spin_lock_irq(&dev->err_lock);
dev->ongoing_read = 0;
spin_unlock_irq(&dev->err_lock);
}
return rv;
}
static ssize_t skel_read(struct file *file, char *buffer, size_t count,
loff_t *ppos)
{
struct usb_skel *dev;
int rv;
bool ongoing_io;
dev = file->private_data;
if (!dev->bulk_in_urb || !count)
return 0;
rv = mutex_lock_interruptible(&dev->io_mutex);
if (rv < 0)
return rv;
if (!dev->interface) {
rv = -ENODEV;
goto exit;
}
retry:
spin_lock_irq(&dev->err_lock);
ongoing_io = dev->ongoing_read;
spin_unlock_irq(&dev->err_lock);
if (ongoing_io) {
if (file->f_flags & O_NONBLOCK) {
rv = -EAGAIN;
goto exit;
}
rv = wait_for_completion_interruptible(&dev->bulk_in_completion);
if (rv < 0)
goto exit;
dev->bulk_in_copied = 0;
dev->processed_urb = 1;
}
if (!dev->processed_urb) {
wait_for_completion(&dev->bulk_in_completion);
dev->bulk_in_copied = 0;
dev->processed_urb = 1;
}
rv = dev->errors;
if (rv < 0) {
dev->errors = 0;
rv = (rv == -EPIPE) ? rv : -EIO;
dev->bulk_in_filled = 0;
goto exit;
}
if (dev->bulk_in_filled) {
size_t available = dev->bulk_in_filled - dev->bulk_in_copied;
size_t chunk = min(available, count);
if (!available) {
rv = skel_do_read_io(dev, count);
if (rv < 0)
goto exit;
else
goto retry;
}
if (copy_to_user(buffer,
dev->bulk_in_buffer + dev->bulk_in_copied,
chunk))
rv = -EFAULT;
else
rv = chunk;
dev->bulk_in_copied += chunk;
if (available < count)
skel_do_read_io(dev, count - chunk);
} else {
rv = skel_do_read_io(dev, count);
if (rv < 0)
goto exit;
else if (!(file->f_flags & O_NONBLOCK))
goto retry;
rv = -EAGAIN;
}
exit:
mutex_unlock(&dev->io_mutex);
return rv;
}
static void skel_write_bulk_callback(struct urb *urb)
{
struct usb_skel *dev;
dev = urb->context;
if (urb->status) {
if (!(urb->status == -ENOENT ||
urb->status == -ECONNRESET ||
urb->status == -ESHUTDOWN))
err("%s - nonzero write bulk status received: %d",
__func__, urb->status);
spin_lock(&dev->err_lock);
dev->errors = urb->status;
spin_unlock(&dev->err_lock);
}
usb_free_coherent(urb->dev, urb->transfer_buffer_length,
urb->transfer_buffer, urb->transfer_dma);
up(&dev->limit_sem);
}
static ssize_t skel_write(struct file *file, const char *user_buffer,
size_t count, loff_t *ppos)
{
struct usb_skel *dev;
int retval = 0;
struct urb *urb = NULL;
char *buf = NULL;
size_t writesize = min(count, (size_t)MAX_TRANSFER);
dev = file->private_data;
if (count == 0)
goto exit;
if (!(file->f_flags & O_NONBLOCK)) {
if (down_interruptible(&dev->limit_sem)) {
retval = -ERESTARTSYS;
goto exit;
}
} else {
if (down_trylock(&dev->limit_sem)) {
retval = -EAGAIN;
goto exit;
}
}
spin_lock_irq(&dev->err_lock);
retval = dev->errors;
if (retval < 0) {
dev->errors = 0;
retval = (retval == -EPIPE) ? retval : -EIO;
}
spin_unlock_irq(&dev->err_lock);
if (retval < 0)
goto error;
urb = usb_alloc_urb(0, GFP_KERNEL);
if (!urb) {
retval = -ENOMEM;
goto error;
}
buf = usb_alloc_coherent(dev->udev, writesize, GFP_KERNEL,
&urb->transfer_dma);
if (!buf) {
retval = -ENOMEM;
goto error;
}
if (copy_from_user(buf, user_buffer, writesize)) {
retval = -EFAULT;
goto error;
}
mutex_lock(&dev->io_mutex);
if (!dev->interface) {
mutex_unlock(&dev->io_mutex);
retval = -ENODEV;
goto error;
}
usb_fill_bulk_urb(urb, dev->udev,
usb_sndbulkpipe(dev->udev, dev->bulk_out_endpointAddr),
buf, writesize, skel_write_bulk_callback, dev);
urb->transfer_flags |= URB_NO_TRANSFER_DMA_MAP;
usb_anchor_urb(urb, &dev->submitted);
retval = usb_submit_urb(urb, GFP_KERNEL);
mutex_unlock(&dev->io_mutex);
if (retval) {
err("%s - failed submitting write urb, error %d", __func__,
retval);
goto error_unanchor;
}
usb_free_urb(urb);
return writesize;
error_unanchor:
usb_unanchor_urb(urb);
error:
if (urb) {
usb_free_coherent(dev->udev, writesize, buf, urb->transfer_dma);
usb_free_urb(urb);
}
up(&dev->limit_sem);
exit:
return retval;
}
static int skel_probe(struct usb_interface *interface,
const struct usb_device_id *id)
{
struct usb_skel *dev;
struct usb_host_interface *iface_desc;
struct usb_endpoint_descriptor *endpoint;
size_t buffer_size;
int i;
int retval = -ENOMEM;
dev = kzalloc(sizeof(*dev), GFP_KERNEL);
if (!dev) {
err("Out of memory");
goto error;
}
kref_init(&dev->kref);
sema_init(&dev->limit_sem, WRITES_IN_FLIGHT);
mutex_init(&dev->io_mutex);
spin_lock_init(&dev->err_lock);
init_usb_anchor(&dev->submitted);
init_completion(&dev->bulk_in_completion);
dev->udev = usb_get_dev(interface_to_usbdev(interface));
dev->interface = interface;
iface_desc = interface->cur_altsetting;
for (i = 0; i < iface_desc->desc.bNumEndpoints; ++i) {
endpoint = &iface_desc->endpoint[i].desc;
if (!dev->bulk_in_endpointAddr &&
usb_endpoint_is_bulk_in(endpoint)) {
buffer_size = le16_to_cpu(endpoint->wMaxPacketSize);
dev->bulk_in_size = buffer_size;
dev->bulk_in_endpointAddr = endpoint->bEndpointAddress;
dev->bulk_in_buffer = kmalloc(buffer_size, GFP_KERNEL);
if (!dev->bulk_in_buffer) {
err("Could not allocate bulk_in_buffer");
goto error;
}
dev->bulk_in_urb = usb_alloc_urb(0, GFP_KERNEL);
if (!dev->bulk_in_urb) {
err("Could not allocate bulk_in_urb");
goto error;
}
}
if (!dev->bulk_out_endpointAddr &&
usb_endpoint_is_bulk_out(endpoint)) {
dev->bulk_out_endpointAddr = endpoint->bEndpointAddress;
}
}
if (!(dev->bulk_in_endpointAddr && dev->bulk_out_endpointAddr)) {
err("Could not find both bulk-in and bulk-out endpoints");
goto error;
}
usb_set_intfdata(interface, dev);
retval = usb_register_dev(interface, &skel_class);
if (retval) {
err("Not able to get a minor for this device.");
usb_set_intfdata(interface, NULL);
goto error;
}
dev_info(&interface->dev,
"USB Skeleton device now attached to USBSkel-%d",
interface->minor);
return 0;
error:
if (dev)
kref_put(&dev->kref, skel_delete);
return retval;
}
static void skel_disconnect(struct usb_interface *interface)
{
struct usb_skel *dev;
int minor = interface->minor;
dev = usb_get_intfdata(interface);
usb_set_intfdata(interface, NULL);
usb_deregister_dev(interface, &skel_class);
mutex_lock(&dev->io_mutex);
dev->interface = NULL;
mutex_unlock(&dev->io_mutex);
usb_kill_anchored_urbs(&dev->submitted);
kref_put(&dev->kref, skel_delete);
dev_info(&interface->dev, "USB Skeleton #%d now disconnected", minor);
}
static void skel_draw_down(struct usb_skel *dev)
{
int time;
time = usb_wait_anchor_empty_timeout(&dev->submitted, 1000);
if (!time)
usb_kill_anchored_urbs(&dev->submitted);
usb_kill_urb(dev->bulk_in_urb);
}
static int skel_suspend(struct usb_interface *intf, pm_message_t message)
{
struct usb_skel *dev = usb_get_intfdata(intf);
if (!dev)
return 0;
skel_draw_down(dev);
return 0;
}
static int skel_resume(struct usb_interface *intf)
{
return 0;
}
static int skel_pre_reset(struct usb_interface *intf)
{
struct usb_skel *dev = usb_get_intfdata(intf);
mutex_lock(&dev->io_mutex);
skel_draw_down(dev);
return 0;
}
static int skel_post_reset(struct usb_interface *intf)
{
struct usb_skel *dev = usb_get_intfdata(intf);
dev->errors = -EPIPE;
mutex_unlock(&dev->io_mutex);
return 0;
}
static int __init usb_skel_init(void)
{
int result;
result = usb_register(&skel_driver);
if (result)
err("usb_register failed. Error number %d", result);
return result;
}
static void __exit usb_skel_exit(void)
{
usb_deregister(&skel_driver);
}
