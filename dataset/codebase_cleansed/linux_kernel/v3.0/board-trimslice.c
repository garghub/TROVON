static void __init tegra_trimslice_fixup(struct machine_desc *desc,
struct tag *tags, char **cmdline, struct meminfo *mi)
{
mi->nr_banks = 2;
mi->bank[0].start = PHYS_OFFSET;
mi->bank[0].size = 448 * SZ_1M;
mi->bank[1].start = SZ_512M;
mi->bank[1].size = SZ_512M;
}
static int __init tegra_trimslice_pci_init(void)
{
if (!machine_is_trimslice())
return 0;
return tegra_pcie_init(true, true);
}
static void __init tegra_trimslice_init(void)
{
tegra_clk_init_from_table(trimslice_clk_init_table);
trimslice_pinmux_init();
tegra_sdhci_device1.dev.platform_data = &sdhci_pdata1;
tegra_sdhci_device4.dev.platform_data = &sdhci_pdata4;
platform_add_devices(trimslice_devices, ARRAY_SIZE(trimslice_devices));
}
