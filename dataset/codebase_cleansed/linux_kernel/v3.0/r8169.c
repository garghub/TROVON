static u32 ocp_read(struct rtl8169_private *tp, u8 mask, u16 reg)
{
void __iomem *ioaddr = tp->mmio_addr;
int i;
RTL_W32(OCPAR, ((u32)mask & 0x0f) << 12 | (reg & 0x0fff));
for (i = 0; i < 20; i++) {
udelay(100);
if (RTL_R32(OCPAR) & OCPAR_FLAG)
break;
}
return RTL_R32(OCPDR);
}
static void ocp_write(struct rtl8169_private *tp, u8 mask, u16 reg, u32 data)
{
void __iomem *ioaddr = tp->mmio_addr;
int i;
RTL_W32(OCPDR, data);
RTL_W32(OCPAR, OCPAR_FLAG | ((u32)mask & 0x0f) << 12 | (reg & 0x0fff));
for (i = 0; i < 20; i++) {
udelay(100);
if ((RTL_R32(OCPAR) & OCPAR_FLAG) == 0)
break;
}
}
static void rtl8168_oob_notify(struct rtl8169_private *tp, u8 cmd)
{
void __iomem *ioaddr = tp->mmio_addr;
int i;
RTL_W8(ERIDR, cmd);
RTL_W32(ERIAR, 0x800010e8);
msleep(2);
for (i = 0; i < 5; i++) {
udelay(100);
if (!(RTL_R32(ERIAR) & ERIAR_FLAG))
break;
}
ocp_write(tp, 0x1, 0x30, 0x00000001);
}
static u16 rtl8168_get_ocp_reg(struct rtl8169_private *tp)
{
return (tp->mac_version == RTL_GIGA_MAC_VER_31) ? 0xb8 : 0x10;
}
static void rtl8168_driver_start(struct rtl8169_private *tp)
{
u16 reg;
int i;
rtl8168_oob_notify(tp, OOB_CMD_DRIVER_START);
reg = rtl8168_get_ocp_reg(tp);
for (i = 0; i < 10; i++) {
msleep(10);
if (ocp_read(tp, 0x0f, reg) & 0x00000800)
break;
}
}
static void rtl8168_driver_stop(struct rtl8169_private *tp)
{
u16 reg;
int i;
rtl8168_oob_notify(tp, OOB_CMD_DRIVER_STOP);
reg = rtl8168_get_ocp_reg(tp);
for (i = 0; i < 10; i++) {
msleep(10);
if ((ocp_read(tp, 0x0f, reg) & 0x00000800) == 0)
break;
}
}
static int r8168dp_check_dash(struct rtl8169_private *tp)
{
u16 reg = rtl8168_get_ocp_reg(tp);
return (ocp_read(tp, 0x0f, reg) & 0x00008000) ? 1 : 0;
}
static void r8169_mdio_write(void __iomem *ioaddr, int reg_addr, int value)
{
int i;
RTL_W32(PHYAR, 0x80000000 | (reg_addr & 0x1f) << 16 | (value & 0xffff));
for (i = 20; i > 0; i--) {
if (!(RTL_R32(PHYAR) & 0x80000000))
break;
udelay(25);
}
udelay(20);
}
static int r8169_mdio_read(void __iomem *ioaddr, int reg_addr)
{
int i, value = -1;
RTL_W32(PHYAR, 0x0 | (reg_addr & 0x1f) << 16);
for (i = 20; i > 0; i--) {
if (RTL_R32(PHYAR) & 0x80000000) {
value = RTL_R32(PHYAR) & 0xffff;
break;
}
udelay(25);
}
udelay(20);
return value;
}
static void r8168dp_1_mdio_access(void __iomem *ioaddr, int reg_addr, u32 data)
{
int i;
RTL_W32(OCPDR, data |
((reg_addr & OCPDR_REG_MASK) << OCPDR_GPHY_REG_SHIFT));
RTL_W32(OCPAR, OCPAR_GPHY_WRITE_CMD);
RTL_W32(EPHY_RXER_NUM, 0);
for (i = 0; i < 100; i++) {
mdelay(1);
if (!(RTL_R32(OCPAR) & OCPAR_FLAG))
break;
}
}
static void r8168dp_1_mdio_write(void __iomem *ioaddr, int reg_addr, int value)
{
r8168dp_1_mdio_access(ioaddr, reg_addr, OCPDR_WRITE_CMD |
(value & OCPDR_DATA_MASK));
}
static int r8168dp_1_mdio_read(void __iomem *ioaddr, int reg_addr)
{
int i;
r8168dp_1_mdio_access(ioaddr, reg_addr, OCPDR_READ_CMD);
mdelay(1);
RTL_W32(OCPAR, OCPAR_GPHY_READ_CMD);
RTL_W32(EPHY_RXER_NUM, 0);
for (i = 0; i < 100; i++) {
mdelay(1);
if (RTL_R32(OCPAR) & OCPAR_FLAG)
break;
}
return RTL_R32(OCPDR) & OCPDR_DATA_MASK;
}
static void r8168dp_2_mdio_start(void __iomem *ioaddr)
{
RTL_W32(0xd0, RTL_R32(0xd0) & ~R8168DP_1_MDIO_ACCESS_BIT);
}
static void r8168dp_2_mdio_stop(void __iomem *ioaddr)
{
RTL_W32(0xd0, RTL_R32(0xd0) | R8168DP_1_MDIO_ACCESS_BIT);
}
static void r8168dp_2_mdio_write(void __iomem *ioaddr, int reg_addr, int value)
{
r8168dp_2_mdio_start(ioaddr);
r8169_mdio_write(ioaddr, reg_addr, value);
r8168dp_2_mdio_stop(ioaddr);
}
static int r8168dp_2_mdio_read(void __iomem *ioaddr, int reg_addr)
{
int value;
r8168dp_2_mdio_start(ioaddr);
value = r8169_mdio_read(ioaddr, reg_addr);
r8168dp_2_mdio_stop(ioaddr);
return value;
}
static void rtl_writephy(struct rtl8169_private *tp, int location, u32 val)
{
tp->mdio_ops.write(tp->mmio_addr, location, val);
}
static int rtl_readphy(struct rtl8169_private *tp, int location)
{
return tp->mdio_ops.read(tp->mmio_addr, location);
}
static void rtl_patchphy(struct rtl8169_private *tp, int reg_addr, int value)
{
rtl_writephy(tp, reg_addr, rtl_readphy(tp, reg_addr) | value);
}
static void rtl_w1w0_phy(struct rtl8169_private *tp, int reg_addr, int p, int m)
{
int val;
val = rtl_readphy(tp, reg_addr);
rtl_writephy(tp, reg_addr, (val | p) & ~m);
}
static void rtl_mdio_write(struct net_device *dev, int phy_id, int location,
int val)
{
struct rtl8169_private *tp = netdev_priv(dev);
rtl_writephy(tp, location, val);
}
static int rtl_mdio_read(struct net_device *dev, int phy_id, int location)
{
struct rtl8169_private *tp = netdev_priv(dev);
return rtl_readphy(tp, location);
}
static void rtl_ephy_write(void __iomem *ioaddr, int reg_addr, int value)
{
unsigned int i;
RTL_W32(EPHYAR, EPHYAR_WRITE_CMD | (value & EPHYAR_DATA_MASK) |
(reg_addr & EPHYAR_REG_MASK) << EPHYAR_REG_SHIFT);
for (i = 0; i < 100; i++) {
if (!(RTL_R32(EPHYAR) & EPHYAR_FLAG))
break;
udelay(10);
}
}
static u16 rtl_ephy_read(void __iomem *ioaddr, int reg_addr)
{
u16 value = 0xffff;
unsigned int i;
RTL_W32(EPHYAR, (reg_addr & EPHYAR_REG_MASK) << EPHYAR_REG_SHIFT);
for (i = 0; i < 100; i++) {
if (RTL_R32(EPHYAR) & EPHYAR_FLAG) {
value = RTL_R32(EPHYAR) & EPHYAR_DATA_MASK;
break;
}
udelay(10);
}
return value;
}
static void rtl_csi_write(void __iomem *ioaddr, int addr, int value)
{
unsigned int i;
RTL_W32(CSIDR, value);
RTL_W32(CSIAR, CSIAR_WRITE_CMD | (addr & CSIAR_ADDR_MASK) |
CSIAR_BYTE_ENABLE << CSIAR_BYTE_ENABLE_SHIFT);
for (i = 0; i < 100; i++) {
if (!(RTL_R32(CSIAR) & CSIAR_FLAG))
break;
udelay(10);
}
}
static u32 rtl_csi_read(void __iomem *ioaddr, int addr)
{
u32 value = ~0x00;
unsigned int i;
RTL_W32(CSIAR, (addr & CSIAR_ADDR_MASK) |
CSIAR_BYTE_ENABLE << CSIAR_BYTE_ENABLE_SHIFT);
for (i = 0; i < 100; i++) {
if (RTL_R32(CSIAR) & CSIAR_FLAG) {
value = RTL_R32(CSIDR);
break;
}
udelay(10);
}
return value;
}
static u8 rtl8168d_efuse_read(void __iomem *ioaddr, int reg_addr)
{
u8 value = 0xff;
unsigned int i;
RTL_W32(EFUSEAR, (reg_addr & EFUSEAR_REG_MASK) << EFUSEAR_REG_SHIFT);
for (i = 0; i < 300; i++) {
if (RTL_R32(EFUSEAR) & EFUSEAR_FLAG) {
value = RTL_R32(EFUSEAR) & EFUSEAR_DATA_MASK;
break;
}
udelay(100);
}
return value;
}
static void rtl8169_irq_mask_and_ack(void __iomem *ioaddr)
{
RTL_W16(IntrMask, 0x0000);
RTL_W16(IntrStatus, 0xffff);
}
static void rtl8169_asic_down(void __iomem *ioaddr)
{
RTL_W8(ChipCmd, 0x00);
rtl8169_irq_mask_and_ack(ioaddr);
RTL_R16(CPlusCmd);
}
static unsigned int rtl8169_tbi_reset_pending(struct rtl8169_private *tp)
{
void __iomem *ioaddr = tp->mmio_addr;
return RTL_R32(TBICSR) & TBIReset;
}
static unsigned int rtl8169_xmii_reset_pending(struct rtl8169_private *tp)
{
return rtl_readphy(tp, MII_BMCR) & BMCR_RESET;
}
static unsigned int rtl8169_tbi_link_ok(void __iomem *ioaddr)
{
return RTL_R32(TBICSR) & TBILinkOk;
}
static unsigned int rtl8169_xmii_link_ok(void __iomem *ioaddr)
{
return RTL_R8(PHYstatus) & LinkStatus;
}
static void rtl8169_tbi_reset_enable(struct rtl8169_private *tp)
{
void __iomem *ioaddr = tp->mmio_addr;
RTL_W32(TBICSR, RTL_R32(TBICSR) | TBIReset);
}
static void rtl8169_xmii_reset_enable(struct rtl8169_private *tp)
{
unsigned int val;
val = rtl_readphy(tp, MII_BMCR) | BMCR_RESET;
rtl_writephy(tp, MII_BMCR, val & 0xffff);
}
static void __rtl8169_check_link_status(struct net_device *dev,
struct rtl8169_private *tp,
void __iomem *ioaddr, bool pm)
{
unsigned long flags;
spin_lock_irqsave(&tp->lock, flags);
if (tp->link_ok(ioaddr)) {
if (pm)
pm_request_resume(&tp->pci_dev->dev);
netif_carrier_on(dev);
if (net_ratelimit())
netif_info(tp, ifup, dev, "link up\n");
} else {
netif_carrier_off(dev);
netif_info(tp, ifdown, dev, "link down\n");
if (pm)
pm_schedule_suspend(&tp->pci_dev->dev, 100);
}
spin_unlock_irqrestore(&tp->lock, flags);
}
static void rtl8169_check_link_status(struct net_device *dev,
struct rtl8169_private *tp,
void __iomem *ioaddr)
{
__rtl8169_check_link_status(dev, tp, ioaddr, false);
}
static u32 __rtl8169_get_wol(struct rtl8169_private *tp)
{
void __iomem *ioaddr = tp->mmio_addr;
u8 options;
u32 wolopts = 0;
options = RTL_R8(Config1);
if (!(options & PMEnable))
return 0;
options = RTL_R8(Config3);
if (options & LinkUp)
wolopts |= WAKE_PHY;
if (options & MagicPacket)
wolopts |= WAKE_MAGIC;
options = RTL_R8(Config5);
if (options & UWF)
wolopts |= WAKE_UCAST;
if (options & BWF)
wolopts |= WAKE_BCAST;
if (options & MWF)
wolopts |= WAKE_MCAST;
return wolopts;
}
static void rtl8169_get_wol(struct net_device *dev, struct ethtool_wolinfo *wol)
{
struct rtl8169_private *tp = netdev_priv(dev);
spin_lock_irq(&tp->lock);
wol->supported = WAKE_ANY;
wol->wolopts = __rtl8169_get_wol(tp);
spin_unlock_irq(&tp->lock);
}
static void __rtl8169_set_wol(struct rtl8169_private *tp, u32 wolopts)
{
void __iomem *ioaddr = tp->mmio_addr;
unsigned int i;
static const struct {
u32 opt;
u16 reg;
u8 mask;
} cfg[] = {
{ WAKE_ANY, Config1, PMEnable },
{ WAKE_PHY, Config3, LinkUp },
{ WAKE_MAGIC, Config3, MagicPacket },
{ WAKE_UCAST, Config5, UWF },
{ WAKE_BCAST, Config5, BWF },
{ WAKE_MCAST, Config5, MWF },
{ WAKE_ANY, Config5, LanWake }
};
RTL_W8(Cfg9346, Cfg9346_Unlock);
for (i = 0; i < ARRAY_SIZE(cfg); i++) {
u8 options = RTL_R8(cfg[i].reg) & ~cfg[i].mask;
if (wolopts & cfg[i].opt)
options |= cfg[i].mask;
RTL_W8(cfg[i].reg, options);
}
RTL_W8(Cfg9346, Cfg9346_Lock);
}
static int rtl8169_set_wol(struct net_device *dev, struct ethtool_wolinfo *wol)
{
struct rtl8169_private *tp = netdev_priv(dev);
spin_lock_irq(&tp->lock);
if (wol->wolopts)
tp->features |= RTL_FEATURE_WOL;
else
tp->features &= ~RTL_FEATURE_WOL;
__rtl8169_set_wol(tp, wol->wolopts);
spin_unlock_irq(&tp->lock);
device_set_wakeup_enable(&tp->pci_dev->dev, wol->wolopts);
return 0;
}
static const char *rtl_lookup_firmware_name(struct rtl8169_private *tp)
{
return rtl_chip_infos[tp->mac_version].fw_name;
}
static void rtl8169_get_drvinfo(struct net_device *dev,
struct ethtool_drvinfo *info)
{
struct rtl8169_private *tp = netdev_priv(dev);
strcpy(info->driver, MODULENAME);
strcpy(info->version, RTL8169_VERSION);
strcpy(info->bus_info, pci_name(tp->pci_dev));
strncpy(info->fw_version, IS_ERR_OR_NULL(tp->fw) ? "N/A" :
rtl_lookup_firmware_name(tp), sizeof(info->fw_version) - 1);
}
static int rtl8169_get_regs_len(struct net_device *dev)
{
return R8169_REGS_SIZE;
}
static int rtl8169_set_speed_tbi(struct net_device *dev,
u8 autoneg, u16 speed, u8 duplex, u32 ignored)
{
struct rtl8169_private *tp = netdev_priv(dev);
void __iomem *ioaddr = tp->mmio_addr;
int ret = 0;
u32 reg;
reg = RTL_R32(TBICSR);
if ((autoneg == AUTONEG_DISABLE) && (speed == SPEED_1000) &&
(duplex == DUPLEX_FULL)) {
RTL_W32(TBICSR, reg & ~(TBINwEnable | TBINwRestart));
} else if (autoneg == AUTONEG_ENABLE)
RTL_W32(TBICSR, reg | TBINwEnable | TBINwRestart);
else {
netif_warn(tp, link, dev,
"incorrect speed setting refused in TBI mode\n");
ret = -EOPNOTSUPP;
}
return ret;
}
static int rtl8169_set_speed_xmii(struct net_device *dev,
u8 autoneg, u16 speed, u8 duplex, u32 adv)
{
struct rtl8169_private *tp = netdev_priv(dev);
int giga_ctrl, bmcr;
int rc = -EINVAL;
rtl_writephy(tp, 0x1f, 0x0000);
if (autoneg == AUTONEG_ENABLE) {
int auto_nego;
auto_nego = rtl_readphy(tp, MII_ADVERTISE);
auto_nego &= ~(ADVERTISE_10HALF | ADVERTISE_10FULL |
ADVERTISE_100HALF | ADVERTISE_100FULL);
if (adv & ADVERTISED_10baseT_Half)
auto_nego |= ADVERTISE_10HALF;
if (adv & ADVERTISED_10baseT_Full)
auto_nego |= ADVERTISE_10FULL;
if (adv & ADVERTISED_100baseT_Half)
auto_nego |= ADVERTISE_100HALF;
if (adv & ADVERTISED_100baseT_Full)
auto_nego |= ADVERTISE_100FULL;
auto_nego |= ADVERTISE_PAUSE_CAP | ADVERTISE_PAUSE_ASYM;
giga_ctrl = rtl_readphy(tp, MII_CTRL1000);
giga_ctrl &= ~(ADVERTISE_1000FULL | ADVERTISE_1000HALF);
if (tp->mii.supports_gmii) {
if (adv & ADVERTISED_1000baseT_Half)
giga_ctrl |= ADVERTISE_1000HALF;
if (adv & ADVERTISED_1000baseT_Full)
giga_ctrl |= ADVERTISE_1000FULL;
} else if (adv & (ADVERTISED_1000baseT_Half |
ADVERTISED_1000baseT_Full)) {
netif_info(tp, link, dev,
"PHY does not support 1000Mbps\n");
goto out;
}
bmcr = BMCR_ANENABLE | BMCR_ANRESTART;
rtl_writephy(tp, MII_ADVERTISE, auto_nego);
rtl_writephy(tp, MII_CTRL1000, giga_ctrl);
} else {
giga_ctrl = 0;
if (speed == SPEED_10)
bmcr = 0;
else if (speed == SPEED_100)
bmcr = BMCR_SPEED100;
else
goto out;
if (duplex == DUPLEX_FULL)
bmcr |= BMCR_FULLDPLX;
}
rtl_writephy(tp, MII_BMCR, bmcr);
if (tp->mac_version == RTL_GIGA_MAC_VER_02 ||
tp->mac_version == RTL_GIGA_MAC_VER_03) {
if ((speed == SPEED_100) && (autoneg != AUTONEG_ENABLE)) {
rtl_writephy(tp, 0x17, 0x2138);
rtl_writephy(tp, 0x0e, 0x0260);
} else {
rtl_writephy(tp, 0x17, 0x2108);
rtl_writephy(tp, 0x0e, 0x0000);
}
}
rc = 0;
out:
return rc;
}
static int rtl8169_set_speed(struct net_device *dev,
u8 autoneg, u16 speed, u8 duplex, u32 advertising)
{
struct rtl8169_private *tp = netdev_priv(dev);
int ret;
ret = tp->set_speed(dev, autoneg, speed, duplex, advertising);
if (ret < 0)
goto out;
if (netif_running(dev) && (autoneg == AUTONEG_ENABLE) &&
(advertising & ADVERTISED_1000baseT_Full)) {
mod_timer(&tp->timer, jiffies + RTL8169_PHY_TIMEOUT);
}
out:
return ret;
}
static int rtl8169_set_settings(struct net_device *dev, struct ethtool_cmd *cmd)
{
struct rtl8169_private *tp = netdev_priv(dev);
unsigned long flags;
int ret;
del_timer_sync(&tp->timer);
spin_lock_irqsave(&tp->lock, flags);
ret = rtl8169_set_speed(dev, cmd->autoneg, ethtool_cmd_speed(cmd),
cmd->duplex, cmd->advertising);
spin_unlock_irqrestore(&tp->lock, flags);
return ret;
}
static u32 rtl8169_fix_features(struct net_device *dev, u32 features)
{
if (dev->mtu > TD_MSS_MAX)
features &= ~NETIF_F_ALL_TSO;
return features;
}
static int rtl8169_set_features(struct net_device *dev, u32 features)
{
struct rtl8169_private *tp = netdev_priv(dev);
void __iomem *ioaddr = tp->mmio_addr;
unsigned long flags;
spin_lock_irqsave(&tp->lock, flags);
if (features & NETIF_F_RXCSUM)
tp->cp_cmd |= RxChkSum;
else
tp->cp_cmd &= ~RxChkSum;
if (dev->features & NETIF_F_HW_VLAN_RX)
tp->cp_cmd |= RxVlan;
else
tp->cp_cmd &= ~RxVlan;
RTL_W16(CPlusCmd, tp->cp_cmd);
RTL_R16(CPlusCmd);
spin_unlock_irqrestore(&tp->lock, flags);
return 0;
}
static inline u32 rtl8169_tx_vlan_tag(struct rtl8169_private *tp,
struct sk_buff *skb)
{
return (vlan_tx_tag_present(skb)) ?
TxVlanTag | swab16(vlan_tx_tag_get(skb)) : 0x00;
}
static void rtl8169_rx_vlan_tag(struct RxDesc *desc, struct sk_buff *skb)
{
u32 opts2 = le32_to_cpu(desc->opts2);
if (opts2 & RxVlanTag)
__vlan_hwaccel_put_tag(skb, swab16(opts2 & 0xffff));
desc->opts2 = 0;
}
static int rtl8169_gset_tbi(struct net_device *dev, struct ethtool_cmd *cmd)
{
struct rtl8169_private *tp = netdev_priv(dev);
void __iomem *ioaddr = tp->mmio_addr;
u32 status;
cmd->supported =
SUPPORTED_1000baseT_Full | SUPPORTED_Autoneg | SUPPORTED_FIBRE;
cmd->port = PORT_FIBRE;
cmd->transceiver = XCVR_INTERNAL;
status = RTL_R32(TBICSR);
cmd->advertising = (status & TBINwEnable) ? ADVERTISED_Autoneg : 0;
cmd->autoneg = !!(status & TBINwEnable);
ethtool_cmd_speed_set(cmd, SPEED_1000);
cmd->duplex = DUPLEX_FULL;
return 0;
}
static int rtl8169_gset_xmii(struct net_device *dev, struct ethtool_cmd *cmd)
{
struct rtl8169_private *tp = netdev_priv(dev);
return mii_ethtool_gset(&tp->mii, cmd);
}
static int rtl8169_get_settings(struct net_device *dev, struct ethtool_cmd *cmd)
{
struct rtl8169_private *tp = netdev_priv(dev);
unsigned long flags;
int rc;
spin_lock_irqsave(&tp->lock, flags);
rc = tp->get_settings(dev, cmd);
spin_unlock_irqrestore(&tp->lock, flags);
return rc;
}
static void rtl8169_get_regs(struct net_device *dev, struct ethtool_regs *regs,
void *p)
{
struct rtl8169_private *tp = netdev_priv(dev);
unsigned long flags;
if (regs->len > R8169_REGS_SIZE)
regs->len = R8169_REGS_SIZE;
spin_lock_irqsave(&tp->lock, flags);
memcpy_fromio(p, tp->mmio_addr, regs->len);
spin_unlock_irqrestore(&tp->lock, flags);
}
static u32 rtl8169_get_msglevel(struct net_device *dev)
{
struct rtl8169_private *tp = netdev_priv(dev);
return tp->msg_enable;
}
static void rtl8169_set_msglevel(struct net_device *dev, u32 value)
{
struct rtl8169_private *tp = netdev_priv(dev);
tp->msg_enable = value;
}
static int rtl8169_get_sset_count(struct net_device *dev, int sset)
{
switch (sset) {
case ETH_SS_STATS:
return ARRAY_SIZE(rtl8169_gstrings);
default:
return -EOPNOTSUPP;
}
}
static void rtl8169_update_counters(struct net_device *dev)
{
struct rtl8169_private *tp = netdev_priv(dev);
void __iomem *ioaddr = tp->mmio_addr;
struct device *d = &tp->pci_dev->dev;
struct rtl8169_counters *counters;
dma_addr_t paddr;
u32 cmd;
int wait = 1000;
if ((RTL_R8(ChipCmd) & CmdRxEnb) == 0)
return;
counters = dma_alloc_coherent(d, sizeof(*counters), &paddr, GFP_KERNEL);
if (!counters)
return;
RTL_W32(CounterAddrHigh, (u64)paddr >> 32);
cmd = (u64)paddr & DMA_BIT_MASK(32);
RTL_W32(CounterAddrLow, cmd);
RTL_W32(CounterAddrLow, cmd | CounterDump);
while (wait--) {
if ((RTL_R32(CounterAddrLow) & CounterDump) == 0) {
memcpy(&tp->counters, counters, sizeof(*counters));
break;
}
udelay(10);
}
RTL_W32(CounterAddrLow, 0);
RTL_W32(CounterAddrHigh, 0);
dma_free_coherent(d, sizeof(*counters), counters, paddr);
}
static void rtl8169_get_ethtool_stats(struct net_device *dev,
struct ethtool_stats *stats, u64 *data)
{
struct rtl8169_private *tp = netdev_priv(dev);
ASSERT_RTNL();
rtl8169_update_counters(dev);
data[0] = le64_to_cpu(tp->counters.tx_packets);
data[1] = le64_to_cpu(tp->counters.rx_packets);
data[2] = le64_to_cpu(tp->counters.tx_errors);
data[3] = le32_to_cpu(tp->counters.rx_errors);
data[4] = le16_to_cpu(tp->counters.rx_missed);
data[5] = le16_to_cpu(tp->counters.align_errors);
data[6] = le32_to_cpu(tp->counters.tx_one_collision);
data[7] = le32_to_cpu(tp->counters.tx_multi_collision);
data[8] = le64_to_cpu(tp->counters.rx_unicast);
data[9] = le64_to_cpu(tp->counters.rx_broadcast);
data[10] = le32_to_cpu(tp->counters.rx_multicast);
data[11] = le16_to_cpu(tp->counters.tx_aborted);
data[12] = le16_to_cpu(tp->counters.tx_underun);
}
static void rtl8169_get_strings(struct net_device *dev, u32 stringset, u8 *data)
{
switch(stringset) {
case ETH_SS_STATS:
memcpy(data, *rtl8169_gstrings, sizeof(rtl8169_gstrings));
break;
}
}
static void rtl8169_get_mac_version(struct rtl8169_private *tp,
struct net_device *dev, u8 default_version)
{
void __iomem *ioaddr = tp->mmio_addr;
static const struct rtl_mac_info {
u32 mask;
u32 val;
int mac_version;
} mac_info[] = {
{ 0x7cf00000, 0x2c200000, RTL_GIGA_MAC_VER_33 },
{ 0x7cf00000, 0x2c100000, RTL_GIGA_MAC_VER_32 },
{ 0x7c800000, 0x2c000000, RTL_GIGA_MAC_VER_33 },
{ 0x7cf00000, 0x28300000, RTL_GIGA_MAC_VER_26 },
{ 0x7cf00000, 0x28100000, RTL_GIGA_MAC_VER_25 },
{ 0x7c800000, 0x28000000, RTL_GIGA_MAC_VER_26 },
{ 0x7cf00000, 0x28800000, RTL_GIGA_MAC_VER_27 },
{ 0x7cf00000, 0x28a00000, RTL_GIGA_MAC_VER_28 },
{ 0x7cf00000, 0x28b00000, RTL_GIGA_MAC_VER_31 },
{ 0x7cf00000, 0x3cb00000, RTL_GIGA_MAC_VER_24 },
{ 0x7cf00000, 0x3c900000, RTL_GIGA_MAC_VER_23 },
{ 0x7cf00000, 0x3c800000, RTL_GIGA_MAC_VER_18 },
{ 0x7c800000, 0x3c800000, RTL_GIGA_MAC_VER_24 },
{ 0x7cf00000, 0x3c000000, RTL_GIGA_MAC_VER_19 },
{ 0x7cf00000, 0x3c200000, RTL_GIGA_MAC_VER_20 },
{ 0x7cf00000, 0x3c300000, RTL_GIGA_MAC_VER_21 },
{ 0x7cf00000, 0x3c400000, RTL_GIGA_MAC_VER_22 },
{ 0x7c800000, 0x3c000000, RTL_GIGA_MAC_VER_22 },
{ 0x7cf00000, 0x38000000, RTL_GIGA_MAC_VER_12 },
{ 0x7cf00000, 0x38500000, RTL_GIGA_MAC_VER_17 },
{ 0x7c800000, 0x38000000, RTL_GIGA_MAC_VER_17 },
{ 0x7c800000, 0x30000000, RTL_GIGA_MAC_VER_11 },
{ 0x7cf00000, 0x40b00000, RTL_GIGA_MAC_VER_30 },
{ 0x7cf00000, 0x40a00000, RTL_GIGA_MAC_VER_30 },
{ 0x7cf00000, 0x40900000, RTL_GIGA_MAC_VER_29 },
{ 0x7c800000, 0x40800000, RTL_GIGA_MAC_VER_30 },
{ 0x7cf00000, 0x34a00000, RTL_GIGA_MAC_VER_09 },
{ 0x7cf00000, 0x24a00000, RTL_GIGA_MAC_VER_09 },
{ 0x7cf00000, 0x34900000, RTL_GIGA_MAC_VER_08 },
{ 0x7cf00000, 0x24900000, RTL_GIGA_MAC_VER_08 },
{ 0x7cf00000, 0x34800000, RTL_GIGA_MAC_VER_07 },
{ 0x7cf00000, 0x24800000, RTL_GIGA_MAC_VER_07 },
{ 0x7cf00000, 0x34000000, RTL_GIGA_MAC_VER_13 },
{ 0x7cf00000, 0x34300000, RTL_GIGA_MAC_VER_10 },
{ 0x7cf00000, 0x34200000, RTL_GIGA_MAC_VER_16 },
{ 0x7c800000, 0x34800000, RTL_GIGA_MAC_VER_09 },
{ 0x7c800000, 0x24800000, RTL_GIGA_MAC_VER_09 },
{ 0x7c800000, 0x34000000, RTL_GIGA_MAC_VER_16 },
{ 0xfc800000, 0x38800000, RTL_GIGA_MAC_VER_15 },
{ 0xfc800000, 0x30800000, RTL_GIGA_MAC_VER_14 },
{ 0xfc800000, 0x98000000, RTL_GIGA_MAC_VER_06 },
{ 0xfc800000, 0x18000000, RTL_GIGA_MAC_VER_05 },
{ 0xfc800000, 0x10000000, RTL_GIGA_MAC_VER_04 },
{ 0xfc800000, 0x04000000, RTL_GIGA_MAC_VER_03 },
{ 0xfc800000, 0x00800000, RTL_GIGA_MAC_VER_02 },
{ 0xfc800000, 0x00000000, RTL_GIGA_MAC_VER_01 },
{ 0x00000000, 0x00000000, RTL_GIGA_MAC_NONE }
};
const struct rtl_mac_info *p = mac_info;
u32 reg;
reg = RTL_R32(TxConfig);
while ((reg & p->mask) != p->val)
p++;
tp->mac_version = p->mac_version;
if (tp->mac_version == RTL_GIGA_MAC_NONE) {
netif_notice(tp, probe, dev,
"unknown MAC, using family default\n");
tp->mac_version = default_version;
}
}
static void rtl8169_print_mac_version(struct rtl8169_private *tp)
{
dprintk("mac_version = 0x%02x\n", tp->mac_version);
}
static void rtl_writephy_batch(struct rtl8169_private *tp,
const struct phy_reg *regs, int len)
{
while (len-- > 0) {
rtl_writephy(tp, regs->reg, regs->val);
regs++;
}
}
static void
rtl_phy_write_fw(struct rtl8169_private *tp, const struct firmware *fw)
{
__le32 *phytable = (__le32 *)fw->data;
struct net_device *dev = tp->dev;
size_t index, fw_size = fw->size / sizeof(*phytable);
u32 predata, count;
if (fw->size % sizeof(*phytable)) {
netif_err(tp, probe, dev, "odd sized firmware %zd\n", fw->size);
return;
}
for (index = 0; index < fw_size; index++) {
u32 action = le32_to_cpu(phytable[index]);
u32 regno = (action & 0x0fff0000) >> 16;
switch(action & 0xf0000000) {
case PHY_READ:
case PHY_DATA_OR:
case PHY_DATA_AND:
case PHY_READ_EFUSE:
case PHY_CLEAR_READCOUNT:
case PHY_WRITE:
case PHY_WRITE_PREVIOUS:
case PHY_DELAY_MS:
break;
case PHY_BJMPN:
if (regno > index) {
netif_err(tp, probe, tp->dev,
"Out of range of firmware\n");
return;
}
break;
case PHY_READCOUNT_EQ_SKIP:
if (index + 2 >= fw_size) {
netif_err(tp, probe, tp->dev,
"Out of range of firmware\n");
return;
}
break;
case PHY_COMP_EQ_SKIPN:
case PHY_COMP_NEQ_SKIPN:
case PHY_SKIPN:
if (index + 1 + regno >= fw_size) {
netif_err(tp, probe, tp->dev,
"Out of range of firmware\n");
return;
}
break;
case PHY_READ_MAC_BYTE:
case PHY_WRITE_MAC_BYTE:
case PHY_WRITE_ERI_WORD:
default:
netif_err(tp, probe, tp->dev,
"Invalid action 0x%08x\n", action);
return;
}
}
predata = 0;
count = 0;
for (index = 0; index < fw_size; ) {
u32 action = le32_to_cpu(phytable[index]);
u32 data = action & 0x0000ffff;
u32 regno = (action & 0x0fff0000) >> 16;
if (!action)
break;
switch(action & 0xf0000000) {
case PHY_READ:
predata = rtl_readphy(tp, regno);
count++;
index++;
break;
case PHY_DATA_OR:
predata |= data;
index++;
break;
case PHY_DATA_AND:
predata &= data;
index++;
break;
case PHY_BJMPN:
index -= regno;
break;
case PHY_READ_EFUSE:
predata = rtl8168d_efuse_read(tp->mmio_addr, regno);
index++;
break;
case PHY_CLEAR_READCOUNT:
count = 0;
index++;
break;
case PHY_WRITE:
rtl_writephy(tp, regno, data);
index++;
break;
case PHY_READCOUNT_EQ_SKIP:
index += (count == data) ? 2 : 1;
break;
case PHY_COMP_EQ_SKIPN:
if (predata == data)
index += regno;
index++;
break;
case PHY_COMP_NEQ_SKIPN:
if (predata != data)
index += regno;
index++;
break;
case PHY_WRITE_PREVIOUS:
rtl_writephy(tp, regno, predata);
index++;
break;
case PHY_SKIPN:
index += regno + 1;
break;
case PHY_DELAY_MS:
mdelay(data);
index++;
break;
case PHY_READ_MAC_BYTE:
case PHY_WRITE_MAC_BYTE:
case PHY_WRITE_ERI_WORD:
default:
BUG();
}
}
}
static void rtl_release_firmware(struct rtl8169_private *tp)
{
if (!IS_ERR_OR_NULL(tp->fw))
release_firmware(tp->fw);
tp->fw = RTL_FIRMWARE_UNKNOWN;
}
static void rtl_apply_firmware(struct rtl8169_private *tp)
{
const struct firmware *fw = tp->fw;
if (!IS_ERR_OR_NULL(fw))
rtl_phy_write_fw(tp, fw);
}
static void rtl_apply_firmware_cond(struct rtl8169_private *tp, u8 reg, u16 val)
{
if (rtl_readphy(tp, reg) != val)
netif_warn(tp, hw, tp->dev, "chipset not ready for firmware\n");
else
rtl_apply_firmware(tp);
}
static void rtl8169s_hw_phy_config(struct rtl8169_private *tp)
{
static const struct phy_reg phy_reg_init[] = {
{ 0x1f, 0x0001 },
{ 0x06, 0x006e },
{ 0x08, 0x0708 },
{ 0x15, 0x4000 },
{ 0x18, 0x65c7 },
{ 0x1f, 0x0001 },
{ 0x03, 0x00a1 },
{ 0x02, 0x0008 },
{ 0x01, 0x0120 },
{ 0x00, 0x1000 },
{ 0x04, 0x0800 },
{ 0x04, 0x0000 },
{ 0x03, 0xff41 },
{ 0x02, 0xdf60 },
{ 0x01, 0x0140 },
{ 0x00, 0x0077 },
{ 0x04, 0x7800 },
{ 0x04, 0x7000 },
{ 0x03, 0x802f },
{ 0x02, 0x4f02 },
{ 0x01, 0x0409 },
{ 0x00, 0xf0f9 },
{ 0x04, 0x9800 },
{ 0x04, 0x9000 },
{ 0x03, 0xdf01 },
{ 0x02, 0xdf20 },
{ 0x01, 0xff95 },
{ 0x00, 0xba00 },
{ 0x04, 0xa800 },
{ 0x04, 0xa000 },
{ 0x03, 0xff41 },
{ 0x02, 0xdf20 },
{ 0x01, 0x0140 },
{ 0x00, 0x00bb },
{ 0x04, 0xb800 },
{ 0x04, 0xb000 },
{ 0x03, 0xdf41 },
{ 0x02, 0xdc60 },
{ 0x01, 0x6340 },
{ 0x00, 0x007d },
{ 0x04, 0xd800 },
{ 0x04, 0xd000 },
{ 0x03, 0xdf01 },
{ 0x02, 0xdf20 },
{ 0x01, 0x100a },
{ 0x00, 0xa0ff },
{ 0x04, 0xf800 },
{ 0x04, 0xf000 },
{ 0x1f, 0x0000 },
{ 0x0b, 0x0000 },
{ 0x00, 0x9200 }
};
rtl_writephy_batch(tp, phy_reg_init, ARRAY_SIZE(phy_reg_init));
}
static void rtl8169sb_hw_phy_config(struct rtl8169_private *tp)
{
static const struct phy_reg phy_reg_init[] = {
{ 0x1f, 0x0002 },
{ 0x01, 0x90d0 },
{ 0x1f, 0x0000 }
};
rtl_writephy_batch(tp, phy_reg_init, ARRAY_SIZE(phy_reg_init));
}
static void rtl8169scd_hw_phy_config_quirk(struct rtl8169_private *tp)
{
struct pci_dev *pdev = tp->pci_dev;
u16 vendor_id, device_id;
pci_read_config_word(pdev, PCI_SUBSYSTEM_VENDOR_ID, &vendor_id);
pci_read_config_word(pdev, PCI_SUBSYSTEM_ID, &device_id);
if ((vendor_id != PCI_VENDOR_ID_GIGABYTE) || (device_id != 0xe000))
return;
rtl_writephy(tp, 0x1f, 0x0001);
rtl_writephy(tp, 0x10, 0xf01b);
rtl_writephy(tp, 0x1f, 0x0000);
}
static void rtl8169scd_hw_phy_config(struct rtl8169_private *tp)
{
static const struct phy_reg phy_reg_init[] = {
{ 0x1f, 0x0001 },
{ 0x04, 0x0000 },
{ 0x03, 0x00a1 },
{ 0x02, 0x0008 },
{ 0x01, 0x0120 },
{ 0x00, 0x1000 },
{ 0x04, 0x0800 },
{ 0x04, 0x9000 },
{ 0x03, 0x802f },
{ 0x02, 0x4f02 },
{ 0x01, 0x0409 },
{ 0x00, 0xf099 },
{ 0x04, 0x9800 },
{ 0x04, 0xa000 },
{ 0x03, 0xdf01 },
{ 0x02, 0xdf20 },
{ 0x01, 0xff95 },
{ 0x00, 0xba00 },
{ 0x04, 0xa800 },
{ 0x04, 0xf000 },
{ 0x03, 0xdf01 },
{ 0x02, 0xdf20 },
{ 0x01, 0x101a },
{ 0x00, 0xa0ff },
{ 0x04, 0xf800 },
{ 0x04, 0x0000 },
{ 0x1f, 0x0000 },
{ 0x1f, 0x0001 },
{ 0x10, 0xf41b },
{ 0x14, 0xfb54 },
{ 0x18, 0xf5c7 },
{ 0x1f, 0x0000 },
{ 0x1f, 0x0001 },
{ 0x17, 0x0cc0 },
{ 0x1f, 0x0000 }
};
rtl_writephy_batch(tp, phy_reg_init, ARRAY_SIZE(phy_reg_init));
rtl8169scd_hw_phy_config_quirk(tp);
}
static void rtl8169sce_hw_phy_config(struct rtl8169_private *tp)
{
static const struct phy_reg phy_reg_init[] = {
{ 0x1f, 0x0001 },
{ 0x04, 0x0000 },
{ 0x03, 0x00a1 },
{ 0x02, 0x0008 },
{ 0x01, 0x0120 },
{ 0x00, 0x1000 },
{ 0x04, 0x0800 },
{ 0x04, 0x9000 },
{ 0x03, 0x802f },
{ 0x02, 0x4f02 },
{ 0x01, 0x0409 },
{ 0x00, 0xf099 },
{ 0x04, 0x9800 },
{ 0x04, 0xa000 },
{ 0x03, 0xdf01 },
{ 0x02, 0xdf20 },
{ 0x01, 0xff95 },
{ 0x00, 0xba00 },
{ 0x04, 0xa800 },
{ 0x04, 0xf000 },
{ 0x03, 0xdf01 },
{ 0x02, 0xdf20 },
{ 0x01, 0x101a },
{ 0x00, 0xa0ff },
{ 0x04, 0xf800 },
{ 0x04, 0x0000 },
{ 0x1f, 0x0000 },
{ 0x1f, 0x0001 },
{ 0x0b, 0x8480 },
{ 0x1f, 0x0000 },
{ 0x1f, 0x0001 },
{ 0x18, 0x67c7 },
{ 0x04, 0x2000 },
{ 0x03, 0x002f },
{ 0x02, 0x4360 },
{ 0x01, 0x0109 },
{ 0x00, 0x3022 },
{ 0x04, 0x2800 },
{ 0x1f, 0x0000 },
{ 0x1f, 0x0001 },
{ 0x17, 0x0cc0 },
{ 0x1f, 0x0000 }
};
rtl_writephy_batch(tp, phy_reg_init, ARRAY_SIZE(phy_reg_init));
}
static void rtl8168bb_hw_phy_config(struct rtl8169_private *tp)
{
static const struct phy_reg phy_reg_init[] = {
{ 0x10, 0xf41b },
{ 0x1f, 0x0000 }
};
rtl_writephy(tp, 0x1f, 0x0001);
rtl_patchphy(tp, 0x16, 1 << 0);
rtl_writephy_batch(tp, phy_reg_init, ARRAY_SIZE(phy_reg_init));
}
static void rtl8168bef_hw_phy_config(struct rtl8169_private *tp)
{
static const struct phy_reg phy_reg_init[] = {
{ 0x1f, 0x0001 },
{ 0x10, 0xf41b },
{ 0x1f, 0x0000 }
};
rtl_writephy_batch(tp, phy_reg_init, ARRAY_SIZE(phy_reg_init));
}
static void rtl8168cp_1_hw_phy_config(struct rtl8169_private *tp)
{
static const struct phy_reg phy_reg_init[] = {
{ 0x1f, 0x0000 },
{ 0x1d, 0x0f00 },
{ 0x1f, 0x0002 },
{ 0x0c, 0x1ec8 },
{ 0x1f, 0x0000 }
};
rtl_writephy_batch(tp, phy_reg_init, ARRAY_SIZE(phy_reg_init));
}
static void rtl8168cp_2_hw_phy_config(struct rtl8169_private *tp)
{
static const struct phy_reg phy_reg_init[] = {
{ 0x1f, 0x0001 },
{ 0x1d, 0x3d98 },
{ 0x1f, 0x0000 }
};
rtl_writephy(tp, 0x1f, 0x0000);
rtl_patchphy(tp, 0x14, 1 << 5);
rtl_patchphy(tp, 0x0d, 1 << 5);
rtl_writephy_batch(tp, phy_reg_init, ARRAY_SIZE(phy_reg_init));
}
static void rtl8168c_1_hw_phy_config(struct rtl8169_private *tp)
{
static const struct phy_reg phy_reg_init[] = {
{ 0x1f, 0x0001 },
{ 0x12, 0x2300 },
{ 0x1f, 0x0002 },
{ 0x00, 0x88d4 },
{ 0x01, 0x82b1 },
{ 0x03, 0x7002 },
{ 0x08, 0x9e30 },
{ 0x09, 0x01f0 },
{ 0x0a, 0x5500 },
{ 0x0c, 0x00c8 },
{ 0x1f, 0x0003 },
{ 0x12, 0xc096 },
{ 0x16, 0x000a },
{ 0x1f, 0x0000 },
{ 0x1f, 0x0000 },
{ 0x09, 0x2000 },
{ 0x09, 0x0000 }
};
rtl_writephy_batch(tp, phy_reg_init, ARRAY_SIZE(phy_reg_init));
rtl_patchphy(tp, 0x14, 1 << 5);
rtl_patchphy(tp, 0x0d, 1 << 5);
rtl_writephy(tp, 0x1f, 0x0000);
}
static void rtl8168c_2_hw_phy_config(struct rtl8169_private *tp)
{
static const struct phy_reg phy_reg_init[] = {
{ 0x1f, 0x0001 },
{ 0x12, 0x2300 },
{ 0x03, 0x802f },
{ 0x02, 0x4f02 },
{ 0x01, 0x0409 },
{ 0x00, 0xf099 },
{ 0x04, 0x9800 },
{ 0x04, 0x9000 },
{ 0x1d, 0x3d98 },
{ 0x1f, 0x0002 },
{ 0x0c, 0x7eb8 },
{ 0x06, 0x0761 },
{ 0x1f, 0x0003 },
{ 0x16, 0x0f0a },
{ 0x1f, 0x0000 }
};
rtl_writephy_batch(tp, phy_reg_init, ARRAY_SIZE(phy_reg_init));
rtl_patchphy(tp, 0x16, 1 << 0);
rtl_patchphy(tp, 0x14, 1 << 5);
rtl_patchphy(tp, 0x0d, 1 << 5);
rtl_writephy(tp, 0x1f, 0x0000);
}
static void rtl8168c_3_hw_phy_config(struct rtl8169_private *tp)
{
static const struct phy_reg phy_reg_init[] = {
{ 0x1f, 0x0001 },
{ 0x12, 0x2300 },
{ 0x1d, 0x3d98 },
{ 0x1f, 0x0002 },
{ 0x0c, 0x7eb8 },
{ 0x06, 0x5461 },
{ 0x1f, 0x0003 },
{ 0x16, 0x0f0a },
{ 0x1f, 0x0000 }
};
rtl_writephy_batch(tp, phy_reg_init, ARRAY_SIZE(phy_reg_init));
rtl_patchphy(tp, 0x16, 1 << 0);
rtl_patchphy(tp, 0x14, 1 << 5);
rtl_patchphy(tp, 0x0d, 1 << 5);
rtl_writephy(tp, 0x1f, 0x0000);
}
static void rtl8168c_4_hw_phy_config(struct rtl8169_private *tp)
{
rtl8168c_3_hw_phy_config(tp);
}
static void rtl8168d_1_hw_phy_config(struct rtl8169_private *tp)
{
static const struct phy_reg phy_reg_init_0[] = {
{ 0x1f, 0x0001 },
{ 0x06, 0x4064 },
{ 0x07, 0x2863 },
{ 0x08, 0x059c },
{ 0x09, 0x26b4 },
{ 0x0a, 0x6a19 },
{ 0x0b, 0xdcc8 },
{ 0x10, 0xf06d },
{ 0x14, 0x7f68 },
{ 0x18, 0x7fd9 },
{ 0x1c, 0xf0ff },
{ 0x1d, 0x3d9c },
{ 0x1f, 0x0003 },
{ 0x12, 0xf49f },
{ 0x13, 0x070b },
{ 0x1a, 0x05ad },
{ 0x14, 0x94c0 },
{ 0x1f, 0x0002 },
{ 0x06, 0x5561 },
{ 0x1f, 0x0005 },
{ 0x05, 0x8332 },
{ 0x06, 0x5561 },
{ 0x1f, 0x0001 },
{ 0x17, 0x0cc0 },
{ 0x1f, 0x0000 },
{ 0x0d, 0xf880 }
};
void __iomem *ioaddr = tp->mmio_addr;
rtl_writephy_batch(tp, phy_reg_init_0, ARRAY_SIZE(phy_reg_init_0));
rtl_writephy(tp, 0x1f, 0x0002);
rtl_w1w0_phy(tp, 0x0b, 0x0010, 0x00ef);
rtl_w1w0_phy(tp, 0x0c, 0xa200, 0x5d00);
if (rtl8168d_efuse_read(ioaddr, 0x01) == 0xb1) {
static const struct phy_reg phy_reg_init[] = {
{ 0x1f, 0x0002 },
{ 0x05, 0x669a },
{ 0x1f, 0x0005 },
{ 0x05, 0x8330 },
{ 0x06, 0x669a },
{ 0x1f, 0x0002 }
};
int val;
rtl_writephy_batch(tp, phy_reg_init, ARRAY_SIZE(phy_reg_init));
val = rtl_readphy(tp, 0x0d);
if ((val & 0x00ff) != 0x006c) {
static const u32 set[] = {
0x0065, 0x0066, 0x0067, 0x0068,
0x0069, 0x006a, 0x006b, 0x006c
};
int i;
rtl_writephy(tp, 0x1f, 0x0002);
val &= 0xff00;
for (i = 0; i < ARRAY_SIZE(set); i++)
rtl_writephy(tp, 0x0d, val | set[i]);
}
} else {
static const struct phy_reg phy_reg_init[] = {
{ 0x1f, 0x0002 },
{ 0x05, 0x6662 },
{ 0x1f, 0x0005 },
{ 0x05, 0x8330 },
{ 0x06, 0x6662 }
};
rtl_writephy_batch(tp, phy_reg_init, ARRAY_SIZE(phy_reg_init));
}
rtl_writephy(tp, 0x1f, 0x0002);
rtl_patchphy(tp, 0x0d, 0x0300);
rtl_patchphy(tp, 0x0f, 0x0010);
rtl_writephy(tp, 0x1f, 0x0002);
rtl_w1w0_phy(tp, 0x02, 0x0100, 0x0600);
rtl_w1w0_phy(tp, 0x03, 0x0000, 0xe000);
rtl_writephy(tp, 0x1f, 0x0005);
rtl_writephy(tp, 0x05, 0x001b);
rtl_apply_firmware_cond(tp, MII_EXPANSION, 0xbf00);
rtl_writephy(tp, 0x1f, 0x0000);
}
static void rtl8168d_2_hw_phy_config(struct rtl8169_private *tp)
{
static const struct phy_reg phy_reg_init_0[] = {
{ 0x1f, 0x0001 },
{ 0x06, 0x4064 },
{ 0x07, 0x2863 },
{ 0x08, 0x059c },
{ 0x09, 0x26b4 },
{ 0x0a, 0x6a19 },
{ 0x0b, 0xdcc8 },
{ 0x10, 0xf06d },
{ 0x14, 0x7f68 },
{ 0x18, 0x7fd9 },
{ 0x1c, 0xf0ff },
{ 0x1d, 0x3d9c },
{ 0x1f, 0x0003 },
{ 0x12, 0xf49f },
{ 0x13, 0x070b },
{ 0x1a, 0x05ad },
{ 0x14, 0x94c0 },
{ 0x1f, 0x0002 },
{ 0x06, 0x5561 },
{ 0x1f, 0x0005 },
{ 0x05, 0x8332 },
{ 0x06, 0x5561 },
{ 0x1f, 0x0001 },
{ 0x17, 0x0cc0 },
{ 0x1f, 0x0000 },
{ 0x0d, 0xf880 }
};
void __iomem *ioaddr = tp->mmio_addr;
rtl_writephy_batch(tp, phy_reg_init_0, ARRAY_SIZE(phy_reg_init_0));
if (rtl8168d_efuse_read(ioaddr, 0x01) == 0xb1) {
static const struct phy_reg phy_reg_init[] = {
{ 0x1f, 0x0002 },
{ 0x05, 0x669a },
{ 0x1f, 0x0005 },
{ 0x05, 0x8330 },
{ 0x06, 0x669a },
{ 0x1f, 0x0002 }
};
int val;
rtl_writephy_batch(tp, phy_reg_init, ARRAY_SIZE(phy_reg_init));
val = rtl_readphy(tp, 0x0d);
if ((val & 0x00ff) != 0x006c) {
static const u32 set[] = {
0x0065, 0x0066, 0x0067, 0x0068,
0x0069, 0x006a, 0x006b, 0x006c
};
int i;
rtl_writephy(tp, 0x1f, 0x0002);
val &= 0xff00;
for (i = 0; i < ARRAY_SIZE(set); i++)
rtl_writephy(tp, 0x0d, val | set[i]);
}
} else {
static const struct phy_reg phy_reg_init[] = {
{ 0x1f, 0x0002 },
{ 0x05, 0x2642 },
{ 0x1f, 0x0005 },
{ 0x05, 0x8330 },
{ 0x06, 0x2642 }
};
rtl_writephy_batch(tp, phy_reg_init, ARRAY_SIZE(phy_reg_init));
}
rtl_writephy(tp, 0x1f, 0x0002);
rtl_w1w0_phy(tp, 0x02, 0x0100, 0x0600);
rtl_w1w0_phy(tp, 0x03, 0x0000, 0xe000);
rtl_writephy(tp, 0x1f, 0x0002);
rtl_patchphy(tp, 0x0f, 0x0017);
rtl_writephy(tp, 0x1f, 0x0005);
rtl_writephy(tp, 0x05, 0x001b);
rtl_apply_firmware_cond(tp, MII_EXPANSION, 0xb300);
rtl_writephy(tp, 0x1f, 0x0000);
}
static void rtl8168d_3_hw_phy_config(struct rtl8169_private *tp)
{
static const struct phy_reg phy_reg_init[] = {
{ 0x1f, 0x0002 },
{ 0x10, 0x0008 },
{ 0x0d, 0x006c },
{ 0x1f, 0x0000 },
{ 0x0d, 0xf880 },
{ 0x1f, 0x0001 },
{ 0x17, 0x0cc0 },
{ 0x1f, 0x0001 },
{ 0x0b, 0xa4d8 },
{ 0x09, 0x281c },
{ 0x07, 0x2883 },
{ 0x0a, 0x6b35 },
{ 0x1d, 0x3da4 },
{ 0x1c, 0xeffd },
{ 0x14, 0x7f52 },
{ 0x18, 0x7fc6 },
{ 0x08, 0x0601 },
{ 0x06, 0x4063 },
{ 0x10, 0xf074 },
{ 0x1f, 0x0003 },
{ 0x13, 0x0789 },
{ 0x12, 0xf4bd },
{ 0x1a, 0x04fd },
{ 0x14, 0x84b0 },
{ 0x1f, 0x0000 },
{ 0x00, 0x9200 },
{ 0x1f, 0x0005 },
{ 0x01, 0x0340 },
{ 0x1f, 0x0001 },
{ 0x04, 0x4000 },
{ 0x03, 0x1d21 },
{ 0x02, 0x0c32 },
{ 0x01, 0x0200 },
{ 0x00, 0x5554 },
{ 0x04, 0x4800 },
{ 0x04, 0x4000 },
{ 0x04, 0xf000 },
{ 0x03, 0xdf01 },
{ 0x02, 0xdf20 },
{ 0x01, 0x101a },
{ 0x00, 0xa0ff },
{ 0x04, 0xf800 },
{ 0x04, 0xf000 },
{ 0x1f, 0x0000 },
{ 0x1f, 0x0007 },
{ 0x1e, 0x0023 },
{ 0x16, 0x0000 },
{ 0x1f, 0x0000 }
};
rtl_writephy_batch(tp, phy_reg_init, ARRAY_SIZE(phy_reg_init));
}
static void rtl8168d_4_hw_phy_config(struct rtl8169_private *tp)
{
static const struct phy_reg phy_reg_init[] = {
{ 0x1f, 0x0001 },
{ 0x17, 0x0cc0 },
{ 0x1f, 0x0007 },
{ 0x1e, 0x002d },
{ 0x18, 0x0040 },
{ 0x1f, 0x0000 }
};
rtl_writephy_batch(tp, phy_reg_init, ARRAY_SIZE(phy_reg_init));
rtl_patchphy(tp, 0x0d, 1 << 5);
}
static void rtl8168e_hw_phy_config(struct rtl8169_private *tp)
{
static const struct phy_reg phy_reg_init[] = {
{ 0x1f, 0x0005 },
{ 0x05, 0x8b80 },
{ 0x06, 0xc896 },
{ 0x1f, 0x0000 },
{ 0x1f, 0x0001 },
{ 0x0b, 0x6c20 },
{ 0x07, 0x2872 },
{ 0x1c, 0xefff },
{ 0x1f, 0x0003 },
{ 0x14, 0x6420 },
{ 0x1f, 0x0000 },
{ 0x1f, 0x0007 },
{ 0x1e, 0x002f },
{ 0x15, 0x1919 },
{ 0x1f, 0x0000 },
{ 0x1f, 0x0007 },
{ 0x1e, 0x00ac },
{ 0x18, 0x0006 },
{ 0x1f, 0x0000 }
};
rtl_apply_firmware(tp);
rtl_writephy_batch(tp, phy_reg_init, ARRAY_SIZE(phy_reg_init));
rtl_writephy(tp, 0x1f, 0x0007);
rtl_writephy(tp, 0x1e, 0x0023);
rtl_w1w0_phy(tp, 0x17, 0x0006, 0x0000);
rtl_writephy(tp, 0x1f, 0x0000);
rtl_writephy(tp, 0x1f, 0x0002);
rtl_w1w0_phy(tp, 0x08, 0x8000, 0x7f00);
rtl_writephy(tp, 0x1f, 0x0000);
rtl_writephy(tp, 0x1f, 0x0007);
rtl_writephy(tp, 0x1e, 0x002d);
rtl_w1w0_phy(tp, 0x18, 0x0050, 0x0000);
rtl_writephy(tp, 0x1f, 0x0000);
rtl_w1w0_phy(tp, 0x14, 0x8000, 0x0000);
rtl_writephy(tp, 0x1f, 0x0005);
rtl_writephy(tp, 0x05, 0x8b86);
rtl_w1w0_phy(tp, 0x06, 0x0001, 0x0000);
rtl_writephy(tp, 0x1f, 0x0000);
rtl_writephy(tp, 0x1f, 0x0005);
rtl_writephy(tp, 0x05, 0x8b85);
rtl_w1w0_phy(tp, 0x06, 0x0000, 0x2000);
rtl_writephy(tp, 0x1f, 0x0007);
rtl_writephy(tp, 0x1e, 0x0020);
rtl_w1w0_phy(tp, 0x15, 0x0000, 0x1100);
rtl_writephy(tp, 0x1f, 0x0006);
rtl_writephy(tp, 0x00, 0x5a00);
rtl_writephy(tp, 0x1f, 0x0000);
rtl_writephy(tp, 0x0d, 0x0007);
rtl_writephy(tp, 0x0e, 0x003c);
rtl_writephy(tp, 0x0d, 0x4007);
rtl_writephy(tp, 0x0e, 0x0000);
rtl_writephy(tp, 0x0d, 0x0000);
}
static void rtl8102e_hw_phy_config(struct rtl8169_private *tp)
{
static const struct phy_reg phy_reg_init[] = {
{ 0x1f, 0x0003 },
{ 0x08, 0x441d },
{ 0x01, 0x9100 },
{ 0x1f, 0x0000 }
};
rtl_writephy(tp, 0x1f, 0x0000);
rtl_patchphy(tp, 0x11, 1 << 12);
rtl_patchphy(tp, 0x19, 1 << 13);
rtl_patchphy(tp, 0x10, 1 << 15);
rtl_writephy_batch(tp, phy_reg_init, ARRAY_SIZE(phy_reg_init));
}
static void rtl8105e_hw_phy_config(struct rtl8169_private *tp)
{
static const struct phy_reg phy_reg_init[] = {
{ 0x1f, 0x0005 },
{ 0x1a, 0x0000 },
{ 0x1f, 0x0000 },
{ 0x1f, 0x0004 },
{ 0x1c, 0x0000 },
{ 0x1f, 0x0000 },
{ 0x1f, 0x0001 },
{ 0x15, 0x7701 },
{ 0x1f, 0x0000 }
};
rtl_writephy(tp, 0x1f, 0x0000);
rtl_writephy(tp, 0x18, 0x0310);
msleep(100);
rtl_apply_firmware(tp);
rtl_writephy_batch(tp, phy_reg_init, ARRAY_SIZE(phy_reg_init));
}
static void rtl_hw_phy_config(struct net_device *dev)
{
struct rtl8169_private *tp = netdev_priv(dev);
rtl8169_print_mac_version(tp);
switch (tp->mac_version) {
case RTL_GIGA_MAC_VER_01:
break;
case RTL_GIGA_MAC_VER_02:
case RTL_GIGA_MAC_VER_03:
rtl8169s_hw_phy_config(tp);
break;
case RTL_GIGA_MAC_VER_04:
rtl8169sb_hw_phy_config(tp);
break;
case RTL_GIGA_MAC_VER_05:
rtl8169scd_hw_phy_config(tp);
break;
case RTL_GIGA_MAC_VER_06:
rtl8169sce_hw_phy_config(tp);
break;
case RTL_GIGA_MAC_VER_07:
case RTL_GIGA_MAC_VER_08:
case RTL_GIGA_MAC_VER_09:
rtl8102e_hw_phy_config(tp);
break;
case RTL_GIGA_MAC_VER_11:
rtl8168bb_hw_phy_config(tp);
break;
case RTL_GIGA_MAC_VER_12:
rtl8168bef_hw_phy_config(tp);
break;
case RTL_GIGA_MAC_VER_17:
rtl8168bef_hw_phy_config(tp);
break;
case RTL_GIGA_MAC_VER_18:
rtl8168cp_1_hw_phy_config(tp);
break;
case RTL_GIGA_MAC_VER_19:
rtl8168c_1_hw_phy_config(tp);
break;
case RTL_GIGA_MAC_VER_20:
rtl8168c_2_hw_phy_config(tp);
break;
case RTL_GIGA_MAC_VER_21:
rtl8168c_3_hw_phy_config(tp);
break;
case RTL_GIGA_MAC_VER_22:
rtl8168c_4_hw_phy_config(tp);
break;
case RTL_GIGA_MAC_VER_23:
case RTL_GIGA_MAC_VER_24:
rtl8168cp_2_hw_phy_config(tp);
break;
case RTL_GIGA_MAC_VER_25:
rtl8168d_1_hw_phy_config(tp);
break;
case RTL_GIGA_MAC_VER_26:
rtl8168d_2_hw_phy_config(tp);
break;
case RTL_GIGA_MAC_VER_27:
rtl8168d_3_hw_phy_config(tp);
break;
case RTL_GIGA_MAC_VER_28:
rtl8168d_4_hw_phy_config(tp);
break;
case RTL_GIGA_MAC_VER_29:
case RTL_GIGA_MAC_VER_30:
rtl8105e_hw_phy_config(tp);
break;
case RTL_GIGA_MAC_VER_31:
break;
case RTL_GIGA_MAC_VER_32:
case RTL_GIGA_MAC_VER_33:
rtl8168e_hw_phy_config(tp);
break;
default:
break;
}
}
static void rtl8169_phy_timer(unsigned long __opaque)
{
struct net_device *dev = (struct net_device *)__opaque;
struct rtl8169_private *tp = netdev_priv(dev);
struct timer_list *timer = &tp->timer;
void __iomem *ioaddr = tp->mmio_addr;
unsigned long timeout = RTL8169_PHY_TIMEOUT;
assert(tp->mac_version > RTL_GIGA_MAC_VER_01);
spin_lock_irq(&tp->lock);
if (tp->phy_reset_pending(tp)) {
timeout = HZ/10;
goto out_mod_timer;
}
if (tp->link_ok(ioaddr))
goto out_unlock;
netif_warn(tp, link, dev, "PHY reset until link up\n");
tp->phy_reset_enable(tp);
out_mod_timer:
mod_timer(timer, jiffies + timeout);
out_unlock:
spin_unlock_irq(&tp->lock);
}
static void rtl8169_netpoll(struct net_device *dev)
{
struct rtl8169_private *tp = netdev_priv(dev);
struct pci_dev *pdev = tp->pci_dev;
disable_irq(pdev->irq);
rtl8169_interrupt(pdev->irq, dev);
enable_irq(pdev->irq);
}
static void rtl8169_release_board(struct pci_dev *pdev, struct net_device *dev,
void __iomem *ioaddr)
{
iounmap(ioaddr);
pci_release_regions(pdev);
pci_clear_mwi(pdev);
pci_disable_device(pdev);
free_netdev(dev);
}
static void rtl8169_phy_reset(struct net_device *dev,
struct rtl8169_private *tp)
{
unsigned int i;
tp->phy_reset_enable(tp);
for (i = 0; i < 100; i++) {
if (!tp->phy_reset_pending(tp))
return;
msleep(1);
}
netif_err(tp, link, dev, "PHY reset failed\n");
}
static void rtl8169_init_phy(struct net_device *dev, struct rtl8169_private *tp)
{
void __iomem *ioaddr = tp->mmio_addr;
rtl_hw_phy_config(dev);
if (tp->mac_version <= RTL_GIGA_MAC_VER_06) {
dprintk("Set MAC Reg C+CR Offset 0x82h = 0x01h\n");
RTL_W8(0x82, 0x01);
}
pci_write_config_byte(tp->pci_dev, PCI_LATENCY_TIMER, 0x40);
if (tp->mac_version <= RTL_GIGA_MAC_VER_06)
pci_write_config_byte(tp->pci_dev, PCI_CACHE_LINE_SIZE, 0x08);
if (tp->mac_version == RTL_GIGA_MAC_VER_02) {
dprintk("Set MAC Reg C+CR Offset 0x82h = 0x01h\n");
RTL_W8(0x82, 0x01);
dprintk("Set PHY Reg 0x0bh = 0x00h\n");
rtl_writephy(tp, 0x0b, 0x0000);
}
rtl8169_phy_reset(dev, tp);
rtl8169_set_speed(dev, AUTONEG_ENABLE, SPEED_1000, DUPLEX_FULL,
ADVERTISED_10baseT_Half | ADVERTISED_10baseT_Full |
ADVERTISED_100baseT_Half | ADVERTISED_100baseT_Full |
(tp->mii.supports_gmii ?
ADVERTISED_1000baseT_Half |
ADVERTISED_1000baseT_Full : 0));
if (RTL_R8(PHYstatus) & TBI_Enable)
netif_info(tp, link, dev, "TBI auto-negotiating\n");
}
static void rtl_rar_set(struct rtl8169_private *tp, u8 *addr)
{
void __iomem *ioaddr = tp->mmio_addr;
u32 high;
u32 low;
low = addr[0] | (addr[1] << 8) | (addr[2] << 16) | (addr[3] << 24);
high = addr[4] | (addr[5] << 8);
spin_lock_irq(&tp->lock);
RTL_W8(Cfg9346, Cfg9346_Unlock);
RTL_W32(MAC4, high);
RTL_R32(MAC4);
RTL_W32(MAC0, low);
RTL_R32(MAC0);
RTL_W8(Cfg9346, Cfg9346_Lock);
spin_unlock_irq(&tp->lock);
}
static int rtl_set_mac_address(struct net_device *dev, void *p)
{
struct rtl8169_private *tp = netdev_priv(dev);
struct sockaddr *addr = p;
if (!is_valid_ether_addr(addr->sa_data))
return -EADDRNOTAVAIL;
memcpy(dev->dev_addr, addr->sa_data, dev->addr_len);
rtl_rar_set(tp, dev->dev_addr);
return 0;
}
static int rtl8169_ioctl(struct net_device *dev, struct ifreq *ifr, int cmd)
{
struct rtl8169_private *tp = netdev_priv(dev);
struct mii_ioctl_data *data = if_mii(ifr);
return netif_running(dev) ? tp->do_ioctl(tp, data, cmd) : -ENODEV;
}
static int rtl_xmii_ioctl(struct rtl8169_private *tp,
struct mii_ioctl_data *data, int cmd)
{
switch (cmd) {
case SIOCGMIIPHY:
data->phy_id = 32;
return 0;
case SIOCGMIIREG:
data->val_out = rtl_readphy(tp, data->reg_num & 0x1f);
return 0;
case SIOCSMIIREG:
rtl_writephy(tp, data->reg_num & 0x1f, data->val_in);
return 0;
}
return -EOPNOTSUPP;
}
static int rtl_tbi_ioctl(struct rtl8169_private *tp, struct mii_ioctl_data *data, int cmd)
{
return -EOPNOTSUPP;
}
static unsigned rtl_try_msi(struct pci_dev *pdev, void __iomem *ioaddr,
const struct rtl_cfg_info *cfg)
{
unsigned msi = 0;
u8 cfg2;
cfg2 = RTL_R8(Config2) & ~MSIEnable;
if (cfg->features & RTL_FEATURE_MSI) {
if (pci_enable_msi(pdev)) {
dev_info(&pdev->dev, "no MSI. Back to INTx.\n");
} else {
cfg2 |= MSIEnable;
msi = RTL_FEATURE_MSI;
}
}
RTL_W8(Config2, cfg2);
return msi;
}
static void rtl_disable_msi(struct pci_dev *pdev, struct rtl8169_private *tp)
{
if (tp->features & RTL_FEATURE_MSI) {
pci_disable_msi(pdev);
tp->features &= ~RTL_FEATURE_MSI;
}
}
static void __devinit rtl_init_mdio_ops(struct rtl8169_private *tp)
{
struct mdio_ops *ops = &tp->mdio_ops;
switch (tp->mac_version) {
case RTL_GIGA_MAC_VER_27:
ops->write = r8168dp_1_mdio_write;
ops->read = r8168dp_1_mdio_read;
break;
case RTL_GIGA_MAC_VER_28:
case RTL_GIGA_MAC_VER_31:
ops->write = r8168dp_2_mdio_write;
ops->read = r8168dp_2_mdio_read;
break;
default:
ops->write = r8169_mdio_write;
ops->read = r8169_mdio_read;
break;
}
}
static void r810x_phy_power_down(struct rtl8169_private *tp)
{
rtl_writephy(tp, 0x1f, 0x0000);
rtl_writephy(tp, MII_BMCR, BMCR_PDOWN);
}
static void r810x_phy_power_up(struct rtl8169_private *tp)
{
rtl_writephy(tp, 0x1f, 0x0000);
rtl_writephy(tp, MII_BMCR, BMCR_ANENABLE);
}
static void r810x_pll_power_down(struct rtl8169_private *tp)
{
if (__rtl8169_get_wol(tp) & WAKE_ANY) {
rtl_writephy(tp, 0x1f, 0x0000);
rtl_writephy(tp, MII_BMCR, 0x0000);
return;
}
r810x_phy_power_down(tp);
}
static void r810x_pll_power_up(struct rtl8169_private *tp)
{
r810x_phy_power_up(tp);
}
static void r8168_phy_power_up(struct rtl8169_private *tp)
{
rtl_writephy(tp, 0x1f, 0x0000);
switch (tp->mac_version) {
case RTL_GIGA_MAC_VER_11:
case RTL_GIGA_MAC_VER_12:
case RTL_GIGA_MAC_VER_17:
case RTL_GIGA_MAC_VER_18:
case RTL_GIGA_MAC_VER_19:
case RTL_GIGA_MAC_VER_20:
case RTL_GIGA_MAC_VER_21:
case RTL_GIGA_MAC_VER_22:
case RTL_GIGA_MAC_VER_23:
case RTL_GIGA_MAC_VER_24:
case RTL_GIGA_MAC_VER_25:
case RTL_GIGA_MAC_VER_26:
case RTL_GIGA_MAC_VER_27:
case RTL_GIGA_MAC_VER_28:
case RTL_GIGA_MAC_VER_31:
rtl_writephy(tp, 0x0e, 0x0000);
break;
default:
break;
}
rtl_writephy(tp, MII_BMCR, BMCR_ANENABLE);
}
static void r8168_phy_power_down(struct rtl8169_private *tp)
{
rtl_writephy(tp, 0x1f, 0x0000);
switch (tp->mac_version) {
case RTL_GIGA_MAC_VER_32:
case RTL_GIGA_MAC_VER_33:
rtl_writephy(tp, MII_BMCR, BMCR_ANENABLE | BMCR_PDOWN);
break;
case RTL_GIGA_MAC_VER_11:
case RTL_GIGA_MAC_VER_12:
case RTL_GIGA_MAC_VER_17:
case RTL_GIGA_MAC_VER_18:
case RTL_GIGA_MAC_VER_19:
case RTL_GIGA_MAC_VER_20:
case RTL_GIGA_MAC_VER_21:
case RTL_GIGA_MAC_VER_22:
case RTL_GIGA_MAC_VER_23:
case RTL_GIGA_MAC_VER_24:
case RTL_GIGA_MAC_VER_25:
case RTL_GIGA_MAC_VER_26:
case RTL_GIGA_MAC_VER_27:
case RTL_GIGA_MAC_VER_28:
case RTL_GIGA_MAC_VER_31:
rtl_writephy(tp, 0x0e, 0x0200);
default:
rtl_writephy(tp, MII_BMCR, BMCR_PDOWN);
break;
}
}
static void r8168_pll_power_down(struct rtl8169_private *tp)
{
void __iomem *ioaddr = tp->mmio_addr;
if ((tp->mac_version == RTL_GIGA_MAC_VER_27 ||
tp->mac_version == RTL_GIGA_MAC_VER_28 ||
tp->mac_version == RTL_GIGA_MAC_VER_31) &&
r8168dp_check_dash(tp)) {
return;
}
if ((tp->mac_version == RTL_GIGA_MAC_VER_23 ||
tp->mac_version == RTL_GIGA_MAC_VER_24) &&
(RTL_R16(CPlusCmd) & ASF)) {
return;
}
if (tp->mac_version == RTL_GIGA_MAC_VER_32 ||
tp->mac_version == RTL_GIGA_MAC_VER_33)
rtl_ephy_write(ioaddr, 0x19, 0xff64);
if (__rtl8169_get_wol(tp) & WAKE_ANY) {
rtl_writephy(tp, 0x1f, 0x0000);
rtl_writephy(tp, MII_BMCR, 0x0000);
RTL_W32(RxConfig, RTL_R32(RxConfig) |
AcceptBroadcast | AcceptMulticast | AcceptMyPhys);
return;
}
r8168_phy_power_down(tp);
switch (tp->mac_version) {
case RTL_GIGA_MAC_VER_25:
case RTL_GIGA_MAC_VER_26:
case RTL_GIGA_MAC_VER_27:
case RTL_GIGA_MAC_VER_28:
case RTL_GIGA_MAC_VER_31:
case RTL_GIGA_MAC_VER_32:
case RTL_GIGA_MAC_VER_33:
RTL_W8(PMCH, RTL_R8(PMCH) & ~0x80);
break;
}
}
static void r8168_pll_power_up(struct rtl8169_private *tp)
{
void __iomem *ioaddr = tp->mmio_addr;
if ((tp->mac_version == RTL_GIGA_MAC_VER_27 ||
tp->mac_version == RTL_GIGA_MAC_VER_28 ||
tp->mac_version == RTL_GIGA_MAC_VER_31) &&
r8168dp_check_dash(tp)) {
return;
}
switch (tp->mac_version) {
case RTL_GIGA_MAC_VER_25:
case RTL_GIGA_MAC_VER_26:
case RTL_GIGA_MAC_VER_27:
case RTL_GIGA_MAC_VER_28:
case RTL_GIGA_MAC_VER_31:
case RTL_GIGA_MAC_VER_32:
case RTL_GIGA_MAC_VER_33:
RTL_W8(PMCH, RTL_R8(PMCH) | 0x80);
break;
}
r8168_phy_power_up(tp);
}
static void rtl_pll_power_op(struct rtl8169_private *tp,
void (*op)(struct rtl8169_private *))
{
if (op)
op(tp);
}
static void rtl_pll_power_down(struct rtl8169_private *tp)
{
rtl_pll_power_op(tp, tp->pll_power_ops.down);
}
static void rtl_pll_power_up(struct rtl8169_private *tp)
{
rtl_pll_power_op(tp, tp->pll_power_ops.up);
}
static void __devinit rtl_init_pll_power_ops(struct rtl8169_private *tp)
{
struct pll_power_ops *ops = &tp->pll_power_ops;
switch (tp->mac_version) {
case RTL_GIGA_MAC_VER_07:
case RTL_GIGA_MAC_VER_08:
case RTL_GIGA_MAC_VER_09:
case RTL_GIGA_MAC_VER_10:
case RTL_GIGA_MAC_VER_16:
case RTL_GIGA_MAC_VER_29:
case RTL_GIGA_MAC_VER_30:
ops->down = r810x_pll_power_down;
ops->up = r810x_pll_power_up;
break;
case RTL_GIGA_MAC_VER_11:
case RTL_GIGA_MAC_VER_12:
case RTL_GIGA_MAC_VER_17:
case RTL_GIGA_MAC_VER_18:
case RTL_GIGA_MAC_VER_19:
case RTL_GIGA_MAC_VER_20:
case RTL_GIGA_MAC_VER_21:
case RTL_GIGA_MAC_VER_22:
case RTL_GIGA_MAC_VER_23:
case RTL_GIGA_MAC_VER_24:
case RTL_GIGA_MAC_VER_25:
case RTL_GIGA_MAC_VER_26:
case RTL_GIGA_MAC_VER_27:
case RTL_GIGA_MAC_VER_28:
case RTL_GIGA_MAC_VER_31:
case RTL_GIGA_MAC_VER_32:
case RTL_GIGA_MAC_VER_33:
ops->down = r8168_pll_power_down;
ops->up = r8168_pll_power_up;
break;
default:
ops->down = NULL;
ops->up = NULL;
break;
}
}
static void rtl_hw_reset(struct rtl8169_private *tp)
{
void __iomem *ioaddr = tp->mmio_addr;
int i;
RTL_W8(ChipCmd, CmdReset);
for (i = 0; i < 100; i++) {
if ((RTL_R8(ChipCmd) & CmdReset) == 0)
break;
msleep_interruptible(1);
}
}
static int __devinit
rtl8169_init_one(struct pci_dev *pdev, const struct pci_device_id *ent)
{
const struct rtl_cfg_info *cfg = rtl_cfg_infos + ent->driver_data;
const unsigned int region = cfg->region;
struct rtl8169_private *tp;
struct mii_if_info *mii;
struct net_device *dev;
void __iomem *ioaddr;
int chipset, i;
int rc;
if (netif_msg_drv(&debug)) {
printk(KERN_INFO "%s Gigabit Ethernet driver %s loaded\n",
MODULENAME, RTL8169_VERSION);
}
dev = alloc_etherdev(sizeof (*tp));
if (!dev) {
if (netif_msg_drv(&debug))
dev_err(&pdev->dev, "unable to alloc new ethernet\n");
rc = -ENOMEM;
goto out;
}
SET_NETDEV_DEV(dev, &pdev->dev);
dev->netdev_ops = &rtl8169_netdev_ops;
tp = netdev_priv(dev);
tp->dev = dev;
tp->pci_dev = pdev;
tp->msg_enable = netif_msg_init(debug.msg_enable, R8169_MSG_DEFAULT);
mii = &tp->mii;
mii->dev = dev;
mii->mdio_read = rtl_mdio_read;
mii->mdio_write = rtl_mdio_write;
mii->phy_id_mask = 0x1f;
mii->reg_num_mask = 0x1f;
mii->supports_gmii = !!(cfg->features & RTL_FEATURE_GMII);
pci_disable_link_state(pdev, PCIE_LINK_STATE_L0S | PCIE_LINK_STATE_L1 |
PCIE_LINK_STATE_CLKPM);
rc = pci_enable_device(pdev);
if (rc < 0) {
netif_err(tp, probe, dev, "enable failure\n");
goto err_out_free_dev_1;
}
if (pci_set_mwi(pdev) < 0)
netif_info(tp, probe, dev, "Mem-Wr-Inval unavailable\n");
if (!(pci_resource_flags(pdev, region) & IORESOURCE_MEM)) {
netif_err(tp, probe, dev,
"region #%d not an MMIO resource, aborting\n",
region);
rc = -ENODEV;
goto err_out_mwi_2;
}
if (pci_resource_len(pdev, region) < R8169_REGS_SIZE) {
netif_err(tp, probe, dev,
"Invalid PCI region size(s), aborting\n");
rc = -ENODEV;
goto err_out_mwi_2;
}
rc = pci_request_regions(pdev, MODULENAME);
if (rc < 0) {
netif_err(tp, probe, dev, "could not request regions\n");
goto err_out_mwi_2;
}
tp->cp_cmd = RxChkSum;
if ((sizeof(dma_addr_t) > 4) &&
!pci_set_dma_mask(pdev, DMA_BIT_MASK(64)) && use_dac) {
tp->cp_cmd |= PCIDAC;
dev->features |= NETIF_F_HIGHDMA;
} else {
rc = pci_set_dma_mask(pdev, DMA_BIT_MASK(32));
if (rc < 0) {
netif_err(tp, probe, dev, "DMA configuration failed\n");
goto err_out_free_res_3;
}
}
ioaddr = ioremap(pci_resource_start(pdev, region), R8169_REGS_SIZE);
if (!ioaddr) {
netif_err(tp, probe, dev, "cannot remap MMIO, aborting\n");
rc = -EIO;
goto err_out_free_res_3;
}
tp->mmio_addr = ioaddr;
tp->pcie_cap = pci_find_capability(pdev, PCI_CAP_ID_EXP);
if (!tp->pcie_cap)
netif_info(tp, probe, dev, "no PCI Express capability\n");
RTL_W16(IntrMask, 0x0000);
rtl_hw_reset(tp);
RTL_W16(IntrStatus, 0xffff);
pci_set_master(pdev);
rtl8169_get_mac_version(tp, dev, cfg->default_ver);
if (tp->mac_version == RTL_GIGA_MAC_VER_05)
tp->cp_cmd |= RxVlan;
rtl_init_mdio_ops(tp);
rtl_init_pll_power_ops(tp);
rtl8169_print_mac_version(tp);
chipset = tp->mac_version;
tp->txd_version = rtl_chip_infos[chipset].txd_version;
RTL_W8(Cfg9346, Cfg9346_Unlock);
RTL_W8(Config1, RTL_R8(Config1) | PMEnable);
RTL_W8(Config5, RTL_R8(Config5) & PMEStatus);
if ((RTL_R8(Config3) & (LinkUp | MagicPacket)) != 0)
tp->features |= RTL_FEATURE_WOL;
if ((RTL_R8(Config5) & (UWF | BWF | MWF)) != 0)
tp->features |= RTL_FEATURE_WOL;
tp->features |= rtl_try_msi(pdev, ioaddr, cfg);
RTL_W8(Cfg9346, Cfg9346_Lock);
if ((tp->mac_version <= RTL_GIGA_MAC_VER_06) &&
(RTL_R8(PHYstatus) & TBI_Enable)) {
tp->set_speed = rtl8169_set_speed_tbi;
tp->get_settings = rtl8169_gset_tbi;
tp->phy_reset_enable = rtl8169_tbi_reset_enable;
tp->phy_reset_pending = rtl8169_tbi_reset_pending;
tp->link_ok = rtl8169_tbi_link_ok;
tp->do_ioctl = rtl_tbi_ioctl;
} else {
tp->set_speed = rtl8169_set_speed_xmii;
tp->get_settings = rtl8169_gset_xmii;
tp->phy_reset_enable = rtl8169_xmii_reset_enable;
tp->phy_reset_pending = rtl8169_xmii_reset_pending;
tp->link_ok = rtl8169_xmii_link_ok;
tp->do_ioctl = rtl_xmii_ioctl;
}
spin_lock_init(&tp->lock);
for (i = 0; i < MAC_ADDR_LEN; i++)
dev->dev_addr[i] = RTL_R8(MAC0 + i);
memcpy(dev->perm_addr, dev->dev_addr, dev->addr_len);
SET_ETHTOOL_OPS(dev, &rtl8169_ethtool_ops);
dev->watchdog_timeo = RTL8169_TX_TIMEOUT;
dev->irq = pdev->irq;
dev->base_addr = (unsigned long) ioaddr;
netif_napi_add(dev, &tp->napi, rtl8169_poll, R8169_NAPI_WEIGHT);
dev->features |= NETIF_F_RXCSUM |
NETIF_F_HW_VLAN_TX | NETIF_F_HW_VLAN_RX;
dev->hw_features = NETIF_F_SG | NETIF_F_IP_CSUM | NETIF_F_TSO |
NETIF_F_RXCSUM | NETIF_F_HW_VLAN_TX | NETIF_F_HW_VLAN_RX;
dev->vlan_features = NETIF_F_SG | NETIF_F_IP_CSUM | NETIF_F_TSO |
NETIF_F_HIGHDMA;
if (tp->mac_version == RTL_GIGA_MAC_VER_05)
dev->hw_features &= ~NETIF_F_HW_VLAN_RX;
tp->intr_mask = 0xffff;
tp->hw_start = cfg->hw_start;
tp->intr_event = cfg->intr_event;
tp->napi_event = cfg->napi_event;
init_timer(&tp->timer);
tp->timer.data = (unsigned long) dev;
tp->timer.function = rtl8169_phy_timer;
tp->fw = RTL_FIRMWARE_UNKNOWN;
rc = register_netdev(dev);
if (rc < 0)
goto err_out_msi_4;
pci_set_drvdata(pdev, dev);
netif_info(tp, probe, dev, "%s at 0x%lx, %pM, XID %08x IRQ %d\n",
rtl_chip_infos[chipset].name, dev->base_addr, dev->dev_addr,
(u32)(RTL_R32(TxConfig) & 0x9cf0f8ff), dev->irq);
if (tp->mac_version == RTL_GIGA_MAC_VER_27 ||
tp->mac_version == RTL_GIGA_MAC_VER_28 ||
tp->mac_version == RTL_GIGA_MAC_VER_31) {
rtl8168_driver_start(tp);
}
device_set_wakeup_enable(&pdev->dev, tp->features & RTL_FEATURE_WOL);
if (pci_dev_run_wake(pdev))
pm_runtime_put_noidle(&pdev->dev);
netif_carrier_off(dev);
out:
return rc;
err_out_msi_4:
rtl_disable_msi(pdev, tp);
iounmap(ioaddr);
err_out_free_res_3:
pci_release_regions(pdev);
err_out_mwi_2:
pci_clear_mwi(pdev);
pci_disable_device(pdev);
err_out_free_dev_1:
free_netdev(dev);
goto out;
}
static void __devexit rtl8169_remove_one(struct pci_dev *pdev)
{
struct net_device *dev = pci_get_drvdata(pdev);
struct rtl8169_private *tp = netdev_priv(dev);
if (tp->mac_version == RTL_GIGA_MAC_VER_27 ||
tp->mac_version == RTL_GIGA_MAC_VER_28 ||
tp->mac_version == RTL_GIGA_MAC_VER_31) {
rtl8168_driver_stop(tp);
}
cancel_delayed_work_sync(&tp->task);
unregister_netdev(dev);
rtl_release_firmware(tp);
if (pci_dev_run_wake(pdev))
pm_runtime_get_noresume(&pdev->dev);
rtl_rar_set(tp, dev->perm_addr);
rtl_disable_msi(pdev, tp);
rtl8169_release_board(pdev, dev, tp->mmio_addr);
pci_set_drvdata(pdev, NULL);
}
static void rtl_request_firmware(struct rtl8169_private *tp)
{
if (IS_ERR(tp->fw)) {
const char *name;
name = rtl_lookup_firmware_name(tp);
if (name) {
int rc;
rc = request_firmware(&tp->fw, name, &tp->pci_dev->dev);
if (rc >= 0)
return;
netif_warn(tp, ifup, tp->dev, "unable to load "
"firmware patch %s (%d)\n", name, rc);
}
tp->fw = NULL;
}
}
static int rtl8169_open(struct net_device *dev)
{
struct rtl8169_private *tp = netdev_priv(dev);
void __iomem *ioaddr = tp->mmio_addr;
struct pci_dev *pdev = tp->pci_dev;
int retval = -ENOMEM;
pm_runtime_get_sync(&pdev->dev);
tp->TxDescArray = dma_alloc_coherent(&pdev->dev, R8169_TX_RING_BYTES,
&tp->TxPhyAddr, GFP_KERNEL);
if (!tp->TxDescArray)
goto err_pm_runtime_put;
tp->RxDescArray = dma_alloc_coherent(&pdev->dev, R8169_RX_RING_BYTES,
&tp->RxPhyAddr, GFP_KERNEL);
if (!tp->RxDescArray)
goto err_free_tx_0;
retval = rtl8169_init_ring(dev);
if (retval < 0)
goto err_free_rx_1;
INIT_DELAYED_WORK(&tp->task, NULL);
smp_mb();
rtl_request_firmware(tp);
retval = request_irq(dev->irq, rtl8169_interrupt,
(tp->features & RTL_FEATURE_MSI) ? 0 : IRQF_SHARED,
dev->name, dev);
if (retval < 0)
goto err_release_fw_2;
napi_enable(&tp->napi);
rtl8169_init_phy(dev, tp);
rtl8169_set_features(dev, dev->features);
rtl_pll_power_up(tp);
rtl_hw_start(dev);
tp->saved_wolopts = 0;
pm_runtime_put_noidle(&pdev->dev);
rtl8169_check_link_status(dev, tp, ioaddr);
out:
return retval;
err_release_fw_2:
rtl_release_firmware(tp);
rtl8169_rx_clear(tp);
err_free_rx_1:
dma_free_coherent(&pdev->dev, R8169_RX_RING_BYTES, tp->RxDescArray,
tp->RxPhyAddr);
tp->RxDescArray = NULL;
err_free_tx_0:
dma_free_coherent(&pdev->dev, R8169_TX_RING_BYTES, tp->TxDescArray,
tp->TxPhyAddr);
tp->TxDescArray = NULL;
err_pm_runtime_put:
pm_runtime_put_noidle(&pdev->dev);
goto out;
}
static void rtl8169_hw_reset(struct rtl8169_private *tp)
{
void __iomem *ioaddr = tp->mmio_addr;
rtl8169_irq_mask_and_ack(ioaddr);
if (tp->mac_version == RTL_GIGA_MAC_VER_27 ||
tp->mac_version == RTL_GIGA_MAC_VER_28 ||
tp->mac_version == RTL_GIGA_MAC_VER_31) {
while (RTL_R8(TxPoll) & NPQ)
udelay(20);
}
RTL_W8(ChipCmd, CmdReset);
RTL_R8(ChipCmd);
}
static void rtl_set_rx_tx_config_registers(struct rtl8169_private *tp)
{
void __iomem *ioaddr = tp->mmio_addr;
u32 cfg = rtl8169_rx_config;
cfg |= (RTL_R32(RxConfig) & RTL_RX_CONFIG_MASK);
RTL_W32(RxConfig, cfg);
RTL_W32(TxConfig, (TX_DMA_BURST << TxDMAShift) |
(InterFrameGap << TxInterFrameGapShift));
}
static void rtl_hw_start(struct net_device *dev)
{
struct rtl8169_private *tp = netdev_priv(dev);
rtl_hw_reset(tp);
tp->hw_start(dev);
netif_start_queue(dev);
}
static void rtl_set_rx_tx_desc_registers(struct rtl8169_private *tp,
void __iomem *ioaddr)
{
RTL_W32(TxDescStartAddrHigh, ((u64) tp->TxPhyAddr) >> 32);
RTL_W32(TxDescStartAddrLow, ((u64) tp->TxPhyAddr) & DMA_BIT_MASK(32));
RTL_W32(RxDescAddrHigh, ((u64) tp->RxPhyAddr) >> 32);
RTL_W32(RxDescAddrLow, ((u64) tp->RxPhyAddr) & DMA_BIT_MASK(32));
}
static u16 rtl_rw_cpluscmd(void __iomem *ioaddr)
{
u16 cmd;
cmd = RTL_R16(CPlusCmd);
RTL_W16(CPlusCmd, cmd);
return cmd;
}
static void rtl_set_rx_max_size(void __iomem *ioaddr, unsigned int rx_buf_sz)
{
RTL_W16(RxMaxSize, rx_buf_sz + 1);
}
static void rtl8169_set_magic_reg(void __iomem *ioaddr, unsigned mac_version)
{
static const struct rtl_cfg2_info {
u32 mac_version;
u32 clk;
u32 val;
} cfg2_info [] = {
{ RTL_GIGA_MAC_VER_05, PCI_Clock_33MHz, 0x000fff00 },
{ RTL_GIGA_MAC_VER_05, PCI_Clock_66MHz, 0x000fffff },
{ RTL_GIGA_MAC_VER_06, PCI_Clock_33MHz, 0x00ffff00 },
{ RTL_GIGA_MAC_VER_06, PCI_Clock_66MHz, 0x00ffffff }
};
const struct rtl_cfg2_info *p = cfg2_info;
unsigned int i;
u32 clk;
clk = RTL_R8(Config2) & PCI_Clock_66MHz;
for (i = 0; i < ARRAY_SIZE(cfg2_info); i++, p++) {
if ((p->mac_version == mac_version) && (p->clk == clk)) {
RTL_W32(0x7c, p->val);
break;
}
}
}
static void rtl_hw_start_8169(struct net_device *dev)
{
struct rtl8169_private *tp = netdev_priv(dev);
void __iomem *ioaddr = tp->mmio_addr;
struct pci_dev *pdev = tp->pci_dev;
if (tp->mac_version == RTL_GIGA_MAC_VER_05) {
RTL_W16(CPlusCmd, RTL_R16(CPlusCmd) | PCIMulRW);
pci_write_config_byte(pdev, PCI_CACHE_LINE_SIZE, 0x08);
}
RTL_W8(Cfg9346, Cfg9346_Unlock);
if (tp->mac_version == RTL_GIGA_MAC_VER_01 ||
tp->mac_version == RTL_GIGA_MAC_VER_02 ||
tp->mac_version == RTL_GIGA_MAC_VER_03 ||
tp->mac_version == RTL_GIGA_MAC_VER_04)
RTL_W8(ChipCmd, CmdTxEnb | CmdRxEnb);
RTL_W8(EarlyTxThres, NoEarlyTx);
rtl_set_rx_max_size(ioaddr, rx_buf_sz);
if (tp->mac_version == RTL_GIGA_MAC_VER_01 ||
tp->mac_version == RTL_GIGA_MAC_VER_02 ||
tp->mac_version == RTL_GIGA_MAC_VER_03 ||
tp->mac_version == RTL_GIGA_MAC_VER_04)
rtl_set_rx_tx_config_registers(tp);
tp->cp_cmd |= rtl_rw_cpluscmd(ioaddr) | PCIMulRW;
if (tp->mac_version == RTL_GIGA_MAC_VER_02 ||
tp->mac_version == RTL_GIGA_MAC_VER_03) {
dprintk("Set MAC Reg C+CR Offset 0xE0. "
"Bit-3 and bit-14 MUST be 1\n");
tp->cp_cmd |= (1 << 14);
}
RTL_W16(CPlusCmd, tp->cp_cmd);
rtl8169_set_magic_reg(ioaddr, tp->mac_version);
RTL_W16(IntrMitigate, 0x0000);
rtl_set_rx_tx_desc_registers(tp, ioaddr);
if (tp->mac_version != RTL_GIGA_MAC_VER_01 &&
tp->mac_version != RTL_GIGA_MAC_VER_02 &&
tp->mac_version != RTL_GIGA_MAC_VER_03 &&
tp->mac_version != RTL_GIGA_MAC_VER_04) {
RTL_W8(ChipCmd, CmdTxEnb | CmdRxEnb);
rtl_set_rx_tx_config_registers(tp);
}
RTL_W8(Cfg9346, Cfg9346_Lock);
RTL_R8(IntrMask);
RTL_W32(RxMissed, 0);
rtl_set_rx_mode(dev);
RTL_W16(MultiIntr, RTL_R16(MultiIntr) & 0xF000);
RTL_W16(IntrMask, tp->intr_event);
}
static void rtl_tx_performance_tweak(struct pci_dev *pdev, u16 force)
{
struct net_device *dev = pci_get_drvdata(pdev);
struct rtl8169_private *tp = netdev_priv(dev);
int cap = tp->pcie_cap;
if (cap) {
u16 ctl;
pci_read_config_word(pdev, cap + PCI_EXP_DEVCTL, &ctl);
ctl = (ctl & ~PCI_EXP_DEVCTL_READRQ) | force;
pci_write_config_word(pdev, cap + PCI_EXP_DEVCTL, ctl);
}
}
static void rtl_csi_access_enable(void __iomem *ioaddr, u32 bits)
{
u32 csi;
csi = rtl_csi_read(ioaddr, 0x070c) & 0x00ffffff;
rtl_csi_write(ioaddr, 0x070c, csi | bits);
}
static void rtl_csi_access_enable_1(void __iomem *ioaddr)
{
rtl_csi_access_enable(ioaddr, 0x17000000);
}
static void rtl_csi_access_enable_2(void __iomem *ioaddr)
{
rtl_csi_access_enable(ioaddr, 0x27000000);
}
static void rtl_ephy_init(void __iomem *ioaddr, const struct ephy_info *e, int len)
{
u16 w;
while (len-- > 0) {
w = (rtl_ephy_read(ioaddr, e->offset) & ~e->mask) | e->bits;
rtl_ephy_write(ioaddr, e->offset, w);
e++;
}
}
static void rtl_disable_clock_request(struct pci_dev *pdev)
{
struct net_device *dev = pci_get_drvdata(pdev);
struct rtl8169_private *tp = netdev_priv(dev);
int cap = tp->pcie_cap;
if (cap) {
u16 ctl;
pci_read_config_word(pdev, cap + PCI_EXP_LNKCTL, &ctl);
ctl &= ~PCI_EXP_LNKCTL_CLKREQ_EN;
pci_write_config_word(pdev, cap + PCI_EXP_LNKCTL, ctl);
}
}
static void rtl_enable_clock_request(struct pci_dev *pdev)
{
struct net_device *dev = pci_get_drvdata(pdev);
struct rtl8169_private *tp = netdev_priv(dev);
int cap = tp->pcie_cap;
if (cap) {
u16 ctl;
pci_read_config_word(pdev, cap + PCI_EXP_LNKCTL, &ctl);
ctl |= PCI_EXP_LNKCTL_CLKREQ_EN;
pci_write_config_word(pdev, cap + PCI_EXP_LNKCTL, ctl);
}
}
static void rtl_hw_start_8168bb(void __iomem *ioaddr, struct pci_dev *pdev)
{
RTL_W8(Config3, RTL_R8(Config3) & ~Beacon_en);
RTL_W16(CPlusCmd, RTL_R16(CPlusCmd) & ~R8168_CPCMD_QUIRK_MASK);
rtl_tx_performance_tweak(pdev,
(0x5 << MAX_READ_REQUEST_SHIFT) | PCI_EXP_DEVCTL_NOSNOOP_EN);
}
static void rtl_hw_start_8168bef(void __iomem *ioaddr, struct pci_dev *pdev)
{
rtl_hw_start_8168bb(ioaddr, pdev);
RTL_W8(MaxTxPacketSize, TxPacketMax);
RTL_W8(Config4, RTL_R8(Config4) & ~(1 << 0));
}
static void __rtl_hw_start_8168cp(void __iomem *ioaddr, struct pci_dev *pdev)
{
RTL_W8(Config1, RTL_R8(Config1) | Speed_down);
RTL_W8(Config3, RTL_R8(Config3) & ~Beacon_en);
rtl_tx_performance_tweak(pdev, 0x5 << MAX_READ_REQUEST_SHIFT);
rtl_disable_clock_request(pdev);
RTL_W16(CPlusCmd, RTL_R16(CPlusCmd) & ~R8168_CPCMD_QUIRK_MASK);
}
static void rtl_hw_start_8168cp_1(void __iomem *ioaddr, struct pci_dev *pdev)
{
static const struct ephy_info e_info_8168cp[] = {
{ 0x01, 0, 0x0001 },
{ 0x02, 0x0800, 0x1000 },
{ 0x03, 0, 0x0042 },
{ 0x06, 0x0080, 0x0000 },
{ 0x07, 0, 0x2000 }
};
rtl_csi_access_enable_2(ioaddr);
rtl_ephy_init(ioaddr, e_info_8168cp, ARRAY_SIZE(e_info_8168cp));
__rtl_hw_start_8168cp(ioaddr, pdev);
}
static void rtl_hw_start_8168cp_2(void __iomem *ioaddr, struct pci_dev *pdev)
{
rtl_csi_access_enable_2(ioaddr);
RTL_W8(Config3, RTL_R8(Config3) & ~Beacon_en);
rtl_tx_performance_tweak(pdev, 0x5 << MAX_READ_REQUEST_SHIFT);
RTL_W16(CPlusCmd, RTL_R16(CPlusCmd) & ~R8168_CPCMD_QUIRK_MASK);
}
static void rtl_hw_start_8168cp_3(void __iomem *ioaddr, struct pci_dev *pdev)
{
rtl_csi_access_enable_2(ioaddr);
RTL_W8(Config3, RTL_R8(Config3) & ~Beacon_en);
RTL_W8(DBG_REG, 0x20);
RTL_W8(MaxTxPacketSize, TxPacketMax);
rtl_tx_performance_tweak(pdev, 0x5 << MAX_READ_REQUEST_SHIFT);
RTL_W16(CPlusCmd, RTL_R16(CPlusCmd) & ~R8168_CPCMD_QUIRK_MASK);
}
static void rtl_hw_start_8168c_1(void __iomem *ioaddr, struct pci_dev *pdev)
{
static const struct ephy_info e_info_8168c_1[] = {
{ 0x02, 0x0800, 0x1000 },
{ 0x03, 0, 0x0002 },
{ 0x06, 0x0080, 0x0000 }
};
rtl_csi_access_enable_2(ioaddr);
RTL_W8(DBG_REG, 0x06 | FIX_NAK_1 | FIX_NAK_2);
rtl_ephy_init(ioaddr, e_info_8168c_1, ARRAY_SIZE(e_info_8168c_1));
__rtl_hw_start_8168cp(ioaddr, pdev);
}
static void rtl_hw_start_8168c_2(void __iomem *ioaddr, struct pci_dev *pdev)
{
static const struct ephy_info e_info_8168c_2[] = {
{ 0x01, 0, 0x0001 },
{ 0x03, 0x0400, 0x0220 }
};
rtl_csi_access_enable_2(ioaddr);
rtl_ephy_init(ioaddr, e_info_8168c_2, ARRAY_SIZE(e_info_8168c_2));
__rtl_hw_start_8168cp(ioaddr, pdev);
}
static void rtl_hw_start_8168c_3(void __iomem *ioaddr, struct pci_dev *pdev)
{
rtl_hw_start_8168c_2(ioaddr, pdev);
}
static void rtl_hw_start_8168c_4(void __iomem *ioaddr, struct pci_dev *pdev)
{
rtl_csi_access_enable_2(ioaddr);
__rtl_hw_start_8168cp(ioaddr, pdev);
}
static void rtl_hw_start_8168d(void __iomem *ioaddr, struct pci_dev *pdev)
{
rtl_csi_access_enable_2(ioaddr);
rtl_disable_clock_request(pdev);
RTL_W8(MaxTxPacketSize, TxPacketMax);
rtl_tx_performance_tweak(pdev, 0x5 << MAX_READ_REQUEST_SHIFT);
RTL_W16(CPlusCmd, RTL_R16(CPlusCmd) & ~R8168_CPCMD_QUIRK_MASK);
}
static void rtl_hw_start_8168dp(void __iomem *ioaddr, struct pci_dev *pdev)
{
rtl_csi_access_enable_1(ioaddr);
rtl_tx_performance_tweak(pdev, 0x5 << MAX_READ_REQUEST_SHIFT);
RTL_W8(MaxTxPacketSize, TxPacketMax);
rtl_disable_clock_request(pdev);
}
static void rtl_hw_start_8168d_4(void __iomem *ioaddr, struct pci_dev *pdev)
{
static const struct ephy_info e_info_8168d_4[] = {
{ 0x0b, ~0, 0x48 },
{ 0x19, 0x20, 0x50 },
{ 0x0c, ~0, 0x20 }
};
int i;
rtl_csi_access_enable_1(ioaddr);
rtl_tx_performance_tweak(pdev, 0x5 << MAX_READ_REQUEST_SHIFT);
RTL_W8(MaxTxPacketSize, TxPacketMax);
for (i = 0; i < ARRAY_SIZE(e_info_8168d_4); i++) {
const struct ephy_info *e = e_info_8168d_4 + i;
u16 w;
w = rtl_ephy_read(ioaddr, e->offset);
rtl_ephy_write(ioaddr, 0x03, (w & e->mask) | e->bits);
}
rtl_enable_clock_request(pdev);
}
static void rtl_hw_start_8168e(void __iomem *ioaddr, struct pci_dev *pdev)
{
static const struct ephy_info e_info_8168e[] = {
{ 0x00, 0x0200, 0x0100 },
{ 0x00, 0x0000, 0x0004 },
{ 0x06, 0x0002, 0x0001 },
{ 0x06, 0x0000, 0x0030 },
{ 0x07, 0x0000, 0x2000 },
{ 0x00, 0x0000, 0x0020 },
{ 0x03, 0x5800, 0x2000 },
{ 0x03, 0x0000, 0x0001 },
{ 0x01, 0x0800, 0x1000 },
{ 0x07, 0x0000, 0x4000 },
{ 0x1e, 0x0000, 0x2000 },
{ 0x19, 0xffff, 0xfe6c },
{ 0x0a, 0x0000, 0x0040 }
};
rtl_csi_access_enable_2(ioaddr);
rtl_ephy_init(ioaddr, e_info_8168e, ARRAY_SIZE(e_info_8168e));
rtl_tx_performance_tweak(pdev, 0x5 << MAX_READ_REQUEST_SHIFT);
RTL_W8(MaxTxPacketSize, TxPacketMax);
rtl_disable_clock_request(pdev);
RTL_W32(MISC, RTL_R32(MISC) | TXPLA_RST);
RTL_W32(MISC, RTL_R32(MISC) & ~TXPLA_RST);
RTL_W8(Config5, RTL_R8(Config5) & ~Spi_en);
}
static void rtl_hw_start_8168(struct net_device *dev)
{
struct rtl8169_private *tp = netdev_priv(dev);
void __iomem *ioaddr = tp->mmio_addr;
struct pci_dev *pdev = tp->pci_dev;
RTL_W8(Cfg9346, Cfg9346_Unlock);
RTL_W8(MaxTxPacketSize, TxPacketMax);
rtl_set_rx_max_size(ioaddr, rx_buf_sz);
tp->cp_cmd |= RTL_R16(CPlusCmd) | PktCntrDisable | INTT_1;
RTL_W16(CPlusCmd, tp->cp_cmd);
RTL_W16(IntrMitigate, 0x5151);
if (tp->mac_version == RTL_GIGA_MAC_VER_11 ||
tp->mac_version == RTL_GIGA_MAC_VER_22) {
tp->intr_event |= RxFIFOOver | PCSTimeout;
tp->intr_event &= ~RxOverflow;
}
rtl_set_rx_tx_desc_registers(tp, ioaddr);
rtl_set_rx_mode(dev);
RTL_W32(TxConfig, (TX_DMA_BURST << TxDMAShift) |
(InterFrameGap << TxInterFrameGapShift));
RTL_R8(IntrMask);
switch (tp->mac_version) {
case RTL_GIGA_MAC_VER_11:
rtl_hw_start_8168bb(ioaddr, pdev);
break;
case RTL_GIGA_MAC_VER_12:
case RTL_GIGA_MAC_VER_17:
rtl_hw_start_8168bef(ioaddr, pdev);
break;
case RTL_GIGA_MAC_VER_18:
rtl_hw_start_8168cp_1(ioaddr, pdev);
break;
case RTL_GIGA_MAC_VER_19:
rtl_hw_start_8168c_1(ioaddr, pdev);
break;
case RTL_GIGA_MAC_VER_20:
rtl_hw_start_8168c_2(ioaddr, pdev);
break;
case RTL_GIGA_MAC_VER_21:
rtl_hw_start_8168c_3(ioaddr, pdev);
break;
case RTL_GIGA_MAC_VER_22:
rtl_hw_start_8168c_4(ioaddr, pdev);
break;
case RTL_GIGA_MAC_VER_23:
rtl_hw_start_8168cp_2(ioaddr, pdev);
break;
case RTL_GIGA_MAC_VER_24:
rtl_hw_start_8168cp_3(ioaddr, pdev);
break;
case RTL_GIGA_MAC_VER_25:
case RTL_GIGA_MAC_VER_26:
case RTL_GIGA_MAC_VER_27:
rtl_hw_start_8168d(ioaddr, pdev);
break;
case RTL_GIGA_MAC_VER_28:
rtl_hw_start_8168d_4(ioaddr, pdev);
break;
case RTL_GIGA_MAC_VER_31:
rtl_hw_start_8168dp(ioaddr, pdev);
break;
case RTL_GIGA_MAC_VER_32:
case RTL_GIGA_MAC_VER_33:
rtl_hw_start_8168e(ioaddr, pdev);
break;
default:
printk(KERN_ERR PFX "%s: unknown chipset (mac_version = %d).\n",
dev->name, tp->mac_version);
break;
}
RTL_W8(ChipCmd, CmdTxEnb | CmdRxEnb);
RTL_W8(Cfg9346, Cfg9346_Lock);
RTL_W16(MultiIntr, RTL_R16(MultiIntr) & 0xF000);
RTL_W16(IntrMask, tp->intr_event);
}
static void rtl_hw_start_8102e_1(void __iomem *ioaddr, struct pci_dev *pdev)
{
static const struct ephy_info e_info_8102e_1[] = {
{ 0x01, 0, 0x6e65 },
{ 0x02, 0, 0x091f },
{ 0x03, 0, 0xc2f9 },
{ 0x06, 0, 0xafb5 },
{ 0x07, 0, 0x0e00 },
{ 0x19, 0, 0xec80 },
{ 0x01, 0, 0x2e65 },
{ 0x01, 0, 0x6e65 }
};
u8 cfg1;
rtl_csi_access_enable_2(ioaddr);
RTL_W8(DBG_REG, FIX_NAK_1);
rtl_tx_performance_tweak(pdev, 0x5 << MAX_READ_REQUEST_SHIFT);
RTL_W8(Config1,
LEDS1 | LEDS0 | Speed_down | MEMMAP | IOMAP | VPD | PMEnable);
RTL_W8(Config3, RTL_R8(Config3) & ~Beacon_en);
cfg1 = RTL_R8(Config1);
if ((cfg1 & LEDS0) && (cfg1 & LEDS1))
RTL_W8(Config1, cfg1 & ~LEDS0);
rtl_ephy_init(ioaddr, e_info_8102e_1, ARRAY_SIZE(e_info_8102e_1));
}
static void rtl_hw_start_8102e_2(void __iomem *ioaddr, struct pci_dev *pdev)
{
rtl_csi_access_enable_2(ioaddr);
rtl_tx_performance_tweak(pdev, 0x5 << MAX_READ_REQUEST_SHIFT);
RTL_W8(Config1, MEMMAP | IOMAP | VPD | PMEnable);
RTL_W8(Config3, RTL_R8(Config3) & ~Beacon_en);
}
static void rtl_hw_start_8102e_3(void __iomem *ioaddr, struct pci_dev *pdev)
{
rtl_hw_start_8102e_2(ioaddr, pdev);
rtl_ephy_write(ioaddr, 0x03, 0xc2f9);
}
static void rtl_hw_start_8105e_1(void __iomem *ioaddr, struct pci_dev *pdev)
{
static const struct ephy_info e_info_8105e_1[] = {
{ 0x07, 0, 0x4000 },
{ 0x19, 0, 0x0200 },
{ 0x19, 0, 0x0020 },
{ 0x1e, 0, 0x2000 },
{ 0x03, 0, 0x0001 },
{ 0x19, 0, 0x0100 },
{ 0x19, 0, 0x0004 },
{ 0x0a, 0, 0x0020 }
};
RTL_W32(FuncEvent, RTL_R32(FuncEvent) | 0x002800);
RTL_W32(FuncEvent, RTL_R32(FuncEvent) & ~0x010000);
RTL_W8(MCU, RTL_R8(MCU) | EN_NDP | EN_OOB_RESET);
RTL_W8(DLLPR, RTL_R8(DLLPR) | PM_SWITCH);
rtl_ephy_init(ioaddr, e_info_8105e_1, ARRAY_SIZE(e_info_8105e_1));
}
static void rtl_hw_start_8105e_2(void __iomem *ioaddr, struct pci_dev *pdev)
{
rtl_hw_start_8105e_1(ioaddr, pdev);
rtl_ephy_write(ioaddr, 0x1e, rtl_ephy_read(ioaddr, 0x1e) | 0x8000);
}
static void rtl_hw_start_8101(struct net_device *dev)
{
struct rtl8169_private *tp = netdev_priv(dev);
void __iomem *ioaddr = tp->mmio_addr;
struct pci_dev *pdev = tp->pci_dev;
if (tp->mac_version == RTL_GIGA_MAC_VER_13 ||
tp->mac_version == RTL_GIGA_MAC_VER_16) {
int cap = tp->pcie_cap;
if (cap) {
pci_write_config_word(pdev, cap + PCI_EXP_DEVCTL,
PCI_EXP_DEVCTL_NOSNOOP_EN);
}
}
RTL_W8(Cfg9346, Cfg9346_Unlock);
switch (tp->mac_version) {
case RTL_GIGA_MAC_VER_07:
rtl_hw_start_8102e_1(ioaddr, pdev);
break;
case RTL_GIGA_MAC_VER_08:
rtl_hw_start_8102e_3(ioaddr, pdev);
break;
case RTL_GIGA_MAC_VER_09:
rtl_hw_start_8102e_2(ioaddr, pdev);
break;
case RTL_GIGA_MAC_VER_29:
rtl_hw_start_8105e_1(ioaddr, pdev);
break;
case RTL_GIGA_MAC_VER_30:
rtl_hw_start_8105e_2(ioaddr, pdev);
break;
}
RTL_W8(Cfg9346, Cfg9346_Lock);
RTL_W8(MaxTxPacketSize, TxPacketMax);
rtl_set_rx_max_size(ioaddr, rx_buf_sz);
tp->cp_cmd &= ~R810X_CPCMD_QUIRK_MASK;
RTL_W16(CPlusCmd, tp->cp_cmd);
RTL_W16(IntrMitigate, 0x0000);
rtl_set_rx_tx_desc_registers(tp, ioaddr);
RTL_W8(ChipCmd, CmdTxEnb | CmdRxEnb);
rtl_set_rx_tx_config_registers(tp);
RTL_R8(IntrMask);
rtl_set_rx_mode(dev);
RTL_W16(MultiIntr, RTL_R16(MultiIntr) & 0xf000);
RTL_W16(IntrMask, tp->intr_event);
}
static int rtl8169_change_mtu(struct net_device *dev, int new_mtu)
{
if (new_mtu < ETH_ZLEN || new_mtu > SafeMtu)
return -EINVAL;
dev->mtu = new_mtu;
netdev_update_features(dev);
return 0;
}
static inline void rtl8169_make_unusable_by_asic(struct RxDesc *desc)
{
desc->addr = cpu_to_le64(0x0badbadbadbadbadull);
desc->opts1 &= ~cpu_to_le32(DescOwn | RsvdMask);
}
static void rtl8169_free_rx_databuff(struct rtl8169_private *tp,
void **data_buff, struct RxDesc *desc)
{
dma_unmap_single(&tp->pci_dev->dev, le64_to_cpu(desc->addr), rx_buf_sz,
DMA_FROM_DEVICE);
kfree(*data_buff);
*data_buff = NULL;
rtl8169_make_unusable_by_asic(desc);
}
static inline void rtl8169_mark_to_asic(struct RxDesc *desc, u32 rx_buf_sz)
{
u32 eor = le32_to_cpu(desc->opts1) & RingEnd;
desc->opts1 = cpu_to_le32(DescOwn | eor | rx_buf_sz);
}
static inline void rtl8169_map_to_asic(struct RxDesc *desc, dma_addr_t mapping,
u32 rx_buf_sz)
{
desc->addr = cpu_to_le64(mapping);
wmb();
rtl8169_mark_to_asic(desc, rx_buf_sz);
}
static inline void *rtl8169_align(void *data)
{
return (void *)ALIGN((long)data, 16);
}
static struct sk_buff *rtl8169_alloc_rx_data(struct rtl8169_private *tp,
struct RxDesc *desc)
{
void *data;
dma_addr_t mapping;
struct device *d = &tp->pci_dev->dev;
struct net_device *dev = tp->dev;
int node = dev->dev.parent ? dev_to_node(dev->dev.parent) : -1;
data = kmalloc_node(rx_buf_sz, GFP_KERNEL, node);
if (!data)
return NULL;
if (rtl8169_align(data) != data) {
kfree(data);
data = kmalloc_node(rx_buf_sz + 15, GFP_KERNEL, node);
if (!data)
return NULL;
}
mapping = dma_map_single(d, rtl8169_align(data), rx_buf_sz,
DMA_FROM_DEVICE);
if (unlikely(dma_mapping_error(d, mapping))) {
if (net_ratelimit())
netif_err(tp, drv, tp->dev, "Failed to map RX DMA!\n");
goto err_out;
}
rtl8169_map_to_asic(desc, mapping, rx_buf_sz);
return data;
err_out:
kfree(data);
return NULL;
}
static void rtl8169_rx_clear(struct rtl8169_private *tp)
{
unsigned int i;
for (i = 0; i < NUM_RX_DESC; i++) {
if (tp->Rx_databuff[i]) {
rtl8169_free_rx_databuff(tp, tp->Rx_databuff + i,
tp->RxDescArray + i);
}
}
}
static inline void rtl8169_mark_as_last_descriptor(struct RxDesc *desc)
{
desc->opts1 |= cpu_to_le32(RingEnd);
}
static int rtl8169_rx_fill(struct rtl8169_private *tp)
{
unsigned int i;
for (i = 0; i < NUM_RX_DESC; i++) {
void *data;
if (tp->Rx_databuff[i])
continue;
data = rtl8169_alloc_rx_data(tp, tp->RxDescArray + i);
if (!data) {
rtl8169_make_unusable_by_asic(tp->RxDescArray + i);
goto err_out;
}
tp->Rx_databuff[i] = data;
}
rtl8169_mark_as_last_descriptor(tp->RxDescArray + NUM_RX_DESC - 1);
return 0;
err_out:
rtl8169_rx_clear(tp);
return -ENOMEM;
}
static void rtl8169_init_ring_indexes(struct rtl8169_private *tp)
{
tp->dirty_tx = tp->dirty_rx = tp->cur_tx = tp->cur_rx = 0;
}
static int rtl8169_init_ring(struct net_device *dev)
{
struct rtl8169_private *tp = netdev_priv(dev);
rtl8169_init_ring_indexes(tp);
memset(tp->tx_skb, 0x0, NUM_TX_DESC * sizeof(struct ring_info));
memset(tp->Rx_databuff, 0x0, NUM_RX_DESC * sizeof(void *));
return rtl8169_rx_fill(tp);
}
static void rtl8169_unmap_tx_skb(struct device *d, struct ring_info *tx_skb,
struct TxDesc *desc)
{
unsigned int len = tx_skb->len;
dma_unmap_single(d, le64_to_cpu(desc->addr), len, DMA_TO_DEVICE);
desc->opts1 = 0x00;
desc->opts2 = 0x00;
desc->addr = 0x00;
tx_skb->len = 0;
}
static void rtl8169_tx_clear_range(struct rtl8169_private *tp, u32 start,
unsigned int n)
{
unsigned int i;
for (i = 0; i < n; i++) {
unsigned int entry = (start + i) % NUM_TX_DESC;
struct ring_info *tx_skb = tp->tx_skb + entry;
unsigned int len = tx_skb->len;
if (len) {
struct sk_buff *skb = tx_skb->skb;
rtl8169_unmap_tx_skb(&tp->pci_dev->dev, tx_skb,
tp->TxDescArray + entry);
if (skb) {
tp->dev->stats.tx_dropped++;
dev_kfree_skb(skb);
tx_skb->skb = NULL;
}
}
}
}
static void rtl8169_tx_clear(struct rtl8169_private *tp)
{
rtl8169_tx_clear_range(tp, tp->dirty_tx, NUM_TX_DESC);
tp->cur_tx = tp->dirty_tx = 0;
}
static void rtl8169_schedule_work(struct net_device *dev, work_func_t task)
{
struct rtl8169_private *tp = netdev_priv(dev);
PREPARE_DELAYED_WORK(&tp->task, task);
schedule_delayed_work(&tp->task, 4);
}
static void rtl8169_wait_for_quiescence(struct net_device *dev)
{
struct rtl8169_private *tp = netdev_priv(dev);
void __iomem *ioaddr = tp->mmio_addr;
synchronize_irq(dev->irq);
napi_disable(&tp->napi);
rtl8169_irq_mask_and_ack(ioaddr);
tp->intr_mask = 0xffff;
RTL_W16(IntrMask, tp->intr_event);
napi_enable(&tp->napi);
}
static void rtl8169_reinit_task(struct work_struct *work)
{
struct rtl8169_private *tp =
container_of(work, struct rtl8169_private, task.work);
struct net_device *dev = tp->dev;
int ret;
rtnl_lock();
if (!netif_running(dev))
goto out_unlock;
rtl8169_wait_for_quiescence(dev);
rtl8169_close(dev);
ret = rtl8169_open(dev);
if (unlikely(ret < 0)) {
if (net_ratelimit())
netif_err(tp, drv, dev,
"reinit failure (status = %d). Rescheduling\n",
ret);
rtl8169_schedule_work(dev, rtl8169_reinit_task);
}
out_unlock:
rtnl_unlock();
}
static void rtl8169_reset_task(struct work_struct *work)
{
struct rtl8169_private *tp =
container_of(work, struct rtl8169_private, task.work);
struct net_device *dev = tp->dev;
int i;
rtnl_lock();
if (!netif_running(dev))
goto out_unlock;
rtl8169_wait_for_quiescence(dev);
for (i = 0; i < NUM_RX_DESC; i++)
rtl8169_mark_to_asic(tp->RxDescArray + i, rx_buf_sz);
rtl8169_tx_clear(tp);
rtl8169_init_ring_indexes(tp);
rtl_hw_start(dev);
netif_wake_queue(dev);
rtl8169_check_link_status(dev, tp, tp->mmio_addr);
out_unlock:
rtnl_unlock();
}
static void rtl8169_tx_timeout(struct net_device *dev)
{
struct rtl8169_private *tp = netdev_priv(dev);
rtl8169_hw_reset(tp);
rtl8169_schedule_work(dev, rtl8169_reset_task);
}
static int rtl8169_xmit_frags(struct rtl8169_private *tp, struct sk_buff *skb,
u32 *opts)
{
struct skb_shared_info *info = skb_shinfo(skb);
unsigned int cur_frag, entry;
struct TxDesc * uninitialized_var(txd);
struct device *d = &tp->pci_dev->dev;
entry = tp->cur_tx;
for (cur_frag = 0; cur_frag < info->nr_frags; cur_frag++) {
skb_frag_t *frag = info->frags + cur_frag;
dma_addr_t mapping;
u32 status, len;
void *addr;
entry = (entry + 1) % NUM_TX_DESC;
txd = tp->TxDescArray + entry;
len = frag->size;
addr = ((void *) page_address(frag->page)) + frag->page_offset;
mapping = dma_map_single(d, addr, len, DMA_TO_DEVICE);
if (unlikely(dma_mapping_error(d, mapping))) {
if (net_ratelimit())
netif_err(tp, drv, tp->dev,
"Failed to map TX fragments DMA!\n");
goto err_out;
}
status = opts[0] | len |
(RingEnd * !((entry + 1) % NUM_TX_DESC));
txd->opts1 = cpu_to_le32(status);
txd->opts2 = cpu_to_le32(opts[1]);
txd->addr = cpu_to_le64(mapping);
tp->tx_skb[entry].len = len;
}
if (cur_frag) {
tp->tx_skb[entry].skb = skb;
txd->opts1 |= cpu_to_le32(LastFrag);
}
return cur_frag;
err_out:
rtl8169_tx_clear_range(tp, tp->cur_tx + 1, cur_frag);
return -EIO;
}
static inline void rtl8169_tso_csum(struct rtl8169_private *tp,
struct sk_buff *skb, u32 *opts)
{
const struct rtl_tx_desc_info *info = tx_desc_info + tp->txd_version;
u32 mss = skb_shinfo(skb)->gso_size;
int offset = info->opts_offset;
if (mss) {
opts[0] |= TD_LSO;
opts[offset] |= min(mss, TD_MSS_MAX) << info->mss_shift;
} else if (skb->ip_summed == CHECKSUM_PARTIAL) {
const struct iphdr *ip = ip_hdr(skb);
if (ip->protocol == IPPROTO_TCP)
opts[offset] |= info->checksum.tcp;
else if (ip->protocol == IPPROTO_UDP)
opts[offset] |= info->checksum.udp;
else
WARN_ON_ONCE(1);
}
}
static netdev_tx_t rtl8169_start_xmit(struct sk_buff *skb,
struct net_device *dev)
{
struct rtl8169_private *tp = netdev_priv(dev);
unsigned int entry = tp->cur_tx % NUM_TX_DESC;
struct TxDesc *txd = tp->TxDescArray + entry;
void __iomem *ioaddr = tp->mmio_addr;
struct device *d = &tp->pci_dev->dev;
dma_addr_t mapping;
u32 status, len;
u32 opts[2];
int frags;
if (unlikely(TX_BUFFS_AVAIL(tp) < skb_shinfo(skb)->nr_frags)) {
netif_err(tp, drv, dev, "BUG! Tx Ring full when queue awake!\n");
goto err_stop_0;
}
if (unlikely(le32_to_cpu(txd->opts1) & DescOwn))
goto err_stop_0;
len = skb_headlen(skb);
mapping = dma_map_single(d, skb->data, len, DMA_TO_DEVICE);
if (unlikely(dma_mapping_error(d, mapping))) {
if (net_ratelimit())
netif_err(tp, drv, dev, "Failed to map TX DMA!\n");
goto err_dma_0;
}
tp->tx_skb[entry].len = len;
txd->addr = cpu_to_le64(mapping);
opts[1] = cpu_to_le32(rtl8169_tx_vlan_tag(tp, skb));
opts[0] = DescOwn;
rtl8169_tso_csum(tp, skb, opts);
frags = rtl8169_xmit_frags(tp, skb, opts);
if (frags < 0)
goto err_dma_1;
else if (frags)
opts[0] |= FirstFrag;
else {
opts[0] |= FirstFrag | LastFrag;
tp->tx_skb[entry].skb = skb;
}
txd->opts2 = cpu_to_le32(opts[1]);
wmb();
status = opts[0] | len | (RingEnd * !((entry + 1) % NUM_TX_DESC));
txd->opts1 = cpu_to_le32(status);
tp->cur_tx += frags + 1;
wmb();
RTL_W8(TxPoll, NPQ);
if (TX_BUFFS_AVAIL(tp) < MAX_SKB_FRAGS) {
netif_stop_queue(dev);
smp_rmb();
if (TX_BUFFS_AVAIL(tp) >= MAX_SKB_FRAGS)
netif_wake_queue(dev);
}
return NETDEV_TX_OK;
err_dma_1:
rtl8169_unmap_tx_skb(d, tp->tx_skb + entry, txd);
err_dma_0:
dev_kfree_skb(skb);
dev->stats.tx_dropped++;
return NETDEV_TX_OK;
err_stop_0:
netif_stop_queue(dev);
dev->stats.tx_dropped++;
return NETDEV_TX_BUSY;
}
static void rtl8169_pcierr_interrupt(struct net_device *dev)
{
struct rtl8169_private *tp = netdev_priv(dev);
struct pci_dev *pdev = tp->pci_dev;
u16 pci_status, pci_cmd;
pci_read_config_word(pdev, PCI_COMMAND, &pci_cmd);
pci_read_config_word(pdev, PCI_STATUS, &pci_status);
netif_err(tp, intr, dev, "PCI error (cmd = 0x%04x, status = 0x%04x)\n",
pci_cmd, pci_status);
if (pdev->broken_parity_status)
pci_cmd &= ~PCI_COMMAND_PARITY;
else
pci_cmd |= PCI_COMMAND_SERR | PCI_COMMAND_PARITY;
pci_write_config_word(pdev, PCI_COMMAND, pci_cmd);
pci_write_config_word(pdev, PCI_STATUS,
pci_status & (PCI_STATUS_DETECTED_PARITY |
PCI_STATUS_SIG_SYSTEM_ERROR | PCI_STATUS_REC_MASTER_ABORT |
PCI_STATUS_REC_TARGET_ABORT | PCI_STATUS_SIG_TARGET_ABORT));
if ((tp->cp_cmd & PCIDAC) && !tp->dirty_rx && !tp->cur_rx) {
void __iomem *ioaddr = tp->mmio_addr;
netif_info(tp, intr, dev, "disabling PCI DAC\n");
tp->cp_cmd &= ~PCIDAC;
RTL_W16(CPlusCmd, tp->cp_cmd);
dev->features &= ~NETIF_F_HIGHDMA;
}
rtl8169_hw_reset(tp);
rtl8169_schedule_work(dev, rtl8169_reinit_task);
}
static void rtl8169_tx_interrupt(struct net_device *dev,
struct rtl8169_private *tp,
void __iomem *ioaddr)
{
unsigned int dirty_tx, tx_left;
dirty_tx = tp->dirty_tx;
smp_rmb();
tx_left = tp->cur_tx - dirty_tx;
while (tx_left > 0) {
unsigned int entry = dirty_tx % NUM_TX_DESC;
struct ring_info *tx_skb = tp->tx_skb + entry;
u32 status;
rmb();
status = le32_to_cpu(tp->TxDescArray[entry].opts1);
if (status & DescOwn)
break;
rtl8169_unmap_tx_skb(&tp->pci_dev->dev, tx_skb,
tp->TxDescArray + entry);
if (status & LastFrag) {
dev->stats.tx_packets++;
dev->stats.tx_bytes += tx_skb->skb->len;
dev_kfree_skb(tx_skb->skb);
tx_skb->skb = NULL;
}
dirty_tx++;
tx_left--;
}
if (tp->dirty_tx != dirty_tx) {
tp->dirty_tx = dirty_tx;
smp_wmb();
if (netif_queue_stopped(dev) &&
(TX_BUFFS_AVAIL(tp) >= MAX_SKB_FRAGS)) {
netif_wake_queue(dev);
}
smp_rmb();
if (tp->cur_tx != dirty_tx)
RTL_W8(TxPoll, NPQ);
}
}
static inline int rtl8169_fragmented_frame(u32 status)
{
return (status & (FirstFrag | LastFrag)) != (FirstFrag | LastFrag);
}
static inline void rtl8169_rx_csum(struct sk_buff *skb, u32 opts1)
{
u32 status = opts1 & RxProtoMask;
if (((status == RxProtoTCP) && !(opts1 & TCPFail)) ||
((status == RxProtoUDP) && !(opts1 & UDPFail)))
skb->ip_summed = CHECKSUM_UNNECESSARY;
else
skb_checksum_none_assert(skb);
}
static struct sk_buff *rtl8169_try_rx_copy(void *data,
struct rtl8169_private *tp,
int pkt_size,
dma_addr_t addr)
{
struct sk_buff *skb;
struct device *d = &tp->pci_dev->dev;
data = rtl8169_align(data);
dma_sync_single_for_cpu(d, addr, pkt_size, DMA_FROM_DEVICE);
prefetch(data);
skb = netdev_alloc_skb_ip_align(tp->dev, pkt_size);
if (skb)
memcpy(skb->data, data, pkt_size);
dma_sync_single_for_device(d, addr, pkt_size, DMA_FROM_DEVICE);
return skb;
}
static int rtl8169_rx_interrupt(struct net_device *dev,
struct rtl8169_private *tp,
void __iomem *ioaddr, u32 budget)
{
unsigned int cur_rx, rx_left;
unsigned int count;
cur_rx = tp->cur_rx;
rx_left = NUM_RX_DESC + tp->dirty_rx - cur_rx;
rx_left = min(rx_left, budget);
for (; rx_left > 0; rx_left--, cur_rx++) {
unsigned int entry = cur_rx % NUM_RX_DESC;
struct RxDesc *desc = tp->RxDescArray + entry;
u32 status;
rmb();
status = le32_to_cpu(desc->opts1);
if (status & DescOwn)
break;
if (unlikely(status & RxRES)) {
netif_info(tp, rx_err, dev, "Rx ERROR. status = %08x\n",
status);
dev->stats.rx_errors++;
if (status & (RxRWT | RxRUNT))
dev->stats.rx_length_errors++;
if (status & RxCRC)
dev->stats.rx_crc_errors++;
if (status & RxFOVF) {
rtl8169_schedule_work(dev, rtl8169_reset_task);
dev->stats.rx_fifo_errors++;
}
rtl8169_mark_to_asic(desc, rx_buf_sz);
} else {
struct sk_buff *skb;
dma_addr_t addr = le64_to_cpu(desc->addr);
int pkt_size = (status & 0x00001FFF) - 4;
if (unlikely(rtl8169_fragmented_frame(status))) {
dev->stats.rx_dropped++;
dev->stats.rx_length_errors++;
rtl8169_mark_to_asic(desc, rx_buf_sz);
continue;
}
skb = rtl8169_try_rx_copy(tp->Rx_databuff[entry],
tp, pkt_size, addr);
rtl8169_mark_to_asic(desc, rx_buf_sz);
if (!skb) {
dev->stats.rx_dropped++;
continue;
}
rtl8169_rx_csum(skb, status);
skb_put(skb, pkt_size);
skb->protocol = eth_type_trans(skb, dev);
rtl8169_rx_vlan_tag(desc, skb);
napi_gro_receive(&tp->napi, skb);
dev->stats.rx_bytes += pkt_size;
dev->stats.rx_packets++;
}
if ((desc->opts2 & cpu_to_le32(0xfffe000)) &&
(tp->mac_version == RTL_GIGA_MAC_VER_05)) {
desc->opts2 = 0;
cur_rx++;
}
}
count = cur_rx - tp->cur_rx;
tp->cur_rx = cur_rx;
tp->dirty_rx += count;
return count;
}
static irqreturn_t rtl8169_interrupt(int irq, void *dev_instance)
{
struct net_device *dev = dev_instance;
struct rtl8169_private *tp = netdev_priv(dev);
void __iomem *ioaddr = tp->mmio_addr;
int handled = 0;
int status;
status = RTL_R16(IntrStatus);
while (status && status != 0xffff) {
handled = 1;
if (unlikely(!netif_running(dev))) {
rtl8169_asic_down(ioaddr);
break;
}
if (unlikely(status & RxFIFOOver)) {
switch (tp->mac_version) {
case RTL_GIGA_MAC_VER_11:
case RTL_GIGA_MAC_VER_22:
case RTL_GIGA_MAC_VER_26:
netif_stop_queue(dev);
rtl8169_tx_timeout(dev);
goto done;
case RTL_GIGA_MAC_VER_17:
case RTL_GIGA_MAC_VER_19:
case RTL_GIGA_MAC_VER_20:
case RTL_GIGA_MAC_VER_21:
case RTL_GIGA_MAC_VER_23:
case RTL_GIGA_MAC_VER_24:
case RTL_GIGA_MAC_VER_27:
case RTL_GIGA_MAC_VER_28:
case RTL_GIGA_MAC_VER_31:
case RTL_GIGA_MAC_VER_12:
case RTL_GIGA_MAC_VER_25:
if (status == RxFIFOOver)
goto done;
break;
default:
break;
}
}
if (unlikely(status & SYSErr)) {
rtl8169_pcierr_interrupt(dev);
break;
}
if (status & LinkChg)
__rtl8169_check_link_status(dev, tp, ioaddr, true);
smp_rmb();
if (status & tp->intr_mask & tp->napi_event) {
RTL_W16(IntrMask, tp->intr_event & ~tp->napi_event);
tp->intr_mask = ~tp->napi_event;
if (likely(napi_schedule_prep(&tp->napi)))
__napi_schedule(&tp->napi);
else
netif_info(tp, intr, dev,
"interrupt %04x in poll\n", status);
}
RTL_W16(IntrStatus,
(status & RxFIFOOver) ? (status | RxOverflow) : status);
status = RTL_R16(IntrStatus);
}
done:
return IRQ_RETVAL(handled);
}
static int rtl8169_poll(struct napi_struct *napi, int budget)
{
struct rtl8169_private *tp = container_of(napi, struct rtl8169_private, napi);
struct net_device *dev = tp->dev;
void __iomem *ioaddr = tp->mmio_addr;
int work_done;
work_done = rtl8169_rx_interrupt(dev, tp, ioaddr, (u32) budget);
rtl8169_tx_interrupt(dev, tp, ioaddr);
if (work_done < budget) {
napi_complete(napi);
tp->intr_mask = 0xffff;
wmb();
RTL_W16(IntrMask, tp->intr_event);
}
return work_done;
}
static void rtl8169_rx_missed(struct net_device *dev, void __iomem *ioaddr)
{
struct rtl8169_private *tp = netdev_priv(dev);
if (tp->mac_version > RTL_GIGA_MAC_VER_06)
return;
dev->stats.rx_missed_errors += (RTL_R32(RxMissed) & 0xffffff);
RTL_W32(RxMissed, 0);
}
static void rtl8169_down(struct net_device *dev)
{
struct rtl8169_private *tp = netdev_priv(dev);
void __iomem *ioaddr = tp->mmio_addr;
del_timer_sync(&tp->timer);
netif_stop_queue(dev);
napi_disable(&tp->napi);
spin_lock_irq(&tp->lock);
rtl8169_asic_down(ioaddr);
rtl8169_rx_missed(dev, ioaddr);
spin_unlock_irq(&tp->lock);
synchronize_irq(dev->irq);
synchronize_sched();
rtl8169_tx_clear(tp);
rtl8169_rx_clear(tp);
rtl_pll_power_down(tp);
}
static int rtl8169_close(struct net_device *dev)
{
struct rtl8169_private *tp = netdev_priv(dev);
struct pci_dev *pdev = tp->pci_dev;
pm_runtime_get_sync(&pdev->dev);
rtl8169_update_counters(dev);
rtl8169_down(dev);
free_irq(dev->irq, dev);
dma_free_coherent(&pdev->dev, R8169_RX_RING_BYTES, tp->RxDescArray,
tp->RxPhyAddr);
dma_free_coherent(&pdev->dev, R8169_TX_RING_BYTES, tp->TxDescArray,
tp->TxPhyAddr);
tp->TxDescArray = NULL;
tp->RxDescArray = NULL;
pm_runtime_put_sync(&pdev->dev);
return 0;
}
static void rtl_set_rx_mode(struct net_device *dev)
{
struct rtl8169_private *tp = netdev_priv(dev);
void __iomem *ioaddr = tp->mmio_addr;
unsigned long flags;
u32 mc_filter[2];
int rx_mode;
u32 tmp = 0;
if (dev->flags & IFF_PROMISC) {
netif_notice(tp, link, dev, "Promiscuous mode enabled\n");
rx_mode =
AcceptBroadcast | AcceptMulticast | AcceptMyPhys |
AcceptAllPhys;
mc_filter[1] = mc_filter[0] = 0xffffffff;
} else if ((netdev_mc_count(dev) > multicast_filter_limit) ||
(dev->flags & IFF_ALLMULTI)) {
rx_mode = AcceptBroadcast | AcceptMulticast | AcceptMyPhys;
mc_filter[1] = mc_filter[0] = 0xffffffff;
} else {
struct netdev_hw_addr *ha;
rx_mode = AcceptBroadcast | AcceptMyPhys;
mc_filter[1] = mc_filter[0] = 0;
netdev_for_each_mc_addr(ha, dev) {
int bit_nr = ether_crc(ETH_ALEN, ha->addr) >> 26;
mc_filter[bit_nr >> 5] |= 1 << (bit_nr & 31);
rx_mode |= AcceptMulticast;
}
}
spin_lock_irqsave(&tp->lock, flags);
tmp = rtl8169_rx_config | rx_mode |
(RTL_R32(RxConfig) & RTL_RX_CONFIG_MASK);
if (tp->mac_version > RTL_GIGA_MAC_VER_06) {
u32 data = mc_filter[0];
mc_filter[0] = swab32(mc_filter[1]);
mc_filter[1] = swab32(data);
}
RTL_W32(MAR0 + 4, mc_filter[1]);
RTL_W32(MAR0 + 0, mc_filter[0]);
RTL_W32(RxConfig, tmp);
spin_unlock_irqrestore(&tp->lock, flags);
}
static struct net_device_stats *rtl8169_get_stats(struct net_device *dev)
{
struct rtl8169_private *tp = netdev_priv(dev);
void __iomem *ioaddr = tp->mmio_addr;
unsigned long flags;
if (netif_running(dev)) {
spin_lock_irqsave(&tp->lock, flags);
rtl8169_rx_missed(dev, ioaddr);
spin_unlock_irqrestore(&tp->lock, flags);
}
return &dev->stats;
}
static void rtl8169_net_suspend(struct net_device *dev)
{
struct rtl8169_private *tp = netdev_priv(dev);
if (!netif_running(dev))
return;
rtl_pll_power_down(tp);
netif_device_detach(dev);
netif_stop_queue(dev);
}
static int rtl8169_suspend(struct device *device)
{
struct pci_dev *pdev = to_pci_dev(device);
struct net_device *dev = pci_get_drvdata(pdev);
rtl8169_net_suspend(dev);
return 0;
}
static void __rtl8169_resume(struct net_device *dev)
{
struct rtl8169_private *tp = netdev_priv(dev);
netif_device_attach(dev);
rtl_pll_power_up(tp);
rtl8169_schedule_work(dev, rtl8169_reset_task);
}
static int rtl8169_resume(struct device *device)
{
struct pci_dev *pdev = to_pci_dev(device);
struct net_device *dev = pci_get_drvdata(pdev);
struct rtl8169_private *tp = netdev_priv(dev);
rtl8169_init_phy(dev, tp);
if (netif_running(dev))
__rtl8169_resume(dev);
return 0;
}
static int rtl8169_runtime_suspend(struct device *device)
{
struct pci_dev *pdev = to_pci_dev(device);
struct net_device *dev = pci_get_drvdata(pdev);
struct rtl8169_private *tp = netdev_priv(dev);
if (!tp->TxDescArray)
return 0;
spin_lock_irq(&tp->lock);
tp->saved_wolopts = __rtl8169_get_wol(tp);
__rtl8169_set_wol(tp, WAKE_ANY);
spin_unlock_irq(&tp->lock);
rtl8169_net_suspend(dev);
return 0;
}
static int rtl8169_runtime_resume(struct device *device)
{
struct pci_dev *pdev = to_pci_dev(device);
struct net_device *dev = pci_get_drvdata(pdev);
struct rtl8169_private *tp = netdev_priv(dev);
if (!tp->TxDescArray)
return 0;
spin_lock_irq(&tp->lock);
__rtl8169_set_wol(tp, tp->saved_wolopts);
tp->saved_wolopts = 0;
spin_unlock_irq(&tp->lock);
rtl8169_init_phy(dev, tp);
__rtl8169_resume(dev);
return 0;
}
static int rtl8169_runtime_idle(struct device *device)
{
struct pci_dev *pdev = to_pci_dev(device);
struct net_device *dev = pci_get_drvdata(pdev);
struct rtl8169_private *tp = netdev_priv(dev);
return tp->TxDescArray ? -EBUSY : 0;
}
static void rtl_shutdown(struct pci_dev *pdev)
{
struct net_device *dev = pci_get_drvdata(pdev);
struct rtl8169_private *tp = netdev_priv(dev);
void __iomem *ioaddr = tp->mmio_addr;
rtl8169_net_suspend(dev);
rtl_rar_set(tp, dev->perm_addr);
spin_lock_irq(&tp->lock);
rtl8169_asic_down(ioaddr);
spin_unlock_irq(&tp->lock);
if (system_state == SYSTEM_POWER_OFF) {
if (tp->features & RTL_FEATURE_WOL) {
pci_clear_master(pdev);
RTL_W8(ChipCmd, CmdRxEnb);
RTL_R8(ChipCmd);
}
pci_wake_from_d3(pdev, true);
pci_set_power_state(pdev, PCI_D3hot);
}
}
static int __init rtl8169_init_module(void)
{
return pci_register_driver(&rtl8169_pci_driver);
}
static void __exit rtl8169_cleanup_module(void)
{
pci_unregister_driver(&rtl8169_pci_driver);
}
