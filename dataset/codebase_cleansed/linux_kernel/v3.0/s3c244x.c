void __init s3c244x_init_uarts(struct s3c2410_uartcfg *cfg, int no)
{
s3c24xx_init_uartdevs("s3c2440-uart", s3c2410_uart_resources, cfg, no);
}
void __init s3c244x_map_io(void)
{
iotable_init(s3c244x_iodesc, ARRAY_SIZE(s3c244x_iodesc));
s3c_device_sdi.name = "s3c2440-sdi";
s3c_device_i2c0.name = "s3c2440-i2c";
s3c_nand_setname("s3c2440-nand");
s3c_device_ts.name = "s3c2440-ts";
s3c_device_usbgadget.name = "s3c2440-usbgadget";
}
void __init_or_cpufreq s3c244x_setup_clocks(void)
{
struct clk *xtal_clk;
unsigned long clkdiv;
unsigned long camdiv;
unsigned long xtal;
unsigned long hclk, fclk, pclk;
int hdiv = 1;
xtal_clk = clk_get(NULL, "xtal");
xtal = clk_get_rate(xtal_clk);
clk_put(xtal_clk);
fclk = s3c24xx_get_pll(__raw_readl(S3C2410_MPLLCON), xtal) * 2;
clkdiv = __raw_readl(S3C2410_CLKDIVN);
camdiv = __raw_readl(S3C2440_CAMDIVN);
switch (clkdiv & S3C2440_CLKDIVN_HDIVN_MASK) {
case S3C2440_CLKDIVN_HDIVN_1:
hdiv = 1;
break;
case S3C2440_CLKDIVN_HDIVN_2:
hdiv = 2;
break;
case S3C2440_CLKDIVN_HDIVN_4_8:
hdiv = (camdiv & S3C2440_CAMDIVN_HCLK4_HALF) ? 8 : 4;
break;
case S3C2440_CLKDIVN_HDIVN_3_6:
hdiv = (camdiv & S3C2440_CAMDIVN_HCLK3_HALF) ? 6 : 3;
break;
}
hclk = fclk / hdiv;
pclk = hclk / ((clkdiv & S3C2440_CLKDIVN_PDIVN) ? 2 : 1);
printk("S3C244X: core %ld.%03ld MHz, memory %ld.%03ld MHz, peripheral %ld.%03ld MHz\n",
print_mhz(fclk), print_mhz(hclk), print_mhz(pclk));
s3c24xx_setup_clocks(fclk, hclk, pclk);
}
void __init s3c244x_init_clocks(int xtal)
{
s3c24xx_register_baseclocks(xtal);
s3c244x_setup_clocks();
s3c2410_baseclk_add();
}
static int __init s3c2440_core_init(void)
{
return sysdev_class_register(&s3c2440_sysclass);
}
static int __init s3c2442_core_init(void)
{
return sysdev_class_register(&s3c2442_sysclass);
}
static int s3c244x_suspend(void)
{
s3c_pm_do_save(s3c244x_sleep, ARRAY_SIZE(s3c244x_sleep));
return 0;
}
static void s3c244x_resume(void)
{
s3c_pm_do_restore(s3c244x_sleep, ARRAY_SIZE(s3c244x_sleep));
}
