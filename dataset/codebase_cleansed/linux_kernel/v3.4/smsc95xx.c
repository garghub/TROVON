static int smsc95xx_read_reg(struct usbnet *dev, u32 index, u32 *data)
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
netdev_warn(dev->net, "Failed to read register index 0x%08x\n", index);
le32_to_cpus(buf);
*data = *buf;
kfree(buf);
return ret;
}
static int smsc95xx_write_reg(struct usbnet *dev, u32 index, u32 data)
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
netdev_warn(dev->net, "Failed to write register index 0x%08x\n", index);
kfree(buf);
return ret;
}
static int smsc95xx_phy_wait_not_busy(struct usbnet *dev)
{
unsigned long start_time = jiffies;
u32 val;
do {
smsc95xx_read_reg(dev, MII_ADDR, &val);
if (!(val & MII_BUSY_))
return 0;
} while (!time_after(jiffies, start_time + HZ));
return -EIO;
}
static int smsc95xx_mdio_read(struct net_device *netdev, int phy_id, int idx)
{
struct usbnet *dev = netdev_priv(netdev);
u32 val, addr;
mutex_lock(&dev->phy_mutex);
if (smsc95xx_phy_wait_not_busy(dev)) {
netdev_warn(dev->net, "MII is busy in smsc95xx_mdio_read\n");
mutex_unlock(&dev->phy_mutex);
return -EIO;
}
phy_id &= dev->mii.phy_id_mask;
idx &= dev->mii.reg_num_mask;
addr = (phy_id << 11) | (idx << 6) | MII_READ_;
smsc95xx_write_reg(dev, MII_ADDR, addr);
if (smsc95xx_phy_wait_not_busy(dev)) {
netdev_warn(dev->net, "Timed out reading MII reg %02X\n", idx);
mutex_unlock(&dev->phy_mutex);
return -EIO;
}
smsc95xx_read_reg(dev, MII_DATA, &val);
mutex_unlock(&dev->phy_mutex);
return (u16)(val & 0xFFFF);
}
static void smsc95xx_mdio_write(struct net_device *netdev, int phy_id, int idx,
int regval)
{
struct usbnet *dev = netdev_priv(netdev);
u32 val, addr;
mutex_lock(&dev->phy_mutex);
if (smsc95xx_phy_wait_not_busy(dev)) {
netdev_warn(dev->net, "MII is busy in smsc95xx_mdio_write\n");
mutex_unlock(&dev->phy_mutex);
return;
}
val = regval;
smsc95xx_write_reg(dev, MII_DATA, val);
phy_id &= dev->mii.phy_id_mask;
idx &= dev->mii.reg_num_mask;
addr = (phy_id << 11) | (idx << 6) | MII_WRITE_;
smsc95xx_write_reg(dev, MII_ADDR, addr);
if (smsc95xx_phy_wait_not_busy(dev))
netdev_warn(dev->net, "Timed out writing MII reg %02X\n", idx);
mutex_unlock(&dev->phy_mutex);
}
static int smsc95xx_wait_eeprom(struct usbnet *dev)
{
unsigned long start_time = jiffies;
u32 val;
do {
smsc95xx_read_reg(dev, E2P_CMD, &val);
if (!(val & E2P_CMD_BUSY_) || (val & E2P_CMD_TIMEOUT_))
break;
udelay(40);
} while (!time_after(jiffies, start_time + HZ));
if (val & (E2P_CMD_TIMEOUT_ | E2P_CMD_BUSY_)) {
netdev_warn(dev->net, "EEPROM read operation timeout\n");
return -EIO;
}
return 0;
}
static int smsc95xx_eeprom_confirm_not_busy(struct usbnet *dev)
{
unsigned long start_time = jiffies;
u32 val;
do {
smsc95xx_read_reg(dev, E2P_CMD, &val);
if (!(val & E2P_CMD_BUSY_))
return 0;
udelay(40);
} while (!time_after(jiffies, start_time + HZ));
netdev_warn(dev->net, "EEPROM is busy\n");
return -EIO;
}
static int smsc95xx_read_eeprom(struct usbnet *dev, u32 offset, u32 length,
u8 *data)
{
u32 val;
int i, ret;
BUG_ON(!dev);
BUG_ON(!data);
ret = smsc95xx_eeprom_confirm_not_busy(dev);
if (ret)
return ret;
for (i = 0; i < length; i++) {
val = E2P_CMD_BUSY_ | E2P_CMD_READ_ | (offset & E2P_CMD_ADDR_);
smsc95xx_write_reg(dev, E2P_CMD, val);
ret = smsc95xx_wait_eeprom(dev);
if (ret < 0)
return ret;
smsc95xx_read_reg(dev, E2P_DATA, &val);
data[i] = val & 0xFF;
offset++;
}
return 0;
}
static int smsc95xx_write_eeprom(struct usbnet *dev, u32 offset, u32 length,
u8 *data)
{
u32 val;
int i, ret;
BUG_ON(!dev);
BUG_ON(!data);
ret = smsc95xx_eeprom_confirm_not_busy(dev);
if (ret)
return ret;
val = E2P_CMD_BUSY_ | E2P_CMD_EWEN_;
smsc95xx_write_reg(dev, E2P_CMD, val);
ret = smsc95xx_wait_eeprom(dev);
if (ret < 0)
return ret;
for (i = 0; i < length; i++) {
val = data[i];
smsc95xx_write_reg(dev, E2P_DATA, val);
val = E2P_CMD_BUSY_ | E2P_CMD_WRITE_ | (offset & E2P_CMD_ADDR_);
smsc95xx_write_reg(dev, E2P_CMD, val);
ret = smsc95xx_wait_eeprom(dev);
if (ret < 0)
return ret;
offset++;
}
return 0;
}
static void smsc95xx_async_cmd_callback(struct urb *urb)
{
struct usb_context *usb_context = urb->context;
struct usbnet *dev = usb_context->dev;
int status = urb->status;
if (status < 0)
netdev_warn(dev->net, "async callback failed with %d\n", status);
kfree(usb_context);
usb_free_urb(urb);
}
static int smsc95xx_write_reg_async(struct usbnet *dev, u16 index, u32 *data)
{
struct usb_context *usb_context;
int status;
struct urb *urb;
const u16 size = 4;
urb = usb_alloc_urb(0, GFP_ATOMIC);
if (!urb) {
netdev_warn(dev->net, "Error allocating URB\n");
return -ENOMEM;
}
usb_context = kmalloc(sizeof(struct usb_context), GFP_ATOMIC);
if (usb_context == NULL) {
netdev_warn(dev->net, "Error allocating control msg\n");
usb_free_urb(urb);
return -ENOMEM;
}
usb_context->req.bRequestType =
USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_DEVICE;
usb_context->req.bRequest = USB_VENDOR_REQUEST_WRITE_REGISTER;
usb_context->req.wValue = 00;
usb_context->req.wIndex = cpu_to_le16(index);
usb_context->req.wLength = cpu_to_le16(size);
usb_fill_control_urb(urb, dev->udev, usb_sndctrlpipe(dev->udev, 0),
(void *)&usb_context->req, data, size,
smsc95xx_async_cmd_callback,
(void *)usb_context);
status = usb_submit_urb(urb, GFP_ATOMIC);
if (status < 0) {
netdev_warn(dev->net, "Error submitting control msg, sts=%d\n",
status);
kfree(usb_context);
usb_free_urb(urb);
}
return status;
}
static unsigned int smsc95xx_hash(char addr[ETH_ALEN])
{
return (ether_crc(ETH_ALEN, addr) >> 26) & 0x3f;
}
static void smsc95xx_set_multicast(struct net_device *netdev)
{
struct usbnet *dev = netdev_priv(netdev);
struct smsc95xx_priv *pdata = (struct smsc95xx_priv *)(dev->data[0]);
unsigned long flags;
pdata->hash_hi = 0;
pdata->hash_lo = 0;
spin_lock_irqsave(&pdata->mac_cr_lock, flags);
if (dev->net->flags & IFF_PROMISC) {
netif_dbg(dev, drv, dev->net, "promiscuous mode enabled\n");
pdata->mac_cr |= MAC_CR_PRMS_;
pdata->mac_cr &= ~(MAC_CR_MCPAS_ | MAC_CR_HPFILT_);
} else if (dev->net->flags & IFF_ALLMULTI) {
netif_dbg(dev, drv, dev->net, "receive all multicast enabled\n");
pdata->mac_cr |= MAC_CR_MCPAS_;
pdata->mac_cr &= ~(MAC_CR_PRMS_ | MAC_CR_HPFILT_);
} else if (!netdev_mc_empty(dev->net)) {
struct netdev_hw_addr *ha;
pdata->mac_cr |= MAC_CR_HPFILT_;
pdata->mac_cr &= ~(MAC_CR_PRMS_ | MAC_CR_MCPAS_);
netdev_for_each_mc_addr(ha, netdev) {
u32 bitnum = smsc95xx_hash(ha->addr);
u32 mask = 0x01 << (bitnum & 0x1F);
if (bitnum & 0x20)
pdata->hash_hi |= mask;
else
pdata->hash_lo |= mask;
}
netif_dbg(dev, drv, dev->net, "HASHH=0x%08X, HASHL=0x%08X\n",
pdata->hash_hi, pdata->hash_lo);
} else {
netif_dbg(dev, drv, dev->net, "receive own packets only\n");
pdata->mac_cr &=
~(MAC_CR_PRMS_ | MAC_CR_MCPAS_ | MAC_CR_HPFILT_);
}
spin_unlock_irqrestore(&pdata->mac_cr_lock, flags);
smsc95xx_write_reg_async(dev, HASHH, &pdata->hash_hi);
smsc95xx_write_reg_async(dev, HASHL, &pdata->hash_lo);
smsc95xx_write_reg_async(dev, MAC_CR, &pdata->mac_cr);
}
static void smsc95xx_phy_update_flowcontrol(struct usbnet *dev, u8 duplex,
u16 lcladv, u16 rmtadv)
{
u32 flow, afc_cfg = 0;
int ret = smsc95xx_read_reg(dev, AFC_CFG, &afc_cfg);
if (ret < 0) {
netdev_warn(dev->net, "error reading AFC_CFG\n");
return;
}
if (duplex == DUPLEX_FULL) {
u8 cap = mii_resolve_flowctrl_fdx(lcladv, rmtadv);
if (cap & FLOW_CTRL_RX)
flow = 0xFFFF0002;
else
flow = 0;
if (cap & FLOW_CTRL_TX)
afc_cfg |= 0xF;
else
afc_cfg &= ~0xF;
netif_dbg(dev, link, dev->net, "rx pause %s, tx pause %s\n",
cap & FLOW_CTRL_RX ? "enabled" : "disabled",
cap & FLOW_CTRL_TX ? "enabled" : "disabled");
} else {
netif_dbg(dev, link, dev->net, "half duplex\n");
flow = 0;
afc_cfg |= 0xF;
}
smsc95xx_write_reg(dev, FLOW, flow);
smsc95xx_write_reg(dev, AFC_CFG, afc_cfg);
}
static int smsc95xx_link_reset(struct usbnet *dev)
{
struct smsc95xx_priv *pdata = (struct smsc95xx_priv *)(dev->data[0]);
struct mii_if_info *mii = &dev->mii;
struct ethtool_cmd ecmd = { .cmd = ETHTOOL_GSET };
unsigned long flags;
u16 lcladv, rmtadv;
u32 intdata;
smsc95xx_mdio_read(dev->net, mii->phy_id, PHY_INT_SRC);
intdata = 0xFFFFFFFF;
smsc95xx_write_reg(dev, INT_STS, intdata);
mii_check_media(mii, 1, 1);
mii_ethtool_gset(&dev->mii, &ecmd);
lcladv = smsc95xx_mdio_read(dev->net, mii->phy_id, MII_ADVERTISE);
rmtadv = smsc95xx_mdio_read(dev->net, mii->phy_id, MII_LPA);
netif_dbg(dev, link, dev->net,
"speed: %u duplex: %d lcladv: %04x rmtadv: %04x\n",
ethtool_cmd_speed(&ecmd), ecmd.duplex, lcladv, rmtadv);
spin_lock_irqsave(&pdata->mac_cr_lock, flags);
if (ecmd.duplex != DUPLEX_FULL) {
pdata->mac_cr &= ~MAC_CR_FDPX_;
pdata->mac_cr |= MAC_CR_RCVOWN_;
} else {
pdata->mac_cr &= ~MAC_CR_RCVOWN_;
pdata->mac_cr |= MAC_CR_FDPX_;
}
spin_unlock_irqrestore(&pdata->mac_cr_lock, flags);
smsc95xx_write_reg(dev, MAC_CR, pdata->mac_cr);
smsc95xx_phy_update_flowcontrol(dev, ecmd.duplex, lcladv, rmtadv);
return 0;
}
static void smsc95xx_status(struct usbnet *dev, struct urb *urb)
{
u32 intdata;
if (urb->actual_length != 4) {
netdev_warn(dev->net, "unexpected urb length %d\n",
urb->actual_length);
return;
}
memcpy(&intdata, urb->transfer_buffer, 4);
le32_to_cpus(&intdata);
netif_dbg(dev, link, dev->net, "intdata: 0x%08X\n", intdata);
if (intdata & INT_ENP_PHY_INT_)
usbnet_defer_kevent(dev, EVENT_LINK_RESET);
else
netdev_warn(dev->net, "unexpected interrupt, intdata=0x%08X\n",
intdata);
}
static int smsc95xx_set_features(struct net_device *netdev,
netdev_features_t features)
{
struct usbnet *dev = netdev_priv(netdev);
u32 read_buf;
int ret;
ret = smsc95xx_read_reg(dev, COE_CR, &read_buf);
if (ret < 0) {
netdev_warn(dev->net, "Failed to read COE_CR: %d\n", ret);
return ret;
}
if (features & NETIF_F_HW_CSUM)
read_buf |= Tx_COE_EN_;
else
read_buf &= ~Tx_COE_EN_;
if (features & NETIF_F_RXCSUM)
read_buf |= Rx_COE_EN_;
else
read_buf &= ~Rx_COE_EN_;
ret = smsc95xx_write_reg(dev, COE_CR, read_buf);
if (ret < 0) {
netdev_warn(dev->net, "Failed to write COE_CR: %d\n", ret);
return ret;
}
netif_dbg(dev, hw, dev->net, "COE_CR = 0x%08x\n", read_buf);
return 0;
}
static int smsc95xx_ethtool_get_eeprom_len(struct net_device *net)
{
return MAX_EEPROM_SIZE;
}
static int smsc95xx_ethtool_get_eeprom(struct net_device *netdev,
struct ethtool_eeprom *ee, u8 *data)
{
struct usbnet *dev = netdev_priv(netdev);
ee->magic = LAN95XX_EEPROM_MAGIC;
return smsc95xx_read_eeprom(dev, ee->offset, ee->len, data);
}
static int smsc95xx_ethtool_set_eeprom(struct net_device *netdev,
struct ethtool_eeprom *ee, u8 *data)
{
struct usbnet *dev = netdev_priv(netdev);
if (ee->magic != LAN95XX_EEPROM_MAGIC) {
netdev_warn(dev->net, "EEPROM: magic value mismatch, magic = 0x%x\n",
ee->magic);
return -EINVAL;
}
return smsc95xx_write_eeprom(dev, ee->offset, ee->len, data);
}
static int smsc95xx_ioctl(struct net_device *netdev, struct ifreq *rq, int cmd)
{
struct usbnet *dev = netdev_priv(netdev);
if (!netif_running(netdev))
return -EINVAL;
return generic_mii_ioctl(&dev->mii, if_mii(rq), cmd, NULL);
}
static void smsc95xx_init_mac_address(struct usbnet *dev)
{
if (smsc95xx_read_eeprom(dev, EEPROM_MAC_OFFSET, ETH_ALEN,
dev->net->dev_addr) == 0) {
if (is_valid_ether_addr(dev->net->dev_addr)) {
netif_dbg(dev, ifup, dev->net, "MAC address read from EEPROM\n");
return;
}
}
eth_hw_addr_random(dev->net);
netif_dbg(dev, ifup, dev->net, "MAC address set to random_ether_addr\n");
}
static int smsc95xx_set_mac_address(struct usbnet *dev)
{
u32 addr_lo = dev->net->dev_addr[0] | dev->net->dev_addr[1] << 8 |
dev->net->dev_addr[2] << 16 | dev->net->dev_addr[3] << 24;
u32 addr_hi = dev->net->dev_addr[4] | dev->net->dev_addr[5] << 8;
int ret;
ret = smsc95xx_write_reg(dev, ADDRL, addr_lo);
if (ret < 0) {
netdev_warn(dev->net, "Failed to write ADDRL: %d\n", ret);
return ret;
}
ret = smsc95xx_write_reg(dev, ADDRH, addr_hi);
if (ret < 0) {
netdev_warn(dev->net, "Failed to write ADDRH: %d\n", ret);
return ret;
}
return 0;
}
static void smsc95xx_start_tx_path(struct usbnet *dev)
{
struct smsc95xx_priv *pdata = (struct smsc95xx_priv *)(dev->data[0]);
unsigned long flags;
u32 reg_val;
spin_lock_irqsave(&pdata->mac_cr_lock, flags);
pdata->mac_cr |= MAC_CR_TXEN_;
spin_unlock_irqrestore(&pdata->mac_cr_lock, flags);
smsc95xx_write_reg(dev, MAC_CR, pdata->mac_cr);
reg_val = TX_CFG_ON_;
smsc95xx_write_reg(dev, TX_CFG, reg_val);
}
static void smsc95xx_start_rx_path(struct usbnet *dev)
{
struct smsc95xx_priv *pdata = (struct smsc95xx_priv *)(dev->data[0]);
unsigned long flags;
spin_lock_irqsave(&pdata->mac_cr_lock, flags);
pdata->mac_cr |= MAC_CR_RXEN_;
spin_unlock_irqrestore(&pdata->mac_cr_lock, flags);
smsc95xx_write_reg(dev, MAC_CR, pdata->mac_cr);
}
static int smsc95xx_phy_initialize(struct usbnet *dev)
{
int bmcr, timeout = 0;
dev->mii.dev = dev->net;
dev->mii.mdio_read = smsc95xx_mdio_read;
dev->mii.mdio_write = smsc95xx_mdio_write;
dev->mii.phy_id_mask = 0x1f;
dev->mii.reg_num_mask = 0x1f;
dev->mii.phy_id = SMSC95XX_INTERNAL_PHY_ID;
smsc95xx_mdio_write(dev->net, dev->mii.phy_id, MII_BMCR, BMCR_RESET);
do {
msleep(10);
bmcr = smsc95xx_mdio_read(dev->net, dev->mii.phy_id, MII_BMCR);
timeout++;
} while ((bmcr & BMCR_RESET) && (timeout < 100));
if (timeout >= 100) {
netdev_warn(dev->net, "timeout on PHY Reset");
return -EIO;
}
smsc95xx_mdio_write(dev->net, dev->mii.phy_id, MII_ADVERTISE,
ADVERTISE_ALL | ADVERTISE_CSMA | ADVERTISE_PAUSE_CAP |
ADVERTISE_PAUSE_ASYM);
smsc95xx_mdio_read(dev->net, dev->mii.phy_id, PHY_INT_SRC);
smsc95xx_mdio_write(dev->net, dev->mii.phy_id, PHY_INT_MASK,
PHY_INT_MASK_DEFAULT_);
mii_nway_restart(&dev->mii);
netif_dbg(dev, ifup, dev->net, "phy initialised successfully\n");
return 0;
}
static int smsc95xx_reset(struct usbnet *dev)
{
struct smsc95xx_priv *pdata = (struct smsc95xx_priv *)(dev->data[0]);
u32 read_buf, write_buf, burst_cap;
int ret = 0, timeout;
netif_dbg(dev, ifup, dev->net, "entering smsc95xx_reset\n");
write_buf = HW_CFG_LRST_;
ret = smsc95xx_write_reg(dev, HW_CFG, write_buf);
if (ret < 0) {
netdev_warn(dev->net, "Failed to write HW_CFG_LRST_ bit in HW_CFG register, ret = %d\n",
ret);
return ret;
}
timeout = 0;
do {
ret = smsc95xx_read_reg(dev, HW_CFG, &read_buf);
if (ret < 0) {
netdev_warn(dev->net, "Failed to read HW_CFG: %d\n", ret);
return ret;
}
msleep(10);
timeout++;
} while ((read_buf & HW_CFG_LRST_) && (timeout < 100));
if (timeout >= 100) {
netdev_warn(dev->net, "timeout waiting for completion of Lite Reset\n");
return ret;
}
write_buf = PM_CTL_PHY_RST_;
ret = smsc95xx_write_reg(dev, PM_CTRL, write_buf);
if (ret < 0) {
netdev_warn(dev->net, "Failed to write PM_CTRL: %d\n", ret);
return ret;
}
timeout = 0;
do {
ret = smsc95xx_read_reg(dev, PM_CTRL, &read_buf);
if (ret < 0) {
netdev_warn(dev->net, "Failed to read PM_CTRL: %d\n", ret);
return ret;
}
msleep(10);
timeout++;
} while ((read_buf & PM_CTL_PHY_RST_) && (timeout < 100));
if (timeout >= 100) {
netdev_warn(dev->net, "timeout waiting for PHY Reset\n");
return ret;
}
ret = smsc95xx_set_mac_address(dev);
if (ret < 0)
return ret;
netif_dbg(dev, ifup, dev->net,
"MAC Address: %pM\n", dev->net->dev_addr);
ret = smsc95xx_read_reg(dev, HW_CFG, &read_buf);
if (ret < 0) {
netdev_warn(dev->net, "Failed to read HW_CFG: %d\n", ret);
return ret;
}
netif_dbg(dev, ifup, dev->net,
"Read Value from HW_CFG : 0x%08x\n", read_buf);
read_buf |= HW_CFG_BIR_;
ret = smsc95xx_write_reg(dev, HW_CFG, read_buf);
if (ret < 0) {
netdev_warn(dev->net, "Failed to write HW_CFG_BIR_ bit in HW_CFG register, ret = %d\n",
ret);
return ret;
}
ret = smsc95xx_read_reg(dev, HW_CFG, &read_buf);
if (ret < 0) {
netdev_warn(dev->net, "Failed to read HW_CFG: %d\n", ret);
return ret;
}
netif_dbg(dev, ifup, dev->net,
"Read Value from HW_CFG after writing HW_CFG_BIR_: 0x%08x\n",
read_buf);
if (!turbo_mode) {
burst_cap = 0;
dev->rx_urb_size = MAX_SINGLE_PACKET_SIZE;
} else if (dev->udev->speed == USB_SPEED_HIGH) {
burst_cap = DEFAULT_HS_BURST_CAP_SIZE / HS_USB_PKT_SIZE;
dev->rx_urb_size = DEFAULT_HS_BURST_CAP_SIZE;
} else {
burst_cap = DEFAULT_FS_BURST_CAP_SIZE / FS_USB_PKT_SIZE;
dev->rx_urb_size = DEFAULT_FS_BURST_CAP_SIZE;
}
netif_dbg(dev, ifup, dev->net,
"rx_urb_size=%ld\n", (ulong)dev->rx_urb_size);
ret = smsc95xx_write_reg(dev, BURST_CAP, burst_cap);
if (ret < 0) {
netdev_warn(dev->net, "Failed to write BURST_CAP: %d\n", ret);
return ret;
}
ret = smsc95xx_read_reg(dev, BURST_CAP, &read_buf);
if (ret < 0) {
netdev_warn(dev->net, "Failed to read BURST_CAP: %d\n", ret);
return ret;
}
netif_dbg(dev, ifup, dev->net,
"Read Value from BURST_CAP after writing: 0x%08x\n",
read_buf);
read_buf = DEFAULT_BULK_IN_DELAY;
ret = smsc95xx_write_reg(dev, BULK_IN_DLY, read_buf);
if (ret < 0) {
netdev_warn(dev->net, "ret = %d\n", ret);
return ret;
}
ret = smsc95xx_read_reg(dev, BULK_IN_DLY, &read_buf);
if (ret < 0) {
netdev_warn(dev->net, "Failed to read BULK_IN_DLY: %d\n", ret);
return ret;
}
netif_dbg(dev, ifup, dev->net,
"Read Value from BULK_IN_DLY after writing: 0x%08x\n",
read_buf);
ret = smsc95xx_read_reg(dev, HW_CFG, &read_buf);
if (ret < 0) {
netdev_warn(dev->net, "Failed to read HW_CFG: %d\n", ret);
return ret;
}
netif_dbg(dev, ifup, dev->net,
"Read Value from HW_CFG: 0x%08x\n", read_buf);
if (turbo_mode)
read_buf |= (HW_CFG_MEF_ | HW_CFG_BCE_);
read_buf &= ~HW_CFG_RXDOFF_;
read_buf |= NET_IP_ALIGN << 9;
ret = smsc95xx_write_reg(dev, HW_CFG, read_buf);
if (ret < 0) {
netdev_warn(dev->net, "Failed to write HW_CFG register, ret=%d\n",
ret);
return ret;
}
ret = smsc95xx_read_reg(dev, HW_CFG, &read_buf);
if (ret < 0) {
netdev_warn(dev->net, "Failed to read HW_CFG: %d\n", ret);
return ret;
}
netif_dbg(dev, ifup, dev->net,
"Read Value from HW_CFG after writing: 0x%08x\n", read_buf);
write_buf = 0xFFFFFFFF;
ret = smsc95xx_write_reg(dev, INT_STS, write_buf);
if (ret < 0) {
netdev_warn(dev->net, "Failed to write INT_STS register, ret=%d\n",
ret);
return ret;
}
ret = smsc95xx_read_reg(dev, ID_REV, &read_buf);
if (ret < 0) {
netdev_warn(dev->net, "Failed to read ID_REV: %d\n", ret);
return ret;
}
netif_dbg(dev, ifup, dev->net, "ID_REV = 0x%08x\n", read_buf);
write_buf = LED_GPIO_CFG_SPD_LED | LED_GPIO_CFG_LNK_LED |
LED_GPIO_CFG_FDX_LED;
ret = smsc95xx_write_reg(dev, LED_GPIO_CFG, write_buf);
if (ret < 0) {
netdev_warn(dev->net, "Failed to write LED_GPIO_CFG register, ret=%d\n",
ret);
return ret;
}
write_buf = 0;
ret = smsc95xx_write_reg(dev, FLOW, write_buf);
if (ret < 0) {
netdev_warn(dev->net, "Failed to write FLOW: %d\n", ret);
return ret;
}
read_buf = AFC_CFG_DEFAULT;
ret = smsc95xx_write_reg(dev, AFC_CFG, read_buf);
if (ret < 0) {
netdev_warn(dev->net, "Failed to write AFC_CFG: %d\n", ret);
return ret;
}
ret = smsc95xx_read_reg(dev, MAC_CR, &pdata->mac_cr);
if (ret < 0) {
netdev_warn(dev->net, "Failed to read MAC_CR: %d\n", ret);
return ret;
}
write_buf = (u32)ETH_P_8021Q;
ret = smsc95xx_write_reg(dev, VLAN1, write_buf);
if (ret < 0) {
netdev_warn(dev->net, "Failed to write VAN1: %d\n", ret);
return ret;
}
smsc95xx_set_features(dev->net, dev->net->features);
smsc95xx_set_multicast(dev->net);
if (smsc95xx_phy_initialize(dev) < 0)
return -EIO;
ret = smsc95xx_read_reg(dev, INT_EP_CTL, &read_buf);
if (ret < 0) {
netdev_warn(dev->net, "Failed to read INT_EP_CTL: %d\n", ret);
return ret;
}
read_buf |= INT_EP_CTL_PHY_INT_;
ret = smsc95xx_write_reg(dev, INT_EP_CTL, read_buf);
if (ret < 0) {
netdev_warn(dev->net, "Failed to write INT_EP_CTL: %d\n", ret);
return ret;
}
smsc95xx_start_tx_path(dev);
smsc95xx_start_rx_path(dev);
netif_dbg(dev, ifup, dev->net, "smsc95xx_reset, return 0\n");
return 0;
}
static int smsc95xx_bind(struct usbnet *dev, struct usb_interface *intf)
{
struct smsc95xx_priv *pdata = NULL;
int ret;
printk(KERN_INFO SMSC_CHIPNAME " v" SMSC_DRIVER_VERSION "\n");
ret = usbnet_get_endpoints(dev, intf);
if (ret < 0) {
netdev_warn(dev->net, "usbnet_get_endpoints failed: %d\n", ret);
return ret;
}
dev->data[0] = (unsigned long)kzalloc(sizeof(struct smsc95xx_priv),
GFP_KERNEL);
pdata = (struct smsc95xx_priv *)(dev->data[0]);
if (!pdata) {
netdev_warn(dev->net, "Unable to allocate struct smsc95xx_priv\n");
return -ENOMEM;
}
spin_lock_init(&pdata->mac_cr_lock);
if (DEFAULT_TX_CSUM_ENABLE)
dev->net->features |= NETIF_F_HW_CSUM;
if (DEFAULT_RX_CSUM_ENABLE)
dev->net->features |= NETIF_F_RXCSUM;
dev->net->hw_features = NETIF_F_HW_CSUM | NETIF_F_RXCSUM;
smsc95xx_init_mac_address(dev);
ret = smsc95xx_reset(dev);
dev->net->netdev_ops = &smsc95xx_netdev_ops;
dev->net->ethtool_ops = &smsc95xx_ethtool_ops;
dev->net->flags |= IFF_MULTICAST;
dev->net->hard_header_len += SMSC95XX_TX_OVERHEAD_CSUM;
dev->hard_mtu = dev->net->mtu + dev->net->hard_header_len;
return 0;
}
static void smsc95xx_unbind(struct usbnet *dev, struct usb_interface *intf)
{
struct smsc95xx_priv *pdata = (struct smsc95xx_priv *)(dev->data[0]);
if (pdata) {
netif_dbg(dev, ifdown, dev->net, "free pdata\n");
kfree(pdata);
pdata = NULL;
dev->data[0] = 0;
}
}
static void smsc95xx_rx_csum_offload(struct sk_buff *skb)
{
skb->csum = *(u16 *)(skb_tail_pointer(skb) - 2);
skb->ip_summed = CHECKSUM_COMPLETE;
skb_trim(skb, skb->len - 2);
}
static int smsc95xx_rx_fixup(struct usbnet *dev, struct sk_buff *skb)
{
while (skb->len > 0) {
u32 header, align_count;
struct sk_buff *ax_skb;
unsigned char *packet;
u16 size;
memcpy(&header, skb->data, sizeof(header));
le32_to_cpus(&header);
skb_pull(skb, 4 + NET_IP_ALIGN);
packet = skb->data;
size = (u16)((header & RX_STS_FL_) >> 16);
align_count = (4 - ((size + NET_IP_ALIGN) % 4)) % 4;
if (unlikely(header & RX_STS_ES_)) {
netif_dbg(dev, rx_err, dev->net,
"Error header=0x%08x\n", header);
dev->net->stats.rx_errors++;
dev->net->stats.rx_dropped++;
if (header & RX_STS_CRC_) {
dev->net->stats.rx_crc_errors++;
} else {
if (header & (RX_STS_TL_ | RX_STS_RF_))
dev->net->stats.rx_frame_errors++;
if ((header & RX_STS_LE_) &&
(!(header & RX_STS_FT_)))
dev->net->stats.rx_length_errors++;
}
} else {
if (unlikely(size > (ETH_FRAME_LEN + 12))) {
netif_dbg(dev, rx_err, dev->net,
"size err header=0x%08x\n", header);
return 0;
}
if (skb->len == size) {
if (dev->net->features & NETIF_F_RXCSUM)
smsc95xx_rx_csum_offload(skb);
skb_trim(skb, skb->len - 4);
skb->truesize = size + sizeof(struct sk_buff);
return 1;
}
ax_skb = skb_clone(skb, GFP_ATOMIC);
if (unlikely(!ax_skb)) {
netdev_warn(dev->net, "Error allocating skb\n");
return 0;
}
ax_skb->len = size;
ax_skb->data = packet;
skb_set_tail_pointer(ax_skb, size);
if (dev->net->features & NETIF_F_RXCSUM)
smsc95xx_rx_csum_offload(ax_skb);
skb_trim(ax_skb, ax_skb->len - 4);
ax_skb->truesize = size + sizeof(struct sk_buff);
usbnet_skb_return(dev, ax_skb);
}
skb_pull(skb, size);
if (skb->len)
skb_pull(skb, align_count);
}
if (unlikely(skb->len < 0)) {
netdev_warn(dev->net, "invalid rx length<0 %d\n", skb->len);
return 0;
}
return 1;
}
static u32 smsc95xx_calc_csum_preamble(struct sk_buff *skb)
{
u16 low_16 = (u16)skb_checksum_start_offset(skb);
u16 high_16 = low_16 + skb->csum_offset;
return (high_16 << 16) | low_16;
}
static struct sk_buff *smsc95xx_tx_fixup(struct usbnet *dev,
struct sk_buff *skb, gfp_t flags)
{
bool csum = skb->ip_summed == CHECKSUM_PARTIAL;
int overhead = csum ? SMSC95XX_TX_OVERHEAD_CSUM : SMSC95XX_TX_OVERHEAD;
u32 tx_cmd_a, tx_cmd_b;
BUG_ON(skb_shinfo(skb)->nr_frags);
if (skb_headroom(skb) < overhead) {
struct sk_buff *skb2 = skb_copy_expand(skb,
overhead, 0, flags);
dev_kfree_skb_any(skb);
skb = skb2;
if (!skb)
return NULL;
}
if (csum) {
if (skb->len <= 45) {
long csstart = skb_checksum_start_offset(skb);
__wsum calc = csum_partial(skb->data + csstart,
skb->len - csstart, 0);
*((__sum16 *)(skb->data + csstart
+ skb->csum_offset)) = csum_fold(calc);
csum = false;
} else {
u32 csum_preamble = smsc95xx_calc_csum_preamble(skb);
skb_push(skb, 4);
memcpy(skb->data, &csum_preamble, 4);
}
}
skb_push(skb, 4);
tx_cmd_b = (u32)(skb->len - 4);
if (csum)
tx_cmd_b |= TX_CMD_B_CSUM_ENABLE;
cpu_to_le32s(&tx_cmd_b);
memcpy(skb->data, &tx_cmd_b, 4);
skb_push(skb, 4);
tx_cmd_a = (u32)(skb->len - 8) | TX_CMD_A_FIRST_SEG_ |
TX_CMD_A_LAST_SEG_;
cpu_to_le32s(&tx_cmd_a);
memcpy(skb->data, &tx_cmd_a, 4);
return skb;
}
