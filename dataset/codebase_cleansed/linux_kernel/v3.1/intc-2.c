static void intc_irq_mask(struct irq_data *d)
{
unsigned int irq = d->irq - MCFINT_VECBASE;
unsigned long imraddr;
u32 val, imrbit;
#ifdef MCFICM_INTC1
imraddr = (irq & 0x40) ? MCFICM_INTC1 : MCFICM_INTC0;
#else
imraddr = MCFICM_INTC0;
#endif
imraddr += (irq & 0x20) ? MCFINTC_IMRH : MCFINTC_IMRL;
imrbit = 0x1 << (irq & 0x1f);
val = __raw_readl(imraddr);
__raw_writel(val | imrbit, imraddr);
}
static void intc_irq_unmask(struct irq_data *d)
{
unsigned int irq = d->irq - MCFINT_VECBASE;
unsigned long imraddr;
u32 val, imrbit;
#ifdef MCFICM_INTC1
imraddr = (irq & 0x40) ? MCFICM_INTC1 : MCFICM_INTC0;
#else
imraddr = MCFICM_INTC0;
#endif
imraddr += ((irq & 0x20) ? MCFINTC_IMRH : MCFINTC_IMRL);
imrbit = 0x1 << (irq & 0x1f);
if ((irq & 0x20) == 0)
imrbit |= 0x1;
val = __raw_readl(imraddr);
__raw_writel(val & ~imrbit, imraddr);
}
static void intc_irq_ack(struct irq_data *d)
{
unsigned int irq = d->irq;
__raw_writeb(0x1 << (irq - EINT0), MCFEPORT_EPFR);
}
static unsigned int intc_irq_startup(struct irq_data *d)
{
unsigned int irq = d->irq - MCFINT_VECBASE;
unsigned long icraddr;
#ifdef MCFICM_INTC1
icraddr = (irq & 0x40) ? MCFICM_INTC1 : MCFICM_INTC0;
#else
icraddr = MCFICM_INTC0;
#endif
icraddr += MCFINTC_ICR0 + (irq & 0x3f);
if (__raw_readb(icraddr) == 0)
__raw_writeb(intc_intpri--, icraddr);
irq = d->irq;
if ((irq >= EINT1) && (irq <= EINT7)) {
u8 v;
irq -= EINT0;
v = __raw_readb(MCFEPORT_EPDDR);
__raw_writeb(v & ~(0x1 << irq), MCFEPORT_EPDDR);
v = __raw_readb(MCFEPORT_EPIER);
__raw_writeb(v | (0x1 << irq), MCFEPORT_EPIER);
}
intc_irq_unmask(d);
return 0;
}
static int intc_irq_set_type(struct irq_data *d, unsigned int type)
{
unsigned int irq = d->irq;
u16 pa, tb;
switch (type) {
case IRQ_TYPE_EDGE_RISING:
tb = 0x1;
break;
case IRQ_TYPE_EDGE_FALLING:
tb = 0x2;
break;
case IRQ_TYPE_EDGE_BOTH:
tb = 0x3;
break;
default:
tb = 0;
break;
}
if (tb)
irq_set_handler(irq, handle_edge_irq);
irq -= EINT0;
pa = __raw_readw(MCFEPORT_EPPAR);
pa = (pa & ~(0x3 << (irq * 2))) | (tb << (irq * 2));
__raw_writew(pa, MCFEPORT_EPPAR);
return 0;
}
void __init init_IRQ(void)
{
int irq;
__raw_writel(0x1, MCFICM_INTC0 + MCFINTC_IMRL);
#ifdef MCFICM_INTC1
__raw_writel(0x1, MCFICM_INTC1 + MCFINTC_IMRL);
#endif
for (irq = MCFINT_VECBASE; (irq < MCFINT_VECBASE + NR_VECS); irq++) {
if ((irq >= EINT1) && (irq <=EINT7))
irq_set_chip(irq, &intc_irq_chip_edge_port);
else
irq_set_chip(irq, &intc_irq_chip);
irq_set_irq_type(irq, IRQ_TYPE_LEVEL_HIGH);
irq_set_handler(irq, handle_level_irq);
}
}
