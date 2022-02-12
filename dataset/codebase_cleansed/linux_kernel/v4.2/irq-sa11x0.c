static void sa1100_mask_irq(struct irq_data *d)
{
u32 reg;
reg = readl_relaxed(iobase + ICMR);
reg &= ~BIT(d->hwirq);
writel_relaxed(reg, iobase + ICMR);
}
static void sa1100_unmask_irq(struct irq_data *d)
{
u32 reg;
reg = readl_relaxed(iobase + ICMR);
reg |= BIT(d->hwirq);
writel_relaxed(reg, iobase + ICMR);
}
static int sa1100_set_wake(struct irq_data *d, unsigned int on)
{
return sa11x0_sc_set_wake(d->hwirq, on);
}
static int sa1100_normal_irqdomain_map(struct irq_domain *d,
unsigned int irq, irq_hw_number_t hwirq)
{
irq_set_chip_and_handler(irq, &sa1100_normal_chip,
handle_level_irq);
set_irq_flags(irq, IRQF_VALID);
return 0;
}
static int sa1100irq_suspend(void)
{
struct sa1100irq_state *st = &sa1100irq_state;
st->saved = 1;
st->icmr = readl_relaxed(iobase + ICMR);
st->iclr = readl_relaxed(iobase + ICLR);
st->iccr = readl_relaxed(iobase + ICCR);
writel_relaxed(st->icmr & 0xfffff000, iobase + ICMR);
return 0;
}
static void sa1100irq_resume(void)
{
struct sa1100irq_state *st = &sa1100irq_state;
if (st->saved) {
writel_relaxed(st->iccr, iobase + ICCR);
writel_relaxed(st->iclr, iobase + ICLR);
writel_relaxed(st->icmr, iobase + ICMR);
}
}
static int __init sa1100irq_init_devicefs(void)
{
register_syscore_ops(&sa1100irq_syscore_ops);
return 0;
}
static asmlinkage void __exception_irq_entry
sa1100_handle_irq(struct pt_regs *regs)
{
uint32_t icip, icmr, mask;
do {
icip = readl_relaxed(iobase + ICIP);
icmr = readl_relaxed(iobase + ICMR);
mask = icip & icmr;
if (mask == 0)
break;
handle_domain_irq(sa1100_normal_irqdomain,
ffs(mask) - 1, regs);
} while (1);
}
void __init sa11x0_init_irq_nodt(int irq_start, resource_size_t io_start)
{
iobase = ioremap(io_start, SZ_64K);
if (WARN_ON(!iobase))
return;
writel_relaxed(0, iobase + ICMR);
writel_relaxed(0, iobase + ICLR);
writel_relaxed(1, iobase + ICCR);
sa1100_normal_irqdomain = irq_domain_add_simple(NULL,
32, irq_start,
&sa1100_normal_irqdomain_ops, NULL);
set_handle_irq(sa1100_handle_irq);
}
