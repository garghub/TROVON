void __msm_gpiomux_write(unsigned gpio, gpiomux_config_t val)
{
unsigned tlmm_config = (val & ~GPIOMUX_CTL_MASK) |
((gpio & 0x3ff) << 4);
unsigned tlmm_disable = 0;
int rc;
rc = msm_proc_comm(PCOM_RPC_GPIO_TLMM_CONFIG_EX,
&tlmm_config, &tlmm_disable);
if (rc)
pr_err("%s: unexpected proc_comm failure %d: %08x %08x\n",
__func__, rc, tlmm_config, tlmm_disable);
}
