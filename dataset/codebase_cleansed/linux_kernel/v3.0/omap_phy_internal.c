int omap4430_phy_init(struct device *dev)
{
ctrl_base = ioremap(OMAP443X_SCM_BASE, SZ_1K);
if (!ctrl_base) {
pr_err("control module ioremap failed\n");
return -ENOMEM;
}
__raw_writel(PHY_PD, ctrl_base + CONTROL_DEV_CONF);
if (!dev) {
iounmap(ctrl_base);
return 0;
}
phyclk = clk_get(dev, "ocp2scp_usb_phy_ick");
if (IS_ERR(phyclk)) {
dev_err(dev, "cannot clk_get ocp2scp_usb_phy_ick\n");
iounmap(ctrl_base);
return PTR_ERR(phyclk);
}
clk48m = clk_get(dev, "ocp2scp_usb_phy_phy_48m");
if (IS_ERR(clk48m)) {
dev_err(dev, "cannot clk_get ocp2scp_usb_phy_phy_48m\n");
clk_put(phyclk);
iounmap(ctrl_base);
return PTR_ERR(clk48m);
}
clk32k = clk_get(dev, "usb_phy_cm_clk32k");
if (IS_ERR(clk32k)) {
dev_err(dev, "cannot clk_get usb_phy_cm_clk32k\n");
clk_put(phyclk);
clk_put(clk48m);
iounmap(ctrl_base);
return PTR_ERR(clk32k);
}
return 0;
}
int omap4430_phy_set_clk(struct device *dev, int on)
{
static int state;
if (on && !state) {
clk_enable(phyclk);
clk_enable(clk48m);
clk_enable(clk32k);
state = 1;
} else if (state) {
clk_disable(phyclk);
clk_disable(clk48m);
clk_disable(clk32k);
state = 0;
}
return 0;
}
int omap4430_phy_power(struct device *dev, int ID, int on)
{
if (on) {
if (ID)
__raw_writel(AVALID | VBUSVALID, ctrl_base +
USBOTGHS_CONTROL);
else
__raw_writel(IDDIG | AVALID | VBUSVALID,
ctrl_base + USBOTGHS_CONTROL);
} else {
__raw_writel(SESSEND | IDDIG, ctrl_base +
USBOTGHS_CONTROL);
}
return 0;
}
int omap4430_phy_suspend(struct device *dev, int suspend)
{
if (suspend) {
omap4430_phy_set_clk(dev, 0);
__raw_writel(PHY_PD, ctrl_base + CONTROL_DEV_CONF);
usbotghs_control = __raw_readl(ctrl_base + USBOTGHS_CONTROL);
} else {
omap4430_phy_set_clk(dev, 1);
if (__raw_readl(ctrl_base + CONTROL_DEV_CONF) & PHY_PD) {
__raw_writel(~PHY_PD, ctrl_base + CONTROL_DEV_CONF);
mdelay(200);
}
__raw_writel(usbotghs_control, ctrl_base + USBOTGHS_CONTROL);
}
return 0;
}
int omap4430_phy_exit(struct device *dev)
{
if (ctrl_base)
iounmap(ctrl_base);
if (phyclk)
clk_put(phyclk);
if (clk48m)
clk_put(clk48m);
if (clk32k)
clk_put(clk32k);
return 0;
}
void am35x_musb_reset(void)
{
u32 regval;
regval = omap_ctrl_readl(AM35XX_CONTROL_IP_SW_RESET);
regval |= AM35XX_USBOTGSS_SW_RST;
omap_ctrl_writel(regval, AM35XX_CONTROL_IP_SW_RESET);
regval &= ~AM35XX_USBOTGSS_SW_RST;
omap_ctrl_writel(regval, AM35XX_CONTROL_IP_SW_RESET);
regval = omap_ctrl_readl(AM35XX_CONTROL_IP_SW_RESET);
}
void am35x_musb_phy_power(u8 on)
{
unsigned long timeout = jiffies + msecs_to_jiffies(100);
u32 devconf2;
if (on) {
devconf2 = omap_ctrl_readl(AM35XX_CONTROL_DEVCONF2);
devconf2 &= ~(CONF2_RESET | CONF2_PHYPWRDN | CONF2_OTGPWRDN);
devconf2 |= CONF2_PHY_PLLON;
omap_ctrl_writel(devconf2, AM35XX_CONTROL_DEVCONF2);
pr_info(KERN_INFO "Waiting for PHY clock good...\n");
while (!(omap_ctrl_readl(AM35XX_CONTROL_DEVCONF2)
& CONF2_PHYCLKGD)) {
cpu_relax();
if (time_after(jiffies, timeout)) {
pr_err(KERN_ERR "musb PHY clock good timed out\n");
break;
}
}
} else {
devconf2 = omap_ctrl_readl(AM35XX_CONTROL_DEVCONF2);
devconf2 &= ~CONF2_PHY_PLLON;
devconf2 |= CONF2_PHYPWRDN | CONF2_OTGPWRDN;
omap_ctrl_writel(devconf2, AM35XX_CONTROL_DEVCONF2);
}
}
void am35x_musb_clear_irq(void)
{
u32 regval;
regval = omap_ctrl_readl(AM35XX_CONTROL_LVL_INTR_CLEAR);
regval |= AM35XX_USBOTGSS_INT_CLR;
omap_ctrl_writel(regval, AM35XX_CONTROL_LVL_INTR_CLEAR);
regval = omap_ctrl_readl(AM35XX_CONTROL_LVL_INTR_CLEAR);
}
void am35x_set_mode(u8 musb_mode)
{
u32 devconf2 = omap_ctrl_readl(AM35XX_CONTROL_DEVCONF2);
devconf2 &= ~CONF2_OTGMODE;
switch (musb_mode) {
#ifdef CONFIG_USB_MUSB_HDRC_HCD
case MUSB_HOST:
devconf2 |= CONF2_FORCE_HOST;
break;
#endif
#ifdef CONFIG_USB_GADGET_MUSB_HDRC
case MUSB_PERIPHERAL:
devconf2 |= CONF2_FORCE_DEVICE;
break;
#endif
#ifdef CONFIG_USB_MUSB_OTG
case MUSB_OTG:
devconf2 |= CONF2_NO_OVERRIDE;
break;
#endif
default:
pr_info(KERN_INFO "Unsupported mode %u\n", musb_mode);
}
omap_ctrl_writel(devconf2, AM35XX_CONTROL_DEVCONF2);
}
