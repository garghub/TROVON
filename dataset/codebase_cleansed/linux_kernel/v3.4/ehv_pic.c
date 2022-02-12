void ehv_pic_unmask_irq(struct irq_data *d)
{
unsigned int src = virq_to_hw(d->irq);
ev_int_set_mask(src, 0);
}
void ehv_pic_mask_irq(struct irq_data *d)
{
unsigned int src = virq_to_hw(d->irq);
ev_int_set_mask(src, 1);
}
void ehv_pic_end_irq(struct irq_data *d)
{
unsigned int src = virq_to_hw(d->irq);
ev_int_eoi(src);
}
void ehv_pic_direct_end_irq(struct irq_data *d)
{
out_be32(mpic_percpu_base_vaddr + MPIC_EOI / 4, 0);
}
int ehv_pic_set_affinity(struct irq_data *d, const struct cpumask *dest,
bool force)
{
unsigned int src = virq_to_hw(d->irq);
unsigned int config, prio, cpu_dest;
int cpuid = irq_choose_cpu(dest);
unsigned long flags;
spin_lock_irqsave(&ehv_pic_lock, flags);
ev_int_get_config(src, &config, &prio, &cpu_dest);
ev_int_set_config(src, config, prio, cpuid);
spin_unlock_irqrestore(&ehv_pic_lock, flags);
return 0;
}
static unsigned int ehv_pic_type_to_vecpri(unsigned int type)
{
switch (type & IRQ_TYPE_SENSE_MASK) {
case IRQ_TYPE_EDGE_RISING:
return EHV_PIC_INFO(VECPRI_SENSE_EDGE) |
EHV_PIC_INFO(VECPRI_POLARITY_POSITIVE);
case IRQ_TYPE_EDGE_FALLING:
case IRQ_TYPE_EDGE_BOTH:
return EHV_PIC_INFO(VECPRI_SENSE_EDGE) |
EHV_PIC_INFO(VECPRI_POLARITY_NEGATIVE);
case IRQ_TYPE_LEVEL_HIGH:
return EHV_PIC_INFO(VECPRI_SENSE_LEVEL) |
EHV_PIC_INFO(VECPRI_POLARITY_POSITIVE);
case IRQ_TYPE_LEVEL_LOW:
default:
return EHV_PIC_INFO(VECPRI_SENSE_LEVEL) |
EHV_PIC_INFO(VECPRI_POLARITY_NEGATIVE);
}
}
int ehv_pic_set_irq_type(struct irq_data *d, unsigned int flow_type)
{
unsigned int src = virq_to_hw(d->irq);
struct irq_desc *desc = irq_to_desc(d->irq);
unsigned int vecpri, vold, vnew, prio, cpu_dest;
unsigned long flags;
if (flow_type == IRQ_TYPE_NONE)
flow_type = IRQ_TYPE_LEVEL_LOW;
irq_settings_clr_level(desc);
irq_settings_set_trigger_mask(desc, flow_type);
if (flow_type & (IRQ_TYPE_LEVEL_HIGH | IRQ_TYPE_LEVEL_LOW))
irq_settings_set_level(desc);
vecpri = ehv_pic_type_to_vecpri(flow_type);
spin_lock_irqsave(&ehv_pic_lock, flags);
ev_int_get_config(src, &vold, &prio, &cpu_dest);
vnew = vold & ~(EHV_PIC_INFO(VECPRI_POLARITY_MASK) |
EHV_PIC_INFO(VECPRI_SENSE_MASK));
vnew |= vecpri;
prio = 8;
ev_int_set_config(src, vecpri, prio, cpu_dest);
spin_unlock_irqrestore(&ehv_pic_lock, flags);
return 0;
}
unsigned int ehv_pic_get_irq(void)
{
int irq;
BUG_ON(global_ehv_pic == NULL);
if (global_ehv_pic->coreint_flag)
irq = mfspr(SPRN_EPR);
else
ev_int_iack(0, &irq);
if (irq == 0xFFFF)
return NO_IRQ;
return irq_linear_revmap(global_ehv_pic->irqhost, irq);
}
static int ehv_pic_host_match(struct irq_domain *h, struct device_node *node)
{
return h->of_node == NULL || h->of_node == node;
}
static int ehv_pic_host_map(struct irq_domain *h, unsigned int virq,
irq_hw_number_t hw)
{
struct ehv_pic *ehv_pic = h->host_data;
struct irq_chip *chip;
chip = &ehv_pic->hc_irq;
if (mpic_percpu_base_vaddr)
if (hwirq_intspec[hw] & IRQ_TYPE_MPIC_DIRECT)
chip = &ehv_pic_direct_eoi_irq_chip;
irq_set_chip_data(virq, chip);
irq_set_chip_and_handler(virq, chip, handle_fasteoi_irq);
irq_set_irq_type(virq, IRQ_TYPE_NONE);
return 0;
}
static int ehv_pic_host_xlate(struct irq_domain *h, struct device_node *ct,
const u32 *intspec, unsigned int intsize,
irq_hw_number_t *out_hwirq, unsigned int *out_flags)
{
static unsigned char map_of_senses_to_linux_irqtype[4] = {
IRQ_TYPE_EDGE_FALLING,
IRQ_TYPE_EDGE_RISING,
IRQ_TYPE_LEVEL_LOW,
IRQ_TYPE_LEVEL_HIGH,
};
*out_hwirq = intspec[0];
if (intsize > 1) {
hwirq_intspec[intspec[0]] = intspec[1];
*out_flags = map_of_senses_to_linux_irqtype[intspec[1] &
~IRQ_TYPE_MPIC_DIRECT];
} else {
*out_flags = IRQ_TYPE_NONE;
}
return 0;
}
void __init ehv_pic_init(void)
{
struct device_node *np, *np2;
struct ehv_pic *ehv_pic;
int coreint_flag = 1;
np = of_find_compatible_node(NULL, NULL, "epapr,hv-pic");
if (!np) {
pr_err("ehv_pic_init: could not find epapr,hv-pic node\n");
return;
}
if (!of_find_property(np, "has-external-proxy", NULL))
coreint_flag = 0;
ehv_pic = kzalloc(sizeof(struct ehv_pic), GFP_KERNEL);
if (!ehv_pic) {
of_node_put(np);
return;
}
ehv_pic->irqhost = irq_domain_add_linear(np, NR_EHV_PIC_INTS,
&ehv_pic_host_ops, ehv_pic);
if (!ehv_pic->irqhost) {
of_node_put(np);
kfree(ehv_pic);
return;
}
np2 = of_find_compatible_node(NULL, NULL, "fsl,hv-mpic-per-cpu");
if (np2) {
mpic_percpu_base_vaddr = of_iomap(np2, 0);
if (!mpic_percpu_base_vaddr)
pr_err("ehv_pic_init: of_iomap failed\n");
of_node_put(np2);
}
ehv_pic->hc_irq = ehv_pic_irq_chip;
ehv_pic->hc_irq.irq_set_affinity = ehv_pic_set_affinity;
ehv_pic->coreint_flag = coreint_flag;
global_ehv_pic = ehv_pic;
irq_set_default_host(global_ehv_pic->irqhost);
}
