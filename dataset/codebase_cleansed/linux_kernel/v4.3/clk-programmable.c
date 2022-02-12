static unsigned long clk_programmable_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
u32 pres;
struct clk_programmable *prog = to_clk_programmable(hw);
struct at91_pmc *pmc = prog->pmc;
const struct clk_programmable_layout *layout = prog->layout;
pres = (pmc_read(pmc, AT91_PMC_PCKR(prog->id)) >> layout->pres_shift) &
PROG_PRES_MASK;
return parent_rate >> pres;
}
static int clk_programmable_determine_rate(struct clk_hw *hw,
struct clk_rate_request *req)
{
struct clk_hw *parent;
long best_rate = -EINVAL;
unsigned long parent_rate;
unsigned long tmp_rate;
int shift;
int i;
for (i = 0; i < clk_hw_get_num_parents(hw); i++) {
parent = clk_hw_get_parent_by_index(hw, i);
if (!parent)
continue;
parent_rate = clk_hw_get_rate(parent);
for (shift = 0; shift < PROG_PRES_MASK; shift++) {
tmp_rate = parent_rate >> shift;
if (tmp_rate <= req->rate)
break;
}
if (tmp_rate > req->rate)
continue;
if (best_rate < 0 ||
(req->rate - tmp_rate) < (req->rate - best_rate)) {
best_rate = tmp_rate;
req->best_parent_rate = parent_rate;
req->best_parent_hw = parent;
}
if (!best_rate)
break;
}
if (best_rate < 0)
return best_rate;
req->rate = best_rate;
return 0;
}
static int clk_programmable_set_parent(struct clk_hw *hw, u8 index)
{
struct clk_programmable *prog = to_clk_programmable(hw);
const struct clk_programmable_layout *layout = prog->layout;
struct at91_pmc *pmc = prog->pmc;
u32 tmp = pmc_read(pmc, AT91_PMC_PCKR(prog->id)) & ~layout->css_mask;
if (layout->have_slck_mck)
tmp &= AT91_PMC_CSSMCK_MCK;
if (index > layout->css_mask) {
if (index > PROG_MAX_RM9200_CSS && layout->have_slck_mck) {
tmp |= AT91_PMC_CSSMCK_MCK;
return 0;
} else {
return -EINVAL;
}
}
pmc_write(pmc, AT91_PMC_PCKR(prog->id), tmp | index);
return 0;
}
static u8 clk_programmable_get_parent(struct clk_hw *hw)
{
u32 tmp;
u8 ret;
struct clk_programmable *prog = to_clk_programmable(hw);
struct at91_pmc *pmc = prog->pmc;
const struct clk_programmable_layout *layout = prog->layout;
tmp = pmc_read(pmc, AT91_PMC_PCKR(prog->id));
ret = tmp & layout->css_mask;
if (layout->have_slck_mck && (tmp & AT91_PMC_CSSMCK_MCK) && !ret)
ret = PROG_MAX_RM9200_CSS + 1;
return ret;
}
static int clk_programmable_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct clk_programmable *prog = to_clk_programmable(hw);
struct at91_pmc *pmc = prog->pmc;
const struct clk_programmable_layout *layout = prog->layout;
unsigned long div = parent_rate / rate;
int shift = 0;
u32 tmp = pmc_read(pmc, AT91_PMC_PCKR(prog->id)) &
~(PROG_PRES_MASK << layout->pres_shift);
if (!div)
return -EINVAL;
shift = fls(div) - 1;
if (div != (1<<shift))
return -EINVAL;
if (shift >= PROG_PRES_MASK)
return -EINVAL;
pmc_write(pmc, AT91_PMC_PCKR(prog->id),
tmp | (shift << layout->pres_shift));
return 0;
}
static struct clk * __init
at91_clk_register_programmable(struct at91_pmc *pmc,
const char *name, const char **parent_names,
u8 num_parents, u8 id,
const struct clk_programmable_layout *layout)
{
struct clk_programmable *prog;
struct clk *clk = NULL;
struct clk_init_data init;
if (id > PROG_ID_MAX)
return ERR_PTR(-EINVAL);
prog = kzalloc(sizeof(*prog), GFP_KERNEL);
if (!prog)
return ERR_PTR(-ENOMEM);
init.name = name;
init.ops = &programmable_ops;
init.parent_names = parent_names;
init.num_parents = num_parents;
init.flags = CLK_SET_RATE_GATE | CLK_SET_PARENT_GATE;
prog->id = id;
prog->layout = layout;
prog->hw.init = &init;
prog->pmc = pmc;
clk = clk_register(NULL, &prog->hw);
if (IS_ERR(clk))
kfree(prog);
return clk;
}
static void __init
of_at91_clk_prog_setup(struct device_node *np, struct at91_pmc *pmc,
const struct clk_programmable_layout *layout)
{
int num;
u32 id;
struct clk *clk;
int num_parents;
const char *parent_names[PROG_SOURCE_MAX];
const char *name;
struct device_node *progclknp;
num_parents = of_clk_get_parent_count(np);
if (num_parents <= 0 || num_parents > PROG_SOURCE_MAX)
return;
of_clk_parent_fill(np, parent_names, num_parents);
num = of_get_child_count(np);
if (!num || num > (PROG_ID_MAX + 1))
return;
for_each_child_of_node(np, progclknp) {
if (of_property_read_u32(progclknp, "reg", &id))
continue;
if (of_property_read_string(np, "clock-output-names", &name))
name = progclknp->name;
clk = at91_clk_register_programmable(pmc, name,
parent_names, num_parents,
id, layout);
if (IS_ERR(clk))
continue;
of_clk_add_provider(progclknp, of_clk_src_simple_get, clk);
}
}
void __init of_at91rm9200_clk_prog_setup(struct device_node *np,
struct at91_pmc *pmc)
{
of_at91_clk_prog_setup(np, pmc, &at91rm9200_programmable_layout);
}
void __init of_at91sam9g45_clk_prog_setup(struct device_node *np,
struct at91_pmc *pmc)
{
of_at91_clk_prog_setup(np, pmc, &at91sam9g45_programmable_layout);
}
void __init of_at91sam9x5_clk_prog_setup(struct device_node *np,
struct at91_pmc *pmc)
{
of_at91_clk_prog_setup(np, pmc, &at91sam9x5_programmable_layout);
}
