static void unmask_kn02_irq(struct irq_data *d)
{
volatile u32 *csr = (volatile u32 *)CKSEG1ADDR(KN02_SLOT_BASE +
KN02_CSR);
cached_kn02_csr |= (1 << (d->irq - kn02_irq_base + 16));
*csr = cached_kn02_csr;
}
static void mask_kn02_irq(struct irq_data *d)
{
volatile u32 *csr = (volatile u32 *)CKSEG1ADDR(KN02_SLOT_BASE +
KN02_CSR);
cached_kn02_csr &= ~(1 << (d->irq - kn02_irq_base + 16));
*csr = cached_kn02_csr;
}
static void ack_kn02_irq(struct irq_data *d)
{
mask_kn02_irq(d);
iob();
}
void __init init_kn02_irqs(int base)
{
volatile u32 *csr = (volatile u32 *)CKSEG1ADDR(KN02_SLOT_BASE +
KN02_CSR);
int i;
cached_kn02_csr &= ~KN02_CSR_IOINTEN;
*csr = cached_kn02_csr;
iob();
for (i = base; i < base + KN02_IRQ_LINES; i++)
irq_set_chip_and_handler(i, &kn02_irq_type, handle_level_irq);
kn02_irq_base = base;
}
