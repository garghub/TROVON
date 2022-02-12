static void paz00_i2c_init(void)
{
platform_device_register(&tegra_i2c_device1);
platform_device_register(&tegra_i2c_device2);
platform_device_register(&tegra_i2c_device4);
}
static void paz00_usb_init(void)
{
tegra_ehci2_ulpi_phy_config.reset_gpio = TEGRA_ULPI_RST;
platform_device_register(&tegra_ehci2_device);
platform_device_register(&tegra_ehci3_device);
}
static void __init tegra_paz00_fixup(struct tag *tags, char **cmdline,
struct meminfo *mi)
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
tegra_sdhci_device4.dev.platform_data = &sdhci_pdata4;
platform_add_devices(paz00_devices, ARRAY_SIZE(paz00_devices));
paz00_i2c_init();
paz00_usb_init();
}
