static int find_alternative(u64 event)
{
int i, j;
for (i = 0; i < ARRAY_SIZE(event_alternatives); ++i) {
if (event < event_alternatives[i][0])
break;
for (j = 0; j < MAX_ALT && event_alternatives[i][j]; ++j)
if (event == event_alternatives[i][j])
return i;
}
return -1;
}
static int power8_get_alternatives(u64 event, unsigned int flags, u64 alt[])
{
int i, j, num_alt = 0;
u64 alt_event;
alt[num_alt++] = event;
i = find_alternative(event);
if (i >= 0) {
for (j = 0; j < MAX_ALT; ++j) {
alt_event = event_alternatives[i][j];
if (alt_event && alt_event != event)
alt[num_alt++] = alt_event;
}
}
if (flags & PPMU_ONLY_COUNT_RUN) {
j = num_alt;
for (i = 0; i < num_alt; ++i) {
switch (alt[i]) {
case PM_CYC:
alt[j++] = PM_RUN_CYC;
break;
case PM_RUN_CYC:
alt[j++] = PM_CYC;
break;
case PM_INST_CMPL:
alt[j++] = PM_RUN_INST_CMPL;
break;
case PM_RUN_INST_CMPL:
alt[j++] = PM_INST_CMPL;
break;
}
}
num_alt = j;
}
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
