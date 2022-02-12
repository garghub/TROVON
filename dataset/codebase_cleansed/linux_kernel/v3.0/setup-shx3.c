static int __init shx3_devices_setup(void)
{
return platform_add_devices(shx3_early_devices,
ARRAY_SIZE(shx3_early_devices));
}
void __init plat_early_device_setup(void)
{
early_platform_add_devices(shx3_early_devices,
ARRAY_SIZE(shx3_early_devices));
}
void __init plat_irq_setup_pins(int mode)
{
int ret = 0;
switch (mode) {
case IRQ_MODE_IRQ:
ret |= gpio_request(GPIO_FN_IRQ3, intc_desc_irq.name);
ret |= gpio_request(GPIO_FN_IRQ2, intc_desc_irq.name);
ret |= gpio_request(GPIO_FN_IRQ1, intc_desc_irq.name);
ret |= gpio_request(GPIO_FN_IRQ0, intc_desc_irq.name);
if (unlikely(ret)) {
pr_err("Failed to set IRQ mode\n");
return;
}
register_intc_controller(&intc_desc_irq);
break;
case IRQ_MODE_IRL3210:
ret |= gpio_request(GPIO_FN_IRL3, intc_desc_irl.name);
ret |= gpio_request(GPIO_FN_IRL2, intc_desc_irl.name);
ret |= gpio_request(GPIO_FN_IRL1, intc_desc_irl.name);
ret |= gpio_request(GPIO_FN_IRL0, intc_desc_irl.name);
if (unlikely(ret)) {
pr_err("Failed to set IRL mode\n");
return;
}
register_intc_controller(&intc_desc_irl);
break;
default:
BUG();
}
}
void __init plat_irq_setup(void)
{
reserve_intc_vectors(vectors_irq, ARRAY_SIZE(vectors_irq));
reserve_intc_vectors(vectors_irl, ARRAY_SIZE(vectors_irl));
register_intc_controller(&intc_desc);
}
void __init plat_mem_setup(void)
{
unsigned int nid = 1;
setup_bootmem_node(nid++, 0x145f0000, 0x14610000);
#if 0
setup_bootmem_node(nid++, 0x14df0000, 0x14e10000);
setup_bootmem_node(nid++, 0x155f0000, 0x15610000);
setup_bootmem_node(nid++, 0x15df0000, 0x15e10000);
#endif
setup_bootmem_node(nid++, 0x16000000, 0x16020000);
}
