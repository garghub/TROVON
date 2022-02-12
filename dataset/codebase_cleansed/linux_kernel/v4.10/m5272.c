static void __init m5272_uarts_init(void)
{
u32 v;
v = readl(MCFSIM_PBCNT);
v = (v & ~0x000000ff) | 0x00000055;
writel(v, MCFSIM_PBCNT);
v = readl(MCFSIM_PDCNT);
v = (v & ~0x000003fc) | 0x000002a8;
writel(v, MCFSIM_PDCNT);
}
static void m5272_cpu_reset(void)
{
local_irq_disable();
__raw_writew(0, MCFSIM_WIRR);
__raw_writew(1, MCFSIM_WRRR);
__raw_writew(0, MCFSIM_WCR);
for (;;)
;
}
void __init config_BSP(char *commandp, int size)
{
#if defined (CONFIG_MOD5272)
writeb(0x40, MCFSIM_PIVR);
#endif
#if defined(CONFIG_NETtel) || defined(CONFIG_SCALES)
memcpy(commandp, (char *) 0xf0004000, size);
commandp[size-1] = 0;
#elif defined(CONFIG_CANCam)
memcpy(commandp, (char *) 0xf0010000, size);
commandp[size-1] = 0;
#endif
mach_reset = m5272_cpu_reset;
mach_sched_init = hw_timer_init;
}
static int __init init_BSP(void)
{
m5272_uarts_init();
fixed_phy_add(PHY_POLL, 0, &nettel_fixed_phy_status, -1);
return 0;
}
