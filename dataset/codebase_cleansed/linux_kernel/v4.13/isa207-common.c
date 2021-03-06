static inline bool event_is_fab_match(u64 event)
{
event &= 0xff0fe;
return (event == 0x30056 || event == 0x4f052);
}
static bool is_event_valid(u64 event)
{
u64 valid_mask = EVENT_VALID_MASK;
if (cpu_has_feature(CPU_FTR_ARCH_300) && !cpu_has_feature(CPU_FTR_POWER9_DD1))
valid_mask = p9_EVENT_VALID_MASK;
return !(event & ~valid_mask);
}
static inline bool is_event_marked(u64 event)
{
if (event & EVENT_IS_MARKED)
return true;
return false;
}
static void mmcra_sdar_mode(u64 event, unsigned long *mmcra)
{
if (cpu_has_feature(CPU_FTR_ARCH_300)) {
if (is_event_marked(event) || (*mmcra & MMCRA_SAMPLE_ENABLE))
*mmcra &= MMCRA_SDAR_MODE_NO_UPDATES;
else if (!cpu_has_feature(CPU_FTR_POWER9_DD1) && p9_SDAR_MODE(event))
*mmcra |= p9_SDAR_MODE(event) << MMCRA_SDAR_MODE_SHIFT;
else
*mmcra |= MMCRA_SDAR_MODE_TLB;
} else
*mmcra |= MMCRA_SDAR_MODE_TLB;
}
static u64 thresh_cmp_val(u64 value)
{
if (cpu_has_feature(CPU_FTR_ARCH_300) && !cpu_has_feature(CPU_FTR_POWER9_DD1))
return value << p9_MMCRA_THR_CMP_SHIFT;
return value << MMCRA_THR_CMP_SHIFT;
}
static unsigned long combine_from_event(u64 event)
{
if (cpu_has_feature(CPU_FTR_ARCH_300) && !cpu_has_feature(CPU_FTR_POWER9_DD1))
return p9_EVENT_COMBINE(event);
return EVENT_COMBINE(event);
}
static unsigned long combine_shift(unsigned long pmc)
{
if (cpu_has_feature(CPU_FTR_ARCH_300) && !cpu_has_feature(CPU_FTR_POWER9_DD1))
return p9_MMCR1_COMBINE_SHIFT(pmc);
return MMCR1_COMBINE_SHIFT(pmc);
}
static inline bool event_is_threshold(u64 event)
{
return (event >> EVENT_THR_SEL_SHIFT) & EVENT_THR_SEL_MASK;
}
static bool is_thresh_cmp_valid(u64 event)
{
unsigned int cmp, exp;
cmp = (event >> EVENT_THR_CMP_SHIFT) & EVENT_THR_CMP_MASK;
exp = cmp >> 7;
if (exp && (cmp & 0x60) == 0)
return false;
return true;
}
static inline u64 isa207_find_source(u64 idx, u32 sub_idx)
{
u64 ret = PERF_MEM_NA;
switch(idx) {
case 0:
break;
case 1:
ret = PH(LVL, L1);
break;
case 2:
ret = PH(LVL, L2);
break;
case 3:
ret = PH(LVL, L3);
break;
case 4:
if (sub_idx <= 1)
ret = PH(LVL, LOC_RAM);
else if (sub_idx > 1 && sub_idx <= 2)
ret = PH(LVL, REM_RAM1);
else
ret = PH(LVL, REM_RAM2);
ret |= P(SNOOP, HIT);
break;
case 5:
ret = PH(LVL, REM_CCE1);
if ((sub_idx == 0) || (sub_idx == 2) || (sub_idx == 4))
ret |= P(SNOOP, HIT);
else if ((sub_idx == 1) || (sub_idx == 3) || (sub_idx == 5))
ret |= P(SNOOP, HITM);
break;
case 6:
ret = PH(LVL, REM_CCE2);
if ((sub_idx == 0) || (sub_idx == 2))
ret |= P(SNOOP, HIT);
else if ((sub_idx == 1) || (sub_idx == 3))
ret |= P(SNOOP, HITM);
break;
case 7:
ret = PM(LVL, L1);
break;
}
return ret;
}
void isa207_get_mem_data_src(union perf_mem_data_src *dsrc, u32 flags,
struct pt_regs *regs)
{
u64 idx;
u32 sub_idx;
u64 sier;
u64 val;
if (!(flags & PPMU_HAS_SIER)) {
dsrc->val = 0;
return;
}
sier = mfspr(SPRN_SIER);
val = (sier & ISA207_SIER_TYPE_MASK) >> ISA207_SIER_TYPE_SHIFT;
if (val == 1 || val == 2) {
idx = (sier & ISA207_SIER_LDST_MASK) >> ISA207_SIER_LDST_SHIFT;
sub_idx = (sier & ISA207_SIER_DATA_SRC_MASK) >> ISA207_SIER_DATA_SRC_SHIFT;
dsrc->val = isa207_find_source(idx, sub_idx);
dsrc->val |= (val == 1) ? P(OP, LOAD) : P(OP, STORE);
}
}
void isa207_get_mem_weight(u64 *weight)
{
u64 mmcra = mfspr(SPRN_MMCRA);
u64 exp = MMCRA_THR_CTR_EXP(mmcra);
u64 mantissa = MMCRA_THR_CTR_MANT(mmcra);
*weight = mantissa << (2 * exp);
}
int isa207_get_constraint(u64 event, unsigned long *maskp, unsigned long *valp)
{
unsigned int unit, pmc, cache, ebb;
unsigned long mask, value;
mask = value = 0;
if (!is_event_valid(event))
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
if (is_event_marked(event)) {
mask |= CNST_SAMPLE_MASK;
value |= CNST_SAMPLE_VAL(event >> EVENT_SAMPLE_SHIFT);
}
if (cpu_has_feature(CPU_FTR_ARCH_300)) {
if (event_is_threshold(event) && is_thresh_cmp_valid(event)) {
mask |= CNST_THRESH_MASK;
value |= CNST_THRESH_VAL(event >> EVENT_THRESH_SHIFT);
}
} else {
if (event_is_fab_match(event)) {
mask |= CNST_FAB_MATCH_MASK;
value |= CNST_FAB_MATCH_VAL(event >> EVENT_THR_CTL_SHIFT);
} else {
if (!is_thresh_cmp_valid(event))
return -1;
mask |= CNST_THRESH_MASK;
value |= CNST_THRESH_VAL(event >> EVENT_THRESH_SHIFT);
}
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
mmcra = mmcr1 = mmcr2 = 0;
for (i = 0; i < n_ev; ++i) {
pmc = (event[i] >> EVENT_PMC_SHIFT) & EVENT_PMC_MASK;
unit = (event[i] >> EVENT_UNIT_SHIFT) & EVENT_UNIT_MASK;
combine = combine_from_event(event[i]);
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
mmcr1 |= combine << combine_shift(pmc);
mmcr1 |= psel << MMCR1_PMCSEL_SHIFT(pmc);
}
mmcra_sdar_mode(event[i], &mmcra);
if (event[i] & EVENT_IS_L1) {
cache = event[i] >> EVENT_CACHE_SEL_SHIFT;
mmcr1 |= (cache & 1) << MMCR1_IC_QUAL_SHIFT;
cache >>= 1;
mmcr1 |= (cache & 1) << MMCR1_DC_QUAL_SHIFT;
}
if (is_event_marked(event[i])) {
mmcra |= MMCRA_SAMPLE_ENABLE;
val = (event[i] >> EVENT_SAMPLE_SHIFT) & EVENT_SAMPLE_MASK;
if (val) {
mmcra |= (val & 3) << MMCRA_SAMP_MODE_SHIFT;
mmcra |= (val >> 2) << MMCRA_SAMP_ELIG_SHIFT;
}
}
if (!cpu_has_feature(CPU_FTR_ARCH_300) && event_is_fab_match(event[i])) {
mmcr1 |= ((event[i] >> EVENT_THR_CTL_SHIFT) &
EVENT_THR_CTL_MASK) << MMCR1_FAB_SHIFT;
} else {
val = (event[i] >> EVENT_THR_CTL_SHIFT) & EVENT_THR_CTL_MASK;
mmcra |= val << MMCRA_THR_CTL_SHIFT;
val = (event[i] >> EVENT_THR_SEL_SHIFT) & EVENT_THR_SEL_MASK;
mmcra |= val << MMCRA_THR_SEL_SHIFT;
val = (event[i] >> EVENT_THR_CMP_SHIFT) & EVENT_THR_CMP_MASK;
mmcra |= thresh_cmp_val(val);
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
static int find_alternative(u64 event, const unsigned int ev_alt[][MAX_ALT], int size)
{
int i, j;
for (i = 0; i < size; ++i) {
if (event < ev_alt[i][0])
break;
for (j = 0; j < MAX_ALT && ev_alt[i][j]; ++j)
if (event == ev_alt[i][j])
return i;
}
return -1;
}
int isa207_get_alternatives(u64 event, u64 alt[],
const unsigned int ev_alt[][MAX_ALT], int size)
{
int i, j, num_alt = 0;
u64 alt_event;
alt[num_alt++] = event;
i = find_alternative(event, ev_alt, size);
if (i >= 0) {
for (j = 0; j < MAX_ALT; ++j) {
alt_event = ev_alt[i][j];
if (alt_event && alt_event != event)
alt[num_alt++] = alt_event;
}
}
return num_alt;
}
