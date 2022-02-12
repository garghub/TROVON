static inline unsigned int get_auxcr(void)
{
unsigned int val;
asm("mrc p15, 0, %0, c1, c0, 1 @ get AUXCR" : "=r" (val) : : "cc");
return val;
}
static inline void set_auxcr(unsigned int val)
{
asm volatile("mcr p15, 0, %0, c1, c0, 1 @ set AUXCR"
: : "r" (val) : "cc");
isb();
}
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
static void calxeda_idle_cpuidle_devices_uninit(void)
{
int i;
struct cpuidle_device *dev;
for_each_possible_cpu(i) {
dev = per_cpu_ptr(calxeda_idle_cpuidle_devices, i);
cpuidle_unregister_device(dev);
}
free_percpu(calxeda_idle_cpuidle_devices);
}
static int __init calxeda_cpuidle_init(void)
{
int cpu_id;
int ret;
struct cpuidle_device *dev;
struct cpuidle_driver *drv = &calxeda_idle_driver;
if (!of_machine_is_compatible("calxeda,highbank"))
return -ENODEV;
ret = cpuidle_register_driver(drv);
if (ret)
return ret;
calxeda_idle_cpuidle_devices = alloc_percpu(struct cpuidle_device);
if (calxeda_idle_cpuidle_devices == NULL) {
ret = -ENOMEM;
goto unregister_drv;
}
for_each_possible_cpu(cpu_id) {
dev = per_cpu_ptr(calxeda_idle_cpuidle_devices, cpu_id);
dev->cpu = cpu_id;
dev->state_count = drv->state_count;
ret = cpuidle_register_device(dev);
if (ret) {
pr_err("Failed to register cpu %u, error: %d\n",
cpu_id, ret);
goto uninit;
}
}
return 0;
uninit:
calxeda_idle_cpuidle_devices_uninit();
unregister_drv:
cpuidle_unregister_driver(drv);
return ret;
}
