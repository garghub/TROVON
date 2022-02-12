static void __init rd88f6281_init(void)
{
u32 dev, rev;
kirkwood_init();
kirkwood_mpp_conf(rd88f6281_mpp_config);
kirkwood_nand_init(rd88f6281_nand_parts,
ARRAY_SIZE(rd88f6281_nand_parts),
25);
kirkwood_ehci_init();
kirkwood_ge00_init(&rd88f6281_ge00_data);
kirkwood_pcie_id(&dev, &rev);
if (rev == MV88F6281_REV_A0) {
rd88f6281_switch_chip_data.sw_addr = 10;
kirkwood_ge01_init(&rd88f6281_ge01_data);
} else {
rd88f6281_switch_chip_data.port_names[4] = "wan";
}
kirkwood_ge00_switch_init(&rd88f6281_switch_plat_data, NO_IRQ);
kirkwood_sata_init(&rd88f6281_sata_data);
kirkwood_sdio_init(&rd88f6281_mvsdio_data);
kirkwood_uart0_init();
}
static int __init rd88f6281_pci_init(void)
{
if (machine_is_rd88f6281())
kirkwood_pcie_init(KW_PCIE0);
return 0;
}
