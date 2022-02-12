static void __init at91sam9261_map_io(void)
{
if (cpu_is_at91sam9g10())
at91_init_sram(0, AT91SAM9G10_SRAM_BASE, AT91SAM9G10_SRAM_SIZE);
else
at91_init_sram(0, AT91SAM9261_SRAM_BASE, AT91SAM9261_SRAM_SIZE);
}
static void __init at91sam9261_initialize(void)
{
arm_pm_idle = at91sam9_idle;
at91_sysirq_mask_rtt(AT91SAM9261_BASE_RTT);
}
