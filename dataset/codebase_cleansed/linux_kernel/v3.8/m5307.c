void __init config_BSP(char *commandp, int size)
{
#if defined(CONFIG_NETtel) || \
defined(CONFIG_SECUREEDGEMP3) || defined(CONFIG_CLEOPATRA)
memcpy(commandp, (char *) 0xf0004000, size);
commandp[size-1] = 0;
#endif
mach_sched_init = hw_timer_init;
mcf_mapirq2imr(25, MCFINTC_EINT1);
mcf_mapirq2imr(27, MCFINTC_EINT3);
mcf_mapirq2imr(29, MCFINTC_EINT5);
mcf_mapirq2imr(31, MCFINTC_EINT7);
#ifdef CONFIG_BDM_DISABLE
wdebug(MCFDEBUG_CSR, MCFDEBUG_CSR_PSTCLK);
#endif
}
