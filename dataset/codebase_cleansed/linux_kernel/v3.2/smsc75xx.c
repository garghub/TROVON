static int __must_check smsc75xx_read_reg(struct usbnet *dev, u32 index,
u32 *data)
{
u32 *buf = kmalloc(4, GFP_KERNEL);
int ret;
BUG_ON(!dev);
if (!buf)
return -ENOMEM;
ret = usb_control_msg(dev->udev, usb_rcvctrlpipe(dev->udev, 0),
USB_VENDOR_REQUEST_READ_REGISTER,
USB_DIR_IN | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
00, index, buf, 4, USB_CTRL_GET_TIMEOUT);
if (unlikely(ret < 0))
netdev_warn(dev->net,
"Failed to read register index 0x%08x", index);
le32_to_cpus(buf);
*data = *buf;
kfree(buf);
return ret;
}
static int __must_check smsc75xx_write_reg(struct usbnet *dev, u32 index,
u32 data)
{
u32 *buf = kmalloc(4, GFP_KERNEL);
int ret;
BUG_ON(!dev);
if (!buf)
return -ENOMEM;
*buf = data;
cpu_to_le32s(buf);
ret = usb_control_msg(dev->udev, usb_sndctrlpipe(dev->udev, 0),
USB_VENDOR_REQUEST_WRITE_REGISTER,
USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
00, index, buf, 4, USB_CTRL_SET_TIMEOUT);
if (unlikely(ret < 0))
netdev_warn(dev->net,
"Failed to write register index 0x%08x", index);
kfree(buf);
return ret;
}
static int smsc75xx_phy_wait_not_busy(struct usbnet *dev)
{
unsigned long start_time = jiffies;
u32 val;
int ret;
do {
ret = smsc75xx_read_reg(dev, MII_ACCESS, &val);
check_warn_return(ret, "Error reading MII_ACCESS");
if (!(val & MII_ACCESS_BUSY))
return 0;
} while (!time_after(jiffies, start_time + HZ));
return -EIO;
}
static int smsc75xx_mdio_read(struct net_device *netdev, int phy_id, int idx)
{
struct usbnet *dev = netdev_priv(netdev);
u32 val, addr;
int ret;
mutex_lock(&dev->phy_mutex);
ret = smsc75xx_phy_wait_not_busy(dev);
check_warn_goto_done(ret, "MII is busy in smsc75xx_mdio_read");
phy_id &= dev->mii.phy_id_mask;
idx &= dev->mii.reg_num_mask;
addr = ((phy_id << MII_ACCESS_PHY_ADDR_SHIFT) & MII_ACCESS_PHY_ADDR)
| ((idx << MII_ACCESS_REG_ADDR_SHIFT) & MII_ACCESS_REG_ADDR)
| MII_ACCESS_READ;
ret = smsc75xx_write_reg(dev, MII_ACCESS, addr);
check_warn_goto_done(ret, "Error writing MII_ACCESS");
ret = smsc75xx_phy_wait_not_busy(dev);
check_warn_goto_done(ret, "Timed out reading MII reg %02X", idx);
ret = smsc75xx_read_reg(dev, MII_DATA, &val);
check_warn_goto_done(ret, "Error reading MII_DATA");
ret = (u16)(val & 0xFFFF);
done:
mutex_unlock(&dev->phy_mutex);
return ret;
}
static void smsc75xx_mdio_write(struct net_device *netdev, int phy_id, int idx,
int regval)
{
struct usbnet *dev = netdev_priv(netdev);
u32 val, addr;
int ret;
mutex_lock(&dev->phy_mutex);
ret = smsc75xx_phy_wait_not_busy(dev);
check_warn_goto_done(ret, "MII is busy in smsc75xx_mdio_write");
val = regval;
ret = smsc75xx_write_reg(dev, MII_DATA, val);
check_warn_goto_done(ret, "Error writing MII_DATA");
phy_id &= dev->mii.phy_id_mask;
idx &= dev->mii.reg_num_mask;
addr = ((phy_id << MII_ACCESS_PHY_ADDR_SHIFT) & MII_ACCESS_PHY_ADDR)
| ((idx << MII_ACCESS_REG_ADDR_SHIFT) & MII_ACCESS_REG_ADDR)
| MII_ACCESS_WRITE;
ret = smsc75xx_write_reg(dev, MII_ACCESS, addr);
check_warn_goto_done(ret, "Error writing MII_ACCESS");
ret = smsc75xx_phy_wait_not_busy(dev);
check_warn_goto_done(ret, "Timed out writing MII reg %02X", idx);
done:
mutex_unlock(&dev->phy_mutex);
}
static int smsc75xx_wait_eeprom(struct usbnet *dev)
{
unsigned long start_time = jiffies;
u32 val;
int ret;
do {
ret = smsc75xx_read_reg(dev, E2P_CMD, &val);
check_warn_return(ret, "Error reading E2P_CMD");
if (!(val & E2P_CMD_BUSY) || (val & E2P_CMD_TIMEOUT))
break;
udelay(40);
} while (!time_after(jiffies, start_time + HZ));
if (val & (E2P_CMD_TIMEOUT | E2P_CMD_BUSY)) {
netdev_warn(dev->net, "EEPROM read operation timeout");
return -EIO;
}
return 0;
}
static int smsc75xx_eeprom_confirm_not_busy(struct usbnet *dev)
{
unsigned long start_time = jiffies;
u32 val;
int ret;
do {
ret = smsc75xx_read_reg(dev, E2P_CMD, &val);
check_warn_return(ret, "Error reading E2P_CMD");
if (!(val & E2P_CMD_BUSY))
return 0;
udelay(40);
} while (!time_after(jiffies, start_time + HZ));
netdev_warn(dev->net, "EEPROM is busy");
return -EIO;
}
static int smsc75xx_read_eeprom(struct usbnet *dev, u32 offset, u32 length,
u8 *data)
{
u32 val;
int i, ret;
BUG_ON(!dev);
BUG_ON(!data);
ret = smsc75xx_eeprom_confirm_not_busy(dev);
if (ret)
return ret;
for (i = 0; i < length; i++) {
val = E2P_CMD_BUSY | E2P_CMD_READ | (offset & E2P_CMD_ADDR);
ret = smsc75xx_write_reg(dev, E2P_CMD, val);
check_warn_return(ret, "Error writing E2P_CMD");
ret = smsc75xx_wait_eeprom(dev);
if (ret < 0)
return ret;
ret = smsc75xx_read_reg(dev, E2P_DATA, &val);
check_warn_return(ret, "Error reading E2P_DATA");
data[i] = val & 0xFF;
offset++;
}
return 0;
}
static int smsc75xx_write_eeprom(struct usbnet *dev, u32 offset, u32 length,
u8 *data)
{
u32 val;
int i, ret;
BUG_ON(!dev);
BUG_ON(!data);
ret = smsc75xx_eeprom_confirm_not_busy(dev);
if (ret)
return ret;
val = E2P_CMD_BUSY | E2P_CMD_EWEN;
ret = smsc75xx_write_reg(dev, E2P_CMD, val);
check_warn_return(ret, "Error writing E2P_CMD");
ret = smsc75xx_wait_eeprom(dev);
if (ret < 0)
return ret;
for (i = 0; i < length; i++) {
val = data[i];
ret = smsc75xx_write_reg(dev, E2P_DATA, val);
check_warn_return(ret, "Error writing E2P_DATA");
val = E2P_CMD_BUSY | E2P_CMD_WRITE | (offset & E2P_CMD_ADDR);
ret = smsc75xx_write_reg(dev, E2P_CMD, val);
check_warn_return(ret, "Error writing E2P_CMD");
ret = smsc75xx_wait_eeprom(dev);
if (ret < 0)
return ret;
offset++;
}
return 0;
}
static int smsc75xx_dataport_wait_not_busy(struct usbnet *dev)
{
int i, ret;
for (i = 0; i < 100; i++) {
u32 dp_sel;
ret = smsc75xx_read_reg(dev, DP_SEL, &dp_sel);
check_warn_return(ret, "Error reading DP_SEL");
if (dp_sel & DP_SEL_DPRDY)
return 0;
udelay(40);
}
netdev_warn(dev->net, "smsc75xx_dataport_wait_not_busy timed out");
return -EIO;
}
static int smsc75xx_dataport_write(struct usbnet *dev, u32 ram_select, u32 addr,
u32 length, u32 *buf)
{
struct smsc75xx_priv *pdata = (struct smsc75xx_priv *)(dev->data[0]);
u32 dp_sel;
int i, ret;
mutex_lock(&pdata->dataport_mutex);
ret = smsc75xx_dataport_wait_not_busy(dev);
check_warn_goto_done(ret, "smsc75xx_dataport_write busy on entry");
ret = smsc75xx_read_reg(dev, DP_SEL, &dp_sel);
check_warn_goto_done(ret, "Error reading DP_SEL");
dp_sel &= ~DP_SEL_RSEL;
dp_sel |= ram_select;
ret = smsc75xx_write_reg(dev, DP_SEL, dp_sel);
check_warn_goto_done(ret, "Error writing DP_SEL");
for (i = 0; i < length; i++) {
ret = smsc75xx_write_reg(dev, DP_ADDR, addr + i);
check_warn_goto_done(ret, "Error writing DP_ADDR");
ret = smsc75xx_write_reg(dev, DP_DATA, buf[i]);
check_warn_goto_done(ret, "Error writing DP_DATA");
ret = smsc75xx_write_reg(dev, DP_CMD, DP_CMD_WRITE);
check_warn_goto_done(ret, "Error writing DP_CMD");
ret = smsc75xx_dataport_wait_not_busy(dev);
check_warn_goto_done(ret, "smsc75xx_dataport_write timeout");
}
done:
mutex_unlock(&pdata->dataport_mutex);
return ret;
}
static u32 smsc75xx_hash(char addr[ETH_ALEN])
{
return (ether_crc(ETH_ALEN, addr) >> 23) & 0x1ff;
}
static void smsc75xx_deferred_multicast_write(struct work_struct *param)
{
struct smsc75xx_priv *pdata =
container_of(param, struct smsc75xx_priv, set_multicast);
struct usbnet *dev = pdata->dev;
int ret;
netif_dbg(dev, drv, dev->net, "deferred multicast write 0x%08x",
pdata->rfe_ctl);
smsc75xx_dataport_write(dev, DP_SEL_VHF, DP_SEL_VHF_VLAN_LEN,
DP_SEL_VHF_HASH_LEN, pdata->multicast_hash_table);
ret = smsc75xx_write_reg(dev, RFE_CTL, pdata->rfe_ctl);
check_warn(ret, "Error writing RFE_CRL");
}
static void smsc75xx_set_multicast(struct net_device *netdev)
{
struct usbnet *dev = netdev_priv(netdev);
struct smsc75xx_priv *pdata = (struct smsc75xx_priv *)(dev->data[0]);
unsigned long flags;
int i;
spin_lock_irqsave(&pdata->rfe_ctl_lock, flags);
pdata->rfe_ctl &=
~(RFE_CTL_AU | RFE_CTL_AM | RFE_CTL_DPF | RFE_CTL_MHF);
pdata->rfe_ctl |= RFE_CTL_AB;
for (i = 0; i < DP_SEL_VHF_HASH_LEN; i++)
pdata->multicast_hash_table[i] = 0;
if (dev->net->flags & IFF_PROMISC) {
netif_dbg(dev, drv, dev->net, "promiscuous mode enabled");
pdata->rfe_ctl |= RFE_CTL_AM | RFE_CTL_AU;
} else if (dev->net->flags & IFF_ALLMULTI) {
netif_dbg(dev, drv, dev->net, "receive all multicast enabled");
pdata->rfe_ctl |= RFE_CTL_AM | RFE_CTL_DPF;
} else if (!netdev_mc_empty(dev->net)) {
struct netdev_hw_addr *ha;
netif_dbg(dev, drv, dev->net, "receive multicast hash filter");
pdata->rfe_ctl |= RFE_CTL_MHF | RFE_CTL_DPF;
netdev_for_each_mc_addr(ha, netdev) {
u32 bitnum = smsc75xx_hash(ha->addr);
pdata->multicast_hash_table[bitnum / 32] |=
(1 << (bitnum % 32));
}
} else {
netif_dbg(dev, drv, dev->net, "receive own packets only");
pdata->rfe_ctl |= RFE_CTL_DPF;
}
spin_unlock_irqrestore(&pdata->rfe_ctl_lock, flags);
schedule_work(&pdata->set_multicast);
}
static int smsc75xx_update_flowcontrol(struct usbnet *dev, u8 duplex,
u16 lcladv, u16 rmtadv)
{
u32 flow = 0, fct_flow = 0;
int ret;
if (duplex == DUPLEX_FULL) {
u8 cap = mii_resolve_flowctrl_fdx(lcladv, rmtadv);
if (cap & FLOW_CTRL_TX) {
flow = (FLOW_TX_FCEN | 0xFFFF);
fct_flow = (8 << 8) | 32;
}
if (cap & FLOW_CTRL_RX)
flow |= FLOW_RX_FCEN;
netif_dbg(dev, link, dev->net, "rx pause %s, tx pause %s",
(cap & FLOW_CTRL_RX ? "enabled" : "disabled"),
(cap & FLOW_CTRL_TX ? "enabled" : "disabled"));
} else {
netif_dbg(dev, link, dev->net, "half duplex");
}
ret = smsc75xx_write_reg(dev, FLOW, flow);
check_warn_return(ret, "Error writing FLOW");
ret = smsc75xx_write_reg(dev, FCT_FLOW, fct_flow);
check_warn_return(ret, "Error writing FCT_FLOW");
return 0;
}
static int smsc75xx_link_reset(struct usbnet *dev)
{
struct mii_if_info *mii = &dev->mii;
struct ethtool_cmd ecmd = { .cmd = ETHTOOL_GSET };
u16 lcladv, rmtadv;
int ret;
ret = smsc75xx_mdio_read(dev->net, mii->phy_id, PHY_INT_SRC);
check_warn_return(ret, "Error reading PHY_INT_SRC");
ret = smsc75xx_write_reg(dev, INT_STS, INT_STS_CLEAR_ALL);
check_warn_return(ret, "Error writing INT_STS");
mii_check_media(mii, 1, 1);
mii_ethtool_gset(&dev->mii, &ecmd);
lcladv = smsc75xx_mdio_read(dev->net, mii->phy_id, MII_ADVERTISE);
rmtadv = smsc75xx_mdio_read(dev->net, mii->phy_id, MII_LPA);
netif_dbg(dev, link, dev->net, "speed: %u duplex: %d lcladv: %04x"
" rmtadv: %04x", ethtool_cmd_speed(&ecmd),
ecmd.duplex, lcladv, rmtadv);
return smsc75xx_update_flowcontrol(dev, ecmd.duplex, lcladv, rmtadv);
}
static void smsc75xx_status(struct usbnet *dev, struct urb *urb)
{
u32 intdata;
if (urb->actual_length != 4) {
netdev_warn(dev->net,
"unexpected urb length %d", urb->actual_length);
return;
}
memcpy(&intdata, urb->transfer_buffer, 4);
le32_to_cpus(&intdata);
netif_dbg(dev, link, dev->net, "intdata: 0x%08X", intdata);
if (intdata & INT_ENP_PHY_INT)
usbnet_defer_kevent(dev, EVENT_LINK_RESET);
else
netdev_warn(dev->net,
"unexpected interrupt, intdata=0x%08X", intdata);
}
static int smsc75xx_ethtool_get_eeprom_len(struct net_device *net)
{
return MAX_EEPROM_SIZE;
}
static int smsc75xx_ethtool_get_eeprom(struct net_device *netdev,
struct ethtool_eeprom *ee, u8 *data)
{
struct usbnet *dev = netdev_priv(netdev);
ee->magic = LAN75XX_EEPROM_MAGIC;
return smsc75xx_read_eeprom(dev, ee->offset, ee->len, data);
}
static int smsc75xx_ethtool_set_eeprom(struct net_device *netdev,
struct ethtool_eeprom *ee, u8 *data)
{
struct usbnet *dev = netdev_priv(netdev);
if (ee->magic != LAN75XX_EEPROM_MAGIC) {
netdev_warn(dev->net,
"EEPROM: magic value mismatch: 0x%x", ee->magic);
return -EINVAL;
}
return smsc75xx_write_eeprom(dev, ee->offset, ee->len, data);
}
static int smsc75xx_ioctl(struct net_device *netdev, struct ifreq *rq, int cmd)
{
struct usbnet *dev = netdev_priv(netdev);
if (!netif_running(netdev))
return -EINVAL;
return generic_mii_ioctl(&dev->mii, if_mii(rq), cmd, NULL);
}
static void smsc75xx_init_mac_address(struct usbnet *dev)
{
if (smsc75xx_read_eeprom(dev, EEPROM_MAC_OFFSET, ETH_ALEN,
dev->net->dev_addr) == 0) {
if (is_valid_ether_addr(dev->net->dev_addr)) {
netif_dbg(dev, ifup, dev->net,
"MAC address read from EEPROM");
return;
}
}
random_ether_addr(dev->net->dev_addr);
netif_dbg(dev, ifup, dev->net, "MAC address set to random_ether_addr");
}
static int smsc75xx_set_mac_address(struct usbnet *dev)
{
u32 addr_lo = dev->net->dev_addr[0] | dev->net->dev_addr[1] << 8 |
dev->net->dev_addr[2] << 16 | dev->net->dev_addr[3] << 24;
u32 addr_hi = dev->net->dev_addr[4] | dev->net->dev_addr[5] << 8;
int ret = smsc75xx_write_reg(dev, RX_ADDRH, addr_hi);
check_warn_return(ret, "Failed to write RX_ADDRH: %d", ret);
ret = smsc75xx_write_reg(dev, RX_ADDRL, addr_lo);
check_warn_return(ret, "Failed to write RX_ADDRL: %d", ret);
addr_hi |= ADDR_FILTX_FB_VALID;
ret = smsc75xx_write_reg(dev, ADDR_FILTX, addr_hi);
check_warn_return(ret, "Failed to write ADDR_FILTX: %d", ret);
ret = smsc75xx_write_reg(dev, ADDR_FILTX + 4, addr_lo);
check_warn_return(ret, "Failed to write ADDR_FILTX+4: %d", ret);
return 0;
}
static int smsc75xx_phy_initialize(struct usbnet *dev)
{
int bmcr, timeout = 0;
dev->mii.dev = dev->net;
dev->mii.mdio_read = smsc75xx_mdio_read;
dev->mii.mdio_write = smsc75xx_mdio_write;
dev->mii.phy_id_mask = 0x1f;
dev->mii.reg_num_mask = 0x1f;
dev->mii.phy_id = SMSC75XX_INTERNAL_PHY_ID;
smsc75xx_mdio_write(dev->net, dev->mii.phy_id, MII_BMCR, BMCR_RESET);
do {
msleep(10);
bmcr = smsc75xx_mdio_read(dev->net, dev->mii.phy_id, MII_BMCR);
check_warn_return(bmcr, "Error reading MII_BMCR");
timeout++;
} while ((bmcr & MII_BMCR) && (timeout < 100));
if (timeout >= 100) {
netdev_warn(dev->net, "timeout on PHY Reset");
return -EIO;
}
smsc75xx_mdio_write(dev->net, dev->mii.phy_id, MII_ADVERTISE,
ADVERTISE_ALL | ADVERTISE_CSMA | ADVERTISE_PAUSE_CAP |
ADVERTISE_PAUSE_ASYM);
smsc75xx_mdio_read(dev->net, dev->mii.phy_id, PHY_INT_SRC);
check_warn_return(bmcr, "Error reading PHY_INT_SRC");
smsc75xx_mdio_write(dev->net, dev->mii.phy_id, PHY_INT_MASK,
PHY_INT_MASK_DEFAULT);
mii_nway_restart(&dev->mii);
netif_dbg(dev, ifup, dev->net, "phy initialised successfully");
return 0;
}
static int smsc75xx_set_rx_max_frame_length(struct usbnet *dev, int size)
{
int ret = 0;
u32 buf;
bool rxenabled;
ret = smsc75xx_read_reg(dev, MAC_RX, &buf);
check_warn_return(ret, "Failed to read MAC_RX: %d", ret);
rxenabled = ((buf & MAC_RX_RXEN) != 0);
if (rxenabled) {
buf &= ~MAC_RX_RXEN;
ret = smsc75xx_write_reg(dev, MAC_RX, buf);
check_warn_return(ret, "Failed to write MAC_RX: %d", ret);
}
buf &= ~MAC_RX_MAX_SIZE;
buf |= (((size + 4) << MAC_RX_MAX_SIZE_SHIFT) & MAC_RX_MAX_SIZE);
ret = smsc75xx_write_reg(dev, MAC_RX, buf);
check_warn_return(ret, "Failed to write MAC_RX: %d", ret);
if (rxenabled) {
buf |= MAC_RX_RXEN;
ret = smsc75xx_write_reg(dev, MAC_RX, buf);
check_warn_return(ret, "Failed to write MAC_RX: %d", ret);
}
return 0;
}
static int smsc75xx_change_mtu(struct net_device *netdev, int new_mtu)
{
struct usbnet *dev = netdev_priv(netdev);
int ret = smsc75xx_set_rx_max_frame_length(dev, new_mtu);
check_warn_return(ret, "Failed to set mac rx frame length");
return usbnet_change_mtu(netdev, new_mtu);
}
static int smsc75xx_set_features(struct net_device *netdev, u32 features)
{
struct usbnet *dev = netdev_priv(netdev);
struct smsc75xx_priv *pdata = (struct smsc75xx_priv *)(dev->data[0]);
unsigned long flags;
int ret;
spin_lock_irqsave(&pdata->rfe_ctl_lock, flags);
if (features & NETIF_F_RXCSUM)
pdata->rfe_ctl |= RFE_CTL_TCPUDP_CKM | RFE_CTL_IP_CKM;
else
pdata->rfe_ctl &= ~(RFE_CTL_TCPUDP_CKM | RFE_CTL_IP_CKM);
spin_unlock_irqrestore(&pdata->rfe_ctl_lock, flags);
ret = smsc75xx_write_reg(dev, RFE_CTL, pdata->rfe_ctl);
check_warn_return(ret, "Error writing RFE_CTL");
return 0;
}
static int smsc75xx_reset(struct usbnet *dev)
{
struct smsc75xx_priv *pdata = (struct smsc75xx_priv *)(dev->data[0]);
u32 buf;
int ret = 0, timeout;
netif_dbg(dev, ifup, dev->net, "entering smsc75xx_reset");
ret = smsc75xx_read_reg(dev, HW_CFG, &buf);
check_warn_return(ret, "Failed to read HW_CFG: %d", ret);
buf |= HW_CFG_LRST;
ret = smsc75xx_write_reg(dev, HW_CFG, buf);
check_warn_return(ret, "Failed to write HW_CFG: %d", ret);
timeout = 0;
do {
msleep(10);
ret = smsc75xx_read_reg(dev, HW_CFG, &buf);
check_warn_return(ret, "Failed to read HW_CFG: %d", ret);
timeout++;
} while ((buf & HW_CFG_LRST) && (timeout < 100));
if (timeout >= 100) {
netdev_warn(dev->net, "timeout on completion of Lite Reset");
return -EIO;
}
netif_dbg(dev, ifup, dev->net, "Lite reset complete, resetting PHY");
ret = smsc75xx_read_reg(dev, PMT_CTL, &buf);
check_warn_return(ret, "Failed to read PMT_CTL: %d", ret);
buf |= PMT_CTL_PHY_RST;
ret = smsc75xx_write_reg(dev, PMT_CTL, buf);
check_warn_return(ret, "Failed to write PMT_CTL: %d", ret);
timeout = 0;
do {
msleep(10);
ret = smsc75xx_read_reg(dev, PMT_CTL, &buf);
check_warn_return(ret, "Failed to read PMT_CTL: %d", ret);
timeout++;
} while ((buf & PMT_CTL_PHY_RST) && (timeout < 100));
if (timeout >= 100) {
netdev_warn(dev->net, "timeout waiting for PHY Reset");
return -EIO;
}
netif_dbg(dev, ifup, dev->net, "PHY reset complete");
smsc75xx_init_mac_address(dev);
ret = smsc75xx_set_mac_address(dev);
check_warn_return(ret, "Failed to set mac address");
netif_dbg(dev, ifup, dev->net, "MAC Address: %pM", dev->net->dev_addr);
ret = smsc75xx_read_reg(dev, HW_CFG, &buf);
check_warn_return(ret, "Failed to read HW_CFG: %d", ret);
netif_dbg(dev, ifup, dev->net, "Read Value from HW_CFG : 0x%08x", buf);
buf |= HW_CFG_BIR;
ret = smsc75xx_write_reg(dev, HW_CFG, buf);
check_warn_return(ret, "Failed to write HW_CFG: %d", ret);
ret = smsc75xx_read_reg(dev, HW_CFG, &buf);
check_warn_return(ret, "Failed to read HW_CFG: %d", ret);
netif_dbg(dev, ifup, dev->net, "Read Value from HW_CFG after "
"writing HW_CFG_BIR: 0x%08x", buf);
if (!turbo_mode) {
buf = 0;
dev->rx_urb_size = MAX_SINGLE_PACKET_SIZE;
} else if (dev->udev->speed == USB_SPEED_HIGH) {
buf = DEFAULT_HS_BURST_CAP_SIZE / HS_USB_PKT_SIZE;
dev->rx_urb_size = DEFAULT_HS_BURST_CAP_SIZE;
} else {
buf = DEFAULT_FS_BURST_CAP_SIZE / FS_USB_PKT_SIZE;
dev->rx_urb_size = DEFAULT_FS_BURST_CAP_SIZE;
}
netif_dbg(dev, ifup, dev->net, "rx_urb_size=%ld",
(ulong)dev->rx_urb_size);
ret = smsc75xx_write_reg(dev, BURST_CAP, buf);
check_warn_return(ret, "Failed to write BURST_CAP: %d", ret);
ret = smsc75xx_read_reg(dev, BURST_CAP, &buf);
check_warn_return(ret, "Failed to read BURST_CAP: %d", ret);
netif_dbg(dev, ifup, dev->net,
"Read Value from BURST_CAP after writing: 0x%08x", buf);
ret = smsc75xx_write_reg(dev, BULK_IN_DLY, DEFAULT_BULK_IN_DELAY);
check_warn_return(ret, "Failed to write BULK_IN_DLY: %d", ret);
ret = smsc75xx_read_reg(dev, BULK_IN_DLY, &buf);
check_warn_return(ret, "Failed to read BULK_IN_DLY: %d", ret);
netif_dbg(dev, ifup, dev->net,
"Read Value from BULK_IN_DLY after writing: 0x%08x", buf);
if (turbo_mode) {
ret = smsc75xx_read_reg(dev, HW_CFG, &buf);
check_warn_return(ret, "Failed to read HW_CFG: %d", ret);
netif_dbg(dev, ifup, dev->net, "HW_CFG: 0x%08x", buf);
buf |= (HW_CFG_MEF | HW_CFG_BCE);
ret = smsc75xx_write_reg(dev, HW_CFG, buf);
check_warn_return(ret, "Failed to write HW_CFG: %d", ret);
ret = smsc75xx_read_reg(dev, HW_CFG, &buf);
check_warn_return(ret, "Failed to read HW_CFG: %d", ret);
netif_dbg(dev, ifup, dev->net, "HW_CFG: 0x%08x", buf);
}
buf = (MAX_RX_FIFO_SIZE - 512) / 512;
ret = smsc75xx_write_reg(dev, FCT_RX_FIFO_END, buf);
check_warn_return(ret, "Failed to write FCT_RX_FIFO_END: %d", ret);
netif_dbg(dev, ifup, dev->net, "FCT_RX_FIFO_END set to 0x%08x", buf);
buf = (MAX_TX_FIFO_SIZE - 512) / 512;
ret = smsc75xx_write_reg(dev, FCT_TX_FIFO_END, buf);
check_warn_return(ret, "Failed to write FCT_TX_FIFO_END: %d", ret);
netif_dbg(dev, ifup, dev->net, "FCT_TX_FIFO_END set to 0x%08x", buf);
ret = smsc75xx_write_reg(dev, INT_STS, INT_STS_CLEAR_ALL);
check_warn_return(ret, "Failed to write INT_STS: %d", ret);
ret = smsc75xx_read_reg(dev, ID_REV, &buf);
check_warn_return(ret, "Failed to read ID_REV: %d", ret);
netif_dbg(dev, ifup, dev->net, "ID_REV = 0x%08x", buf);
ret = smsc75xx_read_reg(dev, LED_GPIO_CFG, &buf);
check_warn_return(ret, "Failed to read LED_GPIO_CFG: %d", ret);
buf &= ~(LED_GPIO_CFG_LED2_FUN_SEL | LED_GPIO_CFG_LED10_FUN_SEL);
buf |= LED_GPIO_CFG_LEDGPIO_EN | LED_GPIO_CFG_LED2_FUN_SEL;
ret = smsc75xx_write_reg(dev, LED_GPIO_CFG, buf);
check_warn_return(ret, "Failed to write LED_GPIO_CFG: %d", ret);
ret = smsc75xx_write_reg(dev, FLOW, 0);
check_warn_return(ret, "Failed to write FLOW: %d", ret);
ret = smsc75xx_write_reg(dev, FCT_FLOW, 0);
check_warn_return(ret, "Failed to write FCT_FLOW: %d", ret);
ret = smsc75xx_read_reg(dev, RFE_CTL, &pdata->rfe_ctl);
check_warn_return(ret, "Failed to read RFE_CTL: %d", ret);
pdata->rfe_ctl |= RFE_CTL_AB | RFE_CTL_DPF;
ret = smsc75xx_write_reg(dev, RFE_CTL, pdata->rfe_ctl);
check_warn_return(ret, "Failed to write RFE_CTL: %d", ret);
ret = smsc75xx_read_reg(dev, RFE_CTL, &pdata->rfe_ctl);
check_warn_return(ret, "Failed to read RFE_CTL: %d", ret);
netif_dbg(dev, ifup, dev->net, "RFE_CTL set to 0x%08x", pdata->rfe_ctl);
smsc75xx_set_features(dev->net, dev->net->features);
smsc75xx_set_multicast(dev->net);
ret = smsc75xx_phy_initialize(dev);
check_warn_return(ret, "Failed to initialize PHY: %d", ret);
ret = smsc75xx_read_reg(dev, INT_EP_CTL, &buf);
check_warn_return(ret, "Failed to read INT_EP_CTL: %d", ret);
buf |= INT_ENP_PHY_INT;
ret = smsc75xx_write_reg(dev, INT_EP_CTL, buf);
check_warn_return(ret, "Failed to write INT_EP_CTL: %d", ret);
ret = smsc75xx_read_reg(dev, MAC_TX, &buf);
check_warn_return(ret, "Failed to read MAC_TX: %d", ret);
buf |= MAC_TX_TXEN;
ret = smsc75xx_write_reg(dev, MAC_TX, buf);
check_warn_return(ret, "Failed to write MAC_TX: %d", ret);
netif_dbg(dev, ifup, dev->net, "MAC_TX set to 0x%08x", buf);
ret = smsc75xx_read_reg(dev, FCT_TX_CTL, &buf);
check_warn_return(ret, "Failed to read FCT_TX_CTL: %d", ret);
buf |= FCT_TX_CTL_EN;
ret = smsc75xx_write_reg(dev, FCT_TX_CTL, buf);
check_warn_return(ret, "Failed to write FCT_TX_CTL: %d", ret);
netif_dbg(dev, ifup, dev->net, "FCT_TX_CTL set to 0x%08x", buf);
ret = smsc75xx_set_rx_max_frame_length(dev, 1514);
check_warn_return(ret, "Failed to set max rx frame length");
ret = smsc75xx_read_reg(dev, MAC_RX, &buf);
check_warn_return(ret, "Failed to read MAC_RX: %d", ret);
buf |= MAC_RX_RXEN;
ret = smsc75xx_write_reg(dev, MAC_RX, buf);
check_warn_return(ret, "Failed to write MAC_RX: %d", ret);
netif_dbg(dev, ifup, dev->net, "MAC_RX set to 0x%08x", buf);
ret = smsc75xx_read_reg(dev, FCT_RX_CTL, &buf);
check_warn_return(ret, "Failed to read FCT_RX_CTL: %d", ret);
buf |= FCT_RX_CTL_EN;
ret = smsc75xx_write_reg(dev, FCT_RX_CTL, buf);
check_warn_return(ret, "Failed to write FCT_RX_CTL: %d", ret);
netif_dbg(dev, ifup, dev->net, "FCT_RX_CTL set to 0x%08x", buf);
netif_dbg(dev, ifup, dev->net, "smsc75xx_reset, return 0");
return 0;
}
static int smsc75xx_bind(struct usbnet *dev, struct usb_interface *intf)
{
struct smsc75xx_priv *pdata = NULL;
int ret;
printk(KERN_INFO SMSC_CHIPNAME " v" SMSC_DRIVER_VERSION "\n");
ret = usbnet_get_endpoints(dev, intf);
check_warn_return(ret, "usbnet_get_endpoints failed: %d", ret);
dev->data[0] = (unsigned long)kzalloc(sizeof(struct smsc75xx_priv),
GFP_KERNEL);
pdata = (struct smsc75xx_priv *)(dev->data[0]);
if (!pdata) {
netdev_warn(dev->net, "Unable to allocate smsc75xx_priv");
return -ENOMEM;
}
pdata->dev = dev;
spin_lock_init(&pdata->rfe_ctl_lock);
mutex_init(&pdata->dataport_mutex);
INIT_WORK(&pdata->set_multicast, smsc75xx_deferred_multicast_write);
if (DEFAULT_TX_CSUM_ENABLE) {
dev->net->features |= NETIF_F_IP_CSUM | NETIF_F_IPV6_CSUM;
if (DEFAULT_TSO_ENABLE)
dev->net->features |= NETIF_F_SG |
NETIF_F_TSO | NETIF_F_TSO6;
}
if (DEFAULT_RX_CSUM_ENABLE)
dev->net->features |= NETIF_F_RXCSUM;
dev->net->hw_features = NETIF_F_IP_CSUM | NETIF_F_IPV6_CSUM |
NETIF_F_SG | NETIF_F_TSO | NETIF_F_TSO6 | NETIF_F_RXCSUM;
ret = smsc75xx_reset(dev);
dev->net->netdev_ops = &smsc75xx_netdev_ops;
dev->net->ethtool_ops = &smsc75xx_ethtool_ops;
dev->net->flags |= IFF_MULTICAST;
dev->net->hard_header_len += SMSC75XX_TX_OVERHEAD;
return 0;
}
static void smsc75xx_unbind(struct usbnet *dev, struct usb_interface *intf)
{
struct smsc75xx_priv *pdata = (struct smsc75xx_priv *)(dev->data[0]);
if (pdata) {
netif_dbg(dev, ifdown, dev->net, "free pdata");
kfree(pdata);
pdata = NULL;
dev->data[0] = 0;
}
}
static void smsc75xx_rx_csum_offload(struct usbnet *dev, struct sk_buff *skb,
u32 rx_cmd_a, u32 rx_cmd_b)
{
if (!(dev->net->features & NETIF_F_RXCSUM) ||
unlikely(rx_cmd_a & RX_CMD_A_LCSM)) {
skb->ip_summed = CHECKSUM_NONE;
} else {
skb->csum = ntohs((u16)(rx_cmd_b >> RX_CMD_B_CSUM_SHIFT));
skb->ip_summed = CHECKSUM_COMPLETE;
}
}
static int smsc75xx_rx_fixup(struct usbnet *dev, struct sk_buff *skb)
{
while (skb->len > 0) {
u32 rx_cmd_a, rx_cmd_b, align_count, size;
struct sk_buff *ax_skb;
unsigned char *packet;
memcpy(&rx_cmd_a, skb->data, sizeof(rx_cmd_a));
le32_to_cpus(&rx_cmd_a);
skb_pull(skb, 4);
memcpy(&rx_cmd_b, skb->data, sizeof(rx_cmd_b));
le32_to_cpus(&rx_cmd_b);
skb_pull(skb, 4 + RXW_PADDING);
packet = skb->data;
size = (rx_cmd_a & RX_CMD_A_LEN) - RXW_PADDING;
align_count = (4 - ((size + RXW_PADDING) % 4)) % 4;
if (unlikely(rx_cmd_a & RX_CMD_A_RED)) {
netif_dbg(dev, rx_err, dev->net,
"Error rx_cmd_a=0x%08x", rx_cmd_a);
dev->net->stats.rx_errors++;
dev->net->stats.rx_dropped++;
if (rx_cmd_a & RX_CMD_A_FCS)
dev->net->stats.rx_crc_errors++;
else if (rx_cmd_a & (RX_CMD_A_LONG | RX_CMD_A_RUNT))
dev->net->stats.rx_frame_errors++;
} else {
if (unlikely(size > (ETH_FRAME_LEN + 12))) {
netif_dbg(dev, rx_err, dev->net,
"size err rx_cmd_a=0x%08x", rx_cmd_a);
return 0;
}
if (skb->len == size) {
smsc75xx_rx_csum_offload(dev, skb, rx_cmd_a,
rx_cmd_b);
skb_trim(skb, skb->len - 4);
skb->truesize = size + sizeof(struct sk_buff);
return 1;
}
ax_skb = skb_clone(skb, GFP_ATOMIC);
if (unlikely(!ax_skb)) {
netdev_warn(dev->net, "Error allocating skb");
return 0;
}
ax_skb->len = size;
ax_skb->data = packet;
skb_set_tail_pointer(ax_skb, size);
smsc75xx_rx_csum_offload(dev, ax_skb, rx_cmd_a,
rx_cmd_b);
skb_trim(ax_skb, ax_skb->len - 4);
ax_skb->truesize = size + sizeof(struct sk_buff);
usbnet_skb_return(dev, ax_skb);
}
skb_pull(skb, size);
if (skb->len)
skb_pull(skb, align_count);
}
if (unlikely(skb->len < 0)) {
netdev_warn(dev->net, "invalid rx length<0 %d", skb->len);
return 0;
}
return 1;
}
static struct sk_buff *smsc75xx_tx_fixup(struct usbnet *dev,
struct sk_buff *skb, gfp_t flags)
{
u32 tx_cmd_a, tx_cmd_b;
skb_linearize(skb);
if (skb_headroom(skb) < SMSC75XX_TX_OVERHEAD) {
struct sk_buff *skb2 =
skb_copy_expand(skb, SMSC75XX_TX_OVERHEAD, 0, flags);
dev_kfree_skb_any(skb);
skb = skb2;
if (!skb)
return NULL;
}
tx_cmd_a = (u32)(skb->len & TX_CMD_A_LEN) | TX_CMD_A_FCS;
if (skb->ip_summed == CHECKSUM_PARTIAL)
tx_cmd_a |= TX_CMD_A_IPE | TX_CMD_A_TPE;
if (skb_is_gso(skb)) {
u16 mss = max(skb_shinfo(skb)->gso_size, TX_MSS_MIN);
tx_cmd_b = (mss << TX_CMD_B_MSS_SHIFT) & TX_CMD_B_MSS;
tx_cmd_a |= TX_CMD_A_LSO;
} else {
tx_cmd_b = 0;
}
skb_push(skb, 4);
cpu_to_le32s(&tx_cmd_b);
memcpy(skb->data, &tx_cmd_b, 4);
skb_push(skb, 4);
cpu_to_le32s(&tx_cmd_a);
memcpy(skb->data, &tx_cmd_a, 4);
return skb;
}
static int __init smsc75xx_init(void)
{
return usb_register(&smsc75xx_driver);
}
static void __exit smsc75xx_exit(void)
{
usb_deregister(&smsc75xx_driver);
}
