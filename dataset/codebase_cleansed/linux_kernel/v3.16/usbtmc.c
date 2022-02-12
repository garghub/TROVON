static void usbtmc_delete(struct kref *kref)
{
struct usbtmc_device_data *data = to_usbtmc_data(kref);
usb_put_dev(data->usb_dev);
}
static int usbtmc_open(struct inode *inode, struct file *filp)
{
struct usb_interface *intf;
struct usbtmc_device_data *data;
int retval = 0;
intf = usb_find_interface(&usbtmc_driver, iminor(inode));
if (!intf) {
pr_err("can not find device for minor %d", iminor(inode));
return -ENODEV;
}
data = usb_get_intfdata(intf);
kref_get(&data->kref);
filp->private_data = data;
return retval;
}
static int usbtmc_release(struct inode *inode, struct file *file)
{
struct usbtmc_device_data *data = file->private_data;
kref_put(&data->kref, usbtmc_delete);
return 0;
}
static int usbtmc_ioctl_abort_bulk_in(struct usbtmc_device_data *data)
{
u8 *buffer;
struct device *dev;
int rv;
int n;
int actual;
struct usb_host_interface *current_setting;
int max_size;
dev = &data->intf->dev;
buffer = kmalloc(USBTMC_SIZE_IOBUFFER, GFP_KERNEL);
if (!buffer)
return -ENOMEM;
rv = usb_control_msg(data->usb_dev,
usb_rcvctrlpipe(data->usb_dev, 0),
USBTMC_REQUEST_INITIATE_ABORT_BULK_IN,
USB_DIR_IN | USB_TYPE_CLASS | USB_RECIP_ENDPOINT,
data->bTag_last_read, data->bulk_in,
buffer, 2, USBTMC_TIMEOUT);
if (rv < 0) {
dev_err(dev, "usb_control_msg returned %d\n", rv);
goto exit;
}
dev_dbg(dev, "INITIATE_ABORT_BULK_IN returned %x\n", buffer[0]);
if (buffer[0] == USBTMC_STATUS_FAILED) {
rv = 0;
goto exit;
}
if (buffer[0] != USBTMC_STATUS_SUCCESS) {
dev_err(dev, "INITIATE_ABORT_BULK_IN returned %x\n",
buffer[0]);
rv = -EPERM;
goto exit;
}
max_size = 0;
current_setting = data->intf->cur_altsetting;
for (n = 0; n < current_setting->desc.bNumEndpoints; n++)
if (current_setting->endpoint[n].desc.bEndpointAddress ==
data->bulk_in)
max_size = usb_endpoint_maxp(&current_setting->endpoint[n].desc);
if (max_size == 0) {
dev_err(dev, "Couldn't get wMaxPacketSize\n");
rv = -EPERM;
goto exit;
}
dev_dbg(&data->intf->dev, "wMaxPacketSize is %d\n", max_size);
n = 0;
do {
dev_dbg(dev, "Reading from bulk in EP\n");
rv = usb_bulk_msg(data->usb_dev,
usb_rcvbulkpipe(data->usb_dev,
data->bulk_in),
buffer, USBTMC_SIZE_IOBUFFER,
&actual, USBTMC_TIMEOUT);
n++;
if (rv < 0) {
dev_err(dev, "usb_bulk_msg returned %d\n", rv);
goto exit;
}
} while ((actual == max_size) &&
(n < USBTMC_MAX_READS_TO_CLEAR_BULK_IN));
if (actual == max_size) {
dev_err(dev, "Couldn't clear device buffer within %d cycles\n",
USBTMC_MAX_READS_TO_CLEAR_BULK_IN);
rv = -EPERM;
goto exit;
}
n = 0;
usbtmc_abort_bulk_in_status:
rv = usb_control_msg(data->usb_dev,
usb_rcvctrlpipe(data->usb_dev, 0),
USBTMC_REQUEST_CHECK_ABORT_BULK_IN_STATUS,
USB_DIR_IN | USB_TYPE_CLASS | USB_RECIP_ENDPOINT,
0, data->bulk_in, buffer, 0x08,
USBTMC_TIMEOUT);
if (rv < 0) {
dev_err(dev, "usb_control_msg returned %d\n", rv);
goto exit;
}
dev_dbg(dev, "INITIATE_ABORT_BULK_IN returned %x\n", buffer[0]);
if (buffer[0] == USBTMC_STATUS_SUCCESS) {
rv = 0;
goto exit;
}
if (buffer[0] != USBTMC_STATUS_PENDING) {
dev_err(dev, "INITIATE_ABORT_BULK_IN returned %x\n", buffer[0]);
rv = -EPERM;
goto exit;
}
if (buffer[1] == 1)
do {
dev_dbg(dev, "Reading from bulk in EP\n");
rv = usb_bulk_msg(data->usb_dev,
usb_rcvbulkpipe(data->usb_dev,
data->bulk_in),
buffer, USBTMC_SIZE_IOBUFFER,
&actual, USBTMC_TIMEOUT);
n++;
if (rv < 0) {
dev_err(dev, "usb_bulk_msg returned %d\n", rv);
goto exit;
}
} while ((actual == max_size) &&
(n < USBTMC_MAX_READS_TO_CLEAR_BULK_IN));
if (actual == max_size) {
dev_err(dev, "Couldn't clear device buffer within %d cycles\n",
USBTMC_MAX_READS_TO_CLEAR_BULK_IN);
rv = -EPERM;
goto exit;
}
goto usbtmc_abort_bulk_in_status;
exit:
kfree(buffer);
return rv;
}
static int usbtmc_ioctl_abort_bulk_out(struct usbtmc_device_data *data)
{
struct device *dev;
u8 *buffer;
int rv;
int n;
dev = &data->intf->dev;
buffer = kmalloc(8, GFP_KERNEL);
if (!buffer)
return -ENOMEM;
rv = usb_control_msg(data->usb_dev,
usb_rcvctrlpipe(data->usb_dev, 0),
USBTMC_REQUEST_INITIATE_ABORT_BULK_OUT,
USB_DIR_IN | USB_TYPE_CLASS | USB_RECIP_ENDPOINT,
data->bTag_last_write, data->bulk_out,
buffer, 2, USBTMC_TIMEOUT);
if (rv < 0) {
dev_err(dev, "usb_control_msg returned %d\n", rv);
goto exit;
}
dev_dbg(dev, "INITIATE_ABORT_BULK_OUT returned %x\n", buffer[0]);
if (buffer[0] != USBTMC_STATUS_SUCCESS) {
dev_err(dev, "INITIATE_ABORT_BULK_OUT returned %x\n",
buffer[0]);
rv = -EPERM;
goto exit;
}
n = 0;
usbtmc_abort_bulk_out_check_status:
rv = usb_control_msg(data->usb_dev,
usb_rcvctrlpipe(data->usb_dev, 0),
USBTMC_REQUEST_CHECK_ABORT_BULK_OUT_STATUS,
USB_DIR_IN | USB_TYPE_CLASS | USB_RECIP_ENDPOINT,
0, data->bulk_out, buffer, 0x08,
USBTMC_TIMEOUT);
n++;
if (rv < 0) {
dev_err(dev, "usb_control_msg returned %d\n", rv);
goto exit;
}
dev_dbg(dev, "CHECK_ABORT_BULK_OUT returned %x\n", buffer[0]);
if (buffer[0] == USBTMC_STATUS_SUCCESS)
goto usbtmc_abort_bulk_out_clear_halt;
if ((buffer[0] == USBTMC_STATUS_PENDING) &&
(n < USBTMC_MAX_READS_TO_CLEAR_BULK_IN))
goto usbtmc_abort_bulk_out_check_status;
rv = -EPERM;
goto exit;
usbtmc_abort_bulk_out_clear_halt:
rv = usb_clear_halt(data->usb_dev,
usb_sndbulkpipe(data->usb_dev, data->bulk_out));
if (rv < 0) {
dev_err(dev, "usb_control_msg returned %d\n", rv);
goto exit;
}
rv = 0;
exit:
kfree(buffer);
return rv;
}
static int send_request_dev_dep_msg_in(struct usbtmc_device_data *data, size_t transfer_size)
{
int retval;
u8 *buffer;
int actual;
buffer = kmalloc(USBTMC_HEADER_SIZE, GFP_KERNEL);
if (!buffer)
return -ENOMEM;
buffer[0] = 2;
buffer[1] = data->bTag;
buffer[2] = ~data->bTag;
buffer[3] = 0;
buffer[4] = transfer_size >> 0;
buffer[5] = transfer_size >> 8;
buffer[6] = transfer_size >> 16;
buffer[7] = transfer_size >> 24;
buffer[8] = data->TermCharEnabled * 2;
buffer[9] = data->TermChar;
buffer[10] = 0;
buffer[11] = 0;
retval = usb_bulk_msg(data->usb_dev,
usb_sndbulkpipe(data->usb_dev,
data->bulk_out),
buffer, USBTMC_HEADER_SIZE, &actual, USBTMC_TIMEOUT);
data->bTag_last_write = data->bTag;
data->bTag++;
if (!data->bTag)
data->bTag++;
kfree(buffer);
if (retval < 0) {
dev_err(&data->intf->dev, "usb_bulk_msg in send_request_dev_dep_msg_in() returned %d\n", retval);
return retval;
}
return 0;
}
static ssize_t usbtmc_read(struct file *filp, char __user *buf,
size_t count, loff_t *f_pos)
{
struct usbtmc_device_data *data;
struct device *dev;
u32 n_characters;
u8 *buffer;
int actual;
size_t done;
size_t remaining;
int retval;
size_t this_part;
data = filp->private_data;
dev = &data->intf->dev;
buffer = kmalloc(USBTMC_SIZE_IOBUFFER, GFP_KERNEL);
if (!buffer)
return -ENOMEM;
mutex_lock(&data->io_mutex);
if (data->zombie) {
retval = -ENODEV;
goto exit;
}
if (data->rigol_quirk) {
dev_dbg(dev, "usb_bulk_msg_in: count(%zu)\n", count);
retval = send_request_dev_dep_msg_in(data, count);
if (retval < 0) {
if (data->auto_abort)
usbtmc_ioctl_abort_bulk_out(data);
goto exit;
}
}
remaining = count;
this_part = remaining;
done = 0;
while (remaining > 0) {
if (!data->rigol_quirk) {
dev_dbg(dev, "usb_bulk_msg_in: remaining(%zu), count(%zu)\n", remaining, count);
if (remaining > USBTMC_SIZE_IOBUFFER - USBTMC_HEADER_SIZE - 3)
this_part = USBTMC_SIZE_IOBUFFER - USBTMC_HEADER_SIZE - 3;
else
this_part = remaining;
retval = send_request_dev_dep_msg_in(data, this_part);
if (retval < 0) {
dev_err(dev, "usb_bulk_msg returned %d\n", retval);
if (data->auto_abort)
usbtmc_ioctl_abort_bulk_out(data);
goto exit;
}
}
retval = usb_bulk_msg(data->usb_dev,
usb_rcvbulkpipe(data->usb_dev,
data->bulk_in),
buffer, USBTMC_SIZE_IOBUFFER, &actual,
USBTMC_TIMEOUT);
dev_dbg(dev, "usb_bulk_msg: retval(%u), done(%zu), remaining(%zu), actual(%d)\n", retval, done, remaining, actual);
data->bTag_last_read = data->bTag;
if (retval < 0) {
dev_dbg(dev, "Unable to read data, error %d\n", retval);
if (data->auto_abort)
usbtmc_ioctl_abort_bulk_in(data);
goto exit;
}
if ((done == 0) || !data->rigol_quirk) {
if (actual < USBTMC_HEADER_SIZE) {
dev_err(dev, "Device sent too small first packet: %u < %u\n", actual, USBTMC_HEADER_SIZE);
if (data->auto_abort)
usbtmc_ioctl_abort_bulk_in(data);
goto exit;
}
if (buffer[0] != 2) {
dev_err(dev, "Device sent reply with wrong MsgID: %u != 2\n", buffer[0]);
if (data->auto_abort)
usbtmc_ioctl_abort_bulk_in(data);
goto exit;
}
if (buffer[1] != data->bTag_last_write) {
dev_err(dev, "Device sent reply with wrong bTag: %u != %u\n", buffer[1], data->bTag_last_write);
if (data->auto_abort)
usbtmc_ioctl_abort_bulk_in(data);
goto exit;
}
n_characters = buffer[4] +
(buffer[5] << 8) +
(buffer[6] << 16) +
(buffer[7] << 24);
if (n_characters > this_part) {
dev_err(dev, "Device wants to return more data than requested: %u > %zu\n", n_characters, count);
if (data->auto_abort)
usbtmc_ioctl_abort_bulk_in(data);
goto exit;
}
actual -= USBTMC_HEADER_SIZE;
if (data->rigol_quirk) {
if (remaining > n_characters)
remaining = n_characters;
if (actual > remaining)
actual = remaining;
}
else {
if (this_part > n_characters)
this_part = n_characters;
if (actual > this_part)
actual = this_part;
}
dev_dbg(dev, "Bulk-IN header: N_characters(%u), bTransAttr(%u)\n", n_characters, buffer[8]);
remaining -= actual;
if ((buffer[8] & 0x01) && (actual >= n_characters))
remaining = 0;
dev_dbg(dev, "Bulk-IN header: remaining(%zu), buf(%p), buffer(%p) done(%zu)\n", remaining,buf,buffer,done);
if (copy_to_user(buf + done, &buffer[USBTMC_HEADER_SIZE], actual)) {
retval = -EFAULT;
goto exit;
}
done += actual;
}
else {
if (actual > remaining)
actual = remaining;
remaining -= actual;
dev_dbg(dev, "Bulk-IN header cont: actual(%u), done(%zu), remaining(%zu), buf(%p), buffer(%p)\n", actual, done, remaining,buf,buffer);
if (copy_to_user(buf + done, buffer, actual)) {
retval = -EFAULT;
goto exit;
}
done += actual;
}
}
*f_pos = *f_pos + done;
retval = done;
exit:
mutex_unlock(&data->io_mutex);
kfree(buffer);
return retval;
}
static ssize_t usbtmc_write(struct file *filp, const char __user *buf,
size_t count, loff_t *f_pos)
{
struct usbtmc_device_data *data;
u8 *buffer;
int retval;
int actual;
unsigned long int n_bytes;
int remaining;
int done;
int this_part;
data = filp->private_data;
buffer = kmalloc(USBTMC_SIZE_IOBUFFER, GFP_KERNEL);
if (!buffer)
return -ENOMEM;
mutex_lock(&data->io_mutex);
if (data->zombie) {
retval = -ENODEV;
goto exit;
}
remaining = count;
done = 0;
while (remaining > 0) {
if (remaining > USBTMC_SIZE_IOBUFFER - USBTMC_HEADER_SIZE) {
this_part = USBTMC_SIZE_IOBUFFER - USBTMC_HEADER_SIZE;
buffer[8] = 0;
} else {
this_part = remaining;
buffer[8] = 1;
}
buffer[0] = 1;
buffer[1] = data->bTag;
buffer[2] = ~data->bTag;
buffer[3] = 0;
buffer[4] = this_part >> 0;
buffer[5] = this_part >> 8;
buffer[6] = this_part >> 16;
buffer[7] = this_part >> 24;
buffer[9] = 0;
buffer[10] = 0;
buffer[11] = 0;
if (copy_from_user(&buffer[USBTMC_HEADER_SIZE], buf + done, this_part)) {
retval = -EFAULT;
goto exit;
}
n_bytes = roundup(USBTMC_HEADER_SIZE + this_part, 4);
memset(buffer + USBTMC_HEADER_SIZE + this_part, 0, n_bytes - (USBTMC_HEADER_SIZE + this_part));
do {
retval = usb_bulk_msg(data->usb_dev,
usb_sndbulkpipe(data->usb_dev,
data->bulk_out),
buffer, n_bytes,
&actual, USBTMC_TIMEOUT);
if (retval != 0)
break;
n_bytes -= actual;
} while (n_bytes);
data->bTag_last_write = data->bTag;
data->bTag++;
if (!data->bTag)
data->bTag++;
if (retval < 0) {
dev_err(&data->intf->dev,
"Unable to send data, error %d\n", retval);
if (data->auto_abort)
usbtmc_ioctl_abort_bulk_out(data);
goto exit;
}
remaining -= this_part;
done += this_part;
}
retval = count;
exit:
mutex_unlock(&data->io_mutex);
kfree(buffer);
return retval;
}
static int usbtmc_ioctl_clear(struct usbtmc_device_data *data)
{
struct usb_host_interface *current_setting;
struct usb_endpoint_descriptor *desc;
struct device *dev;
u8 *buffer;
int rv;
int n;
int actual;
int max_size;
dev = &data->intf->dev;
dev_dbg(dev, "Sending INITIATE_CLEAR request\n");
buffer = kmalloc(USBTMC_SIZE_IOBUFFER, GFP_KERNEL);
if (!buffer)
return -ENOMEM;
rv = usb_control_msg(data->usb_dev,
usb_rcvctrlpipe(data->usb_dev, 0),
USBTMC_REQUEST_INITIATE_CLEAR,
USB_DIR_IN | USB_TYPE_CLASS | USB_RECIP_INTERFACE,
0, 0, buffer, 1, USBTMC_TIMEOUT);
if (rv < 0) {
dev_err(dev, "usb_control_msg returned %d\n", rv);
goto exit;
}
dev_dbg(dev, "INITIATE_CLEAR returned %x\n", buffer[0]);
if (buffer[0] != USBTMC_STATUS_SUCCESS) {
dev_err(dev, "INITIATE_CLEAR returned %x\n", buffer[0]);
rv = -EPERM;
goto exit;
}
max_size = 0;
current_setting = data->intf->cur_altsetting;
for (n = 0; n < current_setting->desc.bNumEndpoints; n++) {
desc = &current_setting->endpoint[n].desc;
if (desc->bEndpointAddress == data->bulk_in)
max_size = usb_endpoint_maxp(desc);
}
if (max_size == 0) {
dev_err(dev, "Couldn't get wMaxPacketSize\n");
rv = -EPERM;
goto exit;
}
dev_dbg(dev, "wMaxPacketSize is %d\n", max_size);
n = 0;
usbtmc_clear_check_status:
dev_dbg(dev, "Sending CHECK_CLEAR_STATUS request\n");
rv = usb_control_msg(data->usb_dev,
usb_rcvctrlpipe(data->usb_dev, 0),
USBTMC_REQUEST_CHECK_CLEAR_STATUS,
USB_DIR_IN | USB_TYPE_CLASS | USB_RECIP_INTERFACE,
0, 0, buffer, 2, USBTMC_TIMEOUT);
if (rv < 0) {
dev_err(dev, "usb_control_msg returned %d\n", rv);
goto exit;
}
dev_dbg(dev, "CHECK_CLEAR_STATUS returned %x\n", buffer[0]);
if (buffer[0] == USBTMC_STATUS_SUCCESS)
goto usbtmc_clear_bulk_out_halt;
if (buffer[0] != USBTMC_STATUS_PENDING) {
dev_err(dev, "CHECK_CLEAR_STATUS returned %x\n", buffer[0]);
rv = -EPERM;
goto exit;
}
if (buffer[1] == 1)
do {
dev_dbg(dev, "Reading from bulk in EP\n");
rv = usb_bulk_msg(data->usb_dev,
usb_rcvbulkpipe(data->usb_dev,
data->bulk_in),
buffer, USBTMC_SIZE_IOBUFFER,
&actual, USBTMC_TIMEOUT);
n++;
if (rv < 0) {
dev_err(dev, "usb_control_msg returned %d\n",
rv);
goto exit;
}
} while ((actual == max_size) &&
(n < USBTMC_MAX_READS_TO_CLEAR_BULK_IN));
if (actual == max_size) {
dev_err(dev, "Couldn't clear device buffer within %d cycles\n",
USBTMC_MAX_READS_TO_CLEAR_BULK_IN);
rv = -EPERM;
goto exit;
}
goto usbtmc_clear_check_status;
usbtmc_clear_bulk_out_halt:
rv = usb_clear_halt(data->usb_dev,
usb_sndbulkpipe(data->usb_dev, data->bulk_out));
if (rv < 0) {
dev_err(dev, "usb_control_msg returned %d\n", rv);
goto exit;
}
rv = 0;
exit:
kfree(buffer);
return rv;
}
static int usbtmc_ioctl_clear_out_halt(struct usbtmc_device_data *data)
{
int rv;
rv = usb_clear_halt(data->usb_dev,
usb_sndbulkpipe(data->usb_dev, data->bulk_out));
if (rv < 0) {
dev_err(&data->usb_dev->dev, "usb_control_msg returned %d\n",
rv);
return rv;
}
return 0;
}
static int usbtmc_ioctl_clear_in_halt(struct usbtmc_device_data *data)
{
int rv;
rv = usb_clear_halt(data->usb_dev,
usb_rcvbulkpipe(data->usb_dev, data->bulk_in));
if (rv < 0) {
dev_err(&data->usb_dev->dev, "usb_control_msg returned %d\n",
rv);
return rv;
}
return 0;
}
static int get_capabilities(struct usbtmc_device_data *data)
{
struct device *dev = &data->usb_dev->dev;
char *buffer;
int rv = 0;
buffer = kmalloc(0x18, GFP_KERNEL);
if (!buffer)
return -ENOMEM;
rv = usb_control_msg(data->usb_dev, usb_rcvctrlpipe(data->usb_dev, 0),
USBTMC_REQUEST_GET_CAPABILITIES,
USB_DIR_IN | USB_TYPE_CLASS | USB_RECIP_INTERFACE,
0, 0, buffer, 0x18, USBTMC_TIMEOUT);
if (rv < 0) {
dev_err(dev, "usb_control_msg returned %d\n", rv);
goto err_out;
}
dev_dbg(dev, "GET_CAPABILITIES returned %x\n", buffer[0]);
if (buffer[0] != USBTMC_STATUS_SUCCESS) {
dev_err(dev, "GET_CAPABILITIES returned %x\n", buffer[0]);
rv = -EPERM;
goto err_out;
}
dev_dbg(dev, "Interface capabilities are %x\n", buffer[4]);
dev_dbg(dev, "Device capabilities are %x\n", buffer[5]);
dev_dbg(dev, "USB488 interface capabilities are %x\n", buffer[14]);
dev_dbg(dev, "USB488 device capabilities are %x\n", buffer[15]);
data->capabilities.interface_capabilities = buffer[4];
data->capabilities.device_capabilities = buffer[5];
data->capabilities.usb488_interface_capabilities = buffer[14];
data->capabilities.usb488_device_capabilities = buffer[15];
rv = 0;
err_out:
kfree(buffer);
return rv;
}
static ssize_t TermChar_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct usb_interface *intf = to_usb_interface(dev);
struct usbtmc_device_data *data = usb_get_intfdata(intf);
return sprintf(buf, "%c\n", data->TermChar);
}
static ssize_t TermChar_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct usb_interface *intf = to_usb_interface(dev);
struct usbtmc_device_data *data = usb_get_intfdata(intf);
if (count < 1)
return -EINVAL;
data->TermChar = buf[0];
return count;
}
static int usbtmc_ioctl_indicator_pulse(struct usbtmc_device_data *data)
{
struct device *dev;
u8 *buffer;
int rv;
dev = &data->intf->dev;
buffer = kmalloc(2, GFP_KERNEL);
if (!buffer)
return -ENOMEM;
rv = usb_control_msg(data->usb_dev,
usb_rcvctrlpipe(data->usb_dev, 0),
USBTMC_REQUEST_INDICATOR_PULSE,
USB_DIR_IN | USB_TYPE_CLASS | USB_RECIP_INTERFACE,
0, 0, buffer, 0x01, USBTMC_TIMEOUT);
if (rv < 0) {
dev_err(dev, "usb_control_msg returned %d\n", rv);
goto exit;
}
dev_dbg(dev, "INDICATOR_PULSE returned %x\n", buffer[0]);
if (buffer[0] != USBTMC_STATUS_SUCCESS) {
dev_err(dev, "INDICATOR_PULSE returned %x\n", buffer[0]);
rv = -EPERM;
goto exit;
}
rv = 0;
exit:
kfree(buffer);
return rv;
}
static long usbtmc_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
struct usbtmc_device_data *data;
int retval = -EBADRQC;
data = file->private_data;
mutex_lock(&data->io_mutex);
if (data->zombie) {
retval = -ENODEV;
goto skip_io_on_zombie;
}
switch (cmd) {
case USBTMC_IOCTL_CLEAR_OUT_HALT:
retval = usbtmc_ioctl_clear_out_halt(data);
break;
case USBTMC_IOCTL_CLEAR_IN_HALT:
retval = usbtmc_ioctl_clear_in_halt(data);
break;
case USBTMC_IOCTL_INDICATOR_PULSE:
retval = usbtmc_ioctl_indicator_pulse(data);
break;
case USBTMC_IOCTL_CLEAR:
retval = usbtmc_ioctl_clear(data);
break;
case USBTMC_IOCTL_ABORT_BULK_OUT:
retval = usbtmc_ioctl_abort_bulk_out(data);
break;
case USBTMC_IOCTL_ABORT_BULK_IN:
retval = usbtmc_ioctl_abort_bulk_in(data);
break;
}
skip_io_on_zombie:
mutex_unlock(&data->io_mutex);
return retval;
}
static int usbtmc_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
struct usbtmc_device_data *data;
struct usb_host_interface *iface_desc;
struct usb_endpoint_descriptor *endpoint;
int n;
int retcode;
dev_dbg(&intf->dev, "%s called\n", __func__);
data = devm_kzalloc(&intf->dev, sizeof(*data), GFP_KERNEL);
if (!data) {
dev_err(&intf->dev, "Unable to allocate kernel memory\n");
return -ENOMEM;
}
data->intf = intf;
data->id = id;
data->usb_dev = usb_get_dev(interface_to_usbdev(intf));
usb_set_intfdata(intf, data);
kref_init(&data->kref);
mutex_init(&data->io_mutex);
data->zombie = 0;
data->rigol_quirk = 0;
dev_dbg(&intf->dev, "Trying to find if device Vendor 0x%04X Product 0x%04X has the RIGOL quirk\n",
le16_to_cpu(data->usb_dev->descriptor.idVendor),
le16_to_cpu(data->usb_dev->descriptor.idProduct));
for(n = 0; usbtmc_id_quirk[n].idVendor > 0; n++) {
if ((usbtmc_id_quirk[n].idVendor == le16_to_cpu(data->usb_dev->descriptor.idVendor)) &&
(usbtmc_id_quirk[n].idProduct == le16_to_cpu(data->usb_dev->descriptor.idProduct))) {
dev_dbg(&intf->dev, "Setting this device as having the RIGOL quirk\n");
data->rigol_quirk = 1;
break;
}
}
data->bTag = 1;
data->TermCharEnabled = 0;
data->TermChar = '\n';
iface_desc = data->intf->cur_altsetting;
for (n = 0; n < iface_desc->desc.bNumEndpoints; n++) {
endpoint = &iface_desc->endpoint[n].desc;
if (usb_endpoint_is_bulk_in(endpoint)) {
data->bulk_in = endpoint->bEndpointAddress;
dev_dbg(&intf->dev, "Found bulk in endpoint at %u\n",
data->bulk_in);
break;
}
}
for (n = 0; n < iface_desc->desc.bNumEndpoints; n++) {
endpoint = &iface_desc->endpoint[n].desc;
if (usb_endpoint_is_bulk_out(endpoint)) {
data->bulk_out = endpoint->bEndpointAddress;
dev_dbg(&intf->dev, "Found Bulk out endpoint at %u\n",
data->bulk_out);
break;
}
}
retcode = get_capabilities(data);
if (retcode)
dev_err(&intf->dev, "can't read capabilities\n");
else
retcode = sysfs_create_group(&intf->dev.kobj,
&capability_attr_grp);
retcode = sysfs_create_group(&intf->dev.kobj, &data_attr_grp);
retcode = usb_register_dev(intf, &usbtmc_class);
if (retcode) {
dev_err(&intf->dev, "Not able to get a minor"
" (base %u, slice default): %d\n", USBTMC_MINOR_BASE,
retcode);
goto error_register;
}
dev_dbg(&intf->dev, "Using minor number %d\n", intf->minor);
return 0;
error_register:
sysfs_remove_group(&intf->dev.kobj, &capability_attr_grp);
sysfs_remove_group(&intf->dev.kobj, &data_attr_grp);
kref_put(&data->kref, usbtmc_delete);
return retcode;
}
static void usbtmc_disconnect(struct usb_interface *intf)
{
struct usbtmc_device_data *data;
dev_dbg(&intf->dev, "usbtmc_disconnect called\n");
data = usb_get_intfdata(intf);
usb_deregister_dev(intf, &usbtmc_class);
sysfs_remove_group(&intf->dev.kobj, &capability_attr_grp);
sysfs_remove_group(&intf->dev.kobj, &data_attr_grp);
mutex_lock(&data->io_mutex);
data->zombie = 1;
mutex_unlock(&data->io_mutex);
kref_put(&data->kref, usbtmc_delete);
}
static int usbtmc_suspend(struct usb_interface *intf, pm_message_t message)
{
return 0;
}
static int usbtmc_resume(struct usb_interface *intf)
{
return 0;
}
