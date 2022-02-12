static int power9_get_alternatives(u64 event, unsigned int flags, u64 alt[])
{
int num_alt = 0;
num_alt = isa207_get_alternatives(event, alt, power9_event_alternatives,
(int)ARRAY_SIZE(power9_event_alternatives));
return num_alt;
}
static u64 power9_bhrb_filter_map(u64 branch_sample_type)
{
u64 pmu_bhrb_filter = 0;
if (branch_sample_type & PERF_SAMPLE_BRANCH_ANY)
return pmu_bhrb_filter;
if (branch_sample_type & PERF_SAMPLE_BRANCH_ANY_RETURN)
return -1;
if (branch_sample_type & PERF_SAMPLE_BRANCH_IND_CALL)
return -1;
if (branch_sample_type & PERF_SAMPLE_BRANCH_CALL)
return -1;
if (branch_sample_type & PERF_SAMPLE_BRANCH_ANY_CALL) {
pmu_bhrb_filter |= POWER9_MMCRA_IFM1;
return pmu_bhrb_filter;
}
return -1;
}
static void power9_config_bhrb(u64 pmu_bhrb_filter)
{
mtspr(SPRN_MMCRA, (mfspr(SPRN_MMCRA) | pmu_bhrb_filter));
}
static int __init init_power9_pmu(void)
{
int rc = 0;
if (!cur_cpu_spec->oprofile_cpu_type ||
strcmp(cur_cpu_spec->oprofile_cpu_type, "ppc64/power9"))
return -ENODEV;
if (cpu_has_feature(CPU_FTR_POWER9_DD1)) {
EVENT_VAR(PM_INST_CMPL, _g).id = PM_INST_DISP;
rc = register_power_pmu(&power9_isa207_pmu);
} else {
rc = register_power_pmu(&power9_pmu);
}
if (rc)
return rc;
cur_cpu_spec->cpu_user_features2 |= PPC_FEATURE2_EBB;
return 0;
}
