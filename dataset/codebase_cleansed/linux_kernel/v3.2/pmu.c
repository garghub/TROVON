static void si_pmu_res_masks(struct si_pub *sih, u32 * pmin, u32 * pmax)
{
u32 min_mask = 0, max_mask = 0;
uint rsrcs;
rsrcs = (sih->pmucaps & PCAP_RC_MASK) >> PCAP_RC_SHIFT;
switch (sih->chip) {
case BCM43224_CHIP_ID:
case BCM43225_CHIP_ID:
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
*pmin = min_mask;
*pmax = max_mask;
}
static void
si_pmu_spuravoid_pllupdate(struct si_pub *sih, struct chipcregs __iomem *cc,
u8 spuravoid)
{
u32 tmp = 0;
switch (sih->chip) {
case BCM43224_CHIP_ID:
case BCM43225_CHIP_ID:
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
default:
return;
}
tmp |= R_REG(&cc->pmucontrol);
W_REG(&cc->pmucontrol, tmp);
}
u16 si_pmu_fast_pwrup_delay(struct si_pub *sih)
{
uint delay = PMU_MAX_TRANSITION_DLY;
switch (sih->chip) {
case BCM43224_CHIP_ID:
case BCM43225_CHIP_ID:
case BCM4313_CHIP_ID:
delay = 3700;
break;
default:
break;
}
return (u16) delay;
}
void si_pmu_sprom_enable(struct si_pub *sih, bool enable)
{
struct chipcregs __iomem *cc;
uint origidx;
origidx = ai_coreidx(sih);
cc = ai_setcoreidx(sih, SI_CC_IDX);
ai_setcoreidx(sih, origidx);
}
u32 si_pmu_chipcontrol(struct si_pub *sih, uint reg, u32 mask, u32 val)
{
ai_corereg(sih, SI_CC_IDX, offsetof(struct chipcregs, chipcontrol_addr),
~0, reg);
return ai_corereg(sih, SI_CC_IDX,
offsetof(struct chipcregs, chipcontrol_data), mask,
val);
}
u32 si_pmu_regcontrol(struct si_pub *sih, uint reg, u32 mask, u32 val)
{
ai_corereg(sih, SI_CC_IDX, offsetof(struct chipcregs, regcontrol_addr),
~0, reg);
return ai_corereg(sih, SI_CC_IDX,
offsetof(struct chipcregs, regcontrol_data), mask,
val);
}
u32 si_pmu_pllcontrol(struct si_pub *sih, uint reg, u32 mask, u32 val)
{
ai_corereg(sih, SI_CC_IDX, offsetof(struct chipcregs, pllcontrol_addr),
~0, reg);
return ai_corereg(sih, SI_CC_IDX,
offsetof(struct chipcregs, pllcontrol_data), mask,
val);
}
void si_pmu_pllupd(struct si_pub *sih)
{
ai_corereg(sih, SI_CC_IDX, offsetof(struct chipcregs, pmucontrol),
PCTL_PLL_PLLCTL_UPD, PCTL_PLL_PLLCTL_UPD);
}
u32 si_pmu_alp_clock(struct si_pub *sih)
{
u32 clock = ALP_CLOCK;
if (!(sih->cccaps & CC_CAP_PMU))
return clock;
switch (sih->chip) {
case BCM43224_CHIP_ID:
case BCM43225_CHIP_ID:
case BCM4313_CHIP_ID:
clock = 20000 * 1000;
break;
default:
break;
}
return clock;
}
void si_pmu_spuravoid(struct si_pub *sih, u8 spuravoid)
{
struct chipcregs __iomem *cc;
uint origidx, intr_val;
cc = (struct chipcregs __iomem *)
ai_switch_core(sih, CC_CORE_ID, &origidx, &intr_val);
si_pmu_spuravoid_pllupdate(sih, cc, spuravoid);
ai_restore_core(sih, origidx, intr_val);
}
void si_pmu_init(struct si_pub *sih)
{
struct chipcregs __iomem *cc;
uint origidx;
origidx = ai_coreidx(sih);
cc = ai_setcoreidx(sih, SI_CC_IDX);
if (sih->pmurev == 1)
AND_REG(&cc->pmucontrol, ~PCTL_NOILP_ON_WAIT);
else if (sih->pmurev >= 2)
OR_REG(&cc->pmucontrol, PCTL_NOILP_ON_WAIT);
ai_setcoreidx(sih, origidx);
}
void si_pmu_chip_init(struct si_pub *sih)
{
uint origidx;
si_pmu_sprom_enable(sih, false);
origidx = ai_coreidx(sih);
ai_setcoreidx(sih, origidx);
}
void si_pmu_swreg_init(struct si_pub *sih)
{
}
void si_pmu_pll_init(struct si_pub *sih, uint xtalfreq)
{
struct chipcregs __iomem *cc;
uint origidx;
origidx = ai_coreidx(sih);
cc = ai_setcoreidx(sih, SI_CC_IDX);
switch (sih->chip) {
case BCM4313_CHIP_ID:
case BCM43224_CHIP_ID:
case BCM43225_CHIP_ID:
break;
default:
break;
}
ai_setcoreidx(sih, origidx);
}
void si_pmu_res_init(struct si_pub *sih)
{
struct chipcregs __iomem *cc;
uint origidx;
u32 min_mask = 0, max_mask = 0;
origidx = ai_coreidx(sih);
cc = ai_setcoreidx(sih, SI_CC_IDX);
si_pmu_res_masks(sih, &min_mask, &max_mask);
if (max_mask)
W_REG(&cc->max_res_mask, max_mask);
if (min_mask)
W_REG(&cc->min_res_mask, min_mask);
mdelay(2);
ai_setcoreidx(sih, origidx);
}
u32 si_pmu_measure_alpclk(struct si_pub *sih)
{
struct chipcregs __iomem *cc;
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
