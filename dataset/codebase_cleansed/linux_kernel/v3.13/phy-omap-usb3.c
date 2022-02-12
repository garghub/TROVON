static struct usb_dpll_params *omap_usb3_get_dpll_params(unsigned long rate)
{
int i;
for (i = 0; i < ARRAY_SIZE(dpll_map); i++) {
if (rate == dpll_map[i].rate)
return &dpll_map[i].params;
}
return NULL;
}
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
omap_control_usb_phy_power(phy->control_dev, 0);
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
struct usb_dpll_params *dpll_params;
rate = clk_get_rate(phy->sys_clk);
dpll_params = omap_usb3_get_dpll_params(rate);
if (!dpll_params) {
dev_err(phy->dev,
"No DPLL configuration for %lu Hz SYS CLK\n", rate);
return -EINVAL;
}
val = omap_usb_readl(phy->pll_ctrl_base, PLL_CONFIGURATION1);
val &= ~PLL_REGN_MASK;
val |= dpll_params->n << PLL_REGN_SHIFT;
omap_usb_writel(phy->pll_ctrl_base, PLL_CONFIGURATION1, val);
val = omap_usb_readl(phy->pll_ctrl_base, PLL_CONFIGURATION2);
val &= ~PLL_SELFREQDCO_MASK;
val |= dpll_params->freq << PLL_SELFREQDCO_SHIFT;
omap_usb_writel(phy->pll_ctrl_base, PLL_CONFIGURATION2, val);
val = omap_usb_readl(phy->pll_ctrl_base, PLL_CONFIGURATION1);
val &= ~PLL_REGM_MASK;
val |= dpll_params->m << PLL_REGM_SHIFT;
omap_usb_writel(phy->pll_ctrl_base, PLL_CONFIGURATION1, val);
val = omap_usb_readl(phy->pll_ctrl_base, PLL_CONFIGURATION4);
val &= ~PLL_REGM_F_MASK;
val |= dpll_params->mf << PLL_REGM_F_SHIFT;
omap_usb_writel(phy->pll_ctrl_base, PLL_CONFIGURATION4, val);
val = omap_usb_readl(phy->pll_ctrl_base, PLL_CONFIGURATION3);
val &= ~PLL_SD_MASK;
val |= dpll_params->sd << PLL_SD_SHIFT;
omap_usb_writel(phy->pll_ctrl_base, PLL_CONFIGURATION3, val);
omap_usb_dpll_relock(phy);
return 0;
}
static int omap_usb3_init(struct usb_phy *x)
{
struct omap_usb *phy = phy_to_omapusb(x);
int ret;
ret = omap_usb_dpll_lock(phy);
if (ret)
return ret;
omap_control_usb_phy_power(phy->control_dev, 1);
return 0;
}
static int omap_usb3_probe(struct platform_device *pdev)
{
struct omap_usb *phy;
struct resource *res;
struct device_node *node = pdev->dev.of_node;
struct device_node *control_node;
struct platform_device *control_pdev;
if (!node)
return -EINVAL;
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
control_node = of_parse_phandle(node, "ctrl-module", 0);
if (!control_node) {
dev_err(&pdev->dev, "Failed to get control device phandle\n");
return -EINVAL;
}
control_pdev = of_find_device_by_node(control_node);
if (!control_pdev) {
dev_err(&pdev->dev, "Failed to get control device\n");
return -EINVAL;
}
phy->control_dev = &control_pdev->dev;
omap_control_usb_phy_power(phy->control_dev, 0);
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
