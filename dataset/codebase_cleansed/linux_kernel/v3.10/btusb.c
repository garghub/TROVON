static int inc_tx(struct btusb_data *data)
{
unsigned long flags;
int rv;
spin_lock_irqsave(&data->txlock, flags);
rv = test_bit(BTUSB_SUSPENDING, &data->flags);
if (!rv)
data->tx_in_flight++;
spin_unlock_irqrestore(&data->txlock, flags);
return rv;
}
static void btusb_intr_complete(struct urb *urb)
{
struct hci_dev *hdev = urb->context;
struct btusb_data *data = hci_get_drvdata(hdev);
int err;
BT_DBG("%s urb %p status %d count %d", hdev->name,
urb, urb->status, urb->actual_length);
if (!test_bit(HCI_RUNNING, &hdev->flags))
return;
if (urb->status == 0) {
hdev->stat.byte_rx += urb->actual_length;
if (hci_recv_fragment(hdev, HCI_EVENT_PKT,
urb->transfer_buffer,
urb->actual_length) < 0) {
BT_ERR("%s corrupted event packet", hdev->name);
hdev->stat.err_rx++;
}
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
btusb_intr_complete, hdev,
data->intr_ep->bInterval);
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
BT_DBG("%s urb %p status %d count %d", hdev->name,
urb, urb->status, urb->actual_length);
if (!test_bit(HCI_RUNNING, &hdev->flags))
return;
if (urb->status == 0) {
hdev->stat.byte_rx += urb->actual_length;
if (hci_recv_fragment(hdev, HCI_ACLDATA_PKT,
urb->transfer_buffer,
urb->actual_length) < 0) {
BT_ERR("%s corrupted ACL packet", hdev->name);
hdev->stat.err_rx++;
}
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
usb_fill_bulk_urb(urb, data->udev, pipe,
buf, size, btusb_bulk_complete, hdev);
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
BT_DBG("%s urb %p status %d count %d", hdev->name,
urb, urb->status, urb->actual_length);
if (!test_bit(HCI_RUNNING, &hdev->flags))
return;
if (urb->status == 0) {
for (i = 0; i < urb->number_of_packets; i++) {
unsigned int offset = urb->iso_frame_desc[i].offset;
unsigned int length = urb->iso_frame_desc[i].actual_length;
if (urb->iso_frame_desc[i].status)
continue;
hdev->stat.byte_rx += length;
if (hci_recv_fragment(hdev, HCI_SCODATA_PKT,
urb->transfer_buffer + offset,
length) < 0) {
BT_ERR("%s corrupted SCO packet", hdev->name);
hdev->stat.err_rx++;
}
}
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
struct hci_dev *hdev = (struct hci_dev *) skb->dev;
struct btusb_data *data = hci_get_drvdata(hdev);
BT_DBG("%s urb %p status %d count %d", hdev->name,
urb, urb->status, urb->actual_length);
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
struct hci_dev *hdev = (struct hci_dev *) skb->dev;
BT_DBG("%s urb %p status %d count %d", hdev->name,
urb, urb->status, urb->actual_length);
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
return 0;
}
static int btusb_send_frame(struct sk_buff *skb)
{
struct hci_dev *hdev = (struct hci_dev *) skb->dev;
struct btusb_data *data = hci_get_drvdata(hdev);
struct usb_ctrlrequest *dr;
struct urb *urb;
unsigned int pipe;
int err;
BT_DBG("%s", hdev->name);
if (!test_bit(HCI_RUNNING, &hdev->flags))
return -EBUSY;
switch (bt_cb(skb)->pkt_type) {
case HCI_COMMAND_PKT:
urb = usb_alloc_urb(0, GFP_ATOMIC);
if (!urb)
return -ENOMEM;
dr = kmalloc(sizeof(*dr), GFP_ATOMIC);
if (!dr) {
usb_free_urb(urb);
return -ENOMEM;
}
dr->bRequestType = data->cmdreq_type;
dr->bRequest = 0;
dr->wIndex = 0;
dr->wValue = 0;
dr->wLength = __cpu_to_le16(skb->len);
pipe = usb_sndctrlpipe(data->udev, 0x00);
usb_fill_control_urb(urb, data->udev, pipe, (void *) dr,
skb->data, skb->len, btusb_tx_complete, skb);
hdev->stat.cmd_tx++;
break;
case HCI_ACLDATA_PKT:
if (!data->bulk_tx_ep)
return -ENODEV;
urb = usb_alloc_urb(0, GFP_ATOMIC);
if (!urb)
return -ENOMEM;
pipe = usb_sndbulkpipe(data->udev,
data->bulk_tx_ep->bEndpointAddress);
usb_fill_bulk_urb(urb, data->udev, pipe,
skb->data, skb->len, btusb_tx_complete, skb);
hdev->stat.acl_tx++;
break;
case HCI_SCODATA_PKT:
if (!data->isoc_tx_ep || hdev->conn_hash.sco_num < 1)
return -ENODEV;
urb = usb_alloc_urb(BTUSB_MAX_ISOC_FRAMES, GFP_ATOMIC);
if (!urb)
return -ENOMEM;
pipe = usb_sndisocpipe(data->udev,
data->isoc_tx_ep->bEndpointAddress);
usb_fill_int_urb(urb, data->udev, pipe,
skb->data, skb->len, btusb_isoc_tx_complete,
skb, data->isoc_tx_ep->bInterval);
urb->transfer_flags = URB_ISO_ASAP;
__fill_isoc_descriptor(urb, skb->len,
le16_to_cpu(data->isoc_tx_ep->wMaxPacketSize));
hdev->stat.sco_tx++;
goto skip_waking;
default:
return -EILSEQ;
}
err = inc_tx(data);
if (err) {
usb_anchor_urb(urb, &data->deferred);
schedule_work(&data->waker);
err = 0;
goto done;
}
skip_waking:
usb_anchor_urb(urb, &data->tx_anchor);
err = usb_submit_urb(urb, GFP_ATOMIC);
if (err < 0) {
if (err != -EPERM && err != -ENODEV)
BT_ERR("%s urb %p submission failed (%d)",
hdev->name, urb, -err);
kfree(urb->setup_packet);
usb_unanchor_urb(urb);
} else {
usb_mark_last_busy(data->udev);
}
done:
usb_free_urb(urb);
return err;
}
static void btusb_notify(struct hci_dev *hdev, unsigned int evt)
{
struct btusb_data *data = hci_get_drvdata(hdev);
BT_DBG("%s evt %d", hdev->name, evt);
if (hdev->conn_hash.sco_num != data->sco_num) {
data->sco_num = hdev->conn_hash.sco_num;
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
if (hdev->conn_hash.sco_num > 0) {
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
new_alts = alts[hdev->conn_hash.sco_num - 1];
} else {
new_alts = hdev->conn_hash.sco_num;
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
return -PTR_ERR(skb);
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
return -PTR_ERR(skb);
}
kfree_skb(skb);
skb = __hci_cmd_sync(hdev, 0xfc05, 0, NULL, HCI_INIT_TIMEOUT);
if (IS_ERR(skb)) {
BT_ERR("%s reading Intel fw version command failed (%ld)",
hdev->name, PTR_ERR(skb));
return -PTR_ERR(skb);
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
return 0;
}
fw = btusb_setup_intel_get_fw(hdev, ver);
if (!fw) {
kfree_skb(skb);
return 0;
}
fw_ptr = fw->data;
skb = __hci_cmd_sync(hdev, 0xfc11, 2, mfg_enable, HCI_INIT_TIMEOUT);
if (IS_ERR(skb)) {
BT_ERR("%s entering Intel manufacturer mode failed (%ld)",
hdev->name, PTR_ERR(skb));
release_firmware(fw);
return -PTR_ERR(skb);
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
return -PTR_ERR(skb);
}
kfree_skb(skb);
BT_INFO("%s: Intel Bluetooth firmware patch completed and activated",
hdev->name);
return 0;
exit_mfg_disable:
skb = __hci_cmd_sync(hdev, 0xfc11, sizeof(mfg_disable), mfg_disable,
HCI_INIT_TIMEOUT);
if (IS_ERR(skb)) {
BT_ERR("%s exiting Intel manufacturer mode failed (%ld)",
hdev->name, PTR_ERR(skb));
return -PTR_ERR(skb);
}
kfree_skb(skb);
BT_INFO("%s: Intel Bluetooth firmware patch completed", hdev->name);
return 0;
exit_mfg_deactivate:
release_firmware(fw);
skb = __hci_cmd_sync(hdev, 0xfc11, sizeof(mfg_reset_deactivate),
mfg_reset_deactivate, HCI_INIT_TIMEOUT);
if (IS_ERR(skb)) {
BT_ERR("%s exiting Intel manufacturer mode failed (%ld)",
hdev->name, PTR_ERR(skb));
return -PTR_ERR(skb);
}
kfree_skb(skb);
BT_INFO("%s: Intel Bluetooth firmware patch completed and deactivated",
hdev->name);
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
if (ignore_dga && id->driver_info & BTUSB_DIGIANSWER)
return -ENODEV;
if (ignore_csr && id->driver_info & BTUSB_CSR)
return -ENODEV;
if (ignore_sniffer && id->driver_info & BTUSB_SNIFFER)
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
spin_lock_init(&data->lock);
INIT_WORK(&data->work, btusb_work);
INIT_WORK(&data->waker, btusb_waker);
spin_lock_init(&data->txlock);
init_usb_anchor(&data->tx_anchor);
init_usb_anchor(&data->intr_anchor);
init_usb_anchor(&data->bulk_anchor);
init_usb_anchor(&data->isoc_anchor);
init_usb_anchor(&data->deferred);
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
if (id->driver_info & BTUSB_INTEL)
hdev->setup = btusb_setup_intel;
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
if (le16_to_cpu(udev->descriptor.bcdDevice) < 0x117)
set_bit(HCI_QUIRK_RESET_ON_CLOSE, &hdev->quirks);
}
if (id->driver_info & BTUSB_SNIFFER) {
struct usb_device *udev = data->udev;
if (le16_to_cpu(udev->descriptor.bcdDevice) > 0x997)
set_bit(HCI_QUIRK_RAW_DEVICE, &hdev->quirks);
data->isoc = NULL;
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
