static void osiris_nand_select(struct s3c2410_nand_set *set, int slot)
{
unsigned int tmp;
slot = set->nr_map[slot] & 3;
pr_debug("osiris_nand: selecting slot %d (set %p,%p)\n",
slot, set, set->nr_map);
tmp = __raw_readb(OSIRIS_VA_CTRL0);
tmp &= ~OSIRIS_CTRL0_NANDSEL;
tmp |= slot;
pr_debug("osiris_nand: ctrl0 now %02x\n", tmp);
__raw_writeb(tmp, OSIRIS_VA_CTRL0);
}
static int osiris_pm_suspend(void)
{
unsigned int tmp;
pm_osiris_ctrl0 = __raw_readb(OSIRIS_VA_CTRL0);
tmp = pm_osiris_ctrl0 & ~OSIRIS_CTRL0_NANDSEL;
if ((pm_osiris_ctrl0 & OSIRIS_CTRL0_BOOT_INT) == 0)
tmp |= 2;
__raw_writeb(tmp, OSIRIS_VA_CTRL0);
gpio_request_one(S3C2410_GPA(21), GPIOF_OUT_INIT_HIGH, NULL);
gpio_free(S3C2410_GPA(21));
return 0;
}
static void osiris_pm_resume(void)
{
if (pm_osiris_ctrl0 & OSIRIS_CTRL0_FIX8)
__raw_writeb(OSIRIS_CTRL1_FIX8, OSIRIS_VA_CTRL1);
__raw_writeb(pm_osiris_ctrl0, OSIRIS_VA_CTRL0);
s3c_gpio_cfgpin(S3C2410_GPA(21), S3C2410_GPA21_nRSTOUT);
}
static void osiris_tps_release(struct device *dev)
{
}
static int osiris_tps_setup(struct i2c_client *client, void *context)
{
osiris_tps_device.dev.parent = &client->dev;
return platform_device_register(&osiris_tps_device);
}
static int osiris_tps_remove(struct i2c_client *client, void *context)
{
platform_device_unregister(&osiris_tps_device);
return 0;
}
static void __init osiris_map_io(void)
{
unsigned long flags;
s3c24xx_init_io(osiris_iodesc, ARRAY_SIZE(osiris_iodesc));
s3c24xx_init_uarts(osiris_uartcfgs, ARRAY_SIZE(osiris_uartcfgs));
samsung_set_timer_source(SAMSUNG_PWM3, SAMSUNG_PWM4);
if ((__raw_readb(OSIRIS_VA_IDREG) & OSIRIS_ID_REVMASK) >= 4) {
printk(KERN_INFO "OSIRIS-B detected (revision %d)\n",
__raw_readb(OSIRIS_VA_IDREG) & OSIRIS_ID_REVMASK);
osiris_nand_sets[0].partitions = osiris_default_nand_part_large;
osiris_nand_sets[0].nr_partitions = ARRAY_SIZE(osiris_default_nand_part_large);
} else {
gpio_request_one(S3C2410_GPA(0), GPIOF_OUT_INIT_HIGH, NULL);
gpio_free(S3C2410_GPA(0));
}
local_irq_save(flags);
__raw_writel(__raw_readl(S3C2410_BWSCON) | S3C2410_BWSCON_ST1 | S3C2410_BWSCON_ST2 | S3C2410_BWSCON_ST3 | S3C2410_BWSCON_ST4 | S3C2410_BWSCON_ST5, S3C2410_BWSCON);
local_irq_restore(flags);
}
static void __init osiris_init_time(void)
{
s3c2440_init_clocks(12000000);
samsung_timer_init();
}
static void __init osiris_init(void)
{
register_syscore_ops(&osiris_pm_syscore_ops);
s3c_i2c0_set_platdata(NULL);
s3c_nand_set_platdata(&osiris_nand_info);
s3c_cpufreq_setboard(&osiris_cpufreq);
i2c_register_board_info(0, osiris_i2c_devs,
ARRAY_SIZE(osiris_i2c_devs));
platform_add_devices(osiris_devices, ARRAY_SIZE(osiris_devices));
}
