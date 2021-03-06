static int cdc_mbim_manage_power(struct usbnet *dev, int on)
{
struct cdc_mbim_state *info = (void *)&dev->data;
int rv = 0;
dev_dbg(&dev->intf->dev, "%s() pmcount=%d, on=%d\n", __func__, atomic_read(&info->pmcount), on);
if ((on && atomic_add_return(1, &info->pmcount) == 1) || (!on && atomic_dec_and_test(&info->pmcount))) {
rv = usb_autopm_get_interface(dev->intf);
dev->intf->needs_remote_wakeup = on;
if (!rv)
usb_autopm_put_interface(dev->intf);
}
return 0;
}
static int cdc_mbim_wdm_manage_power(struct usb_interface *intf, int status)
{
struct usbnet *dev = usb_get_intfdata(intf);
if (!dev)
return 0;
return cdc_mbim_manage_power(dev, status);
}
static int cdc_mbim_rx_add_vid(struct net_device *netdev, __be16 proto, u16 vid)
{
struct usbnet *dev = netdev_priv(netdev);
struct cdc_mbim_state *info = (void *)&dev->data;
if (vid == MBIM_IPS0_VID)
info->flags |= FLAG_IPS0_VLAN;
else
if (vid >= 512)
return -EINVAL;
return 0;
}
static int cdc_mbim_rx_kill_vid(struct net_device *netdev, __be16 proto, u16 vid)
{
struct usbnet *dev = netdev_priv(netdev);
struct cdc_mbim_state *info = (void *)&dev->data;
if (vid == MBIM_IPS0_VID)
info->flags &= ~FLAG_IPS0_VLAN;
return 0;
}
static int cdc_mbim_set_ctrlalt(struct usbnet *dev, struct usb_interface *intf, u8 alt)
{
struct usb_driver *driver = to_usb_driver(intf->dev.driver);
const struct usb_device_id *id;
struct driver_info *info;
int ret;
ret = usb_set_interface(dev->udev,
intf->cur_altsetting->desc.bInterfaceNumber,
alt);
if (ret)
return ret;
id = usb_match_id(intf, driver->id_table);
if (!id)
return -ENODEV;
info = (struct driver_info *)id->driver_info;
if (info != dev->driver_info) {
dev_dbg(&intf->dev, "driver_info updated to '%s'\n",
info->description);
dev->driver_info = info;
}
return 0;
}
static int cdc_mbim_bind(struct usbnet *dev, struct usb_interface *intf)
{
struct cdc_ncm_ctx *ctx;
struct usb_driver *subdriver = ERR_PTR(-ENODEV);
int ret = -ENODEV;
u8 data_altsetting = 1;
struct cdc_mbim_state *info = (void *)&dev->data;
if (cdc_ncm_select_altsetting(intf) == CDC_NCM_COMM_ALTSETTING_MBIM) {
data_altsetting = CDC_NCM_DATA_ALTSETTING_MBIM;
ret = cdc_mbim_set_ctrlalt(dev, intf, CDC_NCM_COMM_ALTSETTING_MBIM);
if (ret)
goto err;
ret = -ENODEV;
}
if (!cdc_ncm_comm_intf_is_mbim(intf->cur_altsetting))
goto err;
ret = cdc_ncm_bind_common(dev, intf, data_altsetting);
if (ret)
goto err;
ctx = info->ctx;
if (ctx->mbim_desc && dev->status)
subdriver = usb_cdc_wdm_register(ctx->control,
&dev->status->desc,
le16_to_cpu(ctx->mbim_desc->wMaxControlMessage),
cdc_mbim_wdm_manage_power);
if (IS_ERR(subdriver)) {
ret = PTR_ERR(subdriver);
cdc_ncm_unbind(dev, intf);
goto err;
}
dev->status = NULL;
info->subdriver = subdriver;
dev->net->flags |= IFF_NOARP;
dev->net->features |= NETIF_F_HW_VLAN_CTAG_TX | NETIF_F_HW_VLAN_CTAG_FILTER;
dev->net->netdev_ops = &cdc_mbim_netdev_ops;
err:
return ret;
}
static void cdc_mbim_unbind(struct usbnet *dev, struct usb_interface *intf)
{
struct cdc_mbim_state *info = (void *)&dev->data;
struct cdc_ncm_ctx *ctx = info->ctx;
if (info->subdriver && info->subdriver->disconnect)
info->subdriver->disconnect(ctx->control);
info->subdriver = NULL;
cdc_ncm_unbind(dev, intf);
}
static bool is_ip_proto(__be16 proto)
{
switch (proto) {
case htons(ETH_P_IP):
case htons(ETH_P_IPV6):
return true;
}
return false;
}
static struct sk_buff *cdc_mbim_tx_fixup(struct usbnet *dev, struct sk_buff *skb, gfp_t flags)
{
struct sk_buff *skb_out;
struct cdc_mbim_state *info = (void *)&dev->data;
struct cdc_ncm_ctx *ctx = info->ctx;
__le32 sign = cpu_to_le32(USB_CDC_MBIM_NDP16_IPS_SIGN);
u16 tci = 0;
bool is_ip;
u8 *c;
if (!ctx)
goto error;
if (skb) {
if (skb->len <= ETH_HLEN)
goto error;
skb_reset_mac_header(skb);
if (vlan_get_tag(skb, &tci) < 0 && skb->len > VLAN_ETH_HLEN &&
__vlan_get_tag(skb, &tci) == 0) {
is_ip = is_ip_proto(vlan_eth_hdr(skb)->h_vlan_encapsulated_proto);
skb_pull(skb, VLAN_ETH_HLEN);
} else {
is_ip = is_ip_proto(eth_hdr(skb)->h_proto);
skb_pull(skb, ETH_HLEN);
}
if (info->flags & FLAG_IPS0_VLAN) {
if (!tci)
goto error;
if (tci == MBIM_IPS0_VID)
tci = 0;
}
switch (tci & 0x0f00) {
case 0x0000:
if (!is_ip)
goto error;
c = (u8 *)&sign;
c[3] = tci;
break;
case 0x0100:
if (is_ip)
goto error;
sign = cpu_to_le32(USB_CDC_MBIM_NDP16_DSS_SIGN);
c = (u8 *)&sign;
c[3] = tci;
break;
default:
netif_err(dev, tx_err, dev->net,
"unsupported tci=0x%04x\n", tci);
goto error;
}
}
spin_lock_bh(&ctx->mtx);
skb_out = cdc_ncm_fill_tx_frame(dev, skb, sign);
spin_unlock_bh(&ctx->mtx);
return skb_out;
error:
if (skb)
dev_kfree_skb_any(skb);
return NULL;
}
static void do_neigh_solicit(struct usbnet *dev, u8 *buf, u16 tci)
{
struct ipv6hdr *iph = (void *)buf;
struct nd_msg *msg = (void *)(iph + 1);
struct net_device *netdev;
struct inet6_dev *in6_dev;
bool is_router;
if (!ipv6_addr_is_solict_mult(&iph->daddr) ||
!(ipv6_addr_type(&iph->saddr) & IPV6_ADDR_UNICAST))
return;
rcu_read_lock();
if (tci) {
netdev = __vlan_find_dev_deep_rcu(dev->net, htons(ETH_P_8021Q),
tci);
if (!netdev) {
rcu_read_unlock();
return;
}
} else {
netdev = dev->net;
}
dev_hold(netdev);
rcu_read_unlock();
in6_dev = in6_dev_get(netdev);
if (!in6_dev)
goto out;
is_router = !!in6_dev->cnf.forwarding;
in6_dev_put(in6_dev);
ipv6_stub->ndisc_send_na(netdev, NULL, &iph->saddr, &msg->target,
is_router ,
true ,
false ,
true );
out:
dev_put(netdev);
}
static bool is_neigh_solicit(u8 *buf, size_t len)
{
struct ipv6hdr *iph = (void *)buf;
struct nd_msg *msg = (void *)(iph + 1);
return (len >= sizeof(struct ipv6hdr) + sizeof(struct nd_msg) &&
iph->nexthdr == IPPROTO_ICMPV6 &&
msg->icmph.icmp6_code == 0 &&
msg->icmph.icmp6_type == NDISC_NEIGHBOUR_SOLICITATION);
}
static struct sk_buff *cdc_mbim_process_dgram(struct usbnet *dev, u8 *buf, size_t len, u16 tci)
{
__be16 proto = htons(ETH_P_802_3);
struct sk_buff *skb = NULL;
if (tci < 256 || tci == MBIM_IPS0_VID) {
if (len < sizeof(struct iphdr))
goto err;
switch (*buf & 0xf0) {
case 0x40:
proto = htons(ETH_P_IP);
break;
case 0x60:
if (is_neigh_solicit(buf, len))
do_neigh_solicit(dev, buf, tci);
proto = htons(ETH_P_IPV6);
break;
default:
goto err;
}
}
skb = netdev_alloc_skb_ip_align(dev->net, len + ETH_HLEN);
if (!skb)
goto err;
skb_put(skb, ETH_HLEN);
skb_reset_mac_header(skb);
eth_hdr(skb)->h_proto = proto;
memset(eth_hdr(skb)->h_source, 0, ETH_ALEN);
memcpy(eth_hdr(skb)->h_dest, dev->net->dev_addr, ETH_ALEN);
memcpy(skb_put(skb, len), buf, len);
if (tci)
__vlan_hwaccel_put_tag(skb, htons(ETH_P_8021Q), tci);
err:
return skb;
}
static int cdc_mbim_rx_fixup(struct usbnet *dev, struct sk_buff *skb_in)
{
struct sk_buff *skb;
struct cdc_mbim_state *info = (void *)&dev->data;
struct cdc_ncm_ctx *ctx = info->ctx;
int len;
int nframes;
int x;
int offset;
struct usb_cdc_ncm_ndp16 *ndp16;
struct usb_cdc_ncm_dpe16 *dpe16;
int ndpoffset;
int loopcount = 50;
u32 payload = 0;
u8 *c;
u16 tci;
ndpoffset = cdc_ncm_rx_verify_nth16(ctx, skb_in);
if (ndpoffset < 0)
goto error;
next_ndp:
nframes = cdc_ncm_rx_verify_ndp16(skb_in, ndpoffset);
if (nframes < 0)
goto error;
ndp16 = (struct usb_cdc_ncm_ndp16 *)(skb_in->data + ndpoffset);
switch (ndp16->dwSignature & cpu_to_le32(0x00ffffff)) {
case cpu_to_le32(USB_CDC_MBIM_NDP16_IPS_SIGN):
c = (u8 *)&ndp16->dwSignature;
tci = c[3];
if (!tci && info->flags & FLAG_IPS0_VLAN)
tci = MBIM_IPS0_VID;
break;
case cpu_to_le32(USB_CDC_MBIM_NDP16_DSS_SIGN):
c = (u8 *)&ndp16->dwSignature;
tci = c[3] + 256;
break;
default:
netif_dbg(dev, rx_err, dev->net,
"unsupported NDP signature <0x%08x>\n",
le32_to_cpu(ndp16->dwSignature));
goto err_ndp;
}
dpe16 = ndp16->dpe16;
for (x = 0; x < nframes; x++, dpe16++) {
offset = le16_to_cpu(dpe16->wDatagramIndex);
len = le16_to_cpu(dpe16->wDatagramLength);
if ((offset == 0) || (len == 0)) {
if (!x)
goto err_ndp;
break;
}
if (((offset + len) > skb_in->len) || (len > ctx->rx_max)) {
netif_dbg(dev, rx_err, dev->net,
"invalid frame detected (ignored) offset[%u]=%u, length=%u, skb=%p\n",
x, offset, len, skb_in);
if (!x)
goto err_ndp;
break;
} else {
skb = cdc_mbim_process_dgram(dev, skb_in->data + offset, len, tci);
if (!skb)
goto error;
usbnet_skb_return(dev, skb);
payload += len;
}
}
err_ndp:
ndpoffset = le16_to_cpu(ndp16->wNextNdpIndex);
if (ndpoffset && loopcount--)
goto next_ndp;
ctx->rx_overhead += skb_in->len - payload;
ctx->rx_ntbs++;
return 1;
error:
return 0;
}
static int cdc_mbim_suspend(struct usb_interface *intf, pm_message_t message)
{
int ret = -ENODEV;
struct usbnet *dev = usb_get_intfdata(intf);
struct cdc_mbim_state *info = (void *)&dev->data;
struct cdc_ncm_ctx *ctx = info->ctx;
if (!ctx)
goto error;
ret = usbnet_suspend(intf, message);
if (ret < 0)
goto error;
if (intf == ctx->control && info->subdriver && info->subdriver->suspend)
ret = info->subdriver->suspend(intf, message);
if (ret < 0)
usbnet_resume(intf);
error:
return ret;
}
static int cdc_mbim_resume(struct usb_interface *intf)
{
int ret = 0;
struct usbnet *dev = usb_get_intfdata(intf);
struct cdc_mbim_state *info = (void *)&dev->data;
struct cdc_ncm_ctx *ctx = info->ctx;
bool callsub = (intf == ctx->control && info->subdriver && info->subdriver->resume);
if (callsub)
ret = info->subdriver->resume(intf);
if (ret < 0)
goto err;
ret = usbnet_resume(intf);
if (ret < 0 && callsub)
info->subdriver->suspend(intf, PMSG_SUSPEND);
err:
return ret;
}
