static int power8_get_alternatives(u64 event, unsigned int flags, u64 alt[])
{
int num_alt = 0;
num_alt = isa207_get_alternatives(event, alt,
ARRAY_SIZE(event_alternatives), flags,
event_alternatives);
return num_alt;
}
static u64 power8_bhrb_filter_map(u64 branch_sample_type)
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
pmu_bhrb_filter |= POWER8_MMCRA_IFM1;
return pmu_bhrb_filter;
}
return -1;
}
static void power8_config_bhrb(u64 pmu_bhrb_filter)
{
mtspr(SPRN_MMCRA, (mfspr(SPRN_MMCRA) | pmu_bhrb_filter));
}
static int __init init_power8_pmu(void)
{
int rc;
if (!cur_cpu_spec->oprofile_cpu_type ||
strcmp(cur_cpu_spec->oprofile_cpu_type, "ppc64/power8"))
return -ENODEV;
rc = register_power_pmu(&power8_pmu);
if (rc)
return rc;
cur_cpu_spec->cpu_user_features2 |= PPC_FEATURE2_EBB;
if (cpu_has_feature(CPU_FTR_PMAO_BUG))
pr_info("PMAO restore workaround active.\n");
return 0;
}
