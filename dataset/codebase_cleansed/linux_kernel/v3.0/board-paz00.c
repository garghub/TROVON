static void __init tegra_paz00_fixup(struct machine_desc *desc,
struct tag *tags, char **cmdline, struct meminfo *mi)
{
mi->nr_banks = 1;
mi->bank[0].start = PHYS_OFFSET;
mi->bank[0].size = 448 * SZ_1M;
}
static void __init tegra_paz00_init(void)
{
tegra_clk_init_from_table(paz00_clk_init_table);
paz00_pinmux_init();
tegra_sdhci_device1.dev.platform_data = &sdhci_pdata1;
tegra_sdhci_device2.dev.platform_data = &sdhci_pdata2;
tegra_sdhci_device4.dev.platform_data = &sdhci_pdata4;
platform_add_devices(paz00_devices, ARRAY_SIZE(paz00_devices));
}
