static void s3c_irq_demux_cam(unsigned int irq,
struct irq_desc *desc)
{
unsigned int subsrc, submsk;
subsrc = __raw_readl(S3C2410_SUBSRCPND);
submsk = __raw_readl(S3C2410_INTSUBMSK);
subsrc &= ~submsk;
subsrc >>= 11;
subsrc &= 3;
if (subsrc != 0) {
if (subsrc & 1) {
generic_handle_irq(IRQ_S3C2440_CAM_C);
}
if (subsrc & 2) {
generic_handle_irq(IRQ_S3C2440_CAM_P);
}
}
}
static void
s3c_irq_cam_mask(struct irq_data *data)
{
s3c_irqsub_mask(data->irq, INTMSK_CAM, 3 << 11);
}
static void
s3c_irq_cam_unmask(struct irq_data *data)
{
s3c_irqsub_unmask(data->irq, INTMSK_CAM);
}
static void
s3c_irq_cam_ack(struct irq_data *data)
{
s3c_irqsub_maskack(data->irq, INTMSK_CAM, 3 << 11);
}
static int s3c244x_irq_add(struct device *dev, struct subsys_interface *sif)
{
unsigned int irqno;
irq_set_chip_and_handler(IRQ_NFCON, &s3c_irq_level_chip,
handle_level_irq);
set_irq_flags(IRQ_NFCON, IRQF_VALID);
irq_set_chip_and_handler(IRQ_CAM, &s3c_irq_level_chip,
handle_level_irq);
irq_set_chained_handler(IRQ_CAM, s3c_irq_demux_cam);
for (irqno = IRQ_S3C2440_CAM_C; irqno <= IRQ_S3C2440_CAM_P; irqno++) {
irq_set_chip_and_handler(irqno, &s3c_irq_cam,
handle_level_irq);
set_irq_flags(irqno, IRQF_VALID);
}
return 0;
}
static int s3c2440_irq_init(void)
{
return subsys_interface_register(&s3c2440_irq_interface);
}
static int s3c2442_irq_init(void)
{
return subsys_interface_register(&s3c2442_irq_interface);
}
