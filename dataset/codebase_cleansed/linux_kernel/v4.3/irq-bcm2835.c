static void armctrl_mask_irq(struct irq_data *d)
{
writel_relaxed(HWIRQ_BIT(d->hwirq), intc.disable[HWIRQ_BANK(d->hwirq)]);
}
static void armctrl_unmask_irq(struct irq_data *d)
{
writel_relaxed(HWIRQ_BIT(d->hwirq), intc.enable[HWIRQ_BANK(d->hwirq)]);
}
static int armctrl_xlate(struct irq_domain *d, struct device_node *ctrlr,
const u32 *intspec, unsigned int intsize,
unsigned long *out_hwirq, unsigned int *out_type)
{
if (WARN_ON(intsize != 2))
return -EINVAL;
if (WARN_ON(intspec[0] >= NR_BANKS))
return -EINVAL;
if (WARN_ON(intspec[1] >= IRQS_PER_BANK))
return -EINVAL;
if (WARN_ON(intspec[0] == 0 && intspec[1] >= NR_IRQS_BANK0))
return -EINVAL;
*out_hwirq = MAKE_HWIRQ(intspec[0], intspec[1]);
*out_type = IRQ_TYPE_NONE;
return 0;
}
static int __init armctrl_of_init(struct device_node *node,
struct device_node *parent,
bool is_2836)
{
void __iomem *base;
int irq, b, i;
base = of_iomap(node, 0);
if (!base)
panic("%s: unable to map IC registers\n",
node->full_name);
intc.domain = irq_domain_add_linear(node, MAKE_HWIRQ(NR_BANKS, 0),
&armctrl_ops, NULL);
if (!intc.domain)
panic("%s: unable to create IRQ domain\n", node->full_name);
for (b = 0; b < NR_BANKS; b++) {
intc.pending[b] = base + reg_pending[b];
intc.enable[b] = base + reg_enable[b];
intc.disable[b] = base + reg_disable[b];
for (i = 0; i < bank_irqs[b]; i++) {
irq = irq_create_mapping(intc.domain, MAKE_HWIRQ(b, i));
BUG_ON(irq <= 0);
irq_set_chip_and_handler(irq, &armctrl_chip,
handle_level_irq);
irq_set_probe(irq);
}
}
if (is_2836) {
int parent_irq = irq_of_parse_and_map(node, 0);
if (!parent_irq) {
panic("%s: unable to get parent interrupt.\n",
node->full_name);
}
irq_set_chained_handler(parent_irq, bcm2836_chained_handle_irq);
} else {
set_handle_irq(bcm2835_handle_irq);
}
return 0;
}
static int __init bcm2835_armctrl_of_init(struct device_node *node,
struct device_node *parent)
{
return armctrl_of_init(node, parent, false);
}
static int __init bcm2836_armctrl_of_init(struct device_node *node,
struct device_node *parent)
{
return armctrl_of_init(node, parent, true);
}
static u32 armctrl_translate_bank(int bank)
{
u32 stat = readl_relaxed(intc.pending[bank]);
return MAKE_HWIRQ(bank, ffs(stat) - 1);
}
static u32 armctrl_translate_shortcut(int bank, u32 stat)
{
return MAKE_HWIRQ(bank, shortcuts[ffs(stat >> SHORTCUT_SHIFT) - 1]);
}
static u32 get_next_armctrl_hwirq(void)
{
u32 stat = readl_relaxed(intc.pending[0]) & BANK0_VALID_MASK;
if (stat == 0)
return ~0;
else if (stat & BANK0_HWIRQ_MASK)
return MAKE_HWIRQ(0, ffs(stat & BANK0_HWIRQ_MASK) - 1);
else if (stat & SHORTCUT1_MASK)
return armctrl_translate_shortcut(1, stat & SHORTCUT1_MASK);
else if (stat & SHORTCUT2_MASK)
return armctrl_translate_shortcut(2, stat & SHORTCUT2_MASK);
else if (stat & BANK1_HWIRQ)
return armctrl_translate_bank(1);
else if (stat & BANK2_HWIRQ)
return armctrl_translate_bank(2);
else
BUG();
}
static void __exception_irq_entry bcm2835_handle_irq(
struct pt_regs *regs)
{
u32 hwirq;
while ((hwirq = get_next_armctrl_hwirq()) != ~0)
handle_IRQ(irq_linear_revmap(intc.domain, hwirq), regs);
}
static void bcm2836_chained_handle_irq(struct irq_desc *desc)
{
u32 hwirq;
while ((hwirq = get_next_armctrl_hwirq()) != ~0)
generic_handle_irq(irq_linear_revmap(intc.domain, hwirq));
}
