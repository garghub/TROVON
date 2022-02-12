void mcf_setimr(int index)
{
u16 imr;
imr = __raw_readw(MCFSIM_IMR);
__raw_writew(imr | (0x1 << index), MCFSIM_IMR);
}
void mcf_clrimr(int index)
{
u16 imr;
imr = __raw_readw(MCFSIM_IMR);
__raw_writew(imr & ~(0x1 << index), MCFSIM_IMR);
}
void mcf_maskimr(unsigned int mask)
{
u16 imr;
imr = __raw_readw(MCFSIM_IMR);
imr |= mask;
__raw_writew(imr, MCFSIM_IMR);
}
void mcf_setimr(int index)
{
u32 imr;
imr = __raw_readl(MCFSIM_IMR);
__raw_writel(imr | (0x1 << index), MCFSIM_IMR);
}
void mcf_clrimr(int index)
{
u32 imr;
imr = __raw_readl(MCFSIM_IMR);
__raw_writel(imr & ~(0x1 << index), MCFSIM_IMR);
}
void mcf_maskimr(unsigned int mask)
{
u32 imr;
imr = __raw_readl(MCFSIM_IMR);
imr |= mask;
__raw_writel(imr, MCFSIM_IMR);
}
void mcf_autovector(int irq)
{
#ifdef MCFSIM_AVR
if ((irq >= EIRQ1) && (irq <= EIRQ7)) {
u8 avec;
avec = __raw_readb(MCFSIM_AVR);
avec |= (0x1 << (irq - EIRQ1 + 1));
__raw_writeb(avec, MCFSIM_AVR);
}
#endif
}
static void intc_irq_mask(struct irq_data *d)
{
if (mcf_irq2imr[d->irq])
mcf_setimr(mcf_irq2imr[d->irq]);
}
static void intc_irq_unmask(struct irq_data *d)
{
if (mcf_irq2imr[d->irq])
mcf_clrimr(mcf_irq2imr[d->irq]);
}
static int intc_irq_set_type(struct irq_data *d, unsigned int type)
{
return 0;
}
void __init init_IRQ(void)
{
int irq;
mcf_maskimr(0xffffffff);
for (irq = 0; (irq < NR_IRQS); irq++) {
irq_set_chip(irq, &intc_irq_chip);
irq_set_irq_type(irq, IRQ_TYPE_LEVEL_HIGH);
irq_set_handler(irq, handle_level_irq);
}
}
