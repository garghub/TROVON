int PhyMiRead(struct et131x_adapter *etdev, u8 xcvrAddr,
u8 xcvrReg, u16 *value)
{
struct _MAC_t __iomem *mac = &etdev->regs->mac;
int status = 0;
u32 delay;
u32 miiAddr;
u32 miiCmd;
u32 miiIndicator;
miiAddr = readl(&mac->mii_mgmt_addr);
miiCmd = readl(&mac->mii_mgmt_cmd);
writel(0, &mac->mii_mgmt_cmd);
writel(MII_ADDR(xcvrAddr, xcvrReg), &mac->mii_mgmt_addr);
delay = 0;
writel(0x1, &mac->mii_mgmt_cmd);
do {
udelay(50);
delay++;
miiIndicator = readl(&mac->mii_mgmt_indicator);
} while ((miiIndicator & MGMT_WAIT) && delay < 50);
if (delay == 50) {
dev_warn(&etdev->pdev->dev,
"xcvrReg 0x%08x could not be read\n", xcvrReg);
dev_warn(&etdev->pdev->dev, "status is 0x%08x\n",
miiIndicator);
status = -EIO;
}
*value = readl(&mac->mii_mgmt_stat) & 0xFFFF;
writel(0, &mac->mii_mgmt_cmd);
writel(miiAddr, &mac->mii_mgmt_addr);
writel(miiCmd, &mac->mii_mgmt_cmd);
return status;
}
int MiWrite(struct et131x_adapter *etdev, u8 xcvrReg, u16 value)
{
struct _MAC_t __iomem *mac = &etdev->regs->mac;
int status = 0;
u8 xcvrAddr = etdev->Stats.xcvr_addr;
u32 delay;
u32 miiAddr;
u32 miiCmd;
u32 miiIndicator;
miiAddr = readl(&mac->mii_mgmt_addr);
miiCmd = readl(&mac->mii_mgmt_cmd);
writel(0, &mac->mii_mgmt_cmd);
writel(MII_ADDR(xcvrAddr, xcvrReg), &mac->mii_mgmt_addr);
writel(value, &mac->mii_mgmt_ctrl);
delay = 0;
do {
udelay(50);
delay++;
miiIndicator = readl(&mac->mii_mgmt_indicator);
} while ((miiIndicator & MGMT_BUSY) && delay < 100);
if (delay == 100) {
u16 TempValue;
dev_warn(&etdev->pdev->dev,
"xcvrReg 0x%08x could not be written", xcvrReg);
dev_warn(&etdev->pdev->dev, "status is 0x%08x\n",
miiIndicator);
dev_warn(&etdev->pdev->dev, "command is 0x%08x\n",
readl(&mac->mii_mgmt_cmd));
MiRead(etdev, xcvrReg, &TempValue);
status = -EIO;
}
writel(0, &mac->mii_mgmt_cmd);
writel(miiAddr, &mac->mii_mgmt_addr);
writel(miiCmd, &mac->mii_mgmt_cmd);
return status;
}
int et131x_xcvr_find(struct et131x_adapter *etdev)
{
u8 xcvr_addr;
u16 idr1;
u16 idr2;
u32 xcvr_id;
for (xcvr_addr = 0; xcvr_addr < 32; xcvr_addr++) {
PhyMiRead(etdev, xcvr_addr,
(u8) offsetof(struct mi_regs, idr1),
&idr1);
PhyMiRead(etdev, xcvr_addr,
(u8) offsetof(struct mi_regs, idr2),
&idr2);
xcvr_id = (u32) ((idr1 << 16) | idr2);
if (idr1 != 0 && idr1 != 0xffff) {
etdev->Stats.xcvr_id = xcvr_id;
etdev->Stats.xcvr_addr = xcvr_addr;
return 0;
}
}
return -ENODEV;
}
void ET1310_PhyReset(struct et131x_adapter *etdev)
{
MiWrite(etdev, PHY_CONTROL, 0x8000);
}
void ET1310_PhyPowerDown(struct et131x_adapter *etdev, bool down)
{
u16 data;
MiRead(etdev, PHY_CONTROL, &data);
data &= ~0x0800;
if (down)
data |= 0x0800;
MiWrite(etdev, PHY_CONTROL, data);
}
static void ET1310_PhyAutoNeg(struct et131x_adapter *etdev, bool enable)
{
u16 data;
MiRead(etdev, PHY_CONTROL, &data);
data &= ~0x1000;
if (enable)
data |= 0x1000;
MiWrite(etdev, PHY_CONTROL, data);
}
static void ET1310_PhyDuplexMode(struct et131x_adapter *etdev, u16 duplex)
{
u16 data;
MiRead(etdev, PHY_CONTROL, &data);
data &= ~0x100;
if (duplex == TRUEPHY_DUPLEX_FULL)
data |= 0x100;
MiWrite(etdev, PHY_CONTROL, data);
}
static void ET1310_PhySpeedSelect(struct et131x_adapter *etdev, u16 speed)
{
u16 data;
static const u16 bits[3] = {0x0000, 0x2000, 0x0040};
MiRead(etdev, PHY_CONTROL, &data);
data &= ~0x2040;
MiWrite(etdev, PHY_CONTROL, data | bits[speed]);
}
static void ET1310_PhyLinkStatus(struct et131x_adapter *etdev,
u8 *link_status,
u32 *autoneg,
u32 *linkspeed,
u32 *duplex_mode,
u32 *mdi_mdix,
u32 *masterslave, u32 *polarity)
{
u16 mistatus = 0;
u16 is1000BaseT = 0;
u16 vmi_phystatus = 0;
u16 control = 0;
MiRead(etdev, PHY_STATUS, &mistatus);
MiRead(etdev, PHY_1000_STATUS, &is1000BaseT);
MiRead(etdev, PHY_PHY_STATUS, &vmi_phystatus);
MiRead(etdev, PHY_CONTROL, &control);
*link_status = (vmi_phystatus & 0x0040) ? 1 : 0;
*autoneg = (control & 0x1000) ? ((vmi_phystatus & 0x0020) ?
TRUEPHY_ANEG_COMPLETE :
TRUEPHY_ANEG_NOT_COMPLETE) :
TRUEPHY_ANEG_DISABLED;
*linkspeed = (vmi_phystatus & 0x0300) >> 8;
*duplex_mode = (vmi_phystatus & 0x0080) >> 7;
*mdi_mdix = 0;
*masterslave = (is1000BaseT & 0x4000) ?
TRUEPHY_CFG_MASTER : TRUEPHY_CFG_SLAVE;
*polarity = (vmi_phystatus & 0x0400) ?
TRUEPHY_POLARITY_INVERTED : TRUEPHY_POLARITY_NORMAL;
}
static void ET1310_PhyAndOrReg(struct et131x_adapter *etdev,
u16 regnum, u16 andMask, u16 orMask)
{
u16 reg;
MiRead(etdev, regnum, &reg);
reg &= andMask;
reg |= orMask;
MiWrite(etdev, regnum, reg);
}
void ET1310_PhyAccessMiBit(struct et131x_adapter *etdev, u16 action,
u16 regnum, u16 bitnum, u8 *value)
{
u16 reg;
u16 mask = 0x0001 << bitnum;
MiRead(etdev, regnum, &reg);
switch (action) {
case TRUEPHY_BIT_READ:
*value = (reg & mask) >> bitnum;
break;
case TRUEPHY_BIT_SET:
MiWrite(etdev, regnum, reg | mask);
break;
case TRUEPHY_BIT_CLEAR:
MiWrite(etdev, regnum, reg & ~mask);
break;
default:
break;
}
}
void ET1310_PhyAdvertise1000BaseT(struct et131x_adapter *etdev,
u16 duplex)
{
u16 data;
MiRead(etdev, PHY_1000_CONTROL, &data);
data &= ~0x0300;
switch (duplex) {
case TRUEPHY_ADV_DUPLEX_NONE:
break;
case TRUEPHY_ADV_DUPLEX_FULL:
data |= 0x0200;
break;
case TRUEPHY_ADV_DUPLEX_HALF:
data |= 0x0100;
break;
case TRUEPHY_ADV_DUPLEX_BOTH:
default:
data |= 0x0300;
break;
}
MiWrite(etdev, PHY_1000_CONTROL, data);
}
static void ET1310_PhyAdvertise100BaseT(struct et131x_adapter *etdev,
u16 duplex)
{
u16 data;
MiRead(etdev, PHY_AUTO_ADVERTISEMENT, &data);
data &= ~0x0180;
switch (duplex) {
case TRUEPHY_ADV_DUPLEX_NONE:
break;
case TRUEPHY_ADV_DUPLEX_FULL:
data |= 0x0100;
break;
case TRUEPHY_ADV_DUPLEX_HALF:
data |= 0x0080;
break;
case TRUEPHY_ADV_DUPLEX_BOTH:
default:
data |= 0x0180;
break;
}
MiWrite(etdev, PHY_AUTO_ADVERTISEMENT, data);
}
static void ET1310_PhyAdvertise10BaseT(struct et131x_adapter *etdev,
u16 duplex)
{
u16 data;
MiRead(etdev, PHY_AUTO_ADVERTISEMENT, &data);
data &= ~0x0060;
switch (duplex) {
case TRUEPHY_ADV_DUPLEX_NONE:
break;
case TRUEPHY_ADV_DUPLEX_FULL:
data |= 0x0040;
break;
case TRUEPHY_ADV_DUPLEX_HALF:
data |= 0x0020;
break;
case TRUEPHY_ADV_DUPLEX_BOTH:
default:
data |= 0x0060;
break;
}
MiWrite(etdev, PHY_AUTO_ADVERTISEMENT, data);
}
void et131x_setphy_normal(struct et131x_adapter *etdev)
{
ET1310_PhyPowerDown(etdev, 0);
et131x_xcvr_init(etdev);
}
static void et131x_xcvr_init(struct et131x_adapter *etdev)
{
u16 imr;
u16 isr;
u16 lcr2;
etdev->Bmsr.value = 0;
MiRead(etdev, (u8) offsetof(struct mi_regs, isr), &isr);
MiRead(etdev, (u8) offsetof(struct mi_regs, imr), &imr);
imr |= 0x0105;
MiWrite(etdev, (u8) offsetof(struct mi_regs, imr), imr);
if ((etdev->eeprom_data[1] & 0x4) == 0) {
MiRead(etdev, (u8) offsetof(struct mi_regs, lcr2),
&lcr2);
lcr2 &= 0x00FF;
lcr2 |= 0xA000;
if ((etdev->eeprom_data[1] & 0x8) == 0)
lcr2 |= 0x0300;
else
lcr2 |= 0x0400;
MiWrite(etdev, (u8) offsetof(struct mi_regs, lcr2),
lcr2);
}
if (etdev->AiForceSpeed == 0 && etdev->AiForceDpx == 0) {
if (etdev->wanted_flow == FLOW_TXONLY ||
etdev->wanted_flow == FLOW_BOTH)
ET1310_PhyAccessMiBit(etdev,
TRUEPHY_BIT_SET, 4, 11, NULL);
else
ET1310_PhyAccessMiBit(etdev,
TRUEPHY_BIT_CLEAR, 4, 11, NULL);
if (etdev->wanted_flow == FLOW_BOTH)
ET1310_PhyAccessMiBit(etdev,
TRUEPHY_BIT_SET, 4, 10, NULL);
else
ET1310_PhyAccessMiBit(etdev,
TRUEPHY_BIT_CLEAR, 4, 10, NULL);
ET1310_PhyAutoNeg(etdev, true);
ET1310_PhyAccessMiBit(etdev, TRUEPHY_BIT_SET, 0, 9, NULL);
return;
}
ET1310_PhyAutoNeg(etdev, false);
if (etdev->AiForceDpx != 1) {
if (etdev->wanted_flow == FLOW_TXONLY ||
etdev->wanted_flow == FLOW_BOTH)
ET1310_PhyAccessMiBit(etdev,
TRUEPHY_BIT_SET, 4, 11, NULL);
else
ET1310_PhyAccessMiBit(etdev,
TRUEPHY_BIT_CLEAR, 4, 11, NULL);
if (etdev->wanted_flow == FLOW_BOTH)
ET1310_PhyAccessMiBit(etdev,
TRUEPHY_BIT_SET, 4, 10, NULL);
else
ET1310_PhyAccessMiBit(etdev,
TRUEPHY_BIT_CLEAR, 4, 10, NULL);
} else {
ET1310_PhyAccessMiBit(etdev, TRUEPHY_BIT_CLEAR, 4, 10, NULL);
ET1310_PhyAccessMiBit(etdev, TRUEPHY_BIT_CLEAR, 4, 11, NULL);
}
ET1310_PhyPowerDown(etdev, 1);
switch (etdev->AiForceSpeed) {
case 10:
ET1310_PhyAdvertise1000BaseT(etdev, TRUEPHY_ADV_DUPLEX_NONE);
ET1310_PhyAdvertise100BaseT(etdev, TRUEPHY_ADV_DUPLEX_NONE);
if (etdev->AiForceDpx == 1) {
ET1310_PhyAdvertise10BaseT(etdev,
TRUEPHY_ADV_DUPLEX_HALF);
} else if (etdev->AiForceDpx == 2) {
ET1310_PhyAdvertise10BaseT(etdev,
TRUEPHY_ADV_DUPLEX_FULL);
} else {
ET1310_PhyAutoNeg(etdev, false);
ET1310_PhyAdvertise10BaseT(etdev,
TRUEPHY_ADV_DUPLEX_NONE);
ET1310_PhySpeedSelect(etdev, TRUEPHY_SPEED_10MBPS);
ET1310_PhyDuplexMode(etdev, TRUEPHY_DUPLEX_FULL);
}
break;
case 100:
ET1310_PhyAdvertise1000BaseT(etdev, TRUEPHY_ADV_DUPLEX_NONE);
ET1310_PhyAdvertise10BaseT(etdev, TRUEPHY_ADV_DUPLEX_NONE);
if (etdev->AiForceDpx == 1) {
ET1310_PhyAdvertise100BaseT(etdev,
TRUEPHY_ADV_DUPLEX_HALF);
ET1310_PhySpeedSelect(etdev, TRUEPHY_SPEED_100MBPS);
} else if (etdev->AiForceDpx == 2) {
ET1310_PhyAdvertise100BaseT(etdev,
TRUEPHY_ADV_DUPLEX_FULL);
} else {
ET1310_PhyAutoNeg(etdev, false);
ET1310_PhyAdvertise100BaseT(etdev,
TRUEPHY_ADV_DUPLEX_NONE);
ET1310_PhySpeedSelect(etdev, TRUEPHY_SPEED_100MBPS);
ET1310_PhyDuplexMode(etdev, TRUEPHY_DUPLEX_FULL);
}
break;
case 1000:
ET1310_PhyAdvertise100BaseT(etdev, TRUEPHY_ADV_DUPLEX_NONE);
ET1310_PhyAdvertise10BaseT(etdev, TRUEPHY_ADV_DUPLEX_NONE);
ET1310_PhyAdvertise1000BaseT(etdev, TRUEPHY_ADV_DUPLEX_FULL);
break;
}
ET1310_PhyPowerDown(etdev, 0);
}
void et131x_Mii_check(struct et131x_adapter *etdev,
MI_BMSR_t bmsr, MI_BMSR_t bmsr_ints)
{
u8 link_status;
u32 autoneg_status;
u32 speed;
u32 duplex;
u32 mdi_mdix;
u32 masterslave;
u32 polarity;
unsigned long flags;
if (bmsr_ints.bits.link_status) {
if (bmsr.bits.link_status) {
etdev->boot_coma = 20;
spin_lock_irqsave(&etdev->Lock, flags);
etdev->MediaState = NETIF_STATUS_MEDIA_CONNECT;
etdev->Flags &= ~fMP_ADAPTER_LINK_DETECTION;
spin_unlock_irqrestore(&etdev->Lock, flags);
netif_carrier_on(etdev->netdev);
} else {
dev_warn(&etdev->pdev->dev,
"Link down - cable problem ?\n");
if (etdev->linkspeed == TRUEPHY_SPEED_10MBPS) {
u16 Register18;
MiRead(etdev, 0x12, &Register18);
MiWrite(etdev, 0x12, Register18 | 0x4);
MiWrite(etdev, 0x10, Register18 | 0x8402);
MiWrite(etdev, 0x11, Register18 | 511);
MiWrite(etdev, 0x12, Register18);
}
if (!(etdev->Flags & fMP_ADAPTER_LINK_DETECTION) ||
(etdev->MediaState == NETIF_STATUS_MEDIA_DISCONNECT)) {
spin_lock_irqsave(&etdev->Lock, flags);
etdev->MediaState =
NETIF_STATUS_MEDIA_DISCONNECT;
spin_unlock_irqrestore(&etdev->Lock,
flags);
netif_carrier_off(etdev->netdev);
}
etdev->linkspeed = 0;
etdev->duplex_mode = 0;
et131x_free_busy_send_packets(etdev);
et131x_init_send(etdev);
et131x_reset_recv(etdev);
et131x_soft_reset(etdev);
et131x_adapter_setup(etdev);
if (etdev->RegistryPhyComa == 1)
EnablePhyComa(etdev);
}
}
if (bmsr_ints.bits.auto_neg_complete ||
(etdev->AiForceDpx == 3 && bmsr_ints.bits.link_status)) {
if (bmsr.bits.auto_neg_complete || etdev->AiForceDpx == 3) {
ET1310_PhyLinkStatus(etdev,
&link_status, &autoneg_status,
&speed, &duplex, &mdi_mdix,
&masterslave, &polarity);
etdev->linkspeed = speed;
etdev->duplex_mode = duplex;
etdev->boot_coma = 20;
if (etdev->linkspeed == TRUEPHY_SPEED_10MBPS) {
u16 Register18;
MiRead(etdev, 0x12, &Register18);
MiWrite(etdev, 0x12, Register18 | 0x4);
MiWrite(etdev, 0x10, Register18 | 0x8402);
MiWrite(etdev, 0x11, Register18 | 511);
MiWrite(etdev, 0x12, Register18);
}
ConfigFlowControl(etdev);
if (etdev->linkspeed == TRUEPHY_SPEED_1000MBPS &&
etdev->RegistryJumboPacket > 2048)
ET1310_PhyAndOrReg(etdev, 0x16, 0xcfff,
0x2000);
SetRxDmaTimer(etdev);
ConfigMACRegs2(etdev);
}
}
}
void ET1310_PhyInit(struct et131x_adapter *etdev)
{
u16 data, index;
if (etdev == NULL)
return;
MiRead(etdev, PHY_ID_1, &data);
MiRead(etdev, PHY_ID_2, &data);
MiRead(etdev, PHY_MPHY_CONTROL_REG, &data);
MiWrite(etdev, PHY_MPHY_CONTROL_REG, 0x0006);
MiWrite(etdev, PHY_INDEX_REG, 0x0402);
MiRead(etdev, PHY_DATA_REG, &data);
MiWrite(etdev, PHY_MPHY_CONTROL_REG, 0x0002);
MiRead(etdev, PHY_ID_1, &data);
MiRead(etdev, PHY_ID_2, &data);
MiRead(etdev, PHY_MPHY_CONTROL_REG, &data);
MiWrite(etdev, PHY_MPHY_CONTROL_REG, 0x0006);
MiWrite(etdev, PHY_INDEX_REG, 0x0402);
MiRead(etdev, PHY_DATA_REG, &data);
MiWrite(etdev, PHY_MPHY_CONTROL_REG, 0x0002);
MiRead(etdev, PHY_CONTROL, &data);
MiRead(etdev, PHY_MPHY_CONTROL_REG, &data);
MiWrite(etdev, PHY_CONTROL, 0x1840);
MiWrite(etdev, PHY_MPHY_CONTROL_REG, 0x0007);
index = 0;
while (ConfigPhy[index][0] != 0x0000) {
MiWrite(etdev, PHY_INDEX_REG, ConfigPhy[index][0]);
MiWrite(etdev, PHY_DATA_REG, ConfigPhy[index][1]);
MiWrite(etdev, PHY_INDEX_REG, ConfigPhy[index][0]);
MiRead(etdev, PHY_DATA_REG, &data);
index++;
}
MiRead(etdev, PHY_CONTROL, &data);
MiRead(etdev, PHY_MPHY_CONTROL_REG, &data);
MiWrite(etdev, PHY_CONTROL, 0x1040);
MiWrite(etdev, PHY_MPHY_CONTROL_REG, 0x0002);
}
