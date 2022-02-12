static inline struct sierra_net_data *sierra_net_get_private(struct usbnet *dev)
{
return (struct sierra_net_data *)dev->data[0];
}
static inline void sierra_net_set_private(struct usbnet *dev,
struct sierra_net_data *priv)
{
dev->data[0] = (unsigned long)priv;
}
static inline int is_ip(struct sk_buff *skb)
{
return skb->protocol == cpu_to_be16(ETH_P_IP) ||
skb->protocol == cpu_to_be16(ETH_P_IPV6);
}
static int check_ethip_packet(struct sk_buff *skb, struct usbnet *dev)
{
skb_reset_mac_header(skb);
if (skb_is_nonlinear(skb)) {
netdev_err(dev->net, "Non linear buffer-dropping\n");
return 0;
}
if (!pskb_may_pull(skb, ETH_HLEN))
return 0;
skb->protocol = eth_hdr(skb)->h_proto;
return 1;
}
static const u8 *save16bit(struct param *p, const u8 *datap)
{
p->is_present = 1;
p->word = get_unaligned_be16(datap);
return datap + sizeof(p->word);
}
static const u8 *save8bit(struct param *p, const u8 *datap)
{
p->is_present = 1;
p->byte = *datap;
return datap + sizeof(p->byte);
}
static int parse_hip(const u8 *buf, const u32 buflen, struct hip_hdr *hh)
{
const u8 *curp = buf;
int padded;
if (buflen < SIERRA_NET_HIP_HDR_LEN)
return -EPROTO;
curp = save16bit(&hh->payload_len, curp);
curp = save8bit(&hh->msgid, curp);
curp = save8bit(&hh->msgspecific, curp);
padded = hh->msgid.byte & 0x80;
hh->msgid.byte &= 0x7F;
hh->extmsgid.is_present = (hh->msgid.byte == SIERRA_NET_HIP_EXTENDEDID);
if (hh->extmsgid.is_present) {
if (buflen < SIERRA_NET_HIP_EXT_HDR_LEN)
return -EPROTO;
hh->payload_len.word &= 0x3FFF;
curp = save16bit(&hh->extmsgid, curp);
hh->extmsgid.word &= 0x03FF;
hh->hdrlen = SIERRA_NET_HIP_EXT_HDR_LEN;
} else {
hh->payload_len.word &= 0x07FF;
hh->hdrlen = SIERRA_NET_HIP_HDR_LEN;
}
if (padded) {
hh->hdrlen++;
hh->payload_len.word--;
}
if (buflen < (hh->hdrlen + hh->payload_len.word))
return -EINVAL;
return 0;
}
static void build_hip(u8 *buf, const u16 payloadlen,
struct sierra_net_data *priv)
{
put_unaligned_be16(payloadlen, buf);
memcpy(buf+2, priv->tx_hdr_template, sizeof(priv->tx_hdr_template));
}
static int sierra_net_send_cmd(struct usbnet *dev,
u8 *cmd, int cmdlen, const char * cmd_name)
{
struct sierra_net_data *priv = sierra_net_get_private(dev);
int status;
status = usbnet_write_cmd(dev, USB_CDC_SEND_ENCAPSULATED_COMMAND,
USB_DIR_OUT|USB_TYPE_CLASS|USB_RECIP_INTERFACE,
0, priv->ifnum, cmd, cmdlen);
if (status != cmdlen && status != -ENODEV)
netdev_err(dev->net, "Submit %s failed %d\n", cmd_name, status);
return status;
}
static int sierra_net_send_sync(struct usbnet *dev)
{
int status;
struct sierra_net_data *priv = sierra_net_get_private(dev);
dev_dbg(&dev->udev->dev, "%s", __func__);
status = sierra_net_send_cmd(dev, priv->sync_msg,
sizeof(priv->sync_msg), "SYNC");
return status;
}
static void sierra_net_set_ctx_index(struct sierra_net_data *priv, u8 ctx_ix)
{
dev_dbg(&(priv->usbnet->udev->dev), "%s %d", __func__, ctx_ix);
priv->tx_hdr_template[0] = 0x3F;
priv->tx_hdr_template[1] = ctx_ix;
*((__be16 *)&priv->tx_hdr_template[2]) =
cpu_to_be16(SIERRA_NET_HIP_EXT_IP_OUT_ID);
}
static inline int sierra_net_is_valid_addrlen(u8 len)
{
return len == sizeof(struct in_addr);
}
static int sierra_net_parse_lsi(struct usbnet *dev, char *data, int datalen)
{
struct lsi_umts *lsi = (struct lsi_umts *)data;
u32 expected_length;
if (datalen < sizeof(struct lsi_umts_single)) {
netdev_err(dev->net, "%s: Data length %d, exp >= %zu\n",
__func__, datalen, sizeof(struct lsi_umts_single));
return -1;
}
if (lsi->session_state == SIERRA_NET_SESSION_IDLE) {
netdev_err(dev->net, "Session idle, 0x%02x\n",
lsi->session_state);
return 0;
}
if (lsi->protocol == SIERRA_NET_PROTOCOL_UMTS) {
struct lsi_umts_single *single = (struct lsi_umts_single *)lsi;
if (single->link_type != SIERRA_NET_AS_LINK_TYPE_IPV4 &&
single->link_type != SIERRA_NET_AS_LINK_TYPE_IPV6) {
netdev_err(dev->net, "Link type unsupported: 0x%02x\n",
single->link_type);
return -1;
}
expected_length = SIERRA_NET_LSI_UMTS_STATUS_LEN;
} else if (lsi->protocol == SIERRA_NET_PROTOCOL_UMTS_DS) {
expected_length = SIERRA_NET_LSI_UMTS_DS_STATUS_LEN;
} else {
netdev_err(dev->net, "Protocol unsupported, 0x%02x\n",
lsi->protocol);
return -1;
}
if (be16_to_cpu(lsi->length) != expected_length) {
netdev_err(dev->net, "%s: LSI_UMTS_STATUS_LEN %d, exp %u\n",
__func__, be16_to_cpu(lsi->length), expected_length);
return -1;
}
if (lsi->coverage == SIERRA_NET_COVERAGE_NONE ||
lsi->coverage == SIERRA_NET_COVERAGE_NOPACKET) {
netdev_err(dev->net, "No coverage, 0x%02x\n", lsi->coverage);
return 0;
}
return 1;
}
static void sierra_net_handle_lsi(struct usbnet *dev, char *data,
struct hip_hdr *hh)
{
struct sierra_net_data *priv = sierra_net_get_private(dev);
int link_up;
link_up = sierra_net_parse_lsi(dev, data + hh->hdrlen,
hh->payload_len.word);
if (link_up < 0) {
netdev_err(dev->net, "Invalid LSI\n");
return;
}
if (link_up) {
sierra_net_set_ctx_index(priv, hh->msgspecific.byte);
priv->link_up = 1;
} else {
priv->link_up = 0;
}
usbnet_link_change(dev, link_up, 0);
}
static void sierra_net_dosync(struct usbnet *dev)
{
int status;
struct sierra_net_data *priv = sierra_net_get_private(dev);
dev_dbg(&dev->udev->dev, "%s", __func__);
status = sierra_net_send_sync(dev);
if (status < 0)
netdev_err(dev->net,
"Send SYNC failed, status %d\n", status);
status = sierra_net_send_sync(dev);
if (status < 0)
netdev_err(dev->net,
"Send SYNC failed, status %d\n", status);
priv->sync_timer.function = sierra_sync_timer;
priv->sync_timer.data = (unsigned long) dev;
priv->sync_timer.expires = jiffies + SIERRA_NET_SYNCDELAY;
add_timer(&priv->sync_timer);
}
static void sierra_net_kevent(struct work_struct *work)
{
struct sierra_net_data *priv =
container_of(work, struct sierra_net_data, sierra_net_kevent);
struct usbnet *dev = priv->usbnet;
int len;
int err;
u8 *buf;
u8 ifnum;
if (test_bit(SIERRA_NET_EVENT_RESP_AVAIL, &priv->kevent_flags)) {
clear_bit(SIERRA_NET_EVENT_RESP_AVAIL, &priv->kevent_flags);
buf = kzalloc(SIERRA_NET_USBCTL_BUF_LEN, GFP_KERNEL);
if (!buf)
return;
ifnum = priv->ifnum;
len = usb_control_msg(dev->udev, usb_rcvctrlpipe(dev->udev, 0),
USB_CDC_GET_ENCAPSULATED_RESPONSE,
USB_DIR_IN|USB_TYPE_CLASS|USB_RECIP_INTERFACE,
0, ifnum, buf, SIERRA_NET_USBCTL_BUF_LEN,
USB_CTRL_SET_TIMEOUT);
if (len < 0) {
netdev_err(dev->net,
"usb_control_msg failed, status %d\n", len);
} else {
struct hip_hdr hh;
dev_dbg(&dev->udev->dev, "%s: Received status message,"
" %04x bytes", __func__, len);
err = parse_hip(buf, len, &hh);
if (err) {
netdev_err(dev->net, "%s: Bad packet,"
" parse result %d\n", __func__, err);
kfree(buf);
return;
}
if (len != hh.hdrlen + hh.payload_len.word) {
netdev_err(dev->net, "%s: Bad packet, received"
" %d, expected %d\n", __func__, len,
hh.hdrlen + hh.payload_len.word);
kfree(buf);
return;
}
switch (hh.msgid.byte) {
case SIERRA_NET_HIP_LSI_UMTSID:
dev_dbg(&dev->udev->dev, "LSI for ctx:%d",
hh.msgspecific.byte);
sierra_net_handle_lsi(dev, buf, &hh);
break;
case SIERRA_NET_HIP_RESTART_ID:
dev_dbg(&dev->udev->dev, "Restart reported: %d,"
" stopping sync timer",
hh.msgspecific.byte);
del_timer_sync(&priv->sync_timer);
clear_bit(SIERRA_NET_TIMER_EXPIRY,
&priv->kevent_flags);
break;
case SIERRA_NET_HIP_HSYNC_ID:
dev_dbg(&dev->udev->dev, "SYNC received");
err = sierra_net_send_sync(dev);
if (err < 0)
netdev_err(dev->net,
"Send SYNC failed %d\n", err);
break;
case SIERRA_NET_HIP_EXTENDEDID:
netdev_err(dev->net, "Unrecognized HIP msg, "
"extmsgid 0x%04x\n", hh.extmsgid.word);
break;
case SIERRA_NET_HIP_RCGI:
break;
default:
netdev_err(dev->net, "Unrecognized HIP msg, "
"msgid 0x%02x\n", hh.msgid.byte);
break;
}
}
kfree(buf);
}
if (test_bit(SIERRA_NET_TIMER_EXPIRY, &priv->kevent_flags)) {
clear_bit(SIERRA_NET_TIMER_EXPIRY, &priv->kevent_flags);
dev_dbg(&dev->udev->dev, "Deferred sync timer expiry");
sierra_net_dosync(priv->usbnet);
}
if (priv->kevent_flags)
dev_dbg(&dev->udev->dev, "sierra_net_kevent done, "
"kevent_flags = 0x%lx", priv->kevent_flags);
}
static void sierra_net_defer_kevent(struct usbnet *dev, int work)
{
struct sierra_net_data *priv = sierra_net_get_private(dev);
set_bit(work, &priv->kevent_flags);
schedule_work(&priv->sierra_net_kevent);
}
static void sierra_sync_timer(unsigned long syncdata)
{
struct usbnet *dev = (struct usbnet *)syncdata;
dev_dbg(&dev->udev->dev, "%s", __func__);
sierra_net_defer_kevent(dev, SIERRA_NET_TIMER_EXPIRY);
}
static void sierra_net_status(struct usbnet *dev, struct urb *urb)
{
struct usb_cdc_notification *event;
dev_dbg(&dev->udev->dev, "%s", __func__);
if (urb->actual_length < sizeof *event)
return;
event = urb->transfer_buffer;
switch (event->bNotificationType) {
case USB_CDC_NOTIFY_NETWORK_CONNECTION:
case USB_CDC_NOTIFY_SPEED_CHANGE:
break;
case USB_CDC_NOTIFY_RESPONSE_AVAILABLE:
sierra_net_defer_kevent(dev, SIERRA_NET_EVENT_RESP_AVAIL);
break;
default:
netdev_err(dev->net, ": unexpected notification %02x!\n",
event->bNotificationType);
break;
}
}
static void sierra_net_get_drvinfo(struct net_device *net,
struct ethtool_drvinfo *info)
{
usbnet_get_drvinfo(net, info);
strlcpy(info->driver, driver_name, sizeof(info->driver));
strlcpy(info->version, DRIVER_VERSION, sizeof(info->version));
}
static u32 sierra_net_get_link(struct net_device *net)
{
struct usbnet *dev = netdev_priv(net);
return sierra_net_get_private(dev)->link_up && netif_running(net);
}
static int sierra_net_get_fw_attr(struct usbnet *dev, u16 *datap)
{
int result = 0;
__le16 attrdata;
result = usbnet_read_cmd(dev,
SWI_USB_REQUEST_GET_FW_ATTR,
USB_DIR_IN | USB_TYPE_VENDOR,
0x0000,
0x0000,
&attrdata,
sizeof(attrdata)
);
if (result < 0)
return -EIO;
*datap = le16_to_cpu(attrdata);
return result;
}
static int sierra_net_bind(struct usbnet *dev, struct usb_interface *intf)
{
u8 ifacenum;
u8 numendpoints;
u16 fwattr = 0;
int status;
struct sierra_net_data *priv;
static const u8 sync_tmplate[sizeof(priv->sync_msg)] = {
0x00, 0x00, SIERRA_NET_HIP_MSYNC_ID, 0x00};
static const u8 shdwn_tmplate[sizeof(priv->shdwn_msg)] = {
0x00, 0x00, SIERRA_NET_HIP_SHUTD_ID, 0x00};
dev_dbg(&dev->udev->dev, "%s", __func__);
ifacenum = intf->cur_altsetting->desc.bInterfaceNumber;
numendpoints = intf->cur_altsetting->desc.bNumEndpoints;
if (numendpoints != 3) {
dev_err(&dev->udev->dev, "Expected 3 endpoints, found: %d",
numendpoints);
return -ENODEV;
}
dev->status = NULL;
status = usbnet_get_endpoints(dev, intf);
if (status < 0) {
dev_err(&dev->udev->dev, "Error in usbnet_get_endpoints (%d)",
status);
return -ENODEV;
}
priv = kzalloc(sizeof *priv, GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->usbnet = dev;
priv->ifnum = ifacenum;
dev->net->netdev_ops = &sierra_net_device_ops;
dev->net->dev_addr[ETH_ALEN-2] = atomic_inc_return(&iface_counter);
dev->net->dev_addr[ETH_ALEN-1] = ifacenum;
memcpy(priv->shdwn_msg, shdwn_tmplate, sizeof(priv->shdwn_msg));
sierra_net_set_ctx_index(priv, 0);
memcpy(priv->sync_msg, sync_tmplate, sizeof(priv->sync_msg));
dev->rx_urb_size = SIERRA_NET_RX_URB_SIZE;
if (dev->udev->speed != USB_SPEED_HIGH)
dev->rx_urb_size = min_t(size_t, 4096, SIERRA_NET_RX_URB_SIZE);
dev->net->hard_header_len += SIERRA_NET_HIP_EXT_HDR_LEN;
dev->hard_mtu = dev->net->mtu + dev->net->hard_header_len;
dev->net->max_mtu = SIERRA_NET_MAX_SUPPORTED_MTU;
dev->net->flags |= IFF_NOARP;
dev->net->ethtool_ops = &sierra_net_ethtool_ops;
netif_carrier_off(dev->net);
sierra_net_set_private(dev, priv);
priv->kevent_flags = 0;
INIT_WORK(&priv->sierra_net_kevent, sierra_net_kevent);
init_timer(&priv->sync_timer);
status = sierra_net_get_fw_attr(dev, &fwattr);
dev_dbg(&dev->udev->dev, "Fw attr: %x\n", fwattr);
if (!(status == sizeof(fwattr) && (fwattr & SWI_GET_FW_ATTR_MASK))) {
dev_err(&dev->udev->dev, "Incompatible driver and firmware"
" versions\n");
kfree(priv);
return -ENODEV;
}
return 0;
}
static void sierra_net_unbind(struct usbnet *dev, struct usb_interface *intf)
{
int status;
struct sierra_net_data *priv = sierra_net_get_private(dev);
dev_dbg(&dev->udev->dev, "%s", __func__);
del_timer_sync(&priv->sync_timer);
cancel_work_sync(&priv->sierra_net_kevent);
status = sierra_net_send_cmd(dev, priv->shdwn_msg,
sizeof(priv->shdwn_msg), "Shutdown");
if (status < 0)
netdev_err(dev->net,
"usb_control_msg failed, status %d\n", status);
usbnet_status_stop(dev);
sierra_net_set_private(dev, NULL);
kfree(priv);
}
static struct sk_buff *sierra_net_skb_clone(struct usbnet *dev,
struct sk_buff *skb, int len)
{
struct sk_buff *new_skb;
new_skb = skb_clone(skb, GFP_ATOMIC);
skb_pull(skb, len);
if (new_skb) {
skb_trim(new_skb, len);
} else {
if (netif_msg_rx_err(dev))
netdev_err(dev->net, "failed to get skb\n");
dev->net->stats.rx_dropped++;
}
return new_skb;
}
static int sierra_net_rx_fixup(struct usbnet *dev, struct sk_buff *skb)
{
int err;
struct hip_hdr hh;
struct sk_buff *new_skb;
dev_dbg(&dev->udev->dev, "%s", __func__);
while (likely(skb->len)) {
err = parse_hip(skb->data, skb->len, &hh);
if (err) {
if (netif_msg_rx_err(dev))
netdev_err(dev->net, "Invalid HIP header %d\n",
err);
dev->net->stats.rx_length_errors++;
return 0;
}
if (!hh.extmsgid.is_present
|| hh.extmsgid.word != SIERRA_NET_HIP_EXT_IP_IN_ID) {
if (netif_msg_rx_err(dev))
netdev_err(dev->net, "HIP/ETH: Invalid pkt\n");
dev->net->stats.rx_frame_errors++;
return 0;
}
skb_pull(skb, hh.hdrlen);
skb_reset_mac_header(skb);
if (eth_hdr(skb)->h_proto != cpu_to_be16(ETH_P_IPV6))
eth_hdr(skb)->h_proto = cpu_to_be16(ETH_P_IP);
eth_zero_addr(eth_hdr(skb)->h_source);
memcpy(eth_hdr(skb)->h_dest, dev->net->dev_addr, ETH_ALEN);
if (hh.payload_len.word == skb->len)
return 1;
new_skb = sierra_net_skb_clone(dev, skb, hh.payload_len.word);
if (new_skb)
usbnet_skb_return(dev, new_skb);
}
return 0;
}
static struct sk_buff *sierra_net_tx_fixup(struct usbnet *dev,
struct sk_buff *skb, gfp_t flags)
{
struct sierra_net_data *priv = sierra_net_get_private(dev);
u16 len;
bool need_tail;
BUILD_BUG_ON(FIELD_SIZEOF(struct usbnet, data)
< sizeof(struct cdc_state));
dev_dbg(&dev->udev->dev, "%s", __func__);
if (priv->link_up && check_ethip_packet(skb, dev) && is_ip(skb)) {
if (SIERRA_NET_HIP_EXT_HDR_LEN <= skb_headroom(skb)) {
len = skb->len;
skb_push(skb, SIERRA_NET_HIP_EXT_HDR_LEN);
need_tail = ((len + SIERRA_NET_HIP_EXT_HDR_LEN)
% dev->maxpacket == 0);
if (need_tail) {
if (unlikely(skb_tailroom(skb) == 0)) {
netdev_err(dev->net, "tx_fixup:"
"no room for packet\n");
dev_kfree_skb_any(skb);
return NULL;
} else {
skb->data[skb->len] = 0;
__skb_put(skb, 1);
len = len + 1;
}
}
build_hip(skb->data, len, priv);
return skb;
} else {
netdev_err(dev->net, "tx_fixup: no room for HIP\n");
}
}
if (!priv->link_up)
dev->net->stats.tx_carrier_errors++;
dev_kfree_skb_any(skb);
return NULL;
}
static int
sierra_net_probe(struct usb_interface *udev, const struct usb_device_id *prod)
{
int ret;
ret = usbnet_probe(udev, prod);
if (ret == 0) {
struct usbnet *dev = usb_get_intfdata(udev);
ret = usbnet_status_start(dev, GFP_KERNEL);
if (ret == 0) {
sierra_net_dosync(dev);
}
}
return ret;
}
