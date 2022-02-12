static void __init system_timer_of_register(struct device_node *np)
{
struct clk *clk = NULL;
void __iomem *base;
u32 rate;
int ret;
base = of_iomap(np, 0);
if (!base) {
pr_warn("system-timer: invalid base address\n");
return;
}
ret = of_property_read_u32(np, "clock-frequency", &rate);
if (ret) {
clk = of_clk_get(np, 0);
if (IS_ERR(clk))
goto out_unmap;
ret = clk_prepare_enable(clk);
if (ret)
goto out_clk_put;
rate = clk_get_rate(clk);
if (!rate)
goto out_clk_disable;
}
writel_relaxed(SYSTICK_LOAD_RELOAD_MASK, base + SYST_RVR);
writel_relaxed(SYST_CSR_ENABLE, base + SYST_CSR);
ret = clocksource_mmio_init(base + SYST_CVR, "arm_system_timer", rate,
200, 24, clocksource_mmio_readl_down);
if (ret) {
pr_err("failed to init clocksource (%d)\n", ret);
if (clk)
goto out_clk_disable;
else
goto out_unmap;
}
pr_info("ARM System timer initialized as clocksource\n");
return;
out_clk_disable:
clk_disable_unprepare(clk);
out_clk_put:
clk_put(clk);
out_unmap:
iounmap(base);
pr_warn("ARM System timer register failed (%d)\n", ret);
}
