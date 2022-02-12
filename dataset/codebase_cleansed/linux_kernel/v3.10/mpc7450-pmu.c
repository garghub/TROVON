static int mpc7450_classify_event(u32 event)
{
int pmc;
pmc = (event >> PM_PMC_SH) & PM_PMC_MSK;
if (pmc) {
if (pmc > N_COUNTER)
return -1;
return 4;
}
event &= PM_PMCSEL_MSK;
if (event <= 1)
return 0;
if (event <= 7)
return 1;
if (event <= 13)
return 2;
if (event <= 22)
return 3;
return -1;
}
static int mpc7450_threshold_use(u32 event)
{
int pmc, sel;
pmc = (event >> PM_PMC_SH) & PM_PMC_MSK;
sel = event & PM_PMCSEL_MSK;
switch (pmc) {
case 1:
if (sel == 0x1e || sel == 0x1f)
return 1;
if (sel == 0x28 || sel == 0x2b)
return 2;
break;
case 2:
if (sel == 0x20)
return 1;
break;
case 3:
if (sel == 0xc || sel == 0xd)
return 1;
if (sel == 0x11)
return 2;
break;
case 4:
if (sel == 0x10)
return 1;
break;
}
return 0;
}
static int mpc7450_get_constraint(u64 event, unsigned long *maskp,
unsigned long *valp)
{
int pmc, class;
u32 mask, value;
int thresh, tuse;
class = mpc7450_classify_event(event);
if (class < 0)
return -1;
if (class == 4) {
pmc = ((unsigned int)event >> PM_PMC_SH) & PM_PMC_MSK;
mask = pmcbits[pmc - 1][0];
value = pmcbits[pmc - 1][1];
} else {
mask = classbits[class][0];
value = classbits[class][1];
}
tuse = mpc7450_threshold_use(event);
if (tuse) {
thresh = ((unsigned int)event >> PM_THRESH_SH) & PM_THRESH_MSK;
mask |= 0x3f << 24;
value |= thresh << 24;
if (tuse == 2) {
mask |= 0x40000000;
if ((unsigned int)event & PM_THRMULT_MSKS)
value |= 0x40000000;
}
}
*maskp = mask;
*valp = value;
return 0;
}
static int find_alternative(u32 event)
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
static int mpc7450_get_alternatives(u64 event, unsigned int flags, u64 alt[])
{
int i, j, nalt = 1;
u32 ae;
alt[0] = event;
nalt = 1;
i = find_alternative((u32)event);
if (i >= 0) {
for (j = 0; j < MAX_ALT; ++j) {
ae = event_alternatives[i][j];
if (ae && ae != (u32)event)
alt[nalt++] = ae;
}
}
return nalt;
}
static int mpc7450_compute_mmcr(u64 event[], int n_ev,
unsigned int hwc[], unsigned long mmcr[])
{
u8 event_index[N_CLASSES][N_COUNTER];
int n_classevent[N_CLASSES];
int i, j, class, tuse;
u32 pmc_inuse = 0, pmc_avail;
u32 mmcr0 = 0, mmcr1 = 0, mmcr2 = 0;
u32 ev, pmc, thresh;
if (n_ev > N_COUNTER)
return -1;
for (i = 0; i < N_CLASSES; ++i)
n_classevent[i] = 0;
for (i = 0; i < n_ev; ++i) {
class = mpc7450_classify_event(event[i]);
if (class < 0)
return -1;
j = n_classevent[class]++;
event_index[class][j] = i;
}
for (class = N_CLASSES - 1; class >= 0; --class) {
for (i = 0; i < n_classevent[class]; ++i) {
ev = event[event_index[class][i]];
if (class == 4) {
pmc = (ev >> PM_PMC_SH) & PM_PMC_MSK;
if (pmc_inuse & (1 << (pmc - 1)))
return -1;
} else {
pmc_avail = classmap[class] & ~pmc_inuse;
if (!pmc_avail)
return -1;
pmc = ffs(pmc_avail);
}
pmc_inuse |= 1 << (pmc - 1);
tuse = mpc7450_threshold_use(ev);
if (tuse) {
thresh = (ev >> PM_THRESH_SH) & PM_THRESH_MSK;
mmcr0 |= thresh << 16;
if (tuse == 2 && (ev & PM_THRMULT_MSKS))
mmcr2 = 0x80000000;
}
ev &= pmcsel_mask[pmc - 1];
ev <<= pmcsel_shift[pmc - 1];
if (pmc <= 2)
mmcr0 |= ev;
else
mmcr1 |= ev;
hwc[event_index[class][i]] = pmc - 1;
}
}
if (pmc_inuse & 1)
mmcr0 |= MMCR0_PMC1CE;
if (pmc_inuse & 0x3e)
mmcr0 |= MMCR0_PMCnCE;
mmcr[0] = mmcr0;
mmcr[1] = mmcr1;
mmcr[2] = mmcr2;
return 0;
}
static void mpc7450_disable_pmc(unsigned int pmc, unsigned long mmcr[])
{
if (pmc <= 1)
mmcr[0] &= ~(pmcsel_mask[pmc] << pmcsel_shift[pmc]);
else
mmcr[1] &= ~(pmcsel_mask[pmc] << pmcsel_shift[pmc]);
}
static int __init init_mpc7450_pmu(void)
{
if (!cur_cpu_spec->oprofile_cpu_type ||
strcmp(cur_cpu_spec->oprofile_cpu_type, "ppc/7450"))
return -ENODEV;
return register_power_pmu(&mpc7450_pmu);
}
