static inline void hsdk_pll_write(struct hsdk_pll_clk *clk, u32 reg, u32 val)
{
iowrite32(val, clk->regs + reg);
}
static inline u32 hsdk_pll_read(struct hsdk_pll_clk *clk, u32 reg)
{
return ioread32(clk->regs + reg);
}
static inline void hsdk_pll_set_cfg(struct hsdk_pll_clk *clk,
const struct hsdk_pll_cfg *cfg)
{
u32 val = 0;
val |= cfg->idiv << CGU_PLL_CTRL_IDIV_SHIFT;
val |= cfg->fbdiv << CGU_PLL_CTRL_FBDIV_SHIFT;
val |= cfg->odiv << CGU_PLL_CTRL_ODIV_SHIFT;
val |= cfg->band << CGU_PLL_CTRL_BAND_SHIFT;
dev_dbg(clk->dev, "write configurarion: %#x\n", val);
hsdk_pll_write(clk, CGU_PLL_CTRL, val);
}
static inline bool hsdk_pll_is_locked(struct hsdk_pll_clk *clk)
{
return !!(hsdk_pll_read(clk, CGU_PLL_STATUS) & CGU_PLL_STATUS_LOCK);
}
static inline bool hsdk_pll_is_err(struct hsdk_pll_clk *clk)
{
return !!(hsdk_pll_read(clk, CGU_PLL_STATUS) & CGU_PLL_STATUS_ERR);
}
static inline struct hsdk_pll_clk *to_hsdk_pll_clk(struct clk_hw *hw)
{
return container_of(hw, struct hsdk_pll_clk, hw);
}
static unsigned long hsdk_pll_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
u32 val;
u64 rate;
u32 idiv, fbdiv, odiv;
struct hsdk_pll_clk *clk = to_hsdk_pll_clk(hw);
val = hsdk_pll_read(clk, CGU_PLL_CTRL);
dev_dbg(clk->dev, "current configurarion: %#x\n", val);
if (val & CGU_PLL_CTRL_PD)
return 0;
if (val & CGU_PLL_CTRL_BYPASS)
return parent_rate;
idiv = 1 + ((val & CGU_PLL_CTRL_IDIV_MASK) >> CGU_PLL_CTRL_IDIV_SHIFT);
fbdiv = 2 * (1 + ((val & CGU_PLL_CTRL_FBDIV_MASK) >> CGU_PLL_CTRL_FBDIV_SHIFT));
odiv = 1 << ((val & CGU_PLL_CTRL_ODIV_MASK) >> CGU_PLL_CTRL_ODIV_SHIFT);
rate = (u64)parent_rate * fbdiv;
do_div(rate, idiv * odiv);
return rate;
}
static long hsdk_pll_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *prate)
{
int i;
unsigned long best_rate;
struct hsdk_pll_clk *clk = to_hsdk_pll_clk(hw);
const struct hsdk_pll_cfg *pll_cfg = clk->pll_devdata->pll_cfg;
if (pll_cfg[0].rate == 0)
return -EINVAL;
best_rate = pll_cfg[0].rate;
for (i = 1; pll_cfg[i].rate != 0; i++) {
if (abs(rate - pll_cfg[i].rate) < abs(rate - best_rate))
best_rate = pll_cfg[i].rate;
}
dev_dbg(clk->dev, "chosen best rate: %lu\n", best_rate);
return best_rate;
}
static int hsdk_pll_comm_update_rate(struct hsdk_pll_clk *clk,
unsigned long rate,
const struct hsdk_pll_cfg *cfg)
{
hsdk_pll_set_cfg(clk, cfg);
udelay(HSDK_PLL_MAX_LOCK_TIME);
if (!hsdk_pll_is_locked(clk))
return -ETIMEDOUT;
if (hsdk_pll_is_err(clk))
return -EINVAL;
return 0;
}
static int hsdk_pll_core_update_rate(struct hsdk_pll_clk *clk,
unsigned long rate,
const struct hsdk_pll_cfg *cfg)
{
if (rate > CORE_IF_CLK_THRESHOLD_HZ)
iowrite32(CREG_CORE_IF_CLK_DIV_2, clk->spec_regs);
hsdk_pll_set_cfg(clk, cfg);
udelay(HSDK_PLL_MAX_LOCK_TIME);
if (!hsdk_pll_is_locked(clk))
return -ETIMEDOUT;
if (hsdk_pll_is_err(clk))
return -EINVAL;
if (rate <= CORE_IF_CLK_THRESHOLD_HZ)
iowrite32(CREG_CORE_IF_CLK_DIV_1, clk->spec_regs);
return 0;
}
static int hsdk_pll_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
int i;
struct hsdk_pll_clk *clk = to_hsdk_pll_clk(hw);
const struct hsdk_pll_cfg *pll_cfg = clk->pll_devdata->pll_cfg;
for (i = 0; pll_cfg[i].rate != 0; i++) {
if (pll_cfg[i].rate == rate) {
return clk->pll_devdata->update_rate(clk, rate,
&pll_cfg[i]);
}
}
dev_err(clk->dev, "invalid rate=%ld, parent_rate=%ld\n", rate,
parent_rate);
return -EINVAL;
}
static int hsdk_pll_clk_probe(struct platform_device *pdev)
{
int ret;
struct resource *mem;
const char *parent_name;
unsigned int num_parents;
struct hsdk_pll_clk *pll_clk;
struct clk_init_data init = { };
struct device *dev = &pdev->dev;
pll_clk = devm_kzalloc(dev, sizeof(*pll_clk), GFP_KERNEL);
if (!pll_clk)
return -ENOMEM;
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
pll_clk->regs = devm_ioremap_resource(dev, mem);
if (IS_ERR(pll_clk->regs))
return PTR_ERR(pll_clk->regs);
init.name = dev->of_node->name;
init.ops = &hsdk_pll_ops;
parent_name = of_clk_get_parent_name(dev->of_node, 0);
init.parent_names = &parent_name;
num_parents = of_clk_get_parent_count(dev->of_node);
if (num_parents == 0 || num_parents > CGU_PLL_SOURCE_MAX) {
dev_err(dev, "wrong clock parents number: %u\n", num_parents);
return -EINVAL;
}
init.num_parents = num_parents;
pll_clk->hw.init = &init;
pll_clk->dev = dev;
pll_clk->pll_devdata = of_device_get_match_data(dev);
if (!pll_clk->pll_devdata) {
dev_err(dev, "No OF match data provided\n");
return -EINVAL;
}
ret = devm_clk_hw_register(dev, &pll_clk->hw);
if (ret) {
dev_err(dev, "failed to register %s clock\n", init.name);
return ret;
}
return of_clk_add_hw_provider(dev->of_node, of_clk_hw_simple_get,
&pll_clk->hw);
}
static int hsdk_pll_clk_remove(struct platform_device *pdev)
{
of_clk_del_provider(pdev->dev.of_node);
return 0;
}
static void __init of_hsdk_pll_clk_setup(struct device_node *node)
{
int ret;
const char *parent_name;
unsigned int num_parents;
struct hsdk_pll_clk *pll_clk;
struct clk_init_data init = { };
pll_clk = kzalloc(sizeof(*pll_clk), GFP_KERNEL);
if (!pll_clk)
return;
pll_clk->regs = of_iomap(node, 0);
if (!pll_clk->regs) {
pr_err("failed to map pll registers\n");
goto err_free_pll_clk;
}
pll_clk->spec_regs = of_iomap(node, 1);
if (!pll_clk->spec_regs) {
pr_err("failed to map pll registers\n");
goto err_unmap_comm_regs;
}
init.name = node->name;
init.ops = &hsdk_pll_ops;
parent_name = of_clk_get_parent_name(node, 0);
init.parent_names = &parent_name;
num_parents = of_clk_get_parent_count(node);
if (num_parents > CGU_PLL_SOURCE_MAX) {
pr_err("too much clock parents: %u\n", num_parents);
goto err_unmap_spec_regs;
}
init.num_parents = num_parents;
pll_clk->hw.init = &init;
pll_clk->pll_devdata = &core_pll_devdata;
ret = clk_hw_register(NULL, &pll_clk->hw);
if (ret) {
pr_err("failed to register %s clock\n", node->name);
goto err_unmap_spec_regs;
}
ret = of_clk_add_hw_provider(node, of_clk_hw_simple_get, &pll_clk->hw);
if (ret) {
pr_err("failed to add hw provider for %s clock\n", node->name);
goto err_unmap_spec_regs;
}
return;
err_unmap_spec_regs:
iounmap(pll_clk->spec_regs);
err_unmap_comm_regs:
iounmap(pll_clk->regs);
err_free_pll_clk:
kfree(pll_clk);
}
