static void csiphy_lanes_config(struct isp_csiphy *phy)
{
unsigned int i;
u32 reg;
reg = isp_reg_readl(phy->isp, phy->cfg_regs, ISPCSI2_PHY_CFG);
for (i = 0; i < phy->num_data_lanes; i++) {
reg &= ~(ISPCSI2_PHY_CFG_DATA_POL_MASK(i + 1) |
ISPCSI2_PHY_CFG_DATA_POSITION_MASK(i + 1));
reg |= (phy->lanes.data[i].pol <<
ISPCSI2_PHY_CFG_DATA_POL_SHIFT(i + 1));
reg |= (phy->lanes.data[i].pos <<
ISPCSI2_PHY_CFG_DATA_POSITION_SHIFT(i + 1));
}
reg &= ~(ISPCSI2_PHY_CFG_CLOCK_POL_MASK |
ISPCSI2_PHY_CFG_CLOCK_POSITION_MASK);
reg |= phy->lanes.clk.pol << ISPCSI2_PHY_CFG_CLOCK_POL_SHIFT;
reg |= phy->lanes.clk.pos << ISPCSI2_PHY_CFG_CLOCK_POSITION_SHIFT;
isp_reg_writel(phy->isp, reg, phy->cfg_regs, ISPCSI2_PHY_CFG);
}
static void csiphy_power_autoswitch_enable(struct isp_csiphy *phy, bool enable)
{
isp_reg_clr_set(phy->isp, phy->cfg_regs, ISPCSI2_PHY_CFG,
ISPCSI2_PHY_CFG_PWR_AUTO,
enable ? ISPCSI2_PHY_CFG_PWR_AUTO : 0);
}
static int csiphy_set_power(struct isp_csiphy *phy, u32 power)
{
u32 reg;
u8 retry_count;
isp_reg_clr_set(phy->isp, phy->cfg_regs, ISPCSI2_PHY_CFG,
ISPCSI2_PHY_CFG_PWR_CMD_MASK, power);
retry_count = 0;
do {
udelay(50);
reg = isp_reg_readl(phy->isp, phy->cfg_regs, ISPCSI2_PHY_CFG) &
ISPCSI2_PHY_CFG_PWR_STATUS_MASK;
if (reg != power >> 2)
retry_count++;
} while ((reg != power >> 2) && (retry_count < 100));
if (retry_count == 100) {
printk(KERN_ERR "CSI2 CIO set power failed!\n");
return -EBUSY;
}
return 0;
}
static void csiphy_dphy_config(struct isp_csiphy *phy)
{
u32 reg;
reg = isp_reg_readl(phy->isp, phy->phy_regs, ISPCSIPHY_REG0);
reg &= ~(ISPCSIPHY_REG0_THS_TERM_MASK |
ISPCSIPHY_REG0_THS_SETTLE_MASK);
reg |= phy->dphy.ths_term << ISPCSIPHY_REG0_THS_TERM_SHIFT;
reg |= phy->dphy.ths_settle << ISPCSIPHY_REG0_THS_SETTLE_SHIFT;
isp_reg_writel(phy->isp, reg, phy->phy_regs, ISPCSIPHY_REG0);
reg = isp_reg_readl(phy->isp, phy->phy_regs, ISPCSIPHY_REG1);
reg &= ~(ISPCSIPHY_REG1_TCLK_TERM_MASK |
ISPCSIPHY_REG1_TCLK_MISS_MASK |
ISPCSIPHY_REG1_TCLK_SETTLE_MASK);
reg |= phy->dphy.tclk_term << ISPCSIPHY_REG1_TCLK_TERM_SHIFT;
reg |= phy->dphy.tclk_miss << ISPCSIPHY_REG1_TCLK_MISS_SHIFT;
reg |= phy->dphy.tclk_settle << ISPCSIPHY_REG1_TCLK_SETTLE_SHIFT;
isp_reg_writel(phy->isp, reg, phy->phy_regs, ISPCSIPHY_REG1);
}
static int csiphy_config(struct isp_csiphy *phy,
struct isp_csiphy_dphy_cfg *dphy,
struct isp_csiphy_lanes_cfg *lanes)
{
unsigned int used_lanes = 0;
unsigned int i;
for (i = 0; i < phy->num_data_lanes; i++) {
if (lanes->data[i].pol > 1 || lanes->data[i].pos > 3)
return -EINVAL;
if (used_lanes & (1 << lanes->data[i].pos))
return -EINVAL;
used_lanes |= 1 << lanes->data[i].pos;
}
if (lanes->clk.pol > 1 || lanes->clk.pos > 3)
return -EINVAL;
if (lanes->clk.pos == 0 || used_lanes & (1 << lanes->clk.pos))
return -EINVAL;
mutex_lock(&phy->mutex);
phy->dphy = *dphy;
phy->lanes = *lanes;
mutex_unlock(&phy->mutex);
return 0;
}
int omap3isp_csiphy_acquire(struct isp_csiphy *phy)
{
int rval;
if (phy->vdd == NULL) {
dev_err(phy->isp->dev, "Power regulator for CSI PHY not "
"available\n");
return -ENODEV;
}
mutex_lock(&phy->mutex);
rval = regulator_enable(phy->vdd);
if (rval < 0)
goto done;
omap3isp_csi2_reset(phy->csi2);
csiphy_dphy_config(phy);
csiphy_lanes_config(phy);
rval = csiphy_set_power(phy, ISPCSI2_PHY_CFG_PWR_CMD_ON);
if (rval) {
regulator_disable(phy->vdd);
goto done;
}
csiphy_power_autoswitch_enable(phy, true);
phy->phy_in_use = 1;
done:
mutex_unlock(&phy->mutex);
return rval;
}
void omap3isp_csiphy_release(struct isp_csiphy *phy)
{
mutex_lock(&phy->mutex);
if (phy->phy_in_use) {
csiphy_power_autoswitch_enable(phy, false);
csiphy_set_power(phy, ISPCSI2_PHY_CFG_PWR_CMD_OFF);
regulator_disable(phy->vdd);
phy->phy_in_use = 0;
}
mutex_unlock(&phy->mutex);
}
int omap3isp_csiphy_init(struct isp_device *isp)
{
struct isp_csiphy *phy1 = &isp->isp_csiphy1;
struct isp_csiphy *phy2 = &isp->isp_csiphy2;
isp->platform_cb.csiphy_config = csiphy_config;
phy2->isp = isp;
phy2->csi2 = &isp->isp_csi2a;
phy2->num_data_lanes = ISP_CSIPHY2_NUM_DATA_LANES;
phy2->cfg_regs = OMAP3_ISP_IOMEM_CSI2A_REGS1;
phy2->phy_regs = OMAP3_ISP_IOMEM_CSIPHY2;
mutex_init(&phy2->mutex);
if (isp->revision == ISP_REVISION_15_0) {
phy1->isp = isp;
phy1->csi2 = &isp->isp_csi2c;
phy1->num_data_lanes = ISP_CSIPHY1_NUM_DATA_LANES;
phy1->cfg_regs = OMAP3_ISP_IOMEM_CSI2C_REGS1;
phy1->phy_regs = OMAP3_ISP_IOMEM_CSIPHY1;
mutex_init(&phy1->mutex);
}
return 0;
}
