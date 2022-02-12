int irq_reserve_ipi(struct irq_domain *domain,
const struct cpumask *dest)
{
unsigned int nr_irqs, offset;
struct irq_data *data;
int virq, i;
if (!domain ||!irq_domain_is_ipi(domain)) {
pr_warn("Reservation on a non IPI domain\n");
return -EINVAL;
}
if (!cpumask_subset(dest, cpu_possible_mask)) {
pr_warn("Reservation is not in possible_cpu_mask\n");
return -EINVAL;
}
nr_irqs = cpumask_weight(dest);
if (!nr_irqs) {
pr_warn("Reservation for empty destination mask\n");
return -EINVAL;
}
if (irq_domain_is_ipi_single(domain)) {
nr_irqs = 1;
offset = 0;
} else {
unsigned int next;
offset = cpumask_first(dest);
next = cpumask_next_zero(offset, dest);
if (next < nr_cpu_ids)
next = cpumask_next(next, dest);
if (next < nr_cpu_ids) {
pr_warn("Destination mask has holes\n");
return -EINVAL;
}
}
virq = irq_domain_alloc_descs(-1, nr_irqs, 0, NUMA_NO_NODE, NULL);
if (virq <= 0) {
pr_warn("Can't reserve IPI, failed to alloc descs\n");
return -ENOMEM;
}
virq = __irq_domain_alloc_irqs(domain, virq, nr_irqs, NUMA_NO_NODE,
(void *) dest, true, NULL);
if (virq <= 0) {
pr_warn("Can't reserve IPI, failed to alloc hw irqs\n");
goto free_descs;
}
for (i = 0; i < nr_irqs; i++) {
data = irq_get_irq_data(virq + i);
cpumask_copy(data->common->affinity, dest);
data->common->ipi_offset = offset;
irq_set_status_flags(virq + i, IRQ_NO_BALANCING);
}
return virq;
free_descs:
irq_free_descs(virq, nr_irqs);
return -EBUSY;
}
int irq_destroy_ipi(unsigned int irq, const struct cpumask *dest)
{
struct irq_data *data = irq_get_irq_data(irq);
struct cpumask *ipimask = data ? irq_data_get_affinity_mask(data) : NULL;
struct irq_domain *domain;
unsigned int nr_irqs;
if (!irq || !data || !ipimask)
return -EINVAL;
domain = data->domain;
if (WARN_ON(domain == NULL))
return -EINVAL;
if (!irq_domain_is_ipi(domain)) {
pr_warn("Trying to destroy a non IPI domain!\n");
return -EINVAL;
}
if (WARN_ON(!cpumask_subset(dest, ipimask)))
return -EINVAL;
if (irq_domain_is_ipi_per_cpu(domain)) {
irq = irq + cpumask_first(dest) - data->common->ipi_offset;
nr_irqs = cpumask_weight(dest);
} else {
nr_irqs = 1;
}
irq_domain_free_irqs(irq, nr_irqs);
return 0;
}
irq_hw_number_t ipi_get_hwirq(unsigned int irq, unsigned int cpu)
{
struct irq_data *data = irq_get_irq_data(irq);
struct cpumask *ipimask = data ? irq_data_get_affinity_mask(data) : NULL;
if (!data || !ipimask || cpu >= nr_cpu_ids)
return INVALID_HWIRQ;
if (!cpumask_test_cpu(cpu, ipimask))
return INVALID_HWIRQ;
if (irq_domain_is_ipi_per_cpu(data->domain))
data = irq_get_irq_data(irq + cpu - data->common->ipi_offset);
return data ? irqd_to_hwirq(data) : INVALID_HWIRQ;
}
static int ipi_send_verify(struct irq_chip *chip, struct irq_data *data,
const struct cpumask *dest, unsigned int cpu)
{
struct cpumask *ipimask = irq_data_get_affinity_mask(data);
if (!chip || !ipimask)
return -EINVAL;
if (!chip->ipi_send_single && !chip->ipi_send_mask)
return -EINVAL;
if (cpu >= nr_cpu_ids)
return -EINVAL;
if (dest) {
if (!cpumask_subset(dest, ipimask))
return -EINVAL;
} else {
if (!cpumask_test_cpu(cpu, ipimask))
return -EINVAL;
}
return 0;
}
int __ipi_send_single(struct irq_desc *desc, unsigned int cpu)
{
struct irq_data *data = irq_desc_get_irq_data(desc);
struct irq_chip *chip = irq_data_get_irq_chip(data);
#ifdef DEBUG
if (WARN_ON_ONCE(ipi_send_verify(chip, data, NULL, cpu)))
return -EINVAL;
#endif
if (!chip->ipi_send_single) {
chip->ipi_send_mask(data, cpumask_of(cpu));
return 0;
}
if (irq_domain_is_ipi_per_cpu(data->domain) &&
cpu != data->common->ipi_offset) {
unsigned irq = data->irq + cpu - data->common->ipi_offset;
data = irq_get_irq_data(irq);
}
chip->ipi_send_single(data, cpu);
return 0;
}
int __ipi_send_mask(struct irq_desc *desc, const struct cpumask *dest)
{
struct irq_data *data = irq_desc_get_irq_data(desc);
struct irq_chip *chip = irq_data_get_irq_chip(data);
unsigned int cpu;
#ifdef DEBUG
if (WARN_ON_ONCE(ipi_send_verify(chip, data, dest, 0)))
return -EINVAL;
#endif
if (chip->ipi_send_mask) {
chip->ipi_send_mask(data, dest);
return 0;
}
if (irq_domain_is_ipi_per_cpu(data->domain)) {
unsigned int base = data->irq;
for_each_cpu(cpu, dest) {
unsigned irq = base + cpu - data->common->ipi_offset;
data = irq_get_irq_data(irq);
chip->ipi_send_single(data, cpu);
}
} else {
for_each_cpu(cpu, dest)
chip->ipi_send_single(data, cpu);
}
return 0;
}
int ipi_send_single(unsigned int virq, unsigned int cpu)
{
struct irq_desc *desc = irq_to_desc(virq);
struct irq_data *data = desc ? irq_desc_get_irq_data(desc) : NULL;
struct irq_chip *chip = data ? irq_data_get_irq_chip(data) : NULL;
if (WARN_ON_ONCE(ipi_send_verify(chip, data, NULL, cpu)))
return -EINVAL;
return __ipi_send_single(desc, cpu);
}
int ipi_send_mask(unsigned int virq, const struct cpumask *dest)
{
struct irq_desc *desc = irq_to_desc(virq);
struct irq_data *data = desc ? irq_desc_get_irq_data(desc) : NULL;
struct irq_chip *chip = data ? irq_data_get_irq_chip(data) : NULL;
if (WARN_ON_ONCE(ipi_send_verify(chip, data, dest, 0)))
return -EINVAL;
return __ipi_send_mask(desc, dest);
}
