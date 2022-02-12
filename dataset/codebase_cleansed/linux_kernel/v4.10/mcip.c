static void mcip_setup_per_cpu(int cpu)
{
smp_ipi_irq_setup(cpu, IPI_IRQ);
smp_ipi_irq_setup(cpu, SOFTIRQ_IRQ);
}
static void mcip_ipi_send(int cpu)
{
unsigned long flags;
int ipi_was_pending;
if (unlikely(cpu == raw_smp_processor_id())) {
arc_softirq_trigger(SOFTIRQ_IRQ);
return;
}
raw_spin_lock_irqsave(&mcip_lock, flags);
__mcip_cmd(CMD_INTRPT_READ_STATUS, cpu);
ipi_was_pending = read_aux_reg(ARC_REG_MCIP_READBACK);
if (!ipi_was_pending)
__mcip_cmd(CMD_INTRPT_GENERATE_IRQ, cpu);
raw_spin_unlock_irqrestore(&mcip_lock, flags);
}
static void mcip_ipi_clear(int irq)
{
unsigned int cpu, c;
unsigned long flags;
if (unlikely(irq == SOFTIRQ_IRQ)) {
arc_softirq_clear(irq);
return;
}
raw_spin_lock_irqsave(&mcip_lock, flags);
__mcip_cmd(CMD_INTRPT_CHECK_SOURCE, 0);
cpu = read_aux_reg(ARC_REG_MCIP_READBACK);
do {
c = __ffs(cpu);
__mcip_cmd(CMD_INTRPT_GENERATE_ACK, c);
cpu &= ~(1U << c);
} while (cpu);
raw_spin_unlock_irqrestore(&mcip_lock, flags);
}
static void mcip_probe_n_setup(void)
{
struct mcip_bcr mp;
READ_BCR(ARC_REG_MCIP_BCR, mp);
sprintf(smp_cpuinfo_buf,
"Extn [SMP]\t: ARConnect (v%d): %d cores with %s%s%s%s\n",
mp.ver, mp.num_cores,
IS_AVAIL1(mp.ipi, "IPI "),
IS_AVAIL1(mp.idu, "IDU "),
IS_AVAIL1(mp.dbg, "DEBUG "),
IS_AVAIL1(mp.gfrc, "GFRC"));
cpuinfo_arc700[0].extn.gfrc = mp.gfrc;
if (mp.dbg) {
__mcip_cmd_data(CMD_DEBUG_SET_SELECT, 0, 0xf);
__mcip_cmd_data(CMD_DEBUG_SET_MASK, 0xf, 0xf);
}
}
static void idu_set_dest(unsigned int cmn_irq, unsigned int cpu_mask)
{
__mcip_cmd_data(CMD_IDU_SET_DEST, cmn_irq, cpu_mask);
}
static void idu_set_mode(unsigned int cmn_irq, unsigned int lvl,
unsigned int distr)
{
union {
unsigned int word;
struct {
unsigned int distr:2, pad:2, lvl:1, pad2:27;
};
} data;
data.distr = distr;
data.lvl = lvl;
__mcip_cmd_data(CMD_IDU_SET_MODE, cmn_irq, data.word);
}
static void idu_irq_mask(struct irq_data *data)
{
unsigned long flags;
raw_spin_lock_irqsave(&mcip_lock, flags);
__mcip_cmd_data(CMD_IDU_SET_MASK, data->hwirq, 1);
raw_spin_unlock_irqrestore(&mcip_lock, flags);
}
static void idu_irq_unmask(struct irq_data *data)
{
unsigned long flags;
raw_spin_lock_irqsave(&mcip_lock, flags);
__mcip_cmd_data(CMD_IDU_SET_MASK, data->hwirq, 0);
raw_spin_unlock_irqrestore(&mcip_lock, flags);
}
static int
idu_irq_set_affinity(struct irq_data *data, const struct cpumask *cpumask,
bool force)
{
unsigned long flags;
cpumask_t online;
unsigned int destination_bits;
unsigned int distribution_mode;
if (!cpumask_and(&online, cpumask, cpu_online_mask))
return -EINVAL;
raw_spin_lock_irqsave(&mcip_lock, flags);
destination_bits = cpumask_bits(&online)[0];
idu_set_dest(data->hwirq, destination_bits);
if (ffs(destination_bits) == fls(destination_bits))
distribution_mode = IDU_M_DISTRI_DEST;
else
distribution_mode = IDU_M_DISTRI_RR;
idu_set_mode(data->hwirq, IDU_M_TRIG_LEVEL, distribution_mode);
raw_spin_unlock_irqrestore(&mcip_lock, flags);
return IRQ_SET_MASK_OK;
}
static void idu_irq_enable(struct irq_data *data)
{
idu_irq_set_affinity(data, cpu_online_mask, false);
idu_irq_unmask(data);
}
static void idu_cascade_isr(struct irq_desc *desc)
{
struct irq_domain *idu_domain = irq_desc_get_handler_data(desc);
struct irq_chip *core_chip = irq_desc_get_chip(desc);
irq_hw_number_t core_hwirq = irqd_to_hwirq(irq_desc_get_irq_data(desc));
irq_hw_number_t idu_hwirq = core_hwirq - idu_first_hwirq;
chained_irq_enter(core_chip, desc);
generic_handle_irq(irq_find_mapping(idu_domain, idu_hwirq));
chained_irq_exit(core_chip, desc);
}
static int idu_irq_map(struct irq_domain *d, unsigned int virq, irq_hw_number_t hwirq)
{
irq_set_chip_and_handler(virq, &idu_irq_chip, handle_level_irq);
irq_set_status_flags(virq, IRQ_MOVE_PCNTXT);
return 0;
}
static int idu_irq_xlate(struct irq_domain *d, struct device_node *n,
const u32 *intspec, unsigned int intsize,
irq_hw_number_t *out_hwirq, unsigned int *out_type)
{
*out_hwirq = intspec[0];
*out_type = IRQ_TYPE_NONE;
return 0;
}
static int __init
idu_of_init(struct device_node *intc, struct device_node *parent)
{
struct irq_domain *domain;
int nr_irqs = of_irq_count(intc);
int i, virq;
struct mcip_bcr mp;
READ_BCR(ARC_REG_MCIP_BCR, mp);
if (!mp.idu)
panic("IDU not detected, but DeviceTree using it");
pr_info("MCIP: IDU referenced from Devicetree %d irqs\n", nr_irqs);
domain = irq_domain_add_linear(intc, nr_irqs, &idu_irq_ops, NULL);
for (i = 0; i < nr_irqs; i++) {
virq = irq_of_parse_and_map(intc, i);
if (!i)
idu_first_hwirq = irqd_to_hwirq(irq_get_irq_data(virq));
irq_set_chained_handler_and_data(virq, idu_cascade_isr, domain);
}
__mcip_cmd(CMD_IDU_ENABLE, 0);
return 0;
}
