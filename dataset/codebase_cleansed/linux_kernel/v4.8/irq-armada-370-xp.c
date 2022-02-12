static inline bool is_percpu_irq(irq_hw_number_t irq)
{
if (irq <= ARMADA_370_XP_MAX_PER_CPU_IRQS)
return true;
return false;
}
static void armada_370_xp_irq_mask(struct irq_data *d)
{
irq_hw_number_t hwirq = irqd_to_hwirq(d);
if (!is_percpu_irq(hwirq))
writel(hwirq, main_int_base +
ARMADA_370_XP_INT_CLEAR_ENABLE_OFFS);
else
writel(hwirq, per_cpu_int_base +
ARMADA_370_XP_INT_SET_MASK_OFFS);
}
static void armada_370_xp_irq_unmask(struct irq_data *d)
{
irq_hw_number_t hwirq = irqd_to_hwirq(d);
if (!is_percpu_irq(hwirq))
writel(hwirq, main_int_base +
ARMADA_370_XP_INT_SET_ENABLE_OFFS);
else
writel(hwirq, per_cpu_int_base +
ARMADA_370_XP_INT_CLEAR_MASK_OFFS);
}
static void armada_370_xp_compose_msi_msg(struct irq_data *data, struct msi_msg *msg)
{
msg->address_lo = lower_32_bits(msi_doorbell_addr);
msg->address_hi = upper_32_bits(msi_doorbell_addr);
msg->data = 0xf00 | (data->hwirq + PCI_MSI_DOORBELL_START);
}
static int armada_370_xp_msi_set_affinity(struct irq_data *irq_data,
const struct cpumask *mask, bool force)
{
return -EINVAL;
}
static int armada_370_xp_msi_alloc(struct irq_domain *domain, unsigned int virq,
unsigned int nr_irqs, void *args)
{
int hwirq, i;
mutex_lock(&msi_used_lock);
hwirq = bitmap_find_next_zero_area(msi_used, PCI_MSI_DOORBELL_NR,
0, nr_irqs, 0);
if (hwirq >= PCI_MSI_DOORBELL_NR) {
mutex_unlock(&msi_used_lock);
return -ENOSPC;
}
bitmap_set(msi_used, hwirq, nr_irqs);
mutex_unlock(&msi_used_lock);
for (i = 0; i < nr_irqs; i++) {
irq_domain_set_info(domain, virq + i, hwirq + i,
&armada_370_xp_msi_bottom_irq_chip,
domain->host_data, handle_simple_irq,
NULL, NULL);
}
return hwirq;
}
static void armada_370_xp_msi_free(struct irq_domain *domain,
unsigned int virq, unsigned int nr_irqs)
{
struct irq_data *d = irq_domain_get_irq_data(domain, virq);
mutex_lock(&msi_used_lock);
bitmap_clear(msi_used, d->hwirq, nr_irqs);
mutex_unlock(&msi_used_lock);
}
static int armada_370_xp_msi_init(struct device_node *node,
phys_addr_t main_int_phys_base)
{
u32 reg;
msi_doorbell_addr = main_int_phys_base +
ARMADA_370_XP_SW_TRIG_INT_OFFS;
armada_370_xp_msi_inner_domain =
irq_domain_add_linear(NULL, PCI_MSI_DOORBELL_NR,
&armada_370_xp_msi_domain_ops, NULL);
if (!armada_370_xp_msi_inner_domain)
return -ENOMEM;
armada_370_xp_msi_domain =
pci_msi_create_irq_domain(of_node_to_fwnode(node),
&armada_370_xp_msi_domain_info,
armada_370_xp_msi_inner_domain);
if (!armada_370_xp_msi_domain) {
irq_domain_remove(armada_370_xp_msi_inner_domain);
return -ENOMEM;
}
reg = readl(per_cpu_int_base + ARMADA_370_XP_IN_DRBEL_MSK_OFFS)
| PCI_MSI_DOORBELL_MASK;
writel(reg, per_cpu_int_base +
ARMADA_370_XP_IN_DRBEL_MSK_OFFS);
writel(1, per_cpu_int_base + ARMADA_370_XP_INT_CLEAR_MASK_OFFS);
return 0;
}
static inline int armada_370_xp_msi_init(struct device_node *node,
phys_addr_t main_int_phys_base)
{
return 0;
}
static int armada_xp_set_affinity(struct irq_data *d,
const struct cpumask *mask_val, bool force)
{
irq_hw_number_t hwirq = irqd_to_hwirq(d);
unsigned long reg, mask;
int cpu;
cpu = cpumask_any_and(mask_val, cpu_online_mask);
mask = 1UL << cpu_logical_map(cpu);
raw_spin_lock(&irq_controller_lock);
reg = readl(main_int_base + ARMADA_370_XP_INT_SOURCE_CTL(hwirq));
reg = (reg & (~ARMADA_370_XP_INT_SOURCE_CPU_MASK)) | mask;
writel(reg, main_int_base + ARMADA_370_XP_INT_SOURCE_CTL(hwirq));
raw_spin_unlock(&irq_controller_lock);
return IRQ_SET_MASK_OK;
}
static int armada_370_xp_mpic_irq_map(struct irq_domain *h,
unsigned int virq, irq_hw_number_t hw)
{
armada_370_xp_irq_mask(irq_get_irq_data(virq));
if (!is_percpu_irq(hw))
writel(hw, per_cpu_int_base +
ARMADA_370_XP_INT_CLEAR_MASK_OFFS);
else
writel(hw, main_int_base + ARMADA_370_XP_INT_SET_ENABLE_OFFS);
irq_set_status_flags(virq, IRQ_LEVEL);
if (is_percpu_irq(hw)) {
irq_set_percpu_devid(virq);
irq_set_chip_and_handler(virq, &armada_370_xp_irq_chip,
handle_percpu_devid_irq);
} else {
irq_set_chip_and_handler(virq, &armada_370_xp_irq_chip,
handle_level_irq);
}
irq_set_probe(virq);
irq_clear_status_flags(virq, IRQ_NOAUTOEN);
return 0;
}
static void armada_xp_mpic_smp_cpu_init(void)
{
u32 control;
int nr_irqs, i;
control = readl(main_int_base + ARMADA_370_XP_INT_CONTROL);
nr_irqs = (control >> 2) & 0x3ff;
for (i = 0; i < nr_irqs; i++)
writel(i, per_cpu_int_base + ARMADA_370_XP_INT_SET_MASK_OFFS);
writel(0, per_cpu_int_base + ARMADA_370_XP_IN_DRBEL_CAUSE_OFFS);
writel(IPI_DOORBELL_MASK, per_cpu_int_base +
ARMADA_370_XP_IN_DRBEL_MSK_OFFS);
writel(0, per_cpu_int_base + ARMADA_370_XP_INT_CLEAR_MASK_OFFS);
}
static void armada_xp_mpic_perf_init(void)
{
unsigned long cpuid = cpu_logical_map(smp_processor_id());
writel(ARMADA_370_XP_INT_CAUSE_PERF(cpuid),
per_cpu_int_base + ARMADA_370_XP_INT_FABRIC_MASK_OFFS);
}
static void armada_mpic_send_doorbell(const struct cpumask *mask,
unsigned int irq)
{
int cpu;
unsigned long map = 0;
for_each_cpu(cpu, mask)
map |= 1 << cpu_logical_map(cpu);
dsb();
writel((map << 8) | irq, main_int_base +
ARMADA_370_XP_SW_TRIG_INT_OFFS);
}
static int armada_xp_mpic_starting_cpu(unsigned int cpu)
{
armada_xp_mpic_perf_init();
armada_xp_mpic_smp_cpu_init();
return 0;
}
static int mpic_cascaded_starting_cpu(unsigned int cpu)
{
armada_xp_mpic_perf_init();
enable_percpu_irq(parent_irq, IRQ_TYPE_NONE);
return 0;
}
static void armada_370_xp_handle_msi_irq(struct pt_regs *regs, bool is_chained)
{
u32 msimask, msinr;
msimask = readl_relaxed(per_cpu_int_base +
ARMADA_370_XP_IN_DRBEL_CAUSE_OFFS)
& PCI_MSI_DOORBELL_MASK;
writel(~msimask, per_cpu_int_base +
ARMADA_370_XP_IN_DRBEL_CAUSE_OFFS);
for (msinr = PCI_MSI_DOORBELL_START;
msinr < PCI_MSI_DOORBELL_END; msinr++) {
int irq;
if (!(msimask & BIT(msinr)))
continue;
if (is_chained) {
irq = irq_find_mapping(armada_370_xp_msi_inner_domain,
msinr - PCI_MSI_DOORBELL_START);
generic_handle_irq(irq);
} else {
irq = msinr - PCI_MSI_DOORBELL_START;
handle_domain_irq(armada_370_xp_msi_inner_domain,
irq, regs);
}
}
}
static void armada_370_xp_handle_msi_irq(struct pt_regs *r, bool b) {}
static void armada_370_xp_mpic_handle_cascade_irq(struct irq_desc *desc)
{
struct irq_chip *chip = irq_desc_get_chip(desc);
unsigned long irqmap, irqn, irqsrc, cpuid;
unsigned int cascade_irq;
chained_irq_enter(chip, desc);
irqmap = readl_relaxed(per_cpu_int_base + ARMADA_375_PPI_CAUSE);
cpuid = cpu_logical_map(smp_processor_id());
for_each_set_bit(irqn, &irqmap, BITS_PER_LONG) {
irqsrc = readl_relaxed(main_int_base +
ARMADA_370_XP_INT_SOURCE_CTL(irqn));
if (!(irqsrc & ARMADA_370_XP_INT_IRQ_FIQ_MASK(cpuid)))
continue;
if (irqn == 1) {
armada_370_xp_handle_msi_irq(NULL, true);
continue;
}
cascade_irq = irq_find_mapping(armada_370_xp_mpic_domain, irqn);
generic_handle_irq(cascade_irq);
}
chained_irq_exit(chip, desc);
}
static void __exception_irq_entry
armada_370_xp_handle_irq(struct pt_regs *regs)
{
u32 irqstat, irqnr;
do {
irqstat = readl_relaxed(per_cpu_int_base +
ARMADA_370_XP_CPU_INTACK_OFFS);
irqnr = irqstat & 0x3FF;
if (irqnr > 1022)
break;
if (irqnr > 1) {
handle_domain_irq(armada_370_xp_mpic_domain,
irqnr, regs);
continue;
}
if (irqnr == 1)
armada_370_xp_handle_msi_irq(regs, false);
#ifdef CONFIG_SMP
if (irqnr == 0) {
u32 ipimask, ipinr;
ipimask = readl_relaxed(per_cpu_int_base +
ARMADA_370_XP_IN_DRBEL_CAUSE_OFFS)
& IPI_DOORBELL_MASK;
writel(~ipimask, per_cpu_int_base +
ARMADA_370_XP_IN_DRBEL_CAUSE_OFFS);
for (ipinr = IPI_DOORBELL_START;
ipinr < IPI_DOORBELL_END; ipinr++) {
if (ipimask & (0x1 << ipinr))
handle_IPI(ipinr, regs);
}
continue;
}
#endif
} while (1);
}
static int armada_370_xp_mpic_suspend(void)
{
doorbell_mask_reg = readl(per_cpu_int_base +
ARMADA_370_XP_IN_DRBEL_MSK_OFFS);
return 0;
}
static void armada_370_xp_mpic_resume(void)
{
int nirqs;
irq_hw_number_t irq;
nirqs = (readl(main_int_base + ARMADA_370_XP_INT_CONTROL) >> 2) & 0x3ff;
for (irq = 0; irq < nirqs; irq++) {
struct irq_data *data;
int virq;
virq = irq_linear_revmap(armada_370_xp_mpic_domain, irq);
if (virq == 0)
continue;
if (!is_percpu_irq(irq))
writel(irq, per_cpu_int_base +
ARMADA_370_XP_INT_CLEAR_MASK_OFFS);
else
writel(irq, main_int_base +
ARMADA_370_XP_INT_SET_ENABLE_OFFS);
data = irq_get_irq_data(virq);
if (!irqd_irq_disabled(data))
armada_370_xp_irq_unmask(data);
}
writel(doorbell_mask_reg,
per_cpu_int_base + ARMADA_370_XP_IN_DRBEL_MSK_OFFS);
if (doorbell_mask_reg & IPI_DOORBELL_MASK)
writel(0, per_cpu_int_base + ARMADA_370_XP_INT_CLEAR_MASK_OFFS);
if (doorbell_mask_reg & PCI_MSI_DOORBELL_MASK)
writel(1, per_cpu_int_base + ARMADA_370_XP_INT_CLEAR_MASK_OFFS);
}
static int __init armada_370_xp_mpic_of_init(struct device_node *node,
struct device_node *parent)
{
struct resource main_int_res, per_cpu_int_res;
int nr_irqs, i;
u32 control;
BUG_ON(of_address_to_resource(node, 0, &main_int_res));
BUG_ON(of_address_to_resource(node, 1, &per_cpu_int_res));
BUG_ON(!request_mem_region(main_int_res.start,
resource_size(&main_int_res),
node->full_name));
BUG_ON(!request_mem_region(per_cpu_int_res.start,
resource_size(&per_cpu_int_res),
node->full_name));
main_int_base = ioremap(main_int_res.start,
resource_size(&main_int_res));
BUG_ON(!main_int_base);
per_cpu_int_base = ioremap(per_cpu_int_res.start,
resource_size(&per_cpu_int_res));
BUG_ON(!per_cpu_int_base);
control = readl(main_int_base + ARMADA_370_XP_INT_CONTROL);
nr_irqs = (control >> 2) & 0x3ff;
for (i = 0; i < nr_irqs; i++)
writel(i, main_int_base + ARMADA_370_XP_INT_CLEAR_ENABLE_OFFS);
armada_370_xp_mpic_domain =
irq_domain_add_linear(node, nr_irqs,
&armada_370_xp_mpic_irq_ops, NULL);
BUG_ON(!armada_370_xp_mpic_domain);
armada_370_xp_mpic_domain->bus_token = DOMAIN_BUS_WIRED;
armada_xp_mpic_perf_init();
armada_xp_mpic_smp_cpu_init();
armada_370_xp_msi_init(node, main_int_res.start);
parent_irq = irq_of_parse_and_map(node, 0);
if (parent_irq <= 0) {
irq_set_default_host(armada_370_xp_mpic_domain);
set_handle_irq(armada_370_xp_handle_irq);
#ifdef CONFIG_SMP
set_smp_cross_call(armada_mpic_send_doorbell);
cpuhp_setup_state_nocalls(CPUHP_AP_IRQ_ARMADA_XP_STARTING,
"AP_IRQ_ARMADA_XP_STARTING",
armada_xp_mpic_starting_cpu, NULL);
#endif
} else {
#ifdef CONFIG_SMP
cpuhp_setup_state_nocalls(CPUHP_AP_IRQ_ARMADA_CASC_STARTING,
"AP_IRQ_ARMADA_CASC_STARTING",
mpic_cascaded_starting_cpu, NULL);
#endif
irq_set_chained_handler(parent_irq,
armada_370_xp_mpic_handle_cascade_irq);
}
register_syscore_ops(&armada_370_xp_mpic_syscore_ops);
return 0;
}
