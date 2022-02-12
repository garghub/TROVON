static void usblp_dump(struct usblp *usblp)
{
int p;
dbg("usblp=0x%p", usblp);
dbg("dev=0x%p", usblp->dev);
dbg("present=%d", usblp->present);
dbg("readbuf=0x%p", usblp->readbuf);
dbg("readcount=%d", usblp->readcount);
dbg("ifnum=%d", usblp->ifnum);
for (p = USBLP_FIRST_PROTOCOL; p <= USBLP_LAST_PROTOCOL; p++) {
dbg("protocol[%d].alt_setting=%d", p, usblp->protocol[p].alt_setting);
dbg("protocol[%d].epwrite=%p", p, usblp->protocol[p].epwrite);
dbg("protocol[%d].epread=%p", p, usblp->protocol[p].epread);
}
dbg("current_protocol=%d", usblp->current_protocol);
dbg("minor=%d", usblp->minor);
dbg("wstatus=%d", usblp->wstatus);
dbg("rstatus=%d", usblp->rstatus);
dbg("quirks=%d", usblp->quirks);
dbg("used=%d", usblp->used);
dbg("bidir=%d", usblp->bidir);
dbg("device_id_string=\"%s\"",
usblp->device_id_string ?
usblp->device_id_string + 2 :
(unsigned char *)"(null)");
}
static int usblp_ctrl_msg(struct usblp *usblp, int request, int type, int dir, int recip, int value, void *buf, int len)
{
int retval;
int index = usblp->ifnum;
if ((request == USBLP_REQ_GET_ID) && (type == USB_TYPE_CLASS))
index = (usblp->ifnum<<8)|usblp->protocol[usblp->current_protocol].alt_setting;
retval = usb_control_msg(usblp->dev,
dir ? usb_rcvctrlpipe(usblp->dev, 0) : usb_sndctrlpipe(usblp->dev, 0),
request, type | dir | recip, value, index, buf, len, USBLP_CTL_TIMEOUT);
dbg("usblp_control_msg: rq: 0x%02x dir: %d recip: %d value: %d idx: %d len: %#x result: %d",
request, !!dir, recip, value, index, len, retval);
return retval < 0 ? retval : 0;
}
static void usblp_bulk_read(struct urb *urb)
{
struct usblp *usblp = urb->context;
int status = urb->status;
if (usblp->present && usblp->used) {
if (status)
printk(KERN_WARNING "usblp%d: "
"nonzero read bulk status received: %d\n",
usblp->minor, status);
}
spin_lock(&usblp->lock);
if (status < 0)
usblp->rstatus = status;
else
usblp->rstatus = urb->actual_length;
usblp->rcomplete = 1;
wake_up(&usblp->rwait);
spin_unlock(&usblp->lock);
usb_free_urb(urb);
}
static void usblp_bulk_write(struct urb *urb)
{
struct usblp *usblp = urb->context;
int status = urb->status;
if (usblp->present && usblp->used) {
if (status)
printk(KERN_WARNING "usblp%d: "
"nonzero write bulk status received: %d\n",
usblp->minor, status);
}
spin_lock(&usblp->lock);
if (status < 0)
usblp->wstatus = status;
else
usblp->wstatus = urb->actual_length;
usblp->no_paper = 0;
usblp->wcomplete = 1;
wake_up(&usblp->wwait);
spin_unlock(&usblp->lock);
usb_free_urb(urb);
}
static int usblp_check_status(struct usblp *usblp, int err)
{
unsigned char status, newerr = 0;
int error;
mutex_lock(&usblp->mut);
if ((error = usblp_read_status(usblp, usblp->statusbuf)) < 0) {
mutex_unlock(&usblp->mut);
if (printk_ratelimit())
printk(KERN_ERR
"usblp%d: error %d reading printer status\n",
usblp->minor, error);
return 0;
}
status = *usblp->statusbuf;
mutex_unlock(&usblp->mut);
if (~status & LP_PERRORP)
newerr = 3;
if (status & LP_POUTPA)
newerr = 1;
if (~status & LP_PSELECD)
newerr = 2;
if (newerr != err) {
printk(KERN_INFO "usblp%d: %s\n",
usblp->minor, usblp_messages[newerr]);
}
return newerr;
}
static int handle_bidir(struct usblp *usblp)
{
if (usblp->bidir && usblp->used) {
if (usblp_submit_read(usblp) < 0)
return -EIO;
}
return 0;
}
static int usblp_open(struct inode *inode, struct file *file)
{
int minor = iminor(inode);
struct usblp *usblp;
struct usb_interface *intf;
int retval;
if (minor < 0)
return -ENODEV;
mutex_lock(&usblp_mutex);
retval = -ENODEV;
intf = usb_find_interface(&usblp_driver, minor);
if (!intf)
goto out;
usblp = usb_get_intfdata(intf);
if (!usblp || !usblp->dev || !usblp->present)
goto out;
retval = -EBUSY;
if (usblp->used)
goto out;
retval = usb_autopm_get_interface(intf);
if (retval < 0)
goto out;
usblp->used = 1;
file->private_data = usblp;
usblp->wcomplete = 1;
usblp->wstatus = 0;
usblp->rcomplete = 0;
if (handle_bidir(usblp) < 0) {
usb_autopm_put_interface(intf);
usblp->used = 0;
file->private_data = NULL;
retval = -EIO;
}
out:
mutex_unlock(&usblp_mutex);
return retval;
}
static void usblp_cleanup(struct usblp *usblp)
{
printk(KERN_INFO "usblp%d: removed\n", usblp->minor);
kfree(usblp->readbuf);
kfree(usblp->device_id_string);
kfree(usblp->statusbuf);
kfree(usblp);
}
static void usblp_unlink_urbs(struct usblp *usblp)
{
usb_kill_anchored_urbs(&usblp->urbs);
}
static int usblp_release(struct inode *inode, struct file *file)
{
struct usblp *usblp = file->private_data;
usblp->flags &= ~LP_ABORT;
mutex_lock(&usblp_mutex);
usblp->used = 0;
if (usblp->present) {
usblp_unlink_urbs(usblp);
usb_autopm_put_interface(usblp->intf);
} else
usblp_cleanup(usblp);
mutex_unlock(&usblp_mutex);
return 0;
}
static unsigned int usblp_poll(struct file *file, struct poll_table_struct *wait)
{
int ret;
unsigned long flags;
struct usblp *usblp = file->private_data;
poll_wait(file, &usblp->rwait, wait);
poll_wait(file, &usblp->wwait, wait);
spin_lock_irqsave(&usblp->lock, flags);
ret = ((usblp->bidir && usblp->rcomplete) ? POLLIN | POLLRDNORM : 0) |
((usblp->no_paper || usblp->wcomplete) ? POLLOUT | POLLWRNORM : 0);
spin_unlock_irqrestore(&usblp->lock, flags);
return ret;
}
static long usblp_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
struct usblp *usblp = file->private_data;
int length, err, i;
unsigned char newChannel;
int status;
int twoints[2];
int retval = 0;
mutex_lock(&usblp->mut);
if (!usblp->present) {
retval = -ENODEV;
goto done;
}
dbg("usblp_ioctl: cmd=0x%x (%c nr=%d len=%d dir=%d)", cmd, _IOC_TYPE(cmd),
_IOC_NR(cmd), _IOC_SIZE(cmd), _IOC_DIR(cmd));
if (_IOC_TYPE(cmd) == 'P')
switch (_IOC_NR(cmd)) {
case IOCNR_GET_DEVICE_ID:
if (_IOC_DIR(cmd) != _IOC_READ) {
retval = -EINVAL;
goto done;
}
length = usblp_cache_device_id_string(usblp);
if (length < 0) {
retval = length;
goto done;
}
if (length > _IOC_SIZE(cmd))
length = _IOC_SIZE(cmd);
if (copy_to_user((void __user *) arg,
usblp->device_id_string,
(unsigned long) length)) {
retval = -EFAULT;
goto done;
}
break;
case IOCNR_GET_PROTOCOLS:
if (_IOC_DIR(cmd) != _IOC_READ ||
_IOC_SIZE(cmd) < sizeof(twoints)) {
retval = -EINVAL;
goto done;
}
twoints[0] = usblp->current_protocol;
twoints[1] = 0;
for (i = USBLP_FIRST_PROTOCOL;
i <= USBLP_LAST_PROTOCOL; i++) {
if (usblp->protocol[i].alt_setting >= 0)
twoints[1] |= (1<<i);
}
if (copy_to_user((void __user *)arg,
(unsigned char *)twoints,
sizeof(twoints))) {
retval = -EFAULT;
goto done;
}
break;
case IOCNR_SET_PROTOCOL:
if (_IOC_DIR(cmd) != _IOC_WRITE) {
retval = -EINVAL;
goto done;
}
#ifdef DEBUG
if (arg == -10) {
usblp_dump(usblp);
break;
}
#endif
usblp_unlink_urbs(usblp);
retval = usblp_set_protocol(usblp, arg);
if (retval < 0) {
usblp_set_protocol(usblp,
usblp->current_protocol);
}
break;
case IOCNR_HP_SET_CHANNEL:
if (_IOC_DIR(cmd) != _IOC_WRITE ||
le16_to_cpu(usblp->dev->descriptor.idVendor) != 0x03F0 ||
usblp->quirks & USBLP_QUIRK_BIDIR) {
retval = -EINVAL;
goto done;
}
err = usblp_hp_channel_change_request(usblp,
arg, &newChannel);
if (err < 0) {
dev_err(&usblp->dev->dev,
"usblp%d: error = %d setting "
"HP channel\n",
usblp->minor, err);
retval = -EIO;
goto done;
}
dbg("usblp%d requested/got HP channel %ld/%d",
usblp->minor, arg, newChannel);
break;
case IOCNR_GET_BUS_ADDRESS:
if (_IOC_DIR(cmd) != _IOC_READ ||
_IOC_SIZE(cmd) < sizeof(twoints)) {
retval = -EINVAL;
goto done;
}
twoints[0] = usblp->dev->bus->busnum;
twoints[1] = usblp->dev->devnum;
if (copy_to_user((void __user *)arg,
(unsigned char *)twoints,
sizeof(twoints))) {
retval = -EFAULT;
goto done;
}
dbg("usblp%d is bus=%d, device=%d",
usblp->minor, twoints[0], twoints[1]);
break;
case IOCNR_GET_VID_PID:
if (_IOC_DIR(cmd) != _IOC_READ ||
_IOC_SIZE(cmd) < sizeof(twoints)) {
retval = -EINVAL;
goto done;
}
twoints[0] = le16_to_cpu(usblp->dev->descriptor.idVendor);
twoints[1] = le16_to_cpu(usblp->dev->descriptor.idProduct);
if (copy_to_user((void __user *)arg,
(unsigned char *)twoints,
sizeof(twoints))) {
retval = -EFAULT;
goto done;
}
dbg("usblp%d is VID=0x%4.4X, PID=0x%4.4X",
usblp->minor, twoints[0], twoints[1]);
break;
case IOCNR_SOFT_RESET:
if (_IOC_DIR(cmd) != _IOC_NONE) {
retval = -EINVAL;
goto done;
}
retval = usblp_reset(usblp);
break;
default:
retval = -ENOTTY;
}
else
switch (cmd) {
case LPGETSTATUS:
if ((retval = usblp_read_status(usblp, usblp->statusbuf))) {
if (printk_ratelimit())
printk(KERN_ERR "usblp%d:"
"failed reading printer status (%d)\n",
usblp->minor, retval);
retval = -EIO;
goto done;
}
status = *usblp->statusbuf;
if (copy_to_user((void __user *)arg, &status, sizeof(int)))
retval = -EFAULT;
break;
case LPABORT:
if (arg)
usblp->flags |= LP_ABORT;
else
usblp->flags &= ~LP_ABORT;
break;
default:
retval = -ENOTTY;
}
done:
mutex_unlock(&usblp->mut);
return retval;
}
static struct urb *usblp_new_writeurb(struct usblp *usblp, int transfer_length)
{
struct urb *urb;
char *writebuf;
if ((writebuf = kmalloc(transfer_length, GFP_KERNEL)) == NULL)
return NULL;
if ((urb = usb_alloc_urb(0, GFP_KERNEL)) == NULL) {
kfree(writebuf);
return NULL;
}
usb_fill_bulk_urb(urb, usblp->dev,
usb_sndbulkpipe(usblp->dev,
usblp->protocol[usblp->current_protocol].epwrite->bEndpointAddress),
writebuf, transfer_length, usblp_bulk_write, usblp);
urb->transfer_flags |= URB_FREE_BUFFER;
return urb;
}
static ssize_t usblp_write(struct file *file, const char __user *buffer, size_t count, loff_t *ppos)
{
struct usblp *usblp = file->private_data;
struct urb *writeurb;
int rv;
int transfer_length;
ssize_t writecount = 0;
if (mutex_lock_interruptible(&usblp->wmut)) {
rv = -EINTR;
goto raise_biglock;
}
if ((rv = usblp_wwait(usblp, !!(file->f_flags & O_NONBLOCK))) < 0)
goto raise_wait;
while (writecount < count) {
if ((transfer_length = count - writecount) > USBLP_BUF_SIZE)
transfer_length = USBLP_BUF_SIZE;
rv = -ENOMEM;
if ((writeurb = usblp_new_writeurb(usblp, transfer_length)) == NULL)
goto raise_urb;
usb_anchor_urb(writeurb, &usblp->urbs);
if (copy_from_user(writeurb->transfer_buffer,
buffer + writecount, transfer_length)) {
rv = -EFAULT;
goto raise_badaddr;
}
spin_lock_irq(&usblp->lock);
usblp->wcomplete = 0;
spin_unlock_irq(&usblp->lock);
if ((rv = usb_submit_urb(writeurb, GFP_KERNEL)) < 0) {
usblp->wstatus = 0;
spin_lock_irq(&usblp->lock);
usblp->no_paper = 0;
usblp->wcomplete = 1;
wake_up(&usblp->wwait);
spin_unlock_irq(&usblp->lock);
if (rv != -ENOMEM)
rv = -EIO;
goto raise_submit;
}
rv = usblp_wwait(usblp, !!(file->f_flags&O_NONBLOCK));
if (rv < 0) {
if (rv == -EAGAIN) {
writecount += transfer_length;
}
if (rv == -ENOSPC) {
spin_lock_irq(&usblp->lock);
usblp->no_paper = 1;
spin_unlock_irq(&usblp->lock);
writecount += transfer_length;
}
goto collect_error;
}
if (usblp->wstatus < 0) {
rv = -EIO;
goto collect_error;
}
writecount += usblp->wstatus;
}
mutex_unlock(&usblp->wmut);
return writecount;
raise_submit:
raise_badaddr:
usb_unanchor_urb(writeurb);
usb_free_urb(writeurb);
raise_urb:
raise_wait:
collect_error:
mutex_unlock(&usblp->wmut);
raise_biglock:
return writecount ? writecount : rv;
}
static ssize_t usblp_read(struct file *file, char __user *buffer, size_t len, loff_t *ppos)
{
struct usblp *usblp = file->private_data;
ssize_t count;
ssize_t avail;
int rv;
if (!usblp->bidir)
return -EINVAL;
rv = usblp_rwait_and_lock(usblp, !!(file->f_flags & O_NONBLOCK));
if (rv < 0)
return rv;
if ((avail = usblp->rstatus) < 0) {
printk(KERN_ERR "usblp%d: error %d reading from printer\n",
usblp->minor, (int)avail);
usblp_submit_read(usblp);
count = -EIO;
goto done;
}
count = len < avail - usblp->readcount ? len : avail - usblp->readcount;
if (count != 0 &&
copy_to_user(buffer, usblp->readbuf + usblp->readcount, count)) {
count = -EFAULT;
goto done;
}
if ((usblp->readcount += count) == avail) {
if (usblp_submit_read(usblp) < 0) {
if (count == 0)
count = -EIO;
goto done;
}
}
done:
mutex_unlock(&usblp->mut);
return count;
}
static int usblp_wwait(struct usblp *usblp, int nonblock)
{
DECLARE_WAITQUEUE(waita, current);
int rc;
int err = 0;
add_wait_queue(&usblp->wwait, &waita);
for (;;) {
set_current_state(TASK_INTERRUPTIBLE);
if (mutex_lock_interruptible(&usblp->mut)) {
rc = -EINTR;
break;
}
rc = usblp_wtest(usblp, nonblock);
mutex_unlock(&usblp->mut);
if (rc <= 0)
break;
if (schedule_timeout(msecs_to_jiffies(1500)) == 0) {
if (usblp->flags & LP_ABORT) {
err = usblp_check_status(usblp, err);
if (err == 1) {
rc = -ENOSPC;
break;
}
} else {
mutex_lock(&usblp->mut);
usblp_read_status(usblp, usblp->statusbuf);
mutex_unlock(&usblp->mut);
}
}
}
set_current_state(TASK_RUNNING);
remove_wait_queue(&usblp->wwait, &waita);
return rc;
}
static int usblp_wtest(struct usblp *usblp, int nonblock)
{
unsigned long flags;
if (!usblp->present)
return -ENODEV;
if (signal_pending(current))
return -EINTR;
spin_lock_irqsave(&usblp->lock, flags);
if (usblp->wcomplete) {
spin_unlock_irqrestore(&usblp->lock, flags);
return 0;
}
spin_unlock_irqrestore(&usblp->lock, flags);
if (nonblock)
return -EAGAIN;
return 1;
}
static int usblp_rwait_and_lock(struct usblp *usblp, int nonblock)
{
DECLARE_WAITQUEUE(waita, current);
int rc;
add_wait_queue(&usblp->rwait, &waita);
for (;;) {
if (mutex_lock_interruptible(&usblp->mut)) {
rc = -EINTR;
break;
}
set_current_state(TASK_INTERRUPTIBLE);
if ((rc = usblp_rtest(usblp, nonblock)) < 0) {
mutex_unlock(&usblp->mut);
break;
}
if (rc == 0)
break;
mutex_unlock(&usblp->mut);
schedule();
}
set_current_state(TASK_RUNNING);
remove_wait_queue(&usblp->rwait, &waita);
return rc;
}
static int usblp_rtest(struct usblp *usblp, int nonblock)
{
unsigned long flags;
if (!usblp->present)
return -ENODEV;
if (signal_pending(current))
return -EINTR;
spin_lock_irqsave(&usblp->lock, flags);
if (usblp->rcomplete) {
spin_unlock_irqrestore(&usblp->lock, flags);
return 0;
}
spin_unlock_irqrestore(&usblp->lock, flags);
if (nonblock)
return -EAGAIN;
return 1;
}
static int usblp_submit_read(struct usblp *usblp)
{
struct urb *urb;
unsigned long flags;
int rc;
rc = -ENOMEM;
if ((urb = usb_alloc_urb(0, GFP_KERNEL)) == NULL)
goto raise_urb;
usb_fill_bulk_urb(urb, usblp->dev,
usb_rcvbulkpipe(usblp->dev,
usblp->protocol[usblp->current_protocol].epread->bEndpointAddress),
usblp->readbuf, USBLP_BUF_SIZE_IN,
usblp_bulk_read, usblp);
usb_anchor_urb(urb, &usblp->urbs);
spin_lock_irqsave(&usblp->lock, flags);
usblp->readcount = 0;
usblp->rcomplete = 0;
spin_unlock_irqrestore(&usblp->lock, flags);
if ((rc = usb_submit_urb(urb, GFP_KERNEL)) < 0) {
dbg("error submitting urb (%d)", rc);
spin_lock_irqsave(&usblp->lock, flags);
usblp->rstatus = rc;
usblp->rcomplete = 1;
spin_unlock_irqrestore(&usblp->lock, flags);
goto raise_submit;
}
return 0;
raise_submit:
usb_unanchor_urb(urb);
usb_free_urb(urb);
raise_urb:
return rc;
}
static unsigned int usblp_quirks(__u16 vendor, __u16 product)
{
int i;
for (i = 0; quirk_printers[i].vendorId; i++) {
if (vendor == quirk_printers[i].vendorId &&
product == quirk_printers[i].productId)
return quirk_printers[i].quirks;
}
return 0;
}
static char *usblp_devnode(struct device *dev, mode_t *mode)
{
return kasprintf(GFP_KERNEL, "usb/%s", dev_name(dev));
}
static ssize_t usblp_show_ieee1284_id(struct device *dev, struct device_attribute *attr, char *buf)
{
struct usb_interface *intf = to_usb_interface(dev);
struct usblp *usblp = usb_get_intfdata(intf);
if (usblp->device_id_string[0] == 0 &&
usblp->device_id_string[1] == 0)
return 0;
return sprintf(buf, "%s", usblp->device_id_string+2);
}
static int usblp_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
struct usb_device *dev = interface_to_usbdev(intf);
struct usblp *usblp;
int protocol;
int retval;
usblp = kzalloc(sizeof(struct usblp), GFP_KERNEL);
if (!usblp) {
retval = -ENOMEM;
goto abort_ret;
}
usblp->dev = dev;
mutex_init(&usblp->wmut);
mutex_init(&usblp->mut);
spin_lock_init(&usblp->lock);
init_waitqueue_head(&usblp->rwait);
init_waitqueue_head(&usblp->wwait);
init_usb_anchor(&usblp->urbs);
usblp->ifnum = intf->cur_altsetting->desc.bInterfaceNumber;
usblp->intf = intf;
if (!(usblp->device_id_string = kmalloc(USBLP_DEVICE_ID_SIZE, GFP_KERNEL))) {
retval = -ENOMEM;
goto abort;
}
if (!(usblp->readbuf = kmalloc(USBLP_BUF_SIZE_IN, GFP_KERNEL))) {
retval = -ENOMEM;
goto abort;
}
usblp->statusbuf = kmalloc(STATUS_BUF_SIZE, GFP_KERNEL);
if (!usblp->statusbuf) {
retval = -ENOMEM;
goto abort;
}
usblp->quirks = usblp_quirks(
le16_to_cpu(dev->descriptor.idVendor),
le16_to_cpu(dev->descriptor.idProduct));
protocol = usblp_select_alts(usblp);
if (protocol < 0) {
dbg("incompatible printer-class device 0x%4.4X/0x%4.4X",
le16_to_cpu(dev->descriptor.idVendor),
le16_to_cpu(dev->descriptor.idProduct));
retval = -ENODEV;
goto abort;
}
if (usblp_set_protocol(usblp, protocol) < 0) {
retval = -ENODEV;
goto abort;
}
usblp_cache_device_id_string(usblp);
retval = device_create_file(&intf->dev, &dev_attr_ieee1284_id);
if (retval)
goto abort_intfdata;
#ifdef DEBUG
usblp_check_status(usblp, 0);
#endif
usb_set_intfdata(intf, usblp);
usblp->present = 1;
retval = usb_register_dev(intf, &usblp_class);
if (retval) {
printk(KERN_ERR "usblp: Not able to get a minor"
" (base %u, slice default): %d\n",
USBLP_MINOR_BASE, retval);
goto abort_intfdata;
}
usblp->minor = intf->minor;
printk(KERN_INFO "usblp%d: USB %sdirectional printer dev %d "
"if %d alt %d proto %d vid 0x%4.4X pid 0x%4.4X\n",
usblp->minor, usblp->bidir ? "Bi" : "Uni", dev->devnum,
usblp->ifnum,
usblp->protocol[usblp->current_protocol].alt_setting,
usblp->current_protocol,
le16_to_cpu(usblp->dev->descriptor.idVendor),
le16_to_cpu(usblp->dev->descriptor.idProduct));
return 0;
abort_intfdata:
usb_set_intfdata(intf, NULL);
device_remove_file(&intf->dev, &dev_attr_ieee1284_id);
abort:
kfree(usblp->readbuf);
kfree(usblp->statusbuf);
kfree(usblp->device_id_string);
kfree(usblp);
abort_ret:
return retval;
}
static int usblp_select_alts(struct usblp *usblp)
{
struct usb_interface *if_alt;
struct usb_host_interface *ifd;
struct usb_endpoint_descriptor *epd, *epwrite, *epread;
int p, i, e;
if_alt = usblp->intf;
for (p = 0; p < USBLP_MAX_PROTOCOLS; p++)
usblp->protocol[p].alt_setting = -1;
for (i = 0; i < if_alt->num_altsetting; i++) {
ifd = &if_alt->altsetting[i];
if (ifd->desc.bInterfaceClass != 7 || ifd->desc.bInterfaceSubClass != 1)
if (!(usblp->quirks & USBLP_QUIRK_BAD_CLASS))
continue;
if (ifd->desc.bInterfaceProtocol < USBLP_FIRST_PROTOCOL ||
ifd->desc.bInterfaceProtocol > USBLP_LAST_PROTOCOL)
continue;
epwrite = epread = NULL;
for (e = 0; e < ifd->desc.bNumEndpoints; e++) {
epd = &ifd->endpoint[e].desc;
if (usb_endpoint_is_bulk_out(epd))
if (!epwrite)
epwrite = epd;
if (usb_endpoint_is_bulk_in(epd))
if (!epread)
epread = epd;
}
if (!epwrite || (ifd->desc.bInterfaceProtocol > 1 && !epread))
continue;
if (ifd->desc.bInterfaceProtocol == 1) {
epread = NULL;
} else if (usblp->quirks & USBLP_QUIRK_BIDIR) {
printk(KERN_INFO "usblp%d: Disabling reads from "
"problematic bidirectional printer\n",
usblp->minor);
epread = NULL;
}
usblp->protocol[ifd->desc.bInterfaceProtocol].alt_setting =
ifd->desc.bAlternateSetting;
usblp->protocol[ifd->desc.bInterfaceProtocol].epwrite = epwrite;
usblp->protocol[ifd->desc.bInterfaceProtocol].epread = epread;
}
if (proto_bias >= USBLP_FIRST_PROTOCOL &&
proto_bias <= USBLP_LAST_PROTOCOL &&
usblp->protocol[proto_bias].alt_setting != -1)
return proto_bias;
if (usblp->protocol[2].alt_setting != -1)
return 2;
if (usblp->protocol[1].alt_setting != -1)
return 1;
if (usblp->protocol[3].alt_setting != -1)
return 3;
return -1;
}
static int usblp_set_protocol(struct usblp *usblp, int protocol)
{
int r, alts;
if (protocol < USBLP_FIRST_PROTOCOL || protocol > USBLP_LAST_PROTOCOL)
return -EINVAL;
alts = usblp->protocol[protocol].alt_setting;
if (alts < 0)
return -EINVAL;
r = usb_set_interface(usblp->dev, usblp->ifnum, alts);
if (r < 0) {
printk(KERN_ERR "usblp: can't set desired altsetting %d on interface %d\n",
alts, usblp->ifnum);
return r;
}
usblp->bidir = (usblp->protocol[protocol].epread != NULL);
usblp->current_protocol = protocol;
dbg("usblp%d set protocol %d", usblp->minor, protocol);
return 0;
}
static int usblp_cache_device_id_string(struct usblp *usblp)
{
int err, length;
err = usblp_get_id(usblp, 0, usblp->device_id_string, USBLP_DEVICE_ID_SIZE - 1);
if (err < 0) {
dbg("usblp%d: error = %d reading IEEE-1284 Device ID string",
usblp->minor, err);
usblp->device_id_string[0] = usblp->device_id_string[1] = '\0';
return -EIO;
}
length = be16_to_cpu(*((__be16 *)usblp->device_id_string));
if (length < 2)
length = 2;
else if (length >= USBLP_DEVICE_ID_SIZE)
length = USBLP_DEVICE_ID_SIZE - 1;
usblp->device_id_string[length] = '\0';
dbg("usblp%d Device ID string [len=%d]=\"%s\"",
usblp->minor, length, &usblp->device_id_string[2]);
return length;
}
static void usblp_disconnect(struct usb_interface *intf)
{
struct usblp *usblp = usb_get_intfdata(intf);
usb_deregister_dev(intf, &usblp_class);
if (!usblp || !usblp->dev) {
dev_err(&intf->dev, "bogus disconnect\n");
BUG();
}
device_remove_file(&intf->dev, &dev_attr_ieee1284_id);
mutex_lock(&usblp_mutex);
mutex_lock(&usblp->mut);
usblp->present = 0;
wake_up(&usblp->wwait);
wake_up(&usblp->rwait);
usb_set_intfdata(intf, NULL);
usblp_unlink_urbs(usblp);
mutex_unlock(&usblp->mut);
if (!usblp->used)
usblp_cleanup(usblp);
mutex_unlock(&usblp_mutex);
}
static int usblp_suspend(struct usb_interface *intf, pm_message_t message)
{
struct usblp *usblp = usb_get_intfdata(intf);
usblp_unlink_urbs(usblp);
#if 0
wake_up(&usblp->wwait);
wake_up(&usblp->rwait);
#endif
return 0;
}
static int usblp_resume(struct usb_interface *intf)
{
struct usblp *usblp = usb_get_intfdata(intf);
int r;
r = handle_bidir(usblp);
return r;
}
static int __init usblp_init(void)
{
return usb_register(&usblp_driver);
}
static void __exit usblp_exit(void)
{
usb_deregister(&usblp_driver);
}
