static void enable_intc_irq(struct irq_data *data)
{
unsigned int irq = data->irq;
unsigned long reg;
unsigned long bitmask;
if ((irq <= IRQ_IRL3) && (irlm == NO_PRIORITY))
printk("Trying to use straight IRL0-3 with an encoding platform.\n");
if (irq < 32) {
reg = INTC_INTENB_0;
bitmask = 1 << irq;
} else {
reg = INTC_INTENB_1;
bitmask = 1 << (irq - 32);
}
__raw_writel(bitmask, reg);
}
static void disable_intc_irq(struct irq_data *data)
{
unsigned int irq = data->irq;
unsigned long reg;
unsigned long bitmask;
if (irq < 32) {
reg = INTC_INTDSB_0;
bitmask = 1 << irq;
} else {
reg = INTC_INTDSB_1;
bitmask = 1 << (irq - 32);
}
__raw_writel(bitmask, reg);
}
void __init plat_irq_setup(void)
{
unsigned long long __dummy0, __dummy1=~0x00000000100000f0;
unsigned long reg;
int i;
intc_virt = (unsigned long)ioremap_nocache(INTC_BASE, 1024);
if (!intc_virt) {
panic("Unable to remap INTC\n");
}
for (i = 0; i < NR_INTC_IRQS; i++)
irq_set_chip_and_handler(i, &intc_irq_type, handle_level_irq);
__raw_writel(-1, INTC_INTDSB_0);
__raw_writel(-1, INTC_INTDSB_1);
for (reg = INTC_INTPRI_0, i = 0; i < INTC_INTPRI_PREGS; i++, reg += 8)
__raw_writel( NO_PRIORITY, reg);
#ifdef CONFIG_SH_CAYMAN
{
unsigned long data;
irlm = platform_int_priority[IRQ_IRL0] +
platform_int_priority[IRQ_IRL1] +
platform_int_priority[IRQ_IRL2] +
platform_int_priority[IRQ_IRL3];
if (irlm == NO_PRIORITY) {
reg = INTC_ICR_CLEAR;
i = IRQ_INTA;
printk("Trying to use encoded IRL0-3. IRLs unsupported.\n");
} else {
reg = INTC_ICR_SET;
i = IRQ_IRL0;
}
__raw_writel(INTC_ICR_IRLM, reg);
for (data = 0, reg = INTC_INTPRI_0; i < NR_INTC_IRQS; i++) {
data |= platform_int_priority[i] <<
((i % INTC_INTPRI_PPREG) * 4);
if ((i % INTC_INTPRI_PPREG) == (INTC_INTPRI_PPREG - 1)) {
__raw_writel(data, reg);
data = 0;
reg += 8;
}
}
}
#endif
__asm__ __volatile__("getcon " __SR ", %0\n\t"
"and %0, %1, %0\n\t"
"putcon %0, " __SR "\n\t"
: "=&r" (__dummy0)
: "r" (__dummy1));
}
