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
data->recv_event(data->hdev, skb);
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
if (data->recv_bulk(data, urb->transfer_buffer,
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
if (data->setup_on_usb) {
err = data->setup_on_usb(hdev);
if (err < 0)
return err;
}
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
dr->bRequest = data->cmdreq;
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
static struct sk_buff *btusb_read_local_version(struct hci_dev *hdev)
{
struct sk_buff *skb;
skb = __hci_cmd_sync(hdev, HCI_OP_READ_LOCAL_VERSION, 0, NULL,
HCI_INIT_TIMEOUT);
if (IS_ERR(skb)) {
BT_ERR("%s: HCI_OP_READ_LOCAL_VERSION failed (%ld)",
hdev->name, PTR_ERR(skb));
return skb;
}
if (skb->len != sizeof(struct hci_rp_read_local_version)) {
BT_ERR("%s: HCI_OP_READ_LOCAL_VERSION event length mismatch",
hdev->name);
kfree_skb(skb);
return ERR_PTR(-EIO);
}
return skb;
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
skb = btusb_read_local_version(hdev);
if (IS_ERR(skb))
return -PTR_ERR(skb);
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
static int rtl_read_rom_version(struct hci_dev *hdev, u8 *version)
{
struct rtl_rom_version_evt *rom_version;
struct sk_buff *skb;
int ret;
skb = __hci_cmd_sync(hdev, 0xfc6d, 0, NULL, HCI_INIT_TIMEOUT);
if (IS_ERR(skb)) {
BT_ERR("%s: Read ROM version failed (%ld)",
hdev->name, PTR_ERR(skb));
return PTR_ERR(skb);
}
if (skb->len != sizeof(*rom_version)) {
BT_ERR("%s: RTL version event length mismatch", hdev->name);
kfree_skb(skb);
return -EIO;
}
rom_version = (struct rtl_rom_version_evt *)skb->data;
BT_INFO("%s: rom_version status=%x version=%x",
hdev->name, rom_version->status, rom_version->version);
ret = rom_version->status;
if (ret == 0)
*version = rom_version->version;
kfree_skb(skb);
return ret;
}
static int rtl8723b_parse_firmware(struct hci_dev *hdev, u16 lmp_subver,
const struct firmware *fw,
unsigned char **_buf)
{
const u8 extension_sig[] = { 0x51, 0x04, 0xfd, 0x77 };
struct rtl_epatch_header *epatch_info;
unsigned char *buf;
int i, ret, len;
size_t min_size;
u8 opcode, length, data, rom_version = 0;
int project_id = -1;
const unsigned char *fwptr, *chip_id_base;
const unsigned char *patch_length_base, *patch_offset_base;
u32 patch_offset = 0;
u16 patch_length, num_patches;
const u16 project_id_to_lmp_subver[] = {
RTL_ROM_LMP_8723A,
RTL_ROM_LMP_8723B,
RTL_ROM_LMP_8821A,
RTL_ROM_LMP_8761A
};
ret = rtl_read_rom_version(hdev, &rom_version);
if (ret)
return -bt_to_errno(ret);
min_size = sizeof(struct rtl_epatch_header) + sizeof(extension_sig) + 3;
if (fw->size < min_size)
return -EINVAL;
fwptr = fw->data + fw->size - sizeof(extension_sig);
if (memcmp(fwptr, extension_sig, sizeof(extension_sig)) != 0) {
BT_ERR("%s: extension section signature mismatch", hdev->name);
return -EINVAL;
}
while (fwptr >= fw->data + (sizeof(struct rtl_epatch_header) + 3)) {
opcode = *--fwptr;
length = *--fwptr;
data = *--fwptr;
BT_DBG("check op=%x len=%x data=%x", opcode, length, data);
if (opcode == 0xff)
break;
if (length == 0) {
BT_ERR("%s: found instruction with length 0",
hdev->name);
return -EINVAL;
}
if (opcode == 0 && length == 1) {
project_id = data;
break;
}
fwptr -= length;
}
if (project_id < 0) {
BT_ERR("%s: failed to find version instruction", hdev->name);
return -EINVAL;
}
if (project_id >= ARRAY_SIZE(project_id_to_lmp_subver)) {
BT_ERR("%s: unknown project id %d", hdev->name, project_id);
return -EINVAL;
}
if (lmp_subver != project_id_to_lmp_subver[project_id]) {
BT_ERR("%s: firmware is for %x but this is a %x", hdev->name,
project_id_to_lmp_subver[project_id], lmp_subver);
return -EINVAL;
}
epatch_info = (struct rtl_epatch_header *)fw->data;
if (memcmp(epatch_info->signature, RTL_EPATCH_SIGNATURE, 8) != 0) {
BT_ERR("%s: bad EPATCH signature", hdev->name);
return -EINVAL;
}
num_patches = le16_to_cpu(epatch_info->num_patches);
BT_DBG("fw_version=%x, num_patches=%d",
le32_to_cpu(epatch_info->fw_version), num_patches);
min_size += 8 * num_patches;
if (fw->size < min_size)
return -EINVAL;
chip_id_base = fw->data + sizeof(struct rtl_epatch_header);
patch_length_base = chip_id_base + (sizeof(u16) * num_patches);
patch_offset_base = patch_length_base + (sizeof(u16) * num_patches);
for (i = 0; i < num_patches; i++) {
u16 chip_id = get_unaligned_le16(chip_id_base +
(i * sizeof(u16)));
if (chip_id == rom_version + 1) {
patch_length = get_unaligned_le16(patch_length_base +
(i * sizeof(u16)));
patch_offset = get_unaligned_le32(patch_offset_base +
(i * sizeof(u32)));
break;
}
}
if (!patch_offset) {
BT_ERR("%s: didn't find patch for chip id %d",
hdev->name, rom_version);
return -EINVAL;
}
BT_DBG("length=%x offset=%x index %d", patch_length, patch_offset, i);
min_size = patch_offset + patch_length;
if (fw->size < min_size)
return -EINVAL;
len = patch_length;
buf = kmemdup(fw->data + patch_offset, patch_length, GFP_KERNEL);
if (!buf)
return -ENOMEM;
memcpy(buf + patch_length - 4, &epatch_info->fw_version, 4);
*_buf = buf;
return len;
}
static int rtl_download_firmware(struct hci_dev *hdev,
const unsigned char *data, int fw_len)
{
struct rtl_download_cmd *dl_cmd;
int frag_num = fw_len / RTL_FRAG_LEN + 1;
int frag_len = RTL_FRAG_LEN;
int ret = 0;
int i;
dl_cmd = kmalloc(sizeof(struct rtl_download_cmd), GFP_KERNEL);
if (!dl_cmd)
return -ENOMEM;
for (i = 0; i < frag_num; i++) {
struct rtl_download_response *dl_resp;
struct sk_buff *skb;
BT_DBG("download fw (%d/%d)", i, frag_num);
dl_cmd->index = i;
if (i == (frag_num - 1)) {
dl_cmd->index |= 0x80;
frag_len = fw_len % RTL_FRAG_LEN;
}
memcpy(dl_cmd->data, data, frag_len);
skb = __hci_cmd_sync(hdev, 0xfc20, frag_len + 1, dl_cmd,
HCI_INIT_TIMEOUT);
if (IS_ERR(skb)) {
BT_ERR("%s: download fw command failed (%ld)",
hdev->name, PTR_ERR(skb));
ret = -PTR_ERR(skb);
goto out;
}
if (skb->len != sizeof(*dl_resp)) {
BT_ERR("%s: download fw event length mismatch",
hdev->name);
kfree_skb(skb);
ret = -EIO;
goto out;
}
dl_resp = (struct rtl_download_response *)skb->data;
if (dl_resp->status != 0) {
kfree_skb(skb);
ret = bt_to_errno(dl_resp->status);
goto out;
}
kfree_skb(skb);
data += RTL_FRAG_LEN;
}
out:
kfree(dl_cmd);
return ret;
}
static int btusb_setup_rtl8723a(struct hci_dev *hdev)
{
struct btusb_data *data = dev_get_drvdata(&hdev->dev);
struct usb_device *udev = interface_to_usbdev(data->intf);
const struct firmware *fw;
int ret;
BT_INFO("%s: rtl: loading rtl_bt/rtl8723a_fw.bin", hdev->name);
ret = request_firmware(&fw, "rtl_bt/rtl8723a_fw.bin", &udev->dev);
if (ret < 0) {
BT_ERR("%s: Failed to load rtl_bt/rtl8723a_fw.bin", hdev->name);
return ret;
}
if (fw->size < 8) {
ret = -EINVAL;
goto out;
}
if (!memcmp(fw->data, RTL_EPATCH_SIGNATURE, 8)) {
BT_ERR("%s: unexpected EPATCH signature!", hdev->name);
ret = -EINVAL;
goto out;
}
ret = rtl_download_firmware(hdev, fw->data, fw->size);
out:
release_firmware(fw);
return ret;
}
static int btusb_setup_rtl8723b(struct hci_dev *hdev, u16 lmp_subver,
const char *fw_name)
{
struct btusb_data *data = dev_get_drvdata(&hdev->dev);
struct usb_device *udev = interface_to_usbdev(data->intf);
unsigned char *fw_data = NULL;
const struct firmware *fw;
int ret;
BT_INFO("%s: rtl: loading %s", hdev->name, fw_name);
ret = request_firmware(&fw, fw_name, &udev->dev);
if (ret < 0) {
BT_ERR("%s: Failed to load %s", hdev->name, fw_name);
return ret;
}
ret = rtl8723b_parse_firmware(hdev, lmp_subver, fw, &fw_data);
if (ret < 0)
goto out;
ret = rtl_download_firmware(hdev, fw_data, ret);
kfree(fw_data);
if (ret < 0)
goto out;
out:
release_firmware(fw);
return ret;
}
static int btusb_setup_realtek(struct hci_dev *hdev)
{
struct sk_buff *skb;
struct hci_rp_read_local_version *resp;
u16 lmp_subver;
skb = btusb_read_local_version(hdev);
if (IS_ERR(skb))
return -PTR_ERR(skb);
resp = (struct hci_rp_read_local_version *)skb->data;
BT_INFO("%s: rtl: examining hci_ver=%02x hci_rev=%04x lmp_ver=%02x "
"lmp_subver=%04x", hdev->name, resp->hci_ver, resp->hci_rev,
resp->lmp_ver, resp->lmp_subver);
lmp_subver = le16_to_cpu(resp->lmp_subver);
kfree_skb(skb);
switch (lmp_subver) {
case RTL_ROM_LMP_8723A:
case RTL_ROM_LMP_3499:
return btusb_setup_rtl8723a(hdev);
case RTL_ROM_LMP_8723B:
return btusb_setup_rtl8723b(hdev, lmp_subver,
"rtl_bt/rtl8723b_fw.bin");
case RTL_ROM_LMP_8821A:
return btusb_setup_rtl8723b(hdev, lmp_subver,
"rtl_bt/rtl8821a_fw.bin");
case RTL_ROM_LMP_8761A:
return btusb_setup_rtl8723b(hdev, lmp_subver,
"rtl_bt/rtl8761a_fw.bin");
default:
BT_INFO("rtl: assuming no firmware upload needed.");
return 0;
}
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
btintel_check_bdaddr(hdev);
return 0;
}
fw = btusb_setup_intel_get_fw(hdev, ver);
if (!fw) {
kfree_skb(skb);
btintel_check_bdaddr(hdev);
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
btintel_check_bdaddr(hdev);
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
btintel_check_bdaddr(hdev);
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
btintel_check_bdaddr(hdev);
return 0;
}
static int inject_cmd_complete(struct hci_dev *hdev, __u16 opcode)
{
struct sk_buff *skb;
struct hci_event_hdr *hdr;
struct hci_ev_cmd_complete *evt;
skb = bt_skb_alloc(sizeof(*hdr) + sizeof(*evt) + 1, GFP_ATOMIC);
if (!skb)
return -ENOMEM;
hdr = (struct hci_event_hdr *)skb_put(skb, sizeof(*hdr));
hdr->evt = HCI_EV_CMD_COMPLETE;
hdr->plen = sizeof(*evt) + 1;
evt = (struct hci_ev_cmd_complete *)skb_put(skb, sizeof(*evt));
evt->ncmd = 0x01;
evt->opcode = cpu_to_le16(opcode);
*skb_put(skb, 1) = 0x00;
bt_cb(skb)->pkt_type = HCI_EVENT_PKT;
return hci_recv_frame(hdev, skb);
}
static int btusb_recv_bulk_intel(struct btusb_data *data, void *buffer,
int count)
{
if (test_bit(BTUSB_BOOTLOADER, &data->flags))
return btusb_recv_intr(data, buffer, count);
return btusb_recv_bulk(data, buffer, count);
}
static void btusb_intel_bootup(struct btusb_data *data, const void *ptr,
unsigned int len)
{
const struct intel_bootup *evt = ptr;
if (len != sizeof(*evt))
return;
if (test_and_clear_bit(BTUSB_BOOTING, &data->flags)) {
smp_mb__after_atomic();
wake_up_bit(&data->flags, BTUSB_BOOTING);
}
}
static void btusb_intel_secure_send_result(struct btusb_data *data,
const void *ptr, unsigned int len)
{
const struct intel_secure_send_result *evt = ptr;
if (len != sizeof(*evt))
return;
if (evt->result)
set_bit(BTUSB_FIRMWARE_FAILED, &data->flags);
if (test_and_clear_bit(BTUSB_DOWNLOADING, &data->flags) &&
test_bit(BTUSB_FIRMWARE_LOADED, &data->flags)) {
smp_mb__after_atomic();
wake_up_bit(&data->flags, BTUSB_DOWNLOADING);
}
}
static int btusb_recv_event_intel(struct hci_dev *hdev, struct sk_buff *skb)
{
struct btusb_data *data = hci_get_drvdata(hdev);
if (test_bit(BTUSB_BOOTLOADER, &data->flags)) {
struct hci_event_hdr *hdr = (void *)skb->data;
if (skb->len > HCI_EVENT_HDR_SIZE && hdr->evt == 0xff &&
hdr->plen > 0) {
const void *ptr = skb->data + HCI_EVENT_HDR_SIZE + 1;
unsigned int len = skb->len - HCI_EVENT_HDR_SIZE - 1;
switch (skb->data[2]) {
case 0x02:
btusb_intel_bootup(data, ptr, len);
break;
case 0x06:
btusb_intel_secure_send_result(data, ptr, len);
break;
}
}
}
return hci_recv_frame(hdev, skb);
}
static int btusb_send_frame_intel(struct hci_dev *hdev, struct sk_buff *skb)
{
struct btusb_data *data = hci_get_drvdata(hdev);
struct urb *urb;
BT_DBG("%s", hdev->name);
if (!test_bit(HCI_RUNNING, &hdev->flags))
return -EBUSY;
switch (bt_cb(skb)->pkt_type) {
case HCI_COMMAND_PKT:
if (test_bit(BTUSB_BOOTLOADER, &data->flags)) {
struct hci_command_hdr *cmd = (void *)skb->data;
__u16 opcode = le16_to_cpu(cmd->opcode);
if (opcode == 0xfc09)
urb = alloc_bulk_urb(hdev, skb);
else
urb = alloc_ctrl_urb(hdev, skb);
if (opcode == 0xfc01)
inject_cmd_complete(hdev, opcode);
} else {
urb = alloc_ctrl_urb(hdev, skb);
}
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
static int btusb_intel_secure_send(struct hci_dev *hdev, u8 fragment_type,
u32 plen, const void *param)
{
while (plen > 0) {
struct sk_buff *skb;
u8 cmd_param[253], fragment_len = (plen > 252) ? 252 : plen;
cmd_param[0] = fragment_type;
memcpy(cmd_param + 1, param, fragment_len);
skb = __hci_cmd_sync(hdev, 0xfc09, fragment_len + 1,
cmd_param, HCI_INIT_TIMEOUT);
if (IS_ERR(skb))
return PTR_ERR(skb);
kfree_skb(skb);
plen -= fragment_len;
param += fragment_len;
}
return 0;
}
static void btusb_intel_version_info(struct hci_dev *hdev,
struct intel_version *ver)
{
const char *variant;
switch (ver->fw_variant) {
case 0x06:
variant = "Bootloader";
break;
case 0x23:
variant = "Firmware";
break;
default:
return;
}
BT_INFO("%s: %s revision %u.%u build %u week %u %u", hdev->name,
variant, ver->fw_revision >> 4, ver->fw_revision & 0x0f,
ver->fw_build_num, ver->fw_build_ww, 2000 + ver->fw_build_yy);
}
static int btusb_setup_intel_new(struct hci_dev *hdev)
{
static const u8 reset_param[] = { 0x00, 0x01, 0x00, 0x01,
0x00, 0x08, 0x04, 0x00 };
struct btusb_data *data = hci_get_drvdata(hdev);
struct sk_buff *skb;
struct intel_version *ver;
struct intel_boot_params *params;
const struct firmware *fw;
const u8 *fw_ptr;
char fwname[64];
ktime_t calltime, delta, rettime;
unsigned long long duration;
int err;
BT_DBG("%s", hdev->name);
calltime = ktime_get();
skb = __hci_cmd_sync(hdev, 0xfc05, 0, NULL, HCI_INIT_TIMEOUT);
if (IS_ERR(skb)) {
BT_ERR("%s: Reading Intel version information failed (%ld)",
hdev->name, PTR_ERR(skb));
return PTR_ERR(skb);
}
if (skb->len != sizeof(*ver)) {
BT_ERR("%s: Intel version event size mismatch", hdev->name);
kfree_skb(skb);
return -EILSEQ;
}
ver = (struct intel_version *)skb->data;
if (ver->status) {
BT_ERR("%s: Intel version command failure (%02x)",
hdev->name, ver->status);
err = -bt_to_errno(ver->status);
kfree_skb(skb);
return err;
}
if (ver->hw_platform != 0x37) {
BT_ERR("%s: Unsupported Intel hardware platform (%u)",
hdev->name, ver->hw_platform);
kfree_skb(skb);
return -EINVAL;
}
if (ver->hw_variant != 0x0b) {
BT_ERR("%s: Unsupported Intel hardware variant (%u)",
hdev->name, ver->hw_variant);
kfree_skb(skb);
return -EINVAL;
}
btusb_intel_version_info(hdev, ver);
if (ver->fw_variant == 0x23) {
kfree_skb(skb);
clear_bit(BTUSB_BOOTLOADER, &data->flags);
btintel_check_bdaddr(hdev);
return 0;
}
if (ver->fw_variant != 0x06) {
BT_ERR("%s: Unsupported Intel firmware variant (%u)",
hdev->name, ver->fw_variant);
kfree_skb(skb);
return -ENODEV;
}
kfree_skb(skb);
skb = __hci_cmd_sync(hdev, 0xfc0d, 0, NULL, HCI_INIT_TIMEOUT);
if (IS_ERR(skb)) {
BT_ERR("%s: Reading Intel boot parameters failed (%ld)",
hdev->name, PTR_ERR(skb));
return PTR_ERR(skb);
}
if (skb->len != sizeof(*params)) {
BT_ERR("%s: Intel boot parameters size mismatch", hdev->name);
kfree_skb(skb);
return -EILSEQ;
}
params = (struct intel_boot_params *)skb->data;
if (params->status) {
BT_ERR("%s: Intel boot parameters command failure (%02x)",
hdev->name, params->status);
err = -bt_to_errno(params->status);
kfree_skb(skb);
return err;
}
BT_INFO("%s: Device revision is %u", hdev->name,
le16_to_cpu(params->dev_revid));
BT_INFO("%s: Secure boot is %s", hdev->name,
params->secure_boot ? "enabled" : "disabled");
BT_INFO("%s: Minimum firmware build %u week %u %u", hdev->name,
params->min_fw_build_nn, params->min_fw_build_cw,
2000 + params->min_fw_build_yy);
if (params->limited_cce != 0x00) {
BT_ERR("%s: Unsupported Intel firmware loading method (%u)",
hdev->name, params->limited_cce);
kfree_skb(skb);
return -EINVAL;
}
if (!bacmp(&params->otp_bdaddr, BDADDR_ANY)) {
BT_INFO("%s: No device address configured", hdev->name);
set_bit(HCI_QUIRK_INVALID_BDADDR, &hdev->quirks);
}
snprintf(fwname, sizeof(fwname), "intel/ibt-11-%u.sfi",
le16_to_cpu(params->dev_revid));
err = request_firmware(&fw, fwname, &hdev->dev);
if (err < 0) {
BT_ERR("%s: Failed to load Intel firmware file (%d)",
hdev->name, err);
kfree_skb(skb);
return err;
}
BT_INFO("%s: Found device firmware: %s", hdev->name, fwname);
kfree_skb(skb);
if (fw->size < 644) {
BT_ERR("%s: Invalid size of firmware file (%zu)",
hdev->name, fw->size);
err = -EBADF;
goto done;
}
set_bit(BTUSB_DOWNLOADING, &data->flags);
err = btusb_intel_secure_send(hdev, 0x00, 128, fw->data);
if (err < 0) {
BT_ERR("%s: Failed to send firmware header (%d)",
hdev->name, err);
goto done;
}
err = btusb_intel_secure_send(hdev, 0x03, 256, fw->data + 128);
if (err < 0) {
BT_ERR("%s: Failed to send firmware public key (%d)",
hdev->name, err);
goto done;
}
err = btusb_intel_secure_send(hdev, 0x02, 256, fw->data + 388);
if (err < 0) {
BT_ERR("%s: Failed to send firmware signature (%d)",
hdev->name, err);
goto done;
}
fw_ptr = fw->data + 644;
while (fw_ptr - fw->data < fw->size) {
struct hci_command_hdr *cmd = (void *)fw_ptr;
u8 cmd_len;
cmd_len = sizeof(*cmd) + cmd->plen;
err = btusb_intel_secure_send(hdev, 0x01, cmd_len, fw_ptr);
if (err < 0) {
BT_ERR("%s: Failed to send firmware data (%d)",
hdev->name, err);
goto done;
}
fw_ptr += cmd_len;
}
set_bit(BTUSB_FIRMWARE_LOADED, &data->flags);
BT_INFO("%s: Waiting for firmware download to complete", hdev->name);
err = wait_on_bit_timeout(&data->flags, BTUSB_DOWNLOADING,
TASK_INTERRUPTIBLE,
msecs_to_jiffies(5000));
if (err == 1) {
BT_ERR("%s: Firmware loading interrupted", hdev->name);
err = -EINTR;
goto done;
}
if (err) {
BT_ERR("%s: Firmware loading timeout", hdev->name);
err = -ETIMEDOUT;
goto done;
}
if (test_bit(BTUSB_FIRMWARE_FAILED, &data->flags)) {
BT_ERR("%s: Firmware loading failed", hdev->name);
err = -ENOEXEC;
goto done;
}
rettime = ktime_get();
delta = ktime_sub(rettime, calltime);
duration = (unsigned long long) ktime_to_ns(delta) >> 10;
BT_INFO("%s: Firmware loaded in %llu usecs", hdev->name, duration);
done:
release_firmware(fw);
if (err < 0)
return err;
calltime = ktime_get();
set_bit(BTUSB_BOOTING, &data->flags);
skb = __hci_cmd_sync(hdev, 0xfc01, sizeof(reset_param), reset_param,
HCI_INIT_TIMEOUT);
if (IS_ERR(skb))
return PTR_ERR(skb);
kfree_skb(skb);
BT_INFO("%s: Waiting for device to boot", hdev->name);
err = wait_on_bit_timeout(&data->flags, BTUSB_BOOTING,
TASK_INTERRUPTIBLE,
msecs_to_jiffies(1000));
if (err == 1) {
BT_ERR("%s: Device boot interrupted", hdev->name);
return -EINTR;
}
if (err) {
BT_ERR("%s: Device boot timeout", hdev->name);
return -ETIMEDOUT;
}
rettime = ktime_get();
delta = ktime_sub(rettime, calltime);
duration = (unsigned long long) ktime_to_ns(delta) >> 10;
BT_INFO("%s: Device booted in %llu usecs", hdev->name, duration);
clear_bit(BTUSB_BOOTLOADER, &data->flags);
return 0;
}
static void btusb_hw_error_intel(struct hci_dev *hdev, u8 code)
{
struct sk_buff *skb;
u8 type = 0x00;
BT_ERR("%s: Hardware error 0x%2.2x", hdev->name, code);
skb = __hci_cmd_sync(hdev, HCI_OP_RESET, 0, NULL, HCI_INIT_TIMEOUT);
if (IS_ERR(skb)) {
BT_ERR("%s: Reset after hardware error failed (%ld)",
hdev->name, PTR_ERR(skb));
return;
}
kfree_skb(skb);
skb = __hci_cmd_sync(hdev, 0xfc22, 1, &type, HCI_INIT_TIMEOUT);
if (IS_ERR(skb)) {
BT_ERR("%s: Retrieving Intel exception info failed (%ld)",
hdev->name, PTR_ERR(skb));
return;
}
if (skb->len != 13) {
BT_ERR("%s: Exception info size mismatch", hdev->name);
kfree_skb(skb);
return;
}
if (skb->data[0] != 0x00) {
BT_ERR("%s: Exception info command failure (%02x)",
hdev->name, skb->data[0]);
kfree_skb(skb);
return;
}
BT_ERR("%s: Exception info %s", hdev->name, (char *)(skb->data + 1));
kfree_skb(skb);
}
static int btusb_shutdown_intel(struct hci_dev *hdev)
{
struct sk_buff *skb;
long ret;
skb = __hci_cmd_sync(hdev, 0xfc3f, 0, NULL, HCI_INIT_TIMEOUT);
if (IS_ERR(skb)) {
ret = PTR_ERR(skb);
BT_ERR("%s: turning off Intel device LED failed (%ld)",
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
static int btusb_set_bdaddr_ath3012(struct hci_dev *hdev,
const bdaddr_t *bdaddr)
{
struct sk_buff *skb;
u8 buf[10];
long ret;
buf[0] = 0x01;
buf[1] = 0x01;
buf[2] = 0x00;
buf[3] = sizeof(bdaddr_t);
memcpy(buf + 4, bdaddr, sizeof(bdaddr_t));
skb = __hci_cmd_sync(hdev, 0xfc0b, sizeof(buf), buf, HCI_INIT_TIMEOUT);
if (IS_ERR(skb)) {
ret = PTR_ERR(skb);
BT_ERR("%s: Change address command failed (%ld)",
hdev->name, ret);
return ret;
}
kfree_skb(skb);
return 0;
}
static int btusb_qca_send_vendor_req(struct hci_dev *hdev, u8 request,
void *data, u16 size)
{
struct btusb_data *btdata = hci_get_drvdata(hdev);
struct usb_device *udev = btdata->udev;
int pipe, err;
u8 *buf;
buf = kmalloc(size, GFP_KERNEL);
if (!buf)
return -ENOMEM;
pipe = usb_rcvctrlpipe(udev, 0);
err = usb_control_msg(udev, pipe, request, USB_TYPE_VENDOR | USB_DIR_IN,
0, 0, buf, size, USB_CTRL_SET_TIMEOUT);
if (err < 0) {
BT_ERR("%s: Failed to access otp area (%d)", hdev->name, err);
goto done;
}
memcpy(data, buf, size);
done:
kfree(buf);
return err;
}
static int btusb_setup_qca_download_fw(struct hci_dev *hdev,
const struct firmware *firmware,
size_t hdr_size)
{
struct btusb_data *btdata = hci_get_drvdata(hdev);
struct usb_device *udev = btdata->udev;
size_t count, size, sent = 0;
int pipe, len, err;
u8 *buf;
buf = kmalloc(QCA_DFU_PACKET_LEN, GFP_KERNEL);
if (!buf)
return -ENOMEM;
count = firmware->size;
size = min_t(size_t, count, hdr_size);
memcpy(buf, firmware->data, size);
pipe = usb_sndctrlpipe(udev, 0);
err = usb_control_msg(udev, pipe, QCA_DFU_DOWNLOAD, USB_TYPE_VENDOR,
0, 0, buf, size, USB_CTRL_SET_TIMEOUT);
if (err < 0) {
BT_ERR("%s: Failed to send headers (%d)", hdev->name, err);
goto done;
}
sent += size;
count -= size;
while (count) {
size = min_t(size_t, count, QCA_DFU_PACKET_LEN);
memcpy(buf, firmware->data + sent, size);
pipe = usb_sndbulkpipe(udev, 0x02);
err = usb_bulk_msg(udev, pipe, buf, size, &len,
QCA_DFU_TIMEOUT);
if (err < 0) {
BT_ERR("%s: Failed to send body at %zd of %zd (%d)",
hdev->name, sent, firmware->size, err);
break;
}
if (size != len) {
BT_ERR("%s: Failed to get bulk buffer", hdev->name);
err = -EILSEQ;
break;
}
sent += size;
count -= size;
}
done:
kfree(buf);
return err;
}
static int btusb_setup_qca_load_rampatch(struct hci_dev *hdev,
struct qca_version *ver,
const struct qca_device_info *info)
{
struct qca_rampatch_version *rver;
const struct firmware *fw;
u32 ver_rom, ver_patch;
u16 rver_rom, rver_patch;
char fwname[64];
int err;
ver_rom = le32_to_cpu(ver->rom_version);
ver_patch = le32_to_cpu(ver->patch_version);
snprintf(fwname, sizeof(fwname), "qca/rampatch_usb_%08x.bin", ver_rom);
err = request_firmware(&fw, fwname, &hdev->dev);
if (err) {
BT_ERR("%s: failed to request rampatch file: %s (%d)",
hdev->name, fwname, err);
return err;
}
BT_INFO("%s: using rampatch file: %s", hdev->name, fwname);
rver = (struct qca_rampatch_version *)(fw->data + info->ver_offset);
rver_rom = le16_to_cpu(rver->rom_version);
rver_patch = le16_to_cpu(rver->patch_version);
BT_INFO("%s: QCA: patch rome 0x%x build 0x%x, firmware rome 0x%x "
"build 0x%x", hdev->name, rver_rom, rver_patch, ver_rom,
ver_patch);
if (rver_rom != ver_rom || rver_patch <= ver_patch) {
BT_ERR("%s: rampatch file version did not match with firmware",
hdev->name);
err = -EINVAL;
goto done;
}
err = btusb_setup_qca_download_fw(hdev, fw, info->rampatch_hdr);
done:
release_firmware(fw);
return err;
}
static int btusb_setup_qca_load_nvm(struct hci_dev *hdev,
struct qca_version *ver,
const struct qca_device_info *info)
{
const struct firmware *fw;
char fwname[64];
int err;
snprintf(fwname, sizeof(fwname), "qca/nvm_usb_%08x.bin",
le32_to_cpu(ver->rom_version));
err = request_firmware(&fw, fwname, &hdev->dev);
if (err) {
BT_ERR("%s: failed to request NVM file: %s (%d)",
hdev->name, fwname, err);
return err;
}
BT_INFO("%s: using NVM file: %s", hdev->name, fwname);
err = btusb_setup_qca_download_fw(hdev, fw, info->nvm_hdr);
release_firmware(fw);
return err;
}
static int btusb_setup_qca(struct hci_dev *hdev)
{
const struct qca_device_info *info = NULL;
struct qca_version ver;
u32 ver_rom;
u8 status;
int i, err;
err = btusb_qca_send_vendor_req(hdev, QCA_GET_TARGET_VERSION, &ver,
sizeof(ver));
if (err < 0)
return err;
ver_rom = le32_to_cpu(ver.rom_version);
for (i = 0; i < ARRAY_SIZE(qca_devices_table); i++) {
if (ver_rom == qca_devices_table[i].rom_version)
info = &qca_devices_table[i];
}
if (!info) {
BT_ERR("%s: don't support firmware rome 0x%x", hdev->name,
ver_rom);
return -ENODEV;
}
err = btusb_qca_send_vendor_req(hdev, QCA_CHECK_STATUS, &status,
sizeof(status));
if (err < 0)
return err;
if (!(status & QCA_PATCH_UPDATED)) {
err = btusb_setup_qca_load_rampatch(hdev, &ver, info);
if (err < 0)
return err;
}
if (!(status & QCA_SYSCFG_UPDATED)) {
err = btusb_setup_qca_load_nvm(hdev, &ver, info);
if (err < 0)
return err;
}
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
if (id->driver_info & BTUSB_AMP) {
data->cmdreq_type = USB_TYPE_CLASS | 0x01;
data->cmdreq = 0x2b;
} else {
data->cmdreq_type = USB_TYPE_CLASS;
data->cmdreq = 0x00;
}
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
if (id->driver_info & BTUSB_INTEL_NEW) {
data->recv_event = btusb_recv_event_intel;
data->recv_bulk = btusb_recv_bulk_intel;
set_bit(BTUSB_BOOTLOADER, &data->flags);
} else {
data->recv_event = hci_recv_frame;
data->recv_bulk = btusb_recv_bulk;
}
hdev = hci_alloc_dev();
if (!hdev)
return -ENOMEM;
hdev->bus = HCI_USB;
hci_set_drvdata(hdev, data);
if (id->driver_info & BTUSB_AMP)
hdev->dev_type = HCI_AMP;
else
hdev->dev_type = HCI_BREDR;
data->hdev = hdev;
SET_HCIDEV_DEV(hdev, &intf->dev);
hdev->open = btusb_open;
hdev->close = btusb_close;
hdev->flush = btusb_flush;
hdev->send = btusb_send_frame;
hdev->notify = btusb_notify;
if (id->driver_info & BTUSB_BCM92035)
hdev->setup = btusb_setup_bcm92035;
#ifdef CONFIG_BT_HCIBTUSB_BCM
if (id->driver_info & BTUSB_BCM_PATCHRAM) {
hdev->setup = btbcm_setup_patchram;
hdev->set_bdaddr = btbcm_set_bdaddr;
}
if (id->driver_info & BTUSB_BCM_APPLE)
hdev->setup = btbcm_setup_apple;
#endif
if (id->driver_info & BTUSB_INTEL) {
hdev->setup = btusb_setup_intel;
hdev->shutdown = btusb_shutdown_intel;
hdev->set_bdaddr = btintel_set_bdaddr;
set_bit(HCI_QUIRK_STRICT_DUPLICATE_FILTER, &hdev->quirks);
set_bit(HCI_QUIRK_SIMULTANEOUS_DISCOVERY, &hdev->quirks);
}
if (id->driver_info & BTUSB_INTEL_NEW) {
hdev->send = btusb_send_frame_intel;
hdev->setup = btusb_setup_intel_new;
hdev->hw_error = btusb_hw_error_intel;
hdev->set_bdaddr = btintel_set_bdaddr;
set_bit(HCI_QUIRK_STRICT_DUPLICATE_FILTER, &hdev->quirks);
}
if (id->driver_info & BTUSB_MARVELL)
hdev->set_bdaddr = btusb_set_bdaddr_marvell;
if (id->driver_info & BTUSB_SWAVE) {
set_bit(HCI_QUIRK_FIXUP_INQUIRY_MODE, &hdev->quirks);
set_bit(HCI_QUIRK_BROKEN_LOCAL_COMMANDS, &hdev->quirks);
}
if (id->driver_info & BTUSB_INTEL_BOOT)
set_bit(HCI_QUIRK_RAW_DEVICE, &hdev->quirks);
if (id->driver_info & BTUSB_ATH3012) {
hdev->set_bdaddr = btusb_set_bdaddr_ath3012;
set_bit(HCI_QUIRK_SIMULTANEOUS_DISCOVERY, &hdev->quirks);
set_bit(HCI_QUIRK_STRICT_DUPLICATE_FILTER, &hdev->quirks);
}
if (id->driver_info & BTUSB_QCA_ROME) {
data->setup_on_usb = btusb_setup_qca;
hdev->set_bdaddr = btusb_set_bdaddr_ath3012;
}
if (id->driver_info & BTUSB_REALTEK)
hdev->setup = btusb_setup_realtek;
if (id->driver_info & BTUSB_AMP) {
data->isoc = NULL;
} else {
data->isoc = usb_ifnum_to_if(data->udev, 1);
}
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
set_bit(HCI_QUIRK_SIMULTANEOUS_DISCOVERY, &hdev->quirks);
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
