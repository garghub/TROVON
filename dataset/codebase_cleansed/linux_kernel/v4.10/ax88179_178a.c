static int __ax88179_read_cmd(struct usbnet *dev, u8 cmd, u16 value, u16 index,
u16 size, void *data, int in_pm)
{
int ret;
int (*fn)(struct usbnet *, u8, u8, u16, u16, void *, u16);
BUG_ON(!dev);
if (!in_pm)
fn = usbnet_read_cmd;
else
fn = usbnet_read_cmd_nopm;
ret = fn(dev, cmd, USB_DIR_IN | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
value, index, data, size);
if (unlikely(ret < 0))
netdev_warn(dev->net, "Failed to read reg index 0x%04x: %d\n",
index, ret);
return ret;
}
static int __ax88179_write_cmd(struct usbnet *dev, u8 cmd, u16 value, u16 index,
u16 size, void *data, int in_pm)
{
int ret;
int (*fn)(struct usbnet *, u8, u8, u16, u16, const void *, u16);
BUG_ON(!dev);
if (!in_pm)
fn = usbnet_write_cmd;
else
fn = usbnet_write_cmd_nopm;
ret = fn(dev, cmd, USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
value, index, data, size);
if (unlikely(ret < 0))
netdev_warn(dev->net, "Failed to write reg index 0x%04x: %d\n",
index, ret);
return ret;
}
static void ax88179_write_cmd_async(struct usbnet *dev, u8 cmd, u16 value,
u16 index, u16 size, void *data)
{
u16 buf;
if (2 == size) {
buf = *((u16 *)data);
cpu_to_le16s(&buf);
usbnet_write_cmd_async(dev, cmd, USB_DIR_OUT | USB_TYPE_VENDOR |
USB_RECIP_DEVICE, value, index, &buf,
size);
} else {
usbnet_write_cmd_async(dev, cmd, USB_DIR_OUT | USB_TYPE_VENDOR |
USB_RECIP_DEVICE, value, index, data,
size);
}
}
static int ax88179_read_cmd_nopm(struct usbnet *dev, u8 cmd, u16 value,
u16 index, u16 size, void *data)
{
int ret;
if (2 == size) {
u16 buf;
ret = __ax88179_read_cmd(dev, cmd, value, index, size, &buf, 1);
le16_to_cpus(&buf);
*((u16 *)data) = buf;
} else if (4 == size) {
u32 buf;
ret = __ax88179_read_cmd(dev, cmd, value, index, size, &buf, 1);
le32_to_cpus(&buf);
*((u32 *)data) = buf;
} else {
ret = __ax88179_read_cmd(dev, cmd, value, index, size, data, 1);
}
return ret;
}
static int ax88179_write_cmd_nopm(struct usbnet *dev, u8 cmd, u16 value,
u16 index, u16 size, void *data)
{
int ret;
if (2 == size) {
u16 buf;
buf = *((u16 *)data);
cpu_to_le16s(&buf);
ret = __ax88179_write_cmd(dev, cmd, value, index,
size, &buf, 1);
} else {
ret = __ax88179_write_cmd(dev, cmd, value, index,
size, data, 1);
}
return ret;
}
static int ax88179_read_cmd(struct usbnet *dev, u8 cmd, u16 value, u16 index,
u16 size, void *data)
{
int ret;
if (2 == size) {
u16 buf;
ret = __ax88179_read_cmd(dev, cmd, value, index, size, &buf, 0);
le16_to_cpus(&buf);
*((u16 *)data) = buf;
} else if (4 == size) {
u32 buf;
ret = __ax88179_read_cmd(dev, cmd, value, index, size, &buf, 0);
le32_to_cpus(&buf);
*((u32 *)data) = buf;
} else {
ret = __ax88179_read_cmd(dev, cmd, value, index, size, data, 0);
}
return ret;
}
static int ax88179_write_cmd(struct usbnet *dev, u8 cmd, u16 value, u16 index,
u16 size, void *data)
{
int ret;
if (2 == size) {
u16 buf;
buf = *((u16 *)data);
cpu_to_le16s(&buf);
ret = __ax88179_write_cmd(dev, cmd, value, index,
size, &buf, 0);
} else {
ret = __ax88179_write_cmd(dev, cmd, value, index,
size, data, 0);
}
return ret;
}
static void ax88179_status(struct usbnet *dev, struct urb *urb)
{
struct ax88179_int_data *event;
u32 link;
if (urb->actual_length < 8)
return;
event = urb->transfer_buffer;
le32_to_cpus((void *)&event->intdata1);
link = (((__force u32)event->intdata1) & AX_INT_PPLS_LINK) >> 16;
if (netif_carrier_ok(dev->net) != link) {
usbnet_link_change(dev, link, 1);
netdev_info(dev->net, "ax88179 - Link status is: %d\n", link);
}
}
static int ax88179_mdio_read(struct net_device *netdev, int phy_id, int loc)
{
struct usbnet *dev = netdev_priv(netdev);
u16 res;
ax88179_read_cmd(dev, AX_ACCESS_PHY, phy_id, (__u16)loc, 2, &res);
return res;
}
static void ax88179_mdio_write(struct net_device *netdev, int phy_id, int loc,
int val)
{
struct usbnet *dev = netdev_priv(netdev);
u16 res = (u16) val;
ax88179_write_cmd(dev, AX_ACCESS_PHY, phy_id, (__u16)loc, 2, &res);
}
static inline int ax88179_phy_mmd_indirect(struct usbnet *dev, u16 prtad,
u16 devad)
{
u16 tmp16;
int ret;
tmp16 = devad;
ret = ax88179_write_cmd(dev, AX_ACCESS_PHY, AX88179_PHY_ID,
MII_MMD_CTRL, 2, &tmp16);
tmp16 = prtad;
ret = ax88179_write_cmd(dev, AX_ACCESS_PHY, AX88179_PHY_ID,
MII_MMD_DATA, 2, &tmp16);
tmp16 = devad | MII_MMD_CTRL_NOINCR;
ret = ax88179_write_cmd(dev, AX_ACCESS_PHY, AX88179_PHY_ID,
MII_MMD_CTRL, 2, &tmp16);
return ret;
}
static int
ax88179_phy_read_mmd_indirect(struct usbnet *dev, u16 prtad, u16 devad)
{
int ret;
u16 tmp16;
ax88179_phy_mmd_indirect(dev, prtad, devad);
ret = ax88179_read_cmd(dev, AX_ACCESS_PHY, AX88179_PHY_ID,
MII_MMD_DATA, 2, &tmp16);
if (ret < 0)
return ret;
return tmp16;
}
static int
ax88179_phy_write_mmd_indirect(struct usbnet *dev, u16 prtad, u16 devad,
u16 data)
{
int ret;
ax88179_phy_mmd_indirect(dev, prtad, devad);
ret = ax88179_write_cmd(dev, AX_ACCESS_PHY, AX88179_PHY_ID,
MII_MMD_DATA, 2, &data);
if (ret < 0)
return ret;
return 0;
}
static int ax88179_suspend(struct usb_interface *intf, pm_message_t message)
{
struct usbnet *dev = usb_get_intfdata(intf);
u16 tmp16;
u8 tmp8;
usbnet_suspend(intf, message);
ax88179_read_cmd_nopm(dev, AX_ACCESS_MAC, AX_MEDIUM_STATUS_MODE,
2, 2, &tmp16);
tmp16 &= ~AX_MEDIUM_RECEIVE_EN;
ax88179_write_cmd_nopm(dev, AX_ACCESS_MAC, AX_MEDIUM_STATUS_MODE,
2, 2, &tmp16);
ax88179_read_cmd_nopm(dev, AX_ACCESS_MAC, AX_PHYPWR_RSTCTL,
2, 2, &tmp16);
tmp16 |= AX_PHYPWR_RSTCTL_BZ | AX_PHYPWR_RSTCTL_IPRL;
ax88179_write_cmd_nopm(dev, AX_ACCESS_MAC, AX_PHYPWR_RSTCTL,
2, 2, &tmp16);
tmp8 = 0;
ax88179_write_cmd_nopm(dev, AX_ACCESS_MAC, AX_CLK_SELECT, 1, 1, &tmp8);
tmp16 = AX_RX_CTL_STOP;
ax88179_write_cmd_nopm(dev, AX_ACCESS_MAC, AX_RX_CTL, 2, 2, &tmp16);
return 0;
}
static int ax88179_auto_detach(struct usbnet *dev, int in_pm)
{
u16 tmp16;
u8 tmp8;
int (*fnr)(struct usbnet *, u8, u16, u16, u16, void *);
int (*fnw)(struct usbnet *, u8, u16, u16, u16, void *);
if (!in_pm) {
fnr = ax88179_read_cmd;
fnw = ax88179_write_cmd;
} else {
fnr = ax88179_read_cmd_nopm;
fnw = ax88179_write_cmd_nopm;
}
if (fnr(dev, AX_ACCESS_EEPROM, 0x43, 1, 2, &tmp16) < 0)
return 0;
if ((tmp16 == 0xFFFF) || (!(tmp16 & 0x0100)))
return 0;
tmp8 = 0;
fnr(dev, AX_ACCESS_MAC, AX_CLK_SELECT, 1, 1, &tmp8);
tmp8 |= AX_CLK_SELECT_ULR;
fnw(dev, AX_ACCESS_MAC, AX_CLK_SELECT, 1, 1, &tmp8);
fnr(dev, AX_ACCESS_MAC, AX_PHYPWR_RSTCTL, 2, 2, &tmp16);
tmp16 |= AX_PHYPWR_RSTCTL_AT;
fnw(dev, AX_ACCESS_MAC, AX_PHYPWR_RSTCTL, 2, 2, &tmp16);
return 0;
}
static int ax88179_resume(struct usb_interface *intf)
{
struct usbnet *dev = usb_get_intfdata(intf);
u16 tmp16;
u8 tmp8;
usbnet_link_change(dev, 0, 0);
tmp16 = 0;
ax88179_write_cmd_nopm(dev, AX_ACCESS_MAC, AX_PHYPWR_RSTCTL,
2, 2, &tmp16);
udelay(1000);
tmp16 = AX_PHYPWR_RSTCTL_IPRL;
ax88179_write_cmd_nopm(dev, AX_ACCESS_MAC, AX_PHYPWR_RSTCTL,
2, 2, &tmp16);
msleep(200);
ax88179_auto_detach(dev, 1);
ax88179_read_cmd_nopm(dev, AX_ACCESS_MAC, AX_CLK_SELECT, 1, 1, &tmp8);
tmp8 |= AX_CLK_SELECT_ACS | AX_CLK_SELECT_BCS;
ax88179_write_cmd_nopm(dev, AX_ACCESS_MAC, AX_CLK_SELECT, 1, 1, &tmp8);
msleep(100);
tmp16 = AX_RX_CTL_DROPCRCERR | AX_RX_CTL_IPE | AX_RX_CTL_START |
AX_RX_CTL_AP | AX_RX_CTL_AMALL | AX_RX_CTL_AB;
ax88179_write_cmd_nopm(dev, AX_ACCESS_MAC, AX_RX_CTL, 2, 2, &tmp16);
return usbnet_resume(intf);
}
static void
ax88179_get_wol(struct net_device *net, struct ethtool_wolinfo *wolinfo)
{
struct usbnet *dev = netdev_priv(net);
u8 opt;
if (ax88179_read_cmd(dev, AX_ACCESS_MAC, AX_MONITOR_MOD,
1, 1, &opt) < 0) {
wolinfo->supported = 0;
wolinfo->wolopts = 0;
return;
}
wolinfo->supported = WAKE_PHY | WAKE_MAGIC;
wolinfo->wolopts = 0;
if (opt & AX_MONITOR_MODE_RWLC)
wolinfo->wolopts |= WAKE_PHY;
if (opt & AX_MONITOR_MODE_RWMP)
wolinfo->wolopts |= WAKE_MAGIC;
}
static int
ax88179_set_wol(struct net_device *net, struct ethtool_wolinfo *wolinfo)
{
struct usbnet *dev = netdev_priv(net);
u8 opt = 0;
if (wolinfo->wolopts & WAKE_PHY)
opt |= AX_MONITOR_MODE_RWLC;
if (wolinfo->wolopts & WAKE_MAGIC)
opt |= AX_MONITOR_MODE_RWMP;
if (ax88179_write_cmd(dev, AX_ACCESS_MAC, AX_MONITOR_MOD,
1, 1, &opt) < 0)
return -EINVAL;
return 0;
}
static int ax88179_get_eeprom_len(struct net_device *net)
{
return AX_EEPROM_LEN;
}
static int
ax88179_get_eeprom(struct net_device *net, struct ethtool_eeprom *eeprom,
u8 *data)
{
struct usbnet *dev = netdev_priv(net);
u16 *eeprom_buff;
int first_word, last_word;
int i, ret;
if (eeprom->len == 0)
return -EINVAL;
eeprom->magic = AX88179_EEPROM_MAGIC;
first_word = eeprom->offset >> 1;
last_word = (eeprom->offset + eeprom->len - 1) >> 1;
eeprom_buff = kmalloc(sizeof(u16) * (last_word - first_word + 1),
GFP_KERNEL);
if (!eeprom_buff)
return -ENOMEM;
for (i = first_word; i <= last_word; i++) {
ret = __ax88179_read_cmd(dev, AX_ACCESS_EEPROM, i, 1, 2,
&eeprom_buff[i - first_word],
0);
if (ret < 0) {
kfree(eeprom_buff);
return -EIO;
}
}
memcpy(data, (u8 *)eeprom_buff + (eeprom->offset & 1), eeprom->len);
kfree(eeprom_buff);
return 0;
}
static int ax88179_get_settings(struct net_device *net, struct ethtool_cmd *cmd)
{
struct usbnet *dev = netdev_priv(net);
return mii_ethtool_gset(&dev->mii, cmd);
}
static int ax88179_set_settings(struct net_device *net, struct ethtool_cmd *cmd)
{
struct usbnet *dev = netdev_priv(net);
return mii_ethtool_sset(&dev->mii, cmd);
}
static int
ax88179_ethtool_get_eee(struct usbnet *dev, struct ethtool_eee *data)
{
int val;
val = ax88179_phy_read_mmd_indirect(dev, MDIO_PCS_EEE_ABLE,
MDIO_MMD_PCS);
if (val < 0)
return val;
data->supported = mmd_eee_cap_to_ethtool_sup_t(val);
val = ax88179_phy_read_mmd_indirect(dev, MDIO_AN_EEE_ADV,
MDIO_MMD_AN);
if (val < 0)
return val;
data->advertised = mmd_eee_adv_to_ethtool_adv_t(val);
val = ax88179_phy_read_mmd_indirect(dev, MDIO_AN_EEE_LPABLE,
MDIO_MMD_AN);
if (val < 0)
return val;
data->lp_advertised = mmd_eee_adv_to_ethtool_adv_t(val);
return 0;
}
static int
ax88179_ethtool_set_eee(struct usbnet *dev, struct ethtool_eee *data)
{
u16 tmp16 = ethtool_adv_to_mmd_eee_adv_t(data->advertised);
return ax88179_phy_write_mmd_indirect(dev, MDIO_AN_EEE_ADV,
MDIO_MMD_AN, tmp16);
}
static int ax88179_chk_eee(struct usbnet *dev)
{
struct ethtool_cmd ecmd = { .cmd = ETHTOOL_GSET };
struct ax88179_data *priv = (struct ax88179_data *)dev->data;
mii_ethtool_gset(&dev->mii, &ecmd);
if (ecmd.duplex & DUPLEX_FULL) {
int eee_lp, eee_cap, eee_adv;
u32 lp, cap, adv, supported = 0;
eee_cap = ax88179_phy_read_mmd_indirect(dev,
MDIO_PCS_EEE_ABLE,
MDIO_MMD_PCS);
if (eee_cap < 0) {
priv->eee_active = 0;
return false;
}
cap = mmd_eee_cap_to_ethtool_sup_t(eee_cap);
if (!cap) {
priv->eee_active = 0;
return false;
}
eee_lp = ax88179_phy_read_mmd_indirect(dev,
MDIO_AN_EEE_LPABLE,
MDIO_MMD_AN);
if (eee_lp < 0) {
priv->eee_active = 0;
return false;
}
eee_adv = ax88179_phy_read_mmd_indirect(dev,
MDIO_AN_EEE_ADV,
MDIO_MMD_AN);
if (eee_adv < 0) {
priv->eee_active = 0;
return false;
}
adv = mmd_eee_adv_to_ethtool_adv_t(eee_adv);
lp = mmd_eee_adv_to_ethtool_adv_t(eee_lp);
supported = (ecmd.speed == SPEED_1000) ?
SUPPORTED_1000baseT_Full :
SUPPORTED_100baseT_Full;
if (!(lp & adv & supported)) {
priv->eee_active = 0;
return false;
}
priv->eee_active = 1;
return true;
}
priv->eee_active = 0;
return false;
}
static void ax88179_disable_eee(struct usbnet *dev)
{
u16 tmp16;
tmp16 = GMII_PHY_PGSEL_PAGE3;
ax88179_write_cmd(dev, AX_ACCESS_PHY, AX88179_PHY_ID,
GMII_PHY_PAGE_SELECT, 2, &tmp16);
tmp16 = 0x3246;
ax88179_write_cmd(dev, AX_ACCESS_PHY, AX88179_PHY_ID,
MII_PHYADDR, 2, &tmp16);
tmp16 = GMII_PHY_PGSEL_PAGE0;
ax88179_write_cmd(dev, AX_ACCESS_PHY, AX88179_PHY_ID,
GMII_PHY_PAGE_SELECT, 2, &tmp16);
}
static void ax88179_enable_eee(struct usbnet *dev)
{
u16 tmp16;
tmp16 = GMII_PHY_PGSEL_PAGE3;
ax88179_write_cmd(dev, AX_ACCESS_PHY, AX88179_PHY_ID,
GMII_PHY_PAGE_SELECT, 2, &tmp16);
tmp16 = 0x3247;
ax88179_write_cmd(dev, AX_ACCESS_PHY, AX88179_PHY_ID,
MII_PHYADDR, 2, &tmp16);
tmp16 = GMII_PHY_PGSEL_PAGE5;
ax88179_write_cmd(dev, AX_ACCESS_PHY, AX88179_PHY_ID,
GMII_PHY_PAGE_SELECT, 2, &tmp16);
tmp16 = 0x0680;
ax88179_write_cmd(dev, AX_ACCESS_PHY, AX88179_PHY_ID,
MII_BMSR, 2, &tmp16);
tmp16 = GMII_PHY_PGSEL_PAGE0;
ax88179_write_cmd(dev, AX_ACCESS_PHY, AX88179_PHY_ID,
GMII_PHY_PAGE_SELECT, 2, &tmp16);
}
static int ax88179_get_eee(struct net_device *net, struct ethtool_eee *edata)
{
struct usbnet *dev = netdev_priv(net);
struct ax88179_data *priv = (struct ax88179_data *)dev->data;
edata->eee_enabled = priv->eee_enabled;
edata->eee_active = priv->eee_active;
return ax88179_ethtool_get_eee(dev, edata);
}
static int ax88179_set_eee(struct net_device *net, struct ethtool_eee *edata)
{
struct usbnet *dev = netdev_priv(net);
struct ax88179_data *priv = (struct ax88179_data *)dev->data;
int ret = -EOPNOTSUPP;
priv->eee_enabled = edata->eee_enabled;
if (!priv->eee_enabled) {
ax88179_disable_eee(dev);
} else {
priv->eee_enabled = ax88179_chk_eee(dev);
if (!priv->eee_enabled)
return -EOPNOTSUPP;
ax88179_enable_eee(dev);
}
ret = ax88179_ethtool_set_eee(dev, edata);
if (ret)
return ret;
mii_nway_restart(&dev->mii);
usbnet_link_change(dev, 0, 0);
return ret;
}
static int ax88179_ioctl(struct net_device *net, struct ifreq *rq, int cmd)
{
struct usbnet *dev = netdev_priv(net);
return generic_mii_ioctl(&dev->mii, if_mii(rq), cmd, NULL);
}
static void ax88179_set_multicast(struct net_device *net)
{
struct usbnet *dev = netdev_priv(net);
struct ax88179_data *data = (struct ax88179_data *)dev->data;
u8 *m_filter = ((u8 *)dev->data) + 12;
data->rxctl = (AX_RX_CTL_START | AX_RX_CTL_AB | AX_RX_CTL_IPE);
if (net->flags & IFF_PROMISC) {
data->rxctl |= AX_RX_CTL_PRO;
} else if (net->flags & IFF_ALLMULTI ||
netdev_mc_count(net) > AX_MAX_MCAST) {
data->rxctl |= AX_RX_CTL_AMALL;
} else if (netdev_mc_empty(net)) {
} else {
u32 crc_bits;
struct netdev_hw_addr *ha;
memset(m_filter, 0, AX_MCAST_FLTSIZE);
netdev_for_each_mc_addr(ha, net) {
crc_bits = ether_crc(ETH_ALEN, ha->addr) >> 26;
*(m_filter + (crc_bits >> 3)) |= (1 << (crc_bits & 7));
}
ax88179_write_cmd_async(dev, AX_ACCESS_MAC, AX_MULFLTARY,
AX_MCAST_FLTSIZE, AX_MCAST_FLTSIZE,
m_filter);
data->rxctl |= AX_RX_CTL_AM;
}
ax88179_write_cmd_async(dev, AX_ACCESS_MAC, AX_RX_CTL,
2, 2, &data->rxctl);
}
static int
ax88179_set_features(struct net_device *net, netdev_features_t features)
{
u8 tmp;
struct usbnet *dev = netdev_priv(net);
netdev_features_t changed = net->features ^ features;
if (changed & NETIF_F_IP_CSUM) {
ax88179_read_cmd(dev, AX_ACCESS_MAC, AX_TXCOE_CTL, 1, 1, &tmp);
tmp ^= AX_TXCOE_TCP | AX_TXCOE_UDP;
ax88179_write_cmd(dev, AX_ACCESS_MAC, AX_TXCOE_CTL, 1, 1, &tmp);
}
if (changed & NETIF_F_IPV6_CSUM) {
ax88179_read_cmd(dev, AX_ACCESS_MAC, AX_TXCOE_CTL, 1, 1, &tmp);
tmp ^= AX_TXCOE_TCPV6 | AX_TXCOE_UDPV6;
ax88179_write_cmd(dev, AX_ACCESS_MAC, AX_TXCOE_CTL, 1, 1, &tmp);
}
if (changed & NETIF_F_RXCSUM) {
ax88179_read_cmd(dev, AX_ACCESS_MAC, AX_RXCOE_CTL, 1, 1, &tmp);
tmp ^= AX_RXCOE_IP | AX_RXCOE_TCP | AX_RXCOE_UDP |
AX_RXCOE_TCPV6 | AX_RXCOE_UDPV6;
ax88179_write_cmd(dev, AX_ACCESS_MAC, AX_RXCOE_CTL, 1, 1, &tmp);
}
return 0;
}
static int ax88179_change_mtu(struct net_device *net, int new_mtu)
{
struct usbnet *dev = netdev_priv(net);
u16 tmp16;
net->mtu = new_mtu;
dev->hard_mtu = net->mtu + net->hard_header_len;
if (net->mtu > 1500) {
ax88179_read_cmd(dev, AX_ACCESS_MAC, AX_MEDIUM_STATUS_MODE,
2, 2, &tmp16);
tmp16 |= AX_MEDIUM_JUMBO_EN;
ax88179_write_cmd(dev, AX_ACCESS_MAC, AX_MEDIUM_STATUS_MODE,
2, 2, &tmp16);
} else {
ax88179_read_cmd(dev, AX_ACCESS_MAC, AX_MEDIUM_STATUS_MODE,
2, 2, &tmp16);
tmp16 &= ~AX_MEDIUM_JUMBO_EN;
ax88179_write_cmd(dev, AX_ACCESS_MAC, AX_MEDIUM_STATUS_MODE,
2, 2, &tmp16);
}
usbnet_update_max_qlen(dev);
return 0;
}
static int ax88179_set_mac_addr(struct net_device *net, void *p)
{
struct usbnet *dev = netdev_priv(net);
struct sockaddr *addr = p;
int ret;
if (netif_running(net))
return -EBUSY;
if (!is_valid_ether_addr(addr->sa_data))
return -EADDRNOTAVAIL;
memcpy(net->dev_addr, addr->sa_data, ETH_ALEN);
ret = ax88179_write_cmd(dev, AX_ACCESS_MAC, AX_NODE_ID, ETH_ALEN,
ETH_ALEN, net->dev_addr);
if (ret < 0)
return ret;
return 0;
}
static int ax88179_check_eeprom(struct usbnet *dev)
{
u8 i, buf, eeprom[20];
u16 csum, delay = HZ / 10;
unsigned long jtimeout;
for (i = 0; i < 6; i++) {
buf = i;
if (ax88179_write_cmd(dev, AX_ACCESS_MAC, AX_SROM_ADDR,
1, 1, &buf) < 0)
return -EINVAL;
buf = EEP_RD;
if (ax88179_write_cmd(dev, AX_ACCESS_MAC, AX_SROM_CMD,
1, 1, &buf) < 0)
return -EINVAL;
jtimeout = jiffies + delay;
do {
ax88179_read_cmd(dev, AX_ACCESS_MAC, AX_SROM_CMD,
1, 1, &buf);
if (time_after(jiffies, jtimeout))
return -EINVAL;
} while (buf & EEP_BUSY);
__ax88179_read_cmd(dev, AX_ACCESS_MAC, AX_SROM_DATA_LOW,
2, 2, &eeprom[i * 2], 0);
if ((i == 0) && (eeprom[0] == 0xFF))
return -EINVAL;
}
csum = eeprom[6] + eeprom[7] + eeprom[8] + eeprom[9];
csum = (csum >> 8) + (csum & 0xff);
if ((csum + eeprom[10]) != 0xff)
return -EINVAL;
return 0;
}
static int ax88179_check_efuse(struct usbnet *dev, u16 *ledmode)
{
u8 i;
u8 efuse[64];
u16 csum = 0;
if (ax88179_read_cmd(dev, AX_ACCESS_EFUS, 0, 64, 64, efuse) < 0)
return -EINVAL;
if (*efuse == 0xFF)
return -EINVAL;
for (i = 0; i < 64; i++)
csum = csum + efuse[i];
while (csum > 255)
csum = (csum & 0x00FF) + ((csum >> 8) & 0x00FF);
if (csum != 0xFF)
return -EINVAL;
*ledmode = (efuse[51] << 8) | efuse[52];
return 0;
}
static int ax88179_convert_old_led(struct usbnet *dev, u16 *ledvalue)
{
u16 led;
if (ax88179_read_cmd(dev, AX_ACCESS_EEPROM, 0x3C, 1, 2, &led) < 0)
return -EINVAL;
led >>= 8;
switch (led) {
case 0xFF:
led = LED0_ACTIVE | LED1_LINK_10 | LED1_LINK_100 |
LED1_LINK_1000 | LED2_ACTIVE | LED2_LINK_10 |
LED2_LINK_100 | LED2_LINK_1000 | LED_VALID;
break;
case 0xFE:
led = LED0_ACTIVE | LED1_LINK_1000 | LED2_LINK_100 | LED_VALID;
break;
case 0xFD:
led = LED0_ACTIVE | LED1_LINK_1000 | LED2_LINK_100 |
LED2_LINK_10 | LED_VALID;
break;
case 0xFC:
led = LED0_ACTIVE | LED1_ACTIVE | LED1_LINK_1000 | LED2_ACTIVE |
LED2_LINK_100 | LED2_LINK_10 | LED_VALID;
break;
default:
led = LED0_ACTIVE | LED1_LINK_10 | LED1_LINK_100 |
LED1_LINK_1000 | LED2_ACTIVE | LED2_LINK_10 |
LED2_LINK_100 | LED2_LINK_1000 | LED_VALID;
break;
}
*ledvalue = led;
return 0;
}
static int ax88179_led_setting(struct usbnet *dev)
{
u8 ledfd, value = 0;
u16 tmp, ledact, ledlink, ledvalue = 0, delay = HZ / 10;
unsigned long jtimeout;
ax88179_read_cmd(dev, AX_ACCESS_MAC, GENERAL_STATUS, 1, 1, &value);
if (!(value & AX_SECLD)) {
value = AX_GPIO_CTRL_GPIO3EN | AX_GPIO_CTRL_GPIO2EN |
AX_GPIO_CTRL_GPIO1EN;
if (ax88179_write_cmd(dev, AX_ACCESS_MAC, AX_GPIO_CTRL,
1, 1, &value) < 0)
return -EINVAL;
}
if (!ax88179_check_eeprom(dev)) {
value = 0x42;
if (ax88179_write_cmd(dev, AX_ACCESS_MAC, AX_SROM_ADDR,
1, 1, &value) < 0)
return -EINVAL;
value = EEP_RD;
if (ax88179_write_cmd(dev, AX_ACCESS_MAC, AX_SROM_CMD,
1, 1, &value) < 0)
return -EINVAL;
jtimeout = jiffies + delay;
do {
ax88179_read_cmd(dev, AX_ACCESS_MAC, AX_SROM_CMD,
1, 1, &value);
if (time_after(jiffies, jtimeout))
return -EINVAL;
} while (value & EEP_BUSY);
ax88179_read_cmd(dev, AX_ACCESS_MAC, AX_SROM_DATA_HIGH,
1, 1, &value);
ledvalue = (value << 8);
ax88179_read_cmd(dev, AX_ACCESS_MAC, AX_SROM_DATA_LOW,
1, 1, &value);
ledvalue |= value;
if ((ledvalue == 0xFFFF) || ((ledvalue & LED_VALID) == 0))
ax88179_convert_old_led(dev, &ledvalue);
} else if (!ax88179_check_efuse(dev, &ledvalue)) {
if ((ledvalue == 0xFFFF) || ((ledvalue & LED_VALID) == 0))
ax88179_convert_old_led(dev, &ledvalue);
} else {
ax88179_convert_old_led(dev, &ledvalue);
}
tmp = GMII_PHY_PGSEL_EXT;
ax88179_write_cmd(dev, AX_ACCESS_PHY, AX88179_PHY_ID,
GMII_PHY_PAGE_SELECT, 2, &tmp);
tmp = 0x2c;
ax88179_write_cmd(dev, AX_ACCESS_PHY, AX88179_PHY_ID,
GMII_PHYPAGE, 2, &tmp);
ax88179_read_cmd(dev, AX_ACCESS_PHY, AX88179_PHY_ID,
GMII_LED_ACT, 2, &ledact);
ax88179_read_cmd(dev, AX_ACCESS_PHY, AX88179_PHY_ID,
GMII_LED_LINK, 2, &ledlink);
ledact &= GMII_LED_ACTIVE_MASK;
ledlink &= GMII_LED_LINK_MASK;
if (ledvalue & LED0_ACTIVE)
ledact |= GMII_LED0_ACTIVE;
if (ledvalue & LED1_ACTIVE)
ledact |= GMII_LED1_ACTIVE;
if (ledvalue & LED2_ACTIVE)
ledact |= GMII_LED2_ACTIVE;
if (ledvalue & LED0_LINK_10)
ledlink |= GMII_LED0_LINK_10;
if (ledvalue & LED1_LINK_10)
ledlink |= GMII_LED1_LINK_10;
if (ledvalue & LED2_LINK_10)
ledlink |= GMII_LED2_LINK_10;
if (ledvalue & LED0_LINK_100)
ledlink |= GMII_LED0_LINK_100;
if (ledvalue & LED1_LINK_100)
ledlink |= GMII_LED1_LINK_100;
if (ledvalue & LED2_LINK_100)
ledlink |= GMII_LED2_LINK_100;
if (ledvalue & LED0_LINK_1000)
ledlink |= GMII_LED0_LINK_1000;
if (ledvalue & LED1_LINK_1000)
ledlink |= GMII_LED1_LINK_1000;
if (ledvalue & LED2_LINK_1000)
ledlink |= GMII_LED2_LINK_1000;
tmp = ledact;
ax88179_write_cmd(dev, AX_ACCESS_PHY, AX88179_PHY_ID,
GMII_LED_ACT, 2, &tmp);
tmp = ledlink;
ax88179_write_cmd(dev, AX_ACCESS_PHY, AX88179_PHY_ID,
GMII_LED_LINK, 2, &tmp);
tmp = GMII_PHY_PGSEL_PAGE0;
ax88179_write_cmd(dev, AX_ACCESS_PHY, AX88179_PHY_ID,
GMII_PHY_PAGE_SELECT, 2, &tmp);
ledfd = 0;
if (ledvalue & LED0_FD)
ledfd |= 0x01;
else if ((ledvalue & LED0_USB3_MASK) == 0)
ledfd |= 0x02;
if (ledvalue & LED1_FD)
ledfd |= 0x04;
else if ((ledvalue & LED1_USB3_MASK) == 0)
ledfd |= 0x08;
if (ledvalue & LED2_FD)
ledfd |= 0x10;
else if ((ledvalue & LED2_USB3_MASK) == 0)
ledfd |= 0x20;
ax88179_write_cmd(dev, AX_ACCESS_MAC, AX_LEDCTRL, 1, 1, &ledfd);
return 0;
}
static int ax88179_bind(struct usbnet *dev, struct usb_interface *intf)
{
u8 buf[5];
u16 *tmp16;
u8 *tmp;
struct ax88179_data *ax179_data = (struct ax88179_data *)dev->data;
struct ethtool_eee eee_data;
usbnet_get_endpoints(dev, intf);
tmp16 = (u16 *)buf;
tmp = (u8 *)buf;
memset(ax179_data, 0, sizeof(*ax179_data));
*tmp16 = 0;
ax88179_write_cmd(dev, AX_ACCESS_MAC, AX_PHYPWR_RSTCTL, 2, 2, tmp16);
*tmp16 = AX_PHYPWR_RSTCTL_IPRL;
ax88179_write_cmd(dev, AX_ACCESS_MAC, AX_PHYPWR_RSTCTL, 2, 2, tmp16);
msleep(200);
*tmp = AX_CLK_SELECT_ACS | AX_CLK_SELECT_BCS;
ax88179_write_cmd(dev, AX_ACCESS_MAC, AX_CLK_SELECT, 1, 1, tmp);
msleep(100);
ax88179_read_cmd(dev, AX_ACCESS_MAC, AX_NODE_ID, ETH_ALEN,
ETH_ALEN, dev->net->dev_addr);
memcpy(dev->net->perm_addr, dev->net->dev_addr, ETH_ALEN);
memcpy(tmp, &AX88179_BULKIN_SIZE[0], 5);
ax88179_write_cmd(dev, AX_ACCESS_MAC, AX_RX_BULKIN_QCTRL, 5, 5, tmp);
dev->rx_urb_size = 1024 * 20;
*tmp = 0x34;
ax88179_write_cmd(dev, AX_ACCESS_MAC, AX_PAUSE_WATERLVL_LOW, 1, 1, tmp);
*tmp = 0x52;
ax88179_write_cmd(dev, AX_ACCESS_MAC, AX_PAUSE_WATERLVL_HIGH,
1, 1, tmp);
dev->net->netdev_ops = &ax88179_netdev_ops;
dev->net->ethtool_ops = &ax88179_ethtool_ops;
dev->net->needed_headroom = 8;
dev->net->max_mtu = 4088;
dev->mii.dev = dev->net;
dev->mii.mdio_read = ax88179_mdio_read;
dev->mii.mdio_write = ax88179_mdio_write;
dev->mii.phy_id_mask = 0xff;
dev->mii.reg_num_mask = 0xff;
dev->mii.phy_id = 0x03;
dev->mii.supports_gmii = 1;
dev->net->features |= NETIF_F_IP_CSUM | NETIF_F_IPV6_CSUM |
NETIF_F_RXCSUM;
dev->net->hw_features |= NETIF_F_IP_CSUM | NETIF_F_IPV6_CSUM |
NETIF_F_RXCSUM;
*tmp = AX_RXCOE_IP | AX_RXCOE_TCP | AX_RXCOE_UDP |
AX_RXCOE_TCPV6 | AX_RXCOE_UDPV6;
ax88179_write_cmd(dev, AX_ACCESS_MAC, AX_RXCOE_CTL, 1, 1, tmp);
*tmp = AX_TXCOE_IP | AX_TXCOE_TCP | AX_TXCOE_UDP |
AX_TXCOE_TCPV6 | AX_TXCOE_UDPV6;
ax88179_write_cmd(dev, AX_ACCESS_MAC, AX_TXCOE_CTL, 1, 1, tmp);
*tmp16 = AX_RX_CTL_DROPCRCERR | AX_RX_CTL_IPE | AX_RX_CTL_START |
AX_RX_CTL_AP | AX_RX_CTL_AMALL | AX_RX_CTL_AB;
ax88179_write_cmd(dev, AX_ACCESS_MAC, AX_RX_CTL, 2, 2, tmp16);
*tmp = AX_MONITOR_MODE_PMETYPE | AX_MONITOR_MODE_PMEPOL |
AX_MONITOR_MODE_RWMP;
ax88179_write_cmd(dev, AX_ACCESS_MAC, AX_MONITOR_MOD, 1, 1, tmp);
*tmp16 = AX_MEDIUM_RECEIVE_EN | AX_MEDIUM_TXFLOW_CTRLEN |
AX_MEDIUM_RXFLOW_CTRLEN | AX_MEDIUM_FULL_DUPLEX |
AX_MEDIUM_GIGAMODE;
ax88179_write_cmd(dev, AX_ACCESS_MAC, AX_MEDIUM_STATUS_MODE,
2, 2, tmp16);
ax88179_led_setting(dev);
ax179_data->eee_enabled = 0;
ax179_data->eee_active = 0;
ax88179_disable_eee(dev);
ax88179_ethtool_get_eee(dev, &eee_data);
eee_data.advertised = 0;
ax88179_ethtool_set_eee(dev, &eee_data);
mii_nway_restart(&dev->mii);
usbnet_link_change(dev, 0, 0);
return 0;
}
static void ax88179_unbind(struct usbnet *dev, struct usb_interface *intf)
{
u16 tmp16;
tmp16 = AX_RX_CTL_STOP;
ax88179_write_cmd(dev, AX_ACCESS_MAC, AX_RX_CTL, 2, 2, &tmp16);
tmp16 = 0;
ax88179_write_cmd(dev, AX_ACCESS_MAC, AX_CLK_SELECT, 1, 1, &tmp16);
tmp16 = 0;
ax88179_write_cmd(dev, AX_ACCESS_MAC, AX_PHYPWR_RSTCTL, 2, 2, &tmp16);
}
static void
ax88179_rx_checksum(struct sk_buff *skb, u32 *pkt_hdr)
{
skb->ip_summed = CHECKSUM_NONE;
if ((*pkt_hdr & AX_RXHDR_L3CSUM_ERR) ||
(*pkt_hdr & AX_RXHDR_L4CSUM_ERR))
return;
if (((*pkt_hdr & AX_RXHDR_L4_TYPE_MASK) == AX_RXHDR_L4_TYPE_TCP) ||
((*pkt_hdr & AX_RXHDR_L4_TYPE_MASK) == AX_RXHDR_L4_TYPE_UDP))
skb->ip_summed = CHECKSUM_UNNECESSARY;
}
static int ax88179_rx_fixup(struct usbnet *dev, struct sk_buff *skb)
{
struct sk_buff *ax_skb;
int pkt_cnt;
u32 rx_hdr;
u16 hdr_off;
u32 *pkt_hdr;
if (skb->len < dev->net->hard_header_len)
return 0;
skb_trim(skb, skb->len - 4);
memcpy(&rx_hdr, skb_tail_pointer(skb), 4);
le32_to_cpus(&rx_hdr);
pkt_cnt = (u16)rx_hdr;
hdr_off = (u16)(rx_hdr >> 16);
pkt_hdr = (u32 *)(skb->data + hdr_off);
while (pkt_cnt--) {
u16 pkt_len;
le32_to_cpus(pkt_hdr);
pkt_len = (*pkt_hdr >> 16) & 0x1fff;
if ((*pkt_hdr & AX_RXHDR_CRC_ERR) ||
(*pkt_hdr & AX_RXHDR_DROP_ERR)) {
skb_pull(skb, (pkt_len + 7) & 0xFFF8);
pkt_hdr++;
continue;
}
if (pkt_cnt == 0) {
skb_pull(skb, 2);
skb->len = pkt_len;
skb_set_tail_pointer(skb, pkt_len);
skb->truesize = pkt_len + sizeof(struct sk_buff);
ax88179_rx_checksum(skb, pkt_hdr);
return 1;
}
ax_skb = skb_clone(skb, GFP_ATOMIC);
if (ax_skb) {
ax_skb->len = pkt_len;
ax_skb->data = skb->data + 2;
skb_set_tail_pointer(ax_skb, pkt_len);
ax_skb->truesize = pkt_len + sizeof(struct sk_buff);
ax88179_rx_checksum(ax_skb, pkt_hdr);
usbnet_skb_return(dev, ax_skb);
} else {
return 0;
}
skb_pull(skb, (pkt_len + 7) & 0xFFF8);
pkt_hdr++;
}
return 1;
}
static struct sk_buff *
ax88179_tx_fixup(struct usbnet *dev, struct sk_buff *skb, gfp_t flags)
{
u32 tx_hdr1, tx_hdr2;
int frame_size = dev->maxpacket;
int mss = skb_shinfo(skb)->gso_size;
int headroom;
tx_hdr1 = skb->len;
tx_hdr2 = mss;
if (((skb->len + 8) % frame_size) == 0)
tx_hdr2 |= 0x80008000;
headroom = skb_headroom(skb) - 8;
if ((skb_header_cloned(skb) || headroom < 0) &&
pskb_expand_head(skb, headroom < 0 ? 8 : 0, 0, GFP_ATOMIC)) {
dev_kfree_skb_any(skb);
return NULL;
}
skb_push(skb, 4);
cpu_to_le32s(&tx_hdr2);
skb_copy_to_linear_data(skb, &tx_hdr2, 4);
skb_push(skb, 4);
cpu_to_le32s(&tx_hdr1);
skb_copy_to_linear_data(skb, &tx_hdr1, 4);
return skb;
}
static int ax88179_link_reset(struct usbnet *dev)
{
struct ax88179_data *ax179_data = (struct ax88179_data *)dev->data;
u8 tmp[5], link_sts;
u16 mode, tmp16, delay = HZ / 10;
u32 tmp32 = 0x40000000;
unsigned long jtimeout;
jtimeout = jiffies + delay;
while (tmp32 & 0x40000000) {
mode = 0;
ax88179_write_cmd(dev, AX_ACCESS_MAC, AX_RX_CTL, 2, 2, &mode);
ax88179_write_cmd(dev, AX_ACCESS_MAC, AX_RX_CTL, 2, 2,
&ax179_data->rxctl);
ax88179_read_cmd(dev, 0x81, 0x8c, 0, 4, &tmp32);
if (time_after(jiffies, jtimeout))
return 0;
}
mode = AX_MEDIUM_RECEIVE_EN | AX_MEDIUM_TXFLOW_CTRLEN |
AX_MEDIUM_RXFLOW_CTRLEN;
ax88179_read_cmd(dev, AX_ACCESS_MAC, PHYSICAL_LINK_STATUS,
1, 1, &link_sts);
ax88179_read_cmd(dev, AX_ACCESS_PHY, AX88179_PHY_ID,
GMII_PHY_PHYSR, 2, &tmp16);
if (!(tmp16 & GMII_PHY_PHYSR_LINK)) {
return 0;
} else if (GMII_PHY_PHYSR_GIGA == (tmp16 & GMII_PHY_PHYSR_SMASK)) {
mode |= AX_MEDIUM_GIGAMODE | AX_MEDIUM_EN_125MHZ;
if (dev->net->mtu > 1500)
mode |= AX_MEDIUM_JUMBO_EN;
if (link_sts & AX_USB_SS)
memcpy(tmp, &AX88179_BULKIN_SIZE[0], 5);
else if (link_sts & AX_USB_HS)
memcpy(tmp, &AX88179_BULKIN_SIZE[1], 5);
else
memcpy(tmp, &AX88179_BULKIN_SIZE[3], 5);
} else if (GMII_PHY_PHYSR_100 == (tmp16 & GMII_PHY_PHYSR_SMASK)) {
mode |= AX_MEDIUM_PS;
if (link_sts & (AX_USB_SS | AX_USB_HS))
memcpy(tmp, &AX88179_BULKIN_SIZE[2], 5);
else
memcpy(tmp, &AX88179_BULKIN_SIZE[3], 5);
} else {
memcpy(tmp, &AX88179_BULKIN_SIZE[3], 5);
}
ax88179_write_cmd(dev, AX_ACCESS_MAC, AX_RX_BULKIN_QCTRL, 5, 5, tmp);
dev->rx_urb_size = (1024 * (tmp[3] + 2));
if (tmp16 & GMII_PHY_PHYSR_FULL)
mode |= AX_MEDIUM_FULL_DUPLEX;
ax88179_write_cmd(dev, AX_ACCESS_MAC, AX_MEDIUM_STATUS_MODE,
2, 2, &mode);
ax179_data->eee_enabled = ax88179_chk_eee(dev);
netif_carrier_on(dev->net);
return 0;
}
static int ax88179_reset(struct usbnet *dev)
{
u8 buf[5];
u16 *tmp16;
u8 *tmp;
struct ax88179_data *ax179_data = (struct ax88179_data *)dev->data;
struct ethtool_eee eee_data;
tmp16 = (u16 *)buf;
tmp = (u8 *)buf;
*tmp16 = 0;
ax88179_write_cmd(dev, AX_ACCESS_MAC, AX_PHYPWR_RSTCTL, 2, 2, tmp16);
*tmp16 = AX_PHYPWR_RSTCTL_IPRL;
ax88179_write_cmd(dev, AX_ACCESS_MAC, AX_PHYPWR_RSTCTL, 2, 2, tmp16);
msleep(200);
*tmp = AX_CLK_SELECT_ACS | AX_CLK_SELECT_BCS;
ax88179_write_cmd(dev, AX_ACCESS_MAC, AX_CLK_SELECT, 1, 1, tmp);
msleep(100);
ax88179_auto_detach(dev, 0);
ax88179_read_cmd(dev, AX_ACCESS_MAC, AX_NODE_ID, ETH_ALEN, ETH_ALEN,
dev->net->dev_addr);
memcpy(dev->net->perm_addr, dev->net->dev_addr, ETH_ALEN);
memcpy(tmp, &AX88179_BULKIN_SIZE[0], 5);
ax88179_write_cmd(dev, AX_ACCESS_MAC, AX_RX_BULKIN_QCTRL, 5, 5, tmp);
dev->rx_urb_size = 1024 * 20;
*tmp = 0x34;
ax88179_write_cmd(dev, AX_ACCESS_MAC, AX_PAUSE_WATERLVL_LOW, 1, 1, tmp);
*tmp = 0x52;
ax88179_write_cmd(dev, AX_ACCESS_MAC, AX_PAUSE_WATERLVL_HIGH,
1, 1, tmp);
dev->net->features |= NETIF_F_IP_CSUM | NETIF_F_IPV6_CSUM |
NETIF_F_RXCSUM;
dev->net->hw_features |= NETIF_F_IP_CSUM | NETIF_F_IPV6_CSUM |
NETIF_F_RXCSUM;
*tmp = AX_RXCOE_IP | AX_RXCOE_TCP | AX_RXCOE_UDP |
AX_RXCOE_TCPV6 | AX_RXCOE_UDPV6;
ax88179_write_cmd(dev, AX_ACCESS_MAC, AX_RXCOE_CTL, 1, 1, tmp);
*tmp = AX_TXCOE_IP | AX_TXCOE_TCP | AX_TXCOE_UDP |
AX_TXCOE_TCPV6 | AX_TXCOE_UDPV6;
ax88179_write_cmd(dev, AX_ACCESS_MAC, AX_TXCOE_CTL, 1, 1, tmp);
*tmp16 = AX_RX_CTL_DROPCRCERR | AX_RX_CTL_IPE | AX_RX_CTL_START |
AX_RX_CTL_AP | AX_RX_CTL_AMALL | AX_RX_CTL_AB;
ax88179_write_cmd(dev, AX_ACCESS_MAC, AX_RX_CTL, 2, 2, tmp16);
*tmp = AX_MONITOR_MODE_PMETYPE | AX_MONITOR_MODE_PMEPOL |
AX_MONITOR_MODE_RWMP;
ax88179_write_cmd(dev, AX_ACCESS_MAC, AX_MONITOR_MOD, 1, 1, tmp);
*tmp16 = AX_MEDIUM_RECEIVE_EN | AX_MEDIUM_TXFLOW_CTRLEN |
AX_MEDIUM_RXFLOW_CTRLEN | AX_MEDIUM_FULL_DUPLEX |
AX_MEDIUM_GIGAMODE;
ax88179_write_cmd(dev, AX_ACCESS_MAC, AX_MEDIUM_STATUS_MODE,
2, 2, tmp16);
ax88179_led_setting(dev);
ax179_data->eee_enabled = 0;
ax179_data->eee_active = 0;
ax88179_disable_eee(dev);
ax88179_ethtool_get_eee(dev, &eee_data);
eee_data.advertised = 0;
ax88179_ethtool_set_eee(dev, &eee_data);
mii_nway_restart(&dev->mii);
usbnet_link_change(dev, 0, 0);
return 0;
}
static int ax88179_stop(struct usbnet *dev)
{
u16 tmp16;
ax88179_read_cmd(dev, AX_ACCESS_MAC, AX_MEDIUM_STATUS_MODE,
2, 2, &tmp16);
tmp16 &= ~AX_MEDIUM_RECEIVE_EN;
ax88179_write_cmd(dev, AX_ACCESS_MAC, AX_MEDIUM_STATUS_MODE,
2, 2, &tmp16);
return 0;
}
