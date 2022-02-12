static unsigned long cpg_z_clk_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct cpg_z_clk *zclk = to_z_clk(hw);
unsigned int mult;
unsigned int val;
val = (clk_readl(zclk->reg) & CPG_FRQCRC_ZFC_MASK)
>> CPG_FRQCRC_ZFC_SHIFT;
mult = 32 - val;
return div_u64((u64)parent_rate * mult, 32);
}
static long cpg_z_clk_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *parent_rate)
{
unsigned long prate = *parent_rate;
unsigned int mult;
if (!prate)
prate = 1;
mult = div_u64((u64)rate * 32, prate);
mult = clamp(mult, 1U, 32U);
return *parent_rate / 32 * mult;
}
static int cpg_z_clk_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct cpg_z_clk *zclk = to_z_clk(hw);
unsigned int mult;
u32 val, kick;
unsigned int i;
mult = div_u64((u64)rate * 32, parent_rate);
mult = clamp(mult, 1U, 32U);
if (clk_readl(zclk->kick_reg) & CPG_FRQCRB_KICK)
return -EBUSY;
val = clk_readl(zclk->reg);
val &= ~CPG_FRQCRC_ZFC_MASK;
val |= (32 - mult) << CPG_FRQCRC_ZFC_SHIFT;
clk_writel(val, zclk->reg);
kick = clk_readl(zclk->kick_reg);
kick |= CPG_FRQCRB_KICK;
clk_writel(kick, zclk->kick_reg);
for (i = 1000; i; i--) {
if (!(clk_readl(zclk->kick_reg) & CPG_FRQCRB_KICK))
return 0;
cpu_relax();
}
return -ETIMEDOUT;
}
static struct clk * __init cpg_z_clk_register(struct rcar_gen2_cpg *cpg)
{
static const char *parent_name = "pll0";
struct clk_init_data init;
struct cpg_z_clk *zclk;
struct clk *clk;
zclk = kzalloc(sizeof(*zclk), GFP_KERNEL);
if (!zclk)
return ERR_PTR(-ENOMEM);
init.name = "z";
init.ops = &cpg_z_clk_ops;
init.flags = 0;
init.parent_names = &parent_name;
init.num_parents = 1;
zclk->reg = cpg->reg + CPG_FRQCRC;
zclk->kick_reg = cpg->reg + CPG_FRQCRB;
zclk->hw.init = &init;
clk = clk_register(NULL, &zclk->hw);
if (IS_ERR(clk))
kfree(zclk);
return clk;
}
static struct clk * __init cpg_rcan_clk_register(struct rcar_gen2_cpg *cpg,
struct device_node *np)
{
const char *parent_name = of_clk_get_parent_name(np, 1);
struct clk_fixed_factor *fixed;
struct clk_gate *gate;
struct clk *clk;
fixed = kzalloc(sizeof(*fixed), GFP_KERNEL);
if (!fixed)
return ERR_PTR(-ENOMEM);
fixed->mult = 1;
fixed->div = 6;
gate = kzalloc(sizeof(*gate), GFP_KERNEL);
if (!gate) {
kfree(fixed);
return ERR_PTR(-ENOMEM);
}
gate->reg = cpg->reg + CPG_RCANCKCR;
gate->bit_idx = 8;
gate->flags = CLK_GATE_SET_TO_DISABLE;
gate->lock = &cpg->lock;
clk = clk_register_composite(NULL, "rcan", &parent_name, 1, NULL, NULL,
&fixed->hw, &clk_fixed_factor_ops,
&gate->hw, &clk_gate_ops, 0);
if (IS_ERR(clk)) {
kfree(gate);
kfree(fixed);
}
return clk;
}
static struct clk * __init cpg_adsp_clk_register(struct rcar_gen2_cpg *cpg)
{
const char *parent_name = "pll1";
struct clk_divider *div;
struct clk_gate *gate;
struct clk *clk;
div = kzalloc(sizeof(*div), GFP_KERNEL);
if (!div)
return ERR_PTR(-ENOMEM);
div->reg = cpg->reg + CPG_ADSPCKCR;
div->width = 4;
div->table = cpg_adsp_div_table;
div->lock = &cpg->lock;
gate = kzalloc(sizeof(*gate), GFP_KERNEL);
if (!gate) {
kfree(div);
return ERR_PTR(-ENOMEM);
}
gate->reg = cpg->reg + CPG_ADSPCKCR;
gate->bit_idx = 8;
gate->flags = CLK_GATE_SET_TO_DISABLE;
gate->lock = &cpg->lock;
clk = clk_register_composite(NULL, "adsp", &parent_name, 1, NULL, NULL,
&div->hw, &clk_divider_ops,
&gate->hw, &clk_gate_ops, 0);
if (IS_ERR(clk)) {
kfree(gate);
kfree(div);
}
return clk;
}
static struct clk * __init
rcar_gen2_cpg_register_clock(struct device_node *np, struct rcar_gen2_cpg *cpg,
const struct cpg_pll_config *config,
const char *name)
{
const struct clk_div_table *table = NULL;
const char *parent_name;
unsigned int shift;
unsigned int mult = 1;
unsigned int div = 1;
if (!strcmp(name, "main")) {
parent_name = of_clk_get_parent_name(np, 0);
div = config->extal_div;
} else if (!strcmp(name, "pll0")) {
u32 value = clk_readl(cpg->reg + CPG_PLL0CR);
parent_name = "main";
mult = ((value >> 24) & ((1 << 7) - 1)) + 1;
} else if (!strcmp(name, "pll1")) {
parent_name = "main";
mult = config->pll1_mult / 2;
} else if (!strcmp(name, "pll3")) {
parent_name = "main";
mult = config->pll3_mult;
} else if (!strcmp(name, "lb")) {
parent_name = "pll1";
div = cpg_mode & BIT(18) ? 36 : 24;
} else if (!strcmp(name, "qspi")) {
parent_name = "pll1_div2";
div = (cpg_mode & (BIT(3) | BIT(2) | BIT(1))) == BIT(2)
? 8 : 10;
} else if (!strcmp(name, "sdh")) {
parent_name = "pll1";
table = cpg_sdh_div_table;
shift = 8;
} else if (!strcmp(name, "sd0")) {
parent_name = "pll1";
table = cpg_sd01_div_table;
shift = 4;
} else if (!strcmp(name, "sd1")) {
parent_name = "pll1";
table = cpg_sd01_div_table;
shift = 0;
} else if (!strcmp(name, "z")) {
return cpg_z_clk_register(cpg);
} else if (!strcmp(name, "rcan")) {
return cpg_rcan_clk_register(cpg, np);
} else if (!strcmp(name, "adsp")) {
return cpg_adsp_clk_register(cpg);
} else {
return ERR_PTR(-EINVAL);
}
if (!table)
return clk_register_fixed_factor(NULL, name, parent_name, 0,
mult, div);
else
return clk_register_divider_table(NULL, name, parent_name, 0,
cpg->reg + CPG_SDCKCR, shift,
4, 0, table, &cpg->lock);
}
static u32 __init rcar_gen2_read_mode_pins(void)
{
void __iomem *modemr = ioremap_nocache(MODEMR, 4);
u32 mode;
BUG_ON(!modemr);
mode = ioread32(modemr);
iounmap(modemr);
return mode;
}
static void __init rcar_gen2_cpg_clocks_init(struct device_node *np)
{
const struct cpg_pll_config *config;
struct rcar_gen2_cpg *cpg;
struct clk **clks;
unsigned int i;
int num_clks;
if (rcar_rst_read_mode_pins(&cpg_mode)) {
pr_warn("%s: failed to obtain mode pins from RST\n",
np->full_name);
cpg_mode = rcar_gen2_read_mode_pins();
}
num_clks = of_property_count_strings(np, "clock-output-names");
if (num_clks < 0) {
pr_err("%s: failed to count clocks\n", __func__);
return;
}
cpg = kzalloc(sizeof(*cpg), GFP_KERNEL);
clks = kzalloc(num_clks * sizeof(*clks), GFP_KERNEL);
if (cpg == NULL || clks == NULL) {
pr_err("%s: failed to allocate cpg\n", __func__);
return;
}
spin_lock_init(&cpg->lock);
cpg->data.clks = clks;
cpg->data.clk_num = num_clks;
cpg->reg = of_iomap(np, 0);
if (WARN_ON(cpg->reg == NULL))
return;
config = &cpg_pll_configs[CPG_PLL_CONFIG_INDEX(cpg_mode)];
for (i = 0; i < num_clks; ++i) {
const char *name;
struct clk *clk;
of_property_read_string_index(np, "clock-output-names", i,
&name);
clk = rcar_gen2_cpg_register_clock(np, cpg, config, name);
if (IS_ERR(clk))
pr_err("%s: failed to register %s %s clock (%ld)\n",
__func__, np->name, name, PTR_ERR(clk));
else
cpg->data.clks[i] = clk;
}
of_clk_add_provider(np, of_clk_src_onecell_get, &cpg->data);
cpg_mstp_add_clk_domain(np);
}
