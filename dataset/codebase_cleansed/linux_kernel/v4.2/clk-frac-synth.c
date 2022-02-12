static unsigned long frac_calc_rate(struct clk_hw *hw, unsigned long prate,
int index)
{
struct clk_frac *frac = to_clk_frac(hw);
struct frac_rate_tbl *rtbl = frac->rtbl;
prate /= 10000;
prate <<= 14;
prate /= (2 * rtbl[index].div);
prate *= 10000;
return prate;
}
static long clk_frac_round_rate(struct clk_hw *hw, unsigned long drate,
unsigned long *prate)
{
struct clk_frac *frac = to_clk_frac(hw);
int unused;
return clk_round_rate_index(hw, drate, *prate, frac_calc_rate,
frac->rtbl_cnt, &unused);
}
static unsigned long clk_frac_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct clk_frac *frac = to_clk_frac(hw);
unsigned long flags = 0;
unsigned int div = 1, val;
if (frac->lock)
spin_lock_irqsave(frac->lock, flags);
val = readl_relaxed(frac->reg);
if (frac->lock)
spin_unlock_irqrestore(frac->lock, flags);
div = val & DIV_FACTOR_MASK;
if (!div)
return 0;
parent_rate = parent_rate / 10000;
parent_rate = (parent_rate << 14) / (2 * div);
return parent_rate * 10000;
}
static int clk_frac_set_rate(struct clk_hw *hw, unsigned long drate,
unsigned long prate)
{
struct clk_frac *frac = to_clk_frac(hw);
struct frac_rate_tbl *rtbl = frac->rtbl;
unsigned long flags = 0, val;
int i;
clk_round_rate_index(hw, drate, prate, frac_calc_rate, frac->rtbl_cnt,
&i);
if (frac->lock)
spin_lock_irqsave(frac->lock, flags);
val = readl_relaxed(frac->reg) & ~DIV_FACTOR_MASK;
val |= rtbl[i].div & DIV_FACTOR_MASK;
writel_relaxed(val, frac->reg);
if (frac->lock)
spin_unlock_irqrestore(frac->lock, flags);
return 0;
}
struct clk *clk_register_frac(const char *name, const char *parent_name,
unsigned long flags, void __iomem *reg,
struct frac_rate_tbl *rtbl, u8 rtbl_cnt, spinlock_t *lock)
{
struct clk_init_data init;
struct clk_frac *frac;
struct clk *clk;
if (!name || !parent_name || !reg || !rtbl || !rtbl_cnt) {
pr_err("Invalid arguments passed");
return ERR_PTR(-EINVAL);
}
frac = kzalloc(sizeof(*frac), GFP_KERNEL);
if (!frac) {
pr_err("could not allocate frac clk\n");
return ERR_PTR(-ENOMEM);
}
frac->reg = reg;
frac->rtbl = rtbl;
frac->rtbl_cnt = rtbl_cnt;
frac->lock = lock;
frac->hw.init = &init;
init.name = name;
init.ops = &clk_frac_ops;
init.flags = flags;
init.parent_names = &parent_name;
init.num_parents = 1;
clk = clk_register(NULL, &frac->hw);
if (!IS_ERR_OR_NULL(clk))
return clk;
pr_err("clk register failed\n");
kfree(frac);
return NULL;
}
