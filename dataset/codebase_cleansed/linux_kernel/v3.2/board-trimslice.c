static void trimslice_i2c_init(void)
{
platform_device_register(&tegra_i2c_device1);
platform_device_register(&tegra_i2c_device2);
platform_device_register(&tegra_i2c_device3);
i2c_register_board_info(2, trimslice_i2c3_board_info,
ARRAY_SIZE(trimslice_i2c3_board_info));
}
static void trimslice_usb_init(void)
{
int err;
platform_device_register(&tegra_ehci3_device);
platform_device_register(&tegra_ehci2_device);
err = gpio_request_one(TRIMSLICE_GPIO_USB1_MODE, GPIOF_OUT_INIT_HIGH,
"usb1mode");
if (err) {
pr_err("TrimSlice: failed to obtain USB1 mode gpio: %d\n", err);
return;
}
platform_device_register(&tegra_ehci1_device);
}
static void __init tegra_trimslice_fixup(struct tag *tags, char **cmdline,
struct meminfo *mi)
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
trimslice_i2c_init();
trimslice_usb_init();
}
