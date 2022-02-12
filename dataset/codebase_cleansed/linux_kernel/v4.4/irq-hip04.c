static inline void __iomem *hip04_dist_base(struct irq_data *d)
{
struct hip04_irq_data *hip04_data = irq_data_get_irq_chip_data(d);
return hip04_data->dist_base;
}
static inline void __iomem *hip04_cpu_base(struct irq_data *d)
{
struct hip04_irq_data *hip04_data = irq_data_get_irq_chip_data(d);
return hip04_data->cpu_base;
}
static inline unsigned int hip04_irq(struct irq_data *d)
{
return d->hwirq;
}
static void hip04_mask_irq(struct irq_data *d)
{
u32 mask = 1 << (hip04_irq(d) % 32);
raw_spin_lock(&irq_controller_lock);
writel_relaxed(mask, hip04_dist_base(d) + GIC_DIST_ENABLE_CLEAR +
(hip04_irq(d) / 32) * 4);
raw_spin_unlock(&irq_controller_lock);
}
static void hip04_unmask_irq(struct irq_data *d)
{
u32 mask = 1 << (hip04_irq(d) % 32);
raw_spin_lock(&irq_controller_lock);
writel_relaxed(mask, hip04_dist_base(d) + GIC_DIST_ENABLE_SET +
(hip04_irq(d) / 32) * 4);
raw_spin_unlock(&irq_controller_lock);
}
static void hip04_eoi_irq(struct irq_data *d)
{
writel_relaxed(hip04_irq(d), hip04_cpu_base(d) + GIC_CPU_EOI);
}
static int hip04_irq_set_type(struct irq_data *d, unsigned int type)
{
void __iomem *base = hip04_dist_base(d);
unsigned int irq = hip04_irq(d);
int ret;
if (irq < 16)
return -EINVAL;
if (irq >= 32 && type != IRQ_TYPE_LEVEL_HIGH &&
type != IRQ_TYPE_EDGE_RISING)
return -EINVAL;
raw_spin_lock(&irq_controller_lock);
ret = gic_configure_irq(irq, type, base, NULL);
raw_spin_unlock(&irq_controller_lock);
return ret;
}
static int hip04_irq_set_affinity(struct irq_data *d,
const struct cpumask *mask_val,
bool force)
{
void __iomem *reg;
unsigned int cpu, shift = (hip04_irq(d) % 2) * 16;
u32 val, mask, bit;
if (!force)
cpu = cpumask_any_and(mask_val, cpu_online_mask);
else
cpu = cpumask_first(mask_val);
if (cpu >= NR_HIP04_CPU_IF || cpu >= nr_cpu_ids)
return -EINVAL;
raw_spin_lock(&irq_controller_lock);
reg = hip04_dist_base(d) + GIC_DIST_TARGET + ((hip04_irq(d) * 2) & ~3);
mask = 0xffff << shift;
bit = hip04_cpu_map[cpu] << shift;
val = readl_relaxed(reg) & ~mask;
writel_relaxed(val | bit, reg);
raw_spin_unlock(&irq_controller_lock);
return IRQ_SET_MASK_OK;
}
static void __exception_irq_entry hip04_handle_irq(struct pt_regs *regs)
{
u32 irqstat, irqnr;
void __iomem *cpu_base = hip04_data.cpu_base;
do {
irqstat = readl_relaxed(cpu_base + GIC_CPU_INTACK);
irqnr = irqstat & GICC_IAR_INT_ID_MASK;
if (likely(irqnr > 15 && irqnr <= HIP04_MAX_IRQS)) {
handle_domain_irq(hip04_data.domain, irqnr, regs);
continue;
}
if (irqnr < 16) {
writel_relaxed(irqstat, cpu_base + GIC_CPU_EOI);
#ifdef CONFIG_SMP
handle_IPI(irqnr, regs);
#endif
continue;
}
break;
} while (1);
}
static u16 hip04_get_cpumask(struct hip04_irq_data *intc)
{
void __iomem *base = intc->dist_base;
u32 mask, i;
for (i = mask = 0; i < 32; i += 2) {
mask = readl_relaxed(base + GIC_DIST_TARGET + i * 2);
mask |= mask >> 16;
if (mask)
break;
}
if (!mask)
pr_crit("GIC CPU mask not found - kernel will fail to boot.\n");
return mask;
}
static void __init hip04_irq_dist_init(struct hip04_irq_data *intc)
{
unsigned int i;
u32 cpumask;
unsigned int nr_irqs = intc->nr_irqs;
void __iomem *base = intc->dist_base;
writel_relaxed(0, base + GIC_DIST_CTRL);
cpumask = hip04_get_cpumask(intc);
cpumask |= cpumask << 16;
for (i = 32; i < nr_irqs; i += 2)
writel_relaxed(cpumask, base + GIC_DIST_TARGET + ((i * 2) & ~3));
gic_dist_config(base, nr_irqs, NULL);
writel_relaxed(1, base + GIC_DIST_CTRL);
}
static void hip04_irq_cpu_init(struct hip04_irq_data *intc)
{
void __iomem *dist_base = intc->dist_base;
void __iomem *base = intc->cpu_base;
unsigned int cpu_mask, cpu = smp_processor_id();
int i;
BUG_ON(cpu >= NR_HIP04_CPU_IF);
cpu_mask = hip04_get_cpumask(intc);
hip04_cpu_map[cpu] = cpu_mask;
for (i = 0; i < NR_HIP04_CPU_IF; i++)
if (i != cpu)
hip04_cpu_map[i] &= ~cpu_mask;
gic_cpu_config(dist_base, NULL);
writel_relaxed(0xf0, base + GIC_CPU_PRIMASK);
writel_relaxed(1, base + GIC_CPU_CTRL);
}
static void hip04_raise_softirq(const struct cpumask *mask, unsigned int irq)
{
int cpu;
unsigned long flags, map = 0;
raw_spin_lock_irqsave(&irq_controller_lock, flags);
for_each_cpu(cpu, mask)
map |= hip04_cpu_map[cpu];
dmb(ishst);
writel_relaxed(map << 8 | irq, hip04_data.dist_base + GIC_DIST_SOFTINT);
raw_spin_unlock_irqrestore(&irq_controller_lock, flags);
}
static int hip04_irq_domain_map(struct irq_domain *d, unsigned int irq,
irq_hw_number_t hw)
{
if (hw < 32) {
irq_set_percpu_devid(irq);
irq_set_chip_and_handler(irq, &hip04_irq_chip,
handle_percpu_devid_irq);
irq_set_status_flags(irq, IRQ_NOAUTOEN);
} else {
irq_set_chip_and_handler(irq, &hip04_irq_chip,
handle_fasteoi_irq);
irq_set_probe(irq);
}
irq_set_chip_data(irq, d->host_data);
return 0;
}
static int hip04_irq_domain_xlate(struct irq_domain *d,
struct device_node *controller,
const u32 *intspec, unsigned int intsize,
unsigned long *out_hwirq,
unsigned int *out_type)
{
unsigned long ret = 0;
if (irq_domain_get_of_node(d) != controller)
return -EINVAL;
if (intsize < 3)
return -EINVAL;
*out_hwirq = intspec[1] + 16;
if (!intspec[0])
*out_hwirq += 16;
*out_type = intspec[2] & IRQ_TYPE_SENSE_MASK;
return ret;
}
static int hip04_irq_secondary_init(struct notifier_block *nfb,
unsigned long action,
void *hcpu)
{
if (action == CPU_STARTING || action == CPU_STARTING_FROZEN)
hip04_irq_cpu_init(&hip04_data);
return NOTIFY_OK;
}
static int __init
hip04_of_init(struct device_node *node, struct device_node *parent)
{
irq_hw_number_t hwirq_base = 16;
int nr_irqs, irq_base, i;
if (WARN_ON(!node))
return -ENODEV;
hip04_data.dist_base = of_iomap(node, 0);
WARN(!hip04_data.dist_base, "fail to map hip04 intc dist registers\n");
hip04_data.cpu_base = of_iomap(node, 1);
WARN(!hip04_data.cpu_base, "unable to map hip04 intc cpu registers\n");
for (i = 0; i < NR_HIP04_CPU_IF; i++)
hip04_cpu_map[i] = 0xffff;
nr_irqs = readl_relaxed(hip04_data.dist_base + GIC_DIST_CTR) & 0x1f;
nr_irqs = (nr_irqs + 1) * 32;
if (nr_irqs > HIP04_MAX_IRQS)
nr_irqs = HIP04_MAX_IRQS;
hip04_data.nr_irqs = nr_irqs;
nr_irqs -= hwirq_base;
irq_base = irq_alloc_descs(-1, hwirq_base, nr_irqs, numa_node_id());
if (IS_ERR_VALUE(irq_base)) {
pr_err("failed to allocate IRQ numbers\n");
return -EINVAL;
}
hip04_data.domain = irq_domain_add_legacy(node, nr_irqs, irq_base,
hwirq_base,
&hip04_irq_domain_ops,
&hip04_data);
if (WARN_ON(!hip04_data.domain))
return -EINVAL;
#ifdef CONFIG_SMP
set_smp_cross_call(hip04_raise_softirq);
register_cpu_notifier(&hip04_irq_cpu_notifier);
#endif
set_handle_irq(hip04_handle_irq);
hip04_irq_dist_init(&hip04_data);
hip04_irq_cpu_init(&hip04_data);
return 0;
}
