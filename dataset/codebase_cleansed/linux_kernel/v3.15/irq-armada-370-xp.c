static void armada_370_xp_irq_mask(struct irq_data *d)
{
irq_hw_number_t hwirq = irqd_to_hwirq(d);
if (hwirq != ARMADA_370_XP_TIMER0_PER_CPU_IRQ)
writel(hwirq, main_int_base +
ARMADA_370_XP_INT_CLEAR_ENABLE_OFFS);
else
writel(hwirq, per_cpu_int_base +
ARMADA_370_XP_INT_SET_MASK_OFFS);
}
static void armada_370_xp_irq_unmask(struct irq_data *d)
{
irq_hw_number_t hwirq = irqd_to_hwirq(d);
if (hwirq != ARMADA_370_XP_TIMER0_PER_CPU_IRQ)
writel(hwirq, main_int_base +
ARMADA_370_XP_INT_SET_ENABLE_OFFS);
else
writel(hwirq, per_cpu_int_base +
ARMADA_370_XP_INT_CLEAR_MASK_OFFS);
}
static int armada_370_xp_alloc_msi(void)
{
int hwirq;
mutex_lock(&msi_used_lock);
hwirq = find_first_zero_bit(&msi_used, PCI_MSI_DOORBELL_NR);
if (hwirq >= PCI_MSI_DOORBELL_NR)
hwirq = -ENOSPC;
else
set_bit(hwirq, msi_used);
mutex_unlock(&msi_used_lock);
return hwirq;
}
static void armada_370_xp_free_msi(int hwirq)
{
mutex_lock(&msi_used_lock);
if (!test_bit(hwirq, msi_used))
pr_err("trying to free unused MSI#%d\n", hwirq);
else
clear_bit(hwirq, msi_used);
mutex_unlock(&msi_used_lock);
}
static int armada_370_xp_setup_msi_irq(struct msi_chip *chip,
struct pci_dev *pdev,
struct msi_desc *desc)
{
struct msi_msg msg;
int virq, hwirq;
hwirq = armada_370_xp_alloc_msi();
if (hwirq < 0)
return hwirq;
virq = irq_create_mapping(armada_370_xp_msi_domain, hwirq);
if (!virq) {
armada_370_xp_free_msi(hwirq);
return -EINVAL;
}
irq_set_msi_desc(virq, desc);
msg.address_lo = msi_doorbell_addr;
msg.address_hi = 0;
msg.data = 0xf00 | (hwirq + 16);
write_msi_msg(virq, &msg);
return 0;
}
static void armada_370_xp_teardown_msi_irq(struct msi_chip *chip,
unsigned int irq)
{
struct irq_data *d = irq_get_irq_data(irq);
unsigned long hwirq = d->hwirq;
irq_dispose_mapping(irq);
armada_370_xp_free_msi(hwirq);
}
static int armada_370_xp_check_msi_device(struct msi_chip *chip, struct pci_dev *dev,
int nvec, int type)
{
if (type == PCI_CAP_ID_MSI)
return 0;
return -EINVAL;
}
static int armada_370_xp_msi_map(struct irq_domain *domain, unsigned int virq,
irq_hw_number_t hw)
{
irq_set_chip_and_handler(virq, &armada_370_xp_msi_irq_chip,
handle_simple_irq);
set_irq_flags(virq, IRQF_VALID);
return 0;
}
static int armada_370_xp_msi_init(struct device_node *node,
phys_addr_t main_int_phys_base)
{
struct msi_chip *msi_chip;
u32 reg;
int ret;
msi_doorbell_addr = main_int_phys_base +
ARMADA_370_XP_SW_TRIG_INT_OFFS;
msi_chip = kzalloc(sizeof(*msi_chip), GFP_KERNEL);
if (!msi_chip)
return -ENOMEM;
msi_chip->setup_irq = armada_370_xp_setup_msi_irq;
msi_chip->teardown_irq = armada_370_xp_teardown_msi_irq;
msi_chip->check_device = armada_370_xp_check_msi_device;
msi_chip->of_node = node;
armada_370_xp_msi_domain =
irq_domain_add_linear(NULL, PCI_MSI_DOORBELL_NR,
&armada_370_xp_msi_irq_ops,
NULL);
if (!armada_370_xp_msi_domain) {
kfree(msi_chip);
return -ENOMEM;
}
ret = of_pci_msi_chip_add(msi_chip);
if (ret < 0) {
irq_domain_remove(armada_370_xp_msi_domain);
kfree(msi_chip);
return ret;
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
return 0;
}
static int armada_370_xp_mpic_irq_map(struct irq_domain *h,
unsigned int virq, irq_hw_number_t hw)
{
armada_370_xp_irq_mask(irq_get_irq_data(virq));
if (hw != ARMADA_370_XP_TIMER0_PER_CPU_IRQ)
writel(hw, per_cpu_int_base +
ARMADA_370_XP_INT_CLEAR_MASK_OFFS);
else
writel(hw, main_int_base + ARMADA_370_XP_INT_SET_ENABLE_OFFS);
irq_set_status_flags(virq, IRQ_LEVEL);
if (hw == ARMADA_370_XP_TIMER0_PER_CPU_IRQ) {
irq_set_percpu_devid(virq);
irq_set_chip_and_handler(virq, &armada_370_xp_irq_chip,
handle_percpu_devid_irq);
} else {
irq_set_chip_and_handler(virq, &armada_370_xp_irq_chip,
handle_level_irq);
}
set_irq_flags(virq, IRQF_VALID | IRQF_PROBE);
return 0;
}
void armada_mpic_send_doorbell(const struct cpumask *mask, unsigned int irq)
{
int cpu;
unsigned long map = 0;
for_each_cpu(cpu, mask)
map |= 1 << cpu_logical_map(cpu);
dsb();
writel((map << 8) | irq, main_int_base +
ARMADA_370_XP_SW_TRIG_INT_OFFS);
}
void armada_xp_mpic_smp_cpu_init(void)
{
writel(0, per_cpu_int_base + ARMADA_370_XP_IN_DRBEL_CAUSE_OFFS);
writel(IPI_DOORBELL_MASK, per_cpu_int_base +
ARMADA_370_XP_IN_DRBEL_MSK_OFFS);
writel(0, per_cpu_int_base + ARMADA_370_XP_INT_CLEAR_MASK_OFFS);
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
irq = irq_find_mapping(armada_370_xp_msi_domain,
msinr - 16);
if (is_chained)
generic_handle_irq(irq);
else
handle_IRQ(irq, regs);
}
}
static void armada_370_xp_handle_msi_irq(struct pt_regs *r, bool b) {}
static void armada_370_xp_mpic_handle_cascade_irq(unsigned int irq,
struct irq_desc *desc)
{
struct irq_chip *chip = irq_get_chip(irq);
unsigned long irqmap, irqn;
unsigned int cascade_irq;
chained_irq_enter(chip, desc);
irqmap = readl_relaxed(per_cpu_int_base + ARMADA_375_PPI_CAUSE);
if (irqmap & BIT(0)) {
armada_370_xp_handle_msi_irq(NULL, true);
irqmap &= ~BIT(0);
}
for_each_set_bit(irqn, &irqmap, BITS_PER_LONG) {
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
irqnr = irq_find_mapping(armada_370_xp_mpic_domain,
irqnr);
handle_IRQ(irqnr, regs);
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
static int __init armada_370_xp_mpic_of_init(struct device_node *node,
struct device_node *parent)
{
struct resource main_int_res, per_cpu_int_res;
int parent_irq;
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
armada_370_xp_mpic_domain =
irq_domain_add_linear(node, (control >> 2) & 0x3ff,
&armada_370_xp_mpic_irq_ops, NULL);
BUG_ON(!armada_370_xp_mpic_domain);
#ifdef CONFIG_SMP
armada_xp_mpic_smp_cpu_init();
#endif
armada_370_xp_msi_init(node, main_int_res.start);
parent_irq = irq_of_parse_and_map(node, 0);
if (parent_irq <= 0) {
irq_set_default_host(armada_370_xp_mpic_domain);
set_handle_irq(armada_370_xp_handle_irq);
} else {
irq_set_chained_handler(parent_irq,
armada_370_xp_mpic_handle_cascade_irq);
}
return 0;
}
