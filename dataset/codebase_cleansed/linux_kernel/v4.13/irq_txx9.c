static void txx9_irq_unmask(struct irq_data *d)
{
unsigned int irq_nr = d->irq - TXX9_IRQ_BASE;
u32 __iomem *ilrp = &txx9_ircptr->ilr[(irq_nr % 16 ) / 2];
int ofs = irq_nr / 16 * 16 + (irq_nr & 1) * 8;
__raw_writel((__raw_readl(ilrp) & ~(0xff << ofs))
| (txx9irq[irq_nr].level << ofs),
ilrp);
#ifdef CONFIG_CPU_TX39XX
__raw_writel(0, &txx9_ircptr->imr);
__raw_writel(irc_elevel, &txx9_ircptr->imr);
#endif
}
static inline void txx9_irq_mask(struct irq_data *d)
{
unsigned int irq_nr = d->irq - TXX9_IRQ_BASE;
u32 __iomem *ilrp = &txx9_ircptr->ilr[(irq_nr % 16) / 2];
int ofs = irq_nr / 16 * 16 + (irq_nr & 1) * 8;
__raw_writel((__raw_readl(ilrp) & ~(0xff << ofs))
| (irc_dlevel << ofs),
ilrp);
#ifdef CONFIG_CPU_TX39XX
__raw_writel(0, &txx9_ircptr->imr);
__raw_writel(irc_elevel, &txx9_ircptr->imr);
__raw_readl(&txx9_ircptr->ssr);
#else
mmiowb();
#endif
}
static void txx9_irq_mask_ack(struct irq_data *d)
{
unsigned int irq_nr = d->irq - TXX9_IRQ_BASE;
txx9_irq_mask(d);
if (unlikely(TXx9_IRCR_EDGE(txx9irq[irq_nr].mode)))
__raw_writel(TXx9_IRSCR_EIClrE | irq_nr, &txx9_ircptr->scr);
}
static int txx9_irq_set_type(struct irq_data *d, unsigned int flow_type)
{
unsigned int irq_nr = d->irq - TXX9_IRQ_BASE;
u32 cr;
u32 __iomem *crp;
int ofs;
int mode;
if (flow_type & IRQF_TRIGGER_PROBE)
return 0;
switch (flow_type & IRQF_TRIGGER_MASK) {
case IRQF_TRIGGER_RISING: mode = TXx9_IRCR_UP; break;
case IRQF_TRIGGER_FALLING: mode = TXx9_IRCR_DOWN; break;
case IRQF_TRIGGER_HIGH: mode = TXx9_IRCR_HIGH; break;
case IRQF_TRIGGER_LOW: mode = TXx9_IRCR_LOW; break;
default:
return -EINVAL;
}
crp = &txx9_ircptr->cr[(unsigned int)irq_nr / 8];
cr = __raw_readl(crp);
ofs = (irq_nr & (8 - 1)) * 2;
cr &= ~(0x3 << ofs);
cr |= (mode & 0x3) << ofs;
__raw_writel(cr, crp);
txx9irq[irq_nr].mode = mode;
return 0;
}
void __init txx9_irq_init(unsigned long baseaddr)
{
int i;
txx9_ircptr = ioremap(baseaddr, sizeof(struct txx9_irc_reg));
for (i = 0; i < TXx9_MAX_IR; i++) {
txx9irq[i].level = 4;
txx9irq[i].mode = TXx9_IRCR_LOW;
irq_set_chip_and_handler(TXX9_IRQ_BASE + i, &txx9_irq_chip,
handle_level_irq);
}
__raw_writel(0, &txx9_ircptr->imr);
for (i = 0; i < 8; i++)
__raw_writel(0, &txx9_ircptr->ilr[i]);
for (i = 0; i < 2; i++)
__raw_writel(0, &txx9_ircptr->cr[i]);
__raw_writel(TXx9_IRCER_ICE, &txx9_ircptr->cer);
__raw_writel(irc_elevel, &txx9_ircptr->imr);
}
int __init txx9_irq_set_pri(int irc_irq, int new_pri)
{
int old_pri;
if ((unsigned int)irc_irq >= TXx9_MAX_IR)
return 0;
old_pri = txx9irq[irc_irq].level;
txx9irq[irc_irq].level = new_pri;
return old_pri;
}
int txx9_irq(void)
{
u32 csr = __raw_readl(&txx9_ircptr->csr);
if (likely(!(csr & TXx9_IRCSR_IF)))
return TXX9_IRQ_BASE + (csr & (TXx9_MAX_IR - 1));
return -1;
}
