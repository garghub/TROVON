static inline
struct exynos5_usbdrd_phy *to_usbdrd_phy(struct phy_usb_instance *inst)
{
return container_of((inst), struct exynos5_usbdrd_phy,
phys[(inst)->index]);
}
static unsigned int exynos5_rate_to_clk(unsigned long rate, u32 *reg)
{
switch (rate) {
case 9600 * KHZ:
*reg = EXYNOS5_FSEL_9MHZ6;
break;
case 10 * MHZ:
*reg = EXYNOS5_FSEL_10MHZ;
break;
case 12 * MHZ:
*reg = EXYNOS5_FSEL_12MHZ;
break;
case 19200 * KHZ:
*reg = EXYNOS5_FSEL_19MHZ2;
break;
case 20 * MHZ:
*reg = EXYNOS5_FSEL_20MHZ;
break;
case 24 * MHZ:
*reg = EXYNOS5_FSEL_24MHZ;
break;
case 50 * MHZ:
*reg = EXYNOS5_FSEL_50MHZ;
break;
default:
return -EINVAL;
}
return 0;
}
static void exynos5_usbdrd_phy_isol(struct phy_usb_instance *inst,
unsigned int on)
{
unsigned int val;
if (!inst->reg_pmu)
return;
val = on ? 0 : EXYNOS5_PHY_ENABLE;
regmap_update_bits(inst->reg_pmu, inst->pmu_offset,
EXYNOS5_PHY_ENABLE, val);
}
static unsigned int
exynos5_usbdrd_pipe3_set_refclk(struct phy_usb_instance *inst)
{
static u32 reg;
struct exynos5_usbdrd_phy *phy_drd = to_usbdrd_phy(inst);
reg = readl(phy_drd->reg_phy + EXYNOS5_DRD_PHYCLKRST);
reg &= ~PHYCLKRST_REFCLKSEL_MASK;
reg |= PHYCLKRST_REFCLKSEL_EXT_REFCLK;
reg &= ~PHYCLKRST_FSEL_PIPE_MASK |
PHYCLKRST_MPLL_MULTIPLIER_MASK |
PHYCLKRST_SSC_REFCLKSEL_MASK;
switch (phy_drd->extrefclk) {
case EXYNOS5_FSEL_50MHZ:
reg |= (PHYCLKRST_MPLL_MULTIPLIER_50M_REF |
PHYCLKRST_SSC_REFCLKSEL(0x00));
break;
case EXYNOS5_FSEL_24MHZ:
reg |= (PHYCLKRST_MPLL_MULTIPLIER_24MHZ_REF |
PHYCLKRST_SSC_REFCLKSEL(0x88));
break;
case EXYNOS5_FSEL_20MHZ:
reg |= (PHYCLKRST_MPLL_MULTIPLIER_20MHZ_REF |
PHYCLKRST_SSC_REFCLKSEL(0x00));
break;
case EXYNOS5_FSEL_19MHZ2:
reg |= (PHYCLKRST_MPLL_MULTIPLIER_19200KHZ_REF |
PHYCLKRST_SSC_REFCLKSEL(0x88));
break;
default:
dev_dbg(phy_drd->dev, "unsupported ref clk\n");
break;
}
return reg;
}
static unsigned int
exynos5_usbdrd_utmi_set_refclk(struct phy_usb_instance *inst)
{
static u32 reg;
struct exynos5_usbdrd_phy *phy_drd = to_usbdrd_phy(inst);
reg = readl(phy_drd->reg_phy + EXYNOS5_DRD_PHYCLKRST);
reg &= ~PHYCLKRST_REFCLKSEL_MASK;
reg |= PHYCLKRST_REFCLKSEL_EXT_REFCLK;
reg &= ~PHYCLKRST_FSEL_UTMI_MASK |
PHYCLKRST_MPLL_MULTIPLIER_MASK |
PHYCLKRST_SSC_REFCLKSEL_MASK;
reg |= PHYCLKRST_FSEL(phy_drd->extrefclk);
return reg;
}
static void exynos5_usbdrd_pipe3_init(struct exynos5_usbdrd_phy *phy_drd)
{
u32 reg;
reg = readl(phy_drd->reg_phy + EXYNOS5_DRD_PHYPARAM1);
reg &= ~PHYPARAM1_PCS_TXDEEMPH_MASK;
reg |= PHYPARAM1_PCS_TXDEEMPH;
writel(reg, phy_drd->reg_phy + EXYNOS5_DRD_PHYPARAM1);
reg = readl(phy_drd->reg_phy + EXYNOS5_DRD_PHYTEST);
reg &= ~PHYTEST_POWERDOWN_SSP;
writel(reg, phy_drd->reg_phy + EXYNOS5_DRD_PHYTEST);
}
static void exynos5_usbdrd_utmi_init(struct exynos5_usbdrd_phy *phy_drd)
{
u32 reg;
reg = readl(phy_drd->reg_phy + EXYNOS5_DRD_PHYPARAM0);
reg &= ~PHYPARAM0_REF_LOSLEVEL_MASK;
reg |= PHYPARAM0_REF_LOSLEVEL;
writel(reg, phy_drd->reg_phy + EXYNOS5_DRD_PHYPARAM0);
reg = readl(phy_drd->reg_phy + EXYNOS5_DRD_PHYPARAM1);
reg &= ~PHYPARAM1_PCS_TXDEEMPH_MASK;
reg |= PHYPARAM1_PCS_TXDEEMPH;
writel(reg, phy_drd->reg_phy + EXYNOS5_DRD_PHYPARAM1);
writel(PHYUTMI_OTGDISABLE, phy_drd->reg_phy + EXYNOS5_DRD_PHYUTMI);
reg = readl(phy_drd->reg_phy + EXYNOS5_DRD_PHYTEST);
reg &= ~PHYTEST_POWERDOWN_HSP;
writel(reg, phy_drd->reg_phy + EXYNOS5_DRD_PHYTEST);
}
static int exynos5_usbdrd_phy_init(struct phy *phy)
{
int ret;
u32 reg;
struct phy_usb_instance *inst = phy_get_drvdata(phy);
struct exynos5_usbdrd_phy *phy_drd = to_usbdrd_phy(inst);
ret = clk_prepare_enable(phy_drd->clk);
if (ret)
return ret;
writel(0x0, phy_drd->reg_phy + EXYNOS5_DRD_PHYREG0);
writel(0x0, phy_drd->reg_phy + EXYNOS5_DRD_PHYRESUME);
reg = LINKSYSTEM_XHCI_VERSION_CONTROL |
LINKSYSTEM_FLADJ(0x20);
writel(reg, phy_drd->reg_phy + EXYNOS5_DRD_LINKSYSTEM);
reg = readl(phy_drd->reg_phy + EXYNOS5_DRD_PHYPARAM0);
reg &= ~PHYPARAM0_REF_USE_PAD;
writel(reg, phy_drd->reg_phy + EXYNOS5_DRD_PHYPARAM0);
reg = readl(phy_drd->reg_phy + EXYNOS5_DRD_PHYUTMICLKSEL);
reg |= PHYUTMICLKSEL_UTMI_CLKSEL;
writel(reg, phy_drd->reg_phy + EXYNOS5_DRD_PHYUTMICLKSEL);
inst->phy_cfg->phy_init(phy_drd);
reg = inst->phy_cfg->set_refclk(inst);
reg |= PHYCLKRST_RETENABLEN |
PHYCLKRST_REF_SSP_EN |
PHYCLKRST_SSC_EN |
PHYCLKRST_COMMONONN |
PHYCLKRST_PORTRESET;
writel(reg, phy_drd->reg_phy + EXYNOS5_DRD_PHYCLKRST);
udelay(10);
reg &= ~PHYCLKRST_PORTRESET;
writel(reg, phy_drd->reg_phy + EXYNOS5_DRD_PHYCLKRST);
clk_disable_unprepare(phy_drd->clk);
return 0;
}
static int exynos5_usbdrd_phy_exit(struct phy *phy)
{
int ret;
u32 reg;
struct phy_usb_instance *inst = phy_get_drvdata(phy);
struct exynos5_usbdrd_phy *phy_drd = to_usbdrd_phy(inst);
ret = clk_prepare_enable(phy_drd->clk);
if (ret)
return ret;
reg = PHYUTMI_OTGDISABLE |
PHYUTMI_FORCESUSPEND |
PHYUTMI_FORCESLEEP;
writel(reg, phy_drd->reg_phy + EXYNOS5_DRD_PHYUTMI);
reg = readl(phy_drd->reg_phy + EXYNOS5_DRD_PHYCLKRST);
reg &= ~(PHYCLKRST_REF_SSP_EN |
PHYCLKRST_SSC_EN |
PHYCLKRST_COMMONONN);
writel(reg, phy_drd->reg_phy + EXYNOS5_DRD_PHYCLKRST);
reg = readl(phy_drd->reg_phy + EXYNOS5_DRD_PHYTEST);
reg |= PHYTEST_POWERDOWN_SSP |
PHYTEST_POWERDOWN_HSP;
writel(reg, phy_drd->reg_phy + EXYNOS5_DRD_PHYTEST);
clk_disable_unprepare(phy_drd->clk);
return 0;
}
static int exynos5_usbdrd_phy_power_on(struct phy *phy)
{
int ret;
struct phy_usb_instance *inst = phy_get_drvdata(phy);
struct exynos5_usbdrd_phy *phy_drd = to_usbdrd_phy(inst);
dev_dbg(phy_drd->dev, "Request to power_on usbdrd_phy phy\n");
clk_prepare_enable(phy_drd->ref_clk);
if (phy_drd->vbus) {
ret = regulator_enable(phy_drd->vbus);
if (ret) {
dev_err(phy_drd->dev, "Failed to enable VBUS supply\n");
goto fail_vbus;
}
}
inst->phy_cfg->phy_isol(inst, 0);
return 0;
fail_vbus:
clk_disable_unprepare(phy_drd->ref_clk);
return ret;
}
static int exynos5_usbdrd_phy_power_off(struct phy *phy)
{
struct phy_usb_instance *inst = phy_get_drvdata(phy);
struct exynos5_usbdrd_phy *phy_drd = to_usbdrd_phy(inst);
dev_dbg(phy_drd->dev, "Request to power_off usbdrd_phy phy\n");
inst->phy_cfg->phy_isol(inst, 1);
if (phy_drd->vbus)
regulator_disable(phy_drd->vbus);
clk_disable_unprepare(phy_drd->ref_clk);
return 0;
}
static struct phy *exynos5_usbdrd_phy_xlate(struct device *dev,
struct of_phandle_args *args)
{
struct exynos5_usbdrd_phy *phy_drd = dev_get_drvdata(dev);
if (WARN_ON(args->args[0] > EXYNOS5_DRDPHYS_NUM))
return ERR_PTR(-ENODEV);
return phy_drd->phys[args->args[0]].phy;
}
static int exynos5_usbdrd_phy_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct device_node *node = dev->of_node;
struct exynos5_usbdrd_phy *phy_drd;
struct phy_provider *phy_provider;
struct resource *res;
const struct of_device_id *match;
const struct exynos5_usbdrd_phy_drvdata *drv_data;
struct regmap *reg_pmu;
u32 pmu_offset;
unsigned long ref_rate;
int i, ret;
int channel;
phy_drd = devm_kzalloc(dev, sizeof(*phy_drd), GFP_KERNEL);
if (!phy_drd)
return -ENOMEM;
dev_set_drvdata(dev, phy_drd);
phy_drd->dev = dev;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
phy_drd->reg_phy = devm_ioremap_resource(dev, res);
if (IS_ERR(phy_drd->reg_phy))
return PTR_ERR(phy_drd->reg_phy);
match = of_match_node(exynos5_usbdrd_phy_of_match, pdev->dev.of_node);
drv_data = match->data;
phy_drd->drv_data = drv_data;
phy_drd->clk = devm_clk_get(dev, "phy");
if (IS_ERR(phy_drd->clk)) {
dev_err(dev, "Failed to get clock of phy controller\n");
return PTR_ERR(phy_drd->clk);
}
phy_drd->ref_clk = devm_clk_get(dev, "ref");
if (IS_ERR(phy_drd->ref_clk)) {
dev_err(dev, "Failed to get reference clock of usbdrd phy\n");
return PTR_ERR(phy_drd->ref_clk);
}
ref_rate = clk_get_rate(phy_drd->ref_clk);
ret = exynos5_rate_to_clk(ref_rate, &phy_drd->extrefclk);
if (ret) {
dev_err(phy_drd->dev, "Clock rate (%ld) not supported\n",
ref_rate);
return ret;
}
reg_pmu = syscon_regmap_lookup_by_phandle(dev->of_node,
"samsung,pmu-syscon");
if (IS_ERR(reg_pmu)) {
dev_err(dev, "Failed to lookup PMU regmap\n");
return PTR_ERR(reg_pmu);
}
channel = of_alias_get_id(node, "usbdrdphy");
if (channel < 0)
dev_dbg(dev, "Not a multi-controller usbdrd phy\n");
switch (channel) {
case 1:
pmu_offset = phy_drd->drv_data->pmu_offset_usbdrd1_phy;
break;
case 0:
default:
pmu_offset = phy_drd->drv_data->pmu_offset_usbdrd0_phy;
break;
}
phy_drd->vbus = devm_regulator_get(dev, "vbus");
if (IS_ERR(phy_drd->vbus)) {
ret = PTR_ERR(phy_drd->vbus);
if (ret == -EPROBE_DEFER)
return ret;
dev_warn(dev, "Failed to get VBUS supply regulator\n");
phy_drd->vbus = NULL;
}
dev_vdbg(dev, "Creating usbdrd_phy phy\n");
for (i = 0; i < EXYNOS5_DRDPHYS_NUM; i++) {
struct phy *phy = devm_phy_create(dev, &exynos5_usbdrd_phy_ops,
NULL);
if (IS_ERR(phy)) {
dev_err(dev, "Failed to create usbdrd_phy phy\n");
return PTR_ERR(phy);
}
phy_drd->phys[i].phy = phy;
phy_drd->phys[i].index = i;
phy_drd->phys[i].reg_pmu = reg_pmu;
phy_drd->phys[i].pmu_offset = pmu_offset;
phy_drd->phys[i].phy_cfg = &drv_data->phy_cfg[i];
phy_set_drvdata(phy, &phy_drd->phys[i]);
}
phy_provider = devm_of_phy_provider_register(dev,
exynos5_usbdrd_phy_xlate);
if (IS_ERR(phy_provider)) {
dev_err(phy_drd->dev, "Failed to register phy provider\n");
return PTR_ERR(phy_provider);
}
return 0;
}
