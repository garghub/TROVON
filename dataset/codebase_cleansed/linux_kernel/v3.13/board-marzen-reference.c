static void __init marzen_init(void)
{
r8a7779_add_standard_devices_dt();
r8a7779_init_irq_extpin_dt(1);
}
