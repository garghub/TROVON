static inline void btusb_free_frags(struct btusb_data *data)
{
unsigned long flags;
spin_lock_irqsave(&data->rxlock, flags);
kfree_skb(data->evt_skb);
data->evt_skb = NULL;
kfree_skb(data->acl_skb);
data->acl_skb = NULL;
kfree_skb(data->sco_skb);
data->sco_skb = NULL;
spin_unlock_irqrestore(&data->rxlock, flags);
}
static int btusb_recv_intr(struct btusb_data *data, void *buffer, int count)
{
struct sk_buff *skb;
int err = 0;
spin_lock(&data->rxlock);
skb = data->evt_skb;
while (count) {
int len;
if (!skb) {
skb = bt_skb_alloc(HCI_MAX_EVENT_SIZE, GFP_ATOMIC);
if (!skb) {
err = -ENOMEM;
break;
}
bt_cb(skb)->pkt_type = HCI_EVENT_PKT;
bt_cb(skb)->expect = HCI_EVENT_HDR_SIZE;
}
len = min_t(uint, bt_cb(skb)->expect, count);
memcpy(skb_put(skb, len), buffer, len);
count -= len;
buffer += len;
bt_cb(skb)->expect -= len;
if (skb->len == HCI_EVENT_HDR_SIZE) {
bt_cb(skb)->expect = hci_event_hdr(skb)->plen;
if (skb_tailroom(skb) < bt_cb(skb)->expect) {
kfree_skb(skb);
skb = NULL;
err = -EILSEQ;
break;
}
}
if (bt_cb(skb)->expect == 0) {
hci_recv_frame(data->hdev, skb);
skb = NULL;
}
}
data->evt_skb = skb;
spin_unlock(&data->rxlock);
return err;
}
static int btusb_recv_bulk(struct btusb_data *data, void *buffer, int count)
{
struct sk_buff *skb;
int err = 0;
spin_lock(&data->rxlock);
skb = data->acl_skb;
while (count) {
int len;
if (!skb) {
skb = bt_skb_alloc(HCI_MAX_FRAME_SIZE, GFP_ATOMIC);
if (!skb) {
err = -ENOMEM;
break;
}
bt_cb(skb)->pkt_type = HCI_ACLDATA_PKT;
bt_cb(skb)->expect = HCI_ACL_HDR_SIZE;
}
len = min_t(uint, bt_cb(skb)->expect, count);
memcpy(skb_put(skb, len), buffer, len);
count -= len;
buffer += len;
bt_cb(skb)->expect -= len;
if (skb->len == HCI_ACL_HDR_SIZE) {
__le16 dlen = hci_acl_hdr(skb)->dlen;
bt_cb(skb)->expect = __le16_to_cpu(dlen);
if (skb_tailroom(skb) < bt_cb(skb)->expect) {
kfree_skb(skb);
skb = NULL;
err = -EILSEQ;
break;
}
}
if (bt_cb(skb)->expect == 0) {
hci_recv_frame(data->hdev, skb);
skb = NULL;
}
}
data->acl_skb = skb;
spin_unlock(&data->rxlock);
return err;
}
static int btusb_recv_isoc(struct btusb_data *data, void *buffer, int count)
{
struct sk_buff *skb;
int err = 0;
spin_lock(&data->rxlock);
skb = data->sco_skb;
while (count) {
int len;
if (!skb) {
skb = bt_skb_alloc(HCI_MAX_SCO_SIZE, GFP_ATOMIC);
if (!skb) {
err = -ENOMEM;
break;
}
bt_cb(skb)->pkt_type = HCI_SCODATA_PKT;
bt_cb(skb)->expect = HCI_SCO_HDR_SIZE;
}
len = min_t(uint, bt_cb(skb)->expect, count);
memcpy(skb_put(skb, len), buffer, len);
count -= len;
buffer += len;
bt_cb(skb)->expect -= len;
if (skb->len == HCI_SCO_HDR_SIZE) {
bt_cb(skb)->expect = hci_sco_hdr(skb)->dlen;
if (skb_tailroom(skb) < bt_cb(skb)->expect) {
kfree_skb(skb);
skb = NULL;
err = -EILSEQ;
break;
}
}
if (bt_cb(skb)->expect == 0) {
hci_recv_frame(data->hdev, skb);
skb = NULL;
}
}
data->sco_skb = skb;
spin_unlock(&data->rxlock);
return err;
}
static void btusb_intr_complete(struct urb *urb)
{
struct hci_dev *hdev = urb->context;
struct btusb_data *data = hci_get_drvdata(hdev);
int err;
BT_DBG("%s urb %p status %d count %d", hdev->name, urb, urb->status,
urb->actual_length);
if (!test_bit(HCI_RUNNING, &hdev->flags))
return;
if (urb->status == 0) {
hdev->stat.byte_rx += urb->actual_length;
if (btusb_recv_intr(data, urb->transfer_buffer,
urb->actual_length) < 0) {
BT_ERR("%s corrupted event packet", hdev->name);
hdev->stat.err_rx++;
}
} else if (urb->status == -ENOENT) {
return;
}
if (!test_bit(BTUSB_INTR_RUNNING, &data->flags))
return;
usb_mark_last_busy(data->udev);
usb_anchor_urb(urb, &data->intr_anchor);
err = usb_submit_urb(urb, GFP_ATOMIC);
if (err < 0) {
if (err != -EPERM && err != -ENODEV)
BT_ERR("%s urb %p failed to resubmit (%d)",
hdev->name, urb, -err);
usb_unanchor_urb(urb);
}
}
static int btusb_submit_intr_urb(struct hci_dev *hdev, gfp_t mem_flags)
{
struct btusb_data *data = hci_get_drvdata(hdev);
struct urb *urb;
unsigned char *buf;
unsigned int pipe;
int err, size;
BT_DBG("%s", hdev->name);
if (!data->intr_ep)
return -ENODEV;
urb = usb_alloc_urb(0, mem_flags);
if (!urb)
return -ENOMEM;
size = le16_to_cpu(data->intr_ep->wMaxPacketSize);
buf = kmalloc(size, mem_flags);
if (!buf) {
usb_free_urb(urb);
return -ENOMEM;
}
pipe = usb_rcvintpipe(data->udev, data->intr_ep->bEndpointAddress);
usb_fill_int_urb(urb, data->udev, pipe, buf, size,
btusb_intr_complete, hdev, data->intr_ep->bInterval);
urb->transfer_flags |= URB_FREE_BUFFER;
usb_anchor_urb(urb, &data->intr_anchor);
err = usb_submit_urb(urb, mem_flags);
if (err < 0) {
if (err != -EPERM && err != -ENODEV)
BT_ERR("%s urb %p submission failed (%d)",
hdev->name, urb, -err);
usb_unanchor_urb(urb);
}
usb_free_urb(urb);
return err;
}
static void btusb_bulk_complete(struct urb *urb)
{
struct hci_dev *hdev = urb->context;
struct btusb_data *data = hci_get_drvdata(hdev);
int err;
BT_DBG("%s urb %p status %d count %d", hdev->name, urb, urb->status,
urb->actual_length);
if (!test_bit(HCI_RUNNING, &hdev->flags))
return;
if (urb->status == 0) {
hdev->stat.byte_rx += urb->actual_length;
if (btusb_recv_bulk(data, urb->transfer_buffer,
urb->actual_length) < 0) {
BT_ERR("%s corrupted ACL packet", hdev->name);
hdev->stat.err_rx++;
}
} else if (urb->status == -ENOENT) {
return;
}
if (!test_bit(BTUSB_BULK_RUNNING, &data->flags))
return;
usb_anchor_urb(urb, &data->bulk_anchor);
usb_mark_last_busy(data->udev);
err = usb_submit_urb(urb, GFP_ATOMIC);
if (err < 0) {
if (err != -EPERM && err != -ENODEV)
BT_ERR("%s urb %p failed to resubmit (%d)",
hdev->name, urb, -err);
usb_unanchor_urb(urb);
}
}
static int btusb_submit_bulk_urb(struct hci_dev *hdev, gfp_t mem_flags)
{
struct btusb_data *data = hci_get_drvdata(hdev);
struct urb *urb;
unsigned char *buf;
unsigned int pipe;
int err, size = HCI_MAX_FRAME_SIZE;
BT_DBG("%s", hdev->name);
if (!data->bulk_rx_ep)
return -ENODEV;
urb = usb_alloc_urb(0, mem_flags);
if (!urb)
return -ENOMEM;
buf = kmalloc(size, mem_flags);
if (!buf) {
usb_free_urb(urb);
return -ENOMEM;
}
pipe = usb_rcvbulkpipe(data->udev, data->bulk_rx_ep->bEndpointAddress);
usb_fill_bulk_urb(urb, data->udev, pipe, buf, size,
btusb_bulk_complete, hdev);
urb->transfer_flags |= URB_FREE_BUFFER;
usb_mark_last_busy(data->udev);
usb_anchor_urb(urb, &data->bulk_anchor);
err = usb_submit_urb(urb, mem_flags);
if (err < 0) {
if (err != -EPERM && err != -ENODEV)
BT_ERR("%s urb %p submission failed (%d)",
hdev->name, urb, -err);
usb_unanchor_urb(urb);
}
usb_free_urb(urb);
return err;
}
static void btusb_isoc_complete(struct urb *urb)
{
struct hci_dev *hdev = urb->context;
struct btusb_data *data = hci_get_drvdata(hdev);
int i, err;
BT_DBG("%s urb %p status %d count %d", hdev->name, urb, urb->status,
urb->actual_length);
if (!test_bit(HCI_RUNNING, &hdev->flags))
return;
if (urb->status == 0) {
for (i = 0; i < urb->number_of_packets; i++) {
unsigned int offset = urb->iso_frame_desc[i].offset;
unsigned int length = urb->iso_frame_desc[i].actual_length;
if (urb->iso_frame_desc[i].status)
continue;
hdev->stat.byte_rx += length;
if (btusb_recv_isoc(data, urb->transfer_buffer + offset,
length) < 0) {
BT_ERR("%s corrupted SCO packet", hdev->name);
hdev->stat.err_rx++;
}
}
} else if (urb->status == -ENOENT) {
return;
}
if (!test_bit(BTUSB_ISOC_RUNNING, &data->flags))
return;
usb_anchor_urb(urb, &data->isoc_anchor);
err = usb_submit_urb(urb, GFP_ATOMIC);
if (err < 0) {
if (err != -EPERM && err != -ENODEV)
BT_ERR("%s urb %p failed to resubmit (%d)",
hdev->name, urb, -err);
usb_unanchor_urb(urb);
}
}
static inline void __fill_isoc_descriptor(struct urb *urb, int len, int mtu)
{
int i, offset = 0;
BT_DBG("len %d mtu %d", len, mtu);
for (i = 0; i < BTUSB_MAX_ISOC_FRAMES && len >= mtu;
i++, offset += mtu, len -= mtu) {
urb->iso_frame_desc[i].offset = offset;
urb->iso_frame_desc[i].length = mtu;
}
if (len && i < BTUSB_MAX_ISOC_FRAMES) {
urb->iso_frame_desc[i].offset = offset;
urb->iso_frame_desc[i].length = len;
i++;
}
urb->number_of_packets = i;
}
static int btusb_submit_isoc_urb(struct hci_dev *hdev, gfp_t mem_flags)
{
struct btusb_data *data = hci_get_drvdata(hdev);
struct urb *urb;
unsigned char *buf;
unsigned int pipe;
int err, size;
BT_DBG("%s", hdev->name);
if (!data->isoc_rx_ep)
return -ENODEV;
urb = usb_alloc_urb(BTUSB_MAX_ISOC_FRAMES, mem_flags);
if (!urb)
return -ENOMEM;
size = le16_to_cpu(data->isoc_rx_ep->wMaxPacketSize) *
BTUSB_MAX_ISOC_FRAMES;
buf = kmalloc(size, mem_flags);
if (!buf) {
usb_free_urb(urb);
return -ENOMEM;
}
pipe = usb_rcvisocpipe(data->udev, data->isoc_rx_ep->bEndpointAddress);
usb_fill_int_urb(urb, data->udev, pipe, buf, size, btusb_isoc_complete,
hdev, data->isoc_rx_ep->bInterval);
urb->transfer_flags = URB_FREE_BUFFER | URB_ISO_ASAP;
__fill_isoc_descriptor(urb, size,
le16_to_cpu(data->isoc_rx_ep->wMaxPacketSize));
usb_anchor_urb(urb, &data->isoc_anchor);
err = usb_submit_urb(urb, mem_flags);
if (err < 0) {
if (err != -EPERM && err != -ENODEV)
BT_ERR("%s urb %p submission failed (%d)",
hdev->name, urb, -err);
usb_unanchor_urb(urb);
}
usb_free_urb(urb);
return err;
}
static void btusb_tx_complete(struct urb *urb)
{
struct sk_buff *skb = urb->context;
struct hci_dev *hdev = (struct hci_dev *)skb->dev;
struct btusb_data *data = hci_get_drvdata(hdev);
BT_DBG("%s urb %p status %d count %d", hdev->name, urb, urb->status,
urb->actual_length);
if (!test_bit(HCI_RUNNING, &hdev->flags))
goto done;
if (!urb->status)
hdev->stat.byte_tx += urb->transfer_buffer_length;
else
hdev->stat.err_tx++;
done:
spin_lock(&data->txlock);
data->tx_in_flight--;
spin_unlock(&data->txlock);
kfree(urb->setup_packet);
kfree_skb(skb);
}
static void btusb_isoc_tx_complete(struct urb *urb)
{
struct sk_buff *skb = urb->context;
struct hci_dev *hdev = (struct hci_dev *)skb->dev;
BT_DBG("%s urb %p status %d count %d", hdev->name, urb, urb->status,
urb->actual_length);
if (!test_bit(HCI_RUNNING, &hdev->flags))
goto done;
if (!urb->status)
hdev->stat.byte_tx += urb->transfer_buffer_length;
else
hdev->stat.err_tx++;
done:
kfree(urb->setup_packet);
kfree_skb(skb);
}
static int btusb_open(struct hci_dev *hdev)
{
struct btusb_data *data = hci_get_drvdata(hdev);
int err;
BT_DBG("%s", hdev->name);
err = usb_autopm_get_interface(data->intf);
if (err < 0)
return err;
data->intf->needs_remote_wakeup = 1;
if (test_and_set_bit(HCI_RUNNING, &hdev->flags))
goto done;
if (test_and_set_bit(BTUSB_INTR_RUNNING, &data->flags))
goto done;
err = btusb_submit_intr_urb(hdev, GFP_KERNEL);
if (err < 0)
goto failed;
err = btusb_submit_bulk_urb(hdev, GFP_KERNEL);
if (err < 0) {
usb_kill_anchored_urbs(&data->intr_anchor);
goto failed;
}
set_bit(BTUSB_BULK_RUNNING, &data->flags);
btusb_submit_bulk_urb(hdev, GFP_KERNEL);
done:
usb_autopm_put_interface(data->intf);
return 0;
failed:
clear_bit(BTUSB_INTR_RUNNING, &data->flags);
clear_bit(HCI_RUNNING, &hdev->flags);
usb_autopm_put_interface(data->intf);
return err;
}
static void btusb_stop_traffic(struct btusb_data *data)
{
usb_kill_anchored_urbs(&data->intr_anchor);
usb_kill_anchored_urbs(&data->bulk_anchor);
usb_kill_anchored_urbs(&data->isoc_anchor);
}
static int btusb_close(struct hci_dev *hdev)
{
struct btusb_data *data = hci_get_drvdata(hdev);
int err;
BT_DBG("%s", hdev->name);
if (!test_and_clear_bit(HCI_RUNNING, &hdev->flags))
return 0;
cancel_work_sync(&data->work);
cancel_work_sync(&data->waker);
clear_bit(BTUSB_ISOC_RUNNING, &data->flags);
clear_bit(BTUSB_BULK_RUNNING, &data->flags);
clear_bit(BTUSB_INTR_RUNNING, &data->flags);
btusb_stop_traffic(data);
btusb_free_frags(data);
err = usb_autopm_get_interface(data->intf);
if (err < 0)
goto failed;
data->intf->needs_remote_wakeup = 0;
usb_autopm_put_interface(data->intf);
failed:
usb_scuttle_anchored_urbs(&data->deferred);
return 0;
}
static int btusb_flush(struct hci_dev *hdev)
{
struct btusb_data *data = hci_get_drvdata(hdev);
BT_DBG("%s", hdev->name);
usb_kill_anchored_urbs(&data->tx_anchor);
btusb_free_frags(data);
return 0;
}
static struct urb *alloc_ctrl_urb(struct hci_dev *hdev, struct sk_buff *skb)
{
struct btusb_data *data = hci_get_drvdata(hdev);
struct usb_ctrlrequest *dr;
struct urb *urb;
unsigned int pipe;
urb = usb_alloc_urb(0, GFP_KERNEL);
if (!urb)
return ERR_PTR(-ENOMEM);
dr = kmalloc(sizeof(*dr), GFP_KERNEL);
if (!dr) {
usb_free_urb(urb);
return ERR_PTR(-ENOMEM);
}
dr->bRequestType = data->cmdreq_type;
dr->bRequest = 0;
dr->wIndex = 0;
dr->wValue = 0;
dr->wLength = __cpu_to_le16(skb->len);
pipe = usb_sndctrlpipe(data->udev, 0x00);
usb_fill_control_urb(urb, data->udev, pipe, (void *)dr,
skb->data, skb->len, btusb_tx_complete, skb);
skb->dev = (void *)hdev;
return urb;
}
static struct urb *alloc_bulk_urb(struct hci_dev *hdev, struct sk_buff *skb)
{
struct btusb_data *data = hci_get_drvdata(hdev);
struct urb *urb;
unsigned int pipe;
if (!data->bulk_tx_ep)
return ERR_PTR(-ENODEV);
urb = usb_alloc_urb(0, GFP_KERNEL);
if (!urb)
return ERR_PTR(-ENOMEM);
pipe = usb_sndbulkpipe(data->udev, data->bulk_tx_ep->bEndpointAddress);
usb_fill_bulk_urb(urb, data->udev, pipe,
skb->data, skb->len, btusb_tx_complete, skb);
skb->dev = (void *)hdev;
return urb;
}
static struct urb *alloc_isoc_urb(struct hci_dev *hdev, struct sk_buff *skb)
{
struct btusb_data *data = hci_get_drvdata(hdev);
struct urb *urb;
unsigned int pipe;
if (!data->isoc_tx_ep)
return ERR_PTR(-ENODEV);
urb = usb_alloc_urb(BTUSB_MAX_ISOC_FRAMES, GFP_KERNEL);
if (!urb)
return ERR_PTR(-ENOMEM);
pipe = usb_sndisocpipe(data->udev, data->isoc_tx_ep->bEndpointAddress);
usb_fill_int_urb(urb, data->udev, pipe,
skb->data, skb->len, btusb_isoc_tx_complete,
skb, data->isoc_tx_ep->bInterval);
urb->transfer_flags = URB_ISO_ASAP;
__fill_isoc_descriptor(urb, skb->len,
le16_to_cpu(data->isoc_tx_ep->wMaxPacketSize));
skb->dev = (void *)hdev;
return urb;
}
static int submit_tx_urb(struct hci_dev *hdev, struct urb *urb)
{
struct btusb_data *data = hci_get_drvdata(hdev);
int err;
usb_anchor_urb(urb, &data->tx_anchor);
err = usb_submit_urb(urb, GFP_KERNEL);
if (err < 0) {
if (err != -EPERM && err != -ENODEV)
BT_ERR("%s urb %p submission failed (%d)",
hdev->name, urb, -err);
kfree(urb->setup_packet);
usb_unanchor_urb(urb);
} else {
usb_mark_last_busy(data->udev);
}
usb_free_urb(urb);
return err;
}
static int submit_or_queue_tx_urb(struct hci_dev *hdev, struct urb *urb)
{
struct btusb_data *data = hci_get_drvdata(hdev);
unsigned long flags;
bool suspending;
spin_lock_irqsave(&data->txlock, flags);
suspending = test_bit(BTUSB_SUSPENDING, &data->flags);
if (!suspending)
data->tx_in_flight++;
spin_unlock_irqrestore(&data->txlock, flags);
if (!suspending)
return submit_tx_urb(hdev, urb);
usb_anchor_urb(urb, &data->deferred);
schedule_work(&data->waker);
usb_free_urb(urb);
return 0;
}
static int btusb_send_frame(struct hci_dev *hdev, struct sk_buff *skb)
{
struct urb *urb;
BT_DBG("%s", hdev->name);
if (!test_bit(HCI_RUNNING, &hdev->flags))
return -EBUSY;
switch (bt_cb(skb)->pkt_type) {
case HCI_COMMAND_PKT:
urb = alloc_ctrl_urb(hdev, skb);
if (IS_ERR(urb))
return PTR_ERR(urb);
hdev->stat.cmd_tx++;
return submit_or_queue_tx_urb(hdev, urb);
case HCI_ACLDATA_PKT:
urb = alloc_bulk_urb(hdev, skb);
if (IS_ERR(urb))
return PTR_ERR(urb);
hdev->stat.acl_tx++;
return submit_or_queue_tx_urb(hdev, urb);
case HCI_SCODATA_PKT:
if (hci_conn_num(hdev, SCO_LINK) < 1)
return -ENODEV;
urb = alloc_isoc_urb(hdev, skb);
if (IS_ERR(urb))
return PTR_ERR(urb);
hdev->stat.sco_tx++;
return submit_tx_urb(hdev, urb);
}
return -EILSEQ;
}
static void btusb_notify(struct hci_dev *hdev, unsigned int evt)
{
struct btusb_data *data = hci_get_drvdata(hdev);
BT_DBG("%s evt %d", hdev->name, evt);
if (hci_conn_num(hdev, SCO_LINK) != data->sco_num) {
data->sco_num = hci_conn_num(hdev, SCO_LINK);
schedule_work(&data->work);
}
}
static inline int __set_isoc_interface(struct hci_dev *hdev, int altsetting)
{
struct btusb_data *data = hci_get_drvdata(hdev);
struct usb_interface *intf = data->isoc;
struct usb_endpoint_descriptor *ep_desc;
int i, err;
if (!data->isoc)
return -ENODEV;
err = usb_set_interface(data->udev, 1, altsetting);
if (err < 0) {
BT_ERR("%s setting interface failed (%d)", hdev->name, -err);
return err;
}
data->isoc_altsetting = altsetting;
data->isoc_tx_ep = NULL;
data->isoc_rx_ep = NULL;
for (i = 0; i < intf->cur_altsetting->desc.bNumEndpoints; i++) {
ep_desc = &intf->cur_altsetting->endpoint[i].desc;
if (!data->isoc_tx_ep && usb_endpoint_is_isoc_out(ep_desc)) {
data->isoc_tx_ep = ep_desc;
continue;
}
if (!data->isoc_rx_ep && usb_endpoint_is_isoc_in(ep_desc)) {
data->isoc_rx_ep = ep_desc;
continue;
}
}
if (!data->isoc_tx_ep || !data->isoc_rx_ep) {
BT_ERR("%s invalid SCO descriptors", hdev->name);
return -ENODEV;
}
return 0;
}
static void btusb_work(struct work_struct *work)
{
struct btusb_data *data = container_of(work, struct btusb_data, work);
struct hci_dev *hdev = data->hdev;
int new_alts;
int err;
if (data->sco_num > 0) {
if (!test_bit(BTUSB_DID_ISO_RESUME, &data->flags)) {
err = usb_autopm_get_interface(data->isoc ? data->isoc : data->intf);
if (err < 0) {
clear_bit(BTUSB_ISOC_RUNNING, &data->flags);
usb_kill_anchored_urbs(&data->isoc_anchor);
return;
}
set_bit(BTUSB_DID_ISO_RESUME, &data->flags);
}
if (hdev->voice_setting & 0x0020) {
static const int alts[3] = { 2, 4, 5 };
new_alts = alts[data->sco_num - 1];
} else {
new_alts = data->sco_num;
}
if (data->isoc_altsetting != new_alts) {
clear_bit(BTUSB_ISOC_RUNNING, &data->flags);
usb_kill_anchored_urbs(&data->isoc_anchor);
if (__set_isoc_interface(hdev, new_alts) < 0)
return;
}
if (!test_and_set_bit(BTUSB_ISOC_RUNNING, &data->flags)) {
if (btusb_submit_isoc_urb(hdev, GFP_KERNEL) < 0)
clear_bit(BTUSB_ISOC_RUNNING, &data->flags);
else
btusb_submit_isoc_urb(hdev, GFP_KERNEL);
}
} else {
clear_bit(BTUSB_ISOC_RUNNING, &data->flags);
usb_kill_anchored_urbs(&data->isoc_anchor);
__set_isoc_interface(hdev, 0);
if (test_and_clear_bit(BTUSB_DID_ISO_RESUME, &data->flags))
usb_autopm_put_interface(data->isoc ? data->isoc : data->intf);
}
}
static void btusb_waker(struct work_struct *work)
{
struct btusb_data *data = container_of(work, struct btusb_data, waker);
int err;
err = usb_autopm_get_interface(data->intf);
if (err < 0)
return;
usb_autopm_put_interface(data->intf);
}
static int btusb_setup_bcm92035(struct hci_dev *hdev)
{
struct sk_buff *skb;
u8 val = 0x00;
BT_DBG("%s", hdev->name);
skb = __hci_cmd_sync(hdev, 0xfc3b, 1, &val, HCI_INIT_TIMEOUT);
if (IS_ERR(skb))
BT_ERR("BCM92035 command failed (%ld)", -PTR_ERR(skb));
else
kfree_skb(skb);
return 0;
}
static int btusb_setup_csr(struct hci_dev *hdev)
{
struct hci_rp_read_local_version *rp;
struct sk_buff *skb;
int ret;
BT_DBG("%s", hdev->name);
skb = __hci_cmd_sync(hdev, HCI_OP_READ_LOCAL_VERSION, 0, NULL,
HCI_INIT_TIMEOUT);
if (IS_ERR(skb)) {
BT_ERR("Reading local version failed (%ld)", -PTR_ERR(skb));
return -PTR_ERR(skb);
}
rp = (struct hci_rp_read_local_version *)skb->data;
if (!rp->status) {
if (le16_to_cpu(rp->manufacturer) != 10) {
clear_bit(HCI_QUIRK_RESET_ON_CLOSE, &hdev->quirks);
set_bit(HCI_QUIRK_BROKEN_STORED_LINK_KEY,
&hdev->quirks);
}
}
ret = -bt_to_errno(rp->status);
kfree_skb(skb);
return ret;
}
static const struct firmware *btusb_setup_intel_get_fw(struct hci_dev *hdev,
struct intel_version *ver)
{
const struct firmware *fw;
char fwname[64];
int ret;
snprintf(fwname, sizeof(fwname),
"intel/ibt-hw-%x.%x.%x-fw-%x.%x.%x.%x.%x.bseq",
ver->hw_platform, ver->hw_variant, ver->hw_revision,
ver->fw_variant, ver->fw_revision, ver->fw_build_num,
ver->fw_build_ww, ver->fw_build_yy);
ret = request_firmware(&fw, fwname, &hdev->dev);
if (ret < 0) {
if (ret == -EINVAL) {
BT_ERR("%s Intel firmware file request failed (%d)",
hdev->name, ret);
return NULL;
}
BT_ERR("%s failed to open Intel firmware file: %s(%d)",
hdev->name, fwname, ret);
snprintf(fwname, sizeof(fwname), "intel/ibt-hw-%x.%x.bseq",
ver->hw_platform, ver->hw_variant);
if (request_firmware(&fw, fwname, &hdev->dev) < 0) {
BT_ERR("%s failed to open default Intel fw file: %s",
hdev->name, fwname);
return NULL;
}
}
BT_INFO("%s: Intel Bluetooth firmware file: %s", hdev->name, fwname);
return fw;
}
static int btusb_setup_intel_patching(struct hci_dev *hdev,
const struct firmware *fw,
const u8 **fw_ptr, int *disable_patch)
{
struct sk_buff *skb;
struct hci_command_hdr *cmd;
const u8 *cmd_param;
struct hci_event_hdr *evt = NULL;
const u8 *evt_param = NULL;
int remain = fw->size - (*fw_ptr - fw->data);
if (remain > HCI_COMMAND_HDR_SIZE && *fw_ptr[0] != 0x01) {
BT_ERR("%s Intel fw corrupted: invalid cmd read", hdev->name);
return -EINVAL;
}
(*fw_ptr)++;
remain--;
cmd = (struct hci_command_hdr *)(*fw_ptr);
*fw_ptr += sizeof(*cmd);
remain -= sizeof(*cmd);
if (remain < cmd->plen) {
BT_ERR("%s Intel fw corrupted: invalid cmd len", hdev->name);
return -EFAULT;
}
if (*disable_patch && le16_to_cpu(cmd->opcode) == 0xfc8e)
*disable_patch = 0;
cmd_param = *fw_ptr;
*fw_ptr += cmd->plen;
remain -= cmd->plen;
while (remain > HCI_EVENT_HDR_SIZE && *fw_ptr[0] == 0x02) {
(*fw_ptr)++;
remain--;
evt = (struct hci_event_hdr *)(*fw_ptr);
*fw_ptr += sizeof(*evt);
remain -= sizeof(*evt);
if (remain < evt->plen) {
BT_ERR("%s Intel fw corrupted: invalid evt len",
hdev->name);
return -EFAULT;
}
evt_param = *fw_ptr;
*fw_ptr += evt->plen;
remain -= evt->plen;
}
if (!evt || !evt_param || remain < 0) {
BT_ERR("%s Intel fw corrupted: invalid evt read", hdev->name);
return -EFAULT;
}
skb = __hci_cmd_sync_ev(hdev, le16_to_cpu(cmd->opcode), cmd->plen,
cmd_param, evt->evt, HCI_INIT_TIMEOUT);
if (IS_ERR(skb)) {
BT_ERR("%s sending Intel patch command (0x%4.4x) failed (%ld)",
hdev->name, cmd->opcode, PTR_ERR(skb));
return PTR_ERR(skb);
}
if (skb->len != evt->plen) {
BT_ERR("%s mismatch event length (opcode 0x%4.4x)", hdev->name,
le16_to_cpu(cmd->opcode));
kfree_skb(skb);
return -EFAULT;
}
if (memcmp(skb->data, evt_param, evt->plen)) {
BT_ERR("%s mismatch event parameter (opcode 0x%4.4x)",
hdev->name, le16_to_cpu(cmd->opcode));
kfree_skb(skb);
return -EFAULT;
}
kfree_skb(skb);
return 0;
}
static int btusb_check_bdaddr_intel(struct hci_dev *hdev)
{
struct sk_buff *skb;
struct hci_rp_read_bd_addr *rp;
skb = __hci_cmd_sync(hdev, HCI_OP_READ_BD_ADDR, 0, NULL,
HCI_INIT_TIMEOUT);
if (IS_ERR(skb)) {
BT_ERR("%s reading Intel device address failed (%ld)",
hdev->name, PTR_ERR(skb));
return PTR_ERR(skb);
}
if (skb->len != sizeof(*rp)) {
BT_ERR("%s Intel device address length mismatch", hdev->name);
kfree_skb(skb);
return -EIO;
}
rp = (struct hci_rp_read_bd_addr *)skb->data;
if (rp->status) {
BT_ERR("%s Intel device address result failed (%02x)",
hdev->name, rp->status);
kfree_skb(skb);
return -bt_to_errno(rp->status);
}
if (!bacmp(&rp->bdaddr, BDADDR_INTEL)) {
BT_ERR("%s found Intel default device address (%pMR)",
hdev->name, &rp->bdaddr);
set_bit(HCI_QUIRK_INVALID_BDADDR, &hdev->quirks);
}
kfree_skb(skb);
return 0;
}
static int btusb_setup_intel(struct hci_dev *hdev)
{
struct sk_buff *skb;
const struct firmware *fw;
const u8 *fw_ptr;
int disable_patch;
struct intel_version *ver;
const u8 mfg_enable[] = { 0x01, 0x00 };
const u8 mfg_disable[] = { 0x00, 0x00 };
const u8 mfg_reset_deactivate[] = { 0x00, 0x01 };
const u8 mfg_reset_activate[] = { 0x00, 0x02 };
BT_DBG("%s", hdev->name);
skb = __hci_cmd_sync(hdev, HCI_OP_RESET, 0, NULL, HCI_INIT_TIMEOUT);
if (IS_ERR(skb)) {
BT_ERR("%s sending initial HCI reset command failed (%ld)",
hdev->name, PTR_ERR(skb));
return PTR_ERR(skb);
}
kfree_skb(skb);
skb = __hci_cmd_sync(hdev, 0xfc05, 0, NULL, HCI_INIT_TIMEOUT);
if (IS_ERR(skb)) {
BT_ERR("%s reading Intel fw version command failed (%ld)",
hdev->name, PTR_ERR(skb));
return PTR_ERR(skb);
}
if (skb->len != sizeof(*ver)) {
BT_ERR("%s Intel version event length mismatch", hdev->name);
kfree_skb(skb);
return -EIO;
}
ver = (struct intel_version *)skb->data;
if (ver->status) {
BT_ERR("%s Intel fw version event failed (%02x)", hdev->name,
ver->status);
kfree_skb(skb);
return -bt_to_errno(ver->status);
}
BT_INFO("%s: read Intel version: %02x%02x%02x%02x%02x%02x%02x%02x%02x",
hdev->name, ver->hw_platform, ver->hw_variant,
ver->hw_revision, ver->fw_variant, ver->fw_revision,
ver->fw_build_num, ver->fw_build_ww, ver->fw_build_yy,
ver->fw_patch_num);
if (ver->fw_patch_num) {
BT_INFO("%s: Intel device is already patched. patch num: %02x",
hdev->name, ver->fw_patch_num);
kfree_skb(skb);
btusb_check_bdaddr_intel(hdev);
return 0;
}
fw = btusb_setup_intel_get_fw(hdev, ver);
if (!fw) {
kfree_skb(skb);
btusb_check_bdaddr_intel(hdev);
return 0;
}
fw_ptr = fw->data;
skb = __hci_cmd_sync(hdev, 0xfc11, 2, mfg_enable, HCI_INIT_TIMEOUT);
if (IS_ERR(skb)) {
BT_ERR("%s entering Intel manufacturer mode failed (%ld)",
hdev->name, PTR_ERR(skb));
release_firmware(fw);
return PTR_ERR(skb);
}
if (skb->data[0]) {
u8 evt_status = skb->data[0];
BT_ERR("%s enable Intel manufacturer mode event failed (%02x)",
hdev->name, evt_status);
kfree_skb(skb);
release_firmware(fw);
return -bt_to_errno(evt_status);
}
kfree_skb(skb);
disable_patch = 1;
while (fw->size > fw_ptr - fw->data) {
int ret;
ret = btusb_setup_intel_patching(hdev, fw, &fw_ptr,
&disable_patch);
if (ret < 0)
goto exit_mfg_deactivate;
}
release_firmware(fw);
if (disable_patch)
goto exit_mfg_disable;
skb = __hci_cmd_sync(hdev, 0xfc11, sizeof(mfg_reset_activate),
mfg_reset_activate, HCI_INIT_TIMEOUT);
if (IS_ERR(skb)) {
BT_ERR("%s exiting Intel manufacturer mode failed (%ld)",
hdev->name, PTR_ERR(skb));
return PTR_ERR(skb);
}
kfree_skb(skb);
BT_INFO("%s: Intel Bluetooth firmware patch completed and activated",
hdev->name);
btusb_check_bdaddr_intel(hdev);
return 0;
exit_mfg_disable:
skb = __hci_cmd_sync(hdev, 0xfc11, sizeof(mfg_disable), mfg_disable,
HCI_INIT_TIMEOUT);
if (IS_ERR(skb)) {
BT_ERR("%s exiting Intel manufacturer mode failed (%ld)",
hdev->name, PTR_ERR(skb));
return PTR_ERR(skb);
}
kfree_skb(skb);
BT_INFO("%s: Intel Bluetooth firmware patch completed", hdev->name);
btusb_check_bdaddr_intel(hdev);
return 0;
exit_mfg_deactivate:
release_firmware(fw);
skb = __hci_cmd_sync(hdev, 0xfc11, sizeof(mfg_reset_deactivate),
mfg_reset_deactivate, HCI_INIT_TIMEOUT);
if (IS_ERR(skb)) {
BT_ERR("%s exiting Intel manufacturer mode failed (%ld)",
hdev->name, PTR_ERR(skb));
return PTR_ERR(skb);
}
kfree_skb(skb);
BT_INFO("%s: Intel Bluetooth firmware patch completed and deactivated",
hdev->name);
btusb_check_bdaddr_intel(hdev);
return 0;
}
static int btusb_set_bdaddr_intel(struct hci_dev *hdev, const bdaddr_t *bdaddr)
{
struct sk_buff *skb;
long ret;
skb = __hci_cmd_sync(hdev, 0xfc31, 6, bdaddr, HCI_INIT_TIMEOUT);
if (IS_ERR(skb)) {
ret = PTR_ERR(skb);
BT_ERR("%s: changing Intel device address failed (%ld)",
hdev->name, ret);
return ret;
}
kfree_skb(skb);
return 0;
}
static int btusb_set_bdaddr_marvell(struct hci_dev *hdev,
const bdaddr_t *bdaddr)
{
struct sk_buff *skb;
u8 buf[8];
long ret;
buf[0] = 0xfe;
buf[1] = sizeof(bdaddr_t);
memcpy(buf + 2, bdaddr, sizeof(bdaddr_t));
skb = __hci_cmd_sync(hdev, 0xfc22, sizeof(buf), buf, HCI_INIT_TIMEOUT);
if (IS_ERR(skb)) {
ret = PTR_ERR(skb);
BT_ERR("%s: changing Marvell device address failed (%ld)",
hdev->name, ret);
return ret;
}
kfree_skb(skb);
return 0;
}
static int btusb_setup_bcm_patchram(struct hci_dev *hdev)
{
struct btusb_data *data = hci_get_drvdata(hdev);
struct usb_device *udev = data->udev;
char fw_name[64];
const struct firmware *fw;
const u8 *fw_ptr;
size_t fw_size;
const struct hci_command_hdr *cmd;
const u8 *cmd_param;
u16 opcode;
struct sk_buff *skb;
struct hci_rp_read_local_version *ver;
struct hci_rp_read_bd_addr *bda;
long ret;
snprintf(fw_name, sizeof(fw_name), "brcm/%s-%04x-%04x.hcd",
udev->product ? udev->product : "BCM",
le16_to_cpu(udev->descriptor.idVendor),
le16_to_cpu(udev->descriptor.idProduct));
ret = request_firmware(&fw, fw_name, &hdev->dev);
if (ret < 0) {
BT_INFO("%s: BCM: patch %s not found", hdev->name, fw_name);
return 0;
}
skb = __hci_cmd_sync(hdev, HCI_OP_RESET, 0, NULL, HCI_INIT_TIMEOUT);
if (IS_ERR(skb)) {
ret = PTR_ERR(skb);
BT_ERR("%s: HCI_OP_RESET failed (%ld)", hdev->name, ret);
goto done;
}
kfree_skb(skb);
skb = __hci_cmd_sync(hdev, HCI_OP_READ_LOCAL_VERSION, 0, NULL,
HCI_INIT_TIMEOUT);
if (IS_ERR(skb)) {
ret = PTR_ERR(skb);
BT_ERR("%s: HCI_OP_READ_LOCAL_VERSION failed (%ld)",
hdev->name, ret);
goto done;
}
if (skb->len != sizeof(*ver)) {
BT_ERR("%s: HCI_OP_READ_LOCAL_VERSION event length mismatch",
hdev->name);
kfree_skb(skb);
ret = -EIO;
goto done;
}
ver = (struct hci_rp_read_local_version *)skb->data;
BT_INFO("%s: BCM: patching hci_ver=%02x hci_rev=%04x lmp_ver=%02x "
"lmp_subver=%04x", hdev->name, ver->hci_ver, ver->hci_rev,
ver->lmp_ver, ver->lmp_subver);
kfree_skb(skb);
skb = __hci_cmd_sync(hdev, 0xfc2e, 0, NULL, HCI_INIT_TIMEOUT);
if (IS_ERR(skb)) {
ret = PTR_ERR(skb);
BT_ERR("%s: BCM: Download Minidrv command failed (%ld)",
hdev->name, ret);
goto reset_fw;
}
kfree_skb(skb);
msleep(50);
fw_ptr = fw->data;
fw_size = fw->size;
while (fw_size >= sizeof(*cmd)) {
cmd = (struct hci_command_hdr *)fw_ptr;
fw_ptr += sizeof(*cmd);
fw_size -= sizeof(*cmd);
if (fw_size < cmd->plen) {
BT_ERR("%s: BCM: patch %s is corrupted",
hdev->name, fw_name);
ret = -EINVAL;
goto reset_fw;
}
cmd_param = fw_ptr;
fw_ptr += cmd->plen;
fw_size -= cmd->plen;
opcode = le16_to_cpu(cmd->opcode);
skb = __hci_cmd_sync(hdev, opcode, cmd->plen, cmd_param,
HCI_INIT_TIMEOUT);
if (IS_ERR(skb)) {
ret = PTR_ERR(skb);
BT_ERR("%s: BCM: patch command %04x failed (%ld)",
hdev->name, opcode, ret);
goto reset_fw;
}
kfree_skb(skb);
}
msleep(250);
reset_fw:
skb = __hci_cmd_sync(hdev, HCI_OP_RESET, 0, NULL, HCI_INIT_TIMEOUT);
if (IS_ERR(skb)) {
ret = PTR_ERR(skb);
BT_ERR("%s: HCI_OP_RESET failed (%ld)", hdev->name, ret);
goto done;
}
kfree_skb(skb);
skb = __hci_cmd_sync(hdev, HCI_OP_READ_LOCAL_VERSION, 0, NULL,
HCI_INIT_TIMEOUT);
if (IS_ERR(skb)) {
ret = PTR_ERR(skb);
BT_ERR("%s: HCI_OP_READ_LOCAL_VERSION failed (%ld)",
hdev->name, ret);
goto done;
}
if (skb->len != sizeof(*ver)) {
BT_ERR("%s: HCI_OP_READ_LOCAL_VERSION event length mismatch",
hdev->name);
kfree_skb(skb);
ret = -EIO;
goto done;
}
ver = (struct hci_rp_read_local_version *)skb->data;
BT_INFO("%s: BCM: firmware hci_ver=%02x hci_rev=%04x lmp_ver=%02x "
"lmp_subver=%04x", hdev->name, ver->hci_ver, ver->hci_rev,
ver->lmp_ver, ver->lmp_subver);
kfree_skb(skb);
skb = __hci_cmd_sync(hdev, HCI_OP_READ_BD_ADDR, 0, NULL,
HCI_INIT_TIMEOUT);
if (IS_ERR(skb)) {
ret = PTR_ERR(skb);
BT_ERR("%s: HCI_OP_READ_BD_ADDR failed (%ld)",
hdev->name, ret);
goto done;
}
if (skb->len != sizeof(*bda)) {
BT_ERR("%s: HCI_OP_READ_BD_ADDR event length mismatch",
hdev->name);
kfree_skb(skb);
ret = -EIO;
goto done;
}
bda = (struct hci_rp_read_bd_addr *)skb->data;
if (bda->status) {
BT_ERR("%s: HCI_OP_READ_BD_ADDR error status (%02x)",
hdev->name, bda->status);
kfree_skb(skb);
ret = -bt_to_errno(bda->status);
goto done;
}
if (!bacmp(&bda->bdaddr, BDADDR_BCM20702A0)) {
BT_INFO("%s: BCM: using default device address (%pMR)",
hdev->name, &bda->bdaddr);
set_bit(HCI_QUIRK_INVALID_BDADDR, &hdev->quirks);
}
kfree_skb(skb);
done:
release_firmware(fw);
return ret;
}
static int btusb_set_bdaddr_bcm(struct hci_dev *hdev, const bdaddr_t *bdaddr)
{
struct sk_buff *skb;
long ret;
skb = __hci_cmd_sync(hdev, 0xfc01, 6, bdaddr, HCI_INIT_TIMEOUT);
if (IS_ERR(skb)) {
ret = PTR_ERR(skb);
BT_ERR("%s: BCM: Change address command failed (%ld)",
hdev->name, ret);
return ret;
}
kfree_skb(skb);
return 0;
}
static int btusb_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
struct usb_endpoint_descriptor *ep_desc;
struct btusb_data *data;
struct hci_dev *hdev;
int i, err;
BT_DBG("intf %p id %p", intf, id);
if (intf->cur_altsetting->desc.bInterfaceNumber != 0)
return -ENODEV;
if (!id->driver_info) {
const struct usb_device_id *match;
match = usb_match_id(intf, blacklist_table);
if (match)
id = match;
}
if (id->driver_info == BTUSB_IGNORE)
return -ENODEV;
if (id->driver_info & BTUSB_ATH3012) {
struct usb_device *udev = interface_to_usbdev(intf);
if (le16_to_cpu(udev->descriptor.bcdDevice) <= 0x0001)
return -ENODEV;
}
data = devm_kzalloc(&intf->dev, sizeof(*data), GFP_KERNEL);
if (!data)
return -ENOMEM;
for (i = 0; i < intf->cur_altsetting->desc.bNumEndpoints; i++) {
ep_desc = &intf->cur_altsetting->endpoint[i].desc;
if (!data->intr_ep && usb_endpoint_is_int_in(ep_desc)) {
data->intr_ep = ep_desc;
continue;
}
if (!data->bulk_tx_ep && usb_endpoint_is_bulk_out(ep_desc)) {
data->bulk_tx_ep = ep_desc;
continue;
}
if (!data->bulk_rx_ep && usb_endpoint_is_bulk_in(ep_desc)) {
data->bulk_rx_ep = ep_desc;
continue;
}
}
if (!data->intr_ep || !data->bulk_tx_ep || !data->bulk_rx_ep)
return -ENODEV;
data->cmdreq_type = USB_TYPE_CLASS;
data->udev = interface_to_usbdev(intf);
data->intf = intf;
INIT_WORK(&data->work, btusb_work);
INIT_WORK(&data->waker, btusb_waker);
init_usb_anchor(&data->deferred);
init_usb_anchor(&data->tx_anchor);
spin_lock_init(&data->txlock);
init_usb_anchor(&data->intr_anchor);
init_usb_anchor(&data->bulk_anchor);
init_usb_anchor(&data->isoc_anchor);
spin_lock_init(&data->rxlock);
hdev = hci_alloc_dev();
if (!hdev)
return -ENOMEM;
hdev->bus = HCI_USB;
hci_set_drvdata(hdev, data);
data->hdev = hdev;
SET_HCIDEV_DEV(hdev, &intf->dev);
hdev->open = btusb_open;
hdev->close = btusb_close;
hdev->flush = btusb_flush;
hdev->send = btusb_send_frame;
hdev->notify = btusb_notify;
if (id->driver_info & BTUSB_BCM92035)
hdev->setup = btusb_setup_bcm92035;
if (id->driver_info & BTUSB_BCM_PATCHRAM) {
hdev->setup = btusb_setup_bcm_patchram;
hdev->set_bdaddr = btusb_set_bdaddr_bcm;
}
if (id->driver_info & BTUSB_INTEL) {
hdev->setup = btusb_setup_intel;
hdev->set_bdaddr = btusb_set_bdaddr_intel;
}
if (id->driver_info & BTUSB_MARVELL)
hdev->set_bdaddr = btusb_set_bdaddr_marvell;
if (id->driver_info & BTUSB_INTEL_BOOT)
set_bit(HCI_QUIRK_RAW_DEVICE, &hdev->quirks);
data->isoc = usb_ifnum_to_if(data->udev, 1);
if (!reset)
set_bit(HCI_QUIRK_RESET_ON_CLOSE, &hdev->quirks);
if (force_scofix || id->driver_info & BTUSB_WRONG_SCO_MTU) {
if (!disable_scofix)
set_bit(HCI_QUIRK_FIXUP_BUFFER_SIZE, &hdev->quirks);
}
if (id->driver_info & BTUSB_BROKEN_ISOC)
data->isoc = NULL;
if (id->driver_info & BTUSB_DIGIANSWER) {
data->cmdreq_type = USB_TYPE_VENDOR;
set_bit(HCI_QUIRK_RESET_ON_CLOSE, &hdev->quirks);
}
if (id->driver_info & BTUSB_CSR) {
struct usb_device *udev = data->udev;
u16 bcdDevice = le16_to_cpu(udev->descriptor.bcdDevice);
if (bcdDevice < 0x117)
set_bit(HCI_QUIRK_RESET_ON_CLOSE, &hdev->quirks);
if (bcdDevice <= 0x100)
hdev->setup = btusb_setup_csr;
}
if (id->driver_info & BTUSB_SNIFFER) {
struct usb_device *udev = data->udev;
if (le16_to_cpu(udev->descriptor.bcdDevice) > 0x997)
set_bit(HCI_QUIRK_RAW_DEVICE, &hdev->quirks);
}
if (id->driver_info & BTUSB_INTEL_BOOT) {
err = usb_set_interface(data->udev, 0, 0);
if (err < 0) {
BT_ERR("failed to set interface 0, alt 0 %d", err);
hci_free_dev(hdev);
return err;
}
}
if (data->isoc) {
err = usb_driver_claim_interface(&btusb_driver,
data->isoc, data);
if (err < 0) {
hci_free_dev(hdev);
return err;
}
}
err = hci_register_dev(hdev);
if (err < 0) {
hci_free_dev(hdev);
return err;
}
usb_set_intfdata(intf, data);
return 0;
}
static void btusb_disconnect(struct usb_interface *intf)
{
struct btusb_data *data = usb_get_intfdata(intf);
struct hci_dev *hdev;
BT_DBG("intf %p", intf);
if (!data)
return;
hdev = data->hdev;
usb_set_intfdata(data->intf, NULL);
if (data->isoc)
usb_set_intfdata(data->isoc, NULL);
hci_unregister_dev(hdev);
if (intf == data->isoc)
usb_driver_release_interface(&btusb_driver, data->intf);
else if (data->isoc)
usb_driver_release_interface(&btusb_driver, data->isoc);
btusb_free_frags(data);
hci_free_dev(hdev);
}
static int btusb_suspend(struct usb_interface *intf, pm_message_t message)
{
struct btusb_data *data = usb_get_intfdata(intf);
BT_DBG("intf %p", intf);
if (data->suspend_count++)
return 0;
spin_lock_irq(&data->txlock);
if (!(PMSG_IS_AUTO(message) && data->tx_in_flight)) {
set_bit(BTUSB_SUSPENDING, &data->flags);
spin_unlock_irq(&data->txlock);
} else {
spin_unlock_irq(&data->txlock);
data->suspend_count--;
return -EBUSY;
}
cancel_work_sync(&data->work);
btusb_stop_traffic(data);
usb_kill_anchored_urbs(&data->tx_anchor);
return 0;
}
static void play_deferred(struct btusb_data *data)
{
struct urb *urb;
int err;
while ((urb = usb_get_from_anchor(&data->deferred))) {
err = usb_submit_urb(urb, GFP_ATOMIC);
if (err < 0)
break;
data->tx_in_flight++;
}
usb_scuttle_anchored_urbs(&data->deferred);
}
static int btusb_resume(struct usb_interface *intf)
{
struct btusb_data *data = usb_get_intfdata(intf);
struct hci_dev *hdev = data->hdev;
int err = 0;
BT_DBG("intf %p", intf);
if (--data->suspend_count)
return 0;
if (!test_bit(HCI_RUNNING, &hdev->flags))
goto done;
if (test_bit(BTUSB_INTR_RUNNING, &data->flags)) {
err = btusb_submit_intr_urb(hdev, GFP_NOIO);
if (err < 0) {
clear_bit(BTUSB_INTR_RUNNING, &data->flags);
goto failed;
}
}
if (test_bit(BTUSB_BULK_RUNNING, &data->flags)) {
err = btusb_submit_bulk_urb(hdev, GFP_NOIO);
if (err < 0) {
clear_bit(BTUSB_BULK_RUNNING, &data->flags);
goto failed;
}
btusb_submit_bulk_urb(hdev, GFP_NOIO);
}
if (test_bit(BTUSB_ISOC_RUNNING, &data->flags)) {
if (btusb_submit_isoc_urb(hdev, GFP_NOIO) < 0)
clear_bit(BTUSB_ISOC_RUNNING, &data->flags);
else
btusb_submit_isoc_urb(hdev, GFP_NOIO);
}
spin_lock_irq(&data->txlock);
play_deferred(data);
clear_bit(BTUSB_SUSPENDING, &data->flags);
spin_unlock_irq(&data->txlock);
schedule_work(&data->work);
return 0;
failed:
usb_scuttle_anchored_urbs(&data->deferred);
done:
spin_lock_irq(&data->txlock);
clear_bit(BTUSB_SUSPENDING, &data->flags);
spin_unlock_irq(&data->txlock);
return err;
}
