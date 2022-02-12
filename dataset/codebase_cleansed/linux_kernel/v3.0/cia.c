unsigned char cia_set_irq(struct ciabase *base, unsigned char mask)
{
unsigned char old;
old = (base->icr_data |= base->cia->icr);
if (mask & CIA_ICR_SETCLR)
base->icr_data |= mask;
else
base->icr_data &= ~mask;
if (base->icr_data & base->icr_mask)
amiga_custom.intreq = IF_SETCLR | base->int_mask;
return old & base->icr_mask;
}
unsigned char cia_able_irq(struct ciabase *base, unsigned char mask)
{
unsigned char old;
old = base->icr_mask;
base->icr_data |= base->cia->icr;
base->cia->icr = mask;
if (mask & CIA_ICR_SETCLR)
base->icr_mask |= mask;
else
base->icr_mask &= ~mask;
base->icr_mask &= CIA_ICR_ALL;
if (base->icr_data & base->icr_mask)
amiga_custom.intreq = IF_SETCLR | base->int_mask;
return old;
}
static irqreturn_t cia_handler(int irq, void *dev_id)
{
struct ciabase *base = dev_id;
int mach_irq;
unsigned char ints;
mach_irq = base->cia_irq;
ints = cia_set_irq(base, CIA_ICR_ALL);
amiga_custom.intreq = base->int_mask;
for (; ints; mach_irq++, ints >>= 1) {
if (ints & 1)
m68k_handle_int(mach_irq);
}
return IRQ_HANDLED;
}
static void cia_enable_irq(unsigned int irq)
{
unsigned char mask;
if (irq >= IRQ_AMIGA_CIAB) {
mask = 1 << (irq - IRQ_AMIGA_CIAB);
cia_set_irq(&ciab_base, mask);
cia_able_irq(&ciab_base, CIA_ICR_SETCLR | mask);
} else {
mask = 1 << (irq - IRQ_AMIGA_CIAA);
cia_set_irq(&ciaa_base, mask);
cia_able_irq(&ciaa_base, CIA_ICR_SETCLR | mask);
}
}
static void cia_disable_irq(unsigned int irq)
{
if (irq >= IRQ_AMIGA_CIAB)
cia_able_irq(&ciab_base, 1 << (irq - IRQ_AMIGA_CIAB));
else
cia_able_irq(&ciaa_base, 1 << (irq - IRQ_AMIGA_CIAA));
}
static void auto_enable_irq(unsigned int irq)
{
switch (irq) {
case IRQ_AUTO_2:
amiga_custom.intena = IF_SETCLR | IF_PORTS;
break;
case IRQ_AUTO_6:
amiga_custom.intena = IF_SETCLR | IF_EXTER;
break;
}
}
static void auto_disable_irq(unsigned int irq)
{
switch (irq) {
case IRQ_AUTO_2:
amiga_custom.intena = IF_PORTS;
break;
case IRQ_AUTO_6:
amiga_custom.intena = IF_EXTER;
break;
}
}
void __init cia_init_IRQ(struct ciabase *base)
{
m68k_setup_irq_controller(&cia_irq_controller, base->cia_irq, CIA_IRQS);
cia_set_irq(base, CIA_ICR_ALL);
cia_able_irq(base, CIA_ICR_ALL);
m68k_setup_irq_controller(&auto_irq_controller, base->handler_irq, 1);
m68k_irq_startup(base->handler_irq);
if (request_irq(base->handler_irq, cia_handler, IRQF_SHARED,
base->name, base))
pr_err("Couldn't register %s interrupt\n", base->name);
}
