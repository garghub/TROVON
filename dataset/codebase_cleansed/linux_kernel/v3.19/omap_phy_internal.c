static int __init omap4430_phy_power_down(void)
{
void __iomem *ctrl_base;
if (!cpu_is_omap44xx())
return 0;
ctrl_base = ioremap(OMAP443X_SCM_BASE, SZ_1K);
if (!ctrl_base) {
pr_err("control module ioremap failed\n");
return -ENOMEM;
}
writel_relaxed(PHY_PD, ctrl_base + CONTROL_DEV_CONF);
iounmap(ctrl_base);
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
pr_info("Waiting for PHY clock good...\n");
while (!(omap_ctrl_readl(AM35XX_CONTROL_DEVCONF2)
& CONF2_PHYCLKGD)) {
cpu_relax();
if (time_after(jiffies, timeout)) {
pr_err("musb PHY clock good timed out\n");
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
case MUSB_HOST:
devconf2 |= CONF2_FORCE_HOST;
break;
case MUSB_PERIPHERAL:
devconf2 |= CONF2_FORCE_DEVICE;
break;
case MUSB_OTG:
devconf2 |= CONF2_NO_OVERRIDE;
break;
default:
pr_info("Unsupported mode %u\n", musb_mode);
}
omap_ctrl_writel(devconf2, AM35XX_CONTROL_DEVCONF2);
}
void ti81xx_musb_phy_power(u8 on)
{
void __iomem *scm_base = NULL;
u32 usbphycfg;
scm_base = ioremap(TI81XX_SCM_BASE, SZ_2K);
if (!scm_base) {
pr_err("system control module ioremap failed\n");
return;
}
usbphycfg = readl_relaxed(scm_base + USBCTRL0);
if (on) {
if (cpu_is_ti816x()) {
usbphycfg |= TI816X_USBPHY0_NORMAL_MODE;
usbphycfg &= ~TI816X_USBPHY_REFCLK_OSC;
} else if (cpu_is_ti814x()) {
usbphycfg &= ~(USBPHY_CM_PWRDN | USBPHY_OTG_PWRDN
| USBPHY_DPINPUT | USBPHY_DMINPUT);
usbphycfg |= (USBPHY_OTGVDET_EN | USBPHY_OTGSESSEND_EN
| USBPHY_DPOPBUFCTL | USBPHY_DMOPBUFCTL);
}
} else {
if (cpu_is_ti816x())
usbphycfg &= ~TI816X_USBPHY0_NORMAL_MODE;
else if (cpu_is_ti814x())
usbphycfg |= USBPHY_CM_PWRDN | USBPHY_OTG_PWRDN;
}
writel_relaxed(usbphycfg, scm_base + USBCTRL0);
iounmap(scm_base);
}
