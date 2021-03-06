void xics_update_irq_servers(void)
{
int i, j;
struct device_node *np;
u32 ilen;
const __be32 *ireg;
u32 hcpuid;
np = of_get_cpu_node(boot_cpuid, NULL);
BUG_ON(!np);
hcpuid = get_hard_smp_processor_id(boot_cpuid);
xics_default_server = xics_default_distrib_server = hcpuid;
pr_devel("xics: xics_default_server = 0x%x\n", xics_default_server);
ireg = of_get_property(np, "ibm,ppc-interrupt-gserver#s", &ilen);
if (!ireg) {
of_node_put(np);
return;
}
i = ilen / sizeof(int);
for (j = 0; j < i; j += 2) {
if (be32_to_cpu(ireg[j]) == hcpuid) {
xics_default_distrib_server = be32_to_cpu(ireg[j+1]);
break;
}
}
pr_devel("xics: xics_default_distrib_server = 0x%x\n",
xics_default_distrib_server);
of_node_put(np);
}
void xics_set_cpu_giq(unsigned int gserver, unsigned int join)
{
#ifdef CONFIG_PPC_RTAS
int index;
int status;
if (!rtas_indicator_present(GLOBAL_INTERRUPT_QUEUE, NULL))
return;
index = (1UL << xics_interrupt_server_size) - 1 - gserver;
status = rtas_set_indicator_fast(GLOBAL_INTERRUPT_QUEUE, index, join);
WARN(status < 0, "set-indicator(%d, %d, %u) returned %d\n",
GLOBAL_INTERRUPT_QUEUE, index, join, status);
#endif
}
void xics_setup_cpu(void)
{
icp_ops->set_priority(LOWEST_PRIORITY);
xics_set_cpu_giq(xics_default_distrib_server, 1);
}
void xics_mask_unknown_vec(unsigned int vec)
{
struct ics *ics;
pr_err("Interrupt 0x%x (real) is invalid, disabling it.\n", vec);
list_for_each_entry(ics, &ics_list, link)
ics->mask_unknown(ics, vec);
}
static void xics_request_ipi(void)
{
unsigned int ipi;
ipi = irq_create_mapping(xics_host, XICS_IPI);
BUG_ON(ipi == NO_IRQ);
BUG_ON(request_irq(ipi, icp_ops->ipi_action,
IRQF_PERCPU | IRQF_NO_THREAD, "IPI", NULL));
}
void __init xics_smp_probe(void)
{
smp_ops->cause_ipi = icp_ops->cause_ipi;
xics_request_ipi();
}
void xics_teardown_cpu(void)
{
struct xics_cppr *os_cppr = this_cpu_ptr(&xics_cppr);
os_cppr->index = 0;
icp_ops->set_priority(0);
icp_ops->teardown_cpu();
}
void xics_kexec_teardown_cpu(int secondary)
{
xics_teardown_cpu();
icp_ops->flush_ipi();
if (secondary)
xics_set_cpu_giq(xics_default_distrib_server, 0);
}
void xics_migrate_irqs_away(void)
{
int cpu = smp_processor_id(), hw_cpu = hard_smp_processor_id();
unsigned int irq, virq;
struct irq_desc *desc;
if (hw_cpu == xics_default_server)
xics_update_irq_servers();
icp_ops->set_priority(0);
xics_set_cpu_giq(xics_default_distrib_server, 0);
icp_ops->set_priority(DEFAULT_PRIORITY);
for_each_irq_desc(virq, desc) {
struct irq_chip *chip;
long server;
unsigned long flags;
struct ics *ics;
if (virq < NUM_ISA_INTERRUPTS)
continue;
if (!desc->action)
continue;
if (desc->irq_data.domain != xics_host)
continue;
irq = desc->irq_data.hwirq;
if (irq == XICS_IPI || irq == XICS_IRQ_SPURIOUS)
continue;
chip = irq_desc_get_chip(desc);
if (!chip || !chip->irq_set_affinity)
continue;
raw_spin_lock_irqsave(&desc->lock, flags);
server = -1;
ics = irq_desc_get_chip_data(desc);
if (ics)
server = ics->get_server(ics, irq);
if (server < 0) {
printk(KERN_ERR "%s: Can't find server for irq %d\n",
__func__, irq);
goto unlock;
}
if (server != hw_cpu)
goto unlock;
if (cpu_online(cpu))
pr_warning("IRQ %u affinity broken off cpu %u\n",
virq, cpu);
raw_spin_unlock_irqrestore(&desc->lock, flags);
irq_set_affinity(virq, cpu_all_mask);
continue;
unlock:
raw_spin_unlock_irqrestore(&desc->lock, flags);
}
}
int xics_get_irq_server(unsigned int virq, const struct cpumask *cpumask,
unsigned int strict_check)
{
if (!distribute_irqs)
return xics_default_server;
if (!cpumask_subset(cpu_possible_mask, cpumask)) {
int server = cpumask_first_and(cpu_online_mask, cpumask);
if (server < nr_cpu_ids)
return get_hard_smp_processor_id(server);
if (strict_check)
return -1;
}
if (cpumask_equal(cpu_online_mask, cpu_present_mask))
return xics_default_distrib_server;
return xics_default_server;
}
static int xics_host_match(struct irq_domain *h, struct device_node *node,
enum irq_domain_bus_token bus_token)
{
struct ics *ics;
list_for_each_entry(ics, &ics_list, link)
if (ics->host_match(ics, node))
return 1;
return 0;
}
static void xics_ipi_unmask(struct irq_data *d) { }
static void xics_ipi_mask(struct irq_data *d) { }
static int xics_host_map(struct irq_domain *h, unsigned int virq,
irq_hw_number_t hw)
{
struct ics *ics;
pr_devel("xics: map virq %d, hwirq 0x%lx\n", virq, hw);
irq_clear_status_flags(virq, IRQ_LEVEL);
if (hw == XICS_IPI) {
irq_set_chip_and_handler(virq, &xics_ipi_chip,
handle_percpu_irq);
return 0;
}
list_for_each_entry(ics, &ics_list, link)
if (ics->map(ics, virq) == 0)
return 0;
return -EINVAL;
}
static int xics_host_xlate(struct irq_domain *h, struct device_node *ct,
const u32 *intspec, unsigned int intsize,
irq_hw_number_t *out_hwirq, unsigned int *out_flags)
{
*out_hwirq = intspec[0];
if (intsize > 1) {
if (intspec[1] & 1)
*out_flags = IRQ_TYPE_LEVEL_LOW;
else
*out_flags = IRQ_TYPE_EDGE_RISING;
} else
*out_flags = IRQ_TYPE_LEVEL_LOW;
return 0;
}
int xics_set_irq_type(struct irq_data *d, unsigned int flow_type)
{
if (flow_type == IRQ_TYPE_DEFAULT || flow_type == IRQ_TYPE_NONE)
flow_type = IRQ_TYPE_EDGE_RISING;
if (flow_type != IRQ_TYPE_EDGE_RISING &&
flow_type != IRQ_TYPE_LEVEL_LOW)
return -EINVAL;
irqd_set_trigger_type(d, flow_type);
return IRQ_SET_MASK_OK_NOCOPY;
}
int xics_retrigger(struct irq_data *data)
{
xics_push_cppr(0);
return 0;
}
static void __init xics_init_host(void)
{
xics_host = irq_domain_add_tree(NULL, &xics_host_ops, NULL);
BUG_ON(xics_host == NULL);
irq_set_default_host(xics_host);
}
void __init xics_register_ics(struct ics *ics)
{
list_add(&ics->link, &ics_list);
}
static void __init xics_get_server_size(void)
{
struct device_node *np;
const __be32 *isize;
np = of_find_compatible_node(NULL, NULL, "ibm,ppc-xics");
if (!np)
return;
isize = of_get_property(np, "ibm,interrupt-server#-size", NULL);
if (!isize)
return;
xics_interrupt_server_size = be32_to_cpu(*isize);
of_node_put(np);
}
void __init xics_init(void)
{
int rc = -1;
if (firmware_has_feature(FW_FEATURE_LPAR))
rc = icp_hv_init();
if (rc < 0) {
rc = icp_native_init();
if (rc == -ENODEV)
rc = icp_opal_init();
}
if (rc < 0) {
pr_warning("XICS: Cannot find a Presentation Controller !\n");
return;
}
ppc_md.get_irq = icp_ops->get_irq;
xics_ipi_chip.irq_eoi = icp_ops->eoi;
rc = ics_rtas_init();
if (rc < 0)
rc = ics_opal_init();
if (rc < 0)
pr_warning("XICS: Cannot find a Source Controller !\n");
xics_get_server_size();
xics_update_irq_servers();
xics_init_host();
xics_setup_cpu();
}
