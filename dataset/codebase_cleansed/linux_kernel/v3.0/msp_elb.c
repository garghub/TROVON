static int __init msp_elb_setup(void)
{
#if defined(CONFIG_PMC_MSP7120_GW) \
|| defined(CONFIG_PMC_MSP7120_EVAL)
*CS1_CNFG_REG = *CS2_CNFG_REG = *CS3_CNFG_REG = *CS0_CNFG_REG;
#endif
return 0;
}
