static inline bool kvaser_is_leaf(const struct usb_device_id *id)
{
return id->idProduct >= USB_LEAF_DEVEL_PRODUCT_ID &&
id->idProduct <= USB_MINI_PCIE_HS_PRODUCT_ID;
}
static inline bool kvaser_is_usbcan(const struct usb_device_id *id)
{
return id->idProduct >= USB_USBCAN_REVB_PRODUCT_ID &&
id->idProduct <= USB_MEMORATOR_PRODUCT_ID;
}
static inline int kvaser_usb_send_msg(const struct kvaser_usb *dev,
struct kvaser_msg *msg)
{
int actual_len;
return usb_bulk_msg(dev->udev,
usb_sndbulkpipe(dev->udev,
dev->bulk_out->bEndpointAddress),
msg, msg->len, &actual_len,
USB_SEND_TIMEOUT);
}
static int kvaser_usb_wait_msg(const struct kvaser_usb *dev, u8 id,
struct kvaser_msg *msg)
{
struct kvaser_msg *tmp;
void *buf;
int actual_len;
int err;
int pos;
unsigned long to = jiffies + msecs_to_jiffies(USB_RECV_TIMEOUT);
buf = kzalloc(RX_BUFFER_SIZE, GFP_KERNEL);
if (!buf)
return -ENOMEM;
do {
err = usb_bulk_msg(dev->udev,
usb_rcvbulkpipe(dev->udev,
dev->bulk_in->bEndpointAddress),
buf, RX_BUFFER_SIZE, &actual_len,
USB_RECV_TIMEOUT);
if (err < 0)
goto end;
pos = 0;
while (pos <= actual_len - MSG_HEADER_LEN) {
tmp = buf + pos;
if (tmp->len == 0) {
pos = round_up(pos, le16_to_cpu(dev->bulk_in->
wMaxPacketSize));
continue;
}
if (pos + tmp->len > actual_len) {
dev_err(dev->udev->dev.parent,
"Format error\n");
break;
}
if (tmp->id == id) {
memcpy(msg, tmp, tmp->len);
goto end;
}
pos += tmp->len;
}
} while (time_before(jiffies, to));
err = -EINVAL;
end:
kfree(buf);
return err;
}
static int kvaser_usb_send_simple_msg(const struct kvaser_usb *dev,
u8 msg_id, int channel)
{
struct kvaser_msg *msg;
int rc;
msg = kmalloc(sizeof(*msg), GFP_KERNEL);
if (!msg)
return -ENOMEM;
msg->id = msg_id;
msg->len = MSG_HEADER_LEN + sizeof(struct kvaser_msg_simple);
msg->u.simple.channel = channel;
msg->u.simple.tid = 0xff;
rc = kvaser_usb_send_msg(dev, msg);
kfree(msg);
return rc;
}
static int kvaser_usb_get_software_info(struct kvaser_usb *dev)
{
struct kvaser_msg msg;
int err;
err = kvaser_usb_send_simple_msg(dev, CMD_GET_SOFTWARE_INFO, 0);
if (err)
return err;
err = kvaser_usb_wait_msg(dev, CMD_GET_SOFTWARE_INFO_REPLY, &msg);
if (err)
return err;
switch (dev->family) {
case KVASER_LEAF:
dev->fw_version = le32_to_cpu(msg.u.leaf.softinfo.fw_version);
dev->max_tx_urbs =
le16_to_cpu(msg.u.leaf.softinfo.max_outstanding_tx);
break;
case KVASER_USBCAN:
dev->fw_version = le32_to_cpu(msg.u.usbcan.softinfo.fw_version);
dev->max_tx_urbs =
le16_to_cpu(msg.u.usbcan.softinfo.max_outstanding_tx);
break;
}
return 0;
}
static int kvaser_usb_get_card_info(struct kvaser_usb *dev)
{
struct kvaser_msg msg;
int err;
err = kvaser_usb_send_simple_msg(dev, CMD_GET_CARD_INFO, 0);
if (err)
return err;
err = kvaser_usb_wait_msg(dev, CMD_GET_CARD_INFO_REPLY, &msg);
if (err)
return err;
dev->nchannels = msg.u.cardinfo.nchannels;
if ((dev->nchannels > MAX_NET_DEVICES) ||
(dev->family == KVASER_USBCAN &&
dev->nchannels > MAX_USBCAN_NET_DEVICES))
return -EINVAL;
return 0;
}
static void kvaser_usb_tx_acknowledge(const struct kvaser_usb *dev,
const struct kvaser_msg *msg)
{
struct net_device_stats *stats;
struct kvaser_usb_tx_urb_context *context;
struct kvaser_usb_net_priv *priv;
struct sk_buff *skb;
struct can_frame *cf;
unsigned long flags;
u8 channel, tid;
channel = msg->u.tx_acknowledge_header.channel;
tid = msg->u.tx_acknowledge_header.tid;
if (channel >= dev->nchannels) {
dev_err(dev->udev->dev.parent,
"Invalid channel number (%d)\n", channel);
return;
}
priv = dev->nets[channel];
if (!netif_device_present(priv->netdev))
return;
stats = &priv->netdev->stats;
context = &priv->tx_contexts[tid % dev->max_tx_urbs];
if (priv->can.restart_ms &&
(priv->can.state >= CAN_STATE_BUS_OFF)) {
skb = alloc_can_err_skb(priv->netdev, &cf);
if (skb) {
cf->can_id |= CAN_ERR_RESTARTED;
stats->rx_packets++;
stats->rx_bytes += cf->can_dlc;
netif_rx(skb);
} else {
netdev_err(priv->netdev,
"No memory left for err_skb\n");
}
priv->can.can_stats.restarts++;
netif_carrier_on(priv->netdev);
priv->can.state = CAN_STATE_ERROR_ACTIVE;
}
stats->tx_packets++;
stats->tx_bytes += context->dlc;
spin_lock_irqsave(&priv->tx_contexts_lock, flags);
can_get_echo_skb(priv->netdev, context->echo_index);
context->echo_index = dev->max_tx_urbs;
--priv->active_tx_contexts;
netif_wake_queue(priv->netdev);
spin_unlock_irqrestore(&priv->tx_contexts_lock, flags);
}
static void kvaser_usb_simple_msg_callback(struct urb *urb)
{
struct net_device *netdev = urb->context;
kfree(urb->transfer_buffer);
if (urb->status)
netdev_warn(netdev, "urb status received: %d\n",
urb->status);
}
static int kvaser_usb_simple_msg_async(struct kvaser_usb_net_priv *priv,
u8 msg_id)
{
struct kvaser_usb *dev = priv->dev;
struct net_device *netdev = priv->netdev;
struct kvaser_msg *msg;
struct urb *urb;
void *buf;
int err;
urb = usb_alloc_urb(0, GFP_ATOMIC);
if (!urb) {
netdev_err(netdev, "No memory left for URBs\n");
return -ENOMEM;
}
buf = kmalloc(sizeof(struct kvaser_msg), GFP_ATOMIC);
if (!buf) {
usb_free_urb(urb);
return -ENOMEM;
}
msg = (struct kvaser_msg *)buf;
msg->len = MSG_HEADER_LEN + sizeof(struct kvaser_msg_simple);
msg->id = msg_id;
msg->u.simple.channel = priv->channel;
usb_fill_bulk_urb(urb, dev->udev,
usb_sndbulkpipe(dev->udev,
dev->bulk_out->bEndpointAddress),
buf, msg->len,
kvaser_usb_simple_msg_callback, netdev);
usb_anchor_urb(urb, &priv->tx_submitted);
err = usb_submit_urb(urb, GFP_ATOMIC);
if (err) {
netdev_err(netdev, "Error transmitting URB\n");
usb_unanchor_urb(urb);
usb_free_urb(urb);
return err;
}
usb_free_urb(urb);
return 0;
}
static void kvaser_usb_rx_error_update_can_state(struct kvaser_usb_net_priv *priv,
const struct kvaser_usb_error_summary *es,
struct can_frame *cf)
{
struct kvaser_usb *dev = priv->dev;
struct net_device_stats *stats = &priv->netdev->stats;
enum can_state cur_state, new_state, tx_state, rx_state;
netdev_dbg(priv->netdev, "Error status: 0x%02x\n", es->status);
new_state = cur_state = priv->can.state;
if (es->status & (M16C_STATE_BUS_OFF | M16C_STATE_BUS_RESET))
new_state = CAN_STATE_BUS_OFF;
else if (es->status & M16C_STATE_BUS_PASSIVE)
new_state = CAN_STATE_ERROR_PASSIVE;
else if (es->status & M16C_STATE_BUS_ERROR) {
if (cur_state < CAN_STATE_BUS_OFF) {
if ((es->txerr >= 128) || (es->rxerr >= 128))
new_state = CAN_STATE_ERROR_PASSIVE;
else if ((es->txerr >= 96) || (es->rxerr >= 96))
new_state = CAN_STATE_ERROR_WARNING;
else if (cur_state > CAN_STATE_ERROR_ACTIVE)
new_state = CAN_STATE_ERROR_ACTIVE;
}
}
if (!es->status)
new_state = CAN_STATE_ERROR_ACTIVE;
if (new_state != cur_state) {
tx_state = (es->txerr >= es->rxerr) ? new_state : 0;
rx_state = (es->txerr <= es->rxerr) ? new_state : 0;
can_change_state(priv->netdev, cf, tx_state, rx_state);
}
if (priv->can.restart_ms &&
(cur_state >= CAN_STATE_BUS_OFF) &&
(new_state < CAN_STATE_BUS_OFF)) {
priv->can.can_stats.restarts++;
}
switch (dev->family) {
case KVASER_LEAF:
if (es->leaf.error_factor) {
priv->can.can_stats.bus_error++;
stats->rx_errors++;
}
break;
case KVASER_USBCAN:
if (es->usbcan.error_state & USBCAN_ERROR_STATE_TX_ERROR)
stats->tx_errors++;
if (es->usbcan.error_state & USBCAN_ERROR_STATE_RX_ERROR)
stats->rx_errors++;
if (es->usbcan.error_state & USBCAN_ERROR_STATE_BUSERROR) {
priv->can.can_stats.bus_error++;
}
break;
}
priv->bec.txerr = es->txerr;
priv->bec.rxerr = es->rxerr;
}
static void kvaser_usb_rx_error(const struct kvaser_usb *dev,
const struct kvaser_usb_error_summary *es)
{
struct can_frame *cf, tmp_cf = { .can_id = CAN_ERR_FLAG, .can_dlc = CAN_ERR_DLC };
struct sk_buff *skb;
struct net_device_stats *stats;
struct kvaser_usb_net_priv *priv;
enum can_state old_state, new_state;
if (es->channel >= dev->nchannels) {
dev_err(dev->udev->dev.parent,
"Invalid channel number (%d)\n", es->channel);
return;
}
priv = dev->nets[es->channel];
stats = &priv->netdev->stats;
old_state = priv->can.state;
kvaser_usb_rx_error_update_can_state(priv, es, &tmp_cf);
new_state = priv->can.state;
skb = alloc_can_err_skb(priv->netdev, &cf);
if (!skb) {
stats->rx_dropped++;
return;
}
memcpy(cf, &tmp_cf, sizeof(*cf));
if (new_state != old_state) {
if (es->status &
(M16C_STATE_BUS_OFF | M16C_STATE_BUS_RESET)) {
if (!priv->can.restart_ms)
kvaser_usb_simple_msg_async(priv, CMD_STOP_CHIP);
netif_carrier_off(priv->netdev);
}
if (priv->can.restart_ms &&
(old_state >= CAN_STATE_BUS_OFF) &&
(new_state < CAN_STATE_BUS_OFF)) {
cf->can_id |= CAN_ERR_RESTARTED;
netif_carrier_on(priv->netdev);
}
}
switch (dev->family) {
case KVASER_LEAF:
if (es->leaf.error_factor) {
cf->can_id |= CAN_ERR_BUSERROR | CAN_ERR_PROT;
if (es->leaf.error_factor & M16C_EF_ACKE)
cf->data[3] = CAN_ERR_PROT_LOC_ACK;
if (es->leaf.error_factor & M16C_EF_CRCE)
cf->data[3] = CAN_ERR_PROT_LOC_CRC_SEQ;
if (es->leaf.error_factor & M16C_EF_FORME)
cf->data[2] |= CAN_ERR_PROT_FORM;
if (es->leaf.error_factor & M16C_EF_STFE)
cf->data[2] |= CAN_ERR_PROT_STUFF;
if (es->leaf.error_factor & M16C_EF_BITE0)
cf->data[2] |= CAN_ERR_PROT_BIT0;
if (es->leaf.error_factor & M16C_EF_BITE1)
cf->data[2] |= CAN_ERR_PROT_BIT1;
if (es->leaf.error_factor & M16C_EF_TRE)
cf->data[2] |= CAN_ERR_PROT_TX;
}
break;
case KVASER_USBCAN:
if (es->usbcan.error_state & USBCAN_ERROR_STATE_BUSERROR) {
cf->can_id |= CAN_ERR_BUSERROR;
}
break;
}
cf->data[6] = es->txerr;
cf->data[7] = es->rxerr;
stats->rx_packets++;
stats->rx_bytes += cf->can_dlc;
netif_rx(skb);
}
static void kvaser_usbcan_conditionally_rx_error(const struct kvaser_usb *dev,
struct kvaser_usb_error_summary *es)
{
struct kvaser_usb_net_priv *priv;
int channel;
bool report_error;
channel = es->channel;
if (channel >= dev->nchannels) {
dev_err(dev->udev->dev.parent,
"Invalid channel number (%d)\n", channel);
return;
}
priv = dev->nets[channel];
report_error = false;
if (es->txerr != priv->bec.txerr) {
es->usbcan.error_state |= USBCAN_ERROR_STATE_TX_ERROR;
report_error = true;
}
if (es->rxerr != priv->bec.rxerr) {
es->usbcan.error_state |= USBCAN_ERROR_STATE_RX_ERROR;
report_error = true;
}
if ((es->status & M16C_STATE_BUS_ERROR) &&
!(es->usbcan.other_ch_status & M16C_STATE_BUS_ERROR)) {
es->usbcan.error_state |= USBCAN_ERROR_STATE_BUSERROR;
report_error = true;
}
if (report_error)
kvaser_usb_rx_error(dev, es);
}
static void kvaser_usbcan_rx_error(const struct kvaser_usb *dev,
const struct kvaser_msg *msg)
{
struct kvaser_usb_error_summary es = { };
switch (msg->id) {
case CMD_CHIP_STATE_EVENT:
es.channel = msg->u.usbcan.chip_state_event.channel;
es.status = msg->u.usbcan.chip_state_event.status;
es.txerr = msg->u.usbcan.chip_state_event.tx_errors_count;
es.rxerr = msg->u.usbcan.chip_state_event.rx_errors_count;
kvaser_usbcan_conditionally_rx_error(dev, &es);
break;
case CMD_CAN_ERROR_EVENT:
es.channel = 0;
es.status = msg->u.usbcan.error_event.status_ch0;
es.txerr = msg->u.usbcan.error_event.tx_errors_count_ch0;
es.rxerr = msg->u.usbcan.error_event.rx_errors_count_ch0;
es.usbcan.other_ch_status =
msg->u.usbcan.error_event.status_ch1;
kvaser_usbcan_conditionally_rx_error(dev, &es);
if (dev->nchannels == MAX_USBCAN_NET_DEVICES) {
es.channel = 1;
es.status = msg->u.usbcan.error_event.status_ch1;
es.txerr = msg->u.usbcan.error_event.tx_errors_count_ch1;
es.rxerr = msg->u.usbcan.error_event.rx_errors_count_ch1;
es.usbcan.other_ch_status =
msg->u.usbcan.error_event.status_ch0;
kvaser_usbcan_conditionally_rx_error(dev, &es);
}
break;
default:
dev_err(dev->udev->dev.parent, "Invalid msg id (%d)\n",
msg->id);
}
}
static void kvaser_leaf_rx_error(const struct kvaser_usb *dev,
const struct kvaser_msg *msg)
{
struct kvaser_usb_error_summary es = { };
switch (msg->id) {
case CMD_CAN_ERROR_EVENT:
es.channel = msg->u.leaf.error_event.channel;
es.status = msg->u.leaf.error_event.status;
es.txerr = msg->u.leaf.error_event.tx_errors_count;
es.rxerr = msg->u.leaf.error_event.rx_errors_count;
es.leaf.error_factor = msg->u.leaf.error_event.error_factor;
break;
case CMD_LEAF_LOG_MESSAGE:
es.channel = msg->u.leaf.log_message.channel;
es.status = msg->u.leaf.log_message.data[0];
es.txerr = msg->u.leaf.log_message.data[2];
es.rxerr = msg->u.leaf.log_message.data[3];
es.leaf.error_factor = msg->u.leaf.log_message.data[1];
break;
case CMD_CHIP_STATE_EVENT:
es.channel = msg->u.leaf.chip_state_event.channel;
es.status = msg->u.leaf.chip_state_event.status;
es.txerr = msg->u.leaf.chip_state_event.tx_errors_count;
es.rxerr = msg->u.leaf.chip_state_event.rx_errors_count;
es.leaf.error_factor = 0;
break;
default:
dev_err(dev->udev->dev.parent, "Invalid msg id (%d)\n",
msg->id);
return;
}
kvaser_usb_rx_error(dev, &es);
}
static void kvaser_usb_rx_can_err(const struct kvaser_usb_net_priv *priv,
const struct kvaser_msg *msg)
{
struct can_frame *cf;
struct sk_buff *skb;
struct net_device_stats *stats = &priv->netdev->stats;
if (msg->u.rx_can_header.flag & (MSG_FLAG_ERROR_FRAME |
MSG_FLAG_NERR)) {
netdev_err(priv->netdev, "Unknown error (flags: 0x%02x)\n",
msg->u.rx_can_header.flag);
stats->rx_errors++;
return;
}
if (msg->u.rx_can_header.flag & MSG_FLAG_OVERRUN) {
stats->rx_over_errors++;
stats->rx_errors++;
skb = alloc_can_err_skb(priv->netdev, &cf);
if (!skb) {
stats->rx_dropped++;
return;
}
cf->can_id |= CAN_ERR_CRTL;
cf->data[1] = CAN_ERR_CRTL_RX_OVERFLOW;
stats->rx_packets++;
stats->rx_bytes += cf->can_dlc;
netif_rx(skb);
}
}
static void kvaser_usb_rx_can_msg(const struct kvaser_usb *dev,
const struct kvaser_msg *msg)
{
struct kvaser_usb_net_priv *priv;
struct can_frame *cf;
struct sk_buff *skb;
struct net_device_stats *stats;
u8 channel = msg->u.rx_can_header.channel;
const u8 *rx_msg = NULL;
if (channel >= dev->nchannels) {
dev_err(dev->udev->dev.parent,
"Invalid channel number (%d)\n", channel);
return;
}
priv = dev->nets[channel];
stats = &priv->netdev->stats;
if ((msg->u.rx_can_header.flag & MSG_FLAG_ERROR_FRAME) &&
(dev->family == KVASER_LEAF && msg->id == CMD_LEAF_LOG_MESSAGE)) {
kvaser_leaf_rx_error(dev, msg);
return;
} else if (msg->u.rx_can_header.flag & (MSG_FLAG_ERROR_FRAME |
MSG_FLAG_NERR |
MSG_FLAG_OVERRUN)) {
kvaser_usb_rx_can_err(priv, msg);
return;
} else if (msg->u.rx_can_header.flag & ~MSG_FLAG_REMOTE_FRAME) {
netdev_warn(priv->netdev,
"Unhandled frame (flags: 0x%02x)",
msg->u.rx_can_header.flag);
return;
}
switch (dev->family) {
case KVASER_LEAF:
rx_msg = msg->u.leaf.rx_can.msg;
break;
case KVASER_USBCAN:
rx_msg = msg->u.usbcan.rx_can.msg;
break;
}
skb = alloc_can_skb(priv->netdev, &cf);
if (!skb) {
stats->tx_dropped++;
return;
}
if (dev->family == KVASER_LEAF && msg->id == CMD_LEAF_LOG_MESSAGE) {
cf->can_id = le32_to_cpu(msg->u.leaf.log_message.id);
if (cf->can_id & KVASER_EXTENDED_FRAME)
cf->can_id &= CAN_EFF_MASK | CAN_EFF_FLAG;
else
cf->can_id &= CAN_SFF_MASK;
cf->can_dlc = get_can_dlc(msg->u.leaf.log_message.dlc);
if (msg->u.leaf.log_message.flags & MSG_FLAG_REMOTE_FRAME)
cf->can_id |= CAN_RTR_FLAG;
else
memcpy(cf->data, &msg->u.leaf.log_message.data,
cf->can_dlc);
} else {
cf->can_id = ((rx_msg[0] & 0x1f) << 6) | (rx_msg[1] & 0x3f);
if (msg->id == CMD_RX_EXT_MESSAGE) {
cf->can_id <<= 18;
cf->can_id |= ((rx_msg[2] & 0x0f) << 14) |
((rx_msg[3] & 0xff) << 6) |
(rx_msg[4] & 0x3f);
cf->can_id |= CAN_EFF_FLAG;
}
cf->can_dlc = get_can_dlc(rx_msg[5]);
if (msg->u.rx_can_header.flag & MSG_FLAG_REMOTE_FRAME)
cf->can_id |= CAN_RTR_FLAG;
else
memcpy(cf->data, &rx_msg[6],
cf->can_dlc);
}
stats->rx_packets++;
stats->rx_bytes += cf->can_dlc;
netif_rx(skb);
}
static void kvaser_usb_start_chip_reply(const struct kvaser_usb *dev,
const struct kvaser_msg *msg)
{
struct kvaser_usb_net_priv *priv;
u8 channel = msg->u.simple.channel;
if (channel >= dev->nchannels) {
dev_err(dev->udev->dev.parent,
"Invalid channel number (%d)\n", channel);
return;
}
priv = dev->nets[channel];
if (completion_done(&priv->start_comp) &&
netif_queue_stopped(priv->netdev)) {
netif_wake_queue(priv->netdev);
} else {
netif_start_queue(priv->netdev);
complete(&priv->start_comp);
}
}
static void kvaser_usb_stop_chip_reply(const struct kvaser_usb *dev,
const struct kvaser_msg *msg)
{
struct kvaser_usb_net_priv *priv;
u8 channel = msg->u.simple.channel;
if (channel >= dev->nchannels) {
dev_err(dev->udev->dev.parent,
"Invalid channel number (%d)\n", channel);
return;
}
priv = dev->nets[channel];
complete(&priv->stop_comp);
}
static void kvaser_usb_handle_message(const struct kvaser_usb *dev,
const struct kvaser_msg *msg)
{
switch (msg->id) {
case CMD_START_CHIP_REPLY:
kvaser_usb_start_chip_reply(dev, msg);
break;
case CMD_STOP_CHIP_REPLY:
kvaser_usb_stop_chip_reply(dev, msg);
break;
case CMD_RX_STD_MESSAGE:
case CMD_RX_EXT_MESSAGE:
kvaser_usb_rx_can_msg(dev, msg);
break;
case CMD_LEAF_LOG_MESSAGE:
if (dev->family != KVASER_LEAF)
goto warn;
kvaser_usb_rx_can_msg(dev, msg);
break;
case CMD_CHIP_STATE_EVENT:
case CMD_CAN_ERROR_EVENT:
if (dev->family == KVASER_LEAF)
kvaser_leaf_rx_error(dev, msg);
else
kvaser_usbcan_rx_error(dev, msg);
break;
case CMD_TX_ACKNOWLEDGE:
kvaser_usb_tx_acknowledge(dev, msg);
break;
case CMD_USBCAN_CLOCK_OVERFLOW_EVENT:
if (dev->family != KVASER_USBCAN)
goto warn;
break;
default:
warn: dev_warn(dev->udev->dev.parent,
"Unhandled message (%d)\n", msg->id);
break;
}
}
static void kvaser_usb_read_bulk_callback(struct urb *urb)
{
struct kvaser_usb *dev = urb->context;
struct kvaser_msg *msg;
int pos = 0;
int err, i;
switch (urb->status) {
case 0:
break;
case -ENOENT:
case -ESHUTDOWN:
return;
default:
dev_info(dev->udev->dev.parent, "Rx URB aborted (%d)\n",
urb->status);
goto resubmit_urb;
}
while (pos <= urb->actual_length - MSG_HEADER_LEN) {
msg = urb->transfer_buffer + pos;
if (msg->len == 0) {
pos = round_up(pos, le16_to_cpu(dev->bulk_in->
wMaxPacketSize));
continue;
}
if (pos + msg->len > urb->actual_length) {
dev_err(dev->udev->dev.parent, "Format error\n");
break;
}
kvaser_usb_handle_message(dev, msg);
pos += msg->len;
}
resubmit_urb:
usb_fill_bulk_urb(urb, dev->udev,
usb_rcvbulkpipe(dev->udev,
dev->bulk_in->bEndpointAddress),
urb->transfer_buffer, RX_BUFFER_SIZE,
kvaser_usb_read_bulk_callback, dev);
err = usb_submit_urb(urb, GFP_ATOMIC);
if (err == -ENODEV) {
for (i = 0; i < dev->nchannels; i++) {
if (!dev->nets[i])
continue;
netif_device_detach(dev->nets[i]->netdev);
}
} else if (err) {
dev_err(dev->udev->dev.parent,
"Failed resubmitting read bulk urb: %d\n", err);
}
return;
}
static int kvaser_usb_setup_rx_urbs(struct kvaser_usb *dev)
{
int i, err = 0;
if (dev->rxinitdone)
return 0;
for (i = 0; i < MAX_RX_URBS; i++) {
struct urb *urb = NULL;
u8 *buf = NULL;
dma_addr_t buf_dma;
urb = usb_alloc_urb(0, GFP_KERNEL);
if (!urb) {
dev_warn(dev->udev->dev.parent,
"No memory left for URBs\n");
err = -ENOMEM;
break;
}
buf = usb_alloc_coherent(dev->udev, RX_BUFFER_SIZE,
GFP_KERNEL, &buf_dma);
if (!buf) {
dev_warn(dev->udev->dev.parent,
"No memory left for USB buffer\n");
usb_free_urb(urb);
err = -ENOMEM;
break;
}
usb_fill_bulk_urb(urb, dev->udev,
usb_rcvbulkpipe(dev->udev,
dev->bulk_in->bEndpointAddress),
buf, RX_BUFFER_SIZE,
kvaser_usb_read_bulk_callback,
dev);
urb->transfer_dma = buf_dma;
urb->transfer_flags |= URB_NO_TRANSFER_DMA_MAP;
usb_anchor_urb(urb, &dev->rx_submitted);
err = usb_submit_urb(urb, GFP_KERNEL);
if (err) {
usb_unanchor_urb(urb);
usb_free_coherent(dev->udev, RX_BUFFER_SIZE, buf,
buf_dma);
usb_free_urb(urb);
break;
}
dev->rxbuf[i] = buf;
dev->rxbuf_dma[i] = buf_dma;
usb_free_urb(urb);
}
if (i == 0) {
dev_warn(dev->udev->dev.parent,
"Cannot setup read URBs, error %d\n", err);
return err;
} else if (i < MAX_RX_URBS) {
dev_warn(dev->udev->dev.parent,
"RX performances may be slow\n");
}
dev->rxinitdone = true;
return 0;
}
static int kvaser_usb_set_opt_mode(const struct kvaser_usb_net_priv *priv)
{
struct kvaser_msg *msg;
int rc;
msg = kmalloc(sizeof(*msg), GFP_KERNEL);
if (!msg)
return -ENOMEM;
msg->id = CMD_SET_CTRL_MODE;
msg->len = MSG_HEADER_LEN + sizeof(struct kvaser_msg_ctrl_mode);
msg->u.ctrl_mode.tid = 0xff;
msg->u.ctrl_mode.channel = priv->channel;
if (priv->can.ctrlmode & CAN_CTRLMODE_LISTENONLY)
msg->u.ctrl_mode.ctrl_mode = KVASER_CTRL_MODE_SILENT;
else
msg->u.ctrl_mode.ctrl_mode = KVASER_CTRL_MODE_NORMAL;
rc = kvaser_usb_send_msg(priv->dev, msg);
kfree(msg);
return rc;
}
static int kvaser_usb_start_chip(struct kvaser_usb_net_priv *priv)
{
int err;
init_completion(&priv->start_comp);
err = kvaser_usb_send_simple_msg(priv->dev, CMD_START_CHIP,
priv->channel);
if (err)
return err;
if (!wait_for_completion_timeout(&priv->start_comp,
msecs_to_jiffies(START_TIMEOUT)))
return -ETIMEDOUT;
return 0;
}
static int kvaser_usb_open(struct net_device *netdev)
{
struct kvaser_usb_net_priv *priv = netdev_priv(netdev);
struct kvaser_usb *dev = priv->dev;
int err;
err = open_candev(netdev);
if (err)
return err;
err = kvaser_usb_setup_rx_urbs(dev);
if (err)
goto error;
err = kvaser_usb_set_opt_mode(priv);
if (err)
goto error;
err = kvaser_usb_start_chip(priv);
if (err) {
netdev_warn(netdev, "Cannot start device, error %d\n", err);
goto error;
}
priv->can.state = CAN_STATE_ERROR_ACTIVE;
return 0;
error:
close_candev(netdev);
return err;
}
static void kvaser_usb_reset_tx_urb_contexts(struct kvaser_usb_net_priv *priv)
{
int i, max_tx_urbs;
max_tx_urbs = priv->dev->max_tx_urbs;
priv->active_tx_contexts = 0;
for (i = 0; i < max_tx_urbs; i++)
priv->tx_contexts[i].echo_index = max_tx_urbs;
}
static void kvaser_usb_unlink_tx_urbs(struct kvaser_usb_net_priv *priv)
{
usb_kill_anchored_urbs(&priv->tx_submitted);
kvaser_usb_reset_tx_urb_contexts(priv);
}
static void kvaser_usb_unlink_all_urbs(struct kvaser_usb *dev)
{
int i;
usb_kill_anchored_urbs(&dev->rx_submitted);
for (i = 0; i < MAX_RX_URBS; i++)
usb_free_coherent(dev->udev, RX_BUFFER_SIZE,
dev->rxbuf[i],
dev->rxbuf_dma[i]);
for (i = 0; i < dev->nchannels; i++) {
struct kvaser_usb_net_priv *priv = dev->nets[i];
if (priv)
kvaser_usb_unlink_tx_urbs(priv);
}
}
static int kvaser_usb_stop_chip(struct kvaser_usb_net_priv *priv)
{
int err;
init_completion(&priv->stop_comp);
err = kvaser_usb_send_simple_msg(priv->dev, CMD_STOP_CHIP,
priv->channel);
if (err)
return err;
if (!wait_for_completion_timeout(&priv->stop_comp,
msecs_to_jiffies(STOP_TIMEOUT)))
return -ETIMEDOUT;
return 0;
}
static int kvaser_usb_flush_queue(struct kvaser_usb_net_priv *priv)
{
struct kvaser_msg *msg;
int rc;
msg = kmalloc(sizeof(*msg), GFP_KERNEL);
if (!msg)
return -ENOMEM;
msg->id = CMD_FLUSH_QUEUE;
msg->len = MSG_HEADER_LEN + sizeof(struct kvaser_msg_flush_queue);
msg->u.flush_queue.channel = priv->channel;
msg->u.flush_queue.flags = 0x00;
rc = kvaser_usb_send_msg(priv->dev, msg);
kfree(msg);
return rc;
}
static int kvaser_usb_close(struct net_device *netdev)
{
struct kvaser_usb_net_priv *priv = netdev_priv(netdev);
struct kvaser_usb *dev = priv->dev;
int err;
netif_stop_queue(netdev);
err = kvaser_usb_flush_queue(priv);
if (err)
netdev_warn(netdev, "Cannot flush queue, error %d\n", err);
if (kvaser_usb_send_simple_msg(dev, CMD_RESET_CHIP, priv->channel))
netdev_warn(netdev, "Cannot reset card, error %d\n", err);
err = kvaser_usb_stop_chip(priv);
if (err)
netdev_warn(netdev, "Cannot stop device, error %d\n", err);
kvaser_usb_unlink_tx_urbs(priv);
priv->can.state = CAN_STATE_STOPPED;
close_candev(priv->netdev);
return 0;
}
static void kvaser_usb_write_bulk_callback(struct urb *urb)
{
struct kvaser_usb_tx_urb_context *context = urb->context;
struct kvaser_usb_net_priv *priv;
struct net_device *netdev;
if (WARN_ON(!context))
return;
priv = context->priv;
netdev = priv->netdev;
kfree(urb->transfer_buffer);
if (!netif_device_present(netdev))
return;
if (urb->status)
netdev_info(netdev, "Tx URB aborted (%d)\n", urb->status);
}
static netdev_tx_t kvaser_usb_start_xmit(struct sk_buff *skb,
struct net_device *netdev)
{
struct kvaser_usb_net_priv *priv = netdev_priv(netdev);
struct kvaser_usb *dev = priv->dev;
struct net_device_stats *stats = &netdev->stats;
struct can_frame *cf = (struct can_frame *)skb->data;
struct kvaser_usb_tx_urb_context *context = NULL;
struct urb *urb;
void *buf;
struct kvaser_msg *msg;
int i, err, ret = NETDEV_TX_OK;
u8 *msg_tx_can_flags = NULL;
unsigned long flags;
if (can_dropped_invalid_skb(netdev, skb))
return NETDEV_TX_OK;
urb = usb_alloc_urb(0, GFP_ATOMIC);
if (!urb) {
netdev_err(netdev, "No memory left for URBs\n");
stats->tx_dropped++;
dev_kfree_skb(skb);
return NETDEV_TX_OK;
}
buf = kmalloc(sizeof(struct kvaser_msg), GFP_ATOMIC);
if (!buf) {
stats->tx_dropped++;
dev_kfree_skb(skb);
goto freeurb;
}
msg = buf;
msg->len = MSG_HEADER_LEN + sizeof(struct kvaser_msg_tx_can);
msg->u.tx_can.channel = priv->channel;
switch (dev->family) {
case KVASER_LEAF:
msg_tx_can_flags = &msg->u.tx_can.leaf.flags;
break;
case KVASER_USBCAN:
msg_tx_can_flags = &msg->u.tx_can.usbcan.flags;
break;
}
*msg_tx_can_flags = 0;
if (cf->can_id & CAN_EFF_FLAG) {
msg->id = CMD_TX_EXT_MESSAGE;
msg->u.tx_can.msg[0] = (cf->can_id >> 24) & 0x1f;
msg->u.tx_can.msg[1] = (cf->can_id >> 18) & 0x3f;
msg->u.tx_can.msg[2] = (cf->can_id >> 14) & 0x0f;
msg->u.tx_can.msg[3] = (cf->can_id >> 6) & 0xff;
msg->u.tx_can.msg[4] = cf->can_id & 0x3f;
} else {
msg->id = CMD_TX_STD_MESSAGE;
msg->u.tx_can.msg[0] = (cf->can_id >> 6) & 0x1f;
msg->u.tx_can.msg[1] = cf->can_id & 0x3f;
}
msg->u.tx_can.msg[5] = cf->can_dlc;
memcpy(&msg->u.tx_can.msg[6], cf->data, cf->can_dlc);
if (cf->can_id & CAN_RTR_FLAG)
*msg_tx_can_flags |= MSG_FLAG_REMOTE_FRAME;
spin_lock_irqsave(&priv->tx_contexts_lock, flags);
for (i = 0; i < dev->max_tx_urbs; i++) {
if (priv->tx_contexts[i].echo_index == dev->max_tx_urbs) {
context = &priv->tx_contexts[i];
context->echo_index = i;
can_put_echo_skb(skb, netdev, context->echo_index);
++priv->active_tx_contexts;
if (priv->active_tx_contexts >= dev->max_tx_urbs)
netif_stop_queue(netdev);
break;
}
}
spin_unlock_irqrestore(&priv->tx_contexts_lock, flags);
if (!context) {
netdev_warn(netdev, "cannot find free context\n");
kfree(buf);
ret = NETDEV_TX_BUSY;
goto freeurb;
}
context->priv = priv;
context->dlc = cf->can_dlc;
msg->u.tx_can.tid = context->echo_index;
usb_fill_bulk_urb(urb, dev->udev,
usb_sndbulkpipe(dev->udev,
dev->bulk_out->bEndpointAddress),
buf, msg->len,
kvaser_usb_write_bulk_callback, context);
usb_anchor_urb(urb, &priv->tx_submitted);
err = usb_submit_urb(urb, GFP_ATOMIC);
if (unlikely(err)) {
spin_lock_irqsave(&priv->tx_contexts_lock, flags);
can_free_echo_skb(netdev, context->echo_index);
context->echo_index = dev->max_tx_urbs;
--priv->active_tx_contexts;
netif_wake_queue(netdev);
spin_unlock_irqrestore(&priv->tx_contexts_lock, flags);
usb_unanchor_urb(urb);
stats->tx_dropped++;
if (err == -ENODEV)
netif_device_detach(netdev);
else
netdev_warn(netdev, "Failed tx_urb %d\n", err);
goto freeurb;
}
ret = NETDEV_TX_OK;
freeurb:
usb_free_urb(urb);
return ret;
}
static int kvaser_usb_set_bittiming(struct net_device *netdev)
{
struct kvaser_usb_net_priv *priv = netdev_priv(netdev);
struct can_bittiming *bt = &priv->can.bittiming;
struct kvaser_usb *dev = priv->dev;
struct kvaser_msg *msg;
int rc;
msg = kmalloc(sizeof(*msg), GFP_KERNEL);
if (!msg)
return -ENOMEM;
msg->id = CMD_SET_BUS_PARAMS;
msg->len = MSG_HEADER_LEN + sizeof(struct kvaser_msg_busparams);
msg->u.busparams.channel = priv->channel;
msg->u.busparams.tid = 0xff;
msg->u.busparams.bitrate = cpu_to_le32(bt->bitrate);
msg->u.busparams.sjw = bt->sjw;
msg->u.busparams.tseg1 = bt->prop_seg + bt->phase_seg1;
msg->u.busparams.tseg2 = bt->phase_seg2;
if (priv->can.ctrlmode & CAN_CTRLMODE_3_SAMPLES)
msg->u.busparams.no_samp = 3;
else
msg->u.busparams.no_samp = 1;
rc = kvaser_usb_send_msg(dev, msg);
kfree(msg);
return rc;
}
static int kvaser_usb_set_mode(struct net_device *netdev,
enum can_mode mode)
{
struct kvaser_usb_net_priv *priv = netdev_priv(netdev);
int err;
switch (mode) {
case CAN_MODE_START:
err = kvaser_usb_simple_msg_async(priv, CMD_START_CHIP);
if (err)
return err;
break;
default:
return -EOPNOTSUPP;
}
return 0;
}
static int kvaser_usb_get_berr_counter(const struct net_device *netdev,
struct can_berr_counter *bec)
{
struct kvaser_usb_net_priv *priv = netdev_priv(netdev);
*bec = priv->bec;
return 0;
}
static void kvaser_usb_remove_interfaces(struct kvaser_usb *dev)
{
int i;
for (i = 0; i < dev->nchannels; i++) {
if (!dev->nets[i])
continue;
unregister_candev(dev->nets[i]->netdev);
}
kvaser_usb_unlink_all_urbs(dev);
for (i = 0; i < dev->nchannels; i++) {
if (!dev->nets[i])
continue;
free_candev(dev->nets[i]->netdev);
}
}
static int kvaser_usb_init_one(struct usb_interface *intf,
const struct usb_device_id *id, int channel)
{
struct kvaser_usb *dev = usb_get_intfdata(intf);
struct net_device *netdev;
struct kvaser_usb_net_priv *priv;
int err;
err = kvaser_usb_send_simple_msg(dev, CMD_RESET_CHIP, channel);
if (err)
return err;
netdev = alloc_candev(sizeof(*priv) +
dev->max_tx_urbs * sizeof(*priv->tx_contexts),
dev->max_tx_urbs);
if (!netdev) {
dev_err(&intf->dev, "Cannot alloc candev\n");
return -ENOMEM;
}
priv = netdev_priv(netdev);
init_usb_anchor(&priv->tx_submitted);
init_completion(&priv->start_comp);
init_completion(&priv->stop_comp);
priv->dev = dev;
priv->netdev = netdev;
priv->channel = channel;
spin_lock_init(&priv->tx_contexts_lock);
kvaser_usb_reset_tx_urb_contexts(priv);
priv->can.state = CAN_STATE_STOPPED;
priv->can.clock.freq = CAN_USB_CLOCK;
priv->can.bittiming_const = &kvaser_usb_bittiming_const;
priv->can.do_set_bittiming = kvaser_usb_set_bittiming;
priv->can.do_set_mode = kvaser_usb_set_mode;
if (id->driver_info & KVASER_HAS_TXRX_ERRORS)
priv->can.do_get_berr_counter = kvaser_usb_get_berr_counter;
priv->can.ctrlmode_supported = CAN_CTRLMODE_3_SAMPLES;
if (id->driver_info & KVASER_HAS_SILENT_MODE)
priv->can.ctrlmode_supported |= CAN_CTRLMODE_LISTENONLY;
netdev->flags |= IFF_ECHO;
netdev->netdev_ops = &kvaser_usb_netdev_ops;
SET_NETDEV_DEV(netdev, &intf->dev);
netdev->dev_id = channel;
dev->nets[channel] = priv;
err = register_candev(netdev);
if (err) {
dev_err(&intf->dev, "Failed to register can device\n");
free_candev(netdev);
dev->nets[channel] = NULL;
return err;
}
netdev_dbg(netdev, "device registered\n");
return 0;
}
static int kvaser_usb_get_endpoints(const struct usb_interface *intf,
struct usb_endpoint_descriptor **in,
struct usb_endpoint_descriptor **out)
{
const struct usb_host_interface *iface_desc;
struct usb_endpoint_descriptor *endpoint;
int i;
iface_desc = &intf->altsetting[0];
for (i = 0; i < iface_desc->desc.bNumEndpoints; ++i) {
endpoint = &iface_desc->endpoint[i].desc;
if (!*in && usb_endpoint_is_bulk_in(endpoint))
*in = endpoint;
if (!*out && usb_endpoint_is_bulk_out(endpoint))
*out = endpoint;
if (*in && *out)
return 0;
}
return -ENODEV;
}
static int kvaser_usb_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
struct kvaser_usb *dev;
int err = -ENOMEM;
int i, retry = 3;
dev = devm_kzalloc(&intf->dev, sizeof(*dev), GFP_KERNEL);
if (!dev)
return -ENOMEM;
if (kvaser_is_leaf(id)) {
dev->family = KVASER_LEAF;
} else if (kvaser_is_usbcan(id)) {
dev->family = KVASER_USBCAN;
} else {
dev_err(&intf->dev,
"Product ID (%d) does not belong to any known Kvaser USB family",
id->idProduct);
return -ENODEV;
}
err = kvaser_usb_get_endpoints(intf, &dev->bulk_in, &dev->bulk_out);
if (err) {
dev_err(&intf->dev, "Cannot get usb endpoint(s)");
return err;
}
dev->udev = interface_to_usbdev(intf);
init_usb_anchor(&dev->rx_submitted);
usb_set_intfdata(intf, dev);
do {
err = kvaser_usb_get_software_info(dev);
} while (--retry && err == -ETIMEDOUT);
if (err) {
dev_err(&intf->dev,
"Cannot get software infos, error %d\n", err);
return err;
}
dev_dbg(&intf->dev, "Firmware version: %d.%d.%d\n",
((dev->fw_version >> 24) & 0xff),
((dev->fw_version >> 16) & 0xff),
(dev->fw_version & 0xffff));
dev_dbg(&intf->dev, "Max oustanding tx = %d URBs\n", dev->max_tx_urbs);
err = kvaser_usb_get_card_info(dev);
if (err) {
dev_err(&intf->dev,
"Cannot get card infos, error %d\n", err);
return err;
}
for (i = 0; i < dev->nchannels; i++) {
err = kvaser_usb_init_one(intf, id, i);
if (err) {
kvaser_usb_remove_interfaces(dev);
return err;
}
}
return 0;
}
static void kvaser_usb_disconnect(struct usb_interface *intf)
{
struct kvaser_usb *dev = usb_get_intfdata(intf);
usb_set_intfdata(intf, NULL);
if (!dev)
return;
kvaser_usb_remove_interfaces(dev);
}
