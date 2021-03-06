void mx5_cpu_lp_set(enum mxc_cpu_pwr_mode mode)
{
u32 plat_lpc, arm_srpgcr, ccm_clpcr;
u32 empgc0, empgc1;
int stop_mode = 0;
plat_lpc = __raw_readl(MXC_CORTEXA8_PLAT_LPC) &
~(MXC_CORTEXA8_PLAT_LPC_DSM);
ccm_clpcr = __raw_readl(MXC_CCM_CLPCR) & ~(MXC_CCM_CLPCR_LPM_MASK);
arm_srpgcr = __raw_readl(MXC_SRPG_ARM_SRPGCR) & ~(MXC_SRPGCR_PCR);
empgc0 = __raw_readl(MXC_SRPG_EMPGC0_SRPGCR) & ~(MXC_SRPGCR_PCR);
empgc1 = __raw_readl(MXC_SRPG_EMPGC1_SRPGCR) & ~(MXC_SRPGCR_PCR);
switch (mode) {
case WAIT_CLOCKED:
break;
case WAIT_UNCLOCKED:
ccm_clpcr |= 0x1 << MXC_CCM_CLPCR_LPM_OFFSET;
break;
case WAIT_UNCLOCKED_POWER_OFF:
case STOP_POWER_OFF:
plat_lpc |= MXC_CORTEXA8_PLAT_LPC_DSM
| MXC_CORTEXA8_PLAT_LPC_DBG_DSM;
if (mode == WAIT_UNCLOCKED_POWER_OFF) {
ccm_clpcr |= 0x1 << MXC_CCM_CLPCR_LPM_OFFSET;
ccm_clpcr &= ~MXC_CCM_CLPCR_VSTBY;
ccm_clpcr &= ~MXC_CCM_CLPCR_SBYOS;
stop_mode = 0;
} else {
ccm_clpcr |= 0x2 << MXC_CCM_CLPCR_LPM_OFFSET;
ccm_clpcr |= 0x3 << MXC_CCM_CLPCR_STBY_COUNT_OFFSET;
ccm_clpcr |= MXC_CCM_CLPCR_VSTBY;
ccm_clpcr |= MXC_CCM_CLPCR_SBYOS;
stop_mode = 1;
}
arm_srpgcr |= MXC_SRPGCR_PCR;
if (tzic_enable_wake(1) != 0)
return;
break;
case STOP_POWER_ON:
ccm_clpcr |= 0x2 << MXC_CCM_CLPCR_LPM_OFFSET;
break;
default:
printk(KERN_WARNING "UNKNOWN cpu power mode: %d\n", mode);
return;
}
__raw_writel(plat_lpc, MXC_CORTEXA8_PLAT_LPC);
__raw_writel(ccm_clpcr, MXC_CCM_CLPCR);
__raw_writel(arm_srpgcr, MXC_SRPG_ARM_SRPGCR);
if (mx50_revision() != IMX_CHIP_REVISION_1_0)
__raw_writel(arm_srpgcr, MXC_SRPG_NEON_SRPGCR);
if (stop_mode) {
empgc0 |= MXC_SRPGCR_PCR;
empgc1 |= MXC_SRPGCR_PCR;
__raw_writel(empgc0, MXC_SRPG_EMPGC0_SRPGCR);
__raw_writel(empgc1, MXC_SRPG_EMPGC1_SRPGCR);
}
}
