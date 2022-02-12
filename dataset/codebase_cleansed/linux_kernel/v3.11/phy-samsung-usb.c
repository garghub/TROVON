int samsung_usbphy_parse_dt(struct samsung_usbphy *sphy)
{
struct device_node *usbphy_sys;
usbphy_sys = of_get_child_by_name(sphy->dev->of_node, "usbphy-sys");
if (!usbphy_sys) {
dev_err(sphy->dev, "No sys-controller interface for usb-phy\n");
return -ENODEV;
}
sphy->pmuregs = of_iomap(usbphy_sys, 0);
if (sphy->pmuregs == NULL) {
dev_err(sphy->dev, "Can't get usb-phy pmu control register\n");
goto err0;
}
sphy->sysreg = of_iomap(usbphy_sys, 1);
if (sphy->sysreg == NULL)
dev_warn(sphy->dev, "Can't get usb-phy sysreg cfg register\n");
of_node_put(usbphy_sys);
return 0;
err0:
of_node_put(usbphy_sys);
return -ENXIO;
}
void samsung_usbphy_set_isolation_4210(struct samsung_usbphy *sphy, bool on)
{
void __iomem *reg = NULL;
u32 reg_val;
u32 en_mask = 0;
if (!sphy->pmuregs) {
dev_warn(sphy->dev, "Can't set pmu isolation\n");
return;
}
if (sphy->phy_type == USB_PHY_TYPE_DEVICE) {
reg = sphy->pmuregs + sphy->drv_data->devphy_reg_offset;
en_mask = sphy->drv_data->devphy_en_mask;
} else if (sphy->phy_type == USB_PHY_TYPE_HOST) {
reg = sphy->pmuregs + sphy->drv_data->hostphy_reg_offset;
en_mask = sphy->drv_data->hostphy_en_mask;
}
reg_val = readl(reg);
if (on)
reg_val &= ~en_mask;
else
reg_val |= en_mask;
writel(reg_val, reg);
if (sphy->drv_data->cpu_type == TYPE_EXYNOS4X12) {
writel(reg_val, sphy->pmuregs + EXYNOS4X12_PHY_HSIC_CTRL0);
writel(reg_val, sphy->pmuregs + EXYNOS4X12_PHY_HSIC_CTRL1);
}
}
void samsung_usbphy_cfg_sel(struct samsung_usbphy *sphy)
{
u32 reg;
if (!sphy->sysreg) {
dev_warn(sphy->dev, "Can't configure specified phy mode\n");
return;
}
reg = readl(sphy->sysreg);
if (sphy->phy_type == USB_PHY_TYPE_DEVICE)
reg &= ~EXYNOS_USB20PHY_CFG_HOST_LINK;
else if (sphy->phy_type == USB_PHY_TYPE_HOST)
reg |= EXYNOS_USB20PHY_CFG_HOST_LINK;
writel(reg, sphy->sysreg);
}
int samsung_usbphy_set_type(struct usb_phy *phy,
enum samsung_usb_phy_type phy_type)
{
struct samsung_usbphy *sphy = phy_to_sphy(phy);
sphy->phy_type = phy_type;
return 0;
}
int samsung_usbphy_rate_to_clksel_64xx(struct samsung_usbphy *sphy,
unsigned long rate)
{
unsigned int clksel;
switch (rate) {
case 12 * MHZ:
clksel = PHYCLK_CLKSEL_12M;
break;
case 24 * MHZ:
clksel = PHYCLK_CLKSEL_24M;
break;
case 48 * MHZ:
clksel = PHYCLK_CLKSEL_48M;
break;
default:
dev_err(sphy->dev,
"Invalid reference clock frequency: %lu\n", rate);
return -EINVAL;
}
return clksel;
}
int samsung_usbphy_rate_to_clksel_4x12(struct samsung_usbphy *sphy,
unsigned long rate)
{
unsigned int clksel;
switch (rate) {
case 9600 * KHZ:
clksel = FSEL_CLKSEL_9600K;
break;
case 10 * MHZ:
clksel = FSEL_CLKSEL_10M;
break;
case 12 * MHZ:
clksel = FSEL_CLKSEL_12M;
break;
case 19200 * KHZ:
clksel = FSEL_CLKSEL_19200K;
break;
case 20 * MHZ:
clksel = FSEL_CLKSEL_20M;
break;
case 24 * MHZ:
clksel = FSEL_CLKSEL_24M;
break;
case 50 * MHZ:
clksel = FSEL_CLKSEL_50M;
break;
default:
dev_err(sphy->dev,
"Invalid reference clock frequency: %lu\n", rate);
return -EINVAL;
}
return clksel;
}
int samsung_usbphy_get_refclk_freq(struct samsung_usbphy *sphy)
{
struct clk *ref_clk;
unsigned long rate;
int refclk_freq;
if (sphy->drv_data->cpu_type == TYPE_EXYNOS5250)
ref_clk = clk_get(sphy->dev, "ext_xtal");
else
ref_clk = clk_get(sphy->dev, "xusbxti");
if (IS_ERR(ref_clk)) {
dev_err(sphy->dev, "Failed to get reference clock\n");
return PTR_ERR(ref_clk);
}
rate = clk_get_rate(ref_clk);
refclk_freq = sphy->drv_data->rate_to_clksel(sphy, rate);
clk_put(ref_clk);
return refclk_freq;
}
