void __init plat_time_init(void)
{
char *endp, *s;
unsigned long cpu_rate = 0;
if (cpu_rate == 0) {
s = prom_getenv("clkfreqhz");
cpu_rate = simple_strtoul(s, &endp, 10);
if (endp != NULL && *endp != 0) {
printk(KERN_ERR
"Clock rate in Hz parse error: %s\n", s);
cpu_rate = 0;
}
}
if (cpu_rate == 0) {
s = prom_getenv("clkfreq");
cpu_rate = 1000 * simple_strtoul(s, &endp, 10);
if (endp != NULL && *endp != 0) {
printk(KERN_ERR
"Clock rate in MHz parse error: %s\n", s);
cpu_rate = 0;
}
}
if (cpu_rate == 0) {
#if defined(CONFIG_PMC_MSP7120_EVAL) \
|| defined(CONFIG_PMC_MSP7120_GW)
cpu_rate = 400000000;
#elif defined(CONFIG_PMC_MSP7120_FPGA)
cpu_rate = 25000000;
#else
cpu_rate = 150000000;
#endif
printk(KERN_ERR
"Failed to determine CPU clock rate, "
"assuming %ld hz ...\n", cpu_rate);
}
printk(KERN_WARNING "Clock rate set to %ld\n", cpu_rate);
mips_hpt_frequency = cpu_rate/2;
}
unsigned int __cpuinit get_c0_compare_int(void)
{
if ((get_current_vpe()) && !tim_installed) {
memcpy(&timer_vpe1, &c0_compare_irqaction, sizeof(timer_vpe1));
setup_irq(MSP_INT_VPE1_TIMER, &timer_vpe1);
tim_installed++;
}
return get_current_vpe() ? MSP_INT_VPE1_TIMER : MSP_INT_VPE0_TIMER;
}
