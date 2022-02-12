static void u300_set_mode(enum clock_event_mode mode,
struct clock_event_device *evt)
{
struct u300_clockevent_data *cevdata =
container_of(evt, struct u300_clockevent_data, cevd);
switch (mode) {
case CLOCK_EVT_MODE_PERIODIC:
writel(U300_TIMER_APP_GPT1IE_IRQ_DISABLE,
u300_timer_base + U300_TIMER_APP_GPT1IE);
writel(U300_TIMER_APP_DGPT1_TIMER_DISABLE,
u300_timer_base + U300_TIMER_APP_DGPT1);
writel(cevdata->ticks_per_jiffy,
u300_timer_base + U300_TIMER_APP_GPT1TC);
writel(U300_TIMER_APP_SGPT1M_MODE_CONTINUOUS,
u300_timer_base + U300_TIMER_APP_SGPT1M);
writel(U300_TIMER_APP_GPT1IE_IRQ_ENABLE,
u300_timer_base + U300_TIMER_APP_GPT1IE);
writel(U300_TIMER_APP_EGPT1_TIMER_ENABLE,
u300_timer_base + U300_TIMER_APP_EGPT1);
break;
case CLOCK_EVT_MODE_ONESHOT:
writel(U300_TIMER_APP_GPT1IE_IRQ_DISABLE,
u300_timer_base + U300_TIMER_APP_GPT1IE);
writel(U300_TIMER_APP_DGPT1_TIMER_DISABLE,
u300_timer_base + U300_TIMER_APP_DGPT1);
writel(0xFFFFFFFF, u300_timer_base + U300_TIMER_APP_GPT1TC);
writel(U300_TIMER_APP_SGPT1M_MODE_ONE_SHOT,
u300_timer_base + U300_TIMER_APP_SGPT1M);
writel(U300_TIMER_APP_GPT1IE_IRQ_ENABLE,
u300_timer_base + U300_TIMER_APP_GPT1IE);
writel(U300_TIMER_APP_EGPT1_TIMER_ENABLE,
u300_timer_base + U300_TIMER_APP_EGPT1);
break;
case CLOCK_EVT_MODE_UNUSED:
case CLOCK_EVT_MODE_SHUTDOWN:
writel(U300_TIMER_APP_GPT1IE_IRQ_DISABLE,
u300_timer_base + U300_TIMER_APP_GPT1IE);
writel(U300_TIMER_APP_DGPT1_TIMER_DISABLE,
u300_timer_base + U300_TIMER_APP_DGPT1);
break;
case CLOCK_EVT_MODE_RESUME:
break;
}
}
static int u300_set_next_event(unsigned long cycles,
struct clock_event_device *evt)
{
writel(U300_TIMER_APP_GPT1IE_IRQ_DISABLE,
u300_timer_base + U300_TIMER_APP_GPT1IE);
writel(U300_TIMER_APP_DGPT1_TIMER_DISABLE,
u300_timer_base + U300_TIMER_APP_DGPT1);
writel(U300_TIMER_APP_RGPT1_TIMER_RESET,
u300_timer_base + U300_TIMER_APP_RGPT1);
writel(cycles, u300_timer_base + U300_TIMER_APP_GPT1TC);
writel(U300_TIMER_APP_SGPT1M_MODE_ONE_SHOT,
u300_timer_base + U300_TIMER_APP_SGPT1M);
writel(U300_TIMER_APP_GPT1IE_IRQ_ENABLE,
u300_timer_base + U300_TIMER_APP_GPT1IE);
writel(U300_TIMER_APP_EGPT1_TIMER_ENABLE,
u300_timer_base + U300_TIMER_APP_EGPT1);
return 0;
}
static irqreturn_t u300_timer_interrupt(int irq, void *dev_id)
{
struct clock_event_device *evt = &u300_clockevent_data.cevd;
writel(U300_TIMER_APP_GPT1IA_IRQ_ACK,
u300_timer_base + U300_TIMER_APP_GPT1IA);
evt->event_handler(evt);
return IRQ_HANDLED;
}
static u64 notrace u300_read_sched_clock(void)
{
return readl(u300_timer_base + U300_TIMER_APP_GPT2CC);
}
static unsigned long u300_read_current_timer(void)
{
return readl(u300_timer_base + U300_TIMER_APP_GPT2CC);
}
static void __init u300_timer_init_of(struct device_node *np)
{
unsigned int irq;
struct clk *clk;
unsigned long rate;
u300_timer_base = of_iomap(np, 0);
if (!u300_timer_base)
panic("could not ioremap system timer\n");
irq = irq_of_parse_and_map(np, 2);
if (!irq)
panic("no IRQ for system timer\n");
pr_info("U300 GP1 timer @ base: %p, IRQ: %u\n", u300_timer_base, irq);
clk = of_clk_get(np, 0);
BUG_ON(IS_ERR(clk));
clk_prepare_enable(clk);
rate = clk_get_rate(clk);
u300_clockevent_data.ticks_per_jiffy = DIV_ROUND_CLOSEST(rate, HZ);
sched_clock_register(u300_read_sched_clock, 32, rate);
u300_delay_timer.read_current_timer = &u300_read_current_timer;
u300_delay_timer.freq = rate;
register_current_timer_delay(&u300_delay_timer);
writel(U300_TIMER_APP_CRC_CLOCK_REQUEST_ENABLE,
u300_timer_base + U300_TIMER_APP_CRC);
writel(U300_TIMER_APP_ROST_TIMER_RESET,
u300_timer_base + U300_TIMER_APP_ROST);
writel(U300_TIMER_APP_DOST_TIMER_DISABLE,
u300_timer_base + U300_TIMER_APP_DOST);
writel(U300_TIMER_APP_RDDT_TIMER_RESET,
u300_timer_base + U300_TIMER_APP_RDDT);
writel(U300_TIMER_APP_DDDT_TIMER_DISABLE,
u300_timer_base + U300_TIMER_APP_DDDT);
writel(U300_TIMER_APP_RGPT1_TIMER_RESET,
u300_timer_base + U300_TIMER_APP_RGPT1);
setup_irq(irq, &u300_timer_irq);
writel(U300_TIMER_APP_RGPT2_TIMER_RESET,
u300_timer_base + U300_TIMER_APP_RGPT2);
writel(0xFFFFFFFFU, u300_timer_base + U300_TIMER_APP_GPT2TC);
writel(U300_TIMER_APP_SGPT2M_MODE_CONTINUOUS,
u300_timer_base + U300_TIMER_APP_SGPT2M);
writel(U300_TIMER_APP_GPT2IE_IRQ_DISABLE,
u300_timer_base + U300_TIMER_APP_GPT2IE);
writel(U300_TIMER_APP_EGPT2_TIMER_ENABLE,
u300_timer_base + U300_TIMER_APP_EGPT2);
if (clocksource_mmio_init(u300_timer_base + U300_TIMER_APP_GPT2CC,
"GPT2", rate, 300, 32, clocksource_mmio_readl_up))
pr_err("timer: failed to initialize U300 clock source\n");
clockevents_config_and_register(&u300_clockevent_data.cevd, rate,
1, 0xffffffff);
}
