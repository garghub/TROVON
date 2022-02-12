static inline int nxeb500hmi_check(struct clcd_fb *fb, struct fb_var_screeninfo *var)
{
var->green.length = 5;
var->green.msb_right = 0;
return clcdfb_check(fb, var);
}
static int nxeb500hmi_clcd_setup(struct clcd_fb *fb)
{
unsigned int val;
fb->fb.var.green.length = 5;
fb->fb.var.green.msb_right = 0;
val = readl(NETX_SYSTEM_IOC_ACCESS_KEY);
writel(val, NETX_SYSTEM_IOC_ACCESS_KEY);
writel(3, NETX_SYSTEM_IOC_CR);
writel(9, NETX_GPIO_CFG(14));
val = readl(NETX_PIO_OUTPIO);
writel(val | 1, NETX_PIO_OUTPIO);
val = readl(NETX_PIO_OEPIO);
writel(val | 1, NETX_PIO_OEPIO);
return netx_clcd_setup(fb);
}
static void __init nxeb500hmi_init(void)
{
netx_fb_init(&clcd_data, &qvga);
platform_add_devices(devices, ARRAY_SIZE(devices));
}
