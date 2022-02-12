static void rtl_lock_work(struct rtl8169_private *tp)
{
mutex_lock(&tp->wk.mutex);
}
static void rtl_unlock_work(struct rtl8169_private *tp)
{
mutex_unlock(&tp->wk.mutex);
}
static void rtl_tx_performance_tweak(struct pci_dev *pdev, u16 force)
{
pcie_capability_clear_and_set_word(pdev, PCI_EXP_DEVCTL,
PCI_EXP_DEVCTL_READRQ, force);
}
static void rtl_udelay(unsigned int d)
{
udelay(d);
}
static bool rtl_loop_wait(struct rtl8169_private *tp, const struct rtl_cond *c,
void (*delay)(unsigned int), unsigned int d, int n,
bool high)
{
int i;
for (i = 0; i < n; i++) {
delay(d);
if (c->check(tp) == high)
return true;
}
netif_err(tp, drv, tp->dev, "%s == %d (loop: %d, delay: %d).\n",
c->msg, !high, n, d);
return false;
}
static bool rtl_udelay_loop_wait_high(struct rtl8169_private *tp,
const struct rtl_cond *c,
unsigned int d, int n)
{
return rtl_loop_wait(tp, c, rtl_udelay, d, n, true);
}
static bool rtl_udelay_loop_wait_low(struct rtl8169_private *tp,
const struct rtl_cond *c,
unsigned int d, int n)
{
return rtl_loop_wait(tp, c, rtl_udelay, d, n, false);
}
static bool rtl_msleep_loop_wait_high(struct rtl8169_private *tp,
const struct rtl_cond *c,
unsigned int d, int n)
{
return rtl_loop_wait(tp, c, msleep, d, n, true);
}
static bool rtl_msleep_loop_wait_low(struct rtl8169_private *tp,
const struct rtl_cond *c,
unsigned int d, int n)
{
return rtl_loop_wait(tp, c, msleep, d, n, false);
}
static bool rtl_ocp_reg_failure(struct rtl8169_private *tp, u32 reg)
{
if (reg & 0xffff0001) {
netif_err(tp, drv, tp->dev, "Invalid ocp reg %x!\n", reg);
return true;
}
return false;
}
static void r8168_phy_ocp_write(struct rtl8169_private *tp, u32 reg, u32 data)
{
void __iomem *ioaddr = tp->mmio_addr;
if (rtl_ocp_reg_failure(tp, reg))
return;
RTL_W32(GPHY_OCP, OCPAR_FLAG | (reg << 15) | data);
rtl_udelay_loop_wait_low(tp, &rtl_ocp_gphy_cond, 25, 10);
}
static u16 r8168_phy_ocp_read(struct rtl8169_private *tp, u32 reg)
{
void __iomem *ioaddr = tp->mmio_addr;
if (rtl_ocp_reg_failure(tp, reg))
return 0;
RTL_W32(GPHY_OCP, reg << 15);
return rtl_udelay_loop_wait_high(tp, &rtl_ocp_gphy_cond, 25, 10) ?
(RTL_R32(GPHY_OCP) & 0xffff) : ~0;
}
static void r8168_mac_ocp_write(struct rtl8169_private *tp, u32 reg, u32 data)
{
void __iomem *ioaddr = tp->mmio_addr;
if (rtl_ocp_reg_failure(tp, reg))
return;
RTL_W32(OCPDR, OCPAR_FLAG | (reg << 15) | data);
}
static u16 r8168_mac_ocp_read(struct rtl8169_private *tp, u32 reg)
{
void __iomem *ioaddr = tp->mmio_addr;
if (rtl_ocp_reg_failure(tp, reg))
return 0;
RTL_W32(OCPDR, reg << 15);
return RTL_R32(OCPDR);
}
static void r8168g_mdio_write(struct rtl8169_private *tp, int reg, int value)
{
if (reg == 0x1f) {
tp->ocp_base = value ? value << 4 : OCP_STD_PHY_BASE;
return;
}
if (tp->ocp_base != OCP_STD_PHY_BASE)
reg -= 0x10;
r8168_phy_ocp_write(tp, tp->ocp_base + reg * 2, value);
}
static int r8168g_mdio_read(struct rtl8169_private *tp, int reg)
{
if (tp->ocp_base != OCP_STD_PHY_BASE)
reg -= 0x10;
return r8168_phy_ocp_read(tp, tp->ocp_base + reg * 2);
}
static void mac_mcu_write(struct rtl8169_private *tp, int reg, int value)
{
if (reg == 0x1f) {
tp->ocp_base = value << 4;
return;
}
r8168_mac_ocp_write(tp, tp->ocp_base + reg, value);
}
static int mac_mcu_read(struct rtl8169_private *tp, int reg)
{
return r8168_mac_ocp_read(tp, tp->ocp_base + reg);
}
static void r8169_mdio_write(struct rtl8169_private *tp, int reg, int value)
{
void __iomem *ioaddr = tp->mmio_addr;
RTL_W32(PHYAR, 0x80000000 | (reg & 0x1f) << 16 | (value & 0xffff));
rtl_udelay_loop_wait_low(tp, &rtl_phyar_cond, 25, 20);
udelay(20);
}
static int r8169_mdio_read(struct rtl8169_private *tp, int reg)
{
void __iomem *ioaddr = tp->mmio_addr;
int value;
RTL_W32(PHYAR, 0x0 | (reg & 0x1f) << 16);
value = rtl_udelay_loop_wait_high(tp, &rtl_phyar_cond, 25, 20) ?
RTL_R32(PHYAR) & 0xffff : ~0;
udelay(20);
return value;
}
static void r8168dp_1_mdio_access(struct rtl8169_private *tp, int reg, u32 data)
{
void __iomem *ioaddr = tp->mmio_addr;
RTL_W32(OCPDR, data | ((reg & OCPDR_REG_MASK) << OCPDR_GPHY_REG_SHIFT));
RTL_W32(OCPAR, OCPAR_GPHY_WRITE_CMD);
RTL_W32(EPHY_RXER_NUM, 0);
rtl_udelay_loop_wait_low(tp, &rtl_ocpar_cond, 1000, 100);
}
static void r8168dp_1_mdio_write(struct rtl8169_private *tp, int reg, int value)
{
r8168dp_1_mdio_access(tp, reg,
OCPDR_WRITE_CMD | (value & OCPDR_DATA_MASK));
}
static int r8168dp_1_mdio_read(struct rtl8169_private *tp, int reg)
{
void __iomem *ioaddr = tp->mmio_addr;
r8168dp_1_mdio_access(tp, reg, OCPDR_READ_CMD);
mdelay(1);
RTL_W32(OCPAR, OCPAR_GPHY_READ_CMD);
RTL_W32(EPHY_RXER_NUM, 0);
return rtl_udelay_loop_wait_high(tp, &rtl_ocpar_cond, 1000, 100) ?
RTL_R32(OCPDR) & OCPDR_DATA_MASK : ~0;
}
static void r8168dp_2_mdio_start(void __iomem *ioaddr)
{
RTL_W32(0xd0, RTL_R32(0xd0) & ~R8168DP_1_MDIO_ACCESS_BIT);
}
static void r8168dp_2_mdio_stop(void __iomem *ioaddr)
{
RTL_W32(0xd0, RTL_R32(0xd0) | R8168DP_1_MDIO_ACCESS_BIT);
}
static void r8168dp_2_mdio_write(struct rtl8169_private *tp, int reg, int value)
{
void __iomem *ioaddr = tp->mmio_addr;
r8168dp_2_mdio_start(ioaddr);
r8169_mdio_write(tp, reg, value);
r8168dp_2_mdio_stop(ioaddr);
}
static int r8168dp_2_mdio_read(struct rtl8169_private *tp, int reg)
{
void __iomem *ioaddr = tp->mmio_addr;
int value;
r8168dp_2_mdio_start(ioaddr);
value = r8169_mdio_read(tp, reg);
r8168dp_2_mdio_stop(ioaddr);
return value;
}
static void rtl_writephy(struct rtl8169_private *tp, int location, u32 val)
{
tp->mdio_ops.write(tp, location, val);
}
static int rtl_readphy(struct rtl8169_private *tp, int location)
{
return tp->mdio_ops.read(tp, location);
}
static void rtl_patchphy(struct rtl8169_private *tp, int reg_addr, int value)
{
rtl_writephy(tp, reg_addr, rtl_readphy(tp, reg_addr) | value);
}
static void rtl_w0w1_phy(struct rtl8169_private *tp, int reg_addr, int p, int m)
{
int val;
val = rtl_readphy(tp, reg_addr);
rtl_writephy(tp, reg_addr, (val & ~m) | p);
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
static void rtl_ephy_write(struct rtl8169_private *tp, int reg_addr, int value)
{
void __iomem *ioaddr = tp->mmio_addr;
RTL_W32(EPHYAR, EPHYAR_WRITE_CMD | (value & EPHYAR_DATA_MASK) |
(reg_addr & EPHYAR_REG_MASK) << EPHYAR_REG_SHIFT);
rtl_udelay_loop_wait_low(tp, &rtl_ephyar_cond, 10, 100);
udelay(10);
}
static u16 rtl_ephy_read(struct rtl8169_private *tp, int reg_addr)
{
void __iomem *ioaddr = tp->mmio_addr;
RTL_W32(EPHYAR, (reg_addr & EPHYAR_REG_MASK) << EPHYAR_REG_SHIFT);
return rtl_udelay_loop_wait_high(tp, &rtl_ephyar_cond, 10, 100) ?
RTL_R32(EPHYAR) & EPHYAR_DATA_MASK : ~0;
}
static void rtl_eri_write(struct rtl8169_private *tp, int addr, u32 mask,
u32 val, int type)
{
void __iomem *ioaddr = tp->mmio_addr;
BUG_ON((addr & 3) || (mask == 0));
RTL_W32(ERIDR, val);
RTL_W32(ERIAR, ERIAR_WRITE_CMD | type | mask | addr);
rtl_udelay_loop_wait_low(tp, &rtl_eriar_cond, 100, 100);
}
static u32 rtl_eri_read(struct rtl8169_private *tp, int addr, int type)
{
void __iomem *ioaddr = tp->mmio_addr;
RTL_W32(ERIAR, ERIAR_READ_CMD | type | ERIAR_MASK_1111 | addr);
return rtl_udelay_loop_wait_high(tp, &rtl_eriar_cond, 100, 100) ?
RTL_R32(ERIDR) : ~0;
}
static void rtl_w0w1_eri(struct rtl8169_private *tp, int addr, u32 mask, u32 p,
u32 m, int type)
{
u32 val;
val = rtl_eri_read(tp, addr, type);
rtl_eri_write(tp, addr, mask, (val & ~m) | p, type);
}
static u32 r8168dp_ocp_read(struct rtl8169_private *tp, u8 mask, u16 reg)
{
void __iomem *ioaddr = tp->mmio_addr;
RTL_W32(OCPAR, ((u32)mask & 0x0f) << 12 | (reg & 0x0fff));
return rtl_udelay_loop_wait_high(tp, &rtl_ocpar_cond, 100, 20) ?
RTL_R32(OCPDR) : ~0;
}
static u32 r8168ep_ocp_read(struct rtl8169_private *tp, u8 mask, u16 reg)
{
return rtl_eri_read(tp, reg, ERIAR_OOB);
}
static u32 ocp_read(struct rtl8169_private *tp, u8 mask, u16 reg)
{
switch (tp->mac_version) {
case RTL_GIGA_MAC_VER_27:
case RTL_GIGA_MAC_VER_28:
case RTL_GIGA_MAC_VER_31:
return r8168dp_ocp_read(tp, mask, reg);
case RTL_GIGA_MAC_VER_49:
case RTL_GIGA_MAC_VER_50:
case RTL_GIGA_MAC_VER_51:
return r8168ep_ocp_read(tp, mask, reg);
default:
BUG();
return ~0;
}
}
static void r8168dp_ocp_write(struct rtl8169_private *tp, u8 mask, u16 reg,
u32 data)
{
void __iomem *ioaddr = tp->mmio_addr;
RTL_W32(OCPDR, data);
RTL_W32(OCPAR, OCPAR_FLAG | ((u32)mask & 0x0f) << 12 | (reg & 0x0fff));
rtl_udelay_loop_wait_low(tp, &rtl_ocpar_cond, 100, 20);
}
static void r8168ep_ocp_write(struct rtl8169_private *tp, u8 mask, u16 reg,
u32 data)
{
rtl_eri_write(tp, reg, ((u32)mask & 0x0f) << ERIAR_MASK_SHIFT,
data, ERIAR_OOB);
}
static void ocp_write(struct rtl8169_private *tp, u8 mask, u16 reg, u32 data)
{
switch (tp->mac_version) {
case RTL_GIGA_MAC_VER_27:
case RTL_GIGA_MAC_VER_28:
case RTL_GIGA_MAC_VER_31:
r8168dp_ocp_write(tp, mask, reg, data);
break;
case RTL_GIGA_MAC_VER_49:
case RTL_GIGA_MAC_VER_50:
case RTL_GIGA_MAC_VER_51:
r8168ep_ocp_write(tp, mask, reg, data);
break;
default:
BUG();
break;
}
}
static void rtl8168_oob_notify(struct rtl8169_private *tp, u8 cmd)
{
rtl_eri_write(tp, 0xe8, ERIAR_MASK_0001, cmd, ERIAR_EXGMAC);
ocp_write(tp, 0x1, 0x30, 0x00000001);
}
static u16 rtl8168_get_ocp_reg(struct rtl8169_private *tp)
{
return (tp->mac_version == RTL_GIGA_MAC_VER_31) ? 0xb8 : 0x10;
}
static void rtl8168ep_stop_cmac(struct rtl8169_private *tp)
{
void __iomem *ioaddr = tp->mmio_addr;
RTL_W8(IBCR2, RTL_R8(IBCR2) & ~0x01);
rtl_msleep_loop_wait_low(tp, &rtl_ocp_tx_cond, 50, 2000);
RTL_W8(IBISR0, RTL_R8(IBISR0) | 0x20);
RTL_W8(IBCR0, RTL_R8(IBCR0) & ~0x01);
}
static void rtl8168dp_driver_start(struct rtl8169_private *tp)
{
rtl8168_oob_notify(tp, OOB_CMD_DRIVER_START);
rtl_msleep_loop_wait_high(tp, &rtl_ocp_read_cond, 10, 10);
}
static void rtl8168ep_driver_start(struct rtl8169_private *tp)
{
ocp_write(tp, 0x01, 0x180, OOB_CMD_DRIVER_START);
ocp_write(tp, 0x01, 0x30, ocp_read(tp, 0x01, 0x30) | 0x01);
rtl_msleep_loop_wait_high(tp, &rtl_ep_ocp_read_cond, 10, 10);
}
static void rtl8168_driver_start(struct rtl8169_private *tp)
{
switch (tp->mac_version) {
case RTL_GIGA_MAC_VER_27:
case RTL_GIGA_MAC_VER_28:
case RTL_GIGA_MAC_VER_31:
rtl8168dp_driver_start(tp);
break;
case RTL_GIGA_MAC_VER_49:
case RTL_GIGA_MAC_VER_50:
case RTL_GIGA_MAC_VER_51:
rtl8168ep_driver_start(tp);
break;
default:
BUG();
break;
}
}
static void rtl8168dp_driver_stop(struct rtl8169_private *tp)
{
rtl8168_oob_notify(tp, OOB_CMD_DRIVER_STOP);
rtl_msleep_loop_wait_low(tp, &rtl_ocp_read_cond, 10, 10);
}
static void rtl8168ep_driver_stop(struct rtl8169_private *tp)
{
rtl8168ep_stop_cmac(tp);
ocp_write(tp, 0x01, 0x180, OOB_CMD_DRIVER_STOP);
ocp_write(tp, 0x01, 0x30, ocp_read(tp, 0x01, 0x30) | 0x01);
rtl_msleep_loop_wait_low(tp, &rtl_ep_ocp_read_cond, 10, 10);
}
static void rtl8168_driver_stop(struct rtl8169_private *tp)
{
switch (tp->mac_version) {
case RTL_GIGA_MAC_VER_27:
case RTL_GIGA_MAC_VER_28:
case RTL_GIGA_MAC_VER_31:
rtl8168dp_driver_stop(tp);
break;
case RTL_GIGA_MAC_VER_49:
case RTL_GIGA_MAC_VER_50:
case RTL_GIGA_MAC_VER_51:
rtl8168ep_driver_stop(tp);
break;
default:
BUG();
break;
}
}
static int r8168dp_check_dash(struct rtl8169_private *tp)
{
u16 reg = rtl8168_get_ocp_reg(tp);
return (ocp_read(tp, 0x0f, reg) & 0x00008000) ? 1 : 0;
}
static int r8168ep_check_dash(struct rtl8169_private *tp)
{
return (ocp_read(tp, 0x0f, 0x128) & 0x00000001) ? 1 : 0;
}
static int r8168_check_dash(struct rtl8169_private *tp)
{
switch (tp->mac_version) {
case RTL_GIGA_MAC_VER_27:
case RTL_GIGA_MAC_VER_28:
case RTL_GIGA_MAC_VER_31:
return r8168dp_check_dash(tp);
case RTL_GIGA_MAC_VER_49:
case RTL_GIGA_MAC_VER_50:
case RTL_GIGA_MAC_VER_51:
return r8168ep_check_dash(tp);
default:
return 0;
}
}
static void rtl_write_exgmac_batch(struct rtl8169_private *tp,
const struct exgmac_reg *r, int len)
{
while (len-- > 0) {
rtl_eri_write(tp, r->addr, r->mask, r->val, ERIAR_EXGMAC);
r++;
}
}
static u8 rtl8168d_efuse_read(struct rtl8169_private *tp, int reg_addr)
{
void __iomem *ioaddr = tp->mmio_addr;
RTL_W32(EFUSEAR, (reg_addr & EFUSEAR_REG_MASK) << EFUSEAR_REG_SHIFT);
return rtl_udelay_loop_wait_high(tp, &rtl_efusear_cond, 100, 300) ?
RTL_R32(EFUSEAR) & EFUSEAR_DATA_MASK : ~0;
}
static u16 rtl_get_events(struct rtl8169_private *tp)
{
void __iomem *ioaddr = tp->mmio_addr;
return RTL_R16(IntrStatus);
}
static void rtl_ack_events(struct rtl8169_private *tp, u16 bits)
{
void __iomem *ioaddr = tp->mmio_addr;
RTL_W16(IntrStatus, bits);
mmiowb();
}
static void rtl_irq_disable(struct rtl8169_private *tp)
{
void __iomem *ioaddr = tp->mmio_addr;
RTL_W16(IntrMask, 0);
mmiowb();
}
static void rtl_irq_enable(struct rtl8169_private *tp, u16 bits)
{
void __iomem *ioaddr = tp->mmio_addr;
RTL_W16(IntrMask, bits);
}
static void rtl_irq_enable_all(struct rtl8169_private *tp)
{
rtl_irq_enable(tp, RTL_EVENT_NAPI | tp->event_slow);
}
static void rtl8169_irq_mask_and_ack(struct rtl8169_private *tp)
{
void __iomem *ioaddr = tp->mmio_addr;
rtl_irq_disable(tp);
rtl_ack_events(tp, RTL_EVENT_NAPI | tp->event_slow);
RTL_R8(ChipCmd);
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
static void rtl_link_chg_patch(struct rtl8169_private *tp)
{
void __iomem *ioaddr = tp->mmio_addr;
struct net_device *dev = tp->dev;
if (!netif_running(dev))
return;
if (tp->mac_version == RTL_GIGA_MAC_VER_34 ||
tp->mac_version == RTL_GIGA_MAC_VER_38) {
if (RTL_R8(PHYstatus) & _1000bpsF) {
rtl_eri_write(tp, 0x1bc, ERIAR_MASK_1111, 0x00000011,
ERIAR_EXGMAC);
rtl_eri_write(tp, 0x1dc, ERIAR_MASK_1111, 0x00000005,
ERIAR_EXGMAC);
} else if (RTL_R8(PHYstatus) & _100bps) {
rtl_eri_write(tp, 0x1bc, ERIAR_MASK_1111, 0x0000001f,
ERIAR_EXGMAC);
rtl_eri_write(tp, 0x1dc, ERIAR_MASK_1111, 0x00000005,
ERIAR_EXGMAC);
} else {
rtl_eri_write(tp, 0x1bc, ERIAR_MASK_1111, 0x0000001f,
ERIAR_EXGMAC);
rtl_eri_write(tp, 0x1dc, ERIAR_MASK_1111, 0x0000003f,
ERIAR_EXGMAC);
}
rtl_w0w1_eri(tp, 0xdc, ERIAR_MASK_0001, 0x00, 0x01,
ERIAR_EXGMAC);
rtl_w0w1_eri(tp, 0xdc, ERIAR_MASK_0001, 0x01, 0x00,
ERIAR_EXGMAC);
} else if (tp->mac_version == RTL_GIGA_MAC_VER_35 ||
tp->mac_version == RTL_GIGA_MAC_VER_36) {
if (RTL_R8(PHYstatus) & _1000bpsF) {
rtl_eri_write(tp, 0x1bc, ERIAR_MASK_1111, 0x00000011,
ERIAR_EXGMAC);
rtl_eri_write(tp, 0x1dc, ERIAR_MASK_1111, 0x00000005,
ERIAR_EXGMAC);
} else {
rtl_eri_write(tp, 0x1bc, ERIAR_MASK_1111, 0x0000001f,
ERIAR_EXGMAC);
rtl_eri_write(tp, 0x1dc, ERIAR_MASK_1111, 0x0000003f,
ERIAR_EXGMAC);
}
} else if (tp->mac_version == RTL_GIGA_MAC_VER_37) {
if (RTL_R8(PHYstatus) & _10bps) {
rtl_eri_write(tp, 0x1d0, ERIAR_MASK_0011, 0x4d02,
ERIAR_EXGMAC);
rtl_eri_write(tp, 0x1dc, ERIAR_MASK_0011, 0x0060,
ERIAR_EXGMAC);
} else {
rtl_eri_write(tp, 0x1d0, ERIAR_MASK_0011, 0x0000,
ERIAR_EXGMAC);
}
}
}
static void __rtl8169_check_link_status(struct net_device *dev,
struct rtl8169_private *tp,
void __iomem *ioaddr, bool pm)
{
if (tp->link_ok(ioaddr)) {
rtl_link_chg_patch(tp);
if (pm)
pm_request_resume(&tp->pci_dev->dev);
netif_carrier_on(dev);
if (net_ratelimit())
netif_info(tp, ifup, dev, "link up\n");
} else {
netif_carrier_off(dev);
netif_info(tp, ifdown, dev, "link down\n");
if (pm)
pm_schedule_suspend(&tp->pci_dev->dev, 5000);
}
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
switch (tp->mac_version) {
case RTL_GIGA_MAC_VER_34:
case RTL_GIGA_MAC_VER_35:
case RTL_GIGA_MAC_VER_36:
case RTL_GIGA_MAC_VER_37:
case RTL_GIGA_MAC_VER_38:
case RTL_GIGA_MAC_VER_40:
case RTL_GIGA_MAC_VER_41:
case RTL_GIGA_MAC_VER_42:
case RTL_GIGA_MAC_VER_43:
case RTL_GIGA_MAC_VER_44:
case RTL_GIGA_MAC_VER_45:
case RTL_GIGA_MAC_VER_46:
case RTL_GIGA_MAC_VER_47:
case RTL_GIGA_MAC_VER_48:
case RTL_GIGA_MAC_VER_49:
case RTL_GIGA_MAC_VER_50:
case RTL_GIGA_MAC_VER_51:
if (rtl_eri_read(tp, 0xdc, ERIAR_EXGMAC) & MagicPacket_v2)
wolopts |= WAKE_MAGIC;
break;
default:
if (options & MagicPacket)
wolopts |= WAKE_MAGIC;
break;
}
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
struct device *d = &tp->pci_dev->dev;
pm_runtime_get_noresume(d);
rtl_lock_work(tp);
wol->supported = WAKE_ANY;
if (pm_runtime_active(d))
wol->wolopts = __rtl8169_get_wol(tp);
else
wol->wolopts = tp->saved_wolopts;
rtl_unlock_work(tp);
pm_runtime_put_noidle(d);
}
static void __rtl8169_set_wol(struct rtl8169_private *tp, u32 wolopts)
{
void __iomem *ioaddr = tp->mmio_addr;
unsigned int i, tmp;
static const struct {
u32 opt;
u16 reg;
u8 mask;
} cfg[] = {
{ WAKE_PHY, Config3, LinkUp },
{ WAKE_UCAST, Config5, UWF },
{ WAKE_BCAST, Config5, BWF },
{ WAKE_MCAST, Config5, MWF },
{ WAKE_ANY, Config5, LanWake },
{ WAKE_MAGIC, Config3, MagicPacket }
};
u8 options;
RTL_W8(Cfg9346, Cfg9346_Unlock);
switch (tp->mac_version) {
case RTL_GIGA_MAC_VER_34:
case RTL_GIGA_MAC_VER_35:
case RTL_GIGA_MAC_VER_36:
case RTL_GIGA_MAC_VER_37:
case RTL_GIGA_MAC_VER_38:
case RTL_GIGA_MAC_VER_40:
case RTL_GIGA_MAC_VER_41:
case RTL_GIGA_MAC_VER_42:
case RTL_GIGA_MAC_VER_43:
case RTL_GIGA_MAC_VER_44:
case RTL_GIGA_MAC_VER_45:
case RTL_GIGA_MAC_VER_46:
case RTL_GIGA_MAC_VER_47:
case RTL_GIGA_MAC_VER_48:
case RTL_GIGA_MAC_VER_49:
case RTL_GIGA_MAC_VER_50:
case RTL_GIGA_MAC_VER_51:
tmp = ARRAY_SIZE(cfg) - 1;
if (wolopts & WAKE_MAGIC)
rtl_w0w1_eri(tp,
0x0dc,
ERIAR_MASK_0100,
MagicPacket_v2,
0x0000,
ERIAR_EXGMAC);
else
rtl_w0w1_eri(tp,
0x0dc,
ERIAR_MASK_0100,
0x0000,
MagicPacket_v2,
ERIAR_EXGMAC);
break;
default:
tmp = ARRAY_SIZE(cfg);
break;
}
for (i = 0; i < tmp; i++) {
options = RTL_R8(cfg[i].reg) & ~cfg[i].mask;
if (wolopts & cfg[i].opt)
options |= cfg[i].mask;
RTL_W8(cfg[i].reg, options);
}
switch (tp->mac_version) {
case RTL_GIGA_MAC_VER_01 ... RTL_GIGA_MAC_VER_17:
options = RTL_R8(Config1) & ~PMEnable;
if (wolopts)
options |= PMEnable;
RTL_W8(Config1, options);
break;
default:
options = RTL_R8(Config2) & ~PME_SIGNAL;
if (wolopts)
options |= PME_SIGNAL;
RTL_W8(Config2, options);
break;
}
RTL_W8(Cfg9346, Cfg9346_Lock);
}
static int rtl8169_set_wol(struct net_device *dev, struct ethtool_wolinfo *wol)
{
struct rtl8169_private *tp = netdev_priv(dev);
struct device *d = &tp->pci_dev->dev;
pm_runtime_get_noresume(d);
rtl_lock_work(tp);
if (wol->wolopts)
tp->features |= RTL_FEATURE_WOL;
else
tp->features &= ~RTL_FEATURE_WOL;
if (pm_runtime_active(d))
__rtl8169_set_wol(tp, wol->wolopts);
else
tp->saved_wolopts = wol->wolopts;
rtl_unlock_work(tp);
device_set_wakeup_enable(&tp->pci_dev->dev, wol->wolopts);
pm_runtime_put_noidle(d);
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
struct rtl_fw *rtl_fw = tp->rtl_fw;
strlcpy(info->driver, MODULENAME, sizeof(info->driver));
strlcpy(info->version, RTL8169_VERSION, sizeof(info->version));
strlcpy(info->bus_info, pci_name(tp->pci_dev), sizeof(info->bus_info));
BUILD_BUG_ON(sizeof(info->fw_version) < sizeof(rtl_fw->version));
if (!IS_ERR_OR_NULL(rtl_fw))
strlcpy(info->fw_version, rtl_fw->version,
sizeof(info->fw_version));
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
(advertising & ADVERTISED_1000baseT_Full) &&
!pci_is_pcie(tp->pci_dev)) {
mod_timer(&tp->timer, jiffies + RTL8169_PHY_TIMEOUT);
}
out:
return ret;
}
static int rtl8169_set_settings(struct net_device *dev, struct ethtool_cmd *cmd)
{
struct rtl8169_private *tp = netdev_priv(dev);
int ret;
del_timer_sync(&tp->timer);
rtl_lock_work(tp);
ret = rtl8169_set_speed(dev, cmd->autoneg, ethtool_cmd_speed(cmd),
cmd->duplex, cmd->advertising);
rtl_unlock_work(tp);
return ret;
}
static netdev_features_t rtl8169_fix_features(struct net_device *dev,
netdev_features_t features)
{
struct rtl8169_private *tp = netdev_priv(dev);
if (dev->mtu > TD_MSS_MAX)
features &= ~NETIF_F_ALL_TSO;
if (dev->mtu > JUMBO_1K &&
!rtl_chip_infos[tp->mac_version].jumbo_tx_csum)
features &= ~NETIF_F_IP_CSUM;
return features;
}
static void __rtl8169_set_features(struct net_device *dev,
netdev_features_t features)
{
struct rtl8169_private *tp = netdev_priv(dev);
void __iomem *ioaddr = tp->mmio_addr;
u32 rx_config;
rx_config = RTL_R32(RxConfig);
if (features & NETIF_F_RXALL)
rx_config |= (AcceptErr | AcceptRunt);
else
rx_config &= ~(AcceptErr | AcceptRunt);
RTL_W32(RxConfig, rx_config);
if (features & NETIF_F_RXCSUM)
tp->cp_cmd |= RxChkSum;
else
tp->cp_cmd &= ~RxChkSum;
if (features & NETIF_F_HW_VLAN_CTAG_RX)
tp->cp_cmd |= RxVlan;
else
tp->cp_cmd &= ~RxVlan;
tp->cp_cmd |= RTL_R16(CPlusCmd) & ~(RxVlan | RxChkSum);
RTL_W16(CPlusCmd, tp->cp_cmd);
RTL_R16(CPlusCmd);
}
static int rtl8169_set_features(struct net_device *dev,
netdev_features_t features)
{
struct rtl8169_private *tp = netdev_priv(dev);
features &= NETIF_F_RXALL | NETIF_F_RXCSUM | NETIF_F_HW_VLAN_CTAG_RX;
rtl_lock_work(tp);
if (features ^ dev->features)
__rtl8169_set_features(dev, features);
rtl_unlock_work(tp);
return 0;
}
static inline u32 rtl8169_tx_vlan_tag(struct sk_buff *skb)
{
return (skb_vlan_tag_present(skb)) ?
TxVlanTag | swab16(skb_vlan_tag_get(skb)) : 0x00;
}
static void rtl8169_rx_vlan_tag(struct RxDesc *desc, struct sk_buff *skb)
{
u32 opts2 = le32_to_cpu(desc->opts2);
if (opts2 & RxVlanTag)
__vlan_hwaccel_put_tag(skb, htons(ETH_P_8021Q), swab16(opts2 & 0xffff));
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
int rc;
rtl_lock_work(tp);
rc = tp->get_settings(dev, cmd);
rtl_unlock_work(tp);
return rc;
}
static void rtl8169_get_regs(struct net_device *dev, struct ethtool_regs *regs,
void *p)
{
struct rtl8169_private *tp = netdev_priv(dev);
u32 __iomem *data = tp->mmio_addr;
u32 *dw = p;
int i;
rtl_lock_work(tp);
for (i = 0; i < R8169_REGS_SIZE; i += 4)
memcpy_fromio(dw++, data++, 4);
rtl_unlock_work(tp);
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
static bool rtl8169_do_counters(struct net_device *dev, u32 counter_cmd)
{
struct rtl8169_private *tp = netdev_priv(dev);
void __iomem *ioaddr = tp->mmio_addr;
dma_addr_t paddr = tp->counters_phys_addr;
u32 cmd;
bool ret;
RTL_W32(CounterAddrHigh, (u64)paddr >> 32);
cmd = (u64)paddr & DMA_BIT_MASK(32);
RTL_W32(CounterAddrLow, cmd);
RTL_W32(CounterAddrLow, cmd | counter_cmd);
ret = rtl_udelay_loop_wait_low(tp, &rtl_counters_cond, 10, 1000);
RTL_W32(CounterAddrLow, 0);
RTL_W32(CounterAddrHigh, 0);
return ret;
}
static bool rtl8169_reset_counters(struct net_device *dev)
{
struct rtl8169_private *tp = netdev_priv(dev);
if (tp->mac_version < RTL_GIGA_MAC_VER_19)
return true;
return rtl8169_do_counters(dev, CounterReset);
}
static bool rtl8169_update_counters(struct net_device *dev)
{
struct rtl8169_private *tp = netdev_priv(dev);
void __iomem *ioaddr = tp->mmio_addr;
if ((RTL_R8(ChipCmd) & CmdRxEnb) == 0)
return true;
return rtl8169_do_counters(dev, CounterDump);
}
static bool rtl8169_init_counter_offsets(struct net_device *dev)
{
struct rtl8169_private *tp = netdev_priv(dev);
struct rtl8169_counters *counters = tp->counters;
bool ret = false;
if (tp->tc_offset.inited)
return true;
if (rtl8169_reset_counters(dev))
ret = true;
if (rtl8169_update_counters(dev))
ret = true;
tp->tc_offset.tx_errors = counters->tx_errors;
tp->tc_offset.tx_multi_collision = counters->tx_multi_collision;
tp->tc_offset.tx_aborted = counters->tx_aborted;
tp->tc_offset.inited = true;
return ret;
}
static void rtl8169_get_ethtool_stats(struct net_device *dev,
struct ethtool_stats *stats, u64 *data)
{
struct rtl8169_private *tp = netdev_priv(dev);
struct device *d = &tp->pci_dev->dev;
struct rtl8169_counters *counters = tp->counters;
ASSERT_RTNL();
pm_runtime_get_noresume(d);
if (pm_runtime_active(d))
rtl8169_update_counters(dev);
pm_runtime_put_noidle(d);
data[0] = le64_to_cpu(counters->tx_packets);
data[1] = le64_to_cpu(counters->rx_packets);
data[2] = le64_to_cpu(counters->tx_errors);
data[3] = le32_to_cpu(counters->rx_errors);
data[4] = le16_to_cpu(counters->rx_missed);
data[5] = le16_to_cpu(counters->align_errors);
data[6] = le32_to_cpu(counters->tx_one_collision);
data[7] = le32_to_cpu(counters->tx_multi_collision);
data[8] = le64_to_cpu(counters->rx_unicast);
data[9] = le64_to_cpu(counters->rx_broadcast);
data[10] = le32_to_cpu(counters->rx_multicast);
data[11] = le16_to_cpu(counters->tx_aborted);
data[12] = le16_to_cpu(counters->tx_underun);
}
static void rtl8169_get_strings(struct net_device *dev, u32 stringset, u8 *data)
{
switch(stringset) {
case ETH_SS_STATS:
memcpy(data, *rtl8169_gstrings, sizeof(rtl8169_gstrings));
break;
}
}
static int rtl8169_nway_reset(struct net_device *dev)
{
struct rtl8169_private *tp = netdev_priv(dev);
return mii_nway_restart(&tp->mii);
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
{ 0x7cf00000, 0x50200000, RTL_GIGA_MAC_VER_51 },
{ 0x7cf00000, 0x50100000, RTL_GIGA_MAC_VER_50 },
{ 0x7cf00000, 0x50000000, RTL_GIGA_MAC_VER_49 },
{ 0x7cf00000, 0x54100000, RTL_GIGA_MAC_VER_46 },
{ 0x7cf00000, 0x54000000, RTL_GIGA_MAC_VER_45 },
{ 0x7cf00000, 0x5c800000, RTL_GIGA_MAC_VER_44 },
{ 0x7cf00000, 0x50900000, RTL_GIGA_MAC_VER_42 },
{ 0x7cf00000, 0x4c100000, RTL_GIGA_MAC_VER_41 },
{ 0x7cf00000, 0x4c000000, RTL_GIGA_MAC_VER_40 },
{ 0x7c800000, 0x48800000, RTL_GIGA_MAC_VER_38 },
{ 0x7cf00000, 0x48100000, RTL_GIGA_MAC_VER_36 },
{ 0x7cf00000, 0x48000000, RTL_GIGA_MAC_VER_35 },
{ 0x7c800000, 0x2c800000, RTL_GIGA_MAC_VER_34 },
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
{ 0x7cf00000, 0x44900000, RTL_GIGA_MAC_VER_39 },
{ 0x7c800000, 0x44800000, RTL_GIGA_MAC_VER_39 },
{ 0x7c800000, 0x44000000, RTL_GIGA_MAC_VER_37 },
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
} else if (tp->mac_version == RTL_GIGA_MAC_VER_42) {
tp->mac_version = tp->mii.supports_gmii ?
RTL_GIGA_MAC_VER_42 :
RTL_GIGA_MAC_VER_43;
} else if (tp->mac_version == RTL_GIGA_MAC_VER_45) {
tp->mac_version = tp->mii.supports_gmii ?
RTL_GIGA_MAC_VER_45 :
RTL_GIGA_MAC_VER_47;
} else if (tp->mac_version == RTL_GIGA_MAC_VER_46) {
tp->mac_version = tp->mii.supports_gmii ?
RTL_GIGA_MAC_VER_46 :
RTL_GIGA_MAC_VER_48;
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
static bool rtl_fw_format_ok(struct rtl8169_private *tp, struct rtl_fw *rtl_fw)
{
const struct firmware *fw = rtl_fw->fw;
struct fw_info *fw_info = (struct fw_info *)fw->data;
struct rtl_fw_phy_action *pa = &rtl_fw->phy_action;
char *version = rtl_fw->version;
bool rc = false;
if (fw->size < FW_OPCODE_SIZE)
goto out;
if (!fw_info->magic) {
size_t i, size, start;
u8 checksum = 0;
if (fw->size < sizeof(*fw_info))
goto out;
for (i = 0; i < fw->size; i++)
checksum += fw->data[i];
if (checksum != 0)
goto out;
start = le32_to_cpu(fw_info->fw_start);
if (start > fw->size)
goto out;
size = le32_to_cpu(fw_info->fw_len);
if (size > (fw->size - start) / FW_OPCODE_SIZE)
goto out;
memcpy(version, fw_info->version, RTL_VER_SIZE);
pa->code = (__le32 *)(fw->data + start);
pa->size = size;
} else {
if (fw->size % FW_OPCODE_SIZE)
goto out;
strlcpy(version, rtl_lookup_firmware_name(tp), RTL_VER_SIZE);
pa->code = (__le32 *)fw->data;
pa->size = fw->size / FW_OPCODE_SIZE;
}
version[RTL_VER_SIZE - 1] = 0;
rc = true;
out:
return rc;
}
static bool rtl_fw_data_ok(struct rtl8169_private *tp, struct net_device *dev,
struct rtl_fw_phy_action *pa)
{
bool rc = false;
size_t index;
for (index = 0; index < pa->size; index++) {
u32 action = le32_to_cpu(pa->code[index]);
u32 regno = (action & 0x0fff0000) >> 16;
switch(action & 0xf0000000) {
case PHY_READ:
case PHY_DATA_OR:
case PHY_DATA_AND:
case PHY_MDIO_CHG:
case PHY_CLEAR_READCOUNT:
case PHY_WRITE:
case PHY_WRITE_PREVIOUS:
case PHY_DELAY_MS:
break;
case PHY_BJMPN:
if (regno > index) {
netif_err(tp, ifup, tp->dev,
"Out of range of firmware\n");
goto out;
}
break;
case PHY_READCOUNT_EQ_SKIP:
if (index + 2 >= pa->size) {
netif_err(tp, ifup, tp->dev,
"Out of range of firmware\n");
goto out;
}
break;
case PHY_COMP_EQ_SKIPN:
case PHY_COMP_NEQ_SKIPN:
case PHY_SKIPN:
if (index + 1 + regno >= pa->size) {
netif_err(tp, ifup, tp->dev,
"Out of range of firmware\n");
goto out;
}
break;
default:
netif_err(tp, ifup, tp->dev,
"Invalid action 0x%08x\n", action);
goto out;
}
}
rc = true;
out:
return rc;
}
static int rtl_check_firmware(struct rtl8169_private *tp, struct rtl_fw *rtl_fw)
{
struct net_device *dev = tp->dev;
int rc = -EINVAL;
if (!rtl_fw_format_ok(tp, rtl_fw)) {
netif_err(tp, ifup, dev, "invalid firmware\n");
goto out;
}
if (rtl_fw_data_ok(tp, dev, &rtl_fw->phy_action))
rc = 0;
out:
return rc;
}
static void rtl_phy_write_fw(struct rtl8169_private *tp, struct rtl_fw *rtl_fw)
{
struct rtl_fw_phy_action *pa = &rtl_fw->phy_action;
struct mdio_ops org, *ops = &tp->mdio_ops;
u32 predata, count;
size_t index;
predata = count = 0;
org.write = ops->write;
org.read = ops->read;
for (index = 0; index < pa->size; ) {
u32 action = le32_to_cpu(pa->code[index]);
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
case PHY_MDIO_CHG:
if (data == 0) {
ops->write = org.write;
ops->read = org.read;
} else if (data == 1) {
ops->write = mac_mcu_write;
ops->read = mac_mcu_read;
}
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
default:
BUG();
}
}
ops->write = org.write;
ops->read = org.read;
}
static void rtl_release_firmware(struct rtl8169_private *tp)
{
if (!IS_ERR_OR_NULL(tp->rtl_fw)) {
release_firmware(tp->rtl_fw->fw);
kfree(tp->rtl_fw);
}
tp->rtl_fw = RTL_FIRMWARE_UNKNOWN;
}
static void rtl_apply_firmware(struct rtl8169_private *tp)
{
struct rtl_fw *rtl_fw = tp->rtl_fw;
if (!IS_ERR_OR_NULL(rtl_fw))
rtl_phy_write_fw(tp, rtl_fw);
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
if ((pdev->subsystem_vendor != PCI_VENDOR_ID_GIGABYTE) ||
(pdev->subsystem_device != 0xe000))
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
rtl_writephy_batch(tp, phy_reg_init_0, ARRAY_SIZE(phy_reg_init_0));
rtl_writephy(tp, 0x1f, 0x0002);
rtl_w0w1_phy(tp, 0x0b, 0x0010, 0x00ef);
rtl_w0w1_phy(tp, 0x0c, 0xa200, 0x5d00);
if (rtl8168d_efuse_read(tp, 0x01) == 0xb1) {
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
rtl_w0w1_phy(tp, 0x02, 0x0100, 0x0600);
rtl_w0w1_phy(tp, 0x03, 0x0000, 0xe000);
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
rtl_writephy_batch(tp, phy_reg_init_0, ARRAY_SIZE(phy_reg_init_0));
if (rtl8168d_efuse_read(tp, 0x01) == 0xb1) {
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
rtl_w0w1_phy(tp, 0x02, 0x0100, 0x0600);
rtl_w0w1_phy(tp, 0x03, 0x0000, 0xe000);
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
static void rtl8168e_1_hw_phy_config(struct rtl8169_private *tp)
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
rtl_w0w1_phy(tp, 0x17, 0x0006, 0x0000);
rtl_writephy(tp, 0x1f, 0x0000);
rtl_writephy(tp, 0x1f, 0x0002);
rtl_w0w1_phy(tp, 0x08, 0x8000, 0x7f00);
rtl_writephy(tp, 0x1f, 0x0000);
rtl_writephy(tp, 0x1f, 0x0007);
rtl_writephy(tp, 0x1e, 0x002d);
rtl_w0w1_phy(tp, 0x18, 0x0050, 0x0000);
rtl_writephy(tp, 0x1f, 0x0000);
rtl_w0w1_phy(tp, 0x14, 0x8000, 0x0000);
rtl_writephy(tp, 0x1f, 0x0005);
rtl_writephy(tp, 0x05, 0x8b86);
rtl_w0w1_phy(tp, 0x06, 0x0001, 0x0000);
rtl_writephy(tp, 0x1f, 0x0000);
rtl_writephy(tp, 0x1f, 0x0005);
rtl_writephy(tp, 0x05, 0x8b85);
rtl_w0w1_phy(tp, 0x06, 0x0000, 0x2000);
rtl_writephy(tp, 0x1f, 0x0007);
rtl_writephy(tp, 0x1e, 0x0020);
rtl_w0w1_phy(tp, 0x15, 0x0000, 0x1100);
rtl_writephy(tp, 0x1f, 0x0006);
rtl_writephy(tp, 0x00, 0x5a00);
rtl_writephy(tp, 0x1f, 0x0000);
rtl_writephy(tp, 0x0d, 0x0007);
rtl_writephy(tp, 0x0e, 0x003c);
rtl_writephy(tp, 0x0d, 0x4007);
rtl_writephy(tp, 0x0e, 0x0000);
rtl_writephy(tp, 0x0d, 0x0000);
}
static void rtl_rar_exgmac_set(struct rtl8169_private *tp, u8 *addr)
{
const u16 w[] = {
addr[0] | (addr[1] << 8),
addr[2] | (addr[3] << 8),
addr[4] | (addr[5] << 8)
};
const struct exgmac_reg e[] = {
{ .addr = 0xe0, ERIAR_MASK_1111, .val = w[0] | (w[1] << 16) },
{ .addr = 0xe4, ERIAR_MASK_1111, .val = w[2] },
{ .addr = 0xf0, ERIAR_MASK_1111, .val = w[0] << 16 },
{ .addr = 0xf4, ERIAR_MASK_1111, .val = w[1] | (w[2] << 16) }
};
rtl_write_exgmac_batch(tp, e, ARRAY_SIZE(e));
}
static void rtl8168e_2_hw_phy_config(struct rtl8169_private *tp)
{
static const struct phy_reg phy_reg_init[] = {
{ 0x1f, 0x0004 },
{ 0x1f, 0x0007 },
{ 0x1e, 0x00ac },
{ 0x18, 0x0006 },
{ 0x1f, 0x0002 },
{ 0x1f, 0x0000 },
{ 0x1f, 0x0000 },
{ 0x1f, 0x0003 },
{ 0x09, 0xa20f },
{ 0x1f, 0x0000 },
{ 0x1f, 0x0000 },
{ 0x1f, 0x0005 },
{ 0x05, 0x8b5b },
{ 0x06, 0x9222 },
{ 0x05, 0x8b6d },
{ 0x06, 0x8000 },
{ 0x05, 0x8b76 },
{ 0x06, 0x8000 },
{ 0x1f, 0x0000 }
};
rtl_apply_firmware(tp);
rtl_writephy_batch(tp, phy_reg_init, ARRAY_SIZE(phy_reg_init));
rtl_writephy(tp, 0x1f, 0x0005);
rtl_writephy(tp, 0x05, 0x8b80);
rtl_w0w1_phy(tp, 0x17, 0x0006, 0x0000);
rtl_writephy(tp, 0x1f, 0x0000);
rtl_writephy(tp, 0x1f, 0x0004);
rtl_writephy(tp, 0x1f, 0x0007);
rtl_writephy(tp, 0x1e, 0x002d);
rtl_w0w1_phy(tp, 0x18, 0x0010, 0x0000);
rtl_writephy(tp, 0x1f, 0x0002);
rtl_writephy(tp, 0x1f, 0x0000);
rtl_w0w1_phy(tp, 0x14, 0x8000, 0x0000);
rtl_writephy(tp, 0x1f, 0x0005);
rtl_writephy(tp, 0x05, 0x8b86);
rtl_w0w1_phy(tp, 0x06, 0x0001, 0x0000);
rtl_writephy(tp, 0x1f, 0x0000);
rtl_writephy(tp, 0x1f, 0x0005);
rtl_writephy(tp, 0x05, 0x8b85);
rtl_w0w1_phy(tp, 0x06, 0x4000, 0x0000);
rtl_writephy(tp, 0x1f, 0x0000);
rtl_w0w1_eri(tp, 0x1b0, ERIAR_MASK_1111, 0x0000, 0x0003, ERIAR_EXGMAC);
rtl_writephy(tp, 0x1f, 0x0005);
rtl_writephy(tp, 0x05, 0x8b85);
rtl_w0w1_phy(tp, 0x06, 0x0000, 0x2000);
rtl_writephy(tp, 0x1f, 0x0004);
rtl_writephy(tp, 0x1f, 0x0007);
rtl_writephy(tp, 0x1e, 0x0020);
rtl_w0w1_phy(tp, 0x15, 0x0000, 0x0100);
rtl_writephy(tp, 0x1f, 0x0002);
rtl_writephy(tp, 0x1f, 0x0000);
rtl_writephy(tp, 0x0d, 0x0007);
rtl_writephy(tp, 0x0e, 0x003c);
rtl_writephy(tp, 0x0d, 0x4007);
rtl_writephy(tp, 0x0e, 0x0000);
rtl_writephy(tp, 0x0d, 0x0000);
rtl_writephy(tp, 0x1f, 0x0003);
rtl_w0w1_phy(tp, 0x19, 0x0000, 0x0001);
rtl_w0w1_phy(tp, 0x10, 0x0000, 0x0400);
rtl_writephy(tp, 0x1f, 0x0000);
rtl_rar_exgmac_set(tp, tp->dev->dev_addr);
}
static void rtl8168f_hw_phy_config(struct rtl8169_private *tp)
{
rtl_writephy(tp, 0x1f, 0x0005);
rtl_writephy(tp, 0x05, 0x8b80);
rtl_w0w1_phy(tp, 0x06, 0x0006, 0x0000);
rtl_writephy(tp, 0x1f, 0x0000);
rtl_writephy(tp, 0x1f, 0x0007);
rtl_writephy(tp, 0x1e, 0x002d);
rtl_w0w1_phy(tp, 0x18, 0x0010, 0x0000);
rtl_writephy(tp, 0x1f, 0x0000);
rtl_w0w1_phy(tp, 0x14, 0x8000, 0x0000);
rtl_writephy(tp, 0x1f, 0x0005);
rtl_writephy(tp, 0x05, 0x8b86);
rtl_w0w1_phy(tp, 0x06, 0x0001, 0x0000);
rtl_writephy(tp, 0x1f, 0x0000);
}
static void rtl8168f_1_hw_phy_config(struct rtl8169_private *tp)
{
static const struct phy_reg phy_reg_init[] = {
{ 0x1f, 0x0003 },
{ 0x09, 0xa20f },
{ 0x1f, 0x0000 },
{ 0x1f, 0x0005 },
{ 0x05, 0x8b55 },
{ 0x06, 0x0000 },
{ 0x05, 0x8b5e },
{ 0x06, 0x0000 },
{ 0x05, 0x8b67 },
{ 0x06, 0x0000 },
{ 0x05, 0x8b70 },
{ 0x06, 0x0000 },
{ 0x1f, 0x0000 },
{ 0x1f, 0x0007 },
{ 0x1e, 0x0078 },
{ 0x17, 0x0000 },
{ 0x19, 0x00fb },
{ 0x1f, 0x0000 },
{ 0x1f, 0x0005 },
{ 0x05, 0x8b79 },
{ 0x06, 0xaa00 },
{ 0x1f, 0x0000 },
{ 0x1f, 0x0003 },
{ 0x01, 0x328a },
{ 0x1f, 0x0000 }
};
rtl_apply_firmware(tp);
rtl_writephy_batch(tp, phy_reg_init, ARRAY_SIZE(phy_reg_init));
rtl8168f_hw_phy_config(tp);
rtl_writephy(tp, 0x1f, 0x0005);
rtl_writephy(tp, 0x05, 0x8b85);
rtl_w0w1_phy(tp, 0x06, 0x4000, 0x0000);
rtl_writephy(tp, 0x1f, 0x0000);
}
static void rtl8168f_2_hw_phy_config(struct rtl8169_private *tp)
{
rtl_apply_firmware(tp);
rtl8168f_hw_phy_config(tp);
}
static void rtl8411_hw_phy_config(struct rtl8169_private *tp)
{
static const struct phy_reg phy_reg_init[] = {
{ 0x1f, 0x0003 },
{ 0x09, 0xa20f },
{ 0x1f, 0x0000 },
{ 0x1f, 0x0005 },
{ 0x05, 0x8b55 },
{ 0x06, 0x0000 },
{ 0x05, 0x8b5e },
{ 0x06, 0x0000 },
{ 0x05, 0x8b67 },
{ 0x06, 0x0000 },
{ 0x05, 0x8b70 },
{ 0x06, 0x0000 },
{ 0x1f, 0x0000 },
{ 0x1f, 0x0007 },
{ 0x1e, 0x0078 },
{ 0x17, 0x0000 },
{ 0x19, 0x00aa },
{ 0x1f, 0x0000 },
{ 0x1f, 0x0005 },
{ 0x05, 0x8b79 },
{ 0x06, 0xaa00 },
{ 0x1f, 0x0000 },
{ 0x1f, 0x0003 },
{ 0x01, 0x328a },
{ 0x1f, 0x0000 }
};
rtl_apply_firmware(tp);
rtl8168f_hw_phy_config(tp);
rtl_writephy(tp, 0x1f, 0x0005);
rtl_writephy(tp, 0x05, 0x8b85);
rtl_w0w1_phy(tp, 0x06, 0x4000, 0x0000);
rtl_writephy(tp, 0x1f, 0x0000);
rtl_writephy_batch(tp, phy_reg_init, ARRAY_SIZE(phy_reg_init));
rtl_writephy(tp, 0x1f, 0x0005);
rtl_writephy(tp, 0x05, 0x8b54);
rtl_w0w1_phy(tp, 0x06, 0x0000, 0x0800);
rtl_writephy(tp, 0x05, 0x8b5d);
rtl_w0w1_phy(tp, 0x06, 0x0000, 0x0800);
rtl_writephy(tp, 0x05, 0x8a7c);
rtl_w0w1_phy(tp, 0x06, 0x0000, 0x0100);
rtl_writephy(tp, 0x05, 0x8a7f);
rtl_w0w1_phy(tp, 0x06, 0x0100, 0x0000);
rtl_writephy(tp, 0x05, 0x8a82);
rtl_w0w1_phy(tp, 0x06, 0x0000, 0x0100);
rtl_writephy(tp, 0x05, 0x8a85);
rtl_w0w1_phy(tp, 0x06, 0x0000, 0x0100);
rtl_writephy(tp, 0x05, 0x8a88);
rtl_w0w1_phy(tp, 0x06, 0x0000, 0x0100);
rtl_writephy(tp, 0x1f, 0x0000);
rtl_writephy(tp, 0x1f, 0x0005);
rtl_writephy(tp, 0x05, 0x8b85);
rtl_w0w1_phy(tp, 0x06, 0x8000, 0x0000);
rtl_writephy(tp, 0x1f, 0x0000);
rtl_w0w1_eri(tp, 0x1b0, ERIAR_MASK_0001, 0x00, 0x03, ERIAR_EXGMAC);
rtl_writephy(tp, 0x1f, 0x0005);
rtl_writephy(tp, 0x05, 0x8b85);
rtl_w0w1_phy(tp, 0x06, 0x0000, 0x2000);
rtl_writephy(tp, 0x1f, 0x0004);
rtl_writephy(tp, 0x1f, 0x0007);
rtl_writephy(tp, 0x1e, 0x0020);
rtl_w0w1_phy(tp, 0x15, 0x0000, 0x0100);
rtl_writephy(tp, 0x1f, 0x0000);
rtl_writephy(tp, 0x0d, 0x0007);
rtl_writephy(tp, 0x0e, 0x003c);
rtl_writephy(tp, 0x0d, 0x4007);
rtl_writephy(tp, 0x0e, 0x0000);
rtl_writephy(tp, 0x0d, 0x0000);
rtl_writephy(tp, 0x1f, 0x0003);
rtl_w0w1_phy(tp, 0x19, 0x0000, 0x0001);
rtl_w0w1_phy(tp, 0x10, 0x0000, 0x0400);
rtl_writephy(tp, 0x1f, 0x0000);
}
static void rtl8168g_1_hw_phy_config(struct rtl8169_private *tp)
{
rtl_apply_firmware(tp);
rtl_writephy(tp, 0x1f, 0x0a46);
if (rtl_readphy(tp, 0x10) & 0x0100) {
rtl_writephy(tp, 0x1f, 0x0bcc);
rtl_w0w1_phy(tp, 0x12, 0x0000, 0x8000);
} else {
rtl_writephy(tp, 0x1f, 0x0bcc);
rtl_w0w1_phy(tp, 0x12, 0x8000, 0x0000);
}
rtl_writephy(tp, 0x1f, 0x0a46);
if (rtl_readphy(tp, 0x13) & 0x0100) {
rtl_writephy(tp, 0x1f, 0x0c41);
rtl_w0w1_phy(tp, 0x15, 0x0002, 0x0000);
} else {
rtl_writephy(tp, 0x1f, 0x0c41);
rtl_w0w1_phy(tp, 0x15, 0x0000, 0x0002);
}
rtl_writephy(tp, 0x1f, 0x0a44);
rtl_w0w1_phy(tp, 0x11, 0x000c, 0x0000);
rtl_writephy(tp, 0x1f, 0x0bcc);
rtl_w0w1_phy(tp, 0x14, 0x0100, 0x0000);
rtl_writephy(tp, 0x1f, 0x0a44);
rtl_w0w1_phy(tp, 0x11, 0x00c0, 0x0000);
rtl_writephy(tp, 0x1f, 0x0a43);
rtl_writephy(tp, 0x13, 0x8084);
rtl_w0w1_phy(tp, 0x14, 0x0000, 0x6000);
rtl_w0w1_phy(tp, 0x10, 0x1003, 0x0000);
rtl_writephy(tp, 0x1f, 0x0a4b);
rtl_w0w1_phy(tp, 0x11, 0x0004, 0x0000);
rtl_writephy(tp, 0x1f, 0x0a43);
rtl_writephy(tp, 0x13, 0x8012);
rtl_w0w1_phy(tp, 0x14, 0x8000, 0x0000);
rtl_writephy(tp, 0x1f, 0x0c42);
rtl_w0w1_phy(tp, 0x11, 0x4000, 0x2000);
rtl_writephy(tp, 0x1f, 0x0bcd);
rtl_writephy(tp, 0x14, 0x5065);
rtl_writephy(tp, 0x14, 0xd065);
rtl_writephy(tp, 0x1f, 0x0bc8);
rtl_writephy(tp, 0x11, 0x5655);
rtl_writephy(tp, 0x1f, 0x0bcd);
rtl_writephy(tp, 0x14, 0x1065);
rtl_writephy(tp, 0x14, 0x9065);
rtl_writephy(tp, 0x14, 0x1065);
rtl_writephy(tp, 0x1f, 0x0a43);
if (rtl_readphy(tp, 0x10) & 0x0004)
rtl_w0w1_phy(tp, 0x10, 0x0000, 0x0004);
rtl_writephy(tp, 0x1f, 0x0000);
}
static void rtl8168g_2_hw_phy_config(struct rtl8169_private *tp)
{
rtl_apply_firmware(tp);
}
static void rtl8168h_1_hw_phy_config(struct rtl8169_private *tp)
{
u16 dout_tapbin;
u32 data;
rtl_apply_firmware(tp);
rtl_writephy(tp, 0x1f, 0x0a43);
rtl_writephy(tp, 0x13, 0x809b);
rtl_w0w1_phy(tp, 0x14, 0x8000, 0xf800);
rtl_writephy(tp, 0x13, 0x80a2);
rtl_w0w1_phy(tp, 0x14, 0x8000, 0xff00);
rtl_writephy(tp, 0x13, 0x80a4);
rtl_w0w1_phy(tp, 0x14, 0x8500, 0xff00);
rtl_writephy(tp, 0x13, 0x809c);
rtl_w0w1_phy(tp, 0x14, 0xbd00, 0xff00);
rtl_writephy(tp, 0x1f, 0x0000);
rtl_writephy(tp, 0x1f, 0x0a43);
rtl_writephy(tp, 0x13, 0x80ad);
rtl_w0w1_phy(tp, 0x14, 0x7000, 0xf800);
rtl_writephy(tp, 0x13, 0x80b4);
rtl_w0w1_phy(tp, 0x14, 0x5000, 0xff00);
rtl_writephy(tp, 0x13, 0x80ac);
rtl_w0w1_phy(tp, 0x14, 0x4000, 0xff00);
rtl_writephy(tp, 0x1f, 0x0000);
rtl_writephy(tp, 0x1f, 0x0a43);
rtl_writephy(tp, 0x13, 0x808e);
rtl_w0w1_phy(tp, 0x14, 0x1200, 0xff00);
rtl_writephy(tp, 0x13, 0x8090);
rtl_w0w1_phy(tp, 0x14, 0xe500, 0xff00);
rtl_writephy(tp, 0x13, 0x8092);
rtl_w0w1_phy(tp, 0x14, 0x9f00, 0xff00);
rtl_writephy(tp, 0x1f, 0x0000);
dout_tapbin = 0;
rtl_writephy(tp, 0x1f, 0x0a46);
data = rtl_readphy(tp, 0x13);
data &= 3;
data <<= 2;
dout_tapbin |= data;
data = rtl_readphy(tp, 0x12);
data &= 0xc000;
data >>= 14;
dout_tapbin |= data;
dout_tapbin = ~(dout_tapbin^0x08);
dout_tapbin <<= 12;
dout_tapbin &= 0xf000;
rtl_writephy(tp, 0x1f, 0x0a43);
rtl_writephy(tp, 0x13, 0x827a);
rtl_w0w1_phy(tp, 0x14, dout_tapbin, 0xf000);
rtl_writephy(tp, 0x13, 0x827b);
rtl_w0w1_phy(tp, 0x14, dout_tapbin, 0xf000);
rtl_writephy(tp, 0x13, 0x827c);
rtl_w0w1_phy(tp, 0x14, dout_tapbin, 0xf000);
rtl_writephy(tp, 0x13, 0x827d);
rtl_w0w1_phy(tp, 0x14, dout_tapbin, 0xf000);
rtl_writephy(tp, 0x1f, 0x0a43);
rtl_writephy(tp, 0x13, 0x0811);
rtl_w0w1_phy(tp, 0x14, 0x0800, 0x0000);
rtl_writephy(tp, 0x1f, 0x0a42);
rtl_w0w1_phy(tp, 0x16, 0x0002, 0x0000);
rtl_writephy(tp, 0x1f, 0x0000);
rtl_writephy(tp, 0x1f, 0x0a44);
rtl_w0w1_phy(tp, 0x11, 0x0800, 0x0000);
rtl_writephy(tp, 0x1f, 0x0000);
rtl_writephy(tp, 0x1f, 0x0bca);
rtl_w0w1_phy(tp, 0x17, 0x4000, 0x3000);
rtl_writephy(tp, 0x1f, 0x0000);
rtl_writephy(tp, 0x1f, 0x0a43);
rtl_writephy(tp, 0x13, 0x803f);
rtl_w0w1_phy(tp, 0x14, 0x0000, 0x3000);
rtl_writephy(tp, 0x13, 0x8047);
rtl_w0w1_phy(tp, 0x14, 0x0000, 0x3000);
rtl_writephy(tp, 0x13, 0x804f);
rtl_w0w1_phy(tp, 0x14, 0x0000, 0x3000);
rtl_writephy(tp, 0x13, 0x8057);
rtl_w0w1_phy(tp, 0x14, 0x0000, 0x3000);
rtl_writephy(tp, 0x13, 0x805f);
rtl_w0w1_phy(tp, 0x14, 0x0000, 0x3000);
rtl_writephy(tp, 0x13, 0x8067);
rtl_w0w1_phy(tp, 0x14, 0x0000, 0x3000);
rtl_writephy(tp, 0x13, 0x806f);
rtl_w0w1_phy(tp, 0x14, 0x0000, 0x3000);
rtl_writephy(tp, 0x1f, 0x0000);
rtl_writephy(tp, 0x1f, 0x0a44);
rtl_w0w1_phy(tp, 0x11, 0x0000, 0x0080);
rtl_writephy(tp, 0x1f, 0x0000);
rtl_writephy(tp, 0x1f, 0x0a43);
if (rtl_readphy(tp, 0x10) & 0x0004)
rtl_w0w1_phy(tp, 0x10, 0x0000, 0x0004);
rtl_writephy(tp, 0x1f, 0x0000);
}
static void rtl8168h_2_hw_phy_config(struct rtl8169_private *tp)
{
u16 ioffset_p3, ioffset_p2, ioffset_p1, ioffset_p0;
u16 rlen;
u32 data;
rtl_apply_firmware(tp);
rtl_writephy(tp, 0x1f, 0x0a43);
rtl_writephy(tp, 0x13, 0x808a);
rtl_w0w1_phy(tp, 0x14, 0x000a, 0x003f);
rtl_writephy(tp, 0x1f, 0x0000);
rtl_writephy(tp, 0x1f, 0x0a43);
rtl_writephy(tp, 0x13, 0x0811);
rtl_w0w1_phy(tp, 0x14, 0x0800, 0x0000);
rtl_writephy(tp, 0x1f, 0x0a42);
rtl_w0w1_phy(tp, 0x16, 0x0002, 0x0000);
rtl_writephy(tp, 0x1f, 0x0000);
rtl_writephy(tp, 0x1f, 0x0a44);
rtl_w0w1_phy(tp, 0x11, 0x0800, 0x0000);
rtl_writephy(tp, 0x1f, 0x0000);
r8168_mac_ocp_write(tp, 0xdd02, 0x807d);
data = r8168_mac_ocp_read(tp, 0xdd02);
ioffset_p3 = ((data & 0x80)>>7);
ioffset_p3 <<= 3;
data = r8168_mac_ocp_read(tp, 0xdd00);
ioffset_p3 |= ((data & (0xe000))>>13);
ioffset_p2 = ((data & (0x1e00))>>9);
ioffset_p1 = ((data & (0x01e0))>>5);
ioffset_p0 = ((data & 0x0010)>>4);
ioffset_p0 <<= 3;
ioffset_p0 |= (data & (0x07));
data = (ioffset_p3<<12)|(ioffset_p2<<8)|(ioffset_p1<<4)|(ioffset_p0);
if ((ioffset_p3 != 0x0f) || (ioffset_p2 != 0x0f) ||
(ioffset_p1 != 0x0f) || (ioffset_p0 != 0x0f)) {
rtl_writephy(tp, 0x1f, 0x0bcf);
rtl_writephy(tp, 0x16, data);
rtl_writephy(tp, 0x1f, 0x0000);
}
rtl_writephy(tp, 0x1f, 0x0bcd);
data = rtl_readphy(tp, 0x16);
data &= 0x000f;
rlen = 0;
if (data > 3)
rlen = data - 3;
data = rlen | (rlen<<4) | (rlen<<8) | (rlen<<12);
rtl_writephy(tp, 0x17, data);
rtl_writephy(tp, 0x1f, 0x0bcd);
rtl_writephy(tp, 0x1f, 0x0000);
rtl_writephy(tp, 0x1f, 0x0a44);
rtl_w0w1_phy(tp, 0x11, 0x0000, 0x0080);
rtl_writephy(tp, 0x1f, 0x0000);
rtl_writephy(tp, 0x1f, 0x0a43);
if (rtl_readphy(tp, 0x10) & 0x0004)
rtl_w0w1_phy(tp, 0x10, 0x0000, 0x0004);
rtl_writephy(tp, 0x1f, 0x0000);
}
static void rtl8168ep_1_hw_phy_config(struct rtl8169_private *tp)
{
rtl_writephy(tp, 0x1f, 0x0a44);
rtl_w0w1_phy(tp, 0x11, 0x000c, 0x0000);
rtl_writephy(tp, 0x1f, 0x0000);
rtl_writephy(tp, 0x1f, 0x0bcc);
rtl_w0w1_phy(tp, 0x14, 0x0000, 0x0100);
rtl_writephy(tp, 0x1f, 0x0a44);
rtl_w0w1_phy(tp, 0x11, 0x00c0, 0x0000);
rtl_writephy(tp, 0x1f, 0x0a43);
rtl_writephy(tp, 0x13, 0x8084);
rtl_w0w1_phy(tp, 0x14, 0x0000, 0x6000);
rtl_w0w1_phy(tp, 0x10, 0x1003, 0x0000);
rtl_writephy(tp, 0x1f, 0x0000);
rtl_writephy(tp, 0x1f, 0x0a4b);
rtl_w0w1_phy(tp, 0x11, 0x0004, 0x0000);
rtl_writephy(tp, 0x1f, 0x0000);
rtl_writephy(tp, 0x1f, 0x0a43);
rtl_writephy(tp, 0x13, 0x8012);
rtl_w0w1_phy(tp, 0x14, 0x8000, 0x0000);
rtl_writephy(tp, 0x1f, 0x0000);
rtl_writephy(tp, 0x1f, 0x0c42);
rtl_w0w1_phy(tp, 0x11, 0x4000, 0x2000);
rtl_writephy(tp, 0x1f, 0x0000);
rtl_writephy(tp, 0x1f, 0x0a43);
if (rtl_readphy(tp, 0x10) & 0x0004)
rtl_w0w1_phy(tp, 0x10, 0x0000, 0x0004);
rtl_writephy(tp, 0x1f, 0x0000);
}
static void rtl8168ep_2_hw_phy_config(struct rtl8169_private *tp)
{
rtl_writephy(tp, 0x1f, 0x0bcc);
rtl_w0w1_phy(tp, 0x14, 0x0000, 0x0100);
rtl_writephy(tp, 0x1f, 0x0a44);
rtl_w0w1_phy(tp, 0x11, 0x00c0, 0x0000);
rtl_writephy(tp, 0x1f, 0x0a43);
rtl_writephy(tp, 0x13, 0x8084);
rtl_w0w1_phy(tp, 0x14, 0x0000, 0x6000);
rtl_w0w1_phy(tp, 0x10, 0x1003, 0x0000);
rtl_writephy(tp, 0x1f, 0x0000);
rtl_writephy(tp, 0x1f, 0x0a43);
rtl_writephy(tp, 0x13, 0x8012);
rtl_w0w1_phy(tp, 0x14, 0x8000, 0x0000);
rtl_writephy(tp, 0x1f, 0x0000);
rtl_writephy(tp, 0x1f, 0x0c42);
rtl_w0w1_phy(tp, 0x11, 0x4000, 0x2000);
rtl_writephy(tp, 0x1f, 0x0000);
rtl_writephy(tp, 0x1f, 0x0a43);
rtl_writephy(tp, 0x13, 0x80f3);
rtl_w0w1_phy(tp, 0x14, 0x8b00, ~0x8bff);
rtl_writephy(tp, 0x13, 0x80f0);
rtl_w0w1_phy(tp, 0x14, 0x3a00, ~0x3aff);
rtl_writephy(tp, 0x13, 0x80ef);
rtl_w0w1_phy(tp, 0x14, 0x0500, ~0x05ff);
rtl_writephy(tp, 0x13, 0x80f6);
rtl_w0w1_phy(tp, 0x14, 0x6e00, ~0x6eff);
rtl_writephy(tp, 0x13, 0x80ec);
rtl_w0w1_phy(tp, 0x14, 0x6800, ~0x68ff);
rtl_writephy(tp, 0x13, 0x80ed);
rtl_w0w1_phy(tp, 0x14, 0x7c00, ~0x7cff);
rtl_writephy(tp, 0x13, 0x80f2);
rtl_w0w1_phy(tp, 0x14, 0xf400, ~0xf4ff);
rtl_writephy(tp, 0x13, 0x80f4);
rtl_w0w1_phy(tp, 0x14, 0x8500, ~0x85ff);
rtl_writephy(tp, 0x1f, 0x0a43);
rtl_writephy(tp, 0x13, 0x8110);
rtl_w0w1_phy(tp, 0x14, 0xa800, ~0xa8ff);
rtl_writephy(tp, 0x13, 0x810f);
rtl_w0w1_phy(tp, 0x14, 0x1d00, ~0x1dff);
rtl_writephy(tp, 0x13, 0x8111);
rtl_w0w1_phy(tp, 0x14, 0xf500, ~0xf5ff);
rtl_writephy(tp, 0x13, 0x8113);
rtl_w0w1_phy(tp, 0x14, 0x6100, ~0x61ff);
rtl_writephy(tp, 0x13, 0x8115);
rtl_w0w1_phy(tp, 0x14, 0x9200, ~0x92ff);
rtl_writephy(tp, 0x13, 0x810e);
rtl_w0w1_phy(tp, 0x14, 0x0400, ~0x04ff);
rtl_writephy(tp, 0x13, 0x810c);
rtl_w0w1_phy(tp, 0x14, 0x7c00, ~0x7cff);
rtl_writephy(tp, 0x13, 0x810b);
rtl_w0w1_phy(tp, 0x14, 0x5a00, ~0x5aff);
rtl_writephy(tp, 0x1f, 0x0a43);
rtl_writephy(tp, 0x13, 0x80d1);
rtl_w0w1_phy(tp, 0x14, 0xff00, ~0xffff);
rtl_writephy(tp, 0x13, 0x80cd);
rtl_w0w1_phy(tp, 0x14, 0x9e00, ~0x9eff);
rtl_writephy(tp, 0x13, 0x80d3);
rtl_w0w1_phy(tp, 0x14, 0x0e00, ~0x0eff);
rtl_writephy(tp, 0x13, 0x80d5);
rtl_w0w1_phy(tp, 0x14, 0xca00, ~0xcaff);
rtl_writephy(tp, 0x13, 0x80d7);
rtl_w0w1_phy(tp, 0x14, 0x8400, ~0x84ff);
rtl_writephy(tp, 0x1f, 0x0bcd);
rtl_writephy(tp, 0x14, 0x5065);
rtl_writephy(tp, 0x14, 0xd065);
rtl_writephy(tp, 0x1f, 0x0bc8);
rtl_writephy(tp, 0x12, 0x00ed);
rtl_writephy(tp, 0x1f, 0x0bcd);
rtl_writephy(tp, 0x14, 0x1065);
rtl_writephy(tp, 0x14, 0x9065);
rtl_writephy(tp, 0x14, 0x1065);
rtl_writephy(tp, 0x1f, 0x0000);
rtl_writephy(tp, 0x1f, 0x0a43);
if (rtl_readphy(tp, 0x10) & 0x0004)
rtl_w0w1_phy(tp, 0x10, 0x0000, 0x0004);
rtl_writephy(tp, 0x1f, 0x0000);
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
static void rtl8402_hw_phy_config(struct rtl8169_private *tp)
{
rtl_writephy(tp, 0x1f, 0x0000);
rtl_writephy(tp, 0x18, 0x0310);
msleep(20);
rtl_apply_firmware(tp);
rtl_eri_write(tp, 0x1b0, ERIAR_MASK_0011, 0x0000, ERIAR_EXGMAC);
rtl_writephy(tp, 0x1f, 0x0004);
rtl_writephy(tp, 0x10, 0x401f);
rtl_writephy(tp, 0x19, 0x7030);
rtl_writephy(tp, 0x1f, 0x0000);
}
static void rtl8106e_hw_phy_config(struct rtl8169_private *tp)
{
static const struct phy_reg phy_reg_init[] = {
{ 0x1f, 0x0004 },
{ 0x10, 0xc07f },
{ 0x19, 0x7030 },
{ 0x1f, 0x0000 }
};
rtl_writephy(tp, 0x1f, 0x0000);
rtl_writephy(tp, 0x18, 0x0310);
msleep(100);
rtl_apply_firmware(tp);
rtl_eri_write(tp, 0x1b0, ERIAR_MASK_0011, 0x0000, ERIAR_EXGMAC);
rtl_writephy_batch(tp, phy_reg_init, ARRAY_SIZE(phy_reg_init));
rtl_eri_write(tp, 0x1d0, ERIAR_MASK_0011, 0x0000, ERIAR_EXGMAC);
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
rtl8168e_1_hw_phy_config(tp);
break;
case RTL_GIGA_MAC_VER_34:
rtl8168e_2_hw_phy_config(tp);
break;
case RTL_GIGA_MAC_VER_35:
rtl8168f_1_hw_phy_config(tp);
break;
case RTL_GIGA_MAC_VER_36:
rtl8168f_2_hw_phy_config(tp);
break;
case RTL_GIGA_MAC_VER_37:
rtl8402_hw_phy_config(tp);
break;
case RTL_GIGA_MAC_VER_38:
rtl8411_hw_phy_config(tp);
break;
case RTL_GIGA_MAC_VER_39:
rtl8106e_hw_phy_config(tp);
break;
case RTL_GIGA_MAC_VER_40:
rtl8168g_1_hw_phy_config(tp);
break;
case RTL_GIGA_MAC_VER_42:
case RTL_GIGA_MAC_VER_43:
case RTL_GIGA_MAC_VER_44:
rtl8168g_2_hw_phy_config(tp);
break;
case RTL_GIGA_MAC_VER_45:
case RTL_GIGA_MAC_VER_47:
rtl8168h_1_hw_phy_config(tp);
break;
case RTL_GIGA_MAC_VER_46:
case RTL_GIGA_MAC_VER_48:
rtl8168h_2_hw_phy_config(tp);
break;
case RTL_GIGA_MAC_VER_49:
rtl8168ep_1_hw_phy_config(tp);
break;
case RTL_GIGA_MAC_VER_50:
case RTL_GIGA_MAC_VER_51:
rtl8168ep_2_hw_phy_config(tp);
break;
case RTL_GIGA_MAC_VER_41:
default:
break;
}
}
static void rtl_phy_work(struct rtl8169_private *tp)
{
struct timer_list *timer = &tp->timer;
void __iomem *ioaddr = tp->mmio_addr;
unsigned long timeout = RTL8169_PHY_TIMEOUT;
assert(tp->mac_version > RTL_GIGA_MAC_VER_01);
if (tp->phy_reset_pending(tp)) {
timeout = HZ/10;
goto out_mod_timer;
}
if (tp->link_ok(ioaddr))
return;
netif_dbg(tp, link, tp->dev, "PHY reset until link up\n");
tp->phy_reset_enable(tp);
out_mod_timer:
mod_timer(timer, jiffies + timeout);
}
static void rtl_schedule_task(struct rtl8169_private *tp, enum rtl_flag flag)
{
if (!test_and_set_bit(flag, tp->wk.flags))
schedule_work(&tp->wk.work);
}
static void rtl8169_phy_timer(unsigned long __opaque)
{
struct net_device *dev = (struct net_device *)__opaque;
struct rtl8169_private *tp = netdev_priv(dev);
rtl_schedule_task(tp, RTL_FLAG_TASK_PHY_PENDING);
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
tp->phy_reset_enable(tp);
rtl_msleep_loop_wait_low(tp, &rtl_phy_reset_cond, 1, 100);
}
static bool rtl_tbi_enabled(struct rtl8169_private *tp)
{
void __iomem *ioaddr = tp->mmio_addr;
return (tp->mac_version == RTL_GIGA_MAC_VER_01) &&
(RTL_R8(PHYstatus) & TBI_Enable);
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
if (rtl_tbi_enabled(tp))
netif_info(tp, link, dev, "TBI auto-negotiating\n");
}
static void rtl_rar_set(struct rtl8169_private *tp, u8 *addr)
{
void __iomem *ioaddr = tp->mmio_addr;
rtl_lock_work(tp);
RTL_W8(Cfg9346, Cfg9346_Unlock);
RTL_W32(MAC4, addr[4] | addr[5] << 8);
RTL_R32(MAC4);
RTL_W32(MAC0, addr[0] | addr[1] << 8 | addr[2] << 16 | addr[3] << 24);
RTL_R32(MAC0);
if (tp->mac_version == RTL_GIGA_MAC_VER_34)
rtl_rar_exgmac_set(tp, addr);
RTL_W8(Cfg9346, Cfg9346_Lock);
rtl_unlock_work(tp);
}
static int rtl_set_mac_address(struct net_device *dev, void *p)
{
struct rtl8169_private *tp = netdev_priv(dev);
struct device *d = &tp->pci_dev->dev;
struct sockaddr *addr = p;
if (!is_valid_ether_addr(addr->sa_data))
return -EADDRNOTAVAIL;
memcpy(dev->dev_addr, addr->sa_data, dev->addr_len);
pm_runtime_get_noresume(d);
if (pm_runtime_active(d))
rtl_rar_set(tp, dev->dev_addr);
pm_runtime_put_noidle(d);
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
static void rtl_disable_msi(struct pci_dev *pdev, struct rtl8169_private *tp)
{
if (tp->features & RTL_FEATURE_MSI) {
pci_disable_msi(pdev);
tp->features &= ~RTL_FEATURE_MSI;
}
}
static void rtl_init_mdio_ops(struct rtl8169_private *tp)
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
case RTL_GIGA_MAC_VER_40:
case RTL_GIGA_MAC_VER_41:
case RTL_GIGA_MAC_VER_42:
case RTL_GIGA_MAC_VER_43:
case RTL_GIGA_MAC_VER_44:
case RTL_GIGA_MAC_VER_45:
case RTL_GIGA_MAC_VER_46:
case RTL_GIGA_MAC_VER_47:
case RTL_GIGA_MAC_VER_48:
case RTL_GIGA_MAC_VER_49:
case RTL_GIGA_MAC_VER_50:
case RTL_GIGA_MAC_VER_51:
ops->write = r8168g_mdio_write;
ops->read = r8168g_mdio_read;
break;
default:
ops->write = r8169_mdio_write;
ops->read = r8169_mdio_read;
break;
}
}
static void rtl_speed_down(struct rtl8169_private *tp)
{
u32 adv;
int lpa;
rtl_writephy(tp, 0x1f, 0x0000);
lpa = rtl_readphy(tp, MII_LPA);
if (lpa & (LPA_10HALF | LPA_10FULL))
adv = ADVERTISED_10baseT_Half | ADVERTISED_10baseT_Full;
else if (lpa & (LPA_100HALF | LPA_100FULL))
adv = ADVERTISED_10baseT_Half | ADVERTISED_10baseT_Full |
ADVERTISED_100baseT_Half | ADVERTISED_100baseT_Full;
else
adv = ADVERTISED_10baseT_Half | ADVERTISED_10baseT_Full |
ADVERTISED_100baseT_Half | ADVERTISED_100baseT_Full |
(tp->mii.supports_gmii ?
ADVERTISED_1000baseT_Half |
ADVERTISED_1000baseT_Full : 0);
rtl8169_set_speed(tp->dev, AUTONEG_ENABLE, SPEED_1000, DUPLEX_FULL,
adv);
}
static void rtl_wol_suspend_quirk(struct rtl8169_private *tp)
{
void __iomem *ioaddr = tp->mmio_addr;
switch (tp->mac_version) {
case RTL_GIGA_MAC_VER_25:
case RTL_GIGA_MAC_VER_26:
case RTL_GIGA_MAC_VER_29:
case RTL_GIGA_MAC_VER_30:
case RTL_GIGA_MAC_VER_32:
case RTL_GIGA_MAC_VER_33:
case RTL_GIGA_MAC_VER_34:
case RTL_GIGA_MAC_VER_37:
case RTL_GIGA_MAC_VER_38:
case RTL_GIGA_MAC_VER_39:
case RTL_GIGA_MAC_VER_40:
case RTL_GIGA_MAC_VER_41:
case RTL_GIGA_MAC_VER_42:
case RTL_GIGA_MAC_VER_43:
case RTL_GIGA_MAC_VER_44:
case RTL_GIGA_MAC_VER_45:
case RTL_GIGA_MAC_VER_46:
case RTL_GIGA_MAC_VER_47:
case RTL_GIGA_MAC_VER_48:
case RTL_GIGA_MAC_VER_49:
case RTL_GIGA_MAC_VER_50:
case RTL_GIGA_MAC_VER_51:
RTL_W32(RxConfig, RTL_R32(RxConfig) |
AcceptBroadcast | AcceptMulticast | AcceptMyPhys);
break;
default:
break;
}
}
static bool rtl_wol_pll_power_down(struct rtl8169_private *tp)
{
if (!(__rtl8169_get_wol(tp) & WAKE_ANY))
return false;
rtl_speed_down(tp);
rtl_wol_suspend_quirk(tp);
return true;
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
void __iomem *ioaddr = tp->mmio_addr;
if (rtl_wol_pll_power_down(tp))
return;
r810x_phy_power_down(tp);
switch (tp->mac_version) {
case RTL_GIGA_MAC_VER_07:
case RTL_GIGA_MAC_VER_08:
case RTL_GIGA_MAC_VER_09:
case RTL_GIGA_MAC_VER_10:
case RTL_GIGA_MAC_VER_13:
case RTL_GIGA_MAC_VER_16:
break;
default:
RTL_W8(PMCH, RTL_R8(PMCH) & ~0x80);
break;
}
}
static void r810x_pll_power_up(struct rtl8169_private *tp)
{
void __iomem *ioaddr = tp->mmio_addr;
r810x_phy_power_up(tp);
switch (tp->mac_version) {
case RTL_GIGA_MAC_VER_07:
case RTL_GIGA_MAC_VER_08:
case RTL_GIGA_MAC_VER_09:
case RTL_GIGA_MAC_VER_10:
case RTL_GIGA_MAC_VER_13:
case RTL_GIGA_MAC_VER_16:
break;
case RTL_GIGA_MAC_VER_47:
case RTL_GIGA_MAC_VER_48:
RTL_W8(PMCH, RTL_R8(PMCH) | 0xc0);
break;
default:
RTL_W8(PMCH, RTL_R8(PMCH) | 0x80);
break;
}
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
case RTL_GIGA_MAC_VER_40:
case RTL_GIGA_MAC_VER_41:
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
tp->mac_version == RTL_GIGA_MAC_VER_31 ||
tp->mac_version == RTL_GIGA_MAC_VER_49 ||
tp->mac_version == RTL_GIGA_MAC_VER_50 ||
tp->mac_version == RTL_GIGA_MAC_VER_51) &&
r8168_check_dash(tp)) {
return;
}
if ((tp->mac_version == RTL_GIGA_MAC_VER_23 ||
tp->mac_version == RTL_GIGA_MAC_VER_24) &&
(RTL_R16(CPlusCmd) & ASF)) {
return;
}
if (tp->mac_version == RTL_GIGA_MAC_VER_32 ||
tp->mac_version == RTL_GIGA_MAC_VER_33)
rtl_ephy_write(tp, 0x19, 0xff64);
if (rtl_wol_pll_power_down(tp))
return;
r8168_phy_power_down(tp);
switch (tp->mac_version) {
case RTL_GIGA_MAC_VER_25:
case RTL_GIGA_MAC_VER_26:
case RTL_GIGA_MAC_VER_27:
case RTL_GIGA_MAC_VER_28:
case RTL_GIGA_MAC_VER_31:
case RTL_GIGA_MAC_VER_32:
case RTL_GIGA_MAC_VER_33:
case RTL_GIGA_MAC_VER_44:
case RTL_GIGA_MAC_VER_45:
case RTL_GIGA_MAC_VER_46:
case RTL_GIGA_MAC_VER_50:
case RTL_GIGA_MAC_VER_51:
RTL_W8(PMCH, RTL_R8(PMCH) & ~0x80);
break;
case RTL_GIGA_MAC_VER_40:
case RTL_GIGA_MAC_VER_41:
case RTL_GIGA_MAC_VER_49:
rtl_w0w1_eri(tp, 0x1a8, ERIAR_MASK_1111, 0x00000000,
0xfc000000, ERIAR_EXGMAC);
RTL_W8(PMCH, RTL_R8(PMCH) & ~0x80);
break;
}
}
static void r8168_pll_power_up(struct rtl8169_private *tp)
{
void __iomem *ioaddr = tp->mmio_addr;
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
case RTL_GIGA_MAC_VER_44:
case RTL_GIGA_MAC_VER_45:
case RTL_GIGA_MAC_VER_46:
case RTL_GIGA_MAC_VER_50:
case RTL_GIGA_MAC_VER_51:
RTL_W8(PMCH, RTL_R8(PMCH) | 0xc0);
break;
case RTL_GIGA_MAC_VER_40:
case RTL_GIGA_MAC_VER_41:
case RTL_GIGA_MAC_VER_49:
RTL_W8(PMCH, RTL_R8(PMCH) | 0xc0);
rtl_w0w1_eri(tp, 0x1a8, ERIAR_MASK_1111, 0xfc000000,
0x00000000, ERIAR_EXGMAC);
break;
}
r8168_phy_power_up(tp);
}
static void rtl_generic_op(struct rtl8169_private *tp,
void (*op)(struct rtl8169_private *))
{
if (op)
op(tp);
}
static void rtl_pll_power_down(struct rtl8169_private *tp)
{
rtl_generic_op(tp, tp->pll_power_ops.down);
}
static void rtl_pll_power_up(struct rtl8169_private *tp)
{
rtl_generic_op(tp, tp->pll_power_ops.up);
}
static void rtl_init_pll_power_ops(struct rtl8169_private *tp)
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
case RTL_GIGA_MAC_VER_37:
case RTL_GIGA_MAC_VER_39:
case RTL_GIGA_MAC_VER_43:
case RTL_GIGA_MAC_VER_47:
case RTL_GIGA_MAC_VER_48:
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
case RTL_GIGA_MAC_VER_34:
case RTL_GIGA_MAC_VER_35:
case RTL_GIGA_MAC_VER_36:
case RTL_GIGA_MAC_VER_38:
case RTL_GIGA_MAC_VER_40:
case RTL_GIGA_MAC_VER_41:
case RTL_GIGA_MAC_VER_42:
case RTL_GIGA_MAC_VER_44:
case RTL_GIGA_MAC_VER_45:
case RTL_GIGA_MAC_VER_46:
case RTL_GIGA_MAC_VER_49:
case RTL_GIGA_MAC_VER_50:
case RTL_GIGA_MAC_VER_51:
ops->down = r8168_pll_power_down;
ops->up = r8168_pll_power_up;
break;
default:
ops->down = NULL;
ops->up = NULL;
break;
}
}
static void rtl_init_rxcfg(struct rtl8169_private *tp)
{
void __iomem *ioaddr = tp->mmio_addr;
switch (tp->mac_version) {
case RTL_GIGA_MAC_VER_01:
case RTL_GIGA_MAC_VER_02:
case RTL_GIGA_MAC_VER_03:
case RTL_GIGA_MAC_VER_04:
case RTL_GIGA_MAC_VER_05:
case RTL_GIGA_MAC_VER_06:
case RTL_GIGA_MAC_VER_10:
case RTL_GIGA_MAC_VER_11:
case RTL_GIGA_MAC_VER_12:
case RTL_GIGA_MAC_VER_13:
case RTL_GIGA_MAC_VER_14:
case RTL_GIGA_MAC_VER_15:
case RTL_GIGA_MAC_VER_16:
case RTL_GIGA_MAC_VER_17:
RTL_W32(RxConfig, RX_FIFO_THRESH | RX_DMA_BURST);
break;
case RTL_GIGA_MAC_VER_18:
case RTL_GIGA_MAC_VER_19:
case RTL_GIGA_MAC_VER_20:
case RTL_GIGA_MAC_VER_21:
case RTL_GIGA_MAC_VER_22:
case RTL_GIGA_MAC_VER_23:
case RTL_GIGA_MAC_VER_24:
case RTL_GIGA_MAC_VER_34:
case RTL_GIGA_MAC_VER_35:
RTL_W32(RxConfig, RX128_INT_EN | RX_MULTI_EN | RX_DMA_BURST);
break;
case RTL_GIGA_MAC_VER_40:
case RTL_GIGA_MAC_VER_41:
case RTL_GIGA_MAC_VER_42:
case RTL_GIGA_MAC_VER_43:
case RTL_GIGA_MAC_VER_44:
case RTL_GIGA_MAC_VER_45:
case RTL_GIGA_MAC_VER_46:
case RTL_GIGA_MAC_VER_47:
case RTL_GIGA_MAC_VER_48:
case RTL_GIGA_MAC_VER_49:
case RTL_GIGA_MAC_VER_50:
case RTL_GIGA_MAC_VER_51:
RTL_W32(RxConfig, RX128_INT_EN | RX_MULTI_EN | RX_DMA_BURST | RX_EARLY_OFF);
break;
default:
RTL_W32(RxConfig, RX128_INT_EN | RX_DMA_BURST);
break;
}
}
static void rtl8169_init_ring_indexes(struct rtl8169_private *tp)
{
tp->dirty_tx = tp->cur_tx = tp->cur_rx = 0;
}
static void rtl_hw_jumbo_enable(struct rtl8169_private *tp)
{
void __iomem *ioaddr = tp->mmio_addr;
RTL_W8(Cfg9346, Cfg9346_Unlock);
rtl_generic_op(tp, tp->jumbo_ops.enable);
RTL_W8(Cfg9346, Cfg9346_Lock);
}
static void rtl_hw_jumbo_disable(struct rtl8169_private *tp)
{
void __iomem *ioaddr = tp->mmio_addr;
RTL_W8(Cfg9346, Cfg9346_Unlock);
rtl_generic_op(tp, tp->jumbo_ops.disable);
RTL_W8(Cfg9346, Cfg9346_Lock);
}
static void r8168c_hw_jumbo_enable(struct rtl8169_private *tp)
{
void __iomem *ioaddr = tp->mmio_addr;
RTL_W8(Config3, RTL_R8(Config3) | Jumbo_En0);
RTL_W8(Config4, RTL_R8(Config4) | Jumbo_En1);
rtl_tx_performance_tweak(tp->pci_dev, PCI_EXP_DEVCTL_READRQ_512B);
}
static void r8168c_hw_jumbo_disable(struct rtl8169_private *tp)
{
void __iomem *ioaddr = tp->mmio_addr;
RTL_W8(Config3, RTL_R8(Config3) & ~Jumbo_En0);
RTL_W8(Config4, RTL_R8(Config4) & ~Jumbo_En1);
rtl_tx_performance_tweak(tp->pci_dev, 0x5 << MAX_READ_REQUEST_SHIFT);
}
static void r8168dp_hw_jumbo_enable(struct rtl8169_private *tp)
{
void __iomem *ioaddr = tp->mmio_addr;
RTL_W8(Config3, RTL_R8(Config3) | Jumbo_En0);
}
static void r8168dp_hw_jumbo_disable(struct rtl8169_private *tp)
{
void __iomem *ioaddr = tp->mmio_addr;
RTL_W8(Config3, RTL_R8(Config3) & ~Jumbo_En0);
}
static void r8168e_hw_jumbo_enable(struct rtl8169_private *tp)
{
void __iomem *ioaddr = tp->mmio_addr;
RTL_W8(MaxTxPacketSize, 0x3f);
RTL_W8(Config3, RTL_R8(Config3) | Jumbo_En0);
RTL_W8(Config4, RTL_R8(Config4) | 0x01);
rtl_tx_performance_tweak(tp->pci_dev, PCI_EXP_DEVCTL_READRQ_512B);
}
static void r8168e_hw_jumbo_disable(struct rtl8169_private *tp)
{
void __iomem *ioaddr = tp->mmio_addr;
RTL_W8(MaxTxPacketSize, 0x0c);
RTL_W8(Config3, RTL_R8(Config3) & ~Jumbo_En0);
RTL_W8(Config4, RTL_R8(Config4) & ~0x01);
rtl_tx_performance_tweak(tp->pci_dev, 0x5 << MAX_READ_REQUEST_SHIFT);
}
static void r8168b_0_hw_jumbo_enable(struct rtl8169_private *tp)
{
rtl_tx_performance_tweak(tp->pci_dev,
PCI_EXP_DEVCTL_READRQ_512B | PCI_EXP_DEVCTL_NOSNOOP_EN);
}
static void r8168b_0_hw_jumbo_disable(struct rtl8169_private *tp)
{
rtl_tx_performance_tweak(tp->pci_dev,
(0x5 << MAX_READ_REQUEST_SHIFT) | PCI_EXP_DEVCTL_NOSNOOP_EN);
}
static void r8168b_1_hw_jumbo_enable(struct rtl8169_private *tp)
{
void __iomem *ioaddr = tp->mmio_addr;
r8168b_0_hw_jumbo_enable(tp);
RTL_W8(Config4, RTL_R8(Config4) | (1 << 0));
}
static void r8168b_1_hw_jumbo_disable(struct rtl8169_private *tp)
{
void __iomem *ioaddr = tp->mmio_addr;
r8168b_0_hw_jumbo_disable(tp);
RTL_W8(Config4, RTL_R8(Config4) & ~(1 << 0));
}
static void rtl_init_jumbo_ops(struct rtl8169_private *tp)
{
struct jumbo_ops *ops = &tp->jumbo_ops;
switch (tp->mac_version) {
case RTL_GIGA_MAC_VER_11:
ops->disable = r8168b_0_hw_jumbo_disable;
ops->enable = r8168b_0_hw_jumbo_enable;
break;
case RTL_GIGA_MAC_VER_12:
case RTL_GIGA_MAC_VER_17:
ops->disable = r8168b_1_hw_jumbo_disable;
ops->enable = r8168b_1_hw_jumbo_enable;
break;
case RTL_GIGA_MAC_VER_18:
case RTL_GIGA_MAC_VER_19:
case RTL_GIGA_MAC_VER_20:
case RTL_GIGA_MAC_VER_21:
case RTL_GIGA_MAC_VER_22:
case RTL_GIGA_MAC_VER_23:
case RTL_GIGA_MAC_VER_24:
case RTL_GIGA_MAC_VER_25:
case RTL_GIGA_MAC_VER_26:
ops->disable = r8168c_hw_jumbo_disable;
ops->enable = r8168c_hw_jumbo_enable;
break;
case RTL_GIGA_MAC_VER_27:
case RTL_GIGA_MAC_VER_28:
ops->disable = r8168dp_hw_jumbo_disable;
ops->enable = r8168dp_hw_jumbo_enable;
break;
case RTL_GIGA_MAC_VER_31:
case RTL_GIGA_MAC_VER_32:
case RTL_GIGA_MAC_VER_33:
case RTL_GIGA_MAC_VER_34:
ops->disable = r8168e_hw_jumbo_disable;
ops->enable = r8168e_hw_jumbo_enable;
break;
case RTL_GIGA_MAC_VER_40:
case RTL_GIGA_MAC_VER_41:
case RTL_GIGA_MAC_VER_42:
case RTL_GIGA_MAC_VER_43:
case RTL_GIGA_MAC_VER_44:
case RTL_GIGA_MAC_VER_45:
case RTL_GIGA_MAC_VER_46:
case RTL_GIGA_MAC_VER_47:
case RTL_GIGA_MAC_VER_48:
case RTL_GIGA_MAC_VER_49:
case RTL_GIGA_MAC_VER_50:
case RTL_GIGA_MAC_VER_51:
default:
ops->disable = NULL;
ops->enable = NULL;
break;
}
}
static void rtl_hw_reset(struct rtl8169_private *tp)
{
void __iomem *ioaddr = tp->mmio_addr;
RTL_W8(ChipCmd, CmdReset);
rtl_udelay_loop_wait_low(tp, &rtl_chipcmd_cond, 100, 100);
}
static void rtl_request_uncached_firmware(struct rtl8169_private *tp)
{
struct rtl_fw *rtl_fw;
const char *name;
int rc = -ENOMEM;
name = rtl_lookup_firmware_name(tp);
if (!name)
goto out_no_firmware;
rtl_fw = kzalloc(sizeof(*rtl_fw), GFP_KERNEL);
if (!rtl_fw)
goto err_warn;
rc = request_firmware(&rtl_fw->fw, name, &tp->pci_dev->dev);
if (rc < 0)
goto err_free;
rc = rtl_check_firmware(tp, rtl_fw);
if (rc < 0)
goto err_release_firmware;
tp->rtl_fw = rtl_fw;
out:
return;
err_release_firmware:
release_firmware(rtl_fw->fw);
err_free:
kfree(rtl_fw);
err_warn:
netif_warn(tp, ifup, tp->dev, "unable to load firmware patch %s (%d)\n",
name, rc);
out_no_firmware:
tp->rtl_fw = NULL;
goto out;
}
static void rtl_request_firmware(struct rtl8169_private *tp)
{
if (IS_ERR(tp->rtl_fw))
rtl_request_uncached_firmware(tp);
}
static void rtl_rx_close(struct rtl8169_private *tp)
{
void __iomem *ioaddr = tp->mmio_addr;
RTL_W32(RxConfig, RTL_R32(RxConfig) & ~RX_CONFIG_ACCEPT_MASK);
}
static void rtl8169_hw_reset(struct rtl8169_private *tp)
{
void __iomem *ioaddr = tp->mmio_addr;
rtl8169_irq_mask_and_ack(tp);
rtl_rx_close(tp);
if (tp->mac_version == RTL_GIGA_MAC_VER_27 ||
tp->mac_version == RTL_GIGA_MAC_VER_28 ||
tp->mac_version == RTL_GIGA_MAC_VER_31) {
rtl_udelay_loop_wait_low(tp, &rtl_npq_cond, 20, 42*42);
} else if (tp->mac_version == RTL_GIGA_MAC_VER_34 ||
tp->mac_version == RTL_GIGA_MAC_VER_35 ||
tp->mac_version == RTL_GIGA_MAC_VER_36 ||
tp->mac_version == RTL_GIGA_MAC_VER_37 ||
tp->mac_version == RTL_GIGA_MAC_VER_38 ||
tp->mac_version == RTL_GIGA_MAC_VER_40 ||
tp->mac_version == RTL_GIGA_MAC_VER_41 ||
tp->mac_version == RTL_GIGA_MAC_VER_42 ||
tp->mac_version == RTL_GIGA_MAC_VER_43 ||
tp->mac_version == RTL_GIGA_MAC_VER_44 ||
tp->mac_version == RTL_GIGA_MAC_VER_45 ||
tp->mac_version == RTL_GIGA_MAC_VER_46 ||
tp->mac_version == RTL_GIGA_MAC_VER_47 ||
tp->mac_version == RTL_GIGA_MAC_VER_48 ||
tp->mac_version == RTL_GIGA_MAC_VER_49 ||
tp->mac_version == RTL_GIGA_MAC_VER_50 ||
tp->mac_version == RTL_GIGA_MAC_VER_51) {
RTL_W8(ChipCmd, RTL_R8(ChipCmd) | StopReq);
rtl_udelay_loop_wait_high(tp, &rtl_txcfg_empty_cond, 100, 666);
} else {
RTL_W8(ChipCmd, RTL_R8(ChipCmd) | StopReq);
udelay(100);
}
rtl_hw_reset(tp);
}
static void rtl_set_rx_tx_config_registers(struct rtl8169_private *tp)
{
void __iomem *ioaddr = tp->mmio_addr;
RTL_W32(TxConfig, (TX_DMA_BURST << TxDMAShift) |
(InterFrameGap << TxInterFrameGapShift));
}
static void rtl_hw_start(struct net_device *dev)
{
struct rtl8169_private *tp = netdev_priv(dev);
tp->hw_start(dev);
rtl_irq_enable_all(tp);
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
static void rtl_set_rx_mode(struct net_device *dev)
{
struct rtl8169_private *tp = netdev_priv(dev);
void __iomem *ioaddr = tp->mmio_addr;
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
if (dev->features & NETIF_F_RXALL)
rx_mode |= (AcceptErr | AcceptRunt);
tmp = (RTL_R32(RxConfig) & ~RX_CONFIG_ACCEPT_MASK) | rx_mode;
if (tp->mac_version > RTL_GIGA_MAC_VER_06) {
u32 data = mc_filter[0];
mc_filter[0] = swab32(mc_filter[1]);
mc_filter[1] = swab32(data);
}
if (tp->mac_version == RTL_GIGA_MAC_VER_35)
mc_filter[1] = mc_filter[0] = 0xffffffff;
RTL_W32(MAR0 + 4, mc_filter[1]);
RTL_W32(MAR0 + 0, mc_filter[0]);
RTL_W32(RxConfig, tmp);
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
rtl_init_rxcfg(tp);
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
dprintk("Set MAC Reg C+CR Offset 0xe0. "
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
RTL_W16(MultiIntr, RTL_R16(MultiIntr) & 0xf000);
}
static void rtl_csi_write(struct rtl8169_private *tp, int addr, int value)
{
if (tp->csi_ops.write)
tp->csi_ops.write(tp, addr, value);
}
static u32 rtl_csi_read(struct rtl8169_private *tp, int addr)
{
return tp->csi_ops.read ? tp->csi_ops.read(tp, addr) : ~0;
}
static void rtl_csi_access_enable(struct rtl8169_private *tp, u32 bits)
{
u32 csi;
csi = rtl_csi_read(tp, 0x070c) & 0x00ffffff;
rtl_csi_write(tp, 0x070c, csi | bits);
}
static void rtl_csi_access_enable_1(struct rtl8169_private *tp)
{
rtl_csi_access_enable(tp, 0x17000000);
}
static void rtl_csi_access_enable_2(struct rtl8169_private *tp)
{
rtl_csi_access_enable(tp, 0x27000000);
}
static void r8169_csi_write(struct rtl8169_private *tp, int addr, int value)
{
void __iomem *ioaddr = tp->mmio_addr;
RTL_W32(CSIDR, value);
RTL_W32(CSIAR, CSIAR_WRITE_CMD | (addr & CSIAR_ADDR_MASK) |
CSIAR_BYTE_ENABLE << CSIAR_BYTE_ENABLE_SHIFT);
rtl_udelay_loop_wait_low(tp, &rtl_csiar_cond, 10, 100);
}
static u32 r8169_csi_read(struct rtl8169_private *tp, int addr)
{
void __iomem *ioaddr = tp->mmio_addr;
RTL_W32(CSIAR, (addr & CSIAR_ADDR_MASK) |
CSIAR_BYTE_ENABLE << CSIAR_BYTE_ENABLE_SHIFT);
return rtl_udelay_loop_wait_high(tp, &rtl_csiar_cond, 10, 100) ?
RTL_R32(CSIDR) : ~0;
}
static void r8402_csi_write(struct rtl8169_private *tp, int addr, int value)
{
void __iomem *ioaddr = tp->mmio_addr;
RTL_W32(CSIDR, value);
RTL_W32(CSIAR, CSIAR_WRITE_CMD | (addr & CSIAR_ADDR_MASK) |
CSIAR_BYTE_ENABLE << CSIAR_BYTE_ENABLE_SHIFT |
CSIAR_FUNC_NIC);
rtl_udelay_loop_wait_low(tp, &rtl_csiar_cond, 10, 100);
}
static u32 r8402_csi_read(struct rtl8169_private *tp, int addr)
{
void __iomem *ioaddr = tp->mmio_addr;
RTL_W32(CSIAR, (addr & CSIAR_ADDR_MASK) | CSIAR_FUNC_NIC |
CSIAR_BYTE_ENABLE << CSIAR_BYTE_ENABLE_SHIFT);
return rtl_udelay_loop_wait_high(tp, &rtl_csiar_cond, 10, 100) ?
RTL_R32(CSIDR) : ~0;
}
static void r8411_csi_write(struct rtl8169_private *tp, int addr, int value)
{
void __iomem *ioaddr = tp->mmio_addr;
RTL_W32(CSIDR, value);
RTL_W32(CSIAR, CSIAR_WRITE_CMD | (addr & CSIAR_ADDR_MASK) |
CSIAR_BYTE_ENABLE << CSIAR_BYTE_ENABLE_SHIFT |
CSIAR_FUNC_NIC2);
rtl_udelay_loop_wait_low(tp, &rtl_csiar_cond, 10, 100);
}
static u32 r8411_csi_read(struct rtl8169_private *tp, int addr)
{
void __iomem *ioaddr = tp->mmio_addr;
RTL_W32(CSIAR, (addr & CSIAR_ADDR_MASK) | CSIAR_FUNC_NIC2 |
CSIAR_BYTE_ENABLE << CSIAR_BYTE_ENABLE_SHIFT);
return rtl_udelay_loop_wait_high(tp, &rtl_csiar_cond, 10, 100) ?
RTL_R32(CSIDR) : ~0;
}
static void rtl_init_csi_ops(struct rtl8169_private *tp)
{
struct csi_ops *ops = &tp->csi_ops;
switch (tp->mac_version) {
case RTL_GIGA_MAC_VER_01:
case RTL_GIGA_MAC_VER_02:
case RTL_GIGA_MAC_VER_03:
case RTL_GIGA_MAC_VER_04:
case RTL_GIGA_MAC_VER_05:
case RTL_GIGA_MAC_VER_06:
case RTL_GIGA_MAC_VER_10:
case RTL_GIGA_MAC_VER_11:
case RTL_GIGA_MAC_VER_12:
case RTL_GIGA_MAC_VER_13:
case RTL_GIGA_MAC_VER_14:
case RTL_GIGA_MAC_VER_15:
case RTL_GIGA_MAC_VER_16:
case RTL_GIGA_MAC_VER_17:
ops->write = NULL;
ops->read = NULL;
break;
case RTL_GIGA_MAC_VER_37:
case RTL_GIGA_MAC_VER_38:
ops->write = r8402_csi_write;
ops->read = r8402_csi_read;
break;
case RTL_GIGA_MAC_VER_44:
ops->write = r8411_csi_write;
ops->read = r8411_csi_read;
break;
default:
ops->write = r8169_csi_write;
ops->read = r8169_csi_read;
break;
}
}
static void rtl_ephy_init(struct rtl8169_private *tp, const struct ephy_info *e,
int len)
{
u16 w;
while (len-- > 0) {
w = (rtl_ephy_read(tp, e->offset) & ~e->mask) | e->bits;
rtl_ephy_write(tp, e->offset, w);
e++;
}
}
static void rtl_disable_clock_request(struct pci_dev *pdev)
{
pcie_capability_clear_word(pdev, PCI_EXP_LNKCTL,
PCI_EXP_LNKCTL_CLKREQ_EN);
}
static void rtl_enable_clock_request(struct pci_dev *pdev)
{
pcie_capability_set_word(pdev, PCI_EXP_LNKCTL,
PCI_EXP_LNKCTL_CLKREQ_EN);
}
static void rtl_pcie_state_l2l3_enable(struct rtl8169_private *tp, bool enable)
{
void __iomem *ioaddr = tp->mmio_addr;
u8 data;
data = RTL_R8(Config3);
if (enable)
data |= Rdy_to_L23;
else
data &= ~Rdy_to_L23;
RTL_W8(Config3, data);
}
static void rtl_hw_start_8168bb(struct rtl8169_private *tp)
{
void __iomem *ioaddr = tp->mmio_addr;
struct pci_dev *pdev = tp->pci_dev;
RTL_W8(Config3, RTL_R8(Config3) & ~Beacon_en);
RTL_W16(CPlusCmd, RTL_R16(CPlusCmd) & ~R8168_CPCMD_QUIRK_MASK);
if (tp->dev->mtu <= ETH_DATA_LEN) {
rtl_tx_performance_tweak(pdev, (0x5 << MAX_READ_REQUEST_SHIFT) |
PCI_EXP_DEVCTL_NOSNOOP_EN);
}
}
static void rtl_hw_start_8168bef(struct rtl8169_private *tp)
{
void __iomem *ioaddr = tp->mmio_addr;
rtl_hw_start_8168bb(tp);
RTL_W8(MaxTxPacketSize, TxPacketMax);
RTL_W8(Config4, RTL_R8(Config4) & ~(1 << 0));
}
static void __rtl_hw_start_8168cp(struct rtl8169_private *tp)
{
void __iomem *ioaddr = tp->mmio_addr;
struct pci_dev *pdev = tp->pci_dev;
RTL_W8(Config1, RTL_R8(Config1) | Speed_down);
RTL_W8(Config3, RTL_R8(Config3) & ~Beacon_en);
if (tp->dev->mtu <= ETH_DATA_LEN)
rtl_tx_performance_tweak(pdev, 0x5 << MAX_READ_REQUEST_SHIFT);
rtl_disable_clock_request(pdev);
RTL_W16(CPlusCmd, RTL_R16(CPlusCmd) & ~R8168_CPCMD_QUIRK_MASK);
}
static void rtl_hw_start_8168cp_1(struct rtl8169_private *tp)
{
static const struct ephy_info e_info_8168cp[] = {
{ 0x01, 0, 0x0001 },
{ 0x02, 0x0800, 0x1000 },
{ 0x03, 0, 0x0042 },
{ 0x06, 0x0080, 0x0000 },
{ 0x07, 0, 0x2000 }
};
rtl_csi_access_enable_2(tp);
rtl_ephy_init(tp, e_info_8168cp, ARRAY_SIZE(e_info_8168cp));
__rtl_hw_start_8168cp(tp);
}
static void rtl_hw_start_8168cp_2(struct rtl8169_private *tp)
{
void __iomem *ioaddr = tp->mmio_addr;
struct pci_dev *pdev = tp->pci_dev;
rtl_csi_access_enable_2(tp);
RTL_W8(Config3, RTL_R8(Config3) & ~Beacon_en);
if (tp->dev->mtu <= ETH_DATA_LEN)
rtl_tx_performance_tweak(pdev, 0x5 << MAX_READ_REQUEST_SHIFT);
RTL_W16(CPlusCmd, RTL_R16(CPlusCmd) & ~R8168_CPCMD_QUIRK_MASK);
}
static void rtl_hw_start_8168cp_3(struct rtl8169_private *tp)
{
void __iomem *ioaddr = tp->mmio_addr;
struct pci_dev *pdev = tp->pci_dev;
rtl_csi_access_enable_2(tp);
RTL_W8(Config3, RTL_R8(Config3) & ~Beacon_en);
RTL_W8(DBG_REG, 0x20);
RTL_W8(MaxTxPacketSize, TxPacketMax);
if (tp->dev->mtu <= ETH_DATA_LEN)
rtl_tx_performance_tweak(pdev, 0x5 << MAX_READ_REQUEST_SHIFT);
RTL_W16(CPlusCmd, RTL_R16(CPlusCmd) & ~R8168_CPCMD_QUIRK_MASK);
}
static void rtl_hw_start_8168c_1(struct rtl8169_private *tp)
{
void __iomem *ioaddr = tp->mmio_addr;
static const struct ephy_info e_info_8168c_1[] = {
{ 0x02, 0x0800, 0x1000 },
{ 0x03, 0, 0x0002 },
{ 0x06, 0x0080, 0x0000 }
};
rtl_csi_access_enable_2(tp);
RTL_W8(DBG_REG, 0x06 | FIX_NAK_1 | FIX_NAK_2);
rtl_ephy_init(tp, e_info_8168c_1, ARRAY_SIZE(e_info_8168c_1));
__rtl_hw_start_8168cp(tp);
}
static void rtl_hw_start_8168c_2(struct rtl8169_private *tp)
{
static const struct ephy_info e_info_8168c_2[] = {
{ 0x01, 0, 0x0001 },
{ 0x03, 0x0400, 0x0220 }
};
rtl_csi_access_enable_2(tp);
rtl_ephy_init(tp, e_info_8168c_2, ARRAY_SIZE(e_info_8168c_2));
__rtl_hw_start_8168cp(tp);
}
static void rtl_hw_start_8168c_3(struct rtl8169_private *tp)
{
rtl_hw_start_8168c_2(tp);
}
static void rtl_hw_start_8168c_4(struct rtl8169_private *tp)
{
rtl_csi_access_enable_2(tp);
__rtl_hw_start_8168cp(tp);
}
static void rtl_hw_start_8168d(struct rtl8169_private *tp)
{
void __iomem *ioaddr = tp->mmio_addr;
struct pci_dev *pdev = tp->pci_dev;
rtl_csi_access_enable_2(tp);
rtl_disable_clock_request(pdev);
RTL_W8(MaxTxPacketSize, TxPacketMax);
if (tp->dev->mtu <= ETH_DATA_LEN)
rtl_tx_performance_tweak(pdev, 0x5 << MAX_READ_REQUEST_SHIFT);
RTL_W16(CPlusCmd, RTL_R16(CPlusCmd) & ~R8168_CPCMD_QUIRK_MASK);
}
static void rtl_hw_start_8168dp(struct rtl8169_private *tp)
{
void __iomem *ioaddr = tp->mmio_addr;
struct pci_dev *pdev = tp->pci_dev;
rtl_csi_access_enable_1(tp);
if (tp->dev->mtu <= ETH_DATA_LEN)
rtl_tx_performance_tweak(pdev, 0x5 << MAX_READ_REQUEST_SHIFT);
RTL_W8(MaxTxPacketSize, TxPacketMax);
rtl_disable_clock_request(pdev);
}
static void rtl_hw_start_8168d_4(struct rtl8169_private *tp)
{
void __iomem *ioaddr = tp->mmio_addr;
struct pci_dev *pdev = tp->pci_dev;
static const struct ephy_info e_info_8168d_4[] = {
{ 0x0b, 0x0000, 0x0048 },
{ 0x19, 0x0020, 0x0050 },
{ 0x0c, 0x0100, 0x0020 }
};
rtl_csi_access_enable_1(tp);
rtl_tx_performance_tweak(pdev, 0x5 << MAX_READ_REQUEST_SHIFT);
RTL_W8(MaxTxPacketSize, TxPacketMax);
rtl_ephy_init(tp, e_info_8168d_4, ARRAY_SIZE(e_info_8168d_4));
rtl_enable_clock_request(pdev);
}
static void rtl_hw_start_8168e_1(struct rtl8169_private *tp)
{
void __iomem *ioaddr = tp->mmio_addr;
struct pci_dev *pdev = tp->pci_dev;
static const struct ephy_info e_info_8168e_1[] = {
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
rtl_csi_access_enable_2(tp);
rtl_ephy_init(tp, e_info_8168e_1, ARRAY_SIZE(e_info_8168e_1));
if (tp->dev->mtu <= ETH_DATA_LEN)
rtl_tx_performance_tweak(pdev, 0x5 << MAX_READ_REQUEST_SHIFT);
RTL_W8(MaxTxPacketSize, TxPacketMax);
rtl_disable_clock_request(pdev);
RTL_W32(MISC, RTL_R32(MISC) | TXPLA_RST);
RTL_W32(MISC, RTL_R32(MISC) & ~TXPLA_RST);
RTL_W8(Config5, RTL_R8(Config5) & ~Spi_en);
}
static void rtl_hw_start_8168e_2(struct rtl8169_private *tp)
{
void __iomem *ioaddr = tp->mmio_addr;
struct pci_dev *pdev = tp->pci_dev;
static const struct ephy_info e_info_8168e_2[] = {
{ 0x09, 0x0000, 0x0080 },
{ 0x19, 0x0000, 0x0224 }
};
rtl_csi_access_enable_1(tp);
rtl_ephy_init(tp, e_info_8168e_2, ARRAY_SIZE(e_info_8168e_2));
if (tp->dev->mtu <= ETH_DATA_LEN)
rtl_tx_performance_tweak(pdev, 0x5 << MAX_READ_REQUEST_SHIFT);
rtl_eri_write(tp, 0xc0, ERIAR_MASK_0011, 0x0000, ERIAR_EXGMAC);
rtl_eri_write(tp, 0xb8, ERIAR_MASK_0011, 0x0000, ERIAR_EXGMAC);
rtl_eri_write(tp, 0xc8, ERIAR_MASK_1111, 0x00100002, ERIAR_EXGMAC);
rtl_eri_write(tp, 0xe8, ERIAR_MASK_1111, 0x00100006, ERIAR_EXGMAC);
rtl_eri_write(tp, 0xcc, ERIAR_MASK_1111, 0x00000050, ERIAR_EXGMAC);
rtl_eri_write(tp, 0xd0, ERIAR_MASK_1111, 0x07ff0060, ERIAR_EXGMAC);
rtl_w0w1_eri(tp, 0x1b0, ERIAR_MASK_0001, 0x10, 0x00, ERIAR_EXGMAC);
rtl_w0w1_eri(tp, 0x0d4, ERIAR_MASK_0011, 0x0c00, 0xff00, ERIAR_EXGMAC);
RTL_W8(MaxTxPacketSize, EarlySize);
rtl_disable_clock_request(pdev);
RTL_W32(TxConfig, RTL_R32(TxConfig) | TXCFG_AUTO_FIFO);
RTL_W8(MCU, RTL_R8(MCU) & ~NOW_IS_OOB);
RTL_W8(EEE_LED, RTL_R8(EEE_LED) & ~0x07);
RTL_W8(DLLPR, RTL_R8(DLLPR) | PFM_EN);
RTL_W32(MISC, RTL_R32(MISC) | PWM_EN);
RTL_W8(Config5, RTL_R8(Config5) & ~Spi_en);
}
static void rtl_hw_start_8168f(struct rtl8169_private *tp)
{
void __iomem *ioaddr = tp->mmio_addr;
struct pci_dev *pdev = tp->pci_dev;
rtl_csi_access_enable_2(tp);
rtl_tx_performance_tweak(pdev, 0x5 << MAX_READ_REQUEST_SHIFT);
rtl_eri_write(tp, 0xc0, ERIAR_MASK_0011, 0x0000, ERIAR_EXGMAC);
rtl_eri_write(tp, 0xb8, ERIAR_MASK_0011, 0x0000, ERIAR_EXGMAC);
rtl_eri_write(tp, 0xc8, ERIAR_MASK_1111, 0x00100002, ERIAR_EXGMAC);
rtl_eri_write(tp, 0xe8, ERIAR_MASK_1111, 0x00100006, ERIAR_EXGMAC);
rtl_w0w1_eri(tp, 0xdc, ERIAR_MASK_0001, 0x00, 0x01, ERIAR_EXGMAC);
rtl_w0w1_eri(tp, 0xdc, ERIAR_MASK_0001, 0x01, 0x00, ERIAR_EXGMAC);
rtl_w0w1_eri(tp, 0x1b0, ERIAR_MASK_0001, 0x10, 0x00, ERIAR_EXGMAC);
rtl_w0w1_eri(tp, 0x1d0, ERIAR_MASK_0001, 0x10, 0x00, ERIAR_EXGMAC);
rtl_eri_write(tp, 0xcc, ERIAR_MASK_1111, 0x00000050, ERIAR_EXGMAC);
rtl_eri_write(tp, 0xd0, ERIAR_MASK_1111, 0x00000060, ERIAR_EXGMAC);
RTL_W8(MaxTxPacketSize, EarlySize);
rtl_disable_clock_request(pdev);
RTL_W32(TxConfig, RTL_R32(TxConfig) | TXCFG_AUTO_FIFO);
RTL_W8(MCU, RTL_R8(MCU) & ~NOW_IS_OOB);
RTL_W8(DLLPR, RTL_R8(DLLPR) | PFM_EN);
RTL_W32(MISC, RTL_R32(MISC) | PWM_EN);
RTL_W8(Config5, RTL_R8(Config5) & ~Spi_en);
}
static void rtl_hw_start_8168f_1(struct rtl8169_private *tp)
{
void __iomem *ioaddr = tp->mmio_addr;
static const struct ephy_info e_info_8168f_1[] = {
{ 0x06, 0x00c0, 0x0020 },
{ 0x08, 0x0001, 0x0002 },
{ 0x09, 0x0000, 0x0080 },
{ 0x19, 0x0000, 0x0224 }
};
rtl_hw_start_8168f(tp);
rtl_ephy_init(tp, e_info_8168f_1, ARRAY_SIZE(e_info_8168f_1));
rtl_w0w1_eri(tp, 0x0d4, ERIAR_MASK_0011, 0x0c00, 0xff00, ERIAR_EXGMAC);
RTL_W8(EEE_LED, RTL_R8(EEE_LED) & ~0x07);
}
static void rtl_hw_start_8411(struct rtl8169_private *tp)
{
static const struct ephy_info e_info_8168f_1[] = {
{ 0x06, 0x00c0, 0x0020 },
{ 0x0f, 0xffff, 0x5200 },
{ 0x1e, 0x0000, 0x4000 },
{ 0x19, 0x0000, 0x0224 }
};
rtl_hw_start_8168f(tp);
rtl_pcie_state_l2l3_enable(tp, false);
rtl_ephy_init(tp, e_info_8168f_1, ARRAY_SIZE(e_info_8168f_1));
rtl_w0w1_eri(tp, 0x0d4, ERIAR_MASK_0011, 0x0c00, 0x0000, ERIAR_EXGMAC);
}
static void rtl_hw_start_8168g(struct rtl8169_private *tp)
{
void __iomem *ioaddr = tp->mmio_addr;
struct pci_dev *pdev = tp->pci_dev;
RTL_W32(TxConfig, RTL_R32(TxConfig) | TXCFG_AUTO_FIFO);
rtl_eri_write(tp, 0xc8, ERIAR_MASK_0101, 0x080002, ERIAR_EXGMAC);
rtl_eri_write(tp, 0xcc, ERIAR_MASK_0001, 0x38, ERIAR_EXGMAC);
rtl_eri_write(tp, 0xd0, ERIAR_MASK_0001, 0x48, ERIAR_EXGMAC);
rtl_eri_write(tp, 0xe8, ERIAR_MASK_1111, 0x00100006, ERIAR_EXGMAC);
rtl_csi_access_enable_1(tp);
rtl_tx_performance_tweak(pdev, 0x5 << MAX_READ_REQUEST_SHIFT);
rtl_w0w1_eri(tp, 0xdc, ERIAR_MASK_0001, 0x00, 0x01, ERIAR_EXGMAC);
rtl_w0w1_eri(tp, 0xdc, ERIAR_MASK_0001, 0x01, 0x00, ERIAR_EXGMAC);
rtl_eri_write(tp, 0x2f8, ERIAR_MASK_0011, 0x1d8f, ERIAR_EXGMAC);
RTL_W32(MISC, RTL_R32(MISC) & ~RXDV_GATED_EN);
RTL_W8(MaxTxPacketSize, EarlySize);
rtl_eri_write(tp, 0xc0, ERIAR_MASK_0011, 0x0000, ERIAR_EXGMAC);
rtl_eri_write(tp, 0xb8, ERIAR_MASK_0011, 0x0000, ERIAR_EXGMAC);
RTL_W8(EEE_LED, RTL_R8(EEE_LED) & ~0x07);
rtl_w0w1_eri(tp, 0x2fc, ERIAR_MASK_0001, 0x01, 0x06, ERIAR_EXGMAC);
rtl_w0w1_eri(tp, 0x1b0, ERIAR_MASK_0011, 0x0000, 0x1000, ERIAR_EXGMAC);
rtl_pcie_state_l2l3_enable(tp, false);
}
static void rtl_hw_start_8168g_1(struct rtl8169_private *tp)
{
void __iomem *ioaddr = tp->mmio_addr;
static const struct ephy_info e_info_8168g_1[] = {
{ 0x00, 0x0000, 0x0008 },
{ 0x0c, 0x37d0, 0x0820 },
{ 0x1e, 0x0000, 0x0001 },
{ 0x19, 0x8000, 0x0000 }
};
rtl_hw_start_8168g(tp);
RTL_W8(Config2, RTL_R8(Config2) & ~ClkReqEn);
RTL_W8(Config5, RTL_R8(Config5) & ~ASPM_en);
rtl_ephy_init(tp, e_info_8168g_1, ARRAY_SIZE(e_info_8168g_1));
}
static void rtl_hw_start_8168g_2(struct rtl8169_private *tp)
{
void __iomem *ioaddr = tp->mmio_addr;
static const struct ephy_info e_info_8168g_2[] = {
{ 0x00, 0x0000, 0x0008 },
{ 0x0c, 0x3df0, 0x0200 },
{ 0x19, 0xffff, 0xfc00 },
{ 0x1e, 0xffff, 0x20eb }
};
rtl_hw_start_8168g(tp);
RTL_W8(Config2, RTL_R8(Config2) & ~ClkReqEn);
RTL_W8(Config5, RTL_R8(Config5) & ~ASPM_en);
rtl_ephy_init(tp, e_info_8168g_2, ARRAY_SIZE(e_info_8168g_2));
}
static void rtl_hw_start_8411_2(struct rtl8169_private *tp)
{
void __iomem *ioaddr = tp->mmio_addr;
static const struct ephy_info e_info_8411_2[] = {
{ 0x00, 0x0000, 0x0008 },
{ 0x0c, 0x3df0, 0x0200 },
{ 0x0f, 0xffff, 0x5200 },
{ 0x19, 0x0020, 0x0000 },
{ 0x1e, 0x0000, 0x2000 }
};
rtl_hw_start_8168g(tp);
RTL_W8(Config2, RTL_R8(Config2) & ~ClkReqEn);
RTL_W8(Config5, RTL_R8(Config5) & ~ASPM_en);
rtl_ephy_init(tp, e_info_8411_2, ARRAY_SIZE(e_info_8411_2));
}
static void rtl_hw_start_8168h_1(struct rtl8169_private *tp)
{
void __iomem *ioaddr = tp->mmio_addr;
struct pci_dev *pdev = tp->pci_dev;
int rg_saw_cnt;
u32 data;
static const struct ephy_info e_info_8168h_1[] = {
{ 0x1e, 0x0800, 0x0001 },
{ 0x1d, 0x0000, 0x0800 },
{ 0x05, 0xffff, 0x2089 },
{ 0x06, 0xffff, 0x5881 },
{ 0x04, 0xffff, 0x154a },
{ 0x01, 0xffff, 0x068b }
};
RTL_W8(Config2, RTL_R8(Config2) & ~ClkReqEn);
RTL_W8(Config5, RTL_R8(Config5) & ~ASPM_en);
rtl_ephy_init(tp, e_info_8168h_1, ARRAY_SIZE(e_info_8168h_1));
RTL_W32(TxConfig, RTL_R32(TxConfig) | TXCFG_AUTO_FIFO);
rtl_eri_write(tp, 0xc8, ERIAR_MASK_0101, 0x00080002, ERIAR_EXGMAC);
rtl_eri_write(tp, 0xcc, ERIAR_MASK_0001, 0x38, ERIAR_EXGMAC);
rtl_eri_write(tp, 0xd0, ERIAR_MASK_0001, 0x48, ERIAR_EXGMAC);
rtl_eri_write(tp, 0xe8, ERIAR_MASK_1111, 0x00100006, ERIAR_EXGMAC);
rtl_csi_access_enable_1(tp);
rtl_tx_performance_tweak(pdev, 0x5 << MAX_READ_REQUEST_SHIFT);
rtl_w0w1_eri(tp, 0xdc, ERIAR_MASK_0001, 0x00, 0x01, ERIAR_EXGMAC);
rtl_w0w1_eri(tp, 0xdc, ERIAR_MASK_0001, 0x01, 0x00, ERIAR_EXGMAC);
rtl_w0w1_eri(tp, 0xdc, ERIAR_MASK_1111, 0x0010, 0x00, ERIAR_EXGMAC);
rtl_w0w1_eri(tp, 0xd4, ERIAR_MASK_1111, 0x1f00, 0x00, ERIAR_EXGMAC);
rtl_eri_write(tp, 0x5f0, ERIAR_MASK_0011, 0x4f87, ERIAR_EXGMAC);
RTL_W32(MISC, RTL_R32(MISC) & ~RXDV_GATED_EN);
RTL_W8(MaxTxPacketSize, EarlySize);
rtl_eri_write(tp, 0xc0, ERIAR_MASK_0011, 0x0000, ERIAR_EXGMAC);
rtl_eri_write(tp, 0xb8, ERIAR_MASK_0011, 0x0000, ERIAR_EXGMAC);
RTL_W8(EEE_LED, RTL_R8(EEE_LED) & ~0x07);
RTL_W8(DLLPR, RTL_R8(DLLPR) & ~PFM_EN);
RTL_W8(MISC_1, RTL_R8(MISC_1) & ~PFM_D3COLD_EN);
RTL_W8(DLLPR, RTL_R8(DLLPR) & ~TX_10M_PS_EN);
rtl_w0w1_eri(tp, 0x1b0, ERIAR_MASK_0011, 0x0000, 0x1000, ERIAR_EXGMAC);
rtl_pcie_state_l2l3_enable(tp, false);
rtl_writephy(tp, 0x1f, 0x0c42);
rg_saw_cnt = (rtl_readphy(tp, 0x13) & 0x3fff);
rtl_writephy(tp, 0x1f, 0x0000);
if (rg_saw_cnt > 0) {
u16 sw_cnt_1ms_ini;
sw_cnt_1ms_ini = 16000000/rg_saw_cnt;
sw_cnt_1ms_ini &= 0x0fff;
data = r8168_mac_ocp_read(tp, 0xd412);
data &= ~0x0fff;
data |= sw_cnt_1ms_ini;
r8168_mac_ocp_write(tp, 0xd412, data);
}
data = r8168_mac_ocp_read(tp, 0xe056);
data &= ~0xf0;
data |= 0x70;
r8168_mac_ocp_write(tp, 0xe056, data);
data = r8168_mac_ocp_read(tp, 0xe052);
data &= ~0x6000;
data |= 0x8008;
r8168_mac_ocp_write(tp, 0xe052, data);
data = r8168_mac_ocp_read(tp, 0xe0d6);
data &= ~0x01ff;
data |= 0x017f;
r8168_mac_ocp_write(tp, 0xe0d6, data);
data = r8168_mac_ocp_read(tp, 0xd420);
data &= ~0x0fff;
data |= 0x047f;
r8168_mac_ocp_write(tp, 0xd420, data);
r8168_mac_ocp_write(tp, 0xe63e, 0x0001);
r8168_mac_ocp_write(tp, 0xe63e, 0x0000);
r8168_mac_ocp_write(tp, 0xc094, 0x0000);
r8168_mac_ocp_write(tp, 0xc09e, 0x0000);
}
static void rtl_hw_start_8168ep(struct rtl8169_private *tp)
{
void __iomem *ioaddr = tp->mmio_addr;
struct pci_dev *pdev = tp->pci_dev;
rtl8168ep_stop_cmac(tp);
RTL_W32(TxConfig, RTL_R32(TxConfig) | TXCFG_AUTO_FIFO);
rtl_eri_write(tp, 0xc8, ERIAR_MASK_0101, 0x00080002, ERIAR_EXGMAC);
rtl_eri_write(tp, 0xcc, ERIAR_MASK_0001, 0x2f, ERIAR_EXGMAC);
rtl_eri_write(tp, 0xd0, ERIAR_MASK_0001, 0x5f, ERIAR_EXGMAC);
rtl_eri_write(tp, 0xe8, ERIAR_MASK_1111, 0x00100006, ERIAR_EXGMAC);
rtl_csi_access_enable_1(tp);
rtl_tx_performance_tweak(pdev, 0x5 << MAX_READ_REQUEST_SHIFT);
rtl_w0w1_eri(tp, 0xdc, ERIAR_MASK_0001, 0x00, 0x01, ERIAR_EXGMAC);
rtl_w0w1_eri(tp, 0xdc, ERIAR_MASK_0001, 0x01, 0x00, ERIAR_EXGMAC);
rtl_w0w1_eri(tp, 0xd4, ERIAR_MASK_1111, 0x1f80, 0x00, ERIAR_EXGMAC);
rtl_eri_write(tp, 0x5f0, ERIAR_MASK_0011, 0x4f87, ERIAR_EXGMAC);
RTL_W32(MISC, RTL_R32(MISC) & ~RXDV_GATED_EN);
RTL_W8(MaxTxPacketSize, EarlySize);
rtl_eri_write(tp, 0xc0, ERIAR_MASK_0011, 0x0000, ERIAR_EXGMAC);
rtl_eri_write(tp, 0xb8, ERIAR_MASK_0011, 0x0000, ERIAR_EXGMAC);
RTL_W8(EEE_LED, RTL_R8(EEE_LED) & ~0x07);
rtl_w0w1_eri(tp, 0x2fc, ERIAR_MASK_0001, 0x01, 0x06, ERIAR_EXGMAC);
RTL_W8(DLLPR, RTL_R8(DLLPR) & ~TX_10M_PS_EN);
rtl_pcie_state_l2l3_enable(tp, false);
}
static void rtl_hw_start_8168ep_1(struct rtl8169_private *tp)
{
void __iomem *ioaddr = tp->mmio_addr;
static const struct ephy_info e_info_8168ep_1[] = {
{ 0x00, 0xffff, 0x10ab },
{ 0x06, 0xffff, 0xf030 },
{ 0x08, 0xffff, 0x2006 },
{ 0x0d, 0xffff, 0x1666 },
{ 0x0c, 0x3ff0, 0x0000 }
};
RTL_W8(Config2, RTL_R8(Config2) & ~ClkReqEn);
RTL_W8(Config5, RTL_R8(Config5) & ~ASPM_en);
rtl_ephy_init(tp, e_info_8168ep_1, ARRAY_SIZE(e_info_8168ep_1));
rtl_hw_start_8168ep(tp);
}
static void rtl_hw_start_8168ep_2(struct rtl8169_private *tp)
{
void __iomem *ioaddr = tp->mmio_addr;
static const struct ephy_info e_info_8168ep_2[] = {
{ 0x00, 0xffff, 0x10a3 },
{ 0x19, 0xffff, 0xfc00 },
{ 0x1e, 0xffff, 0x20ea }
};
RTL_W8(Config2, RTL_R8(Config2) & ~ClkReqEn);
RTL_W8(Config5, RTL_R8(Config5) & ~ASPM_en);
rtl_ephy_init(tp, e_info_8168ep_2, ARRAY_SIZE(e_info_8168ep_2));
rtl_hw_start_8168ep(tp);
RTL_W8(DLLPR, RTL_R8(DLLPR) & ~PFM_EN);
RTL_W8(MISC_1, RTL_R8(MISC_1) & ~PFM_D3COLD_EN);
}
static void rtl_hw_start_8168ep_3(struct rtl8169_private *tp)
{
void __iomem *ioaddr = tp->mmio_addr;
u32 data;
static const struct ephy_info e_info_8168ep_3[] = {
{ 0x00, 0xffff, 0x10a3 },
{ 0x19, 0xffff, 0x7c00 },
{ 0x1e, 0xffff, 0x20eb },
{ 0x0d, 0xffff, 0x1666 }
};
RTL_W8(Config2, RTL_R8(Config2) & ~ClkReqEn);
RTL_W8(Config5, RTL_R8(Config5) & ~ASPM_en);
rtl_ephy_init(tp, e_info_8168ep_3, ARRAY_SIZE(e_info_8168ep_3));
rtl_hw_start_8168ep(tp);
RTL_W8(DLLPR, RTL_R8(DLLPR) & ~PFM_EN);
RTL_W8(MISC_1, RTL_R8(MISC_1) & ~PFM_D3COLD_EN);
data = r8168_mac_ocp_read(tp, 0xd3e2);
data &= 0xf000;
data |= 0x0271;
r8168_mac_ocp_write(tp, 0xd3e2, data);
data = r8168_mac_ocp_read(tp, 0xd3e4);
data &= 0xff00;
r8168_mac_ocp_write(tp, 0xd3e4, data);
data = r8168_mac_ocp_read(tp, 0xe860);
data |= 0x0080;
r8168_mac_ocp_write(tp, 0xe860, data);
}
static void rtl_hw_start_8168(struct net_device *dev)
{
struct rtl8169_private *tp = netdev_priv(dev);
void __iomem *ioaddr = tp->mmio_addr;
RTL_W8(Cfg9346, Cfg9346_Unlock);
RTL_W8(MaxTxPacketSize, TxPacketMax);
rtl_set_rx_max_size(ioaddr, rx_buf_sz);
tp->cp_cmd |= RTL_R16(CPlusCmd) | PktCntrDisable | INTT_1;
RTL_W16(CPlusCmd, tp->cp_cmd);
RTL_W16(IntrMitigate, 0x5151);
if (tp->mac_version == RTL_GIGA_MAC_VER_11) {
tp->event_slow |= RxFIFOOver | PCSTimeout;
tp->event_slow &= ~RxOverflow;
}
rtl_set_rx_tx_desc_registers(tp, ioaddr);
rtl_set_rx_tx_config_registers(tp);
RTL_R8(IntrMask);
switch (tp->mac_version) {
case RTL_GIGA_MAC_VER_11:
rtl_hw_start_8168bb(tp);
break;
case RTL_GIGA_MAC_VER_12:
case RTL_GIGA_MAC_VER_17:
rtl_hw_start_8168bef(tp);
break;
case RTL_GIGA_MAC_VER_18:
rtl_hw_start_8168cp_1(tp);
break;
case RTL_GIGA_MAC_VER_19:
rtl_hw_start_8168c_1(tp);
break;
case RTL_GIGA_MAC_VER_20:
rtl_hw_start_8168c_2(tp);
break;
case RTL_GIGA_MAC_VER_21:
rtl_hw_start_8168c_3(tp);
break;
case RTL_GIGA_MAC_VER_22:
rtl_hw_start_8168c_4(tp);
break;
case RTL_GIGA_MAC_VER_23:
rtl_hw_start_8168cp_2(tp);
break;
case RTL_GIGA_MAC_VER_24:
rtl_hw_start_8168cp_3(tp);
break;
case RTL_GIGA_MAC_VER_25:
case RTL_GIGA_MAC_VER_26:
case RTL_GIGA_MAC_VER_27:
rtl_hw_start_8168d(tp);
break;
case RTL_GIGA_MAC_VER_28:
rtl_hw_start_8168d_4(tp);
break;
case RTL_GIGA_MAC_VER_31:
rtl_hw_start_8168dp(tp);
break;
case RTL_GIGA_MAC_VER_32:
case RTL_GIGA_MAC_VER_33:
rtl_hw_start_8168e_1(tp);
break;
case RTL_GIGA_MAC_VER_34:
rtl_hw_start_8168e_2(tp);
break;
case RTL_GIGA_MAC_VER_35:
case RTL_GIGA_MAC_VER_36:
rtl_hw_start_8168f_1(tp);
break;
case RTL_GIGA_MAC_VER_38:
rtl_hw_start_8411(tp);
break;
case RTL_GIGA_MAC_VER_40:
case RTL_GIGA_MAC_VER_41:
rtl_hw_start_8168g_1(tp);
break;
case RTL_GIGA_MAC_VER_42:
rtl_hw_start_8168g_2(tp);
break;
case RTL_GIGA_MAC_VER_44:
rtl_hw_start_8411_2(tp);
break;
case RTL_GIGA_MAC_VER_45:
case RTL_GIGA_MAC_VER_46:
rtl_hw_start_8168h_1(tp);
break;
case RTL_GIGA_MAC_VER_49:
rtl_hw_start_8168ep_1(tp);
break;
case RTL_GIGA_MAC_VER_50:
rtl_hw_start_8168ep_2(tp);
break;
case RTL_GIGA_MAC_VER_51:
rtl_hw_start_8168ep_3(tp);
break;
default:
printk(KERN_ERR PFX "%s: unknown chipset (mac_version = %d).\n",
dev->name, tp->mac_version);
break;
}
RTL_W8(Cfg9346, Cfg9346_Lock);
RTL_W8(ChipCmd, CmdTxEnb | CmdRxEnb);
rtl_set_rx_mode(dev);
RTL_W16(MultiIntr, RTL_R16(MultiIntr) & 0xf000);
}
static void rtl_hw_start_8102e_1(struct rtl8169_private *tp)
{
void __iomem *ioaddr = tp->mmio_addr;
struct pci_dev *pdev = tp->pci_dev;
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
rtl_csi_access_enable_2(tp);
RTL_W8(DBG_REG, FIX_NAK_1);
rtl_tx_performance_tweak(pdev, 0x5 << MAX_READ_REQUEST_SHIFT);
RTL_W8(Config1,
LEDS1 | LEDS0 | Speed_down | MEMMAP | IOMAP | VPD | PMEnable);
RTL_W8(Config3, RTL_R8(Config3) & ~Beacon_en);
cfg1 = RTL_R8(Config1);
if ((cfg1 & LEDS0) && (cfg1 & LEDS1))
RTL_W8(Config1, cfg1 & ~LEDS0);
rtl_ephy_init(tp, e_info_8102e_1, ARRAY_SIZE(e_info_8102e_1));
}
static void rtl_hw_start_8102e_2(struct rtl8169_private *tp)
{
void __iomem *ioaddr = tp->mmio_addr;
struct pci_dev *pdev = tp->pci_dev;
rtl_csi_access_enable_2(tp);
rtl_tx_performance_tweak(pdev, 0x5 << MAX_READ_REQUEST_SHIFT);
RTL_W8(Config1, MEMMAP | IOMAP | VPD | PMEnable);
RTL_W8(Config3, RTL_R8(Config3) & ~Beacon_en);
}
static void rtl_hw_start_8102e_3(struct rtl8169_private *tp)
{
rtl_hw_start_8102e_2(tp);
rtl_ephy_write(tp, 0x03, 0xc2f9);
}
static void rtl_hw_start_8105e_1(struct rtl8169_private *tp)
{
void __iomem *ioaddr = tp->mmio_addr;
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
RTL_W8(DLLPR, RTL_R8(DLLPR) | PFM_EN);
rtl_ephy_init(tp, e_info_8105e_1, ARRAY_SIZE(e_info_8105e_1));
rtl_pcie_state_l2l3_enable(tp, false);
}
static void rtl_hw_start_8105e_2(struct rtl8169_private *tp)
{
rtl_hw_start_8105e_1(tp);
rtl_ephy_write(tp, 0x1e, rtl_ephy_read(tp, 0x1e) | 0x8000);
}
static void rtl_hw_start_8402(struct rtl8169_private *tp)
{
void __iomem *ioaddr = tp->mmio_addr;
static const struct ephy_info e_info_8402[] = {
{ 0x19, 0xffff, 0xff64 },
{ 0x1e, 0, 0x4000 }
};
rtl_csi_access_enable_2(tp);
RTL_W32(FuncEvent, RTL_R32(FuncEvent) | 0x002800);
RTL_W32(TxConfig, RTL_R32(TxConfig) | TXCFG_AUTO_FIFO);
RTL_W8(MCU, RTL_R8(MCU) & ~NOW_IS_OOB);
rtl_ephy_init(tp, e_info_8402, ARRAY_SIZE(e_info_8402));
rtl_tx_performance_tweak(tp->pci_dev, 0x5 << MAX_READ_REQUEST_SHIFT);
rtl_eri_write(tp, 0xc8, ERIAR_MASK_1111, 0x00000002, ERIAR_EXGMAC);
rtl_eri_write(tp, 0xe8, ERIAR_MASK_1111, 0x00000006, ERIAR_EXGMAC);
rtl_w0w1_eri(tp, 0xdc, ERIAR_MASK_0001, 0x00, 0x01, ERIAR_EXGMAC);
rtl_w0w1_eri(tp, 0xdc, ERIAR_MASK_0001, 0x01, 0x00, ERIAR_EXGMAC);
rtl_eri_write(tp, 0xc0, ERIAR_MASK_0011, 0x0000, ERIAR_EXGMAC);
rtl_eri_write(tp, 0xb8, ERIAR_MASK_0011, 0x0000, ERIAR_EXGMAC);
rtl_w0w1_eri(tp, 0x0d4, ERIAR_MASK_0011, 0x0e00, 0xff00, ERIAR_EXGMAC);
rtl_pcie_state_l2l3_enable(tp, false);
}
static void rtl_hw_start_8106(struct rtl8169_private *tp)
{
void __iomem *ioaddr = tp->mmio_addr;
RTL_W32(FuncEvent, RTL_R32(FuncEvent) | 0x002800);
RTL_W32(MISC, (RTL_R32(MISC) | DISABLE_LAN_EN) & ~EARLY_TALLY_EN);
RTL_W8(MCU, RTL_R8(MCU) | EN_NDP | EN_OOB_RESET);
RTL_W8(DLLPR, RTL_R8(DLLPR) & ~PFM_EN);
rtl_pcie_state_l2l3_enable(tp, false);
}
static void rtl_hw_start_8101(struct net_device *dev)
{
struct rtl8169_private *tp = netdev_priv(dev);
void __iomem *ioaddr = tp->mmio_addr;
struct pci_dev *pdev = tp->pci_dev;
if (tp->mac_version >= RTL_GIGA_MAC_VER_30)
tp->event_slow &= ~RxFIFOOver;
if (tp->mac_version == RTL_GIGA_MAC_VER_13 ||
tp->mac_version == RTL_GIGA_MAC_VER_16)
pcie_capability_set_word(pdev, PCI_EXP_DEVCTL,
PCI_EXP_DEVCTL_NOSNOOP_EN);
RTL_W8(Cfg9346, Cfg9346_Unlock);
RTL_W8(MaxTxPacketSize, TxPacketMax);
rtl_set_rx_max_size(ioaddr, rx_buf_sz);
tp->cp_cmd &= ~R810X_CPCMD_QUIRK_MASK;
RTL_W16(CPlusCmd, tp->cp_cmd);
rtl_set_rx_tx_desc_registers(tp, ioaddr);
rtl_set_rx_tx_config_registers(tp);
switch (tp->mac_version) {
case RTL_GIGA_MAC_VER_07:
rtl_hw_start_8102e_1(tp);
break;
case RTL_GIGA_MAC_VER_08:
rtl_hw_start_8102e_3(tp);
break;
case RTL_GIGA_MAC_VER_09:
rtl_hw_start_8102e_2(tp);
break;
case RTL_GIGA_MAC_VER_29:
rtl_hw_start_8105e_1(tp);
break;
case RTL_GIGA_MAC_VER_30:
rtl_hw_start_8105e_2(tp);
break;
case RTL_GIGA_MAC_VER_37:
rtl_hw_start_8402(tp);
break;
case RTL_GIGA_MAC_VER_39:
rtl_hw_start_8106(tp);
break;
case RTL_GIGA_MAC_VER_43:
rtl_hw_start_8168g_2(tp);
break;
case RTL_GIGA_MAC_VER_47:
case RTL_GIGA_MAC_VER_48:
rtl_hw_start_8168h_1(tp);
break;
}
RTL_W8(Cfg9346, Cfg9346_Lock);
RTL_W16(IntrMitigate, 0x0000);
RTL_W8(ChipCmd, CmdTxEnb | CmdRxEnb);
rtl_set_rx_mode(dev);
RTL_R8(IntrMask);
RTL_W16(MultiIntr, RTL_R16(MultiIntr) & 0xf000);
}
static int rtl8169_change_mtu(struct net_device *dev, int new_mtu)
{
struct rtl8169_private *tp = netdev_priv(dev);
if (new_mtu > ETH_DATA_LEN)
rtl_hw_jumbo_enable(tp);
else
rtl_hw_jumbo_disable(tp);
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
dma_wmb();
desc->opts1 = cpu_to_le32(DescOwn | eor | rx_buf_sz);
}
static inline void rtl8169_map_to_asic(struct RxDesc *desc, dma_addr_t mapping,
u32 rx_buf_sz)
{
desc->addr = cpu_to_le64(mapping);
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
dev_kfree_skb_any(skb);
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
static void rtl_reset_work(struct rtl8169_private *tp)
{
struct net_device *dev = tp->dev;
int i;
napi_disable(&tp->napi);
netif_stop_queue(dev);
synchronize_sched();
rtl8169_hw_reset(tp);
for (i = 0; i < NUM_RX_DESC; i++)
rtl8169_mark_to_asic(tp->RxDescArray + i, rx_buf_sz);
rtl8169_tx_clear(tp);
rtl8169_init_ring_indexes(tp);
napi_enable(&tp->napi);
rtl_hw_start(dev);
netif_wake_queue(dev);
rtl8169_check_link_status(dev, tp, tp->mmio_addr);
}
static void rtl8169_tx_timeout(struct net_device *dev)
{
struct rtl8169_private *tp = netdev_priv(dev);
rtl_schedule_task(tp, RTL_FLAG_TASK_RESET_PENDING);
}
static int rtl8169_xmit_frags(struct rtl8169_private *tp, struct sk_buff *skb,
u32 *opts)
{
struct skb_shared_info *info = skb_shinfo(skb);
unsigned int cur_frag, entry;
struct TxDesc *uninitialized_var(txd);
struct device *d = &tp->pci_dev->dev;
entry = tp->cur_tx;
for (cur_frag = 0; cur_frag < info->nr_frags; cur_frag++) {
const skb_frag_t *frag = info->frags + cur_frag;
dma_addr_t mapping;
u32 status, len;
void *addr;
entry = (entry + 1) % NUM_TX_DESC;
txd = tp->TxDescArray + entry;
len = skb_frag_size(frag);
addr = skb_frag_address(frag);
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
static bool rtl_test_hw_pad_bug(struct rtl8169_private *tp, struct sk_buff *skb)
{
return skb->len < ETH_ZLEN && tp->mac_version == RTL_GIGA_MAC_VER_34;
}
static void r8169_csum_workaround(struct rtl8169_private *tp,
struct sk_buff *skb)
{
if (skb_shinfo(skb)->gso_size) {
netdev_features_t features = tp->dev->features;
struct sk_buff *segs, *nskb;
features &= ~(NETIF_F_SG | NETIF_F_IPV6_CSUM | NETIF_F_TSO6);
segs = skb_gso_segment(skb, features);
if (IS_ERR(segs) || !segs)
goto drop;
do {
nskb = segs;
segs = segs->next;
nskb->next = NULL;
rtl8169_start_xmit(nskb, tp->dev);
} while (segs);
dev_consume_skb_any(skb);
} else if (skb->ip_summed == CHECKSUM_PARTIAL) {
if (skb_checksum_help(skb) < 0)
goto drop;
rtl8169_start_xmit(skb, tp->dev);
} else {
struct net_device_stats *stats;
drop:
stats = &tp->dev->stats;
stats->tx_dropped++;
dev_kfree_skb_any(skb);
}
}
static int msdn_giant_send_check(struct sk_buff *skb)
{
const struct ipv6hdr *ipv6h;
struct tcphdr *th;
int ret;
ret = skb_cow_head(skb, 0);
if (ret)
return ret;
ipv6h = ipv6_hdr(skb);
th = tcp_hdr(skb);
th->check = 0;
th->check = ~tcp_v6_check(0, &ipv6h->saddr, &ipv6h->daddr, 0);
return ret;
}
static inline __be16 get_protocol(struct sk_buff *skb)
{
__be16 protocol;
if (skb->protocol == htons(ETH_P_8021Q))
protocol = vlan_eth_hdr(skb)->h_vlan_encapsulated_proto;
else
protocol = skb->protocol;
return protocol;
}
static bool rtl8169_tso_csum_v1(struct rtl8169_private *tp,
struct sk_buff *skb, u32 *opts)
{
u32 mss = skb_shinfo(skb)->gso_size;
if (mss) {
opts[0] |= TD_LSO;
opts[0] |= min(mss, TD_MSS_MAX) << TD0_MSS_SHIFT;
} else if (skb->ip_summed == CHECKSUM_PARTIAL) {
const struct iphdr *ip = ip_hdr(skb);
if (ip->protocol == IPPROTO_TCP)
opts[0] |= TD0_IP_CS | TD0_TCP_CS;
else if (ip->protocol == IPPROTO_UDP)
opts[0] |= TD0_IP_CS | TD0_UDP_CS;
else
WARN_ON_ONCE(1);
}
return true;
}
static bool rtl8169_tso_csum_v2(struct rtl8169_private *tp,
struct sk_buff *skb, u32 *opts)
{
u32 transport_offset = (u32)skb_transport_offset(skb);
u32 mss = skb_shinfo(skb)->gso_size;
if (mss) {
if (transport_offset > GTTCPHO_MAX) {
netif_warn(tp, tx_err, tp->dev,
"Invalid transport offset 0x%x for TSO\n",
transport_offset);
return false;
}
switch (get_protocol(skb)) {
case htons(ETH_P_IP):
opts[0] |= TD1_GTSENV4;
break;
case htons(ETH_P_IPV6):
if (msdn_giant_send_check(skb))
return false;
opts[0] |= TD1_GTSENV6;
break;
default:
WARN_ON_ONCE(1);
break;
}
opts[0] |= transport_offset << GTTCPHO_SHIFT;
opts[1] |= min(mss, TD_MSS_MAX) << TD1_MSS_SHIFT;
} else if (skb->ip_summed == CHECKSUM_PARTIAL) {
u8 ip_protocol;
if (unlikely(rtl_test_hw_pad_bug(tp, skb)))
return !(skb_checksum_help(skb) || eth_skb_pad(skb));
if (transport_offset > TCPHO_MAX) {
netif_warn(tp, tx_err, tp->dev,
"Invalid transport offset 0x%x\n",
transport_offset);
return false;
}
switch (get_protocol(skb)) {
case htons(ETH_P_IP):
opts[1] |= TD1_IPv4_CS;
ip_protocol = ip_hdr(skb)->protocol;
break;
case htons(ETH_P_IPV6):
opts[1] |= TD1_IPv6_CS;
ip_protocol = ipv6_hdr(skb)->nexthdr;
break;
default:
ip_protocol = IPPROTO_RAW;
break;
}
if (ip_protocol == IPPROTO_TCP)
opts[1] |= TD1_TCP_CS;
else if (ip_protocol == IPPROTO_UDP)
opts[1] |= TD1_UDP_CS;
else
WARN_ON_ONCE(1);
opts[1] |= transport_offset << TCPHO_SHIFT;
} else {
if (unlikely(rtl_test_hw_pad_bug(tp, skb)))
return !eth_skb_pad(skb);
}
return true;
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
if (unlikely(!TX_FRAGS_READY_FOR(tp, skb_shinfo(skb)->nr_frags))) {
netif_err(tp, drv, dev, "BUG! Tx Ring full when queue awake!\n");
goto err_stop_0;
}
if (unlikely(le32_to_cpu(txd->opts1) & DescOwn))
goto err_stop_0;
opts[1] = cpu_to_le32(rtl8169_tx_vlan_tag(skb));
opts[0] = DescOwn;
if (!tp->tso_csum(tp, skb, opts)) {
r8169_csum_workaround(tp, skb);
return NETDEV_TX_OK;
}
len = skb_headlen(skb);
mapping = dma_map_single(d, skb->data, len, DMA_TO_DEVICE);
if (unlikely(dma_mapping_error(d, mapping))) {
if (net_ratelimit())
netif_err(tp, drv, dev, "Failed to map TX DMA!\n");
goto err_dma_0;
}
tp->tx_skb[entry].len = len;
txd->addr = cpu_to_le64(mapping);
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
skb_tx_timestamp(skb);
dma_wmb();
status = opts[0] | len | (RingEnd * !((entry + 1) % NUM_TX_DESC));
txd->opts1 = cpu_to_le32(status);
wmb();
tp->cur_tx += frags + 1;
RTL_W8(TxPoll, NPQ);
mmiowb();
if (!TX_FRAGS_READY_FOR(tp, MAX_SKB_FRAGS)) {
smp_wmb();
netif_stop_queue(dev);
smp_mb();
if (TX_FRAGS_READY_FOR(tp, MAX_SKB_FRAGS))
netif_wake_queue(dev);
}
return NETDEV_TX_OK;
err_dma_1:
rtl8169_unmap_tx_skb(d, tp->tx_skb + entry, txd);
err_dma_0:
dev_kfree_skb_any(skb);
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
if ((tp->cp_cmd & PCIDAC) && !tp->cur_rx) {
void __iomem *ioaddr = tp->mmio_addr;
netif_info(tp, intr, dev, "disabling PCI DAC\n");
tp->cp_cmd &= ~PCIDAC;
RTL_W16(CPlusCmd, tp->cp_cmd);
dev->features &= ~NETIF_F_HIGHDMA;
}
rtl8169_hw_reset(tp);
rtl_schedule_task(tp, RTL_FLAG_TASK_RESET_PENDING);
}
static void rtl_tx(struct net_device *dev, struct rtl8169_private *tp)
{
unsigned int dirty_tx, tx_left;
dirty_tx = tp->dirty_tx;
smp_rmb();
tx_left = tp->cur_tx - dirty_tx;
while (tx_left > 0) {
unsigned int entry = dirty_tx % NUM_TX_DESC;
struct ring_info *tx_skb = tp->tx_skb + entry;
u32 status;
status = le32_to_cpu(tp->TxDescArray[entry].opts1);
if (status & DescOwn)
break;
dma_rmb();
rtl8169_unmap_tx_skb(&tp->pci_dev->dev, tx_skb,
tp->TxDescArray + entry);
if (status & LastFrag) {
u64_stats_update_begin(&tp->tx_stats.syncp);
tp->tx_stats.packets++;
tp->tx_stats.bytes += tx_skb->skb->len;
u64_stats_update_end(&tp->tx_stats.syncp);
dev_kfree_skb_any(tx_skb->skb);
tx_skb->skb = NULL;
}
dirty_tx++;
tx_left--;
}
if (tp->dirty_tx != dirty_tx) {
tp->dirty_tx = dirty_tx;
smp_mb();
if (netif_queue_stopped(dev) &&
TX_FRAGS_READY_FOR(tp, MAX_SKB_FRAGS)) {
netif_wake_queue(dev);
}
if (tp->cur_tx != dirty_tx) {
void __iomem *ioaddr = tp->mmio_addr;
RTL_W8(TxPoll, NPQ);
}
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
skb = napi_alloc_skb(&tp->napi, pkt_size);
if (skb)
memcpy(skb->data, data, pkt_size);
dma_sync_single_for_device(d, addr, pkt_size, DMA_FROM_DEVICE);
return skb;
}
static int rtl_rx(struct net_device *dev, struct rtl8169_private *tp, u32 budget)
{
unsigned int cur_rx, rx_left;
unsigned int count;
cur_rx = tp->cur_rx;
for (rx_left = min(budget, NUM_RX_DESC); rx_left > 0; rx_left--, cur_rx++) {
unsigned int entry = cur_rx % NUM_RX_DESC;
struct RxDesc *desc = tp->RxDescArray + entry;
u32 status;
status = le32_to_cpu(desc->opts1) & tp->opts1_mask;
if (status & DescOwn)
break;
dma_rmb();
if (unlikely(status & RxRES)) {
netif_info(tp, rx_err, dev, "Rx ERROR. status = %08x\n",
status);
dev->stats.rx_errors++;
if (status & (RxRWT | RxRUNT))
dev->stats.rx_length_errors++;
if (status & RxCRC)
dev->stats.rx_crc_errors++;
if (status & RxFOVF) {
rtl_schedule_task(tp, RTL_FLAG_TASK_RESET_PENDING);
dev->stats.rx_fifo_errors++;
}
if ((status & (RxRUNT | RxCRC)) &&
!(status & (RxRWT | RxFOVF)) &&
(dev->features & NETIF_F_RXALL))
goto process_pkt;
} else {
struct sk_buff *skb;
dma_addr_t addr;
int pkt_size;
process_pkt:
addr = le64_to_cpu(desc->addr);
if (likely(!(dev->features & NETIF_F_RXFCS)))
pkt_size = (status & 0x00003fff) - 4;
else
pkt_size = status & 0x00003fff;
if (unlikely(rtl8169_fragmented_frame(status))) {
dev->stats.rx_dropped++;
dev->stats.rx_length_errors++;
goto release_descriptor;
}
skb = rtl8169_try_rx_copy(tp->Rx_databuff[entry],
tp, pkt_size, addr);
if (!skb) {
dev->stats.rx_dropped++;
goto release_descriptor;
}
rtl8169_rx_csum(skb, status);
skb_put(skb, pkt_size);
skb->protocol = eth_type_trans(skb, dev);
rtl8169_rx_vlan_tag(desc, skb);
if (skb->pkt_type == PACKET_MULTICAST)
dev->stats.multicast++;
napi_gro_receive(&tp->napi, skb);
u64_stats_update_begin(&tp->rx_stats.syncp);
tp->rx_stats.packets++;
tp->rx_stats.bytes += pkt_size;
u64_stats_update_end(&tp->rx_stats.syncp);
}
release_descriptor:
desc->opts2 = 0;
rtl8169_mark_to_asic(desc, rx_buf_sz);
}
count = cur_rx - tp->cur_rx;
tp->cur_rx = cur_rx;
return count;
}
static irqreturn_t rtl8169_interrupt(int irq, void *dev_instance)
{
struct net_device *dev = dev_instance;
struct rtl8169_private *tp = netdev_priv(dev);
int handled = 0;
u16 status;
status = rtl_get_events(tp);
if (status && status != 0xffff) {
status &= RTL_EVENT_NAPI | tp->event_slow;
if (status) {
handled = 1;
rtl_irq_disable(tp);
napi_schedule(&tp->napi);
}
}
return IRQ_RETVAL(handled);
}
static void rtl_slow_event_work(struct rtl8169_private *tp)
{
struct net_device *dev = tp->dev;
u16 status;
status = rtl_get_events(tp) & tp->event_slow;
rtl_ack_events(tp, status);
if (unlikely(status & RxFIFOOver)) {
switch (tp->mac_version) {
case RTL_GIGA_MAC_VER_11:
netif_stop_queue(dev);
set_bit(RTL_FLAG_TASK_RESET_PENDING, tp->wk.flags);
default:
break;
}
}
if (unlikely(status & SYSErr))
rtl8169_pcierr_interrupt(dev);
if (status & LinkChg)
__rtl8169_check_link_status(dev, tp, tp->mmio_addr, true);
rtl_irq_enable_all(tp);
}
static void rtl_task(struct work_struct *work)
{
static const struct {
int bitnr;
void (*action)(struct rtl8169_private *);
} rtl_work[] = {
{ RTL_FLAG_TASK_SLOW_PENDING, rtl_slow_event_work },
{ RTL_FLAG_TASK_RESET_PENDING, rtl_reset_work },
{ RTL_FLAG_TASK_PHY_PENDING, rtl_phy_work }
};
struct rtl8169_private *tp =
container_of(work, struct rtl8169_private, wk.work);
struct net_device *dev = tp->dev;
int i;
rtl_lock_work(tp);
if (!netif_running(dev) ||
!test_bit(RTL_FLAG_TASK_ENABLED, tp->wk.flags))
goto out_unlock;
for (i = 0; i < ARRAY_SIZE(rtl_work); i++) {
bool pending;
pending = test_and_clear_bit(rtl_work[i].bitnr, tp->wk.flags);
if (pending)
rtl_work[i].action(tp);
}
out_unlock:
rtl_unlock_work(tp);
}
static int rtl8169_poll(struct napi_struct *napi, int budget)
{
struct rtl8169_private *tp = container_of(napi, struct rtl8169_private, napi);
struct net_device *dev = tp->dev;
u16 enable_mask = RTL_EVENT_NAPI | tp->event_slow;
int work_done= 0;
u16 status;
status = rtl_get_events(tp);
rtl_ack_events(tp, status & ~tp->event_slow);
if (status & RTL_EVENT_NAPI_RX)
work_done = rtl_rx(dev, tp, (u32) budget);
if (status & RTL_EVENT_NAPI_TX)
rtl_tx(dev, tp);
if (status & tp->event_slow) {
enable_mask &= ~tp->event_slow;
rtl_schedule_task(tp, RTL_FLAG_TASK_SLOW_PENDING);
}
if (work_done < budget) {
napi_complete_done(napi, work_done);
rtl_irq_enable(tp, enable_mask);
mmiowb();
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
napi_disable(&tp->napi);
netif_stop_queue(dev);
rtl8169_hw_reset(tp);
rtl8169_rx_missed(dev, ioaddr);
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
rtl_lock_work(tp);
clear_bit(RTL_FLAG_TASK_ENABLED, tp->wk.flags);
rtl8169_down(dev);
rtl_unlock_work(tp);
cancel_work_sync(&tp->wk.work);
free_irq(pdev->irq, dev);
dma_free_coherent(&pdev->dev, R8169_RX_RING_BYTES, tp->RxDescArray,
tp->RxPhyAddr);
dma_free_coherent(&pdev->dev, R8169_TX_RING_BYTES, tp->TxDescArray,
tp->TxPhyAddr);
tp->TxDescArray = NULL;
tp->RxDescArray = NULL;
pm_runtime_put_sync(&pdev->dev);
return 0;
}
static void rtl8169_netpoll(struct net_device *dev)
{
struct rtl8169_private *tp = netdev_priv(dev);
rtl8169_interrupt(tp->pci_dev->irq, dev);
}
static int rtl_open(struct net_device *dev)
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
INIT_WORK(&tp->wk.work, rtl_task);
smp_mb();
rtl_request_firmware(tp);
retval = request_irq(pdev->irq, rtl8169_interrupt,
(tp->features & RTL_FEATURE_MSI) ? 0 : IRQF_SHARED,
dev->name, dev);
if (retval < 0)
goto err_release_fw_2;
rtl_lock_work(tp);
set_bit(RTL_FLAG_TASK_ENABLED, tp->wk.flags);
napi_enable(&tp->napi);
rtl8169_init_phy(dev, tp);
__rtl8169_set_features(dev, dev->features);
rtl_pll_power_up(tp);
rtl_hw_start(dev);
if (!rtl8169_init_counter_offsets(dev))
netif_warn(tp, hw, dev, "counter reset/update failed\n");
netif_start_queue(dev);
rtl_unlock_work(tp);
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
static void
rtl8169_get_stats64(struct net_device *dev, struct rtnl_link_stats64 *stats)
{
struct rtl8169_private *tp = netdev_priv(dev);
void __iomem *ioaddr = tp->mmio_addr;
struct pci_dev *pdev = tp->pci_dev;
struct rtl8169_counters *counters = tp->counters;
unsigned int start;
pm_runtime_get_noresume(&pdev->dev);
if (netif_running(dev) && pm_runtime_active(&pdev->dev))
rtl8169_rx_missed(dev, ioaddr);
do {
start = u64_stats_fetch_begin_irq(&tp->rx_stats.syncp);
stats->rx_packets = tp->rx_stats.packets;
stats->rx_bytes = tp->rx_stats.bytes;
} while (u64_stats_fetch_retry_irq(&tp->rx_stats.syncp, start));
do {
start = u64_stats_fetch_begin_irq(&tp->tx_stats.syncp);
stats->tx_packets = tp->tx_stats.packets;
stats->tx_bytes = tp->tx_stats.bytes;
} while (u64_stats_fetch_retry_irq(&tp->tx_stats.syncp, start));
stats->rx_dropped = dev->stats.rx_dropped;
stats->tx_dropped = dev->stats.tx_dropped;
stats->rx_length_errors = dev->stats.rx_length_errors;
stats->rx_errors = dev->stats.rx_errors;
stats->rx_crc_errors = dev->stats.rx_crc_errors;
stats->rx_fifo_errors = dev->stats.rx_fifo_errors;
stats->rx_missed_errors = dev->stats.rx_missed_errors;
stats->multicast = dev->stats.multicast;
if (pm_runtime_active(&pdev->dev))
rtl8169_update_counters(dev);
stats->tx_errors = le64_to_cpu(counters->tx_errors) -
le64_to_cpu(tp->tc_offset.tx_errors);
stats->collisions = le32_to_cpu(counters->tx_multi_collision) -
le32_to_cpu(tp->tc_offset.tx_multi_collision);
stats->tx_aborted_errors = le16_to_cpu(counters->tx_aborted) -
le16_to_cpu(tp->tc_offset.tx_aborted);
pm_runtime_put_noidle(&pdev->dev);
}
static void rtl8169_net_suspend(struct net_device *dev)
{
struct rtl8169_private *tp = netdev_priv(dev);
if (!netif_running(dev))
return;
netif_device_detach(dev);
netif_stop_queue(dev);
rtl_lock_work(tp);
napi_disable(&tp->napi);
clear_bit(RTL_FLAG_TASK_ENABLED, tp->wk.flags);
rtl_unlock_work(tp);
rtl_pll_power_down(tp);
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
rtl_lock_work(tp);
napi_enable(&tp->napi);
set_bit(RTL_FLAG_TASK_ENABLED, tp->wk.flags);
rtl_unlock_work(tp);
rtl_schedule_task(tp, RTL_FLAG_TASK_RESET_PENDING);
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
rtl_lock_work(tp);
tp->saved_wolopts = __rtl8169_get_wol(tp);
__rtl8169_set_wol(tp, WAKE_ANY);
rtl_unlock_work(tp);
rtl8169_net_suspend(dev);
rtl8169_rx_missed(dev, tp->mmio_addr);
rtl8169_update_counters(dev);
return 0;
}
static int rtl8169_runtime_resume(struct device *device)
{
struct pci_dev *pdev = to_pci_dev(device);
struct net_device *dev = pci_get_drvdata(pdev);
struct rtl8169_private *tp = netdev_priv(dev);
rtl_rar_set(tp, dev->dev_addr);
if (!tp->TxDescArray)
return 0;
rtl_lock_work(tp);
__rtl8169_set_wol(tp, tp->saved_wolopts);
tp->saved_wolopts = 0;
rtl_unlock_work(tp);
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
static void rtl_wol_shutdown_quirk(struct rtl8169_private *tp)
{
void __iomem *ioaddr = tp->mmio_addr;
switch (tp->mac_version) {
case RTL_GIGA_MAC_VER_11:
case RTL_GIGA_MAC_VER_12:
case RTL_GIGA_MAC_VER_17:
pci_clear_master(tp->pci_dev);
RTL_W8(ChipCmd, CmdRxEnb);
RTL_R8(ChipCmd);
break;
default:
break;
}
}
static void rtl_shutdown(struct pci_dev *pdev)
{
struct net_device *dev = pci_get_drvdata(pdev);
struct rtl8169_private *tp = netdev_priv(dev);
struct device *d = &pdev->dev;
pm_runtime_get_sync(d);
rtl8169_net_suspend(dev);
rtl_rar_set(tp, dev->perm_addr);
rtl8169_hw_reset(tp);
if (system_state == SYSTEM_POWER_OFF) {
if (__rtl8169_get_wol(tp) & WAKE_ANY) {
rtl_wol_suspend_quirk(tp);
rtl_wol_shutdown_quirk(tp);
}
pci_wake_from_d3(pdev, true);
pci_set_power_state(pdev, PCI_D3hot);
}
pm_runtime_put_noidle(d);
}
static void rtl_remove_one(struct pci_dev *pdev)
{
struct net_device *dev = pci_get_drvdata(pdev);
struct rtl8169_private *tp = netdev_priv(dev);
if ((tp->mac_version == RTL_GIGA_MAC_VER_27 ||
tp->mac_version == RTL_GIGA_MAC_VER_28 ||
tp->mac_version == RTL_GIGA_MAC_VER_31 ||
tp->mac_version == RTL_GIGA_MAC_VER_49 ||
tp->mac_version == RTL_GIGA_MAC_VER_50 ||
tp->mac_version == RTL_GIGA_MAC_VER_51) &&
r8168_check_dash(tp)) {
rtl8168_driver_stop(tp);
}
netif_napi_del(&tp->napi);
unregister_netdev(dev);
dma_free_coherent(&tp->pci_dev->dev, sizeof(*tp->counters),
tp->counters, tp->counters_phys_addr);
rtl_release_firmware(tp);
if (pci_dev_run_wake(pdev))
pm_runtime_get_noresume(&pdev->dev);
rtl_rar_set(tp, dev->perm_addr);
rtl_disable_msi(pdev, tp);
rtl8169_release_board(pdev, dev, tp->mmio_addr);
}
static unsigned rtl_try_msi(struct rtl8169_private *tp,
const struct rtl_cfg_info *cfg)
{
void __iomem *ioaddr = tp->mmio_addr;
unsigned msi = 0;
u8 cfg2;
cfg2 = RTL_R8(Config2) & ~MSIEnable;
if (cfg->features & RTL_FEATURE_MSI) {
if (pci_enable_msi(tp->pci_dev)) {
netif_info(tp, hw, tp->dev, "no MSI. Back to INTx.\n");
} else {
cfg2 |= MSIEnable;
msi = RTL_FEATURE_MSI;
}
}
if (tp->mac_version <= RTL_GIGA_MAC_VER_06)
RTL_W8(Config2, cfg2);
return msi;
}
static void rtl_hw_init_8168g(struct rtl8169_private *tp)
{
void __iomem *ioaddr = tp->mmio_addr;
u32 data;
tp->ocp_base = OCP_STD_PHY_BASE;
RTL_W32(MISC, RTL_R32(MISC) | RXDV_GATED_EN);
if (!rtl_udelay_loop_wait_high(tp, &rtl_txcfg_empty_cond, 100, 42))
return;
if (!rtl_udelay_loop_wait_high(tp, &rtl_rxtx_empty_cond, 100, 42))
return;
RTL_W8(ChipCmd, RTL_R8(ChipCmd) & ~(CmdTxEnb | CmdRxEnb));
msleep(1);
RTL_W8(MCU, RTL_R8(MCU) & ~NOW_IS_OOB);
data = r8168_mac_ocp_read(tp, 0xe8de);
data &= ~(1 << 14);
r8168_mac_ocp_write(tp, 0xe8de, data);
if (!rtl_udelay_loop_wait_high(tp, &rtl_link_list_ready_cond, 100, 42))
return;
data = r8168_mac_ocp_read(tp, 0xe8de);
data |= (1 << 15);
r8168_mac_ocp_write(tp, 0xe8de, data);
if (!rtl_udelay_loop_wait_high(tp, &rtl_link_list_ready_cond, 100, 42))
return;
}
static void rtl_hw_init_8168ep(struct rtl8169_private *tp)
{
rtl8168ep_stop_cmac(tp);
rtl_hw_init_8168g(tp);
}
static void rtl_hw_initialize(struct rtl8169_private *tp)
{
switch (tp->mac_version) {
case RTL_GIGA_MAC_VER_40:
case RTL_GIGA_MAC_VER_41:
case RTL_GIGA_MAC_VER_42:
case RTL_GIGA_MAC_VER_43:
case RTL_GIGA_MAC_VER_44:
case RTL_GIGA_MAC_VER_45:
case RTL_GIGA_MAC_VER_46:
case RTL_GIGA_MAC_VER_47:
case RTL_GIGA_MAC_VER_48:
rtl_hw_init_8168g(tp);
break;
case RTL_GIGA_MAC_VER_49:
case RTL_GIGA_MAC_VER_50:
case RTL_GIGA_MAC_VER_51:
rtl_hw_init_8168ep(tp);
break;
default:
break;
}
}
static int rtl_init_one(struct pci_dev *pdev, const struct pci_device_id *ent)
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
rc = -ENOMEM;
goto out;
}
SET_NETDEV_DEV(dev, &pdev->dev);
dev->netdev_ops = &rtl_netdev_ops;
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
ioaddr = ioremap(pci_resource_start(pdev, region), R8169_REGS_SIZE);
if (!ioaddr) {
netif_err(tp, probe, dev, "cannot remap MMIO, aborting\n");
rc = -EIO;
goto err_out_free_res_3;
}
tp->mmio_addr = ioaddr;
if (!pci_is_pcie(pdev))
netif_info(tp, probe, dev, "not PCI Express\n");
rtl8169_get_mac_version(tp, dev, cfg->default_ver);
tp->cp_cmd = 0;
if ((sizeof(dma_addr_t) > 4) &&
(use_dac == 1 || (use_dac == -1 && pci_is_pcie(pdev) &&
tp->mac_version >= RTL_GIGA_MAC_VER_18)) &&
!pci_set_dma_mask(pdev, DMA_BIT_MASK(64)) &&
!pci_set_consistent_dma_mask(pdev, DMA_BIT_MASK(64))) {
if (!pci_is_pcie(pdev))
tp->cp_cmd |= PCIDAC;
dev->features |= NETIF_F_HIGHDMA;
} else {
rc = pci_set_dma_mask(pdev, DMA_BIT_MASK(32));
if (rc < 0) {
netif_err(tp, probe, dev, "DMA configuration failed\n");
goto err_out_unmap_4;
}
}
rtl_init_rxcfg(tp);
rtl_irq_disable(tp);
rtl_hw_initialize(tp);
rtl_hw_reset(tp);
rtl_ack_events(tp, 0xffff);
pci_set_master(pdev);
rtl_init_mdio_ops(tp);
rtl_init_pll_power_ops(tp);
rtl_init_jumbo_ops(tp);
rtl_init_csi_ops(tp);
rtl8169_print_mac_version(tp);
chipset = tp->mac_version;
tp->txd_version = rtl_chip_infos[chipset].txd_version;
RTL_W8(Cfg9346, Cfg9346_Unlock);
RTL_W8(Config1, RTL_R8(Config1) | PMEnable);
RTL_W8(Config5, RTL_R8(Config5) & (BWF | MWF | UWF | LanWake | PMEStatus));
switch (tp->mac_version) {
case RTL_GIGA_MAC_VER_34:
case RTL_GIGA_MAC_VER_35:
case RTL_GIGA_MAC_VER_36:
case RTL_GIGA_MAC_VER_37:
case RTL_GIGA_MAC_VER_38:
case RTL_GIGA_MAC_VER_40:
case RTL_GIGA_MAC_VER_41:
case RTL_GIGA_MAC_VER_42:
case RTL_GIGA_MAC_VER_43:
case RTL_GIGA_MAC_VER_44:
case RTL_GIGA_MAC_VER_45:
case RTL_GIGA_MAC_VER_46:
case RTL_GIGA_MAC_VER_47:
case RTL_GIGA_MAC_VER_48:
case RTL_GIGA_MAC_VER_49:
case RTL_GIGA_MAC_VER_50:
case RTL_GIGA_MAC_VER_51:
if (rtl_eri_read(tp, 0xdc, ERIAR_EXGMAC) & MagicPacket_v2)
tp->features |= RTL_FEATURE_WOL;
if ((RTL_R8(Config3) & LinkUp) != 0)
tp->features |= RTL_FEATURE_WOL;
break;
default:
if ((RTL_R8(Config3) & (LinkUp | MagicPacket)) != 0)
tp->features |= RTL_FEATURE_WOL;
break;
}
if ((RTL_R8(Config5) & (UWF | BWF | MWF)) != 0)
tp->features |= RTL_FEATURE_WOL;
tp->features |= rtl_try_msi(tp, cfg);
RTL_W8(Cfg9346, Cfg9346_Lock);
if (rtl_tbi_enabled(tp)) {
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
mutex_init(&tp->wk.mutex);
u64_stats_init(&tp->rx_stats.syncp);
u64_stats_init(&tp->tx_stats.syncp);
if (tp->mac_version == RTL_GIGA_MAC_VER_35 ||
tp->mac_version == RTL_GIGA_MAC_VER_36 ||
tp->mac_version == RTL_GIGA_MAC_VER_37 ||
tp->mac_version == RTL_GIGA_MAC_VER_38 ||
tp->mac_version == RTL_GIGA_MAC_VER_40 ||
tp->mac_version == RTL_GIGA_MAC_VER_41 ||
tp->mac_version == RTL_GIGA_MAC_VER_42 ||
tp->mac_version == RTL_GIGA_MAC_VER_43 ||
tp->mac_version == RTL_GIGA_MAC_VER_44 ||
tp->mac_version == RTL_GIGA_MAC_VER_45 ||
tp->mac_version == RTL_GIGA_MAC_VER_46 ||
tp->mac_version == RTL_GIGA_MAC_VER_47 ||
tp->mac_version == RTL_GIGA_MAC_VER_48 ||
tp->mac_version == RTL_GIGA_MAC_VER_49 ||
tp->mac_version == RTL_GIGA_MAC_VER_50 ||
tp->mac_version == RTL_GIGA_MAC_VER_51) {
u16 mac_addr[3];
*(u32 *)&mac_addr[0] = rtl_eri_read(tp, 0xe0, ERIAR_EXGMAC);
*(u16 *)&mac_addr[2] = rtl_eri_read(tp, 0xe4, ERIAR_EXGMAC);
if (is_valid_ether_addr((u8 *)mac_addr))
rtl_rar_set(tp, (u8 *)mac_addr);
}
for (i = 0; i < ETH_ALEN; i++)
dev->dev_addr[i] = RTL_R8(MAC0 + i);
dev->ethtool_ops = &rtl8169_ethtool_ops;
dev->watchdog_timeo = RTL8169_TX_TIMEOUT;
netif_napi_add(dev, &tp->napi, rtl8169_poll, R8169_NAPI_WEIGHT);
dev->features |= NETIF_F_RXCSUM |
NETIF_F_HW_VLAN_CTAG_TX | NETIF_F_HW_VLAN_CTAG_RX;
dev->hw_features = NETIF_F_SG | NETIF_F_IP_CSUM | NETIF_F_TSO |
NETIF_F_RXCSUM | NETIF_F_HW_VLAN_CTAG_TX |
NETIF_F_HW_VLAN_CTAG_RX;
dev->vlan_features = NETIF_F_SG | NETIF_F_IP_CSUM | NETIF_F_TSO |
NETIF_F_HIGHDMA;
tp->cp_cmd |= RxChkSum | RxVlan;
if (tp->mac_version == RTL_GIGA_MAC_VER_05)
dev->hw_features &= ~NETIF_F_HW_VLAN_CTAG_RX;
if (tp->txd_version == RTL_TD_0)
tp->tso_csum = rtl8169_tso_csum_v1;
else if (tp->txd_version == RTL_TD_1) {
tp->tso_csum = rtl8169_tso_csum_v2;
dev->hw_features |= NETIF_F_IPV6_CSUM | NETIF_F_TSO6;
} else
WARN_ON_ONCE(1);
dev->hw_features |= NETIF_F_RXALL;
dev->hw_features |= NETIF_F_RXFCS;
dev->min_mtu = ETH_ZLEN;
dev->max_mtu = rtl_chip_infos[chipset].jumbo_max;
tp->hw_start = cfg->hw_start;
tp->event_slow = cfg->event_slow;
tp->opts1_mask = (tp->mac_version != RTL_GIGA_MAC_VER_01) ?
~(RxBOVF | RxFOVF) : ~0;
init_timer(&tp->timer);
tp->timer.data = (unsigned long) dev;
tp->timer.function = rtl8169_phy_timer;
tp->rtl_fw = RTL_FIRMWARE_UNKNOWN;
tp->counters = dma_alloc_coherent (&pdev->dev, sizeof(*tp->counters),
&tp->counters_phys_addr, GFP_KERNEL);
if (!tp->counters) {
rc = -ENOMEM;
goto err_out_msi_5;
}
rc = register_netdev(dev);
if (rc < 0)
goto err_out_cnt_6;
pci_set_drvdata(pdev, dev);
netif_info(tp, probe, dev, "%s at 0x%p, %pM, XID %08x IRQ %d\n",
rtl_chip_infos[chipset].name, ioaddr, dev->dev_addr,
(u32)(RTL_R32(TxConfig) & 0x9cf0f8ff), pdev->irq);
if (rtl_chip_infos[chipset].jumbo_max != JUMBO_1K) {
netif_info(tp, probe, dev, "jumbo features [frames: %d bytes, "
"tx checksumming: %s]\n",
rtl_chip_infos[chipset].jumbo_max,
rtl_chip_infos[chipset].jumbo_tx_csum ? "ok" : "ko");
}
if ((tp->mac_version == RTL_GIGA_MAC_VER_27 ||
tp->mac_version == RTL_GIGA_MAC_VER_28 ||
tp->mac_version == RTL_GIGA_MAC_VER_31 ||
tp->mac_version == RTL_GIGA_MAC_VER_49 ||
tp->mac_version == RTL_GIGA_MAC_VER_50 ||
tp->mac_version == RTL_GIGA_MAC_VER_51) &&
r8168_check_dash(tp)) {
rtl8168_driver_start(tp);
}
device_set_wakeup_enable(&pdev->dev, tp->features & RTL_FEATURE_WOL);
if (pci_dev_run_wake(pdev))
pm_runtime_put_noidle(&pdev->dev);
netif_carrier_off(dev);
out:
return rc;
err_out_cnt_6:
dma_free_coherent(&pdev->dev, sizeof(*tp->counters), tp->counters,
tp->counters_phys_addr);
err_out_msi_5:
netif_napi_del(&tp->napi);
rtl_disable_msi(pdev, tp);
err_out_unmap_4:
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
