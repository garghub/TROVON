static int intel_idle(struct cpuidle_device *dev,
struct cpuidle_driver *drv, int index)
{
unsigned long ecx = 1;
struct cpuidle_state *state = &drv->states[index];
unsigned long eax = flg2MWAIT(state->flags);
unsigned int cstate;
int cpu = smp_processor_id();
cstate = (((eax) >> MWAIT_SUBSTATE_SIZE) & MWAIT_CSTATE_MASK) + 1;
if (state->flags & CPUIDLE_FLAG_TLB_FLUSHED)
leave_mm(cpu);
if (!(lapic_timer_reliable_states & (1 << (cstate))))
tick_broadcast_enter();
mwait_idle_with_hints(eax, ecx);
if (!(lapic_timer_reliable_states & (1 << (cstate))))
tick_broadcast_exit();
return index;
}
static void intel_idle_freeze(struct cpuidle_device *dev,
struct cpuidle_driver *drv, int index)
{
unsigned long ecx = 1;
unsigned long eax = flg2MWAIT(drv->states[index].flags);
mwait_idle_with_hints(eax, ecx);
}
static void __setup_broadcast_timer(void *arg)
{
unsigned long on = (unsigned long)arg;
if (on)
tick_broadcast_enable();
else
tick_broadcast_disable();
}
static int cpu_hotplug_notify(struct notifier_block *n,
unsigned long action, void *hcpu)
{
int hotcpu = (unsigned long)hcpu;
struct cpuidle_device *dev;
switch (action & ~CPU_TASKS_FROZEN) {
case CPU_ONLINE:
if (lapic_timer_reliable_states != LAPIC_TIMER_ALWAYS_RELIABLE)
smp_call_function_single(hotcpu, __setup_broadcast_timer,
(void *)true, 1);
dev = per_cpu_ptr(intel_idle_cpuidle_devices, hotcpu);
if (dev->registered)
break;
if (intel_idle_cpu_init(hotcpu))
return NOTIFY_BAD;
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
static void c1e_promotion_disable(void *dummy)
{
unsigned long long msr_bits;
rdmsrl(MSR_IA32_POWER_CTL, msr_bits);
msr_bits &= ~0x2;
wrmsrl(MSR_IA32_POWER_CTL, msr_bits);
}
static int __init intel_idle_probe(void)
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
pr_debug(PREFIX "v" INTEL_IDLE_VERSION
" model 0x%X\n", boot_cpu_data.x86_model);
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
}
static void ivt_idle_state_table_update(void)
{
int cpu, package_num, num_sockets = 1;
for_each_online_cpu(cpu) {
package_num = topology_physical_package_id(cpu);
if (package_num + 1 > num_sockets) {
num_sockets = package_num + 1;
if (num_sockets > 4) {
cpuidle_state_table = ivt_cstates_8s;
return;
}
}
}
if (num_sockets > 2)
cpuidle_state_table = ivt_cstates_4s;
}
static void sklh_idle_state_table_update(void)
{
unsigned long long msr;
unsigned int eax, ebx, ecx, edx;
if (max_cstate <= 7)
return;
if ((mwait_substates & (0xF << 28)) == 0)
return;
rdmsrl(MSR_NHM_SNB_PKG_CST_CFG_CTL, msr);
if ((msr & 0xF) != 8)
return;
ecx = 0;
cpuid(7, &eax, &ebx, &ecx, &edx);
if (ebx & (1 << 2)) {
rdmsrl(MSR_IA32_FEATURE_CONTROL, msr);
if (msr & (1 << 18))
return;
}
skl_cstates[5].disabled = 1;
skl_cstates[6].disabled = 1;
}
static void intel_idle_state_table_update(void)
{
switch (boot_cpu_data.x86_model) {
case 0x3e:
ivt_idle_state_table_update();
break;
case 0x5e:
sklh_idle_state_table_update();
break;
}
}
static void __init intel_idle_cpuidle_driver_init(void)
{
int cstate;
struct cpuidle_driver *drv = &intel_idle_driver;
intel_idle_state_table_update();
drv->state_count = 1;
for (cstate = 0; cstate < CPUIDLE_STATE_MAX; ++cstate) {
int num_substates, mwait_hint, mwait_cstate;
if ((cpuidle_state_table[cstate].enter == NULL) &&
(cpuidle_state_table[cstate].enter_freeze == NULL))
break;
if (cstate + 1 > max_cstate) {
printk(PREFIX "max_cstate %d reached\n",
max_cstate);
break;
}
mwait_hint = flg2MWAIT(cpuidle_state_table[cstate].flags);
mwait_cstate = MWAIT_HINT2CSTATE(mwait_hint);
num_substates = (mwait_substates >> ((mwait_cstate + 1) * 4))
& MWAIT_SUBSTATE_MASK;
if (num_substates == 0)
continue;
if (cpuidle_state_table[cstate].disabled != 0) {
pr_debug(PREFIX "state %s is disabled",
cpuidle_state_table[cstate].name);
continue;
}
if (((mwait_cstate + 1) > 2) &&
!boot_cpu_has(X86_FEATURE_NONSTOP_TSC))
mark_tsc_unstable("TSC halts in idle"
" states deeper than C2");
drv->states[drv->state_count] =
cpuidle_state_table[cstate];
drv->state_count += 1;
}
if (icpu->byt_auto_demotion_disable_flag) {
wrmsrl(MSR_CC6_DEMOTION_POLICY_CONFIG, 0);
wrmsrl(MSR_MC6_DEMOTION_POLICY_CONFIG, 0);
}
}
static int intel_idle_cpu_init(int cpu)
{
struct cpuidle_device *dev;
dev = per_cpu_ptr(intel_idle_cpuidle_devices, cpu);
dev->cpu = cpu;
if (cpuidle_register_device(dev)) {
pr_debug(PREFIX "cpuidle_register_device %d failed!\n", cpu);
return -EIO;
}
if (icpu->auto_demotion_disable_flags)
smp_call_function_single(cpu, auto_demotion_disable, NULL, 1);
if (icpu->disable_promotion_to_c1e)
smp_call_function_single(cpu, c1e_promotion_disable, NULL, 1);
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
intel_idle_cpuidle_devices = alloc_percpu(struct cpuidle_device);
if (intel_idle_cpuidle_devices == NULL)
return -ENOMEM;
intel_idle_cpuidle_driver_init();
retval = cpuidle_register_driver(&intel_idle_driver);
if (retval) {
struct cpuidle_driver *drv = cpuidle_get_driver();
printk(KERN_DEBUG PREFIX "intel_idle yielding to %s",
drv ? drv->name : "none");
free_percpu(intel_idle_cpuidle_devices);
return retval;
}
cpu_notifier_register_begin();
for_each_online_cpu(i) {
retval = intel_idle_cpu_init(i);
if (retval) {
intel_idle_cpuidle_devices_uninit();
cpu_notifier_register_done();
cpuidle_unregister_driver(&intel_idle_driver);
free_percpu(intel_idle_cpuidle_devices);
return retval;
}
}
__register_cpu_notifier(&cpu_hotplug_notifier);
if (boot_cpu_has(X86_FEATURE_ARAT))
lapic_timer_reliable_states = LAPIC_TIMER_ALWAYS_RELIABLE;
else
on_each_cpu(__setup_broadcast_timer, (void *)true, 1);
cpu_notifier_register_done();
pr_debug(PREFIX "lapic_timer_reliable_states 0x%x\n",
lapic_timer_reliable_states);
return 0;
}
static void __exit intel_idle_exit(void)
{
struct cpuidle_device *dev;
int i;
cpu_notifier_register_begin();
if (lapic_timer_reliable_states != LAPIC_TIMER_ALWAYS_RELIABLE)
on_each_cpu(__setup_broadcast_timer, (void *)false, 1);
__unregister_cpu_notifier(&cpu_hotplug_notifier);
for_each_possible_cpu(i) {
dev = per_cpu_ptr(intel_idle_cpuidle_devices, i);
cpuidle_unregister_device(dev);
}
cpu_notifier_register_done();
cpuidle_unregister_driver(&intel_idle_driver);
free_percpu(intel_idle_cpuidle_devices);
}
