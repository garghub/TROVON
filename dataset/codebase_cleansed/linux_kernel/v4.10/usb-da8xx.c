int __init da8xx_register_usb_phy(void)
{
return platform_device_register(&da8xx_usb_phy);
}
int __init da8xx_register_usb20(unsigned int mA, unsigned int potpgt)
{
usb_data.power = mA > 510 ? 255 : mA / 2;
usb_data.potpgt = (potpgt + 1) / 2;
return platform_device_register(&da8xx_usb20_dev);
}
int __init da8xx_register_usb11(struct da8xx_ohci_root_hub *pdata)
{
da8xx_usb11_device.dev.platform_data = pdata;
return platform_device_register(&da8xx_usb11_device);
}
int __init da8xx_register_usb_refclkin(int rate)
{
int ret;
usb_refclkin.rate = rate;
ret = clk_register(&usb_refclkin);
if (ret)
return ret;
clkdev_add(&usb_refclkin_lookup);
return 0;
}
static void usb20_phy_clk_enable(struct clk *clk)
{
u32 val;
u32 timeout = 500000;
val = readl(DA8XX_SYSCFG0_VIRT(DA8XX_CFGCHIP2_REG));
davinci_clk_enable(usb20_clk);
val &= ~(CFGCHIP2_RESET | CFGCHIP2_PHYPWRDN);
val |= CFGCHIP2_PHY_PLLON;
writel(val, DA8XX_SYSCFG0_VIRT(DA8XX_CFGCHIP2_REG));
while (--timeout) {
val = readl(DA8XX_SYSCFG0_VIRT(DA8XX_CFGCHIP2_REG));
if (val & CFGCHIP2_PHYCLKGD)
goto done;
udelay(1);
}
pr_err("Timeout waiting for USB 2.0 PHY clock good\n");
done:
davinci_clk_disable(usb20_clk);
}
static void usb20_phy_clk_disable(struct clk *clk)
{
u32 val;
val = readl(DA8XX_SYSCFG0_VIRT(DA8XX_CFGCHIP2_REG));
val |= CFGCHIP2_PHYPWRDN;
writel(val, DA8XX_SYSCFG0_VIRT(DA8XX_CFGCHIP2_REG));
}
static int usb20_phy_clk_set_parent(struct clk *clk, struct clk *parent)
{
u32 val;
val = readl(DA8XX_SYSCFG0_VIRT(DA8XX_CFGCHIP2_REG));
if (parent == &usb_refclkin) {
val &= ~CFGCHIP2_USB2PHYCLKMUX;
} else if (strcmp(parent->name, "pll0_aux_clk") == 0) {
val |= CFGCHIP2_USB2PHYCLKMUX;
} else {
pr_err("Bad parent on USB 2.0 PHY clock\n");
return -EINVAL;
}
val &= ~CFGCHIP2_REFFREQ_MASK;
switch (clk_get_rate(parent)) {
case 12000000:
val |= CFGCHIP2_REFFREQ_12MHZ;
break;
case 13000000:
val |= CFGCHIP2_REFFREQ_13MHZ;
break;
case 19200000:
val |= CFGCHIP2_REFFREQ_19_2MHZ;
break;
case 20000000:
val |= CFGCHIP2_REFFREQ_20MHZ;
break;
case 24000000:
val |= CFGCHIP2_REFFREQ_24MHZ;
break;
case 26000000:
val |= CFGCHIP2_REFFREQ_26MHZ;
break;
case 38400000:
val |= CFGCHIP2_REFFREQ_38_4MHZ;
break;
case 40000000:
val |= CFGCHIP2_REFFREQ_40MHZ;
break;
case 48000000:
val |= CFGCHIP2_REFFREQ_48MHZ;
break;
default:
pr_err("Bad parent clock rate on USB 2.0 PHY clock\n");
return -EINVAL;
}
writel(val, DA8XX_SYSCFG0_VIRT(DA8XX_CFGCHIP2_REG));
return 0;
}
int __init da8xx_register_usb20_phy_clk(bool use_usb_refclkin)
{
struct clk *parent;
int ret;
usb20_clk = clk_get(&da8xx_usb20_dev.dev, "usb20");
ret = PTR_ERR_OR_ZERO(usb20_clk);
if (ret)
return ret;
parent = clk_get(NULL, use_usb_refclkin ? "usb_refclkin" : "pll0_aux");
ret = PTR_ERR_OR_ZERO(parent);
if (ret) {
clk_put(usb20_clk);
return ret;
}
usb20_phy_clk.parent = parent;
ret = clk_register(&usb20_phy_clk);
if (!ret)
clkdev_add(&usb20_phy_clk_lookup);
clk_put(parent);
return ret;
}
static int usb11_phy_clk_set_parent(struct clk *clk, struct clk *parent)
{
u32 val;
val = readl(DA8XX_SYSCFG0_VIRT(DA8XX_CFGCHIP2_REG));
if (parent == &usb20_phy_clk) {
val &= ~CFGCHIP2_USB1PHYCLKMUX;
} else if (parent == &usb_refclkin) {
val |= CFGCHIP2_USB1PHYCLKMUX;
} else {
pr_err("Bad parent on USB 1.1 PHY clock\n");
return -EINVAL;
}
writel(val, DA8XX_SYSCFG0_VIRT(DA8XX_CFGCHIP2_REG));
return 0;
}
int __init da8xx_register_usb11_phy_clk(bool use_usb_refclkin)
{
struct clk *parent;
int ret = 0;
if (use_usb_refclkin)
parent = clk_get(NULL, "usb_refclkin");
else
parent = clk_get(&da8xx_usb_phy.dev, "usb20_phy");
if (IS_ERR(parent))
return PTR_ERR(parent);
usb11_phy_clk.parent = parent;
ret = clk_register(&usb11_phy_clk);
if (!ret)
clkdev_add(&usb11_phy_clk_lookup);
clk_put(parent);
return ret;
}
