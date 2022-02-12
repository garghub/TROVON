static void __init mediatek_timer_init(void)
{
void __iomem *gpt_base;
if (of_machine_is_compatible("mediatek,mt6589") ||
of_machine_is_compatible("mediatek,mt8135") ||
of_machine_is_compatible("mediatek,mt8127")) {
gpt_base = ioremap(GPT6_CON_MT65xx, 0x04);
writel(GPT_ENABLE, gpt_base);
iounmap(gpt_base);
}
of_clk_init(NULL);
clocksource_probe();
}
