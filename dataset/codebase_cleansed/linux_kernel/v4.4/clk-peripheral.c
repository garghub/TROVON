static int clk_peripheral_enable(struct clk_hw *hw)
{
struct clk_peripheral *periph = to_clk_peripheral(hw);
struct at91_pmc *pmc = periph->pmc;
int offset = AT91_PMC_PCER;
u32 id = periph->id;
if (id < PERIPHERAL_ID_MIN)
return 0;
if (id > PERIPHERAL_ID_MAX)
offset = AT91_PMC_PCER1;
pmc_write(pmc, offset, PERIPHERAL_MASK(id));
return 0;
}
static void clk_peripheral_disable(struct clk_hw *hw)
{
struct clk_peripheral *periph = to_clk_peripheral(hw);
struct at91_pmc *pmc = periph->pmc;
int offset = AT91_PMC_PCDR;
u32 id = periph->id;
if (id < PERIPHERAL_ID_MIN)
return;
if (id > PERIPHERAL_ID_MAX)
offset = AT91_PMC_PCDR1;
pmc_write(pmc, offset, PERIPHERAL_MASK(id));
}
static int clk_peripheral_is_enabled(struct clk_hw *hw)
{
struct clk_peripheral *periph = to_clk_peripheral(hw);
struct at91_pmc *pmc = periph->pmc;
int offset = AT91_PMC_PCSR;
u32 id = periph->id;
if (id < PERIPHERAL_ID_MIN)
return 1;
if (id > PERIPHERAL_ID_MAX)
offset = AT91_PMC_PCSR1;
return !!(pmc_read(pmc, offset) & PERIPHERAL_MASK(id));
}
static struct clk * __init
at91_clk_register_peripheral(struct at91_pmc *pmc, const char *name,
const char *parent_name, u32 id)
{
struct clk_peripheral *periph;
struct clk *clk = NULL;
struct clk_init_data init;
if (!pmc || !name || !parent_name || id > PERIPHERAL_ID_MAX)
return ERR_PTR(-EINVAL);
periph = kzalloc(sizeof(*periph), GFP_KERNEL);
if (!periph)
return ERR_PTR(-ENOMEM);
init.name = name;
init.ops = &peripheral_ops;
init.parent_names = (parent_name ? &parent_name : NULL);
init.num_parents = (parent_name ? 1 : 0);
init.flags = 0;
periph->id = id;
periph->hw.init = &init;
periph->pmc = pmc;
clk = clk_register(NULL, &periph->hw);
if (IS_ERR(clk))
kfree(periph);
return clk;
}
static void clk_sam9x5_peripheral_autodiv(struct clk_sam9x5_peripheral *periph)
{
struct clk_hw *parent;
unsigned long parent_rate;
int shift = 0;
if (!periph->auto_div)
return;
if (periph->range.max) {
parent = clk_hw_get_parent_by_index(&periph->hw, 0);
parent_rate = clk_hw_get_rate(parent);
if (!parent_rate)
return;
for (; shift < PERIPHERAL_MAX_SHIFT; shift++) {
if (parent_rate >> shift <= periph->range.max)
break;
}
}
periph->auto_div = false;
periph->div = shift;
}
static int clk_sam9x5_peripheral_enable(struct clk_hw *hw)
{
struct clk_sam9x5_peripheral *periph = to_clk_sam9x5_peripheral(hw);
struct at91_pmc *pmc = periph->pmc;
u32 tmp;
if (periph->id < PERIPHERAL_ID_MIN)
return 0;
pmc_lock(pmc);
pmc_write(pmc, AT91_PMC_PCR, (periph->id & AT91_PMC_PCR_PID_MASK));
tmp = pmc_read(pmc, AT91_PMC_PCR) & ~AT91_PMC_PCR_DIV_MASK;
pmc_write(pmc, AT91_PMC_PCR, tmp | AT91_PMC_PCR_DIV(periph->div)
| AT91_PMC_PCR_CMD
| AT91_PMC_PCR_EN);
pmc_unlock(pmc);
return 0;
}
static void clk_sam9x5_peripheral_disable(struct clk_hw *hw)
{
struct clk_sam9x5_peripheral *periph = to_clk_sam9x5_peripheral(hw);
struct at91_pmc *pmc = periph->pmc;
u32 tmp;
if (periph->id < PERIPHERAL_ID_MIN)
return;
pmc_lock(pmc);
pmc_write(pmc, AT91_PMC_PCR, (periph->id & AT91_PMC_PCR_PID_MASK));
tmp = pmc_read(pmc, AT91_PMC_PCR) & ~AT91_PMC_PCR_EN;
pmc_write(pmc, AT91_PMC_PCR, tmp | AT91_PMC_PCR_CMD);
pmc_unlock(pmc);
}
static int clk_sam9x5_peripheral_is_enabled(struct clk_hw *hw)
{
struct clk_sam9x5_peripheral *periph = to_clk_sam9x5_peripheral(hw);
struct at91_pmc *pmc = periph->pmc;
int ret;
if (periph->id < PERIPHERAL_ID_MIN)
return 1;
pmc_lock(pmc);
pmc_write(pmc, AT91_PMC_PCR, (periph->id & AT91_PMC_PCR_PID_MASK));
ret = !!(pmc_read(pmc, AT91_PMC_PCR) & AT91_PMC_PCR_EN);
pmc_unlock(pmc);
return ret;
}
static unsigned long
clk_sam9x5_peripheral_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct clk_sam9x5_peripheral *periph = to_clk_sam9x5_peripheral(hw);
struct at91_pmc *pmc = periph->pmc;
u32 tmp;
if (periph->id < PERIPHERAL_ID_MIN)
return parent_rate;
pmc_lock(pmc);
pmc_write(pmc, AT91_PMC_PCR, (periph->id & AT91_PMC_PCR_PID_MASK));
tmp = pmc_read(pmc, AT91_PMC_PCR);
pmc_unlock(pmc);
if (tmp & AT91_PMC_PCR_EN) {
periph->div = PERIPHERAL_RSHIFT(tmp);
periph->auto_div = false;
} else {
clk_sam9x5_peripheral_autodiv(periph);
}
return parent_rate >> periph->div;
}
static long clk_sam9x5_peripheral_round_rate(struct clk_hw *hw,
unsigned long rate,
unsigned long *parent_rate)
{
int shift = 0;
unsigned long best_rate;
unsigned long best_diff;
unsigned long cur_rate = *parent_rate;
unsigned long cur_diff;
struct clk_sam9x5_peripheral *periph = to_clk_sam9x5_peripheral(hw);
if (periph->id < PERIPHERAL_ID_MIN || !periph->range.max)
return *parent_rate;
if (periph->range.max) {
for (; shift <= PERIPHERAL_MAX_SHIFT; shift++) {
cur_rate = *parent_rate >> shift;
if (cur_rate <= periph->range.max)
break;
}
}
if (rate >= cur_rate)
return cur_rate;
best_diff = cur_rate - rate;
best_rate = cur_rate;
for (; shift <= PERIPHERAL_MAX_SHIFT; shift++) {
cur_rate = *parent_rate >> shift;
if (cur_rate < rate)
cur_diff = rate - cur_rate;
else
cur_diff = cur_rate - rate;
if (cur_diff < best_diff) {
best_diff = cur_diff;
best_rate = cur_rate;
}
if (!best_diff || cur_rate < rate)
break;
}
return best_rate;
}
static int clk_sam9x5_peripheral_set_rate(struct clk_hw *hw,
unsigned long rate,
unsigned long parent_rate)
{
int shift;
struct clk_sam9x5_peripheral *periph = to_clk_sam9x5_peripheral(hw);
if (periph->id < PERIPHERAL_ID_MIN || !periph->range.max) {
if (parent_rate == rate)
return 0;
else
return -EINVAL;
}
if (periph->range.max && rate > periph->range.max)
return -EINVAL;
for (shift = 0; shift <= PERIPHERAL_MAX_SHIFT; shift++) {
if (parent_rate >> shift == rate) {
periph->auto_div = false;
periph->div = shift;
return 0;
}
}
return -EINVAL;
}
static struct clk * __init
at91_clk_register_sam9x5_peripheral(struct at91_pmc *pmc, const char *name,
const char *parent_name, u32 id,
const struct clk_range *range)
{
struct clk_sam9x5_peripheral *periph;
struct clk *clk = NULL;
struct clk_init_data init;
if (!pmc || !name || !parent_name)
return ERR_PTR(-EINVAL);
periph = kzalloc(sizeof(*periph), GFP_KERNEL);
if (!periph)
return ERR_PTR(-ENOMEM);
init.name = name;
init.ops = &sam9x5_peripheral_ops;
init.parent_names = (parent_name ? &parent_name : NULL);
init.num_parents = (parent_name ? 1 : 0);
init.flags = 0;
periph->id = id;
periph->hw.init = &init;
periph->div = 0;
periph->pmc = pmc;
periph->auto_div = true;
periph->range = *range;
clk = clk_register(NULL, &periph->hw);
if (IS_ERR(clk))
kfree(periph);
else
clk_sam9x5_peripheral_autodiv(periph);
return clk;
}
static void __init
of_at91_clk_periph_setup(struct device_node *np, struct at91_pmc *pmc, u8 type)
{
int num;
u32 id;
struct clk *clk;
const char *parent_name;
const char *name;
struct device_node *periphclknp;
parent_name = of_clk_get_parent_name(np, 0);
if (!parent_name)
return;
num = of_get_child_count(np);
if (!num || num > PERIPHERAL_MAX)
return;
for_each_child_of_node(np, periphclknp) {
if (of_property_read_u32(periphclknp, "reg", &id))
continue;
if (id >= PERIPHERAL_MAX)
continue;
if (of_property_read_string(np, "clock-output-names", &name))
name = periphclknp->name;
if (type == PERIPHERAL_AT91RM9200) {
clk = at91_clk_register_peripheral(pmc, name,
parent_name, id);
} else {
struct clk_range range = CLK_RANGE(0, 0);
of_at91_get_clk_range(periphclknp,
"atmel,clk-output-range",
&range);
clk = at91_clk_register_sam9x5_peripheral(pmc, name,
parent_name,
id, &range);
}
if (IS_ERR(clk))
continue;
of_clk_add_provider(periphclknp, of_clk_src_simple_get, clk);
}
}
void __init of_at91rm9200_clk_periph_setup(struct device_node *np,
struct at91_pmc *pmc)
{
of_at91_clk_periph_setup(np, pmc, PERIPHERAL_AT91RM9200);
}
void __init of_at91sam9x5_clk_periph_setup(struct device_node *np,
struct at91_pmc *pmc)
{
of_at91_clk_periph_setup(np, pmc, PERIPHERAL_AT91SAM9X5);
}
