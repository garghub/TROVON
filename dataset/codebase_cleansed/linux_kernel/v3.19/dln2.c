int dln2_register_event_cb(struct platform_device *pdev, u16 id,
dln2_event_cb_t event_cb)
{
struct dln2_dev *dln2 = dev_get_drvdata(pdev->dev.parent);
struct dln2_event_cb_entry *i, *entry;
unsigned long flags;
int ret = 0;
entry = kzalloc(sizeof(*entry), GFP_KERNEL);
if (!entry)
return -ENOMEM;
entry->id = id;
entry->callback = event_cb;
entry->pdev = pdev;
spin_lock_irqsave(&dln2->event_cb_lock, flags);
list_for_each_entry(i, &dln2->event_cb_list, list) {
if (i->id == id) {
ret = -EBUSY;
break;
}
}
if (!ret)
list_add_rcu(&entry->list, &dln2->event_cb_list);
spin_unlock_irqrestore(&dln2->event_cb_lock, flags);
if (ret)
kfree(entry);
return ret;
}
void dln2_unregister_event_cb(struct platform_device *pdev, u16 id)
{
struct dln2_dev *dln2 = dev_get_drvdata(pdev->dev.parent);
struct dln2_event_cb_entry *i;
unsigned long flags;
bool found = false;
spin_lock_irqsave(&dln2->event_cb_lock, flags);
list_for_each_entry(i, &dln2->event_cb_list, list) {
if (i->id == id) {
list_del_rcu(&i->list);
found = true;
break;
}
}
spin_unlock_irqrestore(&dln2->event_cb_lock, flags);
if (found) {
synchronize_rcu();
kfree(i);
}
}
static bool dln2_transfer_complete(struct dln2_dev *dln2, struct urb *urb,
u16 handle, u16 rx_slot)
{
struct device *dev = &dln2->interface->dev;
struct dln2_mod_rx_slots *rxs = &dln2->mod_rx_slots[handle];
struct dln2_rx_context *rxc;
bool valid_slot = false;
if (rx_slot >= DLN2_MAX_RX_SLOTS)
goto out;
rxc = &rxs->slots[rx_slot];
spin_lock(&rxs->lock);
if (rxc->in_use && !rxc->urb) {
rxc->urb = urb;
complete(&rxc->done);
valid_slot = true;
}
spin_unlock(&rxs->lock);
out:
if (!valid_slot)
dev_warn(dev, "bad/late response %d/%d\n", handle, rx_slot);
return valid_slot;
}
static void dln2_run_event_callbacks(struct dln2_dev *dln2, u16 id, u16 echo,
void *data, int len)
{
struct dln2_event_cb_entry *i;
rcu_read_lock();
list_for_each_entry_rcu(i, &dln2->event_cb_list, list) {
if (i->id == id) {
i->callback(i->pdev, echo, data, len);
break;
}
}
rcu_read_unlock();
}
static void dln2_rx(struct urb *urb)
{
struct dln2_dev *dln2 = urb->context;
struct dln2_header *hdr = urb->transfer_buffer;
struct device *dev = &dln2->interface->dev;
u16 id, echo, handle, size;
u8 *data;
int len;
int err;
switch (urb->status) {
case 0:
break;
case -ECONNRESET:
case -ENOENT:
case -ESHUTDOWN:
case -EPIPE:
dev_dbg(dev, "urb shutting down with status %d\n", urb->status);
return;
default:
dev_dbg(dev, "nonzero urb status received %d\n", urb->status);
goto out;
}
if (urb->actual_length < sizeof(struct dln2_header)) {
dev_err(dev, "short response: %d\n", urb->actual_length);
goto out;
}
handle = le16_to_cpu(hdr->handle);
id = le16_to_cpu(hdr->id);
echo = le16_to_cpu(hdr->echo);
size = le16_to_cpu(hdr->size);
if (size != urb->actual_length) {
dev_err(dev, "size mismatch: handle %x cmd %x echo %x size %d actual %d\n",
handle, id, echo, size, urb->actual_length);
goto out;
}
if (handle >= DLN2_HANDLES) {
dev_warn(dev, "invalid handle %d\n", handle);
goto out;
}
data = urb->transfer_buffer + sizeof(struct dln2_header);
len = urb->actual_length - sizeof(struct dln2_header);
if (handle == DLN2_HANDLE_EVENT) {
dln2_run_event_callbacks(dln2, id, echo, data, len);
} else {
if (dln2_transfer_complete(dln2, urb, handle, echo))
return;
}
out:
err = usb_submit_urb(urb, GFP_ATOMIC);
if (err < 0)
dev_err(dev, "failed to resubmit RX URB: %d\n", err);
}
static void *dln2_prep_buf(u16 handle, u16 cmd, u16 echo, const void *obuf,
int *obuf_len, gfp_t gfp)
{
int len;
void *buf;
struct dln2_header *hdr;
len = *obuf_len + sizeof(*hdr);
buf = kmalloc(len, gfp);
if (!buf)
return NULL;
hdr = (struct dln2_header *)buf;
hdr->id = cpu_to_le16(cmd);
hdr->size = cpu_to_le16(len);
hdr->echo = cpu_to_le16(echo);
hdr->handle = cpu_to_le16(handle);
memcpy(buf + sizeof(*hdr), obuf, *obuf_len);
*obuf_len = len;
return buf;
}
static int dln2_send_wait(struct dln2_dev *dln2, u16 handle, u16 cmd, u16 echo,
const void *obuf, int obuf_len)
{
int ret = 0;
int len = obuf_len;
void *buf;
int actual;
buf = dln2_prep_buf(handle, cmd, echo, obuf, &len, GFP_KERNEL);
if (!buf)
return -ENOMEM;
ret = usb_bulk_msg(dln2->usb_dev,
usb_sndbulkpipe(dln2->usb_dev, dln2->ep_out),
buf, len, &actual, DLN2_USB_TIMEOUT);
kfree(buf);
return ret;
}
static bool find_free_slot(struct dln2_dev *dln2, u16 handle, int *slot)
{
struct dln2_mod_rx_slots *rxs;
unsigned long flags;
if (dln2->disconnect) {
*slot = -ENODEV;
return true;
}
rxs = &dln2->mod_rx_slots[handle];
spin_lock_irqsave(&rxs->lock, flags);
*slot = find_first_zero_bit(rxs->bmap, DLN2_MAX_RX_SLOTS);
if (*slot < DLN2_MAX_RX_SLOTS) {
struct dln2_rx_context *rxc = &rxs->slots[*slot];
set_bit(*slot, rxs->bmap);
rxc->in_use = true;
}
spin_unlock_irqrestore(&rxs->lock, flags);
return *slot < DLN2_MAX_RX_SLOTS;
}
static int alloc_rx_slot(struct dln2_dev *dln2, u16 handle)
{
int ret;
int slot;
ret = wait_event_interruptible(dln2->mod_rx_slots[handle].wq,
find_free_slot(dln2, handle, &slot));
if (ret < 0)
return ret;
return slot;
}
static void free_rx_slot(struct dln2_dev *dln2, u16 handle, int slot)
{
struct dln2_mod_rx_slots *rxs;
struct urb *urb = NULL;
unsigned long flags;
struct dln2_rx_context *rxc;
rxs = &dln2->mod_rx_slots[handle];
spin_lock_irqsave(&rxs->lock, flags);
clear_bit(slot, rxs->bmap);
rxc = &rxs->slots[slot];
rxc->in_use = false;
urb = rxc->urb;
rxc->urb = NULL;
reinit_completion(&rxc->done);
spin_unlock_irqrestore(&rxs->lock, flags);
if (urb) {
int err;
struct device *dev = &dln2->interface->dev;
err = usb_submit_urb(urb, GFP_KERNEL);
if (err < 0)
dev_err(dev, "failed to resubmit RX URB: %d\n", err);
}
wake_up_interruptible(&rxs->wq);
}
static int _dln2_transfer(struct dln2_dev *dln2, u16 handle, u16 cmd,
const void *obuf, unsigned obuf_len,
void *ibuf, unsigned *ibuf_len)
{
int ret = 0;
int rx_slot;
struct dln2_response *rsp;
struct dln2_rx_context *rxc;
struct device *dev = &dln2->interface->dev;
const unsigned long timeout = DLN2_USB_TIMEOUT * HZ / 1000;
struct dln2_mod_rx_slots *rxs = &dln2->mod_rx_slots[handle];
int size;
spin_lock(&dln2->disconnect_lock);
if (!dln2->disconnect)
dln2->active_transfers++;
else
ret = -ENODEV;
spin_unlock(&dln2->disconnect_lock);
if (ret)
return ret;
rx_slot = alloc_rx_slot(dln2, handle);
if (rx_slot < 0) {
ret = rx_slot;
goto out_decr;
}
ret = dln2_send_wait(dln2, handle, cmd, rx_slot, obuf, obuf_len);
if (ret < 0) {
dev_err(dev, "USB write failed: %d\n", ret);
goto out_free_rx_slot;
}
rxc = &rxs->slots[rx_slot];
ret = wait_for_completion_interruptible_timeout(&rxc->done, timeout);
if (ret <= 0) {
if (!ret)
ret = -ETIMEDOUT;
goto out_free_rx_slot;
} else {
ret = 0;
}
if (dln2->disconnect) {
ret = -ENODEV;
goto out_free_rx_slot;
}
rsp = rxc->urb->transfer_buffer;
size = le16_to_cpu(rsp->hdr.size);
if (size < sizeof(*rsp)) {
ret = -EPROTO;
goto out_free_rx_slot;
}
if (le16_to_cpu(rsp->result) > 0x80) {
dev_dbg(dev, "%d received response with error %d\n",
handle, le16_to_cpu(rsp->result));
ret = -EREMOTEIO;
goto out_free_rx_slot;
}
if (!ibuf)
goto out_free_rx_slot;
if (*ibuf_len > size - sizeof(*rsp))
*ibuf_len = size - sizeof(*rsp);
memcpy(ibuf, rsp + 1, *ibuf_len);
out_free_rx_slot:
free_rx_slot(dln2, handle, rx_slot);
out_decr:
spin_lock(&dln2->disconnect_lock);
dln2->active_transfers--;
spin_unlock(&dln2->disconnect_lock);
if (dln2->disconnect)
wake_up(&dln2->disconnect_wq);
return ret;
}
int dln2_transfer(struct platform_device *pdev, u16 cmd,
const void *obuf, unsigned obuf_len,
void *ibuf, unsigned *ibuf_len)
{
struct dln2_platform_data *dln2_pdata;
struct dln2_dev *dln2;
u16 handle;
dln2 = dev_get_drvdata(pdev->dev.parent);
dln2_pdata = dev_get_platdata(&pdev->dev);
handle = dln2_pdata->handle;
return _dln2_transfer(dln2, handle, cmd, obuf, obuf_len, ibuf,
ibuf_len);
}
static int dln2_check_hw(struct dln2_dev *dln2)
{
int ret;
__le32 hw_type;
int len = sizeof(hw_type);
ret = _dln2_transfer(dln2, DLN2_HANDLE_CTRL, CMD_GET_DEVICE_VER,
NULL, 0, &hw_type, &len);
if (ret < 0)
return ret;
if (len < sizeof(hw_type))
return -EREMOTEIO;
if (le32_to_cpu(hw_type) != DLN2_HW_ID) {
dev_err(&dln2->interface->dev, "Device ID 0x%x not supported\n",
le32_to_cpu(hw_type));
return -ENODEV;
}
return 0;
}
static int dln2_print_serialno(struct dln2_dev *dln2)
{
int ret;
__le32 serial_no;
int len = sizeof(serial_no);
struct device *dev = &dln2->interface->dev;
ret = _dln2_transfer(dln2, DLN2_HANDLE_CTRL, CMD_GET_DEVICE_SN, NULL, 0,
&serial_no, &len);
if (ret < 0)
return ret;
if (len < sizeof(serial_no))
return -EREMOTEIO;
dev_info(dev, "Diolan DLN2 serial %u\n", le32_to_cpu(serial_no));
return 0;
}
static int dln2_hw_init(struct dln2_dev *dln2)
{
int ret;
ret = dln2_check_hw(dln2);
if (ret < 0)
return ret;
return dln2_print_serialno(dln2);
}
static void dln2_free_rx_urbs(struct dln2_dev *dln2)
{
int i;
for (i = 0; i < DLN2_MAX_URBS; i++) {
usb_kill_urb(dln2->rx_urb[i]);
usb_free_urb(dln2->rx_urb[i]);
kfree(dln2->rx_buf[i]);
}
}
static void dln2_free(struct dln2_dev *dln2)
{
dln2_free_rx_urbs(dln2);
usb_put_dev(dln2->usb_dev);
kfree(dln2);
}
static int dln2_setup_rx_urbs(struct dln2_dev *dln2,
struct usb_host_interface *hostif)
{
int i;
int ret;
const int rx_max_size = DLN2_RX_BUF_SIZE;
struct device *dev = &dln2->interface->dev;
for (i = 0; i < DLN2_MAX_URBS; i++) {
dln2->rx_buf[i] = kmalloc(rx_max_size, GFP_KERNEL);
if (!dln2->rx_buf[i])
return -ENOMEM;
dln2->rx_urb[i] = usb_alloc_urb(0, GFP_KERNEL);
if (!dln2->rx_urb[i])
return -ENOMEM;
usb_fill_bulk_urb(dln2->rx_urb[i], dln2->usb_dev,
usb_rcvbulkpipe(dln2->usb_dev, dln2->ep_in),
dln2->rx_buf[i], rx_max_size, dln2_rx, dln2);
ret = usb_submit_urb(dln2->rx_urb[i], GFP_KERNEL);
if (ret < 0) {
dev_err(dev, "failed to submit RX URB: %d\n", ret);
return ret;
}
}
return 0;
}
static void dln2_disconnect(struct usb_interface *interface)
{
struct dln2_dev *dln2 = usb_get_intfdata(interface);
int i, j;
spin_lock(&dln2->disconnect_lock);
dln2->disconnect = true;
spin_unlock(&dln2->disconnect_lock);
for (i = 0; i < DLN2_HANDLES; i++) {
struct dln2_mod_rx_slots *rxs = &dln2->mod_rx_slots[i];
unsigned long flags;
spin_lock_irqsave(&rxs->lock, flags);
for (j = 0; j < DLN2_MAX_RX_SLOTS; j++) {
struct dln2_rx_context *rxc = &rxs->slots[j];
if (rxc->in_use)
complete(&rxc->done);
}
spin_unlock_irqrestore(&rxs->lock, flags);
}
wait_event(dln2->disconnect_wq, !dln2->active_transfers);
mfd_remove_devices(&interface->dev);
dln2_free(dln2);
}
static int dln2_probe(struct usb_interface *interface,
const struct usb_device_id *usb_id)
{
struct usb_host_interface *hostif = interface->cur_altsetting;
struct device *dev = &interface->dev;
struct dln2_dev *dln2;
int ret;
int i, j;
if (hostif->desc.bInterfaceNumber != 0 ||
hostif->desc.bNumEndpoints < 2)
return -ENODEV;
dln2 = kzalloc(sizeof(*dln2), GFP_KERNEL);
if (!dln2)
return -ENOMEM;
dln2->ep_out = hostif->endpoint[0].desc.bEndpointAddress;
dln2->ep_in = hostif->endpoint[1].desc.bEndpointAddress;
dln2->usb_dev = usb_get_dev(interface_to_usbdev(interface));
dln2->interface = interface;
usb_set_intfdata(interface, dln2);
init_waitqueue_head(&dln2->disconnect_wq);
for (i = 0; i < DLN2_HANDLES; i++) {
init_waitqueue_head(&dln2->mod_rx_slots[i].wq);
spin_lock_init(&dln2->mod_rx_slots[i].lock);
for (j = 0; j < DLN2_MAX_RX_SLOTS; j++)
init_completion(&dln2->mod_rx_slots[i].slots[j].done);
}
spin_lock_init(&dln2->event_cb_lock);
spin_lock_init(&dln2->disconnect_lock);
INIT_LIST_HEAD(&dln2->event_cb_list);
ret = dln2_setup_rx_urbs(dln2, hostif);
if (ret)
goto out_cleanup;
ret = dln2_hw_init(dln2);
if (ret < 0) {
dev_err(dev, "failed to initialize hardware\n");
goto out_cleanup;
}
ret = mfd_add_hotplug_devices(dev, dln2_devs, ARRAY_SIZE(dln2_devs));
if (ret != 0) {
dev_err(dev, "failed to add mfd devices to core\n");
goto out_cleanup;
}
return 0;
out_cleanup:
dln2_free(dln2);
return ret;
}
