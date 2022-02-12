static void s3c_irq_demux_wdtac97(unsigned int irq,
struct irq_desc *desc)
{
unsigned int subsrc, submsk;
subsrc = __raw_readl(S3C2410_SUBSRCPND);
submsk = __raw_readl(S3C2410_INTSUBMSK);
subsrc &= ~submsk;
subsrc >>= 13;
subsrc &= 3;
if (subsrc != 0) {
if (subsrc & 1) {
generic_handle_irq(IRQ_S3C2440_WDT);
}
if (subsrc & 2) {
generic_handle_irq(IRQ_S3C2440_AC97);
}
}
}
static void
s3c_irq_wdtac97_mask(struct irq_data *data)
{
s3c_irqsub_mask(data->irq, INTMSK_WDT, 3 << 13);
}
static void
s3c_irq_wdtac97_unmask(struct irq_data *data)
{
s3c_irqsub_unmask(data->irq, INTMSK_WDT);
}
static void
s3c_irq_wdtac97_ack(struct irq_data *data)
{
s3c_irqsub_maskack(data->irq, INTMSK_WDT, 3 << 13);
}
static int s3c2440_irq_add(struct device *dev, struct subsys_interface *sif)
{
unsigned int irqno;
printk("S3C2440: IRQ Support\n");
irq_set_chip_and_handler(IRQ_WDT, &s3c_irq_level_chip,
handle_level_irq);
irq_set_chained_handler(IRQ_WDT, s3c_irq_demux_wdtac97);
for (irqno = IRQ_S3C2440_WDT; irqno <= IRQ_S3C2440_AC97; irqno++) {
irq_set_chip_and_handler(irqno, &s3c_irq_wdtac97,
handle_level_irq);
set_irq_flags(irqno, IRQF_VALID);
}
return 0;
}
static int s3c2440_irq_init(void)
{
return subsys_interface_register(&s3c2440_irq_interface);
}
