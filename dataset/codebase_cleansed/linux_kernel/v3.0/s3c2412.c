static int s3c2412_serial_setsource(struct uart_port *port,
struct s3c24xx_uart_clksrc *clk)
{
unsigned long ucon = rd_regl(port, S3C2410_UCON);
ucon &= ~S3C2412_UCON_CLKMASK;
if (strcmp(clk->name, "uclk") == 0)
ucon |= S3C2440_UCON_UCLK;
else if (strcmp(clk->name, "pclk") == 0)
ucon |= S3C2440_UCON_PCLK;
else if (strcmp(clk->name, "usysclk") == 0)
ucon |= S3C2412_UCON_USYSCLK;
else {
printk(KERN_ERR "unknown clock source %s\n", clk->name);
return -EINVAL;
}
wr_regl(port, S3C2410_UCON, ucon);
return 0;
}
static int s3c2412_serial_getsource(struct uart_port *port,
struct s3c24xx_uart_clksrc *clk)
{
unsigned long ucon = rd_regl(port, S3C2410_UCON);
switch (ucon & S3C2412_UCON_CLKMASK) {
case S3C2412_UCON_UCLK:
clk->divisor = 1;
clk->name = "uclk";
break;
case S3C2412_UCON_PCLK:
case S3C2412_UCON_PCLK2:
clk->divisor = 1;
clk->name = "pclk";
break;
case S3C2412_UCON_USYSCLK:
clk->divisor = 1;
clk->name = "usysclk";
break;
}
return 0;
}
static int s3c2412_serial_resetport(struct uart_port *port,
struct s3c2410_uartcfg *cfg)
{
unsigned long ucon = rd_regl(port, S3C2410_UCON);
dbg("%s: port=%p (%08lx), cfg=%p\n",
__func__, port, port->mapbase, cfg);
ucon &= S3C2412_UCON_CLKMASK;
wr_regl(port, S3C2410_UCON, ucon | cfg->ucon);
wr_regl(port, S3C2410_ULCON, cfg->ulcon);
wr_regl(port, S3C2410_UFCON, cfg->ufcon | S3C2410_UFCON_RESETBOTH);
wr_regl(port, S3C2410_UFCON, cfg->ufcon);
return 0;
}
static int s3c2412_serial_probe(struct platform_device *dev)
{
dbg("s3c2440_serial_probe: dev=%p\n", dev);
return s3c24xx_serial_probe(dev, &s3c2412_uart_inf);
}
static inline int s3c2412_serial_init(void)
{
return s3c24xx_serial_init(&s3c2412_serial_driver, &s3c2412_uart_inf);
}
static inline void s3c2412_serial_exit(void)
{
platform_driver_unregister(&s3c2412_serial_driver);
}
