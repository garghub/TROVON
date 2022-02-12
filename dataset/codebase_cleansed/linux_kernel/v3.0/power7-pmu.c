static int power7_get_constraint(u64 event, unsigned long *maskp,
unsigned long *valp)
{
int pmc, sh;
unsigned long mask = 0, value = 0;
pmc = (event >> PM_PMC_SH) & PM_PMC_MSK;
if (pmc) {
if (pmc > 6)
return -1;
sh = (pmc - 1) * 2;
mask |= 2 << sh;
value |= 1 << sh;
if (pmc >= 5 && !(event == 0x500fa || event == 0x600f4))
return -1;
}
if (pmc < 5) {
mask |= 0x8000;
value |= 0x1000;
}
*maskp = mask;
*valp = value;
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
static s64 find_alternative_decode(u64 event)
{
int pmc, psel;
pmc = (event >> PM_PMC_SH) & PM_PMC_MSK;
psel = event & PM_PMCSEL_MSK;
if ((pmc == 2 || pmc == 4) && (psel & ~7) == 0x40)
return event - (1 << PM_PMC_SH) + 8;
if ((pmc == 1 || pmc == 3) && (psel & ~7) == 0x48)
return event + (1 << PM_PMC_SH) - 8;
return -1;
}
static int power7_get_alternatives(u64 event, unsigned int flags, u64 alt[])
{
int i, j, nalt = 1;
s64 ae;
alt[0] = event;
nalt = 1;
i = find_alternative(event);
if (i >= 0) {
for (j = 0; j < MAX_ALT; ++j) {
ae = event_alternatives[i][j];
if (ae && ae != event)
alt[nalt++] = ae;
}
} else {
ae = find_alternative_decode(event);
if (ae > 0)
alt[nalt++] = ae;
}
if (flags & PPMU_ONLY_COUNT_RUN) {
j = nalt;
for (i = 0; i < nalt; ++i) {
switch (alt[i]) {
case 0x1e:
alt[j++] = 0x600f4;
break;
case 0x600f4:
alt[j++] = 0x1e;
break;
case 0x2:
alt[j++] = 0x500fa;
break;
case 0x500fa:
alt[j++] = 0x2;
break;
}
}
nalt = j;
}
return nalt;
}
static int power7_marked_instr_event(u64 event)
{
int pmc, psel;
int unit;
pmc = (event >> PM_PMC_SH) & PM_PMC_MSK;
unit = (event >> PM_UNIT_SH) & PM_UNIT_MSK;
psel = event & PM_PMCSEL_MSK & ~1;
if (pmc >= 5)
return 0;
switch (psel >> 4) {
case 2:
return pmc == 2 || pmc == 4;
case 3:
if (psel == 0x3c)
return pmc == 1;
if (psel == 0x3e)
return pmc != 2;
return 1;
case 4:
case 5:
return unit == 0xd;
case 6:
if (psel == 0x64)
return pmc >= 3;
case 8:
return unit == 0xd;
}
return 0;
}
static int power7_compute_mmcr(u64 event[], int n_ev,
unsigned int hwc[], unsigned long mmcr[])
{
unsigned long mmcr1 = 0;
unsigned long mmcra = MMCRA_SDAR_DCACHE_MISS | MMCRA_SDAR_ERAT_MISS;
unsigned int pmc, unit, combine, l2sel, psel;
unsigned int pmc_inuse = 0;
int i;
for (i = 0; i < n_ev; ++i) {
pmc = (event[i] >> PM_PMC_SH) & PM_PMC_MSK;
if (pmc) {
if (pmc > 6)
return -1;
if (pmc_inuse & (1 << (pmc - 1)))
return -1;
pmc_inuse |= 1 << (pmc - 1);
}
}
for (i = 0; i < n_ev; ++i) {
pmc = (event[i] >> PM_PMC_SH) & PM_PMC_MSK;
unit = (event[i] >> PM_UNIT_SH) & PM_UNIT_MSK;
combine = (event[i] >> PM_COMBINE_SH) & PM_COMBINE_MSK;
l2sel = (event[i] >> PM_L2SEL_SH) & PM_L2SEL_MSK;
psel = event[i] & PM_PMCSEL_MSK;
if (!pmc) {
for (pmc = 0; pmc < 4; ++pmc) {
if (!(pmc_inuse & (1 << pmc)))
break;
}
if (pmc >= 4)
return -1;
pmc_inuse |= 1 << pmc;
} else {
--pmc;
}
if (pmc <= 3) {
mmcr1 |= (unsigned long) unit
<< (MMCR1_TTM0SEL_SH - 4 * pmc);
mmcr1 |= (unsigned long) combine
<< (MMCR1_PMC1_COMBINE_SH - pmc);
mmcr1 |= psel << MMCR1_PMCSEL_SH(pmc);
if (unit == 6)
mmcr1 |= (unsigned long) l2sel
<< MMCR1_L2SEL_SH;
}
if (power7_marked_instr_event(event[i]))
mmcra |= MMCRA_SAMPLE_ENABLE;
hwc[i] = pmc;
}
mmcr[0] = 0;
if (pmc_inuse & 1)
mmcr[0] = MMCR0_PMC1CE;
if (pmc_inuse & 0x3e)
mmcr[0] |= MMCR0_PMCjCE;
mmcr[1] = mmcr1;
mmcr[2] = mmcra;
return 0;
}
static void power7_disable_pmc(unsigned int pmc, unsigned long mmcr[])
{
if (pmc <= 3)
mmcr[1] &= ~(0xffUL << MMCR1_PMCSEL_SH(pmc));
}
static int init_power7_pmu(void)
{
if (!cur_cpu_spec->oprofile_cpu_type ||
strcmp(cur_cpu_spec->oprofile_cpu_type, "ppc64/power7"))
return -ENODEV;
return register_power_pmu(&power7_pmu);
}
