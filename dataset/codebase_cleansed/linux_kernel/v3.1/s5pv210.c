static int s5pv210_serial_setsource(struct uart_port *port,
struct s3c24xx_uart_clksrc *clk)
{
struct s3c2410_uartcfg *cfg = port->dev->platform_data;
unsigned long ucon = rd_regl(port, S3C2410_UCON);
if (cfg->flags & NO_NEED_CHECK_CLKSRC)
return 0;
if (strcmp(clk->name, "pclk") == 0)
ucon &= ~S5PV210_UCON_CLKMASK;
else if (strcmp(clk->name, "uclk1") == 0)
ucon |= S5PV210_UCON_CLKMASK;
else {
printk(KERN_ERR "unknown clock source %s\n", clk->name);
return -EINVAL;
}
wr_regl(port, S3C2410_UCON, ucon);
return 0;
}
static int s5pv210_serial_getsource(struct uart_port *port,
struct s3c24xx_uart_clksrc *clk)
{
struct s3c2410_uartcfg *cfg = port->dev->platform_data;
u32 ucon = rd_regl(port, S3C2410_UCON);
clk->divisor = 1;
if (cfg->flags & NO_NEED_CHECK_CLKSRC)
return 0;
switch (ucon & S5PV210_UCON_CLKMASK) {
case S5PV210_UCON_PCLK:
clk->name = "pclk";
break;
case S5PV210_UCON_UCLK:
clk->name = "uclk1";
break;
}
return 0;
}
static int s5pv210_serial_resetport(struct uart_port *port,
struct s3c2410_uartcfg *cfg)
{
unsigned long ucon = rd_regl(port, S3C2410_UCON);
ucon &= S5PV210_UCON_CLKMASK;
wr_regl(port, S3C2410_UCON, ucon | cfg->ucon);
wr_regl(port, S3C2410_ULCON, cfg->ulcon);
wr_regl(port, S3C2410_UFCON, cfg->ufcon | S3C2410_UFCON_RESETBOTH);
wr_regl(port, S3C2410_UFCON, cfg->ufcon);
udelay(1);
return 0;
}
static int s5p_serial_probe(struct platform_device *pdev)
{
return s3c24xx_serial_probe(pdev, s5p_uart_inf[pdev->id]);
}
static int __init s5p_serial_init(void)
{
return s3c24xx_serial_init(&s5p_serial_driver, *s5p_uart_inf);
}
static void __exit s5p_serial_exit(void)
{
platform_driver_unregister(&s5p_serial_driver);
}
