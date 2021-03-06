unsigned long hv_perf_caps_get(struct hv_perf_caps *caps)
{
unsigned long r;
struct p {
struct hv_get_perf_counter_info_params params;
struct cv_system_performance_capabilities caps;
} __packed __aligned(sizeof(uint64_t));
struct p arg = {
.params = {
.counter_request = cpu_to_be32(
CIR_SYSTEM_PERFORMANCE_CAPABILITIES),
.starting_index = cpu_to_be32(-1),
.counter_info_version_in = 0,
}
};
r = plpar_hcall_norets(H_GET_PERF_COUNTER_INFO,
virt_to_phys(&arg), sizeof(arg));
if (r)
return r;
pr_devel("capability_mask: 0x%x\n", arg.caps.capability_mask);
caps->version = arg.params.counter_info_version_out;
caps->collect_privileged = !!arg.caps.perf_collect_privileged;
caps->ga = !!(arg.caps.capability_mask & CV_CM_GA);
caps->expanded = !!(arg.caps.capability_mask & CV_CM_EXPANDED);
caps->lab = !!(arg.caps.capability_mask & CV_CM_LAB);
return r;
}
