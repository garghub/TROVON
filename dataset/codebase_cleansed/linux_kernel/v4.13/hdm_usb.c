static inline int drci_rd_reg(struct usb_device *dev, u16 reg, u16 *buf)
{
int retval;
__le16 *dma_buf = kzalloc(sizeof(*dma_buf), GFP_KERNEL);
u8 req_type = USB_DIR_IN | USB_TYPE_VENDOR | USB_RECIP_DEVICE;
if (!dma_buf)
return -ENOMEM;
retval = usb_control_msg(dev, usb_rcvctrlpipe(dev, 0),
DRCI_READ_REQ, req_type,
0x0000,
reg, dma_buf, sizeof(*dma_buf), 5 * HZ);
*buf = le16_to_cpu(*dma_buf);
kfree(dma_buf);
return retval;
}
static inline int drci_wr_reg(struct usb_device *dev, u16 reg, u16 data)
{
return usb_control_msg(dev,
usb_sndctrlpipe(dev, 0),
DRCI_WRITE_REQ,
USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
data,
reg,
NULL,
0,
5 * HZ);
}
static inline int start_sync_ep(struct usb_device *usb_dev, u16 ep)
{
return drci_wr_reg(usb_dev, DRCI_REG_BASE + DRCI_COMMAND + ep * 16, 1);
}
static unsigned int get_stream_frame_size(struct most_channel_config *cfg)
{
unsigned int frame_size = 0;
unsigned int sub_size = cfg->subbuffer_size;
if (!sub_size) {
pr_warn("Misconfig: Subbuffer size zero.\n");
return frame_size;
}
switch (cfg->data_type) {
case MOST_CH_ISOC:
frame_size = AV_PACKETS_PER_XACT * sub_size;
break;
case MOST_CH_SYNC:
if (cfg->packets_per_xact == 0) {
pr_warn("Misconfig: Packets per XACT zero\n");
frame_size = 0;
} else if (cfg->packets_per_xact == 0xFF) {
frame_size = (USB_MTU / sub_size) * sub_size;
} else {
frame_size = cfg->packets_per_xact * sub_size;
}
break;
default:
pr_warn("Query frame size of non-streaming channel\n");
break;
}
return frame_size;
}
static int hdm_poison_channel(struct most_interface *iface, int channel)
{
struct most_dev *mdev = to_mdev(iface);
unsigned long flags;
spinlock_t *lock;
if (unlikely(!iface)) {
dev_warn(&mdev->usb_device->dev, "Poison: Bad interface.\n");
return -EIO;
}
if (unlikely(channel < 0 || channel >= iface->num_channels)) {
dev_warn(&mdev->usb_device->dev, "Channel ID out of range.\n");
return -ECHRNG;
}
lock = mdev->channel_lock + channel;
spin_lock_irqsave(lock, flags);
mdev->is_channel_healthy[channel] = false;
spin_unlock_irqrestore(lock, flags);
cancel_work_sync(&mdev->clear_work[channel].ws);
mutex_lock(&mdev->io_mutex);
usb_kill_anchored_urbs(&mdev->busy_urbs[channel]);
if (mdev->padding_active[channel])
mdev->padding_active[channel] = false;
if (mdev->conf[channel].data_type == MOST_CH_ASYNC) {
del_timer_sync(&mdev->link_stat_timer);
cancel_work_sync(&mdev->poll_work_obj);
}
mutex_unlock(&mdev->io_mutex);
return 0;
}
static int hdm_add_padding(struct most_dev *mdev, int channel, struct mbo *mbo)
{
struct most_channel_config *conf = &mdev->conf[channel];
unsigned int frame_size = get_stream_frame_size(conf);
unsigned int j, num_frames;
if (!frame_size)
return -EIO;
num_frames = mbo->buffer_length / frame_size;
if (num_frames < 1) {
dev_err(&mdev->usb_device->dev,
"Missed minimal transfer unit.\n");
return -EIO;
}
for (j = num_frames - 1; j > 0; j--)
memmove(mbo->virt_address + j * USB_MTU,
mbo->virt_address + j * frame_size,
frame_size);
mbo->buffer_length = num_frames * USB_MTU;
return 0;
}
static int hdm_remove_padding(struct most_dev *mdev, int channel,
struct mbo *mbo)
{
struct most_channel_config *const conf = &mdev->conf[channel];
unsigned int frame_size = get_stream_frame_size(conf);
unsigned int j, num_frames;
if (!frame_size)
return -EIO;
num_frames = mbo->processed_length / USB_MTU;
for (j = 1; j < num_frames; j++)
memmove(mbo->virt_address + frame_size * j,
mbo->virt_address + USB_MTU * j,
frame_size);
mbo->processed_length = frame_size * num_frames;
return 0;
}
static void hdm_write_completion(struct urb *urb)
{
struct mbo *mbo = urb->context;
struct most_dev *mdev = to_mdev(mbo->ifp);
unsigned int channel = mbo->hdm_channel_id;
struct device *dev = &mdev->usb_device->dev;
spinlock_t *lock = mdev->channel_lock + channel;
unsigned long flags;
spin_lock_irqsave(lock, flags);
mbo->processed_length = 0;
mbo->status = MBO_E_INVAL;
if (likely(mdev->is_channel_healthy[channel])) {
switch (urb->status) {
case 0:
case -ESHUTDOWN:
mbo->processed_length = urb->actual_length;
mbo->status = MBO_SUCCESS;
break;
case -EPIPE:
dev_warn(dev, "Broken OUT pipe detected\n");
mdev->is_channel_healthy[channel] = false;
mdev->clear_work[channel].pipe = urb->pipe;
schedule_work(&mdev->clear_work[channel].ws);
break;
case -ENODEV:
case -EPROTO:
mbo->status = MBO_E_CLOSE;
break;
}
}
spin_unlock_irqrestore(lock, flags);
if (likely(mbo->complete))
mbo->complete(mbo);
usb_free_urb(urb);
}
static void hdm_read_completion(struct urb *urb)
{
struct mbo *mbo = urb->context;
struct most_dev *mdev = to_mdev(mbo->ifp);
unsigned int channel = mbo->hdm_channel_id;
struct device *dev = &mdev->usb_device->dev;
spinlock_t *lock = mdev->channel_lock + channel;
unsigned long flags;
spin_lock_irqsave(lock, flags);
mbo->processed_length = 0;
mbo->status = MBO_E_INVAL;
if (likely(mdev->is_channel_healthy[channel])) {
switch (urb->status) {
case 0:
case -ESHUTDOWN:
mbo->processed_length = urb->actual_length;
mbo->status = MBO_SUCCESS;
if (mdev->padding_active[channel] &&
hdm_remove_padding(mdev, channel, mbo)) {
mbo->processed_length = 0;
mbo->status = MBO_E_INVAL;
}
break;
case -EPIPE:
dev_warn(dev, "Broken IN pipe detected\n");
mdev->is_channel_healthy[channel] = false;
mdev->clear_work[channel].pipe = urb->pipe;
schedule_work(&mdev->clear_work[channel].ws);
break;
case -ENODEV:
case -EPROTO:
mbo->status = MBO_E_CLOSE;
break;
case -EOVERFLOW:
dev_warn(dev, "Babble on IN pipe detected\n");
break;
}
}
spin_unlock_irqrestore(lock, flags);
if (likely(mbo->complete))
mbo->complete(mbo);
usb_free_urb(urb);
}
static int hdm_enqueue(struct most_interface *iface, int channel,
struct mbo *mbo)
{
struct most_dev *mdev;
struct most_channel_config *conf;
struct device *dev;
int retval = 0;
struct urb *urb;
unsigned long length;
void *virt_address;
if (unlikely(!iface || !mbo))
return -EIO;
if (unlikely(iface->num_channels <= channel || channel < 0))
return -ECHRNG;
mdev = to_mdev(iface);
conf = &mdev->conf[channel];
dev = &mdev->usb_device->dev;
if (!mdev->usb_device)
return -ENODEV;
urb = usb_alloc_urb(NO_ISOCHRONOUS_URB, GFP_ATOMIC);
if (!urb)
return -ENOMEM;
if ((conf->direction & MOST_CH_TX) && mdev->padding_active[channel] &&
hdm_add_padding(mdev, channel, mbo)) {
retval = -EIO;
goto _error;
}
urb->transfer_dma = mbo->bus_address;
virt_address = mbo->virt_address;
length = mbo->buffer_length;
if (conf->direction & MOST_CH_TX) {
usb_fill_bulk_urb(urb, mdev->usb_device,
usb_sndbulkpipe(mdev->usb_device,
mdev->ep_address[channel]),
virt_address,
length,
hdm_write_completion,
mbo);
if (conf->data_type != MOST_CH_ISOC)
urb->transfer_flags |= URB_ZERO_PACKET;
} else {
usb_fill_bulk_urb(urb, mdev->usb_device,
usb_rcvbulkpipe(mdev->usb_device,
mdev->ep_address[channel]),
virt_address,
length + conf->extra_len,
hdm_read_completion,
mbo);
}
urb->transfer_flags |= URB_NO_TRANSFER_DMA_MAP;
usb_anchor_urb(urb, &mdev->busy_urbs[channel]);
retval = usb_submit_urb(urb, GFP_KERNEL);
if (retval) {
dev_err(dev, "URB submit failed with error %d.\n", retval);
goto _error_1;
}
return 0;
_error_1:
usb_unanchor_urb(urb);
_error:
usb_free_urb(urb);
return retval;
}
static int hdm_configure_channel(struct most_interface *iface, int channel,
struct most_channel_config *conf)
{
unsigned int num_frames;
unsigned int frame_size;
struct most_dev *mdev = to_mdev(iface);
struct device *dev = &mdev->usb_device->dev;
mdev->is_channel_healthy[channel] = true;
mdev->clear_work[channel].channel = channel;
mdev->clear_work[channel].mdev = mdev;
INIT_WORK(&mdev->clear_work[channel].ws, wq_clear_halt);
if (unlikely(!iface || !conf)) {
dev_err(dev, "Bad interface or config pointer.\n");
return -EINVAL;
}
if (unlikely(channel < 0 || channel >= iface->num_channels)) {
dev_err(dev, "Channel ID out of range.\n");
return -EINVAL;
}
if (!conf->num_buffers || !conf->buffer_size) {
dev_err(dev, "Misconfig: buffer size or #buffers zero.\n");
return -EINVAL;
}
if (conf->data_type != MOST_CH_SYNC &&
!(conf->data_type == MOST_CH_ISOC &&
conf->packets_per_xact != 0xFF)) {
mdev->padding_active[channel] = false;
goto exit;
}
mdev->padding_active[channel] = true;
frame_size = get_stream_frame_size(conf);
if (frame_size == 0 || frame_size > USB_MTU) {
dev_warn(dev, "Misconfig: frame size wrong\n");
return -EINVAL;
}
num_frames = conf->buffer_size / frame_size;
if (conf->buffer_size % frame_size) {
u16 old_size = conf->buffer_size;
conf->buffer_size = num_frames * frame_size;
dev_warn(dev, "%s: fixed buffer size (%d -> %d)\n",
mdev->suffix[channel], old_size, conf->buffer_size);
}
conf->extra_len = num_frames * (USB_MTU - frame_size);
exit:
mdev->conf[channel] = *conf;
if (conf->data_type == MOST_CH_ASYNC) {
u16 ep = mdev->ep_address[channel];
if (start_sync_ep(mdev->usb_device, ep) < 0)
dev_warn(dev, "sync for ep%02x failed", ep);
}
return 0;
}
static void hdm_request_netinfo(struct most_interface *iface, int channel,
void (*on_netinfo)(struct most_interface *,
unsigned char,
unsigned char *))
{
struct most_dev *mdev;
BUG_ON(!iface);
mdev = to_mdev(iface);
mdev->on_netinfo = on_netinfo;
if (!on_netinfo)
return;
mdev->link_stat_timer.expires = jiffies + HZ;
mod_timer(&mdev->link_stat_timer, mdev->link_stat_timer.expires);
}
static void link_stat_timer_handler(unsigned long data)
{
struct most_dev *mdev = (struct most_dev *)data;
schedule_work(&mdev->poll_work_obj);
mdev->link_stat_timer.expires = jiffies + (2 * HZ);
add_timer(&mdev->link_stat_timer);
}
static void wq_netinfo(struct work_struct *wq_obj)
{
struct most_dev *mdev = to_mdev_from_work(wq_obj);
struct usb_device *usb_device = mdev->usb_device;
struct device *dev = &usb_device->dev;
u16 hi, mi, lo, link;
u8 hw_addr[6];
if (drci_rd_reg(usb_device, DRCI_REG_HW_ADDR_HI, &hi) < 0) {
dev_err(dev, "Vendor request 'hw_addr_hi' failed\n");
return;
}
if (drci_rd_reg(usb_device, DRCI_REG_HW_ADDR_MI, &mi) < 0) {
dev_err(dev, "Vendor request 'hw_addr_mid' failed\n");
return;
}
if (drci_rd_reg(usb_device, DRCI_REG_HW_ADDR_LO, &lo) < 0) {
dev_err(dev, "Vendor request 'hw_addr_low' failed\n");
return;
}
if (drci_rd_reg(usb_device, DRCI_REG_NI_STATE, &link) < 0) {
dev_err(dev, "Vendor request 'link status' failed\n");
return;
}
hw_addr[0] = hi >> 8;
hw_addr[1] = hi;
hw_addr[2] = mi >> 8;
hw_addr[3] = mi;
hw_addr[4] = lo >> 8;
hw_addr[5] = lo;
if (mdev->on_netinfo)
mdev->on_netinfo(&mdev->iface, link, hw_addr);
}
static void wq_clear_halt(struct work_struct *wq_obj)
{
struct clear_hold_work *clear_work = to_clear_hold_work(wq_obj);
struct most_dev *mdev = clear_work->mdev;
unsigned int channel = clear_work->channel;
int pipe = clear_work->pipe;
mutex_lock(&mdev->io_mutex);
most_stop_enqueue(&mdev->iface, channel);
usb_kill_anchored_urbs(&mdev->busy_urbs[channel]);
if (usb_clear_halt(mdev->usb_device, pipe))
dev_warn(&mdev->usb_device->dev, "Failed to reset endpoint.\n");
mdev->is_channel_healthy[channel] = true;
most_resume_enqueue(&mdev->iface, channel);
mutex_unlock(&mdev->io_mutex);
}
static ssize_t dci_attr_show(struct kobject *kobj, struct attribute *attr,
char *buf)
{
struct most_dci_attribute *dci_attr = to_dci_attr(attr);
struct most_dci_obj *dci_obj = to_dci_obj(kobj);
if (!dci_attr->show)
return -EIO;
return dci_attr->show(dci_obj, dci_attr, buf);
}
static ssize_t dci_attr_store(struct kobject *kobj,
struct attribute *attr,
const char *buf,
size_t len)
{
struct most_dci_attribute *dci_attr = to_dci_attr(attr);
struct most_dci_obj *dci_obj = to_dci_obj(kobj);
if (!dci_attr->store)
return -EIO;
return dci_attr->store(dci_obj, dci_attr, buf, len);
}
static void most_dci_release(struct kobject *kobj)
{
struct most_dci_obj *dci_obj = to_dci_obj(kobj);
kfree(dci_obj);
}
static int get_stat_reg_addr(const struct regs *regs, int size,
const char *name, u16 *reg_addr)
{
int i;
for (i = 0; i < size; i++) {
if (!strcmp(name, regs[i].name)) {
*reg_addr = regs[i].reg;
return 0;
}
}
return -EFAULT;
}
static ssize_t show_value(struct most_dci_obj *dci_obj,
struct most_dci_attribute *attr, char *buf)
{
const char *name = attr->attr.name;
u16 val;
u16 reg_addr;
int err;
if (!strcmp(name, "arb_address"))
return snprintf(buf, PAGE_SIZE, "%04x\n", dci_obj->reg_addr);
if (!strcmp(name, "arb_value"))
reg_addr = dci_obj->reg_addr;
else if (get_static_reg_addr(ro_regs, name, &reg_addr) &&
get_static_reg_addr(rw_regs, name, &reg_addr))
return -EFAULT;
err = drci_rd_reg(dci_obj->usb_device, reg_addr, &val);
if (err < 0)
return err;
return snprintf(buf, PAGE_SIZE, "%04x\n", val);
}
static ssize_t store_value(struct most_dci_obj *dci_obj,
struct most_dci_attribute *attr,
const char *buf, size_t count)
{
u16 val;
u16 reg_addr;
const char *name = attr->attr.name;
struct usb_device *usb_dev = dci_obj->usb_device;
int err = kstrtou16(buf, 16, &val);
if (err)
return err;
if (!strcmp(name, "arb_address")) {
dci_obj->reg_addr = val;
return count;
}
if (!strcmp(name, "arb_value"))
err = drci_wr_reg(usb_dev, dci_obj->reg_addr, val);
else if (!strcmp(name, "sync_ep"))
err = start_sync_ep(usb_dev, val);
else if (!get_static_reg_addr(rw_regs, name, &reg_addr))
err = drci_wr_reg(usb_dev, reg_addr, val);
else
return -EFAULT;
if (err < 0)
return err;
return count;
}
static struct
most_dci_obj *create_most_dci_obj(struct kobject *parent)
{
struct most_dci_obj *most_dci = kzalloc(sizeof(*most_dci), GFP_KERNEL);
int retval;
if (!most_dci)
return NULL;
retval = kobject_init_and_add(&most_dci->kobj, &most_dci_ktype, parent,
"dci");
if (retval) {
kobject_put(&most_dci->kobj);
return NULL;
}
return most_dci;
}
static void destroy_most_dci_obj(struct most_dci_obj *p)
{
kobject_put(&p->kobj);
}
static int
hdm_probe(struct usb_interface *interface, const struct usb_device_id *id)
{
struct usb_host_interface *usb_iface_desc = interface->cur_altsetting;
struct usb_device *usb_dev = interface_to_usbdev(interface);
struct device *dev = &usb_dev->dev;
struct most_dev *mdev = kzalloc(sizeof(*mdev), GFP_KERNEL);
unsigned int i;
unsigned int num_endpoints;
struct most_channel_capability *tmp_cap;
struct usb_endpoint_descriptor *ep_desc;
int ret = 0;
if (!mdev)
goto exit_ENOMEM;
usb_set_intfdata(interface, mdev);
num_endpoints = usb_iface_desc->desc.bNumEndpoints;
mutex_init(&mdev->io_mutex);
INIT_WORK(&mdev->poll_work_obj, wq_netinfo);
setup_timer(&mdev->link_stat_timer, link_stat_timer_handler,
(unsigned long)mdev);
mdev->usb_device = usb_dev;
mdev->link_stat_timer.expires = jiffies + (2 * HZ);
mdev->iface.mod = hdm_usb_fops.owner;
mdev->iface.interface = ITYPE_USB;
mdev->iface.configure = hdm_configure_channel;
mdev->iface.request_netinfo = hdm_request_netinfo;
mdev->iface.enqueue = hdm_enqueue;
mdev->iface.poison_channel = hdm_poison_channel;
mdev->iface.description = mdev->description;
mdev->iface.num_channels = num_endpoints;
snprintf(mdev->description, sizeof(mdev->description),
"usb_device %d-%s:%d.%d",
usb_dev->bus->busnum,
usb_dev->devpath,
usb_dev->config->desc.bConfigurationValue,
usb_iface_desc->desc.bInterfaceNumber);
mdev->conf = kcalloc(num_endpoints, sizeof(*mdev->conf), GFP_KERNEL);
if (!mdev->conf)
goto exit_free;
mdev->cap = kcalloc(num_endpoints, sizeof(*mdev->cap), GFP_KERNEL);
if (!mdev->cap)
goto exit_free1;
mdev->iface.channel_vector = mdev->cap;
mdev->iface.priv = NULL;
mdev->ep_address =
kcalloc(num_endpoints, sizeof(*mdev->ep_address), GFP_KERNEL);
if (!mdev->ep_address)
goto exit_free2;
mdev->busy_urbs =
kcalloc(num_endpoints, sizeof(*mdev->busy_urbs), GFP_KERNEL);
if (!mdev->busy_urbs)
goto exit_free3;
tmp_cap = mdev->cap;
for (i = 0; i < num_endpoints; i++) {
ep_desc = &usb_iface_desc->endpoint[i].desc;
mdev->ep_address[i] = ep_desc->bEndpointAddress;
mdev->padding_active[i] = false;
mdev->is_channel_healthy[i] = true;
snprintf(&mdev->suffix[i][0], MAX_SUFFIX_LEN, "ep%02x",
mdev->ep_address[i]);
tmp_cap->name_suffix = &mdev->suffix[i][0];
tmp_cap->buffer_size_packet = MAX_BUF_SIZE;
tmp_cap->buffer_size_streaming = MAX_BUF_SIZE;
tmp_cap->num_buffers_packet = BUF_CHAIN_SIZE;
tmp_cap->num_buffers_streaming = BUF_CHAIN_SIZE;
tmp_cap->data_type = MOST_CH_CONTROL | MOST_CH_ASYNC |
MOST_CH_ISOC | MOST_CH_SYNC;
if (usb_endpoint_dir_in(ep_desc))
tmp_cap->direction = MOST_CH_RX;
else
tmp_cap->direction = MOST_CH_TX;
tmp_cap++;
init_usb_anchor(&mdev->busy_urbs[i]);
spin_lock_init(&mdev->channel_lock[i]);
}
dev_notice(dev, "claimed gadget: Vendor=%4.4x ProdID=%4.4x Bus=%02x Device=%02x\n",
le16_to_cpu(usb_dev->descriptor.idVendor),
le16_to_cpu(usb_dev->descriptor.idProduct),
usb_dev->bus->busnum,
usb_dev->devnum);
dev_notice(dev, "device path: /sys/bus/usb/devices/%d-%s:%d.%d\n",
usb_dev->bus->busnum,
usb_dev->devpath,
usb_dev->config->desc.bConfigurationValue,
usb_iface_desc->desc.bInterfaceNumber);
mdev->parent = most_register_interface(&mdev->iface);
if (IS_ERR(mdev->parent)) {
ret = PTR_ERR(mdev->parent);
goto exit_free4;
}
mutex_lock(&mdev->io_mutex);
if (le16_to_cpu(usb_dev->descriptor.idProduct) == USB_DEV_ID_OS81118 ||
le16_to_cpu(usb_dev->descriptor.idProduct) == USB_DEV_ID_OS81119 ||
le16_to_cpu(usb_dev->descriptor.idProduct) == USB_DEV_ID_OS81210) {
mdev->dci = create_most_dci_obj(mdev->parent);
if (!mdev->dci) {
mutex_unlock(&mdev->io_mutex);
most_deregister_interface(&mdev->iface);
ret = -ENOMEM;
goto exit_free4;
}
kobject_uevent(&mdev->dci->kobj, KOBJ_ADD);
mdev->dci->usb_device = mdev->usb_device;
}
mutex_unlock(&mdev->io_mutex);
return 0;
exit_free4:
kfree(mdev->busy_urbs);
exit_free3:
kfree(mdev->ep_address);
exit_free2:
kfree(mdev->cap);
exit_free1:
kfree(mdev->conf);
exit_free:
kfree(mdev);
exit_ENOMEM:
if (ret == 0 || ret == -ENOMEM) {
ret = -ENOMEM;
dev_err(dev, "out of memory\n");
}
return ret;
}
static void hdm_disconnect(struct usb_interface *interface)
{
struct most_dev *mdev = usb_get_intfdata(interface);
mutex_lock(&mdev->io_mutex);
usb_set_intfdata(interface, NULL);
mdev->usb_device = NULL;
mutex_unlock(&mdev->io_mutex);
del_timer_sync(&mdev->link_stat_timer);
cancel_work_sync(&mdev->poll_work_obj);
destroy_most_dci_obj(mdev->dci);
most_deregister_interface(&mdev->iface);
kfree(mdev->busy_urbs);
kfree(mdev->cap);
kfree(mdev->conf);
kfree(mdev->ep_address);
kfree(mdev);
}
static int __init hdm_usb_init(void)
{
pr_info("hdm_usb_init()\n");
if (usb_register(&hdm_usb)) {
pr_err("could not register hdm_usb driver\n");
return -EIO;
}
return 0;
}
static void __exit hdm_usb_exit(void)
{
pr_info("hdm_usb_exit()\n");
usb_deregister(&hdm_usb);
}
