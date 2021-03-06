static void enable_local0_irq(struct irq_data *d)
{
if (d->irq != SGI_MAP_0_IRQ)
sgint->imask0 |= (1 << (d->irq - SGINT_LOCAL0));
}
static void disable_local0_irq(struct irq_data *d)
{
sgint->imask0 &= ~(1 << (d->irq - SGINT_LOCAL0));
}
static void enable_local1_irq(struct irq_data *d)
{
if (d->irq != SGI_MAP_1_IRQ)
sgint->imask1 |= (1 << (d->irq - SGINT_LOCAL1));
}
static void disable_local1_irq(struct irq_data *d)
{
sgint->imask1 &= ~(1 << (d->irq - SGINT_LOCAL1));
}
static void enable_local2_irq(struct irq_data *d)
{
sgint->imask0 |= (1 << (SGI_MAP_0_IRQ - SGINT_LOCAL0));
sgint->cmeimask0 |= (1 << (d->irq - SGINT_LOCAL2));
}
static void disable_local2_irq(struct irq_data *d)
{
sgint->cmeimask0 &= ~(1 << (d->irq - SGINT_LOCAL2));
if (!sgint->cmeimask0)
sgint->imask0 &= ~(1 << (SGI_MAP_0_IRQ - SGINT_LOCAL0));
}
static void enable_local3_irq(struct irq_data *d)
{
sgint->imask1 |= (1 << (SGI_MAP_1_IRQ - SGINT_LOCAL1));
sgint->cmeimask1 |= (1 << (d->irq - SGINT_LOCAL3));
}
static void disable_local3_irq(struct irq_data *d)
{
sgint->cmeimask1 &= ~(1 << (d->irq - SGINT_LOCAL3));
if (!sgint->cmeimask1)
sgint->imask1 &= ~(1 << (SGI_MAP_1_IRQ - SGINT_LOCAL1));
}
static void indy_local0_irqdispatch(void)
{
u8 mask = sgint->istat0 & sgint->imask0;
u8 mask2;
int irq;
if (mask & SGINT_ISTAT0_LIO2) {
mask2 = sgint->vmeistat & sgint->cmeimask0;
irq = lc2msk_to_irqnr[mask2];
} else
irq = lc0msk_to_irqnr[mask];
if (irq)
do_IRQ(irq);
else
do_IRQ(SGINT_LOCAL0 + 0);
}
static void indy_local1_irqdispatch(void)
{
u8 mask = sgint->istat1 & sgint->imask1;
u8 mask2;
int irq;
if (mask & SGINT_ISTAT1_LIO3) {
mask2 = sgint->vmeistat & sgint->cmeimask1;
irq = lc3msk_to_irqnr[mask2];
} else
irq = lc1msk_to_irqnr[mask];
if (irq)
do_IRQ(irq);
}
static void __irq_entry indy_buserror_irq(void)
{
int irq = SGI_BUSERR_IRQ;
irq_enter();
kstat_incr_irq_this_cpu(irq);
ip22_be_interrupt(irq);
irq_exit();
}
asmlinkage void plat_irq_dispatch(void)
{
unsigned int pending = read_c0_status() & read_c0_cause();
if (pending & CAUSEF_IP7)
do_IRQ(SGI_TIMER_IRQ);
else if (pending & CAUSEF_IP2)
indy_local0_irqdispatch();
else if (pending & CAUSEF_IP3)
indy_local1_irqdispatch();
else if (pending & CAUSEF_IP6)
indy_buserror_irq();
else if (pending & (CAUSEF_IP4 | CAUSEF_IP5))
indy_8254timer_irq();
}
void __init arch_init_irq(void)
{
int i;
for (i = 0; i < 256; i++) {
if (i & 0x80) {
lc0msk_to_irqnr[i] = SGINT_LOCAL0 + 7;
lc1msk_to_irqnr[i] = SGINT_LOCAL1 + 7;
lc2msk_to_irqnr[i] = SGINT_LOCAL2 + 7;
lc3msk_to_irqnr[i] = SGINT_LOCAL3 + 7;
} else if (i & 0x40) {
lc0msk_to_irqnr[i] = SGINT_LOCAL0 + 6;
lc1msk_to_irqnr[i] = SGINT_LOCAL1 + 6;
lc2msk_to_irqnr[i] = SGINT_LOCAL2 + 6;
lc3msk_to_irqnr[i] = SGINT_LOCAL3 + 6;
} else if (i & 0x20) {
lc0msk_to_irqnr[i] = SGINT_LOCAL0 + 5;
lc1msk_to_irqnr[i] = SGINT_LOCAL1 + 5;
lc2msk_to_irqnr[i] = SGINT_LOCAL2 + 5;
lc3msk_to_irqnr[i] = SGINT_LOCAL3 + 5;
} else if (i & 0x10) {
lc0msk_to_irqnr[i] = SGINT_LOCAL0 + 4;
lc1msk_to_irqnr[i] = SGINT_LOCAL1 + 4;
lc2msk_to_irqnr[i] = SGINT_LOCAL2 + 4;
lc3msk_to_irqnr[i] = SGINT_LOCAL3 + 4;
} else if (i & 0x08) {
lc0msk_to_irqnr[i] = SGINT_LOCAL0 + 3;
lc1msk_to_irqnr[i] = SGINT_LOCAL1 + 3;
lc2msk_to_irqnr[i] = SGINT_LOCAL2 + 3;
lc3msk_to_irqnr[i] = SGINT_LOCAL3 + 3;
} else if (i & 0x04) {
lc0msk_to_irqnr[i] = SGINT_LOCAL0 + 2;
lc1msk_to_irqnr[i] = SGINT_LOCAL1 + 2;
lc2msk_to_irqnr[i] = SGINT_LOCAL2 + 2;
lc3msk_to_irqnr[i] = SGINT_LOCAL3 + 2;
} else if (i & 0x02) {
lc0msk_to_irqnr[i] = SGINT_LOCAL0 + 1;
lc1msk_to_irqnr[i] = SGINT_LOCAL1 + 1;
lc2msk_to_irqnr[i] = SGINT_LOCAL2 + 1;
lc3msk_to_irqnr[i] = SGINT_LOCAL3 + 1;
} else if (i & 0x01) {
lc0msk_to_irqnr[i] = SGINT_LOCAL0 + 0;
lc1msk_to_irqnr[i] = SGINT_LOCAL1 + 0;
lc2msk_to_irqnr[i] = SGINT_LOCAL2 + 0;
lc3msk_to_irqnr[i] = SGINT_LOCAL3 + 0;
} else {
lc0msk_to_irqnr[i] = 0;
lc1msk_to_irqnr[i] = 0;
lc2msk_to_irqnr[i] = 0;
lc3msk_to_irqnr[i] = 0;
}
}
sgint->imask0 = 0;
sgint->imask1 = 0;
sgint->cmeimask0 = 0;
sgint->cmeimask1 = 0;
mips_cpu_irq_init();
for (i = SGINT_LOCAL0; i < SGI_INTERRUPTS; i++) {
struct irq_chip *handler;
if (i < SGINT_LOCAL1)
handler = &ip22_local0_irq_type;
else if (i < SGINT_LOCAL2)
handler = &ip22_local1_irq_type;
else if (i < SGINT_LOCAL3)
handler = &ip22_local2_irq_type;
else
handler = &ip22_local3_irq_type;
irq_set_chip_and_handler(i, handler, handle_level_irq);
}
setup_irq(SGI_LOCAL_0_IRQ, &local0_cascade);
setup_irq(SGI_LOCAL_1_IRQ, &local1_cascade);
setup_irq(SGI_BUSERR_IRQ, &buserr);
setup_irq(SGI_MAP_0_IRQ, &map0_cascade);
#ifdef USE_LIO3_IRQ
setup_irq(SGI_MAP_1_IRQ, &map1_cascade);
#endif
#ifdef CONFIG_EISA
if (ip22_is_fullhouse())
ip22_eisa_init();
#endif
}
