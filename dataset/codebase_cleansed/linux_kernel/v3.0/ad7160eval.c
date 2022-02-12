static int __init ad7160eval_init(void)
{
printk(KERN_INFO "%s(): registering device resources\n", __func__);
i2c_register_board_info(0, bfin_i2c_board_info,
ARRAY_SIZE(bfin_i2c_board_info));
platform_add_devices(stamp_devices, ARRAY_SIZE(stamp_devices));
spi_register_board_info(bfin_spi_board_info, ARRAY_SIZE(bfin_spi_board_info));
return 0;
}
void __init native_machine_early_platform_add_devices(void)
{
printk(KERN_INFO "register early platform devices\n");
early_platform_add_devices(ad7160eval_early_devices,
ARRAY_SIZE(ad7160eval_early_devices));
}
void native_machine_restart(char *cmd)
{
if ((bfin_read_SYSCR() & 0x7) == 0x3)
bfin_reset_boot_spi_cs(P_DEFAULT_BOOT_SPI_CS);
}
void bfin_get_ether_addr(char *addr)
{
u32 ret;
u64 otp_mac;
u32 (*otp_read)(u32 page, u32 flags, u64 *page_content) = (void *)0xEF00001A;
ret = otp_read(0xDF, 0x00, &otp_mac);
if (!(ret & 0x1)) {
char *otp_mac_p = (char *)&otp_mac;
for (ret = 0; ret < 6; ++ret)
addr[ret] = otp_mac_p[5 - ret];
}
}
