static unsigned long cpg_z_clk_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct cpg_z_clk *zclk = to_z_clk(hw);
unsigned int mult;
unsigned int val;
val = (readl(zclk->reg) & CPG_FRQCRC_ZFC_MASK) >> CPG_FRQCRC_ZFC_SHIFT;
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
if (readl(zclk->kick_reg) & CPG_FRQCRB_KICK)
return -EBUSY;
val = readl(zclk->reg);
val &= ~CPG_FRQCRC_ZFC_MASK;
val |= (32 - mult) << CPG_FRQCRC_ZFC_SHIFT;
writel(val, zclk->reg);
kick = readl(zclk->kick_reg);
kick |= CPG_FRQCRB_KICK;
writel(kick, zclk->kick_reg);
for (i = 1000; i; i--) {
if (!(readl(zclk->kick_reg) & CPG_FRQCRB_KICK))
return 0;
cpu_relax();
}
return -ETIMEDOUT;
}
static struct clk * __init cpg_z_clk_register(const char *name,
const char *parent_name,
void __iomem *base)
{
struct clk_init_data init;
struct cpg_z_clk *zclk;
struct clk *clk;
zclk = kzalloc(sizeof(*zclk), GFP_KERNEL);
if (!zclk)
return ERR_PTR(-ENOMEM);
init.name = name;
init.ops = &cpg_z_clk_ops;
init.flags = 0;
init.parent_names = &parent_name;
init.num_parents = 1;
zclk->reg = base + CPG_FRQCRC;
zclk->kick_reg = base + CPG_FRQCRB;
zclk->hw.init = &init;
clk = clk_register(NULL, &zclk->hw);
if (IS_ERR(clk))
kfree(zclk);
return clk;
}
static struct clk * __init cpg_rcan_clk_register(const char *name,
const char *parent_name,
void __iomem *base)
{
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
gate->reg = base + CPG_RCANCKCR;
gate->bit_idx = 8;
gate->flags = CLK_GATE_SET_TO_DISABLE;
gate->lock = &cpg_lock;
clk = clk_register_composite(NULL, name, &parent_name, 1, NULL, NULL,
&fixed->hw, &clk_fixed_factor_ops,
&gate->hw, &clk_gate_ops, 0);
if (IS_ERR(clk)) {
kfree(gate);
kfree(fixed);
}
return clk;
}
static struct clk * __init cpg_adsp_clk_register(const char *name,
const char *parent_name,
void __iomem *base)
{
struct clk_divider *div;
struct clk_gate *gate;
struct clk *clk;
div = kzalloc(sizeof(*div), GFP_KERNEL);
if (!div)
return ERR_PTR(-ENOMEM);
div->reg = base + CPG_ADSPCKCR;
div->width = 4;
div->table = cpg_adsp_div_table;
div->lock = &cpg_lock;
gate = kzalloc(sizeof(*gate), GFP_KERNEL);
if (!gate) {
kfree(div);
return ERR_PTR(-ENOMEM);
}
gate->reg = base + CPG_ADSPCKCR;
gate->bit_idx = 8;
gate->flags = CLK_GATE_SET_TO_DISABLE;
gate->lock = &cpg_lock;
clk = clk_register_composite(NULL, name, &parent_name, 1, NULL, NULL,
&div->hw, &clk_divider_ops,
&gate->hw, &clk_gate_ops, 0);
if (IS_ERR(clk)) {
kfree(gate);
kfree(div);
}
return clk;
}
struct clk * __init rcar_gen2_cpg_clk_register(struct device *dev,
const struct cpg_core_clk *core,
const struct cpg_mssr_info *info,
struct clk **clks,
void __iomem *base)
{
const struct clk_div_table *table = NULL;
const struct clk *parent;
const char *parent_name;
unsigned int mult = 1;
unsigned int div = 1;
unsigned int shift;
parent = clks[core->parent];
if (IS_ERR(parent))
return ERR_CAST(parent);
parent_name = __clk_get_name(parent);
switch (core->type) {
case CLK_TYPE_GEN2_MAIN:
div = cpg_pll_config->extal_div;
break;
case CLK_TYPE_GEN2_PLL0:
mult = cpg_pll_config->pll0_mult;
div = cpg_pll0_div;
if (!mult) {
u32 pll0cr = readl(base + CPG_PLL0CR);
mult = (((pll0cr & CPG_PLL0CR_STC_MASK) >>
CPG_PLL0CR_STC_SHIFT) + 1) * 2;
}
break;
case CLK_TYPE_GEN2_PLL1:
mult = cpg_pll_config->pll1_mult / 2;
break;
case CLK_TYPE_GEN2_PLL3:
mult = cpg_pll_config->pll3_mult;
break;
case CLK_TYPE_GEN2_Z:
return cpg_z_clk_register(core->name, parent_name, base);
case CLK_TYPE_GEN2_LB:
div = cpg_mode & BIT(18) ? 36 : 24;
break;
case CLK_TYPE_GEN2_ADSP:
return cpg_adsp_clk_register(core->name, parent_name, base);
case CLK_TYPE_GEN2_SDH:
table = cpg_sdh_div_table;
shift = 8;
break;
case CLK_TYPE_GEN2_SD0:
table = cpg_sd01_div_table;
shift = 4;
break;
case CLK_TYPE_GEN2_SD1:
table = cpg_sd01_div_table;
shift = 0;
break;
case CLK_TYPE_GEN2_QSPI:
div = (cpg_mode & (BIT(3) | BIT(2) | BIT(1))) == BIT(2) ?
8 : 10;
break;
case CLK_TYPE_GEN2_RCAN:
return cpg_rcan_clk_register(core->name, parent_name, base);
default:
return ERR_PTR(-EINVAL);
}
if (!table)
return clk_register_fixed_factor(NULL, core->name, parent_name,
0, mult, div);
else
return clk_register_divider_table(NULL, core->name,
parent_name, 0,
base + CPG_SDCKCR, shift, 4,
0, table, &cpg_lock);
}
int __init rcar_gen2_cpg_init(const struct rcar_gen2_cpg_pll_config *config,
unsigned int pll0_div, u32 mode)
{
cpg_pll_config = config;
cpg_pll0_div = pll0_div;
cpg_mode = mode;
spin_lock_init(&cpg_lock);
return 0;
}
