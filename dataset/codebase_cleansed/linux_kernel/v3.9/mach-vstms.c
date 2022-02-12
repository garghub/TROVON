static void __init vstms_fixup(struct tag *tags, char **cmdline,
struct meminfo *mi)
{
if (tags != phys_to_virt(S3C2410_SDRAM_PA + 0x100)) {
mi->nr_banks=1;
mi->bank[0].start = 0x30000000;
mi->bank[0].size = SZ_64M;
}
}
static void __init vstms_map_io(void)
{
s3c24xx_init_io(vstms_iodesc, ARRAY_SIZE(vstms_iodesc));
s3c24xx_init_clocks(12000000);
s3c24xx_init_uarts(vstms_uartcfgs, ARRAY_SIZE(vstms_uartcfgs));
}
static void __init vstms_init(void)
{
s3c_i2c0_set_platdata(NULL);
s3c_nand_set_platdata(&vstms_nand_info);
platform_add_devices(vstms_devices, ARRAY_SIZE(vstms_devices));
}
