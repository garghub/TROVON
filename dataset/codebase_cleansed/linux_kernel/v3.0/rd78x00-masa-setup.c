static void __init rd78x00_masa_init(void)
{
mv78xx0_init();
if (mv78xx0_core_index() == 0) {
mv78xx0_ehci0_init();
mv78xx0_ehci1_init();
mv78xx0_ge00_init(&rd78x00_masa_ge00_data);
mv78xx0_ge10_init(&rd78x00_masa_ge10_data);
mv78xx0_sata_init(&rd78x00_masa_sata_data);
mv78xx0_uart0_init();
mv78xx0_uart2_init();
} else {
mv78xx0_ehci2_init();
mv78xx0_ge01_init(&rd78x00_masa_ge01_data);
mv78xx0_ge11_init(&rd78x00_masa_ge11_data);
mv78xx0_uart1_init();
mv78xx0_uart3_init();
}
}
static int __init rd78x00_pci_init(void)
{
if (machine_is_rd78x00_masa() && mv78xx0_core_index() == 0)
mv78xx0_pcie_init(1, 1);
return 0;
}
