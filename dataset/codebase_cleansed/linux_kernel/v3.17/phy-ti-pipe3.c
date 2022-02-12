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
struct ti_pipe3 *phy = phy_get_drvdata(x);
omap_control_phy_power(phy->control_dev, 0);
return 0;
}
static int ti_pipe3_power_on(struct phy *x)
{
struct ti_pipe3 *phy = phy_get_drvdata(x);
omap_control_phy_power(phy->control_dev, 1);
return 0;
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
break;
} while (!time_after(jiffies, timeout));
if (!(val & PLL_LOCK)) {
dev_err(phy->dev, "DPLL failed to lock\n");
return -EBUSY;
}
return 0;
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
if (of_device_is_compatible(phy->dev->of_node, "ti,phy-pipe3-pcie")) {
omap_control_pcie_pcs(phy->control_dev, phy->id, 0xF1);
return 0;
}
val = ti_pipe3_readl(phy->pll_ctrl_base, PLL_CONFIGURATION2);
if (val & PLL_IDLE) {
val &= ~PLL_IDLE;
ti_pipe3_writel(phy->pll_ctrl_base, PLL_CONFIGURATION2, val);
ret = ti_pipe3_dpll_wait_lock(phy);
}
val = ti_pipe3_readl(phy->pll_ctrl_base, PLL_STATUS);
if (!(val & PLL_LOCK))
if (ti_pipe3_dpll_program(phy))
return -EINVAL;
return ret;
}
static int ti_pipe3_exit(struct phy *x)
{
struct ti_pipe3 *phy = phy_get_drvdata(x);
u32 val;
unsigned long timeout;
if (of_device_is_compatible(phy->dev->of_node, "ti,phy-pipe3-sata") ||
of_device_is_compatible(phy->dev->of_node, "ti,phy-pipe3-pcie"))
return 0;
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
return 0;
}
static int ti_pipe3_probe(struct platform_device *pdev)
{
struct ti_pipe3 *phy;
struct phy *generic_phy;
struct phy_provider *phy_provider;
struct resource *res;
struct device_node *node = pdev->dev.of_node;
struct device_node *control_node;
struct platform_device *control_pdev;
const struct of_device_id *match;
struct clk *clk;
phy = devm_kzalloc(&pdev->dev, sizeof(*phy), GFP_KERNEL);
if (!phy) {
dev_err(&pdev->dev, "unable to alloc mem for TI PIPE3 PHY\n");
return -ENOMEM;
}
phy->dev = &pdev->dev;
if (!of_device_is_compatible(node, "ti,phy-pipe3-pcie")) {
match = of_match_device(of_match_ptr(ti_pipe3_id_table),
&pdev->dev);
if (!match)
return -EINVAL;
phy->dpll_map = (struct pipe3_dpll_map *)match->data;
if (!phy->dpll_map) {
dev_err(&pdev->dev, "no DPLL data\n");
return -EINVAL;
}
res = platform_get_resource_byname(pdev, IORESOURCE_MEM,
"pll_ctrl");
phy->pll_ctrl_base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(phy->pll_ctrl_base))
return PTR_ERR(phy->pll_ctrl_base);
phy->sys_clk = devm_clk_get(phy->dev, "sysclk");
if (IS_ERR(phy->sys_clk)) {
dev_err(&pdev->dev, "unable to get sysclk\n");
return -EINVAL;
}
}
if (!of_device_is_compatible(node, "ti,phy-pipe3-sata")) {
phy->wkupclk = devm_clk_get(phy->dev, "wkupclk");
if (IS_ERR(phy->wkupclk)) {
dev_err(&pdev->dev, "unable to get wkupclk\n");
return PTR_ERR(phy->wkupclk);
}
phy->refclk = devm_clk_get(phy->dev, "refclk");
if (IS_ERR(phy->refclk)) {
dev_err(&pdev->dev, "unable to get refclk\n");
return PTR_ERR(phy->refclk);
}
} else {
phy->wkupclk = ERR_PTR(-ENODEV);
phy->refclk = ERR_PTR(-ENODEV);
}
if (of_device_is_compatible(node, "ti,phy-pipe3-pcie")) {
if (of_property_read_u8(node, "id", &phy->id) < 0)
phy->id = 1;
clk = devm_clk_get(phy->dev, "dpll_ref");
if (IS_ERR(clk)) {
dev_err(&pdev->dev, "unable to get dpll ref clk\n");
return PTR_ERR(clk);
}
clk_set_rate(clk, 1500000000);
clk = devm_clk_get(phy->dev, "dpll_ref_m2");
if (IS_ERR(clk)) {
dev_err(&pdev->dev, "unable to get dpll ref m2 clk\n");
return PTR_ERR(clk);
}
clk_set_rate(clk, 100000000);
clk = devm_clk_get(phy->dev, "phy-div");
if (IS_ERR(clk)) {
dev_err(&pdev->dev, "unable to get phy-div clk\n");
return PTR_ERR(clk);
}
clk_set_rate(clk, 100000000);
phy->div_clk = devm_clk_get(phy->dev, "div-clk");
if (IS_ERR(phy->div_clk)) {
dev_err(&pdev->dev, "unable to get div-clk\n");
return PTR_ERR(phy->div_clk);
}
} else {
phy->div_clk = ERR_PTR(-ENODEV);
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
omap_control_phy_power(phy->control_dev, 0);
platform_set_drvdata(pdev, phy);
pm_runtime_enable(phy->dev);
generic_phy = devm_phy_create(phy->dev, NULL, &ops, NULL);
if (IS_ERR(generic_phy))
return PTR_ERR(generic_phy);
phy_set_drvdata(generic_phy, phy);
phy_provider = devm_of_phy_provider_register(phy->dev,
of_phy_simple_xlate);
if (IS_ERR(phy_provider))
return PTR_ERR(phy_provider);
pm_runtime_get(&pdev->dev);
return 0;
}
static int ti_pipe3_remove(struct platform_device *pdev)
{
if (!pm_runtime_suspended(&pdev->dev))
pm_runtime_put(&pdev->dev);
pm_runtime_disable(&pdev->dev);
return 0;
}
static int ti_pipe3_runtime_suspend(struct device *dev)
{
struct ti_pipe3 *phy = dev_get_drvdata(dev);
if (!IS_ERR(phy->wkupclk))
clk_disable_unprepare(phy->wkupclk);
if (!IS_ERR(phy->refclk))
clk_disable_unprepare(phy->refclk);
if (!IS_ERR(phy->div_clk))
clk_disable_unprepare(phy->div_clk);
return 0;
}
static int ti_pipe3_runtime_resume(struct device *dev)
{
u32 ret = 0;
struct ti_pipe3 *phy = dev_get_drvdata(dev);
if (!IS_ERR(phy->refclk)) {
ret = clk_prepare_enable(phy->refclk);
if (ret) {
dev_err(phy->dev, "Failed to enable refclk %d\n", ret);
goto err1;
}
}
if (!IS_ERR(phy->wkupclk)) {
ret = clk_prepare_enable(phy->wkupclk);
if (ret) {
dev_err(phy->dev, "Failed to enable wkupclk %d\n", ret);
goto err2;
}
}
if (!IS_ERR(phy->div_clk)) {
ret = clk_prepare_enable(phy->div_clk);
if (ret) {
dev_err(phy->dev, "Failed to enable div_clk %d\n", ret);
goto err3;
}
}
return 0;
err3:
if (!IS_ERR(phy->wkupclk))
clk_disable_unprepare(phy->wkupclk);
err2:
if (!IS_ERR(phy->refclk))
clk_disable_unprepare(phy->refclk);
err1:
return ret;
}
