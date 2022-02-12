static int clk_corediv_is_enabled(struct clk_hw *hwclk)
{
struct clk_corediv *corediv = to_corediv_clk(hwclk);
const struct clk_corediv_soc_desc *soc_desc = corediv->soc_desc;
const struct clk_corediv_desc *desc = corediv->desc;
u32 enable_mask = BIT(desc->fieldbit) << soc_desc->enable_bit_offset;
return !!(readl(corediv->reg) & enable_mask);
}
static int clk_corediv_enable(struct clk_hw *hwclk)
{
struct clk_corediv *corediv = to_corediv_clk(hwclk);
const struct clk_corediv_soc_desc *soc_desc = corediv->soc_desc;
const struct clk_corediv_desc *desc = corediv->desc;
unsigned long flags = 0;
u32 reg;
spin_lock_irqsave(&corediv->lock, flags);
reg = readl(corediv->reg);
reg |= (BIT(desc->fieldbit) << soc_desc->enable_bit_offset);
writel(reg, corediv->reg);
spin_unlock_irqrestore(&corediv->lock, flags);
return 0;
}
static void clk_corediv_disable(struct clk_hw *hwclk)
{
struct clk_corediv *corediv = to_corediv_clk(hwclk);
const struct clk_corediv_soc_desc *soc_desc = corediv->soc_desc;
const struct clk_corediv_desc *desc = corediv->desc;
unsigned long flags = 0;
u32 reg;
spin_lock_irqsave(&corediv->lock, flags);
reg = readl(corediv->reg);
reg &= ~(BIT(desc->fieldbit) << soc_desc->enable_bit_offset);
writel(reg, corediv->reg);
spin_unlock_irqrestore(&corediv->lock, flags);
}
static unsigned long clk_corediv_recalc_rate(struct clk_hw *hwclk,
unsigned long parent_rate)
{
struct clk_corediv *corediv = to_corediv_clk(hwclk);
const struct clk_corediv_soc_desc *soc_desc = corediv->soc_desc;
const struct clk_corediv_desc *desc = corediv->desc;
u32 reg, div;
reg = readl(corediv->reg + soc_desc->ratio_offset);
div = (reg >> desc->offset) & desc->mask;
return parent_rate / div;
}
static long clk_corediv_round_rate(struct clk_hw *hwclk, unsigned long rate,
unsigned long *parent_rate)
{
u32 div;
div = *parent_rate / rate;
if (div < 4)
div = 4;
else if (div > 6)
div = 8;
return *parent_rate / div;
}
static int clk_corediv_set_rate(struct clk_hw *hwclk, unsigned long rate,
unsigned long parent_rate)
{
struct clk_corediv *corediv = to_corediv_clk(hwclk);
const struct clk_corediv_soc_desc *soc_desc = corediv->soc_desc;
const struct clk_corediv_desc *desc = corediv->desc;
unsigned long flags = 0;
u32 reg, div;
div = parent_rate / rate;
spin_lock_irqsave(&corediv->lock, flags);
reg = readl(corediv->reg + soc_desc->ratio_offset);
reg &= ~(desc->mask << desc->offset);
reg |= (div & desc->mask) << desc->offset;
writel(reg, corediv->reg + soc_desc->ratio_offset);
reg = readl(corediv->reg) | BIT(desc->fieldbit);
writel(reg, corediv->reg);
reg = readl(corediv->reg) | soc_desc->ratio_reload;
writel(reg, corediv->reg);
udelay(1000);
reg &= ~(CORE_CLK_DIV_RATIO_MASK | soc_desc->ratio_reload);
writel(reg, corediv->reg);
udelay(1000);
spin_unlock_irqrestore(&corediv->lock, flags);
return 0;
}
static void __init
mvebu_corediv_clk_init(struct device_node *node,
const struct clk_corediv_soc_desc *soc_desc)
{
struct clk_init_data init;
struct clk_corediv *corediv;
struct clk **clks;
void __iomem *base;
const char *parent_name;
const char *clk_name;
int i;
base = of_iomap(node, 0);
if (WARN_ON(!base))
return;
parent_name = of_clk_get_parent_name(node, 0);
clk_data.clk_num = soc_desc->ndescs;
clks = kcalloc(clk_data.clk_num, sizeof(struct clk *),
GFP_KERNEL);
if (WARN_ON(!clks))
goto err_unmap;
corediv = kcalloc(clk_data.clk_num, sizeof(struct clk_corediv),
GFP_KERNEL);
if (WARN_ON(!corediv))
goto err_free_clks;
spin_lock_init(&corediv->lock);
for (i = 0; i < clk_data.clk_num; i++) {
of_property_read_string_index(node, "clock-output-names",
i, &clk_name);
init.num_parents = 1;
init.parent_names = &parent_name;
init.name = clk_name;
init.ops = &soc_desc->ops;
init.flags = 0;
corediv[i].soc_desc = soc_desc;
corediv[i].desc = soc_desc->descs + i;
corediv[i].reg = base;
corediv[i].hw.init = &init;
clks[i] = clk_register(NULL, &corediv[i].hw);
WARN_ON(IS_ERR(clks[i]));
}
clk_data.clks = clks;
of_clk_add_provider(node, of_clk_src_onecell_get, &clk_data);
return;
err_free_clks:
kfree(clks);
err_unmap:
iounmap(base);
}
static void __init armada370_corediv_clk_init(struct device_node *node)
{
return mvebu_corediv_clk_init(node, &armada370_corediv_soc);
}
static void __init armada375_corediv_clk_init(struct device_node *node)
{
return mvebu_corediv_clk_init(node, &armada375_corediv_soc);
}
static void __init armada380_corediv_clk_init(struct device_node *node)
{
return mvebu_corediv_clk_init(node, &armada380_corediv_soc);
}
