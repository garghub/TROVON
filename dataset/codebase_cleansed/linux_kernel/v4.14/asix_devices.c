static void asix_status(struct usbnet *dev, struct urb *urb)
{
struct ax88172_int_data *event;
int link;
if (urb->actual_length < 8)
return;
event = urb->transfer_buffer;
link = event->link & 0x01;
if (netif_carrier_ok(dev->net) != link) {
usbnet_link_change(dev, link, 1);
netdev_dbg(dev->net, "Link Status is: %d\n", link);
}
}
static void asix_set_netdev_dev_addr(struct usbnet *dev, u8 *addr)
{
if (is_valid_ether_addr(addr)) {
memcpy(dev->net->dev_addr, addr, ETH_ALEN);
} else {
netdev_info(dev->net, "invalid hw address, using random\n");
eth_hw_addr_random(dev->net);
}
}
static u32 asix_get_phyid(struct usbnet *dev)
{
int phy_reg;
u32 phy_id;
int i;
for (i = 0; i < 100; i++) {
phy_reg = asix_mdio_read(dev->net, dev->mii.phy_id, MII_PHYSID1);
if (phy_reg < 0)
return 0;
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
asix_write_medium_mode(dev, mode, 0);
return 0;
}
static void asix_phy_reset(struct usbnet *dev, unsigned int reset_bits)
{
unsigned int timeout = 5000;
asix_mdio_write(dev->net, dev->mii.phy_id, MII_BMCR, reset_bits);
udelay(500);
while (timeout--) {
if (asix_mdio_read(dev->net, dev->mii.phy_id, MII_BMCR)
& BMCR_RESET)
udelay(100);
else
return;
}
netdev_err(dev->net, "BMCR_RESET timeout on phy_id %d\n",
dev->mii.phy_id);
}
static int ax88172_bind(struct usbnet *dev, struct usb_interface *intf)
{
int ret = 0;
u8 buf[ETH_ALEN];
int i;
unsigned long gpio_bits = dev->driver_info->data;
usbnet_get_endpoints(dev,intf);
for (i = 2; i >= 0; i--) {
ret = asix_write_cmd(dev, AX_CMD_WRITE_GPIOS,
(gpio_bits >> (i * 8)) & 0xff, 0, 0, NULL, 0);
if (ret < 0)
goto out;
msleep(5);
}
ret = asix_write_rx_ctl(dev, 0x80, 0);
if (ret < 0)
goto out;
ret = asix_read_cmd(dev, AX88172_CMD_READ_NODE_ID,
0, 0, ETH_ALEN, buf, 0);
if (ret < 0) {
netdev_dbg(dev->net, "read AX_CMD_READ_NODE_ID failed: %d\n",
ret);
goto out;
}
asix_set_netdev_dev_addr(dev, buf);
dev->mii.dev = dev->net;
dev->mii.mdio_read = asix_mdio_read;
dev->mii.mdio_write = asix_mdio_write;
dev->mii.phy_id_mask = 0x3f;
dev->mii.reg_num_mask = 0x1f;
dev->mii.phy_id = asix_get_phy_addr(dev);
dev->net->netdev_ops = &ax88172_netdev_ops;
dev->net->ethtool_ops = &ax88172_ethtool_ops;
dev->net->needed_headroom = 4;
dev->net->needed_tailroom = 4;
asix_phy_reset(dev, BMCR_RESET);
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
asix_write_medium_mode(dev, mode, 0);
return 0;
}
static int ax88772_reset(struct usbnet *dev)
{
struct asix_data *data = (struct asix_data *)&dev->data;
int ret;
ether_addr_copy(data->mac_addr, dev->net->dev_addr);
ret = asix_write_cmd(dev, AX_CMD_WRITE_NODE_ID, 0, 0,
ETH_ALEN, data->mac_addr, 0);
if (ret < 0)
goto out;
ret = asix_write_rx_ctl(dev, AX_DEFAULT_RX_CTL, 0);
if (ret < 0)
goto out;
ret = asix_write_medium_mode(dev, AX88772_MEDIUM_DEFAULT, 0);
if (ret < 0)
goto out;
return 0;
out:
return ret;
}
static int ax88772_hw_reset(struct usbnet *dev, int in_pm)
{
struct asix_data *data = (struct asix_data *)&dev->data;
int ret, embd_phy;
u16 rx_ctl;
ret = asix_write_gpio(dev, AX_GPIO_RSE | AX_GPIO_GPO_2 |
AX_GPIO_GPO2EN, 5, in_pm);
if (ret < 0)
goto out;
embd_phy = ((dev->mii.phy_id & 0x1f) == 0x10 ? 1 : 0);
ret = asix_write_cmd(dev, AX_CMD_SW_PHY_SELECT, embd_phy,
0, 0, NULL, in_pm);
if (ret < 0) {
netdev_dbg(dev->net, "Select PHY #1 failed: %d\n", ret);
goto out;
}
if (embd_phy) {
ret = asix_sw_reset(dev, AX_SWRESET_IPPD, in_pm);
if (ret < 0)
goto out;
usleep_range(10000, 11000);
ret = asix_sw_reset(dev, AX_SWRESET_CLEAR, in_pm);
if (ret < 0)
goto out;
msleep(60);
ret = asix_sw_reset(dev, AX_SWRESET_IPRL | AX_SWRESET_PRL,
in_pm);
if (ret < 0)
goto out;
} else {
ret = asix_sw_reset(dev, AX_SWRESET_IPPD | AX_SWRESET_PRL,
in_pm);
if (ret < 0)
goto out;
}
msleep(150);
if (in_pm && (!asix_mdio_read_nopm(dev->net, dev->mii.phy_id,
MII_PHYSID1))){
ret = -EIO;
goto out;
}
ret = asix_write_rx_ctl(dev, AX_DEFAULT_RX_CTL, in_pm);
if (ret < 0)
goto out;
ret = asix_write_medium_mode(dev, AX88772_MEDIUM_DEFAULT, in_pm);
if (ret < 0)
goto out;
ret = asix_write_cmd(dev, AX_CMD_WRITE_IPG0,
AX88772_IPG0_DEFAULT | AX88772_IPG1_DEFAULT,
AX88772_IPG2_DEFAULT, 0, NULL, in_pm);
if (ret < 0) {
netdev_dbg(dev->net, "Write IPG,IPG1,IPG2 failed: %d\n", ret);
goto out;
}
ether_addr_copy(data->mac_addr, dev->net->dev_addr);
ret = asix_write_cmd(dev, AX_CMD_WRITE_NODE_ID, 0, 0,
ETH_ALEN, data->mac_addr, in_pm);
if (ret < 0)
goto out;
ret = asix_write_rx_ctl(dev, AX_DEFAULT_RX_CTL, in_pm);
if (ret < 0)
goto out;
rx_ctl = asix_read_rx_ctl(dev, in_pm);
netdev_dbg(dev->net, "RX_CTL is 0x%04x after all initializations\n",
rx_ctl);
rx_ctl = asix_read_medium_status(dev, in_pm);
netdev_dbg(dev->net,
"Medium Status is 0x%04x after all initializations\n",
rx_ctl);
return 0;
out:
return ret;
}
static int ax88772a_hw_reset(struct usbnet *dev, int in_pm)
{
struct asix_data *data = (struct asix_data *)&dev->data;
int ret, embd_phy;
u16 rx_ctl, phy14h, phy15h, phy16h;
u8 chipcode = 0;
ret = asix_write_gpio(dev, AX_GPIO_RSE, 5, in_pm);
if (ret < 0)
goto out;
embd_phy = ((dev->mii.phy_id & 0x1f) == 0x10 ? 1 : 0);
ret = asix_write_cmd(dev, AX_CMD_SW_PHY_SELECT, embd_phy |
AX_PHYSEL_SSEN, 0, 0, NULL, in_pm);
if (ret < 0) {
netdev_dbg(dev->net, "Select PHY #1 failed: %d\n", ret);
goto out;
}
usleep_range(10000, 11000);
ret = asix_sw_reset(dev, AX_SWRESET_IPPD | AX_SWRESET_IPRL, in_pm);
if (ret < 0)
goto out;
usleep_range(10000, 11000);
ret = asix_sw_reset(dev, AX_SWRESET_IPRL, in_pm);
if (ret < 0)
goto out;
msleep(160);
ret = asix_sw_reset(dev, AX_SWRESET_CLEAR, in_pm);
if (ret < 0)
goto out;
ret = asix_sw_reset(dev, AX_SWRESET_IPRL, in_pm);
if (ret < 0)
goto out;
msleep(200);
if (in_pm && (!asix_mdio_read_nopm(dev->net, dev->mii.phy_id,
MII_PHYSID1))) {
ret = -1;
goto out;
}
ret = asix_read_cmd(dev, AX_CMD_STATMNGSTS_REG, 0,
0, 1, &chipcode, in_pm);
if (ret < 0)
goto out;
if ((chipcode & AX_CHIPCODE_MASK) == AX_AX88772B_CHIPCODE) {
ret = asix_write_cmd(dev, AX_QCTCTRL, 0x8000, 0x8001,
0, NULL, in_pm);
if (ret < 0) {
netdev_dbg(dev->net, "Write BQ setting failed: %d\n",
ret);
goto out;
}
} else if ((chipcode & AX_CHIPCODE_MASK) == AX_AX88772A_CHIPCODE) {
phy14h = asix_mdio_read_nopm(dev->net, dev->mii.phy_id,
AX88772A_PHY14H);
phy15h = asix_mdio_read_nopm(dev->net, dev->mii.phy_id,
AX88772A_PHY15H);
phy16h = asix_mdio_read_nopm(dev->net, dev->mii.phy_id,
AX88772A_PHY16H);
netdev_dbg(dev->net,
"772a_hw_reset: MR20=0x%x MR21=0x%x MR22=0x%x\n",
phy14h, phy15h, phy16h);
if (phy14h != AX88772A_PHY14H_DEFAULT)
asix_mdio_write_nopm(dev->net, dev->mii.phy_id,
AX88772A_PHY14H,
AX88772A_PHY14H_DEFAULT);
if (phy15h != AX88772A_PHY15H_DEFAULT)
asix_mdio_write_nopm(dev->net, dev->mii.phy_id,
AX88772A_PHY15H,
AX88772A_PHY15H_DEFAULT);
if (phy16h != AX88772A_PHY16H_DEFAULT)
asix_mdio_write_nopm(dev->net, dev->mii.phy_id,
AX88772A_PHY16H,
AX88772A_PHY16H_DEFAULT);
}
ret = asix_write_cmd(dev, AX_CMD_WRITE_IPG0,
AX88772_IPG0_DEFAULT | AX88772_IPG1_DEFAULT,
AX88772_IPG2_DEFAULT, 0, NULL, in_pm);
if (ret < 0) {
netdev_dbg(dev->net, "Write IPG,IPG1,IPG2 failed: %d\n", ret);
goto out;
}
memcpy(data->mac_addr, dev->net->dev_addr, ETH_ALEN);
ret = asix_write_cmd(dev, AX_CMD_WRITE_NODE_ID, 0, 0, ETH_ALEN,
data->mac_addr, in_pm);
if (ret < 0)
goto out;
ret = asix_write_rx_ctl(dev, AX_DEFAULT_RX_CTL, in_pm);
if (ret < 0)
goto out;
ret = asix_write_medium_mode(dev, AX88772_MEDIUM_DEFAULT, in_pm);
if (ret < 0)
return ret;
ret = asix_write_rx_ctl(dev, AX_DEFAULT_RX_CTL, in_pm);
if (ret < 0)
goto out;
rx_ctl = asix_read_rx_ctl(dev, in_pm);
netdev_dbg(dev->net, "RX_CTL is 0x%04x after all initializations\n",
rx_ctl);
rx_ctl = asix_read_medium_status(dev, in_pm);
netdev_dbg(dev->net,
"Medium Status is 0x%04x after all initializations\n",
rx_ctl);
return 0;
out:
return ret;
}
static void ax88772_suspend(struct usbnet *dev)
{
struct asix_common_private *priv = dev->driver_priv;
u16 medium;
medium = asix_read_medium_status(dev, 1);
medium &= ~AX_MEDIUM_RE;
asix_write_medium_mode(dev, medium, 1);
netdev_dbg(dev->net, "ax88772_suspend: medium=0x%04x\n",
asix_read_medium_status(dev, 1));
priv->presvd_phy_bmcr =
asix_mdio_read_nopm(dev->net, dev->mii.phy_id, MII_BMCR);
priv->presvd_phy_advertise =
asix_mdio_read_nopm(dev->net, dev->mii.phy_id, MII_ADVERTISE);
}
static int asix_suspend(struct usb_interface *intf, pm_message_t message)
{
struct usbnet *dev = usb_get_intfdata(intf);
struct asix_common_private *priv = dev->driver_priv;
if (priv && priv->suspend)
priv->suspend(dev);
return usbnet_suspend(intf, message);
}
static void ax88772_restore_phy(struct usbnet *dev)
{
struct asix_common_private *priv = dev->driver_priv;
if (priv->presvd_phy_advertise) {
asix_mdio_write_nopm(dev->net, dev->mii.phy_id, MII_ADVERTISE,
priv->presvd_phy_advertise);
asix_mdio_write_nopm(dev->net, dev->mii.phy_id, MII_BMCR,
priv->presvd_phy_bmcr);
mii_nway_restart(&dev->mii);
priv->presvd_phy_advertise = 0;
priv->presvd_phy_bmcr = 0;
}
}
static void ax88772_resume(struct usbnet *dev)
{
int i;
for (i = 0; i < 3; i++)
if (!ax88772_hw_reset(dev, 1))
break;
ax88772_restore_phy(dev);
}
static void ax88772a_resume(struct usbnet *dev)
{
int i;
for (i = 0; i < 3; i++) {
if (!ax88772a_hw_reset(dev, 1))
break;
}
ax88772_restore_phy(dev);
}
static int asix_resume(struct usb_interface *intf)
{
struct usbnet *dev = usb_get_intfdata(intf);
struct asix_common_private *priv = dev->driver_priv;
if (priv && priv->resume)
priv->resume(dev);
return usbnet_resume(intf);
}
static int ax88772_bind(struct usbnet *dev, struct usb_interface *intf)
{
int ret, i;
u8 buf[ETH_ALEN], chipcode = 0;
u32 phyid;
struct asix_common_private *priv;
usbnet_get_endpoints(dev,intf);
if (dev->driver_info->data & FLAG_EEPROM_MAC) {
for (i = 0; i < (ETH_ALEN >> 1); i++) {
ret = asix_read_cmd(dev, AX_CMD_READ_EEPROM, 0x04 + i,
0, 2, buf + i * 2, 0);
if (ret < 0)
break;
}
} else {
ret = asix_read_cmd(dev, AX_CMD_READ_NODE_ID,
0, 0, ETH_ALEN, buf, 0);
}
if (ret < 0) {
netdev_dbg(dev->net, "Failed to read MAC address: %d\n", ret);
return ret;
}
asix_set_netdev_dev_addr(dev, buf);
dev->mii.dev = dev->net;
dev->mii.mdio_read = asix_mdio_read;
dev->mii.mdio_write = asix_mdio_write;
dev->mii.phy_id_mask = 0x1f;
dev->mii.reg_num_mask = 0x1f;
dev->mii.phy_id = asix_get_phy_addr(dev);
dev->net->netdev_ops = &ax88772_netdev_ops;
dev->net->ethtool_ops = &ax88772_ethtool_ops;
dev->net->needed_headroom = 4;
dev->net->needed_tailroom = 4;
asix_read_cmd(dev, AX_CMD_STATMNGSTS_REG, 0, 0, 1, &chipcode, 0);
chipcode &= AX_CHIPCODE_MASK;
(chipcode == AX_AX88772_CHIPCODE) ? ax88772_hw_reset(dev, 0) :
ax88772a_hw_reset(dev, 0);
phyid = asix_get_phyid(dev);
netdev_dbg(dev->net, "PHYID=0x%08x\n", phyid);
if (dev->driver_info->flags & FLAG_FRAMING_AX) {
dev->rx_urb_size = 2048;
}
dev->driver_priv = kzalloc(sizeof(struct asix_common_private), GFP_KERNEL);
if (!dev->driver_priv)
return -ENOMEM;
priv = dev->driver_priv;
priv->presvd_phy_bmcr = 0;
priv->presvd_phy_advertise = 0;
if (chipcode == AX_AX88772_CHIPCODE) {
priv->resume = ax88772_resume;
priv->suspend = ax88772_suspend;
} else {
priv->resume = ax88772a_resume;
priv->suspend = ax88772_suspend;
}
return 0;
}
static void ax88772_unbind(struct usbnet *dev, struct usb_interface *intf)
{
asix_rx_fixup_common_free(dev->driver_priv);
kfree(dev->driver_priv);
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
asix_read_cmd(dev, AX_CMD_READ_GPIOS, 0, 0, 1, &status, 0);
netdev_dbg(dev->net, "GPIO Status: 0x%04x\n", status);
asix_write_cmd(dev, AX_CMD_WRITE_ENABLE, 0, 0, 0, NULL, 0);
asix_read_cmd(dev, AX_CMD_READ_EEPROM, 0x0017, 0, 2, &eeprom, 0);
asix_write_cmd(dev, AX_CMD_WRITE_DISABLE, 0, 0, 0, NULL, 0);
netdev_dbg(dev->net, "EEPROM index 0x17 is 0x%04x\n", eeprom);
if (eeprom == cpu_to_le16(0xffff)) {
data->phymode = PHY_MODE_MARVELL;
data->ledmode = 0;
gpio0 = 1;
} else {
data->phymode = le16_to_cpu(eeprom) & 0x7F;
data->ledmode = le16_to_cpu(eeprom) >> 8;
gpio0 = (le16_to_cpu(eeprom) & 0x80) ? 0 : 1;
}
netdev_dbg(dev->net, "GPIO0: %d, PhyMode: %d\n", gpio0, data->phymode);
asix_write_gpio(dev, AX_GPIO_RSE | AX_GPIO_GPO_1 |
AX_GPIO_GPO1EN, 40, 0);
if ((le16_to_cpu(eeprom) >> 8) != 1) {
asix_write_gpio(dev, 0x003c, 30, 0);
asix_write_gpio(dev, 0x001c, 300, 0);
asix_write_gpio(dev, 0x003c, 30, 0);
} else {
netdev_dbg(dev->net, "gpio phymode == 1 path\n");
asix_write_gpio(dev, AX_GPIO_GPO1EN, 30, 0);
asix_write_gpio(dev, AX_GPIO_GPO1EN | AX_GPIO_GPO_1, 30, 0);
}
phyid = asix_get_phyid(dev);
netdev_dbg(dev->net, "PHYID=0x%08x\n", phyid);
asix_write_cmd(dev, AX_CMD_SW_PHY_SELECT, 0, 0, 0, NULL, 0);
asix_sw_reset(dev, 0, 0);
msleep(150);
asix_sw_reset(dev, AX_SWRESET_PRL | AX_SWRESET_IPPD, 0);
msleep(150);
asix_write_rx_ctl(dev, 0, 0);
if (data->phymode == PHY_MODE_MARVELL) {
marvell_phy_init(dev);
msleep(60);
} else if (data->phymode == PHY_MODE_RTL8211CL)
rtl8211cl_phy_init(dev);
asix_phy_reset(dev, BMCR_RESET | BMCR_ANENABLE);
asix_mdio_write(dev->net, dev->mii.phy_id, MII_ADVERTISE,
ADVERTISE_ALL | ADVERTISE_CSMA | ADVERTISE_PAUSE_CAP);
asix_mdio_write(dev->net, dev->mii.phy_id, MII_CTRL1000,
ADVERTISE_1000FULL);
asix_write_medium_mode(dev, AX88178_MEDIUM_DEFAULT, 0);
mii_nway_restart(&dev->mii);
memcpy(data->mac_addr, dev->net->dev_addr, ETH_ALEN);
ret = asix_write_cmd(dev, AX_CMD_WRITE_NODE_ID, 0, 0, ETH_ALEN,
data->mac_addr, 0);
if (ret < 0)
return ret;
ret = asix_write_rx_ctl(dev, AX_DEFAULT_RX_CTL, 0);
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
asix_write_medium_mode(dev, mode, 0);
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
rxctl = asix_read_rx_ctl(dev, 0);
asix_write_rx_ctl(dev, (rxctl & ~AX_RX_CTL_MFB_16384) | mfb, 0);
medium = asix_read_medium_status(dev, 0);
if (dev->net->mtu > 1500)
medium |= AX_MEDIUM_JFE;
else
medium &= ~AX_MEDIUM_JFE;
asix_write_medium_mode(dev, medium, 0);
if (dev->rx_urb_size > old_rx_urb_size)
usbnet_unlink_rx_urbs(dev);
}
static int ax88178_change_mtu(struct net_device *net, int new_mtu)
{
struct usbnet *dev = netdev_priv(net);
int ll_mtu = new_mtu + net->hard_header_len + 4;
netdev_dbg(dev->net, "ax88178_change_mtu() new_mtu=%d\n", new_mtu);
if ((ll_mtu % dev->maxpacket) == 0)
return -EDOM;
net->mtu = new_mtu;
dev->hard_mtu = net->mtu + net->hard_header_len;
ax88178_set_mfb(dev);
usbnet_update_max_qlen(dev);
return 0;
}
static int ax88178_bind(struct usbnet *dev, struct usb_interface *intf)
{
int ret;
u8 buf[ETH_ALEN];
usbnet_get_endpoints(dev,intf);
ret = asix_read_cmd(dev, AX_CMD_READ_NODE_ID, 0, 0, ETH_ALEN, buf, 0);
if (ret < 0) {
netdev_dbg(dev->net, "Failed to read MAC address: %d\n", ret);
return ret;
}
asix_set_netdev_dev_addr(dev, buf);
dev->mii.dev = dev->net;
dev->mii.mdio_read = asix_mdio_read;
dev->mii.mdio_write = asix_mdio_write;
dev->mii.phy_id_mask = 0x1f;
dev->mii.reg_num_mask = 0xff;
dev->mii.supports_gmii = 1;
dev->mii.phy_id = asix_get_phy_addr(dev);
dev->net->netdev_ops = &ax88178_netdev_ops;
dev->net->ethtool_ops = &ax88178_ethtool_ops;
dev->net->max_mtu = 16384 - (dev->net->hard_header_len + 4);
asix_sw_reset(dev, 0, 0);
msleep(150);
asix_sw_reset(dev, AX_SWRESET_PRL | AX_SWRESET_IPPD, 0);
msleep(150);
if (dev->driver_info->flags & FLAG_FRAMING_AX) {
dev->rx_urb_size = 2048;
}
dev->driver_priv = kzalloc(sizeof(struct asix_common_private), GFP_KERNEL);
if (!dev->driver_priv)
return -ENOMEM;
return 0;
}
