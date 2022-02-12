static void __init wxl_init(void)
{
mv78xx0_init();
mv78xx0_mpp_conf(wxl_mpp_config);
mv78xx0_ehci0_init();
mv78xx0_ehci1_init();
mv78xx0_ehci2_init();
mv78xx0_ge00_init(&db78x00_ge00_data);
mv78xx0_ge01_init(&db78x00_ge01_data);
mv78xx0_sata_init(&db78x00_sata_data);
mv78xx0_uart0_init();
mv78xx0_uart1_init();
mv78xx0_uart2_init();
mv78xx0_uart3_init();
mv78xx0_i2c_init();
i2c_register_board_info(0, &db78x00_i2c_rtc, 1);
}
static int __init wxl_pci_init(void)
{
if (machine_is_terastation_wxl()) {
if (mv78xx0_core_index() == 0)
mv78xx0_pcie_init(0, 1);
else
mv78xx0_pcie_init(1, 0);
}
return 0;
}
