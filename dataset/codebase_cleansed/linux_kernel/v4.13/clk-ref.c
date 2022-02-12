static int clk_ref_enable(struct clk_hw *hw)
{
struct clk_ref *ref = to_clk_ref(hw);
writel_relaxed(1 << ((ref->idx + 1) * 8 - 1), ref->reg + CLR);
return 0;
}
static void clk_ref_disable(struct clk_hw *hw)
{
struct clk_ref *ref = to_clk_ref(hw);
writel_relaxed(1 << ((ref->idx + 1) * 8 - 1), ref->reg + SET);
}
static unsigned long clk_ref_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct clk_ref *ref = to_clk_ref(hw);
u64 tmp = parent_rate;
u8 frac = (readl_relaxed(ref->reg) >> (ref->idx * 8)) & 0x3f;
tmp *= 18;
do_div(tmp, frac);
return tmp;
}
static long clk_ref_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *prate)
{
unsigned long parent_rate = *prate;
u64 tmp = parent_rate;
u8 frac;
tmp = tmp * 18 + rate / 2;
do_div(tmp, rate);
frac = tmp;
if (frac < 18)
frac = 18;
else if (frac > 35)
frac = 35;
tmp = parent_rate;
tmp *= 18;
do_div(tmp, frac);
return tmp;
}
static int clk_ref_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct clk_ref *ref = to_clk_ref(hw);
unsigned long flags;
u64 tmp = parent_rate;
u32 val;
u8 frac, shift = ref->idx * 8;
tmp = tmp * 18 + rate / 2;
do_div(tmp, rate);
frac = tmp;
if (frac < 18)
frac = 18;
else if (frac > 35)
frac = 35;
spin_lock_irqsave(&mxs_lock, flags);
val = readl_relaxed(ref->reg);
val &= ~(0x3f << shift);
val |= frac << shift;
writel_relaxed(val, ref->reg);
spin_unlock_irqrestore(&mxs_lock, flags);
return 0;
}
struct clk *mxs_clk_ref(const char *name, const char *parent_name,
void __iomem *reg, u8 idx)
{
struct clk_ref *ref;
struct clk *clk;
struct clk_init_data init;
ref = kzalloc(sizeof(*ref), GFP_KERNEL);
if (!ref)
return ERR_PTR(-ENOMEM);
init.name = name;
init.ops = &clk_ref_ops;
init.flags = 0;
init.parent_names = (parent_name ? &parent_name: NULL);
init.num_parents = (parent_name ? 1 : 0);
ref->reg = reg;
ref->idx = idx;
ref->hw.init = &init;
clk = clk_register(NULL, &ref->hw);
if (IS_ERR(clk))
kfree(ref);
return clk;
}
