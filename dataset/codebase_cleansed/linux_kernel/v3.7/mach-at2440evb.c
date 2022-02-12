static void __init at2440evb_map_io(void)
{
s3c24xx_init_io(at2440evb_iodesc, ARRAY_SIZE(at2440evb_iodesc));
s3c24xx_init_clocks(16934400);
s3c24xx_init_uarts(at2440evb_uartcfgs, ARRAY_SIZE(at2440evb_uartcfgs));
}
static void __init at2440evb_init(void)
{
s3c24xx_fb_set_platdata(&at2440evb_fb_info);
s3c24xx_mci_set_platdata(&at2440evb_mci_pdata);
s3c_nand_set_platdata(&at2440evb_nand_info);
s3c_i2c0_set_platdata(NULL);
platform_add_devices(at2440evb_devices, ARRAY_SIZE(at2440evb_devices));
}
