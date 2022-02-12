static void cpm2_mask_irq(struct irq_data *d)
{
int bit, word;
unsigned int irq_nr = irqd_to_hwirq(d);
bit = irq_to_siubit[irq_nr];
word = irq_to_siureg[irq_nr];
ppc_cached_irq_mask[word] &= ~(1 << bit);
out_be32(&cpm2_intctl->ic_simrh + word, ppc_cached_irq_mask[word]);
}
static void cpm2_unmask_irq(struct irq_data *d)
{
int bit, word;
unsigned int irq_nr = irqd_to_hwirq(d);
bit = irq_to_siubit[irq_nr];
word = irq_to_siureg[irq_nr];
ppc_cached_irq_mask[word] |= 1 << bit;
out_be32(&cpm2_intctl->ic_simrh + word, ppc_cached_irq_mask[word]);
}
static void cpm2_ack(struct irq_data *d)
{
int bit, word;
unsigned int irq_nr = irqd_to_hwirq(d);
bit = irq_to_siubit[irq_nr];
word = irq_to_siureg[irq_nr];
out_be32(&cpm2_intctl->ic_sipnrh + word, 1 << bit);
}
static void cpm2_end_irq(struct irq_data *d)
{
int bit, word;
unsigned int irq_nr = irqd_to_hwirq(d);
bit = irq_to_siubit[irq_nr];
word = irq_to_siureg[irq_nr];
ppc_cached_irq_mask[word] |= 1 << bit;
out_be32(&cpm2_intctl->ic_simrh + word, ppc_cached_irq_mask[word]);
mb();
}
static int cpm2_set_irq_type(struct irq_data *d, unsigned int flow_type)
{
unsigned int src = irqd_to_hwirq(d);
unsigned int vold, vnew, edibit;
if (src >= CPM2_IRQ_PORTC15 && src <= CPM2_IRQ_PORTC0) {
if (flow_type == IRQ_TYPE_NONE)
flow_type = IRQ_TYPE_EDGE_BOTH;
if (flow_type != IRQ_TYPE_EDGE_BOTH &&
flow_type != IRQ_TYPE_EDGE_FALLING)
goto err_sense;
} else {
if (flow_type == IRQ_TYPE_NONE)
flow_type = IRQ_TYPE_LEVEL_LOW;
if (flow_type & (IRQ_TYPE_EDGE_RISING | IRQ_TYPE_LEVEL_HIGH))
goto err_sense;
}
irqd_set_trigger_type(d, flow_type);
if (flow_type & IRQ_TYPE_LEVEL_LOW)
irq_set_handler_locked(d, handle_level_irq);
else
irq_set_handler_locked(d, handle_edge_irq);
if (src >= CPM2_IRQ_EXT1 && src <= CPM2_IRQ_EXT7)
edibit = (14 - (src - CPM2_IRQ_EXT1));
else
if (src >= CPM2_IRQ_PORTC15 && src <= CPM2_IRQ_PORTC0)
edibit = (31 - (CPM2_IRQ_PORTC0 - src));
else
return (flow_type & IRQ_TYPE_LEVEL_LOW) ?
IRQ_SET_MASK_OK_NOCOPY : -EINVAL;
vold = in_be32(&cpm2_intctl->ic_siexr);
if ((flow_type & IRQ_TYPE_SENSE_MASK) == IRQ_TYPE_EDGE_FALLING)
vnew = vold | (1 << edibit);
else
vnew = vold & ~(1 << edibit);
if (vold != vnew)
out_be32(&cpm2_intctl->ic_siexr, vnew);
return IRQ_SET_MASK_OK_NOCOPY;
err_sense:
pr_err("CPM2 PIC: sense type 0x%x not supported\n", flow_type);
return -EINVAL;
}
unsigned int cpm2_get_irq(void)
{
int irq;
unsigned long bits;
bits = in_be32(&cpm2_intctl->ic_sivec);
irq = bits >> 26;
if (irq == 0)
return(-1);
return irq_linear_revmap(cpm2_pic_host, irq);
}
static int cpm2_pic_host_map(struct irq_domain *h, unsigned int virq,
irq_hw_number_t hw)
{
pr_debug("cpm2_pic_host_map(%d, 0x%lx)\n", virq, hw);
irq_set_status_flags(virq, IRQ_LEVEL);
irq_set_chip_and_handler(virq, &cpm2_pic, handle_level_irq);
return 0;
}
void cpm2_pic_init(struct device_node *node)
{
int i;
cpm2_intctl = cpm2_map(im_intctl);
out_be32(&cpm2_intctl->ic_simrh, 0x00000000);
out_be32(&cpm2_intctl->ic_simrl, 0x00000000);
wmb();
out_be32(&cpm2_intctl->ic_sipnrh, 0xffffffff);
out_be32(&cpm2_intctl->ic_sipnrl, 0xffffffff);
wmb();
i = in_be32(&cpm2_intctl->ic_sivec);
rmb();
out_be16(&cpm2_intctl->ic_sicr, 0);
out_be32(&cpm2_intctl->ic_scprrh, 0x05309770);
out_be32(&cpm2_intctl->ic_scprrl, 0x05309770);
cpm2_pic_host = irq_domain_add_linear(node, 64, &cpm2_pic_host_ops, NULL);
if (cpm2_pic_host == NULL) {
printk(KERN_ERR "CPM2 PIC: failed to allocate irq host!\n");
return;
}
}
