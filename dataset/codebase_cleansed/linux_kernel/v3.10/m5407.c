void __init config_BSP(char *commandp, int size)
{
mach_sched_init = hw_timer_init;
mcf_mapirq2imr(25, MCFINTC_EINT1);
mcf_mapirq2imr(27, MCFINTC_EINT3);
mcf_mapirq2imr(29, MCFINTC_EINT5);
mcf_mapirq2imr(31, MCFINTC_EINT7);
}
