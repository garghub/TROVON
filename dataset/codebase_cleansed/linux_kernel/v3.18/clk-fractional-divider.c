static unsigned long clk_fd_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct clk_fractional_divider *fd = to_clk_fd(hw);
unsigned long flags = 0;
u32 val, m, n;
u64 ret;
if (fd->lock)
spin_lock_irqsave(fd->lock, flags);
val = clk_readl(fd->reg);
if (fd->lock)
spin_unlock_irqrestore(fd->lock, flags);
m = (val & fd->mmask) >> fd->mshift;
n = (val & fd->nmask) >> fd->nshift;
ret = (u64)parent_rate * m;
do_div(ret, n);
return ret;
}
static long clk_fd_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *prate)
{
struct clk_fractional_divider *fd = to_clk_fd(hw);
unsigned maxn = (fd->nmask >> fd->nshift) + 1;
unsigned div;
if (!rate || rate >= *prate)
return *prate;
div = gcd(*prate, rate);
while ((*prate / div) > maxn) {
div <<= 1;
rate <<= 1;
}
return rate;
}
static int clk_fd_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct clk_fractional_divider *fd = to_clk_fd(hw);
unsigned long flags = 0;
unsigned long div;
unsigned n, m;
u32 val;
div = gcd(parent_rate, rate);
m = rate / div;
n = parent_rate / div;
if (fd->lock)
spin_lock_irqsave(fd->lock, flags);
val = clk_readl(fd->reg);
val &= ~(fd->mmask | fd->nmask);
val |= (m << fd->mshift) | (n << fd->nshift);
clk_writel(val, fd->reg);
if (fd->lock)
spin_unlock_irqrestore(fd->lock, flags);
return 0;
}
struct clk *clk_register_fractional_divider(struct device *dev,
const char *name, const char *parent_name, unsigned long flags,
void __iomem *reg, u8 mshift, u8 mwidth, u8 nshift, u8 nwidth,
u8 clk_divider_flags, spinlock_t *lock)
{
struct clk_fractional_divider *fd;
struct clk_init_data init;
struct clk *clk;
fd = kzalloc(sizeof(*fd), GFP_KERNEL);
if (!fd) {
dev_err(dev, "could not allocate fractional divider clk\n");
return ERR_PTR(-ENOMEM);
}
init.name = name;
init.ops = &clk_fractional_divider_ops;
init.flags = flags | CLK_IS_BASIC;
init.parent_names = parent_name ? &parent_name : NULL;
init.num_parents = parent_name ? 1 : 0;
fd->reg = reg;
fd->mshift = mshift;
fd->mmask = (BIT(mwidth) - 1) << mshift;
fd->nshift = nshift;
fd->nmask = (BIT(nwidth) - 1) << nshift;
fd->flags = clk_divider_flags;
fd->lock = lock;
fd->hw.init = &init;
clk = clk_register(dev, &fd->hw);
if (IS_ERR(clk))
kfree(fd);
return clk;
}
