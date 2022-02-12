static void __init at91sam9263_map_io(void)
{
at91_init_sram(0, AT91SAM9263_SRAM0_BASE, AT91SAM9263_SRAM0_SIZE);
at91_init_sram(1, AT91SAM9263_SRAM1_BASE, AT91SAM9263_SRAM1_SIZE);
}
static void __init at91sam9263_initialize(void)
{
arm_pm_idle = at91sam9_idle;
at91_sysirq_mask_rtt(AT91SAM9263_BASE_RTT0);
at91_sysirq_mask_rtt(AT91SAM9263_BASE_RTT1);
}
