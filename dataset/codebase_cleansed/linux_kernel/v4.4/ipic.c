static inline u32 ipic_read(volatile u32 __iomem *base, unsigned int reg)
{
return in_be32(base + (reg >> 2));
}
static inline void ipic_write(volatile u32 __iomem *base, unsigned int reg, u32 value)
{
out_be32(base + (reg >> 2), value);
}
static inline struct ipic * ipic_from_irq(unsigned int virq)
{
return primary_ipic;
}
static void ipic_unmask_irq(struct irq_data *d)
{
struct ipic *ipic = ipic_from_irq(d->irq);
unsigned int src = irqd_to_hwirq(d);
unsigned long flags;
u32 temp;
raw_spin_lock_irqsave(&ipic_lock, flags);
temp = ipic_read(ipic->regs, ipic_info[src].mask);
temp |= (1 << (31 - ipic_info[src].bit));
ipic_write(ipic->regs, ipic_info[src].mask, temp);
raw_spin_unlock_irqrestore(&ipic_lock, flags);
}
static void ipic_mask_irq(struct irq_data *d)
{
struct ipic *ipic = ipic_from_irq(d->irq);
unsigned int src = irqd_to_hwirq(d);
unsigned long flags;
u32 temp;
raw_spin_lock_irqsave(&ipic_lock, flags);
temp = ipic_read(ipic->regs, ipic_info[src].mask);
temp &= ~(1 << (31 - ipic_info[src].bit));
ipic_write(ipic->regs, ipic_info[src].mask, temp);
mb();
raw_spin_unlock_irqrestore(&ipic_lock, flags);
}
static void ipic_ack_irq(struct irq_data *d)
{
struct ipic *ipic = ipic_from_irq(d->irq);
unsigned int src = irqd_to_hwirq(d);
unsigned long flags;
u32 temp;
raw_spin_lock_irqsave(&ipic_lock, flags);
temp = 1 << (31 - ipic_info[src].bit);
ipic_write(ipic->regs, ipic_info[src].ack, temp);
mb();
raw_spin_unlock_irqrestore(&ipic_lock, flags);
}
static void ipic_mask_irq_and_ack(struct irq_data *d)
{
struct ipic *ipic = ipic_from_irq(d->irq);
unsigned int src = irqd_to_hwirq(d);
unsigned long flags;
u32 temp;
raw_spin_lock_irqsave(&ipic_lock, flags);
temp = ipic_read(ipic->regs, ipic_info[src].mask);
temp &= ~(1 << (31 - ipic_info[src].bit));
ipic_write(ipic->regs, ipic_info[src].mask, temp);
temp = 1 << (31 - ipic_info[src].bit);
ipic_write(ipic->regs, ipic_info[src].ack, temp);
mb();
raw_spin_unlock_irqrestore(&ipic_lock, flags);
}
static int ipic_set_irq_type(struct irq_data *d, unsigned int flow_type)
{
struct ipic *ipic = ipic_from_irq(d->irq);
unsigned int src = irqd_to_hwirq(d);
unsigned int vold, vnew, edibit;
if (flow_type == IRQ_TYPE_NONE)
flow_type = IRQ_TYPE_LEVEL_LOW;
if (!(flow_type & (IRQ_TYPE_LEVEL_LOW | IRQ_TYPE_EDGE_FALLING))) {
printk(KERN_ERR "ipic: sense type 0x%x not supported\n",
flow_type);
return -EINVAL;
}
if ((flow_type & IRQ_TYPE_EDGE_FALLING) && !ipic_info[src].ack) {
printk(KERN_ERR "ipic: edge sense not supported on internal "
"interrupts\n");
return -EINVAL;
}
irqd_set_trigger_type(d, flow_type);
if (flow_type & IRQ_TYPE_LEVEL_LOW) {
irq_set_handler_locked(d, handle_level_irq);
d->chip = &ipic_level_irq_chip;
} else {
irq_set_handler_locked(d, handle_edge_irq);
d->chip = &ipic_edge_irq_chip;
}
if (src == IPIC_IRQ_EXT0)
edibit = 15;
else
if (src >= IPIC_IRQ_EXT1 && src <= IPIC_IRQ_EXT7)
edibit = (14 - (src - IPIC_IRQ_EXT1));
else
return (flow_type & IRQ_TYPE_LEVEL_LOW) ? 0 : -EINVAL;
vold = ipic_read(ipic->regs, IPIC_SECNR);
if ((flow_type & IRQ_TYPE_SENSE_MASK) == IRQ_TYPE_EDGE_FALLING) {
vnew = vold | (1 << edibit);
} else {
vnew = vold & ~(1 << edibit);
}
if (vold != vnew)
ipic_write(ipic->regs, IPIC_SECNR, vnew);
return IRQ_SET_MASK_OK_NOCOPY;
}
static int ipic_host_match(struct irq_domain *h, struct device_node *node,
enum irq_domain_bus_token bus_token)
{
struct device_node *of_node = irq_domain_get_of_node(h);
return of_node == NULL || of_node == node;
}
static int ipic_host_map(struct irq_domain *h, unsigned int virq,
irq_hw_number_t hw)
{
struct ipic *ipic = h->host_data;
irq_set_chip_data(virq, ipic);
irq_set_chip_and_handler(virq, &ipic_level_irq_chip, handle_level_irq);
irq_set_irq_type(virq, IRQ_TYPE_NONE);
return 0;
}
struct ipic * __init ipic_init(struct device_node *node, unsigned int flags)
{
struct ipic *ipic;
struct resource res;
u32 temp = 0, ret;
ret = of_address_to_resource(node, 0, &res);
if (ret)
return NULL;
ipic = kzalloc(sizeof(*ipic), GFP_KERNEL);
if (ipic == NULL)
return NULL;
ipic->irqhost = irq_domain_add_linear(node, NR_IPIC_INTS,
&ipic_host_ops, ipic);
if (ipic->irqhost == NULL) {
kfree(ipic);
return NULL;
}
ipic->regs = ioremap(res.start, resource_size(&res));
ipic_write(ipic->regs, IPIC_SICNR, 0x0);
if (flags & IPIC_SPREADMODE_GRP_A)
temp |= SICFR_IPSA;
if (flags & IPIC_SPREADMODE_GRP_B)
temp |= SICFR_IPSB;
if (flags & IPIC_SPREADMODE_GRP_C)
temp |= SICFR_IPSC;
if (flags & IPIC_SPREADMODE_GRP_D)
temp |= SICFR_IPSD;
if (flags & IPIC_SPREADMODE_MIX_A)
temp |= SICFR_MPSA;
if (flags & IPIC_SPREADMODE_MIX_B)
temp |= SICFR_MPSB;
ipic_write(ipic->regs, IPIC_SICFR, temp);
temp = 0;
if (flags & IPIC_DISABLE_MCP_OUT)
temp = SERCR_MCPR;
ipic_write(ipic->regs, IPIC_SERCR, temp);
temp = ipic_read(ipic->regs, IPIC_SEMSR);
if (flags & IPIC_IRQ0_MCP)
temp |= SEMSR_SIRQ0;
else
temp &= ~SEMSR_SIRQ0;
ipic_write(ipic->regs, IPIC_SEMSR, temp);
primary_ipic = ipic;
irq_set_default_host(primary_ipic->irqhost);
ipic_write(ipic->regs, IPIC_SIMSR_H, 0);
ipic_write(ipic->regs, IPIC_SIMSR_L, 0);
printk ("IPIC (%d IRQ sources) at %p\n", NR_IPIC_INTS,
primary_ipic->regs);
return ipic;
}
int ipic_set_priority(unsigned int virq, unsigned int priority)
{
struct ipic *ipic = ipic_from_irq(virq);
unsigned int src = virq_to_hw(virq);
u32 temp;
if (priority > 7)
return -EINVAL;
if (src > 127)
return -EINVAL;
if (ipic_info[src].prio == 0)
return -EINVAL;
temp = ipic_read(ipic->regs, ipic_info[src].prio);
if (priority < 4) {
temp &= ~(0x7 << (20 + (3 - priority) * 3));
temp |= ipic_info[src].prio_mask << (20 + (3 - priority) * 3);
} else {
temp &= ~(0x7 << (4 + (7 - priority) * 3));
temp |= ipic_info[src].prio_mask << (4 + (7 - priority) * 3);
}
ipic_write(ipic->regs, ipic_info[src].prio, temp);
return 0;
}
void ipic_set_highest_priority(unsigned int virq)
{
struct ipic *ipic = ipic_from_irq(virq);
unsigned int src = virq_to_hw(virq);
u32 temp;
temp = ipic_read(ipic->regs, IPIC_SICFR);
temp &= 0x7f000000;
temp |= (src & 0x7f) << 24;
ipic_write(ipic->regs, IPIC_SICFR, temp);
}
void ipic_set_default_priority(void)
{
ipic_write(primary_ipic->regs, IPIC_SIPRR_A, IPIC_PRIORITY_DEFAULT);
ipic_write(primary_ipic->regs, IPIC_SIPRR_B, IPIC_PRIORITY_DEFAULT);
ipic_write(primary_ipic->regs, IPIC_SIPRR_C, IPIC_PRIORITY_DEFAULT);
ipic_write(primary_ipic->regs, IPIC_SIPRR_D, IPIC_PRIORITY_DEFAULT);
ipic_write(primary_ipic->regs, IPIC_SMPRR_A, IPIC_PRIORITY_DEFAULT);
ipic_write(primary_ipic->regs, IPIC_SMPRR_B, IPIC_PRIORITY_DEFAULT);
}
void ipic_enable_mcp(enum ipic_mcp_irq mcp_irq)
{
struct ipic *ipic = primary_ipic;
u32 temp;
temp = ipic_read(ipic->regs, IPIC_SERMR);
temp |= (1 << (31 - mcp_irq));
ipic_write(ipic->regs, IPIC_SERMR, temp);
}
void ipic_disable_mcp(enum ipic_mcp_irq mcp_irq)
{
struct ipic *ipic = primary_ipic;
u32 temp;
temp = ipic_read(ipic->regs, IPIC_SERMR);
temp &= (1 << (31 - mcp_irq));
ipic_write(ipic->regs, IPIC_SERMR, temp);
}
u32 ipic_get_mcp_status(void)
{
return ipic_read(primary_ipic->regs, IPIC_SERMR);
}
void ipic_clear_mcp_status(u32 mask)
{
ipic_write(primary_ipic->regs, IPIC_SERMR, mask);
}
unsigned int ipic_get_irq(void)
{
int irq;
BUG_ON(primary_ipic == NULL);
#define IPIC_SIVCR_VECTOR_MASK 0x7f
irq = ipic_read(primary_ipic->regs, IPIC_SIVCR) & IPIC_SIVCR_VECTOR_MASK;
if (irq == 0)
return NO_IRQ;
return irq_linear_revmap(primary_ipic->irqhost, irq);
}
static int ipic_suspend(void)
{
struct ipic *ipic = primary_ipic;
ipic_saved_state.sicfr = ipic_read(ipic->regs, IPIC_SICFR);
ipic_saved_state.siprr[0] = ipic_read(ipic->regs, IPIC_SIPRR_A);
ipic_saved_state.siprr[1] = ipic_read(ipic->regs, IPIC_SIPRR_D);
ipic_saved_state.simsr[0] = ipic_read(ipic->regs, IPIC_SIMSR_H);
ipic_saved_state.simsr[1] = ipic_read(ipic->regs, IPIC_SIMSR_L);
ipic_saved_state.sicnr = ipic_read(ipic->regs, IPIC_SICNR);
ipic_saved_state.smprr[0] = ipic_read(ipic->regs, IPIC_SMPRR_A);
ipic_saved_state.smprr[1] = ipic_read(ipic->regs, IPIC_SMPRR_B);
ipic_saved_state.semsr = ipic_read(ipic->regs, IPIC_SEMSR);
ipic_saved_state.secnr = ipic_read(ipic->regs, IPIC_SECNR);
ipic_saved_state.sermr = ipic_read(ipic->regs, IPIC_SERMR);
ipic_saved_state.sercr = ipic_read(ipic->regs, IPIC_SERCR);
if (fsl_deep_sleep()) {
ipic_write(ipic->regs, IPIC_SIMSR_H, 0);
ipic_write(ipic->regs, IPIC_SIMSR_L, 0);
ipic_write(ipic->regs, IPIC_SEMSR, 0);
ipic_write(ipic->regs, IPIC_SERMR, 0);
}
return 0;
}
static void ipic_resume(void)
{
struct ipic *ipic = primary_ipic;
ipic_write(ipic->regs, IPIC_SICFR, ipic_saved_state.sicfr);
ipic_write(ipic->regs, IPIC_SIPRR_A, ipic_saved_state.siprr[0]);
ipic_write(ipic->regs, IPIC_SIPRR_D, ipic_saved_state.siprr[1]);
ipic_write(ipic->regs, IPIC_SIMSR_H, ipic_saved_state.simsr[0]);
ipic_write(ipic->regs, IPIC_SIMSR_L, ipic_saved_state.simsr[1]);
ipic_write(ipic->regs, IPIC_SICNR, ipic_saved_state.sicnr);
ipic_write(ipic->regs, IPIC_SMPRR_A, ipic_saved_state.smprr[0]);
ipic_write(ipic->regs, IPIC_SMPRR_B, ipic_saved_state.smprr[1]);
ipic_write(ipic->regs, IPIC_SEMSR, ipic_saved_state.semsr);
ipic_write(ipic->regs, IPIC_SECNR, ipic_saved_state.secnr);
ipic_write(ipic->regs, IPIC_SERMR, ipic_saved_state.sermr);
ipic_write(ipic->regs, IPIC_SERCR, ipic_saved_state.sercr);
}
static int __init init_ipic_syscore(void)
{
if (!primary_ipic || !primary_ipic->regs)
return -ENODEV;
printk(KERN_DEBUG "Registering ipic system core operations\n");
register_syscore_ops(&ipic_syscore_ops);
return 0;
}
