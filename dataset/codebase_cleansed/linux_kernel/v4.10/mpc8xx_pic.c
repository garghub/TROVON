static inline unsigned long mpc8xx_irqd_to_bit(struct irq_data *d)
{
return 0x80000000 >> irqd_to_hwirq(d);
}
static void mpc8xx_unmask_irq(struct irq_data *d)
{
mpc8xx_cached_irq_mask |= mpc8xx_irqd_to_bit(d);
out_be32(&siu_reg->sc_simask, mpc8xx_cached_irq_mask);
}
static void mpc8xx_mask_irq(struct irq_data *d)
{
mpc8xx_cached_irq_mask &= ~mpc8xx_irqd_to_bit(d);
out_be32(&siu_reg->sc_simask, mpc8xx_cached_irq_mask);
}
static void mpc8xx_ack(struct irq_data *d)
{
out_be32(&siu_reg->sc_sipend, mpc8xx_irqd_to_bit(d));
}
static void mpc8xx_end_irq(struct irq_data *d)
{
mpc8xx_cached_irq_mask |= mpc8xx_irqd_to_bit(d);
out_be32(&siu_reg->sc_simask, mpc8xx_cached_irq_mask);
}
static int mpc8xx_set_irq_type(struct irq_data *d, unsigned int flow_type)
{
if ((flow_type & IRQ_TYPE_EDGE_FALLING) && !(irqd_to_hwirq(d) & 1)) {
unsigned int siel = in_be32(&siu_reg->sc_siel);
siel |= mpc8xx_irqd_to_bit(d);
out_be32(&siu_reg->sc_siel, siel);
irq_set_handler_locked(d, handle_edge_irq);
}
return 0;
}
unsigned int mpc8xx_get_irq(void)
{
int irq;
irq = in_be32(&siu_reg->sc_sivec) >> 26;
if (irq == PIC_VEC_SPURRIOUS)
irq = 0;
return irq_linear_revmap(mpc8xx_pic_host, irq);
}
static int mpc8xx_pic_host_map(struct irq_domain *h, unsigned int virq,
irq_hw_number_t hw)
{
pr_debug("mpc8xx_pic_host_map(%d, 0x%lx)\n", virq, hw);
irq_set_chip_and_handler(virq, &mpc8xx_pic, handle_level_irq);
return 0;
}
static int mpc8xx_pic_host_xlate(struct irq_domain *h, struct device_node *ct,
const u32 *intspec, unsigned int intsize,
irq_hw_number_t *out_hwirq, unsigned int *out_flags)
{
static unsigned char map_pic_senses[4] = {
IRQ_TYPE_EDGE_RISING,
IRQ_TYPE_LEVEL_LOW,
IRQ_TYPE_LEVEL_HIGH,
IRQ_TYPE_EDGE_FALLING,
};
if (intspec[0] > 0x1f)
return 0;
*out_hwirq = intspec[0];
if (intsize > 1 && intspec[1] < 4)
*out_flags = map_pic_senses[intspec[1]];
else
*out_flags = IRQ_TYPE_NONE;
return 0;
}
int mpc8xx_pic_init(void)
{
struct resource res;
struct device_node *np;
int ret;
np = of_find_compatible_node(NULL, NULL, "fsl,pq1-pic");
if (np == NULL)
np = of_find_node_by_type(NULL, "mpc8xx-pic");
if (np == NULL) {
printk(KERN_ERR "Could not find fsl,pq1-pic node\n");
return -ENOMEM;
}
ret = of_address_to_resource(np, 0, &res);
if (ret)
goto out;
siu_reg = ioremap(res.start, resource_size(&res));
if (siu_reg == NULL) {
ret = -EINVAL;
goto out;
}
mpc8xx_pic_host = irq_domain_add_linear(np, 64, &mpc8xx_pic_host_ops, NULL);
if (mpc8xx_pic_host == NULL) {
printk(KERN_ERR "MPC8xx PIC: failed to allocate irq host!\n");
ret = -ENOMEM;
goto out;
}
return 0;
out:
of_node_put(np);
return ret;
}
