static void emac_reg_write_all(void __iomem *base,
const struct emac_reg_write *itr, size_t size)
{
size_t i;
for (i = 0; i < size; ++itr, ++i)
writel(itr->val, base + itr->offset);
}
int emac_sgmii_init_qdf2400(struct emac_adapter *adpt)
{
struct emac_phy *phy = &adpt->phy;
void __iomem *phy_regs = phy->base;
void __iomem *laned = phy->digital;
unsigned int i;
u32 lnstatus;
emac_reg_write_all(phy->base, physical_coding_sublayer_programming,
ARRAY_SIZE(physical_coding_sublayer_programming));
emac_reg_write_all(phy->digital, sgmii_laned, ARRAY_SIZE(sgmii_laned));
writel(0, phy_regs + EMAC_SGMII_PHY_RESET_CTRL);
writel(1, laned + SGMII_LN_RSM_START);
for (i = 0; i < SERDES_START_WAIT_TIMES; i++) {
lnstatus = readl(phy_regs + SGMII_PHY_LN_LANE_STATUS);
if (lnstatus & BIT(1))
break;
usleep_range(100, 200);
}
if (i == SERDES_START_WAIT_TIMES) {
netdev_err(adpt->netdev, "SGMII failed to start\n");
return -EIO;
}
writel(0, phy_regs + SGMII_PHY_LN_BIST_GEN0);
writel(0, phy_regs + SGMII_PHY_LN_BIST_GEN2);
writel(0, phy_regs + SGMII_PHY_LN_CDR_CTRL1);
writel(0, phy_regs + EMAC_SGMII_PHY_INTERRUPT_MASK);
return 0;
}
