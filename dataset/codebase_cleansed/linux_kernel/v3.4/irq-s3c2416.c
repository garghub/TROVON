static inline void s3c2416_irq_demux(unsigned int irq, unsigned int len)
{
unsigned int subsrc, submsk;
unsigned int end;
subsrc = __raw_readl(S3C2410_SUBSRCPND);
submsk = __raw_readl(S3C2410_INTSUBMSK);
subsrc &= ~submsk;
subsrc >>= (irq - S3C2410_IRQSUB(0));
subsrc &= (1 << len)-1;
end = len + irq;
for (; irq < end && subsrc; irq++) {
if (subsrc & 1)
generic_handle_irq(irq);
subsrc >>= 1;
}
}
static void s3c2416_irq_demux_wdtac97(unsigned int irq, struct irq_desc *desc)
{
s3c2416_irq_demux(IRQ_S3C2443_WDT, 4);
}
static void s3c2416_irq_wdtac97_mask(struct irq_data *data)
{
s3c_irqsub_mask(data->irq, INTMSK_WDTAC97, SUBMSK_WDTAC97);
}
static void s3c2416_irq_wdtac97_unmask(struct irq_data *data)
{
s3c_irqsub_unmask(data->irq, INTMSK_WDTAC97);
}
static void s3c2416_irq_wdtac97_ack(struct irq_data *data)
{
s3c_irqsub_maskack(data->irq, INTMSK_WDTAC97, SUBMSK_WDTAC97);
}
static void s3c2416_irq_demux_lcd(unsigned int irq, struct irq_desc *desc)
{
s3c2416_irq_demux(IRQ_S3C2443_LCD1, 4);
}
static void s3c2416_irq_lcd_mask(struct irq_data *data)
{
s3c_irqsub_mask(data->irq, INTMSK_LCD, SUBMSK_LCD);
}
static void s3c2416_irq_lcd_unmask(struct irq_data *data)
{
s3c_irqsub_unmask(data->irq, INTMSK_LCD);
}
static void s3c2416_irq_lcd_ack(struct irq_data *data)
{
s3c_irqsub_maskack(data->irq, INTMSK_LCD, SUBMSK_LCD);
}
static void s3c2416_irq_demux_dma(unsigned int irq, struct irq_desc *desc)
{
s3c2416_irq_demux(IRQ_S3C2443_DMA0, 6);
}
static void s3c2416_irq_dma_mask(struct irq_data *data)
{
s3c_irqsub_mask(data->irq, INTMSK_DMA, SUBMSK_DMA);
}
static void s3c2416_irq_dma_unmask(struct irq_data *data)
{
s3c_irqsub_unmask(data->irq, INTMSK_DMA);
}
static void s3c2416_irq_dma_ack(struct irq_data *data)
{
s3c_irqsub_maskack(data->irq, INTMSK_DMA, SUBMSK_DMA);
}
static void s3c2416_irq_demux_uart3(unsigned int irq, struct irq_desc *desc)
{
s3c2416_irq_demux(IRQ_S3C2443_RX3, 3);
}
static void s3c2416_irq_uart3_mask(struct irq_data *data)
{
s3c_irqsub_mask(data->irq, INTMSK_UART3, SUBMSK_UART3);
}
static void s3c2416_irq_uart3_unmask(struct irq_data *data)
{
s3c_irqsub_unmask(data->irq, INTMSK_UART3);
}
static void s3c2416_irq_uart3_ack(struct irq_data *data)
{
s3c_irqsub_maskack(data->irq, INTMSK_UART3, SUBMSK_UART3);
}
static int __init s3c2416_add_sub(unsigned int base,
void (*demux)(unsigned int,
struct irq_desc *),
struct irq_chip *chip,
unsigned int start, unsigned int end)
{
unsigned int irqno;
irq_set_chip_and_handler(base, &s3c_irq_level_chip, handle_level_irq);
irq_set_chained_handler(base, demux);
for (irqno = start; irqno <= end; irqno++) {
irq_set_chip_and_handler(irqno, chip, handle_level_irq);
set_irq_flags(irqno, IRQF_VALID);
}
return 0;
}
static int __init s3c2416_irq_add(struct device *dev,
struct subsys_interface *sif)
{
printk(KERN_INFO "S3C2416: IRQ Support\n");
s3c2416_add_sub(IRQ_LCD, s3c2416_irq_demux_lcd, &s3c2416_irq_lcd,
IRQ_S3C2443_LCD2, IRQ_S3C2443_LCD4);
s3c2416_add_sub(IRQ_S3C2443_DMA, s3c2416_irq_demux_dma,
&s3c2416_irq_dma, IRQ_S3C2443_DMA0, IRQ_S3C2443_DMA5);
s3c2416_add_sub(IRQ_S3C2443_UART3, s3c2416_irq_demux_uart3,
&s3c2416_irq_uart3,
IRQ_S3C2443_RX3, IRQ_S3C2443_ERR3);
s3c2416_add_sub(IRQ_WDT, s3c2416_irq_demux_wdtac97,
&s3c2416_irq_wdtac97,
IRQ_S3C2443_WDT, IRQ_S3C2443_AC97);
return 0;
}
static int __init s3c2416_irq_init(void)
{
return subsys_interface_register(&s3c2416_irq_interface);
}
