static void bcm2836_arm_irqchip_mask_per_cpu_irq(unsigned int reg_offset,
unsigned int bit,
int cpu)
{
void __iomem *reg = intc.base + reg_offset + 4 * cpu;
writel(readl(reg) & ~BIT(bit), reg);
}
static void bcm2836_arm_irqchip_unmask_per_cpu_irq(unsigned int reg_offset,
unsigned int bit,
int cpu)
{
void __iomem *reg = intc.base + reg_offset + 4 * cpu;
writel(readl(reg) | BIT(bit), reg);
}
static void bcm2836_arm_irqchip_mask_timer_irq(struct irq_data *d)
{
bcm2836_arm_irqchip_mask_per_cpu_irq(LOCAL_TIMER_INT_CONTROL0,
d->hwirq - LOCAL_IRQ_CNTPSIRQ,
smp_processor_id());
}
static void bcm2836_arm_irqchip_unmask_timer_irq(struct irq_data *d)
{
bcm2836_arm_irqchip_unmask_per_cpu_irq(LOCAL_TIMER_INT_CONTROL0,
d->hwirq - LOCAL_IRQ_CNTPSIRQ,
smp_processor_id());
}
static void bcm2836_arm_irqchip_mask_pmu_irq(struct irq_data *d)
{
writel(1 << smp_processor_id(), intc.base + LOCAL_PM_ROUTING_CLR);
}
static void bcm2836_arm_irqchip_unmask_pmu_irq(struct irq_data *d)
{
writel(1 << smp_processor_id(), intc.base + LOCAL_PM_ROUTING_SET);
}
static void bcm2836_arm_irqchip_mask_gpu_irq(struct irq_data *d)
{
}
static void bcm2836_arm_irqchip_unmask_gpu_irq(struct irq_data *d)
{
}
static void bcm2836_arm_irqchip_register_irq(int hwirq, struct irq_chip *chip)
{
int irq = irq_create_mapping(intc.domain, hwirq);
irq_set_percpu_devid(irq);
irq_set_chip_and_handler(irq, chip, handle_percpu_devid_irq);
irq_set_status_flags(irq, IRQ_NOAUTOEN);
}
static void
__exception_irq_entry bcm2836_arm_irqchip_handle_irq(struct pt_regs *regs)
{
int cpu = smp_processor_id();
u32 stat;
stat = readl_relaxed(intc.base + LOCAL_IRQ_PENDING0 + 4 * cpu);
if (stat & BIT(LOCAL_IRQ_MAILBOX0)) {
#ifdef CONFIG_SMP
void __iomem *mailbox0 = (intc.base +
LOCAL_MAILBOX0_CLR0 + 16 * cpu);
u32 mbox_val = readl(mailbox0);
u32 ipi = ffs(mbox_val) - 1;
writel(1 << ipi, mailbox0);
handle_IPI(ipi, regs);
#endif
} else if (stat) {
u32 hwirq = ffs(stat) - 1;
handle_domain_irq(intc.domain, hwirq, regs);
}
}
static void bcm2836_arm_irqchip_send_ipi(const struct cpumask *mask,
unsigned int ipi)
{
int cpu;
void __iomem *mailbox0_base = intc.base + LOCAL_MAILBOX0_SET0;
smp_wmb();
for_each_cpu(cpu, mask) {
writel(1 << ipi, mailbox0_base + 16 * cpu);
}
}
static int bcm2836_cpu_starting(unsigned int cpu)
{
bcm2836_arm_irqchip_unmask_per_cpu_irq(LOCAL_MAILBOX_INT_CONTROL0, 0,
cpu);
return 0;
}
static int bcm2836_cpu_dying(unsigned int cpu)
{
bcm2836_arm_irqchip_mask_per_cpu_irq(LOCAL_MAILBOX_INT_CONTROL0, 0,
cpu);
return 0;
}
static int __init bcm2836_smp_boot_secondary(unsigned int cpu,
struct task_struct *idle)
{
unsigned long secondary_startup_phys =
(unsigned long)virt_to_phys((void *)secondary_startup);
writel(secondary_startup_phys,
intc.base + LOCAL_MAILBOX3_SET0 + 16 * cpu);
return 0;
}
static void
bcm2836_arm_irqchip_smp_init(void)
{
#ifdef CONFIG_SMP
cpuhp_setup_state(CPUHP_AP_IRQ_BCM2836_STARTING,
"AP_IRQ_BCM2836_STARTING", bcm2836_cpu_starting,
bcm2836_cpu_dying);
set_smp_cross_call(bcm2836_arm_irqchip_send_ipi);
#ifdef CONFIG_ARM
smp_set_ops(&bcm2836_smp_ops);
#endif
#endif
}
static void bcm2835_init_local_timer_frequency(void)
{
writel(0, intc.base + LOCAL_CONTROL);
writel(0x80000000, intc.base + LOCAL_PRESCALER);
}
static int __init bcm2836_arm_irqchip_l1_intc_of_init(struct device_node *node,
struct device_node *parent)
{
intc.base = of_iomap(node, 0);
if (!intc.base) {
panic("%s: unable to map local interrupt registers\n",
node->full_name);
}
bcm2835_init_local_timer_frequency();
intc.domain = irq_domain_add_linear(node, LAST_IRQ + 1,
&bcm2836_arm_irqchip_intc_ops,
NULL);
if (!intc.domain)
panic("%s: unable to create IRQ domain\n", node->full_name);
bcm2836_arm_irqchip_register_irq(LOCAL_IRQ_CNTPSIRQ,
&bcm2836_arm_irqchip_timer);
bcm2836_arm_irqchip_register_irq(LOCAL_IRQ_CNTPNSIRQ,
&bcm2836_arm_irqchip_timer);
bcm2836_arm_irqchip_register_irq(LOCAL_IRQ_CNTHPIRQ,
&bcm2836_arm_irqchip_timer);
bcm2836_arm_irqchip_register_irq(LOCAL_IRQ_CNTVIRQ,
&bcm2836_arm_irqchip_timer);
bcm2836_arm_irqchip_register_irq(LOCAL_IRQ_GPU_FAST,
&bcm2836_arm_irqchip_gpu);
bcm2836_arm_irqchip_register_irq(LOCAL_IRQ_PMU_FAST,
&bcm2836_arm_irqchip_pmu);
bcm2836_arm_irqchip_smp_init();
set_handle_irq(bcm2836_arm_irqchip_handle_irq);
return 0;
}
