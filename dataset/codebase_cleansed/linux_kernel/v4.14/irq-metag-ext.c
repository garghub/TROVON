static unsigned int meta_intc_offset(irq_hw_number_t hw)
{
return hw & 0x1f;
}
static unsigned int meta_intc_bank(irq_hw_number_t hw)
{
return hw >> 5;
}
static void __iomem *meta_intc_stat_addr(irq_hw_number_t hw)
{
return (void __iomem *)(HWSTATEXT +
HWSTAT_STRIDE * meta_intc_bank(hw));
}
static void __iomem *meta_intc_level_addr(irq_hw_number_t hw)
{
return (void __iomem *)(HWLEVELEXT +
HWSTAT_STRIDE * meta_intc_bank(hw));
}
static void __iomem *meta_intc_mask_addr(irq_hw_number_t hw)
{
return (void __iomem *)(HWMASKEXT +
HWSTAT_STRIDE * meta_intc_bank(hw));
}
static inline void __iomem *meta_intc_vec_addr(irq_hw_number_t hw)
{
return (void __iomem *)(HWVEC0EXT +
HWVEC_BLK_STRIDE * meta_intc_bank(hw) +
HWVECnEXT_STRIDE * meta_intc_offset(hw));
}
static unsigned int meta_intc_startup_irq(struct irq_data *data)
{
irq_hw_number_t hw = data->hwirq;
void __iomem *vec_addr = meta_intc_vec_addr(hw);
int thread = hard_processor_id();
if (data->chip->irq_ack)
data->chip->irq_ack(data);
metag_out32(TBI_TRIG_VEC(TBID_SIGNUM_TR2(thread)), vec_addr);
data->chip->irq_unmask(data);
return 0;
}
static void meta_intc_shutdown_irq(struct irq_data *data)
{
irq_hw_number_t hw = data->hwirq;
void __iomem *vec_addr = meta_intc_vec_addr(hw);
data->chip->irq_mask(data);
metag_out32(0, vec_addr);
}
static void meta_intc_ack_irq(struct irq_data *data)
{
irq_hw_number_t hw = data->hwirq;
unsigned int bit = 1 << meta_intc_offset(hw);
void __iomem *stat_addr = meta_intc_stat_addr(hw);
if (metag_in32(stat_addr) & bit)
metag_out32(bit, stat_addr);
}
static void record_irq_is_masked(struct irq_data *data)
{
struct meta_intc_priv *priv = &meta_intc_priv;
irq_hw_number_t hw = data->hwirq;
clear_bit(meta_intc_offset(hw), &priv->unmasked[meta_intc_bank(hw)]);
}
static void record_irq_is_unmasked(struct irq_data *data)
{
struct meta_intc_priv *priv = &meta_intc_priv;
irq_hw_number_t hw = data->hwirq;
set_bit(meta_intc_offset(hw), &priv->unmasked[meta_intc_bank(hw)]);
}
void meta_intc_mask_irq_simple(struct irq_data *data)
{
record_irq_is_masked(data);
}
void meta_intc_unmask_irq_simple(struct irq_data *data)
{
record_irq_is_unmasked(data);
}
static void meta_intc_mask_irq(struct irq_data *data)
{
irq_hw_number_t hw = data->hwirq;
unsigned int bit = 1 << meta_intc_offset(hw);
void __iomem *mask_addr = meta_intc_mask_addr(hw);
unsigned long flags;
record_irq_is_masked(data);
__global_lock2(flags);
metag_out32(metag_in32(mask_addr) & ~bit, mask_addr);
__global_unlock2(flags);
}
static void meta_intc_unmask_irq(struct irq_data *data)
{
irq_hw_number_t hw = data->hwirq;
unsigned int bit = 1 << meta_intc_offset(hw);
void __iomem *mask_addr = meta_intc_mask_addr(hw);
unsigned long flags;
record_irq_is_unmasked(data);
__global_lock2(flags);
metag_out32(metag_in32(mask_addr) | bit, mask_addr);
__global_unlock2(flags);
}
static void meta_intc_mask_irq_nomask(struct irq_data *data)
{
irq_hw_number_t hw = data->hwirq;
void __iomem *vec_addr = meta_intc_vec_addr(hw);
record_irq_is_masked(data);
metag_out32(0, vec_addr);
}
static void meta_intc_unmask_edge_irq_nomask(struct irq_data *data)
{
irq_hw_number_t hw = data->hwirq;
unsigned int bit = 1 << meta_intc_offset(hw);
void __iomem *stat_addr = meta_intc_stat_addr(hw);
void __iomem *vec_addr = meta_intc_vec_addr(hw);
unsigned int thread = hard_processor_id();
record_irq_is_unmasked(data);
metag_out32(TBI_TRIG_VEC(TBID_SIGNUM_TR2(thread)), vec_addr);
if (metag_in32(stat_addr) & bit) {
metag_out32(bit, stat_addr);
while (!(metag_in32(stat_addr) & bit))
metag_out32(bit, stat_addr);
}
}
static void meta_intc_unmask_level_irq_nomask(struct irq_data *data)
{
irq_hw_number_t hw = data->hwirq;
unsigned int bit = 1 << meta_intc_offset(hw);
void __iomem *stat_addr = meta_intc_stat_addr(hw);
void __iomem *vec_addr = meta_intc_vec_addr(hw);
unsigned int thread = hard_processor_id();
record_irq_is_unmasked(data);
metag_out32(TBI_TRIG_VEC(TBID_SIGNUM_TR2(thread)), vec_addr);
if (metag_in32(stat_addr) & bit)
metag_out32(bit, stat_addr);
}
static int meta_intc_irq_set_type(struct irq_data *data, unsigned int flow_type)
{
#ifdef CONFIG_METAG_SUSPEND_MEM
struct meta_intc_priv *priv = &meta_intc_priv;
#endif
irq_hw_number_t hw = data->hwirq;
unsigned int bit = 1 << meta_intc_offset(hw);
void __iomem *level_addr = meta_intc_level_addr(hw);
unsigned long flags;
unsigned int level;
if (flow_type & IRQ_TYPE_LEVEL_MASK)
irq_set_chip_handler_name_locked(data, &meta_intc_level_chip,
handle_level_irq, NULL);
else
irq_set_chip_handler_name_locked(data, &meta_intc_edge_chip,
handle_edge_irq, NULL);
__global_lock2(flags);
level = metag_in32(level_addr);
if (flow_type & IRQ_TYPE_LEVEL_MASK)
level |= bit;
else
level &= ~bit;
metag_out32(level, level_addr);
#ifdef CONFIG_METAG_SUSPEND_MEM
priv->levels_altered[meta_intc_bank(hw)] |= bit;
#endif
__global_unlock2(flags);
return 0;
}
static void meta_intc_irq_demux(struct irq_desc *desc)
{
struct meta_intc_priv *priv = &meta_intc_priv;
irq_hw_number_t hw;
unsigned int bank, irq_no, status;
void __iomem *stat_addr = meta_intc_stat_addr(0);
for (bank = 0; bank < priv->nr_banks; ++bank) {
recalculate:
status = metag_in32(stat_addr) & priv->unmasked[bank];
for (hw = bank*32; status; status >>= 1, ++hw) {
if (status & 0x1) {
irq_no = irq_linear_revmap(priv->domain, hw);
generic_handle_irq(irq_no);
goto recalculate;
}
}
stat_addr += HWSTAT_STRIDE;
}
}
static int meta_intc_set_affinity(struct irq_data *data,
const struct cpumask *cpumask, bool force)
{
irq_hw_number_t hw = data->hwirq;
void __iomem *vec_addr = meta_intc_vec_addr(hw);
unsigned int cpu, thread;
cpu = cpumask_any_and(cpumask, cpu_online_mask);
thread = cpu_2_hwthread_id[cpu];
metag_out32(TBI_TRIG_VEC(TBID_SIGNUM_TR2(thread)), vec_addr);
irq_data_update_effective_affinity(data, cpumask_of(cpu));
return 0;
}
static int meta_intc_map(struct irq_domain *d, unsigned int irq,
irq_hw_number_t hw)
{
unsigned int bit = 1 << meta_intc_offset(hw);
void __iomem *level_addr = meta_intc_level_addr(hw);
if (metag_in32(level_addr) & bit)
irq_set_chip_and_handler(irq, &meta_intc_level_chip,
handle_level_irq);
else
irq_set_chip_and_handler(irq, &meta_intc_edge_chip,
handle_edge_irq);
irqd_set_single_target(irq_desc_get_irq_data(irq_to_desc(irq)));
return 0;
}
static int meta_intc_suspend(void)
{
struct meta_intc_priv *priv = &meta_intc_priv;
int i, j;
irq_hw_number_t hw;
unsigned int bank;
unsigned long flags;
struct meta_intc_context *context;
void __iomem *level_addr, *mask_addr, *vec_addr;
u32 mask, bit;
context = kzalloc(sizeof(*context), GFP_ATOMIC);
if (!context)
return -ENOMEM;
hw = 0;
level_addr = meta_intc_level_addr(0);
mask_addr = meta_intc_mask_addr(0);
for (bank = 0; bank < priv->nr_banks; ++bank) {
vec_addr = meta_intc_vec_addr(hw);
mask = 0;
for (bit = 1; bit; bit <<= 1) {
i = irq_linear_revmap(priv->domain, hw);
if (i && (!irqd_irq_disabled(irq_get_irq_data(i)) ||
irq_has_action(i))) {
mask |= bit;
context->vectors[hw] = metag_in32(vec_addr);
}
++hw;
vec_addr += HWVECnEXT_STRIDE;
}
if (priv->levels_altered[bank])
context->levels[bank] = metag_in32(level_addr);
if (mask)
context->masks[bank] = metag_in32(mask_addr);
level_addr += HWSTAT_STRIDE;
mask_addr += HWSTAT_STRIDE;
}
__global_lock2(flags);
for (i = 0; i < 4; ++i)
for (j = 0; j < 4; ++j)
context->txvecint[i][j] = metag_in32(T0VECINT_BHALT +
TnVECINT_STRIDE*i +
8*j);
__global_unlock2(flags);
meta_intc_context = context;
return 0;
}
static void meta_intc_resume(void)
{
struct meta_intc_priv *priv = &meta_intc_priv;
int i, j;
irq_hw_number_t hw;
unsigned int bank;
unsigned long flags;
struct meta_intc_context *context = meta_intc_context;
void __iomem *level_addr, *mask_addr, *vec_addr;
u32 mask, bit, tmp;
meta_intc_context = NULL;
hw = 0;
level_addr = meta_intc_level_addr(0);
mask_addr = meta_intc_mask_addr(0);
for (bank = 0; bank < priv->nr_banks; ++bank) {
vec_addr = meta_intc_vec_addr(hw);
mask = 0;
for (bit = 1; bit; bit <<= 1) {
i = irq_linear_revmap(priv->domain, hw);
if (i && (!irqd_irq_disabled(irq_get_irq_data(i)) ||
irq_has_action(i))) {
mask |= bit;
metag_out32(context->vectors[hw], vec_addr);
}
++hw;
vec_addr += HWVECnEXT_STRIDE;
}
if (mask) {
__global_lock2(flags);
tmp = metag_in32(mask_addr);
tmp = (tmp & ~mask) | (context->masks[bank] & mask);
metag_out32(tmp, mask_addr);
__global_unlock2(flags);
}
mask = priv->levels_altered[bank];
if (mask) {
__global_lock2(flags);
tmp = metag_in32(level_addr);
tmp = (tmp & ~mask) | (context->levels[bank] & mask);
metag_out32(tmp, level_addr);
__global_unlock2(flags);
}
level_addr += HWSTAT_STRIDE;
mask_addr += HWSTAT_STRIDE;
}
__global_lock2(flags);
for (i = 0; i < 4; ++i) {
for (j = 0; j < 4; ++j) {
metag_out32(context->txvecint[i][j],
T0VECINT_BHALT +
TnVECINT_STRIDE*i +
8*j);
}
}
__global_unlock2(flags);
kfree(context);
}
static void __init meta_intc_init_syscore_ops(struct meta_intc_priv *priv)
{
register_syscore_ops(&meta_intc_syscore_ops);
}
static void __init meta_intc_init_cpu(struct meta_intc_priv *priv, int cpu)
{
unsigned int thread = cpu_2_hwthread_id[cpu];
unsigned int signum = TBID_SIGNUM_TR2(thread);
int irq = tbisig_map(signum);
irq_set_chained_handler(irq, meta_intc_irq_demux);
irq_set_irq_type(irq, IRQ_TYPE_LEVEL_LOW);
}
void __init meta_intc_no_mask(void)
{
meta_intc_edge_chip.irq_mask = meta_intc_mask_irq_nomask;
meta_intc_edge_chip.irq_unmask = meta_intc_unmask_edge_irq_nomask;
meta_intc_level_chip.irq_mask = meta_intc_mask_irq_nomask;
meta_intc_level_chip.irq_unmask = meta_intc_unmask_level_irq_nomask;
}
int __init init_external_IRQ(void)
{
struct meta_intc_priv *priv = &meta_intc_priv;
struct device_node *node;
int ret, cpu;
u32 val;
bool no_masks = false;
node = of_find_compatible_node(NULL, NULL, "img,meta-intc");
if (!node)
return -ENOENT;
ret = of_property_read_u32(node, "num-banks", &val);
if (ret) {
pr_err("meta-intc: No num-banks property found\n");
return ret;
}
if (val < 1 || val > 4) {
pr_err("meta-intc: num-banks (%u) out of range\n", val);
return -EINVAL;
}
priv->nr_banks = val;
if (of_get_property(node, "no-mask", NULL))
no_masks = true;
if (no_masks)
meta_intc_no_mask();
priv->domain = irq_domain_add_linear(node, priv->nr_banks*32,
&meta_intc_domain_ops, priv);
if (unlikely(!priv->domain)) {
pr_err("meta-intc: cannot add IRQ domain\n");
return -ENOMEM;
}
for_each_possible_cpu(cpu)
meta_intc_init_cpu(priv, cpu);
meta_intc_init_syscore_ops(priv);
pr_info("meta-intc: External IRQ controller initialised (%u IRQs)\n",
priv->nr_banks*32);
return 0;
}
