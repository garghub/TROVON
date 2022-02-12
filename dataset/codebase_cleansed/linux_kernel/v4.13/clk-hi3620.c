static void __init hi3620_clk_init(struct device_node *np)
{
struct hisi_clock_data *clk_data;
clk_data = hisi_clk_init(np, HI3620_NR_CLKS);
if (!clk_data)
return;
hisi_clk_register_fixed_rate(hi3620_fixed_rate_clks,
ARRAY_SIZE(hi3620_fixed_rate_clks),
clk_data);
hisi_clk_register_fixed_factor(hi3620_fixed_factor_clks,
ARRAY_SIZE(hi3620_fixed_factor_clks),
clk_data);
hisi_clk_register_mux(hi3620_mux_clks, ARRAY_SIZE(hi3620_mux_clks),
clk_data);
hisi_clk_register_divider(hi3620_div_clks, ARRAY_SIZE(hi3620_div_clks),
clk_data);
hisi_clk_register_gate_sep(hi3620_separated_gate_clks,
ARRAY_SIZE(hi3620_separated_gate_clks),
clk_data);
}
static unsigned long mmc_clk_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
switch (parent_rate) {
case 26000000:
return 13000000;
case 180000000:
return 25000000;
case 360000000:
return 50000000;
case 720000000:
return 100000000;
case 1440000000:
return 180000000;
default:
return parent_rate;
}
}
static int mmc_clk_determine_rate(struct clk_hw *hw,
struct clk_rate_request *req)
{
struct clk_mmc *mclk = to_mmc(hw);
if ((req->rate <= 13000000) && (mclk->id == HI3620_MMC_CIUCLK1)) {
req->rate = 13000000;
req->best_parent_rate = 26000000;
} else if (req->rate <= 26000000) {
req->rate = 25000000;
req->best_parent_rate = 180000000;
} else if (req->rate <= 52000000) {
req->rate = 50000000;
req->best_parent_rate = 360000000;
} else if (req->rate <= 100000000) {
req->rate = 100000000;
req->best_parent_rate = 720000000;
} else {
req->rate = 180000000;
req->best_parent_rate = 1440000000;
}
return -EINVAL;
}
static u32 mmc_clk_delay(u32 val, u32 para, u32 off, u32 len)
{
u32 i;
for (i = 0; i < len; i++) {
if (para % 2)
val |= 1 << (off + i);
else
val &= ~(1 << (off + i));
para = para >> 1;
}
return val;
}
static int mmc_clk_set_timing(struct clk_hw *hw, unsigned long rate)
{
struct clk_mmc *mclk = to_mmc(hw);
unsigned long flags;
u32 sam, drv, div, val;
static DEFINE_SPINLOCK(mmc_clk_lock);
switch (rate) {
case 13000000:
sam = 3;
drv = 1;
div = 1;
break;
case 25000000:
sam = 13;
drv = 6;
div = 6;
break;
case 50000000:
sam = 3;
drv = 6;
div = 6;
break;
case 100000000:
sam = 6;
drv = 4;
div = 6;
break;
case 180000000:
sam = 6;
drv = 4;
div = 7;
break;
default:
return -EINVAL;
}
spin_lock_irqsave(&mmc_clk_lock, flags);
val = readl_relaxed(mclk->clken_reg);
val &= ~(1 << mclk->clken_bit);
writel_relaxed(val, mclk->clken_reg);
val = readl_relaxed(mclk->sam_reg);
val = mmc_clk_delay(val, sam, mclk->sam_off, mclk->sam_bits);
writel_relaxed(val, mclk->sam_reg);
val = readl_relaxed(mclk->drv_reg);
val = mmc_clk_delay(val, drv, mclk->drv_off, mclk->drv_bits);
writel_relaxed(val, mclk->drv_reg);
val = readl_relaxed(mclk->div_reg);
val = mmc_clk_delay(val, div, mclk->div_off, mclk->div_bits);
writel_relaxed(val, mclk->div_reg);
val = readl_relaxed(mclk->clken_reg);
val |= 1 << mclk->clken_bit;
writel_relaxed(val, mclk->clken_reg);
spin_unlock_irqrestore(&mmc_clk_lock, flags);
return 0;
}
static int mmc_clk_prepare(struct clk_hw *hw)
{
struct clk_mmc *mclk = to_mmc(hw);
unsigned long rate;
if (mclk->id == HI3620_MMC_CIUCLK1)
rate = 13000000;
else
rate = 25000000;
return mmc_clk_set_timing(hw, rate);
}
static int mmc_clk_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
return mmc_clk_set_timing(hw, rate);
}
static struct clk *hisi_register_clk_mmc(struct hisi_mmc_clock *mmc_clk,
void __iomem *base, struct device_node *np)
{
struct clk_mmc *mclk;
struct clk *clk;
struct clk_init_data init;
mclk = kzalloc(sizeof(*mclk), GFP_KERNEL);
if (!mclk)
return ERR_PTR(-ENOMEM);
init.name = mmc_clk->name;
init.ops = &clk_mmc_ops;
init.flags = mmc_clk->flags | CLK_IS_BASIC;
init.parent_names = (mmc_clk->parent_name ? &mmc_clk->parent_name : NULL);
init.num_parents = (mmc_clk->parent_name ? 1 : 0);
mclk->hw.init = &init;
mclk->id = mmc_clk->id;
mclk->clken_reg = base + mmc_clk->clken_reg;
mclk->clken_bit = mmc_clk->clken_bit;
mclk->div_reg = base + mmc_clk->div_reg;
mclk->div_off = mmc_clk->div_off;
mclk->div_bits = mmc_clk->div_bits;
mclk->drv_reg = base + mmc_clk->drv_reg;
mclk->drv_off = mmc_clk->drv_off;
mclk->drv_bits = mmc_clk->drv_bits;
mclk->sam_reg = base + mmc_clk->sam_reg;
mclk->sam_off = mmc_clk->sam_off;
mclk->sam_bits = mmc_clk->sam_bits;
clk = clk_register(NULL, &mclk->hw);
if (WARN_ON(IS_ERR(clk)))
kfree(mclk);
return clk;
}
static void __init hi3620_mmc_clk_init(struct device_node *node)
{
void __iomem *base;
int i, num = ARRAY_SIZE(hi3620_mmc_clks);
struct clk_onecell_data *clk_data;
if (!node) {
pr_err("failed to find pctrl node in DTS\n");
return;
}
base = of_iomap(node, 0);
if (!base) {
pr_err("failed to map pctrl\n");
return;
}
clk_data = kzalloc(sizeof(*clk_data), GFP_KERNEL);
if (WARN_ON(!clk_data))
return;
clk_data->clks = kcalloc(num, sizeof(*clk_data->clks), GFP_KERNEL);
if (!clk_data->clks)
return;
for (i = 0; i < num; i++) {
struct hisi_mmc_clock *mmc_clk = &hi3620_mmc_clks[i];
clk_data->clks[mmc_clk->id] =
hisi_register_clk_mmc(mmc_clk, base, node);
}
clk_data->clk_num = num;
of_clk_add_provider(node, of_clk_src_onecell_get, clk_data);
}
