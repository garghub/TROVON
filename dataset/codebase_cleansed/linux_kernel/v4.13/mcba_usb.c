static inline void mcba_init_ctx(struct mcba_priv *priv)
{
int i = 0;
for (i = 0; i < MCBA_MAX_TX_URBS; i++) {
priv->tx_context[i].ndx = MCBA_CTX_FREE;
priv->tx_context[i].priv = priv;
}
atomic_set(&priv->free_ctx_cnt, ARRAY_SIZE(priv->tx_context));
}
static inline struct mcba_usb_ctx *mcba_usb_get_free_ctx(struct mcba_priv *priv,
struct can_frame *cf)
{
int i = 0;
struct mcba_usb_ctx *ctx = NULL;
for (i = 0; i < MCBA_MAX_TX_URBS; i++) {
if (priv->tx_context[i].ndx == MCBA_CTX_FREE) {
ctx = &priv->tx_context[i];
ctx->ndx = i;
if (cf) {
ctx->can = true;
ctx->dlc = cf->can_dlc;
} else {
ctx->can = false;
ctx->dlc = 0;
}
atomic_dec(&priv->free_ctx_cnt);
break;
}
}
if (!atomic_read(&priv->free_ctx_cnt))
netif_stop_queue(priv->netdev);
return ctx;
}
static inline void mcba_usb_free_ctx(struct mcba_usb_ctx *ctx)
{
atomic_inc(&ctx->priv->free_ctx_cnt);
ctx->ndx = MCBA_CTX_FREE;
netif_wake_queue(ctx->priv->netdev);
}
static void mcba_usb_write_bulk_callback(struct urb *urb)
{
struct mcba_usb_ctx *ctx = urb->context;
struct net_device *netdev;
WARN_ON(!ctx);
netdev = ctx->priv->netdev;
usb_free_coherent(urb->dev, urb->transfer_buffer_length,
urb->transfer_buffer, urb->transfer_dma);
if (ctx->can) {
if (!netif_device_present(netdev))
return;
netdev->stats.tx_packets++;
netdev->stats.tx_bytes += ctx->dlc;
can_led_event(netdev, CAN_LED_EVENT_TX);
can_get_echo_skb(netdev, ctx->ndx);
}
if (urb->status)
netdev_info(netdev, "Tx URB aborted (%d)\n", urb->status);
mcba_usb_free_ctx(ctx);
}
static netdev_tx_t mcba_usb_xmit(struct mcba_priv *priv,
struct mcba_usb_msg *usb_msg,
struct mcba_usb_ctx *ctx)
{
struct urb *urb;
u8 *buf;
int err;
urb = usb_alloc_urb(0, GFP_ATOMIC);
if (!urb)
return -ENOMEM;
buf = usb_alloc_coherent(priv->udev, MCBA_USB_TX_BUFF_SIZE, GFP_ATOMIC,
&urb->transfer_dma);
if (!buf) {
err = -ENOMEM;
goto nomembuf;
}
memcpy(buf, usb_msg, MCBA_USB_TX_BUFF_SIZE);
usb_fill_bulk_urb(urb, priv->udev,
usb_sndbulkpipe(priv->udev, MCBA_USB_EP_OUT), buf,
MCBA_USB_TX_BUFF_SIZE, mcba_usb_write_bulk_callback,
ctx);
urb->transfer_flags |= URB_NO_TRANSFER_DMA_MAP;
usb_anchor_urb(urb, &priv->tx_submitted);
err = usb_submit_urb(urb, GFP_ATOMIC);
if (unlikely(err))
goto failed;
usb_free_urb(urb);
return 0;
failed:
usb_unanchor_urb(urb);
usb_free_coherent(priv->udev, MCBA_USB_TX_BUFF_SIZE, buf,
urb->transfer_dma);
if (err == -ENODEV)
netif_device_detach(priv->netdev);
else
netdev_warn(priv->netdev, "failed tx_urb %d\n", err);
nomembuf:
usb_free_urb(urb);
return err;
}
static netdev_tx_t mcba_usb_start_xmit(struct sk_buff *skb,
struct net_device *netdev)
{
struct mcba_priv *priv = netdev_priv(netdev);
struct can_frame *cf = (struct can_frame *)skb->data;
struct mcba_usb_ctx *ctx = NULL;
struct net_device_stats *stats = &priv->netdev->stats;
u16 sid;
int err;
struct mcba_usb_msg_can usb_msg = {
.cmd_id = MBCA_CMD_TRANSMIT_MESSAGE_EV
};
if (can_dropped_invalid_skb(netdev, skb))
return NETDEV_TX_OK;
ctx = mcba_usb_get_free_ctx(priv, cf);
if (!ctx)
return NETDEV_TX_BUSY;
can_put_echo_skb(skb, priv->netdev, ctx->ndx);
if (cf->can_id & CAN_EFF_FLAG) {
sid = MCBA_SIDL_EXID_MASK;
sid |= (cf->can_id & 0x1ffc0000) >> 13;
sid |= (cf->can_id & 0x30000) >> 16;
put_unaligned_be16(sid, &usb_msg.sid);
put_unaligned_be16(cf->can_id & 0xffff, &usb_msg.eid);
} else {
put_unaligned_be16((cf->can_id & CAN_SFF_MASK) << 5,
&usb_msg.sid);
usb_msg.eid = 0;
}
usb_msg.dlc = cf->can_dlc;
memcpy(usb_msg.data, cf->data, usb_msg.dlc);
if (cf->can_id & CAN_RTR_FLAG)
usb_msg.dlc |= MCBA_DLC_RTR_MASK;
err = mcba_usb_xmit(priv, (struct mcba_usb_msg *)&usb_msg, ctx);
if (err)
goto xmit_failed;
return NETDEV_TX_OK;
xmit_failed:
can_free_echo_skb(priv->netdev, ctx->ndx);
mcba_usb_free_ctx(ctx);
dev_kfree_skb(skb);
stats->tx_dropped++;
return NETDEV_TX_OK;
}
static void mcba_usb_xmit_cmd(struct mcba_priv *priv,
struct mcba_usb_msg *usb_msg)
{
struct mcba_usb_ctx *ctx = NULL;
int err;
ctx = mcba_usb_get_free_ctx(priv, NULL);
if (!ctx) {
netdev_err(priv->netdev,
"Lack of free ctx. Sending (%d) cmd aborted",
usb_msg->cmd_id);
return;
}
err = mcba_usb_xmit(priv, usb_msg, ctx);
if (err)
netdev_err(priv->netdev, "Failed to send cmd (%d)",
usb_msg->cmd_id);
}
static void mcba_usb_xmit_change_bitrate(struct mcba_priv *priv, u16 bitrate)
{
struct mcba_usb_msg_change_bitrate usb_msg = {
.cmd_id = MBCA_CMD_CHANGE_BIT_RATE
};
put_unaligned_be16(bitrate, &usb_msg.bitrate);
mcba_usb_xmit_cmd(priv, (struct mcba_usb_msg *)&usb_msg);
}
static void mcba_usb_xmit_read_fw_ver(struct mcba_priv *priv, u8 pic)
{
struct mcba_usb_msg_fw_ver usb_msg = {
.cmd_id = MBCA_CMD_READ_FW_VERSION,
.pic = pic
};
mcba_usb_xmit_cmd(priv, (struct mcba_usb_msg *)&usb_msg);
}
static void mcba_usb_process_can(struct mcba_priv *priv,
struct mcba_usb_msg_can *msg)
{
struct can_frame *cf;
struct sk_buff *skb;
struct net_device_stats *stats = &priv->netdev->stats;
u16 sid;
skb = alloc_can_skb(priv->netdev, &cf);
if (!skb)
return;
sid = get_unaligned_be16(&msg->sid);
if (sid & MCBA_SIDL_EXID_MASK) {
cf->can_id = CAN_EFF_FLAG;
cf->can_id |= (sid & 0xffe0) << 13;
cf->can_id |= (sid & 3) << 16;
cf->can_id |= get_unaligned_be16(&msg->eid);
} else {
cf->can_id = (sid & 0xffe0) >> 5;
}
if (msg->dlc & MCBA_DLC_RTR_MASK)
cf->can_id |= CAN_RTR_FLAG;
cf->can_dlc = get_can_dlc(msg->dlc & MCBA_DLC_MASK);
memcpy(cf->data, msg->data, cf->can_dlc);
stats->rx_packets++;
stats->rx_bytes += cf->can_dlc;
can_led_event(priv->netdev, CAN_LED_EVENT_RX);
netif_rx(skb);
}
static void mcba_usb_process_ka_usb(struct mcba_priv *priv,
struct mcba_usb_msg_ka_usb *msg)
{
if (unlikely(priv->usb_ka_first_pass)) {
netdev_info(priv->netdev, "PIC USB version %hhu.%hhu\n",
msg->soft_ver_major, msg->soft_ver_minor);
priv->usb_ka_first_pass = false;
}
if (msg->termination_state)
priv->can.termination = MCBA_TERMINATION_ENABLED;
else
priv->can.termination = MCBA_TERMINATION_DISABLED;
}
static u32 convert_can2host_bitrate(struct mcba_usb_msg_ka_can *msg)
{
const u32 bitrate = get_unaligned_be16(&msg->can_bitrate);
if ((bitrate == 33) || (bitrate == 83))
return bitrate * 1000 + 333;
else
return bitrate * 1000;
}
static void mcba_usb_process_ka_can(struct mcba_priv *priv,
struct mcba_usb_msg_ka_can *msg)
{
if (unlikely(priv->can_ka_first_pass)) {
netdev_info(priv->netdev, "PIC CAN version %hhu.%hhu\n",
msg->soft_ver_major, msg->soft_ver_minor);
priv->can_ka_first_pass = false;
}
if (unlikely(priv->can_speed_check)) {
const u32 bitrate = convert_can2host_bitrate(msg);
priv->can_speed_check = false;
if (bitrate != priv->can.bittiming.bitrate)
netdev_err(
priv->netdev,
"Wrong bitrate reported by the device (%u). Expected %u",
bitrate, priv->can.bittiming.bitrate);
}
priv->bec.txerr = msg->tx_err_cnt;
priv->bec.rxerr = msg->rx_err_cnt;
if (msg->tx_bus_off)
priv->can.state = CAN_STATE_BUS_OFF;
else if ((priv->bec.txerr > MCBA_CAN_STATE_ERR_PSV_TH) ||
(priv->bec.rxerr > MCBA_CAN_STATE_ERR_PSV_TH))
priv->can.state = CAN_STATE_ERROR_PASSIVE;
else if ((priv->bec.txerr > MCBA_CAN_STATE_WRN_TH) ||
(priv->bec.rxerr > MCBA_CAN_STATE_WRN_TH))
priv->can.state = CAN_STATE_ERROR_WARNING;
}
static void mcba_usb_process_rx(struct mcba_priv *priv,
struct mcba_usb_msg *msg)
{
switch (msg->cmd_id) {
case MBCA_CMD_I_AM_ALIVE_FROM_CAN:
mcba_usb_process_ka_can(priv,
(struct mcba_usb_msg_ka_can *)msg);
break;
case MBCA_CMD_I_AM_ALIVE_FROM_USB:
mcba_usb_process_ka_usb(priv,
(struct mcba_usb_msg_ka_usb *)msg);
break;
case MBCA_CMD_RECEIVE_MESSAGE:
mcba_usb_process_can(priv, (struct mcba_usb_msg_can *)msg);
break;
case MBCA_CMD_NOTHING_TO_SEND:
break;
case MBCA_CMD_TRANSMIT_MESSAGE_RSP:
break;
default:
netdev_warn(priv->netdev, "Unsupported msg (0x%hhX)",
msg->cmd_id);
break;
}
}
static void mcba_usb_read_bulk_callback(struct urb *urb)
{
struct mcba_priv *priv = urb->context;
struct net_device *netdev;
int retval;
int pos = 0;
netdev = priv->netdev;
if (!netif_device_present(netdev))
return;
switch (urb->status) {
case 0:
break;
case -ENOENT:
case -ESHUTDOWN:
return;
default:
netdev_info(netdev, "Rx URB aborted (%d)\n", urb->status);
goto resubmit_urb;
}
while (pos < urb->actual_length) {
struct mcba_usb_msg *msg;
if (pos + sizeof(struct mcba_usb_msg) > urb->actual_length) {
netdev_err(priv->netdev, "format error\n");
break;
}
msg = (struct mcba_usb_msg *)(urb->transfer_buffer + pos);
mcba_usb_process_rx(priv, msg);
pos += sizeof(struct mcba_usb_msg);
}
resubmit_urb:
usb_fill_bulk_urb(urb, priv->udev,
usb_rcvbulkpipe(priv->udev, MCBA_USB_EP_OUT),
urb->transfer_buffer, MCBA_USB_RX_BUFF_SIZE,
mcba_usb_read_bulk_callback, priv);
retval = usb_submit_urb(urb, GFP_ATOMIC);
if (retval == -ENODEV)
netif_device_detach(netdev);
else if (retval)
netdev_err(netdev, "failed resubmitting read bulk urb: %d\n",
retval);
}
static int mcba_usb_start(struct mcba_priv *priv)
{
struct net_device *netdev = priv->netdev;
int err, i;
mcba_init_ctx(priv);
for (i = 0; i < MCBA_MAX_RX_URBS; i++) {
struct urb *urb = NULL;
u8 *buf;
urb = usb_alloc_urb(0, GFP_KERNEL);
if (!urb) {
err = -ENOMEM;
break;
}
buf = usb_alloc_coherent(priv->udev, MCBA_USB_RX_BUFF_SIZE,
GFP_KERNEL, &urb->transfer_dma);
if (!buf) {
netdev_err(netdev, "No memory left for USB buffer\n");
usb_free_urb(urb);
err = -ENOMEM;
break;
}
usb_fill_bulk_urb(urb, priv->udev,
usb_rcvbulkpipe(priv->udev, MCBA_USB_EP_IN),
buf, MCBA_USB_RX_BUFF_SIZE,
mcba_usb_read_bulk_callback, priv);
urb->transfer_flags |= URB_NO_TRANSFER_DMA_MAP;
usb_anchor_urb(urb, &priv->rx_submitted);
err = usb_submit_urb(urb, GFP_KERNEL);
if (err) {
usb_unanchor_urb(urb);
usb_free_coherent(priv->udev, MCBA_USB_RX_BUFF_SIZE,
buf, urb->transfer_dma);
usb_free_urb(urb);
break;
}
usb_free_urb(urb);
}
if (i == 0) {
netdev_warn(netdev, "couldn't setup read URBs\n");
return err;
}
if (i < MCBA_MAX_RX_URBS)
netdev_warn(netdev, "rx performance may be slow\n");
mcba_usb_xmit_read_fw_ver(priv, MCBA_VER_REQ_USB);
mcba_usb_xmit_read_fw_ver(priv, MCBA_VER_REQ_CAN);
return err;
}
static int mcba_usb_open(struct net_device *netdev)
{
struct mcba_priv *priv = netdev_priv(netdev);
int err;
err = open_candev(netdev);
if (err)
return err;
priv->can_speed_check = true;
priv->can.state = CAN_STATE_ERROR_ACTIVE;
can_led_event(netdev, CAN_LED_EVENT_OPEN);
netif_start_queue(netdev);
return 0;
}
static void mcba_urb_unlink(struct mcba_priv *priv)
{
usb_kill_anchored_urbs(&priv->rx_submitted);
usb_kill_anchored_urbs(&priv->tx_submitted);
}
static int mcba_usb_close(struct net_device *netdev)
{
struct mcba_priv *priv = netdev_priv(netdev);
priv->can.state = CAN_STATE_STOPPED;
netif_stop_queue(netdev);
mcba_urb_unlink(priv);
close_candev(netdev);
can_led_event(netdev, CAN_LED_EVENT_STOP);
return 0;
}
static int mcba_net_set_mode(struct net_device *netdev, enum can_mode mode)
{
return 0;
}
static int mcba_net_get_berr_counter(const struct net_device *netdev,
struct can_berr_counter *bec)
{
struct mcba_priv *priv = netdev_priv(netdev);
bec->txerr = priv->bec.txerr;
bec->rxerr = priv->bec.rxerr;
return 0;
}
static int mcba_net_set_bittiming(struct net_device *netdev)
{
struct mcba_priv *priv = netdev_priv(netdev);
const u16 bitrate_kbps = priv->can.bittiming.bitrate / 1000;
mcba_usb_xmit_change_bitrate(priv, bitrate_kbps);
return 0;
}
static int mcba_set_termination(struct net_device *netdev, u16 term)
{
struct mcba_priv *priv = netdev_priv(netdev);
struct mcba_usb_msg_termination usb_msg = {
.cmd_id = MBCA_CMD_SETUP_TERMINATION_RESISTANCE
};
if (term == MCBA_TERMINATION_ENABLED)
usb_msg.termination = 1;
else
usb_msg.termination = 0;
mcba_usb_xmit_cmd(priv, (struct mcba_usb_msg *)&usb_msg);
return 0;
}
static int mcba_usb_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
struct net_device *netdev;
struct mcba_priv *priv;
int err = -ENOMEM;
struct usb_device *usbdev = interface_to_usbdev(intf);
netdev = alloc_candev(sizeof(struct mcba_priv), MCBA_MAX_TX_URBS);
if (!netdev) {
dev_err(&intf->dev, "Couldn't alloc candev\n");
return -ENOMEM;
}
priv = netdev_priv(netdev);
priv->udev = usbdev;
priv->netdev = netdev;
priv->usb_ka_first_pass = true;
priv->can_ka_first_pass = true;
priv->can_speed_check = false;
init_usb_anchor(&priv->rx_submitted);
init_usb_anchor(&priv->tx_submitted);
usb_set_intfdata(intf, priv);
priv->can.state = CAN_STATE_STOPPED;
priv->can.termination_const = mcba_termination;
priv->can.termination_const_cnt = ARRAY_SIZE(mcba_termination);
priv->can.bitrate_const = mcba_bitrate;
priv->can.bitrate_const_cnt = ARRAY_SIZE(mcba_bitrate);
priv->can.do_set_termination = mcba_set_termination;
priv->can.do_set_mode = mcba_net_set_mode;
priv->can.do_get_berr_counter = mcba_net_get_berr_counter;
priv->can.do_set_bittiming = mcba_net_set_bittiming;
netdev->netdev_ops = &mcba_netdev_ops;
netdev->flags |= IFF_ECHO;
SET_NETDEV_DEV(netdev, &intf->dev);
err = register_candev(netdev);
if (err) {
netdev_err(netdev, "couldn't register CAN device: %d\n", err);
goto cleanup_free_candev;
}
devm_can_led_init(netdev);
err = mcba_usb_start(priv);
if (err) {
if (err == -ENODEV)
netif_device_detach(priv->netdev);
netdev_warn(netdev, "couldn't start device: %d\n", err);
goto cleanup_unregister_candev;
}
dev_info(&intf->dev, "Microchip CAN BUS analizer connected\n");
return 0;
cleanup_unregister_candev:
unregister_candev(priv->netdev);
cleanup_free_candev:
free_candev(netdev);
return err;
}
static void mcba_usb_disconnect(struct usb_interface *intf)
{
struct mcba_priv *priv = usb_get_intfdata(intf);
usb_set_intfdata(intf, NULL);
netdev_info(priv->netdev, "device disconnected\n");
unregister_candev(priv->netdev);
free_candev(priv->netdev);
mcba_urb_unlink(priv);
}
