static void mv64x60_mask_low(struct irq_data *d)
{
int level2 = irqd_to_hwirq(d) & MV64x60_LEVEL2_MASK;
unsigned long flags;
spin_lock_irqsave(&mv64x60_lock, flags);
mv64x60_cached_low_mask &= ~(1 << level2);
out_le32(mv64x60_irq_reg_base + MV64X60_IC_CPU0_INTR_MASK_LO,
mv64x60_cached_low_mask);
spin_unlock_irqrestore(&mv64x60_lock, flags);
(void)in_le32(mv64x60_irq_reg_base + MV64X60_IC_CPU0_INTR_MASK_LO);
}
static void mv64x60_unmask_low(struct irq_data *d)
{
int level2 = irqd_to_hwirq(d) & MV64x60_LEVEL2_MASK;
unsigned long flags;
spin_lock_irqsave(&mv64x60_lock, flags);
mv64x60_cached_low_mask |= 1 << level2;
out_le32(mv64x60_irq_reg_base + MV64X60_IC_CPU0_INTR_MASK_LO,
mv64x60_cached_low_mask);
spin_unlock_irqrestore(&mv64x60_lock, flags);
(void)in_le32(mv64x60_irq_reg_base + MV64X60_IC_CPU0_INTR_MASK_LO);
}
static void mv64x60_mask_high(struct irq_data *d)
{
int level2 = irqd_to_hwirq(d) & MV64x60_LEVEL2_MASK;
unsigned long flags;
spin_lock_irqsave(&mv64x60_lock, flags);
mv64x60_cached_high_mask &= ~(1 << level2);
out_le32(mv64x60_irq_reg_base + MV64X60_IC_CPU0_INTR_MASK_HI,
mv64x60_cached_high_mask);
spin_unlock_irqrestore(&mv64x60_lock, flags);
(void)in_le32(mv64x60_irq_reg_base + MV64X60_IC_CPU0_INTR_MASK_HI);
}
static void mv64x60_unmask_high(struct irq_data *d)
{
int level2 = irqd_to_hwirq(d) & MV64x60_LEVEL2_MASK;
unsigned long flags;
spin_lock_irqsave(&mv64x60_lock, flags);
mv64x60_cached_high_mask |= 1 << level2;
out_le32(mv64x60_irq_reg_base + MV64X60_IC_CPU0_INTR_MASK_HI,
mv64x60_cached_high_mask);
spin_unlock_irqrestore(&mv64x60_lock, flags);
(void)in_le32(mv64x60_irq_reg_base + MV64X60_IC_CPU0_INTR_MASK_HI);
}
static void mv64x60_mask_gpp(struct irq_data *d)
{
int level2 = irqd_to_hwirq(d) & MV64x60_LEVEL2_MASK;
unsigned long flags;
spin_lock_irqsave(&mv64x60_lock, flags);
mv64x60_cached_gpp_mask &= ~(1 << level2);
out_le32(mv64x60_gpp_reg_base + MV64x60_GPP_INTR_MASK,
mv64x60_cached_gpp_mask);
spin_unlock_irqrestore(&mv64x60_lock, flags);
(void)in_le32(mv64x60_gpp_reg_base + MV64x60_GPP_INTR_MASK);
}
static void mv64x60_mask_ack_gpp(struct irq_data *d)
{
int level2 = irqd_to_hwirq(d) & MV64x60_LEVEL2_MASK;
unsigned long flags;
spin_lock_irqsave(&mv64x60_lock, flags);
mv64x60_cached_gpp_mask &= ~(1 << level2);
out_le32(mv64x60_gpp_reg_base + MV64x60_GPP_INTR_MASK,
mv64x60_cached_gpp_mask);
out_le32(mv64x60_gpp_reg_base + MV64x60_GPP_INTR_CAUSE,
~(1 << level2));
spin_unlock_irqrestore(&mv64x60_lock, flags);
(void)in_le32(mv64x60_gpp_reg_base + MV64x60_GPP_INTR_CAUSE);
}
static void mv64x60_unmask_gpp(struct irq_data *d)
{
int level2 = irqd_to_hwirq(d) & MV64x60_LEVEL2_MASK;
unsigned long flags;
spin_lock_irqsave(&mv64x60_lock, flags);
mv64x60_cached_gpp_mask |= 1 << level2;
out_le32(mv64x60_gpp_reg_base + MV64x60_GPP_INTR_MASK,
mv64x60_cached_gpp_mask);
spin_unlock_irqrestore(&mv64x60_lock, flags);
(void)in_le32(mv64x60_gpp_reg_base + MV64x60_GPP_INTR_MASK);
}
static int mv64x60_host_map(struct irq_domain *h, unsigned int virq,
irq_hw_number_t hwirq)
{
int level1;
irq_set_status_flags(virq, IRQ_LEVEL);
level1 = (hwirq & MV64x60_LEVEL1_MASK) >> MV64x60_LEVEL1_OFFSET;
BUG_ON(level1 > MV64x60_LEVEL1_GPP);
irq_set_chip_and_handler(virq, mv64x60_chips[level1],
handle_level_irq);
return 0;
}
void __init mv64x60_init_irq(void)
{
struct device_node *np;
phys_addr_t paddr;
unsigned int size;
const unsigned int *reg;
unsigned long flags;
np = of_find_compatible_node(NULL, NULL, "marvell,mv64360-gpp");
reg = of_get_property(np, "reg", &size);
paddr = of_translate_address(np, reg);
mv64x60_gpp_reg_base = ioremap(paddr, reg[1]);
of_node_put(np);
np = of_find_compatible_node(NULL, NULL, "marvell,mv64360-pic");
reg = of_get_property(np, "reg", &size);
paddr = of_translate_address(np, reg);
mv64x60_irq_reg_base = ioremap(paddr, reg[1]);
mv64x60_irq_host = irq_domain_add_linear(np, MV64x60_NUM_IRQS,
&mv64x60_host_ops, NULL);
spin_lock_irqsave(&mv64x60_lock, flags);
out_le32(mv64x60_gpp_reg_base + MV64x60_GPP_INTR_MASK,
mv64x60_cached_gpp_mask);
out_le32(mv64x60_irq_reg_base + MV64X60_IC_CPU0_INTR_MASK_LO,
mv64x60_cached_low_mask);
out_le32(mv64x60_irq_reg_base + MV64X60_IC_CPU0_INTR_MASK_HI,
mv64x60_cached_high_mask);
out_le32(mv64x60_gpp_reg_base + MV64x60_GPP_INTR_CAUSE, 0);
out_le32(mv64x60_irq_reg_base + MV64X60_IC_MAIN_CAUSE_LO, 0);
out_le32(mv64x60_irq_reg_base + MV64X60_IC_MAIN_CAUSE_HI, 0);
spin_unlock_irqrestore(&mv64x60_lock, flags);
}
unsigned int mv64x60_get_irq(void)
{
u32 cause;
int level1;
irq_hw_number_t hwirq;
int virq = NO_IRQ;
cause = in_le32(mv64x60_irq_reg_base + MV64X60_IC_CPU0_SELECT_CAUSE);
if (cause & MV64X60_SELECT_CAUSE_HIGH) {
cause &= mv64x60_cached_high_mask;
level1 = MV64x60_LEVEL1_HIGH;
if (cause & MV64X60_HIGH_GPP_GROUPS) {
cause = in_le32(mv64x60_gpp_reg_base +
MV64x60_GPP_INTR_CAUSE);
cause &= mv64x60_cached_gpp_mask;
level1 = MV64x60_LEVEL1_GPP;
}
} else {
cause &= mv64x60_cached_low_mask;
level1 = MV64x60_LEVEL1_LOW;
}
if (cause) {
hwirq = (level1 << MV64x60_LEVEL1_OFFSET) | __ilog2(cause);
virq = irq_linear_revmap(mv64x60_irq_host, hwirq);
}
return virq;
}
