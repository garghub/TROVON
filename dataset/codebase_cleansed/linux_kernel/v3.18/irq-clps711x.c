static asmlinkage void __exception_irq_entry clps711x_irqh(struct pt_regs *regs)
{
u32 irqstat;
do {
irqstat = readw_relaxed(clps711x_intc->intmr[0]) &
readw_relaxed(clps711x_intc->intsr[0]);
if (irqstat)
handle_domain_irq(clps711x_intc->domain,
fls(irqstat) - 1, regs);
irqstat = readw_relaxed(clps711x_intc->intmr[1]) &
readw_relaxed(clps711x_intc->intsr[1]);
if (irqstat)
handle_domain_irq(clps711x_intc->domain,
fls(irqstat) - 1 + 16, regs);
} while (irqstat);
}
static void clps711x_intc_eoi(struct irq_data *d)
{
irq_hw_number_t hwirq = irqd_to_hwirq(d);
writel_relaxed(0, clps711x_intc->base + clps711x_irqs[hwirq].eoi);
}
static void clps711x_intc_mask(struct irq_data *d)
{
irq_hw_number_t hwirq = irqd_to_hwirq(d);
void __iomem *intmr = clps711x_intc->intmr[hwirq / 16];
u32 tmp;
tmp = readl_relaxed(intmr);
tmp &= ~(1 << (hwirq % 16));
writel_relaxed(tmp, intmr);
}
static void clps711x_intc_unmask(struct irq_data *d)
{
irq_hw_number_t hwirq = irqd_to_hwirq(d);
void __iomem *intmr = clps711x_intc->intmr[hwirq / 16];
u32 tmp;
tmp = readl_relaxed(intmr);
tmp |= 1 << (hwirq % 16);
writel_relaxed(tmp, intmr);
}
static int __init clps711x_intc_irq_map(struct irq_domain *h, unsigned int virq,
irq_hw_number_t hw)
{
irq_flow_handler_t handler = handle_level_irq;
unsigned int flags = IRQF_VALID | IRQF_PROBE;
if (!clps711x_irqs[hw].flags)
return 0;
if (clps711x_irqs[hw].flags & CLPS711X_FLAG_FIQ) {
handler = handle_bad_irq;
flags |= IRQF_NOAUTOEN;
} else if (clps711x_irqs[hw].eoi) {
handler = handle_fasteoi_irq;
}
if (clps711x_irqs[hw].eoi)
writel_relaxed(0, clps711x_intc->base + clps711x_irqs[hw].eoi);
irq_set_chip_and_handler(virq, &clps711x_intc_chip, handler);
set_irq_flags(virq, flags);
return 0;
}
static int __init _clps711x_intc_init(struct device_node *np,
phys_addr_t base, resource_size_t size)
{
int err;
clps711x_intc = kzalloc(sizeof(*clps711x_intc), GFP_KERNEL);
if (!clps711x_intc)
return -ENOMEM;
clps711x_intc->base = ioremap(base, size);
if (!clps711x_intc->base) {
err = -ENOMEM;
goto out_kfree;
}
clps711x_intc->intsr[0] = clps711x_intc->base + CLPS711X_INTSR1;
clps711x_intc->intmr[0] = clps711x_intc->base + CLPS711X_INTMR1;
clps711x_intc->intsr[1] = clps711x_intc->base + CLPS711X_INTSR2;
clps711x_intc->intmr[1] = clps711x_intc->base + CLPS711X_INTMR2;
clps711x_intc->intsr[2] = clps711x_intc->base + CLPS711X_INTSR3;
clps711x_intc->intmr[2] = clps711x_intc->base + CLPS711X_INTMR3;
writel_relaxed(0, clps711x_intc->intmr[0]);
writel_relaxed(0, clps711x_intc->intmr[1]);
writel_relaxed(0, clps711x_intc->intmr[2]);
err = irq_alloc_descs(-1, 0, ARRAY_SIZE(clps711x_irqs), numa_node_id());
if (IS_ERR_VALUE(err))
goto out_iounmap;
clps711x_intc->ops.map = clps711x_intc_irq_map;
clps711x_intc->ops.xlate = irq_domain_xlate_onecell;
clps711x_intc->domain =
irq_domain_add_legacy(np, ARRAY_SIZE(clps711x_irqs),
0, 0, &clps711x_intc->ops, NULL);
if (!clps711x_intc->domain) {
err = -ENOMEM;
goto out_irqfree;
}
irq_set_default_host(clps711x_intc->domain);
set_handle_irq(clps711x_irqh);
#ifdef CONFIG_FIQ
init_FIQ(0);
#endif
return 0;
out_irqfree:
irq_free_descs(0, ARRAY_SIZE(clps711x_irqs));
out_iounmap:
iounmap(clps711x_intc->base);
out_kfree:
kfree(clps711x_intc);
return err;
}
void __init clps711x_intc_init(phys_addr_t base, resource_size_t size)
{
BUG_ON(_clps711x_intc_init(NULL, base, size));
}
static int __init clps711x_intc_init_dt(struct device_node *np,
struct device_node *parent)
{
struct resource res;
int err;
err = of_address_to_resource(np, 0, &res);
if (err)
return err;
return _clps711x_intc_init(np, res.start, resource_size(&res));
}
