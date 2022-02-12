void process_int(int vec, struct pt_regs *fp)
{
int irq;
int mask;
unsigned long pend = ISR;
while (pend) {
if (pend & 0x0000ffff) {
if (pend & 0x000000ff) {
if (pend & 0x0000000f) {
mask = 0x00000001;
irq = 0;
} else {
mask = 0x00000010;
irq = 4;
}
} else {
if (pend & 0x00000f00) {
mask = 0x00000100;
irq = 8;
} else {
mask = 0x00001000;
irq = 12;
}
}
} else {
if (pend & 0x00ff0000) {
if (pend & 0x000f0000) {
mask = 0x00010000;
irq = 16;
} else {
mask = 0x00100000;
irq = 20;
}
} else {
if (pend & 0x0f000000) {
mask = 0x01000000;
irq = 24;
} else {
mask = 0x10000000;
irq = 28;
}
}
}
while (! (mask & pend)) {
mask <<=1;
irq++;
}
do_IRQ(irq, fp);
pend &= ~mask;
}
}
static void intc_irq_unmask(struct irq_data *d)
{
IMR &= ~(1 << d->irq);
}
static void intc_irq_mask(struct irq_data *d)
{
IMR |= (1 << d->irq);
}
void __init trap_init(void)
{
int i;
for (i = 72; i < 256; ++i)
_ramvec[i] = (e_vector) bad_interrupt;
_ramvec[32] = system_call;
_ramvec[65] = (e_vector) inthandler1;
_ramvec[66] = (e_vector) inthandler2;
_ramvec[67] = (e_vector) inthandler3;
_ramvec[68] = (e_vector) inthandler4;
_ramvec[69] = (e_vector) inthandler5;
_ramvec[70] = (e_vector) inthandler6;
_ramvec[71] = (e_vector) inthandler7;
}
void __init init_IRQ(void)
{
int i;
IVR = 0x40;
IMR = ~0;
for (i = 0; (i < NR_IRQS); i++) {
irq_set_chip(i, &intc_irq_chip);
irq_set_handler(i, handle_level_irq);
}
}
