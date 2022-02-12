static inline void qusb2_setbits(void __iomem *base, u32 offset, u32 val)
{
u32 reg;
reg = readl(base + offset);
reg |= val;
writel(reg, base + offset);
readl(base + offset);
}
static inline void qusb2_clrbits(void __iomem *base, u32 offset, u32 val)
{
u32 reg;
reg = readl(base + offset);
reg &= ~val;
writel(reg, base + offset);
readl(base + offset);
}
static inline
void qcom_qusb2_phy_configure(void __iomem *base,
const struct qusb2_phy_init_tbl tbl[], int num)
{
int i;
for (i = 0; i < num; i++)
writel(tbl[i].val, base + tbl[i].offset);
}
static void qusb2_phy_set_tune2_param(struct qusb2_phy *qphy)
{
struct device *dev = &qphy->phy->dev;
u8 *val;
val = nvmem_cell_read(qphy->cell, NULL);
if (IS_ERR(val) || !val[0]) {
dev_dbg(dev, "failed to read a valid hs-tx trim value\n");
return;
}
qusb2_setbits(qphy->base, QUSB2PHY_PORT_TUNE2, val[0] << 0x4);
}
static int qusb2_phy_poweron(struct phy *phy)
{
struct qusb2_phy *qphy = phy_get_drvdata(phy);
int num = ARRAY_SIZE(qphy->vregs);
int ret;
dev_vdbg(&phy->dev, "%s(): Powering-on QUSB2 phy\n", __func__);
ret = regulator_bulk_enable(num, qphy->vregs);
if (ret)
return ret;
ret = clk_prepare_enable(qphy->iface_clk);
if (ret) {
dev_err(&phy->dev, "failed to enable iface_clk, %d\n", ret);
regulator_bulk_disable(num, qphy->vregs);
return ret;
}
return 0;
}
static int qusb2_phy_poweroff(struct phy *phy)
{
struct qusb2_phy *qphy = phy_get_drvdata(phy);
clk_disable_unprepare(qphy->iface_clk);
regulator_bulk_disable(ARRAY_SIZE(qphy->vregs), qphy->vregs);
return 0;
}
static int qusb2_phy_init(struct phy *phy)
{
struct qusb2_phy *qphy = phy_get_drvdata(phy);
unsigned int val;
unsigned int clk_scheme;
int ret;
dev_vdbg(&phy->dev, "%s(): Initializing QUSB2 phy\n", __func__);
ret = clk_prepare_enable(qphy->cfg_ahb_clk);
if (ret) {
dev_err(&phy->dev, "failed to enable cfg ahb clock, %d\n", ret);
return ret;
}
ret = reset_control_assert(qphy->phy_reset);
if (ret) {
dev_err(&phy->dev, "failed to assert phy_reset, %d\n", ret);
goto disable_ahb_clk;
}
usleep_range(100, 150);
ret = reset_control_deassert(qphy->phy_reset);
if (ret) {
dev_err(&phy->dev, "failed to de-assert phy_reset, %d\n", ret);
goto disable_ahb_clk;
}
qusb2_setbits(qphy->base, QUSB2PHY_PORT_POWERDOWN,
CLAMP_N_EN | FREEZIO_N | POWER_DOWN);
val = readl(qphy->base + QUSB2PHY_PLL_TEST);
qcom_qusb2_phy_configure(qphy->base, qphy->cfg->tbl,
qphy->cfg->tbl_num);
qusb2_phy_set_tune2_param(qphy);
qusb2_clrbits(qphy->base, QUSB2PHY_PORT_POWERDOWN, POWER_DOWN);
usleep_range(150, 160);
qphy->has_se_clk_scheme = true;
if (qphy->tcsr) {
ret = regmap_read(qphy->tcsr, qphy->cfg->clk_scheme_offset,
&clk_scheme);
if (ret) {
dev_err(&phy->dev, "failed to read clk scheme reg\n");
goto assert_phy_reset;
}
if (!(clk_scheme & PHY_CLK_SCHEME_SEL)) {
dev_vdbg(&phy->dev, "%s(): select differential clk\n",
__func__);
qphy->has_se_clk_scheme = false;
} else {
dev_vdbg(&phy->dev, "%s(): select single-ended clk\n",
__func__);
}
}
if (!qphy->has_se_clk_scheme) {
val &= ~CLK_REF_SEL;
ret = clk_prepare_enable(qphy->ref_clk);
if (ret) {
dev_err(&phy->dev, "failed to enable ref clk, %d\n",
ret);
goto assert_phy_reset;
}
} else {
val |= CLK_REF_SEL;
}
writel(val, qphy->base + QUSB2PHY_PLL_TEST);
readl(qphy->base + QUSB2PHY_PLL_TEST);
usleep_range(100, 110);
val = readb(qphy->base + QUSB2PHY_PLL_STATUS);
if (!(val & PLL_LOCKED)) {
dev_err(&phy->dev,
"QUSB2PHY pll lock failed: status reg = %x\n", val);
ret = -EBUSY;
goto disable_ref_clk;
}
return 0;
disable_ref_clk:
if (!qphy->has_se_clk_scheme)
clk_disable_unprepare(qphy->ref_clk);
assert_phy_reset:
reset_control_assert(qphy->phy_reset);
disable_ahb_clk:
clk_disable_unprepare(qphy->cfg_ahb_clk);
return ret;
}
static int qusb2_phy_exit(struct phy *phy)
{
struct qusb2_phy *qphy = phy_get_drvdata(phy);
qusb2_setbits(qphy->base, QUSB2PHY_PORT_POWERDOWN,
CLAMP_N_EN | FREEZIO_N | POWER_DOWN);
if (!qphy->has_se_clk_scheme)
clk_disable_unprepare(qphy->ref_clk);
reset_control_assert(qphy->phy_reset);
clk_disable_unprepare(qphy->cfg_ahb_clk);
return 0;
}
static int qusb2_phy_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct qusb2_phy *qphy;
struct phy_provider *phy_provider;
struct phy *generic_phy;
struct resource *res;
int ret, i;
int num;
qphy = devm_kzalloc(dev, sizeof(*qphy), GFP_KERNEL);
if (!qphy)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
qphy->base = devm_ioremap_resource(dev, res);
if (IS_ERR(qphy->base))
return PTR_ERR(qphy->base);
qphy->cfg_ahb_clk = devm_clk_get(dev, "cfg_ahb");
if (IS_ERR(qphy->cfg_ahb_clk)) {
ret = PTR_ERR(qphy->cfg_ahb_clk);
if (ret != -EPROBE_DEFER)
dev_err(dev, "failed to get cfg ahb clk, %d\n", ret);
return ret;
}
qphy->ref_clk = devm_clk_get(dev, "ref");
if (IS_ERR(qphy->ref_clk)) {
ret = PTR_ERR(qphy->ref_clk);
if (ret != -EPROBE_DEFER)
dev_err(dev, "failed to get ref clk, %d\n", ret);
return ret;
}
qphy->iface_clk = devm_clk_get(dev, "iface");
if (IS_ERR(qphy->iface_clk)) {
ret = PTR_ERR(qphy->iface_clk);
if (ret == -EPROBE_DEFER)
return ret;
qphy->iface_clk = NULL;
dev_dbg(dev, "failed to get iface clk, %d\n", ret);
}
qphy->phy_reset = devm_reset_control_get_by_index(&pdev->dev, 0);
if (IS_ERR(qphy->phy_reset)) {
dev_err(dev, "failed to get phy core reset\n");
return PTR_ERR(qphy->phy_reset);
}
num = ARRAY_SIZE(qphy->vregs);
for (i = 0; i < num; i++)
qphy->vregs[i].supply = qusb2_phy_vreg_names[i];
ret = devm_regulator_bulk_get(dev, num, qphy->vregs);
if (ret) {
dev_err(dev, "failed to get regulator supplies\n");
return ret;
}
qphy->cfg = of_device_get_match_data(dev);
qphy->tcsr = syscon_regmap_lookup_by_phandle(dev->of_node,
"qcom,tcsr-syscon");
if (IS_ERR(qphy->tcsr)) {
dev_dbg(dev, "failed to lookup TCSR regmap\n");
qphy->tcsr = NULL;
}
qphy->cell = devm_nvmem_cell_get(dev, NULL);
if (IS_ERR(qphy->cell)) {
if (PTR_ERR(qphy->cell) == -EPROBE_DEFER)
return -EPROBE_DEFER;
qphy->cell = NULL;
dev_dbg(dev, "failed to lookup tune2 hstx trim value\n");
}
generic_phy = devm_phy_create(dev, NULL, &qusb2_phy_gen_ops);
if (IS_ERR(generic_phy)) {
ret = PTR_ERR(generic_phy);
dev_err(dev, "failed to create phy, %d\n", ret);
return ret;
}
qphy->phy = generic_phy;
dev_set_drvdata(dev, qphy);
phy_set_drvdata(generic_phy, qphy);
phy_provider = devm_of_phy_provider_register(dev, of_phy_simple_xlate);
if (!IS_ERR(phy_provider))
dev_info(dev, "Registered Qcom-QUSB2 phy\n");
return PTR_ERR_OR_ZERO(phy_provider);
}
