static void pseries_kexec_cpu_down(int crash_shutdown, int secondary)
{
if (firmware_has_feature(FW_FEATURE_SPLPAR) && !crash_shutdown) {
unsigned long addr;
addr = __pa(get_slb_shadow());
if (unregister_slb_shadow(hard_smp_processor_id(), addr))
printk("SLB shadow buffer deregistration of "
"cpu %u (hw_cpu_id %d) failed\n",
smp_processor_id(),
hard_smp_processor_id());
addr = __pa(get_lppaca());
if (unregister_vpa(hard_smp_processor_id(), addr)) {
printk("VPA deregistration of cpu %u (hw_cpu_id %d) "
"failed\n", smp_processor_id(),
hard_smp_processor_id());
}
}
}
static void pseries_kexec_cpu_down_mpic(int crash_shutdown, int secondary)
{
pseries_kexec_cpu_down(crash_shutdown, secondary);
mpic_teardown_this_cpu(secondary);
}
void __init setup_kexec_cpu_down_mpic(void)
{
ppc_md.kexec_cpu_down = pseries_kexec_cpu_down_mpic;
}
static void pseries_kexec_cpu_down_xics(int crash_shutdown, int secondary)
{
pseries_kexec_cpu_down(crash_shutdown, secondary);
xics_kexec_teardown_cpu(secondary);
}
void __init setup_kexec_cpu_down_xics(void)
{
ppc_md.kexec_cpu_down = pseries_kexec_cpu_down_xics;
}
