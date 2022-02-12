static void __init brcmstb_init_irq(void)
{
irqchip_init();
brcmstb_biuctrl_init();
}
