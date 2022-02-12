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
int rc;
if (!cur_cpu_spec->oprofile_cpu_type ||
strcmp(cur_cpu_spec->oprofile_cpu_type, "ppc64/power9"))
return -ENODEV;
rc = register_power_pmu(&power9_pmu);
if (rc)
return rc;
cur_cpu_spec->cpu_user_features2 |= PPC_FEATURE2_EBB;
return 0;
}
