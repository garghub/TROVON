static void __init bockw_init(void)
{
void __iomem *base;
r8a7778_clock_init();
r8a7778_init_irq_extpin(1);
r8a7778_add_standard_devices();
r8a7778_add_usb_phy_device(&usb_phy_platform_data);
r8a7778_add_ether_device(&ether_platform_data);
r8a7778_add_i2c_device(0);
r8a7778_add_hspi_device(0);
r8a7778_add_mmc_device(&sh_mmcif_plat);
i2c_register_board_info(0, i2c0_devices,
ARRAY_SIZE(i2c0_devices));
spi_register_board_info(spi_board_info,
ARRAY_SIZE(spi_board_info));
pinctrl_register_mappings(bockw_pinctrl_map,
ARRAY_SIZE(bockw_pinctrl_map));
r8a7778_pinmux_init();
base = ioremap_nocache(FPGA, SZ_1M);
if (base) {
u16 val = ioread16(base + IRQ0MR);
val &= ~(1 << 4);
iowrite16(val, base + IRQ0MR);
iounmap(base);
regulator_register_fixed(0, dummy_supplies,
ARRAY_SIZE(dummy_supplies));
platform_device_register_resndata(
&platform_bus, "smsc911x", -1,
smsc911x_resources, ARRAY_SIZE(smsc911x_resources),
&smsc911x_data, sizeof(smsc911x_data));
}
base = ioremap_nocache(PFC, 0x200);
if (base) {
iowrite32(ioread32(base + PUPR4) | (3 << 26), base + PUPR4);
iounmap(base);
r8a7778_sdhi_init(0, &sdhi0_info);
}
}
