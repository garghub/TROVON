static void __init sama5d3_map_io(void)
{
at91_init_sram(0, SAMA5D3_SRAM_BASE, SAMA5D3_SRAM_SIZE);
}
static void __init sama5d3_initialize(void)
{
at91_sysirq_mask_rtc(SAMA5D3_BASE_RTC);
}
