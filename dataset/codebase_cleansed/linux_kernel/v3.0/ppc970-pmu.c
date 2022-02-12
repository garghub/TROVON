static int p970_marked_instr_event(u64 event)
{
int pmc, psel, unit, byte, bit;
unsigned int mask;
pmc = (event >> PM_PMC_SH) & PM_PMC_MSK;
psel = event & PM_PMCSEL_MSK;
if (pmc) {
if (direct_marked_event[pmc - 1] & (1 << psel))
return 1;
if (psel == 0)
bit = (pmc <= 4)? pmc - 1: 8 - pmc;
else if (psel == 7 || psel == 13)
bit = 4;
else
return 0;
} else
bit = psel;
byte = (event >> PM_BYTE_SH) & PM_BYTE_MSK;
unit = (event >> PM_UNIT_SH) & PM_UNIT_MSK;
mask = 0;
switch (unit) {
case PM_VPU:
mask = 0x4c;
break;
case PM_LSU0:
mask = 0x085dff00;
break;
case PM_LSU1L:
mask = 0x50 << 24;
break;
}
return (mask >> (byte * 8 + bit)) & 1;
}
static int p970_get_constraint(u64 event, unsigned long *maskp,
unsigned long *valp)
{
int pmc, byte, unit, sh, spcsel;
unsigned long mask = 0, value = 0;
int grp = -1;
pmc = (event >> PM_PMC_SH) & PM_PMC_MSK;
if (pmc) {
if (pmc > 8)
return -1;
sh = (pmc - 1) * 2;
mask |= 2 << sh;
value |= 1 << sh;
grp = ((pmc - 1) >> 1) & 1;
}
unit = (event >> PM_UNIT_SH) & PM_UNIT_MSK;
if (unit) {
if (unit > PM_LASTUNIT)
return -1;
mask |= unit_cons[unit][0];
value |= unit_cons[unit][1];
byte = (event >> PM_BYTE_SH) & PM_BYTE_MSK;
if (!pmc)
grp = byte & 1;
mask |= 0xfULL << (28 - 4 * byte);
value |= (unsigned long)unit << (28 - 4 * byte);
}
if (grp == 0) {
mask |= 0x8000000000ull;
value |= 0x1000000000ull;
} else if (grp == 1) {
mask |= 0x800000000ull;
value |= 0x100000000ull;
}
spcsel = (event >> PM_SPCSEL_SH) & PM_SPCSEL_MSK;
if (spcsel) {
mask |= 3ull << 48;
value |= (unsigned long)spcsel << 48;
}
*maskp = mask;
*valp = value;
return 0;
}
static int p970_get_alternatives(u64 event, unsigned int flags, u64 alt[])
{
alt[0] = event;
if (event == 0x2002 || event == 0x3002) {
alt[1] = event ^ 0x1000;
return 2;
}
return 1;
}
static int p970_compute_mmcr(u64 event[], int n_ev,
unsigned int hwc[], unsigned long mmcr[])
{
unsigned long mmcr0 = 0, mmcr1 = 0, mmcra = 0;
unsigned int pmc, unit, byte, psel;
unsigned int ttm, grp;
unsigned int pmc_inuse = 0;
unsigned int pmc_grp_use[2];
unsigned char busbyte[4];
unsigned char unituse[16];
unsigned char unitmap[] = { 0, 0<<3, 3<<3, 1<<3, 2<<3, 0|4, 3|4 };
unsigned char ttmuse[2];
unsigned char pmcsel[8];
int i;
int spcsel;
if (n_ev > 8)
return -1;
pmc_grp_use[0] = pmc_grp_use[1] = 0;
memset(busbyte, 0, sizeof(busbyte));
memset(unituse, 0, sizeof(unituse));
for (i = 0; i < n_ev; ++i) {
pmc = (event[i] >> PM_PMC_SH) & PM_PMC_MSK;
if (pmc) {
if (pmc_inuse & (1 << (pmc - 1)))
return -1;
pmc_inuse |= 1 << (pmc - 1);
++pmc_grp_use[((pmc - 1) >> 1) & 1];
}
unit = (event[i] >> PM_UNIT_SH) & PM_UNIT_MSK;
byte = (event[i] >> PM_BYTE_SH) & PM_BYTE_MSK;
if (unit) {
if (unit > PM_LASTUNIT)
return -1;
if (!pmc)
++pmc_grp_use[byte & 1];
if (busbyte[byte] && busbyte[byte] != unit)
return -1;
busbyte[byte] = unit;
unituse[unit] = 1;
}
}
if (pmc_grp_use[0] > 4 || pmc_grp_use[1] > 4)
return -1;
if (unituse[PM_ISU] &
(unituse[PM_FPU] | unituse[PM_IFU] | unituse[PM_VPU]))
unitmap[PM_ISU] = 2 | 4;
ttmuse[0] = ttmuse[1] = 0;
for (i = PM_FPU; i <= PM_STS; ++i) {
if (!unituse[i])
continue;
ttm = unitmap[i];
++ttmuse[(ttm >> 2) & 1];
mmcr1 |= (unsigned long)(ttm & ~4) << MMCR1_TTM1SEL_SH;
}
if (ttmuse[0] > 1 || ttmuse[1] > 1)
return -1;
for (byte = 0; byte < 4; ++byte) {
unit = busbyte[byte];
if (!unit)
continue;
if (unit <= PM_STS)
ttm = (unitmap[unit] >> 2) & 1;
else if (unit == PM_LSU0)
ttm = 2;
else {
ttm = 3;
if (unit == PM_LSU1L && byte >= 2)
mmcr1 |= 1ull << (MMCR1_TTM3SEL_SH + 3 - byte);
}
mmcr1 |= (unsigned long)ttm
<< (MMCR1_TD_CP_DBG0SEL_SH - 2 * byte);
}
memset(pmcsel, 0x8, sizeof(pmcsel));
for (i = 0; i < n_ev; ++i) {
pmc = (event[i] >> PM_PMC_SH) & PM_PMC_MSK;
unit = (event[i] >> PM_UNIT_SH) & PM_UNIT_MSK;
byte = (event[i] >> PM_BYTE_SH) & PM_BYTE_MSK;
psel = event[i] & PM_PMCSEL_MSK;
if (!pmc) {
if (unit)
psel |= 0x10 | ((byte & 2) << 2);
else
psel |= 8;
for (pmc = 0; pmc < 8; ++pmc) {
if (pmc_inuse & (1 << pmc))
continue;
grp = (pmc >> 1) & 1;
if (unit) {
if (grp == (byte & 1))
break;
} else if (pmc_grp_use[grp] < 4) {
++pmc_grp_use[grp];
break;
}
}
pmc_inuse |= 1 << pmc;
} else {
--pmc;
if (psel == 0 && (byte & 2))
mmcr1 |= 1ull << mmcr1_adder_bits[pmc];
}
pmcsel[pmc] = psel;
hwc[i] = pmc;
spcsel = (event[i] >> PM_SPCSEL_SH) & PM_SPCSEL_MSK;
mmcr1 |= spcsel;
if (p970_marked_instr_event(event[i]))
mmcra |= MMCRA_SAMPLE_ENABLE;
}
for (pmc = 0; pmc < 2; ++pmc)
mmcr0 |= pmcsel[pmc] << (MMCR0_PMC1SEL_SH - 7 * pmc);
for (; pmc < 8; ++pmc)
mmcr1 |= (unsigned long)pmcsel[pmc]
<< (MMCR1_PMC3SEL_SH - 5 * (pmc - 2));
if (pmc_inuse & 1)
mmcr0 |= MMCR0_PMC1CE;
if (pmc_inuse & 0xfe)
mmcr0 |= MMCR0_PMCjCE;
mmcra |= 0x2000;
mmcr[0] = mmcr0;
mmcr[1] = mmcr1;
mmcr[2] = mmcra;
return 0;
}
static void p970_disable_pmc(unsigned int pmc, unsigned long mmcr[])
{
int shift, i;
if (pmc <= 1) {
shift = MMCR0_PMC1SEL_SH - 7 * pmc;
i = 0;
} else {
shift = MMCR1_PMC3SEL_SH - 5 * (pmc - 2);
i = 1;
}
mmcr[i] = (mmcr[i] & ~(0x1fUL << shift)) | (0x08UL << shift);
}
static int init_ppc970_pmu(void)
{
if (!cur_cpu_spec->oprofile_cpu_type ||
(strcmp(cur_cpu_spec->oprofile_cpu_type, "ppc64/970")
&& strcmp(cur_cpu_spec->oprofile_cpu_type, "ppc64/970MP")))
return -ENODEV;
return register_power_pmu(&ppc970_pmu);
}
