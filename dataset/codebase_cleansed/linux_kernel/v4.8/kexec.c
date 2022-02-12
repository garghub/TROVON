void pseries_kexec_cpu_down(int crash_shutdown, int secondary)
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
xics_kexec_teardown_cpu(secondary);
}
