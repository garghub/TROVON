static void sti_vtac_rx_set_config(struct sti_vtac *vtac)
{
u32 config;
if (clk_prepare_enable(vtac->clk))
DRM_ERROR("Failed to prepare/enable vtac_rx clock.\n");
writel(VTAC_FIFO_CONFIG_VAL, vtac->regs + VTAC_RX_FIFO_CONFIG);
config = VTAC_ENABLE;
config |= vtac->mode->vid_in_width << 4;
config |= vtac->mode->phyts_width << 16;
config |= vtac->mode->phyts_per_pixel << 23;
writel(config, vtac->regs + VTAC_CONFIG);
}
static void sti_vtac_tx_set_config(struct sti_vtac *vtac)
{
u32 phy_config;
u32 config;
if (clk_prepare_enable(vtac->clk))
DRM_ERROR("Failed to prepare/enable vtac_tx clock.\n");
phy_config = 0x00000000;
writel(phy_config, vtac->phy_regs + VTAC_SYS_CFG8522);
phy_config = VTAC_TX_PHY_ENABLE_CLK_PHY;
writel(phy_config, vtac->phy_regs + VTAC_SYS_CFG8521);
phy_config = readl(vtac->phy_regs + VTAC_SYS_CFG8521);
phy_config |= VTAC_TX_PHY_PROG_N3;
writel(phy_config, vtac->phy_regs + VTAC_SYS_CFG8521);
phy_config = readl(vtac->phy_regs + VTAC_SYS_CFG8521);
phy_config |= VTAC_TX_PHY_ENABLE_CLK_DLL;
writel(phy_config, vtac->phy_regs + VTAC_SYS_CFG8521);
phy_config = readl(vtac->phy_regs + VTAC_SYS_CFG8521);
phy_config |= VTAC_TX_PHY_RST_N_DLL_SWITCH;
writel(phy_config, vtac->phy_regs + VTAC_SYS_CFG8521);
phy_config = readl(vtac->phy_regs + VTAC_SYS_CFG8521);
phy_config |= VTAC_TX_PHY_PLL_NOT_OSC_MODE;
writel(phy_config, vtac->phy_regs + VTAC_SYS_CFG8521);
config = VTAC_ENABLE;
config |= vtac->mode->vid_in_width << 4;
config |= vtac->mode->phyts_width << 16;
config |= vtac->mode->phyts_per_pixel << 23;
writel(config, vtac->regs + VTAC_CONFIG);
}
static int sti_vtac_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct device_node *np = dev->of_node;
const struct of_device_id *id;
struct sti_vtac *vtac;
struct resource *res;
vtac = devm_kzalloc(dev, sizeof(*vtac), GFP_KERNEL);
if (!vtac)
return -ENOMEM;
vtac->dev = dev;
id = of_match_node(vtac_of_match, np);
if (!id)
return -ENOMEM;
vtac->mode = id->data;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
DRM_ERROR("Invalid resource\n");
return -ENOMEM;
}
vtac->regs = devm_ioremap_resource(dev, res);
if (IS_ERR(vtac->regs))
return PTR_ERR(vtac->regs);
vtac->clk = devm_clk_get(dev, "vtac");
if (IS_ERR(vtac->clk)) {
DRM_ERROR("Cannot get vtac clock\n");
return PTR_ERR(vtac->clk);
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 1);
if (res) {
vtac->phy_regs = devm_ioremap_nocache(dev, res->start,
resource_size(res));
sti_vtac_tx_set_config(vtac);
} else {
sti_vtac_rx_set_config(vtac);
}
platform_set_drvdata(pdev, vtac);
DRM_INFO("%s %s\n", __func__, dev_name(vtac->dev));
return 0;
}
static int sti_vtac_remove(struct platform_device *pdev)
{
return 0;
}
