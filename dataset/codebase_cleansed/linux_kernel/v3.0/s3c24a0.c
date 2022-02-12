static int s3c24a0_serial_setsource(struct uart_port *port,
struct s3c24xx_uart_clksrc *clk)
{
unsigned long ucon = rd_regl(port, S3C2410_UCON);
if (strcmp(clk->name, "uclk") == 0)
ucon |= S3C2410_UCON_UCLK;
else
ucon &= ~S3C2410_UCON_UCLK;
wr_regl(port, S3C2410_UCON, ucon);
return 0;
}
static int s3c24a0_serial_getsource(struct uart_port *port,
struct s3c24xx_uart_clksrc *clk)
{
unsigned long ucon = rd_regl(port, S3C2410_UCON);
clk->divisor = 1;
clk->name = (ucon & S3C2410_UCON_UCLK) ? "uclk" : "pclk";
return 0;
}
static int s3c24a0_serial_resetport(struct uart_port *port,
struct s3c2410_uartcfg *cfg)
{
dbg("s3c24a0_serial_resetport: port=%p (%08lx), cfg=%p\n",
port, port->mapbase, cfg);
wr_regl(port, S3C2410_UCON, cfg->ucon);
wr_regl(port, S3C2410_ULCON, cfg->ulcon);
wr_regl(port, S3C2410_UFCON, cfg->ufcon | S3C2410_UFCON_RESETBOTH);
wr_regl(port, S3C2410_UFCON, cfg->ufcon);
return 0;
}
static int s3c24a0_serial_probe(struct platform_device *dev)
{
return s3c24xx_serial_probe(dev, &s3c24a0_uart_inf);
}
static int __init s3c24a0_serial_init(void)
{
return s3c24xx_serial_init(&s3c24a0_serial_driver, &s3c24a0_uart_inf);
}
static void __exit s3c24a0_serial_exit(void)
{
platform_driver_unregister(&s3c24a0_serial_driver);
}
