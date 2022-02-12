static void vt8500_power_off(void)
{
local_irq_disable();
writew(5, pmc_hiber);
asm("mcr%? p15, 0, %0, c7, c0, 4" : : "r" (0));
}
void __init bv07_init(void)
{
#ifdef CONFIG_FB_VT8500
void __iomem *gpio_mux_reg = ioremap(wmt_gpio_base + 0x200, 4);
if (gpio_mux_reg) {
writel(readl(gpio_mux_reg) | 1, gpio_mux_reg);
iounmap(gpio_mux_reg);
} else {
printk(KERN_ERR "Could not remap the GPIO mux register, display may not work properly!\n");
}
#endif
pmc_hiber = ioremap(wmt_pmc_base + 0x12, 2);
if (pmc_hiber)
pm_power_off = &vt8500_power_off;
else
printk(KERN_ERR "PMC Hibernation register could not be remapped, not enabling power off!\n");
vt8500_set_resources();
platform_add_devices(devices, ARRAY_SIZE(devices));
vt8500_gpio_init();
}
