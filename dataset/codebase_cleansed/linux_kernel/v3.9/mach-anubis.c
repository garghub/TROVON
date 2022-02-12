static void anubis_nand_select(struct s3c2410_nand_set *set, int slot)
{
unsigned int tmp;
slot = set->nr_map[slot] & 3;
pr_debug("anubis_nand: selecting slot %d (set %p,%p)\n",
slot, set, set->nr_map);
tmp = __raw_readb(ANUBIS_VA_CTRL1);
tmp &= ~ANUBIS_CTRL1_NANDSEL;
tmp |= slot;
pr_debug("anubis_nand: ctrl1 now %02x\n", tmp);
__raw_writeb(tmp, ANUBIS_VA_CTRL1);
}
static void __init anubis_map_io(void)
{
s3c24xx_dclk0.parent = &clk_upll;
s3c24xx_dclk0.rate = 12*1000*1000;
s3c24xx_dclk1.parent = &clk_upll;
s3c24xx_dclk1.rate = 24*1000*1000;
s3c24xx_clkout0.parent = &s3c24xx_dclk0;
s3c24xx_clkout1.parent = &s3c24xx_dclk1;
s3c24xx_uclk.parent = &s3c24xx_clkout1;
s3c24xx_register_clocks(anubis_clocks, ARRAY_SIZE(anubis_clocks));
s3c24xx_init_io(anubis_iodesc, ARRAY_SIZE(anubis_iodesc));
s3c24xx_init_clocks(0);
s3c24xx_init_uarts(anubis_uartcfgs, ARRAY_SIZE(anubis_uartcfgs));
if ((__raw_readb(ANUBIS_VA_IDREG) & ANUBIS_IDREG_REVMASK) >= 4) {
printk(KERN_INFO "ANUBIS-B detected (revision %d)\n",
__raw_readb(ANUBIS_VA_IDREG) & ANUBIS_IDREG_REVMASK);
anubis_nand_sets[0].partitions = anubis_default_nand_part_large;
anubis_nand_sets[0].nr_partitions = ARRAY_SIZE(anubis_default_nand_part_large);
} else {
gpio_request_one(S3C2410_GPA(0), GPIOF_OUT_INIT_HIGH, NULL);
gpio_free(S3C2410_GPA(0));
}
}
static void __init anubis_init(void)
{
s3c_i2c0_set_platdata(NULL);
s3c_nand_set_platdata(&anubis_nand_info);
simtec_audio_add(NULL, false, &anubis_audio);
platform_add_devices(anubis_devices, ARRAY_SIZE(anubis_devices));
i2c_register_board_info(0, anubis_i2c_devs,
ARRAY_SIZE(anubis_i2c_devs));
}
