u16 si_pmu_fast_pwrup_delay(struct si_pub *sih)
{
uint delay = PMU_MAX_TRANSITION_DLY;
switch (ai_get_chip_id(sih)) {
case BCMA_CHIP_ID_BCM43224:
case BCMA_CHIP_ID_BCM43225:
case BCMA_CHIP_ID_BCM4313:
delay = 3700;
break;
default:
break;
}
return (u16) delay;
}
u32 si_pmu_measure_alpclk(struct si_pub *sih)
{
struct si_info *sii = container_of(sih, struct si_info, pub);
struct bcma_device *core;
u32 alp_khz;
if (ai_get_pmurev(sih) < 10)
return 0;
core = sii->icbus->drv_cc.core;
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
