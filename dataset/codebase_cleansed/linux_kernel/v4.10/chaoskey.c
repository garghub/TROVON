static void chaoskey_free(struct chaoskey *dev)
{
if (dev) {
usb_dbg(dev->interface, "free");
usb_free_urb(dev->urb);
kfree(dev->name);
kfree(dev->buf);
kfree(dev);
}
}
static int chaoskey_probe(struct usb_interface *interface,
const struct usb_device_id *id)
{
struct usb_device *udev = interface_to_usbdev(interface);
struct usb_host_interface *altsetting = interface->cur_altsetting;
int i;
int in_ep = -1;
struct chaoskey *dev;
int result = -ENOMEM;
int size;
usb_dbg(interface, "probe %s-%s", udev->product, udev->serial);
for (i = 0; i < altsetting->desc.bNumEndpoints; i++) {
if (usb_endpoint_is_bulk_in(&altsetting->endpoint[i].desc)) {
in_ep = usb_endpoint_num(&altsetting->endpoint[i].desc);
size = usb_endpoint_maxp(&altsetting->endpoint[i].desc);
break;
}
}
if (in_ep == -1) {
usb_dbg(interface, "no IN endpoint found");
return -ENODEV;
}
if (size <= 0) {
usb_dbg(interface, "invalid size (%d)", size);
return -ENODEV;
}
if (size > CHAOSKEY_BUF_LEN) {
usb_dbg(interface, "size reduced from %d to %d\n",
size, CHAOSKEY_BUF_LEN);
size = CHAOSKEY_BUF_LEN;
}
dev = kzalloc(sizeof(struct chaoskey), GFP_KERNEL);
if (dev == NULL)
goto out;
dev->buf = kmalloc(size, GFP_KERNEL);
if (dev->buf == NULL)
goto out;
dev->urb = usb_alloc_urb(0, GFP_KERNEL);
if (!dev->urb)
goto out;
usb_fill_bulk_urb(dev->urb,
udev,
usb_rcvbulkpipe(udev, in_ep),
dev->buf,
size,
chaos_read_callback,
dev);
if (udev->product && udev->serial) {
dev->name = kmalloc(strlen(udev->product) + 1 +
strlen(udev->serial) + 1, GFP_KERNEL);
if (dev->name == NULL)
goto out;
strcpy(dev->name, udev->product);
strcat(dev->name, "-");
strcat(dev->name, udev->serial);
}
dev->interface = interface;
dev->in_ep = in_ep;
if (udev->descriptor.idVendor != ALEA_VENDOR_ID)
dev->reads_started = 1;
dev->size = size;
dev->present = 1;
init_waitqueue_head(&dev->wait_q);
mutex_init(&dev->lock);
mutex_init(&dev->rng_lock);
usb_set_intfdata(interface, dev);
result = usb_register_dev(interface, &chaoskey_class);
if (result) {
usb_err(interface, "Unable to allocate minor number.");
goto out;
}
dev->hwrng.name = dev->name ? dev->name : chaoskey_driver.name;
dev->hwrng.read = chaoskey_rng_read;
dev->hwrng.quality = 1024;
dev->hwrng_registered = (hwrng_register(&dev->hwrng) == 0);
if (!dev->hwrng_registered)
usb_err(interface, "Unable to register with hwrng");
usb_enable_autosuspend(udev);
usb_dbg(interface, "chaoskey probe success, size %d", dev->size);
return 0;
out:
usb_set_intfdata(interface, NULL);
chaoskey_free(dev);
return result;
}
static void chaoskey_disconnect(struct usb_interface *interface)
{
struct chaoskey *dev;
usb_dbg(interface, "disconnect");
dev = usb_get_intfdata(interface);
if (!dev) {
usb_dbg(interface, "disconnect failed - no dev");
return;
}
if (dev->hwrng_registered)
hwrng_unregister(&dev->hwrng);
usb_deregister_dev(interface, &chaoskey_class);
usb_set_intfdata(interface, NULL);
mutex_lock(&dev->lock);
dev->present = 0;
usb_poison_urb(dev->urb);
if (!dev->open) {
mutex_unlock(&dev->lock);
chaoskey_free(dev);
} else
mutex_unlock(&dev->lock);
usb_dbg(interface, "disconnect done");
}
static int chaoskey_open(struct inode *inode, struct file *file)
{
struct chaoskey *dev;
struct usb_interface *interface;
interface = usb_find_interface(&chaoskey_driver, iminor(inode));
if (!interface)
return -ENODEV;
usb_dbg(interface, "open");
dev = usb_get_intfdata(interface);
if (!dev) {
usb_dbg(interface, "open (dev)");
return -ENODEV;
}
file->private_data = dev;
mutex_lock(&dev->lock);
++dev->open;
mutex_unlock(&dev->lock);
usb_dbg(interface, "open success");
return 0;
}
static int chaoskey_release(struct inode *inode, struct file *file)
{
struct chaoskey *dev = file->private_data;
struct usb_interface *interface;
if (dev == NULL)
return -ENODEV;
interface = dev->interface;
usb_dbg(interface, "release");
mutex_lock(&dev->lock);
usb_dbg(interface, "open count at release is %d", dev->open);
if (dev->open <= 0) {
usb_dbg(interface, "invalid open count (%d)", dev->open);
mutex_unlock(&dev->lock);
return -ENODEV;
}
--dev->open;
if (!dev->present) {
if (dev->open == 0) {
mutex_unlock(&dev->lock);
chaoskey_free(dev);
} else
mutex_unlock(&dev->lock);
} else
mutex_unlock(&dev->lock);
usb_dbg(interface, "release success");
return 0;
}
static void chaos_read_callback(struct urb *urb)
{
struct chaoskey *dev = urb->context;
int status = urb->status;
usb_dbg(dev->interface, "callback status (%d)", status);
if (status == 0)
dev->valid = urb->actual_length;
else
dev->valid = 0;
dev->used = 0;
smp_wmb();
dev->reading = false;
wake_up(&dev->wait_q);
}
static int _chaoskey_fill(struct chaoskey *dev)
{
DEFINE_WAIT(wait);
int result;
bool started;
usb_dbg(dev->interface, "fill");
if (dev->valid != dev->used) {
usb_dbg(dev->interface, "not empty yet (valid %d used %d)",
dev->valid, dev->used);
return 0;
}
if (!dev->present) {
usb_dbg(dev->interface, "device not present");
return -ENODEV;
}
result = usb_autopm_get_interface(dev->interface);
if (result) {
usb_dbg(dev->interface, "wakeup failed (result %d)", result);
return result;
}
dev->reading = true;
result = usb_submit_urb(dev->urb, GFP_KERNEL);
if (result < 0) {
result = usb_translate_errors(result);
dev->reading = false;
goto out;
}
started = dev->reads_started;
dev->reads_started = true;
result = wait_event_interruptible_timeout(
dev->wait_q,
!dev->reading,
(started ? NAK_TIMEOUT : ALEA_FIRST_TIMEOUT) );
if (result < 0)
goto out;
if (result == 0)
result = -ETIMEDOUT;
else
result = dev->valid;
out:
usb_autopm_put_interface(dev->interface);
usb_dbg(dev->interface, "read %d bytes", dev->valid);
return result;
}
static ssize_t chaoskey_read(struct file *file,
char __user *buffer,
size_t count,
loff_t *ppos)
{
struct chaoskey *dev;
ssize_t read_count = 0;
int this_time;
int result = 0;
unsigned long remain;
dev = file->private_data;
if (dev == NULL || !dev->present)
return -ENODEV;
usb_dbg(dev->interface, "read %zu", count);
while (count > 0) {
result = mutex_lock_interruptible(&dev->rng_lock);
if (result)
goto bail;
mutex_unlock(&dev->rng_lock);
result = mutex_lock_interruptible(&dev->lock);
if (result)
goto bail;
if (dev->valid == dev->used) {
result = _chaoskey_fill(dev);
if (result < 0) {
mutex_unlock(&dev->lock);
goto bail;
}
}
this_time = dev->valid - dev->used;
if (this_time > count)
this_time = count;
remain = copy_to_user(buffer, dev->buf + dev->used, this_time);
if (remain) {
result = -EFAULT;
dev->used += this_time - remain;
mutex_unlock(&dev->lock);
goto bail;
}
count -= this_time;
read_count += this_time;
buffer += this_time;
dev->used += this_time;
mutex_unlock(&dev->lock);
}
bail:
if (read_count) {
usb_dbg(dev->interface, "read %zu bytes", read_count);
return read_count;
}
usb_dbg(dev->interface, "empty read, result %d", result);
if (result == -ETIMEDOUT)
result = -EAGAIN;
return result;
}
static int chaoskey_rng_read(struct hwrng *rng, void *data,
size_t max, bool wait)
{
struct chaoskey *dev = container_of(rng, struct chaoskey, hwrng);
int this_time;
usb_dbg(dev->interface, "rng_read max %zu wait %d", max, wait);
if (!dev->present) {
usb_dbg(dev->interface, "device not present");
return 0;
}
mutex_lock(&dev->rng_lock);
mutex_lock(&dev->lock);
mutex_unlock(&dev->rng_lock);
if (dev->valid == dev->used)
(void) _chaoskey_fill(dev);
this_time = dev->valid - dev->used;
if (this_time > max)
this_time = max;
memcpy(data, dev->buf + dev->used, this_time);
dev->used += this_time;
mutex_unlock(&dev->lock);
usb_dbg(dev->interface, "rng_read this_time %d\n", this_time);
return this_time;
}
static int chaoskey_suspend(struct usb_interface *interface,
pm_message_t message)
{
usb_dbg(interface, "suspend");
return 0;
}
static int chaoskey_resume(struct usb_interface *interface)
{
usb_dbg(interface, "resume");
return 0;
}
