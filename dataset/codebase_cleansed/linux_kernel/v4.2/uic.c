static void uic_unmask_irq(struct irq_data *d)
{
struct uic *uic = irq_data_get_irq_chip_data(d);
unsigned int src = irqd_to_hwirq(d);
unsigned long flags;
u32 er, sr;
sr = 1 << (31-src);
raw_spin_lock_irqsave(&uic->lock, flags);
if (irqd_is_level_type(d))
mtdcr(uic->dcrbase + UIC_SR, sr);
er = mfdcr(uic->dcrbase + UIC_ER);
er |= sr;
mtdcr(uic->dcrbase + UIC_ER, er);
raw_spin_unlock_irqrestore(&uic->lock, flags);
}
static void uic_mask_irq(struct irq_data *d)
{
struct uic *uic = irq_data_get_irq_chip_data(d);
unsigned int src = irqd_to_hwirq(d);
unsigned long flags;
u32 er;
raw_spin_lock_irqsave(&uic->lock, flags);
er = mfdcr(uic->dcrbase + UIC_ER);
er &= ~(1 << (31 - src));
mtdcr(uic->dcrbase + UIC_ER, er);
raw_spin_unlock_irqrestore(&uic->lock, flags);
}
static void uic_ack_irq(struct irq_data *d)
{
struct uic *uic = irq_data_get_irq_chip_data(d);
unsigned int src = irqd_to_hwirq(d);
unsigned long flags;
raw_spin_lock_irqsave(&uic->lock, flags);
mtdcr(uic->dcrbase + UIC_SR, 1 << (31-src));
raw_spin_unlock_irqrestore(&uic->lock, flags);
}
static void uic_mask_ack_irq(struct irq_data *d)
{
struct uic *uic = irq_data_get_irq_chip_data(d);
unsigned int src = irqd_to_hwirq(d);
unsigned long flags;
u32 er, sr;
sr = 1 << (31-src);
raw_spin_lock_irqsave(&uic->lock, flags);
er = mfdcr(uic->dcrbase + UIC_ER);
er &= ~sr;
mtdcr(uic->dcrbase + UIC_ER, er);
if (!irqd_is_level_type(d))
mtdcr(uic->dcrbase + UIC_SR, sr);
raw_spin_unlock_irqrestore(&uic->lock, flags);
}
static int uic_set_irq_type(struct irq_data *d, unsigned int flow_type)
{
struct uic *uic = irq_data_get_irq_chip_data(d);
unsigned int src = irqd_to_hwirq(d);
unsigned long flags;
int trigger, polarity;
u32 tr, pr, mask;
switch (flow_type & IRQ_TYPE_SENSE_MASK) {
case IRQ_TYPE_NONE:
uic_mask_irq(d);
return 0;
case IRQ_TYPE_EDGE_RISING:
trigger = 1; polarity = 1;
break;
case IRQ_TYPE_EDGE_FALLING:
trigger = 1; polarity = 0;
break;
case IRQ_TYPE_LEVEL_HIGH:
trigger = 0; polarity = 1;
break;
case IRQ_TYPE_LEVEL_LOW:
trigger = 0; polarity = 0;
break;
default:
return -EINVAL;
}
mask = ~(1 << (31 - src));
raw_spin_lock_irqsave(&uic->lock, flags);
tr = mfdcr(uic->dcrbase + UIC_TR);
pr = mfdcr(uic->dcrbase + UIC_PR);
tr = (tr & mask) | (trigger << (31-src));
pr = (pr & mask) | (polarity << (31-src));
mtdcr(uic->dcrbase + UIC_PR, pr);
mtdcr(uic->dcrbase + UIC_TR, tr);
raw_spin_unlock_irqrestore(&uic->lock, flags);
return 0;
}
static int uic_host_map(struct irq_domain *h, unsigned int virq,
irq_hw_number_t hw)
{
struct uic *uic = h->host_data;
irq_set_chip_data(virq, uic);
irq_set_chip_and_handler(virq, &uic_irq_chip, handle_level_irq);
irq_set_irq_type(virq, IRQ_TYPE_NONE);
return 0;
}
void uic_irq_cascade(unsigned int virq, struct irq_desc *desc)
{
struct irq_chip *chip = irq_desc_get_chip(desc);
struct irq_data *idata = irq_desc_get_irq_data(desc);
struct uic *uic = irq_desc_get_handler_data(desc);
u32 msr;
int src;
int subvirq;
raw_spin_lock(&desc->lock);
if (irqd_is_level_type(idata))
chip->irq_mask(idata);
else
chip->irq_mask_ack(idata);
raw_spin_unlock(&desc->lock);
msr = mfdcr(uic->dcrbase + UIC_MSR);
if (!msr)
goto uic_irq_ret;
src = 32 - ffs(msr);
subvirq = irq_linear_revmap(uic->irqhost, src);
generic_handle_irq(subvirq);
uic_irq_ret:
raw_spin_lock(&desc->lock);
if (irqd_is_level_type(idata))
chip->irq_ack(idata);
if (!irqd_irq_disabled(idata) && chip->irq_unmask)
chip->irq_unmask(idata);
raw_spin_unlock(&desc->lock);
}
static struct uic * __init uic_init_one(struct device_node *node)
{
struct uic *uic;
const u32 *indexp, *dcrreg;
int len;
BUG_ON(! of_device_is_compatible(node, "ibm,uic"));
uic = kzalloc(sizeof(*uic), GFP_KERNEL);
if (! uic)
return NULL;
raw_spin_lock_init(&uic->lock);
indexp = of_get_property(node, "cell-index", &len);
if (!indexp || (len != sizeof(u32))) {
printk(KERN_ERR "uic: Device node %s has missing or invalid "
"cell-index property\n", node->full_name);
return NULL;
}
uic->index = *indexp;
dcrreg = of_get_property(node, "dcr-reg", &len);
if (!dcrreg || (len != 2*sizeof(u32))) {
printk(KERN_ERR "uic: Device node %s has missing or invalid "
"dcr-reg property\n", node->full_name);
return NULL;
}
uic->dcrbase = *dcrreg;
uic->irqhost = irq_domain_add_linear(node, NR_UIC_INTS, &uic_host_ops,
uic);
if (! uic->irqhost)
return NULL;
mtdcr(uic->dcrbase + UIC_ER, 0);
mtdcr(uic->dcrbase + UIC_CR, 0);
mtdcr(uic->dcrbase + UIC_TR, 0);
mtdcr(uic->dcrbase + UIC_SR, 0xffffffff);
printk ("UIC%d (%d IRQ sources) at DCR 0x%x\n", uic->index,
NR_UIC_INTS, uic->dcrbase);
return uic;
}
void __init uic_init_tree(void)
{
struct device_node *np;
struct uic *uic;
const u32 *interrupts;
for_each_compatible_node(np, NULL, "ibm,uic") {
interrupts = of_get_property(np, "interrupts", NULL);
if (!interrupts)
break;
}
BUG_ON(!np);
primary_uic = uic_init_one(np);
if (!primary_uic)
panic("Unable to initialize primary UIC %s\n", np->full_name);
irq_set_default_host(primary_uic->irqhost);
of_node_put(np);
for_each_compatible_node(np, NULL, "ibm,uic") {
interrupts = of_get_property(np, "interrupts", NULL);
if (interrupts) {
int cascade_virq;
uic = uic_init_one(np);
if (! uic)
panic("Unable to initialize a secondary UIC %s\n",
np->full_name);
cascade_virq = irq_of_parse_and_map(np, 0);
irq_set_handler_data(cascade_virq, uic);
irq_set_chained_handler(cascade_virq, uic_irq_cascade);
}
}
}
unsigned int uic_get_irq(void)
{
u32 msr;
int src;
BUG_ON(! primary_uic);
msr = mfdcr(primary_uic->dcrbase + UIC_MSR);
src = 32 - ffs(msr);
return irq_linear_revmap(primary_uic->irqhost, src);
}
