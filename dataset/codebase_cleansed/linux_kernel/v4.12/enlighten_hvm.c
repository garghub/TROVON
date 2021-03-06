void __ref xen_hvm_init_shared_info(void)
{
int cpu;
struct xen_add_to_physmap xatp;
static struct shared_info *shared_info_page;
if (!shared_info_page)
shared_info_page = (struct shared_info *)
extend_brk(PAGE_SIZE, PAGE_SIZE);
xatp.domid = DOMID_SELF;
xatp.idx = 0;
xatp.space = XENMAPSPACE_shared_info;
xatp.gpfn = __pa(shared_info_page) >> PAGE_SHIFT;
if (HYPERVISOR_memory_op(XENMEM_add_to_physmap, &xatp))
BUG();
HYPERVISOR_shared_info = (struct shared_info *)shared_info_page;
for_each_online_cpu(cpu) {
if (xen_vcpu_nr(cpu) >= MAX_VIRT_CPUS)
continue;
per_cpu(xen_vcpu, cpu) =
&HYPERVISOR_shared_info->vcpu_info[xen_vcpu_nr(cpu)];
}
}
static void __init init_hvm_pv_info(void)
{
int major, minor;
uint32_t eax, ebx, ecx, edx, base;
base = xen_cpuid_base();
eax = cpuid_eax(base + 1);
major = eax >> 16;
minor = eax & 0xffff;
printk(KERN_INFO "Xen version %d.%d.\n", major, minor);
xen_domain_type = XEN_HVM_DOMAIN;
if (xen_pvh_domain())
pv_info.name = "Xen PVH";
else {
u64 pfn;
uint32_t msr;
pv_info.name = "Xen HVM";
msr = cpuid_ebx(base + 2);
pfn = __pa(hypercall_page);
wrmsr_safe(msr, (u32)pfn, (u32)(pfn >> 32));
}
xen_setup_features();
cpuid(base + 4, &eax, &ebx, &ecx, &edx);
if (eax & XEN_HVM_CPUID_VCPU_ID_PRESENT)
this_cpu_write(xen_vcpu_id, ebx);
else
this_cpu_write(xen_vcpu_id, smp_processor_id());
}
static void xen_hvm_shutdown(void)
{
native_machine_shutdown();
if (kexec_in_progress)
xen_reboot(SHUTDOWN_soft_reset);
}
static void xen_hvm_crash_shutdown(struct pt_regs *regs)
{
native_machine_crash_shutdown(regs);
xen_reboot(SHUTDOWN_soft_reset);
}
static int xen_cpu_up_prepare_hvm(unsigned int cpu)
{
int rc;
if (cpu_report_state(cpu) == CPU_DEAD_FROZEN) {
xen_smp_intr_free(cpu);
xen_uninit_lock_cpu(cpu);
}
if (cpu_acpi_id(cpu) != U32_MAX)
per_cpu(xen_vcpu_id, cpu) = cpu_acpi_id(cpu);
else
per_cpu(xen_vcpu_id, cpu) = cpu;
xen_vcpu_setup(cpu);
if (xen_have_vector_callback && xen_feature(XENFEAT_hvm_safe_pvclock))
xen_setup_timer(cpu);
rc = xen_smp_intr_init(cpu);
if (rc) {
WARN(1, "xen_smp_intr_init() for CPU %d failed: %d\n",
cpu, rc);
return rc;
}
return 0;
}
static int xen_cpu_dead_hvm(unsigned int cpu)
{
xen_smp_intr_free(cpu);
if (xen_have_vector_callback && xen_feature(XENFEAT_hvm_safe_pvclock))
xen_teardown_timer(cpu);
return 0;
}
static void __init xen_hvm_guest_init(void)
{
if (xen_pv_domain())
return;
init_hvm_pv_info();
xen_hvm_init_shared_info();
xen_panic_handler_init();
if (xen_feature(XENFEAT_hvm_callback_vector))
xen_have_vector_callback = 1;
xen_hvm_smp_init();
WARN_ON(xen_cpuhp_setup(xen_cpu_up_prepare_hvm, xen_cpu_dead_hvm));
xen_unplug_emulated_devices();
x86_init.irqs.intr_init = xen_init_IRQ;
xen_hvm_init_time_ops();
xen_hvm_init_mmu_ops();
if (xen_pvh_domain())
machine_ops.emergency_restart = xen_emergency_restart;
#ifdef CONFIG_KEXEC_CORE
machine_ops.shutdown = xen_hvm_shutdown;
machine_ops.crash_shutdown = xen_hvm_crash_shutdown;
#endif
}
static __init int xen_parse_nopv(char *arg)
{
xen_nopv = true;
return 0;
}
bool xen_hvm_need_lapic(void)
{
if (xen_nopv)
return false;
if (xen_pv_domain())
return false;
if (!xen_hvm_domain())
return false;
if (xen_feature(XENFEAT_hvm_pirqs) && xen_have_vector_callback)
return false;
return true;
}
static uint32_t __init xen_platform_hvm(void)
{
if (xen_pv_domain() || xen_nopv)
return 0;
return xen_cpuid_base();
}
