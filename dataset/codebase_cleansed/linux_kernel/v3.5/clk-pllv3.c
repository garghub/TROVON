static int clk_pllv3_prepare(struct clk_hw *hw)
{
struct clk_pllv3 *pll = to_clk_pllv3(hw);
unsigned long timeout = jiffies + msecs_to_jiffies(10);
u32 val;
val = readl_relaxed(pll->base);
val &= ~BM_PLL_BYPASS;
if (pll->powerup_set)
val |= BM_PLL_POWER;
else
val &= ~BM_PLL_POWER;
writel_relaxed(val, pll->base);
while (!(readl_relaxed(pll->base) & BM_PLL_LOCK))
if (time_after(jiffies, timeout))
return -ETIMEDOUT;
return 0;
}
static void clk_pllv3_unprepare(struct clk_hw *hw)
{
struct clk_pllv3 *pll = to_clk_pllv3(hw);
u32 val;
val = readl_relaxed(pll->base);
val |= BM_PLL_BYPASS;
if (pll->powerup_set)
val &= ~BM_PLL_POWER;
else
val |= BM_PLL_POWER;
writel_relaxed(val, pll->base);
}
static int clk_pllv3_enable(struct clk_hw *hw)
{
struct clk_pllv3 *pll = to_clk_pllv3(hw);
u32 val;
val = readl_relaxed(pll->base);
val |= pll->gate_mask;
writel_relaxed(val, pll->base);
return 0;
}
static void clk_pllv3_disable(struct clk_hw *hw)
{
struct clk_pllv3 *pll = to_clk_pllv3(hw);
u32 val;
val = readl_relaxed(pll->base);
val &= ~pll->gate_mask;
writel_relaxed(val, pll->base);
}
static unsigned long clk_pllv3_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct clk_pllv3 *pll = to_clk_pllv3(hw);
u32 div = readl_relaxed(pll->base) & pll->div_mask;
return (div == 1) ? parent_rate * 22 : parent_rate * 20;
}
static long clk_pllv3_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *prate)
{
unsigned long parent_rate = *prate;
return (rate >= parent_rate * 22) ? parent_rate * 22 :
parent_rate * 20;
}
static int clk_pllv3_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct clk_pllv3 *pll = to_clk_pllv3(hw);
u32 val, div;
if (rate == parent_rate * 22)
div = 1;
else if (rate == parent_rate * 20)
div = 0;
else
return -EINVAL;
val = readl_relaxed(pll->base);
val &= ~pll->div_mask;
val |= div;
writel_relaxed(val, pll->base);
return 0;
}
static unsigned long clk_pllv3_sys_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct clk_pllv3 *pll = to_clk_pllv3(hw);
u32 div = readl_relaxed(pll->base) & pll->div_mask;
return parent_rate * div / 2;
}
static long clk_pllv3_sys_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *prate)
{
unsigned long parent_rate = *prate;
unsigned long min_rate = parent_rate * 54 / 2;
unsigned long max_rate = parent_rate * 108 / 2;
u32 div;
if (rate > max_rate)
rate = max_rate;
else if (rate < min_rate)
rate = min_rate;
div = rate * 2 / parent_rate;
return parent_rate * div / 2;
}
static int clk_pllv3_sys_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct clk_pllv3 *pll = to_clk_pllv3(hw);
unsigned long min_rate = parent_rate * 54 / 2;
unsigned long max_rate = parent_rate * 108 / 2;
u32 val, div;
if (rate < min_rate || rate > max_rate)
return -EINVAL;
div = rate * 2 / parent_rate;
val = readl_relaxed(pll->base);
val &= ~pll->div_mask;
val |= div;
writel_relaxed(val, pll->base);
return 0;
}
static unsigned long clk_pllv3_av_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct clk_pllv3 *pll = to_clk_pllv3(hw);
u32 mfn = readl_relaxed(pll->base + PLL_NUM_OFFSET);
u32 mfd = readl_relaxed(pll->base + PLL_DENOM_OFFSET);
u32 div = readl_relaxed(pll->base) & pll->div_mask;
return (parent_rate * div) + ((parent_rate / mfd) * mfn);
}
static long clk_pllv3_av_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *prate)
{
unsigned long parent_rate = *prate;
unsigned long min_rate = parent_rate * 27;
unsigned long max_rate = parent_rate * 54;
u32 div;
u32 mfn, mfd = 1000000;
s64 temp64;
if (rate > max_rate)
rate = max_rate;
else if (rate < min_rate)
rate = min_rate;
div = rate / parent_rate;
temp64 = (u64) (rate - div * parent_rate);
temp64 *= mfd;
do_div(temp64, parent_rate);
mfn = temp64;
return parent_rate * div + parent_rate / mfd * mfn;
}
static int clk_pllv3_av_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct clk_pllv3 *pll = to_clk_pllv3(hw);
unsigned long min_rate = parent_rate * 27;
unsigned long max_rate = parent_rate * 54;
u32 val, div;
u32 mfn, mfd = 1000000;
s64 temp64;
if (rate < min_rate || rate > max_rate)
return -EINVAL;
div = rate / parent_rate;
temp64 = (u64) (rate - div * parent_rate);
temp64 *= mfd;
do_div(temp64, parent_rate);
mfn = temp64;
val = readl_relaxed(pll->base);
val &= ~pll->div_mask;
val |= div;
writel_relaxed(val, pll->base);
writel_relaxed(mfn, pll->base + PLL_NUM_OFFSET);
writel_relaxed(mfd, pll->base + PLL_DENOM_OFFSET);
return 0;
}
static unsigned long clk_pllv3_enet_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct clk_pllv3 *pll = to_clk_pllv3(hw);
u32 div = readl_relaxed(pll->base) & pll->div_mask;
switch (div) {
case 0:
return 25000000;
case 1:
return 50000000;
case 2:
return 100000000;
case 3:
return 125000000;
}
return 0;
}
static long clk_pllv3_enet_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *prate)
{
if (rate >= 125000000)
rate = 125000000;
else if (rate >= 100000000)
rate = 100000000;
else if (rate >= 50000000)
rate = 50000000;
else
rate = 25000000;
return rate;
}
static int clk_pllv3_enet_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct clk_pllv3 *pll = to_clk_pllv3(hw);
u32 val, div;
switch (rate) {
case 25000000:
div = 0;
break;
case 50000000:
div = 1;
break;
case 100000000:
div = 2;
break;
case 125000000:
div = 3;
break;
default:
return -EINVAL;
}
val = readl_relaxed(pll->base);
val &= ~pll->div_mask;
val |= div;
writel_relaxed(val, pll->base);
return 0;
}
struct clk *imx_clk_pllv3(enum imx_pllv3_type type, const char *name,
const char *parent_name, void __iomem *base,
u32 gate_mask, u32 div_mask)
{
struct clk_pllv3 *pll;
const struct clk_ops *ops;
struct clk *clk;
struct clk_init_data init;
pll = kzalloc(sizeof(*pll), GFP_KERNEL);
if (!pll)
return ERR_PTR(-ENOMEM);
switch (type) {
case IMX_PLLV3_SYS:
ops = &clk_pllv3_sys_ops;
break;
case IMX_PLLV3_USB:
ops = &clk_pllv3_ops;
pll->powerup_set = true;
break;
case IMX_PLLV3_AV:
ops = &clk_pllv3_av_ops;
break;
case IMX_PLLV3_ENET:
ops = &clk_pllv3_enet_ops;
break;
case IMX_PLLV3_MLB:
ops = &clk_pllv3_mlb_ops;
break;
default:
ops = &clk_pllv3_ops;
}
pll->base = base;
pll->gate_mask = gate_mask;
pll->div_mask = div_mask;
init.name = name;
init.ops = ops;
init.flags = 0;
init.parent_names = &parent_name;
init.num_parents = 1;
pll->hw.init = &init;
clk = clk_register(NULL, &pll->hw);
if (IS_ERR(clk))
kfree(pll);
return clk;
}
