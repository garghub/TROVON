static inline void idle_loop_prolog(unsigned long *in_purr)
{
ppc64_runlatch_off();
*in_purr = mfspr(SPRN_PURR);
get_lppaca()->idle = 1;
}
static inline void idle_loop_epilog(unsigned long in_purr)
{
u64 wait_cycles;
wait_cycles = be64_to_cpu(get_lppaca()->wait_state_cycles);
wait_cycles += mfspr(SPRN_PURR) - in_purr;
get_lppaca()->wait_state_cycles = cpu_to_be64(wait_cycles);
get_lppaca()->idle = 0;
if (irqs_disabled())
local_irq_enable();
ppc64_runlatch_on();
}
static int snooze_loop(struct cpuidle_device *dev,
struct cpuidle_driver *drv,
int index)
{
unsigned long in_purr;
u64 snooze_exit_time;
idle_loop_prolog(&in_purr);
local_irq_enable();
set_thread_flag(TIF_POLLING_NRFLAG);
snooze_exit_time = get_tb() + snooze_timeout;
while (!need_resched()) {
HMT_low();
HMT_very_low();
if (snooze_timeout_en && get_tb() > snooze_exit_time)
break;
}
HMT_medium();
clear_thread_flag(TIF_POLLING_NRFLAG);
smp_mb();
idle_loop_epilog(in_purr);
return index;
}
static void check_and_cede_processor(void)
{
if (prep_irq_for_idle()) {
cede_processor();
#ifdef CONFIG_TRACE_IRQFLAGS
if (WARN_ON(!(mfmsr() & MSR_EE)))
__hard_irq_enable();
#endif
}
}
static int dedicated_cede_loop(struct cpuidle_device *dev,
struct cpuidle_driver *drv,
int index)
{
unsigned long in_purr;
idle_loop_prolog(&in_purr);
get_lppaca()->donate_dedicated_cpu = 1;
HMT_medium();
check_and_cede_processor();
get_lppaca()->donate_dedicated_cpu = 0;
idle_loop_epilog(in_purr);
return index;
}
static int shared_cede_loop(struct cpuidle_device *dev,
struct cpuidle_driver *drv,
int index)
{
unsigned long in_purr;
idle_loop_prolog(&in_purr);
check_and_cede_processor();
idle_loop_epilog(in_purr);
return index;
}
static int pseries_cpuidle_add_cpu_notifier(struct notifier_block *n,
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
static int pseries_cpuidle_driver_init(void)
{
int idle_state;
struct cpuidle_driver *drv = &pseries_idle_driver;
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
static int pseries_idle_probe(void)
{
if (cpuidle_disable != IDLE_NO_OVERRIDE)
return -ENODEV;
if (firmware_has_feature(FW_FEATURE_SPLPAR)) {
if (lppaca_shared_proc(get_lppaca())) {
cpuidle_state_table = shared_states;
max_idle_state = ARRAY_SIZE(shared_states);
} else {
cpuidle_state_table = dedicated_states;
max_idle_state = ARRAY_SIZE(dedicated_states);
}
} else
return -ENODEV;
if (max_idle_state > 1) {
snooze_timeout_en = true;
snooze_timeout = cpuidle_state_table[1].target_residency *
tb_ticks_per_usec;
}
return 0;
}
static int __init pseries_processor_idle_init(void)
{
int retval;
retval = pseries_idle_probe();
if (retval)
return retval;
pseries_cpuidle_driver_init();
retval = cpuidle_register(&pseries_idle_driver, NULL);
if (retval) {
printk(KERN_DEBUG "Registration of pseries driver failed.\n");
return retval;
}
register_cpu_notifier(&setup_hotplug_notifier);
printk(KERN_DEBUG "pseries_idle_driver registered\n");
return 0;
}
