static unsigned long clk_fd_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct clk_fractional_divider *fd = to_clk_fd(hw);
unsigned long flags = 0;
unsigned long m, n;
u32 val;
u64 ret;
if (fd->lock)
spin_lock_irqsave(fd->lock, flags);
else
__acquire(fd->lock);
val = clk_readl(fd->reg);
if (fd->lock)
spin_unlock_irqrestore(fd->lock, flags);
else
__release(fd->lock);
m = (val & fd->mmask) >> fd->mshift;
n = (val & fd->nmask) >> fd->nshift;
if (!n || !m)
return parent_rate;
ret = (u64)parent_rate * m;
do_div(ret, n);
return ret;
}
static long clk_fd_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *parent_rate)
{
struct clk_fractional_divider *fd = to_clk_fd(hw);
unsigned long scale;
unsigned long m, n;
u64 ret;
if (!rate || rate >= *parent_rate)
return *parent_rate;
scale = fls_long(*parent_rate / rate - 1);
if (scale > fd->nwidth)
rate <<= scale - fd->nwidth;
rational_best_approximation(rate, *parent_rate,
GENMASK(fd->mwidth - 1, 0), GENMASK(fd->nwidth - 1, 0),
&m, &n);
ret = (u64)*parent_rate * m;
do_div(ret, n);
return ret;
}
static int clk_fd_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct clk_fractional_divider *fd = to_clk_fd(hw);
unsigned long flags = 0;
unsigned long m, n;
u32 val;
rational_best_approximation(rate, parent_rate,
GENMASK(fd->mwidth - 1, 0), GENMASK(fd->nwidth - 1, 0),
&m, &n);
if (fd->lock)
spin_lock_irqsave(fd->lock, flags);
else
__acquire(fd->lock);
val = clk_readl(fd->reg);
val &= ~(fd->mmask | fd->nmask);
val |= (m << fd->mshift) | (n << fd->nshift);
clk_writel(val, fd->reg);
if (fd->lock)
spin_unlock_irqrestore(fd->lock, flags);
else
__release(fd->lock);
return 0;
}
struct clk_hw *clk_hw_register_fractional_divider(struct device *dev,
const char *name, const char *parent_name, unsigned long flags,
void __iomem *reg, u8 mshift, u8 mwidth, u8 nshift, u8 nwidth,
u8 clk_divider_flags, spinlock_t *lock)
{
struct clk_fractional_divider *fd;
struct clk_init_data init;
struct clk_hw *hw;
int ret;
fd = kzalloc(sizeof(*fd), GFP_KERNEL);
if (!fd)
return ERR_PTR(-ENOMEM);
init.name = name;
init.ops = &clk_fractional_divider_ops;
init.flags = flags | CLK_IS_BASIC;
init.parent_names = parent_name ? &parent_name : NULL;
init.num_parents = parent_name ? 1 : 0;
fd->reg = reg;
fd->mshift = mshift;
fd->mwidth = mwidth;
fd->mmask = GENMASK(mwidth - 1, 0) << mshift;
fd->nshift = nshift;
fd->nwidth = nwidth;
fd->nmask = GENMASK(nwidth - 1, 0) << nshift;
fd->flags = clk_divider_flags;
fd->lock = lock;
fd->hw.init = &init;
hw = &fd->hw;
ret = clk_hw_register(dev, hw);
if (ret) {
kfree(fd);
hw = ERR_PTR(ret);
}
return hw;
}
struct clk *clk_register_fractional_divider(struct device *dev,
const char *name, const char *parent_name, unsigned long flags,
void __iomem *reg, u8 mshift, u8 mwidth, u8 nshift, u8 nwidth,
u8 clk_divider_flags, spinlock_t *lock)
{
struct clk_hw *hw;
hw = clk_hw_register_fractional_divider(dev, name, parent_name, flags,
reg, mshift, mwidth, nshift, nwidth, clk_divider_flags,
lock);
if (IS_ERR(hw))
return ERR_CAST(hw);
return hw->clk;
}
void clk_hw_unregister_fractional_divider(struct clk_hw *hw)
{
struct clk_fractional_divider *fd;
fd = to_clk_fd(hw);
clk_hw_unregister(hw);
kfree(fd);
}
