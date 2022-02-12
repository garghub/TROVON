static int clk_apbc_prepare(struct clk_hw *hw)
{
struct clk_apbc *apbc = to_clk_apbc(hw);
unsigned int data;
unsigned long flags = 0;
if (apbc->lock)
spin_lock_irqsave(apbc->lock, flags);
data = readl_relaxed(apbc->base);
if (apbc->flags & APBC_POWER_CTRL)
data |= APBC_POWER;
data |= APBC_FNCLK;
writel_relaxed(data, apbc->base);
if (apbc->lock)
spin_unlock_irqrestore(apbc->lock, flags);
udelay(apbc->delay);
if (apbc->lock)
spin_lock_irqsave(apbc->lock, flags);
data = readl_relaxed(apbc->base);
data |= APBC_APBCLK;
writel_relaxed(data, apbc->base);
if (apbc->lock)
spin_unlock_irqrestore(apbc->lock, flags);
udelay(apbc->delay);
if (!(apbc->flags & APBC_NO_BUS_CTRL)) {
if (apbc->lock)
spin_lock_irqsave(apbc->lock, flags);
data = readl_relaxed(apbc->base);
data &= ~APBC_RST;
writel_relaxed(data, apbc->base);
if (apbc->lock)
spin_unlock_irqrestore(apbc->lock, flags);
}
return 0;
}
static void clk_apbc_unprepare(struct clk_hw *hw)
{
struct clk_apbc *apbc = to_clk_apbc(hw);
unsigned long data;
unsigned long flags = 0;
if (apbc->lock)
spin_lock_irqsave(apbc->lock, flags);
data = readl_relaxed(apbc->base);
if (apbc->flags & APBC_POWER_CTRL)
data &= ~APBC_POWER;
data &= ~APBC_FNCLK;
writel_relaxed(data, apbc->base);
if (apbc->lock)
spin_unlock_irqrestore(apbc->lock, flags);
udelay(10);
if (apbc->lock)
spin_lock_irqsave(apbc->lock, flags);
data = readl_relaxed(apbc->base);
data &= ~APBC_APBCLK;
writel_relaxed(data, apbc->base);
if (apbc->lock)
spin_unlock_irqrestore(apbc->lock, flags);
}
struct clk *mmp_clk_register_apbc(const char *name, const char *parent_name,
void __iomem *base, unsigned int delay,
unsigned int apbc_flags, spinlock_t *lock)
{
struct clk_apbc *apbc;
struct clk *clk;
struct clk_init_data init;
apbc = kzalloc(sizeof(*apbc), GFP_KERNEL);
if (!apbc)
return NULL;
init.name = name;
init.ops = &clk_apbc_ops;
init.flags = CLK_SET_RATE_PARENT;
init.parent_names = (parent_name ? &parent_name : NULL);
init.num_parents = (parent_name ? 1 : 0);
apbc->base = base;
apbc->delay = delay;
apbc->flags = apbc_flags;
apbc->lock = lock;
apbc->hw.init = &init;
clk = clk_register(NULL, &apbc->hw);
if (IS_ERR(clk))
kfree(apbc);
return clk;
}
