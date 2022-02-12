static int power5p_get_constraint(u64 event, unsigned long *maskp,
unsigned long *valp)
{
int pmc, byte, unit, sh;
int bit, fmask;
unsigned long mask = 0, value = 0;
pmc = (event >> PM_PMC_SH) & PM_PMC_MSK;
if (pmc) {
if (pmc > 6)
return -1;
sh = (pmc - 1) * 2;
mask |= 2 << sh;
value |= 1 << sh;
if (pmc >= 5 && !(event == 0x500009 || event == 0x600005))
return -1;
}
if (event & PM_BUSEVENT_MSK) {
unit = (event >> PM_UNIT_SH) & PM_UNIT_MSK;
if (unit > PM_LASTUNIT)
return -1;
if (unit == PM_ISU0_ALT)
unit = PM_ISU0;
mask |= unit_cons[unit][0];
value |= unit_cons[unit][1];
byte = (event >> PM_BYTE_SH) & PM_BYTE_MSK;
if (byte >= 4) {
if (unit != PM_LSU1)
return -1;
++unit;
byte &= 3;
}
if (unit == PM_GRS) {
bit = event & 7;
fmask = (bit == 6)? 7: 3;
sh = grsel_shift[bit];
mask |= (unsigned long)fmask << sh;
value |= (unsigned long)((event >> PM_GRS_SH) & fmask)
<< sh;
}
mask |= 0xfUL << (24 - 4 * byte);
value |= (unsigned long)unit << (24 - 4 * byte);
}
if (pmc < 5) {
mask |= 0x8000000000000ul;
value |= 0x1000000000000ul;
}
*maskp = mask;
*valp = value;
return 0;
}
static int power5p_limited_pmc_event(u64 event)
{
int pmc = (event >> PM_PMC_SH) & PM_PMC_MSK;
return pmc == 5 || pmc == 6;
}
static int find_alternative(unsigned int event)
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
static s64 find_alternative_bdecode(u64 event)
{
int pmc, altpmc, pp, j;
pmc = (event >> PM_PMC_SH) & PM_PMC_MSK;
if (pmc == 0 || pmc > 4)
return -1;
altpmc = 5 - pmc;
pp = event & PM_PMCSEL_MSK;
for (j = 0; j < 4; ++j) {
if (bytedecode_alternatives[pmc - 1][j] == pp) {
return (event & ~(PM_PMC_MSKS | PM_PMCSEL_MSK)) |
(altpmc << PM_PMC_SH) |
bytedecode_alternatives[altpmc - 1][j];
}
}
if (pmc == 1 && (pp == 0x0d || pp == 0x0e))
return event + (2 << PM_PMC_SH) + (0x2e - 0x0d);
if (pmc == 3 && (pp == 0x2e || pp == 0x2f))
return event - (2 << PM_PMC_SH) - (0x2e - 0x0d);
if (pp == 0x10 || pp == 0x28)
return ((event ^ (0x10 ^ 0x28)) & ~PM_PMC_MSKS) |
(altpmc << PM_PMC_SH);
return -1;
}
static int power5p_get_alternatives(u64 event, unsigned int flags, u64 alt[])
{
int i, j, nalt = 1;
int nlim;
s64 ae;
alt[0] = event;
nalt = 1;
nlim = power5p_limited_pmc_event(event);
i = find_alternative(event);
if (i >= 0) {
for (j = 0; j < MAX_ALT; ++j) {
ae = event_alternatives[i][j];
if (ae && ae != event)
alt[nalt++] = ae;
nlim += power5p_limited_pmc_event(ae);
}
} else {
ae = find_alternative_bdecode(event);
if (ae > 0)
alt[nalt++] = ae;
}
if (flags & PPMU_ONLY_COUNT_RUN) {
j = nalt;
for (i = 0; i < nalt; ++i) {
switch (alt[i]) {
case 0xf:
alt[j++] = 0x600005;
++nlim;
break;
case 0x600005:
alt[j++] = 0xf;
break;
case 0x100009:
alt[j++] = 0x500009;
++nlim;
break;
case 0x500009:
alt[j++] = 0x100009;
alt[j++] = 0x200009;
break;
}
}
nalt = j;
}
if (!(flags & PPMU_LIMITED_PMC_OK) && nlim) {
j = 0;
for (i = 0; i < nalt; ++i) {
if (!power5p_limited_pmc_event(alt[i])) {
alt[j] = alt[i];
++j;
}
}
nalt = j;
} else if ((flags & PPMU_LIMITED_PMC_REQD) && nlim < nalt) {
j = 0;
for (i = 0; i < nalt; ++i) {
if (power5p_limited_pmc_event(alt[i])) {
alt[j] = alt[i];
++j;
}
}
nalt = j;
}
return nalt;
}
static int power5p_marked_instr_event(u64 event)
{
int pmc, psel;
int bit, byte, unit;
u32 mask;
pmc = (event >> PM_PMC_SH) & PM_PMC_MSK;
psel = event & PM_PMCSEL_MSK;
if (pmc >= 5)
return 0;
bit = -1;
if (psel < sizeof(direct_event_is_marked)) {
if (direct_event_is_marked[psel] & (1 << pmc))
return 1;
if (direct_event_is_marked[psel] & 0x80)
bit = 4;
else if (psel == 0x08)
bit = pmc - 1;
else if (psel == 0x10)
bit = 4 - pmc;
else if (psel == 0x1b && (pmc == 1 || pmc == 3))
bit = 4;
} else if ((psel & 0x48) == 0x40) {
bit = psel & 7;
} else if (psel == 0x28) {
bit = pmc - 1;
} else if (pmc == 3 && (psel == 0x2e || psel == 0x2f)) {
bit = 4;
}
if (!(event & PM_BUSEVENT_MSK) || bit == -1)
return 0;
byte = (event >> PM_BYTE_SH) & PM_BYTE_MSK;
unit = (event >> PM_UNIT_SH) & PM_UNIT_MSK;
if (unit == PM_LSU0) {
mask = 0x5dff00;
} else if (unit == PM_LSU1 && byte >= 4) {
byte -= 4;
mask = 0x5f11c000;
} else
return 0;
return (mask >> (byte * 8 + bit)) & 1;
}
static int power5p_compute_mmcr(u64 event[], int n_ev,
unsigned int hwc[], unsigned long mmcr[], struct perf_event *pevents[])
{
unsigned long mmcr1 = 0;
unsigned long mmcra = 0;
unsigned int pmc, unit, byte, psel;
unsigned int ttm;
int i, isbus, bit, grsel;
unsigned int pmc_inuse = 0;
unsigned char busbyte[4];
unsigned char unituse[16];
int ttmuse;
if (n_ev > 6)
return -1;
memset(busbyte, 0, sizeof(busbyte));
memset(unituse, 0, sizeof(unituse));
for (i = 0; i < n_ev; ++i) {
pmc = (event[i] >> PM_PMC_SH) & PM_PMC_MSK;
if (pmc) {
if (pmc > 6)
return -1;
if (pmc_inuse & (1 << (pmc - 1)))
return -1;
pmc_inuse |= 1 << (pmc - 1);
}
if (event[i] & PM_BUSEVENT_MSK) {
unit = (event[i] >> PM_UNIT_SH) & PM_UNIT_MSK;
byte = (event[i] >> PM_BYTE_SH) & PM_BYTE_MSK;
if (unit > PM_LASTUNIT)
return -1;
if (unit == PM_ISU0_ALT)
unit = PM_ISU0;
if (byte >= 4) {
if (unit != PM_LSU1)
return -1;
++unit;
byte &= 3;
}
if (busbyte[byte] && busbyte[byte] != unit)
return -1;
busbyte[byte] = unit;
unituse[unit] = 1;
}
}
if (unituse[PM_ISU0] &
(unituse[PM_FPU] | unituse[PM_IFU] | unituse[PM_ISU1])) {
unituse[PM_ISU0_ALT] = 1;
unituse[PM_ISU0] = 0;
}
ttmuse = 0;
for (i = PM_FPU; i <= PM_ISU1; ++i) {
if (!unituse[i])
continue;
if (ttmuse++)
return -1;
mmcr1 |= (unsigned long)i << MMCR1_TTM0SEL_SH;
}
ttmuse = 0;
for (; i <= PM_GRS; ++i) {
if (!unituse[i])
continue;
if (ttmuse++)
return -1;
mmcr1 |= (unsigned long)(i & 3) << MMCR1_TTM1SEL_SH;
}
if (ttmuse > 1)
return -1;
for (byte = 0; byte < 4; ++byte) {
unit = busbyte[byte];
if (!unit)
continue;
if (unit == PM_ISU0 && unituse[PM_ISU0_ALT]) {
unit = PM_ISU0_ALT;
} else if (unit == PM_LSU1 + 1) {
mmcr1 |= 1ul << (MMCR1_TTM3SEL_SH + 3 - byte);
}
ttm = unit >> 2;
mmcr1 |= (unsigned long)ttm
<< (MMCR1_TD_CP_DBG0SEL_SH - 2 * byte);
}
for (i = 0; i < n_ev; ++i) {
pmc = (event[i] >> PM_PMC_SH) & PM_PMC_MSK;
unit = (event[i] >> PM_UNIT_SH) & PM_UNIT_MSK;
byte = (event[i] >> PM_BYTE_SH) & PM_BYTE_MSK;
psel = event[i] & PM_PMCSEL_MSK;
isbus = event[i] & PM_BUSEVENT_MSK;
if (!pmc) {
for (pmc = 0; pmc < 4; ++pmc) {
if (!(pmc_inuse & (1 << pmc)))
break;
}
if (pmc >= 4)
return -1;
pmc_inuse |= 1 << pmc;
} else if (pmc <= 4) {
--pmc;
if (isbus && (byte & 2) &&
(psel == 8 || psel == 0x10 || psel == 0x28))
mmcr1 |= 1ul << (MMCR1_PMC1_ADDER_SEL_SH - pmc);
} else {
--pmc;
}
if (isbus && unit == PM_GRS) {
bit = psel & 7;
grsel = (event[i] >> PM_GRS_SH) & PM_GRS_MSK;
mmcr1 |= (unsigned long)grsel << grsel_shift[bit];
}
if (power5p_marked_instr_event(event[i]))
mmcra |= MMCRA_SAMPLE_ENABLE;
if ((psel & 0x58) == 0x40 && (byte & 1) != ((pmc >> 1) & 1))
psel |= 0x10;
if (pmc <= 3)
mmcr1 |= psel << MMCR1_PMCSEL_SH(pmc);
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
static void power5p_disable_pmc(unsigned int pmc, unsigned long mmcr[])
{
if (pmc <= 3)
mmcr[1] &= ~(0x7fUL << MMCR1_PMCSEL_SH(pmc));
}
static int __init init_power5p_pmu(void)
{
if (!cur_cpu_spec->oprofile_cpu_type ||
(strcmp(cur_cpu_spec->oprofile_cpu_type, "ppc64/power5+")
&& strcmp(cur_cpu_spec->oprofile_cpu_type, "ppc64/power5++")))
return -ENODEV;
return register_power_pmu(&power5p_pmu);
}
