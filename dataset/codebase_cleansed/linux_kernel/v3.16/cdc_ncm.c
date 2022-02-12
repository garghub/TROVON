static int cdc_ncm_get_sset_count(struct net_device __always_unused *netdev, int sset)
{
switch (sset) {
case ETH_SS_STATS:
return ARRAY_SIZE(cdc_ncm_gstrings_stats);
default:
return -EOPNOTSUPP;
}
}
static void cdc_ncm_get_ethtool_stats(struct net_device *netdev,
struct ethtool_stats __always_unused *stats,
u64 *data)
{
struct usbnet *dev = netdev_priv(netdev);
struct cdc_ncm_ctx *ctx = (struct cdc_ncm_ctx *)dev->data[0];
int i;
char *p = NULL;
for (i = 0; i < ARRAY_SIZE(cdc_ncm_gstrings_stats); i++) {
p = (char *)ctx + cdc_ncm_gstrings_stats[i].stat_offset;
data[i] = (cdc_ncm_gstrings_stats[i].sizeof_stat == sizeof(u64)) ? *(u64 *)p : *(u32 *)p;
}
}
static void cdc_ncm_get_strings(struct net_device __always_unused *netdev, u32 stringset, u8 *data)
{
u8 *p = data;
int i;
switch (stringset) {
case ETH_SS_STATS:
for (i = 0; i < ARRAY_SIZE(cdc_ncm_gstrings_stats); i++) {
memcpy(p, cdc_ncm_gstrings_stats[i].stat_string, ETH_GSTRING_LEN);
p += ETH_GSTRING_LEN;
}
}
}
static u32 cdc_ncm_check_rx_max(struct usbnet *dev, u32 new_rx)
{
struct cdc_ncm_ctx *ctx = (struct cdc_ncm_ctx *)dev->data[0];
u32 val, max, min;
min = USB_CDC_NCM_NTB_MIN_IN_SIZE;
max = min_t(u32, CDC_NCM_NTB_MAX_SIZE_RX, le32_to_cpu(ctx->ncm_parm.dwNtbInMaxSize));
if (max < min) {
dev_warn(&dev->intf->dev, "dwNtbInMaxSize=%u is too small. Using %u\n",
le32_to_cpu(ctx->ncm_parm.dwNtbInMaxSize), min);
max = min;
}
val = clamp_t(u32, new_rx, min, max);
if (val != new_rx)
dev_dbg(&dev->intf->dev, "rx_max must be in the [%u, %u] range\n", min, max);
return val;
}
static u32 cdc_ncm_check_tx_max(struct usbnet *dev, u32 new_tx)
{
struct cdc_ncm_ctx *ctx = (struct cdc_ncm_ctx *)dev->data[0];
u32 val, max, min;
min = ctx->max_datagram_size + ctx->max_ndp_size + sizeof(struct usb_cdc_ncm_nth16);
max = min_t(u32, CDC_NCM_NTB_MAX_SIZE_TX, le32_to_cpu(ctx->ncm_parm.dwNtbOutMaxSize));
min = min(min, max);
val = clamp_t(u32, new_tx, min, max);
if (val != new_tx)
dev_dbg(&dev->intf->dev, "tx_max must be in the [%u, %u] range\n", min, max);
return val;
}
static ssize_t cdc_ncm_show_min_tx_pkt(struct device *d, struct device_attribute *attr, char *buf)
{
struct usbnet *dev = netdev_priv(to_net_dev(d));
struct cdc_ncm_ctx *ctx = (struct cdc_ncm_ctx *)dev->data[0];
return sprintf(buf, "%u\n", ctx->min_tx_pkt);
}
static ssize_t cdc_ncm_show_rx_max(struct device *d, struct device_attribute *attr, char *buf)
{
struct usbnet *dev = netdev_priv(to_net_dev(d));
struct cdc_ncm_ctx *ctx = (struct cdc_ncm_ctx *)dev->data[0];
return sprintf(buf, "%u\n", ctx->rx_max);
}
static ssize_t cdc_ncm_show_tx_max(struct device *d, struct device_attribute *attr, char *buf)
{
struct usbnet *dev = netdev_priv(to_net_dev(d));
struct cdc_ncm_ctx *ctx = (struct cdc_ncm_ctx *)dev->data[0];
return sprintf(buf, "%u\n", ctx->tx_max);
}
static ssize_t cdc_ncm_show_tx_timer_usecs(struct device *d, struct device_attribute *attr, char *buf)
{
struct usbnet *dev = netdev_priv(to_net_dev(d));
struct cdc_ncm_ctx *ctx = (struct cdc_ncm_ctx *)dev->data[0];
return sprintf(buf, "%u\n", ctx->timer_interval / (u32)NSEC_PER_USEC);
}
static ssize_t cdc_ncm_store_min_tx_pkt(struct device *d, struct device_attribute *attr, const char *buf, size_t len)
{
struct usbnet *dev = netdev_priv(to_net_dev(d));
struct cdc_ncm_ctx *ctx = (struct cdc_ncm_ctx *)dev->data[0];
unsigned long val;
if (kstrtoul(buf, 0, &val))
return -EINVAL;
ctx->min_tx_pkt = val;
return len;
}
static ssize_t cdc_ncm_store_rx_max(struct device *d, struct device_attribute *attr, const char *buf, size_t len)
{
struct usbnet *dev = netdev_priv(to_net_dev(d));
struct cdc_ncm_ctx *ctx = (struct cdc_ncm_ctx *)dev->data[0];
unsigned long val;
if (kstrtoul(buf, 0, &val) || cdc_ncm_check_rx_max(dev, val) != val)
return -EINVAL;
cdc_ncm_update_rxtx_max(dev, val, ctx->tx_max);
return len;
}
static ssize_t cdc_ncm_store_tx_max(struct device *d, struct device_attribute *attr, const char *buf, size_t len)
{
struct usbnet *dev = netdev_priv(to_net_dev(d));
struct cdc_ncm_ctx *ctx = (struct cdc_ncm_ctx *)dev->data[0];
unsigned long val;
if (kstrtoul(buf, 0, &val) || cdc_ncm_check_tx_max(dev, val) != val)
return -EINVAL;
cdc_ncm_update_rxtx_max(dev, ctx->rx_max, val);
return len;
}
static ssize_t cdc_ncm_store_tx_timer_usecs(struct device *d, struct device_attribute *attr, const char *buf, size_t len)
{
struct usbnet *dev = netdev_priv(to_net_dev(d));
struct cdc_ncm_ctx *ctx = (struct cdc_ncm_ctx *)dev->data[0];
ssize_t ret;
unsigned long val;
ret = kstrtoul(buf, 0, &val);
if (ret)
return ret;
if (val && (val < CDC_NCM_TIMER_INTERVAL_MIN || val > CDC_NCM_TIMER_INTERVAL_MAX))
return -EINVAL;
spin_lock_bh(&ctx->mtx);
ctx->timer_interval = val * NSEC_PER_USEC;
if (!ctx->timer_interval)
ctx->tx_timer_pending = 0;
spin_unlock_bh(&ctx->mtx);
return len;
}
static void cdc_ncm_update_rxtx_max(struct usbnet *dev, u32 new_rx, u32 new_tx)
{
struct cdc_ncm_ctx *ctx = (struct cdc_ncm_ctx *)dev->data[0];
u8 iface_no = ctx->control->cur_altsetting->desc.bInterfaceNumber;
u32 val;
val = cdc_ncm_check_rx_max(dev, new_rx);
if (val != ctx->rx_max) {
__le32 dwNtbInMaxSize = cpu_to_le32(val);
dev_info(&dev->intf->dev, "setting rx_max = %u\n", val);
if (usbnet_write_cmd(dev, USB_CDC_SET_NTB_INPUT_SIZE,
USB_TYPE_CLASS | USB_DIR_OUT
| USB_RECIP_INTERFACE,
0, iface_no, &dwNtbInMaxSize, 4) < 0)
dev_dbg(&dev->intf->dev, "Setting NTB Input Size failed\n");
else
ctx->rx_max = val;
}
if (dev->rx_urb_size != ctx->rx_max) {
dev->rx_urb_size = ctx->rx_max;
if (netif_running(dev->net))
usbnet_unlink_rx_urbs(dev);
}
val = cdc_ncm_check_tx_max(dev, new_tx);
if (val != ctx->tx_max)
dev_info(&dev->intf->dev, "setting tx_max = %u\n", val);
if (val != le32_to_cpu(ctx->ncm_parm.dwNtbOutMaxSize) &&
val % usb_maxpacket(dev->udev, dev->out, 1) == 0)
val++;
if (netif_running(dev->net) && val > ctx->tx_max) {
netif_tx_lock_bh(dev->net);
usbnet_start_xmit(NULL, dev->net);
if (ctx->tx_curr_skb) {
dev_kfree_skb_any(ctx->tx_curr_skb);
ctx->tx_curr_skb = NULL;
}
ctx->tx_max = val;
netif_tx_unlock_bh(dev->net);
} else {
ctx->tx_max = val;
}
dev->hard_mtu = ctx->tx_max;
usbnet_update_max_qlen(dev);
ctx->min_tx_pkt = clamp_t(u16, ctx->tx_max - 3 * usb_maxpacket(dev->udev, dev->out, 1),
CDC_NCM_MIN_TX_PKT, ctx->tx_max);
}
static u8 cdc_ncm_flags(struct usbnet *dev)
{
struct cdc_ncm_ctx *ctx = (struct cdc_ncm_ctx *)dev->data[0];
if (cdc_ncm_comm_intf_is_mbim(dev->intf->cur_altsetting) && ctx->mbim_desc)
return ctx->mbim_desc->bmNetworkCapabilities;
if (ctx->func_desc)
return ctx->func_desc->bmNetworkCapabilities;
return 0;
}
static int cdc_ncm_eth_hlen(struct usbnet *dev)
{
if (cdc_ncm_comm_intf_is_mbim(dev->intf->cur_altsetting))
return 0;
return ETH_HLEN;
}
static u32 cdc_ncm_min_dgram_size(struct usbnet *dev)
{
if (cdc_ncm_comm_intf_is_mbim(dev->intf->cur_altsetting))
return CDC_MBIM_MIN_DATAGRAM_SIZE;
return CDC_NCM_MIN_DATAGRAM_SIZE;
}
static u32 cdc_ncm_max_dgram_size(struct usbnet *dev)
{
struct cdc_ncm_ctx *ctx = (struct cdc_ncm_ctx *)dev->data[0];
if (cdc_ncm_comm_intf_is_mbim(dev->intf->cur_altsetting) && ctx->mbim_desc)
return le16_to_cpu(ctx->mbim_desc->wMaxSegmentSize);
if (ctx->ether_desc)
return le16_to_cpu(ctx->ether_desc->wMaxSegmentSize);
return CDC_NCM_MAX_DATAGRAM_SIZE;
}
static int cdc_ncm_init(struct usbnet *dev)
{
struct cdc_ncm_ctx *ctx = (struct cdc_ncm_ctx *)dev->data[0];
u8 iface_no = ctx->control->cur_altsetting->desc.bInterfaceNumber;
int err;
err = usbnet_read_cmd(dev, USB_CDC_GET_NTB_PARAMETERS,
USB_TYPE_CLASS | USB_DIR_IN
|USB_RECIP_INTERFACE,
0, iface_no, &ctx->ncm_parm,
sizeof(ctx->ncm_parm));
if (err < 0) {
dev_err(&dev->intf->dev, "failed GET_NTB_PARAMETERS\n");
return err;
}
if (cdc_ncm_flags(dev) & USB_CDC_NCM_NCAP_CRC_MODE) {
dev_dbg(&dev->intf->dev, "Setting CRC mode off\n");
err = usbnet_write_cmd(dev, USB_CDC_SET_CRC_MODE,
USB_TYPE_CLASS | USB_DIR_OUT
| USB_RECIP_INTERFACE,
USB_CDC_NCM_CRC_NOT_APPENDED,
iface_no, NULL, 0);
if (err < 0)
dev_err(&dev->intf->dev, "SET_CRC_MODE failed\n");
}
if (le16_to_cpu(ctx->ncm_parm.bmNtbFormatsSupported) &
USB_CDC_NCM_NTB32_SUPPORTED) {
dev_dbg(&dev->intf->dev, "Setting NTB format to 16-bit\n");
err = usbnet_write_cmd(dev, USB_CDC_SET_NTB_FORMAT,
USB_TYPE_CLASS | USB_DIR_OUT
| USB_RECIP_INTERFACE,
USB_CDC_NCM_NTB16_FORMAT,
iface_no, NULL, 0);
if (err < 0)
dev_err(&dev->intf->dev, "SET_NTB_FORMAT failed\n");
}
ctx->rx_max = le32_to_cpu(ctx->ncm_parm.dwNtbInMaxSize);
ctx->tx_max = le32_to_cpu(ctx->ncm_parm.dwNtbOutMaxSize);
ctx->tx_remainder = le16_to_cpu(ctx->ncm_parm.wNdpOutPayloadRemainder);
ctx->tx_modulus = le16_to_cpu(ctx->ncm_parm.wNdpOutDivisor);
ctx->tx_ndp_modulus = le16_to_cpu(ctx->ncm_parm.wNdpOutAlignment);
ctx->tx_max_datagrams = le16_to_cpu(ctx->ncm_parm.wNtbOutMaxDatagrams);
dev_dbg(&dev->intf->dev,
"dwNtbInMaxSize=%u dwNtbOutMaxSize=%u wNdpOutPayloadRemainder=%u wNdpOutDivisor=%u wNdpOutAlignment=%u wNtbOutMaxDatagrams=%u flags=0x%x\n",
ctx->rx_max, ctx->tx_max, ctx->tx_remainder, ctx->tx_modulus,
ctx->tx_ndp_modulus, ctx->tx_max_datagrams, cdc_ncm_flags(dev));
if ((ctx->tx_max_datagrams == 0) ||
(ctx->tx_max_datagrams > CDC_NCM_DPT_DATAGRAMS_MAX))
ctx->tx_max_datagrams = CDC_NCM_DPT_DATAGRAMS_MAX;
ctx->max_ndp_size = sizeof(struct usb_cdc_ncm_ndp16) + (ctx->tx_max_datagrams + 1) * sizeof(struct usb_cdc_ncm_dpe16);
ctx->timer_interval = CDC_NCM_TIMER_INTERVAL_USEC * NSEC_PER_USEC;
return 0;
}
static void cdc_ncm_set_dgram_size(struct usbnet *dev, int new_size)
{
struct cdc_ncm_ctx *ctx = (struct cdc_ncm_ctx *)dev->data[0];
u8 iface_no = ctx->control->cur_altsetting->desc.bInterfaceNumber;
__le16 max_datagram_size;
u16 mbim_mtu;
int err;
ctx->max_datagram_size = clamp_t(u32, new_size,
cdc_ncm_min_dgram_size(dev),
CDC_NCM_MAX_DATAGRAM_SIZE);
if (!(cdc_ncm_flags(dev) & USB_CDC_NCM_NCAP_MAX_DATAGRAM_SIZE))
goto out;
err = usbnet_read_cmd(dev, USB_CDC_GET_MAX_DATAGRAM_SIZE,
USB_TYPE_CLASS | USB_DIR_IN | USB_RECIP_INTERFACE,
0, iface_no, &max_datagram_size, 2);
if (err < 0) {
dev_dbg(&dev->intf->dev, "GET_MAX_DATAGRAM_SIZE failed\n");
goto out;
}
if (le16_to_cpu(max_datagram_size) == ctx->max_datagram_size)
goto out;
max_datagram_size = cpu_to_le16(ctx->max_datagram_size);
err = usbnet_write_cmd(dev, USB_CDC_SET_MAX_DATAGRAM_SIZE,
USB_TYPE_CLASS | USB_DIR_OUT | USB_RECIP_INTERFACE,
0, iface_no, &max_datagram_size, 2);
if (err < 0)
dev_dbg(&dev->intf->dev, "SET_MAX_DATAGRAM_SIZE failed\n");
out:
dev->net->mtu = min_t(int, dev->net->mtu, ctx->max_datagram_size - cdc_ncm_eth_hlen(dev));
if (ctx->mbim_extended_desc) {
mbim_mtu = le16_to_cpu(ctx->mbim_extended_desc->wMTU);
if (mbim_mtu != 0 && mbim_mtu < dev->net->mtu)
dev->net->mtu = mbim_mtu;
}
}
static void cdc_ncm_fix_modulus(struct usbnet *dev)
{
struct cdc_ncm_ctx *ctx = (struct cdc_ncm_ctx *)dev->data[0];
u32 val;
val = ctx->tx_ndp_modulus;
if ((val < USB_CDC_NCM_NDP_ALIGN_MIN_SIZE) ||
(val != ((-val) & val)) || (val >= ctx->tx_max)) {
dev_dbg(&dev->intf->dev, "Using default alignment: 4 bytes\n");
ctx->tx_ndp_modulus = USB_CDC_NCM_NDP_ALIGN_MIN_SIZE;
}
val = ctx->tx_modulus;
if ((val < USB_CDC_NCM_NDP_ALIGN_MIN_SIZE) ||
(val != ((-val) & val)) || (val >= ctx->tx_max)) {
dev_dbg(&dev->intf->dev, "Using default transmit modulus: 4 bytes\n");
ctx->tx_modulus = USB_CDC_NCM_NDP_ALIGN_MIN_SIZE;
}
if (ctx->tx_remainder >= ctx->tx_modulus) {
dev_dbg(&dev->intf->dev, "Using default transmit remainder: 0 bytes\n");
ctx->tx_remainder = 0;
}
ctx->tx_remainder = ((ctx->tx_remainder - cdc_ncm_eth_hlen(dev)) &
(ctx->tx_modulus - 1));
}
static int cdc_ncm_setup(struct usbnet *dev)
{
struct cdc_ncm_ctx *ctx = (struct cdc_ncm_ctx *)dev->data[0];
u32 def_rx, def_tx;
def_rx = min_t(u32, CDC_NCM_NTB_DEF_SIZE_RX,
le32_to_cpu(ctx->ncm_parm.dwNtbInMaxSize));
def_tx = min_t(u32, CDC_NCM_NTB_DEF_SIZE_TX,
le32_to_cpu(ctx->ncm_parm.dwNtbOutMaxSize));
cdc_ncm_update_rxtx_max(dev, def_rx, def_tx);
cdc_ncm_fix_modulus(dev);
cdc_ncm_set_dgram_size(dev, cdc_ncm_max_dgram_size(dev));
return 0;
}
static void
cdc_ncm_find_endpoints(struct usbnet *dev, struct usb_interface *intf)
{
struct usb_host_endpoint *e, *in = NULL, *out = NULL;
u8 ep;
for (ep = 0; ep < intf->cur_altsetting->desc.bNumEndpoints; ep++) {
e = intf->cur_altsetting->endpoint + ep;
switch (e->desc.bmAttributes & USB_ENDPOINT_XFERTYPE_MASK) {
case USB_ENDPOINT_XFER_INT:
if (usb_endpoint_dir_in(&e->desc)) {
if (!dev->status)
dev->status = e;
}
break;
case USB_ENDPOINT_XFER_BULK:
if (usb_endpoint_dir_in(&e->desc)) {
if (!in)
in = e;
} else {
if (!out)
out = e;
}
break;
default:
break;
}
}
if (in && !dev->in)
dev->in = usb_rcvbulkpipe(dev->udev,
in->desc.bEndpointAddress &
USB_ENDPOINT_NUMBER_MASK);
if (out && !dev->out)
dev->out = usb_sndbulkpipe(dev->udev,
out->desc.bEndpointAddress &
USB_ENDPOINT_NUMBER_MASK);
}
static void cdc_ncm_free(struct cdc_ncm_ctx *ctx)
{
if (ctx == NULL)
return;
if (ctx->tx_rem_skb != NULL) {
dev_kfree_skb_any(ctx->tx_rem_skb);
ctx->tx_rem_skb = NULL;
}
if (ctx->tx_curr_skb != NULL) {
dev_kfree_skb_any(ctx->tx_curr_skb);
ctx->tx_curr_skb = NULL;
}
kfree(ctx);
}
int cdc_ncm_bind_common(struct usbnet *dev, struct usb_interface *intf, u8 data_altsetting)
{
const struct usb_cdc_union_desc *union_desc = NULL;
struct cdc_ncm_ctx *ctx;
struct usb_driver *driver;
u8 *buf;
int len;
int temp;
u8 iface_no;
ctx = kzalloc(sizeof(*ctx), GFP_KERNEL);
if (!ctx)
return -ENOMEM;
hrtimer_init(&ctx->tx_timer, CLOCK_MONOTONIC, HRTIMER_MODE_REL);
ctx->tx_timer.function = &cdc_ncm_tx_timer_cb;
ctx->bh.data = (unsigned long)dev;
ctx->bh.func = cdc_ncm_txpath_bh;
atomic_set(&ctx->stop, 0);
spin_lock_init(&ctx->mtx);
dev->data[0] = (unsigned long)ctx;
ctx->control = intf;
driver = driver_of(intf);
buf = intf->cur_altsetting->extra;
len = intf->cur_altsetting->extralen;
while ((len > 0) && (buf[0] > 2) && (buf[0] <= len)) {
if (buf[1] != USB_DT_CS_INTERFACE)
goto advance;
switch (buf[2]) {
case USB_CDC_UNION_TYPE:
if (buf[0] < sizeof(*union_desc))
break;
union_desc = (const struct usb_cdc_union_desc *)buf;
if (intf->cur_altsetting->desc.bInterfaceNumber !=
union_desc->bMasterInterface0) {
dev_dbg(&intf->dev, "bogus CDC Union\n");
goto error;
}
ctx->data = usb_ifnum_to_if(dev->udev,
union_desc->bSlaveInterface0);
break;
case USB_CDC_ETHERNET_TYPE:
if (buf[0] < sizeof(*(ctx->ether_desc)))
break;
ctx->ether_desc =
(const struct usb_cdc_ether_desc *)buf;
break;
case USB_CDC_NCM_TYPE:
if (buf[0] < sizeof(*(ctx->func_desc)))
break;
ctx->func_desc = (const struct usb_cdc_ncm_desc *)buf;
break;
case USB_CDC_MBIM_TYPE:
if (buf[0] < sizeof(*(ctx->mbim_desc)))
break;
ctx->mbim_desc = (const struct usb_cdc_mbim_desc *)buf;
break;
case USB_CDC_MBIM_EXTENDED_TYPE:
if (buf[0] < sizeof(*(ctx->mbim_extended_desc)))
break;
ctx->mbim_extended_desc =
(const struct usb_cdc_mbim_extended_desc *)buf;
break;
default:
break;
}
advance:
temp = buf[0];
buf += temp;
len -= temp;
}
if (!union_desc && intf->intf_assoc && intf->intf_assoc->bInterfaceCount == 2) {
ctx->data = usb_ifnum_to_if(dev->udev, intf->cur_altsetting->desc.bInterfaceNumber + 1);
dev_dbg(&intf->dev, "CDC Union missing - got slave from IAD\n");
}
if (!ctx->data) {
dev_dbg(&intf->dev, "CDC Union missing and no IAD found\n");
goto error;
}
if (cdc_ncm_comm_intf_is_mbim(intf->cur_altsetting)) {
if (!ctx->mbim_desc) {
dev_dbg(&intf->dev, "MBIM functional descriptor missing\n");
goto error;
}
} else {
if (!ctx->ether_desc || !ctx->func_desc) {
dev_dbg(&intf->dev, "NCM or ECM functional descriptors missing\n");
goto error;
}
}
if (ctx->data != ctx->control) {
temp = usb_driver_claim_interface(driver, ctx->data, dev);
if (temp) {
dev_dbg(&intf->dev, "failed to claim data intf\n");
goto error;
}
}
iface_no = ctx->data->cur_altsetting->desc.bInterfaceNumber;
temp = usb_set_interface(dev->udev, iface_no, 0);
if (temp) {
dev_dbg(&intf->dev, "set interface failed\n");
goto error2;
}
if (cdc_ncm_init(dev))
goto error2;
temp = usb_set_interface(dev->udev, iface_no, data_altsetting);
if (temp) {
dev_dbg(&intf->dev, "set interface failed\n");
goto error2;
}
cdc_ncm_find_endpoints(dev, ctx->data);
cdc_ncm_find_endpoints(dev, ctx->control);
if (!dev->in || !dev->out || !dev->status) {
dev_dbg(&intf->dev, "failed to collect endpoints\n");
goto error2;
}
usb_set_intfdata(ctx->data, dev);
usb_set_intfdata(ctx->control, dev);
if (ctx->ether_desc) {
temp = usbnet_get_ethernet_addr(dev, ctx->ether_desc->iMACAddress);
if (temp) {
dev_dbg(&intf->dev, "failed to get mac address\n");
goto error2;
}
dev_info(&intf->dev, "MAC-Address: %pM\n", dev->net->dev_addr);
}
cdc_ncm_setup(dev);
dev->net->ethtool_ops = &cdc_ncm_ethtool_ops;
dev->net->sysfs_groups[0] = &cdc_ncm_sysfs_attr_group;
return 0;
error2:
usb_set_intfdata(ctx->control, NULL);
usb_set_intfdata(ctx->data, NULL);
if (ctx->data != ctx->control)
usb_driver_release_interface(driver, ctx->data);
error:
cdc_ncm_free((struct cdc_ncm_ctx *)dev->data[0]);
dev->data[0] = 0;
dev_info(&intf->dev, "bind() failure\n");
return -ENODEV;
}
void cdc_ncm_unbind(struct usbnet *dev, struct usb_interface *intf)
{
struct cdc_ncm_ctx *ctx = (struct cdc_ncm_ctx *)dev->data[0];
struct usb_driver *driver = driver_of(intf);
if (ctx == NULL)
return;
atomic_set(&ctx->stop, 1);
if (hrtimer_active(&ctx->tx_timer))
hrtimer_cancel(&ctx->tx_timer);
tasklet_kill(&ctx->bh);
if (ctx->control == ctx->data)
ctx->data = NULL;
if (intf == ctx->control && ctx->data) {
usb_set_intfdata(ctx->data, NULL);
usb_driver_release_interface(driver, ctx->data);
ctx->data = NULL;
} else if (intf == ctx->data && ctx->control) {
usb_set_intfdata(ctx->control, NULL);
usb_driver_release_interface(driver, ctx->control);
ctx->control = NULL;
}
usb_set_intfdata(intf, NULL);
cdc_ncm_free(ctx);
}
u8 cdc_ncm_select_altsetting(struct usb_interface *intf)
{
struct usb_host_interface *alt;
if (intf->num_altsetting < 2)
return intf->cur_altsetting->desc.bAlternateSetting;
if (prefer_mbim) {
alt = usb_altnum_to_altsetting(intf, CDC_NCM_COMM_ALTSETTING_MBIM);
if (alt && cdc_ncm_comm_intf_is_mbim(alt))
return CDC_NCM_COMM_ALTSETTING_MBIM;
}
return CDC_NCM_COMM_ALTSETTING_NCM;
}
static int cdc_ncm_bind(struct usbnet *dev, struct usb_interface *intf)
{
int ret;
if (cdc_ncm_select_altsetting(intf) != CDC_NCM_COMM_ALTSETTING_NCM)
return -ENODEV;
ret = cdc_ncm_bind_common(dev, intf, CDC_NCM_DATA_ALTSETTING_NCM);
usbnet_link_change(dev, 0, 0);
return ret;
}
static void cdc_ncm_align_tail(struct sk_buff *skb, size_t modulus, size_t remainder, size_t max)
{
size_t align = ALIGN(skb->len, modulus) - skb->len + remainder;
if (skb->len + align > max)
align = max - skb->len;
if (align && skb_tailroom(skb) >= align)
memset(skb_put(skb, align), 0, align);
}
static struct usb_cdc_ncm_ndp16 *cdc_ncm_ndp(struct cdc_ncm_ctx *ctx, struct sk_buff *skb, __le32 sign, size_t reserve)
{
struct usb_cdc_ncm_ndp16 *ndp16 = NULL;
struct usb_cdc_ncm_nth16 *nth16 = (void *)skb->data;
size_t ndpoffset = le16_to_cpu(nth16->wNdpIndex);
while (ndpoffset) {
ndp16 = (struct usb_cdc_ncm_ndp16 *)(skb->data + ndpoffset);
if (ndp16->dwSignature == sign)
return ndp16;
ndpoffset = le16_to_cpu(ndp16->wNextNdpIndex);
}
cdc_ncm_align_tail(skb, ctx->tx_ndp_modulus, 0, ctx->tx_max);
if ((ctx->tx_max - skb->len - reserve) < ctx->max_ndp_size)
return NULL;
if (ndp16)
ndp16->wNextNdpIndex = cpu_to_le16(skb->len);
else
nth16->wNdpIndex = cpu_to_le16(skb->len);
ndp16 = (struct usb_cdc_ncm_ndp16 *)memset(skb_put(skb, ctx->max_ndp_size), 0, ctx->max_ndp_size);
ndp16->dwSignature = sign;
ndp16->wLength = cpu_to_le16(sizeof(struct usb_cdc_ncm_ndp16) + sizeof(struct usb_cdc_ncm_dpe16));
return ndp16;
}
struct sk_buff *
cdc_ncm_fill_tx_frame(struct usbnet *dev, struct sk_buff *skb, __le32 sign)
{
struct cdc_ncm_ctx *ctx = (struct cdc_ncm_ctx *)dev->data[0];
struct usb_cdc_ncm_nth16 *nth16;
struct usb_cdc_ncm_ndp16 *ndp16;
struct sk_buff *skb_out;
u16 n = 0, index, ndplen;
u8 ready2send = 0;
if (skb != NULL) {
swap(skb, ctx->tx_rem_skb);
swap(sign, ctx->tx_rem_sign);
} else {
ready2send = 1;
}
skb_out = ctx->tx_curr_skb;
if (!skb_out) {
skb_out = alloc_skb(ctx->tx_max, GFP_ATOMIC);
if (skb_out == NULL) {
if (skb != NULL) {
dev_kfree_skb_any(skb);
dev->net->stats.tx_dropped++;
}
goto exit_no_skb;
}
nth16 = (struct usb_cdc_ncm_nth16 *)memset(skb_put(skb_out, sizeof(struct usb_cdc_ncm_nth16)), 0, sizeof(struct usb_cdc_ncm_nth16));
nth16->dwSignature = cpu_to_le32(USB_CDC_NCM_NTH16_SIGN);
nth16->wHeaderLength = cpu_to_le16(sizeof(struct usb_cdc_ncm_nth16));
nth16->wSequence = cpu_to_le16(ctx->tx_seq++);
ctx->tx_curr_frame_num = 0;
ctx->tx_curr_frame_payload = 0;
}
for (n = ctx->tx_curr_frame_num; n < ctx->tx_max_datagrams; n++) {
if (skb == NULL) {
skb = ctx->tx_rem_skb;
sign = ctx->tx_rem_sign;
ctx->tx_rem_skb = NULL;
if (skb == NULL)
break;
}
ndp16 = cdc_ncm_ndp(ctx, skb_out, sign, skb->len + ctx->tx_modulus + ctx->tx_remainder);
cdc_ncm_align_tail(skb_out, ctx->tx_modulus, ctx->tx_remainder, ctx->tx_max);
if (!ndp16 || skb_out->len + skb->len > ctx->tx_max) {
if (n == 0) {
dev_kfree_skb_any(skb);
skb = NULL;
dev->net->stats.tx_dropped++;
} else {
if (ctx->tx_rem_skb != NULL) {
dev_kfree_skb_any(ctx->tx_rem_skb);
dev->net->stats.tx_dropped++;
}
ctx->tx_rem_skb = skb;
ctx->tx_rem_sign = sign;
skb = NULL;
ready2send = 1;
ctx->tx_reason_ntb_full++;
}
break;
}
ndplen = le16_to_cpu(ndp16->wLength);
index = (ndplen - sizeof(struct usb_cdc_ncm_ndp16)) / sizeof(struct usb_cdc_ncm_dpe16) - 1;
ndp16->dpe16[index].wDatagramLength = cpu_to_le16(skb->len);
ndp16->dpe16[index].wDatagramIndex = cpu_to_le16(skb_out->len);
ndp16->wLength = cpu_to_le16(ndplen + sizeof(struct usb_cdc_ncm_dpe16));
memcpy(skb_put(skb_out, skb->len), skb->data, skb->len);
ctx->tx_curr_frame_payload += skb->len;
dev_kfree_skb_any(skb);
skb = NULL;
if (index >= CDC_NCM_DPT_DATAGRAMS_MAX) {
ready2send = 1;
ctx->tx_reason_ndp_full++;
break;
}
}
if (skb != NULL) {
dev_kfree_skb_any(skb);
skb = NULL;
dev->net->stats.tx_dropped++;
}
ctx->tx_curr_frame_num = n;
if (n == 0) {
ctx->tx_curr_skb = skb_out;
goto exit_no_skb;
} else if ((n < ctx->tx_max_datagrams) && (ready2send == 0) && (ctx->timer_interval > 0)) {
ctx->tx_curr_skb = skb_out;
if (n < CDC_NCM_RESTART_TIMER_DATAGRAM_CNT)
ctx->tx_timer_pending = CDC_NCM_TIMER_PENDING_CNT;
goto exit_no_skb;
} else {
if (n == ctx->tx_max_datagrams)
ctx->tx_reason_max_datagram++;
}
if (!(dev->driver_info->flags & FLAG_SEND_ZLP) &&
skb_out->len > ctx->min_tx_pkt)
memset(skb_put(skb_out, ctx->tx_max - skb_out->len), 0,
ctx->tx_max - skb_out->len);
else if (skb_out->len < ctx->tx_max && (skb_out->len % dev->maxpacket) == 0)
*skb_put(skb_out, 1) = 0;
nth16 = (struct usb_cdc_ncm_nth16 *)skb_out->data;
nth16->wBlockLength = cpu_to_le16(skb_out->len);
ctx->tx_curr_skb = NULL;
dev->net->stats.tx_packets += ctx->tx_curr_frame_num;
ctx->tx_overhead += skb_out->len - ctx->tx_curr_frame_payload;
ctx->tx_ntbs++;
dev->net->stats.tx_bytes -= skb_out->len - ctx->tx_curr_frame_payload;
return skb_out;
exit_no_skb:
if (ctx->tx_curr_skb != NULL && n > 0)
cdc_ncm_tx_timeout_start(ctx);
return NULL;
}
static void cdc_ncm_tx_timeout_start(struct cdc_ncm_ctx *ctx)
{
if (!(hrtimer_active(&ctx->tx_timer) || atomic_read(&ctx->stop)))
hrtimer_start(&ctx->tx_timer,
ktime_set(0, ctx->timer_interval),
HRTIMER_MODE_REL);
}
static enum hrtimer_restart cdc_ncm_tx_timer_cb(struct hrtimer *timer)
{
struct cdc_ncm_ctx *ctx =
container_of(timer, struct cdc_ncm_ctx, tx_timer);
if (!atomic_read(&ctx->stop))
tasklet_schedule(&ctx->bh);
return HRTIMER_NORESTART;
}
static void cdc_ncm_txpath_bh(unsigned long param)
{
struct usbnet *dev = (struct usbnet *)param;
struct cdc_ncm_ctx *ctx = (struct cdc_ncm_ctx *)dev->data[0];
spin_lock_bh(&ctx->mtx);
if (ctx->tx_timer_pending != 0) {
ctx->tx_timer_pending--;
cdc_ncm_tx_timeout_start(ctx);
spin_unlock_bh(&ctx->mtx);
} else if (dev->net != NULL) {
ctx->tx_reason_timeout++;
spin_unlock_bh(&ctx->mtx);
netif_tx_lock_bh(dev->net);
usbnet_start_xmit(NULL, dev->net);
netif_tx_unlock_bh(dev->net);
} else {
spin_unlock_bh(&ctx->mtx);
}
}
struct sk_buff *
cdc_ncm_tx_fixup(struct usbnet *dev, struct sk_buff *skb, gfp_t flags)
{
struct sk_buff *skb_out;
struct cdc_ncm_ctx *ctx = (struct cdc_ncm_ctx *)dev->data[0];
if (ctx == NULL)
goto error;
spin_lock_bh(&ctx->mtx);
skb_out = cdc_ncm_fill_tx_frame(dev, skb, cpu_to_le32(USB_CDC_NCM_NDP16_NOCRC_SIGN));
spin_unlock_bh(&ctx->mtx);
return skb_out;
error:
if (skb != NULL)
dev_kfree_skb_any(skb);
return NULL;
}
int cdc_ncm_rx_verify_nth16(struct cdc_ncm_ctx *ctx, struct sk_buff *skb_in)
{
struct usbnet *dev = netdev_priv(skb_in->dev);
struct usb_cdc_ncm_nth16 *nth16;
int len;
int ret = -EINVAL;
if (ctx == NULL)
goto error;
if (skb_in->len < (sizeof(struct usb_cdc_ncm_nth16) +
sizeof(struct usb_cdc_ncm_ndp16))) {
netif_dbg(dev, rx_err, dev->net, "frame too short\n");
goto error;
}
nth16 = (struct usb_cdc_ncm_nth16 *)skb_in->data;
if (nth16->dwSignature != cpu_to_le32(USB_CDC_NCM_NTH16_SIGN)) {
netif_dbg(dev, rx_err, dev->net,
"invalid NTH16 signature <%#010x>\n",
le32_to_cpu(nth16->dwSignature));
goto error;
}
len = le16_to_cpu(nth16->wBlockLength);
if (len > ctx->rx_max) {
netif_dbg(dev, rx_err, dev->net,
"unsupported NTB block length %u/%u\n", len,
ctx->rx_max);
goto error;
}
if ((ctx->rx_seq + 1) != le16_to_cpu(nth16->wSequence) &&
(ctx->rx_seq || le16_to_cpu(nth16->wSequence)) &&
!((ctx->rx_seq == 0xffff) && !le16_to_cpu(nth16->wSequence))) {
netif_dbg(dev, rx_err, dev->net,
"sequence number glitch prev=%d curr=%d\n",
ctx->rx_seq, le16_to_cpu(nth16->wSequence));
}
ctx->rx_seq = le16_to_cpu(nth16->wSequence);
ret = le16_to_cpu(nth16->wNdpIndex);
error:
return ret;
}
int cdc_ncm_rx_verify_ndp16(struct sk_buff *skb_in, int ndpoffset)
{
struct usbnet *dev = netdev_priv(skb_in->dev);
struct usb_cdc_ncm_ndp16 *ndp16;
int ret = -EINVAL;
if ((ndpoffset + sizeof(struct usb_cdc_ncm_ndp16)) > skb_in->len) {
netif_dbg(dev, rx_err, dev->net, "invalid NDP offset <%u>\n",
ndpoffset);
goto error;
}
ndp16 = (struct usb_cdc_ncm_ndp16 *)(skb_in->data + ndpoffset);
if (le16_to_cpu(ndp16->wLength) < USB_CDC_NCM_NDP16_LENGTH_MIN) {
netif_dbg(dev, rx_err, dev->net, "invalid DPT16 length <%u>\n",
le16_to_cpu(ndp16->wLength));
goto error;
}
ret = ((le16_to_cpu(ndp16->wLength) -
sizeof(struct usb_cdc_ncm_ndp16)) /
sizeof(struct usb_cdc_ncm_dpe16));
ret--;
if ((sizeof(struct usb_cdc_ncm_ndp16) +
ret * (sizeof(struct usb_cdc_ncm_dpe16))) > skb_in->len) {
netif_dbg(dev, rx_err, dev->net, "Invalid nframes = %d\n", ret);
ret = -EINVAL;
}
error:
return ret;
}
int cdc_ncm_rx_fixup(struct usbnet *dev, struct sk_buff *skb_in)
{
struct sk_buff *skb;
struct cdc_ncm_ctx *ctx = (struct cdc_ncm_ctx *)dev->data[0];
int len;
int nframes;
int x;
int offset;
struct usb_cdc_ncm_ndp16 *ndp16;
struct usb_cdc_ncm_dpe16 *dpe16;
int ndpoffset;
int loopcount = 50;
u32 payload = 0;
ndpoffset = cdc_ncm_rx_verify_nth16(ctx, skb_in);
if (ndpoffset < 0)
goto error;
next_ndp:
nframes = cdc_ncm_rx_verify_ndp16(skb_in, ndpoffset);
if (nframes < 0)
goto error;
ndp16 = (struct usb_cdc_ncm_ndp16 *)(skb_in->data + ndpoffset);
if (ndp16->dwSignature != cpu_to_le32(USB_CDC_NCM_NDP16_NOCRC_SIGN)) {
netif_dbg(dev, rx_err, dev->net,
"invalid DPT16 signature <%#010x>\n",
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
if (((offset + len) > skb_in->len) ||
(len > ctx->rx_max) || (len < ETH_HLEN)) {
netif_dbg(dev, rx_err, dev->net,
"invalid frame detected (ignored) offset[%u]=%u, length=%u, skb=%p\n",
x, offset, len, skb_in);
if (!x)
goto err_ndp;
break;
} else {
skb = netdev_alloc_skb_ip_align(dev->net, len);
if (!skb)
goto error;
memcpy(skb_put(skb, len), skb_in->data + offset, len);
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
static void
cdc_ncm_speed_change(struct usbnet *dev,
struct usb_cdc_speed_change *data)
{
uint32_t rx_speed = le32_to_cpu(data->DLBitRRate);
uint32_t tx_speed = le32_to_cpu(data->ULBitRate);
if ((tx_speed > 1000000) && (rx_speed > 1000000)) {
netif_info(dev, link, dev->net,
"%u mbit/s downlink %u mbit/s uplink\n",
(unsigned int)(rx_speed / 1000000U),
(unsigned int)(tx_speed / 1000000U));
} else {
netif_info(dev, link, dev->net,
"%u kbit/s downlink %u kbit/s uplink\n",
(unsigned int)(rx_speed / 1000U),
(unsigned int)(tx_speed / 1000U));
}
}
static void cdc_ncm_status(struct usbnet *dev, struct urb *urb)
{
struct cdc_ncm_ctx *ctx;
struct usb_cdc_notification *event;
ctx = (struct cdc_ncm_ctx *)dev->data[0];
if (urb->actual_length < sizeof(*event))
return;
if (test_and_clear_bit(EVENT_STS_SPLIT, &dev->flags)) {
cdc_ncm_speed_change(dev,
(struct usb_cdc_speed_change *)urb->transfer_buffer);
return;
}
event = urb->transfer_buffer;
switch (event->bNotificationType) {
case USB_CDC_NOTIFY_NETWORK_CONNECTION:
netif_info(dev, link, dev->net,
"network connection: %sconnected\n",
!!event->wValue ? "" : "dis");
usbnet_link_change(dev, !!event->wValue, 0);
break;
case USB_CDC_NOTIFY_SPEED_CHANGE:
if (urb->actual_length < (sizeof(*event) +
sizeof(struct usb_cdc_speed_change)))
set_bit(EVENT_STS_SPLIT, &dev->flags);
else
cdc_ncm_speed_change(dev,
(struct usb_cdc_speed_change *)&event[1]);
break;
default:
dev_dbg(&dev->udev->dev,
"NCM: unexpected notification 0x%02x!\n",
event->bNotificationType);
break;
}
}
