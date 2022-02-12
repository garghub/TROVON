static inline void set_interrupt_registers(int ip)
{
unsigned long __dummy;
asm volatile(
#ifdef CONFIG_CPU_HAS_SR_RB
"ldc %2, r6_bank\n\t"
#endif
"stc sr, %0\n\t"
"and #0xf0, %0\n\t"
"shlr2 %0\n\t"
"cmp/eq #0x3c, %0\n\t"
"bt/s 1f ! CLI-ed\n\t"
" stc sr, %0\n\t"
"and %1, %0\n\t"
"or %2, %0\n\t"
"ldc %0, sr\n"
"1:"
: "=&z" (__dummy)
: "r" (~0xf0), "r" (ip << 4)
: "t");
}
static void mask_imask_irq(struct irq_data *data)
{
unsigned int irq = data->irq;
clear_bit(irq, imask_mask);
if (interrupt_priority < IMASK_PRIORITY - irq)
interrupt_priority = IMASK_PRIORITY - irq;
set_interrupt_registers(interrupt_priority);
}
static void unmask_imask_irq(struct irq_data *data)
{
unsigned int irq = data->irq;
set_bit(irq, imask_mask);
interrupt_priority = IMASK_PRIORITY -
find_first_zero_bit(imask_mask, IMASK_PRIORITY);
set_interrupt_registers(interrupt_priority);
}
void make_imask_irq(unsigned int irq)
{
irq_set_chip_and_handler_name(irq, &imask_irq_chip, handle_level_irq,
"level");
}
