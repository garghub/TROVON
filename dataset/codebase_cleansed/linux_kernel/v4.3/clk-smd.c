static unsigned long at91sam9x5_clk_smd_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
u32 tmp;
u8 smddiv;
struct at91sam9x5_clk_smd *smd = to_at91sam9x5_clk_smd(hw);
struct at91_pmc *pmc = smd->pmc;
tmp = pmc_read(pmc, AT91_PMC_SMD);
smddiv = (tmp & AT91_PMC_SMD_DIV) >> SMD_DIV_SHIFT;
return parent_rate / (smddiv + 1);
}
static long at91sam9x5_clk_smd_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *parent_rate)
{
unsigned long div;
unsigned long bestrate;
unsigned long tmp;
if (rate >= *parent_rate)
return *parent_rate;
div = *parent_rate / rate;
if (div > SMD_MAX_DIV)
return *parent_rate / (SMD_MAX_DIV + 1);
bestrate = *parent_rate / div;
tmp = *parent_rate / (div + 1);
if (bestrate - rate > rate - tmp)
bestrate = tmp;
return bestrate;
}
static int at91sam9x5_clk_smd_set_parent(struct clk_hw *hw, u8 index)
{
u32 tmp;
struct at91sam9x5_clk_smd *smd = to_at91sam9x5_clk_smd(hw);
struct at91_pmc *pmc = smd->pmc;
if (index > 1)
return -EINVAL;
tmp = pmc_read(pmc, AT91_PMC_SMD) & ~AT91_PMC_SMDS;
if (index)
tmp |= AT91_PMC_SMDS;
pmc_write(pmc, AT91_PMC_SMD, tmp);
return 0;
}
static u8 at91sam9x5_clk_smd_get_parent(struct clk_hw *hw)
{
struct at91sam9x5_clk_smd *smd = to_at91sam9x5_clk_smd(hw);
struct at91_pmc *pmc = smd->pmc;
return pmc_read(pmc, AT91_PMC_SMD) & AT91_PMC_SMDS;
}
static int at91sam9x5_clk_smd_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
u32 tmp;
struct at91sam9x5_clk_smd *smd = to_at91sam9x5_clk_smd(hw);
struct at91_pmc *pmc = smd->pmc;
unsigned long div = parent_rate / rate;
if (parent_rate % rate || div < 1 || div > (SMD_MAX_DIV + 1))
return -EINVAL;
tmp = pmc_read(pmc, AT91_PMC_SMD) & ~AT91_PMC_SMD_DIV;
tmp |= (div - 1) << SMD_DIV_SHIFT;
pmc_write(pmc, AT91_PMC_SMD, tmp);
return 0;
}
static struct clk * __init
at91sam9x5_clk_register_smd(struct at91_pmc *pmc, const char *name,
const char **parent_names, u8 num_parents)
{
struct at91sam9x5_clk_smd *smd;
struct clk *clk = NULL;
struct clk_init_data init;
smd = kzalloc(sizeof(*smd), GFP_KERNEL);
if (!smd)
return ERR_PTR(-ENOMEM);
init.name = name;
init.ops = &at91sam9x5_smd_ops;
init.parent_names = parent_names;
init.num_parents = num_parents;
init.flags = CLK_SET_RATE_GATE | CLK_SET_PARENT_GATE;
smd->hw.init = &init;
smd->pmc = pmc;
clk = clk_register(NULL, &smd->hw);
if (IS_ERR(clk))
kfree(smd);
return clk;
}
void __init of_at91sam9x5_clk_smd_setup(struct device_node *np,
struct at91_pmc *pmc)
{
struct clk *clk;
int num_parents;
const char *parent_names[SMD_SOURCE_MAX];
const char *name = np->name;
num_parents = of_clk_get_parent_count(np);
if (num_parents <= 0 || num_parents > SMD_SOURCE_MAX)
return;
of_clk_parent_fill(np, parent_names, num_parents);
of_property_read_string(np, "clock-output-names", &name);
clk = at91sam9x5_clk_register_smd(pmc, name, parent_names,
num_parents);
if (IS_ERR(clk))
return;
of_clk_add_provider(np, of_clk_src_simple_get, clk);
}
