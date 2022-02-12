void __init s5p_init_irq(u32 *vic, u32 num_vic)
{
#ifdef CONFIG_ARM_VIC
int irq;
for (irq = 0; irq < num_vic; irq++)
vic_init(VA_VIC(irq), VIC_BASE(irq), vic[irq], 0);
#endif
s3c_init_vic_timer_irq(5, IRQ_TIMER0);
}
