static void __noreturn gamecube_spin(void)
{
for (;;)
cpu_relax();
}
static void __noreturn gamecube_restart(char *cmd)
{
local_irq_disable();
flipper_platform_reset();
gamecube_spin();
}
static void gamecube_power_off(void)
{
local_irq_disable();
gamecube_spin();
}
static void __noreturn gamecube_halt(void)
{
gamecube_restart(NULL);
}
static int __init gamecube_probe(void)
{
if (!of_machine_is_compatible("nintendo,gamecube"))
return 0;
pm_power_off = gamecube_power_off;
ug_udbg_init();
return 1;
}
static void gamecube_shutdown(void)
{
flipper_quiesce();
}
static int __init gamecube_device_probe(void)
{
if (!machine_is(gamecube))
return 0;
of_platform_bus_probe(NULL, gamecube_of_bus, NULL);
return 0;
}
