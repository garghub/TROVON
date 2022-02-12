static int usb_8dev_send_cmd_msg(struct usb_8dev_priv *priv, u8 *msg, int size)
{
int actual_length;
return usb_bulk_msg(priv->udev,
usb_sndbulkpipe(priv->udev, USB_8DEV_ENDP_CMD_TX),
msg, size, &actual_length, USB_8DEV_CMD_TIMEOUT);
}
static int usb_8dev_wait_cmd_msg(struct usb_8dev_priv *priv, u8 *msg, int size,
int *actual_length)
{
return usb_bulk_msg(priv->udev,
usb_rcvbulkpipe(priv->udev, USB_8DEV_ENDP_CMD_RX),
msg, size, actual_length, USB_8DEV_CMD_TIMEOUT);
}
static int usb_8dev_send_cmd(struct usb_8dev_priv *priv,
struct usb_8dev_cmd_msg *out,
struct usb_8dev_cmd_msg *in)
{
int err;
int num_bytes_read;
struct net_device *netdev;
netdev = priv->netdev;
out->begin = USB_8DEV_CMD_START;
out->end = USB_8DEV_CMD_END;
mutex_lock(&priv->usb_8dev_cmd_lock);
memcpy(priv->cmd_msg_buffer, out,
sizeof(struct usb_8dev_cmd_msg));
err = usb_8dev_send_cmd_msg(priv, priv->cmd_msg_buffer,
sizeof(struct usb_8dev_cmd_msg));
if (err < 0) {
netdev_err(netdev, "sending command message failed\n");
goto failed;
}
err = usb_8dev_wait_cmd_msg(priv, priv->cmd_msg_buffer,
sizeof(struct usb_8dev_cmd_msg),
&num_bytes_read);
if (err < 0) {
netdev_err(netdev, "no command message answer\n");
goto failed;
}
memcpy(in, priv->cmd_msg_buffer, sizeof(struct usb_8dev_cmd_msg));
if (in->begin != USB_8DEV_CMD_START || in->end != USB_8DEV_CMD_END ||
num_bytes_read != 16 || in->opt1 != 0)
err = -EPROTO;
failed:
mutex_unlock(&priv->usb_8dev_cmd_lock);
return err;
}
static int usb_8dev_cmd_open(struct usb_8dev_priv *priv)
{
struct can_bittiming *bt = &priv->can.bittiming;
struct usb_8dev_cmd_msg outmsg;
struct usb_8dev_cmd_msg inmsg;
u32 ctrlmode = priv->can.ctrlmode;
u32 flags = USB_8DEV_STATUS_FRAME;
__be32 beflags;
__be16 bebrp;
memset(&outmsg, 0, sizeof(outmsg));
outmsg.command = USB_8DEV_OPEN;
outmsg.opt1 = USB_8DEV_BAUD_MANUAL;
outmsg.data[0] = bt->prop_seg + bt->phase_seg1;
outmsg.data[1] = bt->phase_seg2;
outmsg.data[2] = bt->sjw;
bebrp = cpu_to_be16((u16)bt->brp);
memcpy(&outmsg.data[3], &bebrp, sizeof(bebrp));
if (ctrlmode & CAN_CTRLMODE_LOOPBACK)
flags |= USB_8DEV_LOOPBACK;
if (ctrlmode & CAN_CTRLMODE_LISTENONLY)
flags |= USB_8DEV_SILENT;
if (ctrlmode & CAN_CTRLMODE_ONE_SHOT)
flags |= USB_8DEV_DISABLE_AUTO_RESTRANS;
beflags = cpu_to_be32(flags);
memcpy(&outmsg.data[5], &beflags, sizeof(beflags));
return usb_8dev_send_cmd(priv, &outmsg, &inmsg);
}
static int usb_8dev_cmd_close(struct usb_8dev_priv *priv)
{
struct usb_8dev_cmd_msg inmsg;
struct usb_8dev_cmd_msg outmsg = {
.channel = 0,
.command = USB_8DEV_CLOSE,
.opt1 = 0,
.opt2 = 0
};
return usb_8dev_send_cmd(priv, &outmsg, &inmsg);
}
static int usb_8dev_cmd_version(struct usb_8dev_priv *priv, u32 *res)
{
struct usb_8dev_cmd_msg inmsg;
struct usb_8dev_cmd_msg outmsg = {
.channel = 0,
.command = USB_8DEV_GET_SOFTW_HARDW_VER,
.opt1 = 0,
.opt2 = 0
};
int err = usb_8dev_send_cmd(priv, &outmsg, &inmsg);
if (err)
return err;
*res = be32_to_cpup((__be32 *)inmsg.data);
return err;
}
static int usb_8dev_set_mode(struct net_device *netdev, enum can_mode mode)
{
struct usb_8dev_priv *priv = netdev_priv(netdev);
int err = 0;
switch (mode) {
case CAN_MODE_START:
err = usb_8dev_cmd_open(priv);
if (err)
netdev_warn(netdev, "couldn't start device");
break;
default:
return -EOPNOTSUPP;
}
return err;
}
static void usb_8dev_rx_err_msg(struct usb_8dev_priv *priv,
struct usb_8dev_rx_msg *msg)
{
struct can_frame *cf;
struct sk_buff *skb;
struct net_device_stats *stats = &priv->netdev->stats;
u8 state = msg->data[0];
u8 rxerr = msg->data[1] & USB_8DEV_RP_MASK;
u8 txerr = msg->data[2];
int rx_errors = 0;
int tx_errors = 0;
skb = alloc_can_err_skb(priv->netdev, &cf);
if (!skb)
return;
switch (state) {
case USB_8DEV_STATUSMSG_OK:
priv->can.state = CAN_STATE_ERROR_ACTIVE;
cf->can_id |= CAN_ERR_PROT;
cf->data[2] = CAN_ERR_PROT_ACTIVE;
break;
case USB_8DEV_STATUSMSG_BUSOFF:
priv->can.state = CAN_STATE_BUS_OFF;
cf->can_id |= CAN_ERR_BUSOFF;
can_bus_off(priv->netdev);
break;
case USB_8DEV_STATUSMSG_OVERRUN:
case USB_8DEV_STATUSMSG_BUSLIGHT:
case USB_8DEV_STATUSMSG_BUSHEAVY:
cf->can_id |= CAN_ERR_CRTL;
break;
default:
priv->can.state = CAN_STATE_ERROR_WARNING;
cf->can_id |= CAN_ERR_PROT | CAN_ERR_BUSERROR;
priv->can.can_stats.bus_error++;
break;
}
switch (state) {
case USB_8DEV_STATUSMSG_OK:
case USB_8DEV_STATUSMSG_BUSOFF:
break;
case USB_8DEV_STATUSMSG_ACK:
cf->can_id |= CAN_ERR_ACK;
tx_errors = 1;
break;
case USB_8DEV_STATUSMSG_CRC:
cf->data[2] |= CAN_ERR_PROT_UNSPEC;
cf->data[3] |= CAN_ERR_PROT_LOC_CRC_SEQ |
CAN_ERR_PROT_LOC_CRC_DEL;
rx_errors = 1;
break;
case USB_8DEV_STATUSMSG_BIT0:
cf->data[2] |= CAN_ERR_PROT_BIT0;
tx_errors = 1;
break;
case USB_8DEV_STATUSMSG_BIT1:
cf->data[2] |= CAN_ERR_PROT_BIT1;
tx_errors = 1;
break;
case USB_8DEV_STATUSMSG_FORM:
cf->data[2] |= CAN_ERR_PROT_FORM;
rx_errors = 1;
break;
case USB_8DEV_STATUSMSG_STUFF:
cf->data[2] |= CAN_ERR_PROT_STUFF;
rx_errors = 1;
break;
case USB_8DEV_STATUSMSG_OVERRUN:
cf->data[1] = CAN_ERR_CRTL_RX_OVERFLOW;
stats->rx_over_errors++;
rx_errors = 1;
break;
case USB_8DEV_STATUSMSG_BUSLIGHT:
priv->can.state = CAN_STATE_ERROR_WARNING;
cf->data[1] = (txerr > rxerr) ?
CAN_ERR_CRTL_TX_WARNING :
CAN_ERR_CRTL_RX_WARNING;
priv->can.can_stats.error_warning++;
break;
case USB_8DEV_STATUSMSG_BUSHEAVY:
priv->can.state = CAN_STATE_ERROR_PASSIVE;
cf->data[1] = (txerr > rxerr) ?
CAN_ERR_CRTL_TX_PASSIVE :
CAN_ERR_CRTL_RX_PASSIVE;
priv->can.can_stats.error_passive++;
break;
default:
netdev_warn(priv->netdev,
"Unknown status/error message (%d)\n", state);
break;
}
if (tx_errors) {
cf->data[2] |= CAN_ERR_PROT_TX;
stats->tx_errors++;
}
if (rx_errors)
stats->rx_errors++;
cf->data[6] = txerr;
cf->data[7] = rxerr;
priv->bec.txerr = txerr;
priv->bec.rxerr = rxerr;
netif_rx(skb);
stats->rx_packets++;
stats->rx_bytes += cf->can_dlc;
}
static void usb_8dev_rx_can_msg(struct usb_8dev_priv *priv,
struct usb_8dev_rx_msg *msg)
{
struct can_frame *cf;
struct sk_buff *skb;
struct net_device_stats *stats = &priv->netdev->stats;
if (msg->type == USB_8DEV_TYPE_ERROR_FRAME &&
msg->flags == USB_8DEV_ERR_FLAG) {
usb_8dev_rx_err_msg(priv, msg);
} else if (msg->type == USB_8DEV_TYPE_CAN_FRAME) {
skb = alloc_can_skb(priv->netdev, &cf);
if (!skb)
return;
cf->can_id = be32_to_cpu(msg->id);
cf->can_dlc = get_can_dlc(msg->dlc & 0xF);
if (msg->flags & USB_8DEV_EXTID)
cf->can_id |= CAN_EFF_FLAG;
if (msg->flags & USB_8DEV_RTR)
cf->can_id |= CAN_RTR_FLAG;
else
memcpy(cf->data, msg->data, cf->can_dlc);
netif_rx(skb);
stats->rx_packets++;
stats->rx_bytes += cf->can_dlc;
can_led_event(priv->netdev, CAN_LED_EVENT_RX);
} else {
netdev_warn(priv->netdev, "frame type %d unknown",
msg->type);
}
}
static void usb_8dev_read_bulk_callback(struct urb *urb)
{
struct usb_8dev_priv *priv = urb->context;
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
netdev_info(netdev, "Rx URB aborted (%d)\n",
urb->status);
goto resubmit_urb;
}
while (pos < urb->actual_length) {
struct usb_8dev_rx_msg *msg;
if (pos + sizeof(struct usb_8dev_rx_msg) > urb->actual_length) {
netdev_err(priv->netdev, "format error\n");
break;
}
msg = (struct usb_8dev_rx_msg *)(urb->transfer_buffer + pos);
usb_8dev_rx_can_msg(priv, msg);
pos += sizeof(struct usb_8dev_rx_msg);
}
resubmit_urb:
usb_fill_bulk_urb(urb, priv->udev,
usb_rcvbulkpipe(priv->udev, USB_8DEV_ENDP_DATA_RX),
urb->transfer_buffer, RX_BUFFER_SIZE,
usb_8dev_read_bulk_callback, priv);
retval = usb_submit_urb(urb, GFP_ATOMIC);
if (retval == -ENODEV)
netif_device_detach(netdev);
else if (retval)
netdev_err(netdev,
"failed resubmitting read bulk urb: %d\n", retval);
}
static void usb_8dev_write_bulk_callback(struct urb *urb)
{
struct usb_8dev_tx_urb_context *context = urb->context;
struct usb_8dev_priv *priv;
struct net_device *netdev;
BUG_ON(!context);
priv = context->priv;
netdev = priv->netdev;
usb_free_coherent(urb->dev, urb->transfer_buffer_length,
urb->transfer_buffer, urb->transfer_dma);
atomic_dec(&priv->active_tx_urbs);
if (!netif_device_present(netdev))
return;
if (urb->status)
netdev_info(netdev, "Tx URB aborted (%d)\n",
urb->status);
netdev->stats.tx_packets++;
netdev->stats.tx_bytes += context->dlc;
can_get_echo_skb(netdev, context->echo_index);
can_led_event(netdev, CAN_LED_EVENT_TX);
context->echo_index = MAX_TX_URBS;
netif_wake_queue(netdev);
}
static netdev_tx_t usb_8dev_start_xmit(struct sk_buff *skb,
struct net_device *netdev)
{
struct usb_8dev_priv *priv = netdev_priv(netdev);
struct net_device_stats *stats = &netdev->stats;
struct can_frame *cf = (struct can_frame *) skb->data;
struct usb_8dev_tx_msg *msg;
struct urb *urb;
struct usb_8dev_tx_urb_context *context = NULL;
u8 *buf;
int i, err;
size_t size = sizeof(struct usb_8dev_tx_msg);
if (can_dropped_invalid_skb(netdev, skb))
return NETDEV_TX_OK;
urb = usb_alloc_urb(0, GFP_ATOMIC);
if (!urb) {
netdev_err(netdev, "No memory left for URBs\n");
goto nomem;
}
buf = usb_alloc_coherent(priv->udev, size, GFP_ATOMIC,
&urb->transfer_dma);
if (!buf) {
netdev_err(netdev, "No memory left for USB buffer\n");
goto nomembuf;
}
memset(buf, 0, size);
msg = (struct usb_8dev_tx_msg *)buf;
msg->begin = USB_8DEV_DATA_START;
msg->flags = 0x00;
if (cf->can_id & CAN_RTR_FLAG)
msg->flags |= USB_8DEV_RTR;
if (cf->can_id & CAN_EFF_FLAG)
msg->flags |= USB_8DEV_EXTID;
msg->id = cpu_to_be32(cf->can_id & CAN_ERR_MASK);
msg->dlc = cf->can_dlc;
memcpy(msg->data, cf->data, cf->can_dlc);
msg->end = USB_8DEV_DATA_END;
for (i = 0; i < MAX_TX_URBS; i++) {
if (priv->tx_contexts[i].echo_index == MAX_TX_URBS) {
context = &priv->tx_contexts[i];
break;
}
}
if (!context)
goto nofreecontext;
context->priv = priv;
context->echo_index = i;
context->dlc = cf->can_dlc;
usb_fill_bulk_urb(urb, priv->udev,
usb_sndbulkpipe(priv->udev, USB_8DEV_ENDP_DATA_TX),
buf, size, usb_8dev_write_bulk_callback, context);
urb->transfer_flags |= URB_NO_TRANSFER_DMA_MAP;
usb_anchor_urb(urb, &priv->tx_submitted);
can_put_echo_skb(skb, netdev, context->echo_index);
atomic_inc(&priv->active_tx_urbs);
err = usb_submit_urb(urb, GFP_ATOMIC);
if (unlikely(err))
goto failed;
else if (atomic_read(&priv->active_tx_urbs) >= MAX_TX_URBS)
netif_stop_queue(netdev);
usb_free_urb(urb);
return NETDEV_TX_OK;
nofreecontext:
usb_free_coherent(priv->udev, size, buf, urb->transfer_dma);
usb_free_urb(urb);
netdev_warn(netdev, "couldn't find free context");
return NETDEV_TX_BUSY;
failed:
can_free_echo_skb(netdev, context->echo_index);
usb_unanchor_urb(urb);
usb_free_coherent(priv->udev, size, buf, urb->transfer_dma);
atomic_dec(&priv->active_tx_urbs);
if (err == -ENODEV)
netif_device_detach(netdev);
else
netdev_warn(netdev, "failed tx_urb %d\n", err);
nomembuf:
usb_free_urb(urb);
nomem:
dev_kfree_skb(skb);
stats->tx_dropped++;
return NETDEV_TX_OK;
}
static int usb_8dev_get_berr_counter(const struct net_device *netdev,
struct can_berr_counter *bec)
{
struct usb_8dev_priv *priv = netdev_priv(netdev);
bec->txerr = priv->bec.txerr;
bec->rxerr = priv->bec.rxerr;
return 0;
}
static int usb_8dev_start(struct usb_8dev_priv *priv)
{
struct net_device *netdev = priv->netdev;
int err, i;
for (i = 0; i < MAX_RX_URBS; i++) {
struct urb *urb = NULL;
u8 *buf;
urb = usb_alloc_urb(0, GFP_KERNEL);
if (!urb) {
netdev_err(netdev, "No memory left for URBs\n");
err = -ENOMEM;
break;
}
buf = usb_alloc_coherent(priv->udev, RX_BUFFER_SIZE, GFP_KERNEL,
&urb->transfer_dma);
if (!buf) {
netdev_err(netdev, "No memory left for USB buffer\n");
usb_free_urb(urb);
err = -ENOMEM;
break;
}
usb_fill_bulk_urb(urb, priv->udev,
usb_rcvbulkpipe(priv->udev,
USB_8DEV_ENDP_DATA_RX),
buf, RX_BUFFER_SIZE,
usb_8dev_read_bulk_callback, priv);
urb->transfer_flags |= URB_NO_TRANSFER_DMA_MAP;
usb_anchor_urb(urb, &priv->rx_submitted);
err = usb_submit_urb(urb, GFP_KERNEL);
if (err) {
usb_unanchor_urb(urb);
usb_free_coherent(priv->udev, RX_BUFFER_SIZE, buf,
urb->transfer_dma);
usb_free_urb(urb);
break;
}
usb_free_urb(urb);
}
if (i == 0) {
netdev_warn(netdev, "couldn't setup read URBs\n");
return err;
}
if (i < MAX_RX_URBS)
netdev_warn(netdev, "rx performance may be slow\n");
err = usb_8dev_cmd_open(priv);
if (err)
goto failed;
priv->can.state = CAN_STATE_ERROR_ACTIVE;
return 0;
failed:
if (err == -ENODEV)
netif_device_detach(priv->netdev);
netdev_warn(netdev, "couldn't submit control: %d\n", err);
return err;
}
static int usb_8dev_open(struct net_device *netdev)
{
struct usb_8dev_priv *priv = netdev_priv(netdev);
int err;
err = open_candev(netdev);
if (err)
return err;
can_led_event(netdev, CAN_LED_EVENT_OPEN);
err = usb_8dev_start(priv);
if (err) {
if (err == -ENODEV)
netif_device_detach(priv->netdev);
netdev_warn(netdev, "couldn't start device: %d\n",
err);
close_candev(netdev);
return err;
}
netif_start_queue(netdev);
return 0;
}
static void unlink_all_urbs(struct usb_8dev_priv *priv)
{
int i;
usb_kill_anchored_urbs(&priv->rx_submitted);
usb_kill_anchored_urbs(&priv->tx_submitted);
atomic_set(&priv->active_tx_urbs, 0);
for (i = 0; i < MAX_TX_URBS; i++)
priv->tx_contexts[i].echo_index = MAX_TX_URBS;
}
static int usb_8dev_close(struct net_device *netdev)
{
struct usb_8dev_priv *priv = netdev_priv(netdev);
int err = 0;
err = usb_8dev_cmd_close(priv);
if (err)
netdev_warn(netdev, "couldn't stop device");
priv->can.state = CAN_STATE_STOPPED;
netif_stop_queue(netdev);
unlink_all_urbs(priv);
close_candev(netdev);
can_led_event(netdev, CAN_LED_EVENT_STOP);
return err;
}
static int usb_8dev_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
struct net_device *netdev;
struct usb_8dev_priv *priv;
int i, err = -ENOMEM;
u32 version;
char buf[18];
struct usb_device *usbdev = interface_to_usbdev(intf);
if (usb_string(usbdev, usbdev->descriptor.iProduct, buf,
sizeof(buf)) > 0 && strcmp(buf, "USB2CAN converter")) {
dev_info(&usbdev->dev, "ignoring: not an USB2CAN converter\n");
return -ENODEV;
}
netdev = alloc_candev(sizeof(struct usb_8dev_priv), MAX_TX_URBS);
if (!netdev) {
dev_err(&intf->dev, "Couldn't alloc candev\n");
return -ENOMEM;
}
priv = netdev_priv(netdev);
priv->udev = usbdev;
priv->netdev = netdev;
priv->can.state = CAN_STATE_STOPPED;
priv->can.clock.freq = USB_8DEV_ABP_CLOCK;
priv->can.bittiming_const = &usb_8dev_bittiming_const;
priv->can.do_set_mode = usb_8dev_set_mode;
priv->can.do_get_berr_counter = usb_8dev_get_berr_counter;
priv->can.ctrlmode_supported = CAN_CTRLMODE_LOOPBACK |
CAN_CTRLMODE_LISTENONLY |
CAN_CTRLMODE_ONE_SHOT;
netdev->netdev_ops = &usb_8dev_netdev_ops;
netdev->flags |= IFF_ECHO;
init_usb_anchor(&priv->rx_submitted);
init_usb_anchor(&priv->tx_submitted);
atomic_set(&priv->active_tx_urbs, 0);
for (i = 0; i < MAX_TX_URBS; i++)
priv->tx_contexts[i].echo_index = MAX_TX_URBS;
priv->cmd_msg_buffer = kzalloc(sizeof(struct usb_8dev_cmd_msg),
GFP_KERNEL);
if (!priv->cmd_msg_buffer)
goto cleanup_candev;
usb_set_intfdata(intf, priv);
SET_NETDEV_DEV(netdev, &intf->dev);
mutex_init(&priv->usb_8dev_cmd_lock);
err = register_candev(netdev);
if (err) {
netdev_err(netdev,
"couldn't register CAN device: %d\n", err);
goto cleanup_cmd_msg_buffer;
}
err = usb_8dev_cmd_version(priv, &version);
if (err) {
netdev_err(netdev, "can't get firmware version\n");
goto cleanup_unregister_candev;
} else {
netdev_info(netdev,
"firmware: %d.%d, hardware: %d.%d\n",
(version>>24) & 0xff, (version>>16) & 0xff,
(version>>8) & 0xff, version & 0xff);
}
devm_can_led_init(netdev);
return 0;
cleanup_unregister_candev:
unregister_netdev(priv->netdev);
cleanup_cmd_msg_buffer:
kfree(priv->cmd_msg_buffer);
cleanup_candev:
free_candev(netdev);
return err;
}
static void usb_8dev_disconnect(struct usb_interface *intf)
{
struct usb_8dev_priv *priv = usb_get_intfdata(intf);
usb_set_intfdata(intf, NULL);
if (priv) {
netdev_info(priv->netdev, "device disconnected\n");
unregister_netdev(priv->netdev);
free_candev(priv->netdev);
unlink_all_urbs(priv);
}
}
