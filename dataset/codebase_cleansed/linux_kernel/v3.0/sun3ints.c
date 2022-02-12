void sun3_disable_interrupts(void)
{
sun3_disable_irq(0);
}
void sun3_enable_interrupts(void)
{
sun3_enable_irq(0);
}
void sun3_enable_irq(unsigned int irq)
{
*sun3_intreg |= (1 << irq);
}
void sun3_disable_irq(unsigned int irq)
{
*sun3_intreg &= ~(1 << irq);
}
static irqreturn_t sun3_int7(int irq, void *dev_id)
{
*sun3_intreg |= (1 << irq);
if (!(kstat_cpu(0).irqs[irq] % 2000))
sun3_leds(led_pattern[(kstat_cpu(0).irqs[irq] % 16000) / 2000]);
return IRQ_HANDLED;
}
static irqreturn_t sun3_int5(int irq, void *dev_id)
{
#ifdef CONFIG_SUN3
intersil_clear();
#endif
*sun3_intreg |= (1 << irq);
#ifdef CONFIG_SUN3
intersil_clear();
#endif
xtime_update(1);
update_process_times(user_mode(get_irq_regs()));
if (!(kstat_cpu(0).irqs[irq] % 20))
sun3_leds(led_pattern[(kstat_cpu(0).irqs[irq] % 160) / 20]);
return IRQ_HANDLED;
}
static irqreturn_t sun3_vec255(int irq, void *dev_id)
{
return IRQ_HANDLED;
}
static void sun3_inthandle(unsigned int irq, struct pt_regs *fp)
{
*sun3_intreg &= ~(1 << irq);
__m68k_handle_int(irq, fp);
}
void __init sun3_init_IRQ(void)
{
*sun3_intreg = 1;
m68k_setup_auto_interrupt(sun3_inthandle);
m68k_setup_irq_controller(&sun3_irq_controller, IRQ_AUTO_1, 7);
m68k_setup_user_interrupt(VEC_USER, 128, NULL);
if (request_irq(IRQ_AUTO_5, sun3_int5, 0, "int5", NULL))
pr_err("Couldn't register %s interrupt\n", "int5");
if (request_irq(IRQ_AUTO_7, sun3_int7, 0, "int7", NULL))
pr_err("Couldn't register %s interrupt\n", "int7");
if (request_irq(IRQ_USER+127, sun3_vec255, 0, "vec255", NULL))
pr_err("Couldn't register %s interrupt\n", "vec255");
}
