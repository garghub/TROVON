void at91sam9_idle(void)
{
at91_pmc_write(AT91_PMC_SCDR, AT91_PMC_PCK);
cpu_do_idle();
}
int of_at91_get_clk_range(struct device_node *np, const char *propname,
struct clk_range *range)
{
u32 min, max;
int ret;
ret = of_property_read_u32_index(np, propname, 0, &min);
if (ret)
return ret;
ret = of_property_read_u32_index(np, propname, 1, &max);
if (ret)
return ret;
if (range) {
range->min = min;
range->max = max;
}
return 0;
}
static void pmc_irq_mask(struct irq_data *d)
{
struct at91_pmc *pmc = irq_data_get_irq_chip_data(d);
pmc_write(pmc, AT91_PMC_IDR, 1 << d->hwirq);
}
static void pmc_irq_unmask(struct irq_data *d)
{
struct at91_pmc *pmc = irq_data_get_irq_chip_data(d);
pmc_write(pmc, AT91_PMC_IER, 1 << d->hwirq);
}
static int pmc_irq_set_type(struct irq_data *d, unsigned type)
{
if (type != IRQ_TYPE_LEVEL_HIGH) {
pr_warn("PMC: type not supported (support only IRQ_TYPE_LEVEL_HIGH type)\n");
return -EINVAL;
}
return 0;
}
static int pmc_irq_map(struct irq_domain *h, unsigned int virq,
irq_hw_number_t hw)
{
struct at91_pmc *pmc = h->host_data;
irq_set_lockdep_class(virq, &pmc_lock_class);
irq_set_chip_and_handler(virq, &pmc_irq,
handle_level_irq);
set_irq_flags(virq, IRQF_VALID);
irq_set_chip_data(virq, pmc);
return 0;
}
static int pmc_irq_domain_xlate(struct irq_domain *d,
struct device_node *ctrlr,
const u32 *intspec, unsigned int intsize,
irq_hw_number_t *out_hwirq,
unsigned int *out_type)
{
struct at91_pmc *pmc = d->host_data;
const struct at91_pmc_caps *caps = pmc->caps;
if (WARN_ON(intsize < 1))
return -EINVAL;
*out_hwirq = intspec[0];
if (!(caps->available_irqs & (1 << *out_hwirq)))
return -EINVAL;
*out_type = IRQ_TYPE_LEVEL_HIGH;
return 0;
}
static irqreturn_t pmc_irq_handler(int irq, void *data)
{
struct at91_pmc *pmc = (struct at91_pmc *)data;
unsigned long sr;
int n;
sr = pmc_read(pmc, AT91_PMC_SR) & pmc_read(pmc, AT91_PMC_IMR);
if (!sr)
return IRQ_NONE;
for_each_set_bit(n, &sr, BITS_PER_LONG)
generic_handle_irq(irq_find_mapping(pmc->irqdomain, n));
return IRQ_HANDLED;
}
static struct at91_pmc *__init at91_pmc_init(struct device_node *np,
void __iomem *regbase, int virq,
const struct at91_pmc_caps *caps)
{
struct at91_pmc *pmc;
if (!regbase || !virq || !caps)
return NULL;
at91_pmc_base = regbase;
pmc = kzalloc(sizeof(*pmc), GFP_KERNEL);
if (!pmc)
return NULL;
spin_lock_init(&pmc->lock);
pmc->regbase = regbase;
pmc->virq = virq;
pmc->caps = caps;
pmc->irqdomain = irq_domain_add_linear(np, 32, &pmc_irq_ops, pmc);
if (!pmc->irqdomain)
goto out_free_pmc;
pmc_write(pmc, AT91_PMC_IDR, 0xffffffff);
if (request_irq(pmc->virq, pmc_irq_handler, IRQF_SHARED, "pmc", pmc))
goto out_remove_irqdomain;
return pmc;
out_remove_irqdomain:
irq_domain_remove(pmc->irqdomain);
out_free_pmc:
kfree(pmc);
return NULL;
}
static void __init of_at91_pmc_setup(struct device_node *np,
const struct at91_pmc_caps *caps)
{
struct at91_pmc *pmc;
struct device_node *childnp;
void (*clk_setup)(struct device_node *, struct at91_pmc *);
const struct of_device_id *clk_id;
void __iomem *regbase = of_iomap(np, 0);
int virq;
if (!regbase)
return;
virq = irq_of_parse_and_map(np, 0);
if (!virq)
return;
pmc = at91_pmc_init(np, regbase, virq, caps);
if (!pmc)
return;
for_each_child_of_node(np, childnp) {
clk_id = of_match_node(pmc_clk_ids, childnp);
if (!clk_id)
continue;
clk_setup = clk_id->data;
clk_setup(childnp, pmc);
}
}
static void __init of_at91rm9200_pmc_setup(struct device_node *np)
{
of_at91_pmc_setup(np, &at91rm9200_caps);
}
static void __init of_at91sam9260_pmc_setup(struct device_node *np)
{
of_at91_pmc_setup(np, &at91sam9260_caps);
}
static void __init of_at91sam9g45_pmc_setup(struct device_node *np)
{
of_at91_pmc_setup(np, &at91sam9g45_caps);
}
static void __init of_at91sam9n12_pmc_setup(struct device_node *np)
{
of_at91_pmc_setup(np, &at91sam9n12_caps);
}
static void __init of_at91sam9x5_pmc_setup(struct device_node *np)
{
of_at91_pmc_setup(np, &at91sam9x5_caps);
}
static void __init of_sama5d3_pmc_setup(struct device_node *np)
{
of_at91_pmc_setup(np, &sama5d3_caps);
}
