static int meson8b_clk_reset_update(struct reset_controller_dev *rcdev,
unsigned long id, bool assert)
{
struct meson8b_clk_reset *meson8b_clk_reset =
container_of(rcdev, struct meson8b_clk_reset, reset);
unsigned long flags;
const struct meson8b_clk_reset_line *reset;
u32 val;
if (id >= ARRAY_SIZE(meson8b_clk_reset_bits))
return -EINVAL;
reset = &meson8b_clk_reset_bits[id];
spin_lock_irqsave(&clk_lock, flags);
val = readl(meson8b_clk_reset->base + reset->reg);
if (assert)
val |= BIT(reset->bit_idx);
else
val &= ~BIT(reset->bit_idx);
writel(val, meson8b_clk_reset->base + reset->reg);
spin_unlock_irqrestore(&clk_lock, flags);
return 0;
}
static int meson8b_clk_reset_assert(struct reset_controller_dev *rcdev,
unsigned long id)
{
return meson8b_clk_reset_update(rcdev, id, true);
}
static int meson8b_clk_reset_deassert(struct reset_controller_dev *rcdev,
unsigned long id)
{
return meson8b_clk_reset_update(rcdev, id, false);
}
static int meson8b_clkc_probe(struct platform_device *pdev)
{
int ret, clkid, i;
struct clk_hw *parent_hw;
struct clk *parent_clk;
struct device *dev = &pdev->dev;
if (!clk_base)
return -ENXIO;
for (i = 0; i < ARRAY_SIZE(meson8b_clk_plls); i++)
meson8b_clk_plls[i]->base = clk_base;
for (i = 0; i < ARRAY_SIZE(meson8b_clk_mplls); i++)
meson8b_clk_mplls[i]->base = clk_base;
meson8b_cpu_clk.base = clk_base;
for (i = 0; i < ARRAY_SIZE(meson8b_clk_gates); i++)
meson8b_clk_gates[i]->reg = clk_base +
(u32)meson8b_clk_gates[i]->reg;
for (i = 0; i < ARRAY_SIZE(meson8b_clk_muxes); i++)
meson8b_clk_muxes[i]->reg = clk_base +
(u32)meson8b_clk_muxes[i]->reg;
for (i = 0; i < ARRAY_SIZE(meson8b_clk_dividers); i++)
meson8b_clk_dividers[i]->reg = clk_base +
(u32)meson8b_clk_dividers[i]->reg;
for (clkid = CLKID_XTAL; clkid < CLK_NR_CLKS; clkid++) {
if (!meson8b_hw_onecell_data.hws[clkid])
continue;
ret = devm_clk_hw_register(dev, meson8b_hw_onecell_data.hws[clkid]);
if (ret)
return ret;
}
parent_hw = clk_hw_get_parent(&meson8b_cpu_clk.hw);
parent_clk = parent_hw->clk;
ret = clk_notifier_register(parent_clk, &meson8b_cpu_clk.clk_nb);
if (ret) {
pr_err("%s: failed to register clock notifier for cpu_clk\n",
__func__);
return ret;
}
return of_clk_add_hw_provider(dev->of_node, of_clk_hw_onecell_get,
&meson8b_hw_onecell_data);
}
static void __init meson8b_clkc_reset_init(struct device_node *np)
{
struct meson8b_clk_reset *rstc;
int ret;
clk_base = of_iomap(np, 1);
if (!clk_base) {
pr_err("%s: Unable to map clk base\n", __func__);
return;
}
rstc = kzalloc(sizeof(*rstc), GFP_KERNEL);
if (!rstc)
return;
rstc->base = clk_base;
rstc->reset.ops = &meson8b_clk_reset_ops;
rstc->reset.nr_resets = ARRAY_SIZE(meson8b_clk_reset_bits);
rstc->reset.of_node = np;
ret = reset_controller_register(&rstc->reset);
if (ret) {
pr_err("%s: Failed to register clkc reset controller: %d\n",
__func__, ret);
return;
}
}
