static int s5pv210_usb_otgphy_init(struct platform_device *pdev)
{
struct clk *xusbxti;
u32 phyclk;
writel(readl(S5PV210_USB_PHY_CON) | S5PV210_USB_PHY0_EN,
S5PV210_USB_PHY_CON);
phyclk = readl(S3C_PHYCLK) & ~S3C_PHYCLK_CLKSEL_MASK;
xusbxti = clk_get(&pdev->dev, "xusbxti");
if (xusbxti && !IS_ERR(xusbxti)) {
switch (clk_get_rate(xusbxti)) {
case 12 * MHZ:
phyclk |= S3C_PHYCLK_CLKSEL_12M;
break;
case 24 * MHZ:
phyclk |= S3C_PHYCLK_CLKSEL_24M;
break;
default:
case 48 * MHZ:
break;
}
clk_put(xusbxti);
}
writel(phyclk | S3C_PHYCLK_CLK_FORCE, S3C_PHYCLK);
writel((readl(S3C_PHYPWR) & ~S3C_PHYPWR_NORMAL_MASK), S3C_PHYPWR);
mdelay(1);
writel(S3C_RSTCON_PHY | S3C_RSTCON_HCLK | S3C_RSTCON_PHYCLK,
S3C_RSTCON);
udelay(20);
writel(0, S3C_RSTCON);
return 0;
}
static int s5pv210_usb_otgphy_exit(struct platform_device *pdev)
{
writel((readl(S3C_PHYPWR) | S3C_PHYPWR_ANALOG_POWERDOWN |
S3C_PHYPWR_OTG_DISABLE), S3C_PHYPWR);
writel(readl(S5PV210_USB_PHY_CON) & ~S5PV210_USB_PHY0_EN,
S5PV210_USB_PHY_CON);
return 0;
}
int s5p_usb_phy_init(struct platform_device *pdev, int type)
{
if (type == S5P_USB_PHY_DEVICE)
return s5pv210_usb_otgphy_init(pdev);
return -EINVAL;
}
int s5p_usb_phy_exit(struct platform_device *pdev, int type)
{
if (type == S5P_USB_PHY_DEVICE)
return s5pv210_usb_otgphy_exit(pdev);
return -EINVAL;
}
