static u32 phy_meson8b_usb2_read(struct phy_meson8b_usb2_priv *phy_priv,
u32 reg)
{
return readl(phy_priv->regs + reg);
}
static void phy_meson8b_usb2_mask_bits(struct phy_meson8b_usb2_priv *phy_priv,
u32 reg, u32 mask, u32 value)
{
u32 data;
data = phy_meson8b_usb2_read(phy_priv, reg);
data &= ~mask;
data |= (value & mask);
writel(data, phy_priv->regs + reg);
}
static int phy_meson8b_usb2_power_on(struct phy *phy)
{
struct phy_meson8b_usb2_priv *priv = phy_get_drvdata(phy);
int ret;
if (!IS_ERR_OR_NULL(priv->reset)) {
ret = reset_control_reset(priv->reset);
if (ret) {
dev_err(&phy->dev, "Failed to trigger USB reset\n");
return ret;
}
}
ret = clk_prepare_enable(priv->clk_usb_general);
if (ret) {
dev_err(&phy->dev, "Failed to enable USB general clock\n");
return ret;
}
ret = clk_prepare_enable(priv->clk_usb);
if (ret) {
dev_err(&phy->dev, "Failed to enable USB DDR clock\n");
clk_disable_unprepare(priv->clk_usb_general);
return ret;
}
phy_meson8b_usb2_mask_bits(priv, REG_CONFIG, REG_CONFIG_CLK_32k_ALTSEL,
REG_CONFIG_CLK_32k_ALTSEL);
phy_meson8b_usb2_mask_bits(priv, REG_CTRL, REG_CTRL_REF_CLK_SEL_MASK,
0x2 << REG_CTRL_REF_CLK_SEL_SHIFT);
phy_meson8b_usb2_mask_bits(priv, REG_CTRL, REG_CTRL_FSEL_MASK,
0x5 << REG_CTRL_FSEL_SHIFT);
phy_meson8b_usb2_mask_bits(priv, REG_CTRL, REG_CTRL_POWER_ON_RESET,
REG_CTRL_POWER_ON_RESET);
udelay(RESET_COMPLETE_TIME);
phy_meson8b_usb2_mask_bits(priv, REG_CTRL, REG_CTRL_POWER_ON_RESET, 0);
udelay(RESET_COMPLETE_TIME);
phy_meson8b_usb2_mask_bits(priv, REG_CTRL, REG_CTRL_SOF_TOGGLE_OUT,
REG_CTRL_SOF_TOGGLE_OUT);
if (priv->dr_mode == USB_DR_MODE_HOST) {
phy_meson8b_usb2_mask_bits(priv, REG_ADP_BC,
REG_ADP_BC_ACA_ENABLE,
REG_ADP_BC_ACA_ENABLE);
udelay(ACA_ENABLE_COMPLETE_TIME);
if (phy_meson8b_usb2_read(priv, REG_ADP_BC) &
REG_ADP_BC_ACA_PIN_FLOAT) {
dev_warn(&phy->dev, "USB ID detect failed!\n");
clk_disable_unprepare(priv->clk_usb);
clk_disable_unprepare(priv->clk_usb_general);
return -EINVAL;
}
}
return 0;
}
static int phy_meson8b_usb2_power_off(struct phy *phy)
{
struct phy_meson8b_usb2_priv *priv = phy_get_drvdata(phy);
clk_disable_unprepare(priv->clk_usb);
clk_disable_unprepare(priv->clk_usb_general);
return 0;
}
static int phy_meson8b_usb2_probe(struct platform_device *pdev)
{
struct phy_meson8b_usb2_priv *priv;
struct resource *res;
struct phy *phy;
struct phy_provider *phy_provider;
priv = devm_kzalloc(&pdev->dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
priv->regs = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(priv->regs))
return PTR_ERR(priv->regs);
priv->clk_usb_general = devm_clk_get(&pdev->dev, "usb_general");
if (IS_ERR(priv->clk_usb_general))
return PTR_ERR(priv->clk_usb_general);
priv->clk_usb = devm_clk_get(&pdev->dev, "usb");
if (IS_ERR(priv->clk_usb))
return PTR_ERR(priv->clk_usb);
priv->reset = devm_reset_control_get_optional_shared(&pdev->dev, NULL);
if (PTR_ERR(priv->reset) == -EPROBE_DEFER)
return PTR_ERR(priv->reset);
priv->dr_mode = of_usb_get_dr_mode_by_phy(pdev->dev.of_node, -1);
if (priv->dr_mode == USB_DR_MODE_UNKNOWN) {
dev_err(&pdev->dev,
"missing dual role configuration of the controller\n");
return -EINVAL;
}
phy = devm_phy_create(&pdev->dev, NULL, &phy_meson8b_usb2_ops);
if (IS_ERR(phy)) {
dev_err(&pdev->dev, "failed to create PHY\n");
return PTR_ERR(phy);
}
phy_set_drvdata(phy, priv);
phy_provider =
devm_of_phy_provider_register(&pdev->dev, of_phy_simple_xlate);
return PTR_ERR_OR_ZERO(phy_provider);
}
