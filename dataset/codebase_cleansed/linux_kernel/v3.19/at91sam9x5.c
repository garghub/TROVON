static void __init at91sam9x5_map_io(void)
{
at91_init_sram(0, AT91SAM9X5_SRAM_BASE, AT91SAM9X5_SRAM_SIZE);
}
static void __init at91sam9x5_initialize(void)
{
at91_sysirq_mask_rtc(AT91SAM9X5_BASE_RTC);
}
