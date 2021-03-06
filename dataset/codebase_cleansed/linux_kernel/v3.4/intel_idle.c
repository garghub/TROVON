static long get_driver_data(int cstate)
{
int driver_data;
switch (cstate) {
case 1:
driver_data = 0x00;
break;
case 2:
driver_data = 0x10;
break;
case 3:
driver_data = 0x20;
break;
case 4:
driver_data = 0x30;
break;
case 5:
driver_data = 0x40;
break;
case 6:
driver_data = 0x52;
break;
default:
driver_data = 0x00;
}
return driver_data;
}
static int intel_idle(struct cpuidle_device *dev,
struct cpuidle_driver *drv, int index)
{
unsigned long ecx = 1;
struct cpuidle_state *state = &drv->states[index];
struct cpuidle_state_usage *state_usage = &dev->states_usage[index];
unsigned long eax = (unsigned long)cpuidle_get_statedata(state_usage);
unsigned int cstate;
ktime_t kt_before, kt_after;
s64 usec_delta;
int cpu = smp_processor_id();
cstate = (((eax) >> MWAIT_SUBSTATE_SIZE) & MWAIT_CSTATE_MASK) + 1;
if (state->flags & CPUIDLE_FLAG_TLB_FLUSHED)
leave_mm(cpu);
if (!(lapic_timer_reliable_states & (1 << (cstate))))
clockevents_notify(CLOCK_EVT_NOTIFY_BROADCAST_ENTER, &cpu);
kt_before = ktime_get_real();
stop_critical_timings();
if (!need_resched()) {
__monitor((void *)&current_thread_info()->flags, 0, 0);
smp_mb();
if (!need_resched())
__mwait(eax, ecx);
}
start_critical_timings();
kt_after = ktime_get_real();
usec_delta = ktime_to_us(ktime_sub(kt_after, kt_before));
local_irq_enable();
if (!(lapic_timer_reliable_states & (1 << (cstate))))
clockevents_notify(CLOCK_EVT_NOTIFY_BROADCAST_EXIT, &cpu);
dev->last_residency = (int)usec_delta;
return index;
}
static void __setup_broadcast_timer(void *arg)
{
unsigned long reason = (unsigned long)arg;
int cpu = smp_processor_id();
reason = reason ?
CLOCK_EVT_NOTIFY_BROADCAST_ON : CLOCK_EVT_NOTIFY_BROADCAST_OFF;
clockevents_notify(reason, &cpu);
}
static int setup_broadcast_cpuhp_notify(struct notifier_block *n,
unsigned long action, void *hcpu)
{
int hotcpu = (unsigned long)hcpu;
switch (action & 0xf) {
case CPU_ONLINE:
smp_call_function_single(hotcpu, __setup_broadcast_timer,
(void *)true, 1);
break;
}
return NOTIFY_OK;
}
static void auto_demotion_disable(void *dummy)
{
unsigned long long msr_bits;
rdmsrl(MSR_NHM_SNB_PKG_CST_CFG_CTL, msr_bits);
msr_bits &= ~(icpu->auto_demotion_disable_flags);
wrmsrl(MSR_NHM_SNB_PKG_CST_CFG_CTL, msr_bits);
}
static int intel_idle_probe(void)
{
unsigned int eax, ebx, ecx;
const struct x86_cpu_id *id;
if (max_cstate == 0) {
pr_debug(PREFIX "disabled\n");
return -EPERM;
}
id = x86_match_cpu(intel_idle_ids);
if (!id) {
if (boot_cpu_data.x86_vendor == X86_VENDOR_INTEL &&
boot_cpu_data.x86 == 6)
pr_debug(PREFIX "does not run on family %d model %d\n",
boot_cpu_data.x86, boot_cpu_data.x86_model);
return -ENODEV;
}
if (boot_cpu_data.cpuid_level < CPUID_MWAIT_LEAF)
return -ENODEV;
cpuid(CPUID_MWAIT_LEAF, &eax, &ebx, &ecx, &mwait_substates);
if (!(ecx & CPUID5_ECX_EXTENSIONS_SUPPORTED) ||
!(ecx & CPUID5_ECX_INTERRUPT_BREAK) ||
!mwait_substates)
return -ENODEV;
pr_debug(PREFIX "MWAIT substates: 0x%x\n", mwait_substates);
icpu = (const struct idle_cpu *)id->driver_data;
cpuidle_state_table = icpu->state_table;
if (boot_cpu_has(X86_FEATURE_ARAT))
lapic_timer_reliable_states = LAPIC_TIMER_ALWAYS_RELIABLE;
else {
on_each_cpu(__setup_broadcast_timer, (void *)true, 1);
register_cpu_notifier(&setup_broadcast_notifier);
}
pr_debug(PREFIX "v" INTEL_IDLE_VERSION
" model 0x%X\n", boot_cpu_data.x86_model);
pr_debug(PREFIX "lapic_timer_reliable_states 0x%x\n",
lapic_timer_reliable_states);
return 0;
}
static void intel_idle_cpuidle_devices_uninit(void)
{
int i;
struct cpuidle_device *dev;
for_each_online_cpu(i) {
dev = per_cpu_ptr(intel_idle_cpuidle_devices, i);
cpuidle_unregister_device(dev);
}
free_percpu(intel_idle_cpuidle_devices);
return;
}
static int intel_idle_cpuidle_driver_init(void)
{
int cstate;
struct cpuidle_driver *drv = &intel_idle_driver;
drv->state_count = 1;
for (cstate = 1; cstate < MWAIT_MAX_NUM_CSTATES; ++cstate) {
int num_substates;
if (cstate > max_cstate) {
printk(PREFIX "max_cstate %d reached\n",
max_cstate);
break;
}
num_substates = (mwait_substates >> ((cstate) * 4))
& MWAIT_SUBSTATE_MASK;
if (num_substates == 0)
continue;
if (cpuidle_state_table[cstate].enter == NULL) {
if (*cpuidle_state_table[cstate].name == '\0')
pr_debug(PREFIX "unaware of model 0x%x"
" MWAIT %d please"
" contact lenb@kernel.org",
boot_cpu_data.x86_model, cstate);
continue;
}
if ((cstate > 2) &&
!boot_cpu_has(X86_FEATURE_NONSTOP_TSC))
mark_tsc_unstable("TSC halts in idle"
" states deeper than C2");
drv->states[drv->state_count] =
cpuidle_state_table[cstate];
drv->state_count += 1;
}
if (icpu->auto_demotion_disable_flags)
on_each_cpu(auto_demotion_disable, NULL, 1);
return 0;
}
int intel_idle_cpu_init(int cpu)
{
int cstate;
struct cpuidle_device *dev;
dev = per_cpu_ptr(intel_idle_cpuidle_devices, cpu);
dev->state_count = 1;
for (cstate = 1; cstate < MWAIT_MAX_NUM_CSTATES; ++cstate) {
int num_substates;
if (cstate > max_cstate) {
printk(PREFIX "max_cstate %d reached\n", max_cstate);
break;
}
num_substates = (mwait_substates >> ((cstate) * 4))
& MWAIT_SUBSTATE_MASK;
if (num_substates == 0)
continue;
if (cpuidle_state_table[cstate].enter == NULL)
continue;
dev->states_usage[dev->state_count].driver_data =
(void *)get_driver_data(cstate);
dev->state_count += 1;
}
dev->cpu = cpu;
if (cpuidle_register_device(dev)) {
pr_debug(PREFIX "cpuidle_register_device %d failed!\n", cpu);
intel_idle_cpuidle_devices_uninit();
return -EIO;
}
if (icpu->auto_demotion_disable_flags)
smp_call_function_single(cpu, auto_demotion_disable, NULL, 1);
return 0;
}
static int __init intel_idle_init(void)
{
int retval, i;
if (boot_option_idle_override != IDLE_NO_OVERRIDE)
return -ENODEV;
retval = intel_idle_probe();
if (retval)
return retval;
intel_idle_cpuidle_driver_init();
retval = cpuidle_register_driver(&intel_idle_driver);
if (retval) {
printk(KERN_DEBUG PREFIX "intel_idle yielding to %s",
cpuidle_get_driver()->name);
return retval;
}
intel_idle_cpuidle_devices = alloc_percpu(struct cpuidle_device);
if (intel_idle_cpuidle_devices == NULL)
return -ENOMEM;
for_each_online_cpu(i) {
retval = intel_idle_cpu_init(i);
if (retval) {
cpuidle_unregister_driver(&intel_idle_driver);
return retval;
}
}
return 0;
}
static void __exit intel_idle_exit(void)
{
intel_idle_cpuidle_devices_uninit();
cpuidle_unregister_driver(&intel_idle_driver);
if (lapic_timer_reliable_states != LAPIC_TIMER_ALWAYS_RELIABLE) {
on_each_cpu(__setup_broadcast_timer, (void *)false, 1);
unregister_cpu_notifier(&setup_broadcast_notifier);
}
return;
}
