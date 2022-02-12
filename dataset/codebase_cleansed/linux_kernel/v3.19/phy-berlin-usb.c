static int phy_berlin_usb_power_on(struct phy *phy)
{
struct phy_berlin_usb_priv *priv = dev_get_drvdata(phy->dev.parent);
reset_control_reset(priv->rst_ctrl);
writel(priv->pll_divider,
priv->base + USB_PHY_PLL);
writel(CLK_STABLE | PLL_CTRL_REG | PHASE_OFF_TOL_250 | KVC0_REG_CTRL |
CLK_BLK_EN, priv->base + USB_PHY_PLL_CONTROL);
writel(V2I_VCO_RATIO(0x5) | R_ROTATE_0 | ANA_TEST_DC_CTRL(0x5),
priv->base + USB_PHY_ANALOG);
writel(PHASE_FREEZE_DLY_4_CL | ACK_LENGTH_16_CL | SQ_LENGTH_12 |
DISCON_THRESHOLD_260 | SQ_THRESHOLD(0xa) | LPF_COEF(0x2) |
INTPL_CUR_30, priv->base + USB_PHY_RX_CTRL);
writel(TX_VDD12_13 | TX_OUT_AMP(0x3), priv->base + USB_PHY_TX_CTRL1);
writel(EXT_HS_RCAL_EN | IMPCAL_VTH_DIV(0x3) | EXT_RS_RCAL_DIV(0x4),
priv->base + USB_PHY_TX_CTRL0);
writel(EXT_HS_RCAL_EN | IMPCAL_VTH_DIV(0x3) | EXT_RS_RCAL_DIV(0x4) |
EXT_FS_RCAL_DIV(0x2), priv->base + USB_PHY_TX_CTRL0);
writel(EXT_HS_RCAL_EN | IMPCAL_VTH_DIV(0x3) | EXT_RS_RCAL_DIV(0x4),
priv->base + USB_PHY_TX_CTRL0);
writel(TX_CHAN_CTRL_REG(0xf) | DRV_SLEWRATE(0x3) | IMP_CAL_FS_HS_DLY_3 |
FS_DRV_EN_MASK(0xd), priv->base + USB_PHY_TX_CTRL2);
return 0;
}
static int phy_berlin_usb_probe(struct platform_device *pdev)
{
const struct of_device_id *match =
of_match_device(phy_berlin_sata_of_match, &pdev->dev);
struct phy_berlin_usb_priv *priv;
struct resource *res;
struct phy_provider *phy_provider;
priv = devm_kzalloc(&pdev->dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
priv->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(priv->base))
return PTR_ERR(priv->base);
priv->rst_ctrl = devm_reset_control_get(&pdev->dev, NULL);
if (IS_ERR(priv->rst_ctrl))
return PTR_ERR(priv->rst_ctrl);
priv->pll_divider = *((u32 *)match->data);
priv->phy = devm_phy_create(&pdev->dev, NULL, &phy_berlin_usb_ops);
if (IS_ERR(priv->phy)) {
dev_err(&pdev->dev, "failed to create PHY\n");
return PTR_ERR(priv->phy);
}
platform_set_drvdata(pdev, priv);
phy_provider =
devm_of_phy_provider_register(&pdev->dev, of_phy_simple_xlate);
if (IS_ERR(phy_provider))
return PTR_ERR(phy_provider);
return 0;
}
