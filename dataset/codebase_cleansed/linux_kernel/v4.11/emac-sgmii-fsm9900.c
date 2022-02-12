static void emac_reg_write_all(void __iomem *base,
const struct emac_reg_write *itr, size_t size)
{
size_t i;
for (i = 0; i < size; ++itr, ++i)
writel(itr->val, base + itr->offset);
}
int emac_sgmii_init_fsm9900(struct emac_adapter *adpt)
{
struct emac_sgmii *phy = &adpt->phy;
unsigned int i;
emac_reg_write_all(phy->base, physical_coding_sublayer_programming,
ARRAY_SIZE(physical_coding_sublayer_programming));
emac_reg_write_all(phy->base, sysclk_refclk_setting,
ARRAY_SIZE(sysclk_refclk_setting));
emac_reg_write_all(phy->base, pll_setting, ARRAY_SIZE(pll_setting));
emac_reg_write_all(phy->base, cdr_setting, ARRAY_SIZE(cdr_setting));
emac_reg_write_all(phy->base, tx_rx_setting, ARRAY_SIZE(tx_rx_setting));
writel(SERDES_START, phy->base + EMAC_SGMII_PHY_SERDES_START);
for (i = 0; i < SERDES_START_WAIT_TIMES; i++) {
if (readl(phy->base + EMAC_QSERDES_COM_RESET_SM) & READY)
break;
usleep_range(100, 200);
}
if (i == SERDES_START_WAIT_TIMES) {
netdev_err(adpt->netdev, "error: ser/des failed to start\n");
return -EIO;
}
writel(0, phy->base + EMAC_SGMII_PHY_INTERRUPT_MASK);
return 0;
}
