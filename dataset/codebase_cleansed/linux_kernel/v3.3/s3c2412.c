static inline void s3c2412_init_gpio2(void)
{
s3c24xx_va_gpio2 = S3C24XX_VA_GPIO + 0x10;
}
void __init s3c2412_init_uarts(struct s3c2410_uartcfg *cfg, int no)
{
s3c24xx_init_uartdevs("s3c2412-uart", s3c2410_uart_resources, cfg, no);
s3c_device_sdi.name = "s3c2412-sdi";
s3c_device_lcd.name = "s3c2412-lcd";
s3c_nand_setname("s3c2412-nand");
s3c_device_sdi.resource[1].start = IRQ_S3C2412_SDI;
s3c_device_sdi.resource[1].end = IRQ_S3C2412_SDI;
s3c_device_spi0.name = "s3c2412-spi";
s3c_device_spi0.resource[0].end = S3C24XX_PA_SPI + 0x24;
s3c_device_spi1.name = "s3c2412-spi";
s3c_device_spi1.resource[0].start = S3C24XX_PA_SPI + S3C2412_SPI1;
s3c_device_spi1.resource[0].end = S3C24XX_PA_SPI + S3C2412_SPI1 + 0x24;
}
static void s3c2412_idle(void)
{
unsigned long tmp;
tmp = __raw_readl(S3C2412_PWRCFG);
tmp &= ~S3C2412_PWRCFG_STANDBYWFI_MASK;
tmp |= S3C2412_PWRCFG_STANDBYWFI_IDLE;
__raw_writel(tmp, S3C2412_PWRCFG);
cpu_do_idle();
}
void s3c2412_restart(char mode, const char *cmd)
{
if (mode == 's')
soft_restart(0);
__raw_writel(0x00, S3C2412_CLKSRC);
__raw_writel(S3C2412_SWRST_RESET, S3C2412_SWRST);
mdelay(1);
}
void __init s3c2412_map_io(void)
{
s3c2412_init_gpio2();
s3c24xx_idle = s3c2412_idle;
iotable_init(s3c2412_iodesc, ARRAY_SIZE(s3c2412_iodesc));
}
void __init_or_cpufreq s3c2412_setup_clocks(void)
{
struct clk *xtal_clk;
unsigned long tmp;
unsigned long xtal;
unsigned long fclk;
unsigned long hclk;
unsigned long pclk;
xtal_clk = clk_get(NULL, "xtal");
xtal = clk_get_rate(xtal_clk);
clk_put(xtal_clk);
fclk = s3c24xx_get_pll(__raw_readl(S3C2410_MPLLCON), xtal * 2);
clk_mpll.rate = fclk;
tmp = __raw_readl(S3C2410_CLKDIVN);
hclk = fclk / ((tmp & S3C2412_CLKDIVN_HDIVN_MASK) + 1);
hclk /= ((tmp & S3C2412_CLKDIVN_ARMDIVN) ? 2 : 1);
pclk = hclk / ((tmp & S3C2412_CLKDIVN_PDIVN) ? 2 : 1);
printk("S3C2412: core %ld.%03ld MHz, memory %ld.%03ld MHz, peripheral %ld.%03ld MHz\n",
print_mhz(fclk), print_mhz(hclk), print_mhz(pclk));
s3c24xx_setup_clocks(fclk, hclk, pclk);
}
void __init s3c2412_init_clocks(int xtal)
{
s3c24xx_register_baseclocks(xtal);
s3c2412_setup_clocks();
s3c2412_baseclk_add();
}
static int __init s3c2412_core_init(void)
{
return subsys_system_register(&s3c2412_subsys, NULL);
}
int __init s3c2412_init(void)
{
printk("S3C2412: Initialising architecture\n");
#ifdef CONFIG_PM
register_syscore_ops(&s3c2412_pm_syscore_ops);
#endif
register_syscore_ops(&s3c24xx_irq_syscore_ops);
return device_register(&s3c2412_dev);
}
