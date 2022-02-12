static int s3c2410_plls_add(struct device *dev, struct subsys_interface *sif)
{
return s3c_plltab_register(pll_vals_12MHz, ARRAY_SIZE(pll_vals_12MHz));
}
static int __init s3c2410_pll_init(void)
{
return subsys_interface_register(&s3c2410_plls_interface);
}
static int __init s3c2410a_pll_init(void)
{
return subsys_interface_register(&s3c2410a_plls_interface);
}
