static irqreturn_t clk_utmi_irq_handler(int irq, void *dev_id)
{
struct clk_utmi *utmi = (struct clk_utmi *)dev_id;
wake_up(&utmi->wait);
disable_irq_nosync(utmi->irq);
return IRQ_HANDLED;
}
static int clk_utmi_prepare(struct clk_hw *hw)
{
struct clk_utmi *utmi = to_clk_utmi(hw);
struct at91_pmc *pmc = utmi->pmc;
u32 tmp = at91_pmc_read(AT91_CKGR_UCKR) | AT91_PMC_UPLLEN |
AT91_PMC_UPLLCOUNT | AT91_PMC_BIASEN;
pmc_write(pmc, AT91_CKGR_UCKR, tmp);
while (!(pmc_read(pmc, AT91_PMC_SR) & AT91_PMC_LOCKU)) {
enable_irq(utmi->irq);
wait_event(utmi->wait,
pmc_read(pmc, AT91_PMC_SR) & AT91_PMC_LOCKU);
}
return 0;
}
static int clk_utmi_is_prepared(struct clk_hw *hw)
{
struct clk_utmi *utmi = to_clk_utmi(hw);
struct at91_pmc *pmc = utmi->pmc;
return !!(pmc_read(pmc, AT91_PMC_SR) & AT91_PMC_LOCKU);
}
static void clk_utmi_unprepare(struct clk_hw *hw)
{
struct clk_utmi *utmi = to_clk_utmi(hw);
struct at91_pmc *pmc = utmi->pmc;
u32 tmp = at91_pmc_read(AT91_CKGR_UCKR) & ~AT91_PMC_UPLLEN;
pmc_write(pmc, AT91_CKGR_UCKR, tmp);
}
static unsigned long clk_utmi_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
return parent_rate * UTMI_FIXED_MUL;
}
static struct clk * __init
at91_clk_register_utmi(struct at91_pmc *pmc, unsigned int irq,
const char *name, const char *parent_name)
{
int ret;
struct clk_utmi *utmi;
struct clk *clk = NULL;
struct clk_init_data init;
utmi = kzalloc(sizeof(*utmi), GFP_KERNEL);
if (!utmi)
return ERR_PTR(-ENOMEM);
init.name = name;
init.ops = &utmi_ops;
init.parent_names = parent_name ? &parent_name : NULL;
init.num_parents = parent_name ? 1 : 0;
init.flags = CLK_SET_RATE_GATE;
utmi->hw.init = &init;
utmi->pmc = pmc;
utmi->irq = irq;
init_waitqueue_head(&utmi->wait);
irq_set_status_flags(utmi->irq, IRQ_NOAUTOEN);
ret = request_irq(utmi->irq, clk_utmi_irq_handler,
IRQF_TRIGGER_HIGH, "clk-utmi", utmi);
if (ret)
return ERR_PTR(ret);
clk = clk_register(NULL, &utmi->hw);
if (IS_ERR(clk))
kfree(utmi);
return clk;
}
static void __init
of_at91_clk_utmi_setup(struct device_node *np, struct at91_pmc *pmc)
{
unsigned int irq;
struct clk *clk;
const char *parent_name;
const char *name = np->name;
parent_name = of_clk_get_parent_name(np, 0);
of_property_read_string(np, "clock-output-names", &name);
irq = irq_of_parse_and_map(np, 0);
if (!irq)
return;
clk = at91_clk_register_utmi(pmc, irq, name, parent_name);
if (IS_ERR(clk))
return;
of_clk_add_provider(np, of_clk_src_simple_get, clk);
return;
}
void __init of_at91sam9x5_clk_utmi_setup(struct device_node *np,
struct at91_pmc *pmc)
{
of_at91_clk_utmi_setup(np, pmc);
}
