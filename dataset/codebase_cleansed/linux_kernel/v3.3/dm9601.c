static int dm_read(struct usbnet *dev, u8 reg, u16 length, void *data)
{
void *buf;
int err = -ENOMEM;
netdev_dbg(dev->net, "dm_read() reg=0x%02x length=%d\n", reg, length);
buf = kmalloc(length, GFP_KERNEL);
if (!buf)
goto out;
err = usb_control_msg(dev->udev,
usb_rcvctrlpipe(dev->udev, 0),
DM_READ_REGS,
USB_DIR_IN | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
0, reg, buf, length, USB_CTRL_SET_TIMEOUT);
if (err == length)
memcpy(data, buf, length);
else if (err >= 0)
err = -EINVAL;
kfree(buf);
out:
return err;
}
static int dm_read_reg(struct usbnet *dev, u8 reg, u8 *value)
{
return dm_read(dev, reg, 1, value);
}
static int dm_write(struct usbnet *dev, u8 reg, u16 length, void *data)
{
void *buf = NULL;
int err = -ENOMEM;
netdev_dbg(dev->net, "dm_write() reg=0x%02x, length=%d\n", reg, length);
if (data) {
buf = kmemdup(data, length, GFP_KERNEL);
if (!buf)
goto out;
}
err = usb_control_msg(dev->udev,
usb_sndctrlpipe(dev->udev, 0),
DM_WRITE_REGS,
USB_DIR_OUT | USB_TYPE_VENDOR |USB_RECIP_DEVICE,
0, reg, buf, length, USB_CTRL_SET_TIMEOUT);
kfree(buf);
if (err >= 0 && err < length)
err = -EINVAL;
out:
return err;
}
static int dm_write_reg(struct usbnet *dev, u8 reg, u8 value)
{
netdev_dbg(dev->net, "dm_write_reg() reg=0x%02x, value=0x%02x\n",
reg, value);
return usb_control_msg(dev->udev,
usb_sndctrlpipe(dev->udev, 0),
DM_WRITE_REG,
USB_DIR_OUT | USB_TYPE_VENDOR |USB_RECIP_DEVICE,
value, reg, NULL, 0, USB_CTRL_SET_TIMEOUT);
}
static void dm_write_async_callback(struct urb *urb)
{
struct usb_ctrlrequest *req = (struct usb_ctrlrequest *)urb->context;
int status = urb->status;
if (status < 0)
printk(KERN_DEBUG "dm_write_async_callback() failed with %d\n",
status);
kfree(req);
usb_free_urb(urb);
}
static void dm_write_async_helper(struct usbnet *dev, u8 reg, u8 value,
u16 length, void *data)
{
struct usb_ctrlrequest *req;
struct urb *urb;
int status;
urb = usb_alloc_urb(0, GFP_ATOMIC);
if (!urb) {
netdev_err(dev->net, "Error allocating URB in dm_write_async_helper!\n");
return;
}
req = kmalloc(sizeof(struct usb_ctrlrequest), GFP_ATOMIC);
if (!req) {
netdev_err(dev->net, "Failed to allocate memory for control request\n");
usb_free_urb(urb);
return;
}
req->bRequestType = USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_DEVICE;
req->bRequest = length ? DM_WRITE_REGS : DM_WRITE_REG;
req->wValue = cpu_to_le16(value);
req->wIndex = cpu_to_le16(reg);
req->wLength = cpu_to_le16(length);
usb_fill_control_urb(urb, dev->udev,
usb_sndctrlpipe(dev->udev, 0),
(void *)req, data, length,
dm_write_async_callback, req);
status = usb_submit_urb(urb, GFP_ATOMIC);
if (status < 0) {
netdev_err(dev->net, "Error submitting the control message: status=%d\n",
status);
kfree(req);
usb_free_urb(urb);
}
}
static void dm_write_async(struct usbnet *dev, u8 reg, u16 length, void *data)
{
netdev_dbg(dev->net, "dm_write_async() reg=0x%02x length=%d\n", reg, length);
dm_write_async_helper(dev, reg, 0, length, data);
}
static void dm_write_reg_async(struct usbnet *dev, u8 reg, u8 value)
{
netdev_dbg(dev->net, "dm_write_reg_async() reg=0x%02x value=0x%02x\n",
reg, value);
dm_write_async_helper(dev, reg, value, 0, NULL);
}
static int dm_read_shared_word(struct usbnet *dev, int phy, u8 reg, __le16 *value)
{
int ret, i;
mutex_lock(&dev->phy_mutex);
dm_write_reg(dev, DM_SHARED_ADDR, phy ? (reg | 0x40) : reg);
dm_write_reg(dev, DM_SHARED_CTRL, phy ? 0xc : 0x4);
for (i = 0; i < DM_TIMEOUT; i++) {
u8 tmp;
udelay(1);
ret = dm_read_reg(dev, DM_SHARED_CTRL, &tmp);
if (ret < 0)
goto out;
if ((tmp & 1) == 0)
break;
}
if (i == DM_TIMEOUT) {
netdev_err(dev->net, "%s read timed out!\n", phy ? "phy" : "eeprom");
ret = -EIO;
goto out;
}
dm_write_reg(dev, DM_SHARED_CTRL, 0x0);
ret = dm_read(dev, DM_SHARED_DATA, 2, value);
netdev_dbg(dev->net, "read shared %d 0x%02x returned 0x%04x, %d\n",
phy, reg, *value, ret);
out:
mutex_unlock(&dev->phy_mutex);
return ret;
}
static int dm_write_shared_word(struct usbnet *dev, int phy, u8 reg, __le16 value)
{
int ret, i;
mutex_lock(&dev->phy_mutex);
ret = dm_write(dev, DM_SHARED_DATA, 2, &value);
if (ret < 0)
goto out;
dm_write_reg(dev, DM_SHARED_ADDR, phy ? (reg | 0x40) : reg);
dm_write_reg(dev, DM_SHARED_CTRL, phy ? 0x1a : 0x12);
for (i = 0; i < DM_TIMEOUT; i++) {
u8 tmp;
udelay(1);
ret = dm_read_reg(dev, DM_SHARED_CTRL, &tmp);
if (ret < 0)
goto out;
if ((tmp & 1) == 0)
break;
}
if (i == DM_TIMEOUT) {
netdev_err(dev->net, "%s write timed out!\n", phy ? "phy" : "eeprom");
ret = -EIO;
goto out;
}
dm_write_reg(dev, DM_SHARED_CTRL, 0x0);
out:
mutex_unlock(&dev->phy_mutex);
return ret;
}
static int dm_read_eeprom_word(struct usbnet *dev, u8 offset, void *value)
{
return dm_read_shared_word(dev, 0, offset, value);
}
static int dm9601_get_eeprom_len(struct net_device *dev)
{
return DM_EEPROM_LEN;
}
static int dm9601_get_eeprom(struct net_device *net,
struct ethtool_eeprom *eeprom, u8 * data)
{
struct usbnet *dev = netdev_priv(net);
__le16 *ebuf = (__le16 *) data;
int i;
if ((eeprom->offset % 2) || (eeprom->len % 2))
return -EINVAL;
for (i = 0; i < eeprom->len / 2; i++) {
if (dm_read_eeprom_word(dev, eeprom->offset / 2 + i,
&ebuf[i]) < 0)
return -EINVAL;
}
return 0;
}
static int dm9601_mdio_read(struct net_device *netdev, int phy_id, int loc)
{
struct usbnet *dev = netdev_priv(netdev);
__le16 res;
if (phy_id) {
netdev_dbg(dev->net, "Only internal phy supported\n");
return 0;
}
dm_read_shared_word(dev, 1, loc, &res);
netdev_dbg(dev->net,
"dm9601_mdio_read() phy_id=0x%02x, loc=0x%02x, returns=0x%04x\n",
phy_id, loc, le16_to_cpu(res));
return le16_to_cpu(res);
}
static void dm9601_mdio_write(struct net_device *netdev, int phy_id, int loc,
int val)
{
struct usbnet *dev = netdev_priv(netdev);
__le16 res = cpu_to_le16(val);
if (phy_id) {
netdev_dbg(dev->net, "Only internal phy supported\n");
return;
}
netdev_dbg(dev->net, "dm9601_mdio_write() phy_id=0x%02x, loc=0x%02x, val=0x%04x\n",
phy_id, loc, val);
dm_write_shared_word(dev, 1, loc, res);
}
static void dm9601_get_drvinfo(struct net_device *net,
struct ethtool_drvinfo *info)
{
usbnet_get_drvinfo(net, info);
info->eedump_len = DM_EEPROM_LEN;
}
static u32 dm9601_get_link(struct net_device *net)
{
struct usbnet *dev = netdev_priv(net);
return mii_link_ok(&dev->mii);
}
static int dm9601_ioctl(struct net_device *net, struct ifreq *rq, int cmd)
{
struct usbnet *dev = netdev_priv(net);
return generic_mii_ioctl(&dev->mii, if_mii(rq), cmd, NULL);
}
static void dm9601_set_multicast(struct net_device *net)
{
struct usbnet *dev = netdev_priv(net);
u8 *hashes = (u8 *) & dev->data;
u8 rx_ctl = 0x31;
memset(hashes, 0x00, DM_MCAST_SIZE);
hashes[DM_MCAST_SIZE - 1] |= 0x80;
if (net->flags & IFF_PROMISC) {
rx_ctl |= 0x02;
} else if (net->flags & IFF_ALLMULTI ||
netdev_mc_count(net) > DM_MAX_MCAST) {
rx_ctl |= 0x04;
} else if (!netdev_mc_empty(net)) {
struct netdev_hw_addr *ha;
netdev_for_each_mc_addr(ha, net) {
u32 crc = ether_crc(ETH_ALEN, ha->addr) >> 26;
hashes[crc >> 3] |= 1 << (crc & 0x7);
}
}
dm_write_async(dev, DM_MCAST_ADDR, DM_MCAST_SIZE, hashes);
dm_write_reg_async(dev, DM_RX_CTRL, rx_ctl);
}
static void __dm9601_set_mac_address(struct usbnet *dev)
{
dm_write_async(dev, DM_PHY_ADDR, ETH_ALEN, dev->net->dev_addr);
}
static int dm9601_set_mac_address(struct net_device *net, void *p)
{
struct sockaddr *addr = p;
struct usbnet *dev = netdev_priv(net);
if (!is_valid_ether_addr(addr->sa_data)) {
dev_err(&net->dev, "not setting invalid mac address %pM\n",
addr->sa_data);
return -EINVAL;
}
memcpy(net->dev_addr, addr->sa_data, net->addr_len);
__dm9601_set_mac_address(dev);
return 0;
}
static int dm9601_bind(struct usbnet *dev, struct usb_interface *intf)
{
int ret;
u8 mac[ETH_ALEN];
ret = usbnet_get_endpoints(dev, intf);
if (ret)
goto out;
dev->net->netdev_ops = &dm9601_netdev_ops;
dev->net->ethtool_ops = &dm9601_ethtool_ops;
dev->net->hard_header_len += DM_TX_OVERHEAD;
dev->hard_mtu = dev->net->mtu + dev->net->hard_header_len;
dev->rx_urb_size = dev->net->mtu + ETH_HLEN + DM_RX_OVERHEAD;
dev->mii.dev = dev->net;
dev->mii.mdio_read = dm9601_mdio_read;
dev->mii.mdio_write = dm9601_mdio_write;
dev->mii.phy_id_mask = 0x1f;
dev->mii.reg_num_mask = 0x1f;
dm_write_reg(dev, DM_NET_CTRL, 1);
udelay(20);
if (dm_read(dev, DM_PHY_ADDR, ETH_ALEN, mac) < 0) {
printk(KERN_ERR "Error reading MAC address\n");
ret = -ENODEV;
goto out;
}
if (is_valid_ether_addr(mac))
memcpy(dev->net->dev_addr, mac, ETH_ALEN);
else {
printk(KERN_WARNING
"dm9601: No valid MAC address in EEPROM, using %pM\n",
dev->net->dev_addr);
__dm9601_set_mac_address(dev);
}
dm_write_reg(dev, DM_GPR_CTRL, 1);
dm_write_reg(dev, DM_GPR_DATA, 0);
dm9601_set_multicast(dev->net);
dm9601_mdio_write(dev->net, dev->mii.phy_id, MII_BMCR, BMCR_RESET);
dm9601_mdio_write(dev->net, dev->mii.phy_id, MII_ADVERTISE,
ADVERTISE_ALL | ADVERTISE_CSMA | ADVERTISE_PAUSE_CAP);
mii_nway_restart(&dev->mii);
out:
return ret;
}
static int dm9601_rx_fixup(struct usbnet *dev, struct sk_buff *skb)
{
u8 status;
int len;
if (unlikely(skb->len < DM_RX_OVERHEAD)) {
dev_err(&dev->udev->dev, "unexpected tiny rx frame\n");
return 0;
}
status = skb->data[0];
len = (skb->data[1] | (skb->data[2] << 8)) - 4;
if (unlikely(status & 0xbf)) {
if (status & 0x01) dev->net->stats.rx_fifo_errors++;
if (status & 0x02) dev->net->stats.rx_crc_errors++;
if (status & 0x04) dev->net->stats.rx_frame_errors++;
if (status & 0x20) dev->net->stats.rx_missed_errors++;
if (status & 0x90) dev->net->stats.rx_length_errors++;
return 0;
}
skb_pull(skb, 3);
skb_trim(skb, len);
return 1;
}
static struct sk_buff *dm9601_tx_fixup(struct usbnet *dev, struct sk_buff *skb,
gfp_t flags)
{
int len;
len = skb->len;
if (skb_headroom(skb) < DM_TX_OVERHEAD) {
struct sk_buff *skb2;
skb2 = skb_copy_expand(skb, DM_TX_OVERHEAD, 0, flags);
dev_kfree_skb_any(skb);
skb = skb2;
if (!skb)
return NULL;
}
__skb_push(skb, DM_TX_OVERHEAD);
if ((skb->len % dev->maxpacket) == 0)
len++;
skb->data[0] = len;
skb->data[1] = len >> 8;
return skb;
}
static void dm9601_status(struct usbnet *dev, struct urb *urb)
{
int link;
u8 *buf;
if (urb->actual_length < 8)
return;
buf = urb->transfer_buffer;
link = !!(buf[0] & 0x40);
if (netif_carrier_ok(dev->net) != link) {
if (link) {
netif_carrier_on(dev->net);
usbnet_defer_kevent (dev, EVENT_LINK_RESET);
}
else
netif_carrier_off(dev->net);
netdev_dbg(dev->net, "Link Status is: %d\n", link);
}
}
static int dm9601_link_reset(struct usbnet *dev)
{
struct ethtool_cmd ecmd = { .cmd = ETHTOOL_GSET };
mii_check_media(&dev->mii, 1, 1);
mii_ethtool_gset(&dev->mii, &ecmd);
netdev_dbg(dev->net, "link_reset() speed: %u duplex: %d\n",
ethtool_cmd_speed(&ecmd), ecmd.duplex);
return 0;
}
