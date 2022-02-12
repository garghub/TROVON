static void __init init_eval_h7202(void)
{
init_hw_h7202();
(void) platform_add_devices(devices, ARRAY_SIZE(devices));
CPU_REG (GPIO_B_VIRT, GPIO_POL) &= ~(1 << 8);
CPU_REG (GPIO_B_VIRT, GPIO_EN) |= (1 << 8);
}
