static int clk_periph_is_enabled(struct clk_hw *hw)
{
struct tegra_clk_periph_gate *gate = to_clk_periph_gate(hw);
int state = 1;
if (!(read_enb(gate) & periph_clk_to_bit(gate)))
state = 0;
if (!(gate->flags & TEGRA_PERIPH_NO_RESET))
if (read_rst(gate) & periph_clk_to_bit(gate))
state = 0;
return state;
}
static int clk_periph_enable(struct clk_hw *hw)
{
struct tegra_clk_periph_gate *gate = to_clk_periph_gate(hw);
unsigned long flags = 0;
spin_lock_irqsave(&periph_ref_lock, flags);
gate->enable_refcnt[gate->clk_num]++;
if (gate->enable_refcnt[gate->clk_num] > 1) {
spin_unlock_irqrestore(&periph_ref_lock, flags);
return 0;
}
write_enb_set(periph_clk_to_bit(gate), gate);
udelay(2);
if (!(gate->flags & TEGRA_PERIPH_NO_RESET) &&
!(gate->flags & TEGRA_PERIPH_MANUAL_RESET)) {
if (read_rst(gate) & periph_clk_to_bit(gate)) {
udelay(5);
write_rst_clr(periph_clk_to_bit(gate), gate);
}
}
spin_unlock_irqrestore(&periph_ref_lock, flags);
return 0;
}
static void clk_periph_disable(struct clk_hw *hw)
{
struct tegra_clk_periph_gate *gate = to_clk_periph_gate(hw);
unsigned long flags = 0;
spin_lock_irqsave(&periph_ref_lock, flags);
gate->enable_refcnt[gate->clk_num]--;
if (gate->enable_refcnt[gate->clk_num] > 0) {
spin_unlock_irqrestore(&periph_ref_lock, flags);
return;
}
if (gate->flags & TEGRA_PERIPH_ON_APB)
tegra_read_chipid();
write_enb_clr(periph_clk_to_bit(gate), gate);
spin_unlock_irqrestore(&periph_ref_lock, flags);
}
void tegra_periph_reset(struct tegra_clk_periph_gate *gate, bool assert)
{
if (gate->flags & TEGRA_PERIPH_NO_RESET)
return;
if (assert) {
if (gate->flags & TEGRA_PERIPH_ON_APB)
tegra_read_chipid();
write_rst_set(periph_clk_to_bit(gate), gate);
} else {
write_rst_clr(periph_clk_to_bit(gate), gate);
}
}
struct clk *tegra_clk_register_periph_gate(const char *name,
const char *parent_name, u8 gate_flags, void __iomem *clk_base,
unsigned long flags, int clk_num,
struct tegra_clk_periph_regs *pregs, int *enable_refcnt)
{
struct tegra_clk_periph_gate *gate;
struct clk *clk;
struct clk_init_data init;
gate = kzalloc(sizeof(*gate), GFP_KERNEL);
if (!gate) {
pr_err("%s: could not allocate periph gate clk\n", __func__);
return ERR_PTR(-ENOMEM);
}
init.name = name;
init.flags = flags;
init.parent_names = parent_name ? &parent_name : NULL;
init.num_parents = parent_name ? 1 : 0;
init.ops = &tegra_clk_periph_gate_ops;
gate->magic = TEGRA_CLK_PERIPH_GATE_MAGIC;
gate->clk_base = clk_base;
gate->clk_num = clk_num;
gate->flags = gate_flags;
gate->enable_refcnt = enable_refcnt;
gate->regs = pregs;
gate->hw.init = &init;
clk = clk_register(NULL, &gate->hw);
if (IS_ERR(clk))
kfree(gate);
return clk;
}
