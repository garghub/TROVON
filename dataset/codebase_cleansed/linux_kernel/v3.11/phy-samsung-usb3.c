static u32 samsung_usb3phy_set_refclk(struct samsung_usbphy *sphy)
{
u32 reg;
u32 refclk;
refclk = sphy->ref_clk_freq;
reg = PHYCLKRST_REFCLKSEL_EXT_REFCLK |
PHYCLKRST_FSEL(refclk);
switch (refclk) {
case FSEL_CLKSEL_50M:
reg |= (PHYCLKRST_MPLL_MULTIPLIER_50M_REF |
PHYCLKRST_SSC_REFCLKSEL(0x00));
break;
case FSEL_CLKSEL_20M:
reg |= (PHYCLKRST_MPLL_MULTIPLIER_20MHZ_REF |
PHYCLKRST_SSC_REFCLKSEL(0x00));
break;
case FSEL_CLKSEL_19200K:
reg |= (PHYCLKRST_MPLL_MULTIPLIER_19200KHZ_REF |
PHYCLKRST_SSC_REFCLKSEL(0x88));
break;
case FSEL_CLKSEL_24M:
default:
reg |= (PHYCLKRST_MPLL_MULTIPLIER_24MHZ_REF |
PHYCLKRST_SSC_REFCLKSEL(0x88));
break;
}
return reg;
}
static void samsung_exynos5_usb3phy_enable(struct samsung_usbphy *sphy)
{
void __iomem *regs = sphy->regs;
u32 phyparam0;
u32 phyparam1;
u32 linksystem;
u32 phybatchg;
u32 phytest;
u32 phyclkrst;
writel(0x0, regs + EXYNOS5_DRD_PHYREG0);
phyparam0 = readl(regs + EXYNOS5_DRD_PHYPARAM0);
phyparam0 &= ~PHYPARAM0_REF_USE_PAD;
phyparam0 &= ~PHYPARAM0_REF_LOSLEVEL_MASK;
phyparam0 |= PHYPARAM0_REF_LOSLEVEL;
writel(phyparam0, regs + EXYNOS5_DRD_PHYPARAM0);
writel(0x0, regs + EXYNOS5_DRD_PHYRESUME);
linksystem = LINKSYSTEM_XHCI_VERSION_CONTROL |
LINKSYSTEM_FLADJ(0x20);
writel(linksystem, regs + EXYNOS5_DRD_LINKSYSTEM);
phyparam1 = readl(regs + EXYNOS5_DRD_PHYPARAM1);
phyparam1 &= ~PHYPARAM1_PCS_TXDEEMPH_MASK;
phyparam1 |= PHYPARAM1_PCS_TXDEEMPH;
writel(phyparam1, regs + EXYNOS5_DRD_PHYPARAM1);
phybatchg = readl(regs + EXYNOS5_DRD_PHYBATCHG);
phybatchg |= PHYBATCHG_UTMI_CLKSEL;
writel(phybatchg, regs + EXYNOS5_DRD_PHYBATCHG);
phytest = readl(regs + EXYNOS5_DRD_PHYTEST);
phytest &= ~(PHYTEST_POWERDOWN_SSP |
PHYTEST_POWERDOWN_HSP);
writel(phytest, regs + EXYNOS5_DRD_PHYTEST);
writel(PHYUTMI_OTGDISABLE, regs + EXYNOS5_DRD_PHYUTMI);
phyclkrst = samsung_usb3phy_set_refclk(sphy);
phyclkrst |= PHYCLKRST_PORTRESET |
PHYCLKRST_RETENABLEN |
PHYCLKRST_REF_SSP_EN |
PHYCLKRST_SSC_EN |
PHYCLKRST_COMMONONN;
writel(phyclkrst, regs + EXYNOS5_DRD_PHYCLKRST);
udelay(10);
phyclkrst &= ~(PHYCLKRST_PORTRESET);
writel(phyclkrst, regs + EXYNOS5_DRD_PHYCLKRST);
}
static void samsung_exynos5_usb3phy_disable(struct samsung_usbphy *sphy)
{
u32 phyutmi;
u32 phyclkrst;
u32 phytest;
void __iomem *regs = sphy->regs;
phyutmi = PHYUTMI_OTGDISABLE |
PHYUTMI_FORCESUSPEND |
PHYUTMI_FORCESLEEP;
writel(phyutmi, regs + EXYNOS5_DRD_PHYUTMI);
phyclkrst = readl(regs + EXYNOS5_DRD_PHYCLKRST);
phyclkrst &= ~(PHYCLKRST_REF_SSP_EN |
PHYCLKRST_SSC_EN |
PHYCLKRST_COMMONONN);
writel(phyclkrst, regs + EXYNOS5_DRD_PHYCLKRST);
phytest = readl(regs + EXYNOS5_DRD_PHYTEST);
phytest |= (PHYTEST_POWERDOWN_SSP |
PHYTEST_POWERDOWN_HSP);
writel(phytest, regs + EXYNOS5_DRD_PHYTEST);
}
static int samsung_usb3phy_init(struct usb_phy *phy)
{
struct samsung_usbphy *sphy;
unsigned long flags;
int ret = 0;
sphy = phy_to_sphy(phy);
ret = clk_prepare_enable(sphy->clk);
if (ret) {
dev_err(sphy->dev, "%s: clk_prepare_enable failed\n", __func__);
return ret;
}
spin_lock_irqsave(&sphy->lock, flags);
samsung_usbphy_set_type(&sphy->phy, USB_PHY_TYPE_DEVICE);
if (sphy->drv_data->set_isolation)
sphy->drv_data->set_isolation(sphy, false);
sphy->drv_data->phy_enable(sphy);
spin_unlock_irqrestore(&sphy->lock, flags);
clk_disable_unprepare(sphy->clk);
return ret;
}
static void samsung_usb3phy_shutdown(struct usb_phy *phy)
{
struct samsung_usbphy *sphy;
unsigned long flags;
sphy = phy_to_sphy(phy);
if (clk_prepare_enable(sphy->clk)) {
dev_err(sphy->dev, "%s: clk_prepare_enable failed\n", __func__);
return;
}
spin_lock_irqsave(&sphy->lock, flags);
samsung_usbphy_set_type(&sphy->phy, USB_PHY_TYPE_DEVICE);
sphy->drv_data->phy_disable(sphy);
if (sphy->drv_data->set_isolation)
sphy->drv_data->set_isolation(sphy, true);
spin_unlock_irqrestore(&sphy->lock, flags);
clk_disable_unprepare(sphy->clk);
}
static int samsung_usb3phy_probe(struct platform_device *pdev)
{
struct samsung_usbphy *sphy;
struct samsung_usbphy_data *pdata = pdev->dev.platform_data;
struct device *dev = &pdev->dev;
struct resource *phy_mem;
void __iomem *phy_base;
struct clk *clk;
int ret;
phy_mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
phy_base = devm_ioremap_resource(dev, phy_mem);
if (IS_ERR(phy_base))
return PTR_ERR(phy_base);
sphy = devm_kzalloc(dev, sizeof(*sphy), GFP_KERNEL);
if (!sphy)
return -ENOMEM;
clk = devm_clk_get(dev, "usbdrd30");
if (IS_ERR(clk)) {
dev_err(dev, "Failed to get device clock\n");
return PTR_ERR(clk);
}
sphy->dev = dev;
if (dev->of_node) {
ret = samsung_usbphy_parse_dt(sphy);
if (ret < 0)
return ret;
} else {
if (!pdata) {
dev_err(dev, "no platform data specified\n");
return -EINVAL;
}
}
sphy->plat = pdata;
sphy->regs = phy_base;
sphy->clk = clk;
sphy->phy.dev = sphy->dev;
sphy->phy.label = "samsung-usb3phy";
sphy->phy.init = samsung_usb3phy_init;
sphy->phy.shutdown = samsung_usb3phy_shutdown;
sphy->drv_data = samsung_usbphy_get_driver_data(pdev);
sphy->ref_clk_freq = samsung_usbphy_get_refclk_freq(sphy);
if (sphy->ref_clk_freq < 0)
return -EINVAL;
spin_lock_init(&sphy->lock);
platform_set_drvdata(pdev, sphy);
return usb_add_phy(&sphy->phy, USB_PHY_TYPE_USB3);
}
static int samsung_usb3phy_remove(struct platform_device *pdev)
{
struct samsung_usbphy *sphy = platform_get_drvdata(pdev);
usb_remove_phy(&sphy->phy);
if (sphy->pmuregs)
iounmap(sphy->pmuregs);
if (sphy->sysreg)
iounmap(sphy->sysreg);
return 0;
}
