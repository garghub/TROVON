static void emac_reg_write_all(void __iomem *base,
const struct emac_reg_write *itr, size_t size)
{
size_t i;
for (i = 0; i < size; ++itr, ++i)
writel(itr->val, base + itr->offset);
}
static int emac_sgmii_link_init(struct emac_adapter *adpt)
{
struct phy_device *phydev = adpt->phydev;
struct emac_phy *phy = &adpt->phy;
u32 val;
val = readl(phy->base + EMAC_SGMII_PHY_AUTONEG_CFG2);
if (phydev->autoneg == AUTONEG_ENABLE) {
val &= ~(FORCE_AN_RX_CFG | FORCE_AN_TX_CFG);
val |= AN_ENABLE;
writel(val, phy->base + EMAC_SGMII_PHY_AUTONEG_CFG2);
} else {
u32 speed_cfg;
switch (phydev->speed) {
case SPEED_10:
speed_cfg = SPDMODE_10;
break;
case SPEED_100:
speed_cfg = SPDMODE_100;
break;
case SPEED_1000:
speed_cfg = SPDMODE_1000;
break;
default:
return -EINVAL;
}
if (phydev->duplex == DUPLEX_FULL)
speed_cfg |= DUPLEX_MODE;
val &= ~AN_ENABLE;
writel(speed_cfg, phy->base + EMAC_SGMII_PHY_SPEED_CFG1);
writel(val, phy->base + EMAC_SGMII_PHY_AUTONEG_CFG2);
}
return 0;
}
static int emac_sgmii_irq_clear(struct emac_adapter *adpt, u32 irq_bits)
{
struct emac_phy *phy = &adpt->phy;
u32 status;
writel_relaxed(irq_bits, phy->base + EMAC_SGMII_PHY_INTERRUPT_CLEAR);
writel_relaxed(IRQ_GLOBAL_CLEAR, phy->base + EMAC_SGMII_PHY_IRQ_CMD);
wmb();
if (readl_poll_timeout_atomic(phy->base +
EMAC_SGMII_PHY_INTERRUPT_STATUS,
status, !(status & irq_bits), 1,
SGMII_PHY_IRQ_CLR_WAIT_TIME)) {
netdev_err(adpt->netdev,
"error: failed clear SGMII irq: status:0x%x bits:0x%x\n",
status, irq_bits);
return -EIO;
}
writel_relaxed(0, phy->base + EMAC_SGMII_PHY_IRQ_CMD);
writel_relaxed(0, phy->base + EMAC_SGMII_PHY_INTERRUPT_CLEAR);
wmb();
return 0;
}
int emac_sgmii_init_v1(struct emac_adapter *adpt)
{
struct emac_phy *phy = &adpt->phy;
unsigned int i;
int ret;
ret = emac_sgmii_link_init(adpt);
if (ret)
return ret;
emac_reg_write_all(phy->base, physical_coding_sublayer_programming_v1,
ARRAY_SIZE(physical_coding_sublayer_programming_v1));
emac_reg_write_all(phy->base, sysclk_refclk_setting,
ARRAY_SIZE(sysclk_refclk_setting));
emac_reg_write_all(phy->base, pll_setting, ARRAY_SIZE(pll_setting));
emac_reg_write_all(phy->base, cdr_setting, ARRAY_SIZE(cdr_setting));
emac_reg_write_all(phy->base, tx_rx_setting,
ARRAY_SIZE(tx_rx_setting));
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
emac_sgmii_irq_clear(adpt, SGMII_PHY_INTERRUPT_ERR);
return 0;
}
int emac_sgmii_init_v2(struct emac_adapter *adpt)
{
struct emac_phy *phy = &adpt->phy;
void __iomem *phy_regs = phy->base;
void __iomem *laned = phy->digital;
unsigned int i;
u32 lnstatus;
int ret;
ret = emac_sgmii_link_init(adpt);
if (ret)
return ret;
emac_reg_write_all(phy->base, physical_coding_sublayer_programming_v2,
ARRAY_SIZE(physical_coding_sublayer_programming_v2));
emac_reg_write_all(phy->digital,
sgmii_v2_laned, ARRAY_SIZE(sgmii_v2_laned));
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
emac_sgmii_irq_clear(adpt, SGMII_PHY_INTERRUPT_ERR);
return 0;
}
static void emac_sgmii_reset_prepare(struct emac_adapter *adpt)
{
struct emac_phy *phy = &adpt->phy;
u32 val;
val = readl(phy->base + EMAC_EMAC_WRAPPER_CSR2);
writel(((val & ~PHY_RESET) | PHY_RESET), phy->base +
EMAC_EMAC_WRAPPER_CSR2);
msleep(50);
val = readl(phy->base + EMAC_EMAC_WRAPPER_CSR2);
writel((val & ~PHY_RESET), phy->base + EMAC_EMAC_WRAPPER_CSR2);
msleep(50);
}
void emac_sgmii_reset(struct emac_adapter *adpt)
{
int ret;
clk_set_rate(adpt->clk[EMAC_CLK_HIGH_SPEED], 19200000);
emac_sgmii_reset_prepare(adpt);
ret = adpt->phy.initialize(adpt);
if (ret)
netdev_err(adpt->netdev,
"could not reinitialize internal PHY (error=%i)\n",
ret);
clk_set_rate(adpt->clk[EMAC_CLK_HIGH_SPEED], 125000000);
}
static int emac_sgmii_acpi_match(struct device *dev, void *data)
{
static const struct acpi_device_id match_table[] = {
{
.id = "QCOM8071",
.driver_data = (kernel_ulong_t)emac_sgmii_init_v2,
},
{}
};
const struct acpi_device_id *id = acpi_match_device(match_table, dev);
emac_sgmii_initialize *initialize = data;
if (id)
*initialize = (emac_sgmii_initialize)id->driver_data;
return !!id;
}
int emac_sgmii_config(struct platform_device *pdev, struct emac_adapter *adpt)
{
struct platform_device *sgmii_pdev = NULL;
struct emac_phy *phy = &adpt->phy;
struct resource *res;
int ret;
if (has_acpi_companion(&pdev->dev)) {
struct device *dev;
dev = device_find_child(&pdev->dev, &phy->initialize,
emac_sgmii_acpi_match);
if (!dev) {
dev_err(&pdev->dev, "cannot find internal phy node\n");
return -ENODEV;
}
sgmii_pdev = to_platform_device(dev);
} else {
const struct of_device_id *match;
struct device_node *np;
np = of_parse_phandle(pdev->dev.of_node, "internal-phy", 0);
if (!np) {
dev_err(&pdev->dev, "missing internal-phy property\n");
return -ENODEV;
}
sgmii_pdev = of_find_device_by_node(np);
if (!sgmii_pdev) {
dev_err(&pdev->dev, "invalid internal-phy property\n");
return -ENODEV;
}
match = of_match_device(emac_sgmii_dt_match, &sgmii_pdev->dev);
if (!match) {
dev_err(&pdev->dev, "unrecognized internal phy node\n");
ret = -ENODEV;
goto error_put_device;
}
phy->initialize = (emac_sgmii_initialize)match->data;
}
res = platform_get_resource(sgmii_pdev, IORESOURCE_MEM, 0);
if (!res) {
ret = -EINVAL;
goto error_put_device;
}
phy->base = ioremap(res->start, resource_size(res));
if (!phy->base) {
ret = -ENOMEM;
goto error_put_device;
}
res = platform_get_resource(sgmii_pdev, IORESOURCE_MEM, 1);
if (res) {
phy->digital = ioremap(res->start, resource_size(res));
if (!phy->digital) {
ret = -ENOMEM;
goto error_unmap_base;
}
}
ret = phy->initialize(adpt);
if (ret)
goto error;
put_device(&sgmii_pdev->dev);
return 0;
error:
if (phy->digital)
iounmap(phy->digital);
error_unmap_base:
iounmap(phy->base);
error_put_device:
put_device(&sgmii_pdev->dev);
return ret;
}
