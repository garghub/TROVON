static unsigned int inline irq2ebit(unsigned int irq)
{
return irqebitmap[irq - EINT0];
}
static unsigned int inline irq2ebit(unsigned int irq)
{
return irq - EINT0;
}
static void intc_irq_mask(struct irq_data *d)
{
unsigned int irq = d->irq - MCFINT_VECBASE;
if (MCFINTC1_SIMR && (irq > 64))
__raw_writeb(irq - 64, MCFINTC1_SIMR);
else
__raw_writeb(irq, MCFINTC0_SIMR);
}
static void intc_irq_unmask(struct irq_data *d)
{
unsigned int irq = d->irq - MCFINT_VECBASE;
if (MCFINTC1_CIMR && (irq > 64))
__raw_writeb(irq - 64, MCFINTC1_CIMR);
else
__raw_writeb(irq, MCFINTC0_CIMR);
}
static void intc_irq_ack(struct irq_data *d)
{
unsigned int ebit = irq2ebit(d->irq);
__raw_writeb(0x1 << ebit, MCFEPORT_EPFR);
}
static unsigned int intc_irq_startup(struct irq_data *d)
{
unsigned int irq = d->irq;
if ((irq >= EINT1) && (irq <= EINT7)) {
unsigned int ebit = irq2ebit(irq);
u8 v;
v = __raw_readb(MCFEPORT_EPDDR);
__raw_writeb(v & ~(0x1 << ebit), MCFEPORT_EPDDR);
v = __raw_readb(MCFEPORT_EPIER);
__raw_writeb(v | (0x1 << ebit), MCFEPORT_EPIER);
}
irq -= MCFINT_VECBASE;
if (MCFINTC1_ICR0 && (irq > 64))
__raw_writeb(5, MCFINTC1_ICR0 + irq - 64);
else
__raw_writeb(5, MCFINTC0_ICR0 + irq);
intc_irq_unmask(d);
return 0;
}
static int intc_irq_set_type(struct irq_data *d, unsigned int type)
{
unsigned int ebit, irq = d->irq;
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
ebit = irq2ebit(irq) * 2;
pa = __raw_readw(MCFEPORT_EPPAR);
pa = (pa & ~(0x3 << ebit)) | (tb << ebit);
__raw_writew(pa, MCFEPORT_EPPAR);
return 0;
}
void __init init_IRQ(void)
{
int irq, eirq;
__raw_writeb(0xff, MCFINTC0_SIMR);
if (MCFINTC1_SIMR)
__raw_writeb(0xff, MCFINTC1_SIMR);
eirq = MCFINT_VECBASE + 64 + (MCFINTC1_ICR0 ? 64 : 0);
for (irq = MCFINT_VECBASE; (irq < eirq); irq++) {
if ((irq >= EINT1) && (irq <= EINT7))
irq_set_chip(irq, &intc_irq_chip_edge_port);
else
irq_set_chip(irq, &intc_irq_chip);
irq_set_irq_type(irq, IRQ_TYPE_LEVEL_HIGH);
irq_set_handler(irq, handle_level_irq);
}
}
