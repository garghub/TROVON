static void __init at91eb01_init_irq(void)
{
at91x40_init_interrupts(NULL);
}
static void __init at91eb01_init_early(void)
{
at91x40_initialize(40000000);
}
