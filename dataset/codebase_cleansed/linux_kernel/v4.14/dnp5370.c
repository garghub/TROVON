static int __init dnp5370_init(void)
{
printk(KERN_INFO "DNP/5370: registering device resources\n");
platform_add_devices(dnp5370_devices, ARRAY_SIZE(dnp5370_devices));
printk(KERN_INFO "DNP/5370: registering %zu SPI slave devices\n",
ARRAY_SIZE(bfin_spi_board_info));
spi_register_board_info(bfin_spi_board_info, ARRAY_SIZE(bfin_spi_board_info));
printk(KERN_INFO "DNP/5370: MAC %pM\n", (void *)FLASH_MAC);
return 0;
}
int bfin_get_ether_addr(char *addr)
{
*(u32 *)(&(addr[0])) = bfin_read32(FLASH_MAC);
*(u16 *)(&(addr[4])) = bfin_read16(FLASH_MAC + 4);
return 0;
}
