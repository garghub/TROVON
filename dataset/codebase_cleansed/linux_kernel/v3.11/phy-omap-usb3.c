static int omap_usb3_suspend(struct usb_phy *x, int suspend)
{
struct omap_usb *phy = phy_to_omapusb(x);
int val;
int timeout = PLL_IDLE_TIME;
if (suspend && !phy->is_suspended) {
val = omap_usb_readl(phy->pll_ctrl_base, PLL_CONFIGURATION2);
val |= PLL_IDLE;
omap_usb_writel(phy->pll_ctrl_base, PLL_CONFIGURATION2, val);
do {
val = omap_usb_readl(phy->pll_ctrl_base, PLL_STATUS);
if (val & PLL_TICOPWDN)
break;
udelay(1);
} while (--timeout);
omap_control_usb3_phy_power(phy->control_dev, 0);
phy->is_suspended = 1;
} else if (!suspend && phy->is_suspended) {
phy->is_suspended = 0;
val = omap_usb_readl(phy->pll_ctrl_base, PLL_CONFIGURATION2);
val &= ~PLL_IDLE;
omap_usb_writel(phy->pll_ctrl_base, PLL_CONFIGURATION2, val);
do {
val = omap_usb_readl(phy->pll_ctrl_base, PLL_STATUS);
if (!(val & PLL_TICOPWDN))
break;
udelay(1);
} while (--timeout);
}
return 0;
}
static inline enum sys_clk_rate __get_sys_clk_index(unsigned long rate)
{
switch (rate) {
case 12000000:
return CLK_RATE_12MHZ;
case 16800000:
return CLK_RATE_16MHZ;
case 19200000:
return CLK_RATE_19MHZ;
case 20000000:
return CLK_RATE_20MHZ;
case 26000000:
return CLK_RATE_26MHZ;
case 38400000:
return CLK_RATE_38MHZ;
default:
return CLK_RATE_UNDEFINED;
}
}
static void omap_usb_dpll_relock(struct omap_usb *phy)
{
u32 val;
unsigned long timeout;
omap_usb_writel(phy->pll_ctrl_base, PLL_GO, SET_PLL_GO);
timeout = jiffies + msecs_to_jiffies(20);
do {
val = omap_usb_readl(phy->pll_ctrl_base, PLL_STATUS);
if (val & PLL_LOCK)
break;
} while (!WARN_ON(time_after(jiffies, timeout)));
}
static int omap_usb_dpll_lock(struct omap_usb *phy)
{
u32 val;
unsigned long rate;
enum sys_clk_rate clk_index;
rate = clk_get_rate(phy->sys_clk);
clk_index = __get_sys_clk_index(rate);
if (clk_index == CLK_RATE_UNDEFINED) {
pr_err("dpll cannot be locked for sys clk freq:%luHz\n", rate);
return -EINVAL;
}
val = omap_usb_readl(phy->pll_ctrl_base, PLL_CONFIGURATION1);
val &= ~PLL_REGN_MASK;
val |= omap_usb3_dpll_params[clk_index].n << PLL_REGN_SHIFT;
omap_usb_writel(phy->pll_ctrl_base, PLL_CONFIGURATION1, val);
val = omap_usb_readl(phy->pll_ctrl_base, PLL_CONFIGURATION2);
val &= ~PLL_SELFREQDCO_MASK;
val |= omap_usb3_dpll_params[clk_index].freq << PLL_SELFREQDCO_SHIFT;
omap_usb_writel(phy->pll_ctrl_base, PLL_CONFIGURATION2, val);
val = omap_usb_readl(phy->pll_ctrl_base, PLL_CONFIGURATION1);
val &= ~PLL_REGM_MASK;
val |= omap_usb3_dpll_params[clk_index].m << PLL_REGM_SHIFT;
omap_usb_writel(phy->pll_ctrl_base, PLL_CONFIGURATION1, val);
val = omap_usb_readl(phy->pll_ctrl_base, PLL_CONFIGURATION4);
val &= ~PLL_REGM_F_MASK;
val |= omap_usb3_dpll_params[clk_index].mf << PLL_REGM_F_SHIFT;
omap_usb_writel(phy->pll_ctrl_base, PLL_CONFIGURATION4, val);
val = omap_usb_readl(phy->pll_ctrl_base, PLL_CONFIGURATION3);
val &= ~PLL_SD_MASK;
val |= omap_usb3_dpll_params[clk_index].sd << PLL_SD_SHIFT;
omap_usb_writel(phy->pll_ctrl_base, PLL_CONFIGURATION3, val);
omap_usb_dpll_relock(phy);
return 0;
}
static int omap_usb3_init(struct usb_phy *x)
{
struct omap_usb *phy = phy_to_omapusb(x);
omap_usb_dpll_lock(phy);
omap_control_usb3_phy_power(phy->control_dev, 1);
return 0;
}
static int omap_usb3_probe(struct platform_device *pdev)
{
struct omap_usb *phy;
struct resource *res;
phy = devm_kzalloc(&pdev->dev, sizeof(*phy), GFP_KERNEL);
if (!phy) {
dev_err(&pdev->dev, "unable to alloc mem for OMAP USB3 PHY\n");
return -ENOMEM;
}
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "pll_ctrl");
phy->pll_ctrl_base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(phy->pll_ctrl_base))
return PTR_ERR(phy->pll_ctrl_base);
phy->dev = &pdev->dev;
phy->phy.dev = phy->dev;
phy->phy.label = "omap-usb3";
phy->phy.init = omap_usb3_init;
phy->phy.set_suspend = omap_usb3_suspend;
phy->phy.type = USB_PHY_TYPE_USB3;
phy->is_suspended = 1;
phy->wkupclk = devm_clk_get(phy->dev, "usb_phy_cm_clk32k");
if (IS_ERR(phy->wkupclk)) {
dev_err(&pdev->dev, "unable to get usb_phy_cm_clk32k\n");
return PTR_ERR(phy->wkupclk);
}
clk_prepare(phy->wkupclk);
phy->optclk = devm_clk_get(phy->dev, "usb_otg_ss_refclk960m");
if (IS_ERR(phy->optclk)) {
dev_err(&pdev->dev, "unable to get usb_otg_ss_refclk960m\n");
return PTR_ERR(phy->optclk);
}
clk_prepare(phy->optclk);
phy->sys_clk = devm_clk_get(phy->dev, "sys_clkin");
if (IS_ERR(phy->sys_clk)) {
pr_err("%s: unable to get sys_clkin\n", __func__);
return -EINVAL;
}
phy->control_dev = omap_get_control_dev();
if (IS_ERR(phy->control_dev)) {
dev_dbg(&pdev->dev, "Failed to get control device\n");
return -ENODEV;
}
omap_control_usb3_phy_power(phy->control_dev, 0);
usb_add_phy_dev(&phy->phy);
platform_set_drvdata(pdev, phy);
pm_runtime_enable(phy->dev);
pm_runtime_get(&pdev->dev);
return 0;
}
static int omap_usb3_remove(struct platform_device *pdev)
{
struct omap_usb *phy = platform_get_drvdata(pdev);
clk_unprepare(phy->wkupclk);
clk_unprepare(phy->optclk);
usb_remove_phy(&phy->phy);
if (!pm_runtime_suspended(&pdev->dev))
pm_runtime_put(&pdev->dev);
pm_runtime_disable(&pdev->dev);
return 0;
}
static int omap_usb3_runtime_suspend(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct omap_usb *phy = platform_get_drvdata(pdev);
clk_disable(phy->wkupclk);
clk_disable(phy->optclk);
return 0;
}
static int omap_usb3_runtime_resume(struct device *dev)
{
u32 ret = 0;
struct platform_device *pdev = to_platform_device(dev);
struct omap_usb *phy = platform_get_drvdata(pdev);
ret = clk_enable(phy->optclk);
if (ret) {
dev_err(phy->dev, "Failed to enable optclk %d\n", ret);
goto err1;
}
ret = clk_enable(phy->wkupclk);
if (ret) {
dev_err(phy->dev, "Failed to enable wkupclk %d\n", ret);
goto err2;
}
return 0;
err2:
clk_disable(phy->optclk);
err1:
return ret;
}
