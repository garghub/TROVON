static void
s3c2412_irq_mask(struct irq_data *data)
{
unsigned long bitval = 1UL << (data->irq - IRQ_EINT0);
unsigned long mask;
mask = __raw_readl(S3C2410_INTMSK);
__raw_writel(mask | bitval, S3C2410_INTMSK);
mask = __raw_readl(S3C2412_EINTMASK);
__raw_writel(mask | bitval, S3C2412_EINTMASK);
}
static inline void
s3c2412_irq_ack(struct irq_data *data)
{
unsigned long bitval = 1UL << (data->irq - IRQ_EINT0);
__raw_writel(bitval, S3C2412_EINTPEND);
__raw_writel(bitval, S3C2410_SRCPND);
__raw_writel(bitval, S3C2410_INTPND);
}
static inline void
s3c2412_irq_maskack(struct irq_data *data)
{
unsigned long bitval = 1UL << (data->irq - IRQ_EINT0);
unsigned long mask;
mask = __raw_readl(S3C2410_INTMSK);
__raw_writel(mask|bitval, S3C2410_INTMSK);
mask = __raw_readl(S3C2412_EINTMASK);
__raw_writel(mask | bitval, S3C2412_EINTMASK);
__raw_writel(bitval, S3C2412_EINTPEND);
__raw_writel(bitval, S3C2410_SRCPND);
__raw_writel(bitval, S3C2410_INTPND);
}
static void
s3c2412_irq_unmask(struct irq_data *data)
{
unsigned long bitval = 1UL << (data->irq - IRQ_EINT0);
unsigned long mask;
mask = __raw_readl(S3C2412_EINTMASK);
__raw_writel(mask & ~bitval, S3C2412_EINTMASK);
mask = __raw_readl(S3C2410_INTMSK);
__raw_writel(mask & ~bitval, S3C2410_INTMSK);
}
static void s3c2412_irq_demux_cfsdi(unsigned int irq, struct irq_desc *desc)
{
unsigned int subsrc, submsk;
subsrc = __raw_readl(S3C2410_SUBSRCPND);
submsk = __raw_readl(S3C2410_INTSUBMSK);
subsrc &= ~submsk;
if (subsrc & INTBIT(IRQ_S3C2412_SDI))
generic_handle_irq(IRQ_S3C2412_SDI);
if (subsrc & INTBIT(IRQ_S3C2412_CF))
generic_handle_irq(IRQ_S3C2412_CF);
}
static void s3c2412_irq_cfsdi_mask(struct irq_data *data)
{
s3c_irqsub_mask(data->irq, INTMSK_CFSDI, SUBMSK_CFSDI);
}
static void s3c2412_irq_cfsdi_unmask(struct irq_data *data)
{
s3c_irqsub_unmask(data->irq, INTMSK_CFSDI);
}
static void s3c2412_irq_cfsdi_ack(struct irq_data *data)
{
s3c_irqsub_maskack(data->irq, INTMSK_CFSDI, SUBMSK_CFSDI);
}
static int s3c2412_irq_rtc_wake(struct irq_data *data, unsigned int state)
{
unsigned long pwrcfg;
pwrcfg = __raw_readl(S3C2412_PWRCFG);
if (state)
pwrcfg &= ~S3C2412_PWRCFG_RTC_MASKIRQ;
else
pwrcfg |= S3C2412_PWRCFG_RTC_MASKIRQ;
__raw_writel(pwrcfg, S3C2412_PWRCFG);
return s3c_irq_chip.irq_set_wake(data, state);
}
static int s3c2412_irq_add(struct device *dev, struct subsys_interface *sif)
{
unsigned int irqno;
for (irqno = IRQ_EINT0; irqno <= IRQ_EINT3; irqno++) {
irq_set_chip_and_handler(irqno, &s3c2412_irq_eint0t4,
handle_edge_irq);
set_irq_flags(irqno, IRQF_VALID);
}
irq_set_chained_handler(IRQ_S3C2412_CFSDI, s3c2412_irq_demux_cfsdi);
for (irqno = IRQ_S3C2412_SDI; irqno <= IRQ_S3C2412_CF; irqno++) {
irq_set_chip_and_handler(irqno, &s3c2412_irq_cfsdi,
handle_level_irq);
set_irq_flags(irqno, IRQF_VALID);
}
s3c2412_irq_rtc_chip = s3c_irq_chip;
s3c2412_irq_rtc_chip.irq_set_wake = s3c2412_irq_rtc_wake;
irq_set_chip(IRQ_RTC, &s3c2412_irq_rtc_chip);
return 0;
}
static int s3c2412_irq_init(void)
{
return subsys_interface_register(&s3c2412_irq_interface);
}
