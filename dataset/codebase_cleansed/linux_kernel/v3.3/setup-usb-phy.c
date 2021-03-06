static int exynos4_usb_host_phy_is_on(void)
{
return (readl(EXYNOS4_PHYPWR) & PHY1_STD_ANALOG_POWERDOWN) ? 0 : 1;
}
static int exynos4_usb_phy1_init(struct platform_device *pdev)
{
struct clk *otg_clk;
struct clk *xusbxti_clk;
u32 phyclk;
u32 rstcon;
int err;
atomic_inc(&host_usage);
otg_clk = clk_get(&pdev->dev, "otg");
if (IS_ERR(otg_clk)) {
dev_err(&pdev->dev, "Failed to get otg clock\n");
return PTR_ERR(otg_clk);
}
err = clk_enable(otg_clk);
if (err) {
clk_put(otg_clk);
return err;
}
if (exynos4_usb_host_phy_is_on())
return 0;
writel(readl(S5P_USBHOST_PHY_CONTROL) | S5P_USBHOST_PHY_ENABLE,
S5P_USBHOST_PHY_CONTROL);
phyclk = readl(EXYNOS4_PHYCLK) & ~CLKSEL_MASK;
xusbxti_clk = clk_get(&pdev->dev, "xusbxti");
if (xusbxti_clk && !IS_ERR(xusbxti_clk)) {
switch (clk_get_rate(xusbxti_clk)) {
case 12 * MHZ:
phyclk |= CLKSEL_12M;
break;
case 24 * MHZ:
phyclk |= CLKSEL_24M;
break;
default:
case 48 * MHZ:
break;
}
clk_put(xusbxti_clk);
}
writel(phyclk, EXYNOS4_PHYCLK);
writel((readl(EXYNOS4_PHY1CON) | FPENABLEN), EXYNOS4_PHY1CON);
writel((readl(EXYNOS4_PHYPWR) & ~PHY1_HSIC_NORMAL_MASK),
EXYNOS4_PHYPWR);
writel((readl(EXYNOS4_PHYPWR) & ~PHY1_STD_NORMAL_MASK), EXYNOS4_PHYPWR);
rstcon = readl(EXYNOS4_RSTCON) | HOST_LINK_PORT_SWRST_MASK |
PHY1_SWRST_MASK;
writel(rstcon, EXYNOS4_RSTCON);
udelay(10);
rstcon &= ~(HOST_LINK_PORT_SWRST_MASK | PHY1_SWRST_MASK);
writel(rstcon, EXYNOS4_RSTCON);
udelay(80);
clk_disable(otg_clk);
clk_put(otg_clk);
return 0;
}
static int exynos4_usb_phy1_exit(struct platform_device *pdev)
{
struct clk *otg_clk;
int err;
if (atomic_dec_return(&host_usage) > 0)
return 0;
otg_clk = clk_get(&pdev->dev, "otg");
if (IS_ERR(otg_clk)) {
dev_err(&pdev->dev, "Failed to get otg clock\n");
return PTR_ERR(otg_clk);
}
err = clk_enable(otg_clk);
if (err) {
clk_put(otg_clk);
return err;
}
writel((readl(EXYNOS4_PHYPWR) | PHY1_STD_ANALOG_POWERDOWN),
EXYNOS4_PHYPWR);
writel(readl(S5P_USBHOST_PHY_CONTROL) & ~S5P_USBHOST_PHY_ENABLE,
S5P_USBHOST_PHY_CONTROL);
clk_disable(otg_clk);
clk_put(otg_clk);
return 0;
}
int s5p_usb_phy_init(struct platform_device *pdev, int type)
{
if (type == S5P_USB_PHY_HOST)
return exynos4_usb_phy1_init(pdev);
return -EINVAL;
}
int s5p_usb_phy_exit(struct platform_device *pdev, int type)
{
if (type == S5P_USB_PHY_HOST)
return exynos4_usb_phy1_exit(pdev);
return -EINVAL;
}
