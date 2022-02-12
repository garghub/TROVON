static void sun4i_a10_get_mod0_factors(u32 *freq, u32 parent_rate,
u8 *n, u8 *k, u8 *m, u8 *p)
{
u8 div, calcm, calcp;
if (*freq > parent_rate)
*freq = parent_rate;
div = DIV_ROUND_UP(parent_rate, *freq);
if (div < 16)
calcp = 0;
else if (div / 2 < 16)
calcp = 1;
else if (div / 4 < 16)
calcp = 2;
else
calcp = 3;
calcm = DIV_ROUND_UP(div, 1 << calcp);
*freq = (parent_rate >> calcp) / calcm;
if (n == NULL)
return;
*m = calcm - 1;
*p = calcp;
}
static void __init sun4i_a10_mod0_setup(struct device_node *node)
{
sunxi_factors_register(node, &sun4i_a10_mod0_data, &sun4i_a10_mod0_lock);
}
static void __init sun5i_a13_mbus_setup(struct device_node *node)
{
struct clk *mbus = sunxi_factors_register(node, &sun4i_a10_mod0_data, &sun5i_a13_mbus_lock);
__clk_get(mbus);
clk_prepare_enable(mbus);
}
static int mmc_get_phase(struct clk_hw *hw)
{
struct clk *mmc, *mmc_parent, *clk = hw->clk;
struct mmc_phase *phase = to_mmc_phase(hw);
unsigned int mmc_rate, mmc_parent_rate;
u16 step, mmc_div;
u32 value;
u8 delay;
value = readl(phase->reg);
delay = (value >> phase->data->offset) & 0x3;
if (!delay)
return 180;
mmc = clk_get_parent(clk);
if (!mmc)
return -EINVAL;
mmc_rate = clk_get_rate(mmc);
if (!mmc_rate)
return -EINVAL;
mmc_parent = clk_get_parent(mmc);
if (!mmc_parent)
return -EINVAL;
mmc_parent_rate = clk_get_rate(mmc_parent);
if (!mmc_parent_rate)
return -EINVAL;
mmc_div = mmc_parent_rate / mmc_rate;
step = DIV_ROUND_CLOSEST(360, mmc_div);
return delay * step;
}
static int mmc_set_phase(struct clk_hw *hw, int degrees)
{
struct clk *mmc, *mmc_parent, *clk = hw->clk;
struct mmc_phase *phase = to_mmc_phase(hw);
unsigned int mmc_rate, mmc_parent_rate;
unsigned long flags;
u32 value;
u8 delay;
mmc = clk_get_parent(clk);
if (!mmc)
return -EINVAL;
mmc_rate = clk_get_rate(mmc);
if (!mmc_rate)
return -EINVAL;
mmc_parent = clk_get_parent(mmc);
if (!mmc_parent)
return -EINVAL;
mmc_parent_rate = clk_get_rate(mmc_parent);
if (!mmc_parent_rate)
return -EINVAL;
if (degrees != 180) {
u16 step, mmc_div;
mmc_div = mmc_parent_rate / mmc_rate;
step = DIV_ROUND_CLOSEST(360, mmc_div);
delay = DIV_ROUND_CLOSEST(degrees, step);
} else {
delay = 0;
}
spin_lock_irqsave(phase->lock, flags);
value = readl(phase->reg);
value &= ~GENMASK(phase->data->offset + 3, phase->data->offset);
value |= delay << phase->data->offset;
writel(value, phase->reg);
spin_unlock_irqrestore(phase->lock, flags);
return 0;
}
static void __init sun4i_a10_mmc_phase_setup(struct device_node *node,
struct mmc_phase_data *data)
{
const char *parent_names[1] = { of_clk_get_parent_name(node, 0) };
struct clk_init_data init = {
.num_parents = 1,
.parent_names = parent_names,
.ops = &mmc_clk_ops,
};
struct mmc_phase *phase;
struct clk *clk;
phase = kmalloc(sizeof(*phase), GFP_KERNEL);
if (!phase)
return;
phase->hw.init = &init;
phase->reg = of_iomap(node, 0);
if (!phase->reg)
goto err_free;
phase->data = data;
phase->lock = &sun4i_a10_mod0_lock;
if (of_property_read_string(node, "clock-output-names", &init.name))
init.name = node->name;
clk = clk_register(NULL, &phase->hw);
if (IS_ERR(clk))
goto err_unmap;
of_clk_add_provider(node, of_clk_src_simple_get, clk);
return;
err_unmap:
iounmap(phase->reg);
err_free:
kfree(phase);
}
static void __init sun4i_a10_mmc_output_setup(struct device_node *node)
{
sun4i_a10_mmc_phase_setup(node, &mmc_output_clk);
}
static void __init sun4i_a10_mmc_sample_setup(struct device_node *node)
{
sun4i_a10_mmc_phase_setup(node, &mmc_sample_clk);
}
