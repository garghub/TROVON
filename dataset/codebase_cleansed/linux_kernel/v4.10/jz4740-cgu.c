static void __init jz4740_cgu_init(struct device_node *np)
{
int retval;
cgu = ingenic_cgu_new(jz4740_cgu_clocks,
ARRAY_SIZE(jz4740_cgu_clocks), np);
if (!cgu) {
pr_err("%s: failed to initialise CGU\n", __func__);
return;
}
retval = ingenic_cgu_register_clocks(cgu);
if (retval)
pr_err("%s: failed to register CGU Clocks\n", __func__);
}
void jz4740_clock_set_wait_mode(enum jz4740_wait_mode mode)
{
uint32_t lcr = readl(cgu->base + CGU_REG_LCR);
switch (mode) {
case JZ4740_WAIT_MODE_IDLE:
lcr &= ~LCR_SLEEP;
break;
case JZ4740_WAIT_MODE_SLEEP:
lcr |= LCR_SLEEP;
break;
}
writel(lcr, cgu->base + CGU_REG_LCR);
}
void jz4740_clock_udc_disable_auto_suspend(void)
{
uint32_t clkgr = readl(cgu->base + CGU_REG_CLKGR);
clkgr &= ~CLKGR_UDC;
writel(clkgr, cgu->base + CGU_REG_CLKGR);
}
void jz4740_clock_udc_enable_auto_suspend(void)
{
uint32_t clkgr = readl(cgu->base + CGU_REG_CLKGR);
clkgr |= CLKGR_UDC;
writel(clkgr, cgu->base + CGU_REG_CLKGR);
}
void jz4740_clock_suspend(void)
{
uint32_t clkgr, cppcr;
clkgr = readl(cgu->base + CGU_REG_CLKGR);
clkgr |= JZ_CLOCK_GATE_TCU | JZ_CLOCK_GATE_DMAC | JZ_CLOCK_GATE_UART0;
writel(clkgr, cgu->base + CGU_REG_CLKGR);
cppcr = readl(cgu->base + CGU_REG_CPPCR);
cppcr &= ~BIT(jz4740_cgu_clocks[JZ4740_CLK_PLL].pll.enable_bit);
writel(cppcr, cgu->base + CGU_REG_CPPCR);
}
void jz4740_clock_resume(void)
{
uint32_t clkgr, cppcr, stable;
cppcr = readl(cgu->base + CGU_REG_CPPCR);
cppcr |= BIT(jz4740_cgu_clocks[JZ4740_CLK_PLL].pll.enable_bit);
writel(cppcr, cgu->base + CGU_REG_CPPCR);
stable = BIT(jz4740_cgu_clocks[JZ4740_CLK_PLL].pll.stable_bit);
do {
cppcr = readl(cgu->base + CGU_REG_CPPCR);
} while (!(cppcr & stable));
clkgr = readl(cgu->base + CGU_REG_CLKGR);
clkgr &= ~JZ_CLOCK_GATE_TCU;
clkgr &= ~JZ_CLOCK_GATE_DMAC;
clkgr &= ~JZ_CLOCK_GATE_UART0;
writel(clkgr, cgu->base + CGU_REG_CLKGR);
}
