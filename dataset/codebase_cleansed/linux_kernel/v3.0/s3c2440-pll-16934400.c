static int s3c2440_plls169344_add(struct sys_device *dev)
{
struct clk *xtal_clk;
unsigned long xtal;
xtal_clk = clk_get(NULL, "xtal");
if (IS_ERR(xtal_clk))
return PTR_ERR(xtal_clk);
xtal = clk_get_rate(xtal_clk);
clk_put(xtal_clk);
if (xtal == 169344000) {
printk(KERN_INFO "Using PLL table for 16.9344MHz crystal\n");
return s3c_plltab_register(s3c2440_plls_169344,
ARRAY_SIZE(s3c2440_plls_169344));
}
return 0;
}
static int __init s3c2440_pll_16934400(void)
{
return sysdev_driver_register(&s3c2440_sysclass,
&s3c2440_plls169344_drv);
}
static int __init s3c2442_pll_16934400(void)
{
return sysdev_driver_register(&s3c2442_sysclass,
&s3c2442_plls169344_drv);
}
