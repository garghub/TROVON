static inline bool clk_utmi_ready(struct regmap *regmap)
{
unsigned int status;
regmap_read(regmap, AT91_PMC_SR, &status);
return status & AT91_PMC_LOCKU;
}
static int clk_utmi_prepare(struct clk_hw *hw)
{
struct clk_utmi *utmi = to_clk_utmi(hw);
unsigned int uckr = AT91_PMC_UPLLEN | AT91_PMC_UPLLCOUNT |
AT91_PMC_BIASEN;
regmap_update_bits(utmi->regmap, AT91_CKGR_UCKR, uckr, uckr);
while (!clk_utmi_ready(utmi->regmap))
cpu_relax();
return 0;
}
static int clk_utmi_is_prepared(struct clk_hw *hw)
{
struct clk_utmi *utmi = to_clk_utmi(hw);
return clk_utmi_ready(utmi->regmap);
}
static void clk_utmi_unprepare(struct clk_hw *hw)
{
struct clk_utmi *utmi = to_clk_utmi(hw);
regmap_update_bits(utmi->regmap, AT91_CKGR_UCKR, AT91_PMC_UPLLEN, 0);
}
static unsigned long clk_utmi_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
return parent_rate * UTMI_FIXED_MUL;
}
static struct clk_hw * __init
at91_clk_register_utmi(struct regmap *regmap,
const char *name, const char *parent_name)
{
struct clk_utmi *utmi;
struct clk_hw *hw;
struct clk_init_data init;
int ret;
utmi = kzalloc(sizeof(*utmi), GFP_KERNEL);
if (!utmi)
return ERR_PTR(-ENOMEM);
init.name = name;
init.ops = &utmi_ops;
init.parent_names = parent_name ? &parent_name : NULL;
init.num_parents = parent_name ? 1 : 0;
init.flags = CLK_SET_RATE_GATE;
utmi->hw.init = &init;
utmi->regmap = regmap;
hw = &utmi->hw;
ret = clk_hw_register(NULL, &utmi->hw);
if (ret) {
kfree(utmi);
hw = ERR_PTR(ret);
}
return hw;
}
static void __init of_at91sam9x5_clk_utmi_setup(struct device_node *np)
{
struct clk_hw *hw;
const char *parent_name;
const char *name = np->name;
struct regmap *regmap;
parent_name = of_clk_get_parent_name(np, 0);
of_property_read_string(np, "clock-output-names", &name);
regmap = syscon_node_to_regmap(of_get_parent(np));
if (IS_ERR(regmap))
return;
hw = at91_clk_register_utmi(regmap, name, parent_name);
if (IS_ERR(hw))
return;
of_clk_add_hw_provider(np, of_clk_hw_simple_get, hw);
return;
}
