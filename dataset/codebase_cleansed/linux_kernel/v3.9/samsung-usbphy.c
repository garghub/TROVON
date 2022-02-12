int samsung_usbphy_set_host(struct usb_otg *otg, struct usb_bus *host)
{
if (!otg)
return -ENODEV;
if (!otg->host)
otg->host = host;
return 0;
}
static int samsung_usbphy_parse_dt(struct samsung_usbphy *sphy)
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
static void samsung_usbphy_set_isolation(struct samsung_usbphy *sphy, bool on)
{
void __iomem *reg = NULL;
u32 reg_val;
u32 en_mask = 0;
if (!sphy->pmuregs) {
dev_warn(sphy->dev, "Can't set pmu isolation\n");
return;
}
switch (sphy->drv_data->cpu_type) {
case TYPE_S3C64XX:
break;
case TYPE_EXYNOS4210:
case TYPE_EXYNOS5250:
if (sphy->phy_type == USB_PHY_TYPE_DEVICE) {
reg = sphy->pmuregs +
sphy->drv_data->devphy_reg_offset;
en_mask = sphy->drv_data->devphy_en_mask;
} else if (sphy->phy_type == USB_PHY_TYPE_HOST) {
reg = sphy->pmuregs +
sphy->drv_data->hostphy_reg_offset;
en_mask = sphy->drv_data->hostphy_en_mask;
}
break;
default:
dev_err(sphy->dev, "Invalid SoC type\n");
return;
}
reg_val = readl(reg);
if (on)
reg_val &= ~en_mask;
else
reg_val |= en_mask;
writel(reg_val, reg);
}
static void samsung_usbphy_cfg_sel(struct samsung_usbphy *sphy)
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
static int samsung_usbphy_set_type(struct usb_phy *phy,
enum samsung_usb_phy_type phy_type)
{
struct samsung_usbphy *sphy = phy_to_sphy(phy);
sphy->phy_type = phy_type;
return 0;
}
static int samsung_usbphy_get_refclk_freq(struct samsung_usbphy *sphy)
{
struct clk *ref_clk;
int refclk_freq = 0;
if (sphy->drv_data->cpu_type == TYPE_EXYNOS5250)
ref_clk = clk_get(sphy->dev, "ext_xtal");
else
ref_clk = clk_get(sphy->dev, "xusbxti");
if (IS_ERR(ref_clk)) {
dev_err(sphy->dev, "Failed to get reference clock\n");
return PTR_ERR(ref_clk);
}
if (sphy->drv_data->cpu_type == TYPE_EXYNOS5250) {
switch (clk_get_rate(ref_clk)) {
case 9600 * KHZ:
refclk_freq = FSEL_CLKSEL_9600K;
break;
case 10 * MHZ:
refclk_freq = FSEL_CLKSEL_10M;
break;
case 12 * MHZ:
refclk_freq = FSEL_CLKSEL_12M;
break;
case 19200 * KHZ:
refclk_freq = FSEL_CLKSEL_19200K;
break;
case 20 * MHZ:
refclk_freq = FSEL_CLKSEL_20M;
break;
case 50 * MHZ:
refclk_freq = FSEL_CLKSEL_50M;
break;
case 24 * MHZ:
default:
refclk_freq = FSEL_CLKSEL_24M;
break;
}
} else {
switch (clk_get_rate(ref_clk)) {
case 12 * MHZ:
refclk_freq = PHYCLK_CLKSEL_12M;
break;
case 24 * MHZ:
refclk_freq = PHYCLK_CLKSEL_24M;
break;
case 48 * MHZ:
refclk_freq = PHYCLK_CLKSEL_48M;
break;
default:
if (sphy->drv_data->cpu_type == TYPE_S3C64XX)
refclk_freq = PHYCLK_CLKSEL_48M;
else
refclk_freq = PHYCLK_CLKSEL_24M;
break;
}
}
clk_put(ref_clk);
return refclk_freq;
}
static bool exynos5_phyhost_is_on(void *regs)
{
u32 reg;
reg = readl(regs + EXYNOS5_PHY_HOST_CTRL0);
return !(reg & HOST_CTRL0_SIDDQ);
}
static void samsung_exynos5_usbphy_enable(struct samsung_usbphy *sphy)
{
void __iomem *regs = sphy->regs;
u32 phyclk = sphy->ref_clk_freq;
u32 phyhost;
u32 phyotg;
u32 phyhsic;
u32 ehcictrl;
u32 ohcictrl;
atomic_inc(&sphy->phy_usage);
if (exynos5_phyhost_is_on(regs)) {
dev_info(sphy->dev, "Already power on PHY\n");
return;
}
phyhost = readl(regs + EXYNOS5_PHY_HOST_CTRL0);
phyhost &= ~HOST_CTRL0_FSEL_MASK;
phyhost |= HOST_CTRL0_FSEL(phyclk);
phyhost &= ~(HOST_CTRL0_PHYSWRST |
HOST_CTRL0_PHYSWRSTALL |
HOST_CTRL0_SIDDQ |
HOST_CTRL0_FORCESUSPEND |
HOST_CTRL0_FORCESLEEP);
phyhost |= (HOST_CTRL0_LINKSWRST |
HOST_CTRL0_UTMISWRST |
HOST_CTRL0_COMMONON_N);
writel(phyhost, regs + EXYNOS5_PHY_HOST_CTRL0);
udelay(10);
phyhost &= ~(HOST_CTRL0_LINKSWRST |
HOST_CTRL0_UTMISWRST);
writel(phyhost, regs + EXYNOS5_PHY_HOST_CTRL0);
phyotg = readl(regs + EXYNOS5_PHY_OTG_SYS);
phyotg &= ~OTG_SYS_FSEL_MASK;
phyotg |= OTG_SYS_FSEL(phyclk);
phyotg &= ~(OTG_SYS_FORCESUSPEND |
OTG_SYS_SIDDQ_UOTG |
OTG_SYS_FORCESLEEP |
OTG_SYS_REFCLKSEL_MASK |
OTG_SYS_COMMON_ON);
phyotg |= (OTG_SYS_PHY0_SWRST |
OTG_SYS_LINKSWRST_UOTG |
OTG_SYS_PHYLINK_SWRESET |
OTG_SYS_OTGDISABLE |
OTG_SYS_REFCLKSEL_CLKCORE);
writel(phyotg, regs + EXYNOS5_PHY_OTG_SYS);
udelay(10);
phyotg &= ~(OTG_SYS_PHY0_SWRST |
OTG_SYS_LINKSWRST_UOTG |
OTG_SYS_PHYLINK_SWRESET);
writel(phyotg, regs + EXYNOS5_PHY_OTG_SYS);
phyhsic = (HSIC_CTRL_REFCLKDIV_12 |
HSIC_CTRL_REFCLKSEL |
HSIC_CTRL_PHYSWRST);
writel(phyhsic, regs + EXYNOS5_PHY_HSIC_CTRL1);
writel(phyhsic, regs + EXYNOS5_PHY_HSIC_CTRL2);
udelay(10);
phyhsic &= ~HSIC_CTRL_PHYSWRST;
writel(phyhsic, regs + EXYNOS5_PHY_HSIC_CTRL1);
writel(phyhsic, regs + EXYNOS5_PHY_HSIC_CTRL2);
udelay(80);
ehcictrl = readl(regs + EXYNOS5_PHY_HOST_EHCICTRL);
ehcictrl |= (HOST_EHCICTRL_ENAINCRXALIGN |
HOST_EHCICTRL_ENAINCR4 |
HOST_EHCICTRL_ENAINCR8 |
HOST_EHCICTRL_ENAINCR16);
writel(ehcictrl, regs + EXYNOS5_PHY_HOST_EHCICTRL);
ohcictrl = readl(regs + EXYNOS5_PHY_HOST_OHCICTRL);
ohcictrl |= HOST_OHCICTRL_SUSPLGCY;
writel(ohcictrl, regs + EXYNOS5_PHY_HOST_OHCICTRL);
}
static void samsung_usbphy_enable(struct samsung_usbphy *sphy)
{
void __iomem *regs = sphy->regs;
u32 phypwr;
u32 phyclk;
u32 rstcon;
phyclk = sphy->ref_clk_freq;
phypwr = readl(regs + SAMSUNG_PHYPWR);
rstcon = readl(regs + SAMSUNG_RSTCON);
switch (sphy->drv_data->cpu_type) {
case TYPE_S3C64XX:
phyclk &= ~PHYCLK_COMMON_ON_N;
phypwr &= ~PHYPWR_NORMAL_MASK;
rstcon |= RSTCON_SWRST;
break;
case TYPE_EXYNOS4210:
phypwr &= ~PHYPWR_NORMAL_MASK_PHY0;
rstcon |= RSTCON_SWRST;
default:
break;
}
writel(phyclk, regs + SAMSUNG_PHYCLK);
writel(phypwr, regs + SAMSUNG_PHYPWR);
writel(rstcon, regs + SAMSUNG_RSTCON);
udelay(10);
rstcon &= ~RSTCON_SWRST;
writel(rstcon, regs + SAMSUNG_RSTCON);
}
static void samsung_exynos5_usbphy_disable(struct samsung_usbphy *sphy)
{
void __iomem *regs = sphy->regs;
u32 phyhost;
u32 phyotg;
u32 phyhsic;
if (atomic_dec_return(&sphy->phy_usage) > 0) {
dev_info(sphy->dev, "still being used\n");
return;
}
phyhsic = (HSIC_CTRL_REFCLKDIV_12 |
HSIC_CTRL_REFCLKSEL |
HSIC_CTRL_SIDDQ |
HSIC_CTRL_FORCESLEEP |
HSIC_CTRL_FORCESUSPEND);
writel(phyhsic, regs + EXYNOS5_PHY_HSIC_CTRL1);
writel(phyhsic, regs + EXYNOS5_PHY_HSIC_CTRL2);
phyhost = readl(regs + EXYNOS5_PHY_HOST_CTRL0);
phyhost |= (HOST_CTRL0_SIDDQ |
HOST_CTRL0_FORCESUSPEND |
HOST_CTRL0_FORCESLEEP |
HOST_CTRL0_PHYSWRST |
HOST_CTRL0_PHYSWRSTALL);
writel(phyhost, regs + EXYNOS5_PHY_HOST_CTRL0);
phyotg = readl(regs + EXYNOS5_PHY_OTG_SYS);
phyotg |= (OTG_SYS_FORCESUSPEND |
OTG_SYS_SIDDQ_UOTG |
OTG_SYS_FORCESLEEP);
writel(phyotg, regs + EXYNOS5_PHY_OTG_SYS);
}
static void samsung_usbphy_disable(struct samsung_usbphy *sphy)
{
void __iomem *regs = sphy->regs;
u32 phypwr;
phypwr = readl(regs + SAMSUNG_PHYPWR);
switch (sphy->drv_data->cpu_type) {
case TYPE_S3C64XX:
phypwr |= PHYPWR_NORMAL_MASK;
break;
case TYPE_EXYNOS4210:
phypwr |= PHYPWR_NORMAL_MASK_PHY0;
default:
break;
}
writel(phypwr, regs + SAMSUNG_PHYPWR);
}
static int samsung_usbphy_init(struct usb_phy *phy)
{
struct samsung_usbphy *sphy;
struct usb_bus *host = NULL;
unsigned long flags;
int ret = 0;
sphy = phy_to_sphy(phy);
host = phy->otg->host;
ret = clk_prepare_enable(sphy->clk);
if (ret) {
dev_err(sphy->dev, "%s: clk_prepare_enable failed\n", __func__);
return ret;
}
spin_lock_irqsave(&sphy->lock, flags);
if (host) {
if (!strstr(dev_name(host->controller), "ehci") ||
!strstr(dev_name(host->controller), "ohci"))
samsung_usbphy_set_type(&sphy->phy, USB_PHY_TYPE_HOST);
} else {
samsung_usbphy_set_type(&sphy->phy, USB_PHY_TYPE_DEVICE);
}
if (sphy->plat && sphy->plat->pmu_isolation)
sphy->plat->pmu_isolation(false);
else
samsung_usbphy_set_isolation(sphy, false);
samsung_usbphy_cfg_sel(sphy);
if (sphy->drv_data->cpu_type == TYPE_EXYNOS5250)
samsung_exynos5_usbphy_enable(sphy);
else
samsung_usbphy_enable(sphy);
spin_unlock_irqrestore(&sphy->lock, flags);
clk_disable_unprepare(sphy->clk);
return ret;
}
static void samsung_usbphy_shutdown(struct usb_phy *phy)
{
struct samsung_usbphy *sphy;
struct usb_bus *host = NULL;
unsigned long flags;
sphy = phy_to_sphy(phy);
host = phy->otg->host;
if (clk_prepare_enable(sphy->clk)) {
dev_err(sphy->dev, "%s: clk_prepare_enable failed\n", __func__);
return;
}
spin_lock_irqsave(&sphy->lock, flags);
if (host) {
if (!strstr(dev_name(host->controller), "ehci") ||
!strstr(dev_name(host->controller), "ohci"))
samsung_usbphy_set_type(&sphy->phy, USB_PHY_TYPE_HOST);
} else {
samsung_usbphy_set_type(&sphy->phy, USB_PHY_TYPE_DEVICE);
}
if (sphy->drv_data->cpu_type == TYPE_EXYNOS5250)
samsung_exynos5_usbphy_disable(sphy);
else
samsung_usbphy_disable(sphy);
if (sphy->plat && sphy->plat->pmu_isolation)
sphy->plat->pmu_isolation(true);
else
samsung_usbphy_set_isolation(sphy, true);
spin_unlock_irqrestore(&sphy->lock, flags);
clk_disable_unprepare(sphy->clk);
}
static inline const struct samsung_usbphy_drvdata
*samsung_usbphy_get_driver_data(struct platform_device *pdev)
{
if (pdev->dev.of_node) {
const struct of_device_id *match;
match = of_match_node(samsung_usbphy_dt_match,
pdev->dev.of_node);
return match->data;
}
return (struct samsung_usbphy_drvdata *)
platform_get_device_id(pdev)->driver_data;
}
static int samsung_usbphy_probe(struct platform_device *pdev)
{
struct samsung_usbphy *sphy;
struct usb_otg *otg;
struct samsung_usbphy_data *pdata = pdev->dev.platform_data;
const struct samsung_usbphy_drvdata *drv_data;
struct device *dev = &pdev->dev;
struct resource *phy_mem;
void __iomem *phy_base;
struct clk *clk;
int ret;
phy_mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!phy_mem) {
dev_err(dev, "%s: missing mem resource\n", __func__);
return -ENODEV;
}
phy_base = devm_ioremap_resource(dev, phy_mem);
if (IS_ERR(phy_base))
return PTR_ERR(phy_base);
sphy = devm_kzalloc(dev, sizeof(*sphy), GFP_KERNEL);
if (!sphy)
return -ENOMEM;
otg = devm_kzalloc(dev, sizeof(*otg), GFP_KERNEL);
if (!otg)
return -ENOMEM;
drv_data = samsung_usbphy_get_driver_data(pdev);
if (drv_data->cpu_type == TYPE_EXYNOS5250)
clk = devm_clk_get(dev, "usbhost");
else
clk = devm_clk_get(dev, "otg");
if (IS_ERR(clk)) {
dev_err(dev, "Failed to get otg clock\n");
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
sphy->drv_data = drv_data;
sphy->phy.dev = sphy->dev;
sphy->phy.label = "samsung-usbphy";
sphy->phy.init = samsung_usbphy_init;
sphy->phy.shutdown = samsung_usbphy_shutdown;
sphy->ref_clk_freq = samsung_usbphy_get_refclk_freq(sphy);
sphy->phy.otg = otg;
sphy->phy.otg->phy = &sphy->phy;
sphy->phy.otg->set_host = samsung_usbphy_set_host;
spin_lock_init(&sphy->lock);
platform_set_drvdata(pdev, sphy);
return usb_add_phy(&sphy->phy, USB_PHY_TYPE_USB2);
}
static int samsung_usbphy_remove(struct platform_device *pdev)
{
struct samsung_usbphy *sphy = platform_get_drvdata(pdev);
usb_remove_phy(&sphy->phy);
if (sphy->pmuregs)
iounmap(sphy->pmuregs);
if (sphy->sysreg)
iounmap(sphy->sysreg);
return 0;
}
