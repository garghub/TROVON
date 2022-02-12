static inline u32 gpt_readl(void __iomem *base, u32 offset, u32 gpt_id)
{
return readl(base + 0x20 * gpt_id + offset);
}
static inline void gpt_writel(void __iomem *base, u32 value, u32 offset,
u32 gpt_id)
{
writel(value, base + 0x20 * gpt_id + offset);
}
static cycle_t notrace
pistachio_clocksource_read_cycles(struct clocksource *cs)
{
struct pistachio_clocksource *pcs = to_pistachio_clocksource(cs);
u32 counter, overflw;
unsigned long flags;
raw_spin_lock_irqsave(&pcs->lock, flags);
overflw = gpt_readl(pcs->base, TIMER_CURRENT_OVERFLOW_VALUE, 0);
counter = gpt_readl(pcs->base, TIMER_CURRENT_VALUE, 0);
raw_spin_unlock_irqrestore(&pcs->lock, flags);
return ~(cycle_t)counter;
}
static u64 notrace pistachio_read_sched_clock(void)
{
return pistachio_clocksource_read_cycles(&pcs_gpt.cs);
}
static void pistachio_clksrc_set_mode(struct clocksource *cs, int timeridx,
int enable)
{
struct pistachio_clocksource *pcs = to_pistachio_clocksource(cs);
u32 val;
val = gpt_readl(pcs->base, TIMER_CFG, timeridx);
if (enable)
val |= TIMER_ME_LOCAL;
else
val &= ~TIMER_ME_LOCAL;
gpt_writel(pcs->base, val, TIMER_CFG, timeridx);
}
static void pistachio_clksrc_enable(struct clocksource *cs, int timeridx)
{
struct pistachio_clocksource *pcs = to_pistachio_clocksource(cs);
pistachio_clksrc_set_mode(cs, timeridx, false);
gpt_writel(pcs->base, RELOAD_VALUE, TIMER_RELOAD_VALUE, timeridx);
pistachio_clksrc_set_mode(cs, timeridx, true);
}
static void pistachio_clksrc_disable(struct clocksource *cs, int timeridx)
{
pistachio_clksrc_set_mode(cs, timeridx, false);
}
static int pistachio_clocksource_enable(struct clocksource *cs)
{
pistachio_clksrc_enable(cs, 0);
return 0;
}
static void pistachio_clocksource_disable(struct clocksource *cs)
{
pistachio_clksrc_disable(cs, 0);
}
static void __init pistachio_clksrc_of_init(struct device_node *node)
{
struct clk *sys_clk, *fast_clk;
struct regmap *periph_regs;
unsigned long rate;
int ret;
pcs_gpt.base = of_iomap(node, 0);
if (!pcs_gpt.base) {
pr_err("cannot iomap\n");
return;
}
periph_regs = syscon_regmap_lookup_by_phandle(node, "img,cr-periph");
if (IS_ERR(periph_regs)) {
pr_err("cannot get peripheral regmap (%lu)\n",
PTR_ERR(periph_regs));
return;
}
ret = regmap_update_bits(periph_regs, PERIP_TIMER_CONTROL,
0xf, 0x0);
if (ret)
return;
sys_clk = of_clk_get_by_name(node, "sys");
if (IS_ERR(sys_clk)) {
pr_err("clock get failed (%lu)\n", PTR_ERR(sys_clk));
return;
}
fast_clk = of_clk_get_by_name(node, "fast");
if (IS_ERR(fast_clk)) {
pr_err("clock get failed (%lu)\n", PTR_ERR(fast_clk));
return;
}
ret = clk_prepare_enable(sys_clk);
if (ret < 0) {
pr_err("failed to enable clock (%d)\n", ret);
return;
}
ret = clk_prepare_enable(fast_clk);
if (ret < 0) {
pr_err("failed to enable clock (%d)\n", ret);
clk_disable_unprepare(sys_clk);
return;
}
rate = clk_get_rate(fast_clk);
gpt_writel(&pcs_gpt.base, 0, TIMER_IRQ_MASK, 0);
gpt_writel(&pcs_gpt.base, 0, TIMER_IRQ_MASK, 1);
gpt_writel(&pcs_gpt.base, 0, TIMER_IRQ_MASK, 2);
gpt_writel(&pcs_gpt.base, 0, TIMER_IRQ_MASK, 3);
writel(TIMER_ME_GLOBAL, pcs_gpt.base);
raw_spin_lock_init(&pcs_gpt.lock);
sched_clock_register(pistachio_read_sched_clock, 32, rate);
clocksource_register_hz(&pcs_gpt.cs, rate);
}
