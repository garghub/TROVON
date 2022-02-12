static int power6_marked_instr_event(u64 event)
{
int pmc, psel, ptype;
int bit, byte, unit;
u32 mask;
pmc = (event >> PM_PMC_SH) & PM_PMC_MSK;
psel = (event & PM_PMCSEL_MSK) >> 1;
if (pmc >= 5)
return 0;
bit = -1;
if (psel < sizeof(direct_event_is_marked)) {
ptype = direct_event_is_marked[psel];
if (pmc == 0 || !(ptype & (1 << (pmc - 1))))
return 0;
ptype >>= 4;
if (ptype == 0)
return 1;
if (ptype == 1)
bit = 0;
else
bit = ptype ^ (pmc - 1);
} else if ((psel & 0x48) == 0x40)
bit = psel & 7;
if (!(event & PM_BUSEVENT_MSK) || bit == -1)
return 0;
byte = (event >> PM_BYTE_SH) & PM_BYTE_MSK;
unit = (event >> PM_UNIT_SH) & PM_UNIT_MSK;
mask = marked_bus_events[unit];
return (mask >> (byte * 8 + bit)) & 1;
}
static int p6_compute_mmcr(u64 event[], int n_ev,
unsigned int hwc[], unsigned long mmcr[], struct perf_event *pevents[])
{
unsigned long mmcr1 = 0;
unsigned long mmcra = MMCRA_SDAR_DCACHE_MISS | MMCRA_SDAR_ERAT_MISS;
int i;
unsigned int pmc, ev, b, u, s, psel;
unsigned int ttmset = 0;
unsigned int pmc_inuse = 0;
if (n_ev > 6)
return -1;
for (i = 0; i < n_ev; ++i) {
pmc = (event[i] >> PM_PMC_SH) & PM_PMC_MSK;
if (pmc) {
if (pmc_inuse & (1 << (pmc - 1)))
return -1;
pmc_inuse |= 1 << (pmc - 1);
}
}
for (i = 0; i < n_ev; ++i) {
ev = event[i];
pmc = (ev >> PM_PMC_SH) & PM_PMC_MSK;
if (pmc) {
--pmc;
} else {
for (pmc = 0; pmc < 4; ++pmc)
if (!(pmc_inuse & (1 << pmc)))
break;
if (pmc >= 4)
return -1;
pmc_inuse |= 1 << pmc;
}
hwc[i] = pmc;
psel = ev & PM_PMCSEL_MSK;
if (ev & PM_BUSEVENT_MSK) {
b = (ev >> PM_BYTE_SH) & PM_BYTE_MSK;
u = (ev >> PM_UNIT_SH) & PM_UNIT_MSK;
if ((ttmset & (1 << b)) && MMCR1_TTMSEL(mmcr1, b) != u)
return -1;
mmcr1 |= (unsigned long)u << MMCR1_TTMSEL_SH(b);
ttmset |= 1 << b;
if (u == 5) {
s = (ev >> PM_SUBUNIT_SH) & PM_SUBUNIT_MSK;
if ((ttmset & 0x10) &&
MMCR1_NESTSEL(mmcr1) != s)
return -1;
ttmset |= 0x10;
mmcr1 |= (unsigned long)s << MMCR1_NESTSEL_SH;
}
if (0x30 <= psel && psel <= 0x3d) {
if (b >= 2)
mmcr1 |= MMCR1_PMC1_ADDR_SEL >> pmc;
}
if (pmc >= 2 && (psel & 0x90) == 0x80)
psel ^= 0x20;
}
if (ev & PM_LLA) {
mmcr1 |= MMCR1_PMC1_LLA >> pmc;
if (ev & PM_LLAV)
mmcr1 |= MMCR1_PMC1_LLA_VALUE >> pmc;
}
if (power6_marked_instr_event(event[i]))
mmcra |= MMCRA_SAMPLE_ENABLE;
if (pmc < 4)
mmcr1 |= (unsigned long)psel << MMCR1_PMCSEL_SH(pmc);
}
mmcr[0] = 0;
if (pmc_inuse & 1)
mmcr[0] = MMCR0_PMC1CE;
if (pmc_inuse & 0xe)
mmcr[0] |= MMCR0_PMCjCE;
mmcr[1] = mmcr1;
mmcr[2] = mmcra;
return 0;
}
static int p6_get_constraint(u64 event, unsigned long *maskp,
unsigned long *valp)
{
int pmc, byte, sh, subunit;
unsigned long mask = 0, value = 0;
pmc = (event >> PM_PMC_SH) & PM_PMC_MSK;
if (pmc) {
if (pmc > 4 && !(event == 0x500009 || event == 0x600005))
return -1;
sh = (pmc - 1) * 2;
mask |= 2 << sh;
value |= 1 << sh;
}
if (event & PM_BUSEVENT_MSK) {
byte = (event >> PM_BYTE_SH) & PM_BYTE_MSK;
sh = byte * 4 + (16 - PM_UNIT_SH);
mask |= PM_UNIT_MSKS << sh;
value |= (unsigned long)(event & PM_UNIT_MSKS) << sh;
if ((event & PM_UNIT_MSKS) == (5 << PM_UNIT_SH)) {
subunit = (event >> PM_SUBUNIT_SH) & PM_SUBUNIT_MSK;
mask |= (unsigned long)PM_SUBUNIT_MSK << 32;
value |= (unsigned long)subunit << 32;
}
}
if (pmc <= 4) {
mask |= 0x8000;
value |= 0x1000;
}
*maskp = mask;
*valp = value;
return 0;
}
static int p6_limited_pmc_event(u64 event)
{
int pmc = (event >> PM_PMC_SH) & PM_PMC_MSK;
return pmc == 5 || pmc == 6;
}
static int find_alternatives_list(u64 event)
{
int i, j;
unsigned int alt;
for (i = 0; i < ARRAY_SIZE(event_alternatives); ++i) {
if (event < event_alternatives[i][0])
return -1;
for (j = 0; j < MAX_ALT; ++j) {
alt = event_alternatives[i][j];
if (!alt || event < alt)
break;
if (event == alt)
return i;
}
}
return -1;
}
static int p6_get_alternatives(u64 event, unsigned int flags, u64 alt[])
{
int i, j, nlim;
unsigned int psel, pmc;
unsigned int nalt = 1;
u64 aevent;
alt[0] = event;
nlim = p6_limited_pmc_event(event);
i = find_alternatives_list(event);
if (i >= 0) {
for (j = 0; j < MAX_ALT; ++j) {
aevent = event_alternatives[i][j];
if (!aevent)
break;
if (aevent != event)
alt[nalt++] = aevent;
nlim += p6_limited_pmc_event(aevent);
}
} else {
psel = event & (PM_PMCSEL_MSK & ~1);
pmc = (event >> PM_PMC_SH) & PM_PMC_MSK;
if (pmc && (psel == 0x32 || psel == 0x34))
alt[nalt++] = ((event ^ 0x6) & ~PM_PMC_MSKS) |
((5 - pmc) << PM_PMC_SH);
if (pmc && (psel == 0x38 || psel == 0x3a))
alt[nalt++] = ((event ^ 0x2) & ~PM_PMC_MSKS) |
((pmc > 2? pmc - 2: pmc + 2) << PM_PMC_SH);
}
if (flags & PPMU_ONLY_COUNT_RUN) {
j = nalt;
for (i = 0; i < nalt; ++i) {
switch (alt[i]) {
case 0x1e:
alt[j++] = 0x600005;
++nlim;
break;
case 0x10000a:
alt[j++] = 0x1e;
break;
case 2:
alt[j++] = 0x500009;
++nlim;
break;
case 0x500009:
alt[j++] = 2;
break;
case 0x10000e:
alt[j++] = 0x4000f4;
break;
case 0x4000f4:
alt[j++] = 0x10000e;
break;
}
}
nalt = j;
}
if (!(flags & PPMU_LIMITED_PMC_OK) && nlim) {
j = 0;
for (i = 0; i < nalt; ++i) {
if (!p6_limited_pmc_event(alt[i])) {
alt[j] = alt[i];
++j;
}
}
nalt = j;
} else if ((flags & PPMU_LIMITED_PMC_REQD) && nlim < nalt) {
j = 0;
for (i = 0; i < nalt; ++i) {
if (p6_limited_pmc_event(alt[i])) {
alt[j] = alt[i];
++j;
}
}
nalt = j;
}
return nalt;
}
static void p6_disable_pmc(unsigned int pmc, unsigned long mmcr[])
{
if (pmc <= 3)
mmcr[1] &= ~(0xffUL << MMCR1_PMCSEL_SH(pmc));
}
static int __init init_power6_pmu(void)
{
if (!cur_cpu_spec->oprofile_cpu_type ||
strcmp(cur_cpu_spec->oprofile_cpu_type, "ppc64/power6"))
return -ENODEV;
return register_power_pmu(&power6_pmu);
}
