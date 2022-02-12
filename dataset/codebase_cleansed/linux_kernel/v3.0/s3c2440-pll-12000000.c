static int s3c2440_plls12_add(struct sys_device *dev)
{
struct clk *xtal_clk;
unsigned long xtal;
xtal_clk = clk_get(NULL, "xtal");
if (IS_ERR(xtal_clk))
return PTR_ERR(xtal_clk);
xtal = clk_get_rate(xtal_clk);
clk_put(xtal_clk);
if (xtal == 12000000) {
printk(KERN_INFO "Using PLL table for 12MHz crystal\n");
return s3c_plltab_register(s3c2440_plls_12,
ARRAY_SIZE(s3c2440_plls_12));
}
return 0;
}
static int __init s3c2440_pll_12mhz(void)
{
return sysdev_driver_register(&s3c2440_sysclass, &s3c2440_plls12_drv);
}
static int __init s3c2442_pll_12mhz(void)
{
return sysdev_driver_register(&s3c2442_sysclass, &s3c2442_plls12_drv);
}
