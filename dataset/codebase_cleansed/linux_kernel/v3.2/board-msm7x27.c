static void __init msm7x2x_init_irq(void)
{
msm_init_irq();
}
static void __init msm7x2x_init(void)
{
if (socinfo_init() < 0)
BUG();
if (machine_is_msm7x25_ffa() || machine_is_msm7x27_ffa()) {
smc91x_resources[0].start = 0x98000300;
smc91x_resources[0].end = 0x980003ff;
smc91x_resources[1].start = MSM_GPIO_TO_INT(85);
smc91x_resources[1].end = MSM_GPIO_TO_INT(85);
if (gpio_tlmm_config(GPIO_CFG(85, 0,
GPIO_INPUT,
GPIO_PULL_DOWN,
GPIO_2MA),
GPIO_ENABLE)) {
printk(KERN_ERR
"%s: Err: Config GPIO-85 INT\n",
__func__);
}
}
platform_add_devices(devices, ARRAY_SIZE(devices));
}
static void __init msm7x2x_map_io(void)
{
msm_map_common_io();
if (machine_is_msm7x27_surf() || machine_is_msm7x27_ffa())
msm_clock_init(msm_clocks_7x27, msm_num_clocks_7x27);
if (machine_is_msm7x25_surf() || machine_is_msm7x25_ffa())
msm_clock_init(msm_clocks_7x25, msm_num_clocks_7x25);
#ifdef CONFIG_CACHE_L2X0
if (machine_is_msm7x27_surf() || machine_is_msm7x27_ffa()) {
l2x0_init(MSM_L2CC_BASE, 0x00068012, 0xfe000000);
}
#endif
}
