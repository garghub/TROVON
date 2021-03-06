static int clk_pllv3_wait_lock(struct clk_pllv3 *pll)
{
unsigned long timeout = jiffies + msecs_to_jiffies(10);
u32 val = readl_relaxed(pll->base) & pll->power_bit;
if ((pll->powerup_set && !val) || (!pll->powerup_set && val))
return 0;
do {
if (readl_relaxed(pll->base) & BM_PLL_LOCK)
break;
if (time_after(jiffies, timeout))
break;
usleep_range(50, 500);
} while (1);
return readl_relaxed(pll->base) & BM_PLL_LOCK ? 0 : -ETIMEDOUT;
}
static int clk_pllv3_prepare(struct clk_hw *hw)
{
struct clk_pllv3 *pll = to_clk_pllv3(hw);
u32 val;
val = readl_relaxed(pll->base);
if (pll->powerup_set)
val |= pll->power_bit;
else
val &= ~pll->power_bit;
writel_relaxed(val, pll->base);
return clk_pllv3_wait_lock(pll);
}
static void clk_pllv3_unprepare(struct clk_hw *hw)
{
struct clk_pllv3 *pll = to_clk_pllv3(hw);
u32 val;
val = readl_relaxed(pll->base);
if (pll->powerup_set)
val &= ~pll->power_bit;
else
val |= pll->power_bit;
writel_relaxed(val, pll->base);
}
static int clk_pllv3_is_prepared(struct clk_hw *hw)
{
struct clk_pllv3 *pll = to_clk_pllv3(hw);
if (readl_relaxed(pll->base) & BM_PLL_LOCK)
return 1;
return 0;
}
static unsigned long clk_pllv3_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct clk_pllv3 *pll = to_clk_pllv3(hw);
u32 div = (readl_relaxed(pll->base) >> pll->div_shift) & pll->div_mask;
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
val &= ~(pll->div_mask << pll->div_shift);
val |= (div << pll->div_shift);
writel_relaxed(val, pll->base);
return clk_pllv3_wait_lock(pll);
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
return clk_pllv3_wait_lock(pll);
}
static unsigned long clk_pllv3_av_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct clk_pllv3 *pll = to_clk_pllv3(hw);
u32 mfn = readl_relaxed(pll->base + PLL_NUM_OFFSET);
u32 mfd = readl_relaxed(pll->base + PLL_DENOM_OFFSET);
u32 div = readl_relaxed(pll->base) & pll->div_mask;
u64 temp64 = (u64)parent_rate;
temp64 *= mfn;
do_div(temp64, mfd);
return parent_rate * div + (unsigned long)temp64;
}
static long clk_pllv3_av_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *prate)
{
unsigned long parent_rate = *prate;
unsigned long min_rate = parent_rate * 27;
unsigned long max_rate = parent_rate * 54;
u32 div;
u32 mfn, mfd = 1000000;
u32 max_mfd = 0x3FFFFFFF;
u64 temp64;
if (rate > max_rate)
rate = max_rate;
else if (rate < min_rate)
rate = min_rate;
if (parent_rate <= max_mfd)
mfd = parent_rate;
div = rate / parent_rate;
temp64 = (u64) (rate - div * parent_rate);
temp64 *= mfd;
do_div(temp64, parent_rate);
mfn = temp64;
temp64 = (u64)parent_rate;
temp64 *= mfn;
do_div(temp64, mfd);
return parent_rate * div + (unsigned long)temp64;
}
static int clk_pllv3_av_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct clk_pllv3 *pll = to_clk_pllv3(hw);
unsigned long min_rate = parent_rate * 27;
unsigned long max_rate = parent_rate * 54;
u32 val, div;
u32 mfn, mfd = 1000000;
u32 max_mfd = 0x3FFFFFFF;
u64 temp64;
if (rate < min_rate || rate > max_rate)
return -EINVAL;
if (parent_rate <= max_mfd)
mfd = parent_rate;
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
return clk_pllv3_wait_lock(pll);
}
static unsigned long clk_pllv3_enet_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct clk_pllv3 *pll = to_clk_pllv3(hw);
return pll->ref_clock;
}
struct clk *imx_clk_pllv3(enum imx_pllv3_type type, const char *name,
const char *parent_name, void __iomem *base,
u32 div_mask)
{
struct clk_pllv3 *pll;
const struct clk_ops *ops;
struct clk *clk;
struct clk_init_data init;
pll = kzalloc(sizeof(*pll), GFP_KERNEL);
if (!pll)
return ERR_PTR(-ENOMEM);
pll->power_bit = BM_PLL_POWER;
switch (type) {
case IMX_PLLV3_SYS:
ops = &clk_pllv3_sys_ops;
break;
case IMX_PLLV3_USB_VF610:
pll->div_shift = 1;
case IMX_PLLV3_USB:
ops = &clk_pllv3_ops;
pll->powerup_set = true;
break;
case IMX_PLLV3_AV:
ops = &clk_pllv3_av_ops;
break;
case IMX_PLLV3_ENET_IMX7:
pll->power_bit = IMX7_ENET_PLL_POWER;
pll->ref_clock = 1000000000;
ops = &clk_pllv3_enet_ops;
break;
case IMX_PLLV3_ENET:
pll->ref_clock = 500000000;
ops = &clk_pllv3_enet_ops;
break;
default:
ops = &clk_pllv3_ops;
}
pll->base = base;
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
