static int ccu_phase_get_phase(struct clk_hw *hw)
{
struct ccu_phase *phase = hw_to_ccu_phase(hw);
struct clk_hw *parent, *grandparent;
unsigned int parent_rate, grandparent_rate;
u16 step, parent_div;
u32 reg;
u8 delay;
reg = readl(phase->common.base + phase->common.reg);
delay = (reg >> phase->shift);
delay &= (1 << phase->width) - 1;
if (!delay)
return 180;
parent = clk_hw_get_parent(hw);
if (!parent)
return -EINVAL;
parent_rate = clk_hw_get_rate(parent);
if (!parent_rate)
return -EINVAL;
grandparent = clk_hw_get_parent(parent);
if (!grandparent)
return -EINVAL;
grandparent_rate = clk_hw_get_rate(grandparent);
if (!grandparent_rate)
return -EINVAL;
parent_div = grandparent_rate / parent_rate;
step = DIV_ROUND_CLOSEST(360, parent_div);
return delay * step;
}
static int ccu_phase_set_phase(struct clk_hw *hw, int degrees)
{
struct ccu_phase *phase = hw_to_ccu_phase(hw);
struct clk_hw *parent, *grandparent;
unsigned int parent_rate, grandparent_rate;
unsigned long flags;
u32 reg;
u8 delay;
parent = clk_hw_get_parent(hw);
if (!parent)
return -EINVAL;
parent_rate = clk_hw_get_rate(parent);
if (!parent_rate)
return -EINVAL;
grandparent = clk_hw_get_parent(parent);
if (!grandparent)
return -EINVAL;
grandparent_rate = clk_hw_get_rate(grandparent);
if (!grandparent_rate)
return -EINVAL;
if (degrees != 180) {
u16 step, parent_div;
parent_div = grandparent_rate / parent_rate;
step = DIV_ROUND_CLOSEST(360, parent_div);
delay = DIV_ROUND_CLOSEST(degrees, step);
} else {
delay = 0;
}
spin_lock_irqsave(phase->common.lock, flags);
reg = readl(phase->common.base + phase->common.reg);
reg &= ~GENMASK(phase->width + phase->shift - 1, phase->shift);
writel(reg | (delay << phase->shift),
phase->common.base + phase->common.reg);
spin_unlock_irqrestore(phase->common.lock, flags);
return 0;
}
