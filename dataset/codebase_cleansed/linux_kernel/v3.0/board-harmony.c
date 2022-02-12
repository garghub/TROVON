static void __init harmony_i2c_init(void)
{
tegra_i2c_device1.dev.platform_data = &harmony_i2c1_platform_data;
tegra_i2c_device2.dev.platform_data = &harmony_i2c2_platform_data;
tegra_i2c_device3.dev.platform_data = &harmony_i2c3_platform_data;
tegra_i2c_device4.dev.platform_data = &harmony_dvc_platform_data;
platform_device_register(&tegra_i2c_device1);
platform_device_register(&tegra_i2c_device2);
platform_device_register(&tegra_i2c_device3);
platform_device_register(&tegra_i2c_device4);
i2c_register_board_info(0, &wm8903_board_info, 1);
}
static void __init tegra_harmony_fixup(struct machine_desc *desc,
struct tag *tags, char **cmdline, struct meminfo *mi)
{
mi->nr_banks = 2;
mi->bank[0].start = PHYS_OFFSET;
mi->bank[0].size = 448 * SZ_1M;
mi->bank[1].start = SZ_512M;
mi->bank[1].size = SZ_512M;
}
static void __init tegra_harmony_init(void)
{
tegra_clk_init_from_table(harmony_clk_init_table);
harmony_pinmux_init();
tegra_sdhci_device1.dev.platform_data = &sdhci_pdata1;
tegra_sdhci_device2.dev.platform_data = &sdhci_pdata2;
tegra_sdhci_device4.dev.platform_data = &sdhci_pdata4;
platform_add_devices(harmony_devices, ARRAY_SIZE(harmony_devices));
harmony_i2c_init();
harmony_regulator_init();
}
