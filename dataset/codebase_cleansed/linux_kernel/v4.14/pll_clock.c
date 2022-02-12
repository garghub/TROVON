static inline void axs10x_pll_write(struct axs10x_pll_clk *clk, u32 reg,
u32 val)
{
iowrite32(val, clk->base + reg);
}
static inline u32 axs10x_pll_read(struct axs10x_pll_clk *clk, u32 reg)
{
return ioread32(clk->base + reg);
}
static inline struct axs10x_pll_clk *to_axs10x_pll_clk(struct clk_hw *hw)
{
return container_of(hw, struct axs10x_pll_clk, hw);
}
static inline u32 axs10x_div_get_value(u32 reg)
{
if (PLL_REG_GET_BYPASS(reg))
return 1;
return PLL_REG_GET_HIGH(reg) + PLL_REG_GET_LOW(reg);
}
static inline u32 axs10x_encode_div(unsigned int id, int upd)
{
u32 div = 0;
PLL_REG_SET_LOW(div, (id % 2 == 0) ? id >> 1 : (id >> 1) + 1);
PLL_REG_SET_HIGH(div, id >> 1);
PLL_REG_SET_EDGE(div, id % 2);
PLL_REG_SET_BYPASS(div, id == 1 ? 1 : 0);
PLL_REG_SET_NOUPD(div, upd == 0 ? 1 : 0);
return div;
}
static unsigned long axs10x_pll_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
u64 rate;
u32 idiv, fbdiv, odiv;
struct axs10x_pll_clk *clk = to_axs10x_pll_clk(hw);
idiv = axs10x_div_get_value(axs10x_pll_read(clk, PLL_REG_IDIV));
fbdiv = axs10x_div_get_value(axs10x_pll_read(clk, PLL_REG_FBDIV));
odiv = axs10x_div_get_value(axs10x_pll_read(clk, PLL_REG_ODIV));
rate = (u64)parent_rate * fbdiv;
do_div(rate, idiv * odiv);
return rate;
}
static long axs10x_pll_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *prate)
{
int i;
long best_rate;
struct axs10x_pll_clk *clk = to_axs10x_pll_clk(hw);
const struct axs10x_pll_cfg *pll_cfg = clk->pll_cfg;
if (pll_cfg[0].rate == 0)
return -EINVAL;
best_rate = pll_cfg[0].rate;
for (i = 1; pll_cfg[i].rate != 0; i++) {
if (abs(rate - pll_cfg[i].rate) < abs(rate - best_rate))
best_rate = pll_cfg[i].rate;
}
return best_rate;
}
static int axs10x_pll_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
int i;
struct axs10x_pll_clk *clk = to_axs10x_pll_clk(hw);
const struct axs10x_pll_cfg *pll_cfg = clk->pll_cfg;
for (i = 0; pll_cfg[i].rate != 0; i++) {
if (pll_cfg[i].rate == rate) {
axs10x_pll_write(clk, PLL_REG_IDIV,
axs10x_encode_div(pll_cfg[i].idiv, 0));
axs10x_pll_write(clk, PLL_REG_FBDIV,
axs10x_encode_div(pll_cfg[i].fbdiv, 0));
axs10x_pll_write(clk, PLL_REG_ODIV,
axs10x_encode_div(pll_cfg[i].odiv, 1));
udelay(PLL_MAX_LOCK_TIME);
if (!(ioread32(clk->lock) & PLL_LOCK))
return -ETIMEDOUT;
if (ioread32(clk->lock) & PLL_ERROR)
return -EINVAL;
return 0;
}
}
dev_err(clk->dev, "invalid rate=%ld, parent_rate=%ld\n", rate,
parent_rate);
return -EINVAL;
}
static int axs10x_pll_clk_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
const char *parent_name;
struct axs10x_pll_clk *pll_clk;
struct resource *mem;
struct clk_init_data init = { };
int ret;
pll_clk = devm_kzalloc(dev, sizeof(*pll_clk), GFP_KERNEL);
if (!pll_clk)
return -ENOMEM;
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
pll_clk->base = devm_ioremap_resource(dev, mem);
if (IS_ERR(pll_clk->base))
return PTR_ERR(pll_clk->base);
mem = platform_get_resource(pdev, IORESOURCE_MEM, 1);
pll_clk->lock = devm_ioremap_resource(dev, mem);
if (IS_ERR(pll_clk->lock))
return PTR_ERR(pll_clk->lock);
init.name = dev->of_node->name;
init.ops = &axs10x_pll_ops;
parent_name = of_clk_get_parent_name(dev->of_node, 0);
init.parent_names = &parent_name;
init.num_parents = 1;
pll_clk->hw.init = &init;
pll_clk->dev = dev;
pll_clk->pll_cfg = of_device_get_match_data(dev);
if (!pll_clk->pll_cfg) {
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
static int axs10x_pll_clk_remove(struct platform_device *pdev)
{
of_clk_del_provider(pdev->dev.of_node);
return 0;
}
static void __init of_axs10x_pll_clk_setup(struct device_node *node)
{
const char *parent_name;
struct axs10x_pll_clk *pll_clk;
struct clk_init_data init = { };
int ret;
pll_clk = kzalloc(sizeof(*pll_clk), GFP_KERNEL);
if (!pll_clk)
return;
pll_clk->base = of_iomap(node, 0);
if (!pll_clk->base) {
pr_err("failed to map pll div registers\n");
goto err_free_pll_clk;
}
pll_clk->lock = of_iomap(node, 1);
if (!pll_clk->lock) {
pr_err("failed to map pll lock register\n");
goto err_unmap_base;
}
init.name = node->name;
init.ops = &axs10x_pll_ops;
parent_name = of_clk_get_parent_name(node, 0);
init.parent_names = &parent_name;
init.num_parents = parent_name ? 1 : 0;
pll_clk->hw.init = &init;
pll_clk->pll_cfg = arc_pll_cfg;
ret = clk_hw_register(NULL, &pll_clk->hw);
if (ret) {
pr_err("failed to register %s clock\n", node->name);
goto err_unmap_lock;
}
ret = of_clk_add_hw_provider(node, of_clk_hw_simple_get, &pll_clk->hw);
if (ret) {
pr_err("failed to add hw provider for %s clock\n", node->name);
goto err_unregister_clk;
}
return;
err_unregister_clk:
clk_hw_unregister(&pll_clk->hw);
err_unmap_lock:
iounmap(pll_clk->lock);
err_unmap_base:
iounmap(pll_clk->base);
err_free_pll_clk:
kfree(pll_clk);
}
