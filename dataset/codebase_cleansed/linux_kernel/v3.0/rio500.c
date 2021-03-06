static int open_rio(struct inode *inode, struct file *file)
{
struct rio_usb_data *rio = &rio_instance;
mutex_lock(&rio500_mutex);
mutex_lock(&(rio->lock));
if (rio->isopen || !rio->present) {
mutex_unlock(&(rio->lock));
mutex_unlock(&rio500_mutex);
return -EBUSY;
}
rio->isopen = 1;
init_waitqueue_head(&rio->wait_q);
mutex_unlock(&(rio->lock));
dev_info(&rio->rio_dev->dev, "Rio opened.\n");
mutex_unlock(&rio500_mutex);
return 0;
}
static int close_rio(struct inode *inode, struct file *file)
{
struct rio_usb_data *rio = &rio_instance;
rio->isopen = 0;
dev_info(&rio->rio_dev->dev, "Rio closed.\n");
return 0;
}
static long ioctl_rio(struct file *file, unsigned int cmd, unsigned long arg)
{
struct RioCommand rio_cmd;
struct rio_usb_data *rio = &rio_instance;
void __user *data;
unsigned char *buffer;
int result, requesttype;
int retries;
int retval=0;
mutex_lock(&(rio->lock));
if (rio->present == 0 || rio->rio_dev == NULL) {
retval = -ENODEV;
goto err_out;
}
switch (cmd) {
case RIO_RECV_COMMAND:
data = (void __user *) arg;
if (data == NULL)
break;
if (copy_from_user(&rio_cmd, data, sizeof(struct RioCommand))) {
retval = -EFAULT;
goto err_out;
}
if (rio_cmd.length < 0 || rio_cmd.length > PAGE_SIZE) {
retval = -EINVAL;
goto err_out;
}
buffer = (unsigned char *) __get_free_page(GFP_KERNEL);
if (buffer == NULL) {
retval = -ENOMEM;
goto err_out;
}
if (copy_from_user(buffer, rio_cmd.buffer, rio_cmd.length)) {
retval = -EFAULT;
free_page((unsigned long) buffer);
goto err_out;
}
requesttype = rio_cmd.requesttype | USB_DIR_IN |
USB_TYPE_VENDOR | USB_RECIP_DEVICE;
dbg
("sending command:reqtype=%0x req=%0x value=%0x index=%0x len=%0x",
requesttype, rio_cmd.request, rio_cmd.value,
rio_cmd.index, rio_cmd.length);
retries = 3;
while (retries) {
result = usb_control_msg(rio->rio_dev,
usb_rcvctrlpipe(rio-> rio_dev, 0),
rio_cmd.request,
requesttype,
rio_cmd.value,
rio_cmd.index, buffer,
rio_cmd.length,
jiffies_to_msecs(rio_cmd.timeout));
if (result == -ETIMEDOUT)
retries--;
else if (result < 0) {
err("Error executing ioctrl. code = %d", result);
retries = 0;
} else {
dbg("Executed ioctl. Result = %d (data=%02x)",
result, buffer[0]);
if (copy_to_user(rio_cmd.buffer, buffer,
rio_cmd.length)) {
free_page((unsigned long) buffer);
retval = -EFAULT;
goto err_out;
}
retries = 0;
}
}
free_page((unsigned long) buffer);
break;
case RIO_SEND_COMMAND:
data = (void __user *) arg;
if (data == NULL)
break;
if (copy_from_user(&rio_cmd, data, sizeof(struct RioCommand))) {
retval = -EFAULT;
goto err_out;
}
if (rio_cmd.length < 0 || rio_cmd.length > PAGE_SIZE) {
retval = -EINVAL;
goto err_out;
}
buffer = (unsigned char *) __get_free_page(GFP_KERNEL);
if (buffer == NULL) {
retval = -ENOMEM;
goto err_out;
}
if (copy_from_user(buffer, rio_cmd.buffer, rio_cmd.length)) {
free_page((unsigned long)buffer);
retval = -EFAULT;
goto err_out;
}
requesttype = rio_cmd.requesttype | USB_DIR_OUT |
USB_TYPE_VENDOR | USB_RECIP_DEVICE;
dbg("sending command: reqtype=%0x req=%0x value=%0x index=%0x len=%0x",
requesttype, rio_cmd.request, rio_cmd.value,
rio_cmd.index, rio_cmd.length);
retries = 3;
while (retries) {
result = usb_control_msg(rio->rio_dev,
usb_sndctrlpipe(rio-> rio_dev, 0),
rio_cmd.request,
requesttype,
rio_cmd.value,
rio_cmd.index, buffer,
rio_cmd.length,
jiffies_to_msecs(rio_cmd.timeout));
if (result == -ETIMEDOUT)
retries--;
else if (result < 0) {
err("Error executing ioctrl. code = %d", result);
retries = 0;
} else {
dbg("Executed ioctl. Result = %d", result);
retries = 0;
}
}
free_page((unsigned long) buffer);
break;
default:
retval = -ENOTTY;
break;
}
err_out:
mutex_unlock(&(rio->lock));
return retval;
}
static ssize_t
write_rio(struct file *file, const char __user *buffer,
size_t count, loff_t * ppos)
{
DEFINE_WAIT(wait);
struct rio_usb_data *rio = &rio_instance;
unsigned long copy_size;
unsigned long bytes_written = 0;
unsigned int partial;
int result = 0;
int maxretry;
int errn = 0;
int intr;
intr = mutex_lock_interruptible(&(rio->lock));
if (intr)
return -EINTR;
if (rio->present == 0 || rio->rio_dev == NULL) {
mutex_unlock(&(rio->lock));
return -ENODEV;
}
do {
unsigned long thistime;
char *obuf = rio->obuf;
thistime = copy_size =
(count >= OBUF_SIZE) ? OBUF_SIZE : count;
if (copy_from_user(rio->obuf, buffer, copy_size)) {
errn = -EFAULT;
goto error;
}
maxretry = 5;
while (thistime) {
if (!rio->rio_dev) {
errn = -ENODEV;
goto error;
}
if (signal_pending(current)) {
mutex_unlock(&(rio->lock));
return bytes_written ? bytes_written : -EINTR;
}
result = usb_bulk_msg(rio->rio_dev,
usb_sndbulkpipe(rio->rio_dev, 2),
obuf, thistime, &partial, 5000);
dbg("write stats: result:%d thistime:%lu partial:%u",
result, thistime, partial);
if (result == -ETIMEDOUT) {
if (!maxretry--) {
errn = -ETIME;
goto error;
}
prepare_to_wait(&rio->wait_q, &wait, TASK_INTERRUPTIBLE);
schedule_timeout(NAK_TIMEOUT);
finish_wait(&rio->wait_q, &wait);
continue;
} else if (!result && partial) {
obuf += partial;
thistime -= partial;
} else
break;
};
if (result) {
err("Write Whoops - %x", result);
errn = -EIO;
goto error;
}
bytes_written += copy_size;
count -= copy_size;
buffer += copy_size;
} while (count > 0);
mutex_unlock(&(rio->lock));
return bytes_written ? bytes_written : -EIO;
error:
mutex_unlock(&(rio->lock));
return errn;
}
static ssize_t
read_rio(struct file *file, char __user *buffer, size_t count, loff_t * ppos)
{
DEFINE_WAIT(wait);
struct rio_usb_data *rio = &rio_instance;
ssize_t read_count;
unsigned int partial;
int this_read;
int result;
int maxretry = 10;
char *ibuf;
int intr;
intr = mutex_lock_interruptible(&(rio->lock));
if (intr)
return -EINTR;
if (rio->present == 0 || rio->rio_dev == NULL) {
mutex_unlock(&(rio->lock));
return -ENODEV;
}
ibuf = rio->ibuf;
read_count = 0;
while (count > 0) {
if (signal_pending(current)) {
mutex_unlock(&(rio->lock));
return read_count ? read_count : -EINTR;
}
if (!rio->rio_dev) {
mutex_unlock(&(rio->lock));
return -ENODEV;
}
this_read = (count >= IBUF_SIZE) ? IBUF_SIZE : count;
result = usb_bulk_msg(rio->rio_dev,
usb_rcvbulkpipe(rio->rio_dev, 1),
ibuf, this_read, &partial,
8000);
dbg("read stats: result:%d this_read:%u partial:%u",
result, this_read, partial);
if (partial) {
count = this_read = partial;
} else if (result == -ETIMEDOUT || result == 15) {
if (!maxretry--) {
mutex_unlock(&(rio->lock));
err("read_rio: maxretry timeout");
return -ETIME;
}
prepare_to_wait(&rio->wait_q, &wait, TASK_INTERRUPTIBLE);
schedule_timeout(NAK_TIMEOUT);
finish_wait(&rio->wait_q, &wait);
continue;
} else if (result != -EREMOTEIO) {
mutex_unlock(&(rio->lock));
err("Read Whoops - result:%u partial:%u this_read:%u",
result, partial, this_read);
return -EIO;
} else {
mutex_unlock(&(rio->lock));
return (0);
}
if (this_read) {
if (copy_to_user(buffer, ibuf, this_read)) {
mutex_unlock(&(rio->lock));
return -EFAULT;
}
count -= this_read;
read_count += this_read;
buffer += this_read;
}
}
mutex_unlock(&(rio->lock));
return read_count;
}
static int probe_rio(struct usb_interface *intf,
const struct usb_device_id *id)
{
struct usb_device *dev = interface_to_usbdev(intf);
struct rio_usb_data *rio = &rio_instance;
int retval;
dev_info(&intf->dev, "USB Rio found at address %d\n", dev->devnum);
retval = usb_register_dev(intf, &usb_rio_class);
if (retval) {
err("Not able to get a minor for this device.");
return -ENOMEM;
}
rio->rio_dev = dev;
if (!(rio->obuf = kmalloc(OBUF_SIZE, GFP_KERNEL))) {
err("probe_rio: Not enough memory for the output buffer");
usb_deregister_dev(intf, &usb_rio_class);
return -ENOMEM;
}
dbg("probe_rio: obuf address:%p", rio->obuf);
if (!(rio->ibuf = kmalloc(IBUF_SIZE, GFP_KERNEL))) {
err("probe_rio: Not enough memory for the input buffer");
usb_deregister_dev(intf, &usb_rio_class);
kfree(rio->obuf);
return -ENOMEM;
}
dbg("probe_rio: ibuf address:%p", rio->ibuf);
mutex_init(&(rio->lock));
usb_set_intfdata (intf, rio);
rio->present = 1;
return 0;
}
static void disconnect_rio(struct usb_interface *intf)
{
struct rio_usb_data *rio = usb_get_intfdata (intf);
usb_set_intfdata (intf, NULL);
mutex_lock(&rio500_mutex);
if (rio) {
usb_deregister_dev(intf, &usb_rio_class);
mutex_lock(&(rio->lock));
if (rio->isopen) {
rio->isopen = 0;
rio->rio_dev = NULL;
mutex_unlock(&(rio->lock));
mutex_unlock(&rio500_mutex);
return;
}
kfree(rio->ibuf);
kfree(rio->obuf);
dev_info(&intf->dev, "USB Rio disconnected.\n");
rio->present = 0;
mutex_unlock(&(rio->lock));
}
mutex_unlock(&rio500_mutex);
}
static int __init usb_rio_init(void)
{
int retval;
retval = usb_register(&rio_driver);
if (retval)
goto out;
printk(KERN_INFO KBUILD_MODNAME ": " DRIVER_VERSION ":"
DRIVER_DESC "\n");
out:
return retval;
}
static void __exit usb_rio_cleanup(void)
{
struct rio_usb_data *rio = &rio_instance;
rio->present = 0;
usb_deregister(&rio_driver);
}
