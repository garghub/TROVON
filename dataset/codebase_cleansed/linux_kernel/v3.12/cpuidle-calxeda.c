static noinline void calxeda_idle_restore(void)
{
set_cr(get_cr() | CR_C);
set_auxcr(get_auxcr() | 0x40);
scu_power_mode(scu_base_addr, SCU_PM_NORMAL);
}
static int calxeda_idle_finish(unsigned long val)
{
flush_cache_all();
set_auxcr(get_auxcr() & ~0x40);
set_cr(get_cr() & ~CR_C);
scu_power_mode(scu_base_addr, SCU_PM_DORMANT);
cpu_do_idle();
calxeda_idle_restore();
return 1;
}
static int calxeda_pwrdown_idle(struct cpuidle_device *dev,
struct cpuidle_driver *drv,
int index)
{
highbank_set_cpu_jump(smp_processor_id(), cpu_resume);
cpu_suspend(0, calxeda_idle_finish);
return index;
}
static int __init calxeda_cpuidle_init(void)
{
if (!of_machine_is_compatible("calxeda,highbank"))
return -ENODEV;
return cpuidle_register(&calxeda_idle_driver, NULL);
}
