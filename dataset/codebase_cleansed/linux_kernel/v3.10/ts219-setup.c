static void __init qnap_ts219_init(void)
{
u32 dev, rev;
kirkwood_init();
kirkwood_mpp_conf(qnap_ts219_mpp_config);
kirkwood_uart0_init();
kirkwood_uart1_init();
qnap_tsx1x_register_flash();
kirkwood_i2c_init();
i2c_register_board_info(0, &qnap_ts219_i2c_rtc, 1);
kirkwood_pcie_id(&dev, &rev);
if (dev == MV88F6282_DEV_ID) {
qnap_ts219_buttons[0].gpio = 43;
qnap_ts219_buttons[1].gpio = 37;
qnap_ts219_ge00_data.phy_addr = MV643XX_ETH_PHY_ADDR(0);
}
kirkwood_ge00_init(&qnap_ts219_ge00_data);
kirkwood_sata_init(&qnap_ts219_sata_data);
kirkwood_ehci_init();
platform_device_register(&qnap_ts219_button_device);
pm_power_off = qnap_tsx1x_power_off;
}
static int __init ts219_pci_init(void)
{
if (machine_is_ts219())
kirkwood_pcie_init(KW_PCIE1 | KW_PCIE0);
return 0;
}
