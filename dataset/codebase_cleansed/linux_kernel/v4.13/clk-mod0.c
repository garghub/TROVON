static void sun4i_a10_get_mod0_factors(struct factors_request *req)
{
u8 div, calcm, calcp;
if (req->rate > req->parent_rate)
req->rate = req->parent_rate;
div = DIV_ROUND_UP(req->parent_rate, req->rate);
if (div < 16)
calcp = 0;
else if (div / 2 < 16)
calcp = 1;
else if (div / 4 < 16)
calcp = 2;
else
calcp = 3;
calcm = DIV_ROUND_UP(div, 1 << calcp);
req->rate = (req->parent_rate >> calcp) / calcm;
req->m = calcm - 1;
req->p = calcp;
}
static void __init sun4i_a10_mod0_setup(struct device_node *node)
{
void __iomem *reg;
reg = of_iomap(node, 0);
if (!reg) {
return;
}
sunxi_factors_register(node, &sun4i_a10_mod0_data,
&sun4i_a10_mod0_lock, reg);
}
static int sun4i_a10_mod0_clk_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct resource *r;
void __iomem *reg;
if (!np)
return -ENODEV;
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
reg = devm_ioremap_resource(&pdev->dev, r);
if (IS_ERR(reg))
return PTR_ERR(reg);
sunxi_factors_register(np, &sun4i_a10_mod0_data,
&sun4i_a10_mod0_lock, reg);
return 0;
}
static void __init sun9i_a80_mod0_setup(struct device_node *node)
{
void __iomem *reg;
reg = of_io_request_and_map(node, 0, of_node_full_name(node));
if (IS_ERR(reg)) {
pr_err("Could not get registers for mod0-clk: %s\n",
node->name);
return;
}
sunxi_factors_register(node, &sun9i_a80_mod0_data,
&sun4i_a10_mod0_lock, reg);
}
static void __init sun5i_a13_mbus_setup(struct device_node *node)
{
struct clk *mbus;
void __iomem *reg;
reg = of_iomap(node, 0);
if (!reg) {
pr_err("Could not get registers for a13-mbus-clk\n");
return;
}
mbus = sunxi_factors_register(node, &sun4i_a10_mod0_data,
&sun5i_a13_mbus_lock, reg);
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
delay = (value >> phase->offset) & 0x3;
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
value &= ~GENMASK(phase->offset + 3, phase->offset);
value |= delay << phase->offset;
writel(value, phase->reg);
spin_unlock_irqrestore(phase->lock, flags);
return 0;
}
static void __init sunxi_mmc_setup(struct device_node *node,
const struct factors_data *data,
spinlock_t *lock)
{
struct clk_onecell_data *clk_data;
const char *parent;
void __iomem *reg;
int i;
reg = of_io_request_and_map(node, 0, of_node_full_name(node));
if (IS_ERR(reg)) {
pr_err("Couldn't map the %s clock registers\n", node->name);
return;
}
clk_data = kmalloc(sizeof(*clk_data), GFP_KERNEL);
if (!clk_data)
return;
clk_data->clks = kcalloc(3, sizeof(*clk_data->clks), GFP_KERNEL);
if (!clk_data->clks)
goto err_free_data;
clk_data->clk_num = 3;
clk_data->clks[0] = sunxi_factors_register(node, data, lock, reg);
if (!clk_data->clks[0])
goto err_free_clks;
parent = __clk_get_name(clk_data->clks[0]);
for (i = 1; i < 3; i++) {
struct clk_init_data init = {
.num_parents = 1,
.parent_names = &parent,
.ops = &mmc_clk_ops,
};
struct mmc_phase *phase;
phase = kmalloc(sizeof(*phase), GFP_KERNEL);
if (!phase)
continue;
phase->hw.init = &init;
phase->reg = reg;
phase->lock = lock;
if (i == 1)
phase->offset = 8;
else
phase->offset = 20;
if (of_property_read_string_index(node, "clock-output-names",
i, &init.name))
init.name = node->name;
clk_data->clks[i] = clk_register(NULL, &phase->hw);
if (IS_ERR(clk_data->clks[i])) {
kfree(phase);
continue;
}
}
of_clk_add_provider(node, of_clk_src_onecell_get, clk_data);
return;
err_free_clks:
kfree(clk_data->clks);
err_free_data:
kfree(clk_data);
}
static void __init sun4i_a10_mmc_setup(struct device_node *node)
{
sunxi_mmc_setup(node, &sun4i_a10_mod0_data, &sun4i_a10_mmc_lock);
}
static void __init sun9i_a80_mmc_setup(struct device_node *node)
{
sunxi_mmc_setup(node, &sun9i_a80_mod0_data, &sun9i_a80_mmc_lock);
}
