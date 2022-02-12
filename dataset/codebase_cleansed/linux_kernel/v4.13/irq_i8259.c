static inline void
i8259_update_irq_hw(unsigned int irq, unsigned long mask)
{
int port = 0x21;
if (irq & 8) mask >>= 8;
if (irq & 8) port = 0xA1;
outb(mask, port);
}
inline void
i8259a_enable_irq(struct irq_data *d)
{
spin_lock(&i8259_irq_lock);
i8259_update_irq_hw(d->irq, cached_irq_mask &= ~(1 << d->irq));
spin_unlock(&i8259_irq_lock);
}
static inline void
__i8259a_disable_irq(unsigned int irq)
{
i8259_update_irq_hw(irq, cached_irq_mask |= 1 << irq);
}
void
i8259a_disable_irq(struct irq_data *d)
{
spin_lock(&i8259_irq_lock);
__i8259a_disable_irq(d->irq);
spin_unlock(&i8259_irq_lock);
}
void
i8259a_mask_and_ack_irq(struct irq_data *d)
{
unsigned int irq = d->irq;
spin_lock(&i8259_irq_lock);
__i8259a_disable_irq(irq);
if (irq >= 8) {
outb(0xE0 | (irq - 8), 0xa0);
irq = 2;
}
outb(0xE0 | irq, 0x20);
spin_unlock(&i8259_irq_lock);
}
void __init
init_i8259a_irqs(void)
{
static struct irqaction cascade = {
.handler = no_action,
.name = "cascade",
};
long i;
outb(0xff, 0x21);
outb(0xff, 0xA1);
for (i = 0; i < 16; i++) {
irq_set_chip_and_handler(i, &i8259a_irq_type, handle_level_irq);
}
setup_irq(2, &cascade);
}
void
isa_device_interrupt(unsigned long vector)
{
int j = *(vuip) IACK_SC;
j &= 0xff;
handle_irq(j);
}
void
isa_no_iack_sc_device_interrupt(unsigned long vector)
{
unsigned long pic;
pic = inb(0x20) | (inb(0xA0) << 8);
pic &= 0xFFFB;
while (pic) {
int j = ffz(~pic);
pic &= pic - 1;
handle_irq(j);
}
}
