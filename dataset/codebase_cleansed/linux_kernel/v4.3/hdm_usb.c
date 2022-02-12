static void trigger_resync_vr(struct usb_device *dev)
{
int retval;
u8 request_type = USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_ENDPOINT;
int *data = kzalloc(sizeof(*data), GFP_KERNEL);
if (!data)
goto error;
*data = HW_RESYNC;
retval = usb_control_msg(dev,
usb_sndctrlpipe(dev, 0),
0,
request_type,
0,
0,
data,
0,
5 * HZ);
kfree(data);
if (retval >= 0)
return;
error:
dev_err(&dev->dev, "Vendor request \"stall\" failed\n");
}
static inline int drci_rd_reg(struct usb_device *dev, u16 reg, void *buf)
{
return usb_control_msg(dev,
usb_rcvctrlpipe(dev, 0),
DRCI_READ_REQ,
USB_DIR_IN | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
0x0000,
reg,
buf,
2,
5 * HZ);
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
static void free_anchored_buffers(struct most_dev *mdev, unsigned int channel)
{
struct mbo *mbo;
struct buf_anchor *anchor, *tmp;
unsigned long flags;
spin_lock_irqsave(&mdev->anchor_list_lock[channel], flags);
list_for_each_entry_safe(anchor, tmp, &mdev->anchor_list[channel], list) {
struct urb *urb = anchor->urb;
spin_unlock_irqrestore(&mdev->anchor_list_lock[channel], flags);
if (likely(urb)) {
mbo = urb->context;
if (!irqs_disabled()) {
usb_kill_urb(urb);
} else {
usb_unlink_urb(urb);
wait_for_completion(&anchor->urb_compl);
}
if ((mbo) && (mbo->complete)) {
mbo->status = MBO_E_CLOSE;
mbo->processed_length = 0;
mbo->complete(mbo);
}
usb_free_urb(urb);
}
spin_lock_irqsave(&mdev->anchor_list_lock[channel], flags);
list_del(&anchor->list);
kfree(anchor);
}
spin_unlock_irqrestore(&mdev->anchor_list_lock[channel], flags);
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
case MOST_CH_ISOC_AVP:
frame_size = AV_PACKETS_PER_XACT * sub_size;
break;
case MOST_CH_SYNC:
if (cfg->packets_per_xact == 0) {
pr_warn("Misconfig: Packets per XACT zero\n");
frame_size = 0;
} else if (cfg->packets_per_xact == 0xFF)
frame_size = (USB_MTU / sub_size) * sub_size;
else
frame_size = cfg->packets_per_xact * sub_size;
break;
default:
pr_warn("Query frame size of non-streaming channel\n");
break;
}
return frame_size;
}
static int hdm_poison_channel(struct most_interface *iface, int channel)
{
struct most_dev *mdev;
mdev = to_mdev(iface);
if (unlikely(!iface)) {
dev_warn(&mdev->usb_device->dev, "Poison: Bad interface.\n");
return -EIO;
}
if (unlikely((channel < 0) || (channel >= iface->num_channels))) {
dev_warn(&mdev->usb_device->dev, "Channel ID out of range.\n");
return -ECHRNG;
}
mdev->is_channel_healthy[channel] = false;
mutex_lock(&mdev->io_mutex);
free_anchored_buffers(mdev, channel);
if (mdev->padding_active[channel] == true)
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
unsigned int j, num_frames, frame_size;
u16 rd_addr, wr_addr;
frame_size = get_stream_frame_size(conf);
if (!frame_size)
return -EIO;
num_frames = mbo->buffer_length / frame_size;
if (num_frames < 1) {
dev_err(&mdev->usb_device->dev,
"Missed minimal transfer unit.\n");
return -EIO;
}
for (j = 1; j < num_frames; j++) {
wr_addr = (num_frames - j) * USB_MTU;
rd_addr = (num_frames - j) * frame_size;
memmove(mbo->virt_address + wr_addr,
mbo->virt_address + rd_addr,
frame_size);
}
mbo->buffer_length = num_frames * USB_MTU;
return 0;
}
static int hdm_remove_padding(struct most_dev *mdev, int channel, struct mbo *mbo)
{
unsigned int j, num_frames, frame_size;
struct most_channel_config *const conf = &mdev->conf[channel];
frame_size = get_stream_frame_size(conf);
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
struct mbo *mbo;
struct buf_anchor *anchor;
struct most_dev *mdev;
struct device *dev;
unsigned int channel;
unsigned long flags;
mbo = urb->context;
anchor = mbo->priv;
mdev = to_mdev(mbo->ifp);
channel = mbo->hdm_channel_id;
dev = &mdev->usb_device->dev;
if ((urb->status == -ENOENT) || (urb->status == -ECONNRESET) ||
(mdev->is_channel_healthy[channel] == false)) {
complete(&anchor->urb_compl);
return;
}
if (unlikely(urb->status && !(urb->status == -ENOENT ||
urb->status == -ECONNRESET ||
urb->status == -ESHUTDOWN))) {
mbo->processed_length = 0;
switch (urb->status) {
case -EPIPE:
dev_warn(dev, "Broken OUT pipe detected\n");
most_stop_enqueue(&mdev->iface, channel);
mbo->status = MBO_E_INVAL;
usb_unlink_urb(urb);
INIT_WORK(&anchor->clear_work_obj, wq_clear_halt);
queue_work(schedule_usb_work, &anchor->clear_work_obj);
return;
case -ENODEV:
case -EPROTO:
mbo->status = MBO_E_CLOSE;
break;
default:
mbo->status = MBO_E_INVAL;
break;
}
} else {
mbo->status = MBO_SUCCESS;
mbo->processed_length = urb->actual_length;
}
spin_lock_irqsave(&mdev->anchor_list_lock[channel], flags);
list_del(&anchor->list);
spin_unlock_irqrestore(&mdev->anchor_list_lock[channel], flags);
kfree(anchor);
if (likely(mbo->complete))
mbo->complete(mbo);
usb_free_urb(urb);
}
static void hdm_read_completion(struct urb *urb)
{
struct mbo *mbo;
struct buf_anchor *anchor;
struct most_dev *mdev;
struct device *dev;
unsigned long flags;
unsigned int channel;
struct most_channel_config *conf;
mbo = urb->context;
anchor = mbo->priv;
mdev = to_mdev(mbo->ifp);
channel = mbo->hdm_channel_id;
dev = &mdev->usb_device->dev;
if ((urb->status == -ENOENT) || (urb->status == -ECONNRESET) ||
(mdev->is_channel_healthy[channel] == false)) {
complete(&anchor->urb_compl);
return;
}
conf = &mdev->conf[channel];
if (unlikely(urb->status && !(urb->status == -ENOENT ||
urb->status == -ECONNRESET ||
urb->status == -ESHUTDOWN))) {
mbo->processed_length = 0;
switch (urb->status) {
case -EPIPE:
dev_warn(dev, "Broken IN pipe detected\n");
mbo->status = MBO_E_INVAL;
usb_unlink_urb(urb);
INIT_WORK(&anchor->clear_work_obj, wq_clear_halt);
queue_work(schedule_usb_work, &anchor->clear_work_obj);
return;
case -ENODEV:
case -EPROTO:
mbo->status = MBO_E_CLOSE;
break;
case -EOVERFLOW:
dev_warn(dev, "Babble on IN pipe detected\n");
default:
mbo->status = MBO_E_INVAL;
break;
}
} else {
mbo->processed_length = urb->actual_length;
if (mdev->padding_active[channel] == false) {
mbo->status = MBO_SUCCESS;
} else {
if (hdm_remove_padding(mdev, channel, mbo)) {
mbo->processed_length = 0;
mbo->status = MBO_E_INVAL;
} else {
mbo->status = MBO_SUCCESS;
}
}
}
spin_lock_irqsave(&mdev->anchor_list_lock[channel], flags);
list_del(&anchor->list);
spin_unlock_irqrestore(&mdev->anchor_list_lock[channel], flags);
kfree(anchor);
if (likely(mbo->complete))
mbo->complete(mbo);
usb_free_urb(urb);
}
static int hdm_enqueue(struct most_interface *iface, int channel, struct mbo *mbo)
{
struct most_dev *mdev;
struct buf_anchor *anchor;
struct most_channel_config *conf;
struct device *dev;
int retval = 0;
struct urb *urb;
unsigned long flags;
unsigned long length;
void *virt_address;
if (unlikely(!iface || !mbo))
return -EIO;
if (unlikely(iface->num_channels <= channel) || (channel < 0))
return -ECHRNG;
mdev = to_mdev(iface);
conf = &mdev->conf[channel];
dev = &mdev->usb_device->dev;
if (!mdev->usb_device)
return -ENODEV;
urb = usb_alloc_urb(NO_ISOCHRONOUS_URB, GFP_ATOMIC);
if (!urb) {
dev_err(dev, "Failed to allocate URB\n");
return -ENOMEM;
}
anchor = kzalloc(sizeof(*anchor), GFP_ATOMIC);
if (!anchor) {
retval = -ENOMEM;
goto _error;
}
anchor->urb = urb;
init_completion(&anchor->urb_compl);
mbo->priv = anchor;
spin_lock_irqsave(&mdev->anchor_list_lock[channel], flags);
list_add_tail(&anchor->list, &mdev->anchor_list[channel]);
spin_unlock_irqrestore(&mdev->anchor_list_lock[channel], flags);
if ((mdev->padding_active[channel] == true) &&
(conf->direction & MOST_CH_TX))
if (hdm_add_padding(mdev, channel, mbo)) {
retval = -EIO;
goto _error_1;
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
if (conf->data_type != MOST_CH_ISOC_AVP)
urb->transfer_flags |= URB_ZERO_PACKET;
} else {
usb_fill_bulk_urb(urb, mdev->usb_device,
usb_rcvbulkpipe(mdev->usb_device,
mdev->ep_address[channel]),
virt_address,
length,
hdm_read_completion,
mbo);
}
urb->transfer_flags |= URB_NO_TRANSFER_DMA_MAP;
retval = usb_submit_urb(urb, GFP_KERNEL);
if (retval) {
dev_err(dev, "URB submit failed with error %d.\n", retval);
goto _error_1;
}
return 0;
_error_1:
spin_lock_irqsave(&mdev->anchor_list_lock[channel], flags);
list_del(&anchor->list);
spin_unlock_irqrestore(&mdev->anchor_list_lock[channel], flags);
kfree(anchor);
_error:
usb_free_urb(urb);
return retval;
}
static int hdm_configure_channel(struct most_interface *iface, int channel,
struct most_channel_config *conf)
{
unsigned int num_frames;
unsigned int frame_size;
unsigned int temp_size;
unsigned int tail_space;
struct most_dev *mdev;
struct device *dev;
mdev = to_mdev(iface);
mdev->is_channel_healthy[channel] = true;
dev = &mdev->usb_device->dev;
if (unlikely(!iface || !conf)) {
dev_err(dev, "Bad interface or config pointer.\n");
return -EINVAL;
}
if (unlikely((channel < 0) || (channel >= iface->num_channels))) {
dev_err(dev, "Channel ID out of range.\n");
return -EINVAL;
}
if ((!conf->num_buffers) || (!conf->buffer_size)) {
dev_err(dev, "Misconfig: buffer size or #buffers zero.\n");
return -EINVAL;
}
if (!(conf->data_type == MOST_CH_SYNC) &&
!((conf->data_type == MOST_CH_ISOC_AVP) &&
(conf->packets_per_xact != 0xFF))) {
mdev->padding_active[channel] = false;
goto exit;
}
mdev->padding_active[channel] = true;
temp_size = conf->buffer_size;
if ((conf->data_type != MOST_CH_SYNC) &&
(conf->data_type != MOST_CH_ISOC_AVP)) {
dev_warn(dev, "Unsupported data type\n");
return -EINVAL;
}
frame_size = get_stream_frame_size(conf);
if ((frame_size == 0) || (frame_size > USB_MTU)) {
dev_warn(dev, "Misconfig: frame size wrong\n");
return -EINVAL;
}
if (conf->buffer_size % frame_size) {
u16 tmp_val;
tmp_val = conf->buffer_size / frame_size;
conf->buffer_size = tmp_val * frame_size;
dev_notice(dev,
"Channel %d - rouding buffer size to %d bytes, "
"channel config says %d bytes\n",
channel,
conf->buffer_size,
temp_size);
}
num_frames = conf->buffer_size / frame_size;
tail_space = num_frames * (USB_MTU - frame_size);
temp_size += tail_space;
conf->extra_len = (CEILING(temp_size, USB_MTU) * USB_MTU)
- conf->buffer_size;
exit:
mdev->conf[channel] = *conf;
return 0;
}
static int hdm_update_netinfo(struct most_dev *mdev)
{
struct device *dev = &mdev->usb_device->dev;
int i;
u16 link;
u8 addr[6];
if (!is_valid_ether_addr(mdev->hw_addr)) {
if (0 > drci_rd_reg(mdev->usb_device,
DRCI_REG_HW_ADDR_HI, addr)) {
dev_err(dev, "Vendor request \"hw_addr_hi\" failed\n");
return -1;
}
if (0 > drci_rd_reg(mdev->usb_device,
DRCI_REG_HW_ADDR_MI, addr + 2)) {
dev_err(dev, "Vendor request \"hw_addr_mid\" failed\n");
return -1;
}
if (0 > drci_rd_reg(mdev->usb_device,
DRCI_REG_HW_ADDR_LO, addr + 4)) {
dev_err(dev, "Vendor request \"hw_addr_low\" failed\n");
return -1;
}
mutex_lock(&mdev->io_mutex);
for (i = 0; i < 6; i++)
mdev->hw_addr[i] = addr[i];
mutex_unlock(&mdev->io_mutex);
}
if (0 > drci_rd_reg(mdev->usb_device, DRCI_REG_NI_STATE, &link)) {
dev_err(dev, "Vendor request \"link status\" failed\n");
return -1;
}
le16_to_cpus(&link);
mutex_lock(&mdev->io_mutex);
mdev->link_stat = link;
mutex_unlock(&mdev->io_mutex);
return 0;
}
static void hdm_request_netinfo(struct most_interface *iface, int channel)
{
struct most_dev *mdev;
BUG_ON(!iface);
mdev = to_mdev(iface);
mdev->link_stat_timer.expires = jiffies + HZ;
mod_timer(&mdev->link_stat_timer, mdev->link_stat_timer.expires);
}
static void link_stat_timer_handler(unsigned long data)
{
struct most_dev *mdev = (struct most_dev *)data;
queue_work(schedule_usb_work, &mdev->poll_work_obj);
mdev->link_stat_timer.expires = jiffies + (2 * HZ);
add_timer(&mdev->link_stat_timer);
}
static void wq_netinfo(struct work_struct *wq_obj)
{
struct most_dev *mdev;
int i, prev_link_stat;
u8 prev_hw_addr[6];
mdev = to_mdev_from_work(wq_obj);
prev_link_stat = mdev->link_stat;
for (i = 0; i < 6; i++)
prev_hw_addr[i] = mdev->hw_addr[i];
if (0 > hdm_update_netinfo(mdev))
return;
if ((prev_link_stat != mdev->link_stat) ||
(prev_hw_addr[0] != mdev->hw_addr[0]) ||
(prev_hw_addr[1] != mdev->hw_addr[1]) ||
(prev_hw_addr[2] != mdev->hw_addr[2]) ||
(prev_hw_addr[3] != mdev->hw_addr[3]) ||
(prev_hw_addr[4] != mdev->hw_addr[4]) ||
(prev_hw_addr[5] != mdev->hw_addr[5]))
most_deliver_netinfo(&mdev->iface, mdev->link_stat,
&mdev->hw_addr[0]);
}
static void wq_clear_halt(struct work_struct *wq_obj)
{
struct buf_anchor *anchor;
struct most_dev *mdev;
struct mbo *mbo;
struct urb *urb;
unsigned int channel;
unsigned long flags;
anchor = to_buf_anchor(wq_obj);
urb = anchor->urb;
mbo = urb->context;
mdev = to_mdev(mbo->ifp);
channel = mbo->hdm_channel_id;
if (usb_clear_halt(urb->dev, urb->pipe))
dev_warn(&mdev->usb_device->dev, "Failed to reset endpoint.\n");
usb_free_urb(urb);
spin_lock_irqsave(&mdev->anchor_list_lock[channel], flags);
list_del(&anchor->list);
spin_unlock_irqrestore(&mdev->anchor_list_lock[channel], flags);
if (likely(mbo->complete))
mbo->complete(mbo);
if (mdev->conf[channel].direction & MOST_CH_TX)
most_resume_enqueue(&mdev->iface, channel);
kfree(anchor);
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
static ssize_t show_value(struct most_dci_obj *dci_obj,
struct most_dci_attribute *attr, char *buf)
{
u16 tmp_val;
u16 reg_addr;
int err;
if (!strcmp(attr->attr.name, "ni_state"))
reg_addr = DRCI_REG_NI_STATE;
else if (!strcmp(attr->attr.name, "packet_bandwidth"))
reg_addr = DRCI_REG_PACKET_BW;
else if (!strcmp(attr->attr.name, "node_address"))
reg_addr = DRCI_REG_NODE_ADDR;
else if (!strcmp(attr->attr.name, "node_position"))
reg_addr = DRCI_REG_NODE_POS;
else if (!strcmp(attr->attr.name, "mep_filter"))
reg_addr = DRCI_REG_MEP_FILTER;
else if (!strcmp(attr->attr.name, "mep_hash0"))
reg_addr = DRCI_REG_HASH_TBL0;
else if (!strcmp(attr->attr.name, "mep_hash1"))
reg_addr = DRCI_REG_HASH_TBL1;
else if (!strcmp(attr->attr.name, "mep_hash2"))
reg_addr = DRCI_REG_HASH_TBL2;
else if (!strcmp(attr->attr.name, "mep_hash3"))
reg_addr = DRCI_REG_HASH_TBL3;
else if (!strcmp(attr->attr.name, "mep_eui48_hi"))
reg_addr = DRCI_REG_HW_ADDR_HI;
else if (!strcmp(attr->attr.name, "mep_eui48_mi"))
reg_addr = DRCI_REG_HW_ADDR_MI;
else if (!strcmp(attr->attr.name, "mep_eui48_lo"))
reg_addr = DRCI_REG_HW_ADDR_LO;
else
return -EIO;
err = drci_rd_reg(dci_obj->usb_device, reg_addr, &tmp_val);
if (err < 0)
return err;
return snprintf(buf, PAGE_SIZE, "%04x\n", le16_to_cpu(tmp_val));
}
static ssize_t store_value(struct most_dci_obj *dci_obj,
struct most_dci_attribute *attr,
const char *buf, size_t count)
{
u16 v16;
u16 reg_addr;
int err;
if (!strcmp(attr->attr.name, "mep_filter"))
reg_addr = DRCI_REG_MEP_FILTER;
else if (!strcmp(attr->attr.name, "mep_hash0"))
reg_addr = DRCI_REG_HASH_TBL0;
else if (!strcmp(attr->attr.name, "mep_hash1"))
reg_addr = DRCI_REG_HASH_TBL1;
else if (!strcmp(attr->attr.name, "mep_hash2"))
reg_addr = DRCI_REG_HASH_TBL2;
else if (!strcmp(attr->attr.name, "mep_hash3"))
reg_addr = DRCI_REG_HASH_TBL3;
else if (!strcmp(attr->attr.name, "mep_eui48_hi"))
reg_addr = DRCI_REG_HW_ADDR_HI;
else if (!strcmp(attr->attr.name, "mep_eui48_mi"))
reg_addr = DRCI_REG_HW_ADDR_MI;
else if (!strcmp(attr->attr.name, "mep_eui48_lo"))
reg_addr = DRCI_REG_HW_ADDR_LO;
else
return -EIO;
err = kstrtou16(buf, 16, &v16);
if (err)
return err;
err = drci_wr_reg(dci_obj->usb_device, reg_addr, cpu_to_le16(v16));
if (err < 0)
return err;
return count;
}
static struct
most_dci_obj *create_most_dci_obj(struct kobject *parent)
{
struct most_dci_obj *most_dci;
int retval;
most_dci = kzalloc(sizeof(*most_dci), GFP_KERNEL);
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
unsigned int i;
unsigned int num_endpoints;
struct most_channel_capability *tmp_cap;
struct most_dev *mdev;
struct usb_device *usb_dev;
struct device *dev;
struct usb_host_interface *usb_iface_desc;
struct usb_endpoint_descriptor *ep_desc;
int ret = 0;
usb_iface_desc = interface->cur_altsetting;
usb_dev = interface_to_usbdev(interface);
dev = &usb_dev->dev;
mdev = kzalloc(sizeof(*mdev), GFP_KERNEL);
if (!mdev)
goto exit_ENOMEM;
usb_set_intfdata(interface, mdev);
num_endpoints = usb_iface_desc->desc.bNumEndpoints;
mutex_init(&mdev->io_mutex);
INIT_WORK(&mdev->poll_work_obj, wq_netinfo);
init_timer(&mdev->link_stat_timer);
mdev->usb_device = usb_dev;
mdev->link_stat_timer.function = link_stat_timer_handler;
mdev->link_stat_timer.data = (unsigned long)mdev;
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
mdev->anchor_list =
kcalloc(num_endpoints, sizeof(*mdev->anchor_list), GFP_KERNEL);
if (!mdev->anchor_list)
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
MOST_CH_ISOC_AVP | MOST_CH_SYNC;
if (ep_desc->bEndpointAddress & USB_DIR_IN)
tmp_cap->direction = MOST_CH_RX;
else
tmp_cap->direction = MOST_CH_TX;
tmp_cap++;
INIT_LIST_HEAD(&mdev->anchor_list[i]);
spin_lock_init(&mdev->anchor_list_lock[i]);
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
if (le16_to_cpu(usb_dev->descriptor.idProduct) == USB_DEV_ID_INIC) {
mdev->dci = create_most_dci_obj(mdev->parent);
if (!mdev->dci) {
mutex_unlock(&mdev->io_mutex);
most_deregister_interface(&mdev->iface);
ret = -ENOMEM;
goto exit_free4;
}
kobject_uevent(&mdev->dci->kobj, KOBJ_ADD);
mdev->dci->usb_device = mdev->usb_device;
trigger_resync_vr(usb_dev);
}
mutex_unlock(&mdev->io_mutex);
return 0;
exit_free4:
kfree(mdev->anchor_list);
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
struct most_dev *mdev;
mdev = usb_get_intfdata(interface);
mutex_lock(&mdev->io_mutex);
usb_set_intfdata(interface, NULL);
mdev->usb_device = NULL;
mutex_unlock(&mdev->io_mutex);
del_timer_sync(&mdev->link_stat_timer);
cancel_work_sync(&mdev->poll_work_obj);
destroy_most_dci_obj(mdev->dci);
most_deregister_interface(&mdev->iface);
kfree(mdev->anchor_list);
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
schedule_usb_work = create_workqueue("hdmu_work");
if (schedule_usb_work == NULL) {
pr_err("could not create workqueue\n");
usb_deregister(&hdm_usb);
return -ENOMEM;
}
return 0;
}
static void __exit hdm_usb_exit(void)
{
pr_info("hdm_usb_exit()\n");
destroy_workqueue(schedule_usb_work);
usb_deregister(&hdm_usb);
}
