static int s3c2400_serial_getsource(struct uart_port *port,
struct s3c24xx_uart_clksrc *clk)
{
clk->divisor = 1;
clk->name = "pclk";
return 0;
}
static int s3c2400_serial_setsource(struct uart_port *port,
struct s3c24xx_uart_clksrc *clk)
{
return 0;
}
static int s3c2400_serial_resetport(struct uart_port *port,
struct s3c2410_uartcfg *cfg)
{
dbg("s3c2400_serial_resetport: port=%p (%08lx), cfg=%p\n",
port, port->mapbase, cfg);
wr_regl(port, S3C2410_UCON, cfg->ucon);
wr_regl(port, S3C2410_ULCON, cfg->ulcon);
wr_regl(port, S3C2410_UFCON, cfg->ufcon | S3C2410_UFCON_RESETBOTH);
wr_regl(port, S3C2410_UFCON, cfg->ufcon);
return 0;
}
static int s3c2400_serial_probe(struct platform_device *dev)
{
return s3c24xx_serial_probe(dev, &s3c2400_uart_inf);
}
static inline int s3c2400_serial_init(void)
{
return s3c24xx_serial_init(&s3c2400_serial_driver, &s3c2400_uart_inf);
}
static inline void s3c2400_serial_exit(void)
{
platform_driver_unregister(&s3c2400_serial_driver);
}
