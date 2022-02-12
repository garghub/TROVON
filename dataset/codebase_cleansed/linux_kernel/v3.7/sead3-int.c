asmlinkage void plat_irq_dispatch(void)
{
unsigned int pending = read_c0_cause() & read_c0_status() & ST0_IM;
int irq;
irq = (fls(pending) - CAUSEB_IP - 1);
if (irq >= 0)
do_IRQ(MIPS_CPU_IRQ_BASE + irq);
else
spurious_interrupt();
}
void __init arch_init_irq(void)
{
int i;
if (!cpu_has_veic) {
mips_cpu_irq_init();
if (cpu_has_vint) {
for (i = 0; i < 8; i++)
set_vi_handler(i, plat_irq_dispatch);
}
}
sead3_config_reg = (unsigned long)ioremap_nocache(SEAD_CONFIG_BASE,
SEAD_CONFIG_SIZE);
gic_present = (REG32(sead3_config_reg) & SEAD_CONFIG_GIC_PRESENT_MSK) >>
SEAD_CONFIG_GIC_PRESENT_SHF;
pr_info("GIC: %spresent\n", (gic_present) ? "" : "not ");
pr_info("EIC: %s\n",
(current_cpu_data.options & MIPS_CPU_VEIC) ? "on" : "off");
if (gic_present)
gic_init(GIC_BASE_ADDR, GIC_ADDRSPACE_SZ, gic_intr_map,
ARRAY_SIZE(gic_intr_map), MIPS_GIC_IRQ_BASE);
}
void gic_enable_interrupt(int irq_vec)
{
unsigned int i, irq_source;
for (i = 0; i < gic_shared_intr_map[irq_vec].num_shared_intr; i++) {
irq_source = gic_shared_intr_map[irq_vec].intr_list[i];
GIC_SET_INTR_MASK(irq_source);
}
if (gic_shared_intr_map[irq_vec].local_intr_mask) {
GICWRITE(GIC_REG(VPE_LOCAL, GIC_VPE_OTHER_ADDR), 0);
GICWRITE(GIC_REG(VPE_OTHER, GIC_VPE_SMASK),
gic_shared_intr_map[irq_vec].local_intr_mask);
}
}
void gic_disable_interrupt(int irq_vec)
{
unsigned int i, irq_source;
for (i = 0; i < gic_shared_intr_map[irq_vec].num_shared_intr; i++) {
irq_source = gic_shared_intr_map[irq_vec].intr_list[i];
GIC_CLR_INTR_MASK(irq_source);
}
if (gic_shared_intr_map[irq_vec].local_intr_mask) {
GICWRITE(GIC_REG(VPE_LOCAL, GIC_VPE_OTHER_ADDR), 0);
GICWRITE(GIC_REG(VPE_OTHER, GIC_VPE_RMASK),
gic_shared_intr_map[irq_vec].local_intr_mask);
}
}
void gic_irq_ack(struct irq_data *d)
{
GIC_CLR_INTR_MASK(d->irq - gic_irq_base);
}
void gic_finish_irq(struct irq_data *d)
{
unsigned int irq = (d->irq - gic_irq_base);
unsigned int i, irq_source;
for (i = 0; i < gic_shared_intr_map[irq].num_shared_intr; i++) {
irq_source = gic_shared_intr_map[irq].intr_list[i];
if (gic_irq_flags[irq_source] & GIC_TRIG_EDGE)
GICWRITE(GIC_REG(SHARED, GIC_SH_WEDGE), irq_source);
}
GIC_SET_INTR_MASK(irq);
}
void __init gic_platform_init(int irqs, struct irq_chip *irq_controller)
{
int i;
if (!cpu_has_veic)
return;
for (i = gic_irq_base; i < (gic_irq_base + irqs); i++)
irq_set_chip_and_handler(i, irq_controller, handle_percpu_irq);
}
