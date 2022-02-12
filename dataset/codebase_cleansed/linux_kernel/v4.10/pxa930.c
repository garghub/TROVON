static int __init pxa930_init(void)
{
int ret = 0;
if (cpu_is_pxa93x()) {
mfp_init_base(io_p2v(MFPR_BASE));
mfp_init_addr(pxa930_mfp_addr_map);
platform_device_add_data(&pxa93x_device_gpio,
&pxa93x_gpio_pdata,
sizeof(pxa93x_gpio_pdata));
ret = platform_device_register(&pxa93x_device_gpio);
}
if (cpu_is_pxa935())
mfp_init_addr(pxa935_mfp_addr_map);
return 0;
}
