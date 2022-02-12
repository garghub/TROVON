static int cpg_sd_clock_enable(struct clk_hw *hw)
{
struct sd_clock *clock = to_sd_clock(hw);
u32 val, sd_fc;
unsigned int i;
val = readl(clock->reg);
sd_fc = val & CPG_SD_FC_MASK;
for (i = 0; i < clock->div_num; i++)
if (sd_fc == (clock->div_table[i].val & CPG_SD_FC_MASK))
break;
if (i >= clock->div_num)
return -EINVAL;
val &= ~(CPG_SD_STP_MASK);
val |= clock->div_table[i].val & CPG_SD_STP_MASK;
writel(val, clock->reg);
return 0;
}
static void cpg_sd_clock_disable(struct clk_hw *hw)
{
struct sd_clock *clock = to_sd_clock(hw);
writel(readl(clock->reg) | CPG_SD_STP_MASK, clock->reg);
}
static int cpg_sd_clock_is_enabled(struct clk_hw *hw)
{
struct sd_clock *clock = to_sd_clock(hw);
return !(readl(clock->reg) & CPG_SD_STP_MASK);
}
static unsigned long cpg_sd_clock_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct sd_clock *clock = to_sd_clock(hw);
unsigned long rate = parent_rate;
u32 val, sd_fc;
unsigned int i;
val = readl(clock->reg);
sd_fc = val & CPG_SD_FC_MASK;
for (i = 0; i < clock->div_num; i++)
if (sd_fc == (clock->div_table[i].val & CPG_SD_FC_MASK))
break;
if (i >= clock->div_num)
return -EINVAL;
return DIV_ROUND_CLOSEST(rate, clock->div_table[i].div);
}
static unsigned int cpg_sd_clock_calc_div(struct sd_clock *clock,
unsigned long rate,
unsigned long parent_rate)
{
unsigned int div;
if (!rate)
rate = 1;
div = DIV_ROUND_CLOSEST(parent_rate, rate);
return clamp_t(unsigned int, div, clock->div_min, clock->div_max);
}
static long cpg_sd_clock_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *parent_rate)
{
struct sd_clock *clock = to_sd_clock(hw);
unsigned int div = cpg_sd_clock_calc_div(clock, rate, *parent_rate);
return DIV_ROUND_CLOSEST(*parent_rate, div);
}
static int cpg_sd_clock_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct sd_clock *clock = to_sd_clock(hw);
unsigned int div = cpg_sd_clock_calc_div(clock, rate, parent_rate);
u32 val;
unsigned int i;
for (i = 0; i < clock->div_num; i++)
if (div == clock->div_table[i].div)
break;
if (i >= clock->div_num)
return -EINVAL;
val = readl(clock->reg);
val &= ~(CPG_SD_STP_MASK | CPG_SD_FC_MASK);
val |= clock->div_table[i].val & (CPG_SD_STP_MASK | CPG_SD_FC_MASK);
writel(val, clock->reg);
return 0;
}
static struct clk * __init cpg_sd_clk_register(const struct cpg_core_clk *core,
void __iomem *base,
const char *parent_name)
{
struct clk_init_data init;
struct sd_clock *clock;
struct clk *clk;
unsigned int i;
clock = kzalloc(sizeof(*clock), GFP_KERNEL);
if (!clock)
return ERR_PTR(-ENOMEM);
init.name = core->name;
init.ops = &cpg_sd_clock_ops;
init.flags = CLK_IS_BASIC | CLK_SET_RATE_PARENT;
init.parent_names = &parent_name;
init.num_parents = 1;
clock->reg = base + core->offset;
clock->hw.init = &init;
clock->div_table = cpg_sd_div_table;
clock->div_num = ARRAY_SIZE(cpg_sd_div_table);
clock->div_max = clock->div_table[0].div;
clock->div_min = clock->div_max;
for (i = 1; i < clock->div_num; i++) {
clock->div_max = max(clock->div_max, clock->div_table[i].div);
clock->div_min = min(clock->div_min, clock->div_table[i].div);
}
clk = clk_register(NULL, &clock->hw);
if (IS_ERR(clk))
kfree(clock);
return clk;
}
struct clk * __init rcar_gen3_cpg_clk_register(struct device *dev,
const struct cpg_core_clk *core, const struct cpg_mssr_info *info,
struct clk **clks, void __iomem *base)
{
const struct clk *parent;
unsigned int mult = 1;
unsigned int div = 1;
u32 value;
parent = clks[core->parent];
if (IS_ERR(parent))
return ERR_CAST(parent);
switch (core->type) {
case CLK_TYPE_GEN3_MAIN:
div = cpg_pll_config->extal_div;
break;
case CLK_TYPE_GEN3_PLL0:
value = readl(base + CPG_PLL0CR);
mult = (((value >> 24) & 0x7f) + 1) * 2;
if (cpg_quirks & PLL_ERRATA)
mult *= 2;
break;
case CLK_TYPE_GEN3_PLL1:
mult = cpg_pll_config->pll1_mult;
break;
case CLK_TYPE_GEN3_PLL2:
value = readl(base + CPG_PLL2CR);
mult = (((value >> 24) & 0x7f) + 1) * 2;
if (cpg_quirks & PLL_ERRATA)
mult *= 2;
break;
case CLK_TYPE_GEN3_PLL3:
mult = cpg_pll_config->pll3_mult;
break;
case CLK_TYPE_GEN3_PLL4:
value = readl(base + CPG_PLL4CR);
mult = (((value >> 24) & 0x7f) + 1) * 2;
if (cpg_quirks & PLL_ERRATA)
mult *= 2;
break;
case CLK_TYPE_GEN3_SD:
return cpg_sd_clk_register(core, base, __clk_get_name(parent));
case CLK_TYPE_GEN3_R:
if (cpg_quirks & RCKCR_CKSEL) {
value = readl(base + CPG_RCKCR) & 0x3f;
if (clk_get_rate(clks[cpg_clk_extalr])) {
parent = clks[cpg_clk_extalr];
value |= BIT(15);
}
writel(value, base + CPG_RCKCR);
break;
}
if (cpg_mode & BIT(28))
parent = clks[cpg_clk_extalr];
break;
default:
return ERR_PTR(-EINVAL);
}
return clk_register_fixed_factor(NULL, core->name,
__clk_get_name(parent), 0, mult, div);
}
int __init rcar_gen3_cpg_init(const struct rcar_gen3_cpg_pll_config *config,
unsigned int clk_extalr, u32 mode)
{
const struct soc_device_attribute *attr;
cpg_pll_config = config;
cpg_clk_extalr = clk_extalr;
cpg_mode = mode;
attr = soc_device_match(cpg_quirks_match);
if (attr)
cpg_quirks = (uintptr_t)attr->data;
pr_debug("%s: mode = 0x%x quirks = 0x%x\n", __func__, mode, cpg_quirks);
return 0;
}
