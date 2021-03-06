static void __init xen_hvm_smp_prepare_boot_cpu(void)
{
BUG_ON(smp_processor_id() != 0);
native_smp_prepare_boot_cpu();
xen_vcpu_setup(0);
xen_init_spinlocks();
}
static void __init xen_hvm_smp_prepare_cpus(unsigned int max_cpus)
{
native_smp_prepare_cpus(max_cpus);
WARN_ON(xen_smp_intr_init(0));
xen_init_lock_cpu(0);
}
static void xen_hvm_cpu_die(unsigned int cpu)
{
if (common_cpu_die(cpu) == 0) {
xen_smp_intr_free(cpu);
xen_uninit_lock_cpu(cpu);
xen_teardown_timer(cpu);
}
}
static void xen_hvm_cpu_die(unsigned int cpu)
{
BUG();
}
void __init xen_hvm_smp_init(void)
{
if (!xen_have_vector_callback)
return;
smp_ops.smp_prepare_cpus = xen_hvm_smp_prepare_cpus;
smp_ops.smp_send_reschedule = xen_smp_send_reschedule;
smp_ops.cpu_die = xen_hvm_cpu_die;
smp_ops.send_call_func_ipi = xen_smp_send_call_function_ipi;
smp_ops.send_call_func_single_ipi = xen_smp_send_call_function_single_ipi;
smp_ops.smp_prepare_boot_cpu = xen_hvm_smp_prepare_boot_cpu;
}
