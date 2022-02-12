static int sr_read_cmd(struct usbnet *dev, u8 cmd, u16 value, u16 index,
u16 size, void *data)
{
int err;
err = usbnet_read_cmd(dev, cmd, SR_REQ_RD_REG, value, index,
data, size);
if ((err != size) && (err >= 0))
err = -EINVAL;
return err;
}
static int sr_write_cmd(struct usbnet *dev, u8 cmd, u16 value, u16 index,
u16 size, void *data)
{
int err;
err = usbnet_write_cmd(dev, cmd, SR_REQ_WR_REG, value, index,
data, size);
if ((err != size) && (err >= 0))
err = -EINVAL;
return err;
}
static void
sr_write_cmd_async(struct usbnet *dev, u8 cmd, u16 value, u16 index,
u16 size, void *data)
{
usbnet_write_cmd_async(dev, cmd, SR_REQ_WR_REG, value, index, data,
size);
}
static int sr_rx_fixup(struct usbnet *dev, struct sk_buff *skb)
{
int offset = 0;
if (skb->len < dev->net->hard_header_len)
return 0;
while (offset + sizeof(u32) < skb->len) {
struct sk_buff *sr_skb;
u16 size;
u32 header = get_unaligned_le32(skb->data + offset);
offset += sizeof(u32);
size = (u16) (header & 0x7ff);
if (size != ((~header >> 16) & 0x07ff)) {
netdev_err(dev->net, "%s : Bad Header Length\n",
__func__);
return 0;
}
if ((size > dev->net->mtu + ETH_HLEN + VLAN_HLEN) ||
(size + offset > skb->len)) {
netdev_err(dev->net, "%s : Bad RX Length %d\n",
__func__, size);
return 0;
}
sr_skb = netdev_alloc_skb_ip_align(dev->net, size);
if (!sr_skb)
return 0;
skb_put(sr_skb, size);
memcpy(sr_skb->data, skb->data + offset, size);
usbnet_skb_return(dev, sr_skb);
offset += (size + 1) & 0xfffe;
}
if (skb->len != offset) {
netdev_err(dev->net, "%s : Bad SKB Length %d\n", __func__,
skb->len);
return 0;
}
return 1;
}
static struct sk_buff *sr_tx_fixup(struct usbnet *dev, struct sk_buff *skb,
gfp_t flags)
{
int headroom = skb_headroom(skb);
int tailroom = skb_tailroom(skb);
u32 padbytes = 0xffff0000;
u32 packet_len;
int padlen;
padlen = ((skb->len + 4) % (dev->maxpacket - 1)) ? 0 : 4;
if ((!skb_cloned(skb)) && ((headroom + tailroom) >= (4 + padlen))) {
if ((headroom < 4) || (tailroom < padlen)) {
skb->data = memmove(skb->head + 4, skb->data,
skb->len);
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
static void sr_status(struct usbnet *dev, struct urb *urb)
{
struct sr9800_int_data *event;
int link;
if (urb->actual_length < 8)
return;
event = urb->transfer_buffer;
link = event->link & 0x01;
if (netif_carrier_ok(dev->net) != link) {
usbnet_link_change(dev, link, 1);
netdev_dbg(dev->net, "Link Status is: %d\n", link);
}
return;
}
static inline int sr_set_sw_mii(struct usbnet *dev)
{
int ret;
ret = sr_write_cmd(dev, SR_CMD_SET_SW_MII, 0x0000, 0, 0, NULL);
if (ret < 0)
netdev_err(dev->net, "Failed to enable software MII access\n");
return ret;
}
static inline int sr_set_hw_mii(struct usbnet *dev)
{
int ret;
ret = sr_write_cmd(dev, SR_CMD_SET_HW_MII, 0x0000, 0, 0, NULL);
if (ret < 0)
netdev_err(dev->net, "Failed to enable hardware MII access\n");
return ret;
}
static inline int sr_get_phy_addr(struct usbnet *dev)
{
u8 buf[2];
int ret;
ret = sr_read_cmd(dev, SR_CMD_READ_PHY_ID, 0, 0, 2, buf);
if (ret < 0) {
netdev_err(dev->net, "%s : Error reading PHYID register:%02x\n",
__func__, ret);
goto out;
}
netdev_dbg(dev->net, "%s : returning 0x%04x\n", __func__,
*((__le16 *)buf));
ret = buf[1];
out:
return ret;
}
static int sr_sw_reset(struct usbnet *dev, u8 flags)
{
int ret;
ret = sr_write_cmd(dev, SR_CMD_SW_RESET, flags, 0, 0, NULL);
if (ret < 0)
netdev_err(dev->net, "Failed to send software reset:%02x\n",
ret);
return ret;
}
static u16 sr_read_rx_ctl(struct usbnet *dev)
{
__le16 v;
int ret;
ret = sr_read_cmd(dev, SR_CMD_READ_RX_CTL, 0, 0, 2, &v);
if (ret < 0) {
netdev_err(dev->net, "Error reading RX_CTL register:%02x\n",
ret);
goto out;
}
ret = le16_to_cpu(v);
out:
return ret;
}
static int sr_write_rx_ctl(struct usbnet *dev, u16 mode)
{
int ret;
netdev_dbg(dev->net, "%s : mode = 0x%04x\n", __func__, mode);
ret = sr_write_cmd(dev, SR_CMD_WRITE_RX_CTL, mode, 0, 0, NULL);
if (ret < 0)
netdev_err(dev->net,
"Failed to write RX_CTL mode to 0x%04x:%02x\n",
mode, ret);
return ret;
}
static u16 sr_read_medium_status(struct usbnet *dev)
{
__le16 v;
int ret;
ret = sr_read_cmd(dev, SR_CMD_READ_MEDIUM_STATUS, 0, 0, 2, &v);
if (ret < 0) {
netdev_err(dev->net,
"Error reading Medium Status register:%02x\n", ret);
return ret;
}
return le16_to_cpu(v);
}
static int sr_write_medium_mode(struct usbnet *dev, u16 mode)
{
int ret;
netdev_dbg(dev->net, "%s : mode = 0x%04x\n", __func__, mode);
ret = sr_write_cmd(dev, SR_CMD_WRITE_MEDIUM_MODE, mode, 0, 0, NULL);
if (ret < 0)
netdev_err(dev->net,
"Failed to write Medium Mode mode to 0x%04x:%02x\n",
mode, ret);
return ret;
}
static int sr_write_gpio(struct usbnet *dev, u16 value, int sleep)
{
int ret;
netdev_dbg(dev->net, "%s : value = 0x%04x\n", __func__, value);
ret = sr_write_cmd(dev, SR_CMD_WRITE_GPIOS, value, 0, 0, NULL);
if (ret < 0)
netdev_err(dev->net, "Failed to write GPIO value 0x%04x:%02x\n",
value, ret);
if (sleep)
msleep(sleep);
return ret;
}
static void sr_set_multicast(struct net_device *net)
{
struct usbnet *dev = netdev_priv(net);
struct sr_data *data = (struct sr_data *)&dev->data;
u16 rx_ctl = SR_DEFAULT_RX_CTL;
if (net->flags & IFF_PROMISC) {
rx_ctl |= SR_RX_CTL_PRO;
} else if (net->flags & IFF_ALLMULTI ||
netdev_mc_count(net) > SR_MAX_MCAST) {
rx_ctl |= SR_RX_CTL_AMALL;
} else if (netdev_mc_empty(net)) {
} else {
struct netdev_hw_addr *ha;
u32 crc_bits;
memset(data->multi_filter, 0, SR_MCAST_FILTER_SIZE);
netdev_for_each_mc_addr(ha, net) {
crc_bits = ether_crc(ETH_ALEN, ha->addr) >> 26;
data->multi_filter[crc_bits >> 3] |=
1 << (crc_bits & 7);
}
sr_write_cmd_async(dev, SR_CMD_WRITE_MULTI_FILTER, 0, 0,
SR_MCAST_FILTER_SIZE, data->multi_filter);
rx_ctl |= SR_RX_CTL_AM;
}
sr_write_cmd_async(dev, SR_CMD_WRITE_RX_CTL, rx_ctl, 0, 0, NULL);
}
static int sr_mdio_read(struct net_device *net, int phy_id, int loc)
{
struct usbnet *dev = netdev_priv(net);
__le16 res;
mutex_lock(&dev->phy_mutex);
sr_set_sw_mii(dev);
sr_read_cmd(dev, SR_CMD_READ_MII_REG, phy_id, (__u16)loc, 2, &res);
sr_set_hw_mii(dev);
mutex_unlock(&dev->phy_mutex);
netdev_dbg(dev->net,
"%s : phy_id=0x%02x, loc=0x%02x, returns=0x%04x\n", __func__,
phy_id, loc, le16_to_cpu(res));
return le16_to_cpu(res);
}
static void
sr_mdio_write(struct net_device *net, int phy_id, int loc, int val)
{
struct usbnet *dev = netdev_priv(net);
__le16 res = cpu_to_le16(val);
netdev_dbg(dev->net,
"%s : phy_id=0x%02x, loc=0x%02x, val=0x%04x\n", __func__,
phy_id, loc, val);
mutex_lock(&dev->phy_mutex);
sr_set_sw_mii(dev);
sr_write_cmd(dev, SR_CMD_WRITE_MII_REG, phy_id, (__u16)loc, 2, &res);
sr_set_hw_mii(dev);
mutex_unlock(&dev->phy_mutex);
}
static u32 sr_get_phyid(struct usbnet *dev)
{
int phy_reg;
u32 phy_id;
int i;
for (i = 0; i < 100; i++) {
phy_reg = sr_mdio_read(dev->net, dev->mii.phy_id, MII_PHYSID1);
if (phy_reg != 0 && phy_reg != 0xFFFF)
break;
mdelay(1);
}
if (phy_reg <= 0 || phy_reg == 0xFFFF)
return 0;
phy_id = (phy_reg & 0xffff) << 16;
phy_reg = sr_mdio_read(dev->net, dev->mii.phy_id, MII_PHYSID2);
if (phy_reg < 0)
return 0;
phy_id |= (phy_reg & 0xffff);
return phy_id;
}
static void
sr_get_wol(struct net_device *net, struct ethtool_wolinfo *wolinfo)
{
struct usbnet *dev = netdev_priv(net);
u8 opt;
if (sr_read_cmd(dev, SR_CMD_READ_MONITOR_MODE, 0, 0, 1, &opt) < 0) {
wolinfo->supported = 0;
wolinfo->wolopts = 0;
return;
}
wolinfo->supported = WAKE_PHY | WAKE_MAGIC;
wolinfo->wolopts = 0;
if (opt & SR_MONITOR_LINK)
wolinfo->wolopts |= WAKE_PHY;
if (opt & SR_MONITOR_MAGIC)
wolinfo->wolopts |= WAKE_MAGIC;
}
static int
sr_set_wol(struct net_device *net, struct ethtool_wolinfo *wolinfo)
{
struct usbnet *dev = netdev_priv(net);
u8 opt = 0;
if (wolinfo->wolopts & WAKE_PHY)
opt |= SR_MONITOR_LINK;
if (wolinfo->wolopts & WAKE_MAGIC)
opt |= SR_MONITOR_MAGIC;
if (sr_write_cmd(dev, SR_CMD_WRITE_MONITOR_MODE,
opt, 0, 0, NULL) < 0)
return -EINVAL;
return 0;
}
static int sr_get_eeprom_len(struct net_device *net)
{
struct usbnet *dev = netdev_priv(net);
struct sr_data *data = (struct sr_data *)&dev->data;
return data->eeprom_len;
}
static int sr_get_eeprom(struct net_device *net,
struct ethtool_eeprom *eeprom, u8 *data)
{
struct usbnet *dev = netdev_priv(net);
__le16 *ebuf = (__le16 *)data;
int ret;
int i;
if (eeprom->len % 2)
return -EINVAL;
eeprom->magic = SR_EEPROM_MAGIC;
for (i = 0; i < eeprom->len / 2; i++) {
ret = sr_read_cmd(dev, SR_CMD_READ_EEPROM, eeprom->offset + i,
0, 2, &ebuf[i]);
if (ret < 0)
return -EINVAL;
}
return 0;
}
static void sr_get_drvinfo(struct net_device *net,
struct ethtool_drvinfo *info)
{
struct usbnet *dev = netdev_priv(net);
struct sr_data *data = (struct sr_data *)&dev->data;
usbnet_get_drvinfo(net, info);
strncpy(info->driver, DRIVER_NAME, sizeof(info->driver));
strncpy(info->version, DRIVER_VERSION, sizeof(info->version));
info->eedump_len = data->eeprom_len;
}
static u32 sr_get_link(struct net_device *net)
{
struct usbnet *dev = netdev_priv(net);
return mii_link_ok(&dev->mii);
}
static int sr_ioctl(struct net_device *net, struct ifreq *rq, int cmd)
{
struct usbnet *dev = netdev_priv(net);
return generic_mii_ioctl(&dev->mii, if_mii(rq), cmd, NULL);
}
static int sr_set_mac_address(struct net_device *net, void *p)
{
struct usbnet *dev = netdev_priv(net);
struct sr_data *data = (struct sr_data *)&dev->data;
struct sockaddr *addr = p;
if (netif_running(net))
return -EBUSY;
if (!is_valid_ether_addr(addr->sa_data))
return -EADDRNOTAVAIL;
memcpy(net->dev_addr, addr->sa_data, ETH_ALEN);
memcpy(data->mac_addr, addr->sa_data, ETH_ALEN);
sr_write_cmd_async(dev, SR_CMD_WRITE_NODE_ID, 0, 0, ETH_ALEN,
data->mac_addr);
return 0;
}
static int sr9800_link_reset(struct usbnet *dev)
{
struct ethtool_cmd ecmd = { .cmd = ETHTOOL_GSET };
u16 mode;
mii_check_media(&dev->mii, 1, 1);
mii_ethtool_gset(&dev->mii, &ecmd);
mode = SR9800_MEDIUM_DEFAULT;
if (ethtool_cmd_speed(&ecmd) != SPEED_100)
mode &= ~SR_MEDIUM_PS;
if (ecmd.duplex != DUPLEX_FULL)
mode &= ~SR_MEDIUM_FD;
netdev_dbg(dev->net, "%s : speed: %u duplex: %d mode: 0x%04x\n",
__func__, ethtool_cmd_speed(&ecmd), ecmd.duplex, mode);
sr_write_medium_mode(dev, mode);
return 0;
}
static int sr9800_set_default_mode(struct usbnet *dev)
{
u16 rx_ctl;
int ret;
sr_mdio_write(dev->net, dev->mii.phy_id, MII_BMCR, BMCR_RESET);
sr_mdio_write(dev->net, dev->mii.phy_id, MII_ADVERTISE,
ADVERTISE_ALL | ADVERTISE_CSMA);
mii_nway_restart(&dev->mii);
ret = sr_write_medium_mode(dev, SR9800_MEDIUM_DEFAULT);
if (ret < 0)
goto out;
ret = sr_write_cmd(dev, SR_CMD_WRITE_IPG012,
SR9800_IPG0_DEFAULT | SR9800_IPG1_DEFAULT,
SR9800_IPG2_DEFAULT, 0, NULL);
if (ret < 0) {
netdev_dbg(dev->net, "Write IPG,IPG1,IPG2 failed: %d\n", ret);
goto out;
}
ret = sr_write_rx_ctl(dev, SR_DEFAULT_RX_CTL);
if (ret < 0)
goto out;
rx_ctl = sr_read_rx_ctl(dev);
netdev_dbg(dev->net, "RX_CTL is 0x%04x after all initializations\n",
rx_ctl);
rx_ctl = sr_read_medium_status(dev);
netdev_dbg(dev->net, "Medium Status:0x%04x after all initializations\n",
rx_ctl);
return 0;
out:
return ret;
}
static int sr9800_reset(struct usbnet *dev)
{
struct sr_data *data = (struct sr_data *)&dev->data;
int ret, embd_phy;
u16 rx_ctl;
ret = sr_write_gpio(dev,
SR_GPIO_RSE | SR_GPIO_GPO_2 | SR_GPIO_GPO2EN, 5);
if (ret < 0)
goto out;
embd_phy = ((sr_get_phy_addr(dev) & 0x1f) == 0x10 ? 1 : 0);
ret = sr_write_cmd(dev, SR_CMD_SW_PHY_SELECT, embd_phy, 0, 0, NULL);
if (ret < 0) {
netdev_dbg(dev->net, "Select PHY #1 failed: %d\n", ret);
goto out;
}
ret = sr_sw_reset(dev, SR_SWRESET_IPPD | SR_SWRESET_PRL);
if (ret < 0)
goto out;
msleep(150);
ret = sr_sw_reset(dev, SR_SWRESET_CLEAR);
if (ret < 0)
goto out;
msleep(150);
if (embd_phy) {
ret = sr_sw_reset(dev, SR_SWRESET_IPRL);
if (ret < 0)
goto out;
} else {
ret = sr_sw_reset(dev, SR_SWRESET_PRTE);
if (ret < 0)
goto out;
}
msleep(150);
rx_ctl = sr_read_rx_ctl(dev);
netdev_dbg(dev->net, "RX_CTL is 0x%04x after software reset\n", rx_ctl);
ret = sr_write_rx_ctl(dev, 0x0000);
if (ret < 0)
goto out;
rx_ctl = sr_read_rx_ctl(dev);
netdev_dbg(dev->net, "RX_CTL is 0x%04x setting to 0x0000\n", rx_ctl);
ret = sr_sw_reset(dev, SR_SWRESET_PRL);
if (ret < 0)
goto out;
msleep(150);
ret = sr_sw_reset(dev, SR_SWRESET_IPRL | SR_SWRESET_PRL);
if (ret < 0)
goto out;
msleep(150);
ret = sr9800_set_default_mode(dev);
if (ret < 0)
goto out;
memcpy(data->mac_addr, dev->net->dev_addr, ETH_ALEN);
ret = sr_write_cmd(dev, SR_CMD_WRITE_NODE_ID, 0, 0, ETH_ALEN,
data->mac_addr);
if (ret < 0)
goto out;
return 0;
out:
return ret;
}
static int sr9800_phy_powerup(struct usbnet *dev)
{
int ret;
ret = sr_sw_reset(dev, SR_SWRESET_IPPD | SR_SWRESET_IPRL);
if (ret < 0) {
netdev_err(dev->net, "Failed to power down PHY : %d\n", ret);
return ret;
}
msleep(20);
ret = sr_sw_reset(dev, SR_SWRESET_IPRL);
if (ret < 0) {
netdev_err(dev->net, "Failed to reset PHY: %d\n", ret);
return ret;
}
msleep(600);
ret = sr_sw_reset(dev, SR_SWRESET_CLEAR);
if (ret < 0) {
netdev_err(dev->net, "Failed to power up PHY: %d\n", ret);
return ret;
}
msleep(20);
ret = sr_sw_reset(dev, SR_SWRESET_IPRL);
if (ret < 0) {
netdev_err(dev->net, "Failed to reset PHY: %d\n", ret);
return ret;
}
return 0;
}
static int sr9800_bind(struct usbnet *dev, struct usb_interface *intf)
{
struct sr_data *data = (struct sr_data *)&dev->data;
u16 led01_mux, led23_mux;
int ret, embd_phy;
u32 phyid;
u16 rx_ctl;
data->eeprom_len = SR9800_EEPROM_LEN;
usbnet_get_endpoints(dev, intf);
led01_mux = (SR_LED_MUX_LINK_ACTIVE << 8) | SR_LED_MUX_LINK;
led23_mux = (SR_LED_MUX_LINK_ACTIVE << 8) | SR_LED_MUX_TX_ACTIVE;
ret = sr_write_cmd(dev, SR_CMD_LED_MUX, led01_mux, led23_mux, 0, NULL);
if (ret < 0) {
netdev_err(dev->net, "set LINK LED failed : %d\n", ret);
goto out;
}
ret = sr_read_cmd(dev, SR_CMD_READ_NODE_ID, 0, 0, ETH_ALEN,
dev->net->dev_addr);
if (ret < 0) {
netdev_dbg(dev->net, "Failed to read MAC address: %d\n", ret);
return ret;
}
netdev_dbg(dev->net, "mac addr : %pM\n", dev->net->dev_addr);
dev->mii.dev = dev->net;
dev->mii.mdio_read = sr_mdio_read;
dev->mii.mdio_write = sr_mdio_write;
dev->mii.phy_id_mask = 0x1f;
dev->mii.reg_num_mask = 0x1f;
dev->mii.phy_id = sr_get_phy_addr(dev);
dev->net->netdev_ops = &sr9800_netdev_ops;
dev->net->ethtool_ops = &sr9800_ethtool_ops;
embd_phy = ((dev->mii.phy_id & 0x1f) == 0x10 ? 1 : 0);
ret = sr_write_cmd(dev, SR_CMD_SW_PHY_SELECT, embd_phy, 0, 0, NULL);
if (ret < 0) {
netdev_dbg(dev->net, "Select PHY #1 failed: %d\n", ret);
return ret;
}
ret = sr9800_phy_powerup(dev);
if (ret < 0)
goto out;
rx_ctl = sr_read_rx_ctl(dev);
netdev_dbg(dev->net, "RX_CTL is 0x%04x after software reset\n", rx_ctl);
ret = sr_write_rx_ctl(dev, 0x0000);
if (ret < 0)
goto out;
rx_ctl = sr_read_rx_ctl(dev);
netdev_dbg(dev->net, "RX_CTL is 0x%04x setting to 0x0000\n", rx_ctl);
phyid = sr_get_phyid(dev);
netdev_dbg(dev->net, "PHYID=0x%08x\n", phyid);
ret = sr9800_set_default_mode(dev);
if (ret < 0)
goto out;
if (dev->udev->speed == USB_SPEED_HIGH) {
ret = sr_write_cmd(dev, SR_CMD_BULKIN_SIZE,
SR9800_BULKIN_SIZE[SR9800_MAX_BULKIN_4K].byte_cnt,
SR9800_BULKIN_SIZE[SR9800_MAX_BULKIN_4K].threshold,
0, NULL);
if (ret < 0) {
netdev_err(dev->net, "Reset RX_CTL failed: %d\n", ret);
goto out;
}
dev->rx_urb_size =
SR9800_BULKIN_SIZE[SR9800_MAX_BULKIN_4K].size;
} else {
ret = sr_write_cmd(dev, SR_CMD_BULKIN_SIZE,
SR9800_BULKIN_SIZE[SR9800_MAX_BULKIN_2K].byte_cnt,
SR9800_BULKIN_SIZE[SR9800_MAX_BULKIN_2K].threshold,
0, NULL);
if (ret < 0) {
netdev_err(dev->net, "Reset RX_CTL failed: %d\n", ret);
goto out;
}
dev->rx_urb_size =
SR9800_BULKIN_SIZE[SR9800_MAX_BULKIN_2K].size;
}
netdev_dbg(dev->net, "%s : setting rx_urb_size with : %zu\n", __func__,
dev->rx_urb_size);
return 0;
out:
return ret;
}
