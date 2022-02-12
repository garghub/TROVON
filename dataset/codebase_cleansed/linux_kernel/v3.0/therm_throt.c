static int therm_throt_process(bool new_event, int event, int level)
{
struct _thermal_state *state;
unsigned int this_cpu = smp_processor_id();
bool old_event;
u64 now;
struct thermal_state *pstate = &per_cpu(thermal_state, this_cpu);
now = get_jiffies_64();
if (level == CORE_LEVEL) {
if (event == THERMAL_THROTTLING_EVENT)
state = &pstate->core_throttle;
else if (event == POWER_LIMIT_EVENT)
state = &pstate->core_power_limit;
else
return 0;
} else if (level == PACKAGE_LEVEL) {
if (event == THERMAL_THROTTLING_EVENT)
state = &pstate->package_throttle;
else if (event == POWER_LIMIT_EVENT)
state = &pstate->package_power_limit;
else
return 0;
} else
return 0;
old_event = state->new_event;
state->new_event = new_event;
if (new_event)
state->count++;
if (time_before64(now, state->next_check) &&
state->count != state->last_count)
return 0;
state->next_check = now + CHECK_INTERVAL;
state->last_count = state->count;
if (new_event) {
if (event == THERMAL_THROTTLING_EVENT)
printk(KERN_CRIT "CPU%d: %s temperature above threshold, cpu clock throttled (total events = %lu)\n",
this_cpu,
level == CORE_LEVEL ? "Core" : "Package",
state->count);
else
printk(KERN_CRIT "CPU%d: %s power limit notification (total events = %lu)\n",
this_cpu,
level == CORE_LEVEL ? "Core" : "Package",
state->count);
return 1;
}
if (old_event) {
if (event == THERMAL_THROTTLING_EVENT)
printk(KERN_INFO "CPU%d: %s temperature/speed normal\n",
this_cpu,
level == CORE_LEVEL ? "Core" : "Package");
else
printk(KERN_INFO "CPU%d: %s power limit normal\n",
this_cpu,
level == CORE_LEVEL ? "Core" : "Package");
return 1;
}
return 0;
}
static int thresh_event_valid(int event)
{
struct _thermal_state *state;
unsigned int this_cpu = smp_processor_id();
struct thermal_state *pstate = &per_cpu(thermal_state, this_cpu);
u64 now = get_jiffies_64();
state = (event == 0) ? &pstate->core_thresh0 : &pstate->core_thresh1;
if (time_before64(now, state->next_check))
return 0;
state->next_check = now + CHECK_INTERVAL;
return 1;
}
static __cpuinit int thermal_throttle_add_dev(struct sys_device *sys_dev,
unsigned int cpu)
{
int err;
struct cpuinfo_x86 *c = &cpu_data(cpu);
err = sysfs_create_group(&sys_dev->kobj, &thermal_attr_group);
if (err)
return err;
if (cpu_has(c, X86_FEATURE_PLN))
err = sysfs_add_file_to_group(&sys_dev->kobj,
&attr_core_power_limit_count.attr,
thermal_attr_group.name);
if (cpu_has(c, X86_FEATURE_PTS)) {
err = sysfs_add_file_to_group(&sys_dev->kobj,
&attr_package_throttle_count.attr,
thermal_attr_group.name);
if (cpu_has(c, X86_FEATURE_PLN))
err = sysfs_add_file_to_group(&sys_dev->kobj,
&attr_package_power_limit_count.attr,
thermal_attr_group.name);
}
return err;
}
static __cpuinit void thermal_throttle_remove_dev(struct sys_device *sys_dev)
{
sysfs_remove_group(&sys_dev->kobj, &thermal_attr_group);
}
static __cpuinit int
thermal_throttle_cpu_callback(struct notifier_block *nfb,
unsigned long action,
void *hcpu)
{
unsigned int cpu = (unsigned long)hcpu;
struct sys_device *sys_dev;
int err = 0;
sys_dev = get_cpu_sysdev(cpu);
switch (action) {
case CPU_UP_PREPARE:
case CPU_UP_PREPARE_FROZEN:
mutex_lock(&therm_cpu_lock);
err = thermal_throttle_add_dev(sys_dev, cpu);
mutex_unlock(&therm_cpu_lock);
WARN_ON(err);
break;
case CPU_UP_CANCELED:
case CPU_UP_CANCELED_FROZEN:
case CPU_DEAD:
case CPU_DEAD_FROZEN:
mutex_lock(&therm_cpu_lock);
thermal_throttle_remove_dev(sys_dev);
mutex_unlock(&therm_cpu_lock);
break;
}
return notifier_from_errno(err);
}
static __init int thermal_throttle_init_device(void)
{
unsigned int cpu = 0;
int err;
if (!atomic_read(&therm_throt_en))
return 0;
register_hotcpu_notifier(&thermal_throttle_cpu_notifier);
#ifdef CONFIG_HOTPLUG_CPU
mutex_lock(&therm_cpu_lock);
#endif
for_each_online_cpu(cpu) {
err = thermal_throttle_add_dev(get_cpu_sysdev(cpu), cpu);
WARN_ON(err);
}
#ifdef CONFIG_HOTPLUG_CPU
mutex_unlock(&therm_cpu_lock);
#endif
return 0;
}
static void notify_thresholds(__u64 msr_val)
{
if (!platform_thermal_notify)
return;
if ((msr_val & THERM_LOG_THRESHOLD0) && thresh_event_valid(0))
platform_thermal_notify(msr_val);
if ((msr_val & THERM_LOG_THRESHOLD1) && thresh_event_valid(1))
platform_thermal_notify(msr_val);
}
static void intel_thermal_interrupt(void)
{
__u64 msr_val;
rdmsrl(MSR_IA32_THERM_STATUS, msr_val);
notify_thresholds(msr_val);
if (therm_throt_process(msr_val & THERM_STATUS_PROCHOT,
THERMAL_THROTTLING_EVENT,
CORE_LEVEL) != 0)
mce_log_therm_throt_event(CORE_THROTTLED | msr_val);
if (this_cpu_has(X86_FEATURE_PLN))
if (therm_throt_process(msr_val & THERM_STATUS_POWER_LIMIT,
POWER_LIMIT_EVENT,
CORE_LEVEL) != 0)
mce_log_therm_throt_event(CORE_POWER_LIMIT | msr_val);
if (this_cpu_has(X86_FEATURE_PTS)) {
rdmsrl(MSR_IA32_PACKAGE_THERM_STATUS, msr_val);
if (therm_throt_process(msr_val & PACKAGE_THERM_STATUS_PROCHOT,
THERMAL_THROTTLING_EVENT,
PACKAGE_LEVEL) != 0)
mce_log_therm_throt_event(PACKAGE_THROTTLED | msr_val);
if (this_cpu_has(X86_FEATURE_PLN))
if (therm_throt_process(msr_val &
PACKAGE_THERM_STATUS_POWER_LIMIT,
POWER_LIMIT_EVENT,
PACKAGE_LEVEL) != 0)
mce_log_therm_throt_event(PACKAGE_POWER_LIMIT
| msr_val);
}
}
static void unexpected_thermal_interrupt(void)
{
printk(KERN_ERR "CPU%d: Unexpected LVT thermal interrupt!\n",
smp_processor_id());
}
asmlinkage void smp_thermal_interrupt(struct pt_regs *regs)
{
exit_idle();
irq_enter();
inc_irq_stat(irq_thermal_count);
smp_thermal_vector();
irq_exit();
ack_APIC_irq();
}
static int intel_thermal_supported(struct cpuinfo_x86 *c)
{
if (!cpu_has_apic)
return 0;
if (!cpu_has(c, X86_FEATURE_ACPI) || !cpu_has(c, X86_FEATURE_ACC))
return 0;
return 1;
}
void __init mcheck_intel_therm_init(void)
{
if (intel_thermal_supported(&boot_cpu_data))
lvtthmr_init = apic_read(APIC_LVTTHMR);
}
void intel_init_thermal(struct cpuinfo_x86 *c)
{
unsigned int cpu = smp_processor_id();
int tm2 = 0;
u32 l, h;
if (!intel_thermal_supported(c))
return;
rdmsr(MSR_IA32_MISC_ENABLE, l, h);
h = lvtthmr_init;
if ((h & APIC_DM_FIXED_MASK) != APIC_DM_FIXED)
apic_write(APIC_LVTTHMR, lvtthmr_init);
if ((l & MSR_IA32_MISC_ENABLE_TM1) && (h & APIC_DM_SMI)) {
printk(KERN_DEBUG
"CPU%d: Thermal monitoring handled by SMI\n", cpu);
return;
}
if (h & APIC_VECTOR_MASK) {
printk(KERN_DEBUG
"CPU%d: Thermal LVT vector (%#x) already installed\n",
cpu, (h & APIC_VECTOR_MASK));
return;
}
if (cpu_has(c, X86_FEATURE_TM2)) {
if (c->x86 == 6 && (c->x86_model == 9 || c->x86_model == 13)) {
rdmsr(MSR_THERM2_CTL, l, h);
if (l & MSR_THERM2_CTL_TM_SELECT)
tm2 = 1;
} else if (l & MSR_IA32_MISC_ENABLE_TM2)
tm2 = 1;
}
h = THERMAL_APIC_VECTOR | APIC_DM_FIXED | APIC_LVT_MASKED;
apic_write(APIC_LVTTHMR, h);
rdmsr(MSR_IA32_THERM_INTERRUPT, l, h);
if (cpu_has(c, X86_FEATURE_PLN))
wrmsr(MSR_IA32_THERM_INTERRUPT,
l | (THERM_INT_LOW_ENABLE
| THERM_INT_HIGH_ENABLE | THERM_INT_PLN_ENABLE), h);
else
wrmsr(MSR_IA32_THERM_INTERRUPT,
l | (THERM_INT_LOW_ENABLE | THERM_INT_HIGH_ENABLE), h);
if (cpu_has(c, X86_FEATURE_PTS)) {
rdmsr(MSR_IA32_PACKAGE_THERM_INTERRUPT, l, h);
if (cpu_has(c, X86_FEATURE_PLN))
wrmsr(MSR_IA32_PACKAGE_THERM_INTERRUPT,
l | (PACKAGE_THERM_INT_LOW_ENABLE
| PACKAGE_THERM_INT_HIGH_ENABLE
| PACKAGE_THERM_INT_PLN_ENABLE), h);
else
wrmsr(MSR_IA32_PACKAGE_THERM_INTERRUPT,
l | (PACKAGE_THERM_INT_LOW_ENABLE
| PACKAGE_THERM_INT_HIGH_ENABLE), h);
}
smp_thermal_vector = intel_thermal_interrupt;
rdmsr(MSR_IA32_MISC_ENABLE, l, h);
wrmsr(MSR_IA32_MISC_ENABLE, l | MSR_IA32_MISC_ENABLE_TM1, h);
l = apic_read(APIC_LVTTHMR);
apic_write(APIC_LVTTHMR, l & ~APIC_LVT_MASKED);
printk_once(KERN_INFO "CPU0: Thermal monitoring enabled (%s)\n",
tm2 ? "TM2" : "TM1");
atomic_set(&therm_throt_en, 1);
}
