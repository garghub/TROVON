static void __init st_clksrc_reset(void)
{
writel_relaxed(0, ddata.base + LPC_LPT_START_OFF);
writel_relaxed(0, ddata.base + LPC_LPT_MSB_OFF);
writel_relaxed(0, ddata.base + LPC_LPT_LSB_OFF);
writel_relaxed(1, ddata.base + LPC_LPT_START_OFF);
}
static u64 notrace st_clksrc_sched_clock_read(void)
{
return (u64)readl_relaxed(ddata.base + LPC_LPT_LSB_OFF);
}
static int __init st_clksrc_init(void)
{
unsigned long rate;
int ret;
st_clksrc_reset();
rate = clk_get_rate(ddata.clk);
sched_clock_register(st_clksrc_sched_clock_read, 32, rate);
ret = clocksource_mmio_init(ddata.base + LPC_LPT_LSB_OFF,
"clksrc-st-lpc", rate, 300, 32,
clocksource_mmio_readl_up);
if (ret) {
pr_err("clksrc-st-lpc: Failed to register clocksource\n");
return ret;
}
return 0;
}
static int __init st_clksrc_setup_clk(struct device_node *np)
{
struct clk *clk;
clk = of_clk_get(np, 0);
if (IS_ERR(clk)) {
pr_err("clksrc-st-lpc: Failed to get LPC clock\n");
return PTR_ERR(clk);
}
if (clk_prepare_enable(clk)) {
pr_err("clksrc-st-lpc: Failed to enable LPC clock\n");
return -EINVAL;
}
if (!clk_get_rate(clk)) {
pr_err("clksrc-st-lpc: Failed to get LPC clock rate\n");
clk_disable_unprepare(clk);
return -EINVAL;
}
ddata.clk = clk;
return 0;
}
static void __init st_clksrc_of_register(struct device_node *np)
{
int ret;
uint32_t mode;
ret = of_property_read_u32(np, "st,lpc-mode", &mode);
if (ret) {
pr_err("clksrc-st-lpc: An LPC mode must be provided\n");
return;
}
if (mode != ST_LPC_MODE_CLKSRC)
return;
ddata.base = of_iomap(np, 0);
if (!ddata.base) {
pr_err("clksrc-st-lpc: Unable to map iomem\n");
return;
}
if (st_clksrc_setup_clk(np)) {
iounmap(ddata.base);
return;
}
if (st_clksrc_init()) {
clk_disable_unprepare(ddata.clk);
clk_put(ddata.clk);
iounmap(ddata.base);
return;
}
pr_info("clksrc-st-lpc: clocksource initialised - running @ %luHz\n",
clk_get_rate(ddata.clk));
}
