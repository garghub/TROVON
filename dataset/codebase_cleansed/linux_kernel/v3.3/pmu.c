static void si_pmu_res_masks(struct si_pub *sih, u32 * pmin, u32 * pmax)
{
u32 min_mask = 0, max_mask = 0;
uint rsrcs;
rsrcs = (ai_get_pmucaps(sih) & PCAP_RC_MASK) >> PCAP_RC_SHIFT;
switch (ai_get_chip_id(sih)) {
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
void si_pmu_spuravoid_pllupdate(struct si_pub *sih, u8 spuravoid)
{
u32 tmp = 0;
struct bcma_device *core;
core = ai_findcore(sih, BCMA_CORE_CHIPCOMMON, 0);
switch (ai_get_chip_id(sih)) {
case BCM43224_CHIP_ID:
case BCM43225_CHIP_ID:
if (spuravoid == 1) {
bcma_write32(core, CHIPCREGOFFS(pllcontrol_addr),
PMU1_PLL0_PLLCTL0);
bcma_write32(core, CHIPCREGOFFS(pllcontrol_data),
0x11500010);
bcma_write32(core, CHIPCREGOFFS(pllcontrol_addr),
PMU1_PLL0_PLLCTL1);
bcma_write32(core, CHIPCREGOFFS(pllcontrol_data),
0x000C0C06);
bcma_write32(core, CHIPCREGOFFS(pllcontrol_addr),
PMU1_PLL0_PLLCTL2);
bcma_write32(core, CHIPCREGOFFS(pllcontrol_data),
0x0F600a08);
bcma_write32(core, CHIPCREGOFFS(pllcontrol_addr),
PMU1_PLL0_PLLCTL3);
bcma_write32(core, CHIPCREGOFFS(pllcontrol_data),
0x00000000);
bcma_write32(core, CHIPCREGOFFS(pllcontrol_addr),
PMU1_PLL0_PLLCTL4);
bcma_write32(core, CHIPCREGOFFS(pllcontrol_data),
0x2001E920);
bcma_write32(core, CHIPCREGOFFS(pllcontrol_addr),
PMU1_PLL0_PLLCTL5);
bcma_write32(core, CHIPCREGOFFS(pllcontrol_data),
0x88888815);
} else {
bcma_write32(core, CHIPCREGOFFS(pllcontrol_addr),
PMU1_PLL0_PLLCTL0);
bcma_write32(core, CHIPCREGOFFS(pllcontrol_data),
0x11100010);
bcma_write32(core, CHIPCREGOFFS(pllcontrol_addr),
PMU1_PLL0_PLLCTL1);
bcma_write32(core, CHIPCREGOFFS(pllcontrol_data),
0x000c0c06);
bcma_write32(core, CHIPCREGOFFS(pllcontrol_addr),
PMU1_PLL0_PLLCTL2);
bcma_write32(core, CHIPCREGOFFS(pllcontrol_data),
0x03000a08);
bcma_write32(core, CHIPCREGOFFS(pllcontrol_addr),
PMU1_PLL0_PLLCTL3);
bcma_write32(core, CHIPCREGOFFS(pllcontrol_data),
0x00000000);
bcma_write32(core, CHIPCREGOFFS(pllcontrol_addr),
PMU1_PLL0_PLLCTL4);
bcma_write32(core, CHIPCREGOFFS(pllcontrol_data),
0x200005c0);
bcma_write32(core, CHIPCREGOFFS(pllcontrol_addr),
PMU1_PLL0_PLLCTL5);
bcma_write32(core, CHIPCREGOFFS(pllcontrol_data),
0x88888815);
}
tmp = 1 << 10;
break;
default:
return;
}
bcma_set32(core, CHIPCREGOFFS(pmucontrol), tmp);
}
u16 si_pmu_fast_pwrup_delay(struct si_pub *sih)
{
uint delay = PMU_MAX_TRANSITION_DLY;
switch (ai_get_chip_id(sih)) {
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
u32 si_pmu_chipcontrol(struct si_pub *sih, uint reg, u32 mask, u32 val)
{
ai_cc_reg(sih, offsetof(struct chipcregs, chipcontrol_addr), ~0, reg);
return ai_cc_reg(sih, offsetof(struct chipcregs, chipcontrol_data),
mask, val);
}
u32 si_pmu_regcontrol(struct si_pub *sih, uint reg, u32 mask, u32 val)
{
ai_cc_reg(sih, offsetof(struct chipcregs, regcontrol_addr), ~0, reg);
return ai_cc_reg(sih, offsetof(struct chipcregs, regcontrol_data),
mask, val);
}
u32 si_pmu_pllcontrol(struct si_pub *sih, uint reg, u32 mask, u32 val)
{
ai_cc_reg(sih, offsetof(struct chipcregs, pllcontrol_addr), ~0, reg);
return ai_cc_reg(sih, offsetof(struct chipcregs, pllcontrol_data),
mask, val);
}
void si_pmu_pllupd(struct si_pub *sih)
{
ai_cc_reg(sih, offsetof(struct chipcregs, pmucontrol),
PCTL_PLL_PLLCTL_UPD, PCTL_PLL_PLLCTL_UPD);
}
u32 si_pmu_alp_clock(struct si_pub *sih)
{
u32 clock = ALP_CLOCK;
if (!(ai_get_cccaps(sih) & CC_CAP_PMU))
return clock;
switch (ai_get_chip_id(sih)) {
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
void si_pmu_init(struct si_pub *sih)
{
struct bcma_device *core;
core = ai_findcore(sih, BCMA_CORE_CHIPCOMMON, 0);
if (ai_get_pmurev(sih) == 1)
bcma_mask32(core, CHIPCREGOFFS(pmucontrol),
~PCTL_NOILP_ON_WAIT);
else if (ai_get_pmurev(sih) >= 2)
bcma_set32(core, CHIPCREGOFFS(pmucontrol), PCTL_NOILP_ON_WAIT);
}
void si_pmu_res_init(struct si_pub *sih)
{
struct bcma_device *core;
u32 min_mask = 0, max_mask = 0;
core = ai_findcore(sih, BCMA_CORE_CHIPCOMMON, 0);
si_pmu_res_masks(sih, &min_mask, &max_mask);
if (max_mask)
bcma_write32(core, CHIPCREGOFFS(max_res_mask), max_mask);
if (min_mask)
bcma_write32(core, CHIPCREGOFFS(min_res_mask), min_mask);
mdelay(2);
}
u32 si_pmu_measure_alpclk(struct si_pub *sih)
{
struct bcma_device *core;
u32 alp_khz;
if (ai_get_pmurev(sih) < 10)
return 0;
core = ai_findcore(sih, BCMA_CORE_CHIPCOMMON, 0);
if (bcma_read32(core, CHIPCREGOFFS(pmustatus)) & PST_EXTLPOAVAIL) {
u32 ilp_ctr, alp_hz;
bcma_write32(core, CHIPCREGOFFS(pmu_xtalfreq),
1U << PMU_XTALFREQ_REG_MEASURE_SHIFT);
udelay(1000);
ilp_ctr = bcma_read32(core, CHIPCREGOFFS(pmu_xtalfreq)) &
PMU_XTALFREQ_REG_ILPCTR_MASK;
bcma_write32(core, CHIPCREGOFFS(pmu_xtalfreq), 0);
alp_hz = (ilp_ctr * EXT_ILP_HZ) / 4;
alp_khz = (alp_hz + 50000) / 100000 * 100;
} else
alp_khz = 0;
return alp_khz;
}
