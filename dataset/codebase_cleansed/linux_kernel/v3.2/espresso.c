static int __init espresso_pci_init(void)
{
if (machine_is_espresso())
ixp23xx_pci_slave_init();
return 0;
}
static void __init espresso_init(void)
{
platform_device_register(&espresso_flash);
IXP23XX_EXP_CS0[0] |= IXP23XX_FLASH_WRITABLE;
IXP23XX_EXP_CS0[1] |= IXP23XX_FLASH_WRITABLE;
ixp23xx_sys_init();
}
