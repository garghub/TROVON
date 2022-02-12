static void icu_mask_irq(struct irq_data *d)
{
uint32_t r = __raw_readl(ICU_INT_CONF(d->irq));
r &= ~ICU_INT_ROUTE_PJ4_IRQ;
__raw_writel(r, ICU_INT_CONF(d->irq));
}
static void icu_unmask_irq(struct irq_data *d)
{
uint32_t r = __raw_readl(ICU_INT_CONF(d->irq));
r |= ICU_INT_ROUTE_PJ4_IRQ;
__raw_writel(r, ICU_INT_CONF(d->irq));
}
static void pmic_irq_ack(struct irq_data *d)
{
if (d->irq == IRQ_MMP2_PMIC)
mmp2_clear_pmic_int();
}
static void init_mux_irq(struct irq_chip *chip, int start, int num)
{
int irq;
for (irq = start; num > 0; irq++, num--) {
struct irq_data *d = irq_get_irq_data(irq);
chip->irq_mask(d);
if (chip->irq_ack)
chip->irq_ack(d);
irq_set_chip(irq, chip);
set_irq_flags(irq, IRQF_VALID);
irq_set_handler(irq, handle_level_irq);
}
}
void __init mmp2_init_icu(void)
{
int irq;
for (irq = 0; irq < IRQ_MMP2_MUX_BASE; irq++) {
icu_mask_irq(irq_get_irq_data(irq));
irq_set_chip(irq, &icu_irq_chip);
set_irq_flags(irq, IRQF_VALID);
switch (irq) {
case IRQ_MMP2_PMIC_MUX:
case IRQ_MMP2_RTC_MUX:
case IRQ_MMP2_TWSI_MUX:
case IRQ_MMP2_MISC_MUX:
case IRQ_MMP2_SSP_MUX:
break;
default:
irq_set_handler(irq, handle_level_irq);
break;
}
}
pmic_irq_chip.irq_ack = pmic_irq_ack;
init_mux_irq(&pmic_irq_chip, IRQ_MMP2_PMIC_BASE, 2);
init_mux_irq(&rtc_irq_chip, IRQ_MMP2_RTC_BASE, 2);
init_mux_irq(&twsi_irq_chip, IRQ_MMP2_TWSI_BASE, 5);
init_mux_irq(&misc_irq_chip, IRQ_MMP2_MISC_BASE, 15);
init_mux_irq(&ssp_irq_chip, IRQ_MMP2_SSP_BASE, 2);
irq_set_chained_handler(IRQ_MMP2_PMIC_MUX, pmic_irq_demux);
irq_set_chained_handler(IRQ_MMP2_RTC_MUX, rtc_irq_demux);
irq_set_chained_handler(IRQ_MMP2_TWSI_MUX, twsi_irq_demux);
irq_set_chained_handler(IRQ_MMP2_MISC_MUX, misc_irq_demux);
irq_set_chained_handler(IRQ_MMP2_SSP_MUX, ssp_irq_demux);
}
