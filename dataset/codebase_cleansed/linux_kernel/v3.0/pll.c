static int s3c2410_plls_add(struct sys_device *dev)
{
return s3c_plltab_register(pll_vals_12MHz, ARRAY_SIZE(pll_vals_12MHz));
}
static int __init s3c2410_pll_init(void)
{
return sysdev_driver_register(&s3c2410_sysclass, &s3c2410_plls_drv);
}
static int __init s3c2410a_pll_init(void)
{
return sysdev_driver_register(&s3c2410a_sysclass, &s3c2410a_plls_drv);
}
