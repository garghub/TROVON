static void __init db88f6281_init(void)
{
kirkwood_init();
kirkwood_mpp_conf(db88f6281_mpp_config);
kirkwood_nand_init(ARRAY_AND_SIZE(db88f6281_nand_parts), 25);
kirkwood_ehci_init();
kirkwood_ge00_init(&db88f6281_ge00_data);
kirkwood_sata_init(&db88f6281_sata_data);
kirkwood_uart0_init();
kirkwood_sdio_init(&db88f6281_mvsdio_data);
}
static int __init db88f6281_pci_init(void)
{
if (machine_is_db88f6281_bp()) {
u32 dev, rev;
kirkwood_pcie_id(&dev, &rev);
if (dev == MV88F6282_DEV_ID)
kirkwood_pcie_init(KW_PCIE1 | KW_PCIE0);
else
kirkwood_pcie_init(KW_PCIE0);
}
return 0;
}
