static inline struct imx_timer *to_imx_timer(struct clock_event_device *ced)
{
return container_of(ced, struct imx_timer, ced);
}
static void imx1_gpt_irq_disable(struct imx_timer *imxtm)
{
unsigned int tmp;
tmp = readl_relaxed(imxtm->base + MXC_TCTL);
writel_relaxed(tmp & ~MX1_2_TCTL_IRQEN, imxtm->base + MXC_TCTL);
}
static void imx31_gpt_irq_disable(struct imx_timer *imxtm)
{
writel_relaxed(0, imxtm->base + V2_IR);
}
static void imx1_gpt_irq_enable(struct imx_timer *imxtm)
{
unsigned int tmp;
tmp = readl_relaxed(imxtm->base + MXC_TCTL);
writel_relaxed(tmp | MX1_2_TCTL_IRQEN, imxtm->base + MXC_TCTL);
}
static void imx31_gpt_irq_enable(struct imx_timer *imxtm)
{
writel_relaxed(1<<0, imxtm->base + V2_IR);
}
static void imx1_gpt_irq_acknowledge(struct imx_timer *imxtm)
{
writel_relaxed(0, imxtm->base + MX1_2_TSTAT);
}
static void imx21_gpt_irq_acknowledge(struct imx_timer *imxtm)
{
writel_relaxed(MX2_TSTAT_CAPT | MX2_TSTAT_COMP,
imxtm->base + MX1_2_TSTAT);
}
static void imx31_gpt_irq_acknowledge(struct imx_timer *imxtm)
{
writel_relaxed(V2_TSTAT_OF1, imxtm->base + V2_TSTAT);
}
static u64 notrace mxc_read_sched_clock(void)
{
return sched_clock_reg ? readl_relaxed(sched_clock_reg) : 0;
}
static unsigned long imx_read_current_timer(void)
{
return readl_relaxed(sched_clock_reg);
}
static int __init mxc_clocksource_init(struct imx_timer *imxtm)
{
unsigned int c = clk_get_rate(imxtm->clk_per);
void __iomem *reg = imxtm->base + imxtm->gpt->reg_tcn;
imx_delay_timer.read_current_timer = &imx_read_current_timer;
imx_delay_timer.freq = c;
register_current_timer_delay(&imx_delay_timer);
sched_clock_reg = reg;
sched_clock_register(mxc_read_sched_clock, 32, c);
return clocksource_mmio_init(reg, "mxc_timer1", c, 200, 32,
clocksource_mmio_readl_up);
}
static int mx1_2_set_next_event(unsigned long evt,
struct clock_event_device *ced)
{
struct imx_timer *imxtm = to_imx_timer(ced);
unsigned long tcmp;
tcmp = readl_relaxed(imxtm->base + MX1_2_TCN) + evt;
writel_relaxed(tcmp, imxtm->base + MX1_2_TCMP);
return (int)(tcmp - readl_relaxed(imxtm->base + MX1_2_TCN)) < 0 ?
-ETIME : 0;
}
static int v2_set_next_event(unsigned long evt,
struct clock_event_device *ced)
{
struct imx_timer *imxtm = to_imx_timer(ced);
unsigned long tcmp;
tcmp = readl_relaxed(imxtm->base + V2_TCN) + evt;
writel_relaxed(tcmp, imxtm->base + V2_TCMP);
return evt < 0x7fffffff &&
(int)(tcmp - readl_relaxed(imxtm->base + V2_TCN)) < 0 ?
-ETIME : 0;
}
static int mxc_shutdown(struct clock_event_device *ced)
{
struct imx_timer *imxtm = to_imx_timer(ced);
unsigned long flags;
u32 tcn;
local_irq_save(flags);
imxtm->gpt->gpt_irq_disable(imxtm);
tcn = readl_relaxed(imxtm->base + imxtm->gpt->reg_tcn);
writel_relaxed(tcn - 3, imxtm->base + imxtm->gpt->reg_tcmp);
imxtm->gpt->gpt_irq_acknowledge(imxtm);
#ifdef DEBUG
printk(KERN_INFO "%s: changing mode\n", __func__);
#endif
local_irq_restore(flags);
return 0;
}
static int mxc_set_oneshot(struct clock_event_device *ced)
{
struct imx_timer *imxtm = to_imx_timer(ced);
unsigned long flags;
local_irq_save(flags);
imxtm->gpt->gpt_irq_disable(imxtm);
if (!clockevent_state_oneshot(ced)) {
u32 tcn = readl_relaxed(imxtm->base + imxtm->gpt->reg_tcn);
writel_relaxed(tcn - 3, imxtm->base + imxtm->gpt->reg_tcmp);
imxtm->gpt->gpt_irq_acknowledge(imxtm);
}
#ifdef DEBUG
printk(KERN_INFO "%s: changing mode\n", __func__);
#endif
imxtm->gpt->gpt_irq_enable(imxtm);
local_irq_restore(flags);
return 0;
}
static irqreturn_t mxc_timer_interrupt(int irq, void *dev_id)
{
struct clock_event_device *ced = dev_id;
struct imx_timer *imxtm = to_imx_timer(ced);
uint32_t tstat;
tstat = readl_relaxed(imxtm->base + imxtm->gpt->reg_tstat);
imxtm->gpt->gpt_irq_acknowledge(imxtm);
ced->event_handler(ced);
return IRQ_HANDLED;
}
static int __init mxc_clockevent_init(struct imx_timer *imxtm)
{
struct clock_event_device *ced = &imxtm->ced;
struct irqaction *act = &imxtm->act;
ced->name = "mxc_timer1";
ced->features = CLOCK_EVT_FEAT_ONESHOT | CLOCK_EVT_FEAT_DYNIRQ;
ced->set_state_shutdown = mxc_shutdown;
ced->set_state_oneshot = mxc_set_oneshot;
ced->tick_resume = mxc_shutdown;
ced->set_next_event = imxtm->gpt->set_next_event;
ced->rating = 200;
ced->cpumask = cpumask_of(0);
ced->irq = imxtm->irq;
clockevents_config_and_register(ced, clk_get_rate(imxtm->clk_per),
0xff, 0xfffffffe);
act->name = "i.MX Timer Tick";
act->flags = IRQF_TIMER | IRQF_IRQPOLL;
act->handler = mxc_timer_interrupt;
act->dev_id = ced;
return setup_irq(imxtm->irq, act);
}
static void imx1_gpt_setup_tctl(struct imx_timer *imxtm)
{
u32 tctl_val;
tctl_val = MX1_2_TCTL_FRR | MX1_2_TCTL_CLK_PCLK1 | MXC_TCTL_TEN;
writel_relaxed(tctl_val, imxtm->base + MXC_TCTL);
}
static void imx31_gpt_setup_tctl(struct imx_timer *imxtm)
{
u32 tctl_val;
tctl_val = V2_TCTL_FRR | V2_TCTL_WAITEN | MXC_TCTL_TEN;
if (clk_get_rate(imxtm->clk_per) == V2_TIMER_RATE_OSC_DIV8)
tctl_val |= V2_TCTL_CLK_OSC_DIV8;
else
tctl_val |= V2_TCTL_CLK_PER;
writel_relaxed(tctl_val, imxtm->base + MXC_TCTL);
}
static void imx6dl_gpt_setup_tctl(struct imx_timer *imxtm)
{
u32 tctl_val;
tctl_val = V2_TCTL_FRR | V2_TCTL_WAITEN | MXC_TCTL_TEN;
if (clk_get_rate(imxtm->clk_per) == V2_TIMER_RATE_OSC_DIV8) {
tctl_val |= V2_TCTL_CLK_OSC_DIV8;
writel_relaxed(7 << V2_TPRER_PRE24M, imxtm->base + MXC_TPRER);
tctl_val |= V2_TCTL_24MEN;
} else {
tctl_val |= V2_TCTL_CLK_PER;
}
writel_relaxed(tctl_val, imxtm->base + MXC_TCTL);
}
static int __init _mxc_timer_init(struct imx_timer *imxtm)
{
int ret;
switch (imxtm->type) {
case GPT_TYPE_IMX1:
imxtm->gpt = &imx1_gpt_data;
break;
case GPT_TYPE_IMX21:
imxtm->gpt = &imx21_gpt_data;
break;
case GPT_TYPE_IMX31:
imxtm->gpt = &imx31_gpt_data;
break;
case GPT_TYPE_IMX6DL:
imxtm->gpt = &imx6dl_gpt_data;
break;
default:
return -EINVAL;
}
if (IS_ERR(imxtm->clk_per)) {
pr_err("i.MX timer: unable to get clk\n");
return PTR_ERR(imxtm->clk_per);
}
if (!IS_ERR(imxtm->clk_ipg))
clk_prepare_enable(imxtm->clk_ipg);
clk_prepare_enable(imxtm->clk_per);
writel_relaxed(0, imxtm->base + MXC_TCTL);
writel_relaxed(0, imxtm->base + MXC_TPRER);
imxtm->gpt->gpt_setup_tctl(imxtm);
ret = mxc_clocksource_init(imxtm);
if (ret)
return ret;
return mxc_clockevent_init(imxtm);
}
void __init mxc_timer_init(unsigned long pbase, int irq, enum imx_gpt_type type)
{
struct imx_timer *imxtm;
imxtm = kzalloc(sizeof(*imxtm), GFP_KERNEL);
BUG_ON(!imxtm);
imxtm->clk_per = clk_get_sys("imx-gpt.0", "per");
imxtm->clk_ipg = clk_get_sys("imx-gpt.0", "ipg");
imxtm->base = ioremap(pbase, SZ_4K);
BUG_ON(!imxtm->base);
imxtm->type = type;
imxtm->irq = irq;
_mxc_timer_init(imxtm);
}
static int __init mxc_timer_init_dt(struct device_node *np, enum imx_gpt_type type)
{
struct imx_timer *imxtm;
static int initialized;
int ret;
if (initialized)
return 0;
imxtm = kzalloc(sizeof(*imxtm), GFP_KERNEL);
if (!imxtm)
return -ENOMEM;
imxtm->base = of_iomap(np, 0);
if (!imxtm->base)
return -ENXIO;
imxtm->irq = irq_of_parse_and_map(np, 0);
if (imxtm->irq <= 0)
return -EINVAL;
imxtm->clk_ipg = of_clk_get_by_name(np, "ipg");
imxtm->clk_per = of_clk_get_by_name(np, "osc_per");
if (IS_ERR(imxtm->clk_per))
imxtm->clk_per = of_clk_get_by_name(np, "per");
imxtm->type = type;
ret = _mxc_timer_init(imxtm);
if (ret)
return ret;
initialized = 1;
return 0;
}
static int __init imx1_timer_init_dt(struct device_node *np)
{
return mxc_timer_init_dt(np, GPT_TYPE_IMX1);
}
static int __init imx21_timer_init_dt(struct device_node *np)
{
return mxc_timer_init_dt(np, GPT_TYPE_IMX21);
}
static int __init imx31_timer_init_dt(struct device_node *np)
{
enum imx_gpt_type type = GPT_TYPE_IMX31;
if (of_machine_is_compatible("fsl,imx6dl"))
type = GPT_TYPE_IMX6DL;
return mxc_timer_init_dt(np, type);
}
static int __init imx6dl_timer_init_dt(struct device_node *np)
{
return mxc_timer_init_dt(np, GPT_TYPE_IMX6DL);
}
