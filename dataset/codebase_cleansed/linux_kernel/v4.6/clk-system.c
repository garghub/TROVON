static inline int is_pck(int id)
{
return (id >= 8) && (id <= 15);
}
static inline bool clk_system_ready(struct regmap *regmap, int id)
{
unsigned int status;
regmap_read(regmap, AT91_PMC_SR, &status);
return status & (1 << id) ? 1 : 0;
}
static int clk_system_prepare(struct clk_hw *hw)
{
struct clk_system *sys = to_clk_system(hw);
regmap_write(sys->regmap, AT91_PMC_SCER, 1 << sys->id);
if (!is_pck(sys->id))
return 0;
while (!clk_system_ready(sys->regmap, sys->id))
cpu_relax();
return 0;
}
static void clk_system_unprepare(struct clk_hw *hw)
{
struct clk_system *sys = to_clk_system(hw);
regmap_write(sys->regmap, AT91_PMC_SCDR, 1 << sys->id);
}
static int clk_system_is_prepared(struct clk_hw *hw)
{
struct clk_system *sys = to_clk_system(hw);
unsigned int status;
regmap_read(sys->regmap, AT91_PMC_SCSR, &status);
if (!(status & (1 << sys->id)))
return 0;
if (!is_pck(sys->id))
return 1;
regmap_read(sys->regmap, AT91_PMC_SR, &status);
return status & (1 << sys->id) ? 1 : 0;
}
static struct clk * __init
at91_clk_register_system(struct regmap *regmap, const char *name,
const char *parent_name, u8 id)
{
struct clk_system *sys;
struct clk *clk = NULL;
struct clk_init_data init;
if (!parent_name || id > SYSTEM_MAX_ID)
return ERR_PTR(-EINVAL);
sys = kzalloc(sizeof(*sys), GFP_KERNEL);
if (!sys)
return ERR_PTR(-ENOMEM);
init.name = name;
init.ops = &system_ops;
init.parent_names = &parent_name;
init.num_parents = 1;
init.flags = CLK_SET_RATE_PARENT;
sys->id = id;
sys->hw.init = &init;
sys->regmap = regmap;
clk = clk_register(NULL, &sys->hw);
if (IS_ERR(clk))
kfree(sys);
return clk;
}
static void __init of_at91rm9200_clk_sys_setup(struct device_node *np)
{
int num;
u32 id;
struct clk *clk;
const char *name;
struct device_node *sysclknp;
const char *parent_name;
struct regmap *regmap;
num = of_get_child_count(np);
if (num > (SYSTEM_MAX_ID + 1))
return;
regmap = syscon_node_to_regmap(of_get_parent(np));
if (IS_ERR(regmap))
return;
for_each_child_of_node(np, sysclknp) {
if (of_property_read_u32(sysclknp, "reg", &id))
continue;
if (of_property_read_string(np, "clock-output-names", &name))
name = sysclknp->name;
parent_name = of_clk_get_parent_name(sysclknp, 0);
clk = at91_clk_register_system(regmap, name, parent_name, id);
if (IS_ERR(clk))
continue;
of_clk_add_provider(sysclknp, of_clk_src_simple_get, clk);
}
}
