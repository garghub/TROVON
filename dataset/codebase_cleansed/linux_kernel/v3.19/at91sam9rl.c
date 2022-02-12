static void __init at91sam9rl_map_io(void)
{
unsigned long sram_size;
switch (at91_soc_initdata.cidr & AT91_CIDR_SRAMSIZ) {
case AT91_CIDR_SRAMSIZ_32K:
sram_size = 2 * SZ_16K;
break;
case AT91_CIDR_SRAMSIZ_16K:
default:
sram_size = SZ_16K;
}
at91_init_sram(0, AT91SAM9RL_SRAM_BASE, sram_size);
}
static void __init at91sam9rl_initialize(void)
{
arm_pm_idle = at91sam9_idle;
at91_sysirq_mask_rtc(AT91SAM9RL_BASE_RTC);
at91_sysirq_mask_rtt(AT91SAM9RL_BASE_RTT);
}
