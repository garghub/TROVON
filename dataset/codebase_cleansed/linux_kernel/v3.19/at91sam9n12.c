static void __init at91sam9n12_map_io(void)
{
at91_init_sram(0, AT91SAM9N12_SRAM_BASE, AT91SAM9N12_SRAM_SIZE);
}
static void __init at91sam9n12_initialize(void)
{
at91_sysirq_mask_rtc(AT91SAM9N12_BASE_RTC);
}
