static void frv_mb93493_mask(struct irq_data *d)
{
uint32_t iqsr;
volatile void *piqsr;
if (IRQ_ROUTING & (1 << (d->irq - IRQ_BASE_MB93493)))
piqsr = __addr_MB93493_IQSR(1);
else
piqsr = __addr_MB93493_IQSR(0);
iqsr = readl(piqsr);
iqsr &= ~(1 << (d->irq - IRQ_BASE_MB93493 + 16));
writel(iqsr, piqsr);
}
static void frv_mb93493_ack(struct irq_data *d)
{
}
static void frv_mb93493_unmask(struct irq_data *d)
{
uint32_t iqsr;
volatile void *piqsr;
if (IRQ_ROUTING & (1 << (d->irq - IRQ_BASE_MB93493)))
piqsr = __addr_MB93493_IQSR(1);
else
piqsr = __addr_MB93493_IQSR(0);
iqsr = readl(piqsr);
iqsr |= 1 << (d->irq - IRQ_BASE_MB93493 + 16);
writel(iqsr, piqsr);
}
static irqreturn_t mb93493_interrupt(int irq, void *_piqsr)
{
volatile void *piqsr = _piqsr;
uint32_t iqsr;
iqsr = readl(piqsr);
iqsr = iqsr & (iqsr >> 16) & 0xffff;
while (iqsr) {
int irq;
asm("scan %1,gr0,%0" : "=r"(irq) : "r"(iqsr));
irq = 31 - irq;
iqsr &= ~(1 << irq);
generic_handle_irq(IRQ_BASE_MB93493 + irq);
}
return IRQ_HANDLED;
}
void __init mb93493_init(void)
{
int irq;
for (irq = IRQ_BASE_MB93493 + 0; irq <= IRQ_BASE_MB93493 + 10; irq++)
irq_set_chip_and_handler(irq, &frv_mb93493_pic,
handle_edge_irq);
setup_irq(IRQ_CPU_MB93493_0, &mb93493_irq[0]);
setup_irq(IRQ_CPU_MB93493_1, &mb93493_irq[1]);
}
