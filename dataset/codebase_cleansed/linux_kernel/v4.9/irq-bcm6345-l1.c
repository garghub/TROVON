static inline unsigned int reg_enable(struct bcm6345_l1_chip *intc,
unsigned int word)
{
#ifdef __BIG_ENDIAN
return (1 * intc->n_words - word - 1) * sizeof(u32);
#else
return (0 * intc->n_words + word) * sizeof(u32);
#endif
}
static inline unsigned int reg_status(struct bcm6345_l1_chip *intc,
unsigned int word)
{
#ifdef __BIG_ENDIAN
return (2 * intc->n_words - word - 1) * sizeof(u32);
#else
return (1 * intc->n_words + word) * sizeof(u32);
#endif
}
static inline unsigned int cpu_for_irq(struct bcm6345_l1_chip *intc,
struct irq_data *d)
{
return cpumask_first_and(&intc->cpumask, irq_data_get_affinity_mask(d));
}
static void bcm6345_l1_irq_handle(struct irq_desc *desc)
{
struct bcm6345_l1_chip *intc = irq_desc_get_handler_data(desc);
struct bcm6345_l1_cpu *cpu;
struct irq_chip *chip = irq_desc_get_chip(desc);
unsigned int idx;
#ifdef CONFIG_SMP
cpu = intc->cpus[cpu_logical_map(smp_processor_id())];
#else
cpu = intc->cpus[0];
#endif
chained_irq_enter(chip, desc);
for (idx = 0; idx < intc->n_words; idx++) {
int base = idx * IRQS_PER_WORD;
unsigned long pending;
irq_hw_number_t hwirq;
unsigned int irq;
pending = __raw_readl(cpu->map_base + reg_status(intc, idx));
pending &= __raw_readl(cpu->map_base + reg_enable(intc, idx));
for_each_set_bit(hwirq, &pending, IRQS_PER_WORD) {
irq = irq_linear_revmap(intc->domain, base + hwirq);
if (irq)
do_IRQ(irq);
else
spurious_interrupt();
}
}
chained_irq_exit(chip, desc);
}
static inline void __bcm6345_l1_unmask(struct irq_data *d)
{
struct bcm6345_l1_chip *intc = irq_data_get_irq_chip_data(d);
u32 word = d->hwirq / IRQS_PER_WORD;
u32 mask = BIT(d->hwirq % IRQS_PER_WORD);
unsigned int cpu_idx = cpu_for_irq(intc, d);
intc->cpus[cpu_idx]->enable_cache[word] |= mask;
__raw_writel(intc->cpus[cpu_idx]->enable_cache[word],
intc->cpus[cpu_idx]->map_base + reg_enable(intc, word));
}
static inline void __bcm6345_l1_mask(struct irq_data *d)
{
struct bcm6345_l1_chip *intc = irq_data_get_irq_chip_data(d);
u32 word = d->hwirq / IRQS_PER_WORD;
u32 mask = BIT(d->hwirq % IRQS_PER_WORD);
unsigned int cpu_idx = cpu_for_irq(intc, d);
intc->cpus[cpu_idx]->enable_cache[word] &= ~mask;
__raw_writel(intc->cpus[cpu_idx]->enable_cache[word],
intc->cpus[cpu_idx]->map_base + reg_enable(intc, word));
}
static void bcm6345_l1_unmask(struct irq_data *d)
{
struct bcm6345_l1_chip *intc = irq_data_get_irq_chip_data(d);
unsigned long flags;
raw_spin_lock_irqsave(&intc->lock, flags);
__bcm6345_l1_unmask(d);
raw_spin_unlock_irqrestore(&intc->lock, flags);
}
static void bcm6345_l1_mask(struct irq_data *d)
{
struct bcm6345_l1_chip *intc = irq_data_get_irq_chip_data(d);
unsigned long flags;
raw_spin_lock_irqsave(&intc->lock, flags);
__bcm6345_l1_mask(d);
raw_spin_unlock_irqrestore(&intc->lock, flags);
}
static int bcm6345_l1_set_affinity(struct irq_data *d,
const struct cpumask *dest,
bool force)
{
struct bcm6345_l1_chip *intc = irq_data_get_irq_chip_data(d);
u32 word = d->hwirq / IRQS_PER_WORD;
u32 mask = BIT(d->hwirq % IRQS_PER_WORD);
unsigned int old_cpu = cpu_for_irq(intc, d);
unsigned int new_cpu;
struct cpumask valid;
unsigned long flags;
bool enabled;
if (!cpumask_and(&valid, &intc->cpumask, dest))
return -EINVAL;
new_cpu = cpumask_any_and(&valid, cpu_online_mask);
if (new_cpu >= nr_cpu_ids)
return -EINVAL;
dest = cpumask_of(new_cpu);
raw_spin_lock_irqsave(&intc->lock, flags);
if (old_cpu != new_cpu) {
enabled = intc->cpus[old_cpu]->enable_cache[word] & mask;
if (enabled)
__bcm6345_l1_mask(d);
cpumask_copy(irq_data_get_affinity_mask(d), dest);
if (enabled)
__bcm6345_l1_unmask(d);
} else {
cpumask_copy(irq_data_get_affinity_mask(d), dest);
}
raw_spin_unlock_irqrestore(&intc->lock, flags);
return IRQ_SET_MASK_OK_NOCOPY;
}
static int __init bcm6345_l1_init_one(struct device_node *dn,
unsigned int idx,
struct bcm6345_l1_chip *intc)
{
struct resource res;
resource_size_t sz;
struct bcm6345_l1_cpu *cpu;
unsigned int i, n_words;
if (of_address_to_resource(dn, idx, &res))
return -EINVAL;
sz = resource_size(&res);
n_words = sz / REG_BYTES_PER_IRQ_WORD;
if (!intc->n_words)
intc->n_words = n_words;
else if (intc->n_words != n_words)
return -EINVAL;
cpu = intc->cpus[idx] = kzalloc(sizeof(*cpu) + n_words * sizeof(u32),
GFP_KERNEL);
if (!cpu)
return -ENOMEM;
cpu->map_base = ioremap(res.start, sz);
if (!cpu->map_base)
return -ENOMEM;
for (i = 0; i < n_words; i++) {
cpu->enable_cache[i] = 0;
__raw_writel(0, cpu->map_base + reg_enable(intc, i));
}
cpu->parent_irq = irq_of_parse_and_map(dn, idx);
if (!cpu->parent_irq) {
pr_err("failed to map parent interrupt %d\n", cpu->parent_irq);
return -EINVAL;
}
irq_set_chained_handler_and_data(cpu->parent_irq,
bcm6345_l1_irq_handle, intc);
return 0;
}
static int bcm6345_l1_map(struct irq_domain *d, unsigned int virq,
irq_hw_number_t hw_irq)
{
irq_set_chip_and_handler(virq,
&bcm6345_l1_irq_chip, handle_percpu_irq);
irq_set_chip_data(virq, d->host_data);
return 0;
}
static int __init bcm6345_l1_of_init(struct device_node *dn,
struct device_node *parent)
{
struct bcm6345_l1_chip *intc;
unsigned int idx;
int ret;
intc = kzalloc(sizeof(*intc), GFP_KERNEL);
if (!intc)
return -ENOMEM;
for_each_possible_cpu(idx) {
ret = bcm6345_l1_init_one(dn, idx, intc);
if (ret)
pr_err("failed to init intc L1 for cpu %d: %d\n",
idx, ret);
else
cpumask_set_cpu(idx, &intc->cpumask);
}
if (!cpumask_weight(&intc->cpumask)) {
ret = -ENODEV;
goto out_free;
}
raw_spin_lock_init(&intc->lock);
intc->domain = irq_domain_add_linear(dn, IRQS_PER_WORD * intc->n_words,
&bcm6345_l1_domain_ops,
intc);
if (!intc->domain) {
ret = -ENOMEM;
goto out_unmap;
}
pr_info("registered BCM6345 L1 intc (IRQs: %d)\n",
IRQS_PER_WORD * intc->n_words);
for_each_cpu(idx, &intc->cpumask) {
struct bcm6345_l1_cpu *cpu = intc->cpus[idx];
pr_info(" CPU%u at MMIO 0x%p (irq = %d)\n", idx,
cpu->map_base, cpu->parent_irq);
}
return 0;
out_unmap:
for_each_possible_cpu(idx) {
struct bcm6345_l1_cpu *cpu = intc->cpus[idx];
if (cpu) {
if (cpu->map_base)
iounmap(cpu->map_base);
kfree(cpu);
}
}
out_free:
kfree(intc);
return ret;
}
