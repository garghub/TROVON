static void isa_mask_pic_lo_irq(struct irq_data *d)
{
unsigned int mask = 1 << (d->irq & 7);
outb(inb(PIC_MASK_LO) | mask, PIC_MASK_LO);
}
static void isa_ack_pic_lo_irq(struct irq_data *d)
{
unsigned int mask = 1 << (d->irq & 7);
outb(inb(PIC_MASK_LO) | mask, PIC_MASK_LO);
outb(0x20, PIC_LO);
}
static void isa_unmask_pic_lo_irq(struct irq_data *d)
{
unsigned int mask = 1 << (d->irq & 7);
outb(inb(PIC_MASK_LO) & ~mask, PIC_MASK_LO);
}
static void isa_mask_pic_hi_irq(struct irq_data *d)
{
unsigned int mask = 1 << (d->irq & 7);
outb(inb(PIC_MASK_HI) | mask, PIC_MASK_HI);
}
static void isa_ack_pic_hi_irq(struct irq_data *d)
{
unsigned int mask = 1 << (d->irq & 7);
outb(inb(PIC_MASK_HI) | mask, PIC_MASK_HI);
outb(0x62, PIC_LO);
outb(0x20, PIC_HI);
}
static void isa_unmask_pic_hi_irq(struct irq_data *d)
{
unsigned int mask = 1 << (d->irq & 7);
outb(inb(PIC_MASK_HI) & ~mask, PIC_MASK_HI);
}
static void
isa_irq_handler(unsigned int irq, struct irq_desc *desc)
{
unsigned int isa_irq = *(unsigned char *)PCIIACK_BASE;
if (isa_irq < _ISA_IRQ(0) || isa_irq >= _ISA_IRQ(16)) {
do_bad_IRQ(isa_irq, desc);
return;
}
generic_handle_irq(isa_irq);
}
void __init isa_init_irq(unsigned int host_irq)
{
unsigned int irq;
outb(0x11, PIC_LO);
outb(_ISA_IRQ(0), PIC_MASK_LO);
outb(0x04, PIC_MASK_LO);
outb(0x01, PIC_MASK_LO);
outb(0xf5, PIC_MASK_LO);
outb(0x11, PIC_HI);
outb(_ISA_IRQ(8), PIC_MASK_HI);
outb(0x02, PIC_MASK_HI);
outb(0x01, PIC_MASK_HI);
outb(0xfa, PIC_MASK_HI);
outb(0x0b, PIC_LO);
outb(0x0b, PIC_HI);
if (inb(PIC_MASK_LO) == 0xf5 && inb(PIC_MASK_HI) == 0xfa) {
outb(0xff, PIC_MASK_LO);
outb(0xff, PIC_MASK_HI);
} else {
printk(KERN_INFO "IRQ: ISA PIC not found\n");
host_irq = (unsigned int)-1;
}
if (host_irq != (unsigned int)-1) {
for (irq = _ISA_IRQ(0); irq < _ISA_IRQ(8); irq++) {
irq_set_chip_and_handler(irq, &isa_lo_chip,
handle_level_irq);
set_irq_flags(irq, IRQF_VALID | IRQF_PROBE);
}
for (irq = _ISA_IRQ(8); irq < _ISA_IRQ(16); irq++) {
irq_set_chip_and_handler(irq, &isa_hi_chip,
handle_level_irq);
set_irq_flags(irq, IRQF_VALID | IRQF_PROBE);
}
request_resource(&ioport_resource, &pic1_resource);
request_resource(&ioport_resource, &pic2_resource);
setup_irq(IRQ_ISA_CASCADE, &irq_cascade);
irq_set_chained_handler(host_irq, isa_irq_handler);
if (machine_is_netwinder())
set_irq_flags(_ISA_IRQ(11), IRQF_VALID |
IRQF_PROBE | IRQF_NOAUTOEN);
}
}
