static void tx4939_irq_unmask(struct irq_data *d)
{
unsigned int irq_nr = d->irq - TXX9_IRQ_BASE;
u32 __iomem *lvlp;
int ofs;
if (irq_nr < 32) {
irq_nr--;
lvlp = &tx4939_ircptr->lvl[(irq_nr % 16) / 2].r;
} else {
irq_nr -= 32;
lvlp = &tx4939_ircptr->lvl[8 + (irq_nr % 16) / 2].r;
}
ofs = (irq_nr & 16) + (irq_nr & 1) * 8;
__raw_writel((__raw_readl(lvlp) & ~(0xff << ofs))
| (tx4939irq[irq_nr].level << ofs),
lvlp);
}
static inline void tx4939_irq_mask(struct irq_data *d)
{
unsigned int irq_nr = d->irq - TXX9_IRQ_BASE;
u32 __iomem *lvlp;
int ofs;
if (irq_nr < 32) {
irq_nr--;
lvlp = &tx4939_ircptr->lvl[(irq_nr % 16) / 2].r;
} else {
irq_nr -= 32;
lvlp = &tx4939_ircptr->lvl[8 + (irq_nr % 16) / 2].r;
}
ofs = (irq_nr & 16) + (irq_nr & 1) * 8;
__raw_writel((__raw_readl(lvlp) & ~(0xff << ofs))
| (irc_dlevel << ofs),
lvlp);
mmiowb();
}
static void tx4939_irq_mask_ack(struct irq_data *d)
{
unsigned int irq_nr = d->irq - TXX9_IRQ_BASE;
tx4939_irq_mask(d);
if (TXx9_IRCR_EDGE(tx4939irq[irq_nr].mode)) {
irq_nr--;
__raw_writel((TXx9_IRSCR_EIClrE | (irq_nr & 0xf))
<< (irq_nr & 0x10),
&tx4939_ircptr->edc.r);
}
}
static int tx4939_irq_set_type(struct irq_data *d, unsigned int flow_type)
{
unsigned int irq_nr = d->irq - TXX9_IRQ_BASE;
u32 cr;
u32 __iomem *crp;
int ofs;
int mode;
if (flow_type & IRQF_TRIGGER_PROBE)
return 0;
switch (flow_type & IRQF_TRIGGER_MASK) {
case IRQF_TRIGGER_RISING:
mode = TXx9_IRCR_UP;
break;
case IRQF_TRIGGER_FALLING:
mode = TXx9_IRCR_DOWN;
break;
case IRQF_TRIGGER_HIGH:
mode = TXx9_IRCR_HIGH;
break;
case IRQF_TRIGGER_LOW:
mode = TXx9_IRCR_LOW;
break;
default:
return -EINVAL;
}
if (irq_nr < 32) {
irq_nr--;
crp = &tx4939_ircptr->dm[(irq_nr & 8) >> 3].r;
} else {
irq_nr -= 32;
crp = &tx4939_ircptr->dm2[((irq_nr & 8) >> 3)].r;
}
ofs = (((irq_nr & 16) >> 1) | (irq_nr & (8 - 1))) * 2;
cr = __raw_readl(crp);
cr &= ~(0x3 << ofs);
cr |= (mode & 0x3) << ofs;
__raw_writel(cr, crp);
tx4939irq[irq_nr].mode = mode;
return 0;
}
static int tx4939_irq_set_pri(int irc_irq, int new_pri)
{
int old_pri;
if ((unsigned int)irc_irq >= TX4939_NUM_IR)
return 0;
old_pri = tx4939irq[irc_irq].level;
tx4939irq[irc_irq].level = new_pri;
return old_pri;
}
void __init tx4939_irq_init(void)
{
int i;
mips_cpu_irq_init();
__raw_writel(0, &tx4939_ircptr->den.r);
__raw_writel(0, &tx4939_ircptr->maskint.r);
__raw_writel(0, &tx4939_ircptr->maskext.r);
for (i = 1; i < TX4939_NUM_IR; i++) {
tx4939irq[i].level = 4;
tx4939irq[i].mode = TXx9_IRCR_LOW;
irq_set_chip_and_handler(TXX9_IRQ_BASE + i, &tx4939_irq_chip,
handle_level_irq);
}
__raw_writel(0, &tx4939_ircptr->msk.r);
for (i = 0; i < 16; i++)
__raw_writel(0, &tx4939_ircptr->lvl[i].r);
for (i = 0; i < 2; i++)
__raw_writel(0, &tx4939_ircptr->dm[i].r);
for (i = 0; i < 2; i++)
__raw_writel(0, &tx4939_ircptr->dm2[i].r);
__raw_writel(TXx9_IRCER_ICE, &tx4939_ircptr->den.r);
__raw_writel(irc_elevel, &tx4939_ircptr->msk.r);
irq_set_chained_handler(MIPS_CPU_IRQ_BASE + TX4939_IRC_INT,
handle_simple_irq);
tx4939_irq_set_pri(TX4939_IR_WTOERR, 7);
tx4939_irq_set_pri(TX4939_IR_PCIERR, 7);
tx4939_irq_set_pri(TX4939_IR_PCIPME, 7);
for (i = 0; i < TX4939_NUM_IR_TMR; i++)
tx4939_irq_set_pri(TX4939_IR_TMR(i), 6);
for (i = 0; i < TX4939_NUM_IR_SIO; i++)
tx4939_irq_set_pri(TX4939_IR_SIO(i), 5);
}
int tx4939_irq(void)
{
u32 csr = __raw_readl(&tx4939_ircptr->cs.r);
if (likely(!(csr & TXx9_IRCSR_IF)))
return TXX9_IRQ_BASE + (csr & (TX4939_NUM_IR - 1));
return -1;
}
