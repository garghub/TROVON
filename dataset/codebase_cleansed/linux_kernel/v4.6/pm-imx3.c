void mx3_cpu_lp_set(enum mx3_cpu_pwr_mode mode)
{
int reg = imx_readl(mx3_ccm_base + MXC_CCM_CCMR);
reg &= ~MXC_CCM_CCMR_LPM_MASK;
switch (mode) {
case MX3_WAIT:
if (cpu_is_mx35())
reg |= MXC_CCM_CCMR_LPM_WAIT_MX35;
imx_writel(reg, mx3_ccm_base + MXC_CCM_CCMR);
break;
default:
pr_err("Unknown cpu power mode: %d\n", mode);
return;
}
}
