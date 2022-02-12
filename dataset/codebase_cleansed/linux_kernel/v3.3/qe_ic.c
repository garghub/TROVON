static inline u32 qe_ic_read(volatile __be32 __iomem * base, unsigned int reg)
{
return in_be32(base + (reg >> 2));
}
static inline void qe_ic_write(volatile __be32 __iomem * base, unsigned int reg,
u32 value)
{
out_be32(base + (reg >> 2), value);
}
static inline struct qe_ic *qe_ic_from_irq(unsigned int virq)
{
return irq_get_chip_data(virq);
}
static inline struct qe_ic *qe_ic_from_irq_data(struct irq_data *d)
{
return irq_data_get_irq_chip_data(d);
}
static void qe_ic_unmask_irq(struct irq_data *d)
{
struct qe_ic *qe_ic = qe_ic_from_irq_data(d);
unsigned int src = irqd_to_hwirq(d);
unsigned long flags;
u32 temp;
raw_spin_lock_irqsave(&qe_ic_lock, flags);
temp = qe_ic_read(qe_ic->regs, qe_ic_info[src].mask_reg);
qe_ic_write(qe_ic->regs, qe_ic_info[src].mask_reg,
temp | qe_ic_info[src].mask);
raw_spin_unlock_irqrestore(&qe_ic_lock, flags);
}
static void qe_ic_mask_irq(struct irq_data *d)
{
struct qe_ic *qe_ic = qe_ic_from_irq_data(d);
unsigned int src = irqd_to_hwirq(d);
unsigned long flags;
u32 temp;
raw_spin_lock_irqsave(&qe_ic_lock, flags);
temp = qe_ic_read(qe_ic->regs, qe_ic_info[src].mask_reg);
qe_ic_write(qe_ic->regs, qe_ic_info[src].mask_reg,
temp & ~qe_ic_info[src].mask);
mb();
raw_spin_unlock_irqrestore(&qe_ic_lock, flags);
}
static int qe_ic_host_match(struct irq_host *h, struct device_node *node)
{
return h->of_node == NULL || h->of_node == node;
}
static int qe_ic_host_map(struct irq_host *h, unsigned int virq,
irq_hw_number_t hw)
{
struct qe_ic *qe_ic = h->host_data;
struct irq_chip *chip;
if (qe_ic_info[hw].mask == 0) {
printk(KERN_ERR "Can't map reserved IRQ\n");
return -EINVAL;
}
chip = &qe_ic->hc_irq;
irq_set_chip_data(virq, qe_ic);
irq_set_status_flags(virq, IRQ_LEVEL);
irq_set_chip_and_handler(virq, chip, handle_level_irq);
return 0;
}
static int qe_ic_host_xlate(struct irq_host *h, struct device_node *ct,
const u32 * intspec, unsigned int intsize,
irq_hw_number_t * out_hwirq,
unsigned int *out_flags)
{
*out_hwirq = intspec[0];
if (intsize > 1)
*out_flags = intspec[1];
else
*out_flags = IRQ_TYPE_NONE;
return 0;
}
unsigned int qe_ic_get_low_irq(struct qe_ic *qe_ic)
{
int irq;
BUG_ON(qe_ic == NULL);
irq = qe_ic_read(qe_ic->regs, QEIC_CIVEC) >> 26;
if (irq == 0)
return NO_IRQ;
return irq_linear_revmap(qe_ic->irqhost, irq);
}
unsigned int qe_ic_get_high_irq(struct qe_ic *qe_ic)
{
int irq;
BUG_ON(qe_ic == NULL);
irq = qe_ic_read(qe_ic->regs, QEIC_CHIVEC) >> 26;
if (irq == 0)
return NO_IRQ;
return irq_linear_revmap(qe_ic->irqhost, irq);
}
void __init qe_ic_init(struct device_node *node, unsigned int flags,
void (*low_handler)(unsigned int irq, struct irq_desc *desc),
void (*high_handler)(unsigned int irq, struct irq_desc *desc))
{
struct qe_ic *qe_ic;
struct resource res;
u32 temp = 0, ret, high_active = 0;
ret = of_address_to_resource(node, 0, &res);
if (ret)
return;
qe_ic = kzalloc(sizeof(*qe_ic), GFP_KERNEL);
if (qe_ic == NULL)
return;
qe_ic->irqhost = irq_alloc_host(node, IRQ_HOST_MAP_LINEAR,
NR_QE_IC_INTS, &qe_ic_host_ops, 0);
if (qe_ic->irqhost == NULL) {
kfree(qe_ic);
return;
}
qe_ic->regs = ioremap(res.start, resource_size(&res));
qe_ic->irqhost->host_data = qe_ic;
qe_ic->hc_irq = qe_ic_irq_chip;
qe_ic->virq_high = irq_of_parse_and_map(node, 0);
qe_ic->virq_low = irq_of_parse_and_map(node, 1);
if (qe_ic->virq_low == NO_IRQ) {
printk(KERN_ERR "Failed to map QE_IC low IRQ\n");
kfree(qe_ic);
return;
}
if (flags & QE_IC_SPREADMODE_GRP_W)
temp |= CICR_GWCC;
if (flags & QE_IC_SPREADMODE_GRP_X)
temp |= CICR_GXCC;
if (flags & QE_IC_SPREADMODE_GRP_Y)
temp |= CICR_GYCC;
if (flags & QE_IC_SPREADMODE_GRP_Z)
temp |= CICR_GZCC;
if (flags & QE_IC_SPREADMODE_GRP_RISCA)
temp |= CICR_GRTA;
if (flags & QE_IC_SPREADMODE_GRP_RISCB)
temp |= CICR_GRTB;
if (flags & QE_IC_HIGH_SIGNAL) {
temp |= (SIGNAL_HIGH << CICR_HPIT_SHIFT);
high_active = 1;
}
qe_ic_write(qe_ic->regs, QEIC_CICR, temp);
irq_set_handler_data(qe_ic->virq_low, qe_ic);
irq_set_chained_handler(qe_ic->virq_low, low_handler);
if (qe_ic->virq_high != NO_IRQ &&
qe_ic->virq_high != qe_ic->virq_low) {
irq_set_handler_data(qe_ic->virq_high, qe_ic);
irq_set_chained_handler(qe_ic->virq_high, high_handler);
}
}
void qe_ic_set_highest_priority(unsigned int virq, int high)
{
struct qe_ic *qe_ic = qe_ic_from_irq(virq);
unsigned int src = virq_to_hw(virq);
u32 temp = 0;
temp = qe_ic_read(qe_ic->regs, QEIC_CICR);
temp &= ~CICR_HP_MASK;
temp |= src << CICR_HP_SHIFT;
temp &= ~CICR_HPIT_MASK;
temp |= (high ? SIGNAL_HIGH : SIGNAL_LOW) << CICR_HPIT_SHIFT;
qe_ic_write(qe_ic->regs, QEIC_CICR, temp);
}
int qe_ic_set_priority(unsigned int virq, unsigned int priority)
{
struct qe_ic *qe_ic = qe_ic_from_irq(virq);
unsigned int src = virq_to_hw(virq);
u32 temp;
if (priority > 8 || priority == 0)
return -EINVAL;
if (src > 127)
return -EINVAL;
if (qe_ic_info[src].pri_reg == 0)
return -EINVAL;
temp = qe_ic_read(qe_ic->regs, qe_ic_info[src].pri_reg);
if (priority < 4) {
temp &= ~(0x7 << (32 - priority * 3));
temp |= qe_ic_info[src].pri_code << (32 - priority * 3);
} else {
temp &= ~(0x7 << (24 - priority * 3));
temp |= qe_ic_info[src].pri_code << (24 - priority * 3);
}
qe_ic_write(qe_ic->regs, qe_ic_info[src].pri_reg, temp);
return 0;
}
int qe_ic_set_high_priority(unsigned int virq, unsigned int priority, int high)
{
struct qe_ic *qe_ic = qe_ic_from_irq(virq);
unsigned int src = virq_to_hw(virq);
u32 temp, control_reg = QEIC_CICNR, shift = 0;
if (priority > 2 || priority == 0)
return -EINVAL;
switch (qe_ic_info[src].pri_reg) {
case QEIC_CIPZCC:
shift = CICNR_ZCC1T_SHIFT;
break;
case QEIC_CIPWCC:
shift = CICNR_WCC1T_SHIFT;
break;
case QEIC_CIPYCC:
shift = CICNR_YCC1T_SHIFT;
break;
case QEIC_CIPXCC:
shift = CICNR_XCC1T_SHIFT;
break;
case QEIC_CIPRTA:
shift = CRICR_RTA1T_SHIFT;
control_reg = QEIC_CRICR;
break;
case QEIC_CIPRTB:
shift = CRICR_RTB1T_SHIFT;
control_reg = QEIC_CRICR;
break;
default:
return -EINVAL;
}
shift += (2 - priority) * 2;
temp = qe_ic_read(qe_ic->regs, control_reg);
temp &= ~(SIGNAL_MASK << shift);
temp |= (high ? SIGNAL_HIGH : SIGNAL_LOW) << shift;
qe_ic_write(qe_ic->regs, control_reg, temp);
return 0;
}
static int __init init_qe_ic_sysfs(void)
{
int rc;
printk(KERN_DEBUG "Registering qe_ic with sysfs...\n");
rc = subsys_system_register(&qe_ic_subsys, NULL);
if (rc) {
printk(KERN_ERR "Failed registering qe_ic sys class\n");
return -ENODEV;
}
rc = device_register(&device_qe_ic);
if (rc) {
printk(KERN_ERR "Failed registering qe_ic sys device\n");
return -ENODEV;
}
return 0;
}
