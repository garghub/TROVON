static int asix_read_cmd(struct usbnet *dev, u8 cmd, u16 value, u16 index,
u16 size, void *data)
{
void *buf;
int err = -ENOMEM;
netdev_dbg(dev->net, "asix_read_cmd() cmd=0x%02x value=0x%04x index=0x%04x size=%d\n",
cmd, value, index, size);
buf = kmalloc(size, GFP_KERNEL);
if (!buf)
goto out;
err = usb_control_msg(
dev->udev,
usb_rcvctrlpipe(dev->udev, 0),
cmd,
USB_DIR_IN | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
value,
index,
buf,
size,
USB_CTRL_GET_TIMEOUT);
if (err == size)
memcpy(data, buf, size);
else if (err >= 0)
err = -EINVAL;
kfree(buf);
out:
return err;
}
static int asix_write_cmd(struct usbnet *dev, u8 cmd, u16 value, u16 index,
u16 size, void *data)
{
void *buf = NULL;
int err = -ENOMEM;
netdev_dbg(dev->net, "asix_write_cmd() cmd=0x%02x value=0x%04x index=0x%04x size=%d\n",
cmd, value, index, size);
if (data) {
buf = kmemdup(data, size, GFP_KERNEL);
if (!buf)
goto out;
}
err = usb_control_msg(
dev->udev,
usb_sndctrlpipe(dev->udev, 0),
cmd,
USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
value,
index,
buf,
size,
USB_CTRL_SET_TIMEOUT);
kfree(buf);
out:
return err;
}
static void asix_async_cmd_callback(struct urb *urb)
{
struct usb_ctrlrequest *req = (struct usb_ctrlrequest *)urb->context;
int status = urb->status;
if (status < 0)
printk(KERN_DEBUG "asix_async_cmd_callback() failed with %d",
status);
kfree(req);
usb_free_urb(urb);
}
static void
asix_write_cmd_async(struct usbnet *dev, u8 cmd, u16 value, u16 index,
u16 size, void *data)
{
struct usb_ctrlrequest *req;
int status;
struct urb *urb;
netdev_dbg(dev->net, "asix_write_cmd_async() cmd=0x%02x value=0x%04x index=0x%04x size=%d\n",
cmd, value, index, size);
urb = usb_alloc_urb(0, GFP_ATOMIC);
if (!urb) {
netdev_err(dev->net, "Error allocating URB in write_cmd_async!\n");
return;
}
req = kmalloc(sizeof(struct usb_ctrlrequest), GFP_ATOMIC);
if (!req) {
netdev_err(dev->net, "Failed to allocate memory for control request\n");
usb_free_urb(urb);
return;
}
req->bRequestType = USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_DEVICE;
req->bRequest = cmd;
req->wValue = cpu_to_le16(value);
req->wIndex = cpu_to_le16(index);
req->wLength = cpu_to_le16(size);
usb_fill_control_urb(urb, dev->udev,
usb_sndctrlpipe(dev->udev, 0),
(void *)req, data, size,
asix_async_cmd_callback, req);
status = usb_submit_urb(urb, GFP_ATOMIC);
if (status < 0) {
netdev_err(dev->net, "Error submitting the control message: status=%d\n",
status);
kfree(req);
usb_free_urb(urb);
}
}
static int asix_rx_fixup(struct usbnet *dev, struct sk_buff *skb)
{
int offset = 0;
while (offset + sizeof(u32) < skb->len) {
struct sk_buff *ax_skb;
u16 size;
u32 header = get_unaligned_le32(skb->data + offset);
offset += sizeof(u32);
size = (u16) (header & 0x7ff);
if (size != ((~header >> 16) & 0x07ff)) {
netdev_err(dev->net, "asix_rx_fixup() Bad Header Length\n");
return 0;
}
if ((size > dev->net->mtu + ETH_HLEN + VLAN_HLEN) ||
(size + offset > skb->len)) {
netdev_err(dev->net, "asix_rx_fixup() Bad RX Length %d\n",
size);
return 0;
}
ax_skb = netdev_alloc_skb_ip_align(dev->net, size);
if (!ax_skb)
return 0;
skb_put(ax_skb, size);
memcpy(ax_skb->data, skb->data + offset, size);
usbnet_skb_return(dev, ax_skb);
offset += (size + 1) & 0xfffe;
}
if (skb->len != offset) {
netdev_err(dev->net, "asix_rx_fixup() Bad SKB Length %d\n",
skb->len);
return 0;
}
return 1;
}
static struct sk_buff *asix_tx_fixup(struct usbnet *dev, struct sk_buff *skb,
gfp_t flags)
{
int padlen;
int headroom = skb_headroom(skb);
int tailroom = skb_tailroom(skb);
u32 packet_len;
u32 padbytes = 0xffff0000;
padlen = ((skb->len + 4) & (dev->maxpacket - 1)) ? 0 : 4;
if ((!skb_cloned(skb)) &&
((headroom + tailroom) >= (4 + padlen))) {
if ((headroom < 4) || (tailroom < padlen)) {
skb->data = memmove(skb->head + 4, skb->data, skb->len);
skb_set_tail_pointer(skb, skb->len);
}
} else {
struct sk_buff *skb2;
skb2 = skb_copy_expand(skb, 4, padlen, flags);
dev_kfree_skb_any(skb);
skb = skb2;
if (!skb)
return NULL;
}
skb_push(skb, 4);
packet_len = (((skb->len - 4) ^ 0x0000ffff) << 16) + (skb->len - 4);
cpu_to_le32s(&packet_len);
skb_copy_to_linear_data(skb, &packet_len, sizeof(packet_len));
if (padlen) {
cpu_to_le32s(&padbytes);
memcpy(skb_tail_pointer(skb), &padbytes, sizeof(padbytes));
skb_put(skb, sizeof(padbytes));
}
return skb;
}
static void asix_status(struct usbnet *dev, struct urb *urb)
{
struct ax88172_int_data *event;
int link;
if (urb->actual_length < 8)
return;
event = urb->transfer_buffer;
link = event->link & 0x01;
if (netif_carrier_ok(dev->net) != link) {
if (link) {
netif_carrier_on(dev->net);
usbnet_defer_kevent (dev, EVENT_LINK_RESET );
} else
netif_carrier_off(dev->net);
netdev_dbg(dev->net, "Link Status is: %d\n", link);
}
}
static inline int asix_set_sw_mii(struct usbnet *dev)
{
int ret;
ret = asix_write_cmd(dev, AX_CMD_SET_SW_MII, 0x0000, 0, 0, NULL);
if (ret < 0)
netdev_err(dev->net, "Failed to enable software MII access\n");
return ret;
}
static inline int asix_set_hw_mii(struct usbnet *dev)
{
int ret;
ret = asix_write_cmd(dev, AX_CMD_SET_HW_MII, 0x0000, 0, 0, NULL);
if (ret < 0)
netdev_err(dev->net, "Failed to enable hardware MII access\n");
return ret;
}
static inline int asix_get_phy_addr(struct usbnet *dev)
{
u8 buf[2];
int ret = asix_read_cmd(dev, AX_CMD_READ_PHY_ID, 0, 0, 2, buf);
netdev_dbg(dev->net, "asix_get_phy_addr()\n");
if (ret < 0) {
netdev_err(dev->net, "Error reading PHYID register: %02x\n", ret);
goto out;
}
netdev_dbg(dev->net, "asix_get_phy_addr() returning 0x%04x\n",
*((__le16 *)buf));
ret = buf[1];
out:
return ret;
}
static int asix_sw_reset(struct usbnet *dev, u8 flags)
{
int ret;
ret = asix_write_cmd(dev, AX_CMD_SW_RESET, flags, 0, 0, NULL);
if (ret < 0)
netdev_err(dev->net, "Failed to send software reset: %02x\n", ret);
return ret;
}
static u16 asix_read_rx_ctl(struct usbnet *dev)
{
__le16 v;
int ret = asix_read_cmd(dev, AX_CMD_READ_RX_CTL, 0, 0, 2, &v);
if (ret < 0) {
netdev_err(dev->net, "Error reading RX_CTL register: %02x\n", ret);
goto out;
}
ret = le16_to_cpu(v);
out:
return ret;
}
static int asix_write_rx_ctl(struct usbnet *dev, u16 mode)
{
int ret;
netdev_dbg(dev->net, "asix_write_rx_ctl() - mode = 0x%04x\n", mode);
ret = asix_write_cmd(dev, AX_CMD_WRITE_RX_CTL, mode, 0, 0, NULL);
if (ret < 0)
netdev_err(dev->net, "Failed to write RX_CTL mode to 0x%04x: %02x\n",
mode, ret);
return ret;
}
static u16 asix_read_medium_status(struct usbnet *dev)
{
__le16 v;
int ret = asix_read_cmd(dev, AX_CMD_READ_MEDIUM_STATUS, 0, 0, 2, &v);
if (ret < 0) {
netdev_err(dev->net, "Error reading Medium Status register: %02x\n",
ret);
return ret;
}
return le16_to_cpu(v);
}
static int asix_write_medium_mode(struct usbnet *dev, u16 mode)
{
int ret;
netdev_dbg(dev->net, "asix_write_medium_mode() - mode = 0x%04x\n", mode);
ret = asix_write_cmd(dev, AX_CMD_WRITE_MEDIUM_MODE, mode, 0, 0, NULL);
if (ret < 0)
netdev_err(dev->net, "Failed to write Medium Mode mode to 0x%04x: %02x\n",
mode, ret);
return ret;
}
static int asix_write_gpio(struct usbnet *dev, u16 value, int sleep)
{
int ret;
netdev_dbg(dev->net, "asix_write_gpio() - value = 0x%04x\n", value);
ret = asix_write_cmd(dev, AX_CMD_WRITE_GPIOS, value, 0, 0, NULL);
if (ret < 0)
netdev_err(dev->net, "Failed to write GPIO value 0x%04x: %02x\n",
value, ret);
if (sleep)
msleep(sleep);
return ret;
}
static void asix_set_multicast(struct net_device *net)
{
struct usbnet *dev = netdev_priv(net);
struct asix_data *data = (struct asix_data *)&dev->data;
u16 rx_ctl = AX_DEFAULT_RX_CTL;
if (net->flags & IFF_PROMISC) {
rx_ctl |= AX_RX_CTL_PRO;
} else if (net->flags & IFF_ALLMULTI ||
netdev_mc_count(net) > AX_MAX_MCAST) {
rx_ctl |= AX_RX_CTL_AMALL;
} else if (netdev_mc_empty(net)) {
} else {
struct netdev_hw_addr *ha;
u32 crc_bits;
memset(data->multi_filter, 0, AX_MCAST_FILTER_SIZE);
netdev_for_each_mc_addr(ha, net) {
crc_bits = ether_crc(ETH_ALEN, ha->addr) >> 26;
data->multi_filter[crc_bits >> 3] |=
1 << (crc_bits & 7);
}
asix_write_cmd_async(dev, AX_CMD_WRITE_MULTI_FILTER, 0, 0,
AX_MCAST_FILTER_SIZE, data->multi_filter);
rx_ctl |= AX_RX_CTL_AM;
}
asix_write_cmd_async(dev, AX_CMD_WRITE_RX_CTL, rx_ctl, 0, 0, NULL);
}
static int asix_mdio_read(struct net_device *netdev, int phy_id, int loc)
{
struct usbnet *dev = netdev_priv(netdev);
__le16 res;
mutex_lock(&dev->phy_mutex);
asix_set_sw_mii(dev);
asix_read_cmd(dev, AX_CMD_READ_MII_REG, phy_id,
(__u16)loc, 2, &res);
asix_set_hw_mii(dev);
mutex_unlock(&dev->phy_mutex);
netdev_dbg(dev->net, "asix_mdio_read() phy_id=0x%02x, loc=0x%02x, returns=0x%04x\n",
phy_id, loc, le16_to_cpu(res));
return le16_to_cpu(res);
}
static void
asix_mdio_write(struct net_device *netdev, int phy_id, int loc, int val)
{
struct usbnet *dev = netdev_priv(netdev);
__le16 res = cpu_to_le16(val);
netdev_dbg(dev->net, "asix_mdio_write() phy_id=0x%02x, loc=0x%02x, val=0x%04x\n",
phy_id, loc, val);
mutex_lock(&dev->phy_mutex);
asix_set_sw_mii(dev);
asix_write_cmd(dev, AX_CMD_WRITE_MII_REG, phy_id, (__u16)loc, 2, &res);
asix_set_hw_mii(dev);
mutex_unlock(&dev->phy_mutex);
}
static u32 asix_get_phyid(struct usbnet *dev)
{
int phy_reg;
u32 phy_id;
int i;
for (i = 0; i < 100; i++) {
phy_reg = asix_mdio_read(dev->net, dev->mii.phy_id, MII_PHYSID1);
if (phy_reg != 0 && phy_reg != 0xFFFF)
break;
mdelay(1);
}
if (phy_reg <= 0 || phy_reg == 0xFFFF)
return 0;
phy_id = (phy_reg & 0xffff) << 16;
phy_reg = asix_mdio_read(dev->net, dev->mii.phy_id, MII_PHYSID2);
if (phy_reg < 0)
return 0;
phy_id |= (phy_reg & 0xffff);
return phy_id;
}
static void
asix_get_wol(struct net_device *net, struct ethtool_wolinfo *wolinfo)
{
struct usbnet *dev = netdev_priv(net);
u8 opt;
if (asix_read_cmd(dev, AX_CMD_READ_MONITOR_MODE, 0, 0, 1, &opt) < 0) {
wolinfo->supported = 0;
wolinfo->wolopts = 0;
return;
}
wolinfo->supported = WAKE_PHY | WAKE_MAGIC;
wolinfo->wolopts = 0;
if (opt & AX_MONITOR_LINK)
wolinfo->wolopts |= WAKE_PHY;
if (opt & AX_MONITOR_MAGIC)
wolinfo->wolopts |= WAKE_MAGIC;
}
static int
asix_set_wol(struct net_device *net, struct ethtool_wolinfo *wolinfo)
{
struct usbnet *dev = netdev_priv(net);
u8 opt = 0;
if (wolinfo->wolopts & WAKE_PHY)
opt |= AX_MONITOR_LINK;
if (wolinfo->wolopts & WAKE_MAGIC)
opt |= AX_MONITOR_MAGIC;
if (asix_write_cmd(dev, AX_CMD_WRITE_MONITOR_MODE,
opt, 0, 0, NULL) < 0)
return -EINVAL;
return 0;
}
static int asix_get_eeprom_len(struct net_device *net)
{
struct usbnet *dev = netdev_priv(net);
struct asix_data *data = (struct asix_data *)&dev->data;
return data->eeprom_len;
}
static int asix_get_eeprom(struct net_device *net,
struct ethtool_eeprom *eeprom, u8 *data)
{
struct usbnet *dev = netdev_priv(net);
__le16 *ebuf = (__le16 *)data;
int i;
if (eeprom->len % 2)
return -EINVAL;
eeprom->magic = AX_EEPROM_MAGIC;
for (i=0; i < eeprom->len / 2; i++) {
if (asix_read_cmd(dev, AX_CMD_READ_EEPROM,
eeprom->offset + i, 0, 2, &ebuf[i]) < 0)
return -EINVAL;
}
return 0;
}
static void asix_get_drvinfo (struct net_device *net,
struct ethtool_drvinfo *info)
{
struct usbnet *dev = netdev_priv(net);
struct asix_data *data = (struct asix_data *)&dev->data;
usbnet_get_drvinfo(net, info);
strncpy (info->driver, DRIVER_NAME, sizeof info->driver);
strncpy (info->version, DRIVER_VERSION, sizeof info->version);
info->eedump_len = data->eeprom_len;
}
static u32 asix_get_link(struct net_device *net)
{
struct usbnet *dev = netdev_priv(net);
return mii_link_ok(&dev->mii);
}
static int asix_ioctl (struct net_device *net, struct ifreq *rq, int cmd)
{
struct usbnet *dev = netdev_priv(net);
return generic_mii_ioctl(&dev->mii, if_mii(rq), cmd, NULL);
}
static int asix_set_mac_address(struct net_device *net, void *p)
{
struct usbnet *dev = netdev_priv(net);
struct asix_data *data = (struct asix_data *)&dev->data;
struct sockaddr *addr = p;
if (netif_running(net))
return -EBUSY;
if (!is_valid_ether_addr(addr->sa_data))
return -EADDRNOTAVAIL;
memcpy(net->dev_addr, addr->sa_data, ETH_ALEN);
memcpy(data->mac_addr, addr->sa_data, ETH_ALEN);
asix_write_cmd_async(dev, AX_CMD_WRITE_NODE_ID, 0, 0, ETH_ALEN,
data->mac_addr);
return 0;
}
static void ax88172_set_multicast(struct net_device *net)
{
struct usbnet *dev = netdev_priv(net);
struct asix_data *data = (struct asix_data *)&dev->data;
u8 rx_ctl = 0x8c;
if (net->flags & IFF_PROMISC) {
rx_ctl |= 0x01;
} else if (net->flags & IFF_ALLMULTI ||
netdev_mc_count(net) > AX_MAX_MCAST) {
rx_ctl |= 0x02;
} else if (netdev_mc_empty(net)) {
} else {
struct netdev_hw_addr *ha;
u32 crc_bits;
memset(data->multi_filter, 0, AX_MCAST_FILTER_SIZE);
netdev_for_each_mc_addr(ha, net) {
crc_bits = ether_crc(ETH_ALEN, ha->addr) >> 26;
data->multi_filter[crc_bits >> 3] |=
1 << (crc_bits & 7);
}
asix_write_cmd_async(dev, AX_CMD_WRITE_MULTI_FILTER, 0, 0,
AX_MCAST_FILTER_SIZE, data->multi_filter);
rx_ctl |= 0x10;
}
asix_write_cmd_async(dev, AX_CMD_WRITE_RX_CTL, rx_ctl, 0, 0, NULL);
}
static int ax88172_link_reset(struct usbnet *dev)
{
u8 mode;
struct ethtool_cmd ecmd = { .cmd = ETHTOOL_GSET };
mii_check_media(&dev->mii, 1, 1);
mii_ethtool_gset(&dev->mii, &ecmd);
mode = AX88172_MEDIUM_DEFAULT;
if (ecmd.duplex != DUPLEX_FULL)
mode |= ~AX88172_MEDIUM_FD;
netdev_dbg(dev->net, "ax88172_link_reset() speed: %u duplex: %d setting mode to 0x%04x\n",
ethtool_cmd_speed(&ecmd), ecmd.duplex, mode);
asix_write_medium_mode(dev, mode);
return 0;
}
static int ax88172_bind(struct usbnet *dev, struct usb_interface *intf)
{
int ret = 0;
u8 buf[ETH_ALEN];
int i;
unsigned long gpio_bits = dev->driver_info->data;
struct asix_data *data = (struct asix_data *)&dev->data;
data->eeprom_len = AX88172_EEPROM_LEN;
usbnet_get_endpoints(dev,intf);
for (i = 2; i >= 0; i--) {
ret = asix_write_cmd(dev, AX_CMD_WRITE_GPIOS,
(gpio_bits >> (i * 8)) & 0xff, 0, 0, NULL);
if (ret < 0)
goto out;
msleep(5);
}
ret = asix_write_rx_ctl(dev, 0x80);
if (ret < 0)
goto out;
ret = asix_read_cmd(dev, AX88172_CMD_READ_NODE_ID, 0, 0, ETH_ALEN, buf);
if (ret < 0) {
dbg("read AX_CMD_READ_NODE_ID failed: %d", ret);
goto out;
}
memcpy(dev->net->dev_addr, buf, ETH_ALEN);
dev->mii.dev = dev->net;
dev->mii.mdio_read = asix_mdio_read;
dev->mii.mdio_write = asix_mdio_write;
dev->mii.phy_id_mask = 0x3f;
dev->mii.reg_num_mask = 0x1f;
dev->mii.phy_id = asix_get_phy_addr(dev);
dev->net->netdev_ops = &ax88172_netdev_ops;
dev->net->ethtool_ops = &ax88172_ethtool_ops;
asix_mdio_write(dev->net, dev->mii.phy_id, MII_BMCR, BMCR_RESET);
asix_mdio_write(dev->net, dev->mii.phy_id, MII_ADVERTISE,
ADVERTISE_ALL | ADVERTISE_CSMA | ADVERTISE_PAUSE_CAP);
mii_nway_restart(&dev->mii);
return 0;
out:
return ret;
}
static int ax88772_link_reset(struct usbnet *dev)
{
u16 mode;
struct ethtool_cmd ecmd = { .cmd = ETHTOOL_GSET };
mii_check_media(&dev->mii, 1, 1);
mii_ethtool_gset(&dev->mii, &ecmd);
mode = AX88772_MEDIUM_DEFAULT;
if (ethtool_cmd_speed(&ecmd) != SPEED_100)
mode &= ~AX_MEDIUM_PS;
if (ecmd.duplex != DUPLEX_FULL)
mode &= ~AX_MEDIUM_FD;
netdev_dbg(dev->net, "ax88772_link_reset() speed: %u duplex: %d setting mode to 0x%04x\n",
ethtool_cmd_speed(&ecmd), ecmd.duplex, mode);
asix_write_medium_mode(dev, mode);
return 0;
}
static int ax88772_reset(struct usbnet *dev)
{
struct asix_data *data = (struct asix_data *)&dev->data;
int ret, embd_phy;
u16 rx_ctl;
ret = asix_write_gpio(dev,
AX_GPIO_RSE | AX_GPIO_GPO_2 | AX_GPIO_GPO2EN, 5);
if (ret < 0)
goto out;
embd_phy = ((asix_get_phy_addr(dev) & 0x1f) == 0x10 ? 1 : 0);
ret = asix_write_cmd(dev, AX_CMD_SW_PHY_SELECT, embd_phy, 0, 0, NULL);
if (ret < 0) {
dbg("Select PHY #1 failed: %d", ret);
goto out;
}
ret = asix_sw_reset(dev, AX_SWRESET_IPPD | AX_SWRESET_PRL);
if (ret < 0)
goto out;
msleep(150);
ret = asix_sw_reset(dev, AX_SWRESET_CLEAR);
if (ret < 0)
goto out;
msleep(150);
if (embd_phy) {
ret = asix_sw_reset(dev, AX_SWRESET_IPRL);
if (ret < 0)
goto out;
} else {
ret = asix_sw_reset(dev, AX_SWRESET_PRTE);
if (ret < 0)
goto out;
}
msleep(150);
rx_ctl = asix_read_rx_ctl(dev);
dbg("RX_CTL is 0x%04x after software reset", rx_ctl);
ret = asix_write_rx_ctl(dev, 0x0000);
if (ret < 0)
goto out;
rx_ctl = asix_read_rx_ctl(dev);
dbg("RX_CTL is 0x%04x setting to 0x0000", rx_ctl);
ret = asix_sw_reset(dev, AX_SWRESET_PRL);
if (ret < 0)
goto out;
msleep(150);
ret = asix_sw_reset(dev, AX_SWRESET_IPRL | AX_SWRESET_PRL);
if (ret < 0)
goto out;
msleep(150);
asix_mdio_write(dev->net, dev->mii.phy_id, MII_BMCR, BMCR_RESET);
asix_mdio_write(dev->net, dev->mii.phy_id, MII_ADVERTISE,
ADVERTISE_ALL | ADVERTISE_CSMA);
mii_nway_restart(&dev->mii);
ret = asix_write_medium_mode(dev, AX88772_MEDIUM_DEFAULT);
if (ret < 0)
goto out;
ret = asix_write_cmd(dev, AX_CMD_WRITE_IPG0,
AX88772_IPG0_DEFAULT | AX88772_IPG1_DEFAULT,
AX88772_IPG2_DEFAULT, 0, NULL);
if (ret < 0) {
dbg("Write IPG,IPG1,IPG2 failed: %d", ret);
goto out;
}
memcpy(data->mac_addr, dev->net->dev_addr, ETH_ALEN);
ret = asix_write_cmd(dev, AX_CMD_WRITE_NODE_ID, 0, 0, ETH_ALEN,
data->mac_addr);
if (ret < 0)
goto out;
ret = asix_write_rx_ctl(dev, AX_DEFAULT_RX_CTL);
if (ret < 0)
goto out;
rx_ctl = asix_read_rx_ctl(dev);
dbg("RX_CTL is 0x%04x after all initializations", rx_ctl);
rx_ctl = asix_read_medium_status(dev);
dbg("Medium Status is 0x%04x after all initializations", rx_ctl);
return 0;
out:
return ret;
}
static int ax88772_bind(struct usbnet *dev, struct usb_interface *intf)
{
int ret, embd_phy;
struct asix_data *data = (struct asix_data *)&dev->data;
u8 buf[ETH_ALEN];
u32 phyid;
data->eeprom_len = AX88772_EEPROM_LEN;
usbnet_get_endpoints(dev,intf);
ret = asix_read_cmd(dev, AX_CMD_READ_NODE_ID, 0, 0, ETH_ALEN, buf);
if (ret < 0) {
dbg("Failed to read MAC address: %d", ret);
return ret;
}
memcpy(dev->net->dev_addr, buf, ETH_ALEN);
dev->mii.dev = dev->net;
dev->mii.mdio_read = asix_mdio_read;
dev->mii.mdio_write = asix_mdio_write;
dev->mii.phy_id_mask = 0x1f;
dev->mii.reg_num_mask = 0x1f;
dev->mii.phy_id = asix_get_phy_addr(dev);
dev->net->netdev_ops = &ax88772_netdev_ops;
dev->net->ethtool_ops = &ax88772_ethtool_ops;
embd_phy = ((dev->mii.phy_id & 0x1f) == 0x10 ? 1 : 0);
ret = asix_write_cmd(dev, AX_CMD_SW_PHY_SELECT, embd_phy, 0, 0, NULL);
if (ret < 0) {
dbg("Select PHY #1 failed: %d", ret);
return ret;
}
ret = asix_sw_reset(dev, AX_SWRESET_IPPD | AX_SWRESET_PRL);
if (ret < 0)
return ret;
msleep(150);
ret = asix_sw_reset(dev, AX_SWRESET_CLEAR);
if (ret < 0)
return ret;
msleep(150);
ret = asix_sw_reset(dev, embd_phy ? AX_SWRESET_IPRL : AX_SWRESET_PRTE);
phyid = asix_get_phyid(dev);
dbg("PHYID=0x%08x", phyid);
if (dev->driver_info->flags & FLAG_FRAMING_AX) {
dev->rx_urb_size = 2048;
}
return 0;
}
static int marvell_phy_init(struct usbnet *dev)
{
struct asix_data *data = (struct asix_data *)&dev->data;
u16 reg;
netdev_dbg(dev->net, "marvell_phy_init()\n");
reg = asix_mdio_read(dev->net, dev->mii.phy_id, MII_MARVELL_STATUS);
netdev_dbg(dev->net, "MII_MARVELL_STATUS = 0x%04x\n", reg);
asix_mdio_write(dev->net, dev->mii.phy_id, MII_MARVELL_CTRL,
MARVELL_CTRL_RXDELAY | MARVELL_CTRL_TXDELAY);
if (data->ledmode) {
reg = asix_mdio_read(dev->net, dev->mii.phy_id,
MII_MARVELL_LED_CTRL);
netdev_dbg(dev->net, "MII_MARVELL_LED_CTRL (1) = 0x%04x\n", reg);
reg &= 0xf8ff;
reg |= (1 + 0x0100);
asix_mdio_write(dev->net, dev->mii.phy_id,
MII_MARVELL_LED_CTRL, reg);
reg = asix_mdio_read(dev->net, dev->mii.phy_id,
MII_MARVELL_LED_CTRL);
netdev_dbg(dev->net, "MII_MARVELL_LED_CTRL (2) = 0x%04x\n", reg);
reg &= 0xfc0f;
}
return 0;
}
static int rtl8211cl_phy_init(struct usbnet *dev)
{
struct asix_data *data = (struct asix_data *)&dev->data;
netdev_dbg(dev->net, "rtl8211cl_phy_init()\n");
asix_mdio_write (dev->net, dev->mii.phy_id, 0x1f, 0x0005);
asix_mdio_write (dev->net, dev->mii.phy_id, 0x0c, 0);
asix_mdio_write (dev->net, dev->mii.phy_id, 0x01,
asix_mdio_read (dev->net, dev->mii.phy_id, 0x01) | 0x0080);
asix_mdio_write (dev->net, dev->mii.phy_id, 0x1f, 0);
if (data->ledmode == 12) {
asix_mdio_write (dev->net, dev->mii.phy_id, 0x1f, 0x0002);
asix_mdio_write (dev->net, dev->mii.phy_id, 0x1a, 0x00cb);
asix_mdio_write (dev->net, dev->mii.phy_id, 0x1f, 0);
}
return 0;
}
static int marvell_led_status(struct usbnet *dev, u16 speed)
{
u16 reg = asix_mdio_read(dev->net, dev->mii.phy_id, MARVELL_LED_MANUAL);
netdev_dbg(dev->net, "marvell_led_status() read 0x%04x\n", reg);
reg &= 0xfc0f;
switch (speed) {
case SPEED_1000:
reg |= 0x03e0;
break;
case SPEED_100:
reg |= 0x03b0;
break;
default:
reg |= 0x02f0;
}
netdev_dbg(dev->net, "marvell_led_status() writing 0x%04x\n", reg);
asix_mdio_write(dev->net, dev->mii.phy_id, MARVELL_LED_MANUAL, reg);
return 0;
}
static int ax88178_reset(struct usbnet *dev)
{
struct asix_data *data = (struct asix_data *)&dev->data;
int ret;
__le16 eeprom;
u8 status;
int gpio0 = 0;
u32 phyid;
asix_read_cmd(dev, AX_CMD_READ_GPIOS, 0, 0, 1, &status);
dbg("GPIO Status: 0x%04x", status);
asix_write_cmd(dev, AX_CMD_WRITE_ENABLE, 0, 0, 0, NULL);
asix_read_cmd(dev, AX_CMD_READ_EEPROM, 0x0017, 0, 2, &eeprom);
asix_write_cmd(dev, AX_CMD_WRITE_DISABLE, 0, 0, 0, NULL);
dbg("EEPROM index 0x17 is 0x%04x", eeprom);
if (eeprom == cpu_to_le16(0xffff)) {
data->phymode = PHY_MODE_MARVELL;
data->ledmode = 0;
gpio0 = 1;
} else {
data->phymode = le16_to_cpu(eeprom) & 0x7F;
data->ledmode = le16_to_cpu(eeprom) >> 8;
gpio0 = (le16_to_cpu(eeprom) & 0x80) ? 0 : 1;
}
dbg("GPIO0: %d, PhyMode: %d", gpio0, data->phymode);
asix_write_gpio(dev, AX_GPIO_RSE | AX_GPIO_GPO_1 | AX_GPIO_GPO1EN, 40);
if ((le16_to_cpu(eeprom) >> 8) != 1) {
asix_write_gpio(dev, 0x003c, 30);
asix_write_gpio(dev, 0x001c, 300);
asix_write_gpio(dev, 0x003c, 30);
} else {
dbg("gpio phymode == 1 path");
asix_write_gpio(dev, AX_GPIO_GPO1EN, 30);
asix_write_gpio(dev, AX_GPIO_GPO1EN | AX_GPIO_GPO_1, 30);
}
phyid = asix_get_phyid(dev);
dbg("PHYID=0x%08x", phyid);
asix_write_cmd(dev, AX_CMD_SW_PHY_SELECT, 0, 0, 0, NULL);
asix_sw_reset(dev, 0);
msleep(150);
asix_sw_reset(dev, AX_SWRESET_PRL | AX_SWRESET_IPPD);
msleep(150);
asix_write_rx_ctl(dev, 0);
if (data->phymode == PHY_MODE_MARVELL) {
marvell_phy_init(dev);
msleep(60);
} else if (data->phymode == PHY_MODE_RTL8211CL)
rtl8211cl_phy_init(dev);
asix_mdio_write(dev->net, dev->mii.phy_id, MII_BMCR,
BMCR_RESET | BMCR_ANENABLE);
asix_mdio_write(dev->net, dev->mii.phy_id, MII_ADVERTISE,
ADVERTISE_ALL | ADVERTISE_CSMA | ADVERTISE_PAUSE_CAP);
asix_mdio_write(dev->net, dev->mii.phy_id, MII_CTRL1000,
ADVERTISE_1000FULL);
mii_nway_restart(&dev->mii);
ret = asix_write_medium_mode(dev, AX88178_MEDIUM_DEFAULT);
if (ret < 0)
return ret;
memcpy(data->mac_addr, dev->net->dev_addr, ETH_ALEN);
ret = asix_write_cmd(dev, AX_CMD_WRITE_NODE_ID, 0, 0, ETH_ALEN,
data->mac_addr);
if (ret < 0)
return ret;
ret = asix_write_rx_ctl(dev, AX_DEFAULT_RX_CTL);
if (ret < 0)
return ret;
return 0;
}
static int ax88178_link_reset(struct usbnet *dev)
{
u16 mode;
struct ethtool_cmd ecmd = { .cmd = ETHTOOL_GSET };
struct asix_data *data = (struct asix_data *)&dev->data;
u32 speed;
netdev_dbg(dev->net, "ax88178_link_reset()\n");
mii_check_media(&dev->mii, 1, 1);
mii_ethtool_gset(&dev->mii, &ecmd);
mode = AX88178_MEDIUM_DEFAULT;
speed = ethtool_cmd_speed(&ecmd);
if (speed == SPEED_1000)
mode |= AX_MEDIUM_GM;
else if (speed == SPEED_100)
mode |= AX_MEDIUM_PS;
else
mode &= ~(AX_MEDIUM_PS | AX_MEDIUM_GM);
mode |= AX_MEDIUM_ENCK;
if (ecmd.duplex == DUPLEX_FULL)
mode |= AX_MEDIUM_FD;
else
mode &= ~AX_MEDIUM_FD;
netdev_dbg(dev->net, "ax88178_link_reset() speed: %u duplex: %d setting mode to 0x%04x\n",
speed, ecmd.duplex, mode);
asix_write_medium_mode(dev, mode);
if (data->phymode == PHY_MODE_MARVELL && data->ledmode)
marvell_led_status(dev, speed);
return 0;
}
static void ax88178_set_mfb(struct usbnet *dev)
{
u16 mfb = AX_RX_CTL_MFB_16384;
u16 rxctl;
u16 medium;
int old_rx_urb_size = dev->rx_urb_size;
if (dev->hard_mtu < 2048) {
dev->rx_urb_size = 2048;
mfb = AX_RX_CTL_MFB_2048;
} else if (dev->hard_mtu < 4096) {
dev->rx_urb_size = 4096;
mfb = AX_RX_CTL_MFB_4096;
} else if (dev->hard_mtu < 8192) {
dev->rx_urb_size = 8192;
mfb = AX_RX_CTL_MFB_8192;
} else if (dev->hard_mtu < 16384) {
dev->rx_urb_size = 16384;
mfb = AX_RX_CTL_MFB_16384;
}
rxctl = asix_read_rx_ctl(dev);
asix_write_rx_ctl(dev, (rxctl & ~AX_RX_CTL_MFB_16384) | mfb);
medium = asix_read_medium_status(dev);
if (dev->net->mtu > 1500)
medium |= AX_MEDIUM_JFE;
else
medium &= ~AX_MEDIUM_JFE;
asix_write_medium_mode(dev, medium);
if (dev->rx_urb_size > old_rx_urb_size)
usbnet_unlink_rx_urbs(dev);
}
static int ax88178_change_mtu(struct net_device *net, int new_mtu)
{
struct usbnet *dev = netdev_priv(net);
int ll_mtu = new_mtu + net->hard_header_len + 4;
netdev_dbg(dev->net, "ax88178_change_mtu() new_mtu=%d\n", new_mtu);
if (new_mtu <= 0 || ll_mtu > 16384)
return -EINVAL;
if ((ll_mtu % dev->maxpacket) == 0)
return -EDOM;
net->mtu = new_mtu;
dev->hard_mtu = net->mtu + net->hard_header_len;
ax88178_set_mfb(dev);
return 0;
}
static int ax88178_bind(struct usbnet *dev, struct usb_interface *intf)
{
int ret;
u8 buf[ETH_ALEN];
struct asix_data *data = (struct asix_data *)&dev->data;
data->eeprom_len = AX88772_EEPROM_LEN;
usbnet_get_endpoints(dev,intf);
ret = asix_read_cmd(dev, AX_CMD_READ_NODE_ID, 0, 0, ETH_ALEN, buf);
if (ret < 0) {
dbg("Failed to read MAC address: %d", ret);
return ret;
}
memcpy(dev->net->dev_addr, buf, ETH_ALEN);
dev->mii.dev = dev->net;
dev->mii.mdio_read = asix_mdio_read;
dev->mii.mdio_write = asix_mdio_write;
dev->mii.phy_id_mask = 0x1f;
dev->mii.reg_num_mask = 0xff;
dev->mii.supports_gmii = 1;
dev->mii.phy_id = asix_get_phy_addr(dev);
dev->net->netdev_ops = &ax88178_netdev_ops;
dev->net->ethtool_ops = &ax88178_ethtool_ops;
asix_sw_reset(dev, 0);
msleep(150);
asix_sw_reset(dev, AX_SWRESET_PRL | AX_SWRESET_IPPD);
msleep(150);
if (dev->driver_info->flags & FLAG_FRAMING_AX) {
dev->rx_urb_size = 2048;
}
return 0;
}
