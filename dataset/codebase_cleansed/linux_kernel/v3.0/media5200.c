static void media5200_irq_unmask(struct irq_data *d)
{
unsigned long flags;
u32 val;
spin_lock_irqsave(&media5200_irq.lock, flags);
val = in_be32(media5200_irq.regs + MEDIA5200_IRQ_ENABLE);
val |= 1 << (MEDIA5200_IRQ_SHIFT + irqd_to_hwirq(d));
out_be32(media5200_irq.regs + MEDIA5200_IRQ_ENABLE, val);
spin_unlock_irqrestore(&media5200_irq.lock, flags);
}
static void media5200_irq_mask(struct irq_data *d)
{
unsigned long flags;
u32 val;
spin_lock_irqsave(&media5200_irq.lock, flags);
val = in_be32(media5200_irq.regs + MEDIA5200_IRQ_ENABLE);
val &= ~(1 << (MEDIA5200_IRQ_SHIFT + irqd_to_hwirq(d)));
out_be32(media5200_irq.regs + MEDIA5200_IRQ_ENABLE, val);
spin_unlock_irqrestore(&media5200_irq.lock, flags);
}
void media5200_irq_cascade(unsigned int virq, struct irq_desc *desc)
{
struct irq_chip *chip = irq_desc_get_chip(desc);
int sub_virq, val;
u32 status, enable;
raw_spin_lock(&desc->lock);
chip->irq_mask(&desc->irq_data);
raw_spin_unlock(&desc->lock);
status = in_be32(media5200_irq.regs + MEDIA5200_IRQ_ENABLE);
enable = in_be32(media5200_irq.regs + MEDIA5200_IRQ_STATUS);
val = ffs((status & enable) >> MEDIA5200_IRQ_SHIFT);
if (val) {
sub_virq = irq_linear_revmap(media5200_irq.irqhost, val - 1);
generic_handle_irq(sub_virq);
}
raw_spin_lock(&desc->lock);
chip->irq_ack(&desc->irq_data);
if (!irqd_irq_disabled(&desc->irq_data))
chip->irq_unmask(&desc->irq_data);
raw_spin_unlock(&desc->lock);
}
static int media5200_irq_map(struct irq_host *h, unsigned int virq,
irq_hw_number_t hw)
{
pr_debug("%s: h=%p, virq=%i, hwirq=%i\n", __func__, h, virq, (int)hw);
irq_set_chip_data(virq, &media5200_irq);
irq_set_chip_and_handler(virq, &media5200_irq_chip, handle_level_irq);
irq_set_status_flags(virq, IRQ_LEVEL);
return 0;
}
static int media5200_irq_xlate(struct irq_host *h, struct device_node *ct,
const u32 *intspec, unsigned int intsize,
irq_hw_number_t *out_hwirq,
unsigned int *out_flags)
{
if (intsize != 2)
return -1;
pr_debug("%s: bank=%i, number=%i\n", __func__, intspec[0], intspec[1]);
*out_hwirq = intspec[1];
*out_flags = IRQ_TYPE_NONE;
return 0;
}
static void __init media5200_init_irq(void)
{
struct device_node *fpga_np;
int cascade_virq;
mpc52xx_init_irq();
fpga_np = of_find_compatible_node(NULL, NULL, "fsl,media5200-fpga");
if (!fpga_np)
goto out;
pr_debug("%s: found fpga node: %s\n", __func__, fpga_np->full_name);
media5200_irq.regs = of_iomap(fpga_np, 0);
if (!media5200_irq.regs)
goto out;
pr_debug("%s: mapped to %p\n", __func__, media5200_irq.regs);
cascade_virq = irq_of_parse_and_map(fpga_np, 0);
if (!cascade_virq)
goto out;
pr_debug("%s: cascaded on virq=%i\n", __func__, cascade_virq);
out_be32(media5200_irq.regs + MEDIA5200_IRQ_ENABLE, 0);
spin_lock_init(&media5200_irq.lock);
media5200_irq.irqhost = irq_alloc_host(fpga_np, IRQ_HOST_MAP_LINEAR,
MEDIA5200_NUM_IRQS,
&media5200_irq_ops, -1);
if (!media5200_irq.irqhost)
goto out;
pr_debug("%s: allocated irqhost\n", __func__);
media5200_irq.irqhost->host_data = &media5200_irq;
irq_set_handler_data(cascade_virq, &media5200_irq);
irq_set_chained_handler(cascade_virq, media5200_irq_cascade);
return;
out:
pr_err("Could not find Media5200 FPGA; PCI interrupts will not work\n");
}
static void __init media5200_setup_arch(void)
{
struct device_node *np;
struct mpc52xx_gpio __iomem *gpio;
u32 port_config;
if (ppc_md.progress)
ppc_md.progress("media5200_setup_arch()", 0);
mpc52xx_map_common_devices();
mpc5200_setup_xlb_arbiter();
mpc52xx_setup_pci();
np = of_find_matching_node(NULL, mpc5200_gpio_ids);
gpio = of_iomap(np, 0);
of_node_put(np);
if (!gpio) {
printk(KERN_ERR "%s() failed. expect abnormal behavior\n",
__func__);
return;
}
port_config = in_be32(&gpio->port_config);
port_config &= ~0x03000000;
port_config |= 0x01000000;
out_be32(&gpio->port_config, port_config);
iounmap(gpio);
}
static int __init media5200_probe(void)
{
return of_flat_dt_match(of_get_flat_dt_root(), board);
}
