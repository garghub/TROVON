static inline bool event_is_fab_match(u64 event)
{
event &= 0xff0fe;
return (event == 0x30056 || event == 0x4f052);
}
int isa207_get_constraint(u64 event, unsigned long *maskp, unsigned long *valp)
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
if (pmc >= 5 && base_event != 0x500fa &&
base_event != 0x600f4)
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
int isa207_compute_mmcr(u64 event[], int n_ev,
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
void isa207_disable_pmc(unsigned int pmc, unsigned long mmcr[])
{
if (pmc <= 3)
mmcr[1] &= ~(0xffUL << MMCR1_PMCSEL_SHIFT(pmc + 1));
}
