void arc_init_IRQ(void)
{
unsigned int tmp;
struct irq_build {
#ifdef CONFIG_CPU_BIG_ENDIAN
unsigned int pad:3, firq:1, prio:4, exts:8, irqs:8, ver:8;
#else
unsigned int ver:8, irqs:8, exts:8, prio:4, firq:1, pad:3;
#endif
} irq_bcr;
struct aux_irq_ctrl {
#ifdef CONFIG_CPU_BIG_ENDIAN
unsigned int res3:18, save_idx_regs:1, res2:1,
save_u_to_u:1, save_lp_regs:1, save_blink:1,
res:4, save_nr_gpr_pairs:5;
#else
unsigned int save_nr_gpr_pairs:5, res:4,
save_blink:1, save_lp_regs:1, save_u_to_u:1,
res2:1, save_idx_regs:1, res3:18;
#endif
} ictrl;
*(unsigned int *)&ictrl = 0;
ictrl.save_nr_gpr_pairs = 6;
ictrl.save_blink = 1;
ictrl.save_lp_regs = 1;
ictrl.save_u_to_u = 0;
ictrl.save_idx_regs = 1;
WRITE_AUX(AUX_IRQ_CTRL, ictrl);
READ_BCR(ARC_REG_IRQ_BCR, irq_bcr);
irq_prio = irq_bcr.prio;
pr_info("archs-intc\t: %d priority levels (default %d)%s\n",
irq_prio + 1, irq_prio,
irq_bcr.firq ? " FIRQ (not used)":"");
tmp = read_aux_reg(0xa);
tmp |= STATUS_AD_MASK | (irq_prio << 1);
tmp &= ~STATUS_IE_MASK;
asm volatile("flag %0 \n"::"r"(tmp));
}
static void arcv2_irq_mask(struct irq_data *data)
{
write_aux_reg(AUX_IRQ_SELECT, data->irq);
write_aux_reg(AUX_IRQ_ENABLE, 0);
}
static void arcv2_irq_unmask(struct irq_data *data)
{
write_aux_reg(AUX_IRQ_SELECT, data->irq);
write_aux_reg(AUX_IRQ_ENABLE, 1);
}
void arcv2_irq_enable(struct irq_data *data)
{
write_aux_reg(AUX_IRQ_SELECT, data->irq);
write_aux_reg(AUX_IRQ_PRIORITY, irq_prio);
write_aux_reg(AUX_IRQ_ENABLE, 1);
}
static int arcv2_irq_map(struct irq_domain *d, unsigned int irq,
irq_hw_number_t hw)
{
if (hw < 24) {
irq_set_percpu_devid(irq);
irq_set_chip_and_handler(irq, &arcv2_irq_chip, handle_percpu_irq);
} else {
irq_set_chip_and_handler(irq, &arcv2_irq_chip, handle_level_irq);
}
return 0;
}
static int __init
init_onchip_IRQ(struct device_node *intc, struct device_node *parent)
{
if (parent)
panic("DeviceTree incore intc not a root irq controller\n");
root_domain = irq_domain_add_legacy(intc, NR_CPU_IRQS, 0, 0,
&arcv2_irq_ops, NULL);
if (!root_domain)
panic("root irq domain not avail\n");
irq_set_default_host(root_domain);
return 0;
}
