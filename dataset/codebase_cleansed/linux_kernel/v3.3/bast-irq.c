static void
bast_pc104_mask(struct irq_data *data)
{
unsigned long temp;
temp = __raw_readb(BAST_VA_PC104_IRQMASK);
temp &= ~bast_pc104_irqmasks[data->irq];
__raw_writeb(temp, BAST_VA_PC104_IRQMASK);
}
static void
bast_pc104_maskack(struct irq_data *data)
{
struct irq_desc *desc = irq_desc + IRQ_ISA;
bast_pc104_mask(data);
desc->irq_data.chip->irq_ack(&desc->irq_data);
}
static void
bast_pc104_unmask(struct irq_data *data)
{
unsigned long temp;
temp = __raw_readb(BAST_VA_PC104_IRQMASK);
temp |= bast_pc104_irqmasks[data->irq];
__raw_writeb(temp, BAST_VA_PC104_IRQMASK);
}
static void
bast_irq_pc104_demux(unsigned int irq,
struct irq_desc *desc)
{
unsigned int stat;
unsigned int irqno;
int i;
stat = __raw_readb(BAST_VA_PC104_IRQREQ) & 0xf;
if (unlikely(stat == 0)) {
desc = irq_desc + IRQ_ISA;
desc->irq_data.chip->irq_ack(&desc->irq_data);
} else {
for (i = 0; stat != 0; i++, stat >>= 1) {
if (stat & 1) {
irqno = bast_pc104_irqs[i];
generic_handle_irq(irqno);
}
}
}
}
static __init int bast_irq_init(void)
{
unsigned int i;
if (machine_is_bast()) {
printk(KERN_INFO "BAST PC104 IRQ routing, Copyright 2005 Simtec Electronics\n");
__raw_writeb(0x0, BAST_VA_PC104_IRQMASK);
irq_set_chained_handler(IRQ_ISA, bast_irq_pc104_demux);
for (i = 0; i < 4; i++) {
unsigned int irqno = bast_pc104_irqs[i];
irq_set_chip_and_handler(irqno, &bast_pc104_chip,
handle_level_irq);
set_irq_flags(irqno, IRQF_VALID);
}
}
return 0;
}
