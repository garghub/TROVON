void opal_handle_events(uint64_t events)
{
int virq, hwirq = 0;
u64 mask = opal_event_irqchip.mask;
if (!in_irq() && (events & mask)) {
last_outstanding_events = events;
irq_work_queue(&opal_event_irq_work);
return;
}
while (events & mask) {
hwirq = fls64(events) - 1;
if (BIT_ULL(hwirq) & mask) {
virq = irq_find_mapping(opal_event_irqchip.domain,
hwirq);
if (virq)
generic_handle_irq(virq);
}
events &= ~BIT_ULL(hwirq);
}
}
static void opal_event_mask(struct irq_data *d)
{
clear_bit(d->hwirq, &opal_event_irqchip.mask);
}
static void opal_event_unmask(struct irq_data *d)
{
__be64 events;
set_bit(d->hwirq, &opal_event_irqchip.mask);
opal_poll_events(&events);
last_outstanding_events = be64_to_cpu(events);
if (last_outstanding_events & opal_event_irqchip.mask)
irq_work_queue(&opal_event_irq_work);
}
static int opal_event_set_type(struct irq_data *d, unsigned int flow_type)
{
if (flow_type != IRQ_TYPE_LEVEL_HIGH)
return -EINVAL;
return 0;
}
static int opal_event_map(struct irq_domain *d, unsigned int irq,
irq_hw_number_t hwirq)
{
irq_set_chip_data(irq, &opal_event_irqchip);
irq_set_chip_and_handler(irq, &opal_event_irqchip.irqchip,
handle_level_irq);
return 0;
}
static irqreturn_t opal_interrupt(int irq, void *data)
{
__be64 events;
opal_handle_interrupt(virq_to_hw(irq), &events);
opal_handle_events(be64_to_cpu(events));
return IRQ_HANDLED;
}
static void opal_handle_irq_work(struct irq_work *work)
{
opal_handle_events(last_outstanding_events);
}
static int opal_event_match(struct irq_domain *h, struct device_node *node,
enum irq_domain_bus_token bus_token)
{
return irq_domain_get_of_node(h) == node;
}
static int opal_event_xlate(struct irq_domain *h, struct device_node *np,
const u32 *intspec, unsigned int intsize,
irq_hw_number_t *out_hwirq, unsigned int *out_flags)
{
*out_hwirq = intspec[0];
*out_flags = IRQ_TYPE_LEVEL_HIGH;
return 0;
}
void opal_event_shutdown(void)
{
unsigned int i;
for (i = 0; i < opal_irq_count; i++) {
if (opal_irqs[i])
free_irq(opal_irqs[i], NULL);
opal_irqs[i] = 0;
}
}
int __init opal_event_init(void)
{
struct device_node *dn, *opal_node;
const __be32 *irqs;
int i, irqlen, rc = 0;
opal_node = of_find_node_by_path("/ibm,opal");
if (!opal_node) {
pr_warn("opal: Node not found\n");
return -ENODEV;
}
dn = of_find_compatible_node(NULL, NULL, "ibm,opal-event");
opal_event_irqchip.domain = irq_domain_add_linear(dn, MAX_NUM_EVENTS,
&opal_event_domain_ops, &opal_event_irqchip);
of_node_put(dn);
if (!opal_event_irqchip.domain) {
pr_warn("opal: Unable to create irq domain\n");
rc = -ENOMEM;
goto out;
}
irqs = of_get_property(opal_node, "opal-interrupts", &irqlen);
opal_irq_count = irqs ? (irqlen / 4) : 0;
pr_debug("Found %d interrupts reserved for OPAL\n", opal_irq_count);
opal_irqs = kcalloc(opal_irq_count, sizeof(*opal_irqs), GFP_KERNEL);
for (i = 0; irqs && i < opal_irq_count; i++, irqs++) {
unsigned int irq, virq;
irq = be32_to_cpup(irqs);
virq = irq_create_mapping(NULL, irq);
if (virq == NO_IRQ) {
pr_warn("Failed to map irq 0x%x\n", irq);
continue;
}
rc = request_irq(virq, opal_interrupt, IRQF_TRIGGER_LOW,
"opal", NULL);
if (rc) {
irq_dispose_mapping(virq);
pr_warn("Error %d requesting irq %d (0x%x)\n",
rc, virq, irq);
continue;
}
opal_irqs[i] = virq;
}
out:
of_node_put(opal_node);
return rc;
}
int opal_event_request(unsigned int opal_event_nr)
{
if (WARN_ON_ONCE(!opal_event_irqchip.domain))
return NO_IRQ;
return irq_create_mapping(opal_event_irqchip.domain, opal_event_nr);
}
