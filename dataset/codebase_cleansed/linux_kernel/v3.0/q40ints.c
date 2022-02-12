static int q40_irq_startup(unsigned int irq)
{
switch (irq) {
case 1: case 2: case 8: case 9:
case 11: case 12: case 13:
printk("%s: ISA IRQ %d not implemented by HW\n", __func__, irq);
return -ENXIO;
}
return 0;
}
static void q40_irq_shutdown(unsigned int irq)
{
}
void __init q40_init_IRQ(void)
{
m68k_setup_irq_controller(&q40_irq_controller, 1, Q40_IRQ_MAX);
m68k_setup_auto_interrupt(q40_irq_handler);
m68k_irq_startup(IRQ_AUTO_2);
m68k_irq_startup(IRQ_AUTO_4);
master_outb(1, EXT_ENABLE_REG);
master_outb(0, KEY_IRQ_ENABLE_REG);
}
void q40_mksound(unsigned int hz, unsigned int ticks)
{
if (hz == 0) {
if (sound_ticks)
sound_ticks = 1;
*DAC_LEFT = 128;
*DAC_RIGHT = 128;
return;
}
if (sound_ticks == 0)
sound_ticks = 1000;
sound_ticks = ticks << 1;
}
static irqreturn_t q40_timer_int (int irq, void * dev)
{
ql_ticks = ql_ticks ? 0 : 1;
if (sound_ticks) {
unsigned char sval=(sound_ticks & 1) ? 128-SVOL : 128+SVOL;
sound_ticks--;
*DAC_LEFT=sval;
*DAC_RIGHT=sval;
}
if (!ql_ticks)
q40_timer_routine(irq, dev);
return IRQ_HANDLED;
}
void q40_sched_init (irq_handler_t timer_routine)
{
int timer_irq;
q40_timer_routine = timer_routine;
timer_irq = Q40_IRQ_FRAME;
if (request_irq(timer_irq, q40_timer_int, 0,
"timer", q40_timer_int))
panic("Couldn't register timer int");
master_outb(-1, FRAME_CLEAR_REG);
master_outb( 1, FRAME_RATE_REG);
}
static void q40_irq_handler(unsigned int irq, struct pt_regs *fp)
{
unsigned mir, mer;
int i;
mir = master_inb(IIRQ_REG);
#ifdef CONFIG_BLK_DEV_FD
if ((mir & Q40_IRQ_EXT_MASK) &&
(master_inb(EIRQ_REG) & Q40_IRQ6_MASK)) {
floppy_hardint();
return;
}
#endif
switch (irq) {
case 4:
case 6:
__m68k_handle_int(Q40_IRQ_SAMPLE, fp);
return;
}
if (mir & Q40_IRQ_FRAME_MASK) {
__m68k_handle_int(Q40_IRQ_FRAME, fp);
master_outb(-1, FRAME_CLEAR_REG);
}
if ((mir & Q40_IRQ_SER_MASK) || (mir & Q40_IRQ_EXT_MASK)) {
mer = master_inb(EIRQ_REG);
for (i = 0; eirqs[i].mask; i++) {
if (mer & eirqs[i].mask) {
irq = eirqs[i].irq;
if (irq > 4 && irq <= 15 && mext_disabled) {
goto iirq;
}
if (q40_state[irq] & IRQ_INPROGRESS) {
#ifdef IP_USE_DISABLE
disable_irq(irq);
disabled = 1;
#else
fp->sr = (((fp->sr) & (~0x700))+0x200);
disabled = 1;
#endif
goto iirq;
}
q40_state[irq] |= IRQ_INPROGRESS;
__m68k_handle_int(irq, fp);
q40_state[irq] &= ~IRQ_INPROGRESS;
if (disabled) {
#ifdef IP_USE_DISABLE
if (irq > 4) {
disabled = 0;
enable_irq(irq);
}
#else
disabled = 0;
#endif
}
return;
}
}
if (mer && ccleirq > 0 && !aliased_irq) {
printk("ISA interrupt from unknown source? EIRQ_REG = %x\n",mer);
ccleirq--;
}
}
iirq:
mir = master_inb(IIRQ_REG);
if (mir & Q40_IRQ_KEYB_MASK)
__m68k_handle_int(Q40_IRQ_KEYBOARD, fp);
return;
}
void q40_enable_irq(unsigned int irq)
{
if (irq >= 5 && irq <= 15) {
mext_disabled--;
if (mext_disabled > 0)
printk("q40_enable_irq : nested disable/enable\n");
if (mext_disabled == 0)
master_outb(1, EXT_ENABLE_REG);
}
}
void q40_disable_irq(unsigned int irq)
{
if (irq >= 5 && irq <= 15) {
master_outb(0, EXT_ENABLE_REG);
mext_disabled++;
if (mext_disabled > 1)
printk("disable_irq nesting count %d\n",mext_disabled);
}
}
unsigned long q40_probe_irq_on(void)
{
printk("irq probing not working - reconfigure the driver to avoid this\n");
return -1;
}
int q40_probe_irq_off(unsigned long irqs)
{
return -1;
}
