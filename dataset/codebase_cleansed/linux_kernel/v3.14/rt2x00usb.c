int rt2x00usb_vendor_request(struct rt2x00_dev *rt2x00dev,
const u8 request, const u8 requesttype,
const u16 offset, const u16 value,
void *buffer, const u16 buffer_length,
const int timeout)
{
struct usb_device *usb_dev = to_usb_device_intf(rt2x00dev->dev);
int status;
unsigned int i;
unsigned int pipe =
(requesttype == USB_VENDOR_REQUEST_IN) ?
usb_rcvctrlpipe(usb_dev, 0) : usb_sndctrlpipe(usb_dev, 0);
if (!test_bit(DEVICE_STATE_PRESENT, &rt2x00dev->flags))
return -ENODEV;
for (i = 0; i < REGISTER_BUSY_COUNT; i++) {
status = usb_control_msg(usb_dev, pipe, request, requesttype,
value, offset, buffer, buffer_length,
timeout);
if (status >= 0)
return 0;
else if (status == -ENODEV) {
clear_bit(DEVICE_STATE_PRESENT, &rt2x00dev->flags);
break;
}
}
rt2x00_err(rt2x00dev,
"Vendor Request 0x%02x failed for offset 0x%04x with error %d\n",
request, offset, status);
return status;
}
int rt2x00usb_vendor_req_buff_lock(struct rt2x00_dev *rt2x00dev,
const u8 request, const u8 requesttype,
const u16 offset, void *buffer,
const u16 buffer_length, const int timeout)
{
int status;
BUG_ON(!mutex_is_locked(&rt2x00dev->csr_mutex));
if (unlikely(!rt2x00dev->csr.cache || buffer_length > CSR_CACHE_SIZE)) {
rt2x00_err(rt2x00dev, "CSR cache not available\n");
return -ENOMEM;
}
if (requesttype == USB_VENDOR_REQUEST_OUT)
memcpy(rt2x00dev->csr.cache, buffer, buffer_length);
status = rt2x00usb_vendor_request(rt2x00dev, request, requesttype,
offset, 0, rt2x00dev->csr.cache,
buffer_length, timeout);
if (!status && requesttype == USB_VENDOR_REQUEST_IN)
memcpy(buffer, rt2x00dev->csr.cache, buffer_length);
return status;
}
int rt2x00usb_vendor_request_buff(struct rt2x00_dev *rt2x00dev,
const u8 request, const u8 requesttype,
const u16 offset, void *buffer,
const u16 buffer_length, const int timeout)
{
int status = 0;
unsigned char *tb;
u16 off, len, bsize;
mutex_lock(&rt2x00dev->csr_mutex);
tb = (char *)buffer;
off = offset;
len = buffer_length;
while (len && !status) {
bsize = min_t(u16, CSR_CACHE_SIZE, len);
status = rt2x00usb_vendor_req_buff_lock(rt2x00dev, request,
requesttype, off, tb,
bsize, timeout);
tb += bsize;
len -= bsize;
off += bsize;
}
mutex_unlock(&rt2x00dev->csr_mutex);
return status;
}
int rt2x00usb_regbusy_read(struct rt2x00_dev *rt2x00dev,
const unsigned int offset,
const struct rt2x00_field32 field,
u32 *reg)
{
unsigned int i;
if (!test_bit(DEVICE_STATE_PRESENT, &rt2x00dev->flags))
return -ENODEV;
for (i = 0; i < REGISTER_BUSY_COUNT; i++) {
rt2x00usb_register_read_lock(rt2x00dev, offset, reg);
if (!rt2x00_get_field32(*reg, field))
return 1;
udelay(REGISTER_BUSY_DELAY);
}
rt2x00_err(rt2x00dev, "Indirect register access failed: offset=0x%.08x, value=0x%.08x\n",
offset, *reg);
*reg = ~0;
return 0;
}
static void rt2x00usb_register_read_async_cb(struct urb *urb)
{
struct rt2x00_async_read_data *rd = urb->context;
if (rd->callback(rd->rt2x00dev, urb->status, le32_to_cpu(rd->reg))) {
if (usb_submit_urb(urb, GFP_ATOMIC) < 0)
kfree(rd);
} else
kfree(rd);
}
void rt2x00usb_register_read_async(struct rt2x00_dev *rt2x00dev,
const unsigned int offset,
bool (*callback)(struct rt2x00_dev*, int, u32))
{
struct usb_device *usb_dev = to_usb_device_intf(rt2x00dev->dev);
struct urb *urb;
struct rt2x00_async_read_data *rd;
rd = kmalloc(sizeof(*rd), GFP_ATOMIC);
if (!rd)
return;
urb = usb_alloc_urb(0, GFP_ATOMIC);
if (!urb) {
kfree(rd);
return;
}
rd->rt2x00dev = rt2x00dev;
rd->callback = callback;
rd->cr.bRequestType = USB_VENDOR_REQUEST_IN;
rd->cr.bRequest = USB_MULTI_READ;
rd->cr.wValue = 0;
rd->cr.wIndex = cpu_to_le16(offset);
rd->cr.wLength = cpu_to_le16(sizeof(u32));
usb_fill_control_urb(urb, usb_dev, usb_rcvctrlpipe(usb_dev, 0),
(unsigned char *)(&rd->cr), &rd->reg, sizeof(rd->reg),
rt2x00usb_register_read_async_cb, rd);
if (usb_submit_urb(urb, GFP_ATOMIC) < 0)
kfree(rd);
usb_free_urb(urb);
}
static void rt2x00usb_work_txdone_entry(struct queue_entry *entry)
{
if (test_bit(ENTRY_DATA_IO_FAILED, &entry->flags))
rt2x00lib_txdone_noinfo(entry, TXDONE_FAILURE);
else
rt2x00lib_txdone_noinfo(entry, TXDONE_UNKNOWN);
}
static void rt2x00usb_work_txdone(struct work_struct *work)
{
struct rt2x00_dev *rt2x00dev =
container_of(work, struct rt2x00_dev, txdone_work);
struct data_queue *queue;
struct queue_entry *entry;
tx_queue_for_each(rt2x00dev, queue) {
while (!rt2x00queue_empty(queue)) {
entry = rt2x00queue_get_entry(queue, Q_INDEX_DONE);
if (test_bit(ENTRY_OWNER_DEVICE_DATA, &entry->flags) ||
!test_bit(ENTRY_DATA_STATUS_PENDING, &entry->flags))
break;
rt2x00usb_work_txdone_entry(entry);
}
}
}
static void rt2x00usb_interrupt_txdone(struct urb *urb)
{
struct queue_entry *entry = (struct queue_entry *)urb->context;
struct rt2x00_dev *rt2x00dev = entry->queue->rt2x00dev;
if (!test_bit(ENTRY_OWNER_DEVICE_DATA, &entry->flags))
return;
if (urb->status)
set_bit(ENTRY_DATA_IO_FAILED, &entry->flags);
rt2x00lib_dmadone(entry);
if (rt2x00dev->ops->lib->tx_dma_done)
rt2x00dev->ops->lib->tx_dma_done(entry);
if (!test_bit(REQUIRE_TXSTATUS_FIFO, &rt2x00dev->cap_flags) ||
!kfifo_is_empty(&rt2x00dev->txstatus_fifo))
queue_work(rt2x00dev->workqueue, &rt2x00dev->txdone_work);
}
static bool rt2x00usb_kick_tx_entry(struct queue_entry *entry, void *data)
{
struct rt2x00_dev *rt2x00dev = entry->queue->rt2x00dev;
struct usb_device *usb_dev = to_usb_device_intf(rt2x00dev->dev);
struct queue_entry_priv_usb *entry_priv = entry->priv_data;
u32 length;
int status;
if (!test_and_clear_bit(ENTRY_DATA_PENDING, &entry->flags) ||
test_bit(ENTRY_DATA_STATUS_PENDING, &entry->flags))
return false;
length = rt2x00dev->ops->lib->get_tx_data_len(entry);
status = skb_padto(entry->skb, length);
if (unlikely(status)) {
rt2x00_warn(rt2x00dev, "TX SKB padding error, out of memory\n");
set_bit(ENTRY_DATA_IO_FAILED, &entry->flags);
rt2x00lib_dmadone(entry);
return false;
}
usb_fill_bulk_urb(entry_priv->urb, usb_dev,
usb_sndbulkpipe(usb_dev, entry->queue->usb_endpoint),
entry->skb->data, length,
rt2x00usb_interrupt_txdone, entry);
status = usb_submit_urb(entry_priv->urb, GFP_ATOMIC);
if (status) {
if (status == -ENODEV)
clear_bit(DEVICE_STATE_PRESENT, &rt2x00dev->flags);
set_bit(ENTRY_DATA_IO_FAILED, &entry->flags);
rt2x00lib_dmadone(entry);
}
return false;
}
static void rt2x00usb_work_rxdone(struct work_struct *work)
{
struct rt2x00_dev *rt2x00dev =
container_of(work, struct rt2x00_dev, rxdone_work);
struct queue_entry *entry;
struct skb_frame_desc *skbdesc;
u8 rxd[32];
while (!rt2x00queue_empty(rt2x00dev->rx)) {
entry = rt2x00queue_get_entry(rt2x00dev->rx, Q_INDEX_DONE);
if (test_bit(ENTRY_OWNER_DEVICE_DATA, &entry->flags) ||
!test_bit(ENTRY_DATA_STATUS_PENDING, &entry->flags))
break;
skbdesc = get_skb_frame_desc(entry->skb);
skbdesc->desc = rxd;
skbdesc->desc_len = entry->queue->desc_size;
rt2x00lib_rxdone(entry, GFP_KERNEL);
}
}
static void rt2x00usb_interrupt_rxdone(struct urb *urb)
{
struct queue_entry *entry = (struct queue_entry *)urb->context;
struct rt2x00_dev *rt2x00dev = entry->queue->rt2x00dev;
if (!test_and_clear_bit(ENTRY_OWNER_DEVICE_DATA, &entry->flags))
return;
rt2x00lib_dmadone(entry);
if (urb->actual_length < entry->queue->desc_size || urb->status)
set_bit(ENTRY_DATA_IO_FAILED, &entry->flags);
queue_work(rt2x00dev->workqueue, &rt2x00dev->rxdone_work);
}
static bool rt2x00usb_kick_rx_entry(struct queue_entry *entry, void *data)
{
struct rt2x00_dev *rt2x00dev = entry->queue->rt2x00dev;
struct usb_device *usb_dev = to_usb_device_intf(rt2x00dev->dev);
struct queue_entry_priv_usb *entry_priv = entry->priv_data;
int status;
if (test_and_set_bit(ENTRY_OWNER_DEVICE_DATA, &entry->flags) ||
test_bit(ENTRY_DATA_STATUS_PENDING, &entry->flags))
return false;
rt2x00lib_dmastart(entry);
usb_fill_bulk_urb(entry_priv->urb, usb_dev,
usb_rcvbulkpipe(usb_dev, entry->queue->usb_endpoint),
entry->skb->data, entry->skb->len,
rt2x00usb_interrupt_rxdone, entry);
status = usb_submit_urb(entry_priv->urb, GFP_ATOMIC);
if (status) {
if (status == -ENODEV)
clear_bit(DEVICE_STATE_PRESENT, &rt2x00dev->flags);
set_bit(ENTRY_DATA_IO_FAILED, &entry->flags);
rt2x00lib_dmadone(entry);
}
return false;
}
void rt2x00usb_kick_queue(struct data_queue *queue)
{
switch (queue->qid) {
case QID_AC_VO:
case QID_AC_VI:
case QID_AC_BE:
case QID_AC_BK:
if (!rt2x00queue_empty(queue))
rt2x00queue_for_each_entry(queue,
Q_INDEX_DONE,
Q_INDEX,
NULL,
rt2x00usb_kick_tx_entry);
break;
case QID_RX:
if (!rt2x00queue_full(queue))
rt2x00queue_for_each_entry(queue,
Q_INDEX,
Q_INDEX_DONE,
NULL,
rt2x00usb_kick_rx_entry);
break;
default:
break;
}
}
static bool rt2x00usb_flush_entry(struct queue_entry *entry, void *data)
{
struct rt2x00_dev *rt2x00dev = entry->queue->rt2x00dev;
struct queue_entry_priv_usb *entry_priv = entry->priv_data;
struct queue_entry_priv_usb_bcn *bcn_priv = entry->priv_data;
if (!test_bit(ENTRY_OWNER_DEVICE_DATA, &entry->flags))
return false;
usb_kill_urb(entry_priv->urb);
if ((entry->queue->qid == QID_BEACON) &&
(test_bit(REQUIRE_BEACON_GUARD, &rt2x00dev->cap_flags)))
usb_kill_urb(bcn_priv->guardian_urb);
return false;
}
void rt2x00usb_flush_queue(struct data_queue *queue, bool drop)
{
struct work_struct *completion;
unsigned int i;
if (drop)
rt2x00queue_for_each_entry(queue, Q_INDEX_DONE, Q_INDEX, NULL,
rt2x00usb_flush_entry);
switch (queue->qid) {
case QID_AC_VO:
case QID_AC_VI:
case QID_AC_BE:
case QID_AC_BK:
completion = &queue->rt2x00dev->txdone_work;
break;
case QID_RX:
completion = &queue->rt2x00dev->rxdone_work;
break;
default:
return;
}
for (i = 0; i < 10; i++) {
if (rt2x00queue_empty(queue))
break;
queue_work(queue->rt2x00dev->workqueue, completion);
msleep(10);
}
}
static void rt2x00usb_watchdog_tx_dma(struct data_queue *queue)
{
rt2x00_warn(queue->rt2x00dev, "TX queue %d DMA timed out, invoke forced forced reset\n",
queue->qid);
rt2x00queue_stop_queue(queue);
rt2x00queue_flush_queue(queue, true);
rt2x00queue_start_queue(queue);
}
static int rt2x00usb_dma_timeout(struct data_queue *queue)
{
struct queue_entry *entry;
entry = rt2x00queue_get_entry(queue, Q_INDEX_DMA_DONE);
return rt2x00queue_dma_timeout(entry);
}
void rt2x00usb_watchdog(struct rt2x00_dev *rt2x00dev)
{
struct data_queue *queue;
tx_queue_for_each(rt2x00dev, queue) {
if (!rt2x00queue_empty(queue)) {
if (rt2x00usb_dma_timeout(queue))
rt2x00usb_watchdog_tx_dma(queue);
}
}
}
void rt2x00usb_disable_radio(struct rt2x00_dev *rt2x00dev)
{
rt2x00usb_vendor_request_sw(rt2x00dev, USB_RX_CONTROL, 0, 0,
REGISTER_TIMEOUT);
}
void rt2x00usb_clear_entry(struct queue_entry *entry)
{
entry->flags = 0;
if (entry->queue->qid == QID_RX)
rt2x00usb_kick_rx_entry(entry, NULL);
}
static void rt2x00usb_assign_endpoint(struct data_queue *queue,
struct usb_endpoint_descriptor *ep_desc)
{
struct usb_device *usb_dev = to_usb_device_intf(queue->rt2x00dev->dev);
int pipe;
queue->usb_endpoint = usb_endpoint_num(ep_desc);
if (queue->qid == QID_RX) {
pipe = usb_rcvbulkpipe(usb_dev, queue->usb_endpoint);
queue->usb_maxpacket = usb_maxpacket(usb_dev, pipe, 0);
} else {
pipe = usb_sndbulkpipe(usb_dev, queue->usb_endpoint);
queue->usb_maxpacket = usb_maxpacket(usb_dev, pipe, 1);
}
if (!queue->usb_maxpacket)
queue->usb_maxpacket = 1;
}
static int rt2x00usb_find_endpoints(struct rt2x00_dev *rt2x00dev)
{
struct usb_interface *intf = to_usb_interface(rt2x00dev->dev);
struct usb_host_interface *intf_desc = intf->cur_altsetting;
struct usb_endpoint_descriptor *ep_desc;
struct data_queue *queue = rt2x00dev->tx;
struct usb_endpoint_descriptor *tx_ep_desc = NULL;
unsigned int i;
for (i = 0; i < intf_desc->desc.bNumEndpoints; i++) {
ep_desc = &intf_desc->endpoint[i].desc;
if (usb_endpoint_is_bulk_in(ep_desc)) {
rt2x00usb_assign_endpoint(rt2x00dev->rx, ep_desc);
} else if (usb_endpoint_is_bulk_out(ep_desc) &&
(queue != queue_end(rt2x00dev))) {
rt2x00usb_assign_endpoint(queue, ep_desc);
queue = queue_next(queue);
tx_ep_desc = ep_desc;
}
}
if (!rt2x00dev->rx->usb_endpoint || !rt2x00dev->tx->usb_endpoint) {
rt2x00_err(rt2x00dev, "Bulk-in/Bulk-out endpoints not found\n");
return -EPIPE;
}
txall_queue_for_each(rt2x00dev, queue) {
if (!queue->usb_endpoint)
rt2x00usb_assign_endpoint(queue, tx_ep_desc);
}
return 0;
}
static int rt2x00usb_alloc_entries(struct data_queue *queue)
{
struct rt2x00_dev *rt2x00dev = queue->rt2x00dev;
struct queue_entry_priv_usb *entry_priv;
struct queue_entry_priv_usb_bcn *bcn_priv;
unsigned int i;
for (i = 0; i < queue->limit; i++) {
entry_priv = queue->entries[i].priv_data;
entry_priv->urb = usb_alloc_urb(0, GFP_KERNEL);
if (!entry_priv->urb)
return -ENOMEM;
}
if (queue->qid != QID_BEACON ||
!test_bit(REQUIRE_BEACON_GUARD, &rt2x00dev->cap_flags))
return 0;
for (i = 0; i < queue->limit; i++) {
bcn_priv = queue->entries[i].priv_data;
bcn_priv->guardian_urb = usb_alloc_urb(0, GFP_KERNEL);
if (!bcn_priv->guardian_urb)
return -ENOMEM;
}
return 0;
}
static void rt2x00usb_free_entries(struct data_queue *queue)
{
struct rt2x00_dev *rt2x00dev = queue->rt2x00dev;
struct queue_entry_priv_usb *entry_priv;
struct queue_entry_priv_usb_bcn *bcn_priv;
unsigned int i;
if (!queue->entries)
return;
for (i = 0; i < queue->limit; i++) {
entry_priv = queue->entries[i].priv_data;
usb_kill_urb(entry_priv->urb);
usb_free_urb(entry_priv->urb);
}
if (queue->qid != QID_BEACON ||
!test_bit(REQUIRE_BEACON_GUARD, &rt2x00dev->cap_flags))
return;
for (i = 0; i < queue->limit; i++) {
bcn_priv = queue->entries[i].priv_data;
usb_kill_urb(bcn_priv->guardian_urb);
usb_free_urb(bcn_priv->guardian_urb);
}
}
int rt2x00usb_initialize(struct rt2x00_dev *rt2x00dev)
{
struct data_queue *queue;
int status;
status = rt2x00usb_find_endpoints(rt2x00dev);
if (status)
goto exit;
queue_for_each(rt2x00dev, queue) {
status = rt2x00usb_alloc_entries(queue);
if (status)
goto exit;
}
return 0;
exit:
rt2x00usb_uninitialize(rt2x00dev);
return status;
}
void rt2x00usb_uninitialize(struct rt2x00_dev *rt2x00dev)
{
struct data_queue *queue;
queue_for_each(rt2x00dev, queue)
rt2x00usb_free_entries(queue);
}
static void rt2x00usb_free_reg(struct rt2x00_dev *rt2x00dev)
{
kfree(rt2x00dev->rf);
rt2x00dev->rf = NULL;
kfree(rt2x00dev->eeprom);
rt2x00dev->eeprom = NULL;
kfree(rt2x00dev->csr.cache);
rt2x00dev->csr.cache = NULL;
}
static int rt2x00usb_alloc_reg(struct rt2x00_dev *rt2x00dev)
{
rt2x00dev->csr.cache = kzalloc(CSR_CACHE_SIZE, GFP_KERNEL);
if (!rt2x00dev->csr.cache)
goto exit;
rt2x00dev->eeprom = kzalloc(rt2x00dev->ops->eeprom_size, GFP_KERNEL);
if (!rt2x00dev->eeprom)
goto exit;
rt2x00dev->rf = kzalloc(rt2x00dev->ops->rf_size, GFP_KERNEL);
if (!rt2x00dev->rf)
goto exit;
return 0;
exit:
rt2x00_probe_err("Failed to allocate registers\n");
rt2x00usb_free_reg(rt2x00dev);
return -ENOMEM;
}
int rt2x00usb_probe(struct usb_interface *usb_intf,
const struct rt2x00_ops *ops)
{
struct usb_device *usb_dev = interface_to_usbdev(usb_intf);
struct ieee80211_hw *hw;
struct rt2x00_dev *rt2x00dev;
int retval;
usb_dev = usb_get_dev(usb_dev);
usb_reset_device(usb_dev);
hw = ieee80211_alloc_hw(sizeof(struct rt2x00_dev), ops->hw);
if (!hw) {
rt2x00_probe_err("Failed to allocate hardware\n");
retval = -ENOMEM;
goto exit_put_device;
}
usb_set_intfdata(usb_intf, hw);
rt2x00dev = hw->priv;
rt2x00dev->dev = &usb_intf->dev;
rt2x00dev->ops = ops;
rt2x00dev->hw = hw;
rt2x00_set_chip_intf(rt2x00dev, RT2X00_CHIP_INTF_USB);
INIT_WORK(&rt2x00dev->rxdone_work, rt2x00usb_work_rxdone);
INIT_WORK(&rt2x00dev->txdone_work, rt2x00usb_work_txdone);
hrtimer_init(&rt2x00dev->txstatus_timer, CLOCK_MONOTONIC,
HRTIMER_MODE_REL);
retval = rt2x00usb_alloc_reg(rt2x00dev);
if (retval)
goto exit_free_device;
retval = rt2x00lib_probe_dev(rt2x00dev);
if (retval)
goto exit_free_reg;
return 0;
exit_free_reg:
rt2x00usb_free_reg(rt2x00dev);
exit_free_device:
ieee80211_free_hw(hw);
exit_put_device:
usb_put_dev(usb_dev);
usb_set_intfdata(usb_intf, NULL);
return retval;
}
void rt2x00usb_disconnect(struct usb_interface *usb_intf)
{
struct ieee80211_hw *hw = usb_get_intfdata(usb_intf);
struct rt2x00_dev *rt2x00dev = hw->priv;
rt2x00lib_remove_dev(rt2x00dev);
rt2x00usb_free_reg(rt2x00dev);
ieee80211_free_hw(hw);
usb_set_intfdata(usb_intf, NULL);
usb_put_dev(interface_to_usbdev(usb_intf));
}
int rt2x00usb_suspend(struct usb_interface *usb_intf, pm_message_t state)
{
struct ieee80211_hw *hw = usb_get_intfdata(usb_intf);
struct rt2x00_dev *rt2x00dev = hw->priv;
return rt2x00lib_suspend(rt2x00dev, state);
}
int rt2x00usb_resume(struct usb_interface *usb_intf)
{
struct ieee80211_hw *hw = usb_get_intfdata(usb_intf);
struct rt2x00_dev *rt2x00dev = hw->priv;
return rt2x00lib_resume(rt2x00dev);
}
