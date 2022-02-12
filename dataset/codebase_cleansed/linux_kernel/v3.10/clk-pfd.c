static int clk_pfd_enable(struct clk_hw *hw)
{
struct clk_pfd *pfd = to_clk_pfd(hw);
writel_relaxed(1 << ((pfd->idx + 1) * 8 - 1), pfd->reg + CLR);
return 0;
}
static void clk_pfd_disable(struct clk_hw *hw)
{
struct clk_pfd *pfd = to_clk_pfd(hw);
writel_relaxed(1 << ((pfd->idx + 1) * 8 - 1), pfd->reg + SET);
}
static unsigned long clk_pfd_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct clk_pfd *pfd = to_clk_pfd(hw);
u64 tmp = parent_rate;
u8 frac = (readl_relaxed(pfd->reg) >> (pfd->idx * 8)) & 0x3f;
tmp *= 18;
do_div(tmp, frac);
return tmp;
}
static long clk_pfd_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *prate)
{
u64 tmp = *prate;
u8 frac;
tmp = tmp * 18 + rate / 2;
do_div(tmp, rate);
frac = tmp;
if (frac < 12)
frac = 12;
else if (frac > 35)
frac = 35;
tmp = *prate;
tmp *= 18;
do_div(tmp, frac);
return tmp;
}
static int clk_pfd_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct clk_pfd *pfd = to_clk_pfd(hw);
u64 tmp = parent_rate;
u8 frac;
tmp = tmp * 18 + rate / 2;
do_div(tmp, rate);
frac = tmp;
if (frac < 12)
frac = 12;
else if (frac > 35)
frac = 35;
writel_relaxed(0x3f << (pfd->idx * 8), pfd->reg + CLR);
writel_relaxed(frac << (pfd->idx * 8), pfd->reg + SET);
return 0;
}
struct clk *imx_clk_pfd(const char *name, const char *parent_name,
void __iomem *reg, u8 idx)
{
struct clk_pfd *pfd;
struct clk *clk;
struct clk_init_data init;
pfd = kzalloc(sizeof(*pfd), GFP_KERNEL);
if (!pfd)
return ERR_PTR(-ENOMEM);
pfd->reg = reg;
pfd->idx = idx;
init.name = name;
init.ops = &clk_pfd_ops;
init.flags = 0;
init.parent_names = &parent_name;
init.num_parents = 1;
pfd->hw.init = &init;
clk = clk_register(NULL, &pfd->hw);
if (IS_ERR(clk))
kfree(pfd);
return clk;
}
