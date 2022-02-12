static inline void __iomem *metag_hwvec_addr(irq_hw_number_t hw)
{
void __iomem *addr;
switch (hw) {
case PERF0TRIG_OFFSET:
addr = (void __iomem *)PERF0VECINT;
break;
case PERF1TRIG_OFFSET:
addr = (void __iomem *)PERF1VECINT;
break;
default:
addr = NULL;
break;
}
return addr;
}
static unsigned int metag_internal_irq_startup(struct irq_data *data)
{
metag_internal_irq_ack(data);
metag_internal_irq_unmask(data);
return 0;
}
static void metag_internal_irq_shutdown(struct irq_data *data)
{
metag_internal_irq_mask(data);
metag_internal_irq_ack(data);
}
static void metag_internal_irq_ack(struct irq_data *data)
{
irq_hw_number_t hw = data->hwirq;
unsigned int bit = 1 << hw;
if (metag_in32(HWSTATMETA) & bit)
metag_out32(bit, HWSTATMETA);
}
static void metag_internal_irq_mask(struct irq_data *data)
{
struct metag_internal_irq_priv *priv = &metag_internal_irq_priv;
irq_hw_number_t hw = data->hwirq;
void __iomem *vec_addr = metag_hwvec_addr(hw);
clear_bit(hw, &priv->unmasked);
metag_out32(0, vec_addr);
}
static void metag_internal_irq_unmask(struct irq_data *data)
{
struct metag_internal_irq_priv *priv = &metag_internal_irq_priv;
irq_hw_number_t hw = data->hwirq;
unsigned int bit = 1 << hw;
void __iomem *vec_addr = metag_hwvec_addr(hw);
unsigned int thread = hard_processor_id();
set_bit(hw, &priv->unmasked);
metag_out32(TBI_TRIG_VEC(TBID_SIGNUM_TR1(thread)), vec_addr);
if (metag_in32(HWSTATMETA) & bit) {
metag_out32(bit, HWSTATMETA);
while (!(metag_in32(HWSTATMETA) & bit))
metag_out32(bit, HWSTATMETA);
}
}
static int metag_internal_irq_set_affinity(struct irq_data *data,
const struct cpumask *cpumask, bool force)
{
unsigned int cpu, thread;
irq_hw_number_t hw = data->hwirq;
cpu = cpumask_any_and(cpumask, cpu_online_mask);
thread = cpu_2_hwthread_id[cpu];
metag_out32(TBI_TRIG_VEC(TBID_SIGNUM_TR1(thread)),
metag_hwvec_addr(hw));
return 0;
}
static void metag_internal_irq_demux(struct irq_desc *desc)
{
struct metag_internal_irq_priv *priv = irq_desc_get_handler_data(desc);
irq_hw_number_t hw;
unsigned int irq_no;
u32 status;
recalculate:
status = metag_in32(HWSTATMETA) & priv->unmasked;
for (hw = 0; status != 0; status >>= 1, ++hw) {
if (status & 0x1) {
irq_no = irq_linear_revmap(priv->domain, hw);
generic_handle_irq(irq_no);
goto recalculate;
}
}
}
int internal_irq_map(unsigned int hw)
{
struct metag_internal_irq_priv *priv = &metag_internal_irq_priv;
if (!priv->domain)
return -ENODEV;
return irq_create_mapping(priv->domain, hw);
}
static void metag_internal_irq_init_cpu(struct metag_internal_irq_priv *priv,
int cpu)
{
unsigned int thread = cpu_2_hwthread_id[cpu];
unsigned int signum = TBID_SIGNUM_TR1(thread);
int irq = tbisig_map(signum);
irq_set_chained_handler_and_data(irq, metag_internal_irq_demux, priv);
irq_set_irq_type(irq, IRQ_TYPE_LEVEL_LOW);
}
static int metag_internal_intc_map(struct irq_domain *d, unsigned int irq,
irq_hw_number_t hw)
{
if (!metag_hwvec_addr(hw))
return -EINVAL;
irq_set_chip_and_handler(irq, &internal_irq_edge_chip,
handle_edge_irq);
return 0;
}
int __init init_internal_IRQ(void)
{
struct metag_internal_irq_priv *priv = &metag_internal_irq_priv;
unsigned int cpu;
priv->domain = irq_domain_add_linear(NULL, 32,
&metag_internal_intc_domain_ops,
priv);
if (unlikely(!priv->domain)) {
pr_err("meta-internal-intc: cannot add IRQ domain\n");
return -ENOMEM;
}
for_each_possible_cpu(cpu)
metag_internal_irq_init_cpu(priv, cpu);
return 0;
}
