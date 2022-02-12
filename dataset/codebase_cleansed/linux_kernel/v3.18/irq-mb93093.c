static void frv_fpga_mask(struct irq_data *d)
{
uint16_t imr = __get_IMR();
imr |= 1 << (d->irq - IRQ_BASE_FPGA);
__set_IMR(imr);
}
static void frv_fpga_ack(struct irq_data *d)
{
__clr_IFR(1 << (d->irq - IRQ_BASE_FPGA));
}
static void frv_fpga_mask_ack(struct irq_data *d)
{
uint16_t imr = __get_IMR();
imr |= 1 << (d->irq - IRQ_BASE_FPGA);
__set_IMR(imr);
__clr_IFR(1 << (d->irq - IRQ_BASE_FPGA));
}
static void frv_fpga_unmask(struct irq_data *d)
{
uint16_t imr = __get_IMR();
imr &= ~(1 << (d->irq - IRQ_BASE_FPGA));
__set_IMR(imr);
}
static irqreturn_t fpga_interrupt(int irq, void *_mask)
{
uint16_t imr, mask = (unsigned long) _mask;
imr = __get_IMR();
mask = mask & ~imr & __get_IFR();
while (mask) {
int irq;
asm("scan %1,gr0,%0" : "=r"(irq) : "r"(mask));
irq = 31 - irq;
mask &= ~(1 << irq);
generic_handle_irq(IRQ_BASE_FPGA + irq);
}
return IRQ_HANDLED;
}
void __init fpga_init(void)
{
int irq;
__set_IMR(0x0700);
__clr_IFR(0x0000);
for (irq = IRQ_BASE_FPGA + 8; irq <= IRQ_BASE_FPGA + 10; irq++)
irq_set_chip_and_handler(irq, &frv_fpga_pic, handle_edge_irq);
setup_irq(IRQ_CPU_EXTERNAL2, &fpga_irq[0]);
}
