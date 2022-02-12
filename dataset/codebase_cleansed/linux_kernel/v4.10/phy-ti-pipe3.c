static inline u32 ti_pipe3_readl(void __iomem *addr, unsigned offset)
{
return __raw_readl(addr + offset);
}
static inline void ti_pipe3_writel(void __iomem *addr, unsigned offset,
u32 data)
{
__raw_writel(data, addr + offset);
}
static struct pipe3_dpll_params *ti_pipe3_get_dpll_params(struct ti_pipe3 *phy)
{
unsigned long rate;
struct pipe3_dpll_map *dpll_map = phy->dpll_map;
rate = clk_get_rate(phy->sys_clk);
for (; dpll_map->rate; dpll_map++) {
if (rate == dpll_map->rate)
return &dpll_map->params;
}
dev_err(phy->dev, "No DPLL configuration for %lu Hz SYS CLK\n", rate);
return NULL;
}
static int ti_pipe3_power_off(struct phy *x)
{
u32 val;
int ret;
struct ti_pipe3 *phy = phy_get_drvdata(x);
if (!phy->phy_power_syscon) {
omap_control_phy_power(phy->control_dev, 0);
return 0;
}
val = PIPE3_PHY_TX_RX_POWEROFF << PIPE3_PHY_PWRCTL_CLK_CMD_SHIFT;
ret = regmap_update_bits(phy->phy_power_syscon, phy->power_reg,
PIPE3_PHY_PWRCTL_CLK_CMD_MASK, val);
return ret;
}
static int ti_pipe3_power_on(struct phy *x)
{
u32 val;
u32 mask;
int ret;
unsigned long rate;
struct ti_pipe3 *phy = phy_get_drvdata(x);
if (!phy->phy_power_syscon) {
omap_control_phy_power(phy->control_dev, 1);
return 0;
}
rate = clk_get_rate(phy->sys_clk);
if (!rate) {
dev_err(phy->dev, "Invalid clock rate\n");
return -EINVAL;
}
rate = rate / 1000000;
mask = OMAP_CTRL_PIPE3_PHY_PWRCTL_CLK_CMD_MASK |
OMAP_CTRL_PIPE3_PHY_PWRCTL_CLK_FREQ_MASK;
val = PIPE3_PHY_TX_RX_POWERON << PIPE3_PHY_PWRCTL_CLK_CMD_SHIFT;
val |= rate << OMAP_CTRL_PIPE3_PHY_PWRCTL_CLK_FREQ_SHIFT;
ret = regmap_update_bits(phy->phy_power_syscon, phy->power_reg,
mask, val);
return ret;
}
static int ti_pipe3_dpll_wait_lock(struct ti_pipe3 *phy)
{
u32 val;
unsigned long timeout;
timeout = jiffies + msecs_to_jiffies(PLL_LOCK_TIME);
do {
cpu_relax();
val = ti_pipe3_readl(phy->pll_ctrl_base, PLL_STATUS);
if (val & PLL_LOCK)
return 0;
} while (!time_after(jiffies, timeout));
dev_err(phy->dev, "DPLL failed to lock\n");
return -EBUSY;
}
static int ti_pipe3_dpll_program(struct ti_pipe3 *phy)
{
u32 val;
struct pipe3_dpll_params *dpll_params;
dpll_params = ti_pipe3_get_dpll_params(phy);
if (!dpll_params)
return -EINVAL;
val = ti_pipe3_readl(phy->pll_ctrl_base, PLL_CONFIGURATION1);
val &= ~PLL_REGN_MASK;
val |= dpll_params->n << PLL_REGN_SHIFT;
ti_pipe3_writel(phy->pll_ctrl_base, PLL_CONFIGURATION1, val);
val = ti_pipe3_readl(phy->pll_ctrl_base, PLL_CONFIGURATION2);
val &= ~PLL_SELFREQDCO_MASK;
val |= dpll_params->freq << PLL_SELFREQDCO_SHIFT;
ti_pipe3_writel(phy->pll_ctrl_base, PLL_CONFIGURATION2, val);
val = ti_pipe3_readl(phy->pll_ctrl_base, PLL_CONFIGURATION1);
val &= ~PLL_REGM_MASK;
val |= dpll_params->m << PLL_REGM_SHIFT;
ti_pipe3_writel(phy->pll_ctrl_base, PLL_CONFIGURATION1, val);
val = ti_pipe3_readl(phy->pll_ctrl_base, PLL_CONFIGURATION4);
val &= ~PLL_REGM_F_MASK;
val |= dpll_params->mf << PLL_REGM_F_SHIFT;
ti_pipe3_writel(phy->pll_ctrl_base, PLL_CONFIGURATION4, val);
val = ti_pipe3_readl(phy->pll_ctrl_base, PLL_CONFIGURATION3);
val &= ~PLL_SD_MASK;
val |= dpll_params->sd << PLL_SD_SHIFT;
ti_pipe3_writel(phy->pll_ctrl_base, PLL_CONFIGURATION3, val);
ti_pipe3_writel(phy->pll_ctrl_base, PLL_GO, SET_PLL_GO);
return ti_pipe3_dpll_wait_lock(phy);
}
static int ti_pipe3_init(struct phy *x)
{
struct ti_pipe3 *phy = phy_get_drvdata(x);
u32 val;
int ret = 0;
ti_pipe3_enable_clocks(phy);
if (of_device_is_compatible(phy->dev->of_node, "ti,phy-pipe3-pcie")) {
if (!phy->pcs_syscon) {
omap_control_pcie_pcs(phy->control_dev, 0x96);
return 0;
}
val = 0x96 << OMAP_CTRL_PCIE_PCS_DELAY_COUNT_SHIFT;
ret = regmap_update_bits(phy->pcs_syscon, phy->pcie_pcs_reg,
PCIE_PCS_MASK, val);
return ret;
}
val = ti_pipe3_readl(phy->pll_ctrl_base, PLL_CONFIGURATION2);
if (val & PLL_IDLE) {
val &= ~PLL_IDLE;
ti_pipe3_writel(phy->pll_ctrl_base, PLL_CONFIGURATION2, val);
ret = ti_pipe3_dpll_wait_lock(phy);
}
val = ti_pipe3_readl(phy->pll_ctrl_base, PLL_STATUS);
if ((val & PLL_LOCK) && of_device_is_compatible(phy->dev->of_node,
"ti,phy-pipe3-sata"))
return ret;
ret = ti_pipe3_dpll_program(phy);
if (ret) {
ti_pipe3_disable_clocks(phy);
return -EINVAL;
}
return ret;
}
static int ti_pipe3_exit(struct phy *x)
{
struct ti_pipe3 *phy = phy_get_drvdata(x);
u32 val;
unsigned long timeout;
if (of_device_is_compatible(phy->dev->of_node, "ti,phy-pipe3-sata") &&
!phy->dpll_reset_syscon)
return 0;
if (!of_device_is_compatible(phy->dev->of_node, "ti,phy-pipe3-pcie")) {
val = ti_pipe3_readl(phy->pll_ctrl_base, PLL_CONFIGURATION2);
val |= PLL_IDLE;
ti_pipe3_writel(phy->pll_ctrl_base, PLL_CONFIGURATION2, val);
timeout = jiffies + msecs_to_jiffies(PLL_IDLE_TIME);
do {
cpu_relax();
val = ti_pipe3_readl(phy->pll_ctrl_base, PLL_STATUS);
if ((val & PLL_TICOPWDN) && (val & PLL_LDOPWDN))
break;
} while (!time_after(jiffies, timeout));
if (!(val & PLL_TICOPWDN) || !(val & PLL_LDOPWDN)) {
dev_err(phy->dev, "Failed to power down: PLL_STATUS 0x%x\n",
val);
return -EBUSY;
}
}
if (of_device_is_compatible(phy->dev->of_node, "ti,phy-pipe3-sata")) {
regmap_update_bits(phy->dpll_reset_syscon, phy->dpll_reset_reg,
SATA_PLL_SOFT_RESET, SATA_PLL_SOFT_RESET);
regmap_update_bits(phy->dpll_reset_syscon, phy->dpll_reset_reg,
SATA_PLL_SOFT_RESET, 0);
}
ti_pipe3_disable_clocks(phy);
return 0;
}
static int ti_pipe3_get_clk(struct ti_pipe3 *phy)
{
struct clk *clk;
struct device *dev = phy->dev;
struct device_node *node = dev->of_node;
phy->refclk = devm_clk_get(dev, "refclk");
if (IS_ERR(phy->refclk)) {
dev_err(dev, "unable to get refclk\n");
if (!of_device_is_compatible(node, "ti,phy-pipe3-sata"))
return PTR_ERR(phy->refclk);
}
if (!of_device_is_compatible(node, "ti,phy-pipe3-sata")) {
phy->wkupclk = devm_clk_get(dev, "wkupclk");
if (IS_ERR(phy->wkupclk)) {
dev_err(dev, "unable to get wkupclk\n");
return PTR_ERR(phy->wkupclk);
}
} else {
phy->wkupclk = ERR_PTR(-ENODEV);
}
if (!of_device_is_compatible(node, "ti,phy-pipe3-pcie") ||
phy->phy_power_syscon) {
phy->sys_clk = devm_clk_get(dev, "sysclk");
if (IS_ERR(phy->sys_clk)) {
dev_err(dev, "unable to get sysclk\n");
return -EINVAL;
}
}
if (of_device_is_compatible(node, "ti,phy-pipe3-pcie")) {
clk = devm_clk_get(dev, "dpll_ref");
if (IS_ERR(clk)) {
dev_err(dev, "unable to get dpll ref clk\n");
return PTR_ERR(clk);
}
clk_set_rate(clk, 1500000000);
clk = devm_clk_get(dev, "dpll_ref_m2");
if (IS_ERR(clk)) {
dev_err(dev, "unable to get dpll ref m2 clk\n");
return PTR_ERR(clk);
}
clk_set_rate(clk, 100000000);
clk = devm_clk_get(dev, "phy-div");
if (IS_ERR(clk)) {
dev_err(dev, "unable to get phy-div clk\n");
return PTR_ERR(clk);
}
clk_set_rate(clk, 100000000);
phy->div_clk = devm_clk_get(dev, "div-clk");
if (IS_ERR(phy->div_clk)) {
dev_err(dev, "unable to get div-clk\n");
return PTR_ERR(phy->div_clk);
}
} else {
phy->div_clk = ERR_PTR(-ENODEV);
}
return 0;
}
static int ti_pipe3_get_sysctrl(struct ti_pipe3 *phy)
{
struct device *dev = phy->dev;
struct device_node *node = dev->of_node;
struct device_node *control_node;
struct platform_device *control_pdev;
phy->phy_power_syscon = syscon_regmap_lookup_by_phandle(node,
"syscon-phy-power");
if (IS_ERR(phy->phy_power_syscon)) {
dev_dbg(dev,
"can't get syscon-phy-power, using control device\n");
phy->phy_power_syscon = NULL;
} else {
if (of_property_read_u32_index(node,
"syscon-phy-power", 1,
&phy->power_reg)) {
dev_err(dev, "couldn't get power reg. offset\n");
return -EINVAL;
}
}
if (!phy->phy_power_syscon) {
control_node = of_parse_phandle(node, "ctrl-module", 0);
if (!control_node) {
dev_err(dev, "Failed to get control device phandle\n");
return -EINVAL;
}
control_pdev = of_find_device_by_node(control_node);
if (!control_pdev) {
dev_err(dev, "Failed to get control device\n");
return -EINVAL;
}
phy->control_dev = &control_pdev->dev;
}
if (of_device_is_compatible(node, "ti,phy-pipe3-pcie")) {
phy->pcs_syscon = syscon_regmap_lookup_by_phandle(node,
"syscon-pcs");
if (IS_ERR(phy->pcs_syscon)) {
dev_dbg(dev,
"can't get syscon-pcs, using omap control\n");
phy->pcs_syscon = NULL;
} else {
if (of_property_read_u32_index(node,
"syscon-pcs", 1,
&phy->pcie_pcs_reg)) {
dev_err(dev,
"couldn't get pcie pcs reg. offset\n");
return -EINVAL;
}
}
}
if (of_device_is_compatible(node, "ti,phy-pipe3-sata")) {
phy->dpll_reset_syscon = syscon_regmap_lookup_by_phandle(node,
"syscon-pllreset");
if (IS_ERR(phy->dpll_reset_syscon)) {
dev_info(dev,
"can't get syscon-pllreset, sata dpll won't idle\n");
phy->dpll_reset_syscon = NULL;
} else {
if (of_property_read_u32_index(node,
"syscon-pllreset", 1,
&phy->dpll_reset_reg)) {
dev_err(dev,
"couldn't get pllreset reg. offset\n");
return -EINVAL;
}
}
}
return 0;
}
static int ti_pipe3_get_pll_base(struct ti_pipe3 *phy)
{
struct resource *res;
const struct of_device_id *match;
struct device *dev = phy->dev;
struct device_node *node = dev->of_node;
struct platform_device *pdev = to_platform_device(dev);
if (of_device_is_compatible(node, "ti,phy-pipe3-pcie"))
return 0;
match = of_match_device(ti_pipe3_id_table, dev);
if (!match)
return -EINVAL;
phy->dpll_map = (struct pipe3_dpll_map *)match->data;
if (!phy->dpll_map) {
dev_err(dev, "no DPLL data\n");
return -EINVAL;
}
res = platform_get_resource_byname(pdev, IORESOURCE_MEM,
"pll_ctrl");
phy->pll_ctrl_base = devm_ioremap_resource(dev, res);
return PTR_ERR_OR_ZERO(phy->pll_ctrl_base);
}
static int ti_pipe3_probe(struct platform_device *pdev)
{
struct ti_pipe3 *phy;
struct phy *generic_phy;
struct phy_provider *phy_provider;
struct device_node *node = pdev->dev.of_node;
struct device *dev = &pdev->dev;
int ret;
phy = devm_kzalloc(dev, sizeof(*phy), GFP_KERNEL);
if (!phy)
return -ENOMEM;
phy->dev = dev;
ret = ti_pipe3_get_pll_base(phy);
if (ret)
return ret;
ret = ti_pipe3_get_sysctrl(phy);
if (ret)
return ret;
ret = ti_pipe3_get_clk(phy);
if (ret)
return ret;
platform_set_drvdata(pdev, phy);
pm_runtime_enable(dev);
if (of_device_is_compatible(node, "ti,phy-pipe3-sata")) {
if (!IS_ERR(phy->refclk)) {
clk_prepare_enable(phy->refclk);
phy->sata_refclk_enabled = true;
}
}
generic_phy = devm_phy_create(dev, NULL, &ops);
if (IS_ERR(generic_phy))
return PTR_ERR(generic_phy);
phy_set_drvdata(generic_phy, phy);
ti_pipe3_power_off(generic_phy);
phy_provider = devm_of_phy_provider_register(dev, of_phy_simple_xlate);
return PTR_ERR_OR_ZERO(phy_provider);
}
static int ti_pipe3_remove(struct platform_device *pdev)
{
pm_runtime_disable(&pdev->dev);
return 0;
}
static int ti_pipe3_enable_clocks(struct ti_pipe3 *phy)
{
int ret = 0;
if (!IS_ERR(phy->refclk)) {
ret = clk_prepare_enable(phy->refclk);
if (ret) {
dev_err(phy->dev, "Failed to enable refclk %d\n", ret);
return ret;
}
}
if (!IS_ERR(phy->wkupclk)) {
ret = clk_prepare_enable(phy->wkupclk);
if (ret) {
dev_err(phy->dev, "Failed to enable wkupclk %d\n", ret);
goto disable_refclk;
}
}
if (!IS_ERR(phy->div_clk)) {
ret = clk_prepare_enable(phy->div_clk);
if (ret) {
dev_err(phy->dev, "Failed to enable div_clk %d\n", ret);
goto disable_wkupclk;
}
}
return 0;
disable_wkupclk:
if (!IS_ERR(phy->wkupclk))
clk_disable_unprepare(phy->wkupclk);
disable_refclk:
if (!IS_ERR(phy->refclk))
clk_disable_unprepare(phy->refclk);
return ret;
}
static void ti_pipe3_disable_clocks(struct ti_pipe3 *phy)
{
if (!IS_ERR(phy->wkupclk))
clk_disable_unprepare(phy->wkupclk);
if (!IS_ERR(phy->refclk)) {
clk_disable_unprepare(phy->refclk);
if (phy->sata_refclk_enabled) {
clk_disable_unprepare(phy->refclk);
phy->sata_refclk_enabled = false;
}
}
if (!IS_ERR(phy->div_clk))
clk_disable_unprepare(phy->div_clk);
}
