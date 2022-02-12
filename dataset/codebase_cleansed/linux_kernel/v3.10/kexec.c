static void pseries_kexec_cpu_down(int crash_shutdown, int secondary)
{
if (firmware_has_feature(FW_FEATURE_SPLPAR) && !crash_shutdown) {
int ret;
int cpu = smp_processor_id();
int hwcpu = hard_smp_processor_id();
if (get_lppaca()->dtl_enable_mask) {
ret = unregister_dtl(hwcpu);
if (ret) {
pr_err("WARNING: DTL deregistration for cpu "
"%d (hw %d) failed with %d\n",
cpu, hwcpu, ret);
}
}
ret = unregister_slb_shadow(hwcpu);
if (ret) {
pr_err("WARNING: SLB shadow buffer deregistration "
"for cpu %d (hw %d) failed with %d\n",
cpu, hwcpu, ret);
}
ret = unregister_vpa(hwcpu);
if (ret) {
pr_err("WARNING: VPA deregistration for cpu %d "
"(hw %d) failed with %d\n", cpu, hwcpu, ret);
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
