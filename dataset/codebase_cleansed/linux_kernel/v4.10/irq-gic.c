int get_c0_perfcount_int(void)
{
return gic_get_c0_perfcount_int();
}
void __init arch_init_irq(void)
{
irqchip_init();
}
