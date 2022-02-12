static void __init at91sam9g45_map_io(void)
{
at91_init_sram(0, AT91SAM9G45_SRAM_BASE, AT91SAM9G45_SRAM_SIZE);
}
static void __init at91sam9g45_initialize(void)
{
arm_pm_idle = at91sam9_idle;
at91_sysirq_mask_rtc(AT91SAM9G45_BASE_RTC);
at91_sysirq_mask_rtt(AT91SAM9G45_BASE_RTT);
}
