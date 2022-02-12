static int snooze_loop(struct cpuidle_device *dev,
struct cpuidle_driver *drv,
int index)
{
local_irq_enable();
set_thread_flag(TIF_POLLING_NRFLAG);
while (!need_resched()) {
HMT_low();
HMT_very_low();
}
HMT_medium();
clear_thread_flag(TIF_POLLING_NRFLAG);
smp_mb();
return index;
}
static int nap_loop(struct cpuidle_device *dev,
struct cpuidle_driver *drv,
int index)
{
power7_idle();
return index;
}
static int powernv_cpuidle_add_cpu_notifier(struct notifier_block *n,
unsigned long action, void *hcpu)
{
int hotcpu = (unsigned long)hcpu;
struct cpuidle_device *dev =
per_cpu(cpuidle_devices, hotcpu);
if (dev && cpuidle_get_driver()) {
switch (action) {
case CPU_ONLINE:
case CPU_ONLINE_FROZEN:
cpuidle_pause_and_lock();
cpuidle_enable_device(dev);
cpuidle_resume_and_unlock();
break;
case CPU_DEAD:
case CPU_DEAD_FROZEN:
cpuidle_pause_and_lock();
cpuidle_disable_device(dev);
cpuidle_resume_and_unlock();
break;
default:
return NOTIFY_DONE;
}
}
return NOTIFY_OK;
}
static int powernv_cpuidle_driver_init(void)
{
int idle_state;
struct cpuidle_driver *drv = &powernv_idle_driver;
drv->state_count = 0;
for (idle_state = 0; idle_state < max_idle_state; ++idle_state) {
if (cpuidle_state_table[idle_state].enter == NULL)
continue;
drv->states[drv->state_count] =
cpuidle_state_table[idle_state];
drv->state_count += 1;
}
return 0;
}
static int powernv_idle_probe(void)
{
if (cpuidle_disable != IDLE_NO_OVERRIDE)
return -ENODEV;
if (firmware_has_feature(FW_FEATURE_OPALv3)) {
cpuidle_state_table = powernv_states;
max_idle_state = ARRAY_SIZE(powernv_states);
} else
return -ENODEV;
return 0;
}
static int __init powernv_processor_idle_init(void)
{
int retval;
retval = powernv_idle_probe();
if (retval)
return retval;
powernv_cpuidle_driver_init();
retval = cpuidle_register(&powernv_idle_driver, NULL);
if (retval) {
printk(KERN_DEBUG "Registration of powernv driver failed.\n");
return retval;
}
register_cpu_notifier(&setup_hotplug_notifier);
printk(KERN_DEBUG "powernv_idle_driver registered\n");
return 0;
}
