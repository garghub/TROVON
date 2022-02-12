static void __init qnap_ts41x_init(void)
{
u32 dev, rev;
kirkwood_init();
kirkwood_mpp_conf(qnap_ts41x_mpp_config);
kirkwood_uart0_init();
kirkwood_uart1_init();
qnap_tsx1x_register_flash();
kirkwood_i2c_init();
i2c_register_board_info(0, &qnap_ts41x_i2c_rtc, 1);
kirkwood_pcie_id(&dev, &rev);
if (dev == MV88F6282_DEV_ID) {
qnap_ts41x_ge00_data.phy_addr = MV643XX_ETH_PHY_ADDR(0);
qnap_ts41x_ge01_data.phy_addr = MV643XX_ETH_PHY_ADDR(1);
}
kirkwood_ge00_init(&qnap_ts41x_ge00_data);
kirkwood_ge01_init(&qnap_ts41x_ge01_data);
kirkwood_sata_init(&qnap_ts41x_sata_data);
kirkwood_ehci_init();
platform_device_register(&qnap_ts41x_button_device);
pm_power_off = qnap_tsx1x_power_off;
if (gpio_request(QNAP_TS41X_JUMPER_JP1, "JP1") == 0)
gpio_export(QNAP_TS41X_JUMPER_JP1, 0);
}
static int __init ts41x_pci_init(void)
{
if (machine_is_ts41x()) {
u32 dev, rev;
orion_pcie_reset((void __iomem *)PCIE_VIRT_BASE);
kirkwood_pcie_id(&dev, &rev);
if (dev == MV88F6282_DEV_ID)
kirkwood_pcie_init(KW_PCIE1 | KW_PCIE0);
else
kirkwood_pcie_init(KW_PCIE0);
}
return 0;
}
