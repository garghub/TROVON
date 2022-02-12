static void write_clkset1_for_usb_extal(struct rcar_gen3_usb3 *r, bool reset)
{
u16 val = CLKSET1_USB30_PLL_MULTI_USB_EXTAL |
CLKSET1_REF_CLKDIV | CLKSET1_PRIVATE_2_1;
if (reset)
val |= CLKSET1_PHYRESET;
writew(val, r->base + USB30_CLKSET1);
}
static void rcar_gen3_phy_usb3_enable_ssc(struct rcar_gen3_usb3 *r)
{
u16 val = SSC_SET_SSC_EN;
switch (r->ssc_range) {
case 4980:
val |= SSC_SET_RANGE_4980;
break;
case 4492:
val |= SSC_SET_RANGE_4492;
break;
case 4003:
val |= SSC_SET_RANGE_4003;
break;
default:
dev_err(&r->phy->dev, "%s: unsupported range (%x)\n", __func__,
r->ssc_range);
return;
}
writew(val, r->base + USB30_SSC_SET);
}
static void rcar_gen3_phy_usb3_select_usb_extal(struct rcar_gen3_usb3 *r)
{
write_clkset1_for_usb_extal(r, false);
if (r->ssc_range)
rcar_gen3_phy_usb3_enable_ssc(r);
writew(CLKSET0_PRIVATE | CLKSET0_USB30_FSEL_USB_EXTAL,
r->base + USB30_CLKSET0);
writew(PHY_ENABLE_RESET_EN, r->base + USB30_PHY_ENABLE);
write_clkset1_for_usb_extal(r, true);
usleep_range(10, 20);
write_clkset1_for_usb_extal(r, false);
}
static int rcar_gen3_phy_usb3_init(struct phy *p)
{
struct rcar_gen3_usb3 *r = phy_get_drvdata(p);
dev_vdbg(&r->phy->dev, "%s: enter (%d, %d, %d)\n", __func__,
r->usb3s_clk, r->usb_extal, r->ssc_range);
if (!r->usb3s_clk && r->usb_extal)
rcar_gen3_phy_usb3_select_usb_extal(r);
writew(VBUS_EN_VBUS_EN, r->base + USB30_VBUS_EN);
return 0;
}
static int rcar_gen3_phy_usb3_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct rcar_gen3_usb3 *r;
struct phy_provider *provider;
struct resource *res;
int ret = 0;
struct clk *clk;
if (!dev->of_node) {
dev_err(dev, "This driver needs device tree\n");
return -EINVAL;
}
r = devm_kzalloc(dev, sizeof(*r), GFP_KERNEL);
if (!r)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
r->base = devm_ioremap_resource(dev, res);
if (IS_ERR(r->base))
return PTR_ERR(r->base);
clk = devm_clk_get(dev, "usb3s_clk");
if (!IS_ERR(clk) && !clk_prepare_enable(clk)) {
r->usb3s_clk = !!clk_get_rate(clk);
clk_disable_unprepare(clk);
}
clk = devm_clk_get(dev, "usb_extal");
if (!IS_ERR(clk) && !clk_prepare_enable(clk)) {
r->usb_extal = !!clk_get_rate(clk);
clk_disable_unprepare(clk);
}
if (!r->usb3s_clk && !r->usb_extal) {
dev_err(dev, "This driver needs usb3s_clk and/or usb_extal\n");
ret = -EINVAL;
goto error;
}
pm_runtime_enable(dev);
r->phy = devm_phy_create(dev, NULL, &rcar_gen3_phy_usb3_ops);
if (IS_ERR(r->phy)) {
dev_err(dev, "Failed to create USB3 PHY\n");
ret = PTR_ERR(r->phy);
goto error;
}
of_property_read_u32(dev->of_node, "renesas,ssc-range", &r->ssc_range);
platform_set_drvdata(pdev, r);
phy_set_drvdata(r->phy, r);
provider = devm_of_phy_provider_register(dev, of_phy_simple_xlate);
if (IS_ERR(provider)) {
dev_err(dev, "Failed to register PHY provider\n");
ret = PTR_ERR(provider);
goto error;
}
return 0;
error:
pm_runtime_disable(dev);
return ret;
}
static int rcar_gen3_phy_usb3_remove(struct platform_device *pdev)
{
pm_runtime_disable(&pdev->dev);
return 0;
}
