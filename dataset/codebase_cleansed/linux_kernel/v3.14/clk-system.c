static int clk_system_enable(struct clk_hw *hw)
{
struct clk_system *sys = to_clk_system(hw);
struct at91_pmc *pmc = sys->pmc;
pmc_write(pmc, AT91_PMC_SCER, 1 << sys->id);
return 0;
}
static void clk_system_disable(struct clk_hw *hw)
{
struct clk_system *sys = to_clk_system(hw);
struct at91_pmc *pmc = sys->pmc;
pmc_write(pmc, AT91_PMC_SCDR, 1 << sys->id);
}
static int clk_system_is_enabled(struct clk_hw *hw)
{
struct clk_system *sys = to_clk_system(hw);
struct at91_pmc *pmc = sys->pmc;
return !!(pmc_read(pmc, AT91_PMC_SCSR) & (1 << sys->id));
}
static struct clk * __init
at91_clk_register_system(struct at91_pmc *pmc, const char *name,
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
init.flags = CLK_IGNORE_UNUSED;
sys->id = id;
sys->hw.init = &init;
sys->pmc = pmc;
clk = clk_register(NULL, &sys->hw);
if (IS_ERR(clk))
kfree(sys);
return clk;
}
static void __init
of_at91_clk_sys_setup(struct device_node *np, struct at91_pmc *pmc)
{
int num;
u32 id;
struct clk *clk;
const char *name;
struct device_node *sysclknp;
const char *parent_name;
num = of_get_child_count(np);
if (num > (SYSTEM_MAX_ID + 1))
return;
for_each_child_of_node(np, sysclknp) {
if (of_property_read_u32(sysclknp, "reg", &id))
continue;
if (of_property_read_string(np, "clock-output-names", &name))
name = sysclknp->name;
parent_name = of_clk_get_parent_name(sysclknp, 0);
clk = at91_clk_register_system(pmc, name, parent_name, id);
if (IS_ERR(clk))
continue;
of_clk_add_provider(sysclknp, of_clk_src_simple_get, clk);
}
}
void __init of_at91rm9200_clk_sys_setup(struct device_node *np,
struct at91_pmc *pmc)
{
of_at91_clk_sys_setup(np, pmc);
}
