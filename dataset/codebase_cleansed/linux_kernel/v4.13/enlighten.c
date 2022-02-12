static int xen_cpu_up_online(unsigned int cpu)
{
xen_init_lock_cpu(cpu);
return 0;
}
int xen_cpuhp_setup(int (*cpu_up_prepare_cb)(unsigned int),
int (*cpu_dead_cb)(unsigned int))
{
int rc;
rc = cpuhp_setup_state_nocalls(CPUHP_XEN_PREPARE,
"x86/xen/hvm_guest:prepare",
cpu_up_prepare_cb, cpu_dead_cb);
if (rc >= 0) {
rc = cpuhp_setup_state_nocalls(CPUHP_AP_ONLINE_DYN,
"x86/xen/hvm_guest:online",
xen_cpu_up_online, NULL);
if (rc < 0)
cpuhp_remove_state_nocalls(CPUHP_XEN_PREPARE);
}
return rc >= 0 ? 0 : rc;
}
static int xen_vcpu_setup_restore(int cpu)
{
int rc = 0;
xen_vcpu_info_reset(cpu);
if (xen_pv_domain() ||
(xen_hvm_domain() && cpu_online(cpu))) {
rc = xen_vcpu_setup(cpu);
}
return rc;
}
void xen_vcpu_restore(void)
{
int cpu, rc;
for_each_possible_cpu(cpu) {
bool other_cpu = (cpu != smp_processor_id());
bool is_up;
if (xen_vcpu_nr(cpu) == XEN_VCPU_ID_INVALID)
continue;
is_up = HYPERVISOR_vcpu_op(VCPUOP_is_up,
xen_vcpu_nr(cpu), NULL) > 0;
if (other_cpu && is_up &&
HYPERVISOR_vcpu_op(VCPUOP_down, xen_vcpu_nr(cpu), NULL))
BUG();
if (xen_pv_domain() || xen_feature(XENFEAT_hvm_safe_pvclock))
xen_setup_runstate_info(cpu);
rc = xen_vcpu_setup_restore(cpu);
if (rc)
pr_emerg_once("vcpu restore failed for cpu=%d err=%d. "
"System will hang.\n", cpu, rc);
if (other_cpu && is_up && (rc == 0) &&
HYPERVISOR_vcpu_op(VCPUOP_up, xen_vcpu_nr(cpu), NULL))
BUG();
}
}
void xen_vcpu_info_reset(int cpu)
{
if (xen_vcpu_nr(cpu) < MAX_VIRT_CPUS) {
per_cpu(xen_vcpu, cpu) =
&HYPERVISOR_shared_info->vcpu_info[xen_vcpu_nr(cpu)];
} else {
per_cpu(xen_vcpu, cpu) = NULL;
}
}
int xen_vcpu_setup(int cpu)
{
struct vcpu_register_vcpu_info info;
int err;
struct vcpu_info *vcpup;
BUG_ON(HYPERVISOR_shared_info == &xen_dummy_shared_info);
if (xen_hvm_domain()) {
if (per_cpu(xen_vcpu, cpu) == &per_cpu(xen_vcpu_info, cpu))
return 0;
}
if (xen_have_vcpu_info_placement) {
vcpup = &per_cpu(xen_vcpu_info, cpu);
info.mfn = arbitrary_virt_to_mfn(vcpup);
info.offset = offset_in_page(vcpup);
err = HYPERVISOR_vcpu_op(VCPUOP_register_vcpu_info,
xen_vcpu_nr(cpu), &info);
if (err) {
pr_warn_once("register_vcpu_info failed: cpu=%d err=%d\n",
cpu, err);
xen_have_vcpu_info_placement = 0;
} else {
per_cpu(xen_vcpu, cpu) = vcpup;
}
}
if (!xen_have_vcpu_info_placement)
xen_vcpu_info_reset(cpu);
return ((per_cpu(xen_vcpu, cpu) == NULL) ? -ENODEV : 0);
}
void xen_reboot(int reason)
{
struct sched_shutdown r = { .reason = reason };
int cpu;
for_each_online_cpu(cpu)
xen_pmu_finish(cpu);
if (HYPERVISOR_sched_op(SCHEDOP_shutdown, &r))
BUG();
}
void xen_emergency_restart(void)
{
xen_reboot(SHUTDOWN_reboot);
}
static int
xen_panic_event(struct notifier_block *this, unsigned long event, void *ptr)
{
if (!kexec_crash_loaded())
xen_reboot(SHUTDOWN_crash);
return NOTIFY_DONE;
}
int xen_panic_handler_init(void)
{
atomic_notifier_chain_register(&panic_notifier_list, &xen_panic_block);
return 0;
}
void xen_pin_vcpu(int cpu)
{
static bool disable_pinning;
struct sched_pin_override pin_override;
int ret;
if (disable_pinning)
return;
pin_override.pcpu = cpu;
ret = HYPERVISOR_sched_op(SCHEDOP_pin_override, &pin_override);
if (cpu < 0)
return;
switch (ret) {
case -ENOSYS:
pr_warn("Unable to pin on physical cpu %d. In case of problems consider vcpu pinning.\n",
cpu);
disable_pinning = true;
break;
case -EPERM:
WARN(1, "Trying to pin vcpu without having privilege to do so\n");
disable_pinning = true;
break;
case -EINVAL:
case -EBUSY:
pr_warn("Physical cpu %d not available for pinning. Check Xen cpu configuration.\n",
cpu);
break;
case 0:
break;
default:
WARN(1, "rc %d while trying to pin vcpu\n", ret);
disable_pinning = true;
}
}
void xen_arch_register_cpu(int num)
{
arch_register_cpu(num);
}
void xen_arch_unregister_cpu(int num)
{
arch_unregister_cpu(num);
}
