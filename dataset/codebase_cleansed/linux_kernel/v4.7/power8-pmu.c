static inline bool event_is_fab_match(u64 event)
{
event &= 0xff0fe;
return (event == 0x30056 || event == 0x4f052);
}
static int power8_get_constraint(u64 event, unsigned long *maskp, unsigned long *valp)
{
unsigned int unit, pmc, cache, ebb;
unsigned long mask, value;
mask = value = 0;
if (event & ~EVENT_VALID_MASK)
return -1;
pmc = (event >> EVENT_PMC_SHIFT) & EVENT_PMC_MASK;
unit = (event >> EVENT_UNIT_SHIFT) & EVENT_UNIT_MASK;
cache = (event >> EVENT_CACHE_SEL_SHIFT) & EVENT_CACHE_SEL_MASK;
ebb = (event >> EVENT_EBB_SHIFT) & EVENT_EBB_MASK;
if (pmc) {
u64 base_event;
if (pmc > 6)
return -1;
base_event = event & ~EVENT_LINUX_MASK;
if (pmc >= 5 && base_event != PM_RUN_INST_CMPL &&
base_event != PM_RUN_CYC)
return -1;
mask |= CNST_PMC_MASK(pmc);
value |= CNST_PMC_VAL(pmc);
}
if (pmc <= 4) {
mask |= CNST_NC_MASK;
value |= CNST_NC_VAL;
}
if (unit >= 6 && unit <= 9) {
if (cache & 0x7)
return -1;
} else if (event & EVENT_IS_L1) {
mask |= CNST_L1_QUAL_MASK;
value |= CNST_L1_QUAL_VAL(cache);
}
if (event & EVENT_IS_MARKED) {
mask |= CNST_SAMPLE_MASK;
value |= CNST_SAMPLE_VAL(event >> EVENT_SAMPLE_SHIFT);
}
if (event_is_fab_match(event)) {
mask |= CNST_FAB_MATCH_MASK;
value |= CNST_FAB_MATCH_VAL(event >> EVENT_THR_CTL_SHIFT);
} else {
unsigned int cmp, exp;
cmp = (event >> EVENT_THR_CMP_SHIFT) & EVENT_THR_CMP_MASK;
exp = cmp >> 7;
if (exp && (cmp & 0x60) == 0)
return -1;
mask |= CNST_THRESH_MASK;
value |= CNST_THRESH_VAL(event >> EVENT_THRESH_SHIFT);
}
if (!pmc && ebb)
return -1;
if (event & EVENT_WANTS_BHRB) {
if (!ebb)
return -1;
mask |= CNST_IFM_MASK;
value |= CNST_IFM_VAL(event >> EVENT_IFM_SHIFT);
}
mask |= CNST_EBB_VAL(ebb);
value |= CNST_EBB_MASK;
*maskp = mask;
*valp = value;
return 0;
}
static int power8_compute_mmcr(u64 event[], int n_ev,
unsigned int hwc[], unsigned long mmcr[],
struct perf_event *pevents[])
{
unsigned long mmcra, mmcr1, mmcr2, unit, combine, psel, cache, val;
unsigned int pmc, pmc_inuse;
int i;
pmc_inuse = 0;
for (i = 0; i < n_ev; ++i) {
pmc = (event[i] >> EVENT_PMC_SHIFT) & EVENT_PMC_MASK;
if (pmc)
pmc_inuse |= 1 << pmc;
}
mmcra = MMCRA_SDAR_MODE_TLB;
mmcr1 = mmcr2 = 0;
for (i = 0; i < n_ev; ++i) {
pmc = (event[i] >> EVENT_PMC_SHIFT) & EVENT_PMC_MASK;
unit = (event[i] >> EVENT_UNIT_SHIFT) & EVENT_UNIT_MASK;
combine = (event[i] >> EVENT_COMBINE_SHIFT) & EVENT_COMBINE_MASK;
psel = event[i] & EVENT_PSEL_MASK;
if (!pmc) {
for (pmc = 1; pmc <= 4; ++pmc) {
if (!(pmc_inuse & (1 << pmc)))
break;
}
pmc_inuse |= 1 << pmc;
}
if (pmc <= 4) {
mmcr1 |= unit << MMCR1_UNIT_SHIFT(pmc);
mmcr1 |= combine << MMCR1_COMBINE_SHIFT(pmc);
mmcr1 |= psel << MMCR1_PMCSEL_SHIFT(pmc);
}
if (event[i] & EVENT_IS_L1) {
cache = event[i] >> EVENT_CACHE_SEL_SHIFT;
mmcr1 |= (cache & 1) << MMCR1_IC_QUAL_SHIFT;
cache >>= 1;
mmcr1 |= (cache & 1) << MMCR1_DC_QUAL_SHIFT;
}
if (event[i] & EVENT_IS_MARKED) {
mmcra |= MMCRA_SAMPLE_ENABLE;
val = (event[i] >> EVENT_SAMPLE_SHIFT) & EVENT_SAMPLE_MASK;
if (val) {
mmcra |= (val & 3) << MMCRA_SAMP_MODE_SHIFT;
mmcra |= (val >> 2) << MMCRA_SAMP_ELIG_SHIFT;
}
}
if (event_is_fab_match(event[i])) {
mmcr1 |= ((event[i] >> EVENT_THR_CTL_SHIFT) &
EVENT_THR_CTL_MASK) << MMCR1_FAB_SHIFT;
} else {
val = (event[i] >> EVENT_THR_CTL_SHIFT) & EVENT_THR_CTL_MASK;
mmcra |= val << MMCRA_THR_CTL_SHIFT;
val = (event[i] >> EVENT_THR_SEL_SHIFT) & EVENT_THR_SEL_MASK;
mmcra |= val << MMCRA_THR_SEL_SHIFT;
val = (event[i] >> EVENT_THR_CMP_SHIFT) & EVENT_THR_CMP_MASK;
mmcra |= val << MMCRA_THR_CMP_SHIFT;
}
if (event[i] & EVENT_WANTS_BHRB) {
val = (event[i] >> EVENT_IFM_SHIFT) & EVENT_IFM_MASK;
mmcra |= val << MMCRA_IFM_SHIFT;
}
if (pevents[i]->attr.exclude_user)
mmcr2 |= MMCR2_FCP(pmc);
if (pevents[i]->attr.exclude_hv)
mmcr2 |= MMCR2_FCH(pmc);
if (pevents[i]->attr.exclude_kernel) {
if (cpu_has_feature(CPU_FTR_HVMODE))
mmcr2 |= MMCR2_FCH(pmc);
else
mmcr2 |= MMCR2_FCS(pmc);
}
hwc[i] = pmc - 1;
}
mmcr[0] = 0;
if (pmc_inuse & 2)
mmcr[0] = MMCR0_PMC1CE;
if (pmc_inuse & 0x7c)
mmcr[0] |= MMCR0_PMCjCE;
if (!(pmc_inuse & 0x60))
mmcr[0] |= MMCR0_FC56;
mmcr[1] = mmcr1;
mmcr[2] = mmcra;
mmcr[3] = mmcr2;
return 0;
}
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
static void power8_disable_pmc(unsigned int pmc, unsigned long mmcr[])
{
if (pmc <= 3)
mmcr[1] &= ~(0xffUL << MMCR1_PMCSEL_SHIFT(pmc + 1));
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
