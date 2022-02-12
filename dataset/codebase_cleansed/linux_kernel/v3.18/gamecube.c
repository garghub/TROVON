static void gamecube_spin(void)
{
for (;;)
cpu_relax();
}
static void gamecube_restart(char *cmd)
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
static void gamecube_halt(void)
{
gamecube_restart(NULL);
}
static void __init gamecube_init_early(void)
{
ug_udbg_init();
}
static int __init gamecube_probe(void)
{
unsigned long dt_root;
dt_root = of_get_flat_dt_root();
if (!of_flat_dt_is_compatible(dt_root, "nintendo,gamecube"))
return 0;
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
