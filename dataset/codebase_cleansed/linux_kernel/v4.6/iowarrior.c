static int usb_get_report(struct usb_device *dev,
struct usb_host_interface *inter, unsigned char type,
unsigned char id, void *buf, int size)
{
return usb_control_msg(dev, usb_rcvctrlpipe(dev, 0),
USB_REQ_GET_REPORT,
USB_DIR_IN | USB_TYPE_CLASS |
USB_RECIP_INTERFACE, (type << 8) + id,
inter->desc.bInterfaceNumber, buf, size,
GET_TIMEOUT*HZ);
}
static int usb_set_report(struct usb_interface *intf, unsigned char type,
unsigned char id, void *buf, int size)
{
return usb_control_msg(interface_to_usbdev(intf),
usb_sndctrlpipe(interface_to_usbdev(intf), 0),
USB_REQ_SET_REPORT,
USB_TYPE_CLASS | USB_RECIP_INTERFACE,
(type << 8) + id,
intf->cur_altsetting->desc.bInterfaceNumber, buf,
size, HZ);
}
static void iowarrior_callback(struct urb *urb)
{
struct iowarrior *dev = urb->context;
int intr_idx;
int read_idx;
int aux_idx;
int offset;
int status = urb->status;
int retval;
switch (status) {
case 0:
break;
case -ECONNRESET:
case -ENOENT:
case -ESHUTDOWN:
return;
default:
goto exit;
}
spin_lock(&dev->intr_idx_lock);
intr_idx = atomic_read(&dev->intr_idx);
aux_idx = (intr_idx == 0) ? (MAX_INTERRUPT_BUFFER - 1) : (intr_idx - 1);
read_idx = atomic_read(&dev->read_idx);
if ((intr_idx != read_idx)
&& (dev->interface->cur_altsetting->desc.bInterfaceNumber == 0)) {
offset = aux_idx * (dev->report_size + 1);
if (!memcmp
(dev->read_queue + offset, urb->transfer_buffer,
dev->report_size)) {
spin_unlock(&dev->intr_idx_lock);
goto exit;
}
}
aux_idx = (intr_idx == (MAX_INTERRUPT_BUFFER - 1)) ? 0 : (intr_idx + 1);
if (read_idx == aux_idx) {
read_idx = (++read_idx == MAX_INTERRUPT_BUFFER) ? 0 : read_idx;
atomic_set(&dev->read_idx, read_idx);
atomic_set(&dev->overflow_flag, 1);
}
offset = intr_idx * (dev->report_size + 1);
memcpy(dev->read_queue + offset, urb->transfer_buffer,
dev->report_size);
*(dev->read_queue + offset + (dev->report_size)) = dev->serial_number++;
atomic_set(&dev->intr_idx, aux_idx);
spin_unlock(&dev->intr_idx_lock);
wake_up_interruptible(&dev->read_wait);
exit:
retval = usb_submit_urb(urb, GFP_ATOMIC);
if (retval)
dev_err(&dev->interface->dev, "%s - usb_submit_urb failed with result %d\n",
__func__, retval);
}
static void iowarrior_write_callback(struct urb *urb)
{
struct iowarrior *dev;
int status = urb->status;
dev = urb->context;
if (status &&
!(status == -ENOENT ||
status == -ECONNRESET || status == -ESHUTDOWN)) {
dev_dbg(&dev->interface->dev,
"nonzero write bulk status received: %d\n", status);
}
usb_free_coherent(urb->dev, urb->transfer_buffer_length,
urb->transfer_buffer, urb->transfer_dma);
atomic_dec(&dev->write_busy);
wake_up_interruptible(&dev->write_wait);
}
static inline void iowarrior_delete(struct iowarrior *dev)
{
dev_dbg(&dev->interface->dev, "minor %d\n", dev->minor);
kfree(dev->int_in_buffer);
usb_free_urb(dev->int_in_urb);
kfree(dev->read_queue);
kfree(dev);
}
static int read_index(struct iowarrior *dev)
{
int intr_idx, read_idx;
read_idx = atomic_read(&dev->read_idx);
intr_idx = atomic_read(&dev->intr_idx);
return (read_idx == intr_idx ? -1 : read_idx);
}
static ssize_t iowarrior_read(struct file *file, char __user *buffer,
size_t count, loff_t *ppos)
{
struct iowarrior *dev;
int read_idx;
int offset;
dev = file->private_data;
if (dev == NULL || !dev->present)
return -ENODEV;
dev_dbg(&dev->interface->dev, "minor %d, count = %zd\n",
dev->minor, count);
if ((count != dev->report_size)
&& (count != (dev->report_size + 1)))
return -EINVAL;
do {
atomic_set(&dev->overflow_flag, 0);
if ((read_idx = read_index(dev)) == -1) {
if (file->f_flags & O_NONBLOCK)
return -EAGAIN;
else {
int r = wait_event_interruptible(dev->read_wait,
(!dev->present
|| (read_idx =
read_index
(dev)) !=
-1));
if (r) {
return -ERESTART;
}
if (!dev->present) {
return -ENODEV;
}
if (read_idx == -1) {
return 0;
}
}
}
offset = read_idx * (dev->report_size + 1);
if (copy_to_user(buffer, dev->read_queue + offset, count)) {
return -EFAULT;
}
} while (atomic_read(&dev->overflow_flag));
read_idx = ++read_idx == MAX_INTERRUPT_BUFFER ? 0 : read_idx;
atomic_set(&dev->read_idx, read_idx);
return count;
}
static ssize_t iowarrior_write(struct file *file,
const char __user *user_buffer,
size_t count, loff_t *ppos)
{
struct iowarrior *dev;
int retval = 0;
char *buf = NULL;
struct urb *int_out_urb = NULL;
dev = file->private_data;
mutex_lock(&dev->mutex);
if (!dev->present) {
retval = -ENODEV;
goto exit;
}
dev_dbg(&dev->interface->dev, "minor %d, count = %zd\n",
dev->minor, count);
if (count == 0) {
retval = 0;
goto exit;
}
if (count != dev->report_size) {
retval = -EINVAL;
goto exit;
}
switch (dev->product_id) {
case USB_DEVICE_ID_CODEMERCS_IOW24:
case USB_DEVICE_ID_CODEMERCS_IOWPV1:
case USB_DEVICE_ID_CODEMERCS_IOWPV2:
case USB_DEVICE_ID_CODEMERCS_IOW40:
buf = kmalloc(count, GFP_KERNEL);
if (!buf) {
retval = -ENOMEM;
goto exit;
}
if (copy_from_user(buf, user_buffer, count)) {
retval = -EFAULT;
kfree(buf);
goto exit;
}
retval = usb_set_report(dev->interface, 2, 0, buf, count);
kfree(buf);
goto exit;
break;
case USB_DEVICE_ID_CODEMERCS_IOW56:
if (atomic_read(&dev->write_busy) == MAX_WRITES_IN_FLIGHT) {
if (file->f_flags & O_NONBLOCK) {
retval = -EAGAIN;
goto exit;
} else {
retval = wait_event_interruptible(dev->write_wait,
(!dev->present || (atomic_read (&dev-> write_busy) < MAX_WRITES_IN_FLIGHT)));
if (retval) {
retval = -ERESTART;
goto exit;
}
if (!dev->present) {
retval = -ENODEV;
goto exit;
}
if (!dev->opened) {
retval = -ENODEV;
goto exit;
}
}
}
atomic_inc(&dev->write_busy);
int_out_urb = usb_alloc_urb(0, GFP_KERNEL);
if (!int_out_urb) {
retval = -ENOMEM;
dev_dbg(&dev->interface->dev,
"Unable to allocate urb\n");
goto error_no_urb;
}
buf = usb_alloc_coherent(dev->udev, dev->report_size,
GFP_KERNEL, &int_out_urb->transfer_dma);
if (!buf) {
retval = -ENOMEM;
dev_dbg(&dev->interface->dev,
"Unable to allocate buffer\n");
goto error_no_buffer;
}
usb_fill_int_urb(int_out_urb, dev->udev,
usb_sndintpipe(dev->udev,
dev->int_out_endpoint->bEndpointAddress),
buf, dev->report_size,
iowarrior_write_callback, dev,
dev->int_out_endpoint->bInterval);
int_out_urb->transfer_flags |= URB_NO_TRANSFER_DMA_MAP;
if (copy_from_user(buf, user_buffer, count)) {
retval = -EFAULT;
goto error;
}
retval = usb_submit_urb(int_out_urb, GFP_KERNEL);
if (retval) {
dev_dbg(&dev->interface->dev,
"submit error %d for urb nr.%d\n",
retval, atomic_read(&dev->write_busy));
goto error;
}
retval = count;
usb_free_urb(int_out_urb);
goto exit;
break;
default:
dev_err(&dev->interface->dev, "%s - not supported for product=0x%x\n",
__func__, dev->product_id);
retval = -EFAULT;
goto exit;
break;
}
error:
usb_free_coherent(dev->udev, dev->report_size, buf,
int_out_urb->transfer_dma);
error_no_buffer:
usb_free_urb(int_out_urb);
error_no_urb:
atomic_dec(&dev->write_busy);
wake_up_interruptible(&dev->write_wait);
exit:
mutex_unlock(&dev->mutex);
return retval;
}
static long iowarrior_ioctl(struct file *file, unsigned int cmd,
unsigned long arg)
{
struct iowarrior *dev = NULL;
__u8 *buffer;
__u8 __user *user_buffer;
int retval;
int io_res;
dev = file->private_data;
if (dev == NULL) {
return -ENODEV;
}
buffer = kzalloc(dev->report_size, GFP_KERNEL);
if (!buffer)
return -ENOMEM;
mutex_lock(&iowarrior_mutex);
mutex_lock(&dev->mutex);
if (!dev->present) {
retval = -ENODEV;
goto error_out;
}
dev_dbg(&dev->interface->dev, "minor %d, cmd 0x%.4x, arg %ld\n",
dev->minor, cmd, arg);
retval = 0;
io_res = 0;
switch (cmd) {
case IOW_WRITE:
if (dev->product_id == USB_DEVICE_ID_CODEMERCS_IOW24 ||
dev->product_id == USB_DEVICE_ID_CODEMERCS_IOWPV1 ||
dev->product_id == USB_DEVICE_ID_CODEMERCS_IOWPV2 ||
dev->product_id == USB_DEVICE_ID_CODEMERCS_IOW40) {
user_buffer = (__u8 __user *)arg;
io_res = copy_from_user(buffer, user_buffer,
dev->report_size);
if (io_res) {
retval = -EFAULT;
} else {
io_res = usb_set_report(dev->interface, 2, 0,
buffer,
dev->report_size);
if (io_res < 0)
retval = io_res;
}
} else {
retval = -EINVAL;
dev_err(&dev->interface->dev,
"ioctl 'IOW_WRITE' is not supported for product=0x%x.\n",
dev->product_id);
}
break;
case IOW_READ:
user_buffer = (__u8 __user *)arg;
io_res = usb_get_report(dev->udev,
dev->interface->cur_altsetting, 1, 0,
buffer, dev->report_size);
if (io_res < 0)
retval = io_res;
else {
io_res = copy_to_user(user_buffer, buffer, dev->report_size);
if (io_res)
retval = -EFAULT;
}
break;
case IOW_GETINFO:
{
struct iowarrior_info info;
struct usb_config_descriptor *cfg_descriptor = &dev->udev->actconfig->desc;
memset(&info, 0, sizeof(info));
info.vendor = le16_to_cpu(dev->udev->descriptor.idVendor);
info.product = dev->product_id;
info.revision = le16_to_cpu(dev->udev->descriptor.bcdDevice);
info.speed = le16_to_cpu(dev->udev->speed);
info.if_num = dev->interface->cur_altsetting->desc.bInterfaceNumber;
info.report_size = dev->report_size;
memcpy(info.serial, dev->chip_serial,
sizeof(dev->chip_serial));
if (cfg_descriptor == NULL) {
info.power = -1;
} else {
info.power = cfg_descriptor->bMaxPower * 2;
}
io_res = copy_to_user((struct iowarrior_info __user *)arg, &info,
sizeof(struct iowarrior_info));
if (io_res)
retval = -EFAULT;
break;
}
default:
retval = -ENOTTY;
break;
}
error_out:
mutex_unlock(&dev->mutex);
mutex_unlock(&iowarrior_mutex);
kfree(buffer);
return retval;
}
static int iowarrior_open(struct inode *inode, struct file *file)
{
struct iowarrior *dev = NULL;
struct usb_interface *interface;
int subminor;
int retval = 0;
mutex_lock(&iowarrior_mutex);
subminor = iminor(inode);
interface = usb_find_interface(&iowarrior_driver, subminor);
if (!interface) {
mutex_unlock(&iowarrior_mutex);
printk(KERN_ERR "%s - error, can't find device for minor %d\n",
__func__, subminor);
return -ENODEV;
}
mutex_lock(&iowarrior_open_disc_lock);
dev = usb_get_intfdata(interface);
if (!dev) {
mutex_unlock(&iowarrior_open_disc_lock);
mutex_unlock(&iowarrior_mutex);
return -ENODEV;
}
mutex_lock(&dev->mutex);
mutex_unlock(&iowarrior_open_disc_lock);
if (dev->opened) {
retval = -EBUSY;
goto out;
}
if ((retval = usb_submit_urb(dev->int_in_urb, GFP_KERNEL)) < 0) {
dev_err(&interface->dev, "Error %d while submitting URB\n", retval);
retval = -EFAULT;
goto out;
}
++dev->opened;
file->private_data = dev;
retval = 0;
out:
mutex_unlock(&dev->mutex);
mutex_unlock(&iowarrior_mutex);
return retval;
}
static int iowarrior_release(struct inode *inode, struct file *file)
{
struct iowarrior *dev;
int retval = 0;
dev = file->private_data;
if (dev == NULL) {
return -ENODEV;
}
dev_dbg(&dev->interface->dev, "minor %d\n", dev->minor);
mutex_lock(&dev->mutex);
if (dev->opened <= 0) {
retval = -ENODEV;
mutex_unlock(&dev->mutex);
} else {
dev->opened = 0;
retval = 0;
if (dev->present) {
usb_kill_urb(dev->int_in_urb);
wake_up_interruptible(&dev->read_wait);
wake_up_interruptible(&dev->write_wait);
mutex_unlock(&dev->mutex);
} else {
mutex_unlock(&dev->mutex);
iowarrior_delete(dev);
}
}
return retval;
}
static unsigned iowarrior_poll(struct file *file, poll_table * wait)
{
struct iowarrior *dev = file->private_data;
unsigned int mask = 0;
if (!dev->present)
return POLLERR | POLLHUP;
poll_wait(file, &dev->read_wait, wait);
poll_wait(file, &dev->write_wait, wait);
if (!dev->present)
return POLLERR | POLLHUP;
if (read_index(dev) != -1)
mask |= POLLIN | POLLRDNORM;
if (atomic_read(&dev->write_busy) < MAX_WRITES_IN_FLIGHT)
mask |= POLLOUT | POLLWRNORM;
return mask;
}
static char *iowarrior_devnode(struct device *dev, umode_t *mode)
{
return kasprintf(GFP_KERNEL, "usb/%s", dev_name(dev));
}
static int iowarrior_probe(struct usb_interface *interface,
const struct usb_device_id *id)
{
struct usb_device *udev = interface_to_usbdev(interface);
struct iowarrior *dev = NULL;
struct usb_host_interface *iface_desc;
struct usb_endpoint_descriptor *endpoint;
int i;
int retval = -ENOMEM;
dev = kzalloc(sizeof(struct iowarrior), GFP_KERNEL);
if (dev == NULL) {
dev_err(&interface->dev, "Out of memory\n");
return retval;
}
mutex_init(&dev->mutex);
atomic_set(&dev->intr_idx, 0);
atomic_set(&dev->read_idx, 0);
spin_lock_init(&dev->intr_idx_lock);
atomic_set(&dev->overflow_flag, 0);
init_waitqueue_head(&dev->read_wait);
atomic_set(&dev->write_busy, 0);
init_waitqueue_head(&dev->write_wait);
dev->udev = udev;
dev->interface = interface;
iface_desc = interface->cur_altsetting;
dev->product_id = le16_to_cpu(udev->descriptor.idProduct);
if (iface_desc->desc.bNumEndpoints < 1) {
dev_err(&interface->dev, "Invalid number of endpoints\n");
retval = -EINVAL;
goto error;
}
for (i = 0; i < iface_desc->desc.bNumEndpoints; ++i) {
endpoint = &iface_desc->endpoint[i].desc;
if (usb_endpoint_is_int_in(endpoint))
dev->int_in_endpoint = endpoint;
if (usb_endpoint_is_int_out(endpoint))
dev->int_out_endpoint = endpoint;
}
dev->report_size = usb_endpoint_maxp(dev->int_in_endpoint);
if ((dev->interface->cur_altsetting->desc.bInterfaceNumber == 0) &&
(dev->product_id == USB_DEVICE_ID_CODEMERCS_IOW56))
dev->report_size = 7;
dev->int_in_urb = usb_alloc_urb(0, GFP_KERNEL);
if (!dev->int_in_urb) {
dev_err(&interface->dev, "Couldn't allocate interrupt_in_urb\n");
goto error;
}
dev->int_in_buffer = kmalloc(dev->report_size, GFP_KERNEL);
if (!dev->int_in_buffer) {
dev_err(&interface->dev, "Couldn't allocate int_in_buffer\n");
goto error;
}
usb_fill_int_urb(dev->int_in_urb, dev->udev,
usb_rcvintpipe(dev->udev,
dev->int_in_endpoint->bEndpointAddress),
dev->int_in_buffer, dev->report_size,
iowarrior_callback, dev,
dev->int_in_endpoint->bInterval);
dev->read_queue =
kmalloc(((dev->report_size + 1) * MAX_INTERRUPT_BUFFER),
GFP_KERNEL);
if (!dev->read_queue) {
dev_err(&interface->dev, "Couldn't allocate read_queue\n");
goto error;
}
memset(dev->chip_serial, 0x00, sizeof(dev->chip_serial));
usb_string(udev, udev->descriptor.iSerialNumber, dev->chip_serial,
sizeof(dev->chip_serial));
if (strlen(dev->chip_serial) != 8)
memset(dev->chip_serial, 0x00, sizeof(dev->chip_serial));
if (dev->interface->cur_altsetting->desc.bInterfaceNumber == 0) {
usb_control_msg(udev, usb_sndctrlpipe(udev, 0),
0x0A,
USB_TYPE_CLASS | USB_RECIP_INTERFACE, 0,
0, NULL, 0, USB_CTRL_SET_TIMEOUT);
}
dev->present = 1;
usb_set_intfdata(interface, dev);
retval = usb_register_dev(interface, &iowarrior_class);
if (retval) {
dev_err(&interface->dev, "Not able to get a minor for this device.\n");
usb_set_intfdata(interface, NULL);
goto error;
}
dev->minor = interface->minor;
dev_info(&interface->dev, "IOWarrior product=0x%x, serial=%s interface=%d "
"now attached to iowarrior%d\n", dev->product_id, dev->chip_serial,
iface_desc->desc.bInterfaceNumber, dev->minor - IOWARRIOR_MINOR_BASE);
return retval;
error:
iowarrior_delete(dev);
return retval;
}
static void iowarrior_disconnect(struct usb_interface *interface)
{
struct iowarrior *dev;
int minor;
dev = usb_get_intfdata(interface);
mutex_lock(&iowarrior_open_disc_lock);
usb_set_intfdata(interface, NULL);
minor = dev->minor;
usb_deregister_dev(interface, &iowarrior_class);
mutex_lock(&dev->mutex);
dev->present = 0;
mutex_unlock(&dev->mutex);
mutex_unlock(&iowarrior_open_disc_lock);
if (dev->opened) {
usb_kill_urb(dev->int_in_urb);
wake_up_interruptible(&dev->read_wait);
wake_up_interruptible(&dev->write_wait);
} else {
iowarrior_delete(dev);
}
dev_info(&interface->dev, "I/O-Warror #%d now disconnected\n",
minor - IOWARRIOR_MINOR_BASE);
}
