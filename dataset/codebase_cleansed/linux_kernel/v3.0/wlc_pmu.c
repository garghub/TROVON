static bool si_pmu_res_depfltr_bb(si_t *sih)
{
return (sih->boardflags & BFL_BUCKBOOST) != 0;
}
static bool si_pmu_res_depfltr_ncb(si_t *sih)
{
return (sih->boardflags & BFL_NOCBUCK) != 0;
}
static bool si_pmu_res_depfltr_paldo(si_t *sih)
{
return (sih->boardflags & BFL_PALDO) != 0;
}
static bool si_pmu_res_depfltr_npaldo(si_t *sih)
{
return (sih->boardflags & BFL_PALDO) == 0;
}
static u32
si_pmu_res_deps(si_t *sih, chipcregs_t *cc, u32 rsrcs,
bool all)
{
u32 deps = 0;
u32 i;
for (i = 0; i <= PMURES_MAX_RESNUM; i++) {
if (!(rsrcs & PMURES_BIT(i)))
continue;
W_REG(&cc->res_table_sel, i);
deps |= R_REG(&cc->res_dep_mask);
}
return !all ? deps : (deps
? (deps |
si_pmu_res_deps(sih, cc, deps,
true)) : 0);
}
static void si_pmu_res_masks(si_t *sih, u32 * pmin, u32 * pmax)
{
u32 min_mask = 0, max_mask = 0;
uint rsrcs;
char *val;
rsrcs = (sih->pmucaps & PCAP_RC_MASK) >> PCAP_RC_SHIFT;
switch (sih->chip) {
case BCM43224_CHIP_ID:
case BCM43225_CHIP_ID:
case BCM43421_CHIP_ID:
case BCM43235_CHIP_ID:
case BCM43236_CHIP_ID:
case BCM43238_CHIP_ID:
case BCM4331_CHIP_ID:
case BCM6362_CHIP_ID:
break;
case BCM4329_CHIP_ID:
min_mask =
PMURES_BIT(RES4329_CBUCK_LPOM) |
PMURES_BIT(RES4329_CLDO_PU);
max_mask = 0x3ff63e;
break;
case BCM4319_CHIP_ID:
min_mask = PMURES_BIT(RES4319_CBUCK_LPOM) |
PMURES_BIT(RES4319_CLDO_PU);
max_mask = ~(~0 << rsrcs);
break;
case BCM4336_CHIP_ID:
min_mask =
PMURES_BIT(RES4336_CBUCK_LPOM) | PMURES_BIT(RES4336_CLDO_PU)
| PMURES_BIT(RES4336_LDO3P3_PU) | PMURES_BIT(RES4336_OTP_PU)
| PMURES_BIT(RES4336_DIS_INT_RESET_PD);
max_mask = 0x1ffffff;
break;
case BCM4330_CHIP_ID:
min_mask =
PMURES_BIT(RES4330_CBUCK_LPOM) | PMURES_BIT(RES4330_CLDO_PU)
| PMURES_BIT(RES4330_DIS_INT_RESET_PD) |
PMURES_BIT(RES4330_LDO3P3_PU) | PMURES_BIT(RES4330_OTP_PU);
max_mask = 0xfffffff;
break;
case BCM4313_CHIP_ID:
min_mask = PMURES_BIT(RES4313_BB_PU_RSRC) |
PMURES_BIT(RES4313_XTAL_PU_RSRC) |
PMURES_BIT(RES4313_ALP_AVAIL_RSRC) |
PMURES_BIT(RES4313_BB_PLL_PWRSW_RSRC);
max_mask = 0xffff;
break;
default:
break;
}
val = getvar(NULL, "rmin");
if (val != NULL) {
min_mask = (u32) simple_strtoul(val, NULL, 0);
}
val = getvar(NULL, "rmax");
if (val != NULL) {
max_mask = (u32) simple_strtoul(val, NULL, 0);
}
*pmin = min_mask;
*pmax = max_mask;
}
static uint
si_pmu_res_uptime(si_t *sih, chipcregs_t *cc, u8 rsrc) {
u32 deps;
uint up, i, dup, dmax;
u32 min_mask = 0, max_mask = 0;
W_REG(&cc->res_table_sel, rsrc);
up = (R_REG(&cc->res_updn_timer) >> 8) & 0xff;
deps = si_pmu_res_deps(sih, cc, PMURES_BIT(rsrc), false);
for (i = 0; i <= PMURES_MAX_RESNUM; i++) {
if (!(deps & PMURES_BIT(i)))
continue;
deps &= ~si_pmu_res_deps(sih, cc, PMURES_BIT(i), true);
}
si_pmu_res_masks(sih, &min_mask, &max_mask);
deps &= ~min_mask;
dmax = 0;
for (i = 0; i <= PMURES_MAX_RESNUM; i++) {
if (!(deps & PMURES_BIT(i)))
continue;
dup = si_pmu_res_uptime(sih, cc, (u8) i);
if (dmax < dup)
dmax = dup;
}
return up + dmax + PMURES_UP_TRANSITION;
}
static void
si_pmu_spuravoid_pllupdate(si_t *sih, chipcregs_t *cc, u8 spuravoid)
{
u32 tmp = 0;
u8 phypll_offset = 0;
u8 bcm5357_bcm43236_p1div[] = { 0x1, 0x5, 0x5 };
u8 bcm5357_bcm43236_ndiv[] = { 0x30, 0xf6, 0xfc };
switch (sih->chip) {
case BCM5357_CHIP_ID:
case BCM43235_CHIP_ID:
case BCM43236_CHIP_ID:
case BCM43238_CHIP_ID:
phypll_offset = (sih->chip == BCM5357_CHIP_ID) ? 6 : 0;
W_REG(&cc->pllcontrol_addr,
PMU1_PLL0_PLLCTL0 + phypll_offset);
tmp = R_REG(&cc->pllcontrol_data);
tmp &= (~(PMU1_PLL0_PC0_P1DIV_MASK));
tmp |=
(bcm5357_bcm43236_p1div[spuravoid] <<
PMU1_PLL0_PC0_P1DIV_SHIFT);
W_REG(&cc->pllcontrol_data, tmp);
W_REG(&cc->pllcontrol_addr,
PMU1_PLL0_PLLCTL2 + phypll_offset);
tmp = R_REG(&cc->pllcontrol_data);
tmp &= ~(PMU1_PLL0_PC2_NDIV_INT_MASK);
tmp |=
(bcm5357_bcm43236_ndiv[spuravoid]) <<
PMU1_PLL0_PC2_NDIV_INT_SHIFT;
W_REG(&cc->pllcontrol_data, tmp);
tmp = 1 << 10;
break;
case BCM4331_CHIP_ID:
if (spuravoid == 2) {
W_REG(&cc->pllcontrol_addr, PMU1_PLL0_PLLCTL0);
W_REG(&cc->pllcontrol_data, 0x11500014);
W_REG(&cc->pllcontrol_addr, PMU1_PLL0_PLLCTL2);
W_REG(&cc->pllcontrol_data, 0x0FC00a08);
} else if (spuravoid == 1) {
W_REG(&cc->pllcontrol_addr, PMU1_PLL0_PLLCTL0);
W_REG(&cc->pllcontrol_data, 0x11500014);
W_REG(&cc->pllcontrol_addr, PMU1_PLL0_PLLCTL2);
W_REG(&cc->pllcontrol_data, 0x0F600a08);
} else {
W_REG(&cc->pllcontrol_addr, PMU1_PLL0_PLLCTL0);
W_REG(&cc->pllcontrol_data, 0x11100014);
W_REG(&cc->pllcontrol_addr, PMU1_PLL0_PLLCTL2);
W_REG(&cc->pllcontrol_data, 0x03000a08);
}
tmp = 1 << 10;
break;
case BCM43224_CHIP_ID:
case BCM43225_CHIP_ID:
case BCM43421_CHIP_ID:
case BCM6362_CHIP_ID:
if (spuravoid == 1) {
W_REG(&cc->pllcontrol_addr, PMU1_PLL0_PLLCTL0);
W_REG(&cc->pllcontrol_data, 0x11500010);
W_REG(&cc->pllcontrol_addr, PMU1_PLL0_PLLCTL1);
W_REG(&cc->pllcontrol_data, 0x000C0C06);
W_REG(&cc->pllcontrol_addr, PMU1_PLL0_PLLCTL2);
W_REG(&cc->pllcontrol_data, 0x0F600a08);
W_REG(&cc->pllcontrol_addr, PMU1_PLL0_PLLCTL3);
W_REG(&cc->pllcontrol_data, 0x00000000);
W_REG(&cc->pllcontrol_addr, PMU1_PLL0_PLLCTL4);
W_REG(&cc->pllcontrol_data, 0x2001E920);
W_REG(&cc->pllcontrol_addr, PMU1_PLL0_PLLCTL5);
W_REG(&cc->pllcontrol_data, 0x88888815);
} else {
W_REG(&cc->pllcontrol_addr, PMU1_PLL0_PLLCTL0);
W_REG(&cc->pllcontrol_data, 0x11100010);
W_REG(&cc->pllcontrol_addr, PMU1_PLL0_PLLCTL1);
W_REG(&cc->pllcontrol_data, 0x000c0c06);
W_REG(&cc->pllcontrol_addr, PMU1_PLL0_PLLCTL2);
W_REG(&cc->pllcontrol_data, 0x03000a08);
W_REG(&cc->pllcontrol_addr, PMU1_PLL0_PLLCTL3);
W_REG(&cc->pllcontrol_data, 0x00000000);
W_REG(&cc->pllcontrol_addr, PMU1_PLL0_PLLCTL4);
W_REG(&cc->pllcontrol_data, 0x200005c0);
W_REG(&cc->pllcontrol_addr, PMU1_PLL0_PLLCTL5);
W_REG(&cc->pllcontrol_data, 0x88888815);
}
tmp = 1 << 10;
break;
W_REG(&cc->pllcontrol_addr, PMU1_PLL0_PLLCTL0);
W_REG(&cc->pllcontrol_data, 0x11100008);
W_REG(&cc->pllcontrol_addr, PMU1_PLL0_PLLCTL1);
W_REG(&cc->pllcontrol_data, 0x0c000c06);
W_REG(&cc->pllcontrol_addr, PMU1_PLL0_PLLCTL2);
W_REG(&cc->pllcontrol_data, 0x03000a08);
W_REG(&cc->pllcontrol_addr, PMU1_PLL0_PLLCTL3);
W_REG(&cc->pllcontrol_data, 0x00000000);
W_REG(&cc->pllcontrol_addr, PMU1_PLL0_PLLCTL4);
W_REG(&cc->pllcontrol_data, 0x200005c0);
W_REG(&cc->pllcontrol_addr, PMU1_PLL0_PLLCTL5);
W_REG(&cc->pllcontrol_data, 0x88888855);
tmp = 1 << 10;
break;
case BCM4716_CHIP_ID:
case BCM4748_CHIP_ID:
case BCM47162_CHIP_ID:
if (spuravoid == 1) {
W_REG(&cc->pllcontrol_addr, PMU1_PLL0_PLLCTL0);
W_REG(&cc->pllcontrol_data, 0x11500060);
W_REG(&cc->pllcontrol_addr, PMU1_PLL0_PLLCTL1);
W_REG(&cc->pllcontrol_data, 0x080C0C06);
W_REG(&cc->pllcontrol_addr, PMU1_PLL0_PLLCTL2);
W_REG(&cc->pllcontrol_data, 0x0F600000);
W_REG(&cc->pllcontrol_addr, PMU1_PLL0_PLLCTL3);
W_REG(&cc->pllcontrol_data, 0x00000000);
W_REG(&cc->pllcontrol_addr, PMU1_PLL0_PLLCTL4);
W_REG(&cc->pllcontrol_data, 0x2001E924);
W_REG(&cc->pllcontrol_addr, PMU1_PLL0_PLLCTL5);
W_REG(&cc->pllcontrol_data, 0x88888815);
} else {
W_REG(&cc->pllcontrol_addr, PMU1_PLL0_PLLCTL0);
W_REG(&cc->pllcontrol_data, 0x11100060);
W_REG(&cc->pllcontrol_addr, PMU1_PLL0_PLLCTL1);
W_REG(&cc->pllcontrol_data, 0x080c0c06);
W_REG(&cc->pllcontrol_addr, PMU1_PLL0_PLLCTL2);
W_REG(&cc->pllcontrol_data, 0x03000000);
W_REG(&cc->pllcontrol_addr, PMU1_PLL0_PLLCTL3);
W_REG(&cc->pllcontrol_data, 0x00000000);
W_REG(&cc->pllcontrol_addr, PMU1_PLL0_PLLCTL4);
W_REG(&cc->pllcontrol_data, 0x200005c0);
W_REG(&cc->pllcontrol_addr, PMU1_PLL0_PLLCTL5);
W_REG(&cc->pllcontrol_data, 0x88888815);
}
tmp = 3 << 9;
break;
case BCM4319_CHIP_ID:
W_REG(&cc->pllcontrol_addr, PMU1_PLL0_PLLCTL0);
W_REG(&cc->pllcontrol_data, 0x11100070);
W_REG(&cc->pllcontrol_addr, PMU1_PLL0_PLLCTL1);
W_REG(&cc->pllcontrol_data, 0x1014140a);
W_REG(&cc->pllcontrol_addr, PMU1_PLL0_PLLCTL5);
W_REG(&cc->pllcontrol_data, 0x88888854);
if (spuravoid == 1) {
W_REG(&cc->pllcontrol_addr, PMU1_PLL0_PLLCTL2);
W_REG(&cc->pllcontrol_data, 0x05201828);
} else {
W_REG(&cc->pllcontrol_addr, PMU1_PLL0_PLLCTL2);
W_REG(&cc->pllcontrol_data, 0x05001828);
}
break;
case BCM4336_CHIP_ID:
W_REG(&cc->pllcontrol_addr, PMU1_PLL0_PLLCTL0);
W_REG(&cc->pllcontrol_data, 0x02100020);
W_REG(&cc->pllcontrol_addr, PMU1_PLL0_PLLCTL1);
W_REG(&cc->pllcontrol_data, 0x0C0C0C0C);
W_REG(&cc->pllcontrol_addr, PMU1_PLL0_PLLCTL2);
W_REG(&cc->pllcontrol_data, 0x01240C0C);
W_REG(&cc->pllcontrol_addr, PMU1_PLL0_PLLCTL4);
W_REG(&cc->pllcontrol_data, 0x202C2820);
W_REG(&cc->pllcontrol_addr, PMU1_PLL0_PLLCTL5);
W_REG(&cc->pllcontrol_data, 0x88888825);
W_REG(&cc->pllcontrol_addr, PMU1_PLL0_PLLCTL3);
if (spuravoid == 1)
W_REG(&cc->pllcontrol_data, 0x00EC4EC4);
else
W_REG(&cc->pllcontrol_data, 0x00762762);
tmp = PCTL_PLL_PLLCTL_UPD;
break;
default:
return;
}
tmp |= R_REG(&cc->pmucontrol);
W_REG(&cc->pmucontrol, tmp);
}
static const pmu1_xtaltab0_t *si_pmu1_xtaldef0(si_t *sih)
{
switch (sih->chip) {
case BCM4329_CHIP_ID:
return &pmu1_xtaltab0_880_4329[PMU1_XTALTAB0_880_38400K];
case BCM4319_CHIP_ID:
return &pmu1_xtaltab0_1440[PMU1_XTALTAB0_1440_30000K];
case BCM4336_CHIP_ID:
return &pmu1_xtaltab0_960[PMU1_XTALTAB0_960_26000K];
case BCM4330_CHIP_ID:
if (CST4330_CHIPMODE_SDIOD(sih->chipst))
return &pmu1_xtaltab0_960[PMU1_XTALTAB0_960_37400K];
else
return &pmu1_xtaltab0_1440[PMU1_XTALTAB0_1440_37400K];
default:
break;
}
return NULL;
}
static const pmu1_xtaltab0_t *si_pmu1_xtaltab0(si_t *sih)
{
switch (sih->chip) {
case BCM4329_CHIP_ID:
return pmu1_xtaltab0_880_4329;
case BCM4319_CHIP_ID:
return pmu1_xtaltab0_1440;
case BCM4336_CHIP_ID:
return pmu1_xtaltab0_960;
case BCM4330_CHIP_ID:
if (CST4330_CHIPMODE_SDIOD(sih->chipst))
return pmu1_xtaltab0_960;
else
return pmu1_xtaltab0_1440;
default:
break;
}
return NULL;
}
static u32
si_pmu1_alpclk0(si_t *sih, chipcregs_t *cc)
{
const pmu1_xtaltab0_t *xt;
u32 xf;
xf = (R_REG(&cc->pmucontrol) & PCTL_XTALFREQ_MASK) >>
PCTL_XTALFREQ_SHIFT;
for (xt = si_pmu1_xtaltab0(sih); xt != NULL && xt->fref != 0; xt++)
if (xt->xf == xf)
break;
if (xt == NULL || xt->fref == 0)
xt = si_pmu1_xtaldef0(sih);
return xt->fref * 1000;
}
static u32 si_pmu1_pllfvco0(si_t *sih)
{
switch (sih->chip) {
case BCM4329_CHIP_ID:
return FVCO_880;
case BCM4319_CHIP_ID:
return FVCO_1440;
case BCM4336_CHIP_ID:
return FVCO_960;
case BCM4330_CHIP_ID:
if (CST4330_CHIPMODE_SDIOD(sih->chipst))
return FVCO_960;
else
return FVCO_1440;
default:
break;
}
return 0;
}
static void si_pmu_set_4330_plldivs(si_t *sih)
{
u32 FVCO = si_pmu1_pllfvco0(sih) / 1000;
u32 m1div, m2div, m3div, m4div, m5div, m6div;
u32 pllc1, pllc2;
m2div = m3div = m4div = m6div = FVCO / 80;
m5div = FVCO / 160;
if (CST4330_CHIPMODE_SDIOD(sih->chipst))
m1div = FVCO / 80;
else
m1div = FVCO / 90;
pllc1 =
(m1div << PMU1_PLL0_PC1_M1DIV_SHIFT) | (m2div <<
PMU1_PLL0_PC1_M2DIV_SHIFT) |
(m3div << PMU1_PLL0_PC1_M3DIV_SHIFT) | (m4div <<
PMU1_PLL0_PC1_M4DIV_SHIFT);
si_pmu_pllcontrol(sih, PMU1_PLL0_PLLCTL1, ~0, pllc1);
pllc2 = si_pmu_pllcontrol(sih, PMU1_PLL0_PLLCTL1, 0, 0);
pllc2 &= ~(PMU1_PLL0_PC2_M5DIV_MASK | PMU1_PLL0_PC2_M6DIV_MASK);
pllc2 |=
((m5div << PMU1_PLL0_PC2_M5DIV_SHIFT) |
(m6div << PMU1_PLL0_PC2_M6DIV_SHIFT));
si_pmu_pllcontrol(sih, PMU1_PLL0_PLLCTL2, ~0, pllc2);
}
static void si_pmu1_pllinit0(si_t *sih, chipcregs_t *cc, u32 xtal)
{
const pmu1_xtaltab0_t *xt;
u32 tmp;
u32 buf_strength = 0;
u8 ndiv_mode = 1;
if (xtal == 0) {
return;
}
for (xt = si_pmu1_xtaltab0(sih); xt != NULL && xt->fref != 0; xt++)
if (xt->fref == xtal)
break;
if (xt == NULL || xt->fref == 0) {
return;
}
if ((((R_REG(&cc->pmucontrol) & PCTL_XTALFREQ_MASK) >>
PCTL_XTALFREQ_SHIFT) == xt->xf) &&
!((sih->chip == BCM4319_CHIP_ID)
|| (sih->chip == BCM4330_CHIP_ID)))
return;
switch (sih->chip) {
case BCM4329_CHIP_ID:
buf_strength = 0x888888;
AND_REG(&cc->min_res_mask,
~(PMURES_BIT(RES4329_BBPLL_PWRSW_PU) |
PMURES_BIT(RES4329_HT_AVAIL)));
AND_REG(&cc->max_res_mask,
~(PMURES_BIT(RES4329_BBPLL_PWRSW_PU) |
PMURES_BIT(RES4329_HT_AVAIL)));
SPINWAIT(R_REG(&cc->clk_ctl_st) & CCS_HTAVAIL,
PMU_MAX_TRANSITION_DLY);
W_REG(&cc->pllcontrol_addr, PMU1_PLL0_PLLCTL4);
if (xt->fref == 38400)
tmp = 0x200024C0;
else if (xt->fref == 37400)
tmp = 0x20004500;
else if (xt->fref == 26000)
tmp = 0x200024C0;
else
tmp = 0x200005C0;
W_REG(&cc->pllcontrol_data, tmp);
W_REG(&cc->pllcontrol_addr, PMU1_PLL0_PLLCTL5);
tmp =
R_REG(&cc->pllcontrol_data) & PMU1_PLL0_PC5_CLK_DRV_MASK;
if ((xt->fref == 38400) || (xt->fref == 37400)
|| (xt->fref == 26000))
tmp |= 0x15;
else
tmp |= 0x25;
W_REG(&cc->pllcontrol_data, tmp);
break;
case BCM4319_CHIP_ID:
buf_strength = 0x222222;
AND_REG(&cc->min_res_mask,
~(PMURES_BIT(RES4319_HT_AVAIL)));
AND_REG(&cc->max_res_mask,
~(PMURES_BIT(RES4319_HT_AVAIL)));
udelay(100);
AND_REG(&cc->min_res_mask,
~(PMURES_BIT(RES4319_BBPLL_PWRSW_PU)));
AND_REG(&cc->max_res_mask,
~(PMURES_BIT(RES4319_BBPLL_PWRSW_PU)));
udelay(100);
SPINWAIT(R_REG(&cc->clk_ctl_st) & CCS_HTAVAIL,
PMU_MAX_TRANSITION_DLY);
W_REG(&cc->pllcontrol_addr, PMU1_PLL0_PLLCTL4);
tmp = 0x200005c0;
W_REG(&cc->pllcontrol_data, tmp);
break;
case BCM4336_CHIP_ID:
AND_REG(&cc->min_res_mask,
~(PMURES_BIT(RES4336_HT_AVAIL) |
PMURES_BIT(RES4336_MACPHY_CLKAVAIL)));
AND_REG(&cc->max_res_mask,
~(PMURES_BIT(RES4336_HT_AVAIL) |
PMURES_BIT(RES4336_MACPHY_CLKAVAIL)));
udelay(100);
SPINWAIT(R_REG(&cc->clk_ctl_st) & CCS_HTAVAIL,
PMU_MAX_TRANSITION_DLY);
break;
case BCM4330_CHIP_ID:
AND_REG(&cc->min_res_mask,
~(PMURES_BIT(RES4330_HT_AVAIL) |
PMURES_BIT(RES4330_MACPHY_CLKAVAIL)));
AND_REG(&cc->max_res_mask,
~(PMURES_BIT(RES4330_HT_AVAIL) |
PMURES_BIT(RES4330_MACPHY_CLKAVAIL)));
udelay(100);
SPINWAIT(R_REG(&cc->clk_ctl_st) & CCS_HTAVAIL,
PMU_MAX_TRANSITION_DLY);
break;
default:
break;
}
W_REG(&cc->pllcontrol_addr, PMU1_PLL0_PLLCTL0);
tmp = R_REG(&cc->pllcontrol_data) &
~(PMU1_PLL0_PC0_P1DIV_MASK | PMU1_PLL0_PC0_P2DIV_MASK);
tmp |=
((xt->
p1div << PMU1_PLL0_PC0_P1DIV_SHIFT) & PMU1_PLL0_PC0_P1DIV_MASK) |
((xt->
p2div << PMU1_PLL0_PC0_P2DIV_SHIFT) & PMU1_PLL0_PC0_P2DIV_MASK);
W_REG(&cc->pllcontrol_data, tmp);
if ((sih->chip == BCM4330_CHIP_ID))
si_pmu_set_4330_plldivs(sih);
if ((sih->chip == BCM4329_CHIP_ID)
&& (sih->chiprev == 0)) {
W_REG(&cc->pllcontrol_addr, PMU1_PLL0_PLLCTL1);
tmp = R_REG(&cc->pllcontrol_data);
tmp = tmp & (~DOT11MAC_880MHZ_CLK_DIVISOR_MASK);
tmp = tmp | DOT11MAC_880MHZ_CLK_DIVISOR_VAL;
W_REG(&cc->pllcontrol_data, tmp);
}
if ((sih->chip == BCM4319_CHIP_ID) ||
(sih->chip == BCM4336_CHIP_ID) ||
(sih->chip == BCM4330_CHIP_ID))
ndiv_mode = PMU1_PLL0_PC2_NDIV_MODE_MFB;
else
ndiv_mode = PMU1_PLL0_PC2_NDIV_MODE_MASH;
W_REG(&cc->pllcontrol_addr, PMU1_PLL0_PLLCTL2);
tmp = R_REG(&cc->pllcontrol_data) &
~(PMU1_PLL0_PC2_NDIV_INT_MASK | PMU1_PLL0_PC2_NDIV_MODE_MASK);
tmp |=
((xt->
ndiv_int << PMU1_PLL0_PC2_NDIV_INT_SHIFT) &
PMU1_PLL0_PC2_NDIV_INT_MASK) | ((ndiv_mode <<
PMU1_PLL0_PC2_NDIV_MODE_SHIFT) &
PMU1_PLL0_PC2_NDIV_MODE_MASK);
W_REG(&cc->pllcontrol_data, tmp);
W_REG(&cc->pllcontrol_addr, PMU1_PLL0_PLLCTL3);
tmp = R_REG(&cc->pllcontrol_data) & ~PMU1_PLL0_PC3_NDIV_FRAC_MASK;
tmp |= ((xt->ndiv_frac << PMU1_PLL0_PC3_NDIV_FRAC_SHIFT) &
PMU1_PLL0_PC3_NDIV_FRAC_MASK);
W_REG(&cc->pllcontrol_data, tmp);
if (buf_strength) {
W_REG(&cc->pllcontrol_addr, PMU1_PLL0_PLLCTL5);
tmp =
R_REG(&cc->pllcontrol_data) & ~PMU1_PLL0_PC5_CLK_DRV_MASK;
tmp |= (buf_strength << PMU1_PLL0_PC5_CLK_DRV_SHIFT);
W_REG(&cc->pllcontrol_data, tmp);
}
if ((sih->chip == BCM4319_CHIP_ID)
&& (xt->fref != XTAL_FREQ_30000MHZ)) {
W_REG(&cc->chipcontrol_addr, PMU1_PLL0_CHIPCTL2);
tmp =
R_REG(&cc->chipcontrol_data) & ~CCTL_4319USB_XTAL_SEL_MASK;
if (xt->fref == XTAL_FREQ_24000MHZ) {
tmp |=
(CCTL_4319USB_24MHZ_PLL_SEL <<
CCTL_4319USB_XTAL_SEL_SHIFT);
} else if (xt->fref == XTAL_FREQ_48000MHZ) {
tmp |=
(CCTL_4319USB_48MHZ_PLL_SEL <<
CCTL_4319USB_XTAL_SEL_SHIFT);
}
W_REG(&cc->chipcontrol_data, tmp);
}
if (sih->pmurev >= 2)
OR_REG(&cc->pmucontrol, PCTL_PLL_PLLCTL_UPD);
tmp = R_REG(&cc->pmucontrol) &
~(PCTL_ILP_DIV_MASK | PCTL_XTALFREQ_MASK);
tmp |= (((((xt->fref + 127) / 128) - 1) << PCTL_ILP_DIV_SHIFT) &
PCTL_ILP_DIV_MASK) |
((xt->xf << PCTL_XTALFREQ_SHIFT) & PCTL_XTALFREQ_MASK);
if ((sih->chip == BCM4329_CHIP_ID)
&& sih->chiprev == 0) {
AND_REG(&cc->clkstretch, ~CSTRETCH_HT);
tmp &= ~PCTL_HT_REQ_EN;
}
W_REG(&cc->pmucontrol, tmp);
}
u32 si_pmu_ilp_clock(si_t *sih)
{
static u32 ilpcycles_per_sec;
if (ISSIM_ENAB(sih) || !PMUCTL_ENAB(sih))
return ILP_CLOCK;
if (ilpcycles_per_sec == 0) {
u32 start, end, delta;
u32 origidx = ai_coreidx(sih);
chipcregs_t *cc = ai_setcoreidx(sih, SI_CC_IDX);
start = R_REG(&cc->pmutimer);
mdelay(ILP_CALC_DUR);
end = R_REG(&cc->pmutimer);
delta = end - start;
ilpcycles_per_sec = delta * (1000 / ILP_CALC_DUR);
ai_setcoreidx(sih, origidx);
}
return ilpcycles_per_sec;
}
void si_pmu_set_ldo_voltage(si_t *sih, u8 ldo, u8 voltage)
{
u8 sr_cntl_shift = 0, rc_shift = 0, shift = 0, mask = 0;
u8 addr = 0;
switch (sih->chip) {
case BCM4336_CHIP_ID:
switch (ldo) {
case SET_LDO_VOLTAGE_CLDO_PWM:
addr = 4;
rc_shift = 1;
mask = 0xf;
break;
case SET_LDO_VOLTAGE_CLDO_BURST:
addr = 4;
rc_shift = 5;
mask = 0xf;
break;
case SET_LDO_VOLTAGE_LNLDO1:
addr = 4;
rc_shift = 17;
mask = 0xf;
break;
default:
return;
}
break;
case BCM4330_CHIP_ID:
switch (ldo) {
case SET_LDO_VOLTAGE_CBUCK_PWM:
addr = 3;
rc_shift = 0;
mask = 0x1f;
break;
default:
return;
}
break;
default:
return;
}
shift = sr_cntl_shift + rc_shift;
ai_corereg(sih, SI_CC_IDX, offsetof(chipcregs_t, regcontrol_addr),
~0, addr);
ai_corereg(sih, SI_CC_IDX, offsetof(chipcregs_t, regcontrol_data),
mask << shift, (voltage & mask) << shift);
}
u16 si_pmu_fast_pwrup_delay(si_t *sih)
{
uint delay = PMU_MAX_TRANSITION_DLY;
chipcregs_t *cc;
uint origidx;
#ifdef BCMDBG
char chn[8];
chn[0] = 0;
#endif
origidx = ai_coreidx(sih);
cc = ai_setcoreidx(sih, SI_CC_IDX);
switch (sih->chip) {
case BCM43224_CHIP_ID:
case BCM43225_CHIP_ID:
case BCM43421_CHIP_ID:
case BCM43235_CHIP_ID:
case BCM43236_CHIP_ID:
case BCM43238_CHIP_ID:
case BCM4331_CHIP_ID:
case BCM6362_CHIP_ID:
case BCM4313_CHIP_ID:
delay = ISSIM_ENAB(sih) ? 70 : 3700;
break;
case BCM4329_CHIP_ID:
if (ISSIM_ENAB(sih))
delay = 70;
else {
u32 ilp = si_pmu_ilp_clock(sih);
delay =
(si_pmu_res_uptime(sih, cc, RES4329_HT_AVAIL) +
D11SCC_SLOW2FAST_TRANSITION) * ((1000000 + ilp -
1) / ilp);
delay = (11 * delay) / 10;
}
break;
case BCM4319_CHIP_ID:
delay = ISSIM_ENAB(sih) ? 70 : 3700;
break;
case BCM4336_CHIP_ID:
if (ISSIM_ENAB(sih))
delay = 70;
else {
u32 ilp = si_pmu_ilp_clock(sih);
delay =
(si_pmu_res_uptime(sih, cc, RES4336_HT_AVAIL) +
D11SCC_SLOW2FAST_TRANSITION) * ((1000000 + ilp -
1) / ilp);
delay = (11 * delay) / 10;
}
break;
case BCM4330_CHIP_ID:
if (ISSIM_ENAB(sih))
delay = 70;
else {
u32 ilp = si_pmu_ilp_clock(sih);
delay =
(si_pmu_res_uptime(sih, cc, RES4330_HT_AVAIL) +
D11SCC_SLOW2FAST_TRANSITION) * ((1000000 + ilp -
1) / ilp);
delay = (11 * delay) / 10;
}
break;
default:
break;
}
ai_setcoreidx(sih, origidx);
return (u16) delay;
}
void si_pmu_sprom_enable(si_t *sih, bool enable)
{
chipcregs_t *cc;
uint origidx;
origidx = ai_coreidx(sih);
cc = ai_setcoreidx(sih, SI_CC_IDX);
ai_setcoreidx(sih, origidx);
}
u32 si_pmu_chipcontrol(si_t *sih, uint reg, u32 mask, u32 val)
{
ai_corereg(sih, SI_CC_IDX, offsetof(chipcregs_t, chipcontrol_addr), ~0,
reg);
return ai_corereg(sih, SI_CC_IDX,
offsetof(chipcregs_t, chipcontrol_data), mask, val);
}
u32 si_pmu_regcontrol(si_t *sih, uint reg, u32 mask, u32 val)
{
ai_corereg(sih, SI_CC_IDX, offsetof(chipcregs_t, regcontrol_addr), ~0,
reg);
return ai_corereg(sih, SI_CC_IDX,
offsetof(chipcregs_t, regcontrol_data), mask, val);
}
u32 si_pmu_pllcontrol(si_t *sih, uint reg, u32 mask, u32 val)
{
ai_corereg(sih, SI_CC_IDX, offsetof(chipcregs_t, pllcontrol_addr), ~0,
reg);
return ai_corereg(sih, SI_CC_IDX,
offsetof(chipcregs_t, pllcontrol_data), mask, val);
}
void si_pmu_pllupd(si_t *sih)
{
ai_corereg(sih, SI_CC_IDX, offsetof(chipcregs_t, pmucontrol),
PCTL_PLL_PLLCTL_UPD, PCTL_PLL_PLLCTL_UPD);
}
u32 si_pmu_alp_clock(si_t *sih)
{
chipcregs_t *cc;
uint origidx;
u32 clock = ALP_CLOCK;
if (!PMUCTL_ENAB(sih))
return clock;
origidx = ai_coreidx(sih);
cc = ai_setcoreidx(sih, SI_CC_IDX);
switch (sih->chip) {
case BCM43224_CHIP_ID:
case BCM43225_CHIP_ID:
case BCM43421_CHIP_ID:
case BCM43235_CHIP_ID:
case BCM43236_CHIP_ID:
case BCM43238_CHIP_ID:
case BCM4331_CHIP_ID:
case BCM6362_CHIP_ID:
case BCM4716_CHIP_ID:
case BCM4748_CHIP_ID:
case BCM47162_CHIP_ID:
case BCM4313_CHIP_ID:
case BCM5357_CHIP_ID:
clock = 20000 * 1000;
break;
case BCM4329_CHIP_ID:
case BCM4319_CHIP_ID:
case BCM4336_CHIP_ID:
case BCM4330_CHIP_ID:
clock = si_pmu1_alpclk0(sih, cc);
break;
case BCM5356_CHIP_ID:
clock = 25000 * 1000;
break;
default:
break;
}
ai_setcoreidx(sih, origidx);
return clock;
}
void si_pmu_spuravoid(si_t *sih, u8 spuravoid)
{
chipcregs_t *cc;
uint origidx, intr_val;
u32 tmp = 0;
cc = (chipcregs_t *) ai_switch_core(sih, CC_CORE_ID, &origidx,
&intr_val);
if (sih->chip == BCM4336_CHIP_ID) {
tmp = R_REG(&cc->max_res_mask);
tmp &= ~RES4336_HT_AVAIL;
W_REG(&cc->max_res_mask, tmp);
SPINWAIT(((R_REG(&cc->clk_ctl_st) & CCS_HTAVAIL) == 0),
10000);
}
si_pmu_spuravoid_pllupdate(sih, cc, spuravoid);
if (sih->chip == BCM4336_CHIP_ID) {
tmp = R_REG(&cc->max_res_mask);
tmp |= RES4336_HT_AVAIL;
W_REG(&cc->max_res_mask, tmp);
}
ai_restore_core(sih, origidx, intr_val);
}
void si_pmu_init(si_t *sih)
{
chipcregs_t *cc;
uint origidx;
origidx = ai_coreidx(sih);
cc = ai_setcoreidx(sih, SI_CC_IDX);
if (sih->pmurev == 1)
AND_REG(&cc->pmucontrol, ~PCTL_NOILP_ON_WAIT);
else if (sih->pmurev >= 2)
OR_REG(&cc->pmucontrol, PCTL_NOILP_ON_WAIT);
if ((sih->chip == BCM4329_CHIP_ID) && (sih->chiprev == 2)) {
W_REG(&cc->regcontrol_addr, 2);
OR_REG(&cc->regcontrol_data, 0x100);
W_REG(&cc->regcontrol_addr, 3);
OR_REG(&cc->regcontrol_data, 0x4);
}
ai_setcoreidx(sih, origidx);
}
void si_pmu_chip_init(si_t *sih)
{
uint origidx;
si_pmu_sprom_enable(sih, false);
origidx = ai_coreidx(sih);
ai_setcoreidx(sih, origidx);
}
void si_pmu_swreg_init(si_t *sih)
{
switch (sih->chip) {
case BCM4336_CHIP_ID:
si_pmu_set_ldo_voltage(sih, SET_LDO_VOLTAGE_CLDO_PWM, 0xe);
si_pmu_set_ldo_voltage(sih, SET_LDO_VOLTAGE_CLDO_BURST,
0xe);
si_pmu_set_ldo_voltage(sih, SET_LDO_VOLTAGE_LNLDO1, 0xe);
if (sih->chiprev == 0)
si_pmu_regcontrol(sih, 2, 0x400000, 0x400000);
break;
case BCM4330_CHIP_ID:
si_pmu_set_ldo_voltage(sih, SET_LDO_VOLTAGE_CBUCK_PWM, 0);
break;
default:
break;
}
}
void si_pmu_pll_init(si_t *sih, uint xtalfreq)
{
chipcregs_t *cc;
uint origidx;
origidx = ai_coreidx(sih);
cc = ai_setcoreidx(sih, SI_CC_IDX);
switch (sih->chip) {
case BCM4329_CHIP_ID:
if (xtalfreq == 0)
xtalfreq = 38400;
si_pmu1_pllinit0(sih, cc, xtalfreq);
break;
case BCM4313_CHIP_ID:
case BCM43224_CHIP_ID:
case BCM43225_CHIP_ID:
case BCM43421_CHIP_ID:
case BCM43235_CHIP_ID:
case BCM43236_CHIP_ID:
case BCM43238_CHIP_ID:
case BCM4331_CHIP_ID:
case BCM6362_CHIP_ID:
break;
case BCM4319_CHIP_ID:
case BCM4336_CHIP_ID:
case BCM4330_CHIP_ID:
si_pmu1_pllinit0(sih, cc, xtalfreq);
break;
default:
break;
}
ai_setcoreidx(sih, origidx);
}
void si_pmu_res_init(si_t *sih)
{
chipcregs_t *cc;
uint origidx;
const pmu_res_updown_t *pmu_res_updown_table = NULL;
uint pmu_res_updown_table_sz = 0;
const pmu_res_depend_t *pmu_res_depend_table = NULL;
uint pmu_res_depend_table_sz = 0;
u32 min_mask = 0, max_mask = 0;
char name[8], *val;
uint i, rsrcs;
origidx = ai_coreidx(sih);
cc = ai_setcoreidx(sih, SI_CC_IDX);
switch (sih->chip) {
case BCM4329_CHIP_ID:
if (ISSIM_ENAB(sih)) {
pmu_res_updown_table = NULL;
pmu_res_updown_table_sz = 0;
} else {
pmu_res_updown_table = bcm4329_res_updown;
pmu_res_updown_table_sz =
ARRAY_SIZE(bcm4329_res_updown);
}
pmu_res_depend_table = bcm4329_res_depend;
pmu_res_depend_table_sz = ARRAY_SIZE(bcm4329_res_depend);
break;
case BCM4319_CHIP_ID:
if (ISSIM_ENAB(sih)) {
pmu_res_updown_table = bcm4319a0_res_updown_qt;
pmu_res_updown_table_sz =
ARRAY_SIZE(bcm4319a0_res_updown_qt);
} else {
pmu_res_updown_table = bcm4319a0_res_updown;
pmu_res_updown_table_sz =
ARRAY_SIZE(bcm4319a0_res_updown);
}
pmu_res_depend_table = bcm4319a0_res_depend;
pmu_res_depend_table_sz = ARRAY_SIZE(bcm4319a0_res_depend);
break;
case BCM4336_CHIP_ID:
if (ISSIM_ENAB(sih)) {
pmu_res_updown_table = bcm4336a0_res_updown_qt;
pmu_res_updown_table_sz =
ARRAY_SIZE(bcm4336a0_res_updown_qt);
} else {
pmu_res_updown_table = bcm4336a0_res_updown;
pmu_res_updown_table_sz =
ARRAY_SIZE(bcm4336a0_res_updown);
}
pmu_res_depend_table = bcm4336a0_res_depend;
pmu_res_depend_table_sz = ARRAY_SIZE(bcm4336a0_res_depend);
break;
case BCM4330_CHIP_ID:
if (ISSIM_ENAB(sih)) {
pmu_res_updown_table = bcm4330a0_res_updown_qt;
pmu_res_updown_table_sz =
ARRAY_SIZE(bcm4330a0_res_updown_qt);
} else {
pmu_res_updown_table = bcm4330a0_res_updown;
pmu_res_updown_table_sz =
ARRAY_SIZE(bcm4330a0_res_updown);
}
pmu_res_depend_table = bcm4330a0_res_depend;
pmu_res_depend_table_sz = ARRAY_SIZE(bcm4330a0_res_depend);
break;
default:
break;
}
rsrcs = (sih->pmucaps & PCAP_RC_MASK) >> PCAP_RC_SHIFT;
while (pmu_res_updown_table_sz--) {
W_REG(&cc->res_table_sel,
pmu_res_updown_table[pmu_res_updown_table_sz].resnum);
W_REG(&cc->res_updn_timer,
pmu_res_updown_table[pmu_res_updown_table_sz].updown);
}
for (i = 0; i < rsrcs; i++) {
snprintf(name, sizeof(name), "r%dt", i);
val = getvar(NULL, name);
if (val == NULL)
continue;
W_REG(&cc->res_table_sel, (u32) i);
W_REG(&cc->res_updn_timer,
(u32) simple_strtoul(val, NULL, 0));
}
while (pmu_res_depend_table_sz--) {
if (pmu_res_depend_table[pmu_res_depend_table_sz].filter != NULL
&& !(pmu_res_depend_table[pmu_res_depend_table_sz].
filter) (sih))
continue;
for (i = 0; i < rsrcs; i++) {
if ((pmu_res_depend_table[pmu_res_depend_table_sz].
res_mask & PMURES_BIT(i)) == 0)
continue;
W_REG(&cc->res_table_sel, i);
switch (pmu_res_depend_table[pmu_res_depend_table_sz].
action) {
case RES_DEPEND_SET:
W_REG(&cc->res_dep_mask,
pmu_res_depend_table
[pmu_res_depend_table_sz].depend_mask);
break;
case RES_DEPEND_ADD:
OR_REG(&cc->res_dep_mask,
pmu_res_depend_table
[pmu_res_depend_table_sz].depend_mask);
break;
case RES_DEPEND_REMOVE:
AND_REG(&cc->res_dep_mask,
~pmu_res_depend_table
[pmu_res_depend_table_sz].depend_mask);
break;
default:
break;
}
}
}
for (i = 0; i < rsrcs; i++) {
snprintf(name, sizeof(name), "r%dd", i);
val = getvar(NULL, name);
if (val == NULL)
continue;
W_REG(&cc->res_table_sel, (u32) i);
W_REG(&cc->res_dep_mask,
(u32) simple_strtoul(val, NULL, 0));
}
si_pmu_res_masks(sih, &min_mask, &max_mask);
if (max_mask)
W_REG(&cc->max_res_mask, max_mask);
if (min_mask)
W_REG(&cc->min_res_mask, min_mask);
mdelay(2);
ai_setcoreidx(sih, origidx);
}
u32 si_pmu_measure_alpclk(si_t *sih)
{
chipcregs_t *cc;
uint origidx;
u32 alp_khz;
if (sih->pmurev < 10)
return 0;
origidx = ai_coreidx(sih);
cc = ai_setcoreidx(sih, SI_CC_IDX);
if (R_REG(&cc->pmustatus) & PST_EXTLPOAVAIL) {
u32 ilp_ctr, alp_hz;
W_REG(&cc->pmu_xtalfreq,
1U << PMU_XTALFREQ_REG_MEASURE_SHIFT);
udelay(1000);
ilp_ctr =
R_REG(&cc->pmu_xtalfreq) & PMU_XTALFREQ_REG_ILPCTR_MASK;
W_REG(&cc->pmu_xtalfreq, 0);
alp_hz = (ilp_ctr * EXT_ILP_HZ) / 4;
alp_khz = (alp_hz + 50000) / 100000 * 100;
} else
alp_khz = 0;
ai_setcoreidx(sih, origidx);
return alp_khz;
}
bool si_pmu_is_otp_powered(si_t *sih)
{
uint idx;
chipcregs_t *cc;
bool st;
idx = ai_coreidx(sih);
cc = ai_setcoreidx(sih, SI_CC_IDX);
switch (sih->chip) {
case BCM4329_CHIP_ID:
st = (R_REG(&cc->res_state) & PMURES_BIT(RES4329_OTP_PU))
!= 0;
break;
case BCM4319_CHIP_ID:
st = (R_REG(&cc->res_state) & PMURES_BIT(RES4319_OTP_PU))
!= 0;
break;
case BCM4336_CHIP_ID:
st = (R_REG(&cc->res_state) & PMURES_BIT(RES4336_OTP_PU))
!= 0;
break;
case BCM4330_CHIP_ID:
st = (R_REG(&cc->res_state) & PMURES_BIT(RES4330_OTP_PU))
!= 0;
break;
case BCM43224_CHIP_ID:
case BCM43225_CHIP_ID:
case BCM43421_CHIP_ID:
case BCM43236_CHIP_ID:
case BCM43235_CHIP_ID:
case BCM43238_CHIP_ID:
st = true;
break;
default:
st = true;
break;
}
ai_setcoreidx(sih, idx);
return st;
}
void si_pmu_otp_power(si_t *sih, bool on)
{
chipcregs_t *cc;
uint origidx;
u32 rsrcs = 0;
if (ai_is_otp_disabled(sih))
return;
origidx = ai_coreidx(sih);
cc = ai_setcoreidx(sih, SI_CC_IDX);
switch (sih->chip) {
case BCM4329_CHIP_ID:
rsrcs = PMURES_BIT(RES4329_OTP_PU);
break;
case BCM4319_CHIP_ID:
rsrcs = PMURES_BIT(RES4319_OTP_PU);
break;
case BCM4336_CHIP_ID:
rsrcs = PMURES_BIT(RES4336_OTP_PU);
break;
case BCM4330_CHIP_ID:
rsrcs = PMURES_BIT(RES4330_OTP_PU);
break;
default:
break;
}
if (rsrcs != 0) {
u32 otps;
u32 deps = si_pmu_res_deps(sih, cc, rsrcs, true);
u32 min_mask = 0, max_mask = 0;
si_pmu_res_masks(sih, &min_mask, &max_mask);
deps &= ~min_mask;
if (on) {
OR_REG(&cc->min_res_mask, (rsrcs | deps));
SPINWAIT(!(R_REG(&cc->res_state) & rsrcs),
PMU_MAX_TRANSITION_DLY);
} else {
AND_REG(&cc->min_res_mask, ~(rsrcs | deps));
}
SPINWAIT((((otps = R_REG(&cc->otpstatus)) & OTPS_READY) !=
(on ? OTPS_READY : 0)), 100);
}
ai_setcoreidx(sih, origidx);
}
